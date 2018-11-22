﻿#include <QDebug>
#include <QInputDialog>
#include <QTableView>
#include <QTextBrowser>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <QMenu>
#include <fstream>
#include <QLocale>
#include <QDir>
#include <time.h>

#if (defined(__linux__) || defined(__APPLE__))
#include <iconv.h>
#endif 

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcalendarproxy.h"
#include "cameramodel.h"
#include "alarmmodel.h"
#include "pushalarmmodel.h"
#include "recordmodel.h"
#include "localsetting.h"
#include "OpenNetStreamError.h"

/****************************************
 Function:    UTF8ToAnsi
 Description: Convert UTF-8 string to Ansi string
 Input:       szAnsiString UTF-8 string
 Return:      Ansi string
 ****************************************/
char *UTF8ToAnsi(const char *szUTF8String)
{
#if defined(_WIN32) || defined(_WIN64)
	WCHAR* strSrc = NULL;
	char* szRes = NULL;
    
	int i = MultiByteToWideChar(CP_UTF8, 0, szUTF8String, -1, NULL, 0);
    
	strSrc = new WCHAR[(size_t)i+1];
	MultiByteToWideChar(CP_UTF8, 0, szUTF8String, -1, strSrc, i);
    
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    
	szRes = new char[(size_t)i+1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);
    
	delete[] strSrc;
	strSrc = NULL;
    
	return szRes;
    
#elif defined(__linux__)
	char *outbuf = 0;
	if (szUTF8String)
	{
		iconv_t cd = iconv_open("EUC-CN", "UTF-8");
		if (cd)
		{
			size_t contlen = strlen(szUTF8String);
			size_t outbuflen = contlen * 3 + 1;
			outbuf = new char[outbuflen];
			memset(outbuf, 0, outbuflen);
            
			char *inptr = const_cast<char*>(szUTF8String);
			char *outptr = outbuf;
            
			size_t inlen = contlen;
			size_t outlen = outbuflen;
			if (iconv(cd, &inptr, &inlen, &outptr, &outlen) == (size_t)(-1))
			{
				outbuf = 0;
			}
            
			iconv_close(cd);
		}
	}
	return outbuf;
#else
    size_t contlen = strlen(szUTF8String);
    size_t outbuflen = contlen;
    char *outbuf = new char[outbuflen];
    if (outbuf)
    {
        memset(outbuf, 0, outbuflen);
        memcpy(outbuf, szUTF8String, outbuflen);
    }

    return outbuf;
#endif
}

std::string UTF8ToANSIString(const char *pUtf8String)
{
    std::string strANSI;
	if (pUtf8String != NULL)
	{
		char *pAnsi = UTF8ToAnsi(pUtf8String);
		if (pAnsi != NULL)
		{
			strANSI = pAnsi;
			delete []pAnsi;
		}
	}
	
	return strANSI;
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    m_osdTimer(NULL),
	m_bRealPlayStarted(false),
	m_bPlayBackStarted(false),
	m_bPlayBackFinished(false)
{
    ui->setupUi(this);

    //User own device list
    m_deviceTableView = new QTableView(this);
    m_deviceTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_deviceTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_deviceTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabWidget->addTab(m_deviceTableView, tr("Device List"));

    connect(m_deviceTableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slotDeviceTableViewPressed(const QModelIndex &)));

    m_deviceTableModel = new CameraModel(this);
    m_deviceTableView->setModel(m_deviceTableModel);
    //User shared device list
    m_shareDevTableView = new QTableView(this); 
    m_shareDevTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_shareDevTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_shareDevTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabWidget->addTab(m_shareDevTableView, tr("Share Dev List"));

    connect(m_shareDevTableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slotDeviceTableViewPressed(const QModelIndex &)));

    m_shareDevTableModel = new CameraModel(this);
    m_shareDevTableView->setModel(m_shareDevTableModel);

    m_alarmTableView = new QTableView(this);
    m_alarmTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_alarmTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_alarmTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabWidget->addTab(m_alarmTableView, tr("Alarm List"));

    m_alarmTableModel = new AlarmModel(this);
    m_alarmTableView->setModel(m_alarmTableModel);

    m_pushAlarmTableView = new QTableView(this);
    m_pushAlarmTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_pushAlarmTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pushAlarmTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabWidget->addTab(m_pushAlarmTableView, tr("Push-Alarm-List"));

    m_pushAlarmTableModel = new PushAlarmModel(this);
    m_pushAlarmTableView->setModel(m_pushAlarmTableModel);

    connect(m_pushAlarmTableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slotPushAlarmTableViewPressed(const QModelIndex &)));

    m_playBackTableView = new QTableView(this);
    m_playBackTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_playBackTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_playBackTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabWidget->addTab(m_playBackTableView, tr("Playback List"));

    m_playBackTableModel = new RecordModel(this);
    m_playBackTableView->setModel(m_playBackTableModel);

    connect(m_playBackTableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slotPlayBackTableViewPressed(const QModelIndex &)));

    m_jsonTextBrowser = new QTextBrowser(this);
    ui->tabWidget->addTab(m_jsonTextBrowser, tr("json"));

    m_realPlayMenu = new QMenu(this);
    ui->switchVideoLevelButton->setMenu(m_realPlayMenu);

    //! [1] init library，alloc session
    OpenNetStream::getInstance()->initLibrary(LocalSetting::getInstance()->authAddress(), LocalSetting::getInstance()->platformAddress(), LocalSetting::getInstance()->appKey());
    QString areaID = LocalSetting::getInstance()->areaId();
    if (!areaID.isEmpty())
    {
        OpenNetStream::getInstance()->setAreaID(areaID);
    }
    QString loginVer = LocalSetting::getInstance()->loginVer();
    if (!loginVer.isEmpty())
    {
        OpenNetStream::getInstance()->setLoginVer(loginVer);
    }
    if (LocalSetting::getInstance()->dataUtf8())
    {
        OpenNetStream::getInstance()->setDataUtf8();
    }

    if (LocalSetting::getInstance()->streamTrans())
    {
        OpenNetStream::getInstance()->setStreamTrans();
    }

    if (LocalSetting::getInstance()->closeP2P())
    {
        OpenNetStream::getInstance()->closeP2P();
    }

    int iP2PMaxNum = LocalSetting::getInstance()->P2PMaxNum();
    if (iP2PMaxNum > 0)
    {
        OpenNetStream::getInstance()->setP2PMaxNum(iP2PMaxNum);
    }

    int iP2PCheckPeriod = LocalSetting::getInstance()->P2PCheckPeriod();
    if (iP2PCheckPeriod > 0)
    {
        OpenNetStream::getInstance()->setP2PCheckPeriod(iP2PCheckPeriod);
    }

    int iP2PExpire = LocalSetting::getInstance()->P2PExpire();
    if (iP2PExpire > 0)
    {
        OpenNetStream::getInstance()->setP2PExpire(iP2PExpire);
    }
    int iLogLevel = LocalSetting::getInstance()->logLevel();
    if (iLogLevel > 0)
    {
        OpenNetStream::getInstance()->setLogLevel(iLogLevel);
    }
    
    m_sessionId = OpenNetStream::getInstance()->allocSessionEx(MainWindow::messageHandler, this);
    //! [1]

    connect(this, SIGNAL(insRecordFile(QByteArray)), this, SLOT(on_insRecordFile(QByteArray)));
    connect(this, SIGNAL(insPlayException(uint,QByteArray)), this, SLOT(on_insPlayException(uint,QByteArray)));
	connect(this, SIGNAL(insPlayBackEnd(uint)), this, SLOT(on_insPlayBackEnd(uint)));
    connect(this, SIGNAL(insPlayReconnectException(uint,QByteArray)),this, SLOT(on_insPlayReconnectException(uint,QByteArray)));
    connect(this, SIGNAL(insPlayStart()),this, SLOT(on_insPlayStart()));
    connect(this, SIGNAL(insPlayStop()),this, SLOT(on_insPlayStop()));
    connect(this, SIGNAL(insRecordSearchFailed(uint,QByteArray)), this, SLOT(on_insRecordSearchFailed(uint,QByteArray)));
    connect(this, SIGNAL(insPlayAlarm(QString,QString,QString)), this, SLOT(on_insPlayAlarm(QString,QString,QString)));
	connect(this, SIGNAL(insPlayPush(QString,QString,QString)), this, SLOT(on_insPlayPush(QString,QString,QString)));

    connect(ui->pushButton_U, SIGNAL(pressed()), this, SLOT(on_insPtzStartUp()));
    connect(ui->pushButton_D,  SIGNAL(pressed()), this, SLOT(on_insPtzStartDown()));
    connect(ui->pushButton_L,  SIGNAL(pressed()), this, SLOT(on_insPtzStartLeft()));
    connect(ui->pushButton_R,  SIGNAL(pressed()), this, SLOT(on_insPtzStartRight()));
    connect(ui->pushButton_UL, SIGNAL(pressed()), this, SLOT(on_insPtzStartUpLeft()));
    connect(ui->pushButton_DL, SIGNAL(pressed()), this, SLOT(on_insPtzStartDownLeft()));
    connect(ui->pushButton_UR, SIGNAL(pressed()), this, SLOT(on_insPtzStartUpRight()));
    connect(ui->pushButton_DR, SIGNAL(pressed()), this, SLOT(on_insPtzStartDownRight()));

    connect(ui->pushButton_U, SIGNAL(released()), this, SLOT(on_insPtzStopUp()));
    connect(ui->pushButton_D,  SIGNAL(released()), this, SLOT(on_insPtzStopDown()));
    connect(ui->pushButton_L,  SIGNAL(released()), this, SLOT(on_insPtzStopLeft()));
    connect(ui->pushButton_R,  SIGNAL(released()), this, SLOT(on_insPtzStopRight()));
    connect(ui->pushButton_UL, SIGNAL(released()), this, SLOT(on_insPtzStopUpLeft()));
    connect(ui->pushButton_DL, SIGNAL(released()), this, SLOT(on_insPtzStopDownLeft()));
    connect(ui->pushButton_UR, SIGNAL(released()), this, SLOT(on_insPtzStopUpRight()));
    connect(ui->pushButton_DR, SIGNAL(released()), this, SLOT(on_insPtzStopDownRight()));

    connect(this, SIGNAL(insPtzStart(PTZDirect)), this, SLOT(on_insPtzStart(PTZDirect)));
    connect(this, SIGNAL(insPtzStop(PTZDirect)), this, SLOT(on_insPtzStop(PTZDirect)));

    connect(ui->pushButton_ZoomIn, SIGNAL(pressed()), this, SLOT(on_insPtzStartZoomIn()));
    connect(ui->pushButton_ZoomOut, SIGNAL(pressed()), this, SLOT(on_insPtzStartZoomOut()));
    connect(ui->pushButton_FocusFar, SIGNAL(pressed()), this, SLOT(on_insPtzStartFocusFar()));
    connect(ui->pushButton_FocusNear, SIGNAL(pressed()), this, SLOT(on_insPtzStartFocusNear()));
    connect(ui->pushButton_IrisStart, SIGNAL(pressed()), this, SLOT(on_insPtzStartIrisStartUp()));
    connect(ui->pushButton_IrisStop, SIGNAL(pressed()), this, SLOT(on_insPtzStartIrisStopDown()));
	connect(ui->pushButton_Auto, SIGNAL(pressed()), this, SLOT(on_insPtzAutoStartUp()));

    connect(ui->pushButton_ZoomIn, SIGNAL(released()), this, SLOT(on_insPtzStopZoomIn()));
    connect(ui->pushButton_ZoomOut, SIGNAL(released()), this, SLOT(on_insPtzStopZoomOut()));
    connect(ui->pushButton_FocusFar, SIGNAL(released()), this, SLOT(on_insPtzStopFocusFar()));
    connect(ui->pushButton_FocusNear, SIGNAL(released()), this, SLOT(on_insPtzStopFocusNear()));
    connect(ui->pushButton_IrisStart, SIGNAL(released()), this, SLOT(on_insPtzStopIrisStartUp()));
    connect(ui->pushButton_IrisStop, SIGNAL(released()), this, SLOT(on_insPtzStopIrisStopDown()));
	connect(ui->pushButton_Auto, SIGNAL(released()), this, SLOT(on_insPtzAutoStopDown()));

    connect(ui->getCameraInfoButton, SIGNAL(released()), this, SLOT(on_insGetCameraInfo()));
    connect(ui->updateCameraInfoButton, SIGNAL(released()), this, SLOT(on_insUpdateCameraInfo()));

    m_loginWindow = new LoginWindow(this);
}

