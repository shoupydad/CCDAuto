VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form MainMenu 
   BackColor       =   &H00000040&
   Caption         =   " SXV  Camera Control and Image Processor for USB 1 and 2"
   ClientHeight    =   10305
   ClientLeft      =   165
   ClientTop       =   -18075
   ClientWidth     =   15240
   FillColor       =   &H00000080&
   ForeColor       =   &H8000000B&
   LinkTopic       =   "Form1"
   ScaleHeight     =   687
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   1016
   StartUpPosition =   2  'CenterScreen
   WindowState     =   2  'Maximized
   Begin VB.VScrollBar VScroll2 
      Height          =   2415
      LargeChange     =   100
      Left            =   240
      Max             =   -1800
      Min             =   300
      SmallChange     =   100
      TabIndex        =   73
      Top             =   4680
      Value           =   300
      Width           =   375
   End
   Begin VB.VScrollBar VScroll1 
      Height          =   2295
      LargeChange     =   100
      Left            =   240
      Max             =   -1500
      Min             =   5
      SmallChange     =   100
      TabIndex        =   72
      Top             =   2160
      Value           =   5
      Width           =   375
   End
   Begin VB.CommandButton Command14 
      Caption         =   "Get model"
      Height          =   495
      Left            =   120
      TabIndex        =   71
      Top             =   7320
      Width           =   615
   End
   Begin VB.CommandButton Command13 
      Caption         =   "Write model"
      Height          =   495
      Left            =   120
      TabIndex        =   70
      Top             =   7920
      Width           =   615
   End
   Begin VB.TextBox messagetext 
      Alignment       =   2  'Center
      BackColor       =   &H0080FFFF&
      Height          =   375
      Left            =   12840
      TabIndex        =   50
      Top             =   360
      Visible         =   0   'False
      Width           =   5895
   End
   Begin VB.CommandButton Command2 
      Height          =   615
      Left            =   120
      Picture         =   "SXV.frx":0000
      Style           =   1  'Graphical
      TabIndex        =   49
      ToolTipText     =   "Shows / Hides guider control panel"
      Top             =   1320
      Width           =   615
   End
   Begin VB.CommandButton Command1 
      Height          =   615
      Left            =   120
      Picture         =   "SXV.frx":0B0A
      Style           =   1  'Graphical
      TabIndex        =   48
      ToolTipText     =   "Shows / Hides Camera control panel"
      Top             =   480
      Width           =   615
   End
   Begin VB.Frame GuiderFrame 
      BackColor       =   &H00000080&
      Height          =   9015
      Left            =   4680
      TabIndex        =   16
      Top             =   240
      Width           =   8055
      Begin VB.PictureBox Guideimage 
         AutoSize        =   -1  'True
         Height          =   4410
         Left            =   240
         Picture         =   "SXV.frx":1614
         ScaleHeight     =   290
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   500
         TabIndex        =   76
         Top             =   240
         Width           =   7560
         Begin VB.TextBox Guidertext 
            Height          =   285
            Left            =   0
            TabIndex        =   86
            Top             =   0
            Visible         =   0   'False
            Width           =   2535
         End
      End
      Begin VB.Frame Frame5 
         BackColor       =   &H000000C0&
         Height          =   615
         Left            =   240
         TabIndex        =   60
         Top             =   8280
         Width           =   7575
         Begin VB.CommandButton Command12 
            Caption         =   "8"
            Height          =   255
            Left            =   5640
            TabIndex        =   69
            Top             =   240
            Width           =   495
         End
         Begin VB.CommandButton Command11 
            Caption         =   "7"
            Height          =   255
            Left            =   5040
            TabIndex        =   68
            Top             =   240
            Width           =   495
         End
         Begin VB.CommandButton Command10 
            Caption         =   "6"
            Height          =   255
            Left            =   4440
            TabIndex        =   67
            Top             =   240
            Width           =   495
         End
         Begin VB.CommandButton Command9 
            Caption         =   "5"
            Height          =   255
            Left            =   3840
            TabIndex        =   66
            Top             =   240
            Width           =   495
         End
         Begin VB.CommandButton Command8 
            Caption         =   "4"
            Height          =   255
            Left            =   3240
            TabIndex        =   65
            Top             =   240
            Width           =   495
         End
         Begin VB.CommandButton Command7 
            Caption         =   "3"
            Height          =   255
            Left            =   2640
            TabIndex        =   64
            Top             =   240
            Width           =   495
         End
         Begin VB.CommandButton Command6 
            Caption         =   "2"
            Height          =   255
            Left            =   2040
            TabIndex        =   63
            Top             =   240
            Width           =   495
         End
         Begin VB.CommandButton Command5 
            BackColor       =   &H8000000B&
            Caption         =   "1"
            Height          =   255
            Left            =   1440
            MaskColor       =   &H000080FF&
            TabIndex        =   62
            Top             =   240
            UseMaskColor    =   -1  'True
            Width           =   495
         End
         Begin VB.Label Label9 
            BackColor       =   &H000000C0&
            Caption         =   "Custom Wheel"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   120
            TabIndex        =   61
            Top             =   240
            Width           =   1215
         End
      End
      Begin VB.Frame Frame4 
         BackColor       =   &H000000C0&
         ForeColor       =   &H8000000E&
         Height          =   3375
         Left            =   6840
         TabIndex        =   54
         Top             =   4800
         Width           =   975
         Begin VB.TextBox Text2 
            Height          =   285
            Left            =   120
            TabIndex        =   59
            Top             =   1800
            Width           =   735
         End
         Begin VB.CommandButton Command4 
            Caption         =   "Version"
            Height          =   255
            Left            =   120
            TabIndex        =   58
            Top             =   1560
            Width           =   735
         End
         Begin VB.TextBox Text1 
            Alignment       =   2  'Center
            Height          =   405
            Left            =   120
            MultiLine       =   -1  'True
            TabIndex        =   57
            Top             =   960
            Width           =   735
         End
         Begin VB.CommandButton Command3 
            Caption         =   "Send"
            Height          =   375
            Left            =   120
            TabIndex        =   56
            Top             =   480
            Width           =   735
         End
         Begin VB.Label Label8 
            Alignment       =   2  'Center
            BackColor       =   &H000000C0&
            Caption         =   "Serial port"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   120
            TabIndex        =   55
            Top             =   120
            Width           =   735
         End
      End
      Begin VB.Frame Frame1 
         BackColor       =   &H000000C0&
         Height          =   3375
         Left            =   240
         TabIndex        =   33
         Top             =   4800
         Width           =   4095
         Begin VB.CommandButton Command15 
            Caption         =   "Calibrate"
            Height          =   375
            Left            =   3120
            TabIndex        =   92
            Top             =   2280
            Width           =   855
         End
         Begin VB.CheckBox AOcheck 
            BackColor       =   &H000000C0&
            Caption         =   "AO mode"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   3000
            TabIndex        =   91
            Top             =   1800
            Width           =   975
         End
         Begin VB.CommandButton Dumpdark 
            Caption         =   "Clear dark"
            Height          =   495
            Left            =   840
            TabIndex        =   89
            Top             =   1920
            Width           =   615
         End
         Begin VB.CommandButton Grabdark 
            Caption         =   "Save dark"
            Height          =   495
            Left            =   120
            TabIndex        =   88
            Top             =   1920
            Width           =   615
         End
         Begin VB.CheckBox conboost 
            BackColor       =   &H000000C0&
            Caption         =   "Contrast Boost "
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   1680
            TabIndex        =   85
            Top             =   2160
            Value           =   1  'Checked
            Width           =   975
         End
         Begin VB.CheckBox Decdirect 
            BackColor       =   &H000000C0&
            Caption         =   "Dec rev"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   3000
            TabIndex        =   82
            Top             =   1320
            Width           =   975
         End
         Begin VB.CheckBox RAdirect 
            BackColor       =   &H000000C0&
            Caption         =   "RA rev"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   3000
            TabIndex        =   81
            Top             =   720
            Width           =   855
         End
         Begin MSComctlLib.Slider Decslider 
            Height          =   255
            Left            =   1560
            TabIndex        =   80
            Top             =   1440
            Width           =   1335
            _ExtentX        =   2355
            _ExtentY        =   450
            _Version        =   393216
            Min             =   1
            Max             =   15
            SelStart        =   6
            Value           =   4
         End
         Begin MSComctlLib.Slider RAslider 
            Height          =   255
            Left            =   1560
            TabIndex        =   79
            Top             =   840
            Width           =   1335
            _ExtentX        =   2355
            _ExtentY        =   450
            _Version        =   393216
            Min             =   1
            Max             =   15
            SelStart        =   4
            Value           =   4
         End
         Begin VB.CommandButton Guidestop 
            Caption         =   "Stop"
            Height          =   495
            Left            =   840
            TabIndex        =   78
            Top             =   2640
            Width           =   615
         End
         Begin VB.CommandButton Guidepic 
            Caption         =   "Image"
            Height          =   495
            Left            =   120
            TabIndex        =   77
            Top             =   2640
            Width           =   615
         End
         Begin VB.TextBox Guidertxt 
            Alignment       =   2  'Center
            BackColor       =   &H0080FFFF&
            Height          =   285
            Left            =   1560
            TabIndex        =   39
            Top             =   2760
            Width           =   1335
         End
         Begin VB.TextBox Cursorloc 
            Alignment       =   2  'Center
            BackColor       =   &H0080FFFF&
            Height          =   285
            Left            =   1560
            TabIndex        =   38
            Top             =   240
            Width           =   2055
         End
         Begin VB.CommandButton Trainguide 
            Caption         =   "Train "
            Height          =   375
            Left            =   3120
            TabIndex        =   37
            ToolTipText     =   "Use this to train the autoguider before use"
            Top             =   2760
            Width           =   855
         End
         Begin VB.CommandButton Pickguide 
            Caption         =   "Pick Guide Star"
            Height          =   375
            Left            =   120
            TabIndex        =   36
            ToolTipText     =   "Click on an isolated star"
            Top             =   1320
            Width           =   1335
         End
         Begin VB.CommandButton Stopguide 
            Caption         =   "Stop Guiding"
            Enabled         =   0   'False
            Height          =   375
            Left            =   120
            TabIndex        =   35
            ToolTipText     =   "Finish autoguiding"
            Top             =   720
            Width           =   1335
         End
         Begin VB.CommandButton Guidestart 
            Caption         =   "Start Guiding"
            Height          =   375
            Left            =   120
            TabIndex        =   34
            ToolTipText     =   "Begin guiding on guide star location"
            Top             =   240
            UseMaskColor    =   -1  'True
            Width           =   1335
         End
         Begin VB.Label Label13 
            BackColor       =   &H000000C0&
            Caption         =   "Dec pixels per sec"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   1560
            TabIndex        =   84
            Top             =   1200
            Width           =   1335
         End
         Begin VB.Label Label12 
            BackColor       =   &H000000C0&
            Caption         =   "RA pixels per sec"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   1560
            TabIndex        =   83
            Top             =   600
            Width           =   1335
         End
      End
      Begin VB.Frame trackint 
         BackColor       =   &H000000C0&
         Height          =   3375
         Left            =   4440
         TabIndex        =   26
         Top             =   4800
         Width           =   855
         Begin VB.OptionButton guidex01 
            BackColor       =   &H000000C0&
            Caption         =   "0.1s"
            ForeColor       =   &H00FFFFFF&
            Height          =   495
            Left            =   120
            TabIndex        =   93
            Top             =   600
            Width           =   615
         End
         Begin VB.OptionButton guidex10 
            BackColor       =   &H000000C0&
            Caption         =   "10 s"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   120
            TabIndex        =   30
            Top             =   2160
            Width           =   615
         End
         Begin VB.OptionButton guidex3 
            BackColor       =   &H000000C0&
            Caption         =   "3 s"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   120
            TabIndex        =   29
            Top             =   1800
            Width           =   615
         End
         Begin VB.OptionButton guidex1 
            BackColor       =   &H000000C0&
            Caption         =   "1 s"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   120
            TabIndex        =   28
            Top             =   1440
            Value           =   -1  'True
            Width           =   615
         End
         Begin VB.OptionButton guidex03 
            BackColor       =   &H000000C0&
            Caption         =   "0.3s"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   120
            TabIndex        =   27
            Top             =   1080
            Width           =   615
         End
         Begin VB.Label Label4 
            Alignment       =   2  'Center
            BackColor       =   &H000000C0&
            Caption         =   "Guiding Interval"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   120
            TabIndex        =   31
            Top             =   120
            Width           =   615
         End
      End
      Begin VB.Frame Manual 
         BackColor       =   &H000000C0&
         Height          =   3375
         Left            =   5400
         TabIndex        =   19
         Top             =   4800
         Width           =   1335
         Begin VB.CommandButton Null 
            Enabled         =   0   'False
            Height          =   375
            Left            =   480
            TabIndex        =   24
            Top             =   1320
            Width           =   375
         End
         Begin VB.CommandButton South 
            Caption         =   "S"
            Height          =   375
            Left            =   480
            TabIndex        =   23
            ToolTipText     =   "Drive South"
            Top             =   1680
            Width           =   375
         End
         Begin VB.CommandButton West 
            Caption         =   "W"
            Height          =   375
            Left            =   840
            TabIndex        =   22
            ToolTipText     =   "Drive West"
            Top             =   1320
            Width           =   375
         End
         Begin VB.CommandButton East 
            Caption         =   "E"
            Height          =   375
            Left            =   120
            TabIndex        =   21
            ToolTipText     =   "Drive East"
            Top             =   1320
            Width           =   375
         End
         Begin VB.CommandButton North 
            Caption         =   "N"
            Height          =   375
            Left            =   480
            TabIndex        =   20
            ToolTipText     =   "Drive North"
            Top             =   960
            Width           =   375
         End
         Begin VB.Label Label3 
            BackColor       =   &H000000C0&
            Caption         =   "Manual Control"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   120
            TabIndex        =   25
            Top             =   120
            Width           =   1095
         End
      End
   End
   Begin VB.Frame camframe 
      BackColor       =   &H00000080&
      Caption         =   "Camera Control Panel"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   9015
      Left            =   960
      TabIndex        =   1
      Top             =   240
      Width           =   3375
      Begin VB.CommandButton Focuscentre 
         Caption         =   "Set focus centre"
         Height          =   375
         Left            =   1200
         TabIndex        =   90
         Top             =   2760
         Width           =   1935
      End
      Begin VB.TextBox Focusloc 
         Alignment       =   2  'Center
         BackColor       =   &H0080FFFF&
         Height          =   285
         Left            =   1200
         TabIndex        =   32
         Top             =   2400
         Width           =   1935
      End
      Begin VB.TextBox Focusmax 
         Alignment       =   2  'Center
         BackColor       =   &H0080FFFF&
         Enabled         =   0   'False
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H80000007&
         Height          =   300
         Left            =   240
         TabIndex        =   14
         ToolTipText     =   "Indicates the brightest pixel value in the Focus window"
         Top             =   840
         Width           =   735
      End
      Begin VB.PictureBox Focusimage 
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000015&
         Height          =   1980
         Left            =   1200
         MousePointer    =   2  'Cross
         Picture         =   "SXV.frx":250BE
         ScaleHeight     =   128
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   128
         TabIndex        =   13
         Top             =   360
         Width           =   1980
      End
      Begin VB.Frame Frame2 
         BackColor       =   &H000000C0&
         Caption         =   "Set Exposure Time"
         ForeColor       =   &H00FFFFFF&
         Height          =   5655
         Left            =   120
         TabIndex        =   2
         Top             =   3240
         Width           =   3135
         Begin VB.CheckBox Contcheck 
            BackColor       =   &H000000C0&
            Caption         =   "Continuous"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   1680
            TabIndex        =   53
            Top             =   3240
            Width           =   1095
         End
         Begin VB.CheckBox Autocheck 
            BackColor       =   &H000000C0&
            Caption         =   "Autosave"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   600
            TabIndex        =   52
            Top             =   3240
            Width           =   975
         End
         Begin VB.Frame Frame3 
            BackColor       =   &H000000C0&
            Caption         =   "Imaging mode"
            ForeColor       =   &H00FFFFFF&
            Height          =   1935
            Left            =   1560
            TabIndex        =   43
            Top             =   1200
            Width           =   1455
            Begin VB.OptionButton Option9 
               BackColor       =   &H000000C0&
               Caption         =   "Finder"
               ForeColor       =   &H00FFFFFF&
               Height          =   375
               Left            =   120
               TabIndex        =   87
               Top             =   240
               Value           =   -1  'True
               Width           =   1095
            End
            Begin VB.OptionButton Option8 
               BackColor       =   &H000000C0&
               Caption         =   "Progressive"
               ForeColor       =   &H00FFFFFF&
               Height          =   375
               Left            =   120
               TabIndex        =   47
               Top             =   1440
               Width           =   1215
            End
            Begin VB.OptionButton Option7 
               BackColor       =   &H000000C0&
               Caption         =   "Interlaced"
               ForeColor       =   &H00FFFFFF&
               Height          =   255
               Left            =   120
               TabIndex        =   46
               Top             =   1200
               Width           =   1095
            End
            Begin VB.OptionButton Option6 
               BackColor       =   &H000000C0&
               Caption         =   "Bin 1 x 2"
               ForeColor       =   &H00FFFFFF&
               Height          =   375
               Left            =   120
               TabIndex        =   45
               Top             =   840
               Width           =   1095
            End
            Begin VB.OptionButton Option5 
               BackColor       =   &H000000C0&
               Caption         =   "Bin 2 x 2"
               ForeColor       =   &H00FFFFFF&
               Height          =   255
               Left            =   120
               TabIndex        =   44
               Top             =   600
               Width           =   1095
            End
         End
         Begin VB.OptionButton Option0 
            BackColor       =   &H000000C0&
            Caption         =   "1000ths"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   600
            TabIndex        =   41
            Top             =   2280
            Width           =   975
         End
         Begin VB.CommandButton Focusstart 
            Caption         =   "Focus Mode"
            Height          =   375
            Left            =   1680
            TabIndex        =   18
            ToolTipText     =   "Begins rapid downloads of a 100x100 window"
            Top             =   360
            Width           =   1215
         End
         Begin VB.CommandButton Focusstop 
            Caption         =   "Stop"
            Height          =   255
            Left            =   1680
            TabIndex        =   17
            ToolTipText     =   "End Focus mode"
            Top             =   840
            Width           =   1215
         End
         Begin VB.OptionButton Option1 
            BackColor       =   &H000000C0&
            Caption         =   "100ths"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   600
            TabIndex        =   11
            Top             =   1800
            Width           =   975
         End
         Begin VB.OptionButton Option2 
            BackColor       =   &H000000C0&
            Caption         =   "10ths"
            ForeColor       =   &H00FFFFFF&
            Height          =   495
            Left            =   600
            TabIndex        =   10
            Top             =   1320
            Width           =   975
         End
         Begin VB.OptionButton Option3 
            BackColor       =   &H000000C0&
            Caption         =   "Secs"
            ForeColor       =   &H00FFFFFF&
            Height          =   375
            Left            =   600
            TabIndex        =   9
            Top             =   960
            Value           =   -1  'True
            Width           =   975
         End
         Begin VB.OptionButton Option4 
            BackColor       =   &H000000C0&
            Caption         =   "Mins"
            ForeColor       =   &H00FFFFFF&
            Height          =   255
            Left            =   600
            TabIndex        =   8
            Top             =   600
            Width           =   735
         End
         Begin VB.VScrollBar Vscrollexp 
            Height          =   3975
            LargeChange     =   10
            Left            =   120
            Max             =   1
            Min             =   99
            TabIndex        =   7
            Top             =   360
            Value           =   1
            Width           =   255
         End
         Begin VB.TextBox exptext 
            Alignment       =   2  'Center
            BackColor       =   &H0080FFFF&
            Enabled         =   0   'False
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   9.75
               Charset         =   0
               Weight          =   700
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            ForeColor       =   &H80000012&
            Height          =   360
            Left            =   600
            MultiLine       =   -1  'True
            TabIndex        =   6
            Top             =   3720
            Width           =   855
         End
         Begin VB.CommandButton Startexp 
            Caption         =   "Start"
            Height          =   375
            Left            =   1800
            TabIndex        =   5
            ToolTipText     =   "Begin exposure of CCD camera"
            Top             =   4320
            Width           =   975
         End
         Begin VB.CommandButton Endexp 
            Caption         =   "Terminate"
            Height          =   375
            Left            =   1800
            TabIndex        =   4
            ToolTipText     =   "End exposure or guiding prematurely"
            Top             =   4800
            Width           =   975
         End
         Begin VB.TextBox Countdowntxt 
            Alignment       =   2  'Center
            BackColor       =   &H0080FFFF&
            Enabled         =   0   'False
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   9.75
               Charset         =   0
               Weight          =   700
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   345
            Left            =   1680
            MultiLine       =   -1  'True
            TabIndex        =   3
            Top             =   3720
            Width           =   1215
         End
         Begin VB.Label Label1 
            Alignment       =   2  'Center
            BackColor       =   &H000000C0&
            Caption         =   "Exposure Time Setting"
            ForeColor       =   &H00FFFFFF&
            Height          =   495
            Left            =   360
            TabIndex        =   12
            Top             =   4200
            Width           =   1335
         End
      End
      Begin MSComctlLib.Slider Gain1 
         Height          =   1215
         Left            =   360
         TabIndex        =   40
         ToolTipText     =   "Set guider/ focus window amplification"
         Top             =   1320
         Width           =   495
         _ExtentX        =   873
         _ExtentY        =   2143
         _Version        =   393216
         Orientation     =   1
         LargeChange     =   1
         SmallChange     =   16
         Min             =   1
         Max             =   16
         SelStart        =   16
         TickFrequency   =   2
         Value           =   16
      End
      Begin VB.Label Label7 
         Alignment       =   2  'Center
         BackColor       =   &H00000080&
         Caption         =   "Focus Contrast"
         ForeColor       =   &H00FFFFFF&
         Height          =   375
         Left            =   240
         TabIndex        =   51
         Top             =   2640
         Width           =   735
      End
      Begin VB.Label Label2 
         Alignment       =   2  'Center
         Appearance      =   0  'Flat
         BackColor       =   &H00000080&
         Caption         =   "Peak Value"
         ForeColor       =   &H00FFFFFF&
         Height          =   495
         Left            =   240
         TabIndex        =   15
         Top             =   360
         Width           =   735
      End
   End
   Begin VB.PictureBox Image1 
      AutoRedraw      =   -1  'True
      AutoSize        =   -1  'True
      BackColor       =   &H00000000&
      Height          =   30915
      Left            =   960
      MousePointer    =   99  'Custom
      ScaleHeight     =   2057
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   3257
      TabIndex        =   0
      Top             =   120
      Width           =   48915
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   1080
      Top             =   5040
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
   End
   Begin VB.Label Label11 
      Alignment       =   2  'Center
      BackColor       =   &H00000040&
      Caption         =   "Scroll Up"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   375
      Left            =   120
      TabIndex        =   75
      Top             =   2280
      Width           =   615
   End
   Begin VB.Label Label10 
      Alignment       =   2  'Center
      BackColor       =   &H00000040&
      Caption         =   "Scroll Left"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   375
      Left            =   120
      TabIndex        =   74
      Top             =   5880
      Width           =   615
   End
   Begin VB.Label Label5 
      BackColor       =   &H00000040&
      Height          =   135
      Left            =   0
      TabIndex        =   42
      Top             =   9240
      Width           =   12135
   End
   Begin VB.Menu File 
      Caption         =   "&File"
      Begin VB.Menu Load 
         Caption         =   "&Load"
      End
      Begin VB.Menu Save 
         Caption         =   "&Save"
      End
      Begin VB.Menu Fitload 
         Caption         =   "Load FITs"
      End
      Begin VB.Menu fits 
         Caption         =   "Save as &FITs"
      End
      Begin VB.Menu BMPsav 
         Caption         =   "Save as &BMP"
      End
      Begin VB.Menu def 
         Caption         =   "Program &Defaults"
         Shortcut        =   ^D
      End
      Begin VB.Menu Camswap 
         Caption         =   "Change camera type"
      End
      Begin VB.Menu Exit 
         Caption         =   "Exit"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu edit 
      Caption         =   "&Edit"
      Begin VB.Menu undo 
         Caption         =   "&Undo"
      End
   End
   Begin VB.Menu view 
      Caption         =   "&View"
      Begin VB.Menu z4 
         Caption         =   "Zoom out 4x"
      End
      Begin VB.Menu auto 
         Caption         =   "Autostretch screen view"
         Shortcut        =   ^S
      End
   End
   Begin VB.Menu Colsyn 
      Caption         =   "Colour Synthesis"
      Begin VB.Menu Preset 
         Caption         =   "Preset synthesis parameters"
      End
      Begin VB.Menu Synth 
         Caption         =   "&Synthesise"
      End
      Begin VB.Menu Colsmooth 
         Caption         =   "&Colour smoothing"
      End
      Begin VB.Menu Bal 
         Caption         =   "&Balance Colour"
      End
      Begin VB.Menu pixfix 
         Caption         =   "Rejig pixels"
      End
   End
   Begin VB.Menu Contrast 
      Caption         =   "&Contrast"
      Begin VB.Menu Lin 
         Caption         =   "&LinearStretch"
      End
      Begin VB.Menu Power 
         Caption         =   "&Power Law Stretch"
      End
      Begin VB.Menu Sine 
         Caption         =   "&Sine Law Stretch"
      End
      Begin VB.Menu Invert 
         Caption         =   "&Invert to Negative"
      End
   End
   Begin VB.Menu Filter 
      Caption         =   "&Filters"
      Begin VB.Menu Unsharp 
         Caption         =   "&Unsharp Mask"
      End
      Begin VB.Menu mediansmooth 
         Caption         =   "&Median Smoother"
      End
      Begin VB.Menu HighL 
         Caption         =   "&Sharpen"
      End
      Begin VB.Menu HighH 
         Caption         =   "&High Pass"
      End
      Begin VB.Menu Lowpassmean 
         Caption         =   "&Low Pass Weighted Mean"
      End
      Begin VB.Menu Basrel 
         Caption         =   "&Bas-relief"
      End
      Begin VB.Menu Gradfind 
         Caption         =   "&Brightness gradient remove"
      End
      Begin VB.Menu Colgrad 
         Caption         =   "Colour gradient remove"
      End
      Begin VB.Menu Vignetteremove 
         Caption         =   "&Vignette"
      End
   End
   Begin VB.Menu calibrate 
      Caption         =   "&Calibrate"
      Begin VB.Menu flat 
         Caption         =   "&Flat-field"
      End
      Begin VB.Menu darksub 
         Caption         =   "&Dark frame subtract"
      End
      Begin VB.Menu AFgen 
         Caption         =   "Artificial flat"
      End
   End
   Begin VB.Menu Info 
      Caption         =   "Help"
      Begin VB.Menu Version 
         Caption         =   "About"
      End
   End
