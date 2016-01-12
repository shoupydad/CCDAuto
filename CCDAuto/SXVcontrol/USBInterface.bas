Attribute VB_Name = "AccessIODevice"
                                                                                                                                                                                                Private Declare Function GetTickCount Lib "kernel32" () As Long
       



Function OpenUSBinterfaces(NameOfDevice$) As Boolean

   Dim Guid(1) As Guid
   Dim DeviceInterfaceData As Device_Interface_Data
   Dim FunctionClassDeviceData As Device_Interface_Detail
   Dim Device As Integer, Interface As Integer, i As Integer
   Dim PnPHandle As Long
   Dim BytesReturned As Long
   Dim Success As Boolean, Openned As Boolean
   Dim DeviceName As String
   Dim Buffer1(256) As Byte
    
   BytesReturnedPtr& = VarPtr(BytesReturned&)
   BufferPtr& = VarPtr(Buffer1(0))
      
   'Initialize the GUID array
   Call HidD_GetHidGuid(Guid(0).Data0)
   
   'This is the Guid for the BlockIO interface
   
   With Guid(1)
        .Data0 = &H606377C1
        .Data1 = &H2270
        .Data2 = &H11D4
        .Data3(0) = &HBF
        .Data3(1) = &HD8
        .Data3(2) = &H0
        .Data3(3) = &H20
        .Data3(4) = &H78
        .Data3(5) = &H12
        .Data3(6) = &HF5
        .Data3(7) = &HD5
    End With
        
'Open the BlockIO interface
Interface = 1
'Get a handle for the PnP node and request currently active devices

          PnPHandle = SetupDiGetClassDevs(Guid(Interface).Data0, 0, 0, &H12)
          
          If (PnPHandle = -1) Then ErrorExit ("Could not attach to PnP node")
          
          DeviceInterfaceData.cbsize = Len(DeviceInterfaceData)
   
'Look for a maximum of 20 devices
      'Handle(Interface) = -1
  
v$ = "0"
p$ = "0"
For Device = 0 To 19

'Is there a device at this table entry?
          Success = SetupDiEnumDeviceInterfaces(PnPHandle&, 0, Guid(Interface).Data0, _
          Device, DeviceInterfaceData.cbsize)
DoEvents
             If (Success <> 0) Then
             
'There is a device here, get its name
             FunctionClassDeviceData.cbsize = 5
             
             Success = SetupDiGetDeviceInterfaceDetail(PnPHandle&, DeviceInterfaceData.cbsize, _
             FunctionClassDeviceData.cbsize, 256, BytesReturned&, 0)
             
             If (Success = 0) Then ErrorExit ("Could not find the system name for this device")
            
             Name$ = "": i% = 0
            
             Do While FunctionClassDeviceData.DataPath(i%) <> 0
             Name$ = Name$ + Chr$(FunctionClassDeviceData.DataPath(i%))
             i% = i% + 1
             Loop
             
             vd& = InStr(Name$, "vid")
             pd& = InStr(Name$, "pid")
             
             v$ = Mid$(Name$, vd& + 4, 4)
             p$ = Mid$(Name$, pd& + 4, 4)
                          'MsgBox "PID = " + Str$(p$)
             
             If v$ = "1278" Then If p$ = "0115" Then camname$ = "SXV-H5": GoTo searchend
             If v$ = "1278" Then If p$ = "0119" Then camname$ = "SXV-H9": GoTo searchend
             If v$ = "1278" Then If p$ = "0319" Then camname$ = "SXV-H9C": GoTo searchend
             
             If v$ = "1278" Then If p$ = "0105" Then camname$ = "SXV-M5": GoTo searchend
             If v$ = "1278" Then If p$ = "0305" Then camname$ = "SXV-M5C": GoTo searchend
             
             If v$ = "1278" Then If p$ = "0107" Then camname$ = "SXV-M7": GoTo searchend
             If v$ = "1278" Then If p$ = "0307" Then camname$ = "SXV-M7C": GoTo searchend
             If v$ = "1278" Then If p$ = "0109" Then camname$ = "SXV-M9": GoTo searchend
            
             
             If v$ = "1278" Then If p$ = "0325" Then camname$ = "SXV-M25C": GoTo searchend
             If v$ = "1278" Then If p$ = "0125" Then camname$ = "SXV-M25C": GoTo searchend
             
             If v$ = "1278" Then If p$ = "0100" Then camname$ = "Generic SXV camera": GoTo searchend
             If v$ = "1278" Then If p$ = "0200" Then camname$ = "USB2 interface module for MX ": GoTo searchend
             If v$ = "1278" Then If p$ = "1010" Then GoTo searchend
             

             If v$ = "04B4" Then If p$ = "8613" Then camname$ = "Empty Cypress USB2 chip": GoTo searchend
             

             
             End If
             
