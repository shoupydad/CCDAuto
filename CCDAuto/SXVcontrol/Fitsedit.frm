VERSION 5.00
Begin VB.Form Fitsedit 
   Caption         =   "Fits Header Information"
   ClientHeight    =   7110
   ClientLeft      =   4035
   ClientTop       =   4050
   ClientWidth     =   8970
   LinkTopic       =   "Form1"
   ScaleHeight     =   7110
   ScaleWidth      =   8970
   Begin VB.TextBox text14 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2040
      TabIndex        =   29
      Top             =   3360
      Width           =   3135
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Cancel"
      Height          =   495
      Left            =   7320
      TabIndex        =   28
      Top             =   6360
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "OK"
      Height          =   495
      Left            =   2040
      TabIndex        =   27
      Top             =   6360
      Width           =   1335
   End
   Begin VB.TextBox Text13 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   6960
      TabIndex        =   25
      Top             =   3360
      Width           =   1695
   End
   Begin VB.TextBox Text12 
      Alignment       =   2  'Center
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   6360
      TabIndex        =   12
      Text            =   "0"
      Top             =   5760
      Width           =   495
   End
   Begin VB.HScrollBar HScroll1 
      Height          =   375
      Left            =   5640
      Max             =   23
      Min             =   -23
      TabIndex        =   11
      Top             =   5760
      Width           =   495
   End
   Begin VB.TextBox Text11 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   2040
      TabIndex        =   10
      Top             =   4920
      Width           =   6615
   End
   Begin VB.TextBox Text10 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   2040
      TabIndex        =   9
      Top             =   4200
      Width           =   6615
   End
   Begin VB.TextBox Text9 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   6960
      TabIndex        =   8
      Top             =   2640
      Width           =   1695
   End
   Begin VB.TextBox Text8 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   4920
      TabIndex        =   7
      Top             =   2640
      Width           =   975
   End
   Begin VB.TextBox Text7 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2040
      TabIndex        =   6
      Top             =   2640
      Width           =   975
   End
   Begin VB.TextBox Text6 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2040
      TabIndex        =   5
      Top             =   2040
      Width           =   6615
   End
   Begin VB.TextBox Text5 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   6960
      TabIndex        =   4
      Top             =   1440
      Width           =   1695
   End
   Begin VB.TextBox Text4 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   6960
      TabIndex        =   3
      Top             =   840
      Width           =   1695
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2040
      TabIndex        =   2
      Top             =   1440
      Width           =   3855
   End
   Begin VB.TextBox Text2 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2040
      TabIndex        =   1
      Top             =   840
      Width           =   3855
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   525
      Left            =   2040
      TabIndex        =   0
      Top             =   240
      Width           =   6615
   End
   Begin VB.Label Label14 
      Alignment       =   2  'Center
      Caption         =   "Camera"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   960
      TabIndex        =   30
      Top             =   3480
      Width           =   975
   End
   Begin VB.Label Label13 
      Alignment       =   2  'Center
      Caption         =   "Exposure time (Secs)"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   5400
      TabIndex        =   26
      Top             =   3360
      Width           =   1575
   End
   Begin VB.Label Label12 
      Caption         =   "Filters"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   6240
      TabIndex        =   24
      Top             =   2760
      Width           =   615
   End
   Begin VB.Label Label11 
      Alignment       =   2  'Center
      Caption         =   "Aperture (Sq ins)"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3720
      TabIndex        =   23
      Top             =   2640
      Width           =   975
   End
   Begin VB.Label Label10 
      Caption         =   "Time difference from UT (Hours)"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2040
      TabIndex        =   22
      Top             =   5760
      Width           =   3495
   End
   Begin VB.Label Label9 
      Caption         =   "Comments"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   840
      TabIndex        =   21
      Top             =   5040
      Width           =   1095
   End
   Begin VB.Label Label8 
      Caption         =   "History"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   1200
      TabIndex        =   20
      Top             =   4320
      Width           =   735
   End
   Begin VB.Label Label7 
      Alignment       =   2  'Center
      Caption         =   "F/L (Inches)"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   1080
      TabIndex        =   19
      Top             =   2640
      Width           =   855
   End
   Begin VB.Label Label6 
      Caption         =   "Telescope"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   840
      TabIndex        =   18
      Top             =   2160
      Width           =   1095
   End
   Begin VB.Label Label5 
      Caption         =   "Time"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   6360
      TabIndex        =   17
      Top             =   1560
      Width           =   495
   End
   Begin VB.Label Label4 
      Caption         =   "Date"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   6360
      TabIndex        =   16
      Top             =   960
      Width           =   495
   End
   Begin VB.Label Label3 
      Caption         =   "Origin"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1200
      TabIndex        =   15
      Top             =   1560
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "Observer"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   960
      TabIndex        =   14
      Top             =   960
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "Object"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   1200
      TabIndex        =   13
      Top             =   360
      Width           =   735
   End
