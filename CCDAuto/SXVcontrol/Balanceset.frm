VERSION 5.00
Begin VB.Form Balanceset 
   Caption         =   "Set Colour Balance"
   ClientHeight    =   5880
   ClientLeft      =   7995
   ClientTop       =   1500
   ClientWidth     =   8730
   LinkTopic       =   "Form1"
   ScaleHeight     =   5880
   ScaleWidth      =   8730
   Begin VB.HScrollBar Scrollsat 
      Height          =   252
      Left            =   2520
      Max             =   10
      TabIndex        =   18
      Top             =   4320
      Value           =   5
      Width           =   3735
   End
   Begin VB.TextBox Sat 
      Alignment       =   2  'Center
      Height          =   288
      Left            =   4200
      MultiLine       =   -1  'True
      TabIndex        =   17
      Text            =   "Balanceset.frx":0000
      Top             =   4920
      Width           =   492
   End
   Begin VB.CommandButton Balchange 
      Caption         =   "OK"
      Height          =   372
      Left            =   2520
      TabIndex        =   16
      Top             =   4920
      Width           =   972
   End
   Begin VB.CommandButton Nobalchange 
      Caption         =   "Cancel"
      Height          =   372
      Left            =   5280
      TabIndex        =   15
      Top             =   4920
      Width           =   972
   End
   Begin VB.PictureBox Greenhistogram 
      BackColor       =   &H00FFFFFF&
      ForeColor       =   &H00FFFFFF&
      Height          =   2415
      Left            =   3120
      ScaleHeight     =   157
      ScaleMode       =   0  'User
      ScaleWidth      =   157
      TabIndex        =   14
      Top             =   600
      Width           =   2415
   End
   Begin VB.PictureBox Bluehistogram 
      BackColor       =   &H00FFFFFF&
      FillColor       =   &H00FFFFFF&
      ForeColor       =   &H00FFFFFF&
      Height          =   2415
      Left            =   5640
      ScaleHeight     =   157
      ScaleMode       =   0  'User
      ScaleWidth      =   157
      TabIndex        =   13
      Top             =   600
      Width           =   2415
   End
   Begin VB.PictureBox Redhistogram 
      BackColor       =   &H00FFFFFF&
      Height          =   2415
      Left            =   600
      ScaleHeight     =   157
      ScaleMode       =   0  'User
      ScaleWidth      =   157
      TabIndex        =   12
      Top             =   600
      Width           =   2415
   End
   Begin VB.HScrollBar Scrollred1 
      Height          =   132
      Left            =   600
      Max             =   255
      TabIndex        =   11
      Top             =   3120
      Width           =   2412
   End
   Begin VB.HScrollBar Scrollgreen1 
      Height          =   132
      Left            =   3120
      Max             =   255
      TabIndex        =   10
      Top             =   3120
      Width           =   2412
   End
   Begin VB.HScrollBar Scrollblue1 
      Height          =   132
      Left            =   5640
      Max             =   255
      TabIndex        =   9
      Top             =   3120
      Width           =   2412
   End
   Begin VB.HScrollBar Scrollred2 
      Height          =   132
      Left            =   600
      Max             =   270
      TabIndex        =   8
      Top             =   3360
      Value           =   255
      Width           =   2412
   End
   Begin VB.HScrollBar Scrollgreen2 
      Height          =   132
      Left            =   3120
      Max             =   270
      TabIndex        =   7
      Top             =   3360
      Value           =   255
      Width           =   2412
   End
   Begin VB.HScrollBar Scrollblue2 
      Height          =   132
      Left            =   5640
      Max             =   270
      TabIndex        =   6
      Top             =   3360
      Value           =   255
      Width           =   2412
   End
   Begin VB.TextBox Redmintxt 
      Alignment       =   2  'Center
      Height          =   288
      Left            =   720
      MultiLine       =   -1  'True
      TabIndex        =   5
      Top             =   3600
      Width           =   492
   End
   Begin VB.TextBox Redmaxtxt 
      Alignment       =   2  'Center
      Height          =   288
      Left            =   2400
      MultiLine       =   -1  'True
      TabIndex        =   4
      Top             =   3600
      Width           =   492
   End
   Begin VB.TextBox Greenmintxt 
      Alignment       =   2  'Center
      Height          =   288
      Left            =   3240
      MultiLine       =   -1  'True
      TabIndex        =   3
      Top             =   3600
      Width           =   492
   End
   Begin VB.TextBox Greenmaxtxt 
      Alignment       =   2  'Center
      Height          =   288
      Left            =   4920
      MultiLine       =   -1  'True
      TabIndex        =   2
      Top             =   3600
      Width           =   492
   End
   Begin VB.TextBox Bluemintxt 
      Alignment       =   2  'Center
      Height          =   288
      Left            =   5760
      MultiLine       =   -1  'True
      TabIndex        =   1
      Top             =   3600
      Width           =   492
   End
   Begin VB.TextBox Bluemaxtxt 
      Alignment       =   2  'Center
      Height          =   288
      Left            =   7440
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   3600
      Width           =   492
   End
   Begin VB.Label Label1 
      Caption         =   "Set colour saturation factor"
      Height          =   255
      Left            =   3480
      TabIndex        =   22
      Top             =   4680
      Width           =   2295
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "Red"
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   1200
      TabIndex        =   21
      Top             =   360
      Width           =   1335
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "Green"
      ForeColor       =   &H00008000&
      Height          =   255
      Left            =   3720
      TabIndex        =   20
      Top             =   360
      Width           =   1215
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      Caption         =   "Blue"
      ForeColor       =   &H00800080&
      Height          =   255
      Left            =   6120
      TabIndex        =   19
      Top             =   360
      Width           =   1335
   End