Next Device

MsgBox "VID = " + Str$(v$) + ", PID = " + Str$(p$)
MsgBox "Sorry, no SXV cameras found": CloseHandle (PnPHandle): OpenUSBinterfaces = False: GoTo USB_end
                        
searchend:
'Can now open this device
            Dim sa As Security_Attributes
            Handle(Interface) = CreateFile(Name$, &HC0000000, 3, sa, 3, 0, 0)

            BlockIOHandle& = Handle(Interface)
                      
            If Handle(Interface) = -1 Then MsgBox "Could not open BlockIO device": CloseHandle (PnPHandle): OpenUSBinterfaces = False: GoTo USB_end
            MsgBox "Starlight Xpress " + camname$ + " camera found, VID = " + v$ + ", PID = " + p$ + ", Handle = " + Str$(Handle(Interface))
            
            OpenUSBinterfaces = True

USB_end:
DoEvents
 'Stop
End Function

Public Sub ReadUSBdevice(BufferPtr&, ByteCount&)
' This subroutine "reads" from an opened USB device
' The routine gets an Input Report from the USB device and returns the data

If ByteCount& > 254 Then ErrorExit ("Maximum ByteCount for ReadUSBdevice is 254")
If ByteCount& < 1 Then ErrorExit ("Minimum ByteCount for ReadUSBdevice is 1")
Success = ReadFile(HidHandle&, AddressFor(ReportBuffer(0)), ByteCount& + 1, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get an Input Report")
Call CopyBuffer(AddressFor(ReportBuffer(1)), BufferPtr&, BytesReturned& - 1)
'Status% = Buffer1(0)
End Sub

Public Sub WriteUSBdevice(BufferPtr&, ByteCount&)
' This subroutine "writes" to an opened USB device
' Copy the user buffer into a local buffer so that a ReportID (=0) may be prepended
' The first byte will contain the ReportID (=0)

If ByteCount& > 254 Then ErrorExit ("Maximum ByteCount for WriteUSBdevice is 254")
Call CopyBuffer(BufferPtr&, AddressFor(ReportBuffer(1)), ByteCount&)
ReportBuffer(0) = 0 ' ReportID
Success = WriteFile(HidHandle&, AddressFor(ReportBuffer(0)), ByteCount& + 1, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write an Output Report")
End Sub

Public Sub CloseUSBdevice()
' This subroutine closes the USB device that we have been using
Call CloseHandle(BlockIOHandle&)
End Sub

Public Sub ErrorExit(Reason$)
ErrorCode = GetLastError()
Call MsgBox(Reason$, vbCritical)
Stop
End Sub

Public Sub SendBlock()
 
    Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
                     
    If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")
                     
End Sub
                
Public Sub Echo()   'send random sequence and check for its return

a1 = Int(Rnd * 255) + 1
a2 = Int(Rnd * 255) + 1
a3 = Int(Rnd * 255) + 1
a4 = Int(Rnd * 255) + 1

CommandBlock(0) = 64
CommandBlock(1) = 0
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 4
CommandBlock(7) = 0
CommandBlock(8) = a1
CommandBlock(9) = a2
CommandBlock(10) = a3
CommandBlock(11) = a4

ByteCount& = 12     'command block size 8 + data byte block size 4

Call SendBlock

ByteCount& = 4      'read back the 4 bytes

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)

MsgBox "Echo of byte string = " + Str$(ReportBuffer(0)) + Str$(ReportBuffer(1)) + Str$(ReportBuffer(2)) + Str$(ReportBuffer(3))

End Sub
            
Public Sub Wiper()  'Dumps the charge in all of the CCD pixels

CommandBlock(0) = 64
CommandBlock(1) = 1
CommandBlock(2) = 0    'don't clear the registers
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock

End Sub
          
Public Sub Clearvert()  'Clears the vertical and horizontal registers of the CCD

CommandBlock(0) = 64
CommandBlock(1) = 1
CommandBlock(2) = 8    'clear all the registers
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
Beep
DoEvents
End Sub

Public Sub Clearreg()  'Clears the vertical and horizontal registers of the CCD

CommandBlock(0) = 64
CommandBlock(1) = 1
CommandBlock(2) = 128    'clear the vertical registers
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
'Beep
DoEvents
End Sub

Public Sub Reader1()    'Moves the odd pixel charge into the vertical registers

CommandBlock(0) = 64
CommandBlock(1) = 2
CommandBlock(2) = 1    'read odd field
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
End Sub

Public Sub Reader2()    'Moves the even pixel charge into the vertical registers

CommandBlock(0) = 64
CommandBlock(1) = 2
CommandBlock(2) = 2    'read even field
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
End Sub

Public Sub Reader3()    'Moves even + odd pixel charge into the vertical registers

CommandBlock(0) = 64
CommandBlock(1) = 2
CommandBlock(2) = 3    'read both fields
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
End Sub

Public Sub ReceiveBlock()   'Downloads an image field

If Bin% = 0 Then BinH& = 2: BinV& = 1: Readcount& = bin2read&
If Bin% = 1 Then BinH& = 1: BinV& = 1: Readcount& = binread&
If Bin% = 4 Then BinH& = 4: BinV& = 2: Readcount& = bin4read&
If Bin% = 11 Then BinH& = 1: BinV& = 1: Readcount& = bin1read&  'HX mode
If Bin% = 22 Then BinH& = 2: BinV& = 2: Readcount& = bin2read&  'HX mode
If Bin% = 44 Then BinH& = 4: BinV& = 4: Readcount& = bin4read&  'HX mode
If Bin% = 10 Then BinH& = 1: BinV& = 1: Readcount& = bin1read&  'HX25 bin1x1 mode
If Bin% = 20 Then BinH& = 4: BinV& = 1: Readcount& = bin2read&  'HX25 bin2x2 mode
If Bin% = 40 Then BinH& = 8: BinV& = 2: Readcount& = bin4read&  'HX25 bin4x4 mode

'command block
CommandBlock(0) = 64
CommandBlock(1) = 2         'read camera data
CommandBlock(2) = 3         'even + odd field
CommandBlock(3) = 0
CommandBlock(4) = 0         'main camera
CommandBlock(5) = 0
CommandBlock(6) = 14        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = 0
CommandBlock(9) = 0
CommandBlock(10) = 0
CommandBlock(11) = 0
CommandBlock(12) = LSwidth&
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&
CommandBlock(15) = MSheight&
CommandBlock(16) = BinH&
CommandBlock(17) = BinV&
CommandBlock(18) = Ex4$
CommandBlock(19) = Ex3$
CommandBlock(20) = Ex2$
CommandBlock(21) = Ex1$

ByteCount& = 22             'command block + parameter block size 22

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")

If Expinterval& > 1000 Then
Endcount& = GetTickCount + Expinterval&
MainMenu.Countdowntxt.Text = "Exposing"
DoEvents
Do While GetTickCount < Endcount&
Remainder& = (Endcount& - GetTickCount) / 1000
MainMenu.Countdowntxt.Text = Format$(Remainder&, "   0.0")
If Remainder& = 4 Then Call Clearvert
If Terminate% = 1 Then Exit Sub
DoEvents
Loop
End If

MainMenu.Countdowntxt.Text = "Reading"
DoEvents
ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

showimage:
MainMenu.Countdowntxt.Text = "Finished"

End Sub

Public Sub ReceiveOddBlock()   'Downloads an odd lines image field
'LSwidth& = 184: MSwidth& = 11: LSheight& = 232: MSheight& = 3
BinH& = 1: BinV& = 1: Readcount& = binread& '6112512

'command block
CommandBlock(0) = 64
CommandBlock(1) = 2         'read camera data
CommandBlock(2) = 1         'odd field
CommandBlock(3) = 0
CommandBlock(4) = 0         'main camera
CommandBlock(5) = 0
CommandBlock(6) = 14        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = 0
CommandBlock(9) = 0
CommandBlock(10) = 0
CommandBlock(11) = 0
CommandBlock(12) = LSwidth&        '3000 pixels
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&       '1000 lines
CommandBlock(15) = MSheight&
CommandBlock(16) = BinH&
CommandBlock(17) = BinV&
CommandBlock(18) = Ex4$
CommandBlock(19) = Ex3$
CommandBlock(20) = Ex2$
CommandBlock(21) = Ex1$

ByteCount& = 22             'command block + parameter block size 22

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")

If Expinterval& > 1000 Then
Endcount& = GetTickCount + Expinterval& - 1000
Do While GetTickCount < Endcount&
Remainder& = (Endcount& - GetTickCount) / 1000
MainMenu.Countdowntxt.Text = Format$(Remainder&, "   0.0")
If Remainder& = 10 Then If Clearcount% = 0 Then Call Clearvert
If Remainder& < 5 Then If Clearcount% = 0 Then Call Clearvert ': Clearcount% = 1
If Terminate% = 1 Then Exit Sub
DoEvents
Loop
End If
MainMenu.Countdowntxt.Text = "Field1"
DoEvents
ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

showimage:
DoEvents

End Sub

Public Sub ReceiveEvenBlock()   'Downloads an even lines image field
BinH& = 1: BinV& = 1: Readcount& = binread&

'command block
CommandBlock(0) = 64
CommandBlock(1) = 2         'read camera data
CommandBlock(2) = 2         'even field
CommandBlock(3) = 0
CommandBlock(4) = 0         'main camera
CommandBlock(5) = 0
CommandBlock(6) = 14        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = 0
CommandBlock(9) = 0
CommandBlock(10) = 0
CommandBlock(11) = 0
CommandBlock(12) = LSwidth&        '3000 pixels
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&       '1000 lines
CommandBlock(15) = MSheight&
CommandBlock(16) = BinH&
CommandBlock(17) = BinV&
CommandBlock(18) = Ex4$
CommandBlock(19) = Ex3$
CommandBlock(20) = Ex2$
CommandBlock(21) = Ex1$

ByteCount& = 22             'command block + parameter block size 22

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")

If Expinterval& > 1000 Then
Endcount& = GetTickCount + Expinterval&
MainMenu.Countdowntxt.Text = "Exposing"
DoEvents
Do While GetTickCount < Endcount&
Remainder& = (Endcount& - GetTickCount) / 1000
MainMenu.Countdowntxt.Text = Format$(Remainder&, "   0.0")
If Remainder& = 10 Then If Clearcount% = 0 Then Call Clearvert
If Remainder& < 5 Then If Clearcount% = 0 Then Call Clearvert ': Clearcount% = 1
If Terminate% = 1 Then Exit Sub
DoEvents
Loop
End If
MainMenu.Countdowntxt.Text = "Field2"
DoEvents
ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

showimage:
MainMenu.Countdowntxt.Text = "Finished"

End Sub

Public Sub ReceiveBlock2()   'Downloads an image using external exposure timing

If Bin% = 0 Then BinH& = 2: BinV& = 1: Readcount& = bin2read&
If Bin% = 1 Then BinH& = 1: BinV& = 1: Readcount& = binread&
If Bin% = 11 Then BinH& = 1: BinV& = 1: Readcount& = bin1read&  'HX mode
If Bin% = 22 Then BinH& = 2: BinV& = 2: Readcount& = bin2read&  'HX mode
If Bin% = 44 Then BinH& = 4: BinV& = 4: Readcount& = bin4read&  'HX mode

'command block
CommandBlock(0) = 64
CommandBlock(1) = 3         'read camera data (external exposure timing)
CommandBlock(2) = 3         'even + odd field
CommandBlock(3) = 0
CommandBlock(4) = 0         'select main camera
CommandBlock(5) = 0
CommandBlock(6) = 10        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = xoffset_L
CommandBlock(9) = xoffset_H
CommandBlock(10) = yoffset_L
CommandBlock(11) = yoffset_H
CommandBlock(12) = LSwidth&
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&
CommandBlock(15) = MSheight&
CommandBlock(16) = BinH&
CommandBlock(17) = BinV&

ByteCount& = 18             'command block + parameter block size 18

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")

ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

End Sub

Public Sub ReceiveEmptyBlock()   'Downloads the vertical register contents field using external exposure timing

Readcount& = bin4read&

'command block
CommandBlock(0) = 64
CommandBlock(1) = 3         'read camera data (external exposure timing)
CommandBlock(2) = 0         'no pixels
CommandBlock(3) = 0
CommandBlock(4) = 0         'select main camera
CommandBlock(5) = 0
CommandBlock(6) = 10        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = xoffset_L
CommandBlock(9) = xoffset_H
CommandBlock(10) = yoffset_L
CommandBlock(11) = yoffset_H
CommandBlock(12) = LSwidth&
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&
CommandBlock(15) = MSheight&
CommandBlock(16) = 4 'BinH&
CommandBlock(17) = 4 'BinV&

ByteCount& = 18             'command block + parameter block size 18

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")
MainMenu.Countdowntxt.Text = "Field1"
DoEvents

ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")
Beep
End Sub

Public Sub ReceiveOddBlock2()   'Downloads an odd lines image field using external exposure timing

'LSheight& = 232: MSheight& = 3: LSwidth& = 184: MSwidth& = 11
BinH& = 1: BinV& = 1: Readcount& = binread&

'command block
CommandBlock(0) = 64
CommandBlock(1) = 3         'read camera data (external exposure timing)
CommandBlock(2) = 1         'odd
CommandBlock(3) = 0
CommandBlock(4) = 0         'select main camera
CommandBlock(5) = 0
CommandBlock(6) = 10        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = xoffset_L
CommandBlock(9) = xoffset_H
CommandBlock(10) = yoffset_L
CommandBlock(11) = yoffset_H
CommandBlock(12) = LSwidth&
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&
CommandBlock(15) = MSheight&
CommandBlock(16) = BinH&
CommandBlock(17) = BinV&

ByteCount& = 18             'command block + parameter block size 18

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")
MainMenu.Countdowntxt.Text = "Field1"
DoEvents

ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

End Sub

Public Sub ReceiveEvenBlock2()   'Downloads an even lines image field using external exposure timing

'LSheight& = 232: MSheight& = 3: LSwidth& = 184: MSwidth& = 11
BinH& = 1: BinV& = 1: Readcount& = binread&

'command block
CommandBlock(0) = 64
CommandBlock(1) = 3         'read camera data (external exposure timing)
CommandBlock(2) = 2         'even
CommandBlock(3) = 0
CommandBlock(4) = 0         'select main camera
CommandBlock(5) = 0
CommandBlock(6) = 10        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = xoffset_L
CommandBlock(9) = xoffset_H
CommandBlock(10) = yoffset_L
CommandBlock(11) = yoffset_H
CommandBlock(12) = LSwidth&
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&
CommandBlock(15) = MSheight&
CommandBlock(16) = BinH&
CommandBlock(17) = BinV&

ByteCount& = 18             'command block + parameter block size 18

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")
MainMenu.Countdowntxt.Text = "Field2"
DoEvents

ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")
MainMenu.Countdowntxt.Text = "Finished"
DoEvents

End Sub

Public Sub ReceiveSubframe()   'Downloads a portion of an image field

If Bin% = 0 Then BinH& = 1: BinV& = 1
If Bin% = 1 Then BinH& = 2: BinV& = 2
If Bin% = 2 Then BinH& = 3: BinV& = 3
If Bin% = 3 Then BinH& = 4: BinV& = 4

'command block
CommandBlock(0) = 64
CommandBlock(1) = 2         'read camera data
CommandBlock(2) = 3         'even + odd field
CommandBlock(3) = 0
CommandBlock(4) = 0         'main camera
CommandBlock(5) = 0
CommandBlock(6) = 14        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = xoffset_L
CommandBlock(9) = xoffset_H
CommandBlock(10) = yoffset_L
CommandBlock(11) = yoffset_H
CommandBlock(12) = LSwidth&
CommandBlock(13) = MSwidth&
CommandBlock(14) = LSheight&
CommandBlock(15) = MSheight&
CommandBlock(16) = BinH&
CommandBlock(17) = BinV&
CommandBlock(18) = Ex4$
CommandBlock(19) = Ex3$
CommandBlock(20) = Ex2$
CommandBlock(21) = Ex1$

ByteCount& = 22             'command block + parameter block size 22

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")

If Expinterval& > 1000 Then
Endcount& = GetTickCount + Expinterval&
Do While GetTickCount < Endcount&
Remainder& = (Endcount& - GetTickCount) / 1000
MainMenu.Countdowntxt.Text = Format$(Remainder&, "   0.0")
If Remainder& < 2 Then If Clearcount% = 0 Then Call Clearvert: Clearcount% = 1
If Terminate% = 1 Then Exit Sub
DoEvents
Loop
End If

MainMenu.Countdowntxt.Text = "Reading"
DoEvents

ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

End Sub
          
Public Sub Guideclear()  'Clears the vertical and horizontal registers of the guide CCD

CommandBlock(0) = 64
CommandBlock(1) = 1
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 1
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
End Sub

Public Sub GuideRead()    'Moves the pixel charges into the vertical registers of the guider

CommandBlock(0) = 64
CommandBlock(1) = 2
CommandBlock(2) = 1
CommandBlock(3) = 0
CommandBlock(4) = 1
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
End Sub

Public Sub ReceiveGuide()   'Downloads a guider field
Readcount& = 145000

'command block
CommandBlock(0) = 64
CommandBlock(1) = 3         'read guider data (external exposure timing)
CommandBlock(2) = 3         'even + odd field
CommandBlock(3) = 0
CommandBlock(4) = 1         'select guider
CommandBlock(5) = 0
CommandBlock(6) = 10        'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = 0 'xoffset_L
CommandBlock(9) = 0 'xoffset_H
CommandBlock(10) = 0 'yoffset_L
CommandBlock(11) = 0 'yoffset_H
CommandBlock(12) = 244
CommandBlock(13) = 1
CommandBlock(14) = 34
CommandBlock(15) = 1
CommandBlock(16) = 1
CommandBlock(17) = 1

ByteCount& = 18             'command block + parameter block size 18

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)
If (Success = 0) Then ErrorExit ("Could not write a BlockIO Output Report - Try re-booting USB device")

