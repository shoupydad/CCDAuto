VERSION 5.00
Begin VB.Form Dialog 
   AutoRedraw      =   -1  'True
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Camera select"
   ClientHeight    =   3195
   ClientLeft      =   1425
   ClientTop       =   2385
   ClientWidth     =   6030
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3195
   ScaleWidth      =   6030
   ShowInTaskbar   =   0   'False
   Begin VB.OptionButton Option9 
      Caption         =   "SXV-M5C"
      Height          =   615
      Left            =   480
      TabIndex        =   11
      Top             =   2280
      Width           =   1215
   End
   Begin VB.OptionButton Option8 
      Caption         =   "SXV-M7C"
      Height          =   495
      Left            =   480
      TabIndex        =   10
      Top             =   1800
      Width           =   1335
   End
   Begin VB.OptionButton Option2 
      Caption         =   "SXV-M5"
      Height          =   615
      Left            =   2280
      TabIndex        =   9
      Top             =   2280
      Width           =   1575
   End
   Begin VB.OptionButton Option7 
      Caption         =   "SXV-M25C"
      Height          =   615
      Left            =   480
      TabIndex        =   8
      Top             =   720
      Value           =   -1  'True
      Width           =   1215
   End
   Begin VB.OptionButton Option6 
      Caption         =   "SXV-M7"
      Height          =   495
      Left            =   2280
      TabIndex        =   7
      Top             =   1800
      Width           =   1455
   End
   Begin VB.OptionButton Option5 
      Caption         =   "SXV-H5"
      Height          =   615
      Left            =   4080
      TabIndex        =   6
      Top             =   2280
      Width           =   1455
   End
   Begin VB.OptionButton Option4 
      Caption         =   "SXV-H9"
      Height          =   615
      Left            =   4080
      TabIndex        =   5
      Top             =   1800
      Width           =   1335
   End
   Begin VB.OptionButton Option3 
      Caption         =   "SXV-M9"
      Height          =   615
      Left            =   2280
      TabIndex        =   4
      Top             =   1200
      Width           =   1215
   End
   Begin VB.OptionButton Option1 
      Caption         =   "SXV-M8C"
      Height          =   615
      Left            =   480
      TabIndex        =   3
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4680
      TabIndex        =   1
      Top             =   600
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   4680
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Camera type selector"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      TabIndex        =   2
      Top             =   120
      Width           =   3135
   End
End
Attribute VB_Name = "Dialog"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub CancelButton_Click()
End
End Sub

Private Sub OKButton_Click()
If Option1 = True Then hsize& = 2088: vsize& = 1550: Readtype% = 0: RGBtype% = 0: camtype% = 1: colourbal% = 1: model% = 120    ' mx8
If Option2 = True Then hsize& = 500: vsize& = 580: Readtype% = 0: RGBtype% = 0: camtype% = 2: colourbal% = 2: model% = 69       'mx5
If Option3 = True Then hsize& = 752: vsize& = 580: Readtype% = 0: RGBtype% = 1: camtype% = 3: colourbal% = 3: model% = 73       'mx9
If Option4 = True Then hsize& = 1392: vsize& = 1040: Readtype% = 1: RGBtype% = 0: camtype% = 4: colourbal% = 4: model% = 9      'hx9
If Option5 = True Then hsize& = 660: vsize& = 494: Readtype% = 1: RGBtype% = 0: camtype% = 5: colourbal% = 5: model% = 5        'hx5
If Option6 = True Then hsize& = 752: vsize& = 580: Readtype% = 0: RGBtype% = 1: camtype% = 6: colourbal% = 6: model% = 71       'mx7
If Option7 = True Then hsize& = 3000: vsize& = 2000: Readtype% = 1: RGBtype% = 0: camtype% = 7: colourbal% = 7: model% = 89     'mx25
If Option8 = True Then hsize& = 752: vsize& = 580: Readtype% = 0: RGBtype% = 1: camtype% = 8: colourbal% = 3: model% = 199      'm7c
If Option9 = True Then hsize& = 500: vsize& = 580: Readtype% = 0: RGBtype% = 0: camtype% = 9: colourbal% = 2: model% = 197      'm5c


Dialog.Hide
ready% = 1
If Option1 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-M8 mode"
If Option2 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-M5 mode"
If Option3 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-M9 mode"
If Option4 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-H9 mode"
If Option5 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-H5 mode"
If Option6 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-M7 mode"
If Option7 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-M25 mode"
If Option8 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-M7C mode"
If Option9 = True Then MainMenu.Caption = "SXV Camera Control and Image Processor for USB1 & 2 - Operating in SXV-M5C mode"


If Option4 = True Or Option5 = True Or Option7 = True Then
MainMenu.Option6.Visible = False: MainMenu.Option7.Visible = False: MainMenu.Option8.Caption = "Bin 1 x 1"
Else
MainMenu.Option6.Visible = True: MainMenu.Option7.Visible = True: MainMenu.Option8.Caption = "Progressive"
End If

Call MainMenu.Form_Initialize: MainMenu.Show
End Sub

