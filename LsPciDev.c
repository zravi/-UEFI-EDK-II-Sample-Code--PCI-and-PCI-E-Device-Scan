#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/PciIo.h>
#include <Protocol/PciRootBridgeIo.h>
#include <IndustryStandard/Pci22.h>
#include <Library/ShellLib.h>
#include <Library/UefiShellDebug1CommandsLib/Pci.h>
#include "PciVenInfo.h"
#include "PciClassInfo.h"
 
#define DID_OFFSET          2
#define Rev_ID_OFFSET       8
#define CLASS_CODE_OFFSET   9
#define HEADER_TYPE_OFFSET  0xE
#define CAP_POINTER         0x34
#define PCIE_DEVICE         0x10
 
UINT32 __inline SerachVenTable(UINT32 LowIndex,UINT32 HighIndex,PCI_VENTABLE SortedArray[],UINT16 TargetVID)
{   UINT32 Low,High,Mid;
    Low = LowIndex;
    High = HighIndex;
    Mid = (Low + High)/2;
 
    if(SortedArray[Mid].VenId == TargetVID)
        return Mid;
    else{
        if(TargetVID > SortedArray[Mid].VenId)
            Low = Mid + 1;
        else
            High = Mid - 1;
        if(High < Low)
            return 0xffffffff; //PCI_Ven_Info.h should be updated.
        else
   return SerachVenTable(Low,High,SortedArray,TargetVID);
    }
}
 
UINT32 __inline SerachPciClassTable(UINT32 LowIndex,UINT32 HighIndex,PCI_CLASSCODETABLE SortedArray[],UINT32 TargetClassCode)
{   UINT32 Low,High,Mid,ToClassCode;
    Low = LowIndex;
    High = HighIndex;
    Mid = (Low + High)/2;
 ToClassCode = 0x00000000 | PciClassCodeTable[Mid].BaseClass << 16 |
                  PciClassCodeTable[Mid].SubClass << 8 | PciClassCodeTable[Mid].ProgIf;
    if(ToClassCode == TargetClassCode)
        return Mid;
    else{
        if(TargetClassCode > ToClassCode)
            Low = Mid + 1;
        else
            High = Mid - 1;
        if(High < Low)
            return 0xffffffff; //PciClassInfo.h should be updated.
        else
   return SerachPciClassTable(Low,High,SortedArray,TargetClassCode);
    }
}
 
BOOLEAN __inline IsRoot(EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,UINTN PciAddress){
 UINT8 CFGValue8;
  
 PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint8,PciAddress | HEADER_TYPE_OFFSET,1,&CFGValue8);
 if(CFGValue8 & PCI_BIT_0)
  return TRUE;
 else
  return FALSE;
}
 
BOOLEAN __inline IsPCIE(EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo, UINTN PciAddress){
 UINT8 CFGValue8 = 0xff;
 UINT16 Offset = CAP_POINTER;
 UINTN TempPciAddress = PciAddress | Offset;
  
 PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint8,TempPciAddress,1,&CFGValue8);
 Offset = CFGValue8;
 while(CFGValue8){
  TempPciAddress = PciAddress | Offset;
  PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint8,TempPciAddress,1,&CFGValue8);
  if(CFGValue8 != PCIE_DEVICE){
   TempPciAddress += 1;
   PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint8,TempPciAddress,1,&CFGValue8);
   Offset = CFGValue8;
  }
  else
   return TRUE;
 }
 return FALSE;
}
 