ByteCount& = Readcount&

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

showimage:

End Sub

Public Sub SetCCD()         'set to CCD type

'command block
CommandBlock(0) = 64
CommandBlock(1) = 7         'set CCD device
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 9         'parameter block length
CommandBlock(7) = 0
                        
'parameter block
CommandBlock(8) = 24
CommandBlock(9) = 40
CommandBlock(10) = 240
CommandBlock(11) = 2
CommandBlock(12) = 7
CommandBlock(13) = 2
CommandBlock(14) = 34
CommandBlock(15) = 1
CommandBlock(16) = 115
CommandBlock(17) = 6
CommandBlock(18) = 115
CommandBlock(19) = 6
CommandBlock(20) = 3
CommandBlock(21) = 3

ByteCount& = 22             'command block + parameter block size = 22

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)

End Sub


Public Sub GetCCD()         'read CCD type

'command block
CommandBlock(0) = 64
CommandBlock(1) = 8         'get CCD device
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 9         'parameter block length
CommandBlock(7) = 0
                        
ByteCount& = 8

Call SendBlock

ByteCount& = 16

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

Hfporch% = ReportBuffer(0)
Hbporch% = ReportBuffer(1)
CCDWidth% = ReportBuffer(2) + ReportBuffer(3) * 256
Vfporch% = ReportBuffer(4)
Vbporch% = ReportBuffer(5)
CCDHeight% = ReportBuffer(6) + ReportBuffer(7) * 256
Pixwidth! = (ReportBuffer(8) + ReportBuffer(9) * 256) / 256
Pixheight! = (ReportBuffer(10) + ReportBuffer(11) * 256) / 256
Magic% = ReportBuffer(12)
Colours% = ReportBuffer(13)
Serial% = ReportBuffer(14)
Star% = ReportBuffer(15)

