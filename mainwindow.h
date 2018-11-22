#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTextBrowser>
#include <QTableView>
#include <QModelIndex>
#include "cameramodel.h"
#include "opennetstream.h"

#define PTZ_SPEED 7 //Default PTZ Control Speed

typedef struct tagDeviceTableViewInfo
{
    QString strSubserial;
    int iChannelNo;
    bool bEncrypt;
    int  iVideoLevel;
}DeviceTableViewInfo;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static void __stdcall videoDataHandler(DataType enType, char* const pData, int iLen, void* pUser);
    static void __stdcall messageHandler(const char* szSessionId, unsigned int iMsgType, unsigned int iErrorCode,const char *pMessageInfo, void *pUser);

    const QString& curVideoPath();

    // 获取设备列表
    void getDeviceList();

private slots:
    void on_btn_login_clicked();
    void on_btn_startPlay_clicked();
    void on_smoothAction();
    void on_equilibriumAction();
    void on_clearAction();
    void on_highAction();

    void slotDeviceTableViewPressed(const QModelIndex &);
private:
    enum TableIndex {
        DeviceTableIndex,
//        SharedDeviceIndex,
//        AlarmTableIndex,
//        PushAlarmTableIndex,
//        PlayBackTableIndex,
        JsonInfoTableIndex
    };

    void libInit();
    bool  GetDeviceTableViewInfo(DeviceTableViewInfo& stDeviceInfo);
    void updateVideoLevelBtn(const int iLevel);
    int switchVideoLevel(int videoLevel);
    void showErrInfo(QString caption);
    void setVideoPath(const QString devSerial);

    Ui::MainWindow *ui;
    bool bInit_;
    QString acToken_;

    // ui controler
    QTableView* deviceTableView_;
    QTextBrowser* jsonTextBrowser_;
    QMenu* realPlayMenu_;

    // ui data
    CameraModel* deviceTableModel_;

    // user data
    QString sessionId_;
    QString devSerial_;
    int Channel_;

    //
    bool bRealPlayStarted_;
    QString videoPath_;
};

#endif // MAINWINDOW_H
