using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace EzvizDemo
{
    class EzvizSDK
    {
        public enum MessageType
        {
            INS_PLAY_EXCEPTION              = 0,   ///< Playback exception, which is usually cased by device offline or network exception
            INS_PLAY_RECONNECT              = 1,   ///< Reconnect,auto-reconnect at real-time stream playing
            INS_PLAY_RECONNECT_EXCEPTION    = 2,   ///< Reconnect exception
            INS_PLAY_START                  = 3,   ///< Start playing
            INS_PLAY_STOP                   = 4,   ///< Stop playing
            INS_PLAY_ARCHIVE_END            = 5,   ///< Message pop up when play ended

            INS_VOICETALK_START             = 16,  ///< Start two-way audio 
            INS_VOICETALK_STOP              = 17,  ///< Stop two-way audio
            INS_VOICETALK_EXCEPTION         = 18,  ///< Two-way aodio exception 
            INS_PTZ_EXCEPTION               = 19,  ///< PTZ control exception
            INS_RECORD_FILE                 = 20,  ///< Search recording files
            INS_RECORD_SEARCH_END           = 21,  ///< Record search ended (do not enable now)
            INS_RECORD_SEARCH_FAILED        = 22,  ///< Record search failed
            INS_DEFENSE_SUCCESS             = 23,  ///< Arming succeeded
            INS_DEFENSE_FAILED              = 24,  ///< Arming failed
            INS_PLAY_ARCHIVE_EXCEPTION      = 28,  ///< Playback exception, which may due to receiving data timed out
            INS_PTZCTRL_SUCCESS             = 46,  ///< PTZ control succeeded
            INS_PTZCTRL_FAILED              = 47,  ///< PTZ control failed
        };

        /**
         *  \brief Message callback error code definition(MessageInfo)
         */
        public const string OPEN_SDK_STREAM_ACCESSTOKEN_ERROR_OR_EXPIRE  = "UE001"; 	///< Accesstoken expire or invalid. update accesstoken.
        public const string OPEN_SDK_STREAM_PU_NO_RESOURCE      		 = "UE101";	    ///< Device connection is too many, upgrade the device version, Hikvision devices can consult customer service to obtain the upgrade process.
        public const string OPEN_SDK_STREAM_TRANSF_DEVICE_OFFLINE   	 = "UE102"; 	///< Device offline. Connect the device to network and try again.
        public const string OPEN_SDK_STREAM_INNER_TIMEOUT                = "UE103"; 	///< Request to connect device to timeout, detect device network connection is normal.
        public const string OPEN_SDK_STREAM_INNER_VERIFYCODE_ERROR   	 = "UE104"; 	///< Video verificaiton code error, check the verification code marked on the device.
        public const string OPEN_SDK_STREAM_PLAY_FAIL       			 = "UE105"; 	///< Failed to play the video, please check the message callback specific error code iErrorCode.
        public const string OPEN_SDK_STREAM_TRANSF_TERMINAL_BINDING   	 = "UE106"; 	///< The current account has enabled terminal binding. Only the specified device can log in.
        public const string OPEN_SDK_STREAM_VIDEO_RECORD_NOTEXIST   	 = "UE108";     ///< Video record not found.
        public const string OPEN_SDK_STREAM_VTDU_CONCURRENT_LIMIT        = "UE109";     ///< Take the flow of concurrent route restrictions, please upgrade to Enterprise Edition
        public const string OPEN_SDK_STREAM_UNSUPPORTED            	     = "UE110";	    ///< The type of resolution that the device does not support is selected according to the device preview capability level.

        /** \enum PTZCommand
         *  \brief 
         */
        public enum PTZCommand
        {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            UPLEFT,
            DOWNLEFT,
            UPRIGHT,
            DOWNRIGHT,
            ZOOMIN,
            ZOOMOUT,
            FOCUSNEAR,
            FOCUSFAR,
            IRISSTARTUP,
            IRISSTOPDOWN,
            LIGHT,
            WIPER,
            AUTO
        };

        /** \enum PTZCommand
         *  \brief PTZ control command 
         */
        public enum PTZAction
        {
            START,
            STOP
        };

        //DataCallBack DataType
        public enum CallBackDateType
        {
            NET_DVR_SYSHEAD = 0,
            NET_DVR_STREAMDATA = 1,
            NET_DVR_RECV_END = 2,
        };

        //Init API
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_InitLib")] //SDK Init
        public static extern int OpenSDK_InitLib(string AuthAddr, string Platform, string appId);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_FiniLib")] //SDK Fini
        public static extern int OpenSDK_FiniLib();
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_SetAccessToken")] //Set AccessToken
        public static extern int OpenSDK_SetAccessToken(string AccessToken);

        //Mid API
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_Mid_Login")]
        public static extern int OpenSDK_Mid_Login(ref IntPtr pAccessToken, ref int iAccessTokenLen);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_Mid_Device_Add")]
        public static extern int OpenSDK_Mid_Device_Add(string AccessToken);
        //DATA API
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_Data_GetDevList")]
        public static extern int OpenSDK_Data_GetDevList(string AccessToken, int iPageStart, int iPageSize, ref IntPtr pBuf, ref int iBufLen);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_Data_GetDevDetailInfo")]
        public static extern int OpenSDK_Data_GetDevDetailInfo(string DevSerial, int ChannelNo, bool bUpdate, ref IntPtr pBuf, ref int iBufLen);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_Data_Free")]
        public static extern int OpenSDK_Data_Free(IntPtr pBuf);

        //PLAY API
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_AllocSessionEx")] //SDK Alloc Sessioon
        public static extern int OpenSDK_AllocSessionEx(OpenSDK_MsgHandler MsgCallBack, IntPtr UserID, ref IntPtr pSID, ref int SIDLen);
        //delegate of message callback api 
        public delegate int OpenSDK_MsgHandler(IntPtr SessionID, uint MsgType, uint Error, string Info, IntPtr pUser);
        
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_FreeSession")]//SDK Free Session
        public static extern int OpenSDK_FreeSession(string SID);

        [DllImport("OpenNetStream.dll")]//Set Data Callback
        public static extern int OpenSDK_SetDataCallBack(IntPtr SessionId, OpenSDK_DataCallBack DataCallBack, IntPtr pUser);
        //delegate of data callback api 
        public delegate void OpenSDK_DataCallBack(CallBackDateType dateType, IntPtr dateContent, int dataLen, string pUser);

        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_StartRealPlayEx")]
        public static extern int OpenSDK_StartRealPlayEx(string SessionId, IntPtr PlayWnd, string DevSerial, int ChannelNo, string SafeKey);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_StopRealPlayEx")]
        public static extern int OpenSDK_StopRealPlayEx(string SessionId);

        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_SetVideoLevel")]
        public static extern int OpenSDK_SetVideoLevel(string DevSerial, int ChannelNo, int iVideoLevel);

        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_StartSearchEx")]
        public static extern int OpenSDK_StartSearchEx(string SessionId, string DevSerial, int ChannelNo, string StartTime, string StopTime);

        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_StartPlayBackEx")]
        public static extern int OpenSDK_StartPlayBackEx(string SessionId, IntPtr PlayWnd, string DevSerial, int ChannelNo, string SafeKey, string StartTime, string StopTime);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_StopPlayBackEx")]
        public static extern int OpenSDK_StopPlayBackEx(string SessionId);

        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_PlayBackResume")]
        public static extern int OpenSDK_PlayBackResume(string SessionId);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_PlayBackPause")]
        public static extern int OpenSDK_PlayBackPause(string SessionId);

        //PTZ Control
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_PTZCtrlEx")]
        public static extern int OpenSDK_PTZCtrlEx(string SessionId, string DevSerial, int ChannelNo, PTZCommand Command, PTZAction Action, int iSpeed);

        //Talk
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_StartVoiceTalkEx")]
        public static extern int OpenSDK_StartVoiceTalkEx(string SessionId, string DevSerial, int ChannelNo);
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_StopVoiceTalk")]
        public static extern int OpenSDK_StopVoiceTalk(string SessionId);

        //Error Info
        [DllImport("OpenNetStream.dll", EntryPoint = "OpenSDK_GetLastErrorCode")]
        public static extern int OpenSDK_GetLastErrorCode();
        

        [DllImport("kernel32")]
        public static extern int GetPrivateProfileString(string section, string key, string def, byte[] retVal, int size, string filePath);

    }
}