VOID __inline PrintDeviceInfo(EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo,UINTN PciAddress){
 UINT16 VID,DID;
 UINT32 ClassCode,Result;
  
 PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint16,PciAddress,1,&VID);
 PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint16,PciAddress | DID_OFFSET,1,&DID);
 PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint32,PciAddress | Rev_ID_OFFSET,1,&ClassCode);
 ClassCode = ClassCode >> 8; //get class code
  
 if(IsPCIE(PciRootBridgeIo,PciAddress))
  Print(L"PCIE "); 
 if(IsRoot(PciRootBridgeIo,PciAddress))
  Print(L"Root Bridge ");
  
 Result = SerachVenTable(0,PCI_VENTABLE_LEN-1,PciVenTable,VID);
 if(Result != 0xffffffff)
  Print(L"%s (%04x) ",PciVenTable[Result].VenStr,VID);
 else
  Print(L"Unknown Vendor (%4x)",VID);
   
 Print(L"Device ID: %04x Class Code: %06x\n",DID,ClassCode); 
 Result = SerachPciClassTable(0,PCI_CLASSCODETABLE_LEN-1,PciClassCodeTable,ClassCode);
 if(Result != 0xffffffff){
  Print(L"Name: %s %s %s\n",PciClassCodeTable[Result].BaseDesc,\
  PciClassCodeTable[Result].SubDesc,PciClassCodeTable[Result].ProgDesc);
   
 }
 else{
  Print(L"Name: %s %s %s\n",PciClassCodeTable[PCI_CLASSCODETABLE_LEN-1].BaseDesc,\
  PciClassCodeTable[PCI_CLASSCODETABLE_LEN-1].SubDesc,PciClassCodeTable[PCI_CLASSCODETABLE_LEN-1].ProgDesc);
 }
}
 
VOID __inline ScanPCIDevices(EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo){
 UINTN Bus,Fun,Dev;
 UINTN PciAddress;
 UINT16 VID;
 UINT8 CFGValue8;
 CFGValue8 = 0;
  
 for(Bus = 0; Bus <= PCI_MAX_BUS;Bus++){
  for(Dev = 0;Dev <= PCI_MAX_DEVICE;Dev++){
   for(Fun = 0;Fun <= PCI_MAX_FUNC;Fun++){
    PciAddress = CALC_EFI_PCI_ADDRESS(Bus,Dev,Fun,0);
    PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint16,PciAddress,1,&VID);
     
    if(VID == 0xFFFF)
     continue;
     
    PrintDeviceInfo(PciRootBridgeIo,PciAddress);
      
    if(Fun == 0){
     //is multi-function?
     PciRootBridgeIo->Pci.Read(PciRootBridgeIo,EfiPciWidthUint8,PciAddress| HEADER_TYPE_OFFSET,1,&CFGValue8);
     if((CFGValue8 & PCI_BIT_7) == 0)
      break; //no
    }    
   }
  }
 }
}
 
EFI_STATUS
EFIAPI
UefiMain (
          IN EFI_HANDLE        ImageHandle,
          IN EFI_SYSTEM_TABLE  *SystemTable
          )
{    
 EFI_STATUS        Status;
 UINTN                      HandleCount;
 EFI_HANDLE                 *HandleBuffer;
 UINTN                      i;
 EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *PciRootBridgeIo;
  
 //A lot of M.B. not includes Shell 2.0 into the UEFI so far.
 //Thus, this App will crash when calling beLow protocol under old shell environment.
 //gEfiShellProtocol->EnablePageBreak();
 //How to solve it: compile shell 2.0 (ShellPkg) and 
 //execute the shell.efi under your old shell.
 //However, there are a lot of bug in the Shell 2.0 (ShellPkg) now.
  
 //Method 1: Using EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
 Status = gBS->LocateHandleBuffer (
    ByProtocol,
    &gEfiPciRootBridgeIoProtocolGuid,
    NULL,
    &HandleCount,
    &HandleBuffer
   );
 ASSERT_EFI_ERROR(Status);
  
 //Method 2: Using EFI_PCI_IO_PROTOCOL
 //Note: this sample only shows you how to use the method 1.
  
 Print(L"Number of PCI Root Bridge: %d\n",HandleCount);
 
 for (i = 0; i < HandleCount; i++) {
  
  Status = gBS->HandleProtocol (HandleBuffer[i], &gEfiPciRootBridgeIoProtocolGuid, &PciRootBridgeIo);
  ASSERT_EFI_ERROR(Status); 
  ScanPCIDevices(PciRootBridgeIo);
 }
  
    return EFI_SUCCESS;
}