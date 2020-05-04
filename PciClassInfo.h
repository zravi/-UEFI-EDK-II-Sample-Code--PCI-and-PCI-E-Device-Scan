#ifndef _PCI_CLASS_INFO_H_
#define _PCI_CLASS_INFO_H_
 
typedef struct _PCI_CLASSCODETABLE
{
 UINT8   BaseClass;
 UINT8   SubClass;
 UINT8  ProgIf;
 UINT16  *BaseDesc;
 UINT16  *SubDesc;
 UINT16  *ProgDesc;
}PCI_CLASSCODETABLE, *PPCI_CLASSCODETABLE;
 
PCI_CLASSCODETABLE PciClassCodeTable [] =
{
 { 0x00, 0x00, 0x00, L"Pre-2.0 PCI", L"Non-VGA",L"" } ,
 { 0x00, 0x01, 0x00, L"Pre-2.0 PCI", L"VGA Compatible", L"" } ,
 
 { 0x01, 0x00, 0x00, L"Mass Storage", L"SCSI", L"" } ,
 { 0x01, 0x01, 0x00, L"Mass Storage", L"IDE", L"" } ,
 { 0x01, 0x02, 0x00, L"Mass Storage", L"Floppy", L"" } ,
 { 0x01, 0x03, 0x00, L"Mass Storage", L"IPI", L"" } ,
 { 0x01, 0x04, 0x00, L"Mass Storage", L"RAID", L"" } ,
 { 0x01, 0x05, 0x20, L"Mass Storage", L"ATA controller with single DMA", L"" } , 
 { 0x01, 0x05, 0x30, L"Mass Storage", L"ATA controller with chained DMA", L"" } ,
 { 0x01, 0x06, 0x00, L"Mass Storage", L"Vendor specific", L"" } ,
 { 0x01, 0x06, 0x01, L"Mass Storage", L"AHCI 1.0", L"" } ,
 { 0x01, 0x07, 0x00, L"Mass Storage", L"Serial Attached SCSI", L"" } ,
 { 0x01, 0x08, 0x00, L"Mass Storage", L"NVM", L"" } ,
 { 0x01, 0x80, 0x00, L"Mass Storage", L"Other", L"" } ,
 
 { 0x02, 0x00, 0x00, L"Network Controller", L"Ethernet", L"" } ,
 { 0x02, 0x01, 0x00, L"Network Controller", L"Token Ring", L"" } ,
 { 0x02, 0x02, 0x00, L"Network Controller", L"FDDI", L"" } ,
 { 0x02, 0x03, 0x00, L"Network Controller", L"ATM", L"" } ,
 { 0x02, 0x04, 0x00, L"Network Controller", L"ISDN", L"" } ,
 { 0x02, 0x05, 0x00, L"Network Controller", L"WorldFip", L"" } ,
 { 0x02, 0x06, 0x00, L"Network Controller", L"PICMG 2.14 Nulti Computing", L"" } ,
 { 0x02, 0x80, 0x00, L"Network Controller", L"Other", L"" } ,
 
 { 0x03, 0x00, 0x00, L"Display Controller", L"PC Compatible", L"VGA" } ,
 { 0x03, 0x00, 0x01, L"Display Controller", L"PC Compatible", L"8514" } ,
 { 0x03, 0x01, 0x00, L"Display Controller", L"XGA", L"" } ,
 { 0x03, 0x02, 0x00, L"Display Controller", L"3D Controller", L"" } ,
 { 0x03, 0x80, 0x00, L"Display Controller", L"Other", L"" } ,
 
 { 0x04, 0x00, 0x00, L"Multimedia Device", L"Video", L"" } ,
 { 0x04, 0x01, 0x00, L"Multimedia Device", L"Audio", L"" } ,
 { 0x04, 0x02, 0x00, L"Multimedia Device", L"Computer Telephony Device", L"" } ,
 { 0x04, 0x03, 0x00, L"Multimedia Device", L"Audio Device", L"" } ,
 { 0x04, 0x80, 0x00, L"Multimedia Device", L"Other", L"" } ,
 
 { 0x05, 0x00, 0x00, L"Memory Controller", L"RAM", L"" } ,
 { 0x05, 0x01, 0x00, L"Memory Controller", L"Flash", L"" } ,
 { 0x05, 0x80, 0x00, L"Memory Controller", L"Other", L"" } ,
 
 { 0x06, 0x00, 0x00, L"Bridge Device", L"Host Bridge", L"" } ,
 { 0x06, 0x01, 0x00, L"Bridge Device", L"ISA Bridge", L"" } ,
 { 0x06, 0x02, 0x00, L"Bridge Device", L"EISA Bridge", L"" } ,
 { 0x06, 0x03, 0x00, L"Bridge Device", L"MCA Bridge", L"" } ,
 { 0x06, 0x04, 0x00, L"Bridge Device", L"PCI-to-PCI Bridge", L"" } ,
 { 0x06, 0x04, 0x01, L"Bridge Device", L"PCI-to-PCI Bridge", L"Subtractive Decode" } ,
 { 0x06, 0x05, 0x00, L"Bridge Device", L"PCMCIA Bridge", L"" } ,
 { 0x06, 0x06, 0x00, L"Bridge Device", L"NuBus Bridge", L"" } ,
 { 0x06, 0x07, 0x00, L"Bridge Device", L"CardBus Bridge", L"" } ,
 { 0x06, 0x08, 0x00, L"Bridge Device", L"RACEway Bridge", L"" } ,
 { 0x06, 0x09, 0x40, L"Bridge Device", L"PCI-to-PCI Bridge", L"Primary" } ,
 { 0x06, 0x09, 0x80, L"Bridge Device", L"PCI-to-PCI Bridge", L"Secondary" } ,
 { 0x06, 0x0A, 0x00, L"Bridge Device", L"InfiniBrand-to-PCI Host Bridge", L"" } ,
 { 0x06, 0x80, 0x00, L"Bridge Device", L"Other", L"" } ,
 
 { 0x07, 0x00, 0x00, L"Simple Communications", L"Serial", L"Generic XT Compatible" } ,
 { 0x07, 0x00, 0x01, L"Simple Communications", L"Serial", L"16450 Compatible" } ,
 { 0x07, 0x00, 0x02, L"Simple Communications", L"Serial", L"16550 Compatible" } ,
 { 0x07, 0x00, 0x03, L"Simple Communications", L"Serial", L"16650 Compatible" } ,
 { 0x07, 0x00, 0x04, L"Simple Communications", L"Serial", L"16750 Compatible" } ,
 { 0x07, 0x00, 0x05, L"Simple Communications", L"Serial", L"16850 Compatible" } ,
 { 0x07, 0x00, 0x06, L"Simple Communications", L"Serial", L"16950 Compatible" } ,
 { 0x07, 0x01, 0x00, L"Simple Communications", L"Parallel", L"Standard" } ,
 { 0x07, 0x01, 0x01, L"Simple Communications", L"Parallel", L"Bi-Directional" } ,
 { 0x07, 0x01, 0x02, L"Simple Communications", L"Parallel", L"ECP 1.X Compliant" } ,
 { 0x07, 0x01, 0x03, L"Simple Communications", L"Parallel", L"IEEE 1284 Controller" } ,
 { 0x07, 0x01, 0xFE, L"Simple Communications", L"Parallel", L"IEEE 1284 Target Device" } ,
 { 0x07, 0x02, 0x00, L"Simple Communications", L"Multiport Serial Controller", L"" } ,
 { 0x07, 0x03, 0x00, L"Simple Communications", L"Generic Modem", L"" } ,
 { 0x07, 0x03, 0x01, L"Simple Communications", L"Hayes Compatible Modem", L"16450 Compatible" } ,
 { 0x07, 0x03, 0x02, L"Simple Communications", L"Hayes Compatible Modem", L"16550 Compatible" } ,
 { 0x07, 0x03, 0x03, L"Simple Communications", L"Hayes Compatible Modem", L"16650 Compatible" } ,
 { 0x07, 0x03, 0x04, L"Simple Communications", L"Hayes Compatible Modem", L"16750 Compatible" } ,
 { 0x07, 0x04, 0x00, L"Simple Communications", L"IEEE 488.1/2 (GPIB)", L"" } ,
 { 0x07, 0x05, 0x00, L"Simple Communications", L"Smart Card", L"" } ,
 { 0x07, 0x80, 0x02, L"Simple Communications", L"Other", L"" } ,
 
 { 0x08, 0x00, 0x00, L"Base Systems Peripheral", L"PIC (Programmable Interrupt Controller)", L"Generic 8259" } ,
 { 0x08, 0x00, 0x01, L"Base Systems Peripheral", L"PIC (Programmable Interrupt Controller)", L"ISA" } ,
 { 0x08, 0x00, 0x02, L"Base Systems Peripheral", L"PIC (Programmable Interrupt Controller)", L"PCI" } ,
 { 0x08, 0x00, 0x10, L"Base Systems Peripheral", L"I/O APIC Interrupt Controller", L"" } ,
 { 0x08, 0x00, 0x20, L"Base Systems Peripheral", L"I/O(x) APIC Interrupt Controller", L"" } ,
 { 0x08, 0x01, 0x00, L"Base Systems Peripheral", L"DMA (Direct Memory Access)", L"Generic 8259" } ,
 { 0x08, 0x01, 0x01, L"Base Systems Peripheral", L"DMA (Direct Memory Access)", L"ISA" } ,
 { 0x08, 0x01, 0x02, L"Base Systems Peripheral", L"DMA (Direct Memory Access)", L"EISA" } ,
 { 0x08, 0x02, 0x00, L"Base Systems Peripheral", L"System Timer", L"Generic 8259" } ,
 { 0x08, 0x02, 0x01, L"Base Systems Peripheral", L"System Timer", L"ISA" } ,
 { 0x08, 0x02, 0x02, L"Base Systems Peripheral", L"System Timer", L"EISA" } ,
 { 0x08, 0x03, 0x00, L"Base Systems Peripheral", L"RTC (Real Time Clock)", L"Generic" } ,
 { 0x08, 0x03, 0x01, L"Base Systems Peripheral", L"RTC (Real Time Clock)", L"ISA" } ,
 { 0x08, 0x04, 0x00, L"Base Systems Peripheral", L"Generic PCI Hot-Plug Controller", L"" } ,
 { 0x08, 0x05, 0x00, L"Base Systems Peripheral", L"SD Host Controller", L"" } ,
 { 0x08, 0x06, 0x00, L"Base Systems Peripheral", L"IOMMU", L"" } ,
 { 0x08, 0x80, 0x00, L"Base Systems Peripheral", L"Other", L"" } ,
 
 { 0x09, 0x00, 0x00, L"Input Device", L"Keyboard", L"" } ,
 { 0x09, 0x01, 0x00, L"Input Device", L"Digitizer (Pen)", L"" } ,
 { 0x09, 0x02, 0x00, L"Input Device", L"Mouse", L"" } ,
 { 0x09, 0x03, 0x00, L"Input Device", L"Scanner", L"" } ,
 { 0x09, 0x04, 0x00, L"Input Device", L"Gameport", L"Generic" } ,
 { 0x09, 0x04, 0x01, L"Input Device", L"Gameport", L"Legacy" } ,
 { 0x09, 0x80, 0x00, L"Input Device", L"Other", L"" } ,
 
 { 0x0A, 0x00, 0x00, L"Docking Station", L"Generic", L"" } ,
 { 0x0A, 0x80, 0x00, L"Docking Station", L"Other", L"" } ,
 
 { 0x0B, 0x00, 0x00, L"Processor", L"i386", L"" } ,
 { 0x0B, 0x01, 0x00, L"Processor", L"i486", L"" } ,
 { 0x0B, 0x02, 0x00, L"Processor", L"Pentium", L"" } ,
 { 0x0B, 0x10, 0x00, L"Processor", L"Alpha", L"" } ,
 { 0x0B, 0x20, 0x00, L"Processor", L"Power PC", L"" } ,
 { 0x0B, 0x30, 0x00, L"Processor", L"MIPS", L"" } ,
 { 0x0B, 0x40, 0x00, L"Processor", L"Co-processor", L"" } ,
 
 { 0x0C, 0x00, 0x00, L"Serial Bus", L"Firewire (IEEE 1394)", L"Generic" } ,
 { 0x0C, 0x00, 0x10, L"Serial Bus", L"Firewire (IEEE 1394)", L"OHCI" } ,
 { 0x0C, 0x01, 0x00, L"Serial Bus", L"ACCESS.bus", L"" } ,
 { 0x0C, 0x02, 0x00, L"Serial Bus", L"SSA (Serial Storage Archetecture)", L"" } ,
 { 0x0C, 0x03, 0x00, L"Serial Bus", L"USB controller", L"UHCI" } ,
 { 0x0C, 0x03, 0x10, L"Serial Bus", L"USB controller", L"OHCI" } ,
 { 0x0C, 0x03, 0x20, L"Serial Bus", L"USB controller", L"EHCI" } ,
 { 0x0C, 0x03, 0x30, L"Serial Bus", L"USB controller", L"XHCI" } ,
 { 0x0C, 0x03, 0x30, L"Serial Bus", L"USB controller", L"Unspecified" } ,
 { 0x0C, 0x03, 0xFE, L"Serial Bus", L"USB controller", L"USB Device" } ,
 { 0x0C, 0x04, 0x00, L"Serial Bus", L"Fibre Channel", L"" } ,
 { 0x0C, 0x05, 0x00, L"Serial Bus", L"SMBus", L"" } ,
 { 0x0C, 0x06, 0x00, L"Serial Bus", L"InfiniBand", L"" } ,
 { 0x0C, 0x07, 0x00, L"Serial Bus", L"IPMI SMIC Interface", L"" } ,
 { 0x0C, 0x08, 0x00, L"Serial Bus", L"SERCOS Interface", L"" } ,
 { 0x0C, 0x09, 0x00, L"Serial Bus", L"CANBUS", L"" } ,
 
 { 0x0D, 0x00, 0x00, L"Wireless Controllers", L"iRDA Compatible Controller", L""},
 { 0x0D, 0x01, 0x00, L"Wireless Controllers", L"Consumer IR Controller", L""},
 { 0x0D, 0x10, 0x00, L"Wireless Controllers", L"RF Controller", L""},
 { 0x0D, 0x11, 0x00, L"Wireless Controllers", L"Bluetooth Controller", L""},
 { 0x0D, 0x12, 0x00, L"Wireless Controllers", L"Broadband Controller", L""},
 { 0x0D, 0x20, 0x00, L"Wireless Controllers", L"Ethernet Controller (802.11a)", L""},
 { 0x0D, 0x21, 0x00, L"Wireless Controllers", L"Ethernet Controller (802.11b)", L""},
 { 0x0D, 0x80, 0x00, L"Wireless Controllers", L"Other Wireless Controller", L""},
 
 { 0x0E, 0x00, 0x00, L"Intelligent I/O Controllers", L"I20 Architecture", L""},
 
 { 0x0F, 0x01, 0x00, L"Satellite Communication", L"TV Controller", L""},
 { 0x0F, 0x02, 0x00, L"Satellite Communication", L"Audio Controller", L""},
 { 0x0F, 0x03, 0x00, L"Satellite Communication", L"Video Controller", L""},
 { 0x0F, 0x04, 0x00, L"Satellite Communication", L"Data Controller", L""},
 
 { 0x10, 0x00, 0x00, L"Encryption/Decryption", L"Network and Computing Encrpytion/Decryption", L""},
 { 0x10, 0x10, 0x00, L"Encryption/Decryption", L"Entertainment Encrpytion/Decryption", L""},
 { 0x10, 0x80, 0x00, L"Encryption/Decryption", L"Other Encrpytion/Decryption", L""},
 
 { 0x11, 0x00, 0x00, L"Data Acquisition & Signal Processing", L"DPIO Modules", L""},
 { 0x11, 0x01, 0x00, L"Data Acquisition & Signal Processing", L"Performance Counters", L""},
 { 0x11, 0x10, 0x00, L"Data Acquisition & Signal Processing", L"Communications Syncrhonization", L""},
 { 0x11, 0x20, 0x00, L"Data Acquisition & Signal Processing", L"Signal processing Management", L""},
 { 0x11, 0x80, 0x00, L"Data Acquisition & Signal Processing", L"Signal Processing Controller", L""},
 
 { 0xFF, 0x00, 0x00, L"Unknown", L"Device Does Not Fit In Class Codes", L"UDF" } ,
};
 
// Use this value for loop control during searching:
#define PCI_CLASSCODETABLE_LEN  (sizeof(PciClassCodeTable) / sizeof(PCI_CLASSCODETABLE))
 
#endif