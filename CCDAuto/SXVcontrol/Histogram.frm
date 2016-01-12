VERSION 5.00
Begin VB.Form Histogram 
   Caption         =   "Image Histogram"
   ClientHeight    =   4635
   ClientLeft      =   3120
   ClientTop       =   2340
   ClientWidth     =   6465
   LinkTopic       =   "Form3"
   ScaleHeight     =   1078.534
   ScaleMode       =   0  'User
   ScaleWidth      =   1628.788
   Begin VB.CommandButton Command2 
      Caption         =   "Cancel"
      Height          =   495
      Left            =   5040
      TabIndex        =   10
      Top             =   1560
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Ok"
      Height          =   495
      Left            =   5040
      TabIndex        =   9
      Top             =   600
      Width           =   1215
   End
   Begin VB.TextBox Whitelevel 
      Alignment       =   2  'Center
      Height          =   387
      Left            =   3960
      MultiLine       =   -1  'True
      TabIndex        =   4
      ToolTipText     =   "Scroll or type the white level"
      Top             =   4080
      Width           =   855
   End
   Begin VB.TextBox Blacklevel 
      Alignment       =   2  'Center
      Height          =   387
      Left            =   360
      MultiLine       =   -1  'True
      TabIndex        =   3
      Top             =   4080
      Width           =   855
   End
   Begin VB.HScrollBar Scrollwhite 
      Height          =   255
      Left            =   240
      Max             =   300
      TabIndex        =   2
      Top             =   3480
      Value           =   255
      Width           =   4695
   End
   Begin VB.HScrollBar Scrollblack 
      Height          =   255
      Left            =   240
      Max             =   300
      TabIndex        =   1
      Top             =   3120
      Width           =   4695
   End
   Begin VB.PictureBox Histopic 
      BackColor       =   &H80000014&
      Height          =   2895
      Left            =   360
      ScaleHeight     =   1100
      ScaleMode       =   0  'User
      ScaleWidth      =   320
      TabIndex        =   0
      Top             =   120
      Width           =   4455
   End
   Begin VB.Label Label1 
      Caption         =   "Black Level"
      Height          =   255
      Left            =   360
      TabIndex        =   11
      Top             =   3840
      Width           =   855
   End
   Begin VB.Label Label5 
      Caption         =   "White"
      Height          =   255
      Left            =   5040
      TabIndex        =   8
      Top             =   3480
      Width           =   495
   End
   Begin VB.Label Label4 
      Caption         =   "Black"
      Height          =   255
      Left            =   5040
      TabIndex        =   7
      Top             =   3120
      Width           =   615
   End
   Begin VB.Label Label3 
      Caption         =   "Set stretch points"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1560
      TabIndex        =   6
      Top             =   4080
      Width           =   2175
   End
   Begin VB.Label Label2 
      Caption         =   "White Level"
      Height          =   255
      Left            =   3960
      TabIndex        =   5
      Top             =   3840
      Width           =   975
   End