End Sub

Public Sub Reset()  'reset CCD status

CommandBlock(0) = 64
CommandBlock(1) = 6
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
End Sub

Public Sub SetSTAR()  'drive STAR2K

CommandBlock(0) = 64
CommandBlock(1) = 9
CommandBlock(2) = S2K
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock
End Sub

Public Sub Getserial()  'read data about serial port

CommandBlock(0) = 64
CommandBlock(1) = 13
CommandBlock(2) = 1     'check for data waiting
CommandBlock(3) = 0
CommandBlock(4) = 0     'port 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock

ByteCount& = 2

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")


End Sub

Public Sub Writeserial()  'send data to serial port

CommandBlock(0) = 64
CommandBlock(1) = 10
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = Le% 'Llow%
CommandBlock(7) = 0 'Lhigh%

CommandBlock(8) = Ch1% '65
CommandBlock(9) = Ch2%  '66
CommandBlock(10) = Ch3% '67
CommandBlock(11) = Ch4% '68

ByteCount& = 8 + Le%   'command block size

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)

End Sub

Public Sub Readserial()  'get data from serial port

CommandBlock(0) = 64
CommandBlock(1) = 11
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 1
CommandBlock(5) = 0
CommandBlock(6) = 4 'Llow%
CommandBlock(7) = 0 'Lhigh%