End
Attribute VB_Name = "Balanceset"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim Redmin%, Greenmin%, Bluemin%, Redmax%, Greenmax%, Bluemax%, br%, wr%, bg%, wg%, bb%, wb%
Dim Redtable%(255)
Dim Greentable%(255)
Dim Bluetable%(255)
Private Declare Sub colourstretcher Lib "MXcolr.dll" Alias "COLOURSTRETCHER" (ByVal Minimum%, ByVal Maximum%, ByVal Colptr&, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Private Declare Sub coloursmooth Lib "MXcolr.dll" Alias "COLOURSMOOTH" (ByVal ptr1&, ByVal ptr2&)
Private Declare Sub colbmpgen Lib "Colbmp.dll" Alias "COLBMPGEN" (ByVal Colourptr&, ByVal Bmpptr&, ByVal hsize&, ByVal vsize&, ByVal SF!, ByVal MRd!, ByVal MGn!, ByVal MBl!, Buffer$)

Private Sub Form_Initialize()
SF! = Scrollsat.Value
Sat.Text = Str$(Scrollsat.Value / 5)
End Sub

Private Sub Balchange_Click()
Balanceset.Hide
MainMenu.MousePointer = 11
'Call copyimge(ByVal Imptr1&, ByVal Imptr4&)
DoEvents
MRd! = 1: MGn! = 1: MBl! = 1
SF! = Scrollsat.Value / 5
Sat.Text = Str$(Scrollsat.Value / 5)
Colptr& = Colourptr& + bin1size&
Minimum% = Redmin%: Maximum% = Redmax%
Call colourstretcher(ByVal Minimum%, ByVal Maximum%, ByVal Colptr&, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Colptr& = Colourptr& + greenstart&
Minimum% = Greenmin%: Maximum% = Greenmax%
Call colourstretcher(ByVal Minimum%, ByVal Maximum%, ByVal Colptr&, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Colptr& = Colourptr& + bluestart&
Minimum% = Bluemin%: Maximum% = Bluemax%
Call colourstretcher(ByVal Minimum%, ByVal Maximum%, ByVal Colptr&, ByVal Colourptr&, ByVal hsize&, ByVal vsize&)
Call MainMenu.Loadimage
MainMenu.MousePointer = 0
End Sub

Private Sub Nobalchange_Click()
Balanceset.Hide
End Sub

Private Sub Scrollsat_Change()
SF! = Scrollsat.Value
Sat.Text = Str$(Scrollsat.Value / 5)
End Sub

Public Sub Drawhistograms()
br% = 0: wr% = 127: bg% = 0: wg% = 127: bb% = 0: wb% = 127
Redhistogram.Cls
Redhistogram.Line (10, 10)-(10, 140), RGB(0, 0, 0)             'Axes
Redhistogram.Line (10, 140)-(140, 140), RGB(0, 0, 0)
n% = 0
For x& = 10 To 138 Step 8                                          'Ticks
If n% = 1 Then v& = 143 Else v& = 145
Redhistogram.Line (x&, 140)-(x&, v&), RGB(0, 0, 0)
n% = n% + 1
If n% = 2 Then n% = 0
Next x&
Greenhistogram.Cls
Greenhistogram.Line (10, 10)-(10, 140), RGB(0, 0, 0)             'Axes
Greenhistogram.Line (10, 140)-(140, 140), RGB(0, 0, 0)
n% = 0
For x& = 10 To 138 Step 8                                          'Ticks
If n% = 1 Then v& = 143 Else v& = 145
Greenhistogram.Line (x&, 140)-(x&, v&), RGB(0, 0, 0)
n% = n% + 1
If n% = 2 Then n% = 0
Next x&
Bluehistogram.Cls
Bluehistogram.Line (10, 10)-(10, 140), RGB(0, 0, 0)             'Axes
Bluehistogram.Line (10, 140)-(140, 140), RGB(0, 0, 0)
n% = 0
For x& = 10 To 138 Step 8                                          'Ticks
If n% = 1 Then v& = 143 Else v& = 145
Bluehistogram.Line (x&, 140)-(x&, v&), RGB(0, 0, 0)
n% = n% + 1
If n% = 2 Then n% = 0
Next x&
Redmin% = 0: Greenmin% = 0: Bluemin% = 0
Redmax% = 255: Greenmax% = 255: Bluemax% = 255
Redmintxt.Text = Str$(Redmin%)
Redmaxtxt.Text = Str$(Redmax%)
Greenmintxt.Text = Str$(Greenmin%)
Greenmaxtxt.Text = Str$(Greenmax%)
Bluemintxt.Text = Str$(Bluemin%)
Bluemaxtxt.Text = Str$(Bluemax%)

Call RedArrows
Call GreenArrows
Call BlueArrows
Call Generate
End Sub

Private Sub RedArrows()
Redhistogram.Line (br%, 147)-(br%, 155), RGB(255, 255, 255)    'Erase Arrows
Redhistogram.Line (br%, 147)-(br% - 3, 150), RGB(255, 255, 255)
Redhistogram.Line (br%, 147)-(br% + 3, 150), RGB(255, 255, 255)
Redhistogram.Line (wr%, 147)-(wr%, 155), RGB(255, 255, 255)
Redhistogram.Line (wr%, 147)-(wr% + 3, 150), RGB(255, 255, 255)
Redhistogram.Line (wr%, 147)-(wr% - 3, 150), RGB(255, 255, 255)
br% = Redmin% \ 2 + 10
wr% = Redmax% \ 2 + 10
Redhistogram.Line (br%, 147)-(br%, 155), RGB(50, 0, 0)      'New Arrows
Redhistogram.Line (br%, 147)-(br% - 3, 150), RGB(50, 0, 0)
Redhistogram.Line (br%, 147)-(br% + 3, 150), RGB(50, 0, 0)
Redhistogram.Line (wr%, 147)-(wr%, 155), RGB(50, 0, 0)
Redhistogram.Line (wr%, 147)-(wr% + 3, 150), RGB(50, 0, 0)
Redhistogram.Line (wr%, 147)-(wr% - 3, 150), RGB(50, 0, 0)
End Sub

Private Sub GreenArrows()
Greenhistogram.Line (bg%, 147)-(bg%, 155), RGB(255, 255, 255)    'Erase Arrows
Greenhistogram.Line (bg%, 147)-(bg% - 3, 150), RGB(255, 255, 255)
Greenhistogram.Line (bg%, 147)-(bg% + 3, 150), RGB(255, 255, 255)
Greenhistogram.Line (wg%, 147)-(wg%, 155), RGB(255, 255, 255)
Greenhistogram.Line (wg%, 147)-(wg% + 3, 150), RGB(255, 255, 255)
Greenhistogram.Line (wg%, 147)-(wg% - 3, 150), RGB(255, 255, 255)
bg% = Greenmin% \ 2 + 10
wg% = Greenmax% \ 2 + 10
Greenhistogram.Line (bg%, 147)-(bg%, 155), RGB(0, 50, 0)      'New Arrows
Greenhistogram.Line (bg%, 147)-(bg% - 3, 150), RGB(0, 50, 0)
Greenhistogram.Line (bg%, 147)-(bg% + 3, 150), RGB(0, 50, 0)
Greenhistogram.Line (wg%, 147)-(wg%, 155), RGB(0, 50, 0)
Greenhistogram.Line (wg%, 147)-(wg% + 3, 150), RGB(0, 50, 0)
Greenhistogram.Line (wg%, 147)-(wg% - 3, 150), RGB(0, 50, 0)
End Sub

Private Sub BlueArrows()
Bluehistogram.Line (bb%, 147)-(bb%, 155), RGB(255, 255, 255)    'Erase Arrows
Bluehistogram.Line (bb%, 147)-(bb% - 3, 150), RGB(255, 255, 255)
Bluehistogram.Line (bb%, 147)-(bb% + 3, 150), RGB(255, 255, 255)
Bluehistogram.Line (wb%, 147)-(wb%, 155), RGB(255, 255, 255)
Bluehistogram.Line (wb%, 147)-(wb% + 3, 150), RGB(255, 255, 255)
Bluehistogram.Line (wb%, 147)-(wb% - 3, 150), RGB(255, 255, 255)
bb% = Bluemin% \ 2 + 10
wb% = Bluemax% \ 2 + 10
Bluehistogram.Line (bb%, 147)-(bb%, 155), RGB(50, 0, 50)      'New Arrows
Bluehistogram.Line (bb%, 147)-(bb% - 3, 150), RGB(0, 0, 50)
Bluehistogram.Line (bb%, 147)-(bb% + 3, 150), RGB(0, 0, 50)
Bluehistogram.Line (wb%, 147)-(wb%, 155), RGB(0, 0, 50)
Bluehistogram.Line (wb%, 147)-(wb% + 3, 150), RGB(0, 0, 50)
Bluehistogram.Line (wb%, 147)-(wb% - 3, 150), RGB(0, 0, 50)
End Sub

Private Sub Generate()

For x& = 0 To 255: Redtable%(x&) = 0: Next x&              'Empty table
                                                   'Read image data and bin
For x& = (hsize& * vsize& + hsize& * 10) To (hsize& * vsize& * 1.5 - hsize& * 10) Step 500
z% = Colourarray%(x&)
If z% < 0 Then zr& = z% + 65535 Else zr& = z%
zr& = zr& \ 256
Redtable%(zr&) = Redtable%(zr&) + 1
Next x&

For x& = 1 To 127                                                       'Draw histogram
v& = 10 + x&
bar% = Redtable%(x& * 2)
If bar% > 139 Then bar% = 139
Redhistogram.Line (v&, 139)-(v&, 139 - bar%), RGB(255, 0, 0)
Next x&

For x& = 0 To 255: Greentable%(x&) = 0: Next x&              'Empty table

For x& = (hsize& * vsize& * 1.5 + hsize& * 10) To (hsize& * vsize& * 2 - hsize& * 10) Step 500                                     'Read image data and bin
z% = Colourarray%(x&)
If z% < 0 Then zg& = z% + 65535 Else zg& = z%
zg& = zg& \ 256
Greentable%(zg&) = Greentable%(zg&) + 1
Next x&

For x& = 1 To 127                                                       'Draw histogram
v& = 10 + x&
bar% = Greentable%(x& * 2)
If bar% > 139 Then bar% = 139
Greenhistogram.Line (v&, 139)-(v&, 139 - bar%), RGB(0, 255, 0)
Next x&

For x& = 0 To 255: Bluetable%(x&) = 0: Next x&                          'Empty table

For x& = (hsize& * vsize& * 2 + hsize& * 10) To (hsize& * vsize& * 2.5 - hsize& * 10) Step 500
z% = Colourarray%(x&)
If z% < 0 Then zb& = z% + 65535 Else zb& = z%
zb& = zb& \ 256
Bluetable%(zb&) = Bluetable%(zb&) + 1
Next x&

For x& = 1 To 127                                                       'Draw histogram
v& = 10 + x&
bar% = Bluetable%(x& * 2)
If bar% > 139 Then bar% = 139
Bluehistogram.Line (v&, 139)-(v&, 139 - bar%), RGB(0, 0, 255)
Next x&
End Sub

Private Sub Scrollred1_Change()
Redmin% = Scrollred1.Value
Redmintxt.Text = Str$(Redmin%)
Call RedArrows
End Sub

Private Sub Scrollred1_Scroll()
Scrollred1_Change
End Sub

Private Sub Scrollred2_Scroll()
Scrollred2_Change
End Sub

Private Sub Scrollgreen1_Scroll()
Scrollgreen1_Change
End Sub

Private Sub Scrollgreen2_Scroll()
Scrollgreen2_Change
End Sub

Private Sub Scrollblue1_Scroll()
ScrollBlue1_Change
End Sub

Private Sub Scrollblue2_Scroll()
ScrollBlue2_Change
End Sub

Private Sub Scrollred2_Change()
Redmax% = Scrollred2.Value
Redmaxtxt.Text = Str$(Redmax%)
Call RedArrows
End Sub

Private Sub Redmintxt_Change()
Redmin% = Int(Val(Redmintxt.Text))
If Redmin% > 300 Then Redmin% = 300
If Redmin% < 0 Then Redmin% = 0
Redmintxt.Text = Str$(Redmin%)
Scrollred1.Value = Redmin%
End Sub

Private Sub Redmaxtxt_Change()
Redmax% = Int(Val(Redmaxtxt.Text))
If Redmax% > 300 Then Redmax% = 300
If Redmax% < 0 Then Redmax% = 0
Redmaxtxt.Text = Str$(Redmax%)
Scrollred2.Value = Redmax%
End Sub

Private Sub Scrollgreen1_Change()
Greenmin% = Scrollgreen1.Value
Greenmintxt.Text = Str$(Greenmin%)
Call GreenArrows
End Sub

Private Sub Scrollgreen2_Change()
Greenmax% = Scrollgreen2.Value
Greenmaxtxt.Text = Str$(Greenmax%)
Call GreenArrows
End Sub

Private Sub Greenmintxt_Change()
Greenmin% = Int(Val(Greenmintxt.Text))
If Greenmin% > 300 Then Greenmin% = 300
If Greenmin% < 0 Then Greenmin% = 0
Greenmintxt.Text = Str$(Greenmin%)
Scrollgreen1.Value = Greenmin%
End Sub

Private Sub Greenmaxtxt_Change()
Greenmax% = Int(Val(Greenmaxtxt.Text))
If Greenmax% > 300 Then Greenmax% = 300
If Greenmax% < 0 Then Greenmax% = 0
Greenmaxtxt.Text = Str$(Greenmax%)
Scrollgreen2.Value = Greenmax%
End Sub

Private Sub ScrollBlue1_Change()
Bluemin% = Scrollblue1.Value
Bluemintxt.Text = Str$(Bluemin%)
Call BlueArrows
End Sub

Private Sub ScrollBlue2_Change()
Bluemax% = Scrollblue2.Value
Bluemaxtxt.Text = Str$(Bluemax%)
Call BlueArrows
End Sub

Private Sub Bluemintxt_Change()
Bluemin% = Int(Val(Bluemintxt.Text))
If Bluemin% > 300 Then Bluemin% = 300
If Bluemin% < 0 Then Bluemin% = 0
Bluemintxt.Text = Str$(Bluemin%)
Scrollblue1.Value = Bluemin%
End Sub

Private Sub Bluemaxtxt_Change()
Bluemax% = Int(Val(Bluemaxtxt.Text))
If Bluemax% > 300 Then Bluemax% = 300
If Bluemax% < 0 Then Bluemax% = 0
Bluemaxtxt.Text = Str$(Bluemax%)
Scrollblue2.Value = Bluemax%
End Sub


