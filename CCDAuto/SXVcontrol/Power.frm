VERSION 5.00
Begin VB.Form Powerset 
   Caption         =   "Power Law Index"
   ClientHeight    =   1800
   ClientLeft      =   3630
   ClientTop       =   4350
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   1800
   ScaleWidth      =   4680
   Begin VB.CommandButton Command2 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2760
      TabIndex        =   3
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "OK"
      Height          =   375
      Left            =   600
      TabIndex        =   2
      Top             =   1200
      Width           =   1215
   End
   Begin VB.TextBox Powertext 
      Alignment       =   2  'Center
      Height          =   285
      Left            =   1800
      MultiLine       =   -1  'True
      TabIndex        =   1
      Text            =   "Power.frx":0000
      Top             =   720
      Width           =   975
   End
   Begin VB.HScrollBar ScrollPower 
      Height          =   255
      Left            =   480
      Max             =   30
      Min             =   1
      TabIndex        =   0
      Top             =   240
      Value           =   10
      Width           =   3735
   End
End
Attribute VB_Name = "Powerset"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Powerset_Load()
ScrollPower.Value = 10
Powr! = 1
End Sub

Private Sub Command1_Click()
Call MainMenu.Powerstretch
ScrollPower.Value = 10
Powertext.Text = Str$(Powr!)
Powr! = 1
Powerset.Hide
MainMenu.Show
End Sub

Private Sub Command2_Click()
ScrollPower.Value = 10
Powr! = 1
Powertext.Text = Str$(Powr!)
Powerset.Hide
End Sub

Private Sub ScrollPower_Change()
Powr! = ScrollPower.Value / 10
Powertext.Text = Str$(Powr!)
End Sub

Private Sub ScrollPower_Scroll()
ScrollPower_Change
End Sub
