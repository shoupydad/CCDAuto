VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form Colour 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Set colour parameters"
   ClientHeight    =   3195
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   6180
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3195
   ScaleWidth      =   6180
   ShowInTaskbar   =   0   'False
   Begin VB.CheckBox Check2 
      Caption         =   "Line offset"
      Height          =   495
      Left            =   4680
      TabIndex        =   7
      Top             =   2040
      Width           =   1215
   End
   Begin VB.CheckBox Check1 
      Caption         =   "Pixel offset"
      Height          =   375
      Left            =   4680
      TabIndex        =   6
      Top             =   1440
      Width           =   1215
   End
   Begin MSComctlLib.Slider Saturation 
      Height          =   615
      Left            =   240
      TabIndex        =   3
      Top             =   1680
      Width           =   3375
      _ExtentX        =   5953
      _ExtentY        =   1085
      _Version        =   393216
      SelStart        =   2
      Value           =   2
   End
   Begin MSComctlLib.Slider Luminance 
      Height          =   615
      Left            =   240
      TabIndex        =   2
      Top             =   360
      Width           =   3375
      _ExtentX        =   5953
      _ExtentY        =   1085
      _Version        =   393216
      Value           =   5
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
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "Set colour saturation"
      Height          =   375
      Left            =   480
      TabIndex        =   5
      Top             =   2280
      Width           =   3015
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Set luminance saturation point"
      Height          =   255
      Left            =   480
      TabIndex        =   4
      Top             =   960
      Width           =   3015
   End
End
Attribute VB_Name = "Colour"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub CancelButton_Click()
Colour.Hide
End Sub

Private Sub Form_Initialize()
cs& = Luminance.Value
End Sub

Private Sub Luminance_Change()
cs& = Luminance.Value
End Sub

Private Sub OKButton_Click()
cs& = Luminance.Value
cv& = Saturation.Value
If Check1.Value = 1 Then pixeloffset% = 1 Else pixeloffset% = 0
If Check2.Value = 1 Then lineoffset% = 1 Else lineoffset% = 0

Colour.Hide
End Sub
