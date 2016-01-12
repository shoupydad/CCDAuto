VERSION 5.00
Begin VB.Form unsharpset 
   Caption         =   "Unsharp Mask parameters"
   ClientHeight    =   3195
   ClientLeft      =   6315
   ClientTop       =   6450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   Begin VB.TextBox unpower 
      Alignment       =   2  'Center
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   3240
      TabIndex        =   5
      Text            =   "1"
      Top             =   960
      Width           =   615
   End
   Begin VB.TextBox unrad 
      Alignment       =   2  'Center
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   720
      TabIndex        =   4
      Text            =   "3"
      Top             =   960
      Width           =   615
   End
   Begin VB.CommandButton unsharpcancel 
      Caption         =   "Cancel"
      Height          =   495
      Left            =   2640
      TabIndex        =   3
      Top             =   2400
      Width           =   1215
   End
   Begin VB.CommandButton unsharpstart 
      Caption         =   "OK"
      Height          =   495
      Left            =   720
      TabIndex        =   2
      Top             =   2400
      Width           =   1095
   End
   Begin VB.HScrollBar unsharppower 
      Height          =   255
      Left            =   600
      Max             =   7
      Min             =   1
      TabIndex        =   1
      Top             =   1560
      Value           =   1
      Width           =   3375
   End
   Begin VB.HScrollBar Radiusscroll 
      Height          =   255
      Left            =   600
      Max             =   7
      Min             =   1
      TabIndex        =   0
      Top             =   480
      Value           =   3
      Width           =   3375
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "Set Power"
      Height          =   255
      Left            =   1320
      TabIndex        =   7
      Top             =   1920
      Width           =   1935
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Set Radius"
      Height          =   255
      Left            =   1320
      TabIndex        =   6
      Top             =   240
      Width           =   1935
   End
End
Attribute VB_Name = "unsharpset"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Radiusscroll_Change()
r% = Radiusscroll.Value
unrad.Text = Str$(r%)
End Sub

Private Sub unsharpcancel_Click()
unsharpset.Hide
MainMenu.Show
End Sub

Private Sub unsharppower_Change()
Pwr% = unsharppower.Value
unpower.Text = Str$(Pwr%)
End Sub

Private Sub unsharpstart_Click()
unsharpset.Hide
DoEvents
Radius% = Radiusscroll.Value
Pwr% = unsharppower.Value
Call MainMenu.Unsharpdo
MainMenu.Show
End Sub