End
Attribute VB_Name = "Histogram"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Declare Sub stretcher Lib "MXproc.dll" Alias "STRETCHER" (ByVal stretchtype%, ByVal Powr!, ByVal Blacklev&, ByVal Whitelev&, ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
Dim black%, white%, b%, w%

Private Sub Command1_Click()
MainMenu.MousePointer = 11
stretchtype% = 1
Powr! = 1
Blacklev& = black%
Blacklev& = Blacklev& * 256
Whitelev& = white%
Whitelev& = Whitelev& * 256
If Colourfile% = 0 Then Imptr& = Imptr1& Else Imptr& = Colourptr&
Call stretcher(ByVal stretchtype%, ByVal Powr!, ByVal Blacklev&, ByVal Whitelev&, ByVal Imptr&, ByVal Imptr2&, ByVal hsize&, ByVal vsize&, ByVal HR%)
'Beep
Histogram.Hide
MainMenu.Show
Imagepresent% = 1
Call MainMenu.Loadimage
MainMenu.MousePointer = 0
End Sub

Public Sub Histopicload()
Histopic.Cls
Histopic.Line (10, 10)-(10, 1000), RGB(0, 0, 0)             'Axes
Histopic.Line (10, 1000)-(310, 1000), RGB(0, 0, 0)
n% = 0
For x& = 10 To 298 Step 16                                  'Ticks
If n% = 1 Then v& = 1020 Else v& = 1030
Histopic.Line (x&, 1000)-(x&, v&), RGB(0, 0, 0)
n% = n% + 1
If n% = 2 Then n% = 0
Next x&

black% = 0
white% = 255
Whitelevel.Text = Str$(white%)
Blacklevel.Text = Str$(black%)
Call Arrows

For x& = 0 To 256: Table&(x&) = 0: Next x&              'Empty table
If Bin% = 0 Then lastpix% = vsize& / 2: hs& = hsize&: stp& = 5
If Bin% = 1 Then lastpix% = vsize&: hs& = hsize&: stp& = 10
If Bin% = 2 Then lastpix% = vsize& / 4: hs& = hsize&: stp& = 2
If Bin% = 4 Then lastpix% = vsize& / 8: hs& = hsize&: stp& = 1
If Bin% = 11 Then lastpix% = vsize&: hs& = hsize&: stp& = 10
If Bin% = 22 Then lastpix% = vsize& / 2: hs& = hsize& / 2: stp& = 2
If Bin% = 44 Then lastpix% = vsize& / 4: hs& = hsize& / 4: stp& = 1
If Bin% = 20 Then lastpix% = vsize& / 2: hs& = hsize& / 2: stp& = 2
If Bin% = 40 Then lastpix% = vsize& / 4: hs& = hsize& / 4: stp& = 1

If Colourfile% = 1 Then lastpix% = vsize&: hs& = hsize&: stp& = 10

For y& = 10 To lastpix% Step stp&                                                     'Read image data and bin
For x& = 0 To hs& - 1 Step 10
If Colourfile% = 0 Then z& = Imagearray1%(x&, y&) Else z& = Colourarray%(x& + y& * hs&)
If z& < 0 Then z& = z& + 65536
z& = z& \ 256
Table&(z&) = Table&(z&) + 1
Next x&
Next y&
For x& = 0 To 255                                                       'Draw histogram
v& = 10 + x&
bar& = Table&(x&)
If bar& > 1000 Then bar& = 1000
Histopic.Line (v&, 1000)-(v&, 1000 - bar&), RGB(0, 0, 255)
Next x&
End Sub

Private Sub Arrows()
Colr& = Histopic.Point(2, 2)
rd% = Colr& And 255
grn% = Colr& \ 256 And 255
blu% = Colr& \ 65536 And 255
'MsgBox Str$(rd%) + ", " + Str$(grn%) + ", " + Str$(blu%)
Histopic.Line (b%, 1040)-(b%, 1095), RGB(rd%, grn%, blu%)    'Erase Arrows
Histopic.Line (b%, 1040)-(b% - 3, 1070), RGB(rd%, grn%, blu%)
Histopic.Line (b%, 1040)-(b% + 3, 1070), RGB(rd%, grn%, blu%)
Histopic.Line (w%, 1040)-(w%, 1095), RGB(rd%, grn%, blu%)
Histopic.Line (w%, 1040)-(w% + 3, 1070), RGB(rd%, grn%, blu%)
Histopic.Line (w%, 1040)-(w% - 3, 1070), RGB(rd%, grn%, blu%)
b% = black% + 10
w% = white% + 10
Histopic.Line (b%, 1040)-(b%, 1095), RGB(50, 0, 0)      'New Arrows
Histopic.Line (b%, 1040)-(b% - 3, 1070), RGB(50, 0, 0)
Histopic.Line (b%, 1040)-(b% + 3, 1070), RGB(50, 0, 0)
Histopic.Line (w%, 1040)-(w%, 1095), RGB(0, 50, 0)
Histopic.Line (w%, 1040)-(w% + 3, 1070), RGB(0, 50, 0)
Histopic.Line (w%, 1040)-(w% - 3, 1070), RGB(0, 50, 0)
End Sub

Private Sub Scrollblack_Change()
black% = Scrollblack.Value
Blacklevel.Text = Str$(black%)
Call Arrows
End Sub

Private Sub Scrollblack_Scroll()
Scrollblack_Change
End Sub

Private Sub Scrollwhite_Change()
white% = Scrollwhite.Value
Whitelevel.Text = Str$(white%)
Call Arrows
End Sub

Private Sub Scrollwhite_Scroll()
Scrollwhite_Change
End Sub

Private Sub Whitelevel_Change()
white% = Int(Val(Whitelevel.Text))
If white% > 300 Then white% = 300
If white% < 0 Then white% = 0
Whitelevel.Text = Str$(white%)
Scrollwhite.Value = white%
End Sub

Private Sub Blacklevel_Change()
black% = Int(Val(Blacklevel.Text))
If black% > 300 Then black% = 300
If black% < 0 Then black% = 0
Blacklevel.Text = Str$(black%)
Scrollblack.Value = black%
End Sub

Private Sub Command2_Click()
Histogram.Hide
End Sub
