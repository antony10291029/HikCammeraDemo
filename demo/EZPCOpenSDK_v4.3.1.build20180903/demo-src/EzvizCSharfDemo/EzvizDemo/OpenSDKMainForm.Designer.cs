namespace EzvizDemo
{
    partial class OpenSDKMainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnLoginIn = new System.Windows.Forms.Button();
            this.groupBoxMid = new System.Windows.Forms.GroupBox();
            this.btnAddDev = new System.Windows.Forms.Button();
            this.btnSetToken = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.comboxSelectVideoLevel = new System.Windows.Forms.ComboBox();
            this.btnStopPlay = new System.Windows.Forms.Button();
            this.btnStartPlay = new System.Windows.Forms.Button();
            this.tabControlShow = new System.Windows.Forms.TabControl();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.pickerStopTime = new System.Windows.Forms.DateTimePicker();
            this.pickerStartTime = new System.Windows.Forms.DateTimePicker();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btnResume = new System.Windows.Forms.Button();
            this.btnPause = new System.Windows.Forms.Button();
            this.btnPlaybackList = new System.Windows.Forms.Button();
            this.btnStopPlayback = new System.Windows.Forms.Button();
            this.btnStartPlayback = new System.Windows.Forms.Button();
            this.previewPanel = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.btnRight = new System.Windows.Forms.Button();
            this.BtnDown = new System.Windows.Forms.Button();
            this.btnLeft = new System.Windows.Forms.Button();
            this.btnUp = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btnStopTalk = new System.Windows.Forms.Button();
            this.btnStartTalk = new System.Windows.Forms.Button();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.btnGetDevList = new System.Windows.Forms.Button();
            this.groupBoxMid.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnLoginIn
            // 
            this.btnLoginIn.Location = new System.Drawing.Point(31, 31);
            this.btnLoginIn.Name = "btnLoginIn";
            this.btnLoginIn.Size = new System.Drawing.Size(75, 23);
            this.btnLoginIn.TabIndex = 1;
            this.btnLoginIn.Text = "Login";
            this.btnLoginIn.UseVisualStyleBackColor = true;
            this.btnLoginIn.Click += new System.EventHandler(this.btnLoginIn_Click);
            // 
            // groupBoxMid
            // 
            this.groupBoxMid.Controls.Add(this.btnAddDev);
            this.groupBoxMid.Controls.Add(this.btnLoginIn);
            this.groupBoxMid.Location = new System.Drawing.Point(16, 5);
            this.groupBoxMid.Name = "groupBoxMid";
            this.groupBoxMid.Size = new System.Drawing.Size(252, 85);
            this.groupBoxMid.TabIndex = 2;
            this.groupBoxMid.TabStop = false;
            this.groupBoxMid.Text = "Middle Page";
            // 
            // btnAddDev
            // 
            this.btnAddDev.Location = new System.Drawing.Point(132, 31);
            this.btnAddDev.Name = "btnAddDev";
            this.btnAddDev.Size = new System.Drawing.Size(75, 23);
            this.btnAddDev.TabIndex = 2;
            this.btnAddDev.Text = "AddDevice";
            this.btnAddDev.UseVisualStyleBackColor = true;
            this.btnAddDev.Click += new System.EventHandler(this.btnAddDev_Click);
            // 
            // btnSetToken
            // 
            this.btnSetToken.Location = new System.Drawing.Point(20, 32);
            this.btnSetToken.Name = "btnSetToken";
            this.btnSetToken.Size = new System.Drawing.Size(75, 23);
            this.btnSetToken.TabIndex = 3;
            this.btnSetToken.Text = "SetToken";
            this.btnSetToken.UseVisualStyleBackColor = true;
            this.btnSetToken.Click += new System.EventHandler(this.btnSetToken_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.comboxSelectVideoLevel);
            this.groupBox1.Controls.Add(this.btnStopPlay);
            this.groupBox1.Controls.Add(this.btnStartPlay);
            this.groupBox1.Location = new System.Drawing.Point(16, 193);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(252, 57);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "RealPlay";
            // 
            // comboxSelectVideoLevel
            // 
            this.comboxSelectVideoLevel.FormattingEnabled = true;
            this.comboxSelectVideoLevel.Location = new System.Drawing.Point(20, 23);
            this.comboxSelectVideoLevel.Name = "comboxSelectVideoLevel";
            this.comboxSelectVideoLevel.Size = new System.Drawing.Size(61, 20);
            this.comboxSelectVideoLevel.TabIndex = 2;
            this.comboxSelectVideoLevel.SelectedIndexChanged += new System.EventHandler(this.comboxSelectVideoLevel_SelectedIndexChanged);
            // 
            // btnStopPlay
            // 
            this.btnStopPlay.Location = new System.Drawing.Point(170, 21);
            this.btnStopPlay.Name = "btnStopPlay";
            this.btnStopPlay.Size = new System.Drawing.Size(75, 23);
            this.btnStopPlay.TabIndex = 1;
            this.btnStopPlay.Text = "StopPlay";
            this.btnStopPlay.UseVisualStyleBackColor = true;
            this.btnStopPlay.Click += new System.EventHandler(this.btnStopPlay_Click);
            // 
            // btnStartPlay
            // 
            this.btnStartPlay.Location = new System.Drawing.Point(89, 22);
            this.btnStartPlay.Name = "btnStartPlay";
            this.btnStartPlay.Size = new System.Drawing.Size(75, 23);
            this.btnStartPlay.TabIndex = 0;
            this.btnStartPlay.Text = "StartPlay";
            this.btnStartPlay.UseVisualStyleBackColor = true;
            this.btnStartPlay.Click += new System.EventHandler(this.btnStartPlay_Click);
            // 
            // tabControlShow
            // 
            this.tabControlShow.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.tabControlShow.Location = new System.Drawing.Point(552, 12);
            this.tabControlShow.Name = "tabControlShow";
            this.tabControlShow.SelectedIndex = 0;
            this.tabControlShow.Size = new System.Drawing.Size(337, 537);
            this.tabControlShow.TabIndex = 4;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.pickerStopTime);
            this.groupBox2.Controls.Add(this.pickerStartTime);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.btnResume);
            this.groupBox2.Controls.Add(this.btnPause);
            this.groupBox2.Controls.Add(this.btnPlaybackList);
            this.groupBox2.Controls.Add(this.btnStopPlayback);
            this.groupBox2.Controls.Add(this.btnStartPlayback);
            this.groupBox2.Location = new System.Drawing.Point(16, 262);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(246, 179);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "PlayBack";
            // 
            // pickerStopTime
            // 
            this.pickerStopTime.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.pickerStopTime.Location = new System.Drawing.Point(71, 50);
            this.pickerStopTime.Name = "pickerStopTime";
            this.pickerStopTime.Size = new System.Drawing.Size(170, 21);
            this.pickerStopTime.TabIndex = 13;
            // 
            // pickerStartTime
            // 
            this.pickerStartTime.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.pickerStartTime.Location = new System.Drawing.Point(69, 20);
            this.pickerStartTime.Name = "pickerStartTime";
            this.pickerStartTime.Size = new System.Drawing.Size(170, 21);
            this.pickerStartTime.TabIndex = 12;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 12);
            this.label2.TabIndex = 11;
            this.label2.Text = "StopTime:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(5, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 10;
            this.label1.Text = "StartTime:";
            // 
            // btnResume
            // 
            this.btnResume.Location = new System.Drawing.Point(126, 143);
            this.btnResume.Name = "btnResume";
            this.btnResume.Size = new System.Drawing.Size(75, 23);
            this.btnResume.TabIndex = 9;
            this.btnResume.Text = "Resume";
            this.btnResume.UseVisualStyleBackColor = true;
            this.btnResume.Click += new System.EventHandler(this.btnResume_Click);
            // 
            // btnPause
            // 
            this.btnPause.Location = new System.Drawing.Point(12, 143);
            this.btnPause.Name = "btnPause";
            this.btnPause.Size = new System.Drawing.Size(75, 23);
            this.btnPause.TabIndex = 8;
            this.btnPause.Text = "Pause";
            this.btnPause.UseVisualStyleBackColor = true;
            this.btnPause.Click += new System.EventHandler(this.btnPause_Click);
            // 
            // btnPlaybackList
            // 
            this.btnPlaybackList.Location = new System.Drawing.Point(12, 77);
            this.btnPlaybackList.Name = "btnPlaybackList";
            this.btnPlaybackList.Size = new System.Drawing.Size(94, 23);
            this.btnPlaybackList.TabIndex = 7;
            this.btnPlaybackList.Text = "Playback List";
            this.btnPlaybackList.UseVisualStyleBackColor = true;
            this.btnPlaybackList.Click += new System.EventHandler(this.btnPlaybackList_Click);
            // 
            // btnStopPlayback
            // 
            this.btnStopPlayback.Location = new System.Drawing.Point(126, 106);
            this.btnStopPlayback.Name = "btnStopPlayback";
            this.btnStopPlayback.Size = new System.Drawing.Size(94, 23);
            this.btnStopPlayback.TabIndex = 3;
            this.btnStopPlayback.Text = "StopPlayBack";
            this.btnStopPlayback.UseVisualStyleBackColor = true;
            this.btnStopPlayback.Click += new System.EventHandler(this.btnStopPlayback_Click);
            // 
            // btnStartPlayback
            // 
            this.btnStartPlayback.Location = new System.Drawing.Point(12, 106);
            this.btnStartPlayback.Name = "btnStartPlayback";
            this.btnStartPlayback.Size = new System.Drawing.Size(94, 23);
            this.btnStartPlayback.TabIndex = 2;
            this.btnStartPlayback.Text = "StartPlayBack";
            this.btnStartPlayback.UseVisualStyleBackColor = true;
            this.btnStartPlayback.Click += new System.EventHandler(this.btnStartPlayback_Click);
            // 
            // previewPanel
            // 
            this.previewPanel.Location = new System.Drawing.Point(11, 15);
            this.previewPanel.Name = "previewPanel";
            this.previewPanel.Size = new System.Drawing.Size(248, 248);
            this.previewPanel.TabIndex = 5;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.previewPanel);
            this.groupBox3.Location = new System.Drawing.Point(274, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(270, 270);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Preview";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.btnRight);
            this.groupBox4.Controls.Add(this.BtnDown);
            this.groupBox4.Controls.Add(this.btnLeft);
            this.groupBox4.Controls.Add(this.btnUp);
            this.groupBox4.Location = new System.Drawing.Point(274, 288);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(270, 105);
            this.groupBox4.TabIndex = 6;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "PTZCtrl";
            // 
            // btnRight
            // 
            this.btnRight.Location = new System.Drawing.Point(184, 45);
            this.btnRight.Name = "btnRight";
            this.btnRight.Size = new System.Drawing.Size(75, 23);
            this.btnRight.TabIndex = 3;
            this.btnRight.Text = "Right";
            this.btnRight.UseVisualStyleBackColor = true;
            this.btnRight.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnRight_MouseDown);
            this.btnRight.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnRight_MouseUp);
            // 
            // BtnDown
            // 
            this.BtnDown.Location = new System.Drawing.Point(97, 76);
            this.BtnDown.Name = "BtnDown";
            this.BtnDown.Size = new System.Drawing.Size(75, 23);
            this.BtnDown.TabIndex = 2;
            this.BtnDown.Text = "Down";
            this.BtnDown.UseVisualStyleBackColor = true;
            this.BtnDown.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnDown_MouseDown);
            this.BtnDown.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnDown_MouseUp);
            // 
            // btnLeft
            // 
            this.btnLeft.Location = new System.Drawing.Point(13, 45);
            this.btnLeft.Name = "btnLeft";
            this.btnLeft.Size = new System.Drawing.Size(75, 23);
            this.btnLeft.TabIndex = 1;
            this.btnLeft.Text = "Left";
            this.btnLeft.UseVisualStyleBackColor = true;
            this.btnLeft.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnLeft_MouseDown);
            this.btnLeft.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnLeft_MouseUp);
            // 
            // btnUp
            // 
            this.btnUp.Location = new System.Drawing.Point(97, 20);
            this.btnUp.Name = "btnUp";
            this.btnUp.Size = new System.Drawing.Size(75, 23);
            this.btnUp.TabIndex = 0;
            this.btnUp.Text = "UP";
            this.btnUp.UseVisualStyleBackColor = true;
            this.btnUp.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnUp_MouseDown);
            this.btnUp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnUp_MouseUp);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btnStopTalk);
            this.groupBox5.Controls.Add(this.btnStartTalk);
            this.groupBox5.Location = new System.Drawing.Point(16, 469);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(246, 57);
            this.groupBox5.TabIndex = 7;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Talk";
            // 
            // btnStopTalk
            // 
            this.btnStopTalk.Location = new System.Drawing.Point(124, 20);
            this.btnStopTalk.Name = "btnStopTalk";
            this.btnStopTalk.Size = new System.Drawing.Size(75, 23);
            this.btnStopTalk.TabIndex = 1;
            this.btnStopTalk.Text = "StopTalk";
            this.btnStopTalk.UseVisualStyleBackColor = true;
            this.btnStopTalk.Click += new System.EventHandler(this.btnStopTalk_Click);
            // 
            // btnStartTalk
            // 
            this.btnStartTalk.Location = new System.Drawing.Point(24, 21);
            this.btnStartTalk.Name = "btnStartTalk";
            this.btnStartTalk.Size = new System.Drawing.Size(75, 23);
            this.btnStartTalk.TabIndex = 0;
            this.btnStartTalk.Text = "StartTalk";
            this.btnStartTalk.UseVisualStyleBackColor = true;
            this.btnStartTalk.Click += new System.EventHandler(this.btnStartTalk_Click);
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.btnGetDevList);
            this.groupBox6.Controls.Add(this.btnSetToken);
            this.groupBox6.Location = new System.Drawing.Point(16, 96);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(252, 77);
            this.groupBox6.TabIndex = 8;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Data";
            // 
            // btnGetDevList
            // 
            this.btnGetDevList.Location = new System.Drawing.Point(124, 32);
            this.btnGetDevList.Name = "btnGetDevList";
            this.btnGetDevList.Size = new System.Drawing.Size(96, 23);
            this.btnGetDevList.TabIndex = 4;
            this.btnGetDevList.Text = "GetDeviceList";
            this.btnGetDevList.UseVisualStyleBackColor = true;
            this.btnGetDevList.Click += new System.EventHandler(this.btnGetDevList_Click);
            // 
            // OpenSDKMainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(901, 561);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.tabControlShow);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBoxMid);
            this.Name = "OpenSDKMainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Open SDK Demo";
            this.Load += new System.EventHandler(this.OpenSDKMainForm_Load);
            this.Closed += new System.EventHandler(this.OpenSDKMainForm_Closed);
            this.groupBoxMid.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnLoginIn;
        private System.Windows.Forms.GroupBox groupBoxMid;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TabControl tabControlShow;
        private System.Windows.Forms.Button btnAddDev;
        private System.Windows.Forms.Button btnStartPlay;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnStopPlay;
        private System.Windows.Forms.Panel previewPanel;
        private System.Windows.Forms.Button btnStopPlayback;
        private System.Windows.Forms.Button btnStartPlayback;
        private System.Windows.Forms.Button btnSetToken;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button btnUp;
        private System.Windows.Forms.Button btnRight;
        private System.Windows.Forms.Button BtnDown;
        private System.Windows.Forms.Button btnLeft;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button btnStopTalk;
        private System.Windows.Forms.Button btnStartTalk;
        private System.Windows.Forms.ComboBox comboxSelectVideoLevel;
        private System.Windows.Forms.Button btnResume;
        private System.Windows.Forms.Button btnPause;
        private System.Windows.Forms.Button btnPlaybackList;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker pickerStartTime;
        private System.Windows.Forms.DateTimePicker pickerStopTime;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Button btnGetDevList;
    }
}

