VERSION 5.00
Begin VB.Form Defaults 
   Caption         =   "Set Camera Readout Defaults"
   ClientHeight    =   3240
   ClientLeft      =   4530
   ClientTop       =   2565
   ClientWidth     =   3105
   LinkTopic       =   "Form1"
   ScaleHeight     =   3240
   ScaleWidth      =   3105
   StartUpPosition =   1  'CenterOwner
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      Height          =   375
      Left            =   720
      TabIndex        =   1
      Top             =   1080
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "OK"
      Height          =   495
      Left            =   960
      TabIndex        =   0
      Top             =   2280
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Current Autosave File Number"
      Height          =   255
      Left            =   480
      TabIndex        =   2
      Top             =   720
      Width           =   2295
   End
End
Attribute VB_Name = "Defaults"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
Open Dirpath$ + "MX.ini" For Output As #2
config$ = Str$(img%)
Print #2, config$
Close #2
Defaults.Hide
End Sub

Private Sub Form_Load()
Text1.Text = Str$(img%)
End Sub

