using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;
using Microsoft.VisualBasic;
using System.Threading;
using System.Globalization;

namespace EzvizDemo
{
    public partial class OpenSDKMainForm : Form
    {
        //define delegate for thread-safe
        public delegate void SearchVideoRecordEntrust(ListView PlayBackList, string RecordInfo);

        public string g_strToken;
        public string g_strAuthAddress;
        public string g_strPlatformAddress;
        public string g_strAppKey;
        public string g_strPushSecret;
        public string g_strIsPlay;
        public string g_strDataUtf8;
        public string g_strStreamMeta;
        public string g_strSaveData;
        public string g_strAreaID;
        public string g_strLoginVer;
        public string g_strSessionId;
        public ListView g_listViewDevice;
        public ListView g_listViewPlayBack;
        public SearchVideoRecordEntrust g_SearchVideoRecordCallBack;
        public GCHandle g_handleForThis;
        //avoid MessageHandler release by system GC
        static EzvizSDK.OpenSDK_MsgHandler g_msgcallback = new EzvizSDK.OpenSDK_MsgHandler(MessageHandler);

		public class SearchResult
        {
            public string cameraId { get; set; }
            public string cameraName { get; set; }
            public string cameraNo { get; set; }
            public string defence { get; set; }
            public string deviceId { get; set; }
            public string deviceSerial { get; set; }
            public string isEncrypt { get; set; }
            public string isShared { get; set; }
            public string picUrl { get; set; }
            public string status { get; set; }
            public string videoLevel { get; set; }
        }

        public class RecordResult
        {
            public string StartTime { get; set; }
            public string EndTime { get; set; }
        }

        public class VideoQualityInfo
        {
            public string videoQualityName;
            public string videoLevel;
            public string streamType;

            public override string ToString()
            {
                return videoQualityName;
            }
        }

        public OpenSDKMainForm()
        {
            //define delegate
            g_SearchVideoRecordCallBack = new SearchVideoRecordEntrust(SearchVideoRecordCallBack);
            InitializeComponent();
            InitSearchTime();
            InitDevList();
            InitPlayBackList();
            // Read init data
            InitConfig();
        }

        public void InitConfig()
        {
            ReadIniData("authAddress", "https://auth.ys7.com", ref g_strAuthAddress);
            ReadIniData("platformAddress", "https://open.ys7.com", ref g_strPlatformAddress);
            ReadIniData("appKey", "", ref g_strAppKey);
            ReadIniData("pushSecret", "", ref g_strPushSecret);
            ReadIniData("isPlay", "true", ref g_strIsPlay);
            ReadIniData("dataUtf8", "false", ref g_strDataUtf8);
            ReadIniData("streamMeta", "false", ref g_strStreamMeta);
            ReadIniData("saveData", "false", ref g_strSaveData);
            ReadIniData("areaID", "", ref g_strAreaID);
            ReadIniData("loginVer", "", ref g_strLoginVer);
        }

        public void InitSearchTime()
        {
            pickerStartTime.Format = DateTimePickerFormat.Custom;
            pickerStartTime.CustomFormat = "yyyy-MM-dd HH:mm:ss";
            pickerStartTime.Value = DateTime.Now.Date;

            pickerStopTime.Format = DateTimePickerFormat.Custom;
            pickerStopTime.CustomFormat = "yyyy-MM-dd HH:mm:ss";
        }