ByteCount& = 8     'command block size 8

Call SendBlock

'ByteCount& = Llow% + Lhigh% * 256
ByteCount& = 4

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)

End Sub

Public Sub Getversion()  'read data about firmware

CommandBlock(0) = 64
CommandBlock(1) = 255
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock

ByteCount& = 4

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")

End Sub


Public Sub Getmodel()  'read data about camera model

CommandBlock(0) = 192
CommandBlock(1) = 14
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 2
CommandBlock(7) = 0

ByteCount& = 8     'command block size 8

Call SendBlock

ByteCount& = 2

Success = ReadFile(BlockIOHandle&, AddressFor(ReportBuffer(0)), ByteCount&, BytesReturned&, 0)
If (Success = 0) Then ErrorExit ("Could not get a BlockIO Input Report - Try re-booting USB device")
MsgBox "Camera model number is " + Str$(ReportBuffer(1)) + Str$(ReportBuffer(0))
End Sub

Public Sub WriteModel()  'send camera model data to eeprom

CommandBlock(0) = 64
CommandBlock(1) = 14
CommandBlock(2) = model%
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8   'command block size

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)

End Sub

Public Sub WriteEeprom()  'send data to eeprom

CommandBlock(0) = 64
CommandBlock(1) = 15
CommandBlock(2) = 9
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = 0
CommandBlock(7) = 0

ByteCount& = 8   'command block size

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)

End Sub


Public Sub ReadEeprom()  'get data from eeprom

CommandBlock(0) = 192
CommandBlock(1) = 15
CommandBlock(2) = 0
CommandBlock(3) = 0
CommandBlock(4) = 0
CommandBlock(5) = 0
CommandBlock(6) = Le% 'Llow%
CommandBlock(7) = 0

CommandBlock(8) = Ch1%
CommandBlock(9) = Ch2%
CommandBlock(10) = Ch3%
CommandBlock(11) = Ch4%

ByteCount& = 8   'command block size

Success = WriteFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesWritten&, 0)

ByteCount& = Le%

Success = ReadFile(BlockIOHandle&, AddressFor(CommandBlock(0)), ByteCount&, BytesReturned&, 0)


End Sub