MainWindow::~MainWindow()
{
    OpenNetStream::getInstance()->freeSession(m_sessionId);
    OpenNetStream::getInstance()->releaseLibrary();
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


const QString& MainWindow::curVideoPath()
{
    return m_videoPath;
}

void MainWindow::addPushAlarm(const char* szAlarmInfo)
{
    if (szAlarmInfo)
    {
        m_pushAlarmTableModel->AddPushAlarmModel(szAlarmInfo);
        ui->tabWidget->setCurrentIndex(PushAlarmTableIndex);
    }
}

void MainWindow::setVideoPath(const QString devSerial)
{
    time_t rawtime;
    time (&rawtime);
    struct tm * timeinfo = localtime(&rawtime);
    const int buflen = 32;
    char buffer[buflen] = {0};
    strftime(buffer, buflen, "%Y%m%d%H%M%S", timeinfo);
    const QString strFlag = devSerial + "_" + buffer;
    QString path = QCoreApplication::applicationDirPath();
	m_videoPath = path + "/" + strFlag + ".mp4";
}

void MainWindow::messageHandler(const char *szSessionId, unsigned int iMsgType, unsigned int iErrorCode, const char *pMessageInfo, void *pUser)
{
    qDebug() << __LINE__ << __FUNCTION__ << szSessionId << iMsgType << iErrorCode << pMessageInfo;
    MainWindow* pInstance = static_cast<MainWindow*>(pUser);
    if (!pInstance) {
        return;
    }

    switch (iMsgType) {
    case INS_PLAY_EXCEPTION:
        emit pInstance->insPlayException(iErrorCode, pMessageInfo);
        break;
    case INS_PLAY_RECONNECT:
        break;
    case INS_PLAY_RECONNECT_EXCEPTION:
        emit pInstance->insPlayReconnectException(iErrorCode, pMessageInfo);
        break;
    case INS_PLAY_START:
        emit pInstance->insPlayStart();
        break;
    case INS_PLAY_STOP:
        emit pInstance->insPlayStop();
        break;
    case INS_PLAY_ARCHIVE_END:
		emit pInstance->insPlayBackEnd(iErrorCode);
        break;
    case INS_RECORD_FILE:
        emit pInstance->insRecordFile(pMessageInfo);
        break;
    case INS_RECORD_SEARCH_END:
        break;
    case INS_RECORD_SEARCH_FAILED:
        emit pInstance->insRecordSearchFailed(iErrorCode, pMessageInfo);
        break;
    }
}

void MainWindow::alarmTransparentMessageHandler(const char* szContent, void* pUser)
{
    qDebug() << __LINE__ << __FUNCTION__ << szContent;
    MainWindow* pInstance = static_cast<MainWindow*>(pUser);
    if (!pInstance) {
        return;
    }
    emit pInstance->insPlayAlarm("", QString::fromLocal8Bit(szContent), "");
}

void MainWindow::pushAlarmHandler(const char* szDesc, const char* szContent, const char* szDetail, void* pUser)
{
    qDebug() << __LINE__ << __FUNCTION__ << szDesc;
    qDebug() << __LINE__ << __FUNCTION__ << szContent;
    MainWindow* pInstance = static_cast<MainWindow*>(pUser);
    if (!pInstance) {
        return;
    }

    pInstance->addPushAlarm(szContent);
}

void MainWindow::pushDevStatusHandler(const char* szDesc, const char* szContent, const char* szDetail, void* pUser)
{
    qDebug() << __LINE__ << __FUNCTION__ << szDesc;
    qDebug() << __LINE__ << __FUNCTION__ << szContent;
    MainWindow* pInstance = static_cast<MainWindow*>(pUser);
    if (!pInstance) {
        return;
    }
    emit pInstance->insPlayPush(QString::fromLocal8Bit(szDesc), QString::fromLocal8Bit(szContent), QString::fromLocal8Bit(szDetail));
}

void MainWindow::pushTransparentHandler(const char* szDesc, const char* szContent, const char* szDetail, void* pUser)
{
    qDebug() << __LINE__ << __FUNCTION__ << szDesc;
    qDebug() << __LINE__ << __FUNCTION__ << szContent;
    MainWindow* pInstance = static_cast<MainWindow*>(pUser);
    if (!pInstance) {
        return;
    }
    emit pInstance->insPlayPush(QString::fromLocal8Bit(szDesc), QString::fromLocal8Bit(szContent), QString::fromLocal8Bit(szDetail));
}

void MainWindow::videoDataHandler(DataType enType, char* const pData, int iLen, void* pUser)
{
	//qDebug() << __LINE__ << __FUNCTION__ <<"enType:"<< enType << "iLen:" << iLen;

    MainWindow * mainWins = (MainWindow *)pUser;
    if(mainWins->curVideoPath().isEmpty())
    {
        return ;
    }
    if (LocalSetting::getInstance()->saveData())
    {
        std::ofstream file;
        file.open(mainWins->curVideoPath().toStdString().c_str(), std::ios::binary|std::ios::app);
        file.write(pData,iLen);
        file.flush();
        file.close();
    }
}

void MainWindow::on_insRecordFile(const QByteArray &messageInfo)
{
    m_playBackTableModel->setRecordModel(messageInfo);
    m_jsonTextBrowser->clear();
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(messageInfo.data(), value)) {
        m_jsonTextBrowser->setText(value.toStyledString().c_str());
    }
    ui->tabWidget->setCurrentIndex(PlayBackTableIndex);
}

