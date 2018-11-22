#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opennetstream.h"
#include "opennetstream_p.h"

#include <QTextBrowser>
#include <QInputDialog>
#include <time.h>
#include <fstream>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    bInit_(false),
    bRealPlayStarted_(false)
{
    ui->setupUi(this);

    deviceTableView_ = new QTableView(this);
    deviceTableView_->setContextMenuPolicy(Qt::CustomContextMenu);
    deviceTableView_->setSelectionBehavior(QAbstractItemView::SelectRows);
    deviceTableView_->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabWidget->addTab(deviceTableView_, QString::fromLocal8Bit("设备列表"));

    connect(deviceTableView_, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotDeviceTableViewPressed(const QModelIndex &)));

    deviceTableModel_ = new CameraModel(this);
    deviceTableView_->setModel(deviceTableModel_);

    jsonTextBrowser_ = new QTextBrowser(this);
    ui->tabWidget->addTab(jsonTextBrowser_, tr("json"));

    realPlayMenu_ = new QMenu(this);
    ui->btn_switchVedioLevel->setMenu(realPlayMenu_);

    if(!bInit_) {
        libInit();
    }

    //sessionId_ = OpenNetStream::getInstance()->allocSessionEx(MainWindow::messageHandler, this);
    qDebug() << "sessionId:" << sessionId_;
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
        // emit pInstance->insPlayException(iErrorCode, pMessageInfo);
        break;
    case INS_PLAY_RECONNECT:
        break;
    case INS_PLAY_RECONNECT_EXCEPTION:
        // emit pInstance->insPlayReconnectException(iErrorCode, pMessageInfo);
        break;
    case INS_PLAY_START:
        // emit pInstance->insPlayStart();
        break;
    case INS_PLAY_STOP:
        // emit pInstance->insPlayStop();
        break;
    case INS_PLAY_ARCHIVE_END:
        // emit pInstance->insPlayBackEnd(iErrorCode);
        break;
    case INS_RECORD_FILE:
        // emit pInstance->insRecordFile(pMessageInfo);
        break;
    case INS_RECORD_SEARCH_END:
        break;
    case INS_RECORD_SEARCH_FAILED:
        // emit pInstance->insRecordSearchFailed(iErrorCode, pMessageInfo);
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_login_clicked()
{
    if(!bInit_) {
        libInit();
    }

    getDeviceList();
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
     jsonTextBrowser_->setText(QString(jsonByte));
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(jsonByte.data(), value)) {
        Json::Value lVideoQuality = value["videoQualityInfos"];
        if (lVideoQuality.isArray())
        {
            realPlayMenu_->clear();
            for (int i=0; i < lVideoQuality.size(); i++)
            {
                 Json::Value videoQualityObj = lVideoQuality[i];
                if (!videoQualityObj["videoQualityName"].isString() || !videoQualityObj["videoLevel"].isInt())
                {
                    continue;
                }
                 std::string strVideoQualityName = videoQualityObj["videoQualityName"].asString();
                 int iVideoLevel = videoQualityObj["videoLevel"].asInt();
                QAction* videoAction = realPlayMenu_->addAction(strVideoQualityName.c_str());
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

void MainWindow::showErrInfo(QString caption)
{
    int iErrCode = OpenNetStream::getInstance()->GetLastErrorCode();
    char szBuf[64] = {0};
    sprintf(szBuf, "ErrorCode:%d", iErrCode);
    QMessageBox::information(this, caption, szBuf);
}

void MainWindow::updateVideoLevelBtn(const int iLevel)
{
    switch(iLevel)
    {
    case VideoSmooth:
        ui->btn_startPlay->setText(QString::fromLocal8Bit("播放-流畅"));
        break;
    case VideoBalanced:
        ui->btn_startPlay->setText(QString::fromLocal8Bit("播放-平衡"));
        break;
    case VideoClear:
        ui->btn_startPlay->setText(QString::fromLocal8Bit("播放-高清"));
        break;
    case VideoHigh:
        ui->btn_startPlay->setText(QString::fromLocal8Bit("播放-超清"));
        break;
    }
    if (ui->tabWidget->currentIndex() == DeviceTableIndex) {
        QModelIndex index = deviceTableView_->currentIndex();
        if (!index.isValid()) {
            return ;
        }
        deviceTableModel_->setVideoLevel(index, iLevel);
    }
}

bool  MainWindow::GetDeviceTableViewInfo(DeviceTableViewInfo& stDeviceInfo)
{
    if (ui->tabWidget->currentIndex() == DeviceTableIndex) {
        QModelIndex index = deviceTableView_->currentIndex();
        if (!index.isValid()) {
            QMessageBox::information(this, tr("Device List"), tr("Please select a device in device list"));
            ui->tabWidget->setCurrentIndex(DeviceTableIndex);
            return false;
        }
        stDeviceInfo.strSubserial = deviceTableModel_->getSerial(index);
        stDeviceInfo.iChannelNo = deviceTableModel_->getCameraNo(index);
        stDeviceInfo.bEncrypt = deviceTableModel_->getIsEncrypt(index);
        stDeviceInfo.iVideoLevel = deviceTableModel_->getVideoLevel(index);
    } else {
        QMessageBox::information(this, tr("Device List"), tr("Please select a device in device list"));
        ui->tabWidget->setCurrentIndex(DeviceTableIndex);
        return false;
    }
    return true;
}

void MainWindow::getDeviceList() {
    void* pBuf = NULL;
    int length = 0;

    int iRet = OpenNetStream::getInstance()->getDevListEx(0, 1000, &pBuf, &length);
    if (iRet != OPEN_SDK_NOERROR)
    {
        qDebug() << "Get Device List failed!";
        return ;
    }

    QString json;
    json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    OpenNetStream::getInstance()->freeData(pBuf);
    qDebug() << json;

    QByteArray jsonByte = json.toUtf8();
    deviceTableModel_->setCameraModel(jsonByte);
    jsonTextBrowser_->clear();
    Json::Reader reader;
    Json::Value	value;
    if(reader.parse(jsonByte.data(), value)) {
        jsonTextBrowser_->setText( value.toStyledString().c_str() );
    }
    ui->tabWidget->setCurrentIndex(DeviceTableIndex);
}

void MainWindow::libInit()
{
    QString authAddress = "https://openauth.ys7.com";
    QString platformAddress = "https://open.ys7.com";

    if(!ui->le_acToken->text().isEmpty()) {
        acToken_ = ui->le_acToken->text();
    } else {
        // QString appKey = ui->le_appKey->text();
        QString appKey = "1db6d18b1ba24c918a42ef2b1cbed71c";
        OpenNetStream::getInstance()->initLibrary(authAddress, platformAddress, appKey);
        acToken_ = OpenNetStream::getInstance()->login();
        bInit_ = true;
    }

    sessionId_ = OpenNetStream::getInstance()->allocSessionEx(MainWindow::messageHandler, this);
    OpenNetStream::getInstance()->setStreamTrans();

    // 日志等级设置
    OpenNetStream::getInstance()->setLogLevel(3);

    // token设置
    OpenNetStream::getInstance()->setAccessToken(acToken_);

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
}

void MainWindow::on_btn_startPlay_clicked()
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return;
    }

    bool bEncrypt = stDeviceInfo.bEncrypt;
    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

    devSerial_ = devSerial;
    Channel_ = iChannelNo;

    QString safekey;
    safekey.clear();
    if(bEncrypt)
    {
        bool ok;
        safekey = QInputDialog::getText(this, tr("Input"), tr("Please Input the verification code"), QLineEdit::Password, "", &ok);
        if (ok == false)
        {
            return;
        }
    }

    //Set the video store path
    setVideoPath(devSerial);
    OpenNetStream::getInstance()->setDataCallBack(sessionId_, videoDataHandler, this);

    HWND hWnd = NULL;
    hWnd = (HWND)ui->previewWindow->winId();
    int iRet = OpenNetStream::getInstance()->startRealPlay(sessionId_, hWnd, devSerial, iChannelNo, safekey);
    if(0 != iRet)
    {
        this->showErrInfo(tr("RealPlay"));
        return;
    }
    bRealPlayStarted_ = true;
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
    videoPath_ = path + "/" + strFlag + ".mp4";
}

void MainWindow::videoDataHandler(DataType enType, char* const pData, int iLen, void* pUser)
{
    //qDebug() << __LINE__ << __FUNCTION__ <<"enType:"<< enType << "iLen:" << iLen;

    MainWindow * mainWins = (MainWindow *)pUser;
    if(mainWins->curVideoPath().isEmpty())
    {
        return ;
    }

    // 保存录像
    if (true)
    {
        std::ofstream file;
        file.open(mainWins->curVideoPath().toStdString().c_str(), std::ios::binary|std::ios::app);
        file.write(pData,iLen);
        file.flush();
        file.close();
    }
}

const QString& MainWindow::curVideoPath()
{
    return videoPath_;
}