End
Attribute VB_Name = "MainMenu"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
                   
Dim r As Integer, c As Integer, Value As Byte

'API Declarations

'Fast image transfer from array to screen
Private Type SAFEARRAYBOUND
    cElements As Long
    lLbound As Long
End Type

Private Type SAFEARRAY1D
    cDims As Integer
    fFeatures As Integer
    cbElements As Long
    cLocks As Long
    pvData As Long
    Bounds(0 To 0) As SAFEARRAYBOUND
End Type

Private Type SAFEARRAY2D
    cDims As Integer
    fFeatures As Integer
    cbElements As Long
    cLocks As Long
    pvData As Long
    Bounds(0 To 1) As SAFEARRAYBOUND
End Type

Private Type BITMAP
    bmType As Long
    bmWidth As Long
    bmHeight As Long
    bmWidthBytes As Long
    bmPlanes As Integer
    bmBitsPixel As Integer
    bmBits As Long
End Type

Dim sa As SAFEARRAY2D, BMP As BITMAP

Private Declare Function GetObjectAPI Lib "gdi32" Alias "GetObjectA" (ByVal hObject As Long, ByVal nCount As Long, lpObject As Any) As Long
Private Declare Function VarPtrArray Lib "msvbvm50.dll" Alias "VarPtr" (Ptr() As Any) As Long
Private Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" (pDst As Any, pSrc As Any, ByVal ByteLen As Long)
Private Declare Function GetTickCount Lib "kernel32" () As Long