/*! @function Login
 * \brief MainWindow::on_loginButton_clicked
 */
void MainWindow::on_loginButton_clicked()
{
    m_loginWindow->clearParam();
    m_loginWindow->exec();
    QString accessId;
    m_loginWindow->getTokenFromLogin(accessId);
	if (accessId.isEmpty())
	{
		return ;
	}
    OpenNetStream::getInstance()->setAccessToken(accessId);
    const char* pTokenExpireTime = OpenNetStream::getInstance()->getTokenExpireTime();
    if (pTokenExpireTime != NULL)
    {
        qDebug() << __LINE__ << __FUNCTION__ << "Token Expire Time:" << pTokenExpireTime;
    }
    const char* pAreaDomain = OpenNetStream::getInstance()->getAreaDomain();
    if (pAreaDomain != NULL)
    {
        qDebug() << __LINE__ << __FUNCTION__ << "Platform Domain:" << pAreaDomain;
    }
    
    on_deviceListButton_clicked();
}

/*! @function Add Device
 * \brief MainWindow::on_deviceAddButton_clicked
 */
void MainWindow::on_deviceAddButton_clicked()
{
	//Add Device Success, Update Device List
    std::string strAccessToken = OpenNetStream::getInstance()->getAccessToken();
    if(strAccessToken.empty())
    {
        return ;
    }
    QString accessId = QString::fromStdString(strAccessToken);
    if(OpenNetStream::getInstance()->deviceAdd(accessId) == OPEN_SDK_NOERROR)
	{
		on_deviceListButton_clicked();
	}
}

/*! @function Stop RealPlay
 * \brief MainWindow::on_stopRealPlayButton_clicked
 */
void MainWindow::on_stopRealPlayButton_clicked()
{
	//Not ReapPlayStarted
	if (m_bRealPlayStarted == false)
	{
		return ;
	}
	int iRet = OpenNetStream::getInstance()->stopRealPlayEx(m_sessionId);
	if (iRet != OPEN_SDK_NOERROR)
	{
		this->showErrInfo(tr("Stop play failed!"));
	}
	m_bRealPlayStarted = false;
}

/*! @function Get PlayBack List
 * \brief MainWindow::on_playBackListButton_clicked
 */
void MainWindow::on_playBackListButton_clicked()
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return ;
    }

    bool bEncrypt = stDeviceInfo.bEncrypt;
    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;
	
    QString startTime = ui->PbStartTime->text();
    QString stopTime = ui->PbEndTime->text();

    if (startTime.toStdString().empty() || stopTime.toStdString().empty()) {
        QMessageBox::information(this, tr("Playback List"), tr("Please click on the 'select search time' button, select a day"));
        return;
    }

    m_playBackTableModel->setIsEncrypt(bEncrypt);
    m_playBackTableModel->setDevSerial(devSerial);
    m_playBackTableModel->setChannelNo(iChannelNo);
	int iRet = OpenNetStream::getInstance()->startSearch(m_sessionId, devSerial, iChannelNo, startTime, stopTime);

	if (iRet != OPEN_SDK_NOERROR)
	{
		this->showErrInfo(tr("Query video record failed!"));
	}
}

/*! @function Start PlayBack
 * \brief MainWindow::on_startPlayBackButton_clicked
 */
void MainWindow::on_startPlayBackButton_clicked()
{
    QModelIndex index = m_playBackTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::information(this, tr("Playback List"), tr("Please choose a time period in playback list first"));
        ui->tabWidget->setCurrentIndex(PlayBackTableIndex);
        return;
    }
	QString safekey;
	safekey.clear();
	if(1 == m_playBackTableModel->isEncrypt()) // Judge device is encrypted
	{
		bool ok;
		safekey = QInputDialog::getText(this, tr("Input"), tr("Please input the verification code"), QLineEdit::Password, "", &ok);
		if (ok == false)
		{
			return;
		}
	}
    QString devSerial = m_playBackTableModel->getDevSerial();
    int     iChannelNo = m_playBackTableModel->getChannelNo();
    QString beginTime = ui->PbStartTime->text();
    QString endTime = ui->PbEndTime->text();
	//Set the video store path
	setVideoPath(devSerial);
    OpenNetStream::getInstance()->setDataCallBack(m_sessionId, videoDataHandler, this);

	HWND hWnd = NULL;
	if (LocalSetting::getInstance()->isPlay())
	{
		hWnd = (HWND)ui->previewWindow->winId();
	}
    int iRet = 0;
    if (LocalSetting::getInstance()->download())
    {
         iRet = OpenNetStream::getInstance()->startDownload(m_sessionId, devSerial, iChannelNo, safekey, beginTime, endTime);
    }
    else
    {
         iRet = OpenNetStream::getInstance()->startPlayBack(m_sessionId, hWnd, devSerial, iChannelNo, safekey, beginTime, endTime);   
    }
    
    if(0 != iRet)
    {
		this->showErrInfo(tr("Playback failed!"));
        return;
    }
	m_bPlayBackStarted = true;
	m_bPlayBackFinished = false;
}

void MainWindow::displayosd()
{
    STREAM_TIME osdTime = STREAM_TIME();
    int iRet = OpenNetStream::getInstance()->getOSDTime(m_sessionId, &osdTime);
    if(OPEN_SDK_NOERROR != iRet)
    {
        this->showErrInfo(tr("Get OSD failed!"));
        return;
    } 

    char szTime[20] = {};
    sprintf(szTime, "%02d:%02d:%02d", osdTime.iHour, osdTime.iMinute, osdTime.iSecond);
    ui->osdLabel->setText(szTime);
}

/*! @function Stop playback
 * \brief MainWindow::on_stopPlayBackButton_clicked
 */
