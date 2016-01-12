Attribute VB_Name = "APIcalls"

' This declares the data types and system calls required to access the Windows operating system
'
' Define the GUID that will allow an application program to rendezvous with this driver
' {606377C1-2270-11d4-BFD8-00207812F5D5}

Public Type Guid: Data0 As Long: Data1 As Integer: Data2 As Integer: Data3(7) As Byte: End Type 'A GUID is 16 bytes long
'(&H606377c1, &H2270, &H11d4, &Hbf, &Hd8, &H0, &H20, &H78, &H12, &Hf5, &Hd5)
    
Public Type Security_Attributes: nLength As Long: lpSecurityDescriptor As Long: bInheritHandle As Long: End Type
      
Public Type Device_Interface_Data
cbsize As Long: InterfaceClassGuid As Guid: Flags As Long: ReservedPtr As Long: End Type
    
Public Type Device_Interface_Detail: cbsize As Long: DataPath(256) As Byte: End Type

Public Type ConfigurationDataType: cookie As Long: cbsize As Long: RingBuffersize As Long: End Type

Public Type HidD_Attributes
cbsize As Long: VendorID(1) As Byte: ProductID(1) As Byte: VersionNumber(1) As Byte: Pad(10) As Byte: End Type

'   Declare the functions from Dan Appleman's "Programmers Guide to the Win32 API"
Declare Function AddressFor Lib "apigid32.dll" Alias "agGetAddressForObject" (PassedByReference As Any) As Long

Declare Sub CopyBuffer Lib "apigid32.dll" Alias "agCopyData" (ByVal SourcePtr&, ByVal DestPtr&, ByVal ByteCount&)
'
'   Declare the API calls that we are using
Declare Sub HidD_GetHidGuid Lib "HID.dll" (GuidPtr&)

Declare Function RegCloseKey& Lib "advapi32.dll" (ByVal hKey As Long)

Declare Function RegSetValueEx& Lib "advapi32.dll" Alias "RegSetValueExA" _
(ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, ByVal _
dwType As Long, lpData As Byte, ByVal cbData As Long)

Declare Function RegQueryValueEx& Lib "advapi32.dll" Alias "RegQueryValueExA" _
(ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, _
lpType As Long, lpData As Any, lpcbData As Long)

Declare Function RegCreateKeyEx& Lib "advapi32.dll" Alias "RegCreateKeyExA" _
(ByVal hKey As Long, ByVal lpSubKey As String, ByVal Reserved As Long, ByVal _
lpClass As String, ByVal dwOptions As Long, ByVal samDesired As Long, _
lpSecurityAttributes As Security_Attributes, phkResult As Long, lpdwDisposition _
As Long)

Declare Function SetupDiGetClassDevs Lib "setupapi.dll" Alias "SetupDiGetClassDevsA" _
(GuidPtr&, ByVal EnumPtr&, ByVal HwndParent&, ByVal Flags&) As Long

Declare Function SetupDiEnumDeviceInterfaces Lib "setupapi.dll" _
(ByVal HANDLE&, ByVal InfoPtr&, GuidPtr&, ByVal MemberIndex&, InterfaceDataPtr&) As Boolean

Declare Function SetupDiGetDeviceInterfaceDetail Lib "setupapi.dll" Alias "SetupDiGetDeviceInterfaceDetailA" _
(ByVal HANDLE&, InterfaceDataPtr&, InterfaceDetailPtr&, ByVal DetailLength&, _
ReturnedLengthPtr&, ByVal DevInfoDataPtr&) As Boolean
 
Declare Function GetLastError Lib "kernel32" () As Long

Declare Function CreateFile Lib "kernel32" Alias "CreateFileA" _
(ByVal lpFileName$, ByVal dwDesiredAccess&, ByVal dwShareMode&, lpSecurityAttributes As Security_Attributes, _
 ByVal dwCreationDisposition&, ByVal dwFlagsAndAttributes&, ByVal hTemplateFile&) As Long

Declare Sub CloseHandle Lib "kernel32" (ByVal HandleToClose As Long)

Declare Function ReadFile Lib "kernel32" _
(ByVal HANDLE&, ByVal BufferPtr&, ByVal ByteCount&, BytesReturnedPtr&, ByVal OverlappedPtr&) As Long

Declare Function WriteFile Lib "kernel32" _
(ByVal HANDLE&, ByVal BufferPtr&, ByVal ByteCount&, BytesReturnedPtr&, ByVal OverlappedPtr&) As Long

Declare Function DeviceIoControl Lib "kernel32" _
(ByVal hDevice&, ByVal dwIoControlCode&, lpInBuffer&, ByVal nInBufferSize&, _
 lpOutBuffer&, ByVal nOutBufferSize&, lpBytesReturned&, lpOverlapped&) As Long
 
Declare Function HidD_GetPreparsedData Lib "HID.dll" (ByVal HANDLE&, ByVal BufferPtr&) As Long
Declare Function HidD_GetAttributes Lib "HID.dll" (ByVal HANDLE&, BufferPtr&) As Long
Declare Function HidD_GetManufacturerString Lib "HID.dll" (ByVal HANDLE&, ByVal BufferPtr&, ByVal Length&) As Long
Declare Function HidD_GetProductString Lib "HID.dll" (ByVal HANDLE&, ByVal BufferPtr&, ByVal Length&) As Long
Declare Function HidD_GetSerialNumberString Lib "HID.dll" (ByVal HANDLE&, ByVal BufferPtr&, ByVal Length&) As Long
Declare Function HidD_GetIndexedString Lib "HID.dll" (ByVal HANDLE&, ByVal index&, ByVal BufferPtr&, ByVal Length&) As Long
Declare Function HidD_GetConfiguration Lib "HID.dll" (ByVal HANDLE&, ByVal BufferPtr&, ByVal Length&) As Long
Declare Function HidD_SetConfiguration Lib "HID.dll" (ByVal HANDLE&, ByVal BufferPtr&, ByVal Length&) As Long
Declare Function HidD_GetPhysicalDescriptor Lib "HID.dll" (ByVal HANDLE&, ByVal BufferPtr&, ByVal Length&) As Long