        public void InitDevList()
        {
            // Create a new ListView control.
            g_listViewDevice = new ListView();
            g_listViewDevice.Bounds = new Rectangle(new Point(10, 10), new Size(300, 500));
            // Set the view to show details.
            g_listViewDevice.View = View.Details;
            // Allow the user to rearrange columns.
            g_listViewDevice.AllowColumnReorder = true;
            // Select the item and subitems when selection is made.
            g_listViewDevice.FullRowSelect = true;
            // Display grid lines.
            g_listViewDevice.GridLines = true;
            // Sort the items in the list in ascending order.
            g_listViewDevice.Sorting = SortOrder.Ascending;

            // Create columns for the items and subitems.
            // Width of -2 indicates auto-size.
            g_listViewDevice.Columns.Add("ID", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("Subserial", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("ChannelNo", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("CameraName", 200, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("Status", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("IsEncrypt", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("IsShared", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("VideoLevel", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("Defence", -2, HorizontalAlignment.Left);
            g_listViewDevice.Columns.Add("PicUrl", -2, HorizontalAlignment.Left);
            g_listViewDevice.Anchor = (AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Bottom | AnchorStyles.Right);
            g_listViewDevice.SelectedIndexChanged += new EventHandler(ListViewDevice_SelectedIndexChanged);
            // add to TabPage
            TabPage tabPageDev = new TabPage();
            tabPageDev.Text = "Device List";
            tabPageDev.Anchor = (AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Bottom | AnchorStyles.Right);
            tabPageDev.Controls.Add(g_listViewDevice);
            tabControlShow.Controls.Add(tabPageDev);
        }

        public void InitPlayBackList()
        {
            // Create a new ListView control.
            g_listViewPlayBack = new ListView();
            g_listViewPlayBack.Bounds = new Rectangle(new Point(10, 10), new Size(300, 500));
            // Set the view to show details.
            g_listViewPlayBack.View = View.Details;
            // Allow the user to rearrange columns.
            g_listViewPlayBack.AllowColumnReorder = true;
            // Display check boxes.
            //g_listViewPlayBack.CheckBoxes = true;
            // Select the item and subitems when selection is made.
            g_listViewPlayBack.FullRowSelect = true;
            // Display grid lines.
            g_listViewPlayBack.GridLines = true;
            // Sort the items in the list in ascending order.
            g_listViewPlayBack.Sorting = SortOrder.Ascending;

            // Create columns for the items and subitems.
            // Width of -2 indicates auto-size.
            g_listViewPlayBack.Columns.Add("ID", -2, HorizontalAlignment.Left);
            g_listViewPlayBack.Columns.Add("StartTime", -2, HorizontalAlignment.Left);
            g_listViewPlayBack.Columns.Add("EndTime", -2, HorizontalAlignment.Left);
            g_listViewPlayBack.Anchor = (AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Bottom | AnchorStyles.Right);
            // add to TabPage
            TabPage tabPageDev = new TabPage();
            tabPageDev.Text = "Video Record List";
            tabPageDev.Anchor = (AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Bottom | AnchorStyles.Right);
            tabPageDev.Controls.Add(g_listViewPlayBack);
            tabControlShow.Controls.Add(tabPageDev);
        }

        public int ReadIniData(string key, string def, ref string value)
        {
            Byte[] Buffer = new Byte[128];
            string strFileName = Application.StartupPath + "\\EzvizCSharfDemo.ini";
            int buflen = EzvizSDK.GetPrivateProfileString("OpenAPI", key, def, Buffer, Buffer.GetUpperBound(0), strFileName);
            value = System.Text.Encoding.Default.GetString(Buffer, 0, buflen);
            return buflen;
        }

        public void ParseVideoRecord(string RecordInfo)
        {
            // turn sub-thread to main-thread.
            if (g_listViewPlayBack.InvokeRequired)
            {
                g_listViewPlayBack.Invoke(g_SearchVideoRecordCallBack, g_listViewPlayBack, RecordInfo);
            }
            else
            {
                g_SearchVideoRecordCallBack(g_listViewPlayBack, RecordInfo);
            }
        }

        public void SearchVideoRecordCallBack(ListView PlayBackList, string RecordInfo)
        {
            Newtonsoft.Json.Linq.JObject json = Newtonsoft.Json.Linq.JObject.Parse(RecordInfo);
            if (json["FileList"] == null)
            {
                return;
            }
            List<Newtonsoft.Json.Linq.JToken> listRecord = json["FileList"].Children().ToList();
            int i = 0;
            PlayBackList.Items.Clear();

            listRecord.ForEach(x =>
            {
                OpenSDKMainForm.RecordResult searchResult = Newtonsoft.Json.JsonConvert.DeserializeObject<OpenSDKMainForm.RecordResult>(x.ToString());
                ListViewItem list = new ListViewItem();
                i++;
                list.Text = i.ToString();
                list.SubItems.Add(searchResult.StartTime);
                list.SubItems.Add(searchResult.EndTime);
                PlayBackList.Items.Add(list);
            });
        }

        public static string ConvertPlayErrorToMessage(string szError)
        {
            if (szError == "")
            {
                return "";
            }
            string msg;
            if (EzvizSDK.OPEN_SDK_STREAM_ACCESSTOKEN_ERROR_OR_EXPIRE == szError)
            {
                msg = "Accesstoken expire or invalid. update accesstoken.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_PU_NO_RESOURCE == szError)
            {
                msg = "Device connection is too many, upgrade the device version, Hikvision devices can consult customer service to obtain the upgrade process.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_TRANSF_DEVICE_OFFLINE == szError)
            {
                msg = "Device offline. Connect the device to network and try again.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_INNER_TIMEOUT == szError)
            {
                msg = "Request to connect device to timeout, detect device network connection is normal.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_INNER_VERIFYCODE_ERROR == szError)
            {
                msg = "Video verificaiton code error, check the verification code marked on the device.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_PLAY_FAIL == szError)
            {
                msg = "Failed to play the video, please check the message callback specific error code iErrorCode.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_TRANSF_TERMINAL_BINDING == szError)
            {
                msg = "The current account has enabled terminal binding. Only the specified device can log in.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_VIDEO_RECORD_NOTEXIST == szError)
            {
                msg = "Video record not found.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_VTDU_CONCURRENT_LIMIT == szError)
            {
                msg = "Take the flow of concurrent route restrictions, please upgrade to Enterprise Edition.";
            }
            else if (EzvizSDK.OPEN_SDK_STREAM_UNSUPPORTED == szError)
            {
                msg = "The type of resolution that the device does not support is selected according to the device preview capability level.";
            }
            else
            {
                msg = "Failed to play the video, please check the message callback specific error code iErrorCode.";
            }
            
            return msg;
        }

        //回调函数
        public static int MessageHandler(IntPtr SessionId, uint MsgType, uint Error, string Info, IntPtr pUser)
        {
            EzvizSDK.MessageType eventType = (EzvizSDK.MessageType)(MsgType);
            switch (eventType)
            {
                case EzvizSDK.MessageType.INS_RECORD_FILE:
                    {
                        GCHandle handle = GCHandle.FromIntPtr(pUser);
                        if (handle.IsAllocated)
                        {
                            OpenSDKMainForm mainForm = (OpenSDKMainForm)handle.Target;
                            mainForm.ParseVideoRecord(Info);
                        }
                    }
                    break;
                case EzvizSDK.MessageType.INS_PLAY_EXCEPTION:
                    string errInfo = ConvertPlayErrorToMessage(Info) ;
                    string caption = "Play Failed. ErrInfo[" + Info + "], ErrCode[" + Error + "]";
                    MessageBox.Show(errInfo, caption);
                    break;
                case EzvizSDK.MessageType.INS_PLAY_START:
                    MessageBox.Show("Play Success.");
                    break;
                case EzvizSDK.MessageType.INS_PLAY_STOP:
                    break;
                case EzvizSDK.MessageType.INS_PLAY_ARCHIVE_END:
                    break;
                case EzvizSDK.MessageType.INS_VOICETALK_START:
                    MessageBox.Show("Talk Success.");
                    break;
                case EzvizSDK.MessageType.INS_VOICETALK_STOP:
                    break;
                case EzvizSDK.MessageType.INS_PTZCTRL_SUCCESS:
                    break;
                case EzvizSDK.MessageType.INS_PTZCTRL_FAILED:
                    break;
                default:
                    break;
            }
            return 0;
        }

        public void GetDeviceList()
        {
            int pageStart = 0;
            int pageSize = 1000;
            string strBuf = string.Empty;
            IntPtr hBuf = Marshal.StringToHGlobalAnsi(strBuf);
            int iLen = 0;
            int iRet = EzvizSDK.OpenSDK_Data_GetDevList(g_strToken, pageStart, pageSize, ref hBuf, ref iLen);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("Failed to get device list", caption);
                return;
            }

            strBuf = Marshal.PtrToStringAnsi(hBuf);
            Newtonsoft.Json.Linq.JObject json = Newtonsoft.Json.Linq.JObject.Parse(strBuf);
            if (json["cameraList"] == null)
            {
                return;
            }
            List<Newtonsoft.Json.Linq.JToken> listToken = json["cameraList"].Children().ToList();
            int i = 0;
            g_listViewDevice.Items.Clear();

            listToken.ForEach(x =>
            {
                OpenSDKMainForm.SearchResult searchResult = Newtonsoft.Json.JsonConvert.DeserializeObject<OpenSDKMainForm.SearchResult>(x.ToString());
                ListViewItem list = new ListViewItem();
                i++;
                list.Text = i.ToString();
                list.SubItems.Add(searchResult.deviceSerial);
                list.SubItems.Add(searchResult.cameraNo);
                list.SubItems.Add(searchResult.cameraName);
                list.SubItems.Add(searchResult.status);
                list.SubItems.Add(searchResult.isEncrypt);
                list.SubItems.Add(searchResult.isShared);
                list.SubItems.Add(searchResult.videoLevel);
                list.SubItems.Add(searchResult.defence);
                list.SubItems.Add(searchResult.picUrl);
                g_listViewDevice.Items.Add(list);
            });
            tabControlShow.SelectTab(0);
        }

        private void OpenSDKMainForm_Load(object sender, EventArgs e)
        {
            //Init Lib
            EzvizSDK.OpenSDK_InitLib(g_strAuthAddress, g_strPlatformAddress, g_strAppKey);
            string strBuf = string.Empty;
            IntPtr hBuf = Marshal.StringToHGlobalAnsi(strBuf);
            int iLen = 0;

            g_handleForThis = GCHandle.Alloc(this);
            IntPtr pUser = GCHandle.ToIntPtr(g_handleForThis);
            int iRet = EzvizSDK.OpenSDK_AllocSessionEx(g_msgcallback, pUser, ref hBuf, ref iLen);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("AllocSession failed.", caption);
                return;
            }
            strBuf = Marshal.PtrToStringAnsi(hBuf);
            g_strSessionId = strBuf;

        }

        private void OpenSDKMainForm_Closed(object sender, EventArgs e)
        {
            g_handleForThis.Free();
            EzvizSDK.OpenSDK_FreeSession(g_strSessionId);
            //Init Lib
            EzvizSDK.OpenSDK_FiniLib();
        }

        private void btnLoginIn_Click(object sender, EventArgs e)
        {
            string strToken = string.Empty;
            IntPtr hToken = Marshal.StringToHGlobalAnsi(strToken);
            int iLen = 0;

            EzvizSDK.OpenSDK_Mid_Login(ref hToken, ref iLen);
            strToken = Marshal.PtrToStringAnsi(hToken);
            if (strToken != "")
            {
                g_strToken = strToken;
                EzvizSDK.OpenSDK_SetAccessToken(g_strToken);
                GetDeviceList();
            }
            
        }

        private void btnStartPlay_Click(object sender, EventArgs e)
        {
            if (g_listViewDevice.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select a device from device list.");
                return;
            }

            string subSerial = g_listViewDevice.SelectedItems[0].SubItems[1].Text;
            string channelNo = g_listViewDevice.SelectedItems[0].SubItems[2].Text;
            string iEncrypt = g_listViewDevice.SelectedItems[0].SubItems[5].Text;
            int iChannelNo = int.Parse(channelNo);
            bool bEnc = (int.Parse(iEncrypt) == 1) ? true : false;
            string safekey = "";
            if (bEnc)
            {
                safekey = Microsoft.VisualBasic.Interaction.InputBox("Please input device verify code", "device is encrypted.", "", -1, -1);
                if (safekey == "")
                {
                    return;
                }
            }

            int iRet = EzvizSDK.OpenSDK_StartRealPlayEx(g_strSessionId, previewPanel.Handle, subSerial, iChannelNo, safekey);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("StartRealPlay failed.", caption);
                return;
            }
        }

        private void btnStopPlay_Click(object sender, EventArgs e)
        {
            int iRet = EzvizSDK.OpenSDK_StopRealPlayEx(g_strSessionId);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("OpenSDK_StopRealPlay failed.", caption);
                return;
            }
        }

        private void PTZControl(EzvizSDK.PTZCommand Command, EzvizSDK.PTZAction Action)
        {
            if (g_listViewDevice.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select a device from device list.");
                return;
            }

            string subSerial = g_listViewDevice.SelectedItems[0].SubItems[1].Text;
            string channelNo = g_listViewDevice.SelectedItems[0].SubItems[2].Text;
            int iChannelNo = int.Parse(channelNo);
            int iRet = EzvizSDK.OpenSDK_PTZCtrlEx(g_strSessionId, subSerial, iChannelNo, Command, Action, 7);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("OpenSDK_PTZCtrlEx failed.", caption);
                return;
            }
        }

        private void btnUp_MouseDown(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.UP, EzvizSDK.PTZAction.START);
        }

        private void btnUp_MouseUp(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.UP, EzvizSDK.PTZAction.STOP);
        }

        private void btnRight_MouseDown(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.RIGHT, EzvizSDK.PTZAction.START);
        }

        private void btnRight_MouseUp(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.RIGHT, EzvizSDK.PTZAction.STOP);
        }

        private void btnLeft_MouseDown(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.LEFT, EzvizSDK.PTZAction.START);
        }

        private void btnLeft_MouseUp(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.LEFT, EzvizSDK.PTZAction.STOP);
        }

        private void btnDown_MouseDown(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.DOWN, EzvizSDK.PTZAction.START);
        }

        private void btnDown_MouseUp(object sender, MouseEventArgs e)
        {
            PTZControl(EzvizSDK.PTZCommand.DOWN, EzvizSDK.PTZAction.STOP);
        }

        private void btnStartTalk_Click(object sender, EventArgs e)
        {
            if (g_listViewDevice.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select a device from device list.");
                return;
            }

            string subSerial = g_listViewDevice.SelectedItems[0].SubItems[1].Text;
            string channelNo = g_listViewDevice.SelectedItems[0].SubItems[2].Text;
            int iChannelNo = int.Parse(channelNo);
            int iRet = EzvizSDK.OpenSDK_StartVoiceTalkEx(g_strSessionId, subSerial, iChannelNo);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("StartVoiceTalk failed.", caption);
                return;
            }
        }

        private void btnStopTalk_Click(object sender, EventArgs e)
        {
            int iRet = EzvizSDK.OpenSDK_StopVoiceTalk(g_strSessionId);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("StopVoiceTalk failed.", caption);
                return;
            }
        }

        private void btnSetToken_Click(object sender, EventArgs e)
        {
            string accesstoken = Microsoft.VisualBasic.Interaction.InputBox("Please input accesstoken", "Update AccessToken", "", -1, -1);
            if (accesstoken != "")
            {
                EzvizSDK.OpenSDK_SetAccessToken(accesstoken);
                g_strToken = accesstoken;
            }
        }

        private void btnAddDev_Click(object sender, EventArgs e)
        {
            if (g_strToken != "")
            {
                EzvizSDK.OpenSDK_Mid_Device_Add(g_strToken);
            }
        }

        private void btnPlaybackList_Click(object sender, EventArgs e)
        {
            if (g_listViewDevice.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select a device from device list.");
                return;
            }

            string subSerial = g_listViewDevice.SelectedItems[0].SubItems[1].Text;
            string channelNo = g_listViewDevice.SelectedItems[0].SubItems[2].Text;
            int iChannelNo = int.Parse(channelNo);

            string startTime = pickerStartTime.Value.ToString("yyyy-MM-dd HH:mm:ss");
            string stopTime = pickerStopTime.Value.ToString("yyyy-MM-dd HH:mm:ss");
            int iRet = EzvizSDK.OpenSDK_StartSearchEx(g_strSessionId, subSerial, iChannelNo, startTime, stopTime);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("StartSearchEx failed.", caption);
                return;
            }
            tabControlShow.SelectTab(1);
        }

        private void btnStartPlayback_Click(object sender, EventArgs e)
        {
            if (g_listViewDevice.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select a device from device list.");
                return;
            }

            string subSerial = g_listViewDevice.SelectedItems[0].SubItems[1].Text;
            string channelNo = g_listViewDevice.SelectedItems[0].SubItems[2].Text;
            int iChannelNo = int.Parse(channelNo);
            string iEncrypt = g_listViewDevice.SelectedItems[0].SubItems[5].Text;

            if (g_listViewPlayBack.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select a period from video record list.");
                return;
            }

            string startTime = g_listViewPlayBack.SelectedItems[0].SubItems[1].Text;
            string stopTime = g_listViewPlayBack.SelectedItems[0].SubItems[2].Text;

            bool bEnc = (int.Parse(iEncrypt) == 1) ? true : false;
            string safekey = "";
            if (bEnc)
            {
                safekey = Microsoft.VisualBasic.Interaction.InputBox("Please input device verify code", "device is encrypted.", "", -1, -1);
                if (safekey == "")
                {
                    return;
                }
            }

            int iRet = EzvizSDK.OpenSDK_StartPlayBackEx(g_strSessionId, previewPanel.Handle, subSerial, iChannelNo, safekey, startTime, stopTime);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("StartPlayBackEx failed.", caption);
                return;
            }
        }