void MainWindow::on_stopPlayBackButton_clicked()
{
	//Not PlayBack Started
	if (m_bPlayBackStarted == false)
	{
		return ;
	}
    int iRet = 0;
    if (LocalSetting::getInstance()->download())
    {
        iRet = OpenNetStream::getInstance()->stopDownload(m_sessionId);
    }
    else
    {
	    iRet = OpenNetStream::getInstance()->stopPlayBackEx(m_sessionId);
    }
    
	m_bPlayBackStarted = false;
    if (m_osdTimer) {
        m_osdTimer->deleteLater();
        m_osdTimer = NULL;
    }
	if(OPEN_SDK_NOERROR != iRet)
	{
		this->showErrInfo(tr("Play stop failed!"));
	}
}

/*! @function pause playback
 * \brief MainWindow::on_pauseButton_clicked
 */
void MainWindow::on_pauseButton_clicked()
{
	//Not PlayBack Started
	if (m_bPlayBackStarted == false)
	{
		return ;
	}
	int iRet = OpenNetStream::getInstance()->playBackPause(m_sessionId);
	if(OPEN_SDK_NOERROR != iRet)
	{
		this->showErrInfo(tr("Play pause failed!"));
	}
    if (m_osdTimer) m_osdTimer->stop();
}

/*! @function Resume playback
 * \brief MainWindow::on_resumeButton_clicked
 */
void MainWindow::on_resumeButton_clicked()
{
	//Not PlayBack Started
	if (m_bPlayBackStarted == false)
	{
		return ;
	}
    int iRet = OpenNetStream::getInstance()->playBackResume(m_sessionId);
	if(OPEN_SDK_NOERROR != iRet)
	{
		this->showErrInfo(tr("playback resume failed!"));
	}
    if (m_osdTimer) m_osdTimer->start(1000);
}

/*! @function Get Device List
 * \brief MainWindow::on_deviceListButton_clicked
 */
void MainWindow::on_deviceListButton_clicked()
{
    int lPageStart = LocalSetting::getInstance()->PageStart();
    int lPageSize = LocalSetting::getInstance()->PageSize();
    int pageStart = 0;
    if(lPageStart > 0)
    {
        pageStart = lPageStart;
    }
    int pageSize = 1000;
    if (lPageSize > 0)
    {
        pageSize = lPageSize;
    }
    void* pBuf = NULL;
    int length = 0;

    int iRet = OpenNetStream::getInstance()->getDevListEx(pageStart, pageSize, &pBuf, &length);
	if (iRet != OPEN_SDK_NOERROR)
	{
		this->showErrInfo(tr("Get Device List failed!"));
        return ;
	}
    QString json;
    if (LocalSetting::getInstance()->dataUtf8())
    {
        json = static_cast<char*>(pBuf);
    }
    else
    {
        json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    }
    
    OpenNetStream::getInstance()->freeData(pBuf);

    QByteArray jsonByte = json.toUtf8();
    m_deviceTableModel->setCameraModel(jsonByte);
    m_jsonTextBrowser->clear();
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(jsonByte.data(), value)) {
		m_jsonTextBrowser->setText( value.toStyledString().c_str() );
    }
    ui->tabWidget->setCurrentIndex(DeviceTableIndex);
}

/*! @function Alarm List
 * \brief MainWindow::on_alarmListButton_clicked
 */
void MainWindow::on_alarmListButton_clicked()
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return ;
    }

    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

    QDate date;
	int ret	= QCalendarProxy::selectedDate(tr("Please select a date"), date);
	if (ret == CalendarNone)
	{
		return ;
	}
    QString startTime = date.toString("yyyy-MM-dd 00:00:00");
    QString stopTime  = date.toString("yyyy-MM-dd 23:59:59");

    int pageStart = 0;
    int pageSize = 999;

    void* pBuf = NULL;
    int length = 0;
    int iRet = OpenNetStream::getInstance()->getAlarmList(devSerial, iChannelNo, startTime, stopTime, -1/*All*/, 2 /*All*/, pageStart, pageSize, &pBuf, &length);
	if(OPEN_SDK_NOERROR != iRet)
	{
		this->showErrInfo(tr("Get alarm list failed!"));
		return ;
	}
    QString json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    OpenNetStream::getInstance()->freeData(pBuf);

    QByteArray jsonByte = json.toUtf8();
    m_alarmTableModel->setAlarmModel(jsonByte);
    m_jsonTextBrowser->clear();
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(jsonByte.data(), value)) {
        m_jsonTextBrowser->setText(value.toStyledString().c_str());
    }
    ui->tabWidget->setCurrentIndex(AlarmTableIndex);
}

/*! @function Capture Picture
 * \brief MainWindow::on_capturePictureButton_clicked
 */
void MainWindow::on_capturePictureButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), "CapturePicture.jpeg", "*.jpeg");
    if (!filename.endsWith(".jpeg")) {
        filename.append(".jpeg");
    }

    int iRet = OpenNetStream::getInstance()->capturePicture(m_sessionId, filename.toUtf8());
    if (iRet != 0) {
		this->showErrInfo(tr("Save the picture failed!"));
    }
}

/*! @function Start Voice Talk
 * \brief MainWindow::on_startVoiceTalkButton_clicked
 */
void MainWindow::on_startVoiceTalkButton_clicked()
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return ;
    }

    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

    int iRet = OpenNetStream::getInstance()->startVoiceTalk(m_sessionId, devSerial, iChannelNo);
	if(iRet != 0)
	{
		this->showErrInfo(tr("Start voice talk failed!"));
	}
}

/*! @function Stop voice talk
 * \brief MainWindow::on_stopVoiceTalkButton_clicked()
 */
void MainWindow::on_stopVoiceTalkButton_clicked()
{
    int iRet;
	iRet = OpenNetStream::getInstance()->stopVoiceTalk(m_sessionId);
    if (iRet != 0) {
		this->showErrInfo(tr("Stop voice talk failed!"));
    }
}

/*! @function Open and close sound
 * \brief MainWindow::on_switchSoundButton_clicked()
 */
void MainWindow::on_switchSoundButton_clicked()
{
    if (ui->switchSoundButton->isChecked()) {
        ui->setVolumeSlider->setEnabled(true);
        OpenNetStream::getInstance()->openSound(m_sessionId);
        int tValue=OpenNetStream::getInstance()->getVolume(m_sessionId);
        ui->setVolumeSlider->setValue(tValue);
    } else {
        ui->setVolumeSlider->setDisabled(true);
        OpenNetStream::getInstance()->closeSound(m_sessionId);
        ui->setVolumeSlider->setValue(0);
    }
}

/*! @function adjust the sound
 * \brief MainWindow::on_setVolumeSlider_sliderReleased()
 */
void MainWindow::on_setVolumeSlider_sliderReleased()
{
    OpenNetStream::getInstance()->setVolume(m_sessionId, (unsigned short)ui->setVolumeSlider->value());
}

/*! @function Start Push Recv
 * \brief MainWindow::on_startPushRecvButton_clicked()
 */
void MainWindow::on_startPushRecvButton_clicked()
{
	QString pushSecret = LocalSetting::getInstance()->pushSecret();
    int iRet = OpenNetStream::getInstance()->Push_StartRecv(pushSecret);
    QString respString;
    if (iRet == 0)
    {
        respString = tr("Start Push Success.");
        QMessageBox::information(this, tr("Push Open Status"), respString);
    }
    else
    {
        this->showErrInfo(respString);
    }
}

/*! @function Stop Push Recv
 * \brief MainWindow::on_stopPushRecvButton_clicked()
 */
void MainWindow::on_stopPushRecvButton_clicked()
{
    int iRet = OpenNetStream::getInstance()->Push_StopRecv();
    QString respString;
    if(iRet == 0)
    {
        respString = tr("Stop push recv success.");
        QMessageBox::information(this, tr("Push Close Status"), respString);
    }
    else
    {
        respString = tr("Stop push recv failed!");
        this->showErrInfo(respString);
    }
}

