/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EzvizQtDemo/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[115];
    char stringdata0[2402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "insRecordFile"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "messageInfo"
QT_MOC_LITERAL(4, 38, 16), // "insPlayException"
QT_MOC_LITERAL(5, 55, 9), // "errorCode"
QT_MOC_LITERAL(6, 65, 14), // "insPlayBackEnd"
QT_MOC_LITERAL(7, 80, 25), // "insPlayReconnectException"
QT_MOC_LITERAL(8, 106, 21), // "insRecordSearchFailed"
QT_MOC_LITERAL(9, 128, 12), // "insPlayAlarm"
QT_MOC_LITERAL(10, 141, 10), // "szCameraId"
QT_MOC_LITERAL(11, 152, 9), // "szContent"
QT_MOC_LITERAL(12, 162, 11), // "szAlarmTime"
QT_MOC_LITERAL(13, 174, 11), // "insPlayPush"
QT_MOC_LITERAL(14, 186, 6), // "szDesc"
QT_MOC_LITERAL(15, 193, 8), // "szDetail"
QT_MOC_LITERAL(16, 202, 16), // "insPlayPushAlarm"
QT_MOC_LITERAL(17, 219, 11), // "insPtzStart"
QT_MOC_LITERAL(18, 231, 6), // "PTZCMD"
QT_MOC_LITERAL(19, 238, 8), // "emDirect"
QT_MOC_LITERAL(20, 247, 10), // "insPtzStop"
QT_MOC_LITERAL(21, 258, 12), // "insPlayStart"
QT_MOC_LITERAL(22, 271, 11), // "insPlayStop"
QT_MOC_LITERAL(23, 283, 26), // "slotDeviceTableViewPressed"
QT_MOC_LITERAL(24, 310, 11), // "QModelIndex"
QT_MOC_LITERAL(25, 322, 5), // "index"
QT_MOC_LITERAL(26, 328, 28), // "slotPlayBackTableViewPressed"
QT_MOC_LITERAL(27, 357, 29), // "slotPushAlarmTableViewPressed"
QT_MOC_LITERAL(28, 387, 22), // "on_loginButton_clicked"
QT_MOC_LITERAL(29, 410, 26), // "on_deviceAddButton_clicked"
QT_MOC_LITERAL(30, 437, 29), // "on_stopRealPlayButton_clicked"
QT_MOC_LITERAL(31, 467, 29), // "on_playBackListButton_clicked"
QT_MOC_LITERAL(32, 497, 30), // "on_startPlayBackButton_clicked"
QT_MOC_LITERAL(33, 528, 29), // "on_stopPlayBackButton_clicked"
QT_MOC_LITERAL(34, 558, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(35, 581, 23), // "on_resumeButton_clicked"
QT_MOC_LITERAL(36, 605, 27), // "on_deviceListButton_clicked"
QT_MOC_LITERAL(37, 633, 26), // "on_alarmListButton_clicked"
QT_MOC_LITERAL(38, 660, 31), // "on_capturePictureButton_clicked"
QT_MOC_LITERAL(39, 692, 31), // "on_startVoiceTalkButton_clicked"
QT_MOC_LITERAL(40, 724, 30), // "on_stopVoiceTalkButton_clicked"
QT_MOC_LITERAL(41, 755, 28), // "on_switchSoundButton_clicked"
QT_MOC_LITERAL(42, 784, 33), // "on_setVolumeSlider_sliderRele..."
QT_MOC_LITERAL(43, 818, 29), // "on_setAlarmReadButton_clicked"
QT_MOC_LITERAL(44, 848, 26), // "on_defenceOnButton_clicked"
QT_MOC_LITERAL(45, 875, 27), // "on_defenceOffButton_clicked"
QT_MOC_LITERAL(46, 903, 16), // "on_insRecordFile"
QT_MOC_LITERAL(47, 920, 19), // "on_insPlayException"
QT_MOC_LITERAL(48, 940, 17), // "on_insPlayBackEnd"
QT_MOC_LITERAL(49, 958, 28), // "on_insPlayReconnectException"
QT_MOC_LITERAL(50, 987, 24), // "on_insRecordSearchFailed"
QT_MOC_LITERAL(51, 1012, 15), // "on_insPlayAlarm"
QT_MOC_LITERAL(52, 1028, 14), // "on_insPlayPush"
QT_MOC_LITERAL(53, 1043, 16), // "on_insPtzStartUp"
QT_MOC_LITERAL(54, 1060, 18), // "on_insPtzStartDown"
QT_MOC_LITERAL(55, 1079, 18), // "on_insPtzStartLeft"
QT_MOC_LITERAL(56, 1098, 19), // "on_insPtzStartRight"
QT_MOC_LITERAL(57, 1118, 20), // "on_insPtzStartUpLeft"
QT_MOC_LITERAL(58, 1139, 22), // "on_insPtzStartDownLeft"
QT_MOC_LITERAL(59, 1162, 21), // "on_insPtzStartUpRight"
QT_MOC_LITERAL(60, 1184, 23), // "on_insPtzStartDownRight"
QT_MOC_LITERAL(61, 1208, 15), // "on_insPtzStopUp"
QT_MOC_LITERAL(62, 1224, 17), // "on_insPtzStopDown"
QT_MOC_LITERAL(63, 1242, 17), // "on_insPtzStopLeft"
QT_MOC_LITERAL(64, 1260, 18), // "on_insPtzStopRight"
QT_MOC_LITERAL(65, 1279, 19), // "on_insPtzStopUpLeft"
QT_MOC_LITERAL(66, 1299, 21), // "on_insPtzStopDownLeft"
QT_MOC_LITERAL(67, 1321, 20), // "on_insPtzStopUpRight"
QT_MOC_LITERAL(68, 1342, 22), // "on_insPtzStopDownRight"
QT_MOC_LITERAL(69, 1365, 20), // "on_insPtzStartZoomIn"
QT_MOC_LITERAL(70, 1386, 21), // "on_insPtzStartZoomOut"
QT_MOC_LITERAL(71, 1408, 19), // "on_insPtzStopZoomIn"
QT_MOC_LITERAL(72, 1428, 20), // "on_insPtzStopZoomOut"
QT_MOC_LITERAL(73, 1449, 22), // "on_insPtzStartFocusFar"
QT_MOC_LITERAL(74, 1472, 23), // "on_insPtzStartFocusNear"
QT_MOC_LITERAL(75, 1496, 21), // "on_insPtzStopFocusFar"
QT_MOC_LITERAL(76, 1518, 22), // "on_insPtzStopFocusNear"
QT_MOC_LITERAL(77, 1541, 25), // "on_insPtzStartIrisStartUp"
QT_MOC_LITERAL(78, 1567, 26), // "on_insPtzStartIrisStopDown"
QT_MOC_LITERAL(79, 1594, 24), // "on_insPtzStopIrisStartUp"
QT_MOC_LITERAL(80, 1619, 25), // "on_insPtzStopIrisStopDown"
QT_MOC_LITERAL(81, 1645, 20), // "on_insPtzAutoStartUp"
QT_MOC_LITERAL(82, 1666, 21), // "on_insPtzAutoStopDown"
QT_MOC_LITERAL(83, 1688, 14), // "on_insPtzStart"
QT_MOC_LITERAL(84, 1703, 13), // "on_insPtzStop"
QT_MOC_LITERAL(85, 1717, 15), // "on_insPlayStart"
QT_MOC_LITERAL(86, 1733, 14), // "on_insPlayStop"
QT_MOC_LITERAL(87, 1748, 19), // "on_insGetCameraInfo"
QT_MOC_LITERAL(88, 1768, 22), // "on_insUpdateCameraInfo"
QT_MOC_LITERAL(89, 1791, 15), // "on_smoothAction"
QT_MOC_LITERAL(90, 1807, 20), // "on_equilibriumAction"
QT_MOC_LITERAL(91, 1828, 14), // "on_clearAction"
QT_MOC_LITERAL(92, 1843, 13), // "on_highAction"
QT_MOC_LITERAL(93, 1857, 10), // "displayosd"
QT_MOC_LITERAL(94, 1868, 29), // "on_stopPushRecvButton_clicked"
QT_MOC_LITERAL(95, 1898, 30), // "on_startPushRecvButton_clicked"
QT_MOC_LITERAL(96, 1929, 33), // "on_pushAlarmCheckBox_stateCha..."
QT_MOC_LITERAL(97, 1963, 4), // "arg1"
QT_MOC_LITERAL(98, 1968, 37), // "on_pushDevStatusCheckBox_stat..."
QT_MOC_LITERAL(99, 2006, 46), // "on_pushTransparentChannelChec..."
QT_MOC_LITERAL(100, 2053, 29), // "on_showAlarmPicButton_clicked"
QT_MOC_LITERAL(101, 2083, 30), // "on_startRealPlayButton_clicked"
QT_MOC_LITERAL(102, 2114, 32), // "on_setPlayBackTimeButton_clicked"
QT_MOC_LITERAL(103, 2147, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(104, 2169, 29), // "on_shareDevListButton_clicked"
QT_MOC_LITERAL(105, 2199, 23), // "on_logoutButton_clicked"
QT_MOC_LITERAL(106, 2223, 30), // "on_videoRecordBox_stateChanged"
QT_MOC_LITERAL(107, 2254, 27), // "on_deviceInfoButton_clicked"
QT_MOC_LITERAL(108, 2282, 10), // "TableIndex"
QT_MOC_LITERAL(109, 2293, 16), // "DeviceTableIndex"
QT_MOC_LITERAL(110, 2310, 17), // "SharedDeviceIndex"
QT_MOC_LITERAL(111, 2328, 15), // "AlarmTableIndex"
QT_MOC_LITERAL(112, 2344, 19), // "PushAlarmTableIndex"
QT_MOC_LITERAL(113, 2364, 18), // "PlayBackTableIndex"
QT_MOC_LITERAL(114, 2383, 18) // "JsonInfoTableIndex"

    },
    "MainWindow\0insRecordFile\0\0messageInfo\0"
    "insPlayException\0errorCode\0insPlayBackEnd\0"
    "insPlayReconnectException\0"
    "insRecordSearchFailed\0insPlayAlarm\0"
    "szCameraId\0szContent\0szAlarmTime\0"
    "insPlayPush\0szDesc\0szDetail\0"
    "insPlayPushAlarm\0insPtzStart\0PTZCMD\0"
    "emDirect\0insPtzStop\0insPlayStart\0"
    "insPlayStop\0slotDeviceTableViewPressed\0"
    "QModelIndex\0index\0slotPlayBackTableViewPressed\0"
    "slotPushAlarmTableViewPressed\0"
    "on_loginButton_clicked\0"
    "on_deviceAddButton_clicked\0"
    "on_stopRealPlayButton_clicked\0"
    "on_playBackListButton_clicked\0"
    "on_startPlayBackButton_clicked\0"
    "on_stopPlayBackButton_clicked\0"
    "on_pauseButton_clicked\0on_resumeButton_clicked\0"
    "on_deviceListButton_clicked\0"
    "on_alarmListButton_clicked\0"
    "on_capturePictureButton_clicked\0"
    "on_startVoiceTalkButton_clicked\0"
    "on_stopVoiceTalkButton_clicked\0"
    "on_switchSoundButton_clicked\0"
    "on_setVolumeSlider_sliderReleased\0"
    "on_setAlarmReadButton_clicked\0"
    "on_defenceOnButton_clicked\0"
    "on_defenceOffButton_clicked\0"
    "on_insRecordFile\0on_insPlayException\0"
    "on_insPlayBackEnd\0on_insPlayReconnectException\0"
    "on_insRecordSearchFailed\0on_insPlayAlarm\0"
    "on_insPlayPush\0on_insPtzStartUp\0"
    "on_insPtzStartDown\0on_insPtzStartLeft\0"
    "on_insPtzStartRight\0on_insPtzStartUpLeft\0"
    "on_insPtzStartDownLeft\0on_insPtzStartUpRight\0"
    "on_insPtzStartDownRight\0on_insPtzStopUp\0"
    "on_insPtzStopDown\0on_insPtzStopLeft\0"
    "on_insPtzStopRight\0on_insPtzStopUpLeft\0"
    "on_insPtzStopDownLeft\0on_insPtzStopUpRight\0"
    "on_insPtzStopDownRight\0on_insPtzStartZoomIn\0"
    "on_insPtzStartZoomOut\0on_insPtzStopZoomIn\0"
    "on_insPtzStopZoomOut\0on_insPtzStartFocusFar\0"
    "on_insPtzStartFocusNear\0on_insPtzStopFocusFar\0"
    "on_insPtzStopFocusNear\0on_insPtzStartIrisStartUp\0"
    "on_insPtzStartIrisStopDown\0"
    "on_insPtzStopIrisStartUp\0"
    "on_insPtzStopIrisStopDown\0"
    "on_insPtzAutoStartUp\0on_insPtzAutoStopDown\0"
    "on_insPtzStart\0on_insPtzStop\0"
    "on_insPlayStart\0on_insPlayStop\0"
    "on_insGetCameraInfo\0on_insUpdateCameraInfo\0"
    "on_smoothAction\0on_equilibriumAction\0"
    "on_clearAction\0on_highAction\0displayosd\0"
    "on_stopPushRecvButton_clicked\0"
    "on_startPushRecvButton_clicked\0"
    "on_pushAlarmCheckBox_stateChanged\0"
    "arg1\0on_pushDevStatusCheckBox_stateChanged\0"
    "on_pushTransparentChannelCheckBox_stateChanged\0"
    "on_showAlarmPicButton_clicked\0"
    "on_startRealPlayButton_clicked\0"
    "on_setPlayBackTimeButton_clicked\0"
    "on_pushButton_clicked\0"
    "on_shareDevListButton_clicked\0"
    "on_logoutButton_clicked\0"
    "on_videoRecordBox_stateChanged\0"
    "on_deviceInfoButton_clicked\0TableIndex\0"
    "DeviceTableIndex\0SharedDeviceIndex\0"
    "AlarmTableIndex\0PushAlarmTableIndex\0"
    "PlayBackTableIndex\0JsonInfoTableIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      94,   14, // methods
       0,    0, // properties
       1,  662, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  484,    2, 0x06 /* Public */,
       4,    2,  487,    2, 0x06 /* Public */,
       6,    1,  492,    2, 0x06 /* Public */,
       7,    2,  495,    2, 0x06 /* Public */,
       8,    2,  500,    2, 0x06 /* Public */,
       9,    3,  505,    2, 0x06 /* Public */,
      13,    3,  512,    2, 0x06 /* Public */,
      16,    3,  519,    2, 0x06 /* Public */,
      17,    1,  526,    2, 0x06 /* Public */,
      20,    1,  529,    2, 0x06 /* Public */,
      21,    0,  532,    2, 0x06 /* Public */,
      22,    0,  533,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  534,    2, 0x0a /* Public */,
      26,    1,  537,    2, 0x0a /* Public */,
      27,    1,  540,    2, 0x0a /* Public */,
      28,    0,  543,    2, 0x0a /* Public */,
      29,    0,  544,    2, 0x0a /* Public */,
      30,    0,  545,    2, 0x0a /* Public */,
      31,    0,  546,    2, 0x0a /* Public */,
      32,    0,  547,    2, 0x0a /* Public */,
      33,    0,  548,    2, 0x0a /* Public */,
      34,    0,  549,    2, 0x0a /* Public */,
      35,    0,  550,    2, 0x0a /* Public */,
      36,    0,  551,    2, 0x0a /* Public */,
      37,    0,  552,    2, 0x0a /* Public */,
      38,    0,  553,    2, 0x0a /* Public */,
      39,    0,  554,    2, 0x0a /* Public */,
      40,    0,  555,    2, 0x0a /* Public */,
      41,    0,  556,    2, 0x0a /* Public */,
      42,    0,  557,    2, 0x0a /* Public */,
      43,    0,  558,    2, 0x0a /* Public */,
      44,    0,  559,    2, 0x0a /* Public */,
      45,    0,  560,    2, 0x0a /* Public */,
      46,    1,  561,    2, 0x0a /* Public */,
      47,    2,  564,    2, 0x0a /* Public */,
      48,    1,  569,    2, 0x0a /* Public */,
      49,    2,  572,    2, 0x0a /* Public */,
      50,    2,  577,    2, 0x0a /* Public */,
      51,    3,  582,    2, 0x0a /* Public */,
      52,    3,  589,    2, 0x0a /* Public */,
      53,    0,  596,    2, 0x0a /* Public */,
      54,    0,  597,    2, 0x0a /* Public */,
      55,    0,  598,    2, 0x0a /* Public */,
      56,    0,  599,    2, 0x0a /* Public */,
      57,    0,  600,    2, 0x0a /* Public */,
      58,    0,  601,    2, 0x0a /* Public */,
      59,    0,  602,    2, 0x0a /* Public */,
      60,    0,  603,    2, 0x0a /* Public */,
      61,    0,  604,    2, 0x0a /* Public */,
      62,    0,  605,    2, 0x0a /* Public */,
      63,    0,  606,    2, 0x0a /* Public */,
      64,    0,  607,    2, 0x0a /* Public */,
      65,    0,  608,    2, 0x0a /* Public */,
      66,    0,  609,    2, 0x0a /* Public */,
      67,    0,  610,    2, 0x0a /* Public */,
      68,    0,  611,    2, 0x0a /* Public */,
      69,    0,  612,    2, 0x0a /* Public */,
      70,    0,  613,    2, 0x0a /* Public */,
      71,    0,  614,    2, 0x0a /* Public */,
      72,    0,  615,    2, 0x0a /* Public */,
      73,    0,  616,    2, 0x0a /* Public */,
      74,    0,  617,    2, 0x0a /* Public */,
      75,    0,  618,    2, 0x0a /* Public */,
      76,    0,  619,    2, 0x0a /* Public */,
      77,    0,  620,    2, 0x0a /* Public */,
      78,    0,  621,    2, 0x0a /* Public */,
      79,    0,  622,    2, 0x0a /* Public */,
      80,    0,  623,    2, 0x0a /* Public */,
      81,    0,  624,    2, 0x0a /* Public */,
      82,    0,  625,    2, 0x0a /* Public */,
      83,    1,  626,    2, 0x0a /* Public */,
      84,    1,  629,    2, 0x0a /* Public */,
      85,    0,  632,    2, 0x0a /* Public */,
      86,    0,  633,    2, 0x0a /* Public */,
      87,    0,  634,    2, 0x0a /* Public */,
      88,    0,  635,    2, 0x0a /* Public */,
      89,    0,  636,    2, 0x0a /* Public */,
      90,    0,  637,    2, 0x0a /* Public */,
      91,    0,  638,    2, 0x0a /* Public */,
      92,    0,  639,    2, 0x0a /* Public */,
      93,    0,  640,    2, 0x0a /* Public */,
      94,    0,  641,    2, 0x08 /* Private */,
      95,    0,  642,    2, 0x08 /* Private */,
      96,    1,  643,    2, 0x08 /* Private */,
      98,    1,  646,    2, 0x08 /* Private */,
      99,    1,  649,    2, 0x08 /* Private */,
     100,    0,  652,    2, 0x08 /* Private */,
     101,    0,  653,    2, 0x08 /* Private */,
     102,    0,  654,    2, 0x08 /* Private */,
     103,    0,  655,    2, 0x08 /* Private */,
     104,    0,  656,    2, 0x08 /* Private */,
     105,    0,  657,    2, 0x08 /* Private */,
     106,    1,  658,    2, 0x08 /* Private */,
     107,    0,  661,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   11,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   11,   15,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   11,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   97,
    QMetaType::Void, QMetaType::Int,   97,
    QMetaType::Void, QMetaType::Int,   97,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   97,
    QMetaType::Void,

 // enums: name, flags, count, data
     108, 0x0,    6,  666,

 // enum data: key, value
     109, uint(MainWindow::DeviceTableIndex),
     110, uint(MainWindow::SharedDeviceIndex),
     111, uint(MainWindow::AlarmTableIndex),
     112, uint(MainWindow::PushAlarmTableIndex),
     113, uint(MainWindow::PlayBackTableIndex),
     114, uint(MainWindow::JsonInfoTableIndex),

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insRecordFile((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->insPlayException((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 2: _t->insPlayBackEnd((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: _t->insPlayReconnectException((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 4: _t->insRecordSearchFailed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 5: _t->insPlayAlarm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->insPlayPush((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->insPlayPushAlarm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->insPtzStart((*reinterpret_cast< PTZCMD(*)>(_a[1]))); break;
        case 9: _t->insPtzStop((*reinterpret_cast< PTZCMD(*)>(_a[1]))); break;
        case 10: _t->insPlayStart(); break;
        case 11: _t->insPlayStop(); break;
        case 12: _t->slotDeviceTableViewPressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->slotPlayBackTableViewPressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->slotPushAlarmTableViewPressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->on_loginButton_clicked(); break;
        case 16: _t->on_deviceAddButton_clicked(); break;
        case 17: _t->on_stopRealPlayButton_clicked(); break;
        case 18: _t->on_playBackListButton_clicked(); break;
        case 19: _t->on_startPlayBackButton_clicked(); break;
        case 20: _t->on_stopPlayBackButton_clicked(); break;
        case 21: _t->on_pauseButton_clicked(); break;
        case 22: _t->on_resumeButton_clicked(); break;
        case 23: _t->on_deviceListButton_clicked(); break;
        case 24: _t->on_alarmListButton_clicked(); break;
        case 25: _t->on_capturePictureButton_clicked(); break;
        case 26: _t->on_startVoiceTalkButton_clicked(); break;
        case 27: _t->on_stopVoiceTalkButton_clicked(); break;
        case 28: _t->on_switchSoundButton_clicked(); break;
        case 29: _t->on_setVolumeSlider_sliderReleased(); break;
        case 30: _t->on_setAlarmReadButton_clicked(); break;
        case 31: _t->on_defenceOnButton_clicked(); break;
        case 32: _t->on_defenceOffButton_clicked(); break;
        case 33: _t->on_insRecordFile((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 34: _t->on_insPlayException((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 35: _t->on_insPlayBackEnd((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 36: _t->on_insPlayReconnectException((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 37: _t->on_insRecordSearchFailed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 38: _t->on_insPlayAlarm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 39: _t->on_insPlayPush((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 40: _t->on_insPtzStartUp(); break;
        case 41: _t->on_insPtzStartDown(); break;
        case 42: _t->on_insPtzStartLeft(); break;
        case 43: _t->on_insPtzStartRight(); break;
        case 44: _t->on_insPtzStartUpLeft(); break;
        case 45: _t->on_insPtzStartDownLeft(); break;
        case 46: _t->on_insPtzStartUpRight(); break;
        case 47: _t->on_insPtzStartDownRight(); break;
        case 48: _t->on_insPtzStopUp(); break;
        case 49: _t->on_insPtzStopDown(); break;
        case 50: _t->on_insPtzStopLeft(); break;
        case 51: _t->on_insPtzStopRight(); break;
        case 52: _t->on_insPtzStopUpLeft(); break;
        case 53: _t->on_insPtzStopDownLeft(); break;
        case 54: _t->on_insPtzStopUpRight(); break;
        case 55: _t->on_insPtzStopDownRight(); break;
        case 56: _t->on_insPtzStartZoomIn(); break;
        case 57: _t->on_insPtzStartZoomOut(); break;
        case 58: _t->on_insPtzStopZoomIn(); break;
        case 59: _t->on_insPtzStopZoomOut(); break;
        case 60: _t->on_insPtzStartFocusFar(); break;
        case 61: _t->on_insPtzStartFocusNear(); break;
        case 62: _t->on_insPtzStopFocusFar(); break;
        case 63: _t->on_insPtzStopFocusNear(); break;
        case 64: _t->on_insPtzStartIrisStartUp(); break;
        case 65: _t->on_insPtzStartIrisStopDown(); break;
        case 66: _t->on_insPtzStopIrisStartUp(); break;
        case 67: _t->on_insPtzStopIrisStopDown(); break;
        case 68: _t->on_insPtzAutoStartUp(); break;
        case 69: _t->on_insPtzAutoStopDown(); break;
        case 70: _t->on_insPtzStart((*reinterpret_cast< PTZCMD(*)>(_a[1]))); break;
        case 71: _t->on_insPtzStop((*reinterpret_cast< PTZCMD(*)>(_a[1]))); break;
        case 72: _t->on_insPlayStart(); break;
        case 73: _t->on_insPlayStop(); break;
        case 74: _t->on_insGetCameraInfo(); break;
        case 75: _t->on_insUpdateCameraInfo(); break;
        case 76: _t->on_smoothAction(); break;
        case 77: _t->on_equilibriumAction(); break;
        case 78: _t->on_clearAction(); break;
        case 79: _t->on_highAction(); break;
        case 80: _t->displayosd(); break;
        case 81: _t->on_stopPushRecvButton_clicked(); break;
        case 82: _t->on_startPushRecvButton_clicked(); break;
        case 83: _t->on_pushAlarmCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 84: _t->on_pushDevStatusCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: _t->on_pushTransparentChannelCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 86: _t->on_showAlarmPicButton_clicked(); break;
        case 87: _t->on_startRealPlayButton_clicked(); break;
        case 88: _t->on_setPlayBackTimeButton_clicked(); break;
        case 89: _t->on_pushButton_clicked(); break;
        case 90: _t->on_shareDevListButton_clicked(); break;
        case 91: _t->on_logoutButton_clicked(); break;
        case 92: _t->on_videoRecordBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 93: _t->on_deviceInfoButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insRecordFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(unsigned  , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayException)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayBackEnd)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(unsigned  , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayReconnectException)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(unsigned  , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insRecordSearchFailed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayAlarm)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayPush)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayPushAlarm)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(PTZCMD );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPtzStart)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(PTZCMD );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPtzStop)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayStart)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::insPlayStop)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 94)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 94;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 94)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 94;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::insRecordFile(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::insPlayException(unsigned  _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::insPlayBackEnd(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::insPlayReconnectException(unsigned  _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::insRecordSearchFailed(unsigned  _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::insPlayAlarm(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::insPlayPush(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::insPlayPushAlarm(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::insPtzStart(PTZCMD _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::insPtzStop(PTZCMD _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::insPlayStart()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MainWindow::insPlayStop()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