End
Attribute VB_Name = "Fitsedit"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()

Fitstring1$ = Text1.Text + "'": lf1% = Len(Fitstring1$)
Fitstring2$ = Text2.Text + "'": lf2% = Len(Fitstring2$)
Fitstring3$ = Text3.Text + "'": lf3% = Len(Fitstring3$)
Fitstring4$ = Text4.Text + "'": lf4% = Len(Fitstring4$)
Fitstring5$ = Text5.Text + "'": lf5% = Len(Fitstring5$)
Fitstring6$ = Text6.Text + "'": lf6% = Len(Fitstring6$)
Fitstring7$ = Text7.Text + "'": lf7% = Len(Fitstring7$)
Fitstring8$ = Text8.Text + "'": lf8% = Len(Fitstring8$)
Fitstring9$ = Text9.Text + "'": lf9% = Len(Fitstring9$)
Fitstring10$ = Text10.Text + "'": lf10% = Len(Fitstring10$)
Fitstring11$ = Text11.Text + "'": lf11% = Len(Fitstring11$)
Fitstring12$ = Text12.Text + "'": lf12% = Len(Fitstring12$)
Fitstring13$ = Text13.Text + "'": lf13% = Len(Fitstring13$)
Fitstring14$ = text14.Text + "'": lf14% = Len(Fitstring14$)

simple$ = "SIMPLE  =                    T"
bitpix$ = "BITPIX  =                   16"
naxis$ = "NAXIS   =                    2"
naxis1$ = "NAXIS1  =                  752"
naxis2$ = "NAXIS2  =                  580"
bzero$ = "BZERO   =              32768.0"
bscale$ = "BSCALE  =                  1.0"
object$ = "OBJECT  =  ''                 "
telescop$ = "TELESCOP=  ''                 "
observer$ = "OBSERVER=  ''                 "
instrume$ = "INSTRUME=  ''                 "
dateobs$ = "DATE-OBS=  'dd/mm/yy'         "
origin$ = "ORIGIN  =  ''                 "
history$ = "HISTORY =  ''                 "
comment$ = "COMMENT =  ''                 "

For n& = 1 To 2880: Fitsarray(n&) = Asc(" "): Next n&
For n& = 1 To 30: Fitsarray(n&) = Asc(Mid$(simple$, n&, 1)): Next n&
p& = 1
For n& = 81 To 110: Fitsarray(n&) = Asc(Mid$(bitpix$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 161 To 190: Fitsarray(n&) = Asc(Mid$(naxis$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 241 To 270: Fitsarray(n&) = Asc(Mid$(naxis1$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 321 To 350: Fitsarray(n&) = Asc(Mid$(naxis2$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 401 To 430: Fitsarray(n&) = Asc(Mid$(bzero$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 481 To 510: Fitsarray(n&) = Asc(Mid$(bscale$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 561 To 573: Fitsarray(n&) = Asc(Mid$(object$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 573 To (572 + lf1%): Fitsarray(n&) = Asc(Mid$(Fitstring1$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 641 To 653: Fitsarray(n&) = Asc(Mid$(telescop$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 653 To (652 + lf6%): Fitsarray(n&) = Asc(Mid$(Fitstring6$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 721 To 732: Fitsarray(n&) = Asc(Mid$(observer$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 733 To (732 + lf2%): Fitsarray(n&) = Asc(Mid$(Fitstring2$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 801 To 812: Fitsarray(n&) = Asc(Mid$(instrume$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 813 To (812 + lf14%): Fitsarray(n&) = Asc(Mid$(Fitstring14$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 881 To 893: Fitsarray(n&) = Asc(Mid$(dateobs$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 894 To (893 + lf4%): Fitsarray(n&) = Asc(Mid$(Fitstring4$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 961 To 973: Fitsarray(n&) = Asc(Mid$(origin$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 974 To (973 + lf3%): Fitsarray(n&) = Asc(Mid$(Fitstring3$, p&, 1)): p& = p& + 1: Next n&
p& = 1
For n& = 1041 To 1070: Fitsarray(n&) = Asc(Mid$(history$, p&, 1)): p& = p& + 1: Next n&

Open "c:\vb6\mx9v2\fitshead" For Binary As #1
For x% = 1 To 2880
Put #1, , Fitsarray(x%)
Next x%
Close #1

End Sub

Private Sub HScroll1_Change()
Text12.Text = HScroll1.Value
End Sub