void MainWindow::on_insPlayException(unsigned errorCode, const QByteArray& messageInfo)
{
    Q_UNUSED(messageInfo);
    if (m_osdTimer) {
        m_osdTimer->deleteLater();
        m_osdTimer = NULL;
    }
    QString desc = ConvertPlayErrorToMessage(messageInfo)+"(" + messageInfo + ":" + QString::number(errorCode)+ ")";
    QString errorInfo = tr("Play Exception");
    QMessageBox::information(this, errorInfo, desc);
}

void MainWindow::on_insPlayBackEnd(unsigned errorCode)
{
	if (!m_bPlayBackFinished)
	{
		m_bPlayBackFinished = true;
        if (m_osdTimer) {
            m_osdTimer->deleteLater();
            m_osdTimer = NULL;
        }
		QMessageBox::information(this, tr("Playback end"), m_videoPath);
	}
}

void MainWindow::on_insPlayReconnectException(unsigned errorCode, const QByteArray& messageInfo)
{
    Q_UNUSED(messageInfo);
    QString errorString = tr("Reconnection exception,") + "errorCode = " + QString::number(errorCode);
    QMessageBox::information(this, tr("Reconnection exception"), errorString);
}

void MainWindow::on_insRecordSearchFailed(unsigned errorCode, const QByteArray& messageInfo)
{
    Q_UNUSED(messageInfo);
    QString errorString = tr("Search playback exception,") + "errorCode = " + QString::number(errorCode);
    QMessageBox::information(this, tr("Search playback exception"), errorString);
}

void MainWindow::on_insPlayAlarm(QString szCameraId, QString szContent, QString szAlarmTime)
{
    Json::FastWriter write;
    Json::Value value;
    value["cameraId"] = szCameraId.toStdString();
    value["content"] = szContent.toStdString();
    value["alarmTime"] = szAlarmTime.toStdString();
    QString json_str(write.write(value).c_str());

    QMessageBox::information(this, tr("alarm popup"), json_str);
}

void MainWindow::on_insPlayPush(QString szDesc, QString szContent, QString szDetail)
{
	Json::FastWriter write;
	Json::Value value;
	value["content"] = szContent.toStdString();
	QString json_str(write.write(value).c_str());
    QMessageBox::information(this, tr("Push popup:") + szDesc, json_str);
}

void MainWindow::on_insPtzStartUp()
{
	on_insPtzStart(DIRECT_UP);
}
void MainWindow::on_insPtzStartDown()
{
	on_insPtzStart(DIRECT_DOWN);
}
void MainWindow::on_insPtzStartLeft()
{
	on_insPtzStart(DIRECT_LEFT);
}

void MainWindow::on_insPtzStartRight()
{
	on_insPtzStart(DIRECT_RIGHT);
}
void MainWindow::on_insPtzStartUpLeft()
{
	on_insPtzStart(DIRECT_UPLEFT);
}
void MainWindow::on_insPtzStartDownLeft()
{
	on_insPtzStart(DIRECT_DOWNLEFT);
}
void MainWindow::on_insPtzStartUpRight()
{
	on_insPtzStart(DIRECT_UPRIGHT);
}
void MainWindow::on_insPtzStartDownRight()
{
	on_insPtzStart(DIRECT_DOWNRIGHT);
}

void MainWindow::on_insPtzStopUp()
{
	on_insPtzStop(DIRECT_UP);
}
void MainWindow::on_insPtzStopDown()
{
	on_insPtzStop(DIRECT_DOWN);
}
void MainWindow::on_insPtzStopLeft()
{
	on_insPtzStop(DIRECT_LEFT);
}

void MainWindow::on_insPtzStopRight()
{
	on_insPtzStop(DIRECT_RIGHT);
}
void MainWindow::on_insPtzStopUpLeft()
{
	on_insPtzStop(DIRECT_UPLEFT);
}
void MainWindow::on_insPtzStopDownLeft()
{
	on_insPtzStop(DIRECT_DOWNLEFT);
}
void MainWindow::on_insPtzStopUpRight()
{
	on_insPtzStop(DIRECT_UPRIGHT);
}
void MainWindow::on_insPtzStopDownRight()
{
	on_insPtzStop(DIRECT_DOWNRIGHT);
}

void MainWindow::on_insPtzStartZoomIn()
{
    on_insPtzStart(PTZ_ZOOMIN);
}
void MainWindow::on_insPtzStartZoomOut()
{
    on_insPtzStart(PTZ_ZOOMOUT);
}

void MainWindow::on_insPtzStopZoomIn()
{
    on_insPtzStop(PTZ_ZOOMIN);
}
void MainWindow::on_insPtzStopZoomOut()
{
    on_insPtzStop(PTZ_ZOOMOUT);
}

void MainWindow::on_insPtzStartFocusFar()
{
    on_insPtzStart(PTZ_FOCUSFAR);
}

void MainWindow::on_insPtzStartFocusNear()
{
    on_insPtzStart(PTZ_FOCUSNEAR);
}

void MainWindow::on_insPtzStopFocusFar()
{
    on_insPtzStop(PTZ_FOCUSFAR);
}

void MainWindow::on_insPtzStopFocusNear()
{
    on_insPtzStop(PTZ_FOCUSNEAR);
}

void MainWindow::on_insPtzStartIrisStartUp()
{
    on_insPtzStart(PTZ_IRISSTARTUP);
}

void MainWindow::on_insPtzStartIrisStopDown()
{
    on_insPtzStart(PTZ_IRISSTOPDOWN);
}

void MainWindow::on_insPtzStopIrisStartUp()
{
    on_insPtzStop(PTZ_IRISSTARTUP);
}

void MainWindow::on_insPtzStopIrisStopDown()
{
    on_insPtzStop(PTZ_IRISSTOPDOWN);
}

void MainWindow::on_insPtzAutoStartUp()
{
	on_insPtzStart(PTZ_AUTO);
}

void MainWindow::on_insPtzAutoStopDown()
{
	on_insPtzStop(PTZ_AUTO);
}

void MainWindow::on_insPtzStart(PTZCMD emDirect)
{
    if (m_devSerial.isEmpty()) {
        QMessageBox::information(this, tr("PTZ Control"), tr("Please start real play before PTZ Control"));
        return;
    }
	int iRet = 0;

    switch (emDirect)
    {
    case DIRECT_UP:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, UP, START, PTZ_SPEED);
        break;
    case DIRECT_DOWN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, DOWN, START, PTZ_SPEED);
        break;
    case DIRECT_LEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, LEFT, START, PTZ_SPEED);
        break;
    case DIRECT_RIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, RIGHT, START, PTZ_SPEED);
        break;
    case DIRECT_UPLEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, UPLEFT, START, PTZ_SPEED);
        break;
    case DIRECT_DOWNLEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, DOWNLEFT, START, PTZ_SPEED);
        break;
    case DIRECT_UPRIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, UPRIGHT, START, PTZ_SPEED);
        break;
    case DIRECT_DOWNRIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, DOWNRIGHT, START, PTZ_SPEED);
        break;
        break;
    case PTZ_ZOOMIN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, ZOOMIN, START, PTZ_SPEED);
        break;
    case PTZ_ZOOMOUT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, ZOOMOUT, START, PTZ_SPEED);
        break;
    case PTZ_IRISSTARTUP:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, IRISSTARTUP, START, PTZ_SPEED);
        break;
    case PTZ_IRISSTOPDOWN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, IRISSTOPDOWN, START, PTZ_SPEED);
        break;
	case PTZ_AUTO:
		iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, AUTO, START, PTZ_SPEED);
		break;
    default:
        break;
    }
    if (iRet != OPEN_SDK_NOERROR)
    {
        this->showErrInfo(tr("PTZ Control failed!"));
    }
}

