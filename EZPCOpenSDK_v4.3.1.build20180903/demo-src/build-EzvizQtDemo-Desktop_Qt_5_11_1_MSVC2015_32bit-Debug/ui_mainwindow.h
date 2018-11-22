/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_1;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *logoutButton;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *deviceListButton;
    QPushButton *alarmListButton;
    QPushButton *setAlarmReadButton;
    QPushButton *showAlarmPicButton;
    QPushButton *getCameraInfoButton;
    QPushButton *updateCameraInfoButton;
    QPushButton *deviceInfoButton;
    QPushButton *shareDevListButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *switchVideoLevelButton;
    QPushButton *startRealPlayButton;
    QPushButton *stopRealPlayButton;
    QPushButton *capturePictureButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *osdLabel;
    QPushButton *pauseButton;
    QPushButton *playBackListButton;
    QPushButton *resumeButton;
    QPushButton *startPlayBackButton;
    QLineEdit *PbStartTime;
    QLineEdit *PbEndTime;
    QPushButton *setPlayBackTimeButton;
    QCheckBox *videoRecordBox;
    QPushButton *stopPlayBackButton;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *switchSoundButton;
    QSlider *setVolumeSlider;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *startVoiceTalkButton;
    QPushButton *stopVoiceTalkButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QPushButton *defenceOnButton;
    QPushButton *defenceOffButton;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_5;
    QWidget *previewWindow;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_ZoomIn;
    QPushButton *pushButton_DR;
    QPushButton *pushButton_ZoomOut;
    QPushButton *pushButton_DL;
    QPushButton *pushButton_FocusNear;
    QPushButton *pushButton_FocusFar;
    QPushButton *pushButton_UR;
    QPushButton *pushButton_U;
    QPushButton *pushButton_Wiper;
    QPushButton *pushButton_Light;
    QPushButton *pushButton_UL;
    QPushButton *pushButton_L;
    QPushButton *pushButton_R;
    QPushButton *pushButton_D;
    QPushButton *pushButton_IrisStart;
    QPushButton *pushButton_IrisStop;
    QPushButton *pushButton_Auto;
    QGroupBox *groupBox_10;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *pushAlarmCheckBox;
    QCheckBox *pushDevStatusCheckBox;
    QCheckBox *pushTransparentChannelCheckBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *startPushRecvButton;
    QPushButton *stopPushRecvButton;
    QTabWidget *tabWidget;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 666);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(MainWindow);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox_1 = new QGroupBox(MainWindow);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setMinimumSize(QSize(300, 0));
        groupBox_1->setMaximumSize(QSize(300, 16777215));
        horizontalLayout = new QHBoxLayout(groupBox_1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loginButton = new QPushButton(groupBox_1);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        horizontalLayout->addWidget(loginButton);

        logoutButton = new QPushButton(groupBox_1);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));

        horizontalLayout->addWidget(logoutButton);

        pushButton = new QPushButton(groupBox_1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(groupBox_1);

        groupBox_2 = new QGroupBox(MainWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        deviceListButton = new QPushButton(groupBox_2);
        deviceListButton->setObjectName(QStringLiteral("deviceListButton"));

        gridLayout_3->addWidget(deviceListButton, 0, 0, 1, 1);

        alarmListButton = new QPushButton(groupBox_2);
        alarmListButton->setObjectName(QStringLiteral("alarmListButton"));

        gridLayout_3->addWidget(alarmListButton, 5, 0, 1, 1);

        setAlarmReadButton = new QPushButton(groupBox_2);
        setAlarmReadButton->setObjectName(QStringLiteral("setAlarmReadButton"));

        gridLayout_3->addWidget(setAlarmReadButton, 5, 2, 1, 1);

        showAlarmPicButton = new QPushButton(groupBox_2);
        showAlarmPicButton->setObjectName(QStringLiteral("showAlarmPicButton"));

        gridLayout_3->addWidget(showAlarmPicButton, 5, 3, 1, 1);

        getCameraInfoButton = new QPushButton(groupBox_2);
        getCameraInfoButton->setObjectName(QStringLiteral("getCameraInfoButton"));

        gridLayout_3->addWidget(getCameraInfoButton, 1, 2, 1, 1);

        updateCameraInfoButton = new QPushButton(groupBox_2);
        updateCameraInfoButton->setObjectName(QStringLiteral("updateCameraInfoButton"));

        gridLayout_3->addWidget(updateCameraInfoButton, 1, 3, 1, 1);

        deviceInfoButton = new QPushButton(groupBox_2);
        deviceInfoButton->setObjectName(QStringLiteral("deviceInfoButton"));

        gridLayout_3->addWidget(deviceInfoButton, 1, 0, 1, 1);

        shareDevListButton = new QPushButton(groupBox_2);
        shareDevListButton->setObjectName(QStringLiteral("shareDevListButton"));

        gridLayout_3->addWidget(shareDevListButton, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(MainWindow);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(300, 16777215));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        switchVideoLevelButton = new QPushButton(groupBox_3);
        switchVideoLevelButton->setObjectName(QStringLiteral("switchVideoLevelButton"));

        horizontalLayout_3->addWidget(switchVideoLevelButton);

        startRealPlayButton = new QPushButton(groupBox_3);
        startRealPlayButton->setObjectName(QStringLiteral("startRealPlayButton"));

        horizontalLayout_3->addWidget(startRealPlayButton);

        stopRealPlayButton = new QPushButton(groupBox_3);
        stopRealPlayButton->setObjectName(QStringLiteral("stopRealPlayButton"));

        horizontalLayout_3->addWidget(stopRealPlayButton);

        capturePictureButton = new QPushButton(groupBox_3);
        capturePictureButton->setObjectName(QStringLiteral("capturePictureButton"));

        horizontalLayout_3->addWidget(capturePictureButton);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(MainWindow);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(300, 16777215));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        osdLabel = new QLabel(groupBox_4);
        osdLabel->setObjectName(QStringLiteral("osdLabel"));
        osdLabel->setLayoutDirection(Qt::LeftToRight);
        osdLabel->setTextFormat(Qt::AutoText);
        osdLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(osdLabel, 1, 3, 1, 1);

        pauseButton = new QPushButton(groupBox_4);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        gridLayout->addWidget(pauseButton, 1, 0, 1, 1);

        playBackListButton = new QPushButton(groupBox_4);
        playBackListButton->setObjectName(QStringLiteral("playBackListButton"));

        gridLayout->addWidget(playBackListButton, 0, 0, 1, 1);

        resumeButton = new QPushButton(groupBox_4);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));

        gridLayout->addWidget(resumeButton, 1, 1, 1, 1);

        startPlayBackButton = new QPushButton(groupBox_4);
        startPlayBackButton->setObjectName(QStringLiteral("startPlayBackButton"));

        gridLayout->addWidget(startPlayBackButton, 0, 1, 1, 1);

        PbStartTime = new QLineEdit(groupBox_4);
        PbStartTime->setObjectName(QStringLiteral("PbStartTime"));

        gridLayout->addWidget(PbStartTime, 2, 1, 1, 1);

        PbEndTime = new QLineEdit(groupBox_4);
        PbEndTime->setObjectName(QStringLiteral("PbEndTime"));

        gridLayout->addWidget(PbEndTime, 2, 3, 1, 1);

        setPlayBackTimeButton = new QPushButton(groupBox_4);
        setPlayBackTimeButton->setObjectName(QStringLiteral("setPlayBackTimeButton"));

        gridLayout->addWidget(setPlayBackTimeButton, 2, 0, 1, 1);

        videoRecordBox = new QCheckBox(groupBox_4);
        videoRecordBox->setObjectName(QStringLiteral("videoRecordBox"));

        gridLayout->addWidget(videoRecordBox, 3, 0, 1, 1);

        stopPlayBackButton = new QPushButton(groupBox_4);
        stopPlayBackButton->setObjectName(QStringLiteral("stopPlayBackButton"));

        gridLayout->addWidget(stopPlayBackButton, 0, 3, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(MainWindow);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        switchSoundButton = new QRadioButton(groupBox_5);
        switchSoundButton->setObjectName(QStringLiteral("switchSoundButton"));

        horizontalLayout_9->addWidget(switchSoundButton);

        setVolumeSlider = new QSlider(groupBox_5);
        setVolumeSlider->setObjectName(QStringLiteral("setVolumeSlider"));
        setVolumeSlider->setEnabled(false);
        setVolumeSlider->setMaximum(99);
        setVolumeSlider->setTracking(true);
        setVolumeSlider->setOrientation(Qt::Horizontal);
        setVolumeSlider->setInvertedAppearance(false);
        setVolumeSlider->setInvertedControls(false);
        setVolumeSlider->setTickPosition(QSlider::NoTicks);
        setVolumeSlider->setTickInterval(0);

        horizontalLayout_9->addWidget(setVolumeSlider);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        startVoiceTalkButton = new QPushButton(groupBox_5);
        startVoiceTalkButton->setObjectName(QStringLiteral("startVoiceTalkButton"));

        horizontalLayout_8->addWidget(startVoiceTalkButton);

        stopVoiceTalkButton = new QPushButton(groupBox_5);
        stopVoiceTalkButton->setObjectName(QStringLiteral("stopVoiceTalkButton"));

        horizontalLayout_8->addWidget(stopVoiceTalkButton);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(groupBox_5);

        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        defenceOnButton = new QPushButton(groupBox);
        defenceOnButton->setObjectName(QStringLiteral("defenceOnButton"));

        gridLayout_4->addWidget(defenceOnButton, 0, 1, 1, 1);

        defenceOffButton = new QPushButton(groupBox);
        defenceOffButton->setObjectName(QStringLiteral("defenceOffButton"));

        gridLayout_4->addWidget(defenceOffButton, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBox);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox_7 = new QGroupBox(MainWindow);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_7);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(3, 20, 3, 20);
        previewWindow = new QWidget(groupBox_7);
        previewWindow->setObjectName(QStringLiteral("previewWindow"));
        previewWindow->setMinimumSize(QSize(320, 240));
        previewWindow->setMaximumSize(QSize(320, 240));

        horizontalLayout_5->addWidget(previewWindow);


        verticalLayout_5->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(MainWindow);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        sizePolicy.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_8);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_ZoomIn = new QPushButton(groupBox_8);
        pushButton_ZoomIn->setObjectName(QStringLiteral("pushButton_ZoomIn"));

        gridLayout_2->addWidget(pushButton_ZoomIn, 3, 1, 1, 1);

        pushButton_DR = new QPushButton(groupBox_8);
        pushButton_DR->setObjectName(QStringLiteral("pushButton_DR"));

        gridLayout_2->addWidget(pushButton_DR, 2, 2, 1, 1);

        pushButton_ZoomOut = new QPushButton(groupBox_8);
        pushButton_ZoomOut->setObjectName(QStringLiteral("pushButton_ZoomOut"));

        gridLayout_2->addWidget(pushButton_ZoomOut, 3, 0, 1, 1);

        pushButton_DL = new QPushButton(groupBox_8);
        pushButton_DL->setObjectName(QStringLiteral("pushButton_DL"));

        gridLayout_2->addWidget(pushButton_DL, 2, 0, 1, 1);

        pushButton_FocusNear = new QPushButton(groupBox_8);
        pushButton_FocusNear->setObjectName(QStringLiteral("pushButton_FocusNear"));

        gridLayout_2->addWidget(pushButton_FocusNear, 4, 0, 1, 1);

        pushButton_FocusFar = new QPushButton(groupBox_8);
        pushButton_FocusFar->setObjectName(QStringLiteral("pushButton_FocusFar"));

        gridLayout_2->addWidget(pushButton_FocusFar, 4, 1, 1, 1);

        pushButton_UR = new QPushButton(groupBox_8);
        pushButton_UR->setObjectName(QStringLiteral("pushButton_UR"));

        gridLayout_2->addWidget(pushButton_UR, 0, 2, 1, 1);

        pushButton_U = new QPushButton(groupBox_8);
        pushButton_U->setObjectName(QStringLiteral("pushButton_U"));

        gridLayout_2->addWidget(pushButton_U, 0, 1, 1, 1);

        pushButton_Wiper = new QPushButton(groupBox_8);
        pushButton_Wiper->setObjectName(QStringLiteral("pushButton_Wiper"));

        gridLayout_2->addWidget(pushButton_Wiper, 3, 2, 1, 1);

        pushButton_Light = new QPushButton(groupBox_8);
        pushButton_Light->setObjectName(QStringLiteral("pushButton_Light"));

        gridLayout_2->addWidget(pushButton_Light, 4, 2, 1, 1);

        pushButton_UL = new QPushButton(groupBox_8);
        pushButton_UL->setObjectName(QStringLiteral("pushButton_UL"));

        gridLayout_2->addWidget(pushButton_UL, 0, 0, 1, 1);

        pushButton_L = new QPushButton(groupBox_8);
        pushButton_L->setObjectName(QStringLiteral("pushButton_L"));

        gridLayout_2->addWidget(pushButton_L, 1, 0, 1, 1);

        pushButton_R = new QPushButton(groupBox_8);
        pushButton_R->setObjectName(QStringLiteral("pushButton_R"));

        gridLayout_2->addWidget(pushButton_R, 1, 2, 1, 1);

        pushButton_D = new QPushButton(groupBox_8);
        pushButton_D->setObjectName(QStringLiteral("pushButton_D"));

        gridLayout_2->addWidget(pushButton_D, 2, 1, 1, 1);

        pushButton_IrisStart = new QPushButton(groupBox_8);
        pushButton_IrisStart->setObjectName(QStringLiteral("pushButton_IrisStart"));

        gridLayout_2->addWidget(pushButton_IrisStart, 5, 0, 1, 1);

        pushButton_IrisStop = new QPushButton(groupBox_8);
        pushButton_IrisStop->setObjectName(QStringLiteral("pushButton_IrisStop"));

        gridLayout_2->addWidget(pushButton_IrisStop, 5, 1, 1, 1);

        pushButton_Auto = new QPushButton(groupBox_8);
        pushButton_Auto->setObjectName(QStringLiteral("pushButton_Auto"));

        gridLayout_2->addWidget(pushButton_Auto, 5, 2, 1, 1);


        verticalLayout_5->addWidget(groupBox_8);

        groupBox_10 = new QGroupBox(MainWindow);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(groupBox_10);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 301, 41));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        pushAlarmCheckBox = new QCheckBox(horizontalLayoutWidget);
        pushAlarmCheckBox->setObjectName(QStringLiteral("pushAlarmCheckBox"));

        horizontalLayout_10->addWidget(pushAlarmCheckBox);

        pushDevStatusCheckBox = new QCheckBox(horizontalLayoutWidget);
        pushDevStatusCheckBox->setObjectName(QStringLiteral("pushDevStatusCheckBox"));

        horizontalLayout_10->addWidget(pushDevStatusCheckBox);

        pushTransparentChannelCheckBox = new QCheckBox(horizontalLayoutWidget);
        pushTransparentChannelCheckBox->setObjectName(QStringLiteral("pushTransparentChannelCheckBox"));

        horizontalLayout_10->addWidget(pushTransparentChannelCheckBox);

        horizontalLayoutWidget_2 = new QWidget(groupBox_10);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 80, 301, 41));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        startPushRecvButton = new QPushButton(horizontalLayoutWidget_2);
        startPushRecvButton->setObjectName(QStringLiteral("startPushRecvButton"));

        horizontalLayout_11->addWidget(startPushRecvButton);

        stopPushRecvButton = new QPushButton(horizontalLayoutWidget_2);
        stopPushRecvButton->setObjectName(QStringLiteral("stopPushRecvButton"));

        horizontalLayout_11->addWidget(stopPushRecvButton);


        verticalLayout_5->addWidget(groupBox_10);


        horizontalLayout_4->addLayout(verticalLayout_5);

        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(tabWidget);


        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Open SDK Demo", nullptr));
        groupBox_1->setTitle(QApplication::translate("MainWindow", "Mid Page", nullptr));
        loginButton->setText(QApplication::translate("MainWindow", "Login", nullptr));
        logoutButton->setText(QApplication::translate("MainWindow", "Logout", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "TokenUpdate", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Data", nullptr));
        deviceListButton->setText(QApplication::translate("MainWindow", "DeviceList", nullptr));
        alarmListButton->setText(QApplication::translate("MainWindow", "AlarmList", nullptr));
        setAlarmReadButton->setText(QApplication::translate("MainWindow", "AlarmSetRead", nullptr));
        showAlarmPicButton->setText(QApplication::translate("MainWindow", "AlarmPic", nullptr));
        getCameraInfoButton->setText(QApplication::translate("MainWindow", "DevDetailInfo", nullptr));
        updateCameraInfoButton->setText(QApplication::translate("MainWindow", "DevDetailUpdate", nullptr));
        deviceInfoButton->setText(QApplication::translate("MainWindow", "ChannelInfo", nullptr));
        shareDevListButton->setText(QApplication::translate("MainWindow", "ShareDevList", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "RealPlay", nullptr));
        switchVideoLevelButton->setText(QApplication::translate("MainWindow", "SwitchDef", nullptr));
        startRealPlayButton->setText(QApplication::translate("MainWindow", "StartPlay", nullptr));
        stopRealPlayButton->setText(QApplication::translate("MainWindow", "StopPlay", nullptr));
        capturePictureButton->setText(QApplication::translate("MainWindow", "CapturePic", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "PlayBack", nullptr));
        osdLabel->setText(QApplication::translate("MainWindow", "00:00:00", nullptr));
        pauseButton->setText(QApplication::translate("MainWindow", "PausePlay", nullptr));
        playBackListButton->setText(QApplication::translate("MainWindow", "PlayBackList", nullptr));
        resumeButton->setText(QApplication::translate("MainWindow", "ResumePlay", nullptr));
        startPlayBackButton->setText(QApplication::translate("MainWindow", "StartPlayBack", nullptr));
        setPlayBackTimeButton->setText(QApplication::translate("MainWindow", "SelectDate", nullptr));
        videoRecordBox->setText(QApplication::translate("MainWindow", "Video Record", nullptr));
        stopPlayBackButton->setText(QApplication::translate("MainWindow", "StopPlayBack", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "VoiceTalk", nullptr));
        switchSoundButton->setText(QApplication::translate("MainWindow", "Sound", nullptr));
        startVoiceTalkButton->setText(QApplication::translate("MainWindow", "StartVoiceTalk", nullptr));
        stopVoiceTalkButton->setText(QApplication::translate("MainWindow", "StopVoiceTalk", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Device Defence", nullptr));
        defenceOnButton->setText(QApplication::translate("MainWindow", "Defence", nullptr));
        defenceOffButton->setText(QApplication::translate("MainWindow", "Undefence", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Preview", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "PTZ Control", nullptr));
        pushButton_ZoomIn->setText(QApplication::translate("MainWindow", "ZOOMIN", nullptr));
        pushButton_DR->setText(QApplication::translate("MainWindow", "RightDown", nullptr));
        pushButton_ZoomOut->setText(QApplication::translate("MainWindow", "ZOOMOUT", nullptr));
        pushButton_DL->setText(QApplication::translate("MainWindow", "LeftDown", nullptr));
        pushButton_FocusNear->setText(QApplication::translate("MainWindow", "FOCUSNEAR", nullptr));
        pushButton_FocusFar->setText(QApplication::translate("MainWindow", "FOCUSFAR", nullptr));
        pushButton_UR->setText(QApplication::translate("MainWindow", "RightTop", nullptr));
        pushButton_U->setText(QApplication::translate("MainWindow", "Top", nullptr));
        pushButton_Wiper->setText(QApplication::translate("MainWindow", "WIPER", nullptr));
        pushButton_Light->setText(QApplication::translate("MainWindow", "LIGHT", nullptr));
        pushButton_UL->setText(QApplication::translate("MainWindow", "LeftTop", nullptr));
        pushButton_L->setText(QApplication::translate("MainWindow", "Left", nullptr));
        pushButton_R->setText(QApplication::translate("MainWindow", "Right", nullptr));
        pushButton_D->setText(QApplication::translate("MainWindow", "Down", nullptr));
        pushButton_IrisStart->setText(QApplication::translate("MainWindow", "IRISSTARTUP", nullptr));
        pushButton_IrisStop->setText(QApplication::translate("MainWindow", "IRISSTOPDOWN", nullptr));
        pushButton_Auto->setText(QApplication::translate("MainWindow", "AUTO", nullptr));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Push Message", nullptr));
        pushAlarmCheckBox->setText(QApplication::translate("MainWindow", "Alarm", nullptr));
        pushDevStatusCheckBox->setText(QApplication::translate("MainWindow", "DevOffline", nullptr));
        pushTransparentChannelCheckBox->setText(QApplication::translate("MainWindow", "TransparentChannel", nullptr));
        startPushRecvButton->setText(QApplication::translate("MainWindow", "OpenPush", nullptr));
        stopPushRecvButton->setText(QApplication::translate("MainWindow", "ClosePush", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