Private Declare Sub stretcher Lib "MXproc.dll" Alias "STRETCHER" (ByVal stretchtype%, ByVal Powr!, ByVal Blacklev&, ByVal Whitelev&, ByVal Imptr1&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Private Declare Sub Synthesis Lib "MXproc.dll" Alias "SYNTHESIS" (ByVal Imptr1&, ByVal Colourptr&)
Private Declare Sub bmpgen Lib "MXbmp.dll" Alias "BMPGEN" (ByVal Imptr1&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
Private Declare Sub Finderbmpgen Lib "MXbmp.dll" Alias "FINDERBMPGEN" (ByVal Imptr1&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
Private Declare Sub zoombmpgen Lib "MXbmp.dll" Alias "ZOOMBMPGEN" (ByVal Imptr1&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
Private Declare Sub zoombinbmpgen Lib "MXbmp.dll" Alias "ZOOMBINBMPGEN" (ByVal Imptr1&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)

Private Declare Sub hibmpgen Lib "MXbmp.dll" Alias "HIBMPGEN" (ByVal Imptr1&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
Private Declare Sub Interlacedbmpgen Lib "MXbmp.dll" Alias "INTERLACEDBMPGEN" (ByVal Imptr1&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
Private Declare Sub autoview Lib "MXbmp.dll" Alias "AUTOVIEW" ()

Private Declare Sub colsynth Lib "MXcolr.dll" Alias "COLSYNTH" (ByVal Colourptr&, ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal cs&, ByVal colourbal%, Buffer$)
Private Declare Sub colsynth2 Lib "MXcolr.dll" Alias "COLSYNTH2" (ByVal Colourptr&, ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal cs&, ByVal colourbal%, Buffer$)
Private Declare Sub intcolsynth Lib "MXcolr.dll" Alias "INTCOLSYNTH" (ByVal Colourptr&, ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal cs&, ByVal colourbal%, Buffer$)
Private Declare Sub intcolsynth2 Lib "MXcolr.dll" Alias "INTCOLSYNTH2" (ByVal Colourptr&, ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal cs&, ByVal colourbal%, Buffer$)

Private Declare Sub colourstretcher Lib "MXcolr.dll" Alias "COLOURSTRETCHER" (ByVal Minimum%, ByVal Maximum%, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Private Declare Sub coloursmooth Lib "MXcolr.dll" Alias "COLOURSMOOTH" (ByVal ptr1&, ByVal ptr2&, ByVal hsize&, ByVal vsize&)
Private Declare Sub colourstretcher2 Lib "MXcolr.dll" Alias "COLOURSTRETCHER2" (ByVal Minimum%, ByVal Maximum%, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
'Private Declare Sub coloursmooth2 Lib "MXcolr.dll" Alias "COLOURSMOOTH2" (ByVal ptr1&, ByVal ptr2&, ByVal hsize&, ByVal vsize&)

Private Declare Sub colbmpgen Lib "Colbmp.dll" Alias "COLBMPGEN" (ByVal Colourptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal SF!, ByVal MRd!, ByVal MGn!, ByVal MBl!, Buffer$)

Private Declare Sub combineimage Lib "MX9drv.dll" Alias "COMBINEIMAGE" (ByVal Imptr1&, ByVal Imptr2&, ByVal Imptr3&, ByVal INL%, ByVal Field%)
Private Declare Sub deinterlace Lib "MX9drv.dll" Alias "DEINTERLACE" (ByVal Imptr1&)
Private Declare Sub unsharpmask Lib "MXproc.dll" Alias "UNSHARPMASK" (ByVal Radius%, ByVal Pwr%, ByVal Imptr1&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Private Declare Sub median Lib "MXproc.dll" Alias "MEDIAN" (ByVal Radius%, ByVal Pwr%, ByVal Imptr1&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Private Declare Sub Highlow Lib "MXproc.dll" Alias "HIGHLOW" (ByVal Imptr1&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Private Declare Sub Highhigh Lib "MXproc.dll" Alias "HIGHHIGH" (ByVal Imptr1&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Private Declare Sub Lowmean Lib "MXproc.dll" Alias "LOWMEAN" (ByVal Imptr1&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Private Declare Sub Basrelief Lib "MXproc.dll" Alias "BASRELIEF" (ByVal Imptr1&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Private Declare Sub Gradientfind Lib "MXproc.dll" Alias "GRADIENTFIND" (ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal Bin%)
Private Declare Sub ColGradientfind Lib "MXproc.dll" Alias "COLGRADIENTFIND" (ByVal Imptr&, ByVal hsize&, ByVal vsize&)
Private Declare Sub Vignette Lib "MXproc.dll" Alias "VIGNETTE" (ByVal Imptr1&, ByVal Imptr5&, ByVal hsize&, ByVal vsize&, ByVal Bf%)

Private Declare Sub sendfile Lib "MXproc.dll" Alias "SENDFILE" (ByVal Imptr&, ByVal Imptr5&, ByVal hsize&, ByVal vsize&, ByVal Colourfile%)
Private Declare Sub returnfile Lib "MXproc.dll" Alias "RETURNFILE" (ByVal Imptr&, ByVal Imptr5&, ByVal hsize&, ByVal vsize&, ByVal Colourfile%)
Private Declare Sub copyimge Lib "MXproc.dll" Alias "COPYIMGE" (ByVal Imptr1&, ByVal Imptr4&, ByVal hsize&, ByVal vsize&)
Private Declare Sub Arrayswap Lib "MXbmp.dll" Alias "ARRAYSWAP" (ByVal Imptr1&, ByVal Imptr2&)
Private Declare Sub Arrayfix Lib "MXbmp.dll" Alias "ARRAYFIX" (ByVal Imptr1&, ByVal Imptr2&)
Private Declare Sub AFgenerate Lib "MXproc.dll" Alias "AFGENERATE" (ByVal Imptr1&, ByVal Imptr2&, ByVal backsignal&, ByVal hsize&, ByVal vsize&)

Private Declare Sub dkload Lib "MXproc.dll" Alias "DKLOAD" (filestring$, ByVal Imptr3&, ByVal hsize&, ByVal vsize&)
Private Declare Sub hidkload Lib "MXproc.dll" Alias "HIDKLOAD" (filestring$, ByVal Imptr3&, ByVal hsize&, ByVal vsize&)
Private Declare Sub darksubtract Lib "MXproc.dll" Alias "DARKSUBTRACT" (ByVal Imptr1&, ByVal Imptr3&, ByVal hsize&, ByVal vsize&)
Private Declare Sub imgsave Lib "MXproc.dll" Alias "IMGSAVE" (filestring$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
Private Declare Sub himgsave Lib "MXproc.dll" Alias "HIMGSAVE" (filestring$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
Private Declare Sub colimgsave Lib "MXproc.dll" Alias "COLIMGSAVE" (filestring$, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Private Declare Sub colimgload Lib "MXproc.dll" Alias "COLIMGLOAD" (filestring$, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Private Declare Sub imgload Lib "MXproc.dll" Alias "IMGLOAD" (filestring$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)

Private Sub AFgen_Click()
Image1.SetFocus
AF% = 1: backsignal& = 0: backcount& = 0
MsgBox "Click on several points in the region of brightest background and then press enter"
keyvalue% = 0
Do
DoEvents
If keyvalue% = 13 Then Exit Do
Loop
backsignal& = backsignal& / backcount&
MsgBox Str$(backsignal&)

Call AFgenerate(ByVal Imptr1&, ByVal Imptr2&, ByVal backsignal&, ByVal hsize&, ByVal vsize&)
Call Loadimage
AF% = 0
End Sub

Private Sub Command15_Click()
S2K% = 15
Call SetSTAR
Pause (0.1)
S2K% = 0
Call SetSTAR
End Sub

Private Sub Image1_KeyPress(keyascii As Integer)
keyvalue% = keyascii
End Sub

Private Sub Camswap_Click()
Dialog.Show
End Sub

Private Sub Command13_Click()
Call WriteModel
End Sub

Private Sub Command14_Click()
Call Getmodel
End Sub

Private Sub Command3_Click()
'Call Getserial

Call Writeserial

Call Readserial
Text1.Text = Str$(ReportBuffer(0)) + ", " + Str$(ReportBuffer(1)) + ", " + Str$(ReportBuffer(2)) + ", " + Str$(ReportBuffer(3))
End Sub

Private Sub Command4_Click()
Call Getversion
Text2.Text = Str$(ReportBuffer(3)) + Str$(ReportBuffer(2)) + Str$(ReportBuffer(1)) + Str$(ReportBuffer(0))
End Sub

Private Sub Command5_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 1: Ch4% = 167: Le% = 4
Command5.Enabled = False: Command6.Enabled = True: Command7.Enabled = True: Command8.Enabled = True
Command9.Enabled = True: Command10.Enabled = True: Command11.Enabled = True: Command12.Enabled = True
Call Writeserial
End Sub

Private Sub Command6_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 2: Ch4% = 168: Le% = 4
Call Writeserial
Command6.Enabled = False: Command5.Enabled = True: Command7.Enabled = True: Command8.Enabled = True
Command9.Enabled = True: Command10.Enabled = True: Command11.Enabled = True: Command12.Enabled = True
End Sub

Private Sub Command7_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 3: Ch4% = 169: Le% = 4
Call Writeserial
Command7.Enabled = False: Command6.Enabled = True: Command5.Enabled = True: Command8.Enabled = True
Command9.Enabled = True: Command10.Enabled = True: Command11.Enabled = True: Command12.Enabled = True
End Sub

Private Sub Command8_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 4: Ch4% = 170: Le% = 4
Call Writeserial
Command8.Enabled = False: Command6.Enabled = True: Command7.Enabled = True: Command5.Enabled = True
Command9.Enabled = True: Command10.Enabled = True: Command11.Enabled = True: Command12.Enabled = True
End Sub

Private Sub Command9_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 5: Ch4% = 171: Le% = 4
Call Writeserial
Command9.Enabled = False: Command6.Enabled = True: Command7.Enabled = True: Command8.Enabled = True
Command5.Enabled = True: Command10.Enabled = True: Command11.Enabled = True: Command12.Enabled = True
End Sub

Private Sub Command10_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 6: Ch4% = 172: Le% = 4
Call Writeserial
Command10.Enabled = False: Command6.Enabled = True: Command7.Enabled = True: Command8.Enabled = True
Command9.Enabled = True: Command5.Enabled = True: Command11.Enabled = True: Command12.Enabled = True
End Sub

Private Sub Command11_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 7: Ch4% = 173: Le% = 4
Call Writeserial
Command11.Enabled = False: Command6.Enabled = True: Command7.Enabled = True: Command8.Enabled = True
Command9.Enabled = True: Command10.Enabled = True: Command5.Enabled = True: Command12.Enabled = True
End Sub

Private Sub Command12_Click()
Ch1% = 165: Ch2% = 1: Ch3% = 8: Ch4% = 174: Le% = 4
Call Writeserial
Command12.Enabled = False: Command6.Enabled = True: Command7.Enabled = True: Command8.Enabled = True
Command9.Enabled = True: Command10.Enabled = True: Command11.Enabled = True: Command5.Enabled = True
End Sub

Public Sub Image1_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
x = Int(x): y = Int(y)
FXloc% = x
FYloc% = y
setfocuscentre% = 1
mclick% = 1
imvalue& = Image1.Point(x, y)
redval% = imvalue& And 255
greenval% = (imvalue& And 65535) / 256
blueval% = (imvalue& And 16776960) / 65536
If AF% = 1 Then backsignal& = backsignal& + 256 * (imvalue& And 255): backcount& = backcount& + 1: GoTo nocol
MsgBox "Red = " + Str$(redval%) + ", Green = " + Str$(greenval%) + ", Blue = " + Str$(blueval%)
nocol:
End Sub

Private Sub pixfix_Click()
Call Arrayfix(ByVal Imptr1&, ByVal Imptr2&)
End Sub


Private Sub Version_Click()
MsgBox "Version 1.3, 9/5/2004. Copyright: Terry Platt"
End Sub

Private Sub Command1_Click()
If camframe.Visible = True Then camframe.Visible = False Else camframe.Visible = True
End Sub

Private Sub Command2_Click()
If GuiderFrame.Visible = True Then GuiderFrame.Visible = False Else GuiderFrame.Visible = True
End Sub

Private Sub Close_Click()
DoEvents
Unload MainMenu
End
End Sub

Private Sub Exit_Click()
DoEvents
Unload MainMenu
End
End Sub

'INITIALISE PROGRAM

Public Sub Form_Initialize()
'set up CCD parameters
'Do While ready% = 0: Loop
If ready% = 0 Then hsize& = 2088: vsize& = 1550

Vs& = vsize&
If camtype% = 1 Then Vs& = vsize& / 2
If camtype% = 2 Then Vs& = vsize& / 2
If camtype% = 3 Then Vs& = vsize& / 2
If camtype% = 6 Then Vs& = vsize& / 2
If camtype% = 8 Then Vs& = vsize& / 2
If camtype% = 9 Then Vs& = vsize& / 2


If camtype% = 7 Then
MSheight& = Fix((Vs& / 2) / 256)
LSheight& = Vs& / 2 - (MSheight& * 256)
MSwidth& = Fix((hsize& * 2) / 256)
LSwidth& = hsize& * 2 - (MSwidth& * 256)
Else
MSheight& = Fix(Vs& / 256)
LSheight& = Vs& - (MSheight& * 256)
MSwidth& = Fix(hsize& / 256)
LSwidth& = hsize& - (MSwidth& * 256)
End If

binsize& = Fix(hsize& * vsize&)
bin1size& = Fix(hsize& * vsize& * 2)
bin2size& = Fix(hsize& * vsize& / 2)
bin4size& = Fix(hsize& * vsize& / 8)

binread& = Fix(hsize& * vsize&)
bin1read& = Fix(hsize& * vsize& * 2)
bin2read& = Fix(hsize& * vsize& / 2)
bin4read& = Fix(hsize& * vsize& / 8)

copysize& = hsize& * 2
coloursize& = hsize& * vsize& * 5
redstart& = hsize& * vsize& * 2
greenstart& = hsize& * vsize& * 3
bluestart& = hsize& * vsize& * 4

'MainMenu.Left = (Screen.Width - MainMenu.Width) \ 2
'MainMenu.Top = (Screen.Height - MainMenu.Height) \ 2


ReDim Imagearray1%(hsize& - 1, vsize& + 10)
ReDim Imagearray2%(hsize& - 1, vsize& + 10)
ReDim Imagearray3%(hsize& - 1, vsize& + 10)
ReDim Imagearray4%(hsize& - 1, vsize& + 10)
ReDim Imagearray5%(hsize& - 1, vsize& * 6)
ReDim Colourarray%(hsize& * vsize& * 6)
ReDim ReportBuffer(hsize& * vsize& * 2.1)

Imptr1& = VarPtr(Imagearray1%(0, 0))
Imptr2& = VarPtr(Imagearray2%(0, 0))
Imptr3& = VarPtr(Imagearray3%(0, 0))
Imptr4& = VarPtr(Imagearray4%(0, 0))
Imptr5& = VarPtr(Imagearray5%(0, 0))
Imptr6& = VarPtr(Imagearray6(0, 0))
Bmpptr& = VarPtr(Bmparray(0))
Colourptr& = VarPtr(Colourarray%(0))
Reportptr& = VarPtr(ReportBuffer(0))
peakloc& = VarPtr(peak%)
Call Dirpathcheck
Open Dirpath$ + "MX.ini" For Input As #1
l& = LOF(1)
If LOF(1) < 1 Then
Close #1
Open Dirpath$ + "MX.ini" For Output As #1
Print #1, "";: Print #1, 0
End If
Close #1
DoEvents
Open Dirpath$ + "MX.ini" For Input As #1
Input #1, img%
Close #1

'Set up focus window table for 0.5 power law

Powr! = 0.3
Ratio! = 1 / (255 ^ (Powr! - 1))
Dim i As Byte
 For i = 0 To 254: a& = Int((i ^ Powr!) * Ratio!)
 If a& > 255 Then a& = 255
 If a& < 0 Then a& = 0
 Imtable(i) = a&
 Imtable(255) = 255
Next i

'Call autoview
Time% = 50 'timetest(ByVal BD1%)    'Find delay value for computer
BD1% = Time%
BD2% = Time% * 2
BD10% = Time% * 10
Buffer$ = Dirpath$ + "MXBuffer.bmp"
incremen$ = " Secs"
factor! = 1
Terminate% = 0
If Option5.Value = False Then HR% = 1 Else HR% = 0
INL% = 0: progressive% = 0
Field% = 1
exptext.Text = Format$(Vscrollexp.Value * factor!, "0.00") + " s"
comms$ = "COM" + LTrim$(Str$(comport1%))
commflag% = 0
selectcentre% = 0
guidemeans% = 0
gain% = 255
pw! = 0.05 * Wrate%: pe! = 0.05 * Erate%: pn! = 0.1 * Nrate%: ps! = 0.1 * Srate%: theta! = 0
Dxptr& = VarPtr(deltax!)
Dyptr& = VarPtr(deltay!)
guideptr& = VarPtr(Guideflag%)

Call VScroll1_Change
Call VScroll2_Change

GuiderFrame.Visible = False
camframe.Visible = False
If ready% = 0 Then Dialog.Visible = True: Dialog.Show: MainMenu.Hide

If ready% = 1 Then If OpenUSBinterfaces("Echo2") = True Then DoEvents
'MsgBox Str$(hsize&) + ", " + Str$(vsize&)
DoEvents
End Sub

Sub Reload()
Open Dirpath$ + "MX.ini" For Input As #1
Input #1, fast%, port1%, comport1%, readtime!, Interrupt%, Nrate%, Srate%, Erate%, Wrate%, NSdirection%, EWdirection%
Close #1
'MsgBox "Erate = " + Str$(Erate%) + "  Wrate = " + Str$(Wrate%) + "  Nrate = " + Str$(Nrate%) + "  Srate = " + Str$(Srate%)
End Sub

Private Sub Dirpathcheck()
Dirpath$ = App.Path
If Right(Dirpath$, 1) <> "\" Then Dirpath$ = Dirpath$ + "\"
End Sub

'SET PROGRAM DEFAULTS

Public Sub Def_Click()
Open Dirpath$ + "MX.ini" For Append As #2
If LOF(2) < 1 Then Print #2, 1
Close #2
Open Dirpath$ + "MX.ini" For Input As #2
Input #2, img%
Close #2
comms$ = "COM" + LTrim$(Str$(comport1%))
Defaults.Show
End Sub

Private Sub freeguide_Click()
If Value = 1 Then freerun% = 1 Else freerun% = 0
End Sub

Private Sub Gain1_Change()
gain% = Gain1.Value
End Sub

'LOAD AND SAVE ROUTINES

Private Sub Load_Click()
Wrongfile:
On Error GoTo noload
CommonDialog1.Filter = "Images (*.*)|*.*"
CommonDialog1.Action = 1
filestring$ = CommonDialog1.FileName
q& = FileLen(filestring$)
DoEvents
If q& = (hsize& * vsize&) Then Colourfile% = 0: Option6.Value = True: GoTo Loading
If q& = (hsize& * vsize& * 2) Then Colourfile% = 0: Option7.Value = True: GoTo Loading
If q& = coloursize& Then Colourfile% = 1: GoTo Loading


MsgBox "Cannot load - Not an SX file of the correct size"
CommonDialog1.FileName = ""
GoTo Wrongfile

Loading:
MousePointer = 11
Imagepresent% = 1
If Colourfile% = 1 Then
Call colimgload(filestring$, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Else
    If Option6 = True Then
    Call imgload(filestring$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
    Else
    Call imgload(filestring$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
    End If
End If
Call Loadimage
noload:
End Sub

Private Sub fitload_Click()
Wrongfile:
On Error GoTo noload
CommonDialog1.Filter = "Images (*.FIT)|*.FIT"
CommonDialog1.Action = 1
filestring$ = CommonDialog1.FileName
q& = FileLen(filestring$)
If q& = 221760 Or q& = 878400 Or q& = 878080 Or q& = 224640 Then
GoTo FitLoading
Else
MsgBox "Cannot load - Not a compatible FITS file"
CommonDialog1.FileName = ""
GoTo Wrongfile
End If
FitLoading:
Imagepresent% = 1
If q& = 878400 Or q& = 878080 Then
HR% = 1
Else
HR% = 0
End If

Call Loadimage
noload:
End Sub

Public Sub Loadimage()

Imptr& = Imptr1&
If viewmode% = 1 Then St% = 1 Else St% = 0

    If Colourfile% = 0 Then
        If z4.Checked = False Then
        If Option9 = True Then Call Finderbmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option8 = True Then Call Interlacedbmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option7 = True Then Call Interlacedbmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option6 = True Then Call hibmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option5 = True Then Call bmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        Else
        If Option8 = True Then Call zoombmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option7 = True Then Call zoombmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option6 = True Then Call zoombinbmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option5 = True Then Call bmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        If Option9 = True Then Call Finderbmpgen(ByVal Imptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal St%, Buffer$)
        End If
    End If

    If Colourfile% = 1 Then
    SF! = Balanceset.Scrollsat.Value / 5: MRd! = 1: MGn! = 1: MBl! = 1
    Call colbmpgen(ByVal Colourptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal SF!, ByVal MRd!, ByVal MGn!, ByVal MBl!, Buffer$)
    End If
DoEvents
Image1.Picture = LoadPicture(Buffer$)

Call copyimge(ByVal Imptr1&, ByVal Imptr4&, ByVal hsize&, ByVal vsize&)

Imagepresent% = 0
loadend:
If Terminate% = 1 Then Contcheck.Value = 0
DoEvents
MousePointer = 0
End Sub

Private Sub Vignetteremove_Click()
MousePointer = 11
Option8 = True
Bf% = 14
Call Vignette(ByVal Colourptr&, ByVal Imptr5&, ByVal hsize&, ByVal vsize&, Bf%)
Call Loadimage
MousePointer = 0
End Sub

Private Sub z4_Click()

If Option8.Value = True Or Option7.Value = True Or Option6.Value = True Then
If z4.Checked = False Then z4.Checked = True Else z4.Checked = False
If z4.Checked = True Then Zoom% = 1 Else Zoom% = 0
VScroll1.Value = 8
VScroll2.Value = 56

Call Loadimage
End If

End Sub

Private Sub auto_Click()

If auto.Checked = False Then auto.Checked = True Else auto.Checked = False
If auto.Checked = True Then viewmode% = 1 Else viewmode% = 0
If viewmode% = 1 Then St% = 1 Else St% = 0

Call Loadimage

End Sub

Private Sub Save_Click()
On Error GoTo nosave
savestart:
qsave% = 1: lf& = 0: filestring$ = ""
CommonDialog1.Filter = "Images (*.*)|*.*"
CommonDialog1.Action = 2

filestring$ = CommonDialog1.FileName

Open filestring$ For Binary As #1
lf& = LOF(1)
Close #1

If lf& > 0 Then Call overwrite_show
If qsave% = 0 Then GoTo savestart
If Colourfile% = 0 Then
    If Option6 = True Then
    Call himgsave(filestring$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
    Else
    Call imgsave(filestring$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
    End If
Else
Call colimgsave(filestring$, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
End If
nosave:
lf& = 0
Exit Sub
End Sub

Private Sub overwrite_show()
Dim Message As String
Dim ButtonsAndIcons As Integer
Dim Response As Integer

Message = "File '" + filestring$ + "' exists - Do you want to overwrite it?"
ButtonsAndIcons = vbYesNo + vbQuestion
Response = MsgBox(Message, ButtonsAndIcons)
If Response = vbYes Then qsave% = 1
If Response = vbNo Then qsave% = 0
End Sub

Private Sub fits_Click()
'Fitsedit.Show
On Error GoTo nosave
savefit:
qsave% = 1
CommonDialog1.Filter = "Images (*.fit)|*.fit"
CommonDialog1.Action = 2

filestring$ = CommonDialog1.FileName

Open filestring$ For Binary As #1
lf& = LOF(1)
Close #1

If lf& > 0 Then Call overwrite_show
If qsave% = 0 Then GoTo savefit


nosave:
End Sub

Private Sub tiff_Click()
On Error GoTo nosave
savetiff:
qsave% = 1
CommonDialog1.Filter = "Images (*.tif)|*.tif"
CommonDialog1.Action = 2

filestring$ = CommonDialog1.FileName

Open filestring$ For Binary As #1
lf& = LOF(1)
Close #1

If lf& > 0 Then Call overwrite_show
If qsave% = 0 Then GoTo savetiff


nosave:
End Sub

Private Sub bmpsav_Click()

CommonDialog1.Filter = "Images (*.*)|*.bmp"
CommonDialog1.Action = 2
On Error GoTo nosave
filestring$ = CommonDialog1.FileName

MainMenu.MousePointer = 11
SavePicture Image1.Image, filestring$

MainMenu.MousePointer = 0
nosave:

End Sub

Private Sub VScroll1_Change()
Image1.Top = VScroll1.Value
Image1.Refresh
End Sub

Private Sub Vscroll1_Scroll()
VScroll1_Change
End Sub

Private Sub VScroll2_Change()
Image1.Left = VScroll2.Value
Image1.Refresh
End Sub

Private Sub Vscroll2_Scroll()
VScroll2_Change
End Sub

'EXPOSURE CONTROL ROUTINES

Private Sub Vscrollexp_Change()
If Option4.Value = True Then
exptext.Text = Format$(Vscrollexp.Value * factor!, "0") + " m"
Else
exptext.Text = Format$(Vscrollexp.Value * factor!, "0.00") + " s"
End If
If Option0.Value = True Then exptext.Text = Format$(Vscrollexp.Value * factor!, "0.000") + " s"
End Sub

Private Sub Vscrollexp_Scroll()
Call Vscrollexp_Change
End Sub

Private Sub Startexp_Click()
Focusflag% = 0
Terminate% = 0
Colourfile% = 0
Mainexpose% = 1
Field% = 1

Countdowntxt.Text = ""
DoEvents

If Option5.Value = True Then INL% = 0: Prog% = 0: HR% = 0: Bin% = 0       'Bin 2 x 2
If Option6.Value = True Then INL% = 1: Prog% = 0: HR% = 1: Bin% = 1       'Bin 1 x 2
If Option7.Value = True Then INL% = 2: Prog% = 0: HR% = 2: Bin% = 2       'Bin 1 x 1 Interlaced
If Option8.Value = True Then INL% = 3: Prog% = 1: HR% = 2: Bin% = 2       'Bin 1 x 1 progressive
If Option9.Value = True Then INL% = 4: Prog% = 0: HR% = 0: Bin% = 4       'Bin 4 x 4 finder mode

Repeatexposure:

Vs& = Vscrollexp.Value

If Option0.Value = True Then
Expinterval& = Vs&
End If

If Option1.Value = True Then
Expinterval& = Vs& * 10
End If

If Option2.Value = True Then
Expinterval& = Vs& * 100
End If

If Option3.Value = True Then
Expinterval& = Vs& * 1000
countsize& = 1000
Countsecs% = Vs&
Increment$ = " s"
End If

If Option4.Value = True Then
Expinterval& = Vs& * 60000
countsize& = 1000
Countsecs% = Vs& * 60
Increment$ = " s"
End If


Clearcount% = 0

Call Vscrollexp_Change

Ex$ = Right("00000000" + Hex$(Expinterval&), 8)

Ex1$ = "&H" + (Left(Ex$, 2))
Ex2$ = "&H" + (Right((Left(Ex$, 4)), 2))
Ex3$ = "&H" + (Right((Left(Ex$, 6)), 2))
Ex4$ = "&H" + (Right((Left(Ex$, 8)), 2))

Call Clearvert

ExposureEnd& = GetTickCount + Expinterval&
Endcount& = GetTickCount + Expinterval&

Call Wiper
If Guideflag% = 1 Then expstart% = 1: Option8.Value = True: Exit Sub           'Is guider on?


'If Guidemodeset.Value = True Then INL% = 2: Prog% = 0
Startexposure:

'Bin 4x4
If INL% = 4 Then
Imptr& = Imptr1&
Reportptr1& = Reportptr&
Clearcount% = 0
If camtype% = 4 Then Bin% = 44
If camtype% = 5 Then Bin% = 44
If camtype% = 7 Then Bin% = 40

Call Wiper
Call ReceiveBlock

If Terminate% = 1 Then Call Endexp_Click: Exit Sub

Call CopyBuffer(Reportptr1&, Imptr&, bin4read&)

If Terminate% = 1 Then Call Endexp_Click: Exit Sub
DoEvents

End If


'Bin 2x2
If INL% = 0 Then
Imptr& = Imptr1&
Reportptr1& = Reportptr&
Clearcount% = 0
If camtype% = 4 Then Bin% = 22
If camtype% = 5 Then Bin% = 22
If camtype% = 7 Then Bin% = 20

Call Wiper
Call ReceiveBlock

If Terminate% = 1 Then Call Endexp_Click: Exit Sub

Call CopyBuffer(Reportptr1&, Imptr&, bin2read&)
End If
If Terminate% = 1 Then
Call Endexp_Click: Exit Sub
End If
DoEvents

'Bin 1x2
If INL% = 1 Then
Imptr& = Imptr1&
Reportptr1& = Reportptr&
Clearcount% = 0
Countdowntxt.Text = "Exposing"
DoEvents

Call Wiper
Call ReceiveBlock

If Terminate% = 1 Then Call Endexp_Click: Exit Sub

Call CopyBuffer(Reportptr1&, Imptr&, bin1read&)

If Terminate% = 1 Then Call Endexp_Click: Exit Sub
DoEvents

End If

'Interlaced
If INL% = 2 Then
Imptr& = Imptr2&
Reportptr1& = Reportptr&
Clearcount% = 0
Call Wiper
Call ReceiveOddBlock

Call CopyBuffer(Reportptr1&, Imptr&, binread&)
Countdowntxt.Text = "Field2"
DoEvents
Imptr& = Imptr3&
Reportptr1& = Reportptr&
Clearcount% = 0
Call Wiper
Call ReceiveEvenBlock

Call CopyBuffer(Reportptr1&, Imptr&, binread&)
DoEvents
Linesize& = hsize& * 2
Imptr& = Imptr1& + 2
ImptrO& = Imptr2&
ImptrE& = Imptr3& + Linesize&
For y% = 1 To vsize& / 2
Call CopyBuffer(ImptrO&, Imptr&, Linesize&)
ImptrO& = ImptrO& + Linesize&
Imptr& = Imptr& + Linesize&
Call CopyBuffer(ImptrE&, Imptr&, Linesize&)
ImptrE& = ImptrE& + Linesize&
Imptr& = Imptr& + Linesize&
Next y%
Beep
If Terminate% = 1 Then Call Endexp_Click: Exit Sub
DoEvents

End If

'Progressive
If INL% = 3 Then
Linesize& = hsize& * 2
If camtype% = 4 Then GoTo HXmode
If camtype% = 5 Then GoTo HXmode
If camtype% = 7 Then GoTo HXmode

Imptr& = Imptr2&
Reportptr1& = Reportptr&
Clearcount% = 0
'For x& = 0 To (hsize& * vsize& * 2.1): ReportBuffer(x&) = 0: Next x&
Call Wiper

Endcount& = GetTickCount + Expinterval&
Rold& = (Endcount& - GetTickCount) / 1000

MainMenu.Countdowntxt.Text = "Exposing"
DoEvents

Do While GetTickCount < Endcount&
Remainder& = (Endcount& - GetTickCount) / 1000
MainMenu.Countdowntxt.Text = Format$(Remainder&, "   0.0")

If Remainder& > 4 Then Call Clearreg Else Call Clearvert
If Terminate% = 1 Then Exit Sub
DoEvents
Loop
Call ReceiveOddBlock2

Call CopyBuffer(Reportptr1&, Imptr&, binread&)
DoEvents
Imptr& = Imptr3&
Reportptr1& = Reportptr&
Call Clearvert
Call ReceiveEvenBlock2

Call CopyBuffer(Reportptr1&, Imptr&, binread&)
DoEvents
Imptr& = Imptr1& + 2
ImptrO& = Imptr2&
ImptrE& = Imptr3& + Linesize&
For y% = 1 To vsize& / 2
Call CopyBuffer(ImptrO&, Imptr&, Linesize&)
ImptrO& = ImptrO& + Linesize&
Imptr& = Imptr& + Linesize&
Call CopyBuffer(ImptrE&, Imptr&, Linesize&)
ImptrE& = ImptrE& + Linesize&
Imptr& = Imptr& + Linesize&
Next y%
Beep
GoTo MXmode

HXmode:
Bin% = 11

Countdowntxt.Text = "Exposing"
DoEvents
Imptr& = Imptr1&
Reportptr1& = Reportptr&

    If Expinterval& < 1000 Then                     'short exposure
    Call Wiper
    Call ReceiveBlock
    Else
    Call Wiper                                      'start exposure
    Endcount& = GetTickCount + Expinterval&
    Do While GetTickCount < Endcount&
    Remainder& = (Endcount& - GetTickCount) / 1000
    If Remainder& < 6 And Remainder& > 1 Then Call Clearvert
    Countdowntxt.Text = Format$(Remainder&, "   0.0")
    If Terminate% = 1 Then Exit Sub
    DoEvents
    Loop
    Countdowntxt.Text = "Reading"
    DoEvents
    Call ReceiveBlock2
    End If

If camtype% = 7 Then                                'assemble H25 image
Call CopyBuffer(Reportptr&, Imptr2&, bin1read&)
Call Arrayswap(ByVal Imptr1&, ByVal Imptr2&)
Else
Call CopyBuffer(Reportptr&, Imptr1&, bin1read&)     'assemble HX image
End If

DoEvents
Countdowntxt.Text = ""
Imagepresent% = 1
Colourfile% = 0

If Terminate% = 1 Then Call Endexp_Click: Exit Sub
DoEvents

MXmode:
End If

DoEvents
Countdowntxt.Text = "Finished"
Imagepresent% = 1

Call Loadimage
Call Wiper

If Autocheck.Value = 1 Then                        'Autosave mode
    Dirpath$ = App.Path
    If Right(Dirpath$, 1) <> "\" Then Dirpath$ = Dirpath$ + "\"

    Open Dirpath$ + "MX.ini" For Input As #1
    Input #1, img%
    Autoimage$ = Dirpath$ + "Image" + Str$(img%)
    img% = img% + 1
    Close #1

    Call imgsave(Autoimage$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
    Open Dirpath$ + "MX.ini" For Output As #1
    Print #1, img%
    Close #1
End If

DoEvents
If Terminate% = 1 Then MainMenu.Text1 = "Static Image": Exit Sub

DoEvents
If Contcheck.Value = 1 Then If Terminate% = 0 Then DoEvents: GoTo Repeatexposure
Mainexpose% = 0: Clearcount% = 0

End Sub


Private Sub Endexp_Click()
Focusflag% = 0
Guideflag% = 0
Terminate% = 1
DoEvents
Countdowntxt.Text = ""
Call Vscrollexp_Change
End Sub

Private Sub Option0_Click()
incremen$ = " Secs"
factor! = 0.001
exptext.Text = Format$(Vscrollexp.Value * factor!, "0.000") + " s"
End Sub
Private Sub Option1_Click()
incremen$ = " Secs"
factor! = 0.01
exptext.Text = Format$(Vscrollexp.Value * factor!, "0.00") + " s"
End Sub

Private Sub Option2_Click()
incremen$ = " Secs"
factor! = 0.1
exptext.Text = Format$(Vscrollexp.Value * factor!, "0.00") + " s"
End Sub

Private Sub Option3_Click()
incremen$ = " Secs"
factor! = 1
exptext.Text = Format$(Vscrollexp.Value * factor!, "0.00") + " s"
End Sub

Private Sub Option4_Click()
incremen$ = " Mins"
factor! = 1
exptext.Text = Format$(Vscrollexp.Value * factor!, "0") + " m"
End Sub


'IMAGE PROCESSING ROUTINES *****************************************************************************


Private Sub Preset_Click()
Colour.Show
End Sub


Private Sub Synth_Click()
If Option9 = True Then MsgBox "Cannot colour convert a binned 4x4 image!": Exit Sub
If Option5 = True Then MsgBox "Cannot colour convert a binned 2x2 image!": Exit Sub
If Option6 = True Then MsgBox "Cannot colour convert a binned 1x2 image!": Exit Sub

MousePointer = 11
DoEvents
Call backup_Click

cs& = Colour.Luminance.Value
'Call Getbackground
'cs& = maxval& / 4000
'If cs& < 2 Then cs& = 2
'cs& = 5
'MsgBox "cs&=" + Str$(cs&)

If Colourfile% = 1 Then MsgBox "Image is already colour synthesised!": Exit Sub
SF! = Balanceset.Scrollsat.Value / 5: MRd! = 1: MGn! = 1: MBl! = 1
If pixoffset% = 0 Then startpoint% = 2 Else startpoint% = 0
If lineoffset% = 1 Then startpoint% = startpoint% + 6000

Call Dirpathcheck
Buffer$ = Dirpath$ + "MXBuffer.bmp"
If colourbal% = 1 Then offset% = 2
If colourbal% = 2 Then offset% = 0
If colourbal% = 3 Then offset% = 2
If colourbal% = 4 Then offset% = 2784
If colourbal% = 5 Then offset% = 2
If colourbal% = 6 Then offset% = 2
If colourbal% = 7 Then offset% = 6000

Imptr& = Imptr1& + offset% + startpoint%
If RGBtype% = 1 Then
Call intcolsynth(ByVal Colourptr&, ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal cs&, ByVal colourbal%, Buffer$)
Else
Call intcolsynth2(ByVal Colourptr&, ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal cs&, ByVal colourbal%, Buffer$)
End If
Colourfile% = 1: Bin% = 0
Call Loadimage

MousePointer = 0
End Sub

Private Sub Bal_Click()
Call backup_Click

Redmin% = 0: Redmax% = 255
Greenmin% = 0: Greenmax% = 255
Bluemin% = 0: Bluemax% = 255
Balanceset.Scrollred1.Value = 0
Balanceset.Scrollgreen1.Value = 0
Balanceset.Scrollblue1.Value = 0
Balanceset.Scrollred2.Value = 255
Balanceset.Scrollgreen2.Value = 255
Balanceset.Scrollblue2.Value = 255

Balanceset.Show
Call Balanceset.Drawhistograms
End Sub

Private Sub Colsmooth_Click()
If Colourfile% = 0 Then MsgBox "Not a colour converted image!": Exit Sub
Image1.MousePointer = 11
ptr1& = Colourptr& + redstart&
ptr2& = Bmpptr&
Call coloursmooth(ByVal ptr1&, ByVal ptr2&, ByVal hsize&, ByVal vsize&)
ptr1& = Colourptr& + greenstart&
Call coloursmooth(ByVal ptr1&, ByVal ptr2&, ByVal hsize&, ByVal vsize&)
ptr1& = Colourptr& + bluestart&
Call coloursmooth(ByVal ptr1&, ByVal ptr2&, ByVal hsize&, ByVal vsize&)

Bmpptr& = VarPtr(Bmparray(0))
Buffer$ = Dirpath$ + "MXBuffer.bmp"

Call colbmpgen(ByVal Colourptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal SF!, ByVal MRd!, ByVal MGn!, ByVal MBl!, Buffer$)
Colourfile% = 1: Bin% = 0
Call Loadimage
Image1.MousePointer = 2

End Sub

Private Sub Getbackground()
Dim Table2&(65535)
For y% = 1 To vsize& / 2
For x% = 1 To hsize& - 1
imdata% = Imagearray1%(x%, y%)
If imdata% < 0 Then dat& = imdata% + 65536 Else dat& = imdata% 'scan image for pixel values
Table2&(dat&) = Table2&(dat&) + 1
Next x%
Next y%
maxval& = 0
For z& = 1 To 40000
dat& = Table2&(z&)
If dat& > maxval& Then maxval& = dat&: q& = z&                 'find most common value
Next z&
maxval& = q&
'MsgBox "Pixel count at 40,000=" + Str$(Table2&(40000))
If Table2&(40000) > 5 Then maxval& = 30000

End Sub


Private Sub darksub_Click()

If Colourfile% = 1 Then MsgBox "Cannot dark subtract a colour file - raw files only!": GoTo noload
Wrongfile:
On Error GoTo noload
CommonDialog1.Filter = "Images (*.*)|*.*"
CommonDialog1.Action = 1
filestring$ = CommonDialog1.FileName
q& = FileLen(filestring$)
If q& = binsize& Or q& = bin1size& Then
    If HR% = 1 Then
        If q& = bin1size& Then GoTo Loading
    Else
        If q& = binsize& Then GoTo Loading
    End If
Else
MsgBox "Cannot load - file size mismatch"
CommonDialog1.FileName = ""
GoTo Wrongfile
End If
Loading:
MousePointer = 11
Call backup_Click
DoEvents

Call imgload(filestring$, ByVal Imptr3&, ByVal hsize&, ByVal vsize&)

For y% = 0 To (vsize& - 1)
For x% = 0 To hsize& - 1
l% = Imagearray1(x%, y%)
If l% < 0 Then Lum& = l% + 65536 Else Lum& = l%
d% = Imagearray3%(x%, y%)
If d% < 0 Then Dk& = d% + 65536 Else Dk& = d%
Lum& = Lum& - Dk&
If Lum& < 0 Then Lum& = 0
If Lum& > 32767 Then Lum& = Lum& - 65536
l% = Lum&
Imagearray1%(x%, y%) = l%
Next x%
Next y%

MousePointer = 0
Call Loadimage
noload:
End Sub

Private Sub Invert_Click()
MainMenu.MousePointer = 11
Call backup_Click
DoEvents
If Option5.Value = 0 Then HR% = 1 Else HR% = 0
stretchtype% = 3
MainMenu.AutoRedraw = False
Blacklev& = 0
Whitelev& = 65535
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call stretcher(ByVal stretchtype%, ByVal Powr!, ByVal Blacklev&, ByVal Whitelev&, ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Imagepresent% = 1
MousePointer = 0
Call Loadimage
End Sub

Private Sub Lin_Click()
MousePointer = 11
DoEvents
Call backup_Click
If Option5.Value = False Then HR% = 1 Else HR% = 0
Histogram.Show
Call Histogram.Histopicload
MousePointer = 0
End Sub

Private Sub Power_Click()
MousePointer = 11
DoEvents
Call backup_Click
If Option5.Value = 0 Then HR% = 1 Else HR% = 0
Powerset.Show
MousePointer = 0
End Sub

Public Sub Powerstretch()
MousePointer = 11
DoEvents
Call backup_Click
If Option5.Value = 0 Then HR% = 1 Else HR% = 0
MainMenu.AutoRedraw = False
stretchtype% = 2
Blacklev& = 0
Whitelev& = 65535
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call stretcher(ByVal stretchtype%, ByVal Powr!, ByVal Blacklev&, ByVal Whitelev&, ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Imagepresent% = 1
MousePointer = 0
Call Loadimage
End Sub

Private Sub Sine_Click()
MousePointer = 11
DoEvents
Call backup_Click
If Option5.Value = 0 Then HR% = 1 Else HR% = 0
stretchtype% = 4
MainMenu.AutoRedraw = False
Blacklev& = 0
Whitelev& = 65535
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call stretcher(ByVal stretchtype%, ByVal Powr!, ByVal Blacklev&, ByVal Whitelev&, ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Imagepresent% = 1
MousePointer = 0
Call Loadimage
End Sub

Private Sub Unsharp_Click()
unsharpset.Show
End Sub

Public Sub Unsharpdo()
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call unsharpmask(ByVal Radius%, ByVal Pwr%, ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
MousePointer = 0
Call Loadimage
End Sub

Private Sub Mediansmooth_Click()
Radius% = 1
Pwr% = 1
DoEvents
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call median(ByVal Radius%, ByVal Pwr%, ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
MousePointer = 0
Call Loadimage
End Sub

Private Sub HighL_Click()
DoEvents
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call Highlow(ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
MousePointer = 0
Call Loadimage
End Sub

Private Sub HighH_Click()
DoEvents
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call Highhigh(ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
MousePointer = 0
Call Loadimage
End Sub

Private Sub Lowpassmean_Click()
DoEvents
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call Lowmean(ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
MousePointer = 0
Call Loadimage
End Sub

Private Sub Basrel_Click()
DoEvents
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call Basrelief(ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
MousePointer = 0
Call Loadimage
End Sub

Private Sub gradfind_Click()
Bin% = 0
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call Gradientfind(ByVal Imptr&, ByVal hsize&, ByVal vsize&, ByVal Bin%)
Call Loadimage
MousePointer = 0
End Sub

Private Sub Colgrad_Click()
Bin% = 0
MousePointer = 11
Call backup_Click
If Colourfile% = 0 Then MsgBox "Not applicable to mono images": GoTo nocolour
Imptr& = Colourptr& + bin1size&
Call ColGradientfind(ByVal Imptr&, ByVal hsize&, ByVal vsize&)
Imptr& = Colourptr& + greenstart&
Call ColGradientfind(ByVal Imptr&, ByVal hsize&, ByVal vsize&)
Imptr& = Colourptr& + bluestart&
Call ColGradientfind(ByVal Imptr&, ByVal hsize&, ByVal vsize&)

Call Loadimage
nocolour:
MousePointer = 0
End Sub


Private Sub backup_Click()
If Colourfile% = 0 Then
Imptr& = Imptr1&
mono% = 1
Else
Imptr& = Colourptr&
mono% = 0
End If

Call sendfile(ByVal Imptr&, ByVal Imptr5&, ByVal hsize&, ByVal vsize&, ByVal Colourfile%)
End Sub

Private Sub undo_Click()
MousePointer = 11
If mono% = 1 Then
Imptr& = Imptr1&
Colourfile% = 0
Else
Imptr& = Colourptr&
End If

Call returnfile(ByVal Imptr&, ByVal Imptr5&, ByVal hsize&, ByVal vsize&, ByVal Colourfile%)

Call Loadimage
MousePointer = 0
End Sub

'MANUAL TELESCOPE CONTROL ROUTINES

Private Sub East_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
Drive% = 1
S2K% = 8
Call SetSTAR
Do While DoEvents()
If Drive% = 0 Then Exit Sub
Loop
End Sub

Private Sub East_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
S2K% = 0
Call SetSTAR
Drive% = 0
DoEvents
End Sub

Private Sub West_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
Drive% = 1
S2K% = 1
Call SetSTAR
Do While DoEvents()
If Drive% = 0 Then Exit Sub
Loop
End Sub

Private Sub West_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
S2K% = 0
Call SetSTAR
Drive% = 0
DoEvents
End Sub

Private Sub North_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
Drive% = 1
S2K% = 4
Call SetSTAR
'Pause (0.013)
'S2K% = 0
'Call SetSTAR
Do While DoEvents()
If Drive% = 0 Then Exit Sub
Loop
End Sub

Private Sub North_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
S2K% = 0
Call SetSTAR
Drive% = 0
DoEvents
End Sub

Private Sub South_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
Drive% = 1
S2K% = 2
Call SetSTAR
Do While DoEvents()
If Drive% = 0 Then Exit Sub
Loop
End Sub

Private Sub South_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
S2K% = 0
Call SetSTAR
Drive% = 0
DoEvents
End Sub


'AUTOGUIDER ROUTINES

Private Sub Vscrollguide_Change()
Guideexp.Text = Format(VScrollguide.Value / 10, "0.0") + " s"
End Sub

Private Sub Vscrollguide_Scroll()
Call Vscrollguide_Change
End Sub

Private Sub RAslider_Change()
RApixel% = RAslider.Value
End Sub

Private Sub RAslider_Scroll()
Call RAslider_Change
End Sub

Private Sub DECslider_Change()
DECpixel% = Decslider.Value
End Sub

Private Sub DECslider_Scroll()
Call DECslider_Change
End Sub

Private Sub Guidepic_Click()

If AOcheck.Value = 1 Then
Guidertext.Visible = True
Guidertext.Text = "Zeroing AO unit"
DoEvents
S2K% = 15: Call SetSTAR             'zero AO unit
Pause (0.1)
S2K% = 0: Call SetSTAR
RAsum& = 0: Decsum& = 0
Pause (5)
Guidertext.Text = "Ready"
DoEvents
End If


Guideflag% = 1: Pickguide.Enabled = False: Focusstart.Enabled = False ': Grabdark.Enabled = False: Dumpdark.Enabled = False

If Guideflag% = 1 Then If Guiderun% = 0 Then Startexp.Enabled = False Else Startexp.Enabled = True
North.Enabled = False: South.Enabled = False: East.Enabled = False: West.Enabled = False
RApixels! = 1 / RAslider.Value
DECpixels! = 1 / Decslider.Value
DoEvents

Reportptr& = VarPtr(ReportBuffer(0))
Imptr& = VarPtr(Imagearray7(0, 0))

Call Guideclear
Call ReceiveGuide                                   'clear first frame

Guiderepeat:
Guidertxt.Text = "Exposing"

If guidex01 = True Then GuideExpinterval& = 100
If guidex03 = True Then GuideExpinterval& = 300
If guidex1 = True Then GuideExpinterval& = 1000
If guidex3 = True Then GuideExpinterval& = 3000
If guidex10 = True Then GuideExpinterval& = 10000

DoEvents
Call Guideclear                                  'clear CCD

    ImageExpEnd& = GetTickCount + GuideExpinterval&

    Do While Elapsed& < ImageExpEnd&                'Exposure loop
    Elapsed& = GetTickCount
    Loop

Readstart1:

Guidertxt.Text = "Reading"
DoEvents

Call ReceiveGuide                                   'Read CCD
    'If Remainder& > 4 Then Call Clearreg
DoEvents
    
    z& = 0: i& = 0
    For y% = 0 To 289
    For x% = 0 To 499
    pixel% = ReportBuffer(z&)
    pixel% = pixel% - Imagearray8(x%, y%)           'subtract dark frame
    If pixel% < 0 Then pixel% = 0
    Imagearray7(x%, y%) = pixel%
    i& = i& + pixel%
    z& = z& + 1
    Next x%
    Next y%
    i& = (i& / z&)
    background& = i&
DoEvents

'Call Guidesmooth                                    'smooth data for guide window

Call Showguide                                      'show main image

                                                    'display magnified guide image in focus box
If Guiderun% = 1 Then
If Xloc% = 0 Then MsgBox "Guide star not selected!": Call Pickguide_Click
x% = Xloc% - 7: y% = Yloc% - 7: c% = 0: d% = 0
For b% = 0 To 127
For a% = 0 To 127
e% = (Imagearray7(x%, y%) - i&) * 8
If e% > 255 Then e% = 255
If e% < 0 Then e% = 0
Imagearray6(a%, b%) = e%
c% = c% + 1: If c% = 8 Then c% = 0: x% = x% + 1
Next a%
x% = Xloc% - 7
d% = d% + 1: If d% = 8 Then d% = 0: y% = y% + 1
Next b%
Call moveimage
End If

    If Guideflag% = 0 Then
    Guidertxt.Text = "Finished"
    Pickguide.Enabled = True
    'Grabdark.Enabled = True
    'Dumpdark.Enabled = True
    North.Enabled = True: South.Enabled = True: East.Enabled = True: West.Enabled = True
    DoEvents
    Exit Sub
    End If

If Guiderun% = 1 Then Call Startguide
If Guideflag% = 1 Then GoTo Guiderepeat
End Sub

Private Sub Startguide()
If pickstar% = 0 Then MsgBox "You must pick a guide star first!": Guiderun% = 0: Guideflag% = 0: Exit Sub
Call Getwindow
DoEvents
End Sub

Private Sub Guidestop_Click()
Guideflag% = 0: Guiderun% = 0
Startexp.Enabled = True
Focusstart.Enabled = True
Pickguide.Enabled = True
'Grabdark.Enabled = True
'Dumpdark.Enabled = True
DoEvents
End Sub

Private Sub Showguide()
Call moveguideimage
DoEvents
End Sub

Sub moveguideimage()
    
' get bitmap info
GetObjectAPI Guideimage.Picture, Len(BMP), BMP

' have the local matrix point to bitmap pixels
With sa
    .cbElements = 1
    .cDims = 2
    .Bounds(0).lLbound = 0
    .Bounds(0).cElements = BMP.bmHeight
    .Bounds(1).lLbound = 0
    .Bounds(1).cElements = BMP.bmWidthBytes
    .pvData = BMP.bmBits
End With

'Normal contrast view
peak% = 0
CopyMemory ByVal VarPtrArray(pict), VarPtr(sa), 4
Dim Intens As Byte
Vlimit% = UBound(pict, 1) - 1
For c = 1 To Vlimit%
    For r = 1 To UBound(pict, 2)
        r2% = 290 - r
        pict(c, r) = Imagearray7(c + 1, r2%)
    Next r
Next c

'Boosted contrast view
If conboost.Value = 1 Then
For c = 1 To Vlimit%
    For r = 1 To UBound(pict, 2)
        r2% = 290 - r
        pix% = (pict(c, r) - background&) * 16
        If pix% > 255 Then pix% = 255
        If pix% > -1 Then pict(c, r) = pix% Else pict(c, r) = 0
    Next r
Next c
End If

' clear the temporary array descriptor without destroying the local temporary array
CopyMemory ByVal VarPtrArray(pict), 0&, 4

' inform VB that something has changed
Guideimage.Refresh

End Sub

Private Sub Grabdark_Click()
CopyMemory ByVal VarPtr(Imagearray8(0, 0)), ByVal VarPtr(Imagearray7(0, 0)), ByVal 145000
End Sub

Private Sub Dumpdark_Click()
Erase Imagearray8
End Sub

Private Sub Pickguide_Click()

pickstart:
camfram% = 0

Guidertext.Visible = True
Guidertext.Text = "Please click on a suitable star"

gtime% = 0
Do While DoEvents()
If gtime% = 1 Then GoTo gotstar
Loop
gotstar:

px% = Xloc% - 5: qx% = Xloc% + 5
py% = Yloc% - 5: qy% = Yloc% + 5

If px% < 0 Or py% < 0 Or qx% > 500 Or qy% > 290 Then
MsgBox "Star is outside useful area, please repeat"
GoTo pickstart
End If

imvalue% = Point(Xloc%, Yloc%)
Guidertext.Text = Str$(imvalue%)
If imvalue% > 254 Then MsgBox "Warning, the star may be too bright for accurate guiding!"

sumx& = 0: sumy& = 0: sumtotal& = 0

For xx% = px% To qx%                    'get total ADU
    For yy% = py% To qy%
    imval% = Imagearray7(xx%, yy%) - background&
    If imval% < 0 Then imval% = 0
    sumtotal& = sumtotal& + imval%
    Next yy%
Next xx%

If sumtotal& < 0 Then MsgBox "Star is too faint!": GoTo pickstart
If sumtotal& = 0 Then sumtotal& = 1

dx% = 1
For xx% = px% To qx%                    'get moment in x direction
    For yy% = py% To qy%
    imval% = Imagearray7(xx%, yy%) - background&
    If imval% < 0 Then imval% = 0
    sumy& = sumy& + (dx% * imval%)
    Next yy%
    dx% = dx% + 1
Next xx%

cx! = sumy& / sumtotal&

dy% = 1
For yy% = py% To qy%                    'get moment in y direction
    For xx% = px% To qx%
    imval% = Imagearray7(xx%, yy%) - background&
    If imval% < 0 Then imval% = 0
    sumx& = sumx& + (dy% * imval%)
    Next xx%
    dy% = dy% + 1
Next yy%

cy! = sumx& / sumtotal&

restart:
Guidertext.Text = ""
Guidertext.Visible = False

Cursorloc.Text = Format$(cx!, "000.0") + " , " + Format$(cy!, "000.0")

Call moveguideimage

Guideimage.Line (Xloc% - 10, Yloc%)-(Xloc% + 10, Yloc%), RGB(0, 255, 0)        'draw cross at guide star position
Guideimage.Line (Xloc%, Yloc% - 10)-(Xloc%, Yloc% + 10), RGB(0, 255, 0)

RAcentre! = cx!
DECcentre! = cy!

pickstar% = 1

End Sub

Private Sub Guidestart_Click()
Guiderun% = 1
Mainexpose% = 0
Call Guidepic_Click
End Sub

Private Sub Getwindow()

sumx& = 0: sumy& = 0: sumtotal& = 0

For xx% = px% To qx%                    'get total ADU
    For yy% = py% To qy%
    imval% = Imagearray7(xx%, yy%)
    imval% = imval% - background&
    If imval% < 0 Then imval% = 0
    sumtotal& = sumtotal& + imval%
    Next yy%
Next xx%

If sumtotal& < 0 Then MsgBox "Star is too faint!": Call Pickguide_Click
If sumtotal& = 0 Then sumtotal& = 1

dx% = 1
For xx% = px% To qx%                    'get moment in x direction
    For yy% = py% To qy%
    imval% = Imagearray7(xx%, yy%)
    imval% = imval% - background&
    If imval% < 0 Then imval% = 0
    sumy& = sumy& + (dx% * imval%)
    Next yy%
    dx% = dx% + 1
Next xx%

cx! = sumy& / sumtotal&

dy% = 1
For yy% = py% To qy%                    'get moment in y direction
    For xx% = px% To qx%
    imval% = Imagearray7(xx%, yy%)
    imval% = imval% - background&
    If imval% < 0 Then imval% = 0
    sumx& = sumx& + (dy% * imval%)
    Next xx%
    dy% = dy% + 1
Next yy%

cy! = sumx& / sumtotal&

Cursorloc.Text = Format$(px% + cx!, "000.0") + " , " + Format$(py% + cy!, "000.0")

RAerror! = RAcentre! - cx!
DECerror! = DECcentre! - cy!

Cursorloc.Text = Format$(RAerror!, "0.0") + " , " + Format$(DECerror!, "0.0")

Guideimage.Line (Xloc% - 10, Yloc%)-(Xloc% + 10, Yloc%), RGB(0, 255, 0)        'draw cross at guide star position
Guideimage.Line (Xloc%, Yloc% - 10)-(Xloc%, Yloc% + 10), RGB(0, 255, 0)

Call Drivecorrect

'******************************* Is main exposure running?

If Mainexpose% = 1 Then

    If Terminate% = 1 Then ExposureEnd& = GetTickCount - 1: Countdowntxt.Text = "Reading": DoEvents
    
    If GetTickCount < Endcount& Then     'update exposure countdown
    Remainder& = (Endcount& - GetTickCount) / 1000
    Countdowntxt.Text = Format$(Remainder&, "   0.0")
        
        If camtype% = 1 Then
        If Remainder& > 4 Then Call Clearreg Else Call Clearvert
        Else
        If Remainder < 5 Then Call Clearvert
        End If
    
    DoEvents
    Else                        'download main camera at end of exposure
    
    If camtype% = 4 Then GoTo HXdownload
    If camtype% = 5 Then GoTo HXdownload
    If camtype% = 7 Then GoTo HXdownload
    
    'Progressive
    Imptr& = Imptr2&
    Reportptr1& = Reportptr&

    Call ReceiveOddBlock2

    Call CopyBuffer(Reportptr1&, Imptr&, binsize&)
    DoEvents
    Imptr& = Imptr3&
    Reportptr1& = Reportptr&
    Call ReceiveEvenBlock2

    Call CopyBuffer(Reportptr1&, Imptr&, binsize&)
    DoEvents
    copysize& = hsize& * 2
    Imptr& = Imptr1& + 2
    ImptrO& = Imptr2&
    ImptrE& = Imptr3& + copysize&
    For y% = 1 To vsize& / 2
    Call CopyBuffer(ImptrO&, Imptr&, copysize&)
    ImptrO& = ImptrO& + copysize&
    Imptr& = Imptr& + copysize&
    Call CopyBuffer(ImptrE&, Imptr&, copysize&)
    ImptrE& = ImptrE& + copysize&
    Imptr& = Imptr& + copysize&
    Next y%
    Beep
    DoEvents
    GoTo MXdownload
    
HXdownload:
    Bin% = 11
    Reportptr1& = Reportptr&

    Call ReceiveBlock2

    If camtype% = 7 Then                'rearrange data for H25 chip
    Call CopyBuffer(Reportptr&, Imptr2&, bin1read&)
    Call Arrayswap(ByVal Imptr1&, ByVal Imptr2&)
    Else
    Call CopyBuffer(Reportptr&, Imptr1&, bin1read&)
    End If
    

    Beep
    DoEvents

MXdownload:
    Imagepresent% = 1
    Colourfile% = 0
    
    Call Loadimage

        If Autocheck.Value = 1 Then                        'Autosave mode
        Dirpath$ = App.Path
        If Right(Dirpath$, 1) <> "\" Then Dirpath$ = Dirpath$ + "\"

        Open Dirpath$ + "MX.ini" For Input As #1
        Input #1, img%
        Autoimage$ = Dirpath$ + "Image" + Str$(img%)
        img% = img% + 1
        Close #1

        Call imgsave(Autoimage$, ByVal Imptr1&, ByVal hsize&, ByVal vsize&)
        Open Dirpath$ + "MX.ini" For Output As #1
        Print #1, img%
        Close #1
        End If
        
        DoEvents
        If Terminate% = 1 Then Contcheck.Value = 0
        
        If Contcheck.Value = 1 Then
        Call Clearvert
        Clearcount% = 0
        ExposureEnd& = GetTickCount + Expinterval&
        Endcount& = ExposureEnd&
        Countdowntxt.Text = Format$((ExposureEnd& - GetTickCount) / 1000, "   0.0")
        DoEvents
        Call Wiper
        Else
        Mainexpose% = 0
        End If
            
    End If
End If

End Sub
'send corrections to telescope drive
Private Sub Drivecorrect()
If AOcheck.Value = 1 Then GoTo AOcorrect
ratefactor% = 1
RApixels! = 1 / (ratefactor% * RAslider.Value)
DECpixels! = 1 / (ratefactor% * Decslider.Value)
If RAdirect.Value = 0 Then RAdirection% = 1 Else RAdirection% = -1
If Decdirect.Value = 0 Then DECdirection% = 1 Else DECdirection% = -1
RAtime& = 1000 * (RApixels! * RAerror! * RAdirection%)
DECtime& = 1000 * (DECpixels! * DECerror! * DECdirection%)

If RAtime& < 0 Then S2K% = 8 Else S2K% = 1
Endtime& = GetTickCount + Abs(RAtime&)
Call SetSTAR                                'send RA correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR

Endtime& = GetTickCount + 200               '200mS pause
Do While GetTickCount < Endtime&: Loop

If DECtime& < 0 Then S2K% = 4 Else S2K% = 2
Endtime& = GetTickCount + Abs(DECtime&)
Call SetSTAR                                'send DEC correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR
GoTo endcorrect

AOcorrect:
ratefactor% = 200
Guidertext.Visible = True
RApixels! = 1 / RAslider.Value
DECpixels! = 1 / Decslider.Value
DoEvents
If RAdirect.Value = 0 Then RAdirection% = 1 Else RAdirection% = -1
If Decdirect.Value = 0 Then DECdirection% = 1 Else DECdirection% = -1
RAtime& = (1000 / ratefactor%) * (RApixels! * RAerror! * RAdirection%)
DECtime& = (1000 / ratefactor%) * (DECpixels! * DECerror! * DECdirection%)
RAsum& = RAsum& + RAtime& * RAdirection%        'accumulate RA error
Decsum& = Decsum& + DECtime& * DECdirection%    'accumulate Dec error
Guidertext.Text = "RA accum = " + Str$(RAsum&) + " , Dec accum = " + Str$(Decsum&)

If RAtime& < 0 Then S2K% = 8 Else S2K% = 1
Endtime& = GetTickCount + Abs(RAtime&) + 10
Call SetSTAR                                'send RA correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR

Endtime& = GetTickCount + 5               '5mS pause
Do While GetTickCount < Endtime&: Loop

If DECtime& < 0 Then S2K% = 4 Else S2K% = 2
Endtime& = GetTickCount + Abs(DECtime&) + 10
Call SetSTAR                                'send DEC correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR

endcorrect:
End Sub
'click on guide star
Public Sub Guideimage_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
x = Int(x): y = Int(y)
Xloc% = x
Yloc% = y
Impoint% = Imagearray7(x, y)
imvalue& = Impoint%
gtime% = 1
End Sub

Private Sub Trainstart_Click()
If pickstar% = 0 Then MsgBox "You must pick a guide star first!": Guiderun% = 0: Guideflag% = 0: Exit Sub
Training% = 1
Call Guidepic_Click

Call Centroid

S2K% = 1
Endtime& = GetTickCount + 2000              '2 seconds drive west
Call SetSTAR                                'send RA correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR
Endtime& = GetTickCount + 100               '100mS pause
Do While GetTickCount < Endtime&: Loop

Call Guidepic_Click

Call Centroid

S2K% = 2
Endtime& = GetTickCount + 2000              '2 seconds drive north
Call SetSTAR                                'send RA correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR
Endtime& = GetTickCount + 100               '100mS pause
Do While GetTickCount < Endtime&: Loop
Call Guidepic_Click

Call Centroid

S2K% = 8
Endtime& = GetTickCount + 2000              '2 seconds drive east
Call SetSTAR                                'send RA correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR
Endtime& = GetTickCount + 100               '100mS pause
Do While GetTickCount < Endtime&: Loop
Call Guidepic_Click

Call Centroid

S2K% = 4
Endtime& = GetTickCount + 2000              '2 seconds drive south
Call SetSTAR                                'send RA correction
Do While GetTickCount < Endtime&: Loop
S2K% = 0
Call SetSTAR
Endtime& = GetTickCount + 100               '100mS pause
Do While GetTickCount < Endtime&: Loop
Call Guidepic_Click

Call Centroid

DoEvents

Training% = 0

End Sub

Private Sub Trainend_Click()
Training% = 0
End Sub

Sub Centroid()

sumx& = 0: sumy& = 0: sumtotal& = 0

For xx% = px% To qx%                    'get total ADU
    For yy% = py% To qy%
    imval% = Imagearray7(xx%, yy%) - background&
    If imval% < 0 Then imval% = 0
    sumtotal& = sumtotal& + imval%
    Next yy%
Next xx%

If sumtotal& < 0 Then MsgBox "Star is too faint!": Call Pickguide_Click

dx% = 1
For xx% = px% To qx%                    'get moment in x direction
    For yy% = py% To qy%
    imval% = Imagearray7(xx%, yy%) - background&
    If imval% < 0 Then imval% = 0
    sumy& = sumy& + (dx% * (imval%))
    Next yy%
    dx% = dx% + 1
Next xx%

cx! = sumy& / sumtotal&

dy% = 1
For yy% = py% To qy%                    'get moment in y direction
    For xx% = px% To qx%
    imval% = Imagearray7(xx%, yy%) - background&
    If imval% < 0 Then imval% = 0
    sumx& = sumx& + (dy% * (imval%))
    Next xx%
    dy% = dy% + 1
Next yy%

cy! = sumx& / sumtotal&

Cursorloc.Text = Format$(px% + cx!, "000.0") + " , " + Format$(py% + cy!, "000.0")

RAerror! = RAcentre! - cx!
DECerror! = DECcentre! - cy!

Errortext.Text = Format$(RAerror!, "0.0") + " , " + Format$(DECerror!, "0.0")

Guideimage.Line (Xloc% - 10, Yloc%)-(Xloc% + 10, Yloc%), RGB(0, 255, 0)        'draw cross at guide star position
Guideimage.Line (Xloc%, Yloc% - 10)-(Xloc%, Yloc% + 10), RGB(0, 255, 0)
End Sub

Sub Guidesmooth()
If pickstar% = 0 Then py% = 135: qy% = 155: px% = 240: qx% = 260
For y% = py% To qy%
    For x% = px% To qx%
        w% = 0
        For yy% = y% - 1 To y% + 1
        For xx% = x% - 1 To x% + 1
        Window&(w%) = Imagearray7(xx%, yy%)
        w% = w% + 1
        Next xx%
        Next yy%
bubble:
        For w% = 0 To 7
        If Window&(w%) > Window&(w% + 1) Then n% = Window&(w%): Window&(w%) = Window&(w% + 1): Window&(w% + 1) = n%: s% = 1
        Next w%
If s% = 1 Then s% = 0: GoTo bubble
        Imagearray9(x%, y%) = Window&(4)
    Next x%
Next y%
For y% = py% To qy%
    For x% = px% To qx%
    Imagearray7(x%, y%) = Imagearray9(x%, y%)
    Next x%
Next y%
End Sub




'FOCUSING ROUTINES

Private Sub Focusstart_Click()
LSwidth& = 128: MSwidth& = 0: LSheight& = 129: MSheight& = 0: gain% = Gain1.Value

'MsgBox "hcentre%=" + Str$(hcentre%) + ", vcentre%=" + Str$(vcentre%)

Bin% = 0

If setfocuscentre% = 0 Then
xoffset_L = 215
xoffset_H = 5
yoffset_L = 244
yoffset_H = 1
Else
FX% = FXloc% - 63
FY% = FYloc% / 2 - 63
If FX% < 0 Then FX% = 0
If FY% < 0 Then FY% = 0
xoffset_H = Fix(FX% / 256)
yoffset_H = Fix(FY% / 256)
xoffset_L = FX% - (xoffset_H * 256)
yoffset_L = FY% - (yoffset_H * 256)
End If

Focusflag% = 1

Vs& = Vscrollexp.Value
If Option0.Value = True Then
Expinterval& = Vs&
End If

If Option1.Value = True Then
Expinterval& = Vs& * 10
End If

If Option2.Value = True Then
Expinterval& = Vs& * 100
End If

If Option3.Value = True Then
Expinterval& = Vs& * 1000
End If

If Option4.Value = True Then
Expinterval& = Vs& * 60000
End If


DoEvents

Reportptr& = VarPtr(ReportBuffer(0))
Imptr& = VarPtr(Imagearray6(0, 0))

'MsgBox Str$(hdump%) + Str$(hdump2%) + Str$(vdump%) + Str$(vdump2%)

Call Clearvert
Call Wiper

DoEvents
Tloop% = 0
Readcount& = 33280

Focusrepeat:

Countdowntxt.Text = "Exposing"

Ex$ = Right("00000000" + Hex$(Expinterval&), 8)

Ex1$ = "&H" + (Left(Ex$, 2))
Ex2$ = "&H" + (Right((Left(Ex$, 4)), 2))
Ex3$ = "&H" + (Right((Left(Ex$, 6)), 2))
Ex4$ = "&H" + (Right((Left(Ex$, 8)), 2))

    Countdowntxt.Text = "Focus"
    DoEvents

    Do While Elapsed& < ImageExpEnd&                'Exposure loop
    Elapsed& = GetTickCount
    Loop

    If Focusflag% = 0 Then Exit Sub

    Call Reader1

Readstart1:

Countdowntxt.Text = "Reading"
DoEvents

mode% = 1
Call ReceiveSubframe
DoEvents

    z& = 257
    For y% = 0 To 127
    For x% = 0 To 127
    p% = ReportBuffer(z&)
    pp& = p% * gain%
    If pp& > 255 Then pp& = 255
    Imagearray6(x%, y%) = pp&
    z& = z& + 2
    Next x%
    Next y%

If Focusflag% = 0 Then Countdowntxt.Text = "": Exit Sub
Countdowntxt.Text = ""
DoEvents
Call Showfocus

End Sub

Private Sub Focusstop_Click()
Focusflag% = 0
Countdowntxt.Text = ""
DoEvents
End Sub

Private Sub Showfocus()
Call moveimage
Focusmax.Text = Str$(peak%)
DoEvents
Focusstart_Click
End Sub

Private Sub Focuscentre_Click()
mclick% = 0
Focusloc.Text = "Click on the main image"
Do While mclick% = 0: DoEvents: Loop
'MainMenu.Focustext.Visible = False
Focusloc.Text = "Focus spot = " + Str$(FXloc%) + ", " + Str$(FYloc%)
setfocuscentre% = 1
End Sub

Sub moveimage()
    
' get bitmap info
GetObjectAPI Focusimage.Picture, Len(BMP), BMP

' have the local matrix point to bitmap pixels
With sa
    .cbElements = 1
    .cDims = 2
    .Bounds(0).lLbound = 0
    .Bounds(0).cElements = BMP.bmHeight
    .Bounds(1).lLbound = 0
    .Bounds(1).cElements = BMP.bmWidthBytes
    .pvData = BMP.bmBits
End With

peak% = 0
CopyMemory ByVal VarPtrArray(pict), VarPtr(sa), 4
Dim Intens As Byte
For c = 1 To UBound(pict, 1) - 1
    For r = 1 To UBound(pict, 2)
        r2% = 128 - r
        If c > 30 Then If Imagearray6(r, c) > peak% Then peak% = Imagearray6(r, c)
        pict(c, r) = Imagearray6(c + 1, r2%)
    Next r
Next c

Focusmax.Text = Str$(peak%)
DoEvents
' clear the temporary array descriptor without destroying the local temporary array
CopyMemory ByVal VarPtrArray(pict), 0&, 4
' inform VB that something has changed
Focusimage.Refresh

End Sub

Private Sub Focusimage_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
Xf% = Int(x): Yf% = Int(y)
Impoint% = Imagearray5%(Xf%, Yf%)
If Impoint% < 0 Then imvalue& = Impoint% + 65536 Else imvalue& = Impoint%
Focusloc.Text = Str$(Xf%) + ",  " + Str$(Yf%) + ",  " + Str$(imvalue&)
If Xf% < 2 Or Xf% > 96 Then Focusloc.Text = ""
If Yf% < 2 Or Yf% > 96 Then Focusloc.Text = ""
DoEvents
End Sub

Private Sub flat_Click()
If Colourfile% = 1 Then c% = 1
MousePointer = 11
Call FlatLoad_Click
MousePointer = 11
sumpix& = 0
For y& = vsize& / 2 To vsize& / 2 + 100
For x& = hsize& / 2 To hsize& / 2 + 100
a& = Imagearray3%(x&, y&)
If a& < 0 Then a& = a& + 65536
sumpix& = sumpix& + a&
Next x&
Next y&
meanflat& = sumpix& / 10000

If c% = 1 Then Colourfile% = 1
If Colourfile% = 1 Then
For y& = 0 To (vsize& - 1)
For x& = 0 To hsize& - 1
n& = x& + (y& * hsize&)
m& = Imagearray3%(x&, y&)
q% = m&
If m& < 0 Then m& = m& + 65536
If m& = 0 Then m& = 1
p& = Colourarray%(n&)
If p& < 0 Then p& = p& + 65536
p& = p& * (meanflat& / m&)
If p& < 0 Then p& = 0
If p& > 65535 Then p& = 65535
If p& > 32767 Then p& = p& - 65536
Colourarray%(n&) = p& 'q%
Next x&
Next y&

Call colbmpgen(ByVal Colourptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal SF!, ByVal MRd!, ByVal MGn!, ByVal MBl!, Buffer$)

Else
For y& = 0 To (vsize& - 1)
For x& = 0 To hsize& - 1
m& = Imagearray3%(x&, y&)
q% = m&
If m& < 0 Then m& = m& + 65536
If m& = 0 Then m& = 1
p& = Imagearray1%(x&, y&)
If p& < 0 Then p& = p& + 65536
pp! = p& * (meanflat& / m&)
If pp! < 0 Then pp! = 0
If pp! > 65535 Then pp! = 65535
If pp! > 32767 Then pp! = pp! - 65536
Imagearray1%(x&, y&) = Fix(pp!)
Next x&
Next y&
Call Loadimage
End If
MousePointer = 0

Beep

End Sub

Private Sub FlatLoad_Click()
Wrongfile:
On Error GoTo noload
CommonDialog1.Filter = "Images (*.*)|*.*"
CommonDialog1.Action = 1
filestring$ = CommonDialog1.FileName
q& = FileLen(filestring$)

If q& = hsize& * vsize& * 2 Then Colourfile% = 0: Option7.Value = True: GoTo Loading

MsgBox "Cannot use - Not a full resolution mono file"
CommonDialog1.FileName = ""
GoTo Wrongfile

Loading:
Imagepresent% = 1
MousePointer = 11

Call imgload(filestring$, ByVal Imptr3&, ByVal hsize&, ByVal vsize&)
MousePointer = 0
noload:
End Sub

Private Sub Crash()
MsgBox "Operation terminated due to an invalid value"
Terminate% = 1
End Sub

Sub Pause(ByVal nSecs!)
tdelay& = Int(nSecs! * 1000)
t0& = GetTickCount
t1& = t0& + tdelay&
Do Until t2& > t1&
t2& = GetTickCount
Loop
End Sub