void MainWindow::on_insPtzStop(PTZCMD emDirect)
{	
	int iRet = 0;

    switch (emDirect)
    {
    case DIRECT_UP:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, UP, STOP, PTZ_SPEED);
        break;
    case DIRECT_DOWN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, DOWN, STOP, PTZ_SPEED);
        break;
    case DIRECT_LEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, LEFT, STOP, PTZ_SPEED);
        break;
    case DIRECT_RIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, RIGHT, STOP, PTZ_SPEED);
        break;
    case DIRECT_UPLEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, UPLEFT, STOP, PTZ_SPEED);
        break;
    case DIRECT_DOWNLEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, DOWNLEFT, STOP, PTZ_SPEED);
        break;
    case DIRECT_UPRIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, UPRIGHT, STOP, PTZ_SPEED);
        break;
    case DIRECT_DOWNRIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, DOWNRIGHT, STOP, PTZ_SPEED);
        break;
    case PTZ_ZOOMIN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, ZOOMIN, STOP, PTZ_SPEED);
        break;
    case PTZ_ZOOMOUT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, ZOOMOUT, STOP, PTZ_SPEED);
        break;
    case PTZ_IRISSTARTUP:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, IRISSTARTUP, STOP, PTZ_SPEED);
        break;
    case PTZ_IRISSTOPDOWN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, IRISSTOPDOWN, STOP, PTZ_SPEED);
        break;
	case PTZ_AUTO:
		iRet = OpenNetStream::getInstance()->PTZCtrl(m_sessionId, m_devSerial, m_Channel, AUTO, STOP, PTZ_SPEED);
    default:
        break;
    }
	if (iRet != OPEN_SDK_NOERROR)
	{
		this->showErrInfo(tr("PTZ Control failed."));
	}
}

void MainWindow::on_insPlayStart()
{
    if (!m_osdTimer) {
        m_osdTimer = new QTimer(this);
        connect(m_osdTimer, SIGNAL(timeout()), this, SLOT(displayosd()));
        m_osdTimer->start(1000);
    }
}

void MainWindow::on_insPlayStop()
{
    if (m_osdTimer) {
        m_osdTimer->deleteLater();
        m_osdTimer = NULL;
    }
}


void MainWindow::on_smoothAction()
{
    if(switchVideoLevel(VideoSmooth) == 0)
	{
		updateVideoLevelBtn(VideoSmooth);
	}
}

void MainWindow::on_equilibriumAction()
{
	if(switchVideoLevel(VideoBalanced) == 0)
	{
		updateVideoLevelBtn(VideoBalanced);
	}
}

void MainWindow::on_clearAction()
{
	if(switchVideoLevel(VideoClear) == 0)
	{
		updateVideoLevelBtn(VideoClear);
	}
}

void MainWindow::on_highAction()
{
    if(switchVideoLevel(VideoHigh) == 0)
    {
        updateVideoLevelBtn(VideoHigh);
    }
}

void MainWindow::on_insGetCameraInfo()
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return ;
    }

    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

	QString safekey;
	safekey.clear();
	void* pBuf = NULL;
	int iLen = 0;
	int iRet = OpenNetStream::getInstance()->GetDevDetailInfo(devSerial, iChannelNo, false, &pBuf, &iLen);
    if(iRet != 0)
    {
        this->showErrInfo(tr("Get Device Detail Info"));
		return;
    }
	QString json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
	OpenNetStream::getInstance()->freeData(pBuf);

	QByteArray jsonByte = json.toUtf8();
	m_jsonTextBrowser->clear();
	Json::Reader reader;
	Json::Value	value;
	if(reader.parse(jsonByte.data(), value)) {
		m_jsonTextBrowser->setText( value.toStyledString().c_str() );
        ui->tabWidget->setCurrentIndex(JsonInfoTableIndex);
	}
}

void MainWindow::on_insUpdateCameraInfo()
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return ;
    }

    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

    QString safekey;
    safekey.clear();
    void* pBuf = NULL;
    int iLen = 0;
    int iRet = OpenNetStream::getInstance()->GetDevDetailInfo(devSerial, iChannelNo, true, &pBuf, &iLen);
    if(iRet != 0)
    {
        this->showErrInfo(tr("Get Device Detail Info"));
        return;
    }
    QString json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    OpenNetStream::getInstance()->freeData(pBuf);

    QByteArray jsonByte = json.toUtf8();
    m_jsonTextBrowser->clear();
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(jsonByte.data(), value)) {
        m_jsonTextBrowser->setText( value.toStyledString().c_str() );
        ui->tabWidget->setCurrentIndex(JsonInfoTableIndex);
    }
}

int MainWindow::switchVideoLevel(int videoLevel)
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return -1;
    }

    bool bEncrypt = stDeviceInfo.bEncrypt;
    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

    int iRet = OpenNetStream::getInstance()->setVideoLevel(devSerial, iChannelNo, videoLevel);
    if(0 != iRet)
    {
        this->showErrInfo(tr("Switch Video Level"));
        return -1;
    }
    return 0;
}

int MainWindow::startRealPlay(int videoLevel)
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return -1;
    }

    bool bEncrypt = stDeviceInfo.bEncrypt;
    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;
    
    m_devSerial = devSerial;
    m_Channel = iChannelNo;

    QString safekey;
    safekey.clear();
    if(bEncrypt)
    {
		bool ok;
        safekey = QInputDialog::getText(this, tr("Input"), tr("Please Input the verification code"), QLineEdit::Password, "", &ok);
		if (ok == false)
		{
			return -1;
		}
    }
    
	//Set the video store path
	setVideoPath(devSerial);
	OpenNetStream::getInstance()->setDataCallBack(m_sessionId, videoDataHandler, this);

	HWND hWnd = NULL;
	if (LocalSetting::getInstance()->isPlay())
	{
		hWnd = (HWND)ui->previewWindow->winId();
	}
    int iRet = OpenNetStream::getInstance()->startRealPlay(m_sessionId, hWnd, devSerial, iChannelNo, safekey);
	if(0 != iRet)
	{
		this->showErrInfo(tr("RealPlay"));
        return -1;
	}
	m_bRealPlayStarted = true;
	return 0;
}

void MainWindow::on_setAlarmReadButton_clicked()
{
    QModelIndex index = m_alarmTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::information(this, tr("Set the alarm has been read"), tr("Please select a device in device list"));
        ui->tabWidget->setCurrentIndex(AlarmTableIndex);
        return;
    }
    QString alarmId = m_alarmTableModel->getAlarmId(index);
    qDebug()<<"werwer["<<alarmId<<"]"<<endl;

    std::string strAccessToken = OpenNetStream::getInstance()->getAccessToken();
    if(strAccessToken.empty())
    {
        return ;
    }
    QString accessId = QString::fromStdString(strAccessToken);

    int iRet = OpenNetStream::getInstance()->setAlarmRead(accessId, alarmId);
    QString strRetString;
    if (iRet == 0)
    {
        strRetString = tr("Set Success!") + "iRet = " + QString::number(iRet);
		m_alarmTableModel->setAlarmChecked(index);
    }
    else
    {
        strRetString = tr("Set Failed!") + "iRet = " + QString::number(iRet);
    }
    QMessageBox::information(this, tr("Set the alarm has been read"), strRetString);
}

void MainWindow::on_defenceOnButton_clicked()
{
    doDefence(true);
}

void MainWindow::on_defenceOffButton_clicked()
{
    doDefence(false);
}

void MainWindow::doDefence(bool iOnOrOff)
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return ;
    }

    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

    int iRet = -1;
    if(iOnOrOff)
    {
        iRet = OpenNetStream::getInstance()->DevDefence(m_sessionId, devSerial, iChannelNo, GLOBAL, DEFENCE, V);
    }
    else
    {
        iRet = OpenNetStream::getInstance()->DevDefence(m_sessionId, devSerial, iChannelNo, GLOBAL, UN_DEFENCE, V);
    }

    QString strRetString;
    if (iRet != -1)
    {
        strRetString = tr("Set Success!") + "iRet = " + QString::number(iRet);
		QMessageBox::information(this, tr("Defence"), strRetString);
    }
    else
    {
        strRetString = tr("Set Failed!") + "iRet = " + QString::number(iRet);
		this->showErrInfo(strRetString);
    }
}