        private void btnStopPlayback_Click(object sender, EventArgs e)
        {
            int iRet = EzvizSDK.OpenSDK_StopPlayBackEx(g_strSessionId);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("StopPlayBackEx failed.", caption);
                return;
            }
        }

        private void btnPause_Click(object sender, EventArgs e)
        {
            int iRet = EzvizSDK.OpenSDK_PlayBackPause(g_strSessionId);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("PlayBackPause failed.", caption);
                return;
            }
        }

        private void btnResume_Click(object sender, EventArgs e)
        {
            int iRet = EzvizSDK.OpenSDK_PlayBackResume(g_strSessionId);
            if (iRet != 0)
            {
                string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                MessageBox.Show("PlayBackResume failed.", caption);
                return;
            }
        }

        void ListViewDevice_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (g_listViewDevice.SelectedItems.Count == 0)
            {
                return;
            }
            string subSerial = g_listViewDevice.SelectedItems[0].SubItems[1].Text;
            string channelNo = g_listViewDevice.SelectedItems[0].SubItems[2].Text;
            string videoLevel = g_listViewDevice.SelectedItems[0].SubItems[7].Text;
            int iChannelNo = int.Parse(channelNo);
            string strBuf = string.Empty;
            IntPtr hBuf = Marshal.StringToHGlobalAnsi(strBuf);
            int iLen = 0;
            int iRet = EzvizSDK.OpenSDK_Data_GetDevDetailInfo(subSerial, iChannelNo, false, ref hBuf, ref iLen);
            if (iRet == 0)
            {
                strBuf = Marshal.PtrToStringAnsi(hBuf);
                Newtonsoft.Json.Linq.JObject json = Newtonsoft.Json.Linq.JObject.Parse(strBuf);
                if (json["videoQualityInfos"] == null)
                {
                    return;
                }
                List<Newtonsoft.Json.Linq.JToken> listRecord = json["videoQualityInfos"].Children().ToList();
                comboxSelectVideoLevel.Items.Clear();
                int i = 0;
                int tabIndex = i;
                listRecord.ForEach(x =>
                {
                    OpenSDKMainForm.VideoQualityInfo result = Newtonsoft.Json.JsonConvert.DeserializeObject<OpenSDKMainForm.VideoQualityInfo>(x.ToString());
                    comboxSelectVideoLevel.Items.Add(result);
                    if (result.videoLevel == videoLevel)
                    {
                        tabIndex = i;
                    }
                    i++;
                });
                comboxSelectVideoLevel.SelectedIndex = tabIndex;
            }
        }

        private void comboxSelectVideoLevel_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (g_listViewDevice.SelectedItems.Count == 0)
            {
                MessageBox.Show("Please select a device from device list.");
                return;
            }

            string subSerial = g_listViewDevice.SelectedItems[0].SubItems[1].Text;
            string channelNo = g_listViewDevice.SelectedItems[0].SubItems[2].Text;
            string videoLevel = g_listViewDevice.SelectedItems[0].SubItems[7].Text;
            int iChannelNo = int.Parse(channelNo);

            ComboBox comboBox = (ComboBox)sender;

            // Save the selected employee's name, because we will remove
            // the employee's name from the list.
            VideoQualityInfo videoQuality = (VideoQualityInfo)comboBox.SelectedItem;

            if(videoLevel != videoQuality.videoLevel)
            {
                int iVideoLevel = int.Parse(videoQuality.videoLevel);

                int iRet = EzvizSDK.OpenSDK_SetVideoLevel(subSerial, iChannelNo, iVideoLevel);
                if (iRet != 0)
                {
                    string caption = "ErrCode:[" + EzvizSDK.OpenSDK_GetLastErrorCode() + "]";
                    MessageBox.Show("SetVideoLevel failed.", caption);
                    return;
                }
                g_listViewDevice.SelectedItems[0].SubItems[7].Text = videoQuality.videoLevel;
            }
        }

        private void btnGetDevList_Click(object sender, EventArgs e)
        {
            GetDeviceList();
        }
    }
}