void MainWindow::showErrInfo(QString caption)
{
	int iErrCode = OpenNetStream::getInstance()->GetLastErrorCode();
    char szBuf[64] = {0};
	sprintf(szBuf, "ErrorCode:%d", iErrCode);
	QMessageBox::information(this, caption, szBuf);
}

void MainWindow::slotDeviceTableViewPressed(const QModelIndex & index)
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return ;
    }
    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;
    int iLevel  = stDeviceInfo.iVideoLevel;
    
    updateVideoLevelBtn(iLevel);

    QString safekey;
    safekey.clear();
    void* pBuf = NULL;
    int iLen = 0;
    int iRet = OpenNetStream::getInstance()->GetDevDetailInfo(devSerial, iChannelNo, false, &pBuf, &iLen);
    if(iRet != 0)
    {
        return;
    }
    QString json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    OpenNetStream::getInstance()->freeData(pBuf);
    QByteArray jsonByte = json.toUtf8();
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(jsonByte.data(), value)) {
        Json::Value lVideoQuality = value["videoQualityInfos"];
        if (lVideoQuality.isArray())
        {
            m_realPlayMenu->clear();
            for (int i=0; i < lVideoQuality.size(); i++)
            {
                Json::Value videoQualityObj = lVideoQuality[i];
                if (!videoQualityObj["videoQualityName"].isString() || !videoQualityObj["videoLevel"].isInt())
                {
                    continue;
                }
                std::string strVideoQualityName = videoQualityObj["videoQualityName"].asString();
                int iVideoLevel = videoQualityObj["videoLevel"].asInt();
                QAction* videoAction = m_realPlayMenu->addAction(strVideoQualityName.c_str());
                if (VideoSmooth == iVideoLevel)
                {
                    connect(videoAction, SIGNAL(triggered()), this, SLOT(on_smoothAction()));
                }
                else if(VideoBalanced == iVideoLevel)
                {
                    connect(videoAction, SIGNAL(triggered()), this, SLOT(on_equilibriumAction()));
                }
                else if (VideoClear == iVideoLevel)
                {
                    connect(videoAction, SIGNAL(triggered()), this, SLOT(on_clearAction()));
                }
                else if (VideoHigh == iVideoLevel)
                {
                    connect(videoAction, SIGNAL(triggered()), this, SLOT(on_highAction()));
                }
            }
        }
    }
}

void MainWindow::slotPlayBackTableViewPressed(const QModelIndex &index)
{
    QString pbStartTime = m_playBackTableModel->getStartTime(index);
    QString pbEndTime = m_playBackTableModel->getStopTime(index);
    ui->PbStartTime->setText(pbStartTime);
    ui->PbEndTime->setText(pbEndTime);
}

void MainWindow::slotPushAlarmTableViewPressed(const QModelIndex & index)
{
    QString pbStartTime = m_pushAlarmTableModel->getAlarmTime(index);
    ui->PbStartTime->setText(pbStartTime);
    ui->PbEndTime->setText(pbStartTime);
}

void MainWindow::updateVideoLevelBtn(const int iLevel)
{
	switch(iLevel)
	{
	case VideoSmooth:
		ui->startRealPlayButton->setText(tr("Play-liquid"));
		break;
	case VideoBalanced:
		ui->startRealPlayButton->setText(tr("Play-Balance"));
		break;
	case VideoClear:
		ui->startRealPlayButton->setText(tr("Play-High"));
        break;
    case VideoHigh:
        ui->startRealPlayButton->setText(tr("Play-Supper"));
        break;
	}
    if (ui->tabWidget->currentIndex() == DeviceTableIndex)
    {
        QModelIndex index = m_deviceTableView->currentIndex();
        if (!index.isValid()) {
            return ;
        }
        m_deviceTableModel->setVideoLevel(index, iLevel);
    }
    else if(ui->tabWidget->currentIndex() == SharedDeviceIndex)
    {
        QModelIndex index = m_shareDevTableView->currentIndex();
        if (!index.isValid()) {
            return ;
        }
        m_shareDevTableModel->setVideoLevel(index, iLevel);
    }
}

void MainWindow::on_pushAlarmCheckBox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
        OpenNetStream::getInstance()->Push_SetAlarmCallBack(pushAlarmHandler, this);
    }
    else
    {
        OpenNetStream::getInstance()->Push_SetAlarmCallBack(NULL, NULL);
    }
}

void MainWindow::on_pushDevStatusCheckBox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
        OpenNetStream::getInstance()->Push_SetDeviceStatusCallBack(pushDevStatusHandler, this);
    }
    else
    {
        OpenNetStream::getInstance()->Push_SetDeviceStatusCallBack(NULL, NULL);
    }
}

void MainWindow::on_pushTransparentChannelCheckBox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
        OpenNetStream::getInstance()->Push_SetTransparentChannelCallBack(pushTransparentHandler, this);
    }
    else
    {
        OpenNetStream::getInstance()->Push_SetTransparentChannelCallBack(NULL, NULL);
    }
}

QString MainWindow::ConvertPlayErrorToMessage(const char* szError)
{
    if (NULL == szError)
    {
        return "";
    }
    QString msg;
    if (strcmp(OPEN_SDK_STREAM_ACCESSTOKEN_ERROR_OR_EXPIRE, szError) == 0)
    {
        msg = tr("Accesstoken expire or invalid. update accesstoken.");
    }
    else if (strcmp(OPEN_SDK_STREAM_PU_NO_RESOURCE, szError) == 0)
    {
        msg = tr("Device connection is too many, upgrade the device version, Hikvision devices can consult customer service to obtain the upgrade process.");
    }
    else if (strcmp(OPEN_SDK_STREAM_TRANSF_DEVICE_OFFLINE, szError) == 0)
    {
        msg = tr("Device offline. Connect the device to network and try again.");
    }
    else if (strcmp(OPEN_SDK_STREAM_INNER_TIMEOUT, szError) == 0)
    {
        msg = tr("Request to connect device to timeout, detect device network connection is normal.");
    }
    else if (strcmp(OPEN_SDK_STREAM_INNER_VERIFYCODE_ERROR, szError) == 0)
    {
        msg = tr("Video verificaiton code error, check the verification code marked on the device.");
    }
    else if (strcmp(OPEN_SDK_STREAM_PLAY_FAIL, szError) == 0)
    {
        msg = tr("Failed to play the video, please check the message callback specific error code iErrorCode.");
    }
    else if (strcmp(OPEN_SDK_STREAM_TRANSF_TERMINAL_BINDING, szError) == 0)
    {
        msg = tr("The current account has enabled terminal binding. Only the specified device can log in.");
    }
    else if (strcmp(OPEN_SDK_STREAM_VIDEO_RECORD_NOTEXIST, szError) == 0)
    {
        msg = tr("Video record not found.");
    }
    else if (strcmp(OPEN_SDK_STREAM_VTDU_CONCURRENT_LIMIT, szError) == 0)
    {
        msg = tr("Take the flow of concurrent route restrictions, please upgrade to Enterprise Edition.");
    }
    else if (strcmp(OPEN_SDK_STREAM_UNSUPPORTED, szError) == 0)
    {
        msg = tr("The type of resolution that the device does not support is selected according to the device preview capability level.");
    }
    else
    {
        msg = tr("Failed to play the video");
    }
    
    return msg;
}

bool  MainWindow::GetDeviceTableViewInfo(DeviceTableViewInfo& stDeviceInfo)
{
    if (ui->tabWidget->currentIndex() == DeviceTableIndex)
    {
        QModelIndex index = m_deviceTableView->currentIndex();
        if (!index.isValid()) {
            QMessageBox::information(this, tr("Device List"), tr("Please select a device in device list"));
            ui->tabWidget->setCurrentIndex(DeviceTableIndex);
            return false;
        }
        stDeviceInfo.strSubserial = m_deviceTableModel->getSerial(index);
        stDeviceInfo.iChannelNo = m_deviceTableModel->getCameraNo(index);
        stDeviceInfo.bEncrypt = m_deviceTableModel->getIsEncrypt(index);
        stDeviceInfo.iVideoLevel = m_deviceTableModel->getVideoLevel(index);
    }
    else if(ui->tabWidget->currentIndex() == SharedDeviceIndex)
    {
        QModelIndex index = m_shareDevTableView->currentIndex();
        if (!index.isValid()) {
            QMessageBox::information(this, tr("Shared Device List"), tr("Please select a device in shared device list"));
            ui->tabWidget->setCurrentIndex(SharedDeviceIndex);
            return false;
        }
        stDeviceInfo.strSubserial = m_shareDevTableModel->getSerial(index);
        stDeviceInfo.iChannelNo = m_shareDevTableModel->getCameraNo(index);
        stDeviceInfo.bEncrypt = m_shareDevTableModel->getIsEncrypt(index);
        stDeviceInfo.iVideoLevel = m_shareDevTableModel->getVideoLevel(index);
    }
    else
    {
        QMessageBox::information(this, tr("Device List"), tr("Please select a device in device list"));
        ui->tabWidget->setCurrentIndex(DeviceTableIndex);
        return false;
    }
    return true;
}

void MainWindow::on_showAlarmPicButton_clicked()
{
    QModelIndex pushIndex = m_pushAlarmTableView->currentIndex();
    if (!pushIndex.isValid()) {
        QMessageBox::information(this, tr("Alarm Picture"), tr("Please select an alarm from push alarm list"));
        ui->tabWidget->setCurrentIndex(AlarmTableIndex);
        return;
    }

    std::string strAccessToken = OpenNetStream::getInstance()->getAccessToken();
    if(strAccessToken.empty())
    {
        return ;
    }

    QString devSerial;
    QString picUrl;
    bool    isEncrypt = false;

    devSerial = m_pushAlarmTableModel->getDeviceSerial(pushIndex);
    picUrl = m_pushAlarmTableModel->getPicUrl(pushIndex);
    isEncrypt = m_pushAlarmTableModel->isEncrypt(pushIndex);
  
    QString safekey;
    if (isEncrypt)
    {
        bool ok;
        safekey = QInputDialog::getText(this, tr("Input"), tr("Please input the verification code"), QLineEdit::Password, "", &ok);
        if (ok == false)
        {
            return ;
        }
    }
	
    void* pBuf;
    int iLen;
    int iRet = OpenNetStream::getInstance()->DecryptPicture(strAccessToken.c_str(), picUrl.toStdString().c_str(), devSerial.toStdString().c_str(), safekey.toStdString().c_str(), &pBuf, &iLen);
    if(iRet != OPEN_SDK_NOERROR)
    {
        this->showErrInfo(tr("the alarm picture decryption failed!"));
		return ;
    }
    
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), "alarm.jpeg", "*.jpeg");
	if (!filename.endsWith(".jpeg")) {
		filename.append(".jpeg");
	}
	if(filename.isEmpty())
	{
		return;
	}
	else
    {
        setlocale(LC_ALL,"");
        std::ofstream file;
        std::string strFilePath = UTF8ToANSIString(filename.toUtf8().data());
        file.open(strFilePath.c_str(), std::ios::binary|std::ios::app);
        file.write((char*)pBuf,iLen);
        file.flush();
        file.close();
        setlocale(LC_ALL,"C");
	}
	OpenNetStream::getInstance()->freeData(pBuf);

}

void MainWindow::on_startRealPlayButton_clicked()
{
    startRealPlay(0);
}

void MainWindow::on_setPlayBackTimeButton_clicked()
{
    QDate date;
    int ret = QCalendarProxy::selectedDate(tr("Please select a date"), date);
    if (ret == CalendarNone)
    {
        return ;
    }
    QString startTime = date.toString("yyyy-MM-dd 00:00:00");
    QString stopTime  = date.toString("yyyy-MM-dd 23:59:59");
    ui->PbStartTime->setText(startTime);
    ui->PbEndTime->setText(stopTime);
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QString token = QInputDialog::getText(this, tr("Input"), tr("Please input AccessToken"), QLineEdit::Normal, "", &ok);
    if (ok == false)
    {
        return ;
    }
    if (token.isEmpty())
    {
        return ;
    }
    OpenNetStream::getInstance()->setAccessToken(token);
}

void MainWindow::on_shareDevListButton_clicked()
{
    int lPageStart = LocalSetting::getInstance()->PageStart();
    int lPageSize = LocalSetting::getInstance()->PageSize();
    int pageStart = 0;
    if(lPageStart > 0)
    {
        pageStart = lPageStart;
    }
    int pageSize = 1000;
    if (lPageSize > 0)
    {
        pageSize = lPageSize;
    }
    void* pBuf = NULL;
    int length = 0;

    if (LocalSetting::getInstance()->dataUtf8())
    {
        OpenNetStream::getInstance()->setDataUtf8();
    }

    if (LocalSetting::getInstance()->streamTrans())
    {
        OpenNetStream::getInstance()->setStreamTrans();
    }

    if (LocalSetting::getInstance()->closeP2P())
    {
        OpenNetStream::getInstance()->closeP2P();
    }

    int iP2PMaxNum = LocalSetting::getInstance()->P2PMaxNum();
    if (iP2PMaxNum > 0)
    {
        OpenNetStream::getInstance()->setP2PMaxNum(iP2PMaxNum);
    }

    int iP2PCheckPeriod = LocalSetting::getInstance()->P2PCheckPeriod();
    if (iP2PCheckPeriod > 0)
    {
        OpenNetStream::getInstance()->setP2PCheckPeriod(iP2PCheckPeriod);
    }

    int iP2PExpire = LocalSetting::getInstance()->P2PExpire();
    if (iP2PExpire > 0)
    {
        OpenNetStream::getInstance()->setP2PExpire(iP2PExpire);
    }

    int iRet = OpenNetStream::getInstance()->getSharedDevList(pageStart, pageSize, &pBuf, &length);
    if (iRet != OPEN_SDK_NOERROR)
    {
        this->showErrInfo(tr("Get Device List failed!"));
        return ;
    }
    QString json;
    if (LocalSetting::getInstance()->dataUtf8())
    {
        json = static_cast<char*>(pBuf);
    }
    else
    {
        json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    }

    OpenNetStream::getInstance()->freeData(pBuf);

    QByteArray jsonByte = json.toUtf8();
    m_shareDevTableModel->setCameraModel(jsonByte);
    m_jsonTextBrowser->clear();
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(jsonByte.data(), value)) {
        m_jsonTextBrowser->setText( value.toStyledString().c_str() );
    }
    ui->tabWidget->setCurrentIndex(SharedDeviceIndex);
}

void MainWindow::on_logoutButton_clicked()
{
    OpenNetStream::getInstance()->logout();
}

void MainWindow::on_videoRecordBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        OpenNetStream::getInstance()->setSessionStreamTrans(m_sessionId, true);
    }
    else
    {
        OpenNetStream::getInstance()->setSessionStreamTrans(m_sessionId, false);
    }
}

void MainWindow::on_deviceInfoButton_clicked()
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
       return ;
    }

    std::string strAccessToken = OpenNetStream::getInstance()->getAccessToken();
    if(strAccessToken.empty())
    {
       return ;
    }
    QString accessId = QString::fromStdString(strAccessToken);
    QString devSerial = stDeviceInfo.strSubserial;

    void* pBuf = NULL;
    int length = 0;
    int iRet = OpenNetStream::getInstance()->getDevInfo(accessId, devSerial, &pBuf, &length);
    QString json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    OpenNetStream::getInstance()->freeData(pBuf);

    if(iRet == 0){
       QMessageBox::information(this, tr("Get device info"), json);
    }
    else
    {
       QMessageBox::information(this, tr("Get device info"), tr("Get device info failed!"));
    }
}
