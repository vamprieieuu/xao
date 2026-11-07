typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned long long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef unsigned short    word;
typedef struct _s__RTTIBaseClassDescriptor _s__RTTIBaseClassDescriptor, *P_s__RTTIBaseClassDescriptor;

typedef struct _s__RTTIBaseClassDescriptor RTTIBaseClassDescriptor;

typedef RTTIBaseClassDescriptor *RTTIBaseClassDescriptor *32 __((image-base-relative));

typedef RTTIBaseClassDescriptor *32 __((image-base-relative)) *RTTIBaseClassDescriptor *32 __((image-base-relative)) *32 __((image-base-relative));

typedef struct PMD PMD, *PPMD;

struct PMD {
    int mdisp;
    int pdisp;
    int vdisp;
};

struct _s__RTTIBaseClassDescriptor {
    ImageBaseOffset32 pTypeDescriptor; // ref to TypeDescriptor (RTTI 0) for class
    dword numContainedBases; // count of extended classes in BaseClassArray (RTTI 2)
    struct PMD where; // member displacement structure
    dword attributes; // bit flags
    ImageBaseOffset32 pClassHierarchyDescriptor; // ref to ClassHierarchyDescriptor (RTTI 3) for class
};

typedef struct CLIENT_ID CLIENT_ID, *PCLIENT_ID;

struct CLIENT_ID {
    void *UniqueProcess;
    void *UniqueThread;
};

typedef struct _s__RTTIClassHierarchyDescriptor _s__RTTIClassHierarchyDescriptor, *P_s__RTTIClassHierarchyDescriptor;

typedef struct _s__RTTIClassHierarchyDescriptor RTTIClassHierarchyDescriptor;

struct _s__RTTIClassHierarchyDescriptor {
    dword signature;
    dword attributes; // bit flags
    dword numBaseClasses; // number of base classes (i.e. rtti1Count)
    RTTIBaseClassDescriptor *32 __((image-base-relative)) *32 __((image-base-relative)) pBaseClassArray; // ref to BaseClassArray (RTTI 2)
};

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory:31;
    dword DataIsDirectory:1;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef struct _s__RTTICompleteObjectLocator _s__RTTICompleteObjectLocator, *P_s__RTTICompleteObjectLocator;

struct _s__RTTICompleteObjectLocator {
    dword signature;
    dword offset; // offset of vbtable within class
    dword cdOffset; // constructor displacement offset
    ImageBaseOffset32 pTypeDescriptor; // ref to TypeDescriptor (RTTI 0) for class
    ImageBaseOffset32 pClassDescriptor; // ref to ClassHierarchyDescriptor (RTTI 3)
};

typedef struct _s__RTTICompleteObjectLocator RTTICompleteObjectLocator;

typedef struct exception exception, *Pexception;

struct exception { // PlaceHolder Class Structure
};

typedef longlong LONGLONG;

typedef struct _struct_20 _struct_20, *P_struct_20;

typedef ulong DWORD;

typedef long LONG;

struct _struct_20 {
    DWORD LowPart;
    LONG HighPart;
};

typedef char CHAR;

typedef CHAR *LPCSTR;

typedef union _LARGE_INTEGER _LARGE_INTEGER, *P_LARGE_INTEGER;

typedef union _LARGE_INTEGER LARGE_INTEGER;

typedef struct _struct_19 _struct_19, *P_struct_19;

struct _struct_19 {
    DWORD LowPart;
    LONG HighPart;
};

struct _struct_20 {
    DWORD LowPart;
    LONG HighPart;
};

union _LARGE_INTEGER {
    struct _struct_19 s;
    struct _struct_20 u;
    LONGLONG QuadPart;
};

typedef DWORD ACCESS_MASK;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef ulonglong UINT_PTR;

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME *LPFILETIME;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

typedef ushort WORD;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

struct HINSTANCE__ {
    int unused;
};

typedef struct HKEY__ HKEY__, *PHKEY__;

struct HKEY__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef DWORD *LPDWORD;

typedef struct HKEY__ *HKEY;

typedef HKEY *PHKEY;

typedef int BOOL;

typedef uchar BYTE;

typedef BYTE *LPBYTE;

typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY _IMAGE_RUNTIME_FUNCTION_ENTRY, *P_IMAGE_RUNTIME_FUNCTION_ENTRY;

struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
    ImageBaseOffset32 BeginAddress;
    dword EndAddress; // Apply ImageBaseOffset32 to see reference
    ImageBaseOffset32 UnwindInfoAddressOrData;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset:31;
    dword NameIsString:1;
};

typedef struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY IMAGE_LOAD_CONFIG_CODE_INTEGRITY, *PIMAGE_LOAD_CONFIG_CODE_INTEGRITY;

struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY {
    word Flags;
    word Catalog;
    dword CatalogOffset;
    dword Reserved;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 34404
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY64 IMAGE_LOAD_CONFIG_DIRECTORY64, *PIMAGE_LOAD_CONFIG_DIRECTORY64;

typedef enum IMAGE_GUARD_FLAGS {
    IMAGE_GUARD_CF_INSTRUMENTED=256,
    IMAGE_GUARD_CFW_INSTRUMENTED=512,
    IMAGE_GUARD_CF_FUNCTION_TABLE_PRESENT=1024,
    IMAGE_GUARD_SECURITY_COOKIE_UNUSED=2048,
    IMAGE_GUARD_PROTECT_DELAYLOAD_IAT=4096,
    IMAGE_GUARD_DELAYLOAD_IAT_IN_ITS_OWN_SECTION=8192,
    IMAGE_GUARD_CF_EXPORT_SUPPRESSION_INFO_PRESENT=16384,
    IMAGE_GUARD_CF_ENABLE_EXPORT_SUPPRESSION=32768,
    IMAGE_GUARD_CF_LONGJUMP_TABLE_PRESENT=65536,
    IMAGE_GUARD_RF_INSTRUMENTED=131072,
    IMAGE_GUARD_RF_ENABLE=262144,
    IMAGE_GUARD_RF_STRICT=524288,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_1=268435456,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_2=536870912,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_4=1073741824,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_8=2147483648
} IMAGE_GUARD_FLAGS;

struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY {
    word Flags;
    word Catalog;
    dword CatalogOffset;
    dword Reserved;
};

struct IMAGE_LOAD_CONFIG_DIRECTORY64 {
    dword Size;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword GlobalFlagsClear;
    dword GlobalFlagsSet;
    dword CriticalSectionDefaultTimeout;
    qword DeCommitFreeBlockThreshold;
    qword DeCommitTotalFreeThreshold;
    pointer64 LockPrefixTable;
    qword MaximumAllocationSize;
    qword VirtualMemoryThreshold;
    qword ProcessAffinityMask;
    dword ProcessHeapFlags;
    word CsdVersion;
    word DependentLoadFlags;
    pointer64 EditList;
    pointer64 SecurityCookie;
    pointer64 SEHandlerTable;
    qword SEHandlerCount;
    pointer64 GuardCFCCheckFunctionPointer;
    pointer64 GuardCFDispatchFunctionPointer;
    pointer64 GuardCFFunctionTable;
    qword GuardCFFunctionCount;
    enum IMAGE_GUARD_FLAGS GuardFlags;
    struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY CodeIntegrity;
    pointer64 GuardAddressTakenIatEntryTable;
    qword GuardAddressTakenIatEntryCount;
    pointer64 GuardLongJumpTargetTable;
    qword GuardLongJumpTargetCount;
    pointer64 DynamicValueRelocTable;
    pointer64 CHPEMetadataPointer;
    pointer64 GuardRFFailureRoutine;
    pointer64 GuardRFFailureRoutineFunctionPointer;
    dword DynamicValueRelocTableOffset;
    word DynamicValueRelocTableSection;
    word Reserved2;
    pointer64 GuardRFVerifyStackPointerFunctionPointer;
    dword HotPatchTableOffset;
    dword Reserved3;
    pointer64 EnclaveConfigurationPointer;
    pointer64 VolatileMetadataPointer;
    pointer64 GuardEHContinuationTable;
    qword GuardEHContinuationCount;
    pointer64 GuardXFGCheckFunctionPointer;
    pointer64 GuardXFGDispatchFunctionPointer;
    pointer64 GuardXFGTableDispatchFunctionPointer;
    pointer64 CastGuardOsDeterminedFailureMode;
    pointer64 GuardMemcpyFunctionPointer;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset:31;
    dword NameIsString:1;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_OPTIONAL_HEADER64 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    pointer64 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    qword SizeOfStackReserve;
    qword SizeOfStackCommit;
    qword SizeOfHeapReserve;
    qword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_NT_HEADERS64 IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

struct IMAGE_FILE_HEADER {
    word Machine; // 34404
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

struct IMAGE_OPTIONAL_HEADER64 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    pointer64 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    qword SizeOfStackReserve;
    qword SizeOfStackCommit;
    qword SizeOfHeapReserve;
    qword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

struct IMAGE_NT_HEADERS64 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER64 OptionalHeader;
};

typedef struct IMAGE_RESOURCE_DIR_STRING_U_8 IMAGE_RESOURCE_DIR_STRING_U_8, *PIMAGE_RESOURCE_DIR_STRING_U_8;

struct IMAGE_RESOURCE_DIR_STRING_U_8 {
    word Length;
    wchar16 NameString[4];
};

typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION, *PIMAGE_BASE_RELOCATION;

struct IMAGE_BASE_RELOCATION {
    dword VirtualAddress;
    dword SizeOfBlock;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct IMAGE_DIRECTORY_ENTRY_EXPORT IMAGE_DIRECTORY_ENTRY_EXPORT, *PIMAGE_DIRECTORY_ENTRY_EXPORT;

struct IMAGE_DIRECTORY_ENTRY_EXPORT {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    ImageBaseOffset32 Name;
    dword Base;
    dword NumberOfFunctions;
    dword NumberOfNames;
    ImageBaseOffset32 AddressOfFunctions;
    ImageBaseOffset32 AddressOfNames;
    ImageBaseOffset32 AddressOfNameOrdinals;
};

typedef int PMFN;

typedef struct _s_ThrowInfo _s_ThrowInfo, *P_s_ThrowInfo;

struct _s_ThrowInfo {
    uint attributes;
    PMFN pmfnUnwind;
    int pForwardCompat;
    int pCatchableTypeArray;
};

typedef struct TypeDescriptor TypeDescriptor, *PTypeDescriptor;

struct TypeDescriptor {
    void *pVFTable;
    void *spare;
    char name[0];
};

typedef struct _s_ThrowInfo ThrowInfo;

typedef LONG LSTATUS;

typedef ACCESS_MASK REGSAM;

typedef ulonglong uintptr_t;

typedef struct sockaddr sockaddr, *Psockaddr;

typedef ushort u_short;

struct sockaddr {
    u_short sa_family;
    char sa_data[14];
};

typedef struct WSAData WSAData, *PWSAData;

typedef struct WSAData WSADATA;

struct WSAData {
    WORD wVersion;
    WORD wHighVersion;
    ushort iMaxSockets;
    ushort iMaxUdpDg;
    char *lpVendorInfo;
    char szDescription[257];
    char szSystemStatus[129];
};

typedef UINT_PTR SOCKET;

typedef WSADATA *LPWSADATA;

typedef longlong __time64_t;

typedef ulonglong size_t;

typedef int errno_t;

typedef size_t rsize_t;



undefined DAT_18002c5f0;
undefined FUN_1800023a0;
undefined UNK_180004452;
undefined UNK_18000445d;
undefined FUN_1800023e0;
undefined UNK_1800049df;
undefined UNK_1800049ea;
undefined FUN_180002360;
pointer[2] vftable;
ulonglong DAT_180030500;
undefined DAT_180020a24;
undefined DAT_180020a25;
undefined DAT_180020a26;
undefined DAT_180020a27;
undefined DAT_180020a29;
undefined DAT_180020a2a;
undefined DAT_180020a2b;
undefined DAT_180020a2d;
undefined DAT_180020a2e;
undefined DAT_180020a2f;
undefined DAT_180029c25;
undefined DAT_180020a20;
undefined DAT_180020a21;
undefined DAT_180020a22;
undefined DAT_180020a23;
undefined LAB_18000ab20;
undefined DAT_18002c670;
undefined4 DAT_180020780;
undefined1 DAT_180029bd0;
undefined DAT_180014980;
undefined DAT_180029b70;
undefined4 DAT_180020920;
undefined4 DAT_180020924;
undefined4 DAT_180020928;
undefined4 DAT_18002092c;
undefined *PTR_s_0123456789abcdef_18002d000;
undefined DAT_180029b4c;
undefined8 UNK_180030642;
int DAT_180030654;
char DAT_180030638;
undefined DAT_18003063a;
undefined8 DAT_18003064a;
undefined1 DAT_180030639;
undefined1 DAT_180030652;
undefined DAT_180020900;
undefined DAT_180030630;
undefined DAT_18002d014;
undefined DAT_18002a060;
undefined DAT_18002a064;
undefined DAT_18002a068;
undefined DAT_18002a06c;
undefined DAT_18002a070;
undefined DAT_18002a074;
undefined DAT_18002a078;
undefined DAT_18002a07c;
undefined DAT_18002a080;
undefined DAT_18002a084;
undefined DAT_18002a088;
undefined DAT_18002a08c;
undefined DAT_18002a090;
undefined DAT_18002a094;
undefined DAT_18002a098;
undefined DAT_18002a09c;
undefined DAT_18002a0a0;
undefined DAT_18002a0a4;
undefined DAT_18002a0a8;
undefined DAT_18002a0ac;
undefined DAT_18002a0b0;
undefined UNK_18002a0b4;
undefined UNK_18002a0b8;
undefined UNK_18002a0bc;
undefined DAT_18002a0c0;
undefined UNK_18002a0c4;
undefined UNK_18002a0c8;
undefined UNK_18002a0cc;
undefined DAT_18002a0d0;
undefined DAT_18002a420;
undefined DAT_18002a430;
undefined DAT_180029f58;
undefined DAT_180029f30;
undefined DAT_180029f08;
undefined8 DAT_180030500;
undefined4 DAT_18002a040;
undefined4 DAT_18002acb0;
undefined DAT_18002ad80;
undefined UNK_18002ad88;
undefined UNK_18002ad90;
undefined UNK_18002ad98;
pointer[1] vftable;
uint UINT_180012bf4;
uint switchdataD_180012be0;
void *StackLimit;
uintptr_t DAT_180030500;
int DAT_180030688;
int DAT_180030664;
undefined DAT_180014270;
undefined DAT_180014278;
undefined DAT_180014280;
undefined DAT_180014288;
undefined DAT_18002c700;
undefined DAT_180030540;
undefined DAT_180030670;
undefined DAT_180030680;
void *DAT_180030690;
void *StackBase;
char DAT_180030699;
undefined DAT_1800306a0;
undefined DAT_1800306b0;
undefined DAT_1800306b8;
undefined DAT_1800306c8;
undefined8 UNK_1800306a8;
undefined8 UNK_1800306c0;
undefined1 DAT_180030698;
IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER_180000218;
undefined DAT_180000308;
undefined8 DAT_180030690;
char DAT_180030698;
undefined DAT_1800306e0;
undefined DAT_180030558;
undefined DAT_180030560;
uint DAT_1800306d4;
ulonglong DAT_180030568;
undefined DAT_180030550;
uint DAT_180030554;
undefined DAT_1800306d8;
int DAT_180030570;
undefined FUN_180012d20;

longlong * FUN_180001000(longlong *param_1,longlong param_2)

{
  *param_1 = param_2;
  memset(param_1 + 1,0,0x490);
  if (*param_1 == 0) {
    FUN_180001fc0(param_1);
  }
  return param_1;
}



void FUN_180001040(void)

{
  FUN_180001050();
  return;
}



void FUN_180001050(longlong *param_1)

{
  if (param_1[7] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Marker Suite",1);
  }
  if (param_1[8] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Marker Suite",2);
  }
  if (param_1[9] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Marker Suite",3);
  }
  if (param_1[0x13] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Suite",8);
  }
  if (param_1[0x14] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Suite",10);
  }
  if (param_1[6] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Stream Suite",0xb);
  }
  if (param_1[5] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Stream Suite",10);
  }
  if (param_1[4] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Stream Suite",9);
  }
  if (param_1[3] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Stream Suite",8);
  }
  if (param_1[0x15] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Stream Suite",7);
  }
  if (param_1[0x75] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Stream Suite",4);
  }
  if (param_1[0x16] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Dynamic Stream Suite",2);
  }
  if (param_1[0x17] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Dynamic Stream Suite",3);
  }
  if (param_1[0x18] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Dynamic Stream Suite",5);
  }
  if (param_1[1] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Keyframe Suite",5);
  }
  if (param_1[2] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Keyframe Suite",4);
  }
  if (param_1[0x19] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Keyframe Suite",3);
  }
  if (param_1[0x78] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Keyframe Suite",1);
  }
  if (param_1[10] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",9);
  }
  if (param_1[0xb] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",0xb);
  }
  if (param_1[0xc] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",0xe);
  }
  if (param_1[0xd] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",0xf);
  }
  if (param_1[0xe] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",0x12);
  }
  if (param_1[0xf] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",0x13);
  }
  if (param_1[0x10] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",0x15);
  }
  if (param_1[0x11] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",0x19);
  }
  if (param_1[0x1a] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Canvas Suite",10);
  }
  if (param_1[0x1b] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Canvas Suite",0xb);
  }
  if (param_1[0x1c] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Canvas Suite",0xd);
  }
  if (param_1[0x1d] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Canvas Suite",0xe);
  }
  if (param_1[0x1e] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Camera Suite",2);
  }
  if (param_1[0x1f] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Register Suite",6);
  }
  if (param_1[0x21] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Item View Suite",1);
  }
  if (param_1[0x23] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Item Suite",0xd);
  }
  if (param_1[0x24] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Item Suite",0xb);
  }
  if (param_1[0x25] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Item Suite",10);
  }
  if (param_1[0x26] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Item Suite",7);
  }
  if (param_1[0x27] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Item Suite",3);
  }
  if (param_1[0x42] != 0) {
    (**(code **)(*param_1 + 8))("AEGP PF Interface Suite",1);
  }
  if (param_1[0x43] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Math Suite",1);
  }
  if (param_1[0x44] != 0) {
    (**(code **)(*param_1 + 8))("PF AE Adv Time Suite",4);
  }
  if (param_1[0x45] != 0) {
    (**(code **)(*param_1 + 8))("PF Path Query Suite",1);
  }
  if (param_1[0x20] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Memory Suite",1);
  }
  if (param_1[0x46] != 0) {
    (**(code **)(*param_1 + 8))("PF Path Data Suite",1);
  }
  if (param_1[0x47] != 0) {
    (**(code **)(*param_1 + 8))("PF Param Utils Suite",3);
  }
  if (param_1[0x48] != 0) {
    (**(code **)(*param_1 + 8))("PF AE App Suite",6);
  }
  if (param_1[0x49] != 0) {
    (**(code **)(*param_1 + 8))("PF AE App Suite",7);
  }
  if (param_1[0x4a] != 0) {
    (**(code **)(*param_1 + 8))("PF AE App Suite",1);
  }
  if (param_1[0x4b] != 0) {
    (**(code **)(*param_1 + 8))("PF AE Adv App Suite",2);
  }
  if (param_1[0x28] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Light Suite",1);
  }
  if (param_1[0x29] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Light Suite",2);
  }
  if (param_1[0x2a] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Light Suite",3);
  }
  if (param_1[0x2b] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Effect Suite",1);
  }
  if (param_1[0x2c] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Effect Suite",2);
  }
  if (param_1[0x2d] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Effect Suite",3);
  }
  if (param_1[0x2e] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Effect Suite",4);
  }
  if (param_1[0x2f] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Effect Suite",5);
  }
  if (param_1[0x30] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Mask Suite",5);
  }
  if (param_1[0x31] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Mask Outline Suite",2);
  }
  if (param_1[0x32] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Mask Outline Suite",3);
  }
  if (param_1[0x33] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Mask Outline Suite",5);
  }
  if (param_1[0x34] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Command Suite",1);
  }
  if (param_1[0x35] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Utility Suite",7);
  }
  if (param_1[0x36] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Suite",1);
  }
  if (param_1[0x37] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Suite",2);
  }
  if (param_1[0x38] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Suite",3);
  }
  if (param_1[0x39] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Suite",5);
  }
  if (param_1[0x3a] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Suite",8);
  }
  if (param_1[0x3b] != 0) {
    (**(code **)(*param_1 + 8))("PF ANSI Suite",1);
  }
  if (param_1[0x3c] != 0) {
    (**(code **)(*param_1 + 8))("PF Handle Suite",2);
  }
  if (param_1[0x3d] != 0) {
    (**(code **)(*param_1 + 8))("PF Fill Matte Suite",2);
  }
  if (param_1[0x3e] != 0) {
    (**(code **)(*param_1 + 8))("PF World Transform Suite",1);
  }
  if (param_1[0x3f] != 0) {
    (**(code **)(*param_1 + 8))("AEGP QueryXform Suite",4);
  }
  if (param_1[0x40] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Composite Suite",4);
  }
  if (param_1[0x41] != 0) {
    (**(code **)(*param_1 + 8))("PF World Suite",1);
  }
  if (param_1[0x4c] != 0) {
    (**(code **)(*param_1 + 8))("AEGP IO In Suite",5);
  }
  if (param_1[0x4d] != 0) {
    (**(code **)(*param_1 + 8))("AEGP IO Out Suite",7);
  }
  if (param_1[0x50] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Queue Suite",1);
  }
  if (param_1[0x51] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Queue Item Suite",3);
  }
  if (param_1[0x52] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Output Module Suite",4);
  }
  if (param_1[0x53] != 0) {
    (**(code **)(*param_1 + 8))("AEGP File Import Manager Suite",3);
  }
  if (param_1[0x43] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Math Suite",1);
  }
  if (param_1[0x44] != 0) {
    (**(code **)(*param_1 + 8))("PF AE Adv Time Suite",4);
  }
  if (param_1[0x54] != 0) {
    (**(code **)(*param_1 + 8))("PF Sampling8 Suite",1);
  }
  if (param_1[0x55] != 0) {
    (**(code **)(*param_1 + 8))("PF Sampling16 Suite",1);
  }
  if (param_1[0x56] != 0) {
    (**(code **)(*param_1 + 8))("PF Iterate8 Suite",1);
  }
  if (param_1[0x57] != 0) {
    (**(code **)(*param_1 + 8))("PF iterate16 Suite",1);
  }
  if (param_1[0x58] != 0) {
    (**(code **)(*param_1 + 8))("PF iterateFloat Suite",1);
  }
  if (param_1[0x59] != 0) {
    (**(code **)(*param_1 + 8))("PF Iterate8 Suite",2);
  }
  if (param_1[0x5a] != 0) {
    (**(code **)(*param_1 + 8))("PF iterate16 Suite",2);
  }
  if (param_1[0x5b] != 0) {
    (**(code **)(*param_1 + 8))("PF iterateFloat Suite",2);
  }
  if (param_1[0x5c] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Collection Suite",2);
  }
  if (param_1[0x5d] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Text Document Suite",1);
  }
  if (param_1[0x5e] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Sound Data Suite",1);
  }
  if (param_1[0x61] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Text Layer Suite",1);
  }
  if (param_1[0x62] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Artisan Util Suite",1);
  }
  if (param_1[99] != 0) {
    (**(code **)(*param_1 + 8))("AEGP World Suite",2);
  }
  if (param_1[100] != 0) {
    (**(code **)(*param_1 + 8))("AEGP World Suite",3);
  }
  if (param_1[0x65] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Options Suite",1);
  }
  if (param_1[0x69] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Tracker Suite",1);
  }
  if (param_1[0x6a] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Tracker Utility Suite",1);
  }
  if (param_1[0x6b] != 0) {
    (**(code **)(*param_1 + 8))("AE Plugin Helper Suite2",2);
  }
  if (param_1[0x6c] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Suite",0xb);
  }
  if (param_1[0x6d] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Suite",0xc);
  }
  if (param_1[0x6e] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Suite",0xd);
  }
  if (param_1[0x6f] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Suite",0xe);
  }
  if (param_1[0x85] != 0) {
    (**(code **)(*param_1 + 8))("PF AE Adv Item Suite",1);
  }
  if (param_1[0x71] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Suite",5);
  }
  if (param_1[0x72] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Mask Suite",2);
  }
  if (param_1[0x73] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Mask Suite",6);
  }
  if (param_1[0x74] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Mask Suite",7);
  }
  if (param_1[0x76] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Comp Suite",4);
  }
  if (param_1[0x77] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Collection Suite",1);
  }
  if (param_1[0x79] != 0) {
    (**(code **)(*param_1 + 8))("PF AE Adv App Suite",1);
  }
  if (param_1[0x7a] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Utility Suite",3);
  }
  if (param_1[0x7b] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Options Suite",2);
  }
  if (param_1[0x66] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Render Options Suite",1);
  }
  if (param_1[0x67] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Layer Render Options Suite",2);
  }
  if (param_1[0x68] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Asyc Manager Suite",1);
  }
  if (param_1[0x7c] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Proj Suite",8);
  }
  if (param_1[0x7d] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Proj Suite",9);
  }
  if (param_1[0x7e] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Footage Suite",0xb);
  }
  if (param_1[0x7f] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Render Queue Item Suite",4);
  }
  if (param_1[0x80] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Utility Suite",10);
  }
  if (param_1[0x4f] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Persistent Data Suite",4);
  }
  if (param_1[0x4e] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Persistent Data Suite",3);
  }
  if (param_1[0x81] != 0) {
    (**(code **)(*param_1 + 8))("PF Color Settings Suite",5);
  }
  if (param_1[0x82] != 0) {
    (**(code **)(*param_1 + 8))("PF Color Settings Suite",4);
  }
  if (param_1[0x83] != 0) {
    (**(code **)(*param_1 + 8))("PF Color Settings Suite",3);
  }
  if (param_1[0x84] != 0) {
    (**(code **)(*param_1 + 8))("PF Color Settings Suite",1);
  }
  if (param_1[0x87] != 0) {
    (**(code **)(*param_1 + 8))("PF ColorParamSuite",1);
  }
  if (param_1[0x88] != 0) {
    (**(code **)(*param_1 + 8))("PF SamplingFloat Suite",1);
  }
  if (param_1[0x89] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Utility Suite",0xb);
  }
  if (param_1[0x8a] != 0) {
    (**(code **)(*param_1 + 8))("AEGP Utility Suite",0xd);
  }
  if (param_1[0x8b] != 0) {
    (**(code **)(*param_1 + 8))("PF Effect Custom UI Suite",1);
  }
  if (param_1[0x8c] != 0) {
    (**(code **)(*param_1 + 8))("PF Effect Custom UI Suite",2);
  }
  if (param_1[0x8d] != 0) {
    (**(code **)(*param_1 + 8))("PF Effect Custom UI Overlay Theme Suite",1);
  }
  if (param_1[0x8e] != 0) {
    (**(code **)(*param_1 + 8))("DRAWBOT Draw Suite",1);
  }
  if (param_1[0x8f] != 0) {
    (**(code **)(*param_1 + 8))("DRAWBOT Supplier Suite",1);
  }
  if (param_1[0x90] != 0) {
    (**(code **)(*param_1 + 8))("DRAWBOT Surface Suite",2);
  }
  if (param_1[0x91] != 0) {
    (**(code **)(*param_1 + 8))("DRAWBOT Path Suite",1);
  }
  if (param_1[0x92] == 0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x000180001fb6. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*param_1 + 8))("SP Suites Suite",2);
  return;
}



void FUN_180001fc0(void)

{
  undefined4 local_res10 [6];
  
  local_res10[0] = 0x204;
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_res10,(ThrowInfo *)&DAT_18002c5f0);
}



undefined8
FUN_180001fe0(longlong *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [96];
  
  puVar12 = auStack_a8;
  lVar10 = *param_1;
  lVar11 = param_1[1] - lVar10 >> 4;
  if (lVar11 == 0xfffffffffffffff) {
                    // WARNING: Subroutine does not return
    FUN_18000a1e0();
  }
  uVar9 = param_1[2] - lVar10 >> 4;
  if (uVar9 <= 0xfffffffffffffff - (uVar9 >> 1)) {
    uVar1 = lVar11 + 1;
    uVar9 = (uVar9 >> 1) + uVar9;
    uVar13 = uVar1;
    if (uVar1 <= uVar9) {
      uVar13 = uVar9;
    }
    if (uVar13 < 0x1000000000000000) {
      uVar9 = uVar13 * 0x10;
      if (uVar9 == 0) {
        puVar14 = (undefined8 *)0x0;
      }
      else if (uVar9 < 0x1000) {
        puVar14 = (undefined8 *)FUN_1800129b0();
        puVar12 = auStack_a8;
      }
      else {
        if (uVar9 + 0x27 <= uVar9) goto LAB_1800021aa;
        lVar11 = FUN_1800129b0(uVar9 + 0x27);
        puVar12 = auStack_a8;
        if (lVar11 == 0) {
          pcVar4 = (code *)swi(0x29);
          lVar11 = (*pcVar4)(5);
          puVar12 = auStack_a0;
        }
        puVar14 = (undefined8 *)(lVar11 + 0x27U & 0xffffffffffffffe0);
        puVar14[-1] = lVar11;
      }
      lVar10 = ((longlong)param_2 - lVar10 & 0xfffffffffffffff0U) + (longlong)puVar14;
      *(longlong *)(puVar12 + 0xb0) = lVar10;
      puVar2 = (undefined8 *)(lVar10 + 0x10);
      *(longlong **)(puVar12 + 0x30) = param_1;
      *(undefined8 **)(puVar12 + 0x38) = puVar14;
      *(ulonglong *)(puVar12 + 0x40) = uVar13;
      *(undefined8 **)(puVar12 + 0x48) = puVar2;
      *(undefined8 **)(puVar12 + 0x50) = puVar2;
      *(undefined8 *)(puVar12 + 0x20) = *(undefined8 *)(puVar12 + 0xd0);
      *(undefined8 *)(puVar12 + -8) = 0x1800020f9;
      FUN_180002f20(param_1,lVar10,param_3,param_4);
      puVar3 = (undefined8 *)param_1[1];
      puVar8 = (undefined8 *)*param_1;
      puVar7 = puVar14;
      if (param_2 == puVar3) {
        for (; puVar8 != puVar3; puVar8 = puVar8 + 2) {
          uVar5 = *puVar8;
          uVar6 = puVar8[1];
          *puVar8 = 0;
          puVar8[1] = 0;
          *puVar7 = uVar5;
          puVar7[1] = uVar6;
          puVar7 = puVar7 + 2;
        }
      }
      else {
        for (; puVar8 != param_2; puVar8 = puVar8 + 2) {
          uVar5 = *puVar8;
          uVar6 = puVar8[1];
          *puVar8 = 0;
          puVar8[1] = 0;
          *puVar7 = uVar5;
          puVar7[1] = uVar6;
          puVar7 = puVar7 + 2;
        }
        puVar3 = (undefined8 *)param_1[1];
        for (; param_2 != puVar3; param_2 = param_2 + 2) {
          uVar5 = *param_2;
          uVar6 = param_2[1];
          *param_2 = 0;
          param_2[1] = 0;
          *puVar2 = uVar5;
          puVar2[1] = uVar6;
          puVar2 = puVar2 + 2;
        }
      }
      *(undefined8 *)(puVar12 + -8) = 0x18000218a;
      FUN_18000a090(param_1,puVar14,uVar1,uVar13);
      return *(undefined8 *)(puVar12 + 0xb0);
    }
  }
LAB_1800021aa:
                    // WARNING: Subroutine does not return
  FUN_18000a140();
}



undefined8 * FUN_1800021b0(longlong *param_1,void *param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  void *pvVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined8 *_Dst;
  void *_Memory;
  undefined8 *unaff_RBX;
  undefined1 *puVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  size_t _Size;
  longlong lVar8;
  undefined8 *puVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar9 = (undefined8 *)*param_1;
  lVar8 = param_1[1] - (longlong)puVar9 >> 3;
  if (lVar8 == 0x1fffffffffffffff) {
                    // WARNING: Subroutine does not return
    FUN_18000a1e0();
  }
  uVar4 = param_1[2] - (longlong)puVar9 >> 3;
  if (0x1fffffffffffffff - (uVar4 >> 1) < uVar4) {
LAB_18000234e:
                    // WARNING: Subroutine does not return
    FUN_18000a140();
  }
  uVar1 = lVar8 + 1;
  uVar4 = (uVar4 >> 1) + uVar4;
  uVar7 = uVar1;
  if (uVar1 <= uVar4) {
    uVar7 = uVar4;
  }
  if (0x1fffffffffffffff < uVar7) goto LAB_18000234e;
  uVar4 = uVar7 * 8;
  if (uVar4 == 0) {
    unaff_RBX = (undefined8 *)0x0;
LAB_180002280:
    puVar9 = (undefined8 *)
             (((longlong)param_2 - (longlong)puVar9 & 0xfffffffffffffff8U) + (longlong)unaff_RBX);
    *puVar9 = *param_3;
    pvVar2 = (void *)*param_1;
    if (param_2 == (void *)param_1[1]) {
      _Size = param_1[1] - (longlong)pvVar2;
      _Dst = unaff_RBX;
      param_2 = pvVar2;
    }
    else {
      memcpy(unaff_RBX,pvVar2,(longlong)param_2 - (longlong)pvVar2);
      _Dst = puVar9 + 1;
      _Size = param_1[1] - (longlong)param_2;
    }
    puVar5 = auStack_38;
    puVar6 = auStack_38;
    memcpy(_Dst,param_2,_Size);
    pvVar2 = (void *)*param_1;
    if (pvVar2 == (void *)0x0) goto LAB_180002314;
    _Memory = pvVar2;
    if ((ulonglong)((param_1[2] - (longlong)pvVar2 >> 3) * 8) < 0x1000) goto LAB_180002309;
    _Memory = *(void **)((longlong)pvVar2 + -8);
    if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory))) goto LAB_180002302;
  }
  else {
    if (uVar4 < 0x1000) {
      unaff_RBX = (undefined8 *)FUN_1800129b0(uVar4);
      goto LAB_180002280;
    }
    if (uVar4 + 0x27 <= uVar4) goto LAB_18000234e;
    lVar8 = FUN_1800129b0();
    if (lVar8 != 0) {
      unaff_RBX = (undefined8 *)(lVar8 + 0x27U & 0xffffffffffffffe0);
      unaff_RBX[-1] = lVar8;
      goto LAB_180002280;
    }
LAB_180002302:
    _Memory = (void *)0x5;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar5 = auStack_30;
LAB_180002309:
    puVar6 = puVar5;
  }
  *(undefined8 *)(puVar6 + -8) = 0x180002314;
  free(_Memory);
LAB_180002314:
  *param_1 = (longlong)unaff_RBX;
  param_1[1] = (longlong)(unaff_RBX + uVar1);
  param_1[2] = (longlong)(unaff_RBX + uVar7);
  return puVar9;
}



undefined8 FUN_180002360(undefined4 *param_1)

{
  FUN_180004e40(param_1 + 2,param_1[1],*param_1);
  _Cnd_do_broadcast_at_thread_exit();
  free(param_1);
  return 0;
}



undefined8 FUN_1800023a0(undefined4 *param_1)

{
  FUN_1800051a0(param_1 + 2,param_1[1],*param_1);
  _Cnd_do_broadcast_at_thread_exit();
  free(param_1);
  return 0;
}



undefined8 FUN_1800023e0(undefined4 *param_1)

{
  FUN_180005ba0(param_1 + 2,param_1[1],*param_1);
  _Cnd_do_broadcast_at_thread_exit();
  free(param_1);
  return 0;
}



void FUN_180002420(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_1;
  fVar2 = *param_2;
  if ((fVar2 < fVar1) || ((fVar2 <= fVar1 && ((int)param_2[1] < (int)param_1[1])))) {
    *param_2 = fVar1;
    *param_1 = fVar2;
    fVar1 = param_2[1];
    param_2[1] = param_1[1];
    param_1[1] = fVar1;
  }
  fVar1 = *param_2;
  fVar2 = *param_3;
  if ((fVar2 < fVar1) || ((fVar2 <= fVar1 && ((int)param_3[1] < (int)param_2[1])))) {
    *param_3 = fVar1;
    *param_2 = fVar2;
    fVar3 = param_3[1];
    param_3[1] = param_2[1];
    param_2[1] = fVar3;
    fVar1 = *param_1;
    fVar2 = *param_2;
    if ((fVar2 < fVar1) || ((fVar2 <= fVar1 && ((int)fVar3 < (int)param_1[1])))) {
      *param_2 = fVar1;
      *param_1 = fVar2;
      fVar1 = param_2[1];
      param_2[1] = param_1[1];
      param_1[1] = fVar1;
    }
  }
  return;
}



ulonglong * FUN_1800024c0(ulonglong *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  
  pfVar4 = param_3 + 2;
  if (param_2 < param_3) {
    while( true ) {
      fVar1 = param_3[-2];
      pfVar6 = param_3 + -2;
      fVar2 = *param_3;
      if ((((fVar1 < fVar2) || (fVar2 < fVar1)) || ((int)param_3[-1] < (int)param_3[1])) ||
         (fVar2 < fVar1)) break;
      if (((fVar2 <= fVar1) && ((int)param_3[1] < (int)param_3[-1])) ||
         (param_3 = pfVar6, pfVar6 <= param_2)) break;
    }
  }
  if (pfVar4 < param_4) {
    fVar1 = *param_3;
    while ((fVar2 = *pfVar4, fVar1 <= fVar2 && (fVar2 <= fVar1))) {
      if ((((int)pfVar4[1] < (int)param_3[1]) || (fVar1 < fVar2)) ||
         (((fVar1 <= fVar2 && ((int)param_3[1] < (int)pfVar4[1])) ||
          (pfVar4 = pfVar4 + 2, param_4 <= pfVar4)))) break;
    }
  }
  pfVar6 = param_3;
  pfVar7 = pfVar4;
LAB_180002580:
  pfVar3 = pfVar6;
  if (pfVar4 < param_4) {
    if (0x1f < (ulonglong)((longlong)param_4 + (7 - (longlong)pfVar4))) {
      do {
        fVar1 = *pfVar4;
        fVar2 = *param_3;
        if (fVar1 <= fVar2) {
          if (fVar1 < fVar2) goto joined_r0x0001800027a8;
          if ((int)pfVar4[1] <= (int)param_3[1]) {
            if ((fVar1 < fVar2) || ((fVar1 <= fVar2 && ((int)pfVar4[1] < (int)param_3[1]))))
            goto joined_r0x0001800027a8;
            if (pfVar7 != pfVar4) {
              fVar2 = *pfVar7;
              *pfVar7 = fVar1;
              *pfVar4 = fVar2;
              fVar1 = pfVar7[1];
              pfVar7[1] = pfVar4[1];
              pfVar4[1] = fVar1;
            }
            pfVar7 = pfVar7 + 2;
          }
        }
        fVar1 = pfVar4[2];
        fVar2 = *param_3;
        if (fVar1 <= fVar2) {
          if (fVar1 < fVar2) {
LAB_180002877:
            pfVar4 = pfVar4 + 2;
            goto joined_r0x0001800027a8;
          }
          if ((int)pfVar4[3] <= (int)param_3[1]) {
            if ((fVar1 < fVar2) || ((fVar1 <= fVar2 && ((int)pfVar4[3] < (int)param_3[1]))))
            goto LAB_180002877;
            if (pfVar7 != pfVar4 + 2) {
              fVar2 = *pfVar7;
              *pfVar7 = fVar1;
              pfVar4[2] = fVar2;
              fVar1 = pfVar7[1];
              pfVar7[1] = pfVar4[3];
              pfVar4[3] = fVar1;
            }
            pfVar7 = pfVar7 + 2;
          }
        }
        fVar1 = pfVar4[4];
        fVar2 = *param_3;
        if (fVar1 <= fVar2) {
          if (fVar1 < fVar2) {
LAB_180002880:
            pfVar4 = pfVar4 + 4;
            goto joined_r0x0001800027a8;
          }
          if ((int)pfVar4[5] <= (int)param_3[1]) {
            if ((fVar1 < fVar2) || ((fVar1 <= fVar2 && ((int)pfVar4[5] < (int)param_3[1]))))
            goto LAB_180002880;
            if (pfVar7 != pfVar4 + 4) {
              fVar2 = *pfVar7;
              *pfVar7 = fVar1;
              pfVar4[4] = fVar2;
              fVar1 = pfVar7[1];
              pfVar7[1] = pfVar4[5];
              pfVar4[5] = fVar1;
            }
            pfVar7 = pfVar7 + 2;
          }
        }
        fVar1 = pfVar4[6];
        fVar2 = *param_3;
        if (fVar1 <= fVar2) {
          if (fVar1 < fVar2) {
LAB_180002889:
            pfVar4 = pfVar4 + 6;
            goto joined_r0x0001800027a8;
          }
          if ((int)pfVar4[7] <= (int)param_3[1]) {
            if ((fVar1 < fVar2) || ((fVar1 <= fVar2 && ((int)pfVar4[7] < (int)param_3[1]))))
            goto LAB_180002889;
            if (pfVar7 != pfVar4 + 6) {
              fVar2 = *pfVar7;
              *pfVar7 = fVar1;
              pfVar4[6] = fVar2;
              fVar1 = pfVar7[1];
              pfVar7[1] = pfVar4[7];
              pfVar4[7] = fVar1;
            }
            pfVar7 = pfVar7 + 2;
          }
        }
        pfVar4 = pfVar4 + 8;
      } while (pfVar4 < param_4 + -6);
      if (param_4 <= pfVar4) goto joined_r0x0001800027a8;
    }
    do {
      fVar1 = *pfVar4;
      fVar2 = *param_3;
      if (fVar1 <= fVar2) {
        if (fVar1 < fVar2) break;
        if ((int)pfVar4[1] <= (int)param_3[1]) {
          if ((fVar1 < fVar2) || ((fVar1 <= fVar2 && ((int)pfVar4[1] < (int)param_3[1])))) break;
          if (pfVar7 != pfVar4) {
            fVar2 = *pfVar7;
            *pfVar7 = fVar1;
            *pfVar4 = fVar2;
            fVar1 = pfVar7[1];
            pfVar7[1] = pfVar4[1];
            pfVar4[1] = fVar1;
          }
          pfVar7 = pfVar7 + 2;
        }
      }
      pfVar4 = pfVar4 + 2;
    } while (pfVar4 < param_4);
  }
joined_r0x0001800027a8:
  do {
    if (pfVar3 <= param_2) break;
    fVar1 = *param_3;
    fVar2 = pfVar3[-2];
    if (fVar1 <= fVar2) {
      if (fVar1 < fVar2) break;
      if ((int)param_3[1] <= (int)pfVar3[-1]) {
        if ((fVar1 < fVar2) || ((fVar1 <= fVar2 && ((int)param_3[1] < (int)pfVar3[-1])))) break;
        if (pfVar3 != param_3) {
          fVar1 = param_3[-2];
          param_3[-2] = fVar2;
          pfVar3[-2] = fVar1;
          fVar1 = param_3[-1];
          param_3[-1] = pfVar3[-1];
          pfVar3[-1] = fVar1;
        }
        param_3 = param_3 + -2;
      }
    }
    pfVar3 = pfVar3 + -2;
  } while( true );
  if (pfVar3 == param_2) {
    if (pfVar4 == param_4) {
      *param_1 = (ulonglong)param_3;
      param_1[1] = (ulonglong)pfVar7;
      return param_1;
    }
    if (pfVar7 != pfVar4) {
      fVar1 = *param_3;
      *param_3 = *pfVar7;
      *pfVar7 = fVar1;
      fVar1 = param_3[1];
      param_3[1] = pfVar7[1];
      pfVar7[1] = fVar1;
    }
    fVar1 = *param_3;
    *param_3 = *pfVar4;
    *pfVar4 = fVar1;
    fVar1 = param_3[1];
    param_3[1] = pfVar4[1];
    pfVar4[1] = fVar1;
    pfVar4 = pfVar4 + 2;
    param_3 = param_3 + 2;
    pfVar6 = pfVar3;
    pfVar7 = pfVar7 + 2;
  }
  else {
    pfVar6 = pfVar3 + -2;
    if (pfVar4 == param_4) {
      pfVar5 = param_3 + -2;
      if (param_3 != pfVar3) {
        fVar1 = *pfVar6;
        *pfVar6 = *pfVar5;
        *pfVar5 = fVar1;
        fVar1 = pfVar3[-1];
        pfVar3[-1] = param_3[-1];
        param_3[-1] = fVar1;
      }
      fVar1 = *pfVar5;
      *pfVar5 = pfVar7[-2];
      pfVar7[-2] = fVar1;
      fVar1 = param_3[-1];
      param_3[-1] = pfVar7[-1];
      pfVar7[-1] = fVar1;
      param_3 = pfVar5;
      pfVar7 = pfVar7 + -2;
    }
    else {
      fVar1 = *pfVar4;
      *pfVar4 = *pfVar6;
      *pfVar6 = fVar1;
      fVar1 = pfVar4[1];
      pfVar4[1] = pfVar3[-1];
      pfVar4 = pfVar4 + 2;
      pfVar3[-1] = fVar1;
    }
  }
  goto LAB_180002580;
}



void FUN_180002950(longlong param_1,longlong param_2,ulonglong param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  longlong lVar6;
  
  lVar6 = (longlong)(param_3 - 1) >> 1;
  lVar3 = param_2;
  while (lVar3 < lVar6) {
    fVar1 = *(float *)(param_1 + 8 + lVar3 * 0x10);
    fVar2 = *(float *)(param_1 + 0x10 + lVar3 * 0x10);
    if ((fVar2 < fVar1) ||
       ((fVar2 <= fVar1 &&
        (*(int *)(param_1 + 0x14 + lVar3 * 0x10) < *(int *)(param_1 + 0xc + lVar3 * 0x10))))) {
      lVar4 = 1;
    }
    else {
      lVar4 = 2;
    }
    lVar4 = lVar4 + lVar3 * 2;
    *(undefined4 *)(param_1 + lVar3 * 8) = *(undefined4 *)(param_1 + lVar4 * 8);
    *(undefined4 *)(param_1 + 4 + lVar3 * 8) = *(undefined4 *)(param_1 + 4 + lVar4 * 8);
    lVar3 = lVar4;
  }
  if ((lVar3 == lVar6) && ((param_3 & 1) == 0)) {
    *(undefined4 *)(param_1 + lVar3 * 8) = *(undefined4 *)(param_1 + -8 + param_3 * 8);
    *(undefined4 *)(param_1 + 4 + lVar3 * 8) = *(undefined4 *)(param_1 + -4 + param_3 * 8);
    lVar3 = param_3 - 1;
  }
  while (param_2 < lVar3) {
    lVar6 = lVar3 + -1 >> 1;
    fVar1 = *(float *)(param_1 + lVar6 * 8);
    if (fVar1 < *param_4) {
      piVar5 = (int *)((lVar6 * 8 | 4U) + param_1);
    }
    else if ((*param_4 < fVar1) ||
            (piVar5 = (int *)(lVar6 * 8 + 4U + param_1), (int)param_4[1] <= *piVar5)) break;
    *(float *)(param_1 + lVar3 * 8) = fVar1;
    *(int *)(param_1 + 4 + lVar3 * 8) = *piVar5;
    lVar3 = lVar6;
  }
  *(float *)(param_1 + lVar3 * 8) = *param_4;
  *(float *)(param_1 + 4 + lVar3 * 8) = param_4[1];
  return;
}



void FUN_180002a50(float *param_1,float *param_2,longlong param_3,undefined1 param_4)

{
  float *pfVar1;
  float fVar2;
  undefined8 uVar3;
  float fVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  float *pfVar8;
  longlong lVar9;
  float *pfVar10;
  longlong lVar11;
  float fVar12;
  ulonglong uVar13;
  undefined8 local_res8;
  float *local_48;
  float *local_40;
  
  lVar5 = (longlong)param_2 - (longlong)param_1;
  while( true ) {
    if (lVar5 >> 3 < 0x21) {
      pfVar8 = param_1;
      if (param_1 != param_2) {
        while (pfVar1 = pfVar8 + 2, pfVar1 != param_2) {
          fVar4 = (float)*(undefined8 *)pfVar1;
          fVar12 = (float)((ulonglong)*(undefined8 *)pfVar1 >> 0x20);
          if ((fVar4 < *param_1) || ((fVar4 <= *param_1 && ((int)fVar12 < (int)param_1[1])))) {
            pfVar8 = pfVar8 + 4;
            for (pfVar10 = pfVar1; pfVar10 != param_1; pfVar10 = pfVar10 + -2) {
              pfVar8[-2] = pfVar10[-2];
              pfVar8[-1] = pfVar10[-1];
              pfVar8 = pfVar8 + -2;
            }
            *param_1 = fVar4;
            param_1[1] = fVar12;
            pfVar8 = pfVar1;
          }
          else {
            pfVar8 = pfVar1;
            while( true ) {
              fVar2 = pfVar8[-2];
              if ((fVar2 <= fVar4) && ((fVar2 < fVar4 || ((int)pfVar8[-1] <= (int)fVar12)))) break;
              *pfVar8 = fVar2;
              pfVar8[1] = pfVar8[-1];
              pfVar8 = pfVar8 + -2;
            }
            *pfVar8 = fVar4;
            pfVar8[1] = fVar12;
            pfVar8 = pfVar1;
          }
        }
      }
      return;
    }
    uVar13 = (longlong)param_2 - (longlong)param_1;
    lVar5 = (longlong)uVar13 >> 4;
    if (param_3 < 1) break;
    local_res8 = param_1 + lVar5 * 2;
    lVar6 = (longlong)param_2 + (-8 - (longlong)param_1) >> 3;
    if (lVar6 < 0x29) {
      FUN_180002420(param_1,local_res8,param_2 + -2,param_4);
      pfVar8 = local_res8;
    }
    else {
      lVar6 = lVar6 + 1 >> 3;
      FUN_180002420(param_1,param_1 + lVar6 * 2,param_1 + lVar6 * 4,param_4);
      pfVar8 = local_res8;
      FUN_180002420(local_res8 + lVar6 * -2,local_res8,param_1 + (lVar6 + lVar5) * 2,param_4);
      pfVar1 = param_2 + -2;
      FUN_180002420(pfVar1 + lVar6 * -4,pfVar1 + lVar6 * -2,pfVar1,param_4);
      FUN_180002420(param_1 + lVar6 * 2,pfVar8,pfVar1 + lVar6 * -2,param_4);
    }
    FUN_1800024c0(&local_48,param_1,pfVar8,param_2,param_4);
    pfVar1 = local_40;
    pfVar8 = local_48;
    param_3 = (param_3 >> 1) + (param_3 >> 2);
    if ((longlong)local_48 - (longlong)param_1 >> 3 < (longlong)param_2 - (longlong)local_40 >> 3) {
      FUN_180002a50(param_1,local_48,param_3,param_4);
      pfVar8 = param_2;
      param_1 = pfVar1;
    }
    else {
      FUN_180002a50(local_40,param_2,param_3,param_4);
    }
    lVar5 = (longlong)pfVar8 - (longlong)param_1;
    param_2 = pfVar8;
  }
  lVar6 = (longlong)uVar13 >> 3;
  if (0 < lVar5) {
    lVar11 = lVar6 + -1 >> 1;
    do {
      uVar3 = *(undefined8 *)(param_1 + lVar5 * 2 + -2);
      lVar5 = lVar5 + -1;
      lVar9 = lVar5;
      while (lVar9 < lVar11) {
        if ((param_1[lVar9 * 4 + 4] < param_1[lVar9 * 4 + 2]) ||
           ((param_1[lVar9 * 4 + 4] <= param_1[lVar9 * 4 + 2] &&
            ((int)param_1[lVar9 * 4 + 5] < (int)param_1[lVar9 * 4 + 3])))) {
          lVar7 = 1;
        }
        else {
          lVar7 = 2;
        }
        lVar7 = lVar7 + lVar9 * 2;
        param_1[lVar9 * 2] = param_1[lVar7 * 2];
        param_1[lVar9 * 2 + 1] = param_1[lVar7 * 2 + 1];
        lVar9 = lVar7;
      }
      if ((lVar9 == lVar11) && ((uVar13 & 8) == 0)) {
        param_1[lVar9 * 2] = *(float *)((longlong)param_1 + ((uVar13 & 0xfffffffffffffff8) - 8));
        param_1[lVar9 * 2 + 1] = *(float *)((longlong)param_1 + ((uVar13 & 0xfffffffffffffff8) - 4))
        ;
        lVar9 = lVar6 + -1;
      }
      if (lVar5 < lVar9) {
        local_res8._4_4_ = (int)((ulonglong)uVar3 >> 0x20);
        local_res8._0_4_ = (float)uVar3;
        do {
          lVar7 = lVar9 + -1 >> 1;
          fVar4 = param_1[lVar7 * 2];
          if (fVar4 < (float)local_res8) {
            pfVar8 = (float *)((lVar7 * 8 | 4U) + (longlong)param_1);
          }
          else if (((float)local_res8 < fVar4) ||
                  (pfVar8 = param_1 + lVar7 * 2 + 1, local_res8._4_4_ <= (int)*pfVar8)) break;
          param_1[lVar9 * 2] = fVar4;
          param_1[lVar9 * 2 + 1] = *pfVar8;
          lVar9 = lVar7;
        } while (lVar5 < lVar7);
      }
      *(undefined8 *)(param_1 + lVar9 * 2) = uVar3;
    } while (0 < lVar5);
  }
  if (lVar6 < 2) {
    return;
  }
  do {
    if (1 < (longlong)param_2 - (longlong)param_1 >> 3) {
      local_res8 = *(float **)(param_2 + -2);
      param_2[-2] = *param_1;
      param_2[-1] = param_1[1];
      FUN_180002950(param_1,0,(longlong)(param_2 + -2) - (longlong)param_1 >> 3,&local_res8,param_4)
      ;
    }
    param_2 = param_2 + -2;
  } while (0xf < (longlong)param_2 - (longlong)param_1);
  return;
}



int * FUN_180002e90(int *param_1,ulonglong param_2,int *param_3)

{
  if (*param_3 == 0) {
    memset(param_1,0,param_2 * 4);
    return param_1 + param_2;
  }
  for (; 3 < param_2; param_2 = param_2 - 4) {
    *param_1 = *param_3;
    param_1[1] = *param_3;
    param_1[2] = *param_3;
    param_1[3] = *param_3;
    param_1 = param_1 + 4;
  }
  for (; param_2 != 0; param_2 = param_2 - 1) {
    *param_1 = *param_3;
    param_1 = param_1 + 1;
  }
  return param_1;
}



void FUN_180002f20(undefined8 param_1,uintptr_t *param_2,undefined8 *param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 *_ArgList;
  uintptr_t uVar5;
  
  _ArgList = (undefined4 *)FUN_1800129b0(0xb8);
  if (_ArgList == (undefined4 *)0x0) {
    _ArgList = (undefined4 *)0x0;
  }
  else {
    *_ArgList = *param_5;
    _ArgList[1] = *param_4;
    uVar4 = param_3[1];
    *(undefined8 *)(_ArgList + 2) = *param_3;
    *(undefined8 *)(_ArgList + 4) = uVar4;
    uVar4 = param_3[3];
    *(undefined8 *)(_ArgList + 6) = param_3[2];
    *(undefined8 *)(_ArgList + 8) = uVar4;
    uVar4 = param_3[5];
    *(undefined8 *)(_ArgList + 10) = param_3[4];
    *(undefined8 *)(_ArgList + 0xc) = uVar4;
    uVar4 = param_3[7];
    *(undefined8 *)(_ArgList + 0xe) = param_3[6];
    *(undefined8 *)(_ArgList + 0x10) = uVar4;
    uVar4 = param_3[9];
    *(undefined8 *)(_ArgList + 0x12) = param_3[8];
    *(undefined8 *)(_ArgList + 0x14) = uVar4;
    uVar4 = param_3[0xb];
    *(undefined8 *)(_ArgList + 0x16) = param_3[10];
    *(undefined8 *)(_ArgList + 0x18) = uVar4;
    uVar4 = param_3[0xd];
    *(undefined8 *)(_ArgList + 0x1a) = param_3[0xc];
    *(undefined8 *)(_ArgList + 0x1c) = uVar4;
    uVar4 = param_3[0xf];
    *(undefined8 *)(_ArgList + 0x1e) = param_3[0xe];
    *(undefined8 *)(_ArgList + 0x20) = uVar4;
    uVar4 = param_3[0x11];
    *(undefined8 *)(_ArgList + 0x22) = param_3[0x10];
    *(undefined8 *)(_ArgList + 0x24) = uVar4;
    uVar4 = param_3[0x13];
    *(undefined8 *)(_ArgList + 0x26) = param_3[0x12];
    *(undefined8 *)(_ArgList + 0x28) = uVar4;
    uVar1 = *(undefined4 *)((longlong)param_3 + 0xa4);
    uVar2 = *(undefined4 *)(param_3 + 0x15);
    uVar3 = *(undefined4 *)((longlong)param_3 + 0xac);
    _ArgList[0x2a] = *(undefined4 *)(param_3 + 0x14);
    _ArgList[0x2b] = uVar1;
    _ArgList[0x2c] = uVar2;
    _ArgList[0x2d] = uVar3;
  }
  uVar5 = _beginthreadex((void *)0x0,0,FUN_1800023a0,_ArgList,0,(uint *)(param_2 + 1));
  *param_2 = uVar5;
  if (uVar5 == 0) {
    *(uint *)(param_2 + 1) = 0;
                    // WARNING: Subroutine does not return
    std::_Throw_Cpp_error(6);
  }
  return;
}



void FUN_180003030(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  ulonglong uVar2;
  int *piVar3;
  ulonglong uVar4;
  
  if (*param_3 == 0) {
    memset(param_1,0,(longlong)param_2 - (longlong)param_1 & 0xfffffffffffffffc);
    return;
  }
  uVar4 = ((longlong)param_2 - (longlong)param_1) + 3;
  uVar2 = uVar4 >> 2;
  if (param_2 < param_1) {
    uVar2 = 0;
  }
  piVar3 = param_1;
  if (3 < uVar2) {
    uVar2 = uVar4 & 0xfffffffffffffffc;
    if (param_2 < param_1) {
      uVar2 = 0;
    }
    if ((param_3 < param_1) || ((int *)((longlong)param_1 + (uVar2 - 4)) < param_3)) {
      iVar1 = *param_3;
      uVar4 = uVar4 & 0xfffffffffffffff0;
      if (param_2 < param_1) {
        uVar4 = 0;
      }
      piVar3 = (int *)((longlong)param_1 + uVar4);
      for (uVar4 = uVar4 / 4; uVar4 != 0; uVar4 = uVar4 - 1) {
        *param_1 = iVar1;
        param_1 = param_1 + 1;
      }
    }
  }
  for (; piVar3 != param_2; piVar3 = piVar3 + 1) {
    *piVar3 = *param_3;
  }
  return;
}



ulonglong FUN_1800030f0(uint param_1,uint param_2,float param_3,longlong *param_4,int *param_5,
                       uint *param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  ulonglong uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  int iVar14;
  int iVar15;
  ulonglong uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  float fVar22;
  float fVar23;
  undefined1 auVar24 [12];
  float fVar25;
  float fVar26;
  float fVar27;
  float in_XMM3_Da;
  float fVar28;
  double dVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  int local_118;
  int local_114;
  int local_10c;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  int local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  undefined8 local_e0;
  
  *param_6 = 0;
  *param_5 = 0;
  piVar7 = param_5;
  if (((int)param_1 < 1) || ((int)param_2 < 1)) goto LAB_180003987;
  if ((int)param_1 < 0xdd) {
    iVar19 = 1;
  }
  else {
    iVar19 = (int)(param_1 + 0xdb) / 0xdc;
  }
  if ((int)param_2 < 0xdd) {
    local_114 = 1;
  }
  else {
    local_114 = (int)(param_2 + 0xdb) / 0xdc;
  }
  uVar6 = 0xffffffff;
  iVar18 = 0;
  iVar12 = 0;
  iVar21 = 0;
  uVar8 = (ulonglong)param_2;
  uVar13 = 0xffffffff;
  uVar16 = 0;
  piVar7 = (int *)(ulonglong)param_1;
  dVar29 = 0.0;
  do {
    uVar17 = 0;
    uVar1 = *(undefined4 *)param_7[1];
    local_e0 = *(undefined8 *)*param_7;
    do {
      FUN_18000c890(local_e0,uVar1,uVar17,in_XMM3_Da,&local_100);
      iVar18 = iVar18 + 1;
      iVar15 = iVar12 + 1;
      if (0.5 <= local_f4) {
        iVar15 = iVar12;
      }
      iVar12 = iVar15;
      fVar26 = local_fc * 0.7152 + local_100 * 0.2126 + local_f8 * 0.0722;
      iVar15 = (int)uVar16;
      if ((0.02 < local_f4) || (0.02 < fVar26)) {
        iVar21 = iVar21 + 1;
        uVar4 = uVar17;
        if ((int)(uint)piVar7 <= (int)uVar17) {
          uVar4 = (uint)piVar7;
        }
        piVar7 = (int *)(ulonglong)uVar4;
        uVar4 = uVar17;
        if ((int)uVar17 <= (int)uVar6) {
          uVar4 = uVar6;
        }
        uVar6 = uVar4;
        if (iVar15 < (int)uVar8) {
          uVar8 = uVar16 & 0xffffffff;
        }
        if ((int)uVar13 < iVar15) {
          uVar13 = uVar16 & 0xffffffff;
        }
        if (local_f4 <= 0.0001) {
          fVar26 = 0.0;
        }
        else {
          fVar26 = fVar26 / local_f4;
        }
        dVar29 = dVar29 + (double)fVar26;
      }
      uVar17 = uVar17 + iVar19;
      in_XMM3_Da = local_f4;
    } while ((int)uVar17 < (int)param_1);
    uVar16 = (ulonglong)(uint)(iVar15 + local_114);
  } while (iVar15 + local_114 < (int)param_2);
  if ((((int)uVar6 < (int)piVar7) || ((int)uVar13 < (int)uVar8)) || (iVar21 == 0))
  goto LAB_180003987;
  iVar5 = (int)piVar7 - iVar19;
  iVar15 = 0;
  if (0 < iVar5) {
    iVar15 = iVar5;
  }
  iVar9 = (int)uVar8 - local_114;
  iVar5 = 0;
  if (0 < iVar9) {
    iVar5 = iVar9;
  }
  iVar9 = param_1 - 1;
  if ((int)(uVar6 + iVar19) < (int)(param_1 - 1)) {
    iVar9 = uVar6 + iVar19;
  }
  local_114 = (int)uVar13 + local_114;
  iVar19 = param_2 - 1;
  if (local_114 < (int)(param_2 - 1)) {
    iVar19 = local_114;
  }
  fVar26 = (float)((iVar9 - iVar15) + 1);
  local_f0 = (int)((double)iVar18 * 0.02);
  fVar31 = (float)((iVar19 - iVar5) + 1);
  if ((local_f0 < iVar12) || (dVar29 / (double)iVar21 <= 0.55)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  auVar24 = ZEXT812(0x3d4ccccd);
  if (auVar24._0_4_ <= param_3) {
    auVar24._4_8_ = auVar24._4_8_;
    auVar24._0_4_ = param_3;
  }
  *param_5 = 0x80;
  uVar6 = (uint)(128.0 / auVar24._0_4_ + 0.5);
  *param_6 = uVar6;
  if ((int)uVar6 < 8) {
    uVar6 = 8;
    *param_6 = 8;
LAB_180003443:
    uVar8 = (ulonglong)uVar6;
  }
  else {
    uVar8 = 0x1c0;
    if ((int)uVar6 < 0x1c1) goto LAB_180003443;
    *param_6 = 0x1c0;
  }
  FUN_18000a200(param_4,(longlong)*param_5 * uVar8);
  fVar22 = (float)*param_5 / fVar26;
  fVar30 = (float)(int)*param_6;
  fVar25 = fVar30 / fVar31;
  if (fVar22 <= fVar25) {
    fVar25 = fVar22;
  }
  fVar22 = 1.0 / fVar25;
  uVar6 = (int)fVar22 + 1;
  piVar7 = (int *)(ulonglong)uVar6;
  if ((int)uVar6 < 8) {
    uVar17 = 1;
    if (0 < (int)uVar6) {
      uVar17 = uVar6;
    }
  }
  else {
    uVar17 = 7;
  }
  if (0 < (int)*param_6) {
    piVar7 = (int *)(ulonglong)(iVar19 + 1);
    local_10c = 0;
    fVar26 = ((float)*param_5 - fVar25 * fVar26) * 0.5;
    fVar31 = (fVar30 - fVar25 * fVar31) * 0.5;
    local_e0 = CONCAT44(local_e0._4_4_,fVar31);
    local_ec = fVar22;
    local_e4 = fVar26;
    do {
      fVar30 = ((float)local_10c - fVar31) * fVar22 + (float)iVar5;
      fVar25 = fVar30 + fVar22;
      if (((float)iVar5 < fVar25) && (fVar30 < (float)(int)piVar7)) {
        iVar18 = *param_5;
        if (0 < iVar18) {
          local_118 = 0;
          local_e8 = fVar25;
          do {
            iVar21 = local_f0;
            fVar31 = ((float)local_118 - fVar26) * fVar22 + (float)iVar15;
            if ((float)iVar15 < fVar31 + fVar22) {
              if (fVar31 < (float)(iVar9 + 1)) {
                iVar11 = 0;
                iVar20 = 0;
                fVar26 = 0.0;
                if (uVar17 == 0) {
LAB_1800037ff:
                  fVar31 = 0.0;
                }
                else {
                  fVar32 = (float)(int)uVar17;
                  do {
                    iVar18 = (int)(((fVar25 - fVar30) * ((float)iVar20 + 0.5)) / fVar32 + fVar30);
                    if ((iVar5 <= iVar18) && (iVar18 <= iVar19)) {
                      iVar18 = 0;
                      fVar28 = (fVar31 + fVar22) - fVar31;
                      if (iVar21 < iVar12) {
                        do {
                          iVar14 = (int)((fVar28 * ((float)iVar18 + 0.5)) / fVar32 + fVar31);
                          if ((iVar15 <= iVar14) && (iVar14 <= iVar9)) {
                            FUN_18000c890(*(undefined8 *)*param_7,*(undefined4 *)param_7[1]);
                            fVar26 = fVar26 + local_f4;
                            iVar11 = iVar11 + 1;
                          }
                          iVar18 = iVar18 + 1;
                        } while (iVar18 < (int)uVar17);
                      }
                      else {
                        do {
                          iVar14 = (int)((fVar28 * ((float)iVar18 + 0.5)) / fVar32 + fVar31);
                          if ((iVar15 <= iVar14) && (iVar14 <= iVar9)) {
                            FUN_18000c890(*(undefined8 *)*param_7,*(undefined4 *)param_7[1]);
                            if (local_f4 <= 0.0001) {
                              fVar27 = 0.0;
LAB_180003770:
                              fVar23 = 1.0;
                              if (fVar27 <= 1.0) {
                                fVar23 = fVar27;
                              }
                            }
                            else {
                              fVar27 = (local_fc * 0.7152 + local_100 * 0.2126 + local_f8 * 0.0722)
                                       / local_f4;
                              if (0.0 <= fVar27) goto LAB_180003770;
                              fVar23 = 0.0;
                            }
                            if (bVar3) {
                              fVar23 = 1.0 - fVar23;
                            }
                            iVar11 = iVar11 + 1;
                            fVar26 = fVar26 + fVar23 * local_f4;
                          }
                          iVar18 = iVar18 + 1;
                        } while (iVar18 < (int)uVar17);
                      }
                    }
                    iVar20 = iVar20 + 1;
                  } while (iVar20 < (int)uVar17);
                  iVar18 = *param_5;
                  if (iVar11 < 1) goto LAB_1800037ff;
                  fVar26 = fVar26 / (float)iVar11;
                  if (0.0 <= fVar26) {
                    fVar31 = 1.0;
                    if (fVar26 <= 1.0) {
                      fVar31 = fVar26;
                    }
                  }
                  else {
                    fVar31 = 0.0;
                  }
                }
                *(float *)(*param_4 +
                          ((longlong)iVar18 * (longlong)local_10c + (longlong)local_118) * 4) =
                     fVar31;
                fVar22 = local_ec;
                fVar25 = local_e8;
                fVar26 = local_e4;
              }
            }
            iVar18 = *param_5;
            local_118 = local_118 + 1;
          } while (local_118 < iVar18);
          fVar31 = (float)local_e0;
        }
        piVar7 = (int *)(ulonglong)(iVar19 + 1);
      }
      local_10c = local_10c + 1;
    } while (local_10c < (int)*param_6);
  }
  lVar2 = *param_4;
  piVar10 = (int *)(param_4[1] - lVar2 >> 2);
  if (piVar10 != (int *)0x0) {
    piVar7 = (int *)0x0;
    fVar26 = 0.0;
    if (piVar10 < (int *)0x4) goto LAB_180003910;
    do {
      fVar31 = *(float *)(lVar2 + (longlong)piVar7 * 4);
      fVar25 = *(float *)(lVar2 + 8 + (longlong)piVar7 * 4);
      if (fVar31 <= fVar26) {
        fVar31 = fVar26;
      }
      fVar26 = *(float *)(lVar2 + 4 + (longlong)piVar7 * 4);
      if (fVar26 <= fVar31) {
        fVar26 = fVar31;
      }
      if (fVar25 <= fVar26) {
        fVar25 = fVar26;
      }
      fVar26 = *(float *)(lVar2 + 0xc + (longlong)piVar7 * 4);
      piVar7 = piVar7 + 1;
      if (fVar26 <= fVar25) {
        fVar26 = fVar25;
      }
      fVar31 = fVar26;
    } while (piVar7 < (int *)((longlong)piVar10 + -3));
    while (fVar26 = fVar31, piVar7 < piVar10) {
LAB_180003910:
      fVar31 = *(float *)(lVar2 + (longlong)piVar7 * 4);
      piVar7 = (int *)((longlong)piVar7 + 1);
      if (fVar31 <= fVar26) {
        fVar31 = fVar26;
      }
    }
    if (0.02 <= fVar26) {
      if (fVar26 < 0.98) {
        piVar10 = (int *)0x0;
        fVar31 = 4.0;
        if (1.0 / fVar26 <= 4.0) {
          fVar31 = 1.0 / fVar26;
        }
        do {
          fVar26 = fVar31 * *(float *)(lVar2 + (longlong)piVar10 * 4);
          if (0.0 <= fVar26) {
            fVar25 = 1.0;
            if (fVar26 <= 1.0) {
              fVar25 = fVar26;
            }
          }
          else {
            fVar25 = 0.0;
          }
          *(float *)(lVar2 + (longlong)piVar10 * 4) = fVar25;
          piVar10 = (int *)((longlong)piVar10 + 1);
          piVar7 = (int *)(param_4[1] - lVar2 >> 2);
        } while (piVar10 < piVar7);
      }
      return CONCAT71((int7)((ulonglong)piVar7 >> 8),1);
    }
  }
LAB_180003987:
  return (ulonglong)piVar7 & 0xffffffffffffff00;
}



void FUN_1800039d0(longlong *param_1,int *param_2,int *param_3,int param_4,int param_5,
                  longlong param_6,undefined8 param_7,undefined8 param_8)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  longlong *plVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  uintptr_t uVar16;
  int *_ArgList;
  undefined1 (*pauVar17) [16];
  int iVar18;
  int iVar19;
  ulonglong uVar20;
  undefined1 auVar21 [8];
  undefined1 (*pauVar22) [16];
  int iVar23;
  int iVar24;
  undefined1 auVar25 [8];
  undefined1 (*pauVar26) [16];
  longlong lVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 (*pauVar30) [16];
  undefined1 (*pauVar31) [16];
  longlong lVar32;
  int iVar33;
  int iVar34;
  ulonglong uVar35;
  int iVar36;
  int *piVar37;
  longlong lVar38;
  undefined1 (*pauVar39) [16];
  uint *_ThrdAddr;
  int *piVar40;
  uint uVar41;
  int iVar42;
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  float fVar45;
  float fVar46;
  float fVar47;
  int local_res20 [2];
  undefined8 uStackY_190;
  undefined1 auStackY_188 [8];
  undefined1 auStackY_180 [24];
  undefined1 local_158 [8];
  undefined1 (*pauStack_150) [16];
  undefined1 (*local_148) [16];
  uint local_140;
  int local_13c;
  int local_138;
  int local_134;
  float local_130;
  float local_12c;
  int local_128;
  uint local_124;
  int *local_118;
  int *local_108;
  undefined1 (*pauStack_100) [16];
  undefined1 (*local_f8) [16];
  int *piStack_f0;
  int *local_e8;
  undefined8 uStack_e0;
  longlong *local_d8;
  float *pfStack_d0;
  float *local_c8;
  
  lVar32 = param_6;
  uVar41 = 0;
  local_140 = 0;
  local_138 = *(int *)(param_6 + 0x7c);
  if (local_138 < 1) {
    local_138 = 1;
  }
  local_134 = *(int *)(param_6 + 0x80);
  if (local_134 < 1) {
    local_134 = 1;
  }
  *param_2 = (param_4 + -1 + local_138) / local_138;
  iVar15 = (param_5 + -1 + local_134) / local_134;
  *param_3 = iVar15;
  local_108 = (int *)0x0;
  pauStack_100 = (undefined1 (*) [16])0x0;
  local_f8 = (undefined1 (*) [16])0x0;
  piStack_f0 = (int *)0x0;
  local_e8 = (int *)0x0;
  uStack_e0 = 0;
  local_d8 = (longlong *)0x0;
  pfStack_d0 = (float *)0x0;
  local_res20[0] = param_4;
  FUN_18000a440(param_1,(longlong)iVar15 * (longlong)*param_2,&local_108);
  local_130 = *(float *)(lVar32 + 0x14) + 1.0;
  local_12c = 0.05;
  if (0.05 <= *(float *)(lVar32 + 0x10)) {
    local_12c = *(float *)(lVar32 + 0x10);
  }
  local_12c = 1.0 / local_12c;
  pauStack_100 = (undefined1 (*) [16])&local_138;
  local_f8 = (undefined1 (*) [16])&local_134;
  piStack_f0 = local_res20;
  local_e8 = &param_5;
  uStack_e0 = CONCAT44(param_8._4_4_,(int)param_8);
  pfStack_d0 = &local_130;
  local_c8 = &local_12c;
  local_108 = param_2;
  local_d8 = param_1;
  local_13c = _Thrd_hardware_concurrency();
  pfVar14 = local_c8;
  pfVar13 = pfStack_d0;
  plVar12 = local_d8;
  uVar8 = uStack_e0;
  piVar11 = local_e8;
  piVar10 = piStack_f0;
  pauVar26 = local_f8;
  pauVar17 = pauStack_100;
  piVar9 = local_108;
  puVar29 = auStackY_188;
  puVar28 = auStackY_188;
  if (local_13c == 0) {
    local_13c = 4;
  }
  piVar37 = param_3;
  if (local_13c < 9) {
    if (1 < local_13c) goto LAB_180003b66;
  }
  else {
    local_13c = 8;
LAB_180003b66:
    if (local_13c * 2 <= *param_3) {
      pauVar22 = (undefined1 (*) [16])0x0;
      local_148 = (undefined1 (*) [16])0x0;
      uVar35 = (longlong)(*param_3 + -1 + local_13c) / (longlong)local_13c;
      local_124 = (uint)uVar35;
      uVar35 = uVar35 & 0xffffffff;
      param_8._0_4_ = 0;
      pauStack_150 = (undefined1 (*) [16])0x0;
      local_158 = (undefined1  [8])0x0;
      auVar25 = local_158;
      pauVar30 = pauStack_150;
      pauVar31 = pauStack_150;
      _local_158 = ZEXT816(0);
      if (local_13c != 0) {
LAB_180003bc9:
        iVar33 = (int)param_8 * (int)uVar35;
        local_118 = (int *)CONCAT44(local_118._4_4_,iVar33);
        iVar15 = iVar33 + (int)uVar35;
        if (*param_3 < iVar15) {
          iVar15 = *param_3;
        }
        pauVar22 = local_148;
        puVar29 = auStackY_188;
        pauVar31 = pauVar30;
        piVar37 = param_3;
        local_128 = iVar15;
        if (iVar15 <= iVar33) goto LAB_180003efe;
        if (pauVar30 != local_148) {
          local_118 = (int *)FUN_1800129b0();
          if (local_118 != (int *)0x0) {
            *local_118 = iVar15;
            local_118[1] = iVar33;
            *(int **)(local_118 + 2) = piVar9;
            *(undefined1 (**) [16])(local_118 + 4) = pauVar17;
            *(undefined1 (**) [16])(local_118 + 6) = pauVar26;
            *(int **)(local_118 + 8) = piVar10;
            *(int **)(local_118 + 10) = piVar11;
            *(undefined8 *)(local_118 + 0xc) = uVar8;
            *(longlong **)(local_118 + 0xe) = plVar12;
            *(float **)(local_118 + 0x10) = pfVar13;
            *(float **)(local_118 + 0x12) = pfVar14;
          }
          uVar16 = _beginthreadex((void *)0x0,0,FUN_1800023e0,local_118,0,
                                  (uint *)((longlong)*pauVar30 + 8));
          *(uintptr_t *)*pauVar30 = uVar16;
          if (uVar16 == 0) {
            *(uint *)((longlong)*pauVar30 + 8) = 0;
                    // WARNING: Subroutine does not return
            std::_Throw_Cpp_error(6);
          }
          local_140 = uVar41 | 1;
          pauVar31 = (undefined1 (*) [16])((longlong)pauStack_150 + 0x10);
          pauStack_150 = pauVar31;
          auVar25 = local_158;
          goto LAB_180003ecc;
        }
        uVar35 = (longlong)pauVar30 - (longlong)auVar25;
        lVar32 = (longlong)uVar35 >> 4;
        if (lVar32 == 0xfffffffffffffff) {
                    // WARNING: Subroutine does not return
          FUN_18000a1e0();
        }
        uVar20 = (longlong)local_148 - (longlong)auVar25 >> 4;
        if (0xfffffffffffffff - (uVar20 >> 1) < uVar20) {
LAB_18000443c:
                    // WARNING: Subroutine does not return
          FUN_18000a140();
        }
        pauVar31 = (undefined1 (*) [16])(lVar32 + 1);
        pauVar22 = (undefined1 (*) [16])((uVar20 >> 1) + uVar20);
        pauVar39 = pauVar31;
        if (pauVar31 <= pauVar22) {
          pauVar39 = pauVar22;
        }
        if ((undefined1 (*) [16])0xfffffffffffffff < pauVar39) goto LAB_18000443c;
        piVar37 = (int *)((longlong)pauVar39 * 0x10);
        if (piVar37 == (int *)0x0) {
          auVar25 = (undefined1  [8])0x0;
        }
        else if (piVar37 < (int *)0x1000) {
          auVar25 = (undefined1  [8])FUN_1800129b0(piVar37);
        }
        else {
          if ((int *)((longlong)piVar37 + 0x27U) <= piVar37) goto LAB_18000443c;
          lVar32 = FUN_1800129b0();
          if (lVar32 == 0) {
            pcVar6 = (code *)swi(0x29);
            (*pcVar6)(5);
            puVar28 = auStackY_180;
LAB_180003ef0:
                    // WARNING: Subroutine does not return
            *(undefined8 *)(puVar28 + -8) = 0x180003ef6;
            terminate();
          }
          auVar25 = (undefined1  [8])(lVar32 + 0x27U & 0xffffffffffffffe0);
          *(longlong *)((longlong)*(undefined1 (*) [16])((longlong)auVar25 + -0x10) + 8) = lVar32;
        }
        uVar35 = uVar35 & 0xfffffffffffffff0;
        piVar40 = (int *)((longlong)*(undefined1 (*) [16])((longlong)auVar25 + 0x10) + uVar35);
        local_108 = (int *)local_158;
        pauStack_100 = (undefined1 (*) [16])auVar25;
        local_f8 = pauVar39;
        piStack_f0 = piVar40;
        local_e8 = piVar40;
        _ArgList = (int *)FUN_1800129b0();
        if (_ArgList != (int *)0x0) {
          *_ArgList = local_128;
          _ArgList[1] = (int)local_118;
          *(int **)(_ArgList + 2) = piVar9;
          *(undefined1 (**) [16])(_ArgList + 4) = pauVar17;
          *(undefined1 (**) [16])(_ArgList + 6) = pauVar26;
          *(int **)(_ArgList + 8) = piVar10;
          *(int **)(_ArgList + 10) = piVar11;
          *(undefined8 *)(_ArgList + 0xc) = uVar8;
          *(longlong **)(_ArgList + 0xe) = plVar12;
          *(float **)(_ArgList + 0x10) = pfVar13;
          *(float **)(_ArgList + 0x12) = pfVar14;
        }
        _ThrdAddr = (uint *)((longlong)*(undefined1 (*) [16])auVar25 + uVar35 + 8);
        local_118 = _ArgList;
        uVar16 = _beginthreadex((void *)0x0,0,FUN_1800023e0,_ArgList,0,_ThrdAddr);
        *(uintptr_t *)((longlong)*(undefined1 (*) [16])auVar25 + uVar35) = uVar16;
        if (uVar16 == 0) {
          *_ThrdAddr = 0;
                    // WARNING: Subroutine does not return
          std::_Throw_Cpp_error(6);
        }
        pauVar22 = (undefined1 (*) [16])auVar25;
        auVar21 = local_158;
        if (pauVar30 == pauStack_150) {
          for (; auVar21 != (undefined1  [8])pauStack_150;
              auVar21 = (undefined1  [8])((longlong)auVar21 + 0x10)) {
            uVar7 = *(undefined8 *)((longlong)*(undefined1 (*) [16])auVar21 + 8);
            *(undefined1 (*) [16])auVar21 = ZEXT816(0);
            *(undefined8 *)*pauVar22 = *(undefined8 *)*(undefined1 (*) [16])auVar21;
            *(undefined8 *)((longlong)*pauVar22 + 8) = uVar7;
            pauVar22 = pauVar22 + 1;
          }
        }
        else {
          for (; auVar21 != (undefined1  [8])pauVar30;
              auVar21 = (undefined1  [8])((longlong)auVar21 + 0x10)) {
            uVar7 = *(undefined8 *)((longlong)*(undefined1 (*) [16])auVar21 + 8);
            *(undefined1 (*) [16])auVar21 = ZEXT816(0);
            *(undefined8 *)*pauVar22 = *(undefined8 *)*(undefined1 (*) [16])auVar21;
            *(undefined8 *)((longlong)*pauVar22 + 8) = uVar7;
            pauVar22 = pauVar22 + 1;
          }
          for (; pauVar30 != pauStack_150; pauVar30 = pauVar30 + 1) {
            uVar7 = *(undefined8 *)((longlong)*pauVar30 + 8);
            *pauVar30 = ZEXT816(0);
            *(undefined8 *)piVar40 = *(undefined8 *)*pauVar30;
            *(undefined8 *)(piVar40 + 2) = uVar7;
            piVar40 = piVar40 + 4;
          }
        }
        auVar21 = local_158;
        if (local_158 != (undefined1  [8])0x0) {
          for (; auVar21 != (undefined1  [8])pauStack_150;
              auVar21 = (undefined1  [8])((longlong)auVar21 + 0x10)) {
            if (*(int *)((longlong)*(undefined1 (*) [16])auVar21 + 8) != 0) goto LAB_180003ef0;
          }
          if (((longlong)local_148 - (longlong)local_158 & 0xfffffffffffffff0U) < 0x1000) {
            auVar21 = local_158;
          }
          else {
            auVar21 = *(undefined1 (*) [8])
                       ((longlong)*(undefined1 (*) [16])((longlong)local_158 + -0x10) + 8);
            if (0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)auVar21))) {
              pauVar22 = (undefined1 (*) [16])0x5;
              pcVar6 = (code *)swi(0x29);
              (*pcVar6)();
              puVar29 = auStackY_180;
LAB_180003efe:
              lVar32 = param_6;
              goto LAB_180003f12;
            }
          }
          free((void *)auVar21);
        }
        local_140 = local_140 | 2;
        pauVar31 = (undefined1 (*) [16])((longlong)auVar25 + pauVar31 * 0x10);
        pauStack_150 = pauVar31;
        local_158 = auVar25;
        local_148 = (undefined1 (*) [16])((longlong)piVar37 + (longlong)auVar25);
LAB_180003ecc:
        param_8._0_4_ = (int)param_8 + 1;
        pauVar22 = local_148;
        puVar29 = auStackY_188;
        piVar37 = param_3;
        if (local_13c <= (int)param_8) goto LAB_180003efe;
        uVar35 = (ulonglong)local_124;
        pauVar30 = pauVar31;
        uVar41 = local_140;
        goto LAB_180003bc9;
      }
LAB_180003f12:
      if (auVar25 != (undefined1  [8])pauVar31) {
        do {
          if (*(int *)((longlong)*(undefined1 (*) [16])auVar25 + 8) == 0) {
                    // WARNING: Subroutine does not return
            *(undefined8 *)(puVar29 + -8) = 0x180004417;
            std::_Throw_Cpp_error(1);
          }
          *(undefined8 *)(puVar29 + -8) = 0x180003f2f;
          iVar15 = _Thrd_id();
          if (*(int *)((longlong)*(undefined1 (*) [16])auVar25 + 8) == iVar15) {
                    // WARNING: Subroutine does not return
            *(undefined **)(puVar29 + -8) = &UNK_18000445d;
            std::_Throw_Cpp_error(5);
          }
          uVar8 = *(undefined8 *)((longlong)*(undefined1 (*) [16])auVar25 + 8);
          *(undefined8 *)(puVar29 + 0x70) = *(undefined8 *)*(undefined1 (*) [16])auVar25;
          *(undefined8 *)(puVar29 + 0x78) = uVar8;
          *(undefined8 *)(puVar29 + -8) = 0x180003f4c;
          iVar15 = _Thrd_join(puVar29 + 0x70,0);
          if (iVar15 != 0) {
                    // WARNING: Subroutine does not return
            *(undefined **)(puVar29 + -8) = &UNK_180004452;
            std::_Throw_Cpp_error(2);
          }
          *(undefined1 (*) [16])auVar25 = ZEXT816(0);
          auVar25 = (undefined1  [8])((longlong)auVar25 + 0x10);
        } while (auVar25 != (undefined1  [8])pauVar31);
        pauVar22 = *(undefined1 (**) [16])(puVar29 + 0x40);
        pauVar31 = *(undefined1 (**) [16])(puVar29 + 0x38);
        auVar25 = *(undefined1 (*) [8])(puVar29 + 0x30);
      }
      if (auVar25 != (undefined1  [8])0x0) {
        if (auVar25 != (undefined1  [8])pauVar31) {
          pauVar17 = (undefined1 (*) [16])auVar25;
          do {
            if (*(int *)((longlong)*pauVar17 + 8) != 0) {
                    // WARNING: Subroutine does not return
              *(undefined8 *)(puVar29 + -8) = 0x180003fbc;
              terminate();
            }
            pauVar17 = pauVar17 + 1;
          } while (pauVar17 != pauVar31);
        }
        pauVar17 = (undefined1 (*) [16])auVar25;
        if (0xfff < ((longlong)pauVar22 - (longlong)auVar25 & 0xfffffffffffffff0U)) {
          pauVar17 = *(undefined1 (**) [16])
                      ((longlong)*(undefined1 (*) [16])((longlong)auVar25 + -0x10) + 8);
          pauVar26 = (undefined1 (*) [16])((longlong)auVar25 + (-8 - (longlong)pauVar17));
          if ((undefined1 (*) [16])0x1f < pauVar26) {
            pcVar6 = (code *)swi(0x29);
            (*pcVar6)(5);
            puVar29 = puVar29 + 8;
            pauVar17 = pauVar26;
          }
        }
        *(undefined8 *)(puVar29 + -8) = 0x180003fd2;
        free(pauVar17);
      }
      goto LAB_180003fd9;
    }
  }
  FUN_180005ba0(&local_108,0,*param_3);
  puVar29 = auStackY_188;
LAB_180003fd9:
  if (*(int *)(lVar32 + 8) != 1) {
    iVar15 = 0;
    if (0 < *piVar37) {
      do {
        iVar42 = 0;
        iVar33 = *param_2;
        if (0 < iVar33) {
          lVar32 = *param_1;
          do {
            iVar34 = *piVar37 + -1;
            iVar24 = iVar15 + -1;
            iVar1 = iVar33 + -1;
            iVar36 = iVar42 + -1;
            iVar23 = iVar24;
            if (iVar24 < 0) {
              iVar23 = 0;
            }
            lVar38 = (longlong)iVar33;
            iVar33 = iVar36;
            if (iVar36 < 0) {
              iVar33 = 0;
            }
            if (iVar1 < iVar33) {
              iVar33 = iVar1;
            }
            if (iVar34 < iVar23) {
              iVar23 = iVar34;
            }
            fVar45 = *(float *)(lVar32 + (iVar23 * lVar38 + (longlong)iVar33) * 0x40);
            iVar33 = iVar42 + 1;
            iVar23 = iVar24;
            if (iVar24 < 0) {
              iVar23 = 0;
            }
            iVar18 = iVar33;
            if (iVar33 < 0) {
              iVar18 = 0;
            }
            if (iVar1 < iVar18) {
              iVar18 = iVar1;
            }
            if (iVar34 < iVar23) {
              iVar23 = iVar34;
            }
            fVar46 = *(float *)(lVar32 + (iVar23 * lVar38 + (longlong)iVar18) * 0x40);
            iVar23 = iVar15 + 1;
            iVar18 = iVar23;
            if (iVar23 < 0) {
              iVar18 = 0;
            }
            iVar19 = iVar36;
            if (iVar36 < 0) {
              iVar19 = 0;
            }
            if (iVar1 < iVar19) {
              iVar19 = iVar1;
            }
            if (iVar34 < iVar18) {
              iVar18 = iVar34;
            }
            fVar2 = *(float *)(lVar32 + (iVar18 * lVar38 + (longlong)iVar19) * 0x40);
            iVar18 = iVar23;
            if (iVar23 < 0) {
              iVar18 = 0;
            }
            iVar19 = iVar33;
            if (iVar33 < 0) {
              iVar19 = 0;
            }
            if (iVar1 < iVar19) {
              iVar19 = iVar1;
            }
            if (iVar34 < iVar18) {
              iVar18 = iVar34;
            }
            fVar3 = *(float *)(lVar32 + (iVar18 * lVar38 + (longlong)iVar19) * 0x40);
            iVar18 = iVar15;
            if (iVar15 < 0) {
              iVar18 = 0;
            }
            if (iVar33 < 0) {
              iVar33 = 0;
            }
            if (iVar1 < iVar33) {
              iVar33 = iVar1;
            }
            if (iVar34 < iVar18) {
              iVar18 = iVar34;
            }
            fVar47 = *(float *)(lVar32 + (iVar18 * lVar38 + (longlong)iVar33) * 0x40);
            iVar33 = iVar15;
            if (iVar15 < 0) {
              iVar33 = 0;
            }
            if (iVar36 < 0) {
              iVar36 = 0;
            }
            if (iVar1 < iVar36) {
              iVar36 = iVar1;
            }
            if (iVar34 < iVar33) {
              iVar33 = iVar34;
            }
            fVar4 = *(float *)(lVar32 + (iVar33 * lVar38 + (longlong)iVar36) * 0x40);
            fVar47 = (fVar47 + fVar47 + fVar46 + fVar3) - (fVar4 + fVar4 + fVar45 + fVar2);
            if (iVar23 < 0) {
              iVar23 = 0;
            }
            iVar33 = iVar42;
            if (iVar42 < 0) {
              iVar33 = 0;
            }
            if (iVar1 < iVar33) {
              iVar33 = iVar1;
            }
            if (iVar34 < iVar23) {
              iVar23 = iVar34;
            }
            fVar4 = *(float *)(lVar32 + (iVar23 * lVar38 + (longlong)iVar33) * 0x40);
            if (iVar24 < 0) {
              iVar24 = 0;
            }
            iVar33 = iVar42;
            if (iVar42 < 0) {
              iVar33 = 0;
            }
            if (iVar1 < iVar33) {
              iVar33 = iVar1;
            }
            if (iVar34 < iVar24) {
              iVar24 = iVar34;
            }
            fVar5 = *(float *)(lVar32 + (iVar24 * lVar38 + (longlong)iVar33) * 0x40);
            fVar46 = (fVar4 + fVar4 + fVar2 + fVar3) - (fVar5 + fVar5 + fVar45 + fVar46);
            fVar45 = fVar46 * fVar46 + fVar47 * fVar47;
            if (fVar45 < 0.0) {
              *(undefined8 *)(puVar29 + -8) = 0x180004278;
              fVar45 = sqrtf(fVar45);
            }
            else {
              fVar45 = SQRT(fVar45);
            }
            fVar45 = fVar45 * 0.25;
            lVar38 = (iVar15 * lVar38 + (longlong)iVar42) * 0x40;
            *(float *)(lVar32 + 0x14 + lVar38) = fVar45;
            if (fVar45 <= 0.0001) {
              fVar46 = 0.0;
              fVar47 = 1.0;
            }
            else {
              fVar46 = fVar46 / (fVar45 * 4.0);
              fVar47 = fVar47 / (fVar45 * 4.0);
            }
            *(float *)(lVar32 + 0x18 + lVar38) = fVar47;
            *(float *)(lVar32 + 0x1c + lVar38) = fVar46;
            fVar45 = fVar46 * fVar46 + fVar47 * fVar47;
            if (fVar45 < 0.0) {
              *(undefined8 *)(puVar29 + -8) = 0x1800042e1;
              fVar45 = sqrtf(fVar45);
            }
            else {
              fVar45 = SQRT(fVar45);
            }
            if (fVar45 <= 1e-06) {
              *(undefined8 *)(lVar32 + 0x18 + lVar38) = 0x3f800000;
            }
            else {
              auVar43._8_8_ = 0;
              auVar43._0_8_ = *(ulonglong *)(lVar32 + 0x18 + lVar38);
              auVar44._4_4_ = fVar45;
              auVar44._0_4_ = fVar45;
              auVar44._8_8_ = 0;
              auVar44 = divps(auVar43,auVar44);
              *(longlong *)(lVar32 + 0x18 + lVar38) = auVar44._0_8_;
            }
            iVar42 = iVar42 + 1;
            iVar33 = *param_2;
            piVar37 = param_3;
          } while (iVar42 < iVar33);
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 < *piVar37);
    }
    lVar32 = param_6;
  }
  uVar8 = param_7;
  uVar35 = 0;
  lVar38 = *param_1;
  if (param_1[1] - lVar38 >> 6 != 0) {
    do {
      lVar27 = uVar35 * 0x40;
      *(undefined8 *)(puVar29 + -8) = 0x180004385;
      FUN_18000b1c0(lVar38 + lVar27,lVar32,uVar8);
      lVar38 = *param_1;
      if (*(int *)(lVar32 + 0x40) == 2) {
        if (*(int *)(lVar32 + 0x44) == 0) {
          *(float *)(lVar38 + 0x20 + lVar27) = *(float *)(lVar38 + lVar27);
        }
        else {
          *(float *)(lVar38 + 0x20 + lVar27) = 1.0 - *(float *)(lVar38 + lVar27);
        }
      }
      else {
        *(undefined4 *)(lVar38 + 0x20 + lVar27) = 0x3f000000;
      }
      uVar35 = uVar35 + 1;
      lVar38 = *param_1;
    } while (uVar35 < (ulonglong)(param_1[1] - lVar38 >> 6));
  }
  return;
}



void FUN_180004460(undefined8 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                  uintptr_t param_5,uintptr_t param_6,uintptr_t param_7,undefined1 param_8,
                  undefined8 param_9)

{
  void *_Memory;
  code *pcVar1;
  uintptr_t uVar2;
  uintptr_t *puVar3;
  uintptr_t **ppuVar4;
  uintptr_t *puVar5;
  uintptr_t *puVar6;
  uintptr_t *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  uintptr_t uVar11;
  uintptr_t *puVar12;
  ulonglong uVar13;
  uintptr_t *_Memory_00;
  undefined1 *puVar14;
  undefined1 *puVar15;
  longlong lVar16;
  uintptr_t *puVar17;
  uintptr_t *puVar18;
  int iVar19;
  uint *_ThrdAddr;
  int iVar20;
  uintptr_t *puVar21;
  ulonglong uVar22;
  uintptr_t *puVar23;
  undefined4 local_res10 [2];
  int local_res18;
  undefined4 local_res20 [2];
  undefined8 uStackY_150;
  undefined1 auStackY_148 [8];
  undefined1 auStackY_140 [24];
  uintptr_t *local_118;
  uintptr_t *puStack_110;
  uintptr_t *local_108;
  int local_100;
  uint local_fc;
  int *local_f8;
  uintptr_t **local_e8;
  uintptr_t *puStack_e0;
  uintptr_t *local_d8;
  uintptr_t *puStack_d0;
  uintptr_t *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined1 *puStack_b0;
  ulonglong local_a8;
  int *local_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  
  local_e8 = (uintptr_t **)local_res10;
  puStack_e0 = (uintptr_t *)local_res20;
  local_d8 = &param_5;
  puStack_d0 = &param_6;
  local_c8 = &param_7;
  uStack_c0 = param_9;
  puStack_b0 = &param_8;
  local_res10[0] = param_2;
  local_res18 = param_3;
  local_res20[0] = param_4;
  local_b8 = param_1;
  local_100 = _Thrd_hardware_concurrency();
  puVar10 = puStack_b0;
  uVar9 = local_b8;
  uVar8 = uStack_c0;
  puVar7 = local_c8;
  puVar6 = puStack_d0;
  puVar5 = local_d8;
  puVar12 = puStack_e0;
  ppuVar4 = local_e8;
  puVar14 = auStackY_148;
  if (local_100 == 0) {
    local_100 = 4;
  }
  if (local_100 < 9) {
    if (local_100 < 2) goto LAB_18000495f;
  }
  else {
    local_100 = 8;
  }
  if (local_100 * 2 <= param_3) {
    local_118 = (uintptr_t *)0x0;
    puStack_110 = (uintptr_t *)0x0;
    local_108 = (uintptr_t *)0x0;
    uVar22 = (longlong)(param_3 + -1 + local_100) / (longlong)local_100;
    local_fc = (uint)uVar22;
    uVar22 = uVar22 & 0xffffffff;
    param_9._0_4_ = 0;
    puVar23 = (uintptr_t *)0x0;
    _Memory_00 = (uintptr_t *)0x0;
    puVar15 = auStackY_148;
    puVar17 = (uintptr_t *)0x0;
    if (local_100 == 0) {
LAB_18000489a:
      if (_Memory_00 != puVar17) {
        do {
          if ((int)_Memory_00[1] == 0) {
                    // WARNING: Subroutine does not return
            *(undefined8 *)(puVar15 + -8) = 0x1800049a4;
            std::_Throw_Cpp_error(1);
          }
          *(undefined8 *)(puVar15 + -8) = 0x1800048af;
          iVar20 = _Thrd_id();
          if ((int)_Memory_00[1] == iVar20) {
                    // WARNING: Subroutine does not return
            *(undefined **)(puVar15 + -8) = &UNK_1800049ea;
            std::_Throw_Cpp_error(5);
          }
          local_98 = (int *)*_Memory_00;
          uStack_90 = (undefined4)_Memory_00[1];
          uStack_8c = *(undefined4 *)((longlong)_Memory_00 + 0xc);
          *(undefined8 *)(puVar15 + -8) = 0x1800048ca;
          iVar20 = _Thrd_join(&local_98,0);
          if (iVar20 != 0) {
                    // WARNING: Subroutine does not return
            *(undefined **)(puVar15 + -8) = &UNK_1800049df;
            std::_Throw_Cpp_error(2);
          }
          *_Memory_00 = 0;
          _Memory_00[1] = 0;
          _Memory_00 = _Memory_00 + 2;
        } while (_Memory_00 != puVar17);
        puVar23 = *(uintptr_t **)(puVar15 + 0x40);
        puVar17 = *(uintptr_t **)(puVar15 + 0x38);
        _Memory_00 = *(uintptr_t **)(puVar15 + 0x30);
      }
      if (_Memory_00 == (uintptr_t *)0x0) {
        return;
      }
      if (_Memory_00 != puVar17) {
        puVar12 = _Memory_00;
        do {
          if ((int)puVar12[1] != 0) {
                    // WARNING: Subroutine does not return
            *(undefined8 *)(puVar15 + -8) = 0x180004947;
            terminate();
          }
          puVar12 = puVar12 + 2;
        } while (puVar12 != puVar17);
      }
      if (0xfff < ((longlong)puVar23 - (longlong)_Memory_00 & 0xfffffffffffffff0U)) {
        _Memory = (void *)_Memory_00[-1];
        _Memory_00 = (uintptr_t *)((longlong)_Memory_00 + (-8 - (longlong)_Memory));
        if (_Memory_00 < (uintptr_t *)0x20) {
          *(undefined8 *)(puVar15 + -8) = 0x18000493f;
          free(_Memory);
          return;
        }
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(5);
        puVar15 = puVar15 + 8;
      }
      *(undefined8 *)(puVar15 + -8) = 0x18000495d;
      free(_Memory_00);
      return;
    }
    do {
      puVar18 = puStack_110;
      iVar19 = (int)param_9 * (int)uVar22;
      iVar20 = iVar19 + (int)uVar22;
      if (param_3 < iVar20) {
        iVar20 = param_3;
      }
      puVar23 = local_108;
      _Memory_00 = local_118;
      puVar15 = auStackY_148;
      puVar17 = puStack_110;
      if (iVar20 <= iVar19) goto LAB_18000489a;
      if (puStack_110 == local_108) {
        uVar22 = (longlong)puStack_110 - (longlong)local_118;
        lVar16 = (longlong)uVar22 >> 4;
        if (lVar16 == 0xfffffffffffffff) {
                    // WARNING: Subroutine does not return
          FUN_18000a1e0();
        }
        uVar13 = (longlong)local_108 - (longlong)local_118 >> 4;
        if (0xfffffffffffffff - (uVar13 >> 1) < uVar13) {
LAB_1800049c9:
                    // WARNING: Subroutine does not return
          FUN_18000a140();
        }
        puVar17 = (uintptr_t *)(lVar16 + 1);
        puVar23 = (uintptr_t *)((uVar13 >> 1) + uVar13);
        puVar21 = puVar17;
        if (puVar17 <= puVar23) {
          puVar21 = puVar23;
        }
        if ((uintptr_t *)0xfffffffffffffff < puVar21) goto LAB_1800049c9;
        local_f8 = (int *)((longlong)puVar21 * 0x10);
        if (local_f8 == (int *)0x0) {
          _Memory_00 = (uintptr_t *)0x0;
        }
        else if (local_f8 < (int *)0x1000) {
          _Memory_00 = (uintptr_t *)FUN_1800129b0(local_f8);
        }
        else {
          if ((int *)((longlong)local_f8 + 0x27U) <= local_f8) goto LAB_1800049c9;
          uVar11 = FUN_1800129b0();
          if (uVar11 == 0) {
            pcVar1 = (code *)swi(0x29);
            (*pcVar1)(5);
            puVar14 = auStackY_140;
LAB_18000488c:
                    // WARNING: Subroutine does not return
            *(undefined8 *)(puVar14 + -8) = 0x180004892;
            terminate();
          }
          _Memory_00 = (uintptr_t *)(uVar11 + 0x27 & 0xffffffffffffffe0);
          _Memory_00[-1] = uVar11;
        }
        local_a8 = uVar22 & 0xfffffffffffffff0;
        puVar23 = (uintptr_t *)(local_a8 + 0x10 + (longlong)_Memory_00);
        local_e8 = &local_118;
        puStack_e0 = _Memory_00;
        local_d8 = puVar21;
        puStack_d0 = puVar23;
        local_c8 = puVar23;
        local_98 = (int *)FUN_1800129b0();
        uVar22 = local_a8;
        if (local_98 != (int *)0x0) {
          *local_98 = iVar20;
          local_98[1] = iVar19;
          *(uintptr_t ***)(local_98 + 2) = ppuVar4;
          *(uintptr_t **)(local_98 + 4) = puVar12;
          *(uintptr_t **)(local_98 + 6) = puVar5;
          *(uintptr_t **)(local_98 + 8) = puVar6;
          *(uintptr_t **)(local_98 + 10) = puVar7;
          *(undefined8 *)(local_98 + 0xc) = uVar8;
          *(undefined8 *)(local_98 + 0xe) = uVar9;
          *(undefined1 **)(local_98 + 0x10) = puVar10;
        }
        _ThrdAddr = (uint *)(local_a8 + 8 + (longlong)_Memory_00);
        uVar11 = _beginthreadex((void *)0x0,0,FUN_180002360,local_98,0,_ThrdAddr);
        *(uintptr_t *)(uVar22 + (longlong)_Memory_00) = uVar11;
        if (uVar11 == 0) {
          *_ThrdAddr = 0;
                    // WARNING: Subroutine does not return
          std::_Throw_Cpp_error(6);
        }
        puVar21 = _Memory_00;
        puVar3 = local_118;
        if (puVar18 == puStack_110) {
          for (; puVar3 != puStack_110; puVar3 = puVar3 + 2) {
            uVar11 = *puVar3;
            uVar2 = puVar3[1];
            *puVar3 = 0;
            puVar3[1] = 0;
            *puVar21 = uVar11;
            puVar21[1] = uVar2;
            puVar21 = puVar21 + 2;
          }
        }
        else {
          for (; puVar3 != puVar18; puVar3 = puVar3 + 2) {
            uVar11 = *puVar3;
            uVar2 = puVar3[1];
            *puVar3 = 0;
            puVar3[1] = 0;
            *puVar21 = uVar11;
            puVar21[1] = uVar2;
            puVar21 = puVar21 + 2;
          }
          for (; puVar18 != puStack_110; puVar18 = puVar18 + 2) {
            uVar11 = *puVar18;
            uVar2 = puVar18[1];
            *puVar18 = 0;
            puVar18[1] = 0;
            *puVar23 = uVar11;
            puVar23[1] = uVar2;
            puVar23 = puVar23 + 2;
          }
        }
        puVar23 = local_118;
        if (local_118 != (uintptr_t *)0x0) {
          for (; puVar23 != puStack_110; puVar23 = puVar23 + 2) {
            if ((int)puVar23[1] != 0) goto LAB_18000488c;
          }
          if (((longlong)local_108 - (longlong)local_118 & 0xfffffffffffffff0U) < 0x1000) {
            puVar23 = local_118;
          }
          else {
            puVar23 = (uintptr_t *)local_118[-1];
            if (0x1f < (ulonglong)((longlong)local_118 + (-8 - (longlong)puVar23))) {
              puVar23 = (uintptr_t *)0x5;
              pcVar1 = (code *)swi(0x29);
              (*pcVar1)();
              puVar15 = auStackY_140;
              goto LAB_18000489a;
            }
          }
          free(puVar23);
        }
        puStack_110 = _Memory_00 + (longlong)puVar17 * 2;
        local_108 = (uintptr_t *)((longlong)local_f8 + (longlong)_Memory_00);
        local_118 = _Memory_00;
        param_3 = local_res18;
      }
      else {
        local_f8 = (int *)FUN_1800129b0();
        if (local_f8 != (int *)0x0) {
          *local_f8 = iVar20;
          local_f8[1] = iVar19;
          *(uintptr_t ***)(local_f8 + 2) = ppuVar4;
          *(uintptr_t **)(local_f8 + 4) = puVar12;
          *(uintptr_t **)(local_f8 + 6) = puVar5;
          *(uintptr_t **)(local_f8 + 8) = puVar6;
          *(uintptr_t **)(local_f8 + 10) = puVar7;
          *(undefined8 *)(local_f8 + 0xc) = uVar8;
          *(undefined8 *)(local_f8 + 0xe) = uVar9;
          *(undefined1 **)(local_f8 + 0x10) = puVar10;
        }
        uVar11 = _beginthreadex((void *)0x0,0,FUN_180002360,local_f8,0,(uint *)(puVar18 + 1));
        *puVar18 = uVar11;
        if (uVar11 == 0) {
          *(uint *)(puVar18 + 1) = 0;
                    // WARNING: Subroutine does not return
          std::_Throw_Cpp_error(6);
        }
        puStack_110 = puStack_110 + 2;
      }
      param_9._0_4_ = (int)param_9 + 1;
      puVar23 = local_108;
      _Memory_00 = local_118;
      puVar15 = auStackY_148;
      puVar17 = puStack_110;
      if (local_100 <= (int)param_9) goto LAB_18000489a;
      uVar22 = (ulonglong)local_fc;
    } while( true );
  }
LAB_18000495f:
  FUN_180004e40(&local_e8,0,param_3);
  return;
}



undefined8 * FUN_1800049f0(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



undefined8 * FUN_180004a30(undefined8 *param_1,longlong param_2)

{
  *param_1 = std::exception::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  __std_exception_copy(param_2 + 8);
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}



undefined8 * FUN_180004a70(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}



// Library Function - Single Match
//  public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64
// 
// Library: Visual Studio 2019 Release

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  *(undefined ***)this = vftable;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  return this;
}



void FUN_180004b40(longlong *param_1)

{
  code *pcVar1;
  void *pvVar2;
  void *_Memory;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = auStack_28;
  puVar4 = auStack_28;
  pvVar2 = (void *)*param_1;
  if (pvVar2 == (void *)0x0) {
    return;
  }
  if (0xfff < (ulonglong)(param_1[2] - (longlong)pvVar2)) {
    _Memory = *(void **)((longlong)pvVar2 + -8);
    if ((ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)) < 0x20) goto LAB_180004b82;
    pcVar1 = (code *)swi(0x29);
    pvVar2 = (void *)(*pcVar1)(5);
    puVar3 = auStack_20;
  }
  _Memory = pvVar2;
  puVar4 = puVar3;
LAB_180004b82:
  *(undefined8 *)(puVar4 + -8) = 0x180004b87;
  free(_Memory);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



void FUN_180004ba0(longlong *param_1)

{
  code *pcVar1;
  void *_Memory;
  void *pvVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = auStack_28;
  puVar4 = auStack_28;
  pvVar2 = (void *)*param_1;
  if (pvVar2 == (void *)0x0) {
    return;
  }
  _Memory = pvVar2;
  if (0xfff < (ulonglong)((param_1[2] - (longlong)pvVar2 >> 2) * 4)) {
    _Memory = *(void **)((longlong)pvVar2 + -8);
    pvVar2 = (void *)((longlong)pvVar2 + (-8 - (longlong)_Memory));
    if (pvVar2 < (void *)0x20) goto LAB_180004bed;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar3 = auStack_20;
    _Memory = pvVar2;
  }
  puVar4 = puVar3;
LAB_180004bed:
  *(undefined8 *)(puVar4 + -8) = 0x180004bf5;
  free(_Memory);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



void FUN_180004c20(longlong *param_1)

{
  code *pcVar1;
  void *_Memory;
  void *pvVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = auStack_28;
  puVar4 = auStack_28;
  pvVar2 = (void *)*param_1;
  if (pvVar2 == (void *)0x0) {
    return;
  }
  _Memory = pvVar2;
  if (0xfff < (ulonglong)((param_1[2] - (longlong)pvVar2 >> 3) * 8)) {
    _Memory = *(void **)((longlong)pvVar2 + -8);
    pvVar2 = (void *)((longlong)pvVar2 + (-8 - (longlong)_Memory));
    if (pvVar2 < (void *)0x20) goto LAB_180004c6d;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar3 = auStack_20;
    _Memory = pvVar2;
  }
  puVar4 = puVar3;
LAB_180004c6d:
  *(undefined8 *)(puVar4 + -8) = 0x180004c75;
  free(_Memory);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



void FUN_180004c90(longlong *param_1)

{
  code *pcVar1;
  void *pvVar2;
  void *_Memory;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = auStack_28;
  puVar4 = auStack_28;
  pvVar2 = (void *)*param_1;
  if (pvVar2 == (void *)0x0) {
    return;
  }
  if (0xfff < (param_1[2] - (longlong)pvVar2 & 0xffffffffffffffc0U)) {
    _Memory = *(void **)((longlong)pvVar2 + -8);
    if ((ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)) < 0x20) goto LAB_180004cd6;
    pcVar1 = (code *)swi(0x29);
    pvVar2 = (void *)(*pcVar1)(5);
    puVar3 = auStack_20;
  }
  _Memory = pvVar2;
  puVar4 = puVar3;
LAB_180004cd6:
  *(undefined8 *)(puVar4 + -8) = 0x180004cdb;
  free(_Memory);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



void FUN_180004d00(longlong *param_1)

{
  code *pcVar1;
  void *pvVar2;
  void *pvVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar4 = auStack_28;
  puVar5 = auStack_28;
  pvVar3 = (void *)*param_1;
  if (pvVar3 == (void *)0x0) {
    return;
  }
  for (pvVar2 = pvVar3; pvVar2 != (void *)param_1[1]; pvVar2 = (void *)((longlong)pvVar2 + 0x10)) {
    if (*(int *)((longlong)pvVar2 + 8) != 0) {
                    // WARNING: Subroutine does not return
      terminate();
    }
  }
  pvVar2 = pvVar3;
  if (0xfff < (param_1[2] - (longlong)pvVar3 & 0xfffffffffffffff0U)) {
    pvVar2 = *(void **)((longlong)pvVar3 + -8);
    pvVar3 = (void *)((longlong)pvVar3 + (-8 - (longlong)pvVar2));
    if (pvVar3 < (void *)0x20) goto LAB_180004d6a;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar4 = auStack_20;
    pvVar2 = pvVar3;
  }
  puVar5 = puVar4;
LAB_180004d6a:
  *(undefined8 *)(puVar5 + -8) = 0x180004d72;
  free(pvVar2);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



void FUN_180004d90(longlong param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  longlong lVar3;
  void *_Memory;
  
  _Memory = *(void **)(param_1 + 8);
  if (_Memory == (void *)0x0) {
    return;
  }
  for (lVar3 = *(longlong *)(param_1 + 0x18); lVar3 != *(longlong *)(param_1 + 0x20);
      lVar3 = lVar3 + 0x10) {
    if (*(int *)(lVar3 + 8) != 0) {
                    // WARNING: Subroutine does not return
      terminate();
    }
  }
  if (0xfff < (ulonglong)(*(longlong *)(param_1 + 0x10) << 4)) {
    puVar1 = (undefined8 *)((longlong)_Memory + -8);
    _Memory = (void *)((longlong)_Memory + (-8 - (longlong)*puVar1));
    if (_Memory < (void *)0x20) {
      free((void *)*puVar1);
      return;
    }
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
  }
  free(_Memory);
  return;
}



void FUN_180004e40(undefined8 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  int iVar11;
  longlong lVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  int local_res10;
  int local_res20;
  int local_e8;
  int local_e4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  
  if (param_2 < param_3) {
    fVar17 = 0.0;
    local_res10 = param_2;
    do {
      local_e4 = 0;
      if (0 < *(int *)*param_1) {
        do {
          fVar18 = 0.0;
          iVar11 = *(int *)param_1[1] * local_e4;
          local_e8 = *(int *)param_1[2] * local_res10;
          iVar1 = *(int *)param_1[1] + iVar11;
          if (*(int *)param_1[3] < iVar1) {
            iVar1 = *(int *)param_1[3];
          }
          iVar2 = *(int *)param_1[2] + local_e8;
          if (*(int *)param_1[4] < iVar2) {
            iVar2 = *(int *)param_1[4];
          }
          iVar14 = 0;
          local_res20 = 0;
          if (local_e8 < iVar2) {
            do {
              if (iVar11 < iVar1) {
                puVar6 = (undefined8 *)param_1[5];
                fVar15 = *(float *)*puVar6;
                iVar14 = *(int *)puVar6[1];
                iVar4 = *(int *)puVar6[3];
                uVar5 = *(undefined4 *)puVar6[5];
                uVar7 = *(undefined8 *)puVar6[4];
                fVar3 = *(float *)puVar6[2];
                iVar13 = iVar11;
                do {
                  iVar9 = (int)((float)iVar13 * fVar15);
                  if (iVar14 <= (int)((float)iVar13 * fVar15)) {
                    iVar9 = iVar14 + -1;
                  }
                  iVar8 = (int)((float)local_e8 * fVar3);
                  if (iVar4 <= (int)((float)local_e8 * fVar3)) {
                    iVar8 = iVar4 + -1;
                  }
                  FUN_18000c890(uVar7,uVar5,iVar9,iVar8,&local_d0);
                  if ((local_c4 <= 0.0001) ||
                     (fVar16 = (local_cc * 0.7152 + local_d0 * 0.2126 + local_c8 * 0.0722) /
                               local_c4, fVar16 < fVar17)) {
                    fVar10 = 0.0;
                  }
                  else {
                    fVar10 = 1.0;
                    if (fVar16 <= 1.0) {
                      fVar10 = fVar16;
                    }
                  }
                  iVar13 = iVar13 + 1;
                  fVar18 = fVar18 + fVar10;
                } while (iVar13 < iVar1);
                local_res20 = local_res20 + (iVar1 - iVar11);
                iVar14 = local_res20;
              }
              local_e8 = local_e8 + 1;
            } while (local_e8 < iVar2);
            if (iVar14 < 1) goto LAB_1800050ae;
            fVar18 = fVar18 / (float)iVar14;
            if (fVar17 <= fVar18) {
              fVar15 = 1.0;
              if (fVar18 <= 1.0) {
                fVar15 = fVar18;
              }
            }
            else {
              fVar15 = 0.0;
            }
          }
          else {
LAB_1800050ae:
            fVar15 = 0.5;
          }
          if (*(int *)param_1[7] != 0) {
            fVar15 = 1.0 - fVar15;
          }
          lVar12 = (longlong)local_e4;
          local_e4 = local_e4 + 1;
          *(float *)(*(longlong *)param_1[6] + 0x20 +
                    ((longlong)*(int *)*param_1 * (longlong)local_res10 + lVar12) * 0x40) = fVar15;
        } while (local_e4 < *(int *)*param_1);
      }
      local_res10 = local_res10 + 1;
    } while (local_res10 < param_3);
  }
  return;
}



void FUN_1800051a0(undefined8 *param_1,int param_2,int param_3)

{
  undefined8 *puVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  uint uVar5;
  float *pfVar6;
  longlong lVar7;
  int iVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float local_188;
  float local_184;
  float local_180;
  float local_17c;
  float local_168;
  float local_164 [12];
  float fStack_134;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  
  do {
    if (param_3 <= param_2) {
      return;
    }
    iVar12 = 0;
    iVar10 = *(int *)*param_1 + param_2;
    if (0 < *(int *)param_1[1]) {
      do {
        iVar11 = *(int *)param_1[2] + iVar12;
        if ((((iVar11 < 0) || (*(int *)param_1[3] <= iVar11)) || (iVar10 < 0)) ||
           (*(int *)param_1[4] <= iVar10)) {
          pfVar2 = (float *)param_1[7];
          fVar14 = pfVar2[3];
          lVar9 = (longlong)*(int *)(*(longlong *)param_1[5] + 0x20) * (longlong)param_2 +
                  *(longlong *)(*(longlong *)param_1[5] + 0x18);
          lVar7 = (longlong)iVar12;
          if (*(int *)param_1[6] == 2) {
            fVar13 = 0.0;
            if (0.0 <= fVar14) {
              fVar13 = fVar14;
            }
            *(float *)(lVar9 + lVar7 * 0x10) = fVar13;
            fVar14 = 0.0;
            if (0.0 <= *pfVar2) {
              fVar14 = *pfVar2;
            }
            *(float *)(lVar9 + 4 + lVar7 * 0x10) = fVar14;
            fVar14 = 0.0;
            if (0.0 <= pfVar2[1]) {
              fVar14 = pfVar2[1];
            }
            *(float *)(lVar9 + 8 + lVar7 * 0x10) = fVar14;
            fVar14 = 0.0;
            if (0.0 <= pfVar2[2]) {
              fVar14 = pfVar2[2];
            }
            *(float *)(lVar9 + 0xc + lVar7 * 0x10) = fVar14;
          }
          else {
            if (*(int *)param_1[6] != 1) {
              if (0.0 <= fVar14) {
                fVar13 = 1.0;
                if (fVar14 <= 1.0) {
                  fVar13 = fVar14;
                }
              }
              else {
                fVar13 = 0.0;
              }
              *(char *)(lVar9 + lVar7 * 4) = (char)(int)(fVar13 * 255.0 + 0.5);
              fVar14 = *pfVar2;
              if (0.0 <= fVar14) {
                fVar13 = 1.0;
                if (fVar14 <= 1.0) {
                  fVar13 = fVar14;
                }
              }
              else {
                fVar13 = 0.0;
              }
              *(char *)(lVar9 + 1 + lVar7 * 4) = (char)(int)(fVar13 * 255.0 + 0.5);
              fVar14 = pfVar2[1];
              if (0.0 <= fVar14) {
                fVar13 = 1.0;
                if (fVar14 <= 1.0) {
                  fVar13 = fVar14;
                }
              }
              else {
                fVar13 = 0.0;
              }
              *(char *)(lVar9 + 2 + lVar7 * 4) = (char)(int)(fVar13 * 255.0 + 0.5);
              fVar14 = pfVar2[2];
              if (0.0 <= fVar14) {
                fVar13 = 1.0;
                if (fVar14 <= 1.0) {
                  fVar13 = fVar14;
                }
              }
              else {
                fVar13 = 0.0;
              }
              goto LAB_180005ad5;
            }
            if (0.0 <= fVar14) {
              fVar13 = 1.0;
              if (fVar14 <= 1.0) {
                fVar13 = fVar14;
              }
            }
            else {
              fVar13 = 0.0;
            }
            *(short *)(lVar9 + lVar7 * 8) = (short)(int)(fVar13 * 32768.0 + 0.5);
            fVar14 = *pfVar2;
            if (0.0 <= fVar14) {
              fVar13 = 1.0;
              if (fVar14 <= 1.0) {
                fVar13 = fVar14;
              }
            }
            else {
              fVar13 = 0.0;
            }
            *(short *)(lVar9 + 2 + lVar7 * 8) = (short)(int)(fVar13 * 32768.0 + 0.5);
            fVar14 = pfVar2[1];
            if (0.0 <= fVar14) {
              fVar13 = 1.0;
              if (fVar14 <= 1.0) {
                fVar13 = fVar14;
              }
            }
            else {
              fVar13 = 0.0;
            }
            *(short *)(lVar9 + 4 + lVar7 * 8) = (short)(int)(fVar13 * 32768.0 + 0.5);
            fVar14 = pfVar2[2];
            if (0.0 <= fVar14) {
              fVar13 = 1.0;
              if (fVar14 <= 1.0) {
                fVar13 = fVar14;
              }
            }
            else {
              fVar13 = 0.0;
            }
            *(short *)(lVar9 + 6 + lVar7 * 8) = (short)(int)(fVar13 * 32768.0 + 0.5);
          }
        }
        else {
          fVar14 = *(float *)param_1[8];
          iVar8 = (int)((float)iVar10 * *(float *)param_1[9] + 0.5);
          puVar1 = (undefined8 *)param_1[0x13];
          pfVar2 = (float *)param_1[0x12];
          local_128 = *puVar1;
          uStack_120 = puVar1[1];
          local_118 = puVar1[2];
          uStack_110 = puVar1[3];
          local_108 = puVar1[4];
          uStack_100 = puVar1[5];
          local_f8 = puVar1[6];
          uStack_f0 = puVar1[7];
          local_e8 = puVar1[8];
          uStack_e0 = puVar1[9];
          if (pfVar2[1] * pfVar2[1] + *pfVar2 * *pfVar2 <= 1e-06) {
            FUN_180005fb0(&local_128);
          }
          else {
            FUN_180005fb0(&local_128);
            FUN_180005fb0(&local_128);
            FUN_180005fb0(&local_128);
            pfVar6 = local_164;
            if (local_164[0] <= local_164[4]) {
              pfVar6 = local_164 + 4;
            }
            pfVar4 = local_164 + 8;
            if (local_164[8] < *pfVar6) {
              pfVar4 = pfVar6;
            }
            local_17c = *pfVar4;
            local_188 = local_164[1];
            local_184 = local_164[6];
            local_180 = local_168;
          }
          fVar13 = pfVar2[6];
          if (0.0 < pfVar2[4]) {
            fVar15 = 1.4013e-45;
            if (0 < (int)pfVar2[5]) {
              fVar15 = pfVar2[5];
            }
            iVar3 = 0;
            if (-1 < iVar8) {
              iVar3 = iVar8;
            }
            if (((longlong)iVar3 / (longlong)(int)fVar15 & 1U) != 0) {
              fVar13 = (1.0 - pfVar2[4] * 0.6) * fVar13;
            }
          }
          local_188 = local_188 * fVar13;
          local_184 = local_184 * fVar13;
          local_180 = local_180 * fVar13;
          if (0.0 <= local_17c) {
            fStack_18c = 1.0;
            if (local_17c <= 1.0) {
              fStack_18c = local_17c;
            }
          }
          else {
            fStack_18c = 0.0;
          }
          if (0.0 <= local_188) {
            local_198 = 1.0;
            if (local_188 <= 1.0) {
              local_198 = local_188;
            }
          }
          else {
            local_198 = 0.0;
          }
          local_198 = local_198 * fStack_18c;
          if (0.0 <= local_184) {
            fStack_194 = 1.0;
            if (local_184 <= 1.0) {
              fStack_194 = local_184;
            }
          }
          else {
            fStack_194 = 0.0;
          }
          fStack_194 = fStack_194 * fStack_18c;
          if (0.0 <= local_180) {
            fStack_190 = 1.0;
            if (local_180 <= 1.0) {
              fStack_190 = local_180;
            }
          }
          else {
            fStack_190 = 0.0;
          }
          lVar7 = param_1[0x12];
          fStack_190 = fStack_190 * fStack_18c;
          if (0.0 < *(float *)(lVar7 + 0x1c)) {
            uVar5 = (int)(fVar14 * (float)iVar11 + 0.5) * 0x165667b1 +
                    *(int *)(lVar7 + 0x24) * -0x52e73c1 + *(int *)(lVar7 + 0x20) * -0x7a143589 +
                    iVar8 * 0x27d4eb2f;
            uVar5 = (uVar5 >> 0xd ^ uVar5) * 0x4bf19f61;
            fVar14 = (float)((uVar5 >> 0x10 ^ uVar5) & 0xffffff) * 5.9604645e-08;
            fVar13 = ((fVar14 + fVar14) - 1.0) * *(float *)(lVar7 + 0x1c) * 0.5;
            fVar14 = ABS(fVar13) + fStack_18c;
            if (0.0 <= fVar14) {
              fStack_18c = 1.0;
              if (fVar14 <= 1.0) {
                fStack_18c = fVar14;
              }
            }
            else {
              fStack_18c = 0.0;
            }
            fVar13 = fStack_18c * fVar13;
            fVar14 = fVar13 + local_198;
            if (0.0 <= fVar14) {
              local_198 = 1.0;
              if (fVar14 <= 1.0) {
                local_198 = fVar14;
              }
            }
            else {
              local_198 = 0.0;
            }
            fVar14 = fVar13 + fStack_194;
            if (0.0 <= fVar14) {
              fStack_194 = 1.0;
              if (fVar14 <= 1.0) {
                fStack_194 = fVar14;
              }
            }
            else {
              fStack_194 = 0.0;
            }
            fVar13 = fVar13 + fStack_190;
            if (0.0 <= fVar13) {
              fStack_190 = 1.0;
              if (fVar13 <= 1.0) {
                fStack_190 = fVar13;
              }
            }
            else {
              fStack_190 = 0.0;
            }
          }
          fVar14 = *(float *)param_1[0x14];
          if (fVar14 < 1.0) {
            fVar13 = fVar14;
            fVar15 = fVar14;
            fVar16 = fVar14;
            FUN_18000c890(*(undefined8 *)param_1[0x15],*(undefined4 *)param_1[6],iVar11,iVar10,
                          local_164 + 9);
            local_198 = (local_198 - local_164[9]) * fVar14 + local_164[9];
            fStack_194 = (fStack_194 - local_164[10]) * fVar13 + local_164[10];
            fStack_190 = (fStack_190 - local_164[0xb]) * fVar15 + local_164[0xb];
            fStack_18c = (fStack_18c - fStack_134) * fVar16 + fStack_134;
          }
          lVar9 = (longlong)*(int *)(*(longlong *)param_1[5] + 0x20) * (longlong)param_2 +
                  *(longlong *)(*(longlong *)param_1[5] + 0x18);
          lVar7 = (longlong)iVar12;
          if (*(int *)param_1[6] == 2) {
            fVar14 = 0.0;
            if (0.0 <= fStack_18c) {
              fVar14 = fStack_18c;
            }
            fVar13 = 0.0;
            if (0.0 <= local_198) {
              fVar13 = local_198;
            }
            *(float *)(lVar9 + lVar7 * 0x10) = fVar14;
            *(float *)(lVar9 + 4 + lVar7 * 0x10) = fVar13;
            fVar14 = 0.0;
            if (0.0 <= fStack_194) {
              fVar14 = fStack_194;
            }
            fVar13 = 0.0;
            if (0.0 <= fStack_190) {
              fVar13 = fStack_190;
            }
            *(float *)(lVar9 + 8 + lVar7 * 0x10) = fVar14;
            *(float *)(lVar9 + 0xc + lVar7 * 0x10) = fVar13;
          }
          else if (*(int *)param_1[6] == 1) {
            if (0.0 <= fStack_18c) {
              fVar14 = 1.0;
              if (fStack_18c <= 1.0) {
                fVar14 = fStack_18c;
              }
            }
            else {
              fVar14 = 0.0;
            }
            *(short *)(lVar9 + lVar7 * 8) = (short)(int)(fVar14 * 32768.0 + 0.5);
            if (0.0 <= local_198) {
              fVar14 = 1.0;
              if (local_198 <= 1.0) {
                fVar14 = local_198;
              }
            }
            else {
              fVar14 = 0.0;
            }
            *(short *)(lVar9 + 2 + lVar7 * 8) = (short)(int)(fVar14 * 32768.0 + 0.5);
            if (0.0 <= fStack_194) {
              fVar14 = 1.0;
              if (fStack_194 <= 1.0) {
                fVar14 = fStack_194;
              }
            }
            else {
              fVar14 = 0.0;
            }
            *(short *)(lVar9 + 4 + lVar7 * 8) = (short)(int)(fVar14 * 32768.0 + 0.5);
            if (0.0 <= fStack_190) {
              fVar14 = 1.0;
              if (fStack_190 <= 1.0) {
                fVar14 = fStack_190;
              }
            }
            else {
              fVar14 = 0.0;
            }
            *(short *)(lVar9 + 6 + lVar7 * 8) = (short)(int)(fVar14 * 32768.0 + 0.5);
          }
          else {
            if (0.0 <= fStack_18c) {
              fVar14 = 1.0;
              if (fStack_18c <= 1.0) {
                fVar14 = fStack_18c;
              }
            }
            else {
              fVar14 = 0.0;
            }
            *(char *)(lVar9 + lVar7 * 4) = (char)(int)(fVar14 * 255.0 + 0.5);
            if (0.0 <= local_198) {
              fVar14 = 1.0;
              if (local_198 <= 1.0) {
                fVar14 = local_198;
              }
            }
            else {
              fVar14 = 0.0;
            }
            *(char *)(lVar9 + 1 + lVar7 * 4) = (char)(int)(fVar14 * 255.0 + 0.5);
            if (0.0 <= fStack_194) {
              fVar14 = 1.0;
              if (fStack_194 <= 1.0) {
                fVar14 = fStack_194;
              }
            }
            else {
              fVar14 = 0.0;
            }
            *(char *)(lVar9 + 2 + lVar7 * 4) = (char)(int)(fVar14 * 255.0 + 0.5);
            if (0.0 <= fStack_190) {
              fVar13 = 1.0;
              if (fStack_190 <= 1.0) {
                fVar13 = fStack_190;
              }
            }
            else {
              fVar13 = 0.0;
            }
LAB_180005ad5:
            *(char *)(lVar9 + 3 + (longlong)iVar12 * 4) = (char)(int)(fVar13 * 255.0 + 0.5);
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < *(int *)param_1[1]);
    }
    param_2 = param_2 + 1;
  } while( true );
}



void FUN_180005ba0(undefined8 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  int *piVar5;
  int *piVar6;
  longlong lVar7;
  int iVar8;
  int *piVar9;
  float *pfVar10;
  int *piVar11;
  uint uVar12;
  ulonglong uVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  int local_res10;
  int local_res20;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  
  if (param_2 < param_3) {
    piVar9 = (int *)*param_1;
    local_res10 = param_2;
    do {
      if (0 < *piVar9) {
        piVar5 = (int *)param_1[1];
        piVar6 = (int *)param_1[2];
        piVar11 = (int *)param_1[3];
        lVar3 = *(longlong *)param_1[6];
        piVar14 = (int *)param_1[4];
        pfVar10 = (float *)param_1[8];
        local_res20 = 0;
        do {
          fVar20 = 0.0;
          fVar21 = 0.0;
          iVar8 = *piVar5 * local_res20;
          uVar12 = *piVar6 * local_res10;
          fVar22 = 0.0;
          fVar19 = 0.0;
          iVar1 = *piVar5 + iVar8;
          iVar17 = *piVar6 + uVar12;
          if (*piVar11 < iVar1) {
            iVar1 = *piVar11;
          }
          if (*piVar14 < iVar17) {
            iVar17 = *piVar14;
          }
          iVar16 = 0;
          if ((int)uVar12 < iVar17) {
            do {
              uVar13 = (ulonglong)uVar12;
              if (iVar8 < iVar1) {
                uVar2 = *(undefined4 *)((undefined8 *)param_1[5])[1];
                uVar4 = **(undefined8 **)param_1[5];
                iVar15 = iVar8;
                do {
                  FUN_18000c890(uVar4,uVar2,iVar15,fVar19,&local_e8);
                  uVar12 = (uint)uVar13;
                  fVar20 = fVar20 + local_e8;
                  fVar21 = fVar21 + local_e4;
                  fVar22 = fVar22 + local_e0;
                  fVar19 = fVar19 + local_dc;
                  iVar15 = iVar15 + 1;
                } while (iVar15 < iVar1);
                iVar16 = iVar16 + (iVar1 - iVar8);
              }
              uVar12 = uVar12 + 1;
            } while ((int)uVar12 < iVar17);
            pfVar10 = (float *)param_1[8];
            if (0 < iVar16) {
              fVar18 = 1.0 / (float)iVar16;
              fVar20 = fVar20 * fVar18;
              fVar21 = fVar21 * fVar18;
              fVar22 = fVar22 * fVar18;
              fVar19 = fVar19 * fVar18;
            }
          }
          piVar9 = (int *)*param_1;
          lVar7 = ((longlong)local_res10 * (longlong)*piVar9 + (longlong)local_res20) * 0x40;
          *(float *)(lVar3 + 0x10 + lVar7) = fVar19;
          if (fVar19 <= 1e-06) {
            fVar19 = 0.0;
            fVar21 = 0.0;
            fVar20 = 0.0;
          }
          else {
            fVar19 = 1.0 / fVar19;
            fVar20 = fVar19 * fVar20;
            fVar21 = fVar19 * fVar21;
            fVar19 = fVar19 * fVar22;
          }
          *(float *)(lVar3 + 4 + lVar7) = fVar20;
          *(float *)(lVar3 + 8 + lVar7) = fVar21;
          *(float *)(lVar3 + 0xc + lVar7) = fVar19;
          if (0.04045 < fVar19) {
            fVar19 = powf((fVar19 + 0.055) / 1.055,2.4);
          }
          else {
            fVar19 = fVar19 / 12.92;
          }
          if (0.04045 < fVar21) {
            fVar21 = powf((fVar21 + 0.055) / 1.055,2.4);
          }
          else {
            fVar21 = fVar21 / 12.92;
          }
          if (0.04045 < fVar20) {
            fVar20 = powf((fVar20 + 0.055) / 1.055,2.4);
          }
          else {
            fVar20 = fVar20 / 12.92;
          }
          fVar19 = fVar21 * 0.7152 + fVar20 * 0.2126 + fVar19 * 0.0722;
          if (0.0 <= fVar19) {
            fVar21 = 1.0;
            if (fVar19 <= 1.0) {
              fVar21 = fVar19;
            }
            if (0.0031308 < fVar21) {
              fVar19 = powf(fVar21,0.41666666);
              fVar21 = fVar19 * 1.055 - 0.055;
            }
            else {
              fVar21 = fVar21 * 12.92;
            }
          }
          else {
            fVar21 = 0.0;
          }
          fVar19 = (fVar21 - 0.5) * *(float *)param_1[7] + 0.5;
          if (0.0 <= fVar19) {
            fVar21 = 1.0;
            if (fVar19 <= 1.0) {
              fVar21 = fVar19;
            }
          }
          else {
            fVar21 = 0.0;
          }
          fVar19 = powf(fVar21,*pfVar10);
          piVar5 = (int *)param_1[1];
          local_res20 = local_res20 + 1;
          piVar6 = (int *)param_1[2];
          piVar11 = (int *)param_1[3];
          piVar14 = (int *)param_1[4];
          *(float *)(lVar3 + lVar7) = fVar19;
        } while (local_res20 < *piVar9);
      }
      local_res10 = local_res10 + 1;
    } while (local_res10 < param_3);
  }
  return;
}



void FUN_180005fb0(undefined8 *param_1,float param_2,float param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  undefined1 local_68 [40];
  
  fVar8 = floorf(param_2);
  iVar5 = 0;
  if (-1 < (int)fVar8) {
    iVar5 = (int)fVar8;
  }
  iVar7 = *(int *)*param_1 + -1;
  if (iVar5 < *(int *)*param_1) {
    iVar7 = iVar5;
  }
  fVar8 = floorf(param_3);
  iVar5 = 0;
  if (-1 < (int)fVar8) {
    iVar5 = (int)fVar8;
  }
  iVar1 = *(int *)param_1[2];
  iVar3 = *(int *)param_1[1] + -1;
  if (iVar5 < *(int *)param_1[1]) {
    iVar3 = iVar5;
  }
  iVar5 = *(int *)param_1[3];
  iVar4 = iVar5 + -1;
  if (iVar7 / iVar1 < iVar5) {
    iVar4 = iVar7 / iVar1;
  }
  iVar6 = *(int *)param_1[4];
  iVar2 = *(int *)param_1[5] + -1;
  if (iVar3 / iVar6 < *(int *)param_1[5]) {
    iVar2 = iVar3 / iVar6;
  }
  FUN_18000c890(*(undefined8 *)param_1[6],*(undefined4 *)param_1[7],iVar7,iVar3,local_68);
  FUN_18000ab30(((longlong)iVar5 * (longlong)iVar2 + (longlong)iVar4) * 0x40 +
                *(longlong *)param_1[8],(float)(iVar7 - iVar1 * iVar4) / (float)iVar1,
                (float)(iVar3 - iVar6 * iVar2) / (float)iVar6,param_1[9],local_68,param_4);
  return;
}



undefined8 * FUN_180006100(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = std::exception::vftable;
  __std_exception_destroy(param_1 + 1);
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

undefined8
FUN_180006150(longlong param_1,uintptr_t param_2,longlong param_3,longlong param_4,uintptr_t param_5
             ,longlong param_6,float param_7,uint param_8,int param_9,int param_10,int param_11,
             int param_12)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  double dVar5;
  bool bVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  longlong *plVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  int *piVar17;
  float *pfVar18;
  int *piVar19;
  float *pfVar20;
  void **ppvVar21;
  float *pfVar22;
  float *pfVar23;
  float *pfVar24;
  int **ppiVar25;
  float *pfVar26;
  uintptr_t *puVar27;
  char cVar28;
  int iVar29;
  uintptr_t uVar30;
  void *pvVar31;
  uint uVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  bool bVar39;
  double dVar40;
  undefined1 auVar41 [12];
  undefined1 auVar42 [12];
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  longlong local_res18 [2];
  undefined8 uStackY_3f0;
  undefined1 auStackY_3e8 [8];
  undefined1 auStackY_3e0 [24];
  float local_398;
  float local_394;
  float local_390;
  float local_38c;
  int local_388;
  int local_384;
  int local_380;
  int local_37c;
  float local_378;
  float local_374;
  float local_370;
  float local_36c;
  int *local_368;
  int local_360;
  int local_35c;
  int local_358;
  int local_354;
  undefined4 local_350;
  undefined4 local_34c;
  float local_348;
  float local_344;
  uintptr_t local_340;
  float *local_338;
  float *pfStack_330;
  float *local_328;
  int *local_320;
  undefined8 *local_318;
  undefined1 *local_310;
  void *local_308;
  undefined8 uStack_300;
  longlong local_2f8;
  void *local_2f0;
  undefined8 uStack_2e8;
  longlong local_2e0;
  uintptr_t local_2d8;
  void *local_2d0;
  undefined8 uStack_2c8;
  longlong local_2c0;
  int *local_2b8;
  int *piStack_2b0;
  int *local_2a8;
  int *piStack_2a0;
  int *local_298;
  longlong *plStack_290;
  undefined1 *local_288;
  undefined8 *puStack_280;
  undefined4 *local_278;
  undefined4 *puStack_270;
  float *local_268;
  int *piStack_260;
  float *local_258;
  int *piStack_250;
  float *local_248;
  void **ppvStack_240;
  float *local_238;
  float *pfStack_230;
  float *local_228;
  int **ppiStack_220;
  float *local_218;
  uintptr_t *puStack_210;
  int *local_208;
  int *local_200;
  int *local_1f8;
  float *local_1f0;
  int *local_1e8;
  float *local_1e0;
  uintptr_t *local_1d8;
  undefined1 *local_1d0;
  void **local_1c8;
  int *local_1c0;
  int local_1b8;
  undefined4 uStack_1b4;
  ulonglong uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  void *local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  longlong local_138;
  ulonglong uStack_130;
  float local_128;
  float local_124;
  float local_120;
  int local_11c;
  float local_118;
  int local_114;
  float local_110;
  float local_10c;
  uint local_108;
  float local_104;
  undefined8 local_100;
  undefined8 uStack_f8;
  ulonglong local_f0;
  
  local_f0 = DAT_180030500 ^ (ulonglong)auStackY_3e8;
  local_2d8 = param_5;
  local_388 = *(int *)(param_2 + 0x24);
  local_384 = *(int *)(param_2 + 0x28);
  local_358 = *(int *)(param_3 + 0x24);
  puVar35 = auStackY_3e8;
  if (((local_388 < 1) || (puVar35 = auStackY_3e8, local_384 < 1)) ||
     (puVar35 = auStackY_3e8, local_358 < 1)) goto LAB_180007034;
  iVar1 = *(int *)(param_3 + 0x28);
  puVar35 = auStackY_3e8;
  if (iVar1 < 1) goto LAB_180007034;
  fVar46 = 1.0;
  if (*(uint *)(param_1 + 0x120) == 0) {
    fVar47 = 1.0;
  }
  else {
    fVar47 = (float)*(int *)(param_1 + 0x11c) / (float)*(uint *)(param_1 + 0x120);
  }
  if (*(uint *)(param_1 + 0x128) == 0) {
    fVar48 = 1.0;
  }
  else {
    fVar48 = (float)*(int *)(param_1 + 0x124) / (float)*(uint *)(param_1 + 0x128);
  }
  auVar41 = ZEXT812(0x3f800000);
  if (0.0 < fVar47) {
    auVar41._4_8_ = auVar41._4_8_;
    auVar41._0_4_ = auVar41._0_4_ / fVar47;
  }
  local_350 = auVar41._0_4_;
  auVar42 = ZEXT812(0x3f800000);
  if (0.0 < fVar48) {
    auVar42._4_8_ = auVar42._4_8_;
    auVar42._0_4_ = auVar42._0_4_ / fVar48;
  }
  local_34c = auVar42._0_4_;
  local_188 = (void *)0x0;
  uStack_180 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  iVar29 = *(int *)(*(longlong *)(param_4 + 0x10) + 0x38);
  uStack_1b4 = *(undefined4 *)(*(longlong *)(param_4 + 0x28) + 0x38);
  uStack_1b0 = (ulonglong)
               CONCAT14(*(int *)(*(longlong *)(param_4 + 0x40) + 0x38) != 0,
                        *(undefined4 *)(*(longlong *)(param_4 + 0x58) + 0x38));
  local_1a8 = CONCAT44((float)(*(double *)(*(longlong *)(param_4 + 0x50) + 0x38) / 100.0),
                       (float)*(double *)(*(longlong *)(param_4 + 0x48) + 0x38));
  fVar49 = (float)(*(double *)(*(longlong *)(param_4 + 0x68) + 0x38) / 100.0);
  uStack_1a0 = CONCAT44(fVar49,(float)((*(double *)(*(longlong *)(param_4 + 0x60) + 0x38) / 100.0) *
                                      0.6000000238418579));
  local_198 = CONCAT44((float)(*(double *)(*(longlong *)(param_4 + 0x80) + 0x38) / 100.0),
                       (float)(*(double *)(*(longlong *)(param_4 + 0x78) + 0x38) / 100.0));
  uVar32 = (uint)(*(int *)(*(longlong *)(param_4 + 0x88) + 0x38) != 0);
  local_138 = (ulonglong)param_8 << 0x20;
  local_378 = *(float *)(*(longlong *)(param_4 + 0x160) + 0x38);
  uStack_130 = (ulonglong)(uint)local_378;
  if (((param_5 == 0) || (*(longlong *)(param_5 + 0x18) == 0)) ||
     ((*(int *)(param_5 + 0x24) < 1 || (*(int *)(param_5 + 0x28) < 1)))) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if ((iVar29 != 6) || (!bVar6)) {
    uStack_190 = (ulonglong)uVar32;
    if (iVar29 == 6) {
      iVar29 = 1;
    }
    local_38c = 0.0;
  }
  else {
    uStack_190 = CONCAT44(1,uVar32);
    local_38c = 1.4013e-45;
  }
  if ((((param_6 == 0) || (*(longlong *)(param_6 + 0x18) == 0)) || (*(int *)(param_6 + 0x24) < 1))
     || (*(int *)(param_6 + 0x28) < 1)) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  iVar37 = *(int *)(*(longlong *)(param_4 + 0xd8) + 0x38);
  bVar39 = *(int *)(*(longlong *)(param_4 + 0xe8) + 0x38) != 0;
  local_178 = (ulonglong)CONCAT14(bVar39,iVar37);
  uStack_170 = CONCAT44((float)(*(double *)(*(longlong *)(param_4 + 0x108) + 0x38) / 100.0),
                        (float)(*(double *)(*(longlong *)(param_4 + 0x100) + 0x38) / 100.0));
  dVar5 = 0.0;
  if (iVar37 == 3) {
    if (!bVar6) {
      local_178 = CONCAT44((uint)bVar39,2);
    }
LAB_1800064f2:
    dVar40 = (*(double *)(*(longlong *)(param_4 + 0xf0) + 0x38) / 100.0) * 80.0;
  }
  else {
    if (iVar37 != 1) goto LAB_1800064f2;
    dVar40 = 0.0;
  }
  local_370 = (float)dVar40;
  fVar44 = ((float)*(int *)(*(longlong *)(param_4 + 0xf8) + 0x38) * 1.5258789e-05 * 3.1415927) /
           180.0;
  local_res18[0] = param_3;
  local_340 = param_2;
  local_1b8 = iVar29;
  local_374 = cosf(fVar44);
  fVar44 = sinf(fVar44);
  local_368 = (int *)CONCAT44(local_368._4_4_,fVar44);
  lVar2 = *(longlong *)(param_4 + 0xa0);
  local_168 = CONCAT44((float)*(byte *)(lVar2 + 0x3a) / 255.0,(float)*(byte *)(lVar2 + 0x39) / 255.0
                      );
  lVar3 = *(longlong *)(param_4 + 0xa8);
  uStack_160 = CONCAT44((float)*(byte *)(lVar3 + 0x39) / 255.0,
                        (float)*(byte *)(lVar2 + 0x3b) / 255.0);
  local_158 = CONCAT44((float)*(byte *)(lVar3 + 0x3b) / 255.0,(float)*(byte *)(lVar3 + 0x3a) / 255.0
                      );
  lVar2 = *(longlong *)(param_4 + 0xb0);
  uStack_150 = CONCAT44((float)*(byte *)(lVar2 + 0x3a) / 255.0,
                        (float)*(byte *)(lVar2 + 0x39) / 255.0);
  local_148 = CONCAT44((float)(*(double *)(*(longlong *)(param_4 + 0xb8) + 0x38) / 100.0),
                       (float)*(byte *)(lVar2 + 0x3b) / 255.0);
  local_36c = (float)(*(double *)(*(longlong *)(param_4 + 0x30) + 0x38) / 100.0);
  fVar43 = (float)(*(double *)(*(longlong *)(param_4 + 0x178) + 0x38) / 100.0);
  fVar44 = (float)*(double *)(*(longlong *)(param_4 + 0x18) + 0x38);
  if (*(int *)(*(longlong *)(param_4 + 0x188) + 0x38) != 0) {
    fVar44 = (1.0 - fVar43 * 0.5) * fVar44;
  }
  local_37c = (int)(fVar44 * fVar48 + 0.5);
  if (local_37c < 2) {
    local_37c = 2;
  }
  iVar37 = local_37c;
  local_380 = (int)((float)*(double *)(*(longlong *)(param_4 + 0x20) + 0x38) * fVar44 * fVar47 + 0.5
                   );
  if (local_380 < 1) {
    local_380 = 1;
  }
  iVar38 = local_380;
  uStack_140 = CONCAT44(local_380,(uint)(*(int *)(*(longlong *)(param_4 + 0xc0) + 0x38) != 0));
  local_138 = CONCAT44(local_138._4_4_,local_37c);
  fVar45 = 0.03;
  if ((0.03 <= fVar49) && (fVar45 = 0.5, fVar49 <= 0.5)) {
    fVar45 = fVar49;
  }
  uStack_1a0 = CONCAT44(fVar45,(undefined4)uStack_1a0);
  if (*(int *)(*(longlong *)(param_4 + 0x180) + 0x38) == 0) {
    fVar43 = 1.0;
  }
  if (*(int *)(*(longlong *)(param_4 + 0x120) + 0x38) == 0) {
    local_390 = 0.0;
    local_394 = 0.0;
    fVar49 = 0.0;
    local_398 = 0.0;
  }
  else {
    dVar40 = (double)fVar43;
    dVar5 = (*(double *)(*(longlong *)(param_4 + 0x158) + 0x38) / 100.0) * dVar40;
    local_390 = (float)((*(double *)(*(longlong *)(param_4 + 0x150) + 0x38) / 100.0) * dVar40);
    local_394 = (float)((*(double *)(*(longlong *)(param_4 + 0x140) + 0x38) / 100.0) * dVar40);
    fVar49 = (float)((*(double *)(*(longlong *)(param_4 + 0x138) + 0x38) / 100.0) * 60.0 * dVar40);
    local_398 = (float)((*(double *)(*(longlong *)(param_4 + 0x128) + 0x38) / 100.0) * 50.0 * dVar40
                       );
  }
  dVar40 = *(double *)(*(longlong *)(param_4 + 0x148) + 0x38);
  fVar45 = ((float)*(int *)(*(longlong *)(param_4 + 0x130) + 0x38) * 1.5258789e-05 * 3.1415927) /
           180.0;
  fVar43 = cosf(fVar45);
  local_128 = fVar43 * local_398 * fVar47;
  fVar43 = sinf(fVar45);
  local_124 = fVar43 * local_398 * fVar48;
  local_120 = fVar49 * fVar47;
  local_11c = (int)(fVar44 + 0.5);
  if (local_11c < 6) {
    local_11c = 6;
  }
  local_118 = local_394;
  local_114 = (int)((float)dVar40 + 0.5);
  if (local_114 < 1) {
    local_114 = 1;
  }
  local_10c = (float)dVar5;
  local_108 = param_8;
  local_104 = local_378;
  if (0.0 < local_390) {
    uVar32 = (int)local_378 * 0x27d4eb2f + param_8 * 0x165667b1 + -0x568d76bf;
    uVar32 = (uVar32 >> 0xd ^ uVar32) * 0x4bf19f61;
    fVar46 = (float)((uVar32 >> 0x10 ^ uVar32) & 0xffffff) * 5.9604645e-08;
    fVar46 = ((fVar46 + fVar46) - 1.0) * local_390 * 0.5 + 1.0;
  }
  local_2d0 = (void *)0x0;
  uStack_2c8 = 0;
  local_2c0 = 0;
  local_110 = fVar46;
  if (local_38c != 0.0) {
    local_38c = 0.0;
    local_390 = 0.0;
    local_338 = (float *)&local_2d8;
    pfStack_330 = &param_7;
    cVar28 = FUN_1800030f0(*(undefined4 *)(param_5 + 0x24),*(undefined4 *)(param_5 + 0x28),
                           (float)iVar38 / (float)iVar37,&local_2d0);
    if (cVar28 == '\0') {
      uStack_190 = uStack_190 & 0xffffffff;
      iVar29 = 1;
      local_1b8 = 1;
    }
    else {
      local_188 = local_2d0;
      uStack_180 = CONCAT44(local_390,local_38c);
      iVar29 = local_1b8;
    }
  }
  local_2f0 = (void *)0x0;
  uStack_2e8 = 0;
  local_2e0 = 0;
  if (iVar29 - 1U < 2) {
    FUN_18000a710(iVar29,&local_2f0);
  }
  local_308 = (void *)0x0;
  uStack_300 = 0;
  local_2f8 = 0;
  local_394 = 0.0;
  local_398 = 0.0;
  local_338 = (float *)&local_340;
  pfStack_330 = &param_7;
  FUN_1800039d0(&local_308,&local_394,&local_398,local_388);
  if ((0 < (int)local_394) && (0 < (int)local_398)) {
    if ((int)local_178 == 3) {
      local_38c = *(float *)(param_6 + 0x24);
      local_360 = *(int *)(param_6 + 0x28);
      local_378 = (float)(int)local_38c / (float)local_388;
      local_390 = (float)local_360 / (float)local_384;
      local_338 = &local_378;
      pfStack_330 = &local_38c;
      local_328 = &local_390;
      local_320 = &local_360;
      local_318 = &param_6;
      local_310 = (undefined1 *)&param_7;
      FUN_180004460(&local_308,local_394,local_398,local_380);
    }
    local_208 = &local_388;
    local_200 = &local_384;
    local_1f8 = &local_380;
    local_1f0 = &local_394;
    local_1e8 = &local_37c;
    local_1e0 = &local_398;
    local_1d8 = &local_340;
    local_1d0 = (undefined1 *)&param_7;
    local_1c8 = &local_308;
    local_1c0 = &local_1b8;
    local_354 = param_11 - param_9;
    local_35c = param_12 - param_10;
    local_100 = 0;
    uStack_f8 = 0;
    local_348 = local_374 * local_370 * fVar47;
    local_344 = local_368._0_4_ * local_370 * fVar48;
    local_2b8 = &local_35c;
    piStack_2b0 = &local_358;
    local_2a8 = &local_354;
    piStack_2a0 = &local_388;
    local_298 = &local_384;
    plStack_290 = local_res18;
    local_288 = (undefined1 *)&param_7;
    puStack_280 = &local_100;
    local_278 = &local_350;
    puStack_270 = &local_34c;
    local_268 = &local_370;
    piStack_260 = &local_380;
    local_258 = &local_394;
    piStack_250 = &local_37c;
    local_248 = &local_398;
    ppvStack_240 = &local_308;
    local_238 = &local_348;
    pfStack_230 = &local_344;
    local_228 = &local_128;
    ppiStack_220 = &local_208;
    local_218 = &local_36c;
    puStack_210 = &local_340;
    iVar29 = _Thrd_hardware_concurrency();
    puVar27 = puStack_210;
    pfVar26 = local_218;
    ppiVar25 = ppiStack_220;
    pfVar24 = local_228;
    pfVar23 = pfStack_230;
    pfVar22 = local_238;
    ppvVar21 = ppvStack_240;
    pfVar20 = local_248;
    piVar19 = piStack_250;
    pfVar18 = local_258;
    piVar17 = piStack_260;
    pfVar9 = local_268;
    puVar16 = puStack_270;
    puVar15 = local_278;
    puVar14 = puStack_280;
    puVar35 = local_288;
    plVar13 = plStack_290;
    piVar12 = local_298;
    piVar11 = piStack_2a0;
    piVar10 = local_2a8;
    if (iVar29 == 0) {
      iVar29 = 4;
    }
    if (iVar29 < 9) {
      if (1 < iVar29) goto LAB_180006d91;
    }
    else {
      iVar29 = 8;
LAB_180006d91:
      if (iVar29 * 8 <= iVar1) {
        local_338 = (float *)0x0;
        pfStack_330 = (float *)0x0;
        local_328 = (float *)0x0;
        iVar37 = (iVar1 + -1 + iVar29) / iVar29;
        iVar38 = 0;
        pfVar7 = local_338;
        pfVar8 = pfStack_330;
        if (iVar29 != 0) {
          do {
            pfVar8 = pfStack_330;
            fVar46 = (float)(iVar38 * iVar37);
            iVar36 = (int)fVar46 + iVar37;
            if (iVar1 < iVar36) {
              iVar36 = iVar1;
            }
            local_368 = (int *)CONCAT44(local_368._4_4_,iVar36);
            local_374 = fVar46;
            pfVar7 = local_338;
            if (iVar36 <= (int)fVar46) break;
            if (pfStack_330 == local_328) {
              FUN_180001fe0(&local_338,pfStack_330,&local_2b8,&local_374);
            }
            else {
              local_368 = (int *)FUN_1800129b0(0xb8);
              if (local_368 != (int *)0x0) {
                *local_368 = iVar36;
                local_368[1] = (int)fVar46;
                *(int **)(local_368 + 2) = local_2b8;
                *(int **)(local_368 + 4) = piStack_2b0;
                *(int **)(local_368 + 6) = piVar10;
                *(int **)(local_368 + 8) = piVar11;
                *(int **)(local_368 + 10) = piVar12;
                *(longlong **)(local_368 + 0xc) = plVar13;
                *(undefined1 **)(local_368 + 0xe) = puVar35;
                *(undefined8 **)(local_368 + 0x10) = puVar14;
                *(undefined4 **)(local_368 + 0x12) = puVar15;
                *(undefined4 **)(local_368 + 0x14) = puVar16;
                *(float **)(local_368 + 0x16) = pfVar9;
                *(int **)(local_368 + 0x18) = piVar17;
                *(float **)(local_368 + 0x1a) = pfVar18;
                *(int **)(local_368 + 0x1c) = piVar19;
                *(float **)(local_368 + 0x1e) = pfVar20;
                *(void ***)(local_368 + 0x20) = ppvVar21;
                *(float **)(local_368 + 0x22) = pfVar22;
                *(float **)(local_368 + 0x24) = pfVar23;
                *(float **)(local_368 + 0x26) = pfVar24;
                *(int ***)(local_368 + 0x28) = ppiVar25;
                *(float **)(local_368 + 0x2a) = pfVar26;
                *(uintptr_t **)(local_368 + 0x2c) = puVar27;
              }
              pfVar7 = pfVar8 + 2;
              uVar30 = _beginthreadex((void *)0x0,0,FUN_1800023a0,local_368,0,(uint *)pfVar7);
              *(uintptr_t *)pfVar8 = uVar30;
              if (uVar30 == 0) {
                *pfVar7 = 0.0;
                    // WARNING: Subroutine does not return
                std::_Throw_Cpp_error(6);
              }
              pfStack_330 = pfStack_330 + 4;
            }
            iVar38 = iVar38 + 1;
            pfVar7 = local_338;
            pfVar8 = pfStack_330;
          } while (iVar38 < iVar29);
        }
        for (; pfVar9 = pfStack_330, pfVar7 != pfStack_330; pfVar7 = pfVar7 + 4) {
          pfStack_330 = pfVar8;
          FUN_18000a6a0(pfVar7);
          pfVar8 = pfStack_330;
          pfStack_330 = pfVar9;
        }
        pfStack_330 = pfVar8;
        FUN_180004d00(&local_338);
        goto LAB_180006f3d;
      }
    }
    FUN_1800051a0(&local_2b8,0,iVar1);
  }
LAB_180006f3d:
  puVar33 = auStackY_3e8;
  puVar34 = auStackY_3e8;
  puVar35 = auStackY_3e8;
  if (local_308 != (void *)0x0) {
    pvVar31 = local_308;
    if ((local_2f8 - (longlong)local_308 & 0xffffffffffffffc0U) < 0x1000) {
LAB_180006f78:
      puVar34 = puVar33;
    }
    else {
      pvVar31 = *(void **)((longlong)local_308 + -8);
      if (0x1f < (ulonglong)((longlong)local_308 + (-8 - (longlong)pvVar31))) {
        pcVar4 = (code *)swi(0x29);
        pvVar31 = (void *)(*pcVar4)(5);
        puVar33 = auStackY_3e0;
        goto LAB_180006f78;
      }
    }
    *(undefined8 *)(puVar34 + -8) = 0x180006f80;
    free(pvVar31);
    local_308 = (void *)0x0;
    uStack_300 = 0;
    local_2f8 = 0;
    puVar35 = puVar34;
  }
  if (local_2f0 != (void *)0x0) {
    pvVar31 = local_2f0;
    if ((0xfff < (ulonglong)((local_2e0 - (longlong)local_2f0 >> 2) * 4)) &&
       (pvVar31 = *(void **)((longlong)local_2f0 + -8),
       0x1f < (ulonglong)((longlong)local_2f0 + (-8 - (longlong)pvVar31)))) {
      pvVar31 = (void *)0x5;
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)();
      puVar35 = puVar35 + 8;
    }
    *(undefined8 *)(puVar35 + -8) = 0x180006fda;
    free(pvVar31);
    local_2f0 = (void *)0x0;
    uStack_2e8 = 0;
    local_2e0 = 0;
  }
  if (local_2d0 != (void *)0x0) {
    pvVar31 = local_2d0;
    if ((0xfff < (ulonglong)((local_2c0 - (longlong)local_2d0 >> 2) * 4)) &&
       (pvVar31 = *(void **)((longlong)local_2d0 + -8),
       0x1f < (ulonglong)((longlong)local_2d0 + (-8 - (longlong)pvVar31)))) {
      pvVar31 = (void *)0x5;
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)();
      puVar35 = puVar35 + 8;
    }
    *(undefined8 *)(puVar35 + -8) = 0x180007034;
    free(pvVar31);
  }
LAB_180007034:
  *(undefined8 *)(puVar35 + -8) = 0x180007045;
  return 0;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

undefined8 FUN_1800070b0(longlong param_1)

{
  int iVar1;
  code *pcVar2;
  byte bVar3;
  byte bVar4;
  longlong lVar5;
  char *pcVar6;
  undefined8 uVar7;
  void *_Memory;
  byte bVar8;
  char *pcVar9;
  ulonglong unaff_RBX;
  void *_Dst;
  undefined8 *puVar10;
  int iVar11;
  undefined8 unaff_RDI;
  int iVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  longlong unaff_R12;
  longlong lVar16;
  longlong unaff_R13;
  float fVar17;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  float fVar18;
  float fVar19;
  undefined8 *in_stack_00000028;
  undefined1 auStack_308 [32];
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  char acStack_2d8 [32];
  undefined4 uStack_2b8;
  ulonglong uStack_2b0;
  undefined *puStack_2a8;
  undefined1 uStack_28c;
  undefined4 uStack_280;
  undefined8 uStack_27c;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  ulonglong uStack_268;
  undefined8 uStack_260;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined8 uStack_234;
  undefined8 uStack_22c;
  undefined8 uStack_224;
  undefined8 uStack_21c;
  undefined8 uStack_214;
  ulonglong uStack_208;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  longlong lStack_1c8;
  longlong lStack_1c0;
  longlong lStack_1b8;
  undefined8 *puStack_1b0;
  undefined8 uStack_1a8;
  ulonglong uStack_1a0;
  undefined1 *apuStack_198 [4];
  undefined8 *local_178;
  void *local_170;
  longlong *local_168;
  undefined4 local_160;
  char local_158;
  char local_157 [3];
  float local_154;
  longlong local_150;
  longlong local_148;
  undefined8 *local_140;
  undefined8 local_138;
  longlong local_130;
  undefined8 *local_128;
  longlong local_120;
  undefined8 local_118;
  longlong local_110;
  char *local_108;
  undefined8 *local_100;
  undefined8 *local_f8;
  void *local_f0;
  longlong lStack_e8;
  longlong local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  char local_c8 [16];
  ulonglong local_b8;
  undefined1 local_98 [88];
  
  local_b8 = DAT_180030500 ^ (ulonglong)apuStack_198;
  if (*(int *)((longlong)in_stack_00000028 + 0x54) != 2) {
    return 0;
  }
  puVar10 = *(undefined8 **)(param_1 + 0x180);
  lVar16 = 0;
  local_f8 = (undefined8 *)0x0;
  local_128 = (undefined8 *)0x0;
  local_150 = 0;
  local_140 = (undefined8 *)0x0;
  local_100 = (undefined8 *)0x0;
  uStack_1a0 = 0x180007147;
  local_118 = puVar10;
  (*(code *)*puVar10)("PF Effect Custom UI Suite",2,&local_f8);
  uStack_1a0 = 0x18000715a;
  (*(code *)*puVar10)("DRAWBOT Draw Suite",1,&local_128);
  uStack_1a0 = 0x18000716d;
  (*(code *)*puVar10)("DRAWBOT Supplier Suite",1,&local_150);
  uStack_1a0 = 0x180007180;
  (*(code *)*puVar10)("DRAWBOT Surface Suite",2,&local_140);
  uStack_1a0 = 0x180007192;
  (*(code *)*puVar10)("DRAWBOT Image Suite",1,&local_100);
  if ((((local_f8 == (undefined8 *)0x0) || (local_128 == (undefined8 *)0x0)) ||
      (local_140 == (undefined8 *)0x0)) || (local_150 == 0)) goto LAB_1800077c4;
  local_110 = 0;
  local_130 = 0;
  local_148 = 0;
  uStack_1a0 = 0x1800071d7;
  (*(code *)*local_f8)(*in_stack_00000028,&local_110);
  if (local_110 != 0) {
    uStack_1a0 = 0x1800071ed;
    (*(code *)local_128[1])(local_110,&local_130);
    uStack_1a0 = 0x1800071fd;
    (*(code *)*local_128)(local_110,&local_148);
  }
  if ((local_130 == 0) || (local_148 == 0)) goto LAB_1800077c4;
  iVar1 = *(int *)(in_stack_00000028 + 0xb);
  fVar19 = (float)*(int *)((longlong)in_stack_00000028 + 0x5c);
  fVar18 = (float)(*(int *)((longlong)in_stack_00000028 + 100) -
                  *(int *)((longlong)in_stack_00000028 + 0x5c));
  uStack_1a0 = 0x180007243;
  (*(code *)*local_140)();
  local_d8 = *(undefined4 *)(in_stack_00000028 + 0xb);
  local_d4 = *(undefined4 *)((longlong)in_stack_00000028 + 0x5c);
  local_d0 = CONCAT44((int)((ulonglong)in_stack_00000028[0xc] >> 0x20) -
                      (int)((ulonglong)in_stack_00000028[0xb] >> 0x20),
                      (int)in_stack_00000028[0xc] - (int)in_stack_00000028[0xb]);
  uStack_1a0 = 0x18000727c;
  (*(code *)local_140[5])(local_130,local_148,&local_d8);
  local_158 = '\0';
  pcVar9 = &local_158;
  uStack_1a0 = 0x180007293;
  (**(code **)(local_150 + 0x40))(local_148);
  local_154 = 7.00649e-45;
  if (local_158 != '\0') {
    local_154 = 9.80909e-45;
  }
  local_f0 = (void *)0x0;
  lStack_e8 = 0;
  local_e0 = 0;
  uStack_1a0 = 0x1800072bf;
  lVar5 = FUN_1800129b0(0x9027);
  if (lVar5 == 0) goto LAB_180007879;
  _Dst = (void *)(lVar5 + 0x27U & 0xffffffffffffffe0);
  *(longlong *)((longlong)_Dst + -8) = lVar5;
  uStack_1a0 = 0x1800072f3;
  local_f0 = _Dst;
  local_e0 = (longlong)_Dst + 0x9000;
  memset(_Dst,0,0x9000);
  iVar11 = 0;
  iVar12 = 0;
  do {
    bVar8 = (&DAT_180020a23)[iVar12];
    uVar15 = (undefined1)(((uint)(byte)(&DAT_180020a20)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    uVar13 = (undefined1)(((uint)(byte)(&DAT_180020a21)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    bVar3 = (byte)((ulonglong)((uint)(byte)(&DAT_180020a22)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    if (local_158 == '\0') {
      bVar4 = bVar3;
      uVar14 = uVar15;
    }
    else {
      bVar4 = bVar8;
      bVar8 = bVar3;
      uVar14 = uVar13;
      uVar13 = uVar15;
    }
    *(byte *)((longlong)_Dst + (longlong)iVar12) = bVar8;
    *(undefined1 *)((longlong)_Dst + (longlong)iVar12 + 1) = uVar14;
    *(undefined1 *)((longlong)_Dst + (longlong)iVar12 + 2) = uVar13;
    *(byte *)((longlong)_Dst + (longlong)iVar12 + 3) = bVar4;
    bVar8 = (&DAT_180020a27)[iVar12];
    uVar15 = (undefined1)(((uint)(byte)(&DAT_180020a24)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    uVar13 = (undefined1)(((uint)(byte)(&DAT_180020a25)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    bVar3 = (byte)((ulonglong)((uint)(byte)(&DAT_180020a26)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    if (local_158 == '\0') {
      bVar4 = bVar3;
      uVar14 = uVar15;
    }
    else {
      bVar4 = bVar8;
      bVar8 = bVar3;
      uVar14 = uVar13;
      uVar13 = uVar15;
    }
    *(byte *)((longlong)_Dst + (longlong)iVar12 + 4) = bVar8;
    *(undefined1 *)((longlong)_Dst + (longlong)iVar12 + 5) = uVar14;
    *(undefined1 *)((longlong)_Dst + (longlong)iVar12 + 6) = uVar13;
    *(byte *)((longlong)_Dst + (longlong)iVar12 + 7) = bVar4;
    bVar8 = (&DAT_180020a2b)[iVar12];
    lVar16 = (longlong)(iVar11 * 4 + 8);
    uVar15 = (undefined1)(((uint)(byte)(&DAT_180020a20)[lVar16] * (uint)bVar8 + 0x7f) / 0xff);
    uVar13 = (undefined1)(((uint)(byte)(&DAT_180020a29)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    bVar3 = (byte)((ulonglong)((uint)(byte)(&DAT_180020a2a)[iVar12] * (uint)bVar8 + 0x7f) / 0xff);
    if (local_158 == '\0') {
      bVar4 = bVar3;
      uVar14 = uVar15;
    }
    else {
      bVar4 = bVar8;
      bVar8 = bVar3;
      uVar14 = uVar13;
      uVar13 = uVar15;
    }
    *(byte *)((longlong)_Dst + lVar16) = bVar8;
    *(undefined1 *)((longlong)_Dst + (longlong)iVar12 + 9) = uVar14;
    *(undefined1 *)((longlong)_Dst + (longlong)iVar12 + 10) = uVar13;
    *(byte *)((longlong)_Dst + (longlong)iVar12 + 0xb) = bVar4;
    lVar16 = (longlong)(iVar11 * 4 + 0xc);
    unaff_R12 = (longlong)iVar12;
    unaff_R13 = (longlong)iVar12;
    bVar8 = (&DAT_180020a2f)[iVar12];
    uVar15 = (undefined1)(((uint)bVar8 * (uint)(byte)(&DAT_180020a20)[lVar16] + 0x7f) / 0xff);
    uVar13 = (undefined1)(((uint)bVar8 * (uint)(byte)(&DAT_180020a2d)[unaff_R12] + 0x7f) / 0xff);
    bVar3 = (byte)((ulonglong)((uint)bVar8 * (uint)(byte)(&DAT_180020a2e)[unaff_R13] + 0x7f) / 0xff)
    ;
    if (local_158 == '\0') {
      bVar4 = bVar3;
      uVar14 = uVar15;
    }
    else {
      bVar4 = bVar8;
      bVar8 = bVar3;
      uVar14 = uVar13;
      uVar13 = uVar15;
    }
    *(byte *)((longlong)_Dst + lVar16) = bVar8;
    *(undefined1 *)((longlong)_Dst + unaff_R12 + 0xd) = uVar14;
    *(undefined1 *)((longlong)_Dst + unaff_R13 + 0xe) = uVar13;
    *(byte *)((longlong)_Dst + (longlong)iVar12 + 0xf) = bVar4;
    iVar11 = iVar11 + 4;
    iVar12 = iVar12 + 0x10;
  } while (iVar11 < 0x2400);
  unaff_RDI = 0;
  local_120 = 0;
  local_168 = &local_120;
  local_178 = (undefined8 *)CONCAT44(local_178._4_4_,local_154);
  uStack_1a0 = 0x1800075a3;
  local_170 = _Dst;
  lStack_e8 = (longlong)_Dst + 0x9000;
  (**(code **)(local_150 + 0x28))(local_148,0x60,0x60,0x180);
  puVar10 = local_118;
  unaff_XMM6_Da = 0x40800000;
  unaff_XMM6_Db = 0;
  unaff_XMM6_Dc = 0;
  unaff_XMM6_Dd = 0;
  unaff_XMM7_Da = 0x41f00000;
  unaff_XMM7_Db = 0;
  unaff_XMM7_Dc = 0;
  unaff_XMM7_Dd = 0;
  unaff_XMM8_Da = 0x3f000000;
  unaff_XMM8_Db = 0;
  unaff_XMM8_Dc = 0;
  unaff_XMM8_Dd = 0;
  if (local_120 != 0) {
    if (local_100 != (undefined8 *)0x0) {
      uStack_1a0 = 0x1800075e0;
      (*(code *)*local_100)(local_120);
    }
    fVar17 = (fVar18 - 30.0) * 0.5 + fVar19;
    if (fVar17 < fVar19) {
      fVar17 = fVar19;
    }
    local_138 = CONCAT44(fVar17,(float)iVar1 + 4.0);
    uStack_1a0 = 0x180007632;
    (*(code *)local_140[10])(local_130,local_120,&local_138,0x3f800000);
    uStack_1a0 = 0x18000763f;
    (**(code **)(local_150 + 0x60))(local_120);
  }
  local_157[0] = '\0';
  pcVar9 = local_157;
  uStack_1a0 = 0x180007656;
  (**(code **)(local_150 + 0x10))(local_148);
  if (local_157[0] != '\0') {
    local_154 = 11.0;
    uStack_1a0 = 0x18000767b;
    (**(code **)(local_150 + 0x18))(local_148,&local_154);
    local_154 = local_154 + 1.5;
    local_138 = 0;
    uStack_1a0 = 0x1800076a6;
    (**(code **)(local_150 + 0x20))(local_148,local_154,&local_138);
    local_c8[0] = '\x1f';
    local_c8[1] = -0x7b;
    local_c8[2] = 'k';
    local_c8[3] = '?';
    local_c8[4] = '\x1f';
    local_c8[5] = -0x7b;
    local_c8[6] = 'k';
    local_c8[7] = '?';
    local_c8[8] = '3';
    local_c8[9] = '3';
    local_c8[10] = 's';
    local_c8[0xb] = '?';
    local_c8[0xc] = '\0';
    local_c8[0xd] = '\0';
    local_c8[0xe] = -0x80;
    local_c8[0xf] = '?';
    local_108 = (char *)0x0;
    pcVar9 = local_c8;
    uStack_1a0 = 0x1800076cb;
    (**(code **)(local_150 + 8))(local_148,pcVar9,&local_108);
    if (local_138 == 0) {
LAB_180007754:
      if (local_108 != (char *)0x0) {
        uStack_1a0 = 0x180007768;
        (**(code **)(local_150 + 0x60))(local_108);
      }
    }
    else {
      pcVar9 = local_108;
      if (local_108 != (char *)0x0) {
        local_118 = (undefined8 *)
                    CONCAT44(fVar18 * 0.5 + fVar19 + local_154 * 0.36,
                             (float)iVar1 + 4.0 + 30.0 + 10.0);
        local_160 = 0;
        local_168 = (longlong *)((ulonglong)local_168 & 0xffffffff00000000);
        local_170 = (void *)((ulonglong)local_170 & 0xffffffff00000000);
        local_178 = &local_118;
        uStack_1a0 = 0x18000774f;
        (*(code *)local_140[9])(local_130,local_108,local_138,L"OBLIVIXN");
        goto LAB_180007754;
      }
    }
    if (local_138 != 0) {
      uStack_1a0 = 0x18000777a;
      (**(code **)(local_150 + 0x60))();
    }
  }
  uStack_1a0 = 0x180007787;
  (*(code *)local_140[1])(local_130);
  *(uint *)((longlong)in_stack_00000028 + 0xcc) = *(uint *)((longlong)in_stack_00000028 + 0xcc) | 1;
  if ((ulonglong)(local_e0 - (longlong)_Dst) < 0x1000) {
    _Memory = _Dst;
  }
  else {
    _Memory = *(void **)((longlong)_Dst + -8);
    unaff_RBX = (longlong)_Dst + (-8 - (longlong)_Memory);
    if (0x1f < unaff_RBX) {
LAB_180007879:
      lVar5 = 5;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)();
      puStack_1b0 = in_stack_00000028;
      uStack_208 = DAT_180030500 ^ (ulonglong)auStack_308;
      lStack_1b8 = lVar16;
      uStack_1a8 = unaff_RDI;
      uStack_1a0 = unaff_RBX;
      apuStack_198[0] = local_98;
      memset(&uStack_2e8,0,0xb0);
      uStack_2e0 = 0x2800dc;
      uStack_2b8 = 2;
      uStack_2e4 = 2;
      uStack_2dc = 5;
      pcVar6 = (char *)FUN_18000cce0(3);
      strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
      uStack_2b0 = 0x550affff550affff;
      uStack_2e8 = 1;
      uVar7 = (**(code **)(lVar5 + 0x10))(*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
      if ((int)uVar7 == 0) {
        lStack_1c8 = unaff_R13;
        lStack_1c0 = unaff_R12;
        memset(&uStack_2e8,0,0xb0);
        uStack_2dc = 7;
        pcVar6 = (char *)FUN_18000cce0(4);
        strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
        uStack_2b0 = 0x1000600000001;
        puStack_2a8 = (undefined *)FUN_18000cce0(5);
        uStack_2e8 = 2;
        uVar7 = (**(code **)(lVar5 + 0x10))(*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
        if ((int)uVar7 == 0) {
          local_178 = puVar10;
          memset(&uStack_2e8,0,0xb0);
          uStack_2dc = 10;
          pcVar6 = (char *)FUN_18000cce0(6);
          strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
          uStack_2b0 = 0x4028000000000000;
          uStack_280 = 0x40800000;
          uStack_27c = 0x4080000042c00000;
          uStack_274 = 0x42400000;
          uStack_270 = 0x41400000;
          uStack_26c = 0;
          uStack_268 = (ulonglong)(uint)uStack_268;
          uStack_2e8 = 3;
          uVar7 = (**(code **)(lVar5 + 0x10))(*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
          if ((int)uVar7 == 0) {
            memset(&uStack_2e8,0,0xb0);
            uStack_2dc = 10;
            pcVar6 = (char *)FUN_18000cce0(7);
            strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
            uStack_2b0 = 0x3fe0000000000000;
            uStack_280 = 0x3e99999a;
            uStack_27c = 0x3e99999a3f800000;
            uStack_274 = 0x3f800000;
            uStack_270 = 0x3f000000;
            uStack_26c = 2;
            uStack_268 = uStack_268 & 0xffffffff;
            uStack_2e8 = 4;
            uVar7 = (**(code **)(lVar5 + 0x10))
                              (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
            if ((int)uVar7 == 0) {
              memset(&uStack_2e8,0,0xb0);
              uStack_2dc = 7;
              pcVar6 = (char *)FUN_18000cce0(8);
              strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
              uStack_2b0 = 0x1000400000001;
              puStack_2a8 = (undefined *)FUN_18000cce0(9);
              uStack_2e8 = 5;
              uVar7 = (**(code **)(lVar5 + 0x10))
                                (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
              if ((int)uVar7 == 0) {
                uStack_1d8 = unaff_XMM6_Da;
                uStack_1d4 = unaff_XMM6_Db;
                uStack_1d0 = unaff_XMM6_Dc;
                uStack_1cc = unaff_XMM6_Dd;
                memset(&uStack_2e8,0,0xb0);
                uStack_2dc = 10;
                pcVar6 = (char *)FUN_18000cce0(10);
                strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                uStack_2b0 = 0x4059000000000000;
                uStack_280 = 0;
                uStack_27c = 0x42c80000;
                uStack_274 = 0x42c80000;
                uStack_270 = 0x42c80000;
                uStack_26c = 1;
                uStack_268 = uStack_268 & 0xffffffff;
                uStack_2e8 = 6;
                uVar7 = (**(code **)(lVar5 + 0x10))
                                  (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
                if ((int)uVar7 == 0) {
                  memset(&uStack_2e8,0,0xb0);
                  uStack_2dc = 0xd;
                  pcVar6 = (char *)FUN_18000cce0(0xb);
                  strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                  uStack_2e8 = 7;
                  uVar7 = (**(code **)(lVar5 + 0x10))
                                    (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
                  if ((int)uVar7 == 0) {
                    memset(&uStack_2e8,0,0xb0);
                    uStack_2dc = 4;
                    pcVar6 = (char *)FUN_18000cce0(0xc);
                    strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                    puStack_2a8 = &DAT_180029c25;
                    uStack_2b0 = uStack_2b0 & 0xffffff0000000000;
                    uStack_2e8 = 8;
                    uVar7 = (**(code **)(lVar5 + 0x10))
                                      (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
                    if ((int)uVar7 == 0) {
                      memset(&uStack_2e8,0,0xb0);
                      uStack_2dc = 10;
                      pcVar6 = (char *)FUN_18000cce0(0xd);
                      strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                      uStack_2b0 = 0x3ff0000000000000;
                      uStack_280 = 0x3e4ccccd;
                      uStack_27c = 0x3e4ccccd40400000;
                      uStack_274 = 0x40400000;
                      uStack_270 = 0x3f800000;
                      uStack_26c = 2;
                      uStack_268 = uStack_268 & 0xffffffff;
                      uStack_2e8 = 9;
                      uVar7 = (**(code **)(lVar5 + 0x10))
                                        (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
                      if ((int)uVar7 == 0) {
                        uStack_1e8 = unaff_XMM7_Da;
                        uStack_1e4 = unaff_XMM7_Db;
                        uStack_1e0 = unaff_XMM7_Dc;
                        uStack_1dc = unaff_XMM7_Dd;
                        memset(&uStack_2e8,0,0xb0);
                        uStack_2dc = 10;
                        pcVar6 = (char *)FUN_18000cce0(0xe);
                        strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                        uStack_280 = 0xc2c80000;
                        uStack_2b0 = 0;
                        uStack_27c = 0xc2c8000042c80000;
                        uStack_274 = 0x42c80000;
                        uStack_270 = 0;
                        uStack_26c = 1;
                        uStack_268 = uStack_268 & 0xffffffff;
                        uStack_2e8 = 10;
                        uVar7 = (**(code **)(lVar5 + 0x10))
                                          (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
                        if ((int)uVar7 == 0) {
                          memset(&uStack_2e8,0,0xb0);
                          uStack_2dc = 7;
                          pcVar6 = (char *)FUN_18000cce0(0xf);
                          strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                          uStack_2b0 = 0x1000300000001;
                          puStack_2a8 = (undefined *)FUN_18000cce0(0x10);
                          uStack_2e8 = 0xb;
                          uVar7 = (**(code **)(lVar5 + 0x10))
                                            (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8);
                          if ((int)uVar7 == 0) {
                            uStack_1f8 = unaff_XMM8_Da;
                            uStack_1f4 = unaff_XMM8_Db;
                            uStack_1f0 = unaff_XMM8_Dc;
                            uStack_1ec = unaff_XMM8_Dd;
                            memset(&uStack_2e8,0,0xb0);
                            uStack_2dc = 10;
                            pcVar6 = (char *)FUN_18000cce0(0x11);
                            strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                            uStack_2b0 = 0x4039000000000000;
                            uStack_280 = 0;
                            uStack_27c = 0x42c80000;
                            uStack_274 = 0x42c80000;
                            uStack_270 = 0x41c80000;
                            uStack_26c = 1;
                            uStack_268 = uStack_268 & 0xffffffff;
                            uStack_2e8 = 0xc;
                            uVar7 = (**(code **)(lVar5 + 0x10))
                                              (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,&uStack_2e8)
                            ;
                            if ((int)uVar7 == 0) {
                              memset(&uStack_2e8,0,0xb0);
                              uStack_2dc = 10;
                              pcVar6 = (char *)FUN_18000cce0(0x12);
                              strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                              uStack_2b0 = 0x4030000000000000;
                              uStack_280 = 0x40a00000;
                              uStack_27c = 0x40a0000042480000;
                              uStack_274 = 0x42480000;
                              uStack_270 = 0x41800000;
                              uStack_26c = 1;
                              uStack_268 = uStack_268 & 0xffffffff;
                              uStack_2e8 = 0xd;
                              uVar7 = (**(code **)(lVar5 + 0x10))
                                                (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,
                                                 &uStack_2e8);
                              if ((int)uVar7 == 0) {
                                memset(&uStack_2e8,0,0xb0);
                                pcVar6 = (char *)FUN_18000cce0(0x13);
                                strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                                uStack_23c = 0;
                                uStack_2e8 = 0xe;
                                uVar7 = (**(code **)(lVar5 + 0x10))
                                                  (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,
                                                   &uStack_2e8);
                                if ((int)uVar7 == 0) {
                                  memset(&uStack_2e8,0,0xb0);
                                  uStack_2dc = 10;
                                  pcVar6 = (char *)FUN_18000cce0(0x14);
                                  strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                                  uStack_2b0 = 0;
                                  uStack_280 = 0;
                                  uStack_27c = 0x42c80000;
                                  uStack_274 = 0x42c80000;
                                  uStack_270 = 0;
                                  uStack_26c = 1;
                                  uStack_268 = uStack_268 & 0xffffffff;
                                  uStack_2e8 = 0xf;
                                  uVar7 = (**(code **)(lVar5 + 0x10))
                                                    (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,
                                                     &uStack_2e8);
                                  if ((int)uVar7 == 0) {
                                    memset(&uStack_2e8,0,0xb0);
                                    uStack_2dc = 10;
                                    pcVar6 = (char *)FUN_18000cce0(0x15);
                                    strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                                    uStack_2b0 = 0x4034000000000000;
                                    uStack_280 = 0;
                                    uStack_27c = 0x42c80000;
                                    uStack_274 = 0x42c80000;
                                    uStack_270 = 0x41a00000;
                                    uStack_26c = 1;
                                    uStack_268 = uStack_268 & 0xffffffff;
                                    uStack_2e8 = 0x10;
                                    uVar7 = (**(code **)(lVar5 + 0x10))
                                                      (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,
                                                       &uStack_2e8);
                                    if ((int)uVar7 == 0) {
                                      memset(&uStack_2e8,0,0xb0);
                                      uStack_2dc = 4;
                                      pcVar6 = (char *)FUN_18000cce0(0x16);
                                      strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                                      puStack_2a8 = &DAT_180029c25;
                                      uStack_2b0 = uStack_2b0 & 0xffffff0000000000;
                                      uStack_2e8 = 0x11;
                                      uVar7 = (**(code **)(lVar5 + 0x10))
                                                        (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,
                                                         &uStack_2e8);
                                      if ((int)uVar7 == 0) {
                                        memset(&uStack_2e8,0,0xb0);
                                        uStack_2dc = 0xe;
                                        uStack_2e8 = 0x12;
                                        uVar7 = (**(code **)(lVar5 + 0x10))
                                                          (*(undefined8 *)(lVar5 + 0xb8),0xffffffff,
                                                           &uStack_2e8);
                                        if ((int)uVar7 == 0) {
                                          memset(&uStack_2e8,0,0xb0);
                                          uStack_2dc = 0xd;
                                          pcVar6 = (char *)FUN_18000cce0(0x17);
                                          strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                                          uStack_2e8 = 0x13;
                                          uVar7 = (**(code **)(lVar5 + 0x10))
                                                            (*(undefined8 *)(lVar5 + 0xb8),
                                                             0xffffffff,&uStack_2e8);
                                          if ((int)uVar7 == 0) {
                                            memset(&uStack_2e8,0,0xb0);
                                            uStack_2dc = 5;
                                            pcVar6 = (char *)FUN_18000cce0(0x18);
                                            strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                                            uStack_2b0 = 0xf0e8e2fff0e8e2ff;
                                            uStack_2e8 = 0x14;
                                            uVar7 = (**(code **)(lVar5 + 0x10))
                                                              (*(undefined8 *)(lVar5 + 0xb8),
                                                               0xffffffff,&uStack_2e8);
                                            if ((int)uVar7 == 0) {
                                              memset(&uStack_2e8,0,0xb0);
                                              uStack_2dc = 5;
                                              pcVar6 = (char *)FUN_18000cce0(0x19);
                                              strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff);
                                              uStack_2b0 = 0x120c0aff120c0aff;
                                              uStack_2e8 = 0x15;
                                              uVar7 = (**(code **)(lVar5 + 0x10))
                                                                (*(undefined8 *)(lVar5 + 0xb8),
                                                                 0xffffffff,&uStack_2e8);
                                              if ((int)uVar7 == 0) {
                                                memset(&uStack_2e8,0,0xb0);
                                                uStack_2dc = 5;
                                                pcVar6 = (char *)FUN_18000cce0(0x1a);
                                                strncpy_s(acStack_2d8,0x20,pcVar6,0xffffffffffffffff
                                                         );
                                                uStack_2b0 = 0x5900ffff5900ffff;
                                                uStack_2e8 = 0x16;
                                                uVar7 = (**(code **)(lVar5 + 0x10))
                                                                  (*(undefined8 *)(lVar5 + 0xb8),
                                                                   0xffffffff,&uStack_2e8);
                                                if ((int)uVar7 == 0) {
                                                  memset(&uStack_2e8,0,0xb0);
                                                  uStack_2dc = 10;
                                                  pcVar6 = (char *)FUN_18000cce0(0x1b);
                                                  strncpy_s(acStack_2d8,0x20,pcVar6,
                                                            0xffffffffffffffff);
                                                  uStack_2b0 = 0x4059000000000000;
                                                  uStack_280 = 0;
                                                  uStack_27c = 0x42c80000;
                                                  uStack_274 = 0x42c80000;
                                                  uStack_270 = 0x42c80000;
                                                  uStack_26c = 1;
                                                  uStack_268 = uStack_268 & 0xffffffff;
                                                  uStack_2e8 = 0x17;
                                                  uVar7 = (**(code **)(lVar5 + 0x10))
                                                                    (*(undefined8 *)(lVar5 + 0xb8),
                                                                     0xffffffff,&uStack_2e8);
                                                  if ((int)uVar7 == 0) {
                                                    memset(&uStack_2e8,0,0xb0);
                                                    uStack_2dc = 4;
                                                    pcVar6 = (char *)FUN_18000cce0(0x1c);
                                                    strncpy_s(acStack_2d8,0x20,pcVar6,
                                                              0xffffffffffffffff);
                                                    puStack_2a8 = &DAT_180029c25;
                                                    uStack_2b0 = uStack_2b0 & 0xffffff0000000000;
                                                    uStack_2e8 = 0x18;
                                                    uVar7 = (**(code **)(lVar5 + 0x10))
                                                                      (*(undefined8 *)(lVar5 + 0xb8)
                                                                       ,0xffffffff,&uStack_2e8);
                                                    if ((int)uVar7 == 0) {
                                                      memset(&uStack_2e8,0,0xb0);
                                                      uStack_2dc = 0xe;
                                                      uStack_2e8 = 0x19;
                                                      uVar7 = (**(code **)(lVar5 + 0x10))
                                                                        (*(undefined8 *)
                                                                          (lVar5 + 0xb8),0xffffffff,
                                                                         &uStack_2e8);
                                                      if ((int)uVar7 == 0) {
                                                        memset(&uStack_2e8,0,0xb0);
                                                        uStack_2dc = 0xd;
                                                        pcVar6 = (char *)FUN_18000cce0(0x1d);
                                                        strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                  0xffffffffffffffff);
                                                        uStack_2e8 = 0x29;
                                                        uVar7 = (**(code **)(lVar5 + 0x10))
                                                                          (*(undefined8 *)
                                                                            (lVar5 + 0xb8),
                                                                           0xffffffff,&uStack_2e8);
                                                        if ((int)uVar7 == 0) {
                                                          memset(&uStack_2e8,0,0xb0);
                                                          uStack_2dc = 7;
                                                          pcVar6 = (char *)FUN_18000cce0(0x1e);
                                                          strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                    0xffffffffffffffff);
                                                          uStack_2b0 = 0x1000300000001;
                                                          puStack_2a8 = (undefined *)
                                                                        FUN_18000cce0(0x1f);
                                                          uStack_2e8 = 0x2a;
                                                          uVar7 = (**(code **)(lVar5 + 0x10))
                                                                            (*(undefined8 *)
                                                                              (lVar5 + 0xb8),
                                                                             0xffffffff,&uStack_2e8)
                                                          ;
                                                          if ((int)uVar7 == 0) {
                                                            memset(&uStack_2e8,0,0xb0);
                                                            pcVar6 = (char *)FUN_18000cce0(0x20);
                                                            strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                      0xffffffffffffffff);
                                                            uStack_23c = 0;
                                                            uStack_2e8 = 0x2b;
                                                            uVar7 = (**(code **)(lVar5 + 0x10))
                                                                              (*(undefined8 *)
                                                                                (lVar5 + 0xb8),
                                                                               0xffffffff,
                                                                               &uStack_2e8);
                                                            if ((int)uVar7 == 0) {
                                                              memset(&uStack_2e8,0,0xb0);
                                                              uStack_2dc = 4;
                                                              pcVar6 = (char *)FUN_18000cce0(0x21);
                                                              strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                        0xffffffffffffffff);
                                                              puStack_2a8 = &DAT_180029c25;
                                                              uStack_2b0 = uStack_2b0 &
                                                                           0xffffff0000000000;
                                                              uStack_2e8 = 0x2c;
                                                              uVar7 = (**(code **)(lVar5 + 0x10))
                                                                                (*(undefined8 *)
                                                                                  (lVar5 + 0xb8),
                                                                                 0xffffffff,
                                                                                 &uStack_2e8);
                                                              if ((int)uVar7 == 0) {
                                                                memset(&uStack_2e8,0,0xb0);
                                                                uStack_2dc = 10;
                                                                pcVar6 = (char *)FUN_18000cce0(0x22)
                                                                ;
                                                                strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                          0xffffffffffffffff);
                                                                uStack_2b0 = 0x4039000000000000;
                                                                uStack_280 = 0;
                                                                uStack_27c = 0x42c80000;
                                                                uStack_274 = 0x42c80000;
                                                                uStack_270 = 0x41c80000;
                                                                uStack_26c = 1;
                                                                uStack_268 = uStack_268 & 0xffffffff
                                                                ;
                                                                uStack_2e8 = 0x2d;
                                                                uVar7 = (**(code **)(lVar5 + 0x10))
                                                                                  (*(undefined8 *)
                                                                                    (lVar5 + 0xb8),
                                                                                   0xffffffff,
                                                                                   &uStack_2e8);
                                                                if ((int)uVar7 == 0) {
                                                                  memset(&uStack_2e8,0,0xb0);
                                                                  uStack_2dc = 3;
                                                                  pcVar6 = (char *)FUN_18000cce0(
                                                  0x23);
                                                  strncpy_s(acStack_2d8,0x20,pcVar6,
                                                            0xffffffffffffffff);
                                                  uStack_2b0 = 0;
                                                  uStack_2e8 = 0x2e;
                                                  uVar7 = (**(code **)(lVar5 + 0x10))
                                                                    (*(undefined8 *)(lVar5 + 0xb8),
                                                                     0xffffffff,&uStack_2e8);
                                                  if ((int)uVar7 == 0) {
                                                    memset(&uStack_2e8,0,0xb0);
                                                    uStack_2dc = 10;
                                                    pcVar6 = (char *)FUN_18000cce0(0x24);
                                                    strncpy_s(acStack_2d8,0x20,pcVar6,
                                                              0xffffffffffffffff);
                                                    uStack_2b0 = 0x4041800000000000;
                                                    uStack_280 = 0;
                                                    uStack_27c = 0x42c80000;
                                                    uStack_274 = 0x42c80000;
                                                    uStack_270 = 0x420c0000;
                                                    uStack_26c = 1;
                                                    uStack_268 = uStack_268 & 0xffffffff;
                                                    uStack_2e8 = 0x2f;
                                                    uVar7 = (**(code **)(lVar5 + 0x10))
                                                                      (*(undefined8 *)(lVar5 + 0xb8)
                                                                       ,0xffffffff,&uStack_2e8);
                                                    if ((int)uVar7 == 0) {
                                                      memset(&uStack_2e8,0,0xb0);
                                                      uStack_2dc = 10;
                                                      pcVar6 = (char *)FUN_18000cce0(0x25);
                                                      strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                0xffffffffffffffff);
                                                      uStack_2b0 = 0x403e000000000000;
                                                      uStack_280 = 0;
                                                      uStack_27c = 0x42c80000;
                                                      uStack_274 = 0x42c80000;
                                                      uStack_270 = 0x41f00000;
                                                      uStack_26c = 1;
                                                      uStack_268 = uStack_268 & 0xffffffff;
                                                      uStack_2e8 = 0x30;
                                                      uVar7 = (**(code **)(lVar5 + 0x10))
                                                                        (*(undefined8 *)
                                                                          (lVar5 + 0xb8),0xffffffff,
                                                                         &uStack_2e8);
                                                      if ((int)uVar7 == 0) {
                                                        memset(&uStack_2e8,0,0xb0);
                                                        uStack_2dc = 0xe;
                                                        uStack_2e8 = 0x31;
                                                        uVar7 = (**(code **)(lVar5 + 0x10))
                                                                          (*(undefined8 *)
                                                                            (lVar5 + 0xb8),
                                                                           0xffffffff,&uStack_2e8);
                                                        if ((int)uVar7 == 0) {
                                                          memset(&uStack_2e8,0,0xb0);
                                                          uStack_2dc = 0xd;
                                                          pcVar6 = (char *)FUN_18000cce0(0x26);
                                                          strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                    0xffffffffffffffff);
                                                          uStack_2e8 = 0x1a;
                                                          uVar7 = (**(code **)(lVar5 + 0x10))
                                                                            (*(undefined8 *)
                                                                              (lVar5 + 0xb8),
                                                                             0xffffffff,&uStack_2e8)
                                                          ;
                                                          if ((int)uVar7 == 0) {
                                                            memset(&uStack_2e8,0,0xb0);
                                                            uStack_2dc = 4;
                                                            pcVar6 = (char *)FUN_18000cce0(0x27);
                                                            strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                      0xffffffffffffffff);
                                                            puStack_2a8 = &DAT_180029c25;
                                                            uStack_2b0 = uStack_2b0 &
                                                                         0xffffff0000000000;
                                                            uStack_2e8 = 0x1b;
                                                            uVar7 = (**(code **)(lVar5 + 0x10))
                                                                              (*(undefined8 *)
                                                                                (lVar5 + 0xb8),
                                                                               0xffffffff,
                                                                               &uStack_2e8);
                                                            if ((int)uVar7 == 0) {
                                                              memset(&uStack_2e8,0,0xb0);
                                                              uStack_2dc = 10;
                                                              pcVar6 = (char *)FUN_18000cce0(0x28);
                                                              strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                        0xffffffffffffffff);
                                                              uStack_2b0 = 0;
                                                              uStack_280 = 0;
                                                              uStack_27c = 0x42c80000;
                                                              uStack_274 = 0x42c80000;
                                                              uStack_270 = 0;
                                                              uStack_26c = 1;
                                                              uStack_268 = uStack_268 & 0xffffffff;
                                                              uStack_2e8 = 0x1c;
                                                              uVar7 = (**(code **)(lVar5 + 0x10))
                                                                                (*(undefined8 *)
                                                                                  (lVar5 + 0xb8),
                                                                                 0xffffffff,
                                                                                 &uStack_2e8);
                                                              if ((int)uVar7 == 0) {
                                                                memset(&uStack_2e8,0,0xb0);
                                                                uStack_2dc = 3;
                                                                pcVar6 = (char *)FUN_18000cce0(0x29)
                                                                ;
                                                                strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                          0xffffffffffffffff);
                                                                uStack_2b0 = 0;
                                                                uStack_2e8 = 0x1d;
                                                                uVar7 = (**(code **)(lVar5 + 0x10))
                                                                                  (*(undefined8 *)
                                                                                    (lVar5 + 0xb8),
                                                                                   0xffffffff,
                                                                                   &uStack_2e8);
                                                                if ((int)uVar7 == 0) {
                                                                  memset(&uStack_2e8,0,0xb0);
                                                                  uStack_2dc = 10;
                                                                  pcVar6 = (char *)FUN_18000cce0(
                                                  0x2a);
                                                  strncpy_s(acStack_2d8,0x20,pcVar6,
                                                            0xffffffffffffffff);
                                                  uStack_2b0 = 0;
                                                  uStack_280 = 0;
                                                  uStack_27c = 0x42c80000;
                                                  uStack_274 = 0x42c80000;
                                                  uStack_270 = 0;
                                                  uStack_26c = 1;
                                                  uStack_268 = uStack_268 & 0xffffffff;
                                                  uStack_2e8 = 0x1e;
                                                  uVar7 = (**(code **)(lVar5 + 0x10))
                                                                    (*(undefined8 *)(lVar5 + 0xb8),
                                                                     0xffffffff,&uStack_2e8);
                                                  if ((int)uVar7 == 0) {
                                                    memset(&uStack_2e8,0,0xb0);
                                                    uStack_2dc = 10;
                                                    pcVar6 = (char *)FUN_18000cce0(0x2b);
                                                    strncpy_s(acStack_2d8,0x20,pcVar6,
                                                              0xffffffffffffffff);
                                                    uStack_2b0 = 0;
                                                    uStack_280 = 0;
                                                    uStack_27c = 0x42c80000;
                                                    uStack_274 = 0x42c80000;
                                                    uStack_270 = 0;
                                                    uStack_26c = 1;
                                                    uStack_268 = uStack_268 & 0xffffffff;
                                                    uStack_2e8 = 0x1f;
                                                    uVar7 = (**(code **)(lVar5 + 0x10))
                                                                      (*(undefined8 *)(lVar5 + 0xb8)
                                                                       ,0xffffffff,&uStack_2e8);
                                                    if ((int)uVar7 == 0) {
                                                      memset(&uStack_2e8,0,0xb0);
                                                      uStack_2dc = 10;
                                                      pcVar6 = (char *)FUN_18000cce0(0x2c);
                                                      strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                0xffffffffffffffff);
                                                      uStack_2b0 = 0x4008000000000000;
                                                      uStack_280 = 0x3f800000;
                                                      uStack_27c = 0x3f80000041a00000;
                                                      uStack_274 = 0x41a00000;
                                                      uStack_270 = 0x40400000;
                                                      uStack_26c = 1;
                                                      uStack_268 = uStack_268 & 0xffffffff;
                                                      uStack_2e8 = 0x32;
                                                      uVar7 = (**(code **)(lVar5 + 0x10))
                                                                        (*(undefined8 *)
                                                                          (lVar5 + 0xb8),0xffffffff,
                                                                         &uStack_2e8);
                                                      if ((int)uVar7 == 0) {
                                                        memset(&uStack_2e8,0,0xb0);
                                                        uStack_2dc = 10;
                                                        pcVar6 = (char *)FUN_18000cce0(0x2d);
                                                        strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                  0xffffffffffffffff);
                                                        uStack_2b0 = 0;
                                                        uStack_280 = 0;
                                                        uStack_27c = 0x42c80000;
                                                        uStack_274 = 0x42c80000;
                                                        uStack_270 = 0;
                                                        uStack_26c = 1;
                                                        uStack_268 = uStack_268 & 0xffffffff;
                                                        uStack_2e8 = 0x20;
                                                        uVar7 = (**(code **)(lVar5 + 0x10))
                                                                          (*(undefined8 *)
                                                                            (lVar5 + 0xb8),
                                                                           0xffffffff,&uStack_2e8);
                                                        if ((int)uVar7 == 0) {
                                                          memset(&uStack_2e8,0,0xb0);
                                                          uStack_2dc = 10;
                                                          pcVar6 = (char *)FUN_18000cce0(0x2e);
                                                          strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                    0xffffffffffffffff);
                                                          uStack_2b0 = 0;
                                                          uStack_280 = 0;
                                                          uStack_27c = 0x42c80000;
                                                          uStack_274 = 0x42c80000;
                                                          uStack_270 = 0;
                                                          uStack_26c = 1;
                                                          uStack_268 = uStack_268 & 0xffffffff;
                                                          uStack_2e8 = 0x21;
                                                          uVar7 = (**(code **)(lVar5 + 0x10))
                                                                            (*(undefined8 *)
                                                                              (lVar5 + 0xb8),
                                                                             0xffffffff,&uStack_2e8)
                                                          ;
                                                          if ((int)uVar7 == 0) {
                                                            memset(&uStack_2e8,0,0xb0);
                                                            uStack_2dc = 1;
                                                            pcVar6 = (char *)FUN_18000cce0(0x2f);
                                                            strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                      0xffffffffffffffff);
                                                            uStack_28c = 0;
                                                            uStack_26c = 0;
                                                            uStack_268 = 1000;
                                                            uStack_260 = 1000;
                                                            uStack_2b0 = uStack_2b0 &
                                                                         0xffffff0000000000;
                                                            uStack_2e8 = 0x22;
                                                            uVar7 = (**(code **)(lVar5 + 0x10))
                                                                              (*(undefined8 *)
                                                                                (lVar5 + 0xb8),
                                                                               0xffffffff,
                                                                               &uStack_2e8);
                                                            if ((int)uVar7 == 0) {
                                                              memset(&uStack_2e8,0,0xb0);
                                                              uStack_2dc = 0xe;
                                                              uStack_2e8 = 0x23;
                                                              uVar7 = (**(code **)(lVar5 + 0x10))
                                                                                (*(undefined8 *)
                                                                                  (lVar5 + 0xb8),
                                                                                 0xffffffff,
                                                                                 &uStack_2e8);
                                                              if ((int)uVar7 == 0) {
                                                                memset(&uStack_2e8,0,0xb0);
                                                                uStack_2dc = 0xd;
                                                                pcVar6 = (char *)FUN_18000cce0(0x30)
                                                                ;
                                                                strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                          0xffffffffffffffff);
                                                                uStack_2e8 = 0x24;
                                                                uVar7 = (**(code **)(lVar5 + 0x10))
                                                                                  (*(undefined8 *)
                                                                                    (lVar5 + 0xb8),
                                                                                   0xffffffff,
                                                                                   &uStack_2e8);
                                                                if ((int)uVar7 == 0) {
                                                                  memset(&uStack_2e8,0,0xb0);
                                                                  uStack_2dc = 10;
                                                                  pcVar6 = (char *)FUN_18000cce0(
                                                  0x31);
                                                  strncpy_s(acStack_2d8,0x20,pcVar6,
                                                            0xffffffffffffffff);
                                                  uStack_2b0 = 0;
                                                  uStack_280 = 0;
                                                  uStack_27c = 0x42c80000;
                                                  uStack_274 = 0x42c80000;
                                                  uStack_270 = 0;
                                                  uStack_26c = 1;
                                                  uStack_268 = uStack_268 & 0xffffffff;
                                                  uStack_2e8 = 0x25;
                                                  uVar7 = (**(code **)(lVar5 + 0x10))
                                                                    (*(undefined8 *)(lVar5 + 0xb8),
                                                                     0xffffffff,&uStack_2e8);
                                                  if ((int)uVar7 == 0) {
                                                    memset(&uStack_2e8,0,0xb0);
                                                    uStack_2dc = 4;
                                                    pcVar6 = (char *)FUN_18000cce0(0x32);
                                                    strncpy_s(acStack_2d8,0x20,pcVar6,
                                                              0xffffffffffffffff);
                                                    puStack_2a8 = &DAT_180029c25;
                                                    uStack_2b0 = uStack_2b0 & 0xffffff0000000000;
                                                    uStack_2e8 = 0x26;
                                                    uVar7 = (**(code **)(lVar5 + 0x10))
                                                                      (*(undefined8 *)(lVar5 + 0xb8)
                                                                       ,0xffffffff,&uStack_2e8);
                                                    if ((int)uVar7 == 0) {
                                                      memset(&uStack_2e8,0,0xb0);
                                                      uStack_2dc = 4;
                                                      pcVar6 = (char *)FUN_18000cce0(0x33);
                                                      strncpy_s(acStack_2d8,0x20,pcVar6,
                                                                0xffffffffffffffff);
                                                      puStack_2a8 = &DAT_180029c25;
                                                      uStack_2b0 = uStack_2b0 & 0xffffff0000000000;
                                                      uStack_2e8 = 0x27;
                                                      uVar7 = (**(code **)(lVar5 + 0x10))
                                                                        (*(undefined8 *)
                                                                          (lVar5 + 0xb8),0xffffffff,
                                                                         &uStack_2e8);
                                                      if ((int)uVar7 == 0) {
                                                        memset(&uStack_2e8,0,0xb0);
                                                        uStack_2dc = 0xe;
                                                        uStack_2e8 = 0x28;
                                                        uVar7 = (**(code **)(lVar5 + 0x10))
                                                                          (*(undefined8 *)
                                                                            (lVar5 + 0xb8),
                                                                           0xffffffff,&uStack_2e8);
                                                        if ((int)uVar7 == 0) {
                                                          uStack_234 = 4;
                                                          uStack_22c = 0;
                                                          pcVar9[0x30] = '3';
                                                          pcVar9[0x31] = '\0';
                                                          pcVar9[0x32] = '\0';
                                                          pcVar9[0x33] = '\0';
                                                          uStack_224 = 0;
                                                          uStack_21c = 0;
                                                          uStack_238 = 0;
                                                          uStack_214 = 0;
                                                          uVar7 = (**(code **)(lVar5 + 0x28))
                                                                            (*(undefined8 *)
                                                                              (lVar5 + 0xb8),
                                                                             &uStack_238);
                                                        }
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      return uVar7;
    }
  }
  uStack_1a0 = 0x1800077c4;
  free(_Memory);
LAB_1800077c4:
  if (local_100 != (undefined8 *)0x0) {
    uStack_1a0 = 0x1800077da;
    (*(code *)puVar10[1])("DRAWBOT Image Suite",1);
  }
  if (local_140 != (undefined8 *)0x0) {
    uStack_1a0 = 0x1800077f1;
    (*(code *)puVar10[1])("DRAWBOT Surface Suite",2);
  }
  if (local_150 != 0) {
    uStack_1a0 = 0x180007808;
    (*(code *)puVar10[1])("DRAWBOT Supplier Suite",1);
  }
  if (local_128 != (undefined8 *)0x0) {
    uStack_1a0 = 0x18000781f;
    (*(code *)puVar10[1])("DRAWBOT Draw Suite",1);
  }
  if (local_f8 != (undefined8 *)0x0) {
    uStack_1a0 = 0x180007835;
    (*(code *)puVar10[1])("PF Effect Custom UI Suite",2);
  }
  return 0;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_180007880(longlong param_1,longlong param_2)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  char local_148 [32];
  undefined4 local_128;
  ulonglong local_120;
  undefined *local_118;
  undefined1 local_fc;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined4 local_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  ulonglong local_d8;
  undefined8 local_d0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined8 uStack_9c;
  undefined8 local_94;
  undefined8 uStack_8c;
  undefined8 local_84;
  ulonglong local_78;
  
  local_78 = DAT_180030500 ^ (ulonglong)auStack_178;
  memset(&local_158,0,0xb0);
  local_150 = 0x2800dc;
  local_128 = 2;
  local_154 = 2;
  local_14c = 5;
  pcVar2 = (char *)FUN_18000cce0(3);
  strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
  local_120 = 0x550affff550affff;
  local_158 = 1;
  iVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
  if (iVar1 == 0) {
    memset(&local_158,0,0xb0);
    local_14c = 7;
    pcVar2 = (char *)FUN_18000cce0(4);
    strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
    local_120 = 0x1000600000001;
    local_118 = (undefined *)FUN_18000cce0(5);
    local_158 = 2;
    iVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
    if (iVar1 == 0) {
      memset(&local_158,0,0xb0);
      local_14c = 10;
      pcVar2 = (char *)FUN_18000cce0(6);
      strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
      local_120 = 0x4028000000000000;
      local_f0 = 0x40800000;
      local_ec = 0x4080000042c00000;
      local_e4 = 0x42400000;
      uStack_e0 = 0x41400000;
      uStack_dc = 0;
      local_d8 = (ulonglong)(uint)local_d8;
      local_158 = 3;
      iVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
      if (iVar1 == 0) {
        memset(&local_158,0,0xb0);
        local_14c = 10;
        pcVar2 = (char *)FUN_18000cce0(7);
        strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
        local_120 = 0x3fe0000000000000;
        local_f0 = 0x3e99999a;
        local_ec = 0x3e99999a3f800000;
        local_e4 = 0x3f800000;
        uStack_e0 = 0x3f000000;
        uStack_dc = 2;
        local_d8 = local_d8 & 0xffffffff;
        local_158 = 4;
        iVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158)
        ;
        if (iVar1 == 0) {
          memset(&local_158,0,0xb0);
          local_14c = 7;
          pcVar2 = (char *)FUN_18000cce0(8);
          strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
          local_120 = 0x1000400000001;
          local_118 = (undefined *)FUN_18000cce0(9);
          local_158 = 5;
          iVar1 = (**(code **)(param_1 + 0x10))
                            (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
          if (iVar1 == 0) {
            memset(&local_158,0,0xb0);
            local_14c = 10;
            pcVar2 = (char *)FUN_18000cce0(10);
            strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
            local_120 = 0x4059000000000000;
            local_f0 = 0;
            local_ec = 0x42c80000;
            local_e4 = 0x42c80000;
            uStack_e0 = 0x42c80000;
            uStack_dc = 1;
            local_d8 = local_d8 & 0xffffffff;
            local_158 = 6;
            iVar1 = (**(code **)(param_1 + 0x10))
                              (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
            if (iVar1 == 0) {
              memset(&local_158,0,0xb0);
              local_14c = 0xd;
              pcVar2 = (char *)FUN_18000cce0(0xb);
              strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
              local_158 = 7;
              iVar1 = (**(code **)(param_1 + 0x10))
                                (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
              if (iVar1 == 0) {
                memset(&local_158,0,0xb0);
                local_14c = 4;
                pcVar2 = (char *)FUN_18000cce0(0xc);
                strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                local_118 = &DAT_180029c25;
                local_120 = local_120 & 0xffffff0000000000;
                local_158 = 8;
                iVar1 = (**(code **)(param_1 + 0x10))
                                  (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
                if (iVar1 == 0) {
                  memset(&local_158,0,0xb0);
                  local_14c = 10;
                  pcVar2 = (char *)FUN_18000cce0(0xd);
                  strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                  local_120 = 0x3ff0000000000000;
                  local_f0 = 0x3e4ccccd;
                  local_ec = 0x3e4ccccd40400000;
                  local_e4 = 0x40400000;
                  uStack_e0 = 0x3f800000;
                  uStack_dc = 2;
                  local_d8 = local_d8 & 0xffffffff;
                  local_158 = 9;
                  iVar1 = (**(code **)(param_1 + 0x10))
                                    (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
                  if (iVar1 == 0) {
                    memset(&local_158,0,0xb0);
                    local_14c = 10;
                    pcVar2 = (char *)FUN_18000cce0(0xe);
                    strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                    local_f0 = 0xc2c80000;
                    local_120 = 0;
                    local_ec = 0xc2c8000042c80000;
                    local_e4 = 0x42c80000;
                    uStack_e0 = 0;
                    uStack_dc = 1;
                    local_d8 = local_d8 & 0xffffffff;
                    local_158 = 10;
                    iVar1 = (**(code **)(param_1 + 0x10))
                                      (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
                    if (iVar1 == 0) {
                      memset(&local_158,0,0xb0);
                      local_14c = 7;
                      pcVar2 = (char *)FUN_18000cce0(0xf);
                      strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                      local_120 = 0x1000300000001;
                      local_118 = (undefined *)FUN_18000cce0(0x10);
                      local_158 = 0xb;
                      iVar1 = (**(code **)(param_1 + 0x10))
                                        (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
                      if (iVar1 == 0) {
                        memset(&local_158,0,0xb0);
                        local_14c = 10;
                        pcVar2 = (char *)FUN_18000cce0(0x11);
                        strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                        local_120 = 0x4039000000000000;
                        local_f0 = 0;
                        local_ec = 0x42c80000;
                        local_e4 = 0x42c80000;
                        uStack_e0 = 0x41c80000;
                        uStack_dc = 1;
                        local_d8 = local_d8 & 0xffffffff;
                        local_158 = 0xc;
                        iVar1 = (**(code **)(param_1 + 0x10))
                                          (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
                        if (iVar1 == 0) {
                          memset(&local_158,0,0xb0);
                          local_14c = 10;
                          pcVar2 = (char *)FUN_18000cce0(0x12);
                          strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                          local_120 = 0x4030000000000000;
                          local_f0 = 0x40a00000;
                          local_ec = 0x40a0000042480000;
                          local_e4 = 0x42480000;
                          uStack_e0 = 0x41800000;
                          uStack_dc = 1;
                          local_d8 = local_d8 & 0xffffffff;
                          local_158 = 0xd;
                          iVar1 = (**(code **)(param_1 + 0x10))
                                            (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158);
                          if (iVar1 == 0) {
                            memset(&local_158,0,0xb0);
                            pcVar2 = (char *)FUN_18000cce0(0x13);
                            strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                            local_ac = 0;
                            local_158 = 0xe;
                            iVar1 = (**(code **)(param_1 + 0x10))
                                              (*(undefined8 *)(param_1 + 0xb8),0xffffffff,&local_158
                                              );
                            if (iVar1 == 0) {
                              memset(&local_158,0,0xb0);
                              local_14c = 10;
                              pcVar2 = (char *)FUN_18000cce0(0x14);
                              strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                              local_120 = 0;
                              local_f0 = 0;
                              local_ec = 0x42c80000;
                              local_e4 = 0x42c80000;
                              uStack_e0 = 0;
                              uStack_dc = 1;
                              local_d8 = local_d8 & 0xffffffff;
                              local_158 = 0xf;
                              iVar1 = (**(code **)(param_1 + 0x10))
                                                (*(undefined8 *)(param_1 + 0xb8),0xffffffff,
                                                 &local_158);
                              if (iVar1 == 0) {
                                memset(&local_158,0,0xb0);
                                local_14c = 10;
                                pcVar2 = (char *)FUN_18000cce0(0x15);
                                strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                local_120 = 0x4034000000000000;
                                local_f0 = 0;
                                local_ec = 0x42c80000;
                                local_e4 = 0x42c80000;
                                uStack_e0 = 0x41a00000;
                                uStack_dc = 1;
                                local_d8 = local_d8 & 0xffffffff;
                                local_158 = 0x10;
                                iVar1 = (**(code **)(param_1 + 0x10))
                                                  (*(undefined8 *)(param_1 + 0xb8),0xffffffff,
                                                   &local_158);
                                if (iVar1 == 0) {
                                  memset(&local_158,0,0xb0);
                                  local_14c = 4;
                                  pcVar2 = (char *)FUN_18000cce0(0x16);
                                  strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                  local_118 = &DAT_180029c25;
                                  local_120 = local_120 & 0xffffff0000000000;
                                  local_158 = 0x11;
                                  iVar1 = (**(code **)(param_1 + 0x10))
                                                    (*(undefined8 *)(param_1 + 0xb8),0xffffffff,
                                                     &local_158);
                                  if (iVar1 == 0) {
                                    memset(&local_158,0,0xb0);
                                    local_14c = 0xe;
                                    local_158 = 0x12;
                                    iVar1 = (**(code **)(param_1 + 0x10))
                                                      (*(undefined8 *)(param_1 + 0xb8),0xffffffff,
                                                       &local_158);
                                    if (iVar1 == 0) {
                                      memset(&local_158,0,0xb0);
                                      local_14c = 0xd;
                                      pcVar2 = (char *)FUN_18000cce0(0x17);
                                      strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                      local_158 = 0x13;
                                      iVar1 = (**(code **)(param_1 + 0x10))
                                                        (*(undefined8 *)(param_1 + 0xb8),0xffffffff,
                                                         &local_158);
                                      if (iVar1 == 0) {
                                        memset(&local_158,0,0xb0);
                                        local_14c = 5;
                                        pcVar2 = (char *)FUN_18000cce0(0x18);
                                        strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                        local_120 = 0xf0e8e2fff0e8e2ff;
                                        local_158 = 0x14;
                                        iVar1 = (**(code **)(param_1 + 0x10))
                                                          (*(undefined8 *)(param_1 + 0xb8),
                                                           0xffffffff,&local_158);
                                        if (iVar1 == 0) {
                                          memset(&local_158,0,0xb0);
                                          local_14c = 5;
                                          pcVar2 = (char *)FUN_18000cce0(0x19);
                                          strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                          local_120 = 0x120c0aff120c0aff;
                                          local_158 = 0x15;
                                          iVar1 = (**(code **)(param_1 + 0x10))
                                                            (*(undefined8 *)(param_1 + 0xb8),
                                                             0xffffffff,&local_158);
                                          if (iVar1 == 0) {
                                            memset(&local_158,0,0xb0);
                                            local_14c = 5;
                                            pcVar2 = (char *)FUN_18000cce0(0x1a);
                                            strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                            local_120 = 0x5900ffff5900ffff;
                                            local_158 = 0x16;
                                            iVar1 = (**(code **)(param_1 + 0x10))
                                                              (*(undefined8 *)(param_1 + 0xb8),
                                                               0xffffffff,&local_158);
                                            if (iVar1 == 0) {
                                              memset(&local_158,0,0xb0);
                                              local_14c = 10;
                                              pcVar2 = (char *)FUN_18000cce0(0x1b);
                                              strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                              local_120 = 0x4059000000000000;
                                              local_f0 = 0;
                                              local_ec = 0x42c80000;
                                              local_e4 = 0x42c80000;
                                              uStack_e0 = 0x42c80000;
                                              uStack_dc = 1;
                                              local_d8 = local_d8 & 0xffffffff;
                                              local_158 = 0x17;
                                              iVar1 = (**(code **)(param_1 + 0x10))
                                                                (*(undefined8 *)(param_1 + 0xb8),
                                                                 0xffffffff,&local_158);
                                              if (iVar1 == 0) {
                                                memset(&local_158,0,0xb0);
                                                local_14c = 4;
                                                pcVar2 = (char *)FUN_18000cce0(0x1c);
                                                strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff);
                                                local_118 = &DAT_180029c25;
                                                local_120 = local_120 & 0xffffff0000000000;
                                                local_158 = 0x18;
                                                iVar1 = (**(code **)(param_1 + 0x10))
                                                                  (*(undefined8 *)(param_1 + 0xb8),
                                                                   0xffffffff,&local_158);
                                                if (iVar1 == 0) {
                                                  memset(&local_158,0,0xb0);
                                                  local_14c = 0xe;
                                                  local_158 = 0x19;
                                                  iVar1 = (**(code **)(param_1 + 0x10))
                                                                    (*(undefined8 *)(param_1 + 0xb8)
                                                                     ,0xffffffff,&local_158);
                                                  if (iVar1 == 0) {
                                                    memset(&local_158,0,0xb0);
                                                    local_14c = 0xd;
                                                    pcVar2 = (char *)FUN_18000cce0(0x1d);
                                                    strncpy_s(local_148,0x20,pcVar2,
                                                              0xffffffffffffffff);
                                                    local_158 = 0x29;
                                                    iVar1 = (**(code **)(param_1 + 0x10))
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0xb8),0xffffffff,
                                                                       &local_158);
                                                    if (iVar1 == 0) {
                                                      memset(&local_158,0,0xb0);
                                                      local_14c = 7;
                                                      pcVar2 = (char *)FUN_18000cce0(0x1e);
                                                      strncpy_s(local_148,0x20,pcVar2,
                                                                0xffffffffffffffff);
                                                      local_120 = 0x1000300000001;
                                                      local_118 = (undefined *)FUN_18000cce0(0x1f);
                                                      local_158 = 0x2a;
                                                      iVar1 = (**(code **)(param_1 + 0x10))
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0xb8),
                                                                         0xffffffff,&local_158);
                                                      if (iVar1 == 0) {
                                                        memset(&local_158,0,0xb0);
                                                        pcVar2 = (char *)FUN_18000cce0(0x20);
                                                        strncpy_s(local_148,0x20,pcVar2,
                                                                  0xffffffffffffffff);
                                                        local_ac = 0;
                                                        local_158 = 0x2b;
                                                        iVar1 = (**(code **)(param_1 + 0x10))
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0xb8),
                                                                           0xffffffff,&local_158);
                                                        if (iVar1 == 0) {
                                                          memset(&local_158,0,0xb0);
                                                          local_14c = 4;
                                                          pcVar2 = (char *)FUN_18000cce0(0x21);
                                                          strncpy_s(local_148,0x20,pcVar2,
                                                                    0xffffffffffffffff);
                                                          local_118 = &DAT_180029c25;
                                                          local_120 = local_120 & 0xffffff0000000000
                                                          ;
                                                          local_158 = 0x2c;
                                                          iVar1 = (**(code **)(param_1 + 0x10))
                                                                            (*(undefined8 *)
                                                                              (param_1 + 0xb8),
                                                                             0xffffffff,&local_158);
                                                          if (iVar1 == 0) {
                                                            memset(&local_158,0,0xb0);
                                                            local_14c = 10;
                                                            pcVar2 = (char *)FUN_18000cce0(0x22);
                                                            strncpy_s(local_148,0x20,pcVar2,
                                                                      0xffffffffffffffff);
                                                            local_120 = 0x4039000000000000;
                                                            local_f0 = 0;
                                                            local_ec = 0x42c80000;
                                                            local_e4 = 0x42c80000;
                                                            uStack_e0 = 0x41c80000;
                                                            uStack_dc = 1;
                                                            local_d8 = local_d8 & 0xffffffff;
                                                            local_158 = 0x2d;
                                                            iVar1 = (**(code **)(param_1 + 0x10))
                                                                              (*(undefined8 *)
                                                                                (param_1 + 0xb8),
                                                                               0xffffffff,&local_158
                                                                              );
                                                            if (iVar1 == 0) {
                                                              memset(&local_158,0,0xb0);
                                                              local_14c = 3;
                                                              pcVar2 = (char *)FUN_18000cce0(0x23);
                                                              strncpy_s(local_148,0x20,pcVar2,
                                                                        0xffffffffffffffff);
                                                              local_120 = 0;
                                                              local_158 = 0x2e;
                                                              iVar1 = (**(code **)(param_1 + 0x10))
                                                                                (*(undefined8 *)
                                                                                  (param_1 + 0xb8),
                                                                                 0xffffffff,
                                                                                 &local_158);
                                                              if (iVar1 == 0) {
                                                                memset(&local_158,0,0xb0);
                                                                local_14c = 10;
                                                                pcVar2 = (char *)FUN_18000cce0(0x24)
                                                                ;
                                                                strncpy_s(local_148,0x20,pcVar2,
                                                                          0xffffffffffffffff);
                                                                local_120 = 0x4041800000000000;
                                                                local_f0 = 0;
                                                                local_ec = 0x42c80000;
                                                                local_e4 = 0x42c80000;
                                                                uStack_e0 = 0x420c0000;
                                                                uStack_dc = 1;
                                                                local_d8 = local_d8 & 0xffffffff;
                                                                local_158 = 0x2f;
                                                                iVar1 = (**(code **)(param_1 + 0x10)
                                                                        )(*(undefined8 *)
                                                                           (param_1 + 0xb8),
                                                                          0xffffffff,&local_158);
                                                                if (iVar1 == 0) {
                                                                  memset(&local_158,0,0xb0);
                                                                  local_14c = 10;
                                                                  pcVar2 = (char *)FUN_18000cce0(
                                                  0x25);
                                                  strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff
                                                           );
                                                  local_120 = 0x403e000000000000;
                                                  local_f0 = 0;
                                                  local_ec = 0x42c80000;
                                                  local_e4 = 0x42c80000;
                                                  uStack_e0 = 0x41f00000;
                                                  uStack_dc = 1;
                                                  local_d8 = local_d8 & 0xffffffff;
                                                  local_158 = 0x30;
                                                  iVar1 = (**(code **)(param_1 + 0x10))
                                                                    (*(undefined8 *)(param_1 + 0xb8)
                                                                     ,0xffffffff,&local_158);
                                                  if (iVar1 == 0) {
                                                    memset(&local_158,0,0xb0);
                                                    local_14c = 0xe;
                                                    local_158 = 0x31;
                                                    iVar1 = (**(code **)(param_1 + 0x10))
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0xb8),0xffffffff,
                                                                       &local_158);
                                                    if (iVar1 == 0) {
                                                      memset(&local_158,0,0xb0);
                                                      local_14c = 0xd;
                                                      pcVar2 = (char *)FUN_18000cce0(0x26);
                                                      strncpy_s(local_148,0x20,pcVar2,
                                                                0xffffffffffffffff);
                                                      local_158 = 0x1a;
                                                      iVar1 = (**(code **)(param_1 + 0x10))
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0xb8),
                                                                         0xffffffff,&local_158);
                                                      if (iVar1 == 0) {
                                                        memset(&local_158,0,0xb0);
                                                        local_14c = 4;
                                                        pcVar2 = (char *)FUN_18000cce0(0x27);
                                                        strncpy_s(local_148,0x20,pcVar2,
                                                                  0xffffffffffffffff);
                                                        local_118 = &DAT_180029c25;
                                                        local_120 = local_120 & 0xffffff0000000000;
                                                        local_158 = 0x1b;
                                                        iVar1 = (**(code **)(param_1 + 0x10))
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0xb8),
                                                                           0xffffffff,&local_158);
                                                        if (iVar1 == 0) {
                                                          memset(&local_158,0,0xb0);
                                                          local_14c = 10;
                                                          pcVar2 = (char *)FUN_18000cce0(0x28);
                                                          strncpy_s(local_148,0x20,pcVar2,
                                                                    0xffffffffffffffff);
                                                          local_120 = 0;
                                                          local_f0 = 0;
                                                          local_ec = 0x42c80000;
                                                          local_e4 = 0x42c80000;
                                                          uStack_e0 = 0;
                                                          uStack_dc = 1;
                                                          local_d8 = local_d8 & 0xffffffff;
                                                          local_158 = 0x1c;
                                                          iVar1 = (**(code **)(param_1 + 0x10))
                                                                            (*(undefined8 *)
                                                                              (param_1 + 0xb8),
                                                                             0xffffffff,&local_158);
                                                          if (iVar1 == 0) {
                                                            memset(&local_158,0,0xb0);
                                                            local_14c = 3;
                                                            pcVar2 = (char *)FUN_18000cce0(0x29);
                                                            strncpy_s(local_148,0x20,pcVar2,
                                                                      0xffffffffffffffff);
                                                            local_120 = 0;
                                                            local_158 = 0x1d;
                                                            iVar1 = (**(code **)(param_1 + 0x10))
                                                                              (*(undefined8 *)
                                                                                (param_1 + 0xb8),
                                                                               0xffffffff,&local_158
                                                                              );
                                                            if (iVar1 == 0) {
                                                              memset(&local_158,0,0xb0);
                                                              local_14c = 10;
                                                              pcVar2 = (char *)FUN_18000cce0(0x2a);
                                                              strncpy_s(local_148,0x20,pcVar2,
                                                                        0xffffffffffffffff);
                                                              local_120 = 0;
                                                              local_f0 = 0;
                                                              local_ec = 0x42c80000;
                                                              local_e4 = 0x42c80000;
                                                              uStack_e0 = 0;
                                                              uStack_dc = 1;
                                                              local_d8 = local_d8 & 0xffffffff;
                                                              local_158 = 0x1e;
                                                              iVar1 = (**(code **)(param_1 + 0x10))
                                                                                (*(undefined8 *)
                                                                                  (param_1 + 0xb8),
                                                                                 0xffffffff,
                                                                                 &local_158);
                                                              if (iVar1 == 0) {
                                                                memset(&local_158,0,0xb0);
                                                                local_14c = 10;
                                                                pcVar2 = (char *)FUN_18000cce0(0x2b)
                                                                ;
                                                                strncpy_s(local_148,0x20,pcVar2,
                                                                          0xffffffffffffffff);
                                                                local_120 = 0;
                                                                local_f0 = 0;
                                                                local_ec = 0x42c80000;
                                                                local_e4 = 0x42c80000;
                                                                uStack_e0 = 0;
                                                                uStack_dc = 1;
                                                                local_d8 = local_d8 & 0xffffffff;
                                                                local_158 = 0x1f;
                                                                iVar1 = (**(code **)(param_1 + 0x10)
                                                                        )(*(undefined8 *)
                                                                           (param_1 + 0xb8),
                                                                          0xffffffff,&local_158);
                                                                if (iVar1 == 0) {
                                                                  memset(&local_158,0,0xb0);
                                                                  local_14c = 10;
                                                                  pcVar2 = (char *)FUN_18000cce0(
                                                  0x2c);
                                                  strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff
                                                           );
                                                  local_120 = 0x4008000000000000;
                                                  local_f0 = 0x3f800000;
                                                  local_ec = 0x3f80000041a00000;
                                                  local_e4 = 0x41a00000;
                                                  uStack_e0 = 0x40400000;
                                                  uStack_dc = 1;
                                                  local_d8 = local_d8 & 0xffffffff;
                                                  local_158 = 0x32;
                                                  iVar1 = (**(code **)(param_1 + 0x10))
                                                                    (*(undefined8 *)(param_1 + 0xb8)
                                                                     ,0xffffffff,&local_158);
                                                  if (iVar1 == 0) {
                                                    memset(&local_158,0,0xb0);
                                                    local_14c = 10;
                                                    pcVar2 = (char *)FUN_18000cce0(0x2d);
                                                    strncpy_s(local_148,0x20,pcVar2,
                                                              0xffffffffffffffff);
                                                    local_120 = 0;
                                                    local_f0 = 0;
                                                    local_ec = 0x42c80000;
                                                    local_e4 = 0x42c80000;
                                                    uStack_e0 = 0;
                                                    uStack_dc = 1;
                                                    local_d8 = local_d8 & 0xffffffff;
                                                    local_158 = 0x20;
                                                    iVar1 = (**(code **)(param_1 + 0x10))
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0xb8),0xffffffff,
                                                                       &local_158);
                                                    if (iVar1 == 0) {
                                                      memset(&local_158,0,0xb0);
                                                      local_14c = 10;
                                                      pcVar2 = (char *)FUN_18000cce0(0x2e);
                                                      strncpy_s(local_148,0x20,pcVar2,
                                                                0xffffffffffffffff);
                                                      local_120 = 0;
                                                      local_f0 = 0;
                                                      local_ec = 0x42c80000;
                                                      local_e4 = 0x42c80000;
                                                      uStack_e0 = 0;
                                                      uStack_dc = 1;
                                                      local_d8 = local_d8 & 0xffffffff;
                                                      local_158 = 0x21;
                                                      iVar1 = (**(code **)(param_1 + 0x10))
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0xb8),
                                                                         0xffffffff,&local_158);
                                                      if (iVar1 == 0) {
                                                        memset(&local_158,0,0xb0);
                                                        local_14c = 1;
                                                        pcVar2 = (char *)FUN_18000cce0(0x2f);
                                                        strncpy_s(local_148,0x20,pcVar2,
                                                                  0xffffffffffffffff);
                                                        local_fc = 0;
                                                        uStack_dc = 0;
                                                        local_d8 = 1000;
                                                        local_d0 = 1000;
                                                        local_120 = local_120 & 0xffffff0000000000;
                                                        local_158 = 0x22;
                                                        iVar1 = (**(code **)(param_1 + 0x10))
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0xb8),
                                                                           0xffffffff,&local_158);
                                                        if (iVar1 == 0) {
                                                          memset(&local_158,0,0xb0);
                                                          local_14c = 0xe;
                                                          local_158 = 0x23;
                                                          iVar1 = (**(code **)(param_1 + 0x10))
                                                                            (*(undefined8 *)
                                                                              (param_1 + 0xb8),
                                                                             0xffffffff,&local_158);
                                                          if (iVar1 == 0) {
                                                            memset(&local_158,0,0xb0);
                                                            local_14c = 0xd;
                                                            pcVar2 = (char *)FUN_18000cce0(0x30);
                                                            strncpy_s(local_148,0x20,pcVar2,
                                                                      0xffffffffffffffff);
                                                            local_158 = 0x24;
                                                            iVar1 = (**(code **)(param_1 + 0x10))
                                                                              (*(undefined8 *)
                                                                                (param_1 + 0xb8),
                                                                               0xffffffff,&local_158
                                                                              );
                                                            if (iVar1 == 0) {
                                                              memset(&local_158,0,0xb0);
                                                              local_14c = 10;
                                                              pcVar2 = (char *)FUN_18000cce0(0x31);
                                                              strncpy_s(local_148,0x20,pcVar2,
                                                                        0xffffffffffffffff);
                                                              local_120 = 0;
                                                              local_f0 = 0;
                                                              local_ec = 0x42c80000;
                                                              local_e4 = 0x42c80000;
                                                              uStack_e0 = 0;
                                                              uStack_dc = 1;
                                                              local_d8 = local_d8 & 0xffffffff;
                                                              local_158 = 0x25;
                                                              iVar1 = (**(code **)(param_1 + 0x10))
                                                                                (*(undefined8 *)
                                                                                  (param_1 + 0xb8),
                                                                                 0xffffffff,
                                                                                 &local_158);
                                                              if (iVar1 == 0) {
                                                                memset(&local_158,0,0xb0);
                                                                local_14c = 4;
                                                                pcVar2 = (char *)FUN_18000cce0(0x32)
                                                                ;
                                                                strncpy_s(local_148,0x20,pcVar2,
                                                                          0xffffffffffffffff);
                                                                local_118 = &DAT_180029c25;
                                                                local_120 = local_120 &
                                                                            0xffffff0000000000;
                                                                local_158 = 0x26;
                                                                iVar1 = (**(code **)(param_1 + 0x10)
                                                                        )(*(undefined8 *)
                                                                           (param_1 + 0xb8),
                                                                          0xffffffff,&local_158);
                                                                if (iVar1 == 0) {
                                                                  memset(&local_158,0,0xb0);
                                                                  local_14c = 4;
                                                                  pcVar2 = (char *)FUN_18000cce0(
                                                  0x33);
                                                  strncpy_s(local_148,0x20,pcVar2,0xffffffffffffffff
                                                           );
                                                  local_118 = &DAT_180029c25;
                                                  local_120 = local_120 & 0xffffff0000000000;
                                                  local_158 = 0x27;
                                                  iVar1 = (**(code **)(param_1 + 0x10))
                                                                    (*(undefined8 *)(param_1 + 0xb8)
                                                                     ,0xffffffff,&local_158);
                                                  if (iVar1 == 0) {
                                                    memset(&local_158,0,0xb0);
                                                    local_14c = 0xe;
                                                    local_158 = 0x28;
                                                    iVar1 = (**(code **)(param_1 + 0x10))
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0xb8),0xffffffff,
                                                                       &local_158);
                                                    if (iVar1 == 0) {
                                                      local_a4 = 4;
                                                      uStack_9c = 0;
                                                      *(undefined4 *)(param_2 + 0x30) = 0x33;
                                                      local_94 = 0;
                                                      uStack_8c = 0;
                                                      local_a8 = 0;
                                                      local_84 = 0;
                                                      (**(code **)(param_1 + 0x28))
                                                                (*(undefined8 *)(param_1 + 0xb8),
                                                                 &local_a8);
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}



undefined8
FUN_180009080(longlong param_1,longlong param_2,int param_3,int param_4,int param_5,int param_6,
             int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  
  if (param_3 == 2) {
    lVar11 = 0x10;
  }
  else {
    lVar11 = 4;
    if (param_3 == 1) {
      lVar11 = 8;
    }
  }
  memset(*(void **)(param_2 + 0x18),0,
         (longlong)*(int *)(param_2 + 0x28) * (longlong)*(int *)(param_2 + 0x20));
  iVar1 = *(int *)(param_2 + 0x28);
  if (0 < iVar1) {
    iVar6 = param_4 - param_6;
    uVar8 = 0;
    iVar2 = *(int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_2 + 0x24);
    iVar10 = *(int *)(param_1 + 0x24) - (param_6 - param_4);
    param_7 = param_7 - param_5;
    do {
      if ((-1 < param_7) && (param_7 < iVar2)) {
        iVar9 = 0;
        if (0 < iVar6) {
          iVar9 = iVar6;
        }
        iVar4 = iVar3;
        if (iVar10 < iVar3) {
          iVar4 = iVar10;
        }
        if (iVar9 < iVar4) {
          iVar5 = param_6 - param_4;
          if (0 < iVar6) {
            iVar5 = 0;
          }
          memcpy((void *)((longlong)*(int *)(param_2 + 0x20) * uVar8 + iVar9 * lVar11 +
                         *(longlong *)(param_2 + 0x18)),
                 (void *)((longlong)*(int *)(param_1 + 0x20) * (longlong)param_7 + iVar5 * lVar11 +
                         *(longlong *)(param_1 + 0x18)),(iVar4 - iVar9) * lVar11);
        }
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
      param_7 = param_7 + 1;
    } while ((int)uVar7 < iVar1);
  }
  return 0;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

int FUN_1800091e0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined1 auStack_168 [32];
  undefined4 local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined8 *local_130;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  undefined8 local_118;
  int iStack_110;
  int iStack_10c;
  ulonglong local_108;
  undefined1 uStack_100;
  undefined3 uStack_ff;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined8 uStack_f4;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined8 uStack_a4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined8 uStack_54;
  ulonglong local_48;
  
  local_48 = DAT_180030500 ^ (ulonglong)auStack_168;
  lVar3 = *param_3;
  uStack_f4 = *(undefined8 *)(lVar3 + 0x24);
  _uStack_100 = CONCAT31((int3)((ulonglong)*(undefined8 *)(lVar3 + 0x18) >> 8),1);
  uStack_fc = (undefined4)*(undefined8 *)(lVar3 + 0x1c);
  uStack_f8 = (undefined4)((ulonglong)*(undefined8 *)(lVar3 + 0x1c) >> 0x20);
  local_b8 = 0;
  uStack_b0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  uStack_ac = 0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  iVar8 = (int)(((double)*(int *)(param_1 + 0x11c) / (double)*(uint *)(param_1 + 0x120)) *
                (double)*(int *)(param_1 + 0xfc) + 0.5);
  if (iVar8 < 1) {
    iVar8 = 1;
  }
  iVar6 = (int)(((double)*(int *)(param_1 + 0x124) / (double)*(uint *)(param_1 + 0x128)) *
                (double)*(int *)(param_1 + 0x100) + 0.5);
  if (iVar6 < 1) {
    iVar6 = 1;
  }
  _iStack_110 = CONCAT44(iVar6,iVar8);
  local_130 = &local_e8;
  local_118 = 0;
  local_138 = *(undefined4 *)(param_1 + 0xf0);
  local_140 = *(undefined4 *)(param_1 + 0xe4);
  local_148 = *(undefined4 *)(param_1 + 0xe0);
  local_108 = *(ulonglong *)(lVar3 + 0x10) & 0xffffffff00000000;
  local_11c = (**(code **)param_3[2])(*(undefined8 *)(param_1 + 0xb8),0,0,&local_118);
  if (local_11c != 0) goto LAB_1800094d1;
  piVar4 = (int *)*param_3;
  iVar8 = *piVar4;
  iVar6 = piVar4[1];
  iVar1 = piVar4[2];
  iVar2 = piVar4[3];
  iVar5 = uStack_e0._4_4_;
  local_128 = (int)local_e8;
  local_124 = local_e8._4_4_;
  local_120 = (int)uStack_e0;
  iVar10 = iVar8;
  iVar11 = iVar1;
  iVar12 = iVar6;
  iVar14 = iVar2;
  if (((int)local_e8 < (int)uStack_e0) && (local_e8._4_4_ < uStack_e0._4_4_)) {
    iVar10 = (int)local_e8;
    if ((int)local_e8 <= iVar8) {
      iVar10 = iVar8;
    }
    iVar12 = local_e8._4_4_;
    if (local_e8._4_4_ <= iVar6) {
      iVar12 = iVar6;
    }
    iVar11 = (int)uStack_e0;
    if (iVar1 <= (int)uStack_e0) {
      iVar11 = iVar1;
    }
    if (uStack_e0._4_4_ < iVar2) {
      iVar14 = uStack_e0._4_4_;
    }
  }
  if ((iVar11 <= iVar10) || (iVar14 <= iVar12)) {
    iVar10 = iVar8;
    iVar11 = iVar1;
    iVar12 = iVar6;
    iVar14 = iVar2;
  }
  iVar8 = iVar12;
  iVar6 = iVar11;
  if ((int)local_d8 < (int)uStack_d0) {
    iVar9 = (int)local_d8;
    iVar1 = (int)uStack_d0;
    iVar2 = local_d8._4_4_;
    iVar13 = uStack_d0._4_4_;
    if (uStack_d0._4_4_ <= local_d8._4_4_) goto LAB_1800093dd;
LAB_1800093fd:
    iVar8 = iVar2;
    iVar6 = iVar1;
    if ((iVar10 < iVar11) && (iVar12 < iVar14)) {
      iVar8 = iVar10;
      if (iVar9 <= iVar10) {
        iVar8 = iVar9;
      }
      iVar9 = iVar8;
      iVar8 = iVar12;
      if (iVar2 <= iVar12) {
        iVar8 = iVar2;
      }
      iVar6 = iVar11;
      if (iVar11 <= iVar1) {
        iVar6 = iVar1;
      }
      if (iVar13 < iVar14) {
        iVar13 = iVar14;
      }
    }
  }
  else {
LAB_1800093dd:
    iVar9 = iVar10;
    iVar13 = iVar14;
    if (((int)local_e8 < (int)uStack_e0) && (local_e8._4_4_ < uStack_e0._4_4_)) {
      iVar9 = (int)local_e8;
      iVar1 = (int)uStack_e0;
      iVar2 = local_e8._4_4_;
      iVar13 = uStack_e0._4_4_;
      goto LAB_1800093fd;
    }
  }
  piVar4 = (int *)param_3[1];
  *piVar4 = iVar10;
  piVar4[1] = iVar12;
  piVar4[2] = iVar11;
  piVar4[3] = iVar14;
  lVar3 = param_3[1];
  *(int *)(lVar3 + 0x10) = iVar9;
  *(int *)(lVar3 + 0x14) = iVar8;
  *(int *)(lVar3 + 0x18) = iVar6;
  *(int *)(lVar3 + 0x1c) = iVar13;
  *(undefined1 *)(param_3[1] + 0x20) = 0;
  puVar7 = malloc(0x24);
  if (puVar7 != (undefined4 *)0x0) {
    puVar7[1] = local_128;
    puVar7[2] = local_124;
    puVar7[3] = local_120;
    lVar3 = param_3[1];
    *puVar7 = 0x4f564e41;
    puVar7[4] = iVar5;
    puVar7[5] = iVar10;
    puVar7[6] = iVar12;
    puVar7[7] = iVar11;
    puVar7[8] = iVar14;
    *(undefined4 **)(lVar3 + 0x28) = puVar7;
    *(undefined1 **)(param_3[1] + 0x30) = &LAB_18000ab20;
  }
LAB_1800094d1:
  local_130 = &local_98;
  local_138 = *(undefined4 *)(param_1 + 0xf0);
  local_140 = *(undefined4 *)(param_1 + 0xe4);
  local_148 = *(undefined4 *)(param_1 + 0xe0);
  local_68 = 0;
  uStack_60 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  (**(code **)param_3[2])(*(undefined8 *)(param_1 + 0xb8),0xe,0xe,&local_118);
  local_130 = &local_98;
  local_138 = *(undefined4 *)(param_1 + 0xf0);
  local_140 = *(undefined4 *)(param_1 + 0xe4);
  local_148 = *(undefined4 *)(param_1 + 0xe0);
  local_68 = 0;
  uStack_60 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  (**(code **)param_3[2])(*(undefined8 *)(param_1 + 0xb8),0x1c,0x1c,&local_118);
  return local_11c;
}



void FUN_1800095b0(longlong param_1,undefined8 param_2,longlong *param_3,longlong param_4)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined8 in_stack_ffffffffffffffa8;
  uint uVar5;
  undefined8 in_stack_ffffffffffffffb0;
  uint uVar6;
  
  uVar5 = (uint)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  uVar6 = (uint)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  lVar1 = *param_3;
  uVar3 = *(uint *)(param_4 + 0x10) & 1;
  cVar2 = FUN_18000b680();
  if (cVar2 == '\0') {
    FUN_180009080(lVar1 + 0x38,param_4,uVar3,0,(ulonglong)uVar5 << 0x20,(ulonglong)uVar6 << 0x20,0);
  }
  else {
    if (*(int *)(param_1 + 0xe4) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0xe0) / *(int *)(param_1 + 0xe4);
    }
    FUN_180006150(param_1,lVar1 + 0x38,param_4,param_3,param_3[0xe] + 0x38,param_3[0x1c] + 0x38,
                  uVar3,iVar4,0,0,0,0);
  }
  return;
}



ulonglong FUN_1800096a0(undefined8 *param_1,undefined8 param_2,longlong *param_3)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  void *pvVar11;
  undefined8 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  void *pvVar16;
  undefined8 *puVar17;
  ulonglong uVar18;
  int iVar19;
  void *_Dst;
  undefined1 uVar20;
  int local_res20 [2];
  undefined8 uStack_190;
  undefined1 auStack_188 [8];
  undefined1 auStack_180 [24];
  undefined8 local_168;
  void *local_160;
  uint local_158;
  int local_150;
  int local_148;
  int local_140;
  int local_138;
  int local_130;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  uint local_f0;
  undefined8 *local_e8;
  int local_e0;
  int local_dc;
  longlong local_d8;
  int local_d0;
  longlong local_c8;
  undefined8 *local_c0;
  undefined8 *local_b8;
  uint local_b0;
  void *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  void *local_90;
  undefined8 *local_88;
  void *local_80;
  longlong *local_78;
  void *local_70;
  longlong lStack_68;
  longlong local_60;
  undefined8 *local_58;
  longlong local_50;
  longlong local_48;
  void *local_40;
  longlong local_38;
  longlong local_30;
  
  local_d8 = 0;
  local_c8 = 0;
  local_a0 = 0;
  local_a8 = (void *)0x0;
  puVar12 = param_1 + 0x17;
  local_c0 = puVar12;
  uVar6 = (**(code **)param_3[1])(*puVar12,0,&local_d8);
  if (uVar6 != 0) {
    return (ulonglong)uVar6;
  }
  local_88 = puVar12;
  local_b0 = (**(code **)(param_3[1] + 0x10))(*puVar12,&local_c8);
  if (local_b0 != 0) {
    return (ulonglong)local_b0;
  }
  if (local_d8 == 0) {
    return 0;
  }
  if (*(longlong *)(local_d8 + 0x18) == 0) {
    return 0;
  }
  if (local_c8 == 0) {
    return 0;
  }
  if (*(longlong *)(local_c8 + 0x18) == 0) {
    return 0;
  }
  (**(code **)param_3[1])(*puVar12,0xe,&local_a0);
  (**(code **)param_3[1])(*puVar12,0x1c,&local_a8);
  uVar20 = 0;
  local_f0 = 0;
  local_e8 = (undefined8 *)0x0;
  iVar7 = (**(code **)param_1[0x30])("PF World Suite",2,&local_e8);
  if ((iVar7 == 0) && (local_e8 != (undefined8 *)0x0)) {
    local_res20[0] = 0x62677261;
    (*(code *)local_e8[2])(local_d8,local_res20);
    if (local_res20[0] == 0x32336561) {
      uVar20 = 2;
      local_f0 = 2;
    }
    else {
      uVar20 = local_res20[0] == 0x36316561;
      local_f0 = (uint)(byte)uVar20;
    }
    (**(code **)(param_1[0x30] + 8))();
  }
  local_dc = 0;
  local_e0 = 0;
  local_d0 = 0;
  local_res20[0] = 0;
  piVar1 = *(int **)(*param_3 + 0x30);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0x4f564e41)) {
    local_dc = piVar1[1];
    local_e0 = piVar1[2];
    local_d0 = piVar1[5];
    local_res20[0] = piVar1[6];
  }
  iVar4 = local_d0;
  iVar3 = local_dc;
  iVar19 = local_e0;
  iVar7 = local_res20[0];
  cVar5 = FUN_18000b680();
  if (cVar5 == '\0') {
    local_160 = (void *)CONCAT44(local_160._4_4_,iVar4);
    local_168 = CONCAT44(local_168._4_4_,iVar19);
    local_158 = iVar7;
    uVar9 = FUN_180009080(local_d8,local_c8,uVar20,iVar3);
    return uVar9;
  }
  local_70 = (void *)0x0;
  lStack_68 = 0;
  local_60 = 0;
  local_98 = param_1;
  lVar10 = FUN_1800129b0(0x2337);
  if (lVar10 == 0) goto LAB_180009fff;
  _Dst = (void *)(lVar10 + 0x27U & 0xffffffffffffffe0);
  local_78 = (longlong *)((longlong)_Dst + -8);
  *local_78 = lVar10;
  local_90 = _Dst;
  local_70 = _Dst;
  local_60 = (longlong)_Dst + 0x2310;
  memset(_Dst,0,0x2310);
  lStack_68 = (longlong)_Dst + 0x2310;
  pvVar11 = (void *)FUN_1800129b0(0x198);
  local_80 = pvVar11;
  local_40 = pvVar11;
  local_30 = (longlong)pvVar11 + 0x198;
  memset(pvVar11,0,0x198);
  local_38 = (longlong)pvVar11 + 0x198;
  local_e8 = (undefined8 *)FUN_1800129b0(0x33);
  puVar13 = auStack_188;
  puVar14 = auStack_188;
  local_50 = (longlong)local_e8 + 0x33;
  *local_e8 = 0;
  local_e8[1] = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  *(undefined4 *)((longlong)local_e8 + 0x2f) = 0;
  uVar9 = 0;
  local_128 = 1;
  local_124 = 3;
  local_120 = 4;
  local_11c = 5;
  local_118 = 6;
  local_114 = 7;
  local_110 = 8;
  local_10c = 9;
  local_108 = 10;
  local_104 = 0xb;
  local_100 = 0xc;
  local_fc = 0xd;
  local_f8 = 0xf;
  local_f4 = 0x10;
  iVar19 = 2;
  iVar7 = 0xe;
  local_b8 = local_e8;
  local_58 = local_e8;
  local_48 = local_50;
  do {
    pvVar16 = (void *)(uVar9 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + uVar9 * 8) = pvVar16;
    lVar10 = (longlong)local_128;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    pvVar16 = (void *)((longlong)iVar19 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + (longlong)iVar19 * 8) = pvVar16;
    lVar10 = (longlong)local_124;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_120;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_11c;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_118;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_114;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_110;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_10c;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_108;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_104;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_100;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_fc;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    pvVar16 = (void *)((longlong)iVar7 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + (longlong)iVar7 * 8) = pvVar16;
    lVar10 = (longlong)local_f8;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    lVar10 = (longlong)local_f4;
    pvVar16 = (void *)(lVar10 * 0xb0 + (longlong)_Dst);
    memset(pvVar16,0,0xb0);
    *(void **)((longlong)pvVar11 + lVar10 * 8) = pvVar16;
    uVar6 = (int)uVar9 + 0x11;
    uVar9 = (ulonglong)uVar6;
    local_128 = local_128 + 0x11;
    iVar19 = iVar19 + 0x11;
    local_124 = local_124 + 0x11;
    local_120 = local_120 + 0x11;
    local_11c = local_11c + 0x11;
    local_118 = local_118 + 0x11;
    local_114 = local_114 + 0x11;
    local_110 = local_110 + 0x11;
    local_10c = local_10c + 0x11;
    local_108 = local_108 + 0x11;
    local_104 = local_104 + 0x11;
    local_100 = local_100 + 0x11;
    local_fc = local_fc + 0x11;
    iVar7 = iVar7 + 0x11;
    local_f8 = local_f8 + 0x11;
    local_f4 = local_f4 + 0x11;
  } while ((int)uVar6 < 0x33);
  uVar18 = 1;
  uVar6 = 1;
  uVar9 = (ulonglong)local_b0;
  do {
    if ((int)uVar9 != 0) goto LAB_180009eb0;
    if ((uVar6 != 0xe) && (uVar6 != 0x1c)) {
      local_160 = (void *)((ulonglong)uVar6 * 0xb0 + (longlong)_Dst);
      local_168 = CONCAT44(local_168._4_4_,*(undefined4 *)(param_1 + 0x1e));
      uVar8 = (*(code *)*param_1)(param_1[0x17],uVar6,*(undefined4 *)(param_1 + 0x1c),
                                  *(undefined4 *)((longlong)param_1 + 0xe4));
      uVar9 = (ulonglong)uVar8;
      if (uVar8 == 0) {
        *(undefined1 *)((longlong)local_b8 + (ulonglong)uVar6) = 1;
      }
    }
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 0x33);
  if ((int)uVar9 == 0) {
    if (*(int *)((longlong)param_1 + 0xe4) == 0) {
      local_150 = 0;
    }
    else {
      local_150 = *(int *)(param_1 + 0x1c) / *(int *)((longlong)param_1 + 0xe4);
    }
    local_130 = local_res20[0];
    local_138 = local_d0;
    local_140 = local_e0;
    local_148 = local_dc;
    local_158 = local_f0;
    local_160 = local_a8;
    local_168 = local_a0;
    uVar6 = FUN_180006150(param_1,local_d8,local_c8,pvVar11);
    uVar9 = (ulonglong)uVar6;
  }
LAB_180009eb0:
  puVar12 = local_c0;
  puVar17 = local_b8;
  do {
    if (*(char *)((longlong)puVar17 + uVar18) != '\0') {
      uVar6 = (*(code *)param_1[1])(*puVar12,(void *)(uVar18 * 0xb0 + (longlong)_Dst));
      if ((int)uVar9 == 0) {
        uVar9 = (ulonglong)uVar6;
      }
      puVar17 = local_b8;
    }
    uVar6 = (int)uVar18 + 1;
    uVar18 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0x33);
  puVar15 = auStack_188;
  if (local_e8 != (undefined8 *)0x0) {
    puVar12 = local_e8;
    if ((ulonglong)(local_48 - (longlong)local_e8) < 0x1000) {
LAB_180009f2f:
      puVar14 = puVar13;
    }
    else {
      puVar12 = (undefined8 *)local_e8[-1];
      puVar17 = (undefined8 *)((longlong)local_e8 + (-8 - (longlong)puVar12));
      if ((undefined8 *)0x1f < puVar17) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(5);
        puVar13 = auStack_180;
        puVar12 = puVar17;
        goto LAB_180009f2f;
      }
    }
    *(undefined8 *)(puVar14 + -8) = 0x180009f37;
    free(puVar12);
    puVar15 = puVar14;
  }
  if (pvVar11 != (void *)0x0) {
    pvVar16 = pvVar11;
    if (0xfff < (ulonglong)((*(longlong *)(puVar15 + 0x158) - (longlong)pvVar11 >> 3) * 8)) {
      pvVar16 = *(void **)((longlong)pvVar11 + -8);
      pvVar11 = (void *)((longlong)pvVar11 + (-8 - (longlong)pvVar16));
      if ((void *)0x1f < pvVar11) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(5);
        puVar15 = puVar15 + 8;
        pvVar16 = pvVar11;
      }
    }
    *(undefined8 *)(puVar15 + -8) = 0x180009f83;
    free(pvVar16);
  }
  if ((ulonglong)(((*(longlong *)(puVar15 + 0x128) - (longlong)_Dst) / 0xb0) * 0xb0) < 0x1000) {
    pvVar11 = _Dst;
  }
  else {
    pvVar11 = (void *)**(longlong **)(puVar15 + 0x110);
    if (0x1f < (ulonglong)((longlong)_Dst + (-8 - (longlong)pvVar11))) {
LAB_180009fff:
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      pcVar2 = (code *)swi(3);
      uVar9 = (*pcVar2)();
      return uVar9;
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x180009fe0;
  free(pvVar11);
  return uVar9;
}



void FUN_18000a010(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  code *pcVar1;
  void *_Memory;
  undefined1 *puVar2;
  undefined1 *puVar3;
  void *pvVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [32];
  
  puVar2 = auStack_48;
  puVar3 = auStack_48;
  pvVar4 = (void *)*param_1;
  if (pvVar4 == (void *)0x0) goto LAB_18000a06f;
  _Memory = pvVar4;
  if ((ulonglong)((param_1[2] - (longlong)pvVar4 >> 2) * 4) < 0x1000) {
LAB_18000a067:
    puVar3 = puVar2;
  }
  else {
    _Memory = *(void **)((longlong)pvVar4 + -8);
    pvVar4 = (void *)((longlong)pvVar4 + (-8 - (longlong)_Memory));
    if ((void *)0x1f < pvVar4) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(5);
      puVar2 = auStack_40;
      _Memory = pvVar4;
      goto LAB_18000a067;
    }
  }
  *(undefined8 *)(puVar3 + -8) = 0x18000a06f;
  free(_Memory);
LAB_18000a06f:
  *param_1 = param_2;
  param_1[1] = param_2 + param_3 * 4;
  param_1[2] = param_2 + param_4 * 4;
  return;
}



void FUN_18000a090(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  code *pcVar1;
  void *pvVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  void *pvVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [32];
  
  puVar3 = auStack_48;
  puVar4 = auStack_48;
  pvVar5 = (void *)*param_1;
  if (pvVar5 == (void *)0x0) goto LAB_18000a110;
  for (pvVar2 = pvVar5; pvVar2 != (void *)param_1[1]; pvVar2 = (void *)((longlong)pvVar2 + 0x10)) {
    if (*(int *)((longlong)pvVar2 + 8) != 0) {
                    // WARNING: Subroutine does not return
      terminate();
    }
  }
  pvVar2 = pvVar5;
  if ((param_1[2] - (longlong)pvVar5 & 0xfffffffffffffff0U) < 0x1000) {
LAB_18000a108:
    puVar4 = puVar3;
  }
  else {
    pvVar2 = *(void **)((longlong)pvVar5 + -8);
    pvVar5 = (void *)((longlong)pvVar5 + (-8 - (longlong)pvVar2));
    if ((void *)0x1f < pvVar5) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(5);
      puVar3 = auStack_40;
      pvVar2 = pvVar5;
      goto LAB_18000a108;
    }
  }
  *(undefined8 *)(puVar4 + -8) = 0x18000a110;
  free(pvVar2);
LAB_18000a110:
  *param_1 = param_2;
  param_1[1] = param_3 * 0x10 + param_2;
  param_1[2] = param_4 * 0x10 + param_2;
  return;
}



void FUN_18000a140(void)

{
  undefined1 local_28 [40];
  
  FUN_180004a70(local_28);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_18002c670);
}



void FUN_18000a160(longlong *param_1)

{
  code *pcVar1;
  void *_Memory;
  undefined1 *puVar2;
  undefined1 *puVar3;
  void *pvVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar2 = auStack_28;
  puVar3 = auStack_28;
  pvVar4 = (void *)*param_1;
  if (pvVar4 == (void *)0x0) {
    return;
  }
  _Memory = pvVar4;
  if (0xfff < (ulonglong)(((param_1[2] - (longlong)pvVar4) / 0xb0) * 0xb0)) {
    _Memory = *(void **)((longlong)pvVar4 + -8);
    pvVar4 = (void *)((longlong)pvVar4 + (-8 - (longlong)_Memory));
    if (pvVar4 < (void *)0x20) goto LAB_18000a1c4;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar2 = auStack_20;
    _Memory = pvVar4;
  }
  puVar3 = puVar2;
LAB_18000a1c4:
  *(undefined8 *)(puVar3 + -8) = 0x18000a1c9;
  free(_Memory);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



void FUN_18000a1e0(void)

{
  code *pcVar1;
  
  std::_Xlength_error("vector too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



void FUN_18000a200(ulonglong *param_1,ulonglong param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int *piVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  int *_Dst;
  int *piVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  _Dst = (int *)*param_1;
  uVar5 = (longlong)(param_1[2] - (longlong)_Dst) >> 2;
  if (param_2 <= uVar5) {
    piVar6 = (int *)param_1[1];
    uVar5 = (longlong)piVar6 - (longlong)_Dst >> 2;
    if (param_2 <= uVar5) {
      FUN_180003030(_Dst,_Dst + param_2,param_3);
      param_1[1] = (ulonglong)(_Dst + param_2);
      return;
    }
    if (*param_3 == 0) {
      memset(_Dst,0,uVar5 * 4);
    }
    else {
      uVar8 = ((longlong)piVar6 - (longlong)_Dst) + 3;
      uVar4 = uVar8 >> 2;
      if (piVar6 < _Dst) {
        uVar4 = 0;
      }
      piVar9 = _Dst;
      if ((3 < uVar4) && ((param_3 < _Dst || (_Dst + (uVar4 - 1) < param_3)))) {
        iVar1 = *param_3;
        uVar8 = uVar8 & 0xfffffffffffffff0;
        if (piVar6 < _Dst) {
          uVar8 = 0;
        }
        piVar9 = (int *)((longlong)_Dst + uVar8);
        for (uVar8 = uVar8 / 4; uVar8 != 0; uVar8 = uVar8 - 1) {
          *_Dst = iVar1;
          _Dst = _Dst + 1;
        }
      }
      for (; piVar9 != piVar6; piVar9 = piVar9 + 1) {
        *piVar9 = *param_3;
      }
    }
    uVar5 = FUN_180002e90(param_1[1],param_2 - uVar5,param_3,param_1);
    param_1[1] = uVar5;
    return;
  }
  if (0x3fffffffffffffff < param_2) {
                    // WARNING: Subroutine does not return
    FUN_18000a1e0();
  }
  if (0x3fffffffffffffff - (uVar5 >> 1) < uVar5) {
    uVar5 = 0x3fffffffffffffff;
  }
  else {
    uVar5 = (uVar5 >> 1) + uVar5;
    if (uVar5 < param_2) {
      uVar5 = param_2;
    }
  }
  uVar8 = 0;
  if (_Dst == (int *)0x0) {
LAB_18000a2b7:
    puVar7 = auStack_38;
    if (0x3fffffffffffffff < uVar5) {
LAB_18000a427:
                    // WARNING: Subroutine does not return
      FUN_18000a140();
    }
    uVar5 = uVar5 * 4;
    if (uVar5 == 0) goto LAB_18000a30d;
    if (uVar5 < 0x1000) {
      uVar8 = FUN_1800129b0(uVar5);
      puVar7 = auStack_38;
      goto LAB_18000a30d;
    }
    if (uVar5 + 0x27 <= uVar5) goto LAB_18000a427;
    lVar3 = FUN_1800129b0();
    puVar7 = auStack_38;
    if (lVar3 == 0) goto LAB_18000a2ed;
  }
  else {
    if ((ulonglong)(((longlong)(param_1[2] - (longlong)_Dst) >> 2) * 4) < 0x1000) {
      piVar6 = _Dst;
LAB_18000a2a7:
      free(piVar6);
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      goto LAB_18000a2b7;
    }
    piVar6 = *(int **)(_Dst + -2);
    if ((ulonglong)((longlong)_Dst + (-8 - (longlong)piVar6)) < 0x20) goto LAB_18000a2a7;
LAB_18000a2ed:
    pcVar2 = (code *)swi(0x29);
    lVar3 = (*pcVar2)(5);
    puVar7 = auStack_30;
  }
  uVar8 = lVar3 + 0x27U & 0xffffffffffffffe0;
  *(longlong *)(uVar8 - 8) = lVar3;
LAB_18000a30d:
  *param_1 = uVar8;
  param_1[1] = uVar8;
  param_1[2] = uVar5 + uVar8;
  *(undefined8 *)(puVar7 + -8) = 0x18000a32d;
  uVar5 = FUN_180002e90(uVar8,param_2,param_3,param_1);
  param_1[1] = uVar5;
  return;
}



void FUN_18000a440(longlong *param_1,ulonglong param_2,undefined8 *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  
  puVar5 = (undefined8 *)*param_1;
  uVar7 = param_1[2] - (longlong)puVar5 >> 6;
  if (param_2 <= uVar7) {
    puVar3 = (undefined8 *)param_1[1];
    uVar7 = (longlong)puVar3 - (longlong)puVar5 >> 6;
    if (uVar7 < param_2) {
      for (; puVar5 != puVar3; puVar5 = puVar5 + 8) {
        uVar2 = param_3[1];
        *puVar5 = *param_3;
        puVar5[1] = uVar2;
        uVar2 = param_3[3];
        puVar5[2] = param_3[2];
        puVar5[3] = uVar2;
        uVar2 = param_3[5];
        puVar5[4] = param_3[4];
        puVar5[5] = uVar2;
        uVar2 = param_3[7];
        puVar5[6] = param_3[6];
        puVar5[7] = uVar2;
      }
      puVar3 = (undefined8 *)param_1[1];
      for (lVar6 = param_2 - uVar7; lVar6 != 0; lVar6 = lVar6 + -1) {
        uVar2 = param_3[1];
        *puVar3 = *param_3;
        puVar3[1] = uVar2;
        uVar2 = param_3[3];
        puVar3[2] = param_3[2];
        puVar3[3] = uVar2;
        uVar2 = param_3[5];
        puVar3[4] = param_3[4];
        puVar3[5] = uVar2;
        uVar2 = param_3[7];
        puVar3[6] = param_3[6];
        puVar3[7] = uVar2;
        puVar3 = puVar3 + 8;
      }
    }
    else {
      puVar3 = puVar5 + param_2 * 8;
      if ((param_2 & 0x3ffffffffffffff) != 0) {
        do {
          uVar2 = param_3[1];
          *puVar5 = *param_3;
          puVar5[1] = uVar2;
          uVar2 = param_3[3];
          puVar5[2] = param_3[2];
          puVar5[3] = uVar2;
          uVar2 = param_3[5];
          puVar5[4] = param_3[4];
          puVar5[5] = uVar2;
          uVar2 = param_3[7];
          puVar5[6] = param_3[6];
          puVar5[7] = uVar2;
          puVar5 = puVar5 + 8;
        } while (puVar5 != puVar3);
        param_1[1] = (longlong)puVar3;
        return;
      }
    }
    param_1[1] = (longlong)puVar3;
    return;
  }
  if (0x3ffffffffffffff < param_2) {
                    // WARNING: Subroutine does not return
    FUN_18000a1e0();
  }
  if (0x3ffffffffffffff - (uVar7 >> 1) < uVar7) {
    uVar7 = 0x3ffffffffffffff;
  }
  else {
    uVar7 = (uVar7 >> 1) + uVar7;
    if (uVar7 < param_2) {
      uVar7 = param_2;
    }
  }
  if (puVar5 == (undefined8 *)0x0) {
LAB_18000a502:
    if (0x3ffffffffffffff < uVar7) {
LAB_18000a68c:
                    // WARNING: Subroutine does not return
      FUN_18000a140();
    }
    uVar7 = uVar7 * 0x40;
    if (uVar7 == 0) {
      puVar5 = (undefined8 *)0x0;
      goto LAB_18000a558;
    }
    if (uVar7 < 0x1000) {
      puVar5 = (undefined8 *)FUN_1800129b0();
      goto LAB_18000a558;
    }
    if ((uVar7 | 0x27) <= uVar7) goto LAB_18000a68c;
    lVar4 = FUN_1800129b0();
    lVar6 = lVar4;
    if (lVar4 == 0) goto LAB_18000a53e;
  }
  else {
    if ((param_1[2] - (longlong)puVar5 & 0xffffffffffffffc0U) < 0x1000) {
      puVar3 = puVar5;
LAB_18000a4e0:
      free(puVar3);
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      goto LAB_18000a502;
    }
    puVar3 = (undefined8 *)puVar5[-1];
    if ((ulonglong)((longlong)puVar5 + (-8 - (longlong)puVar3)) < 0x20) goto LAB_18000a4e0;
LAB_18000a53e:
    lVar6 = 5;
    pcVar1 = (code *)swi(0x29);
    lVar4 = (*pcVar1)();
  }
  puVar5 = (undefined8 *)(lVar4 + 0x27U & 0xffffffffffffffe0);
  puVar5[-1] = lVar6;
LAB_18000a558:
  *param_1 = (longlong)puVar5;
  param_1[1] = (longlong)puVar5;
  param_1[2] = uVar7 + (longlong)puVar5;
  for (; param_2 != 0; param_2 = param_2 - 1) {
    uVar2 = param_3[1];
    *puVar5 = *param_3;
    puVar5[1] = uVar2;
    uVar2 = param_3[3];
    puVar5[2] = param_3[2];
    puVar5[3] = uVar2;
    uVar2 = param_3[5];
    puVar5[4] = param_3[4];
    puVar5[5] = uVar2;
    uVar2 = param_3[7];
    puVar5[6] = param_3[6];
    puVar5[7] = uVar2;
    puVar5 = puVar5 + 8;
  }
  param_1[1] = (longlong)puVar5;
  return;
}



void FUN_18000a6a0(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*(int *)(param_1 + 1) == 0) {
                    // WARNING: Subroutine does not return
    std::_Throw_Cpp_error(1);
  }
  iVar2 = *(int *)(param_1 + 1);
  iVar1 = _Thrd_id();
  if (iVar2 == iVar1) {
                    // WARNING: Subroutine does not return
    std::_Throw_Cpp_error(5);
  }
  local_18 = *(undefined4 *)param_1;
  uStack_14 = *(undefined4 *)((longlong)param_1 + 4);
  uStack_10 = *(undefined4 *)(param_1 + 1);
  uStack_c = *(undefined4 *)((longlong)param_1 + 0xc);
  iVar2 = _Thrd_join(&local_18,0);
  if (iVar2 != 0) {
                    // WARNING: Subroutine does not return
    std::_Throw_Cpp_error(2);
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



void FUN_18000a710(int param_1,longlong *param_2)

{
  ulonglong uVar1;
  byte bVar2;
  undefined4 *puVar3;
  code *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 *_Dst;
  undefined8 *puVar7;
  ulonglong uVar8;
  void *pvVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined4 *_Dst_00;
  char *pcVar14;
  void *pvVar15;
  size_t sVar16;
  undefined4 *_Src;
  ulonglong uVar17;
  float fVar18;
  undefined4 local_res10;
  undefined4 uStackX_14;
  undefined8 uStack_a0;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [24];
  void *local_78;
  undefined8 *puStack_70;
  undefined8 *local_68;
  
  puVar10 = auStack_98;
  puVar11 = auStack_98;
  if (*param_2 != param_2[1]) {
    param_2[1] = *param_2;
  }
  pcVar14 = "0123456789ABCDEF<>[]{}/\\|=+*-.";
  if (param_1 != 2) {
    pcVar14 = &DAT_180029bd0;
  }
  local_78 = (void *)0x0;
  puStack_70 = (undefined8 *)0x0;
  local_68 = (undefined8 *)0x0;
  _Dst_00 = &DAT_180020780;
  do {
    bVar2 = *pcVar14;
    if (bVar2 < 0x20) {
      uVar13 = 0;
    }
    else {
      uVar13 = (ulonglong)(bVar2 - 0x20);
      if (0x7e < bVar2) {
        uVar13 = 0x5e;
      }
    }
    local_res10 = (&DAT_180020780)[uVar13];
    uStackX_14 = (undefined4)uVar13;
    if (puStack_70 == local_68) {
      FUN_1800021b0(&local_78,puStack_70,&local_res10);
    }
    else {
      *puStack_70 = CONCAT44(uStackX_14,local_res10);
      puStack_70 = puStack_70 + 1;
    }
    pcVar14 = pcVar14 + 1;
  } while (*pcVar14 != 0);
  FUN_180002a50(local_78,puStack_70,(longlong)puStack_70 - (longlong)local_78 >> 3,0);
  fVar18 = -1.0;
  uVar13 = 0;
  puVar7 = puStack_70;
  pvVar15 = local_78;
  if ((longlong)puStack_70 - (longlong)local_78 >> 3 != 0) {
    do {
      if (0.008 < *(float *)((longlong)pvVar15 + uVar13 * 8) - fVar18) {
LAB_18000a84b:
        _Src = (undefined4 *)param_2[1];
        if (_Src == (undefined4 *)param_2[2]) {
          uVar8 = (longlong)_Src - *param_2;
          lVar5 = (longlong)uVar8 >> 2;
          if (lVar5 == 0x3fffffffffffffff) goto LAB_18000ab16;
          uVar6 = param_2[2] - *param_2 >> 2;
          if (0x3fffffffffffffff - (uVar6 >> 1) < uVar6) goto LAB_18000ab10;
          uVar1 = lVar5 + 1;
          uVar6 = (uVar6 >> 1) + uVar6;
          uVar17 = uVar1;
          if (uVar1 <= uVar6) {
            uVar17 = uVar6;
          }
          if (0x3fffffffffffffff < uVar17) goto LAB_18000ab10;
          uVar6 = uVar17 * 4;
          if (uVar6 == 0) {
            _Dst_00 = (undefined4 *)0x0;
          }
          else if (uVar6 < 0x1000) {
            _Dst_00 = (undefined4 *)FUN_1800129b0();
          }
          else {
            if (uVar6 + 0x27 <= uVar6) goto LAB_18000ab10;
            lVar5 = FUN_1800129b0(uVar6 + 0x27);
            if (lVar5 == 0) goto LAB_18000aa77;
            _Dst_00 = (undefined4 *)(lVar5 + 0x27U & 0xffffffffffffffe0);
            *(longlong *)(_Dst_00 + -2) = lVar5;
          }
          uVar8 = uVar8 & 0xfffffffffffffffc;
          *(undefined4 *)((longlong)_Dst_00 + uVar8) =
               *(undefined4 *)((longlong)pvVar15 + uVar13 * 8 + 4);
          puVar3 = (undefined4 *)*param_2;
          if (_Src == (undefined4 *)param_2[1]) {
            sVar16 = param_2[1] - (longlong)puVar3;
            _Dst = _Dst_00;
            _Src = puVar3;
          }
          else {
            memcpy(_Dst_00,puVar3,(longlong)_Src - (longlong)puVar3);
            _Dst = (undefined4 *)(uVar8 + 4 + (longlong)_Dst_00);
            sVar16 = param_2[1] - (longlong)_Src;
          }
          memcpy(_Dst,_Src,sVar16);
          FUN_18000a010(param_2,_Dst_00,uVar1,uVar17);
        }
        else {
          *_Src = *(undefined4 *)((longlong)pvVar15 + uVar13 * 8 + 4);
          param_2[1] = param_2[1] + 4;
        }
        fVar18 = *(float *)((longlong)local_78 + uVar13 * 8);
        puVar7 = puStack_70;
        pvVar15 = local_78;
      }
      else if (*param_2 == param_2[1]) goto LAB_18000a84b;
      uVar13 = uVar13 + 1;
    } while (uVar13 < (ulonglong)((longlong)puVar7 - (longlong)pvVar15 >> 3));
  }
  puVar3 = (undefined4 *)*param_2;
  _Dst_00 = (undefined4 *)param_2[1];
  puVar12 = auStack_98;
  if (puVar3 == _Dst_00) {
    if (_Dst_00 == (undefined4 *)param_2[2]) {
      _Src = (undefined4 *)((longlong)_Dst_00 - (longlong)puVar3);
      if ((longlong)_Src >> 2 == 0x3fffffffffffffff) {
LAB_18000ab16:
                    // WARNING: Subroutine does not return
        FUN_18000a1e0();
      }
      uVar8 = param_2[2] - (longlong)puVar3 >> 2;
      if (0x3fffffffffffffff - (uVar8 >> 1) < uVar8) {
LAB_18000ab10:
                    // WARNING: Subroutine does not return
        FUN_18000a140();
      }
      uVar17 = ((longlong)_Src >> 2) + 1;
      uVar8 = (uVar8 >> 1) + uVar8;
      uVar13 = uVar17;
      if (uVar17 <= uVar8) {
        uVar13 = uVar8;
      }
      if (0x3fffffffffffffff < uVar13) goto LAB_18000ab10;
      uVar8 = uVar13 * 4;
      if (uVar8 == 0) {
        pvVar15 = (void *)0x0;
        puVar11 = auStack_98;
      }
      else if (uVar8 < 0x1000) {
        pvVar15 = (void *)FUN_1800129b0();
      }
      else {
        if (uVar8 + 0x27 <= uVar8) goto LAB_18000ab10;
        lVar5 = FUN_1800129b0(uVar8 + 0x27);
        if (lVar5 == 0) {
LAB_18000aa77:
          pcVar4 = (code *)swi(0x29);
          lVar5 = (*pcVar4)(5);
          puVar10 = auStack_90;
        }
        pvVar15 = (void *)(lVar5 + 0x27U & 0xffffffffffffffe0);
        *(longlong *)((longlong)pvVar15 - 8) = lVar5;
        puVar11 = puVar10;
      }
      *(undefined4 *)(((ulonglong)_Src & 0xfffffffffffffffc) + (longlong)pvVar15) = 0;
      puVar3 = (undefined4 *)*param_2;
      if (_Dst_00 == (undefined4 *)param_2[1]) {
        sVar16 = param_2[1] - (longlong)puVar3;
        pvVar9 = pvVar15;
        _Dst_00 = puVar3;
      }
      else {
        *(undefined8 *)(puVar11 + -8) = 0x18000aabf;
        memcpy(pvVar15,puVar3,(longlong)_Dst_00 - (longlong)puVar3);
        pvVar9 = (void *)(((ulonglong)_Src & 0xfffffffffffffffc) + 4 + (longlong)pvVar15);
        sVar16 = param_2[1] - (longlong)_Dst_00;
      }
      *(undefined8 *)(puVar11 + -8) = 0x18000aad5;
      memcpy(pvVar9,_Dst_00,sVar16);
      *(undefined8 *)(puVar11 + -8) = 0x18000aae6;
      FUN_18000a010(param_2,pvVar15,uVar17,uVar13);
    }
    else {
      *_Dst_00 = 0;
      param_2[1] = param_2[1] + 4;
      puVar11 = auStack_98;
    }
    pvVar15 = *(void **)(puVar11 + 0x20);
    puVar12 = puVar11;
  }
  if (pvVar15 == (void *)0x0) {
    return;
  }
  pvVar9 = pvVar15;
  if (0xfff < (ulonglong)((*(longlong *)(puVar12 + 0x30) - (longlong)pvVar15 >> 3) * 8)) {
    pvVar9 = *(void **)((longlong)pvVar15 + -8);
    pvVar15 = (void *)((longlong)pvVar15 + (-8 - (longlong)pvVar9));
    if ((void *)0x1f < pvVar15) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(5);
      puVar12 = puVar12 + 8;
      pvVar9 = pvVar15;
    }
  }
  *(undefined8 *)(puVar12 + -8) = 0x18000aafa;
  free(pvVar9);
  return;
}



void FUN_18000ab30(longlong param_1,float param_2,float param_3,int *param_4,float *param_5,
                  float *param_6)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  ulonglong uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  if ((param_4[0x10] != 1) && (0.0 < (float)param_4[0x12])) {
    fVar11 = (*(float *)(param_1 + 0x20) - 0.35) * (float)param_4[0x12] * 1.6 + 1.0;
    fVar14 = 0.35;
    if ((0.35 <= fVar11) && (fVar14 = 2.4, fVar11 <= 2.4)) {
      fVar14 = fVar11;
    }
    param_2 = (param_2 - 0.5) / fVar14 + 0.5;
    param_3 = (param_3 - 0.5) / fVar14 + 0.5;
    if ((((param_2 < 0.0) || (1.0 < param_2)) || (param_3 < 0.0)) || (1.0 < param_3)) {
      param_2 = -1.0;
    }
  }
  if ((param_4[2] == 1) ||
     (*(float *)(param_1 + 0x14) < (float)param_4[6] ||
      *(float *)(param_1 + 0x14) == (float)param_4[6])) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (param_2 < 0.0) {
    fVar14 = 0.0;
  }
  else if (bVar3) {
    fVar11 = ((float)param_4[7] -
             ABS((param_2 - 0.5) * *(float *)(param_1 + 0x18) +
                 (param_3 - 0.5) * *(float *)(param_1 + 0x1c))) / 0.1 + 0.5;
    if (0.0 <= fVar11) {
      fVar14 = 1.0;
      if (fVar11 <= 1.0) {
        fVar14 = fVar11;
      }
    }
    else {
      fVar14 = 0.0;
    }
  }
  else if (param_4[2] == 2) {
    fVar14 = 0.0;
  }
  else {
    iVar5 = *param_4;
    if (iVar5 == 6) {
      lVar2 = *(longlong *)(param_4 + 0xc);
      if (((lVar2 == 0) || (iVar5 = param_4[0xe], iVar5 < 1)) || (iVar7 = param_4[0xf], iVar7 < 1))
      {
        fVar14 = 0.0;
      }
      else {
        if (0.0 <= param_2) {
          fVar11 = 1.0;
          if (param_2 <= 1.0) {
            fVar11 = param_2;
          }
        }
        else {
          fVar11 = 0.0;
        }
        fVar11 = (float)(iVar5 + -1) * fVar11;
        if (0.0 <= param_3) {
          fVar16 = 1.0;
          if (param_3 <= 1.0) {
            fVar16 = param_3;
          }
        }
        else {
          fVar16 = 0.0;
        }
        iVar6 = (int)fVar11;
        fVar16 = (float)(iVar7 + -1) * fVar16;
        iVar10 = iVar6 + 1;
        if (iVar5 <= iVar6 + 1) {
          iVar10 = iVar6;
        }
        iVar9 = (int)fVar16;
        fVar11 = fVar11 - (float)iVar6;
        iVar8 = iVar9 + 1;
        if (iVar7 <= iVar9 + 1) {
          iVar8 = iVar9;
        }
        fVar14 = *(float *)(lVar2 + (longlong)(iVar9 * iVar5 + iVar6) * 4);
        fVar17 = *(float *)(lVar2 + (longlong)(iVar8 * iVar5 + iVar6) * 4);
        fVar14 = (*(float *)(lVar2 + (longlong)(iVar9 * iVar5 + iVar10) * 4) - fVar14) * fVar11 +
                 fVar14;
        fVar14 = (((*(float *)(lVar2 + (longlong)(iVar8 * iVar5 + iVar10) * 4) - fVar17) * fVar11 +
                  fVar17) - fVar14) * (fVar16 - (float)iVar9) + fVar14;
      }
      fVar14 = fVar14 * *(float *)(param_1 + 0x34);
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x30);
      if ((int)uVar1 < 0) {
        fVar14 = *(float *)(param_1 + 0x34);
        if (0.0 <= fVar14) {
          fVar11 = 1.0;
          if (fVar14 <= 1.0) {
            fVar11 = fVar14;
          }
        }
        else {
          fVar11 = 0.0;
        }
        if (iVar5 == 3) {
          iVar5 = (int)(param_2 * 4.0);
          iVar7 = (int)(param_3 * 4.0);
          if (3 < iVar5) {
            iVar5 = 3;
          }
          if (3 < iVar7) {
            iVar7 = 3;
          }
          if (((float)*(int *)(&DAT_180029b70 + ((longlong)iVar5 + (longlong)iVar7 * 4) * 4) + 0.5)
              * 0.0625 < fVar11) {
            fVar14 = 1.0;
            goto LAB_18000b019;
          }
        }
        else {
          param_2 = param_2 - 0.5;
          param_3 = param_3 - 0.5;
          if (fVar11 < 0.0) {
            fVar11 = sqrtf(fVar11);
          }
          else {
            fVar11 = SQRT(fVar11);
          }
          if (iVar5 == 4) {
            fVar14 = ABS(param_2);
            if (ABS(param_2) <= ABS(param_3)) {
              fVar14 = ABS(param_3);
            }
            fVar14 = fVar11 * 0.5 - fVar14;
          }
          else {
            fVar14 = param_3 * param_3 + param_2 * param_2;
            if (fVar14 < 0.0) {
              fVar14 = sqrtf(fVar14);
            }
            else {
              fVar14 = SQRT(fVar14);
            }
            fVar14 = fVar11 * 0.6 - fVar14;
          }
          fVar11 = fVar14 / 0.06 + 0.5;
          if (0.0 <= fVar11) {
            fVar14 = 1.0;
            if (fVar11 <= 1.0) {
              fVar14 = fVar11;
            }
            goto LAB_18000b019;
          }
        }
        fVar14 = 0.0;
      }
      else {
        uVar4 = (ulonglong)uVar1;
        if (0x5e < (int)uVar1) {
          uVar4 = 0x5e;
        }
        if (0.0 <= param_2) {
          fVar14 = 1.0;
          if (param_2 <= 1.0) {
            fVar14 = param_2;
          }
        }
        else {
          fVar14 = 0.0;
        }
        if (0.0 <= param_3) {
          fVar11 = 1.0;
          if (param_3 <= 1.0) {
            fVar11 = param_3;
          }
        }
        else {
          fVar11 = 0.0;
        }
        iVar7 = (int)(fVar14 * 15.0);
        iVar10 = (int)(fVar11 * 31.0);
        iVar5 = iVar7 + 1;
        if (0xf < iVar7 + 1) {
          iVar5 = iVar7;
        }
        fVar14 = fVar14 * 15.0 - (float)iVar7;
        iVar6 = iVar10 + 1;
        if (0x1f < iVar10 + 1) {
          iVar6 = iVar10;
        }
        fVar17 = (float)(byte)(&DAT_180014980)[(longlong)(iVar7 + iVar10 * 0x10) + uVar4 * 0x200];
        fVar16 = (float)(byte)(&DAT_180014980)[(longlong)(iVar7 + iVar6 * 0x10) + uVar4 * 0x200];
        fVar17 = ((float)(byte)(&DAT_180014980)[(longlong)(iVar5 + iVar10 * 0x10) + uVar4 * 0x200] -
                 fVar17) * fVar14 + fVar17;
        fVar14 = (((((float)(byte)(&DAT_180014980)[(longlong)(iVar5 + iVar6 * 0x10) + uVar4 * 0x200]
                    - fVar16) * fVar14 + fVar16) - fVar17) * (fVar11 * 31.0 - (float)iVar10) +
                 fVar17) / 255.0;
      }
    }
  }
LAB_18000b019:
  fVar11 = 0.0;
  fVar14 = fVar14 * *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x10);
  if ((param_4[0x10] != 1) && (0.0 < (float)param_4[0x13])) {
    fVar11 = *(float *)(param_1 + 0x20);
    if (0.0 <= fVar11) {
      fVar16 = 1.0;
      if (fVar11 <= 1.0) {
        fVar16 = fVar11;
      }
    }
    else {
      fVar16 = 0.0;
    }
    fVar11 = (1.0 - fVar16) * (float)param_4[0x13];
    fVar14 = (1.0 - fVar11 * 0.85) * fVar14;
  }
  if (param_4[0x1e] == 0) {
    fVar17 = (float)param_4[0x17];
    fVar18 = (float)param_4[0x18];
    fVar15 = (float)param_4[0x19];
    fVar16 = *(float *)(param_1 + 0x10) * (float)param_4[0x1d];
  }
  else {
    fVar16 = param_5[3];
    if (fVar16 <= 1e-06) {
      fVar15 = 0.0;
      fVar18 = 0.0;
      fVar17 = 0.0;
    }
    else {
      fVar15 = 1.0 / fVar16;
      fVar17 = fVar15 * *param_5;
      fVar18 = fVar15 * param_5[1];
      fVar15 = fVar15 * param_5[2];
    }
  }
  fVar12 = *(float *)(param_1 + 0x24);
  fVar13 = *(float *)(param_1 + 0x28);
  if (fVar11 <= 0.0) {
    fVar11 = *(float *)(param_1 + 0x2c);
  }
  else {
    fVar11 = fVar11 * 0.6;
    fVar13 = ((float)param_4[0x18] - fVar13) * fVar11 + fVar13;
    fVar12 = ((float)param_4[0x17] - fVar12) * fVar11 + fVar12;
    fVar11 = ((float)param_4[0x19] - *(float *)(param_1 + 0x2c)) * fVar11 +
             *(float *)(param_1 + 0x2c);
  }
  param_6[3] = (1.0 - fVar16) * fVar14 + fVar16;
  *param_6 = (fVar12 - fVar17) * fVar14 + fVar17;
  param_6[1] = (fVar13 - fVar18) * fVar14 + fVar18;
  param_6[2] = (fVar11 - fVar15) * fVar14 + fVar15;
  return;
}



void FUN_18000b1c0(float *param_1,longlong param_2,longlong *param_3)

{
  float fVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  if (*(int *)(param_2 + 4) - 2U < 2) {
    fVar8 = *param_1;
  }
  else {
    fVar8 = 1.0 - *param_1;
  }
  fVar1 = *param_1;
  if (*(int *)(param_2 + 0xc) != 0) {
    fVar8 = 1.0 - fVar8;
  }
  if (0.0 <= fVar8) {
    fVar7 = 1.0;
    if (fVar8 <= 1.0) {
      fVar7 = fVar8;
    }
  }
  else {
    fVar7 = 0.0;
  }
  param_1[0xd] = fVar7;
  lVar3 = *param_3;
  if (lVar3 == param_3[1]) {
    fVar8 = -NAN;
  }
  else {
    iVar2 = (int)(param_3[1] - lVar3 >> 2);
    iVar6 = iVar2 + -1;
    iVar4 = (int)((float)iVar6 * fVar7 + 0.5);
    iVar5 = 0;
    if (-1 < iVar4) {
      iVar5 = iVar4;
    }
    if (iVar5 < iVar2) {
      iVar6 = iVar5;
    }
    fVar8 = *(float *)(lVar3 + (longlong)iVar6 * 4);
  }
  param_1[0xc] = fVar8;
  fVar8 = *(float *)(param_2 + 0x20);
  fVar7 = *(float *)(param_2 + 0x24) * 0.5;
  fVar9 = fVar8 - fVar7;
  fVar7 = fVar7 + fVar8;
  if (fVar9 < fVar7) {
    fVar8 = (fVar1 - fVar9) / (fVar7 - fVar9);
    if (0.0 <= fVar8) {
      fVar7 = 1.0;
      if (fVar8 <= 1.0) {
        fVar7 = fVar8;
      }
      goto LAB_18000b2b1;
    }
  }
  else if (fVar8 <= fVar1) {
    fVar7 = 1.0;
    goto LAB_18000b2b1;
  }
  fVar7 = 0.0;
LAB_18000b2b1:
  fVar8 = (3.0 - (fVar7 + fVar7)) * fVar7 * fVar7;
  if (*(int *)(param_2 + 0x28) != 0) {
    fVar8 = 1.0 - fVar8;
  }
  param_1[0xf] = fVar8;
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 != 1) {
    if (iVar2 == 2) {
      param_1[9] = param_1[1];
      param_1[10] = param_1[2];
      param_1[0xb] = param_1[3];
      return;
    }
    if ((iVar2 != 3) && (iVar2 == 4)) {
      fVar8 = 0.0;
      if ((0.0 <= fVar1) && (fVar8 = 1.0, fVar1 <= 1.0)) {
        fVar8 = fVar1;
      }
      param_1[9] = (*(float *)(param_2 + 0x68) - *(float *)(param_2 + 0x50)) * fVar8 +
                   *(float *)(param_2 + 0x50);
      param_1[10] = (*(float *)(param_2 + 0x6c) - *(float *)(param_2 + 0x54)) * fVar8 +
                    *(float *)(param_2 + 0x54);
      param_1[0xb] = (*(float *)(param_2 + 0x70) - *(float *)(param_2 + 0x58)) * fVar8 +
                     *(float *)(param_2 + 0x58);
      return;
    }
  }
  param_1[9] = *(float *)(param_2 + 0x50);
  param_1[10] = *(float *)(param_2 + 0x54);
  param_1[0xb] = *(float *)(param_2 + 0x58);
  return;
}



int FUN_18000b3b0(longlong param_1,int param_2,longlong param_3,int param_4)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  
  uVar4 = 0;
  iVar8 = 0;
  iVar5 = 0;
  uVar7 = 0;
  if (0 < param_2) {
    do {
      cVar1 = *(char *)(param_1 + uVar7);
      iVar3 = (int)cVar1;
      if ((byte)(cVar1 + 0xbfU) < 0x1a) {
        uVar6 = iVar3 - 0x41;
LAB_18000b40f:
        uVar4 = uVar4 << 6 | uVar6;
        if (iVar8 + 6 < 8) {
          iVar8 = iVar8 + 6;
        }
        else {
          if (param_4 <= iVar5) {
            return -1;
          }
          lVar2 = (longlong)iVar5;
          iVar5 = iVar5 + 1;
          *(char *)(param_3 + lVar2) = (char)((int)uVar4 >> ((byte)(iVar8 + -2) & 0x1f));
          iVar8 = iVar8 + -2;
        }
      }
      else {
        if ((byte)(cVar1 + 0x9fU) < 0x1a) {
          uVar6 = iVar3 - 0x47;
          goto LAB_18000b40f;
        }
        if ((byte)(cVar1 - 0x30U) < 10) {
          uVar6 = iVar3 + 4;
          goto LAB_18000b40f;
        }
        if (cVar1 == '-') {
          uVar6 = 0x3e;
          goto LAB_18000b40f;
        }
        if (cVar1 == '_') {
          uVar6 = 0x3f;
          goto LAB_18000b40f;
        }
        if (cVar1 != '=') {
          return -1;
        }
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((int)uVar6 < param_2);
  }
  return iVar5;
}



// WARNING: Function: __chkstk replaced with injection: alloca_probe
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

ulonglong FUN_18000b460(undefined8 param_1,void *param_2,int param_3)

{
  code *pcVar1;
  u_short uVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  SOCKET s;
  char *pcVar6;
  char *pcVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_2308 [32];
  sockaddr local_22e8;
  WSADATA local_22d8;
  char local_2138 [256];
  char local_2038 [8192];
  ulonglong local_38;
  
  local_38 = DAT_180030500 ^ (ulonglong)auStack_2308;
  iVar3 = WSAStartup(0x202,&local_22d8);
  if (iVar3 == 0) {
    s = socket(2,1,6);
    if (s == 0xffffffffffffffff) {
      WSACleanup();
      uVar8 = 0;
    }
    else {
      local_22e8.sa_data[6] = '\0';
      local_22e8.sa_data[7] = '\0';
      local_22e8.sa_data[8] = '\0';
      local_22e8.sa_data[9] = '\0';
      local_22e8.sa_data[10] = '\0';
      local_22e8.sa_data[0xb] = '\0';
      local_22e8.sa_data[0xc] = '\0';
      local_22e8.sa_data[0xd] = '\0';
      local_22e8.sa_family = 2;
      local_22e8.sa_data[0] = '\0';
      local_22e8.sa_data[1] = '\0';
      local_22e8.sa_data[2] = '\0';
      local_22e8.sa_data[3] = '\0';
      local_22e8.sa_data[4] = '\0';
      local_22e8.sa_data[5] = '\0';
      uVar10 = 0;
      uVar2 = htons(0xbc59);
      local_22e8.sa_data[0] = (char)uVar2;
      local_22e8.sa_data[1] = (char)(uVar2 >> 8);
      uVar4 = inet_addr("127.0.0.1");
      local_22e8.sa_data[2] = (char)uVar4;
      local_22e8.sa_data[3] = (char)(uVar4 >> 8);
      local_22e8.sa_data[4] = (char)(uVar4 >> 0x10);
      local_22e8.sa_data[5] = (char)(uVar4 >> 0x18);
      iVar3 = connect(s,&local_22e8,0x10);
      if (iVar3 == 0) {
        iVar3 = snprintf(local_2138,0x100,
                         "GET /verify?pack=%s HTTP/1.0\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n"
                         ,param_1);
        send(s,local_2138,iVar3,0);
        uVar9 = 0;
        iVar3 = recv(s,local_2038,0x1fff,0);
        while ((0 < iVar3 && (uVar9 = uVar9 + iVar3, (int)uVar9 < 0x1fff))) {
          iVar3 = recv(s,local_2038 + (int)uVar9,0x1fff - uVar9,0);
        }
        uVar5 = 0;
        if (0 < (int)uVar9) {
          uVar5 = uVar9;
        }
        if (0x1fff < uVar5) {
          FUN_180012a20();
          pcVar1 = (code *)swi(3);
          uVar8 = (*pcVar1)();
          return uVar8;
        }
        local_2038[(int)uVar5] = '\0';
        pcVar6 = strstr(local_2038,"\"token\":\"");
        if (pcVar6 != (char *)0x0) {
          pcVar6 = pcVar6 + 9;
          pcVar7 = strchr(pcVar6,0x22);
          if ((pcVar7 != (char *)0x0) && (uVar9 = (int)pcVar7 - (int)pcVar6, (int)uVar9 < param_3))
          {
            memcpy(param_2,pcVar6,(longlong)(int)uVar9);
            *(undefined1 *)((longlong)(int)uVar9 + (longlong)param_2) = 0;
            uVar10 = uVar9;
          }
        }
      }
      closesocket(s);
      WSACleanup();
      uVar8 = (ulonglong)uVar10;
    }
  }
  else {
    uVar8 = 0;
  }
  return uVar8;
}



undefined8 FUN_18000b680(void)

{
  return 1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_18000b730(uint *param_1,undefined1 *param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint auStack_198 [12];
  uint local_168 [4];
  uint local_158 [64];
  ulonglong local_58;
  
  local_58 = DAT_180030500 ^ (ulonglong)(auStack_198 + 0xc);
  local_158[0] = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]);
  local_158[1] = CONCAT31(CONCAT21(CONCAT11(param_2[4],param_2[5]),param_2[6]),param_2[7]);
  local_158[2] = CONCAT31(CONCAT21(CONCAT11(param_2[8],param_2[9]),param_2[10]),param_2[0xb]);
  local_158[3] = CONCAT31(CONCAT21(CONCAT11(param_2[0xc],param_2[0xd]),param_2[0xe]),param_2[0xf]);
  local_158[4] = CONCAT31(CONCAT21(CONCAT11(param_2[0x10],param_2[0x11]),param_2[0x12]),
                          param_2[0x13]);
  local_158[5] = CONCAT31(CONCAT21(CONCAT11(param_2[0x14],param_2[0x15]),param_2[0x16]),
                          param_2[0x17]);
  local_158[6] = CONCAT31(CONCAT21(CONCAT11(param_2[0x18],param_2[0x19]),param_2[0x1a]),
                          param_2[0x1b]);
  local_158[7] = CONCAT31(CONCAT21(CONCAT11(param_2[0x1c],param_2[0x1d]),param_2[0x1e]),
                          param_2[0x1f]);
  local_158[8] = CONCAT31(CONCAT21(CONCAT11(param_2[0x20],param_2[0x21]),param_2[0x22]),
                          param_2[0x23]);
  local_158[9] = CONCAT31(CONCAT21(CONCAT11(param_2[0x24],param_2[0x25]),param_2[0x26]),
                          param_2[0x27]);
  local_158[10] =
       CONCAT31(CONCAT21(CONCAT11(param_2[0x28],param_2[0x29]),param_2[0x2a]),param_2[0x2b]);
  local_158[0xb] =
       CONCAT31(CONCAT21(CONCAT11(param_2[0x2c],param_2[0x2d]),param_2[0x2e]),param_2[0x2f]);
  local_158[0xc] =
       CONCAT31(CONCAT21(CONCAT11(param_2[0x30],param_2[0x31]),param_2[0x32]),param_2[0x33]);
  local_158[0xd] =
       CONCAT31(CONCAT21(CONCAT11(param_2[0x34],param_2[0x35]),param_2[0x36]),param_2[0x37]);
  local_158[0xe] =
       CONCAT31(CONCAT21(CONCAT11(param_2[0x38],param_2[0x39]),param_2[0x3a]),param_2[0x3b]);
  lVar3 = 0x10;
  local_158[0xf] =
       CONCAT31(CONCAT21(CONCAT11(param_2[0x3c],param_2[0x3d]),param_2[0x3e]),param_2[0x3f]);
  do {
    uVar11 = auStack_198[lVar3 + 2];
    uVar5 = auStack_198[lVar3 + 1];
    uVar10 = auStack_198[lVar3 + 0xe];
    uVar12 = auStack_198[lVar3 + 0xf];
    uVar13 = ((uVar5 >> 0x12 | uVar5 << 0xe) ^ (uVar5 >> 7 | uVar5 << 0x19) ^ uVar5 >> 3) +
             ((uVar10 >> 0x11 | uVar10 << 0xf) ^ (uVar10 >> 0x13 | uVar10 << 0xd) ^ uVar10 >> 10) +
             auStack_198[lVar3] + auStack_198[lVar3 + 9];
    auStack_198[lVar3 + 0x10] = uVar13;
    uVar6 = auStack_198[lVar3 + 3];
    uVar9 = uVar5 + ((uVar11 >> 0x12 | uVar11 << 0xe) ^ (uVar11 >> 7 | uVar11 << 0x19) ^ uVar11 >> 3
                    ) +
            ((uVar12 >> 0x11 | uVar12 << 0xf) ^ (uVar12 >> 0x13 | uVar12 << 0xd) ^ uVar12 >> 10) +
            auStack_198[lVar3 + 10];
    auStack_198[lVar3 + 0x11] = uVar9;
    uVar5 = auStack_198[lVar3 + 4];
    uVar4 = ((uVar13 >> 0x11 | uVar13 * 0x8000) ^ (uVar13 >> 0x13 | uVar13 * 0x2000) ^ uVar13 >> 10)
            + uVar11 + ((uVar6 >> 0x12 | uVar6 << 0xe) ^ (uVar6 >> 7 | uVar6 << 0x19) ^ uVar6 >> 3)
            + auStack_198[lVar3 + 0xb];
    auStack_198[lVar3 + 0x12] = uVar4;
    uVar11 = auStack_198[lVar3 + 5];
    uVar7 = auStack_198[lVar3 + 6];
    uVar9 = ((uVar9 >> 0x11 | uVar9 * 0x8000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000) ^ uVar9 >> 10) +
            uVar6 + ((uVar5 >> 0x12 | uVar5 << 0xe) ^ (uVar5 >> 7 | uVar5 << 0x19) ^ uVar5 >> 3) +
            auStack_198[lVar3 + 0xc];
    auStack_198[lVar3 + 0x13] = uVar9;
    uVar6 = auStack_198[lVar3 + 7];
    uVar5 = (uVar4 >> 10 ^ (uVar4 >> 0x11 | uVar4 * 0x8000) ^ (uVar4 >> 0x13 | uVar4 * 0x2000)) +
            uVar5 + ((uVar11 >> 0x12 | uVar11 << 0xe) ^ (uVar11 >> 7 | uVar11 << 0x19) ^ uVar11 >> 3
                    ) + auStack_198[lVar3 + 0xd];
    auStack_198[lVar3 + 0x14] = uVar5;
    uVar10 = uVar11 + ((uVar7 >> 0x12 | uVar7 << 0xe) ^ (uVar7 >> 7 | uVar7 << 0x19) ^ uVar7 >> 3) +
             ((uVar9 >> 0x11 | uVar9 * 0x8000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000) ^ uVar9 >> 10) +
             uVar10;
    auStack_198[lVar3 + 0x15] = uVar10;
    auStack_198[lVar3 + 0x16] =
         ((uVar5 >> 0x11 | uVar5 * 0x8000) ^ (uVar5 >> 0x13 | uVar5 * 0x2000) ^ uVar5 >> 10) +
         uVar7 + ((uVar6 >> 0x12 | uVar6 << 0xe) ^ (uVar6 >> 7 | uVar6 << 0x19) ^ uVar6 >> 3) +
         uVar12;
    uVar11 = auStack_198[lVar3 + 8];
    auStack_198[lVar3 + 0x17] =
         ((uVar10 >> 0x11 | uVar10 * 0x8000) ^ (uVar10 >> 0x13 | uVar10 * 0x2000) ^ uVar10 >> 10) +
         uVar6 + ((uVar11 >> 0x12 | uVar11 << 0xe) ^ (uVar11 >> 7 | uVar11 << 0x19) ^ uVar11 >> 3) +
         uVar13;
    lVar3 = lVar3 + 8;
  } while (lVar3 != 0x40);
  uVar6 = param_1[1];
  uVar7 = param_1[2];
  lVar3 = 0;
  uVar4 = param_1[3];
  uVar12 = param_1[4];
  uVar5 = param_1[6];
  uVar11 = param_1[7];
  uVar10 = param_1[5];
  uVar9 = *param_1;
  do {
    iVar8 = ((uVar12 >> 0xb | uVar12 << 0x15) ^ (uVar12 >> 6 | uVar12 << 0x1a) ^
            (uVar12 >> 0x19 | uVar12 << 7)) + (~uVar12 & uVar5 ^ uVar10 & uVar12) +
            (&DAT_180020920)[lVar3] + auStack_198[lVar3 + 0x10] + uVar11;
    uVar11 = iVar8 + uVar4;
    uVar4 = ((uVar6 ^ uVar9) & uVar7 ^ uVar6 & uVar9) +
            ((uVar9 >> 0x16 | uVar9 << 10) ^ (uVar9 >> 0xd | uVar9 << 0x13) ^
            (uVar9 >> 2 | uVar9 << 0x1e)) + iVar8;
    iVar8 = ((uVar11 >> 0xb | uVar11 * 0x200000) ^ (uVar11 >> 6 | uVar11 * 0x4000000) ^
            (uVar11 >> 0x19 | uVar11 * 0x80)) + (~uVar11 & uVar10 ^ uVar12 & uVar11) +
            (&DAT_180020924)[lVar3] + auStack_198[lVar3 + 0x11] + uVar5;
    uVar5 = iVar8 + uVar7;
    uVar7 = ((uVar9 ^ uVar4) & uVar6 ^ uVar9 & uVar4) +
            ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
            (uVar4 >> 2 | uVar4 * 0x40000000)) + iVar8;
    iVar8 = ((uVar5 >> 0xb | uVar5 * 0x200000) ^ (uVar5 >> 6 | uVar5 * 0x4000000) ^
            (uVar5 >> 0x19 | uVar5 * 0x80)) + (~uVar5 & uVar12 ^ uVar11 & uVar5) +
            (&DAT_180020928)[lVar3] + auStack_198[lVar3 + 0x12] + uVar10;
    uVar10 = iVar8 + uVar6;
    uVar6 = ((uVar4 ^ uVar7) & uVar9 ^ uVar4 & uVar7) +
            ((uVar7 >> 0x16 | uVar7 * 0x400) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
            (uVar7 >> 2 | uVar7 * 0x40000000)) + iVar8;
    piVar1 = &DAT_18002092c + lVar3;
    lVar2 = lVar3 + 0x13;
    lVar3 = lVar3 + 4;
    iVar8 = ((uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 6 | uVar10 * 0x4000000) ^
            (uVar10 >> 0x19 | uVar10 * 0x80)) + (~uVar10 & uVar11 ^ uVar5 & uVar10) + *piVar1 +
            auStack_198[lVar2] + uVar12;
    uVar12 = iVar8 + uVar9;
    uVar9 = ((uVar7 ^ uVar6) & uVar4 ^ uVar7 & uVar6) +
            ((uVar6 >> 0x16 | uVar6 * 0x400) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
            (uVar6 >> 2 | uVar6 * 0x40000000)) + iVar8;
  } while (lVar3 != 0x40);
  param_1[1] = param_1[1] + uVar6;
  param_1[2] = param_1[2] + uVar7;
  param_1[3] = param_1[3] + uVar4;
  param_1[4] = param_1[4] + uVar12;
  param_1[6] = param_1[6] + uVar5;
  *param_1 = *param_1 + uVar9;
  param_1[5] = param_1[5] + uVar10;
  param_1[7] = param_1[7] + uVar11;
  return;
}



void FUN_18000be00(undefined4 *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 local_48 [8];
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  char local_39;
  
  uVar4 = *(ulonglong *)(param_1 + 8);
  puVar7 = local_48;
  local_48[0] = 0x80;
  puVar1 = param_1 + 10;
  uVar5 = 1;
  *(ulonglong *)(param_1 + 8) = uVar4 + 1;
  do {
    uVar2 = 0x40 - *(longlong *)(param_1 + 0x1a);
    uVar6 = uVar5;
    if (uVar2 <= uVar5) {
      uVar6 = uVar2;
    }
    memcpy((undefined1 *)(*(longlong *)(param_1 + 0x1a) + (longlong)puVar1),puVar7,uVar6);
    puVar7 = puVar7 + uVar6;
    lVar3 = *(longlong *)(param_1 + 0x1a) + uVar6;
    uVar5 = uVar5 - uVar6;
    *(longlong *)(param_1 + 0x1a) = lVar3;
    if (lVar3 == 0x40) {
      FUN_18000b730(param_1,puVar1);
      lVar3 = 0;
      *(undefined8 *)(param_1 + 0x1a) = 0;
    }
  } while (uVar5 != 0);
  local_48[0] = 0;
  while (lVar3 != 0x38) {
    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 1;
    puVar7 = local_48;
    uVar5 = 1;
    do {
      uVar6 = uVar5;
      if (0x40U - lVar3 <= uVar5) {
        uVar6 = 0x40U - lVar3;
      }
      memcpy((undefined1 *)(lVar3 + (longlong)puVar1),puVar7,uVar6);
      puVar7 = puVar7 + uVar6;
      lVar3 = *(longlong *)(param_1 + 0x1a) + uVar6;
      uVar5 = uVar5 - uVar6;
      *(longlong *)(param_1 + 0x1a) = lVar3;
      if (lVar3 == 0x40) {
        FUN_18000b730(param_1,puVar1);
        lVar3 = 0;
        *(undefined8 *)(param_1 + 0x1a) = 0;
      }
    } while (uVar5 != 0);
  }
  puVar7 = &local_40;
  uVar6 = 8;
  uVar5 = uVar4 & 0x1fffffffffffffff;
  local_39 = (char)uVar4 << 3;
  local_40 = (undefined1)(uVar5 >> 0x35);
  local_3f = (undefined1)(uVar5 >> 0x2d);
  local_3e = (undefined1)(uVar5 >> 0x25);
  local_3d = (undefined1)(uVar5 >> 0x1d);
  local_3c = (undefined1)(uVar5 >> 0x15);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 8;
  local_3b = (undefined1)(uVar5 >> 0xd);
  local_3a = (undefined1)(uVar5 >> 5);
  lVar3 = 0x38;
  do {
    uVar4 = uVar6;
    if (0x40U - lVar3 <= uVar6) {
      uVar4 = 0x40U - lVar3;
    }
    memcpy((undefined1 *)(lVar3 + (longlong)puVar1),puVar7,uVar4);
    puVar7 = puVar7 + uVar4;
    lVar3 = *(longlong *)(param_1 + 0x1a) + uVar4;
    uVar6 = uVar6 - uVar4;
    *(longlong *)(param_1 + 0x1a) = lVar3;
    if (lVar3 == 0x40) {
      FUN_18000b730(param_1,puVar1);
      lVar3 = 0;
      *(undefined8 *)(param_1 + 0x1a) = 0;
    }
  } while (uVar6 != 0);
  *param_2 = (char)((uint)*param_1 >> 0x18);
  param_2[1] = (char)((uint)*param_1 >> 0x10);
  param_2[2] = (char)((uint)*param_1 >> 8);
  param_2[3] = *(undefined1 *)param_1;
  param_2[4] = (char)((uint)param_1[1] >> 0x18);
  param_2[5] = (char)((uint)param_1[1] >> 0x10);
  param_2[6] = (char)((uint)param_1[1] >> 8);
  param_2[7] = *(undefined1 *)(param_1 + 1);
  param_2[8] = (char)((uint)param_1[2] >> 0x18);
  param_2[9] = (char)((uint)param_1[2] >> 0x10);
  param_2[10] = (char)((uint)param_1[2] >> 8);
  param_2[0xb] = *(undefined1 *)(param_1 + 2);
  param_2[0xc] = (char)((uint)param_1[3] >> 0x18);
  param_2[0xd] = (char)((uint)param_1[3] >> 0x10);
  param_2[0xe] = (char)((uint)param_1[3] >> 8);
  param_2[0xf] = *(undefined1 *)(param_1 + 3);
  param_2[0x10] = (char)((uint)param_1[4] >> 0x18);
  param_2[0x11] = (char)((uint)param_1[4] >> 0x10);
  param_2[0x12] = (char)((uint)param_1[4] >> 8);
  param_2[0x13] = *(undefined1 *)(param_1 + 4);
  param_2[0x14] = (char)((uint)param_1[5] >> 0x18);
  param_2[0x15] = (char)((uint)param_1[5] >> 0x10);
  param_2[0x16] = (char)((uint)param_1[5] >> 8);
  param_2[0x17] = *(undefined1 *)(param_1 + 5);
  param_2[0x18] = (char)((uint)param_1[6] >> 0x18);
  param_2[0x19] = (char)((uint)param_1[6] >> 0x10);
  param_2[0x1a] = (char)((uint)param_1[6] >> 8);
  param_2[0x1b] = *(undefined1 *)(param_1 + 6);
  param_2[0x1c] = (char)((uint)param_1[7] >> 0x18);
  param_2[0x1d] = (char)((uint)param_1[7] >> 0x10);
  param_2[0x1e] = (char)((uint)param_1[7] >> 8);
  param_2[0x1f] = *(undefined1 *)(param_1 + 7);
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_18000c120(void *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  ulonglong _Size;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStack_e8 [32];
  byte local_c8 [32];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  ulonglong local_88;
  undefined1 local_80 [64];
  longlong local_40;
  ulonglong local_38;
  
  local_38 = DAT_180030500 ^ (ulonglong)auStack_e8;
  local_a8 = 0x6a09e667;
  local_a4 = 0xbb67ae85;
  local_a0 = 0x3c6ef372;
  local_9c = 0xa54ff53a;
  local_98 = 0x510e527f;
  local_94 = 0x9b05688c;
  local_90 = 0x1f83d9ab;
  local_8c = 0x5be0cd19;
  local_40 = 0;
  local_88 = param_2;
  while (param_2 != 0) {
    _Size = param_2;
    if (0x40U - local_40 <= param_2) {
      _Size = 0x40U - local_40;
    }
    memcpy(local_80 + local_40,param_1,_Size);
    param_1 = (void *)((longlong)param_1 + _Size);
    local_40 = local_40 + _Size;
    param_2 = param_2 - _Size;
    if (local_40 == 0x40) {
      FUN_18000b730(&local_a8,local_80);
      local_40 = 0;
    }
  }
  FUN_18000be00(&local_a8,local_c8);
  puVar5 = PTR_s_0123456789abcdef_18002d000;
  iVar6 = 0;
  iVar7 = 0;
  lVar9 = 0;
  do {
    bVar2 = local_c8[lVar9];
    bVar3 = local_c8[lVar9 + 2];
    lVar8 = (longlong)iVar7;
    *(undefined *)(param_3 + lVar8) = puVar5[bVar2 >> 4];
    bVar4 = local_c8[lVar9 + 1];
    *(undefined *)(param_3 + 1 + lVar8) = puVar5[bVar2 & 0xf];
    *(undefined *)(param_3 + 2 + lVar8) = puVar5[bVar4 >> 4];
    *(undefined *)(param_3 + 3 + lVar8) = puVar5[bVar4 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 4)) = puVar5[bVar3 >> 4];
    bVar2 = local_c8[lVar9 + 3];
    *(undefined *)(param_3 + 5 + lVar8) = puVar5[bVar3 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 6)) = puVar5[bVar2 >> 4];
    bVar3 = local_c8[lVar9 + 4];
    *(undefined *)(param_3 + 7 + lVar8) = puVar5[bVar2 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 8)) = puVar5[bVar3 >> 4];
    bVar2 = local_c8[lVar9 + 5];
    *(undefined *)(param_3 + 9 + lVar8) = puVar5[bVar3 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 10)) = puVar5[bVar2 >> 4];
    bVar3 = local_c8[lVar9 + 6];
    *(undefined *)(param_3 + 0xb + lVar8) = puVar5[bVar2 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0xc)) = puVar5[bVar3 >> 4];
    bVar2 = local_c8[lVar9 + 7];
    *(undefined *)(param_3 + 0xd + lVar8) = puVar5[bVar3 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0xe)) = puVar5[bVar2 >> 4];
    bVar3 = local_c8[lVar9 + 8];
    *(undefined *)(param_3 + 0xf + lVar8) = puVar5[bVar2 & 0xf];
    iVar7 = iVar7 + 0x20;
    *(undefined *)(param_3 + (iVar6 * 2 + 0x10)) = puVar5[bVar3 >> 4];
    bVar2 = local_c8[lVar9 + 9];
    *(undefined *)(param_3 + 0x11 + lVar8) = puVar5[bVar3 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0x12)) = puVar5[bVar2 >> 4];
    bVar3 = local_c8[lVar9 + 10];
    *(undefined *)(param_3 + 0x13 + lVar8) = puVar5[bVar2 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0x14)) = puVar5[bVar3 >> 4];
    bVar2 = local_c8[lVar9 + 0xb];
    *(undefined *)(param_3 + 0x15 + lVar8) = puVar5[bVar3 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0x16)) = puVar5[bVar2 >> 4];
    bVar3 = local_c8[lVar9 + 0xc];
    *(undefined *)(param_3 + 0x17 + lVar8) = puVar5[bVar2 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0x18)) = puVar5[bVar3 >> 4];
    bVar2 = local_c8[lVar9 + 0xd];
    *(undefined *)(param_3 + 0x19 + lVar8) = puVar5[bVar3 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0x1a)) = puVar5[bVar2 >> 4];
    bVar3 = local_c8[lVar9 + 0xe];
    *(undefined *)(param_3 + 0x1b + lVar8) = puVar5[bVar2 & 0xf];
    *(undefined *)(param_3 + (iVar6 * 2 + 0x1c)) = puVar5[bVar3 >> 4];
    bVar2 = local_c8[lVar9 + 0xf];
    *(undefined *)(param_3 + 0x1d + lVar8) = puVar5[bVar3 & 0xf];
    iVar1 = iVar6 * 2;
    iVar6 = iVar6 + 0x10;
    *(undefined *)(param_3 + (iVar1 + 0x1e)) = puVar5[bVar2 >> 4];
    *(undefined *)(param_3 + 0x1f + lVar8) = puVar5[bVar2 & 0xf];
    lVar9 = lVar9 + 0x10;
  } while (iVar6 < 0x20);
  *(undefined1 *)(param_3 + 0x40) = 0;
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_18000c500(char *param_1,int param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  DWORD DVar4;
  LSTATUS LVar5;
  char *pcVar6;
  __time64_t _Var7;
  char *pcVar8;
  size_t sVar9;
  undefined8 uVar10;
  int iVar11;
  undefined1 auStackY_9a8 [32];
  DWORD local_978;
  DWORD local_974;
  HKEY local_970;
  char local_968;
  undefined1 uStack_967;
  undefined6 uStack_966;
  undefined2 uStack_960;
  undefined6 uStack_95e;
  undefined2 uStack_958;
  undefined6 uStack_956;
  undefined2 uStack_950;
  undefined1 local_94e;
  char local_918 [80];
  char local_8c8 [160];
  undefined1 local_828 [80];
  char local_7d8 [159];
  char acStack_739 [257];
  char local_638 [1536];
  ulonglong local_38;
  
  local_38 = DAT_180030500 ^ (ulonglong)auStackY_9a8;
  pcVar6 = strchr(param_1,0x2e);
  if (pcVar6 != (char *)0x0) {
    iVar11 = (int)pcVar6 - (int)param_1;
    uVar2 = FUN_18000b3b0(param_1,iVar11,local_638,0x5ff);
    iVar11 = FUN_18000b3b0(pcVar6 + 1,(param_2 - iVar11) + -1,local_828,0x50);
    if ((0 < (int)uVar2) && (iVar11 == 0x40)) {
      if (0x5ff < uVar2) {
LAB_18000c87d:
        FUN_180012a20();
        pcVar1 = (code *)swi(3);
        uVar10 = (*pcVar1)();
        return uVar10;
      }
      local_638[(int)uVar2] = '\0';
      iVar11 = FUN_180010e00(local_828,&DAT_180020900,local_638,(longlong)(int)uVar2);
      if ((iVar11 == 0) && (pcVar6 = strstr(local_638,"\"exp\":"), pcVar6 != (char *)0x0)) {
        lVar3 = strtol(pcVar6 + 6,(char **)0x0,10);
        _Var7 = _time64((__time64_t *)0x0);
        if ((int)_Var7 < lVar3) {
          snprintf(local_7d8,0xa0,&DAT_180029b4c,param_3);
          pcVar6 = strstr(local_638,local_7d8);
          if (pcVar6 != (char *)0x0) {
            pcVar6 = strstr(local_638,"\"m\":\"");
            if (pcVar6 != (char *)0x0) {
              pcVar6 = pcVar6 + 5;
              pcVar8 = strchr(pcVar6,0x22);
              if ((((pcVar8 != (char *)0x0) && (pcVar6 < pcVar8)) &&
                  (uVar2 = (int)pcVar8 - (int)pcVar6, 0 < (int)uVar2)) && ((int)uVar2 < 0x50)) {
                memcpy(local_918,pcVar6,(longlong)(int)uVar2);
                if (0x4f < uVar2) goto LAB_18000c87d;
                local_918[(int)uVar2] = '\0';
                if (DAT_180030654 == 0) {
                  _DAT_180030638 = _DAT_180030638 & 0xff00;
                  local_8c8[0] = '\0';
                  DVar4 = RegOpenKeyExA((HKEY)0xffffffff80000002,"SOFTWARE\\Microsoft\\Cryptography"
                                        ,0,0x20119,&local_970);
                  if (DVar4 == 0) {
                    local_974 = 0x100;
                    local_978 = DVar4;
                    LVar5 = RegQueryValueExA(local_970,"MachineGuid",(LPDWORD)0x0,&local_978,
                                             (LPBYTE)(acStack_739 + 1),&local_974);
                    RegCloseKey(local_970);
                    if ((LVar5 == 0) && (uVar2 = local_974, local_978 == 1)) {
                      for (; 0 < (int)uVar2; uVar2 = uVar2 - 1) {
                        if (acStack_739[uVar2] != '\0') {
                          if (0x9f < uVar2) {
                            uVar2 = 0x9f;
                          }
                          memcpy(local_8c8,acStack_739 + 1,(ulonglong)uVar2);
                          local_8c8[uVar2] = '\0';
                          if (local_8c8[0] != '\0') {
                            sVar9 = strlen(local_8c8);
                            FUN_18000c120(local_8c8,sVar9,&local_968);
                            _DAT_18003063a = CONCAT62(uStack_966,CONCAT11(uStack_967,local_968));
                            uRam0000000180030642 = CONCAT62(uStack_95e,uStack_960);
                            DAT_18003064a = CONCAT62(uStack_956,uStack_958);
                            _DAT_180030638 = 0x2d6d;
                            DAT_180030652 = 0;
                          }
                          break;
                        }
                      }
                    }
                  }
                  DAT_180030654 = 1;
                }
                if (DAT_180030638 != '\0') {
                  local_968 = DAT_180030638;
                  uStack_967 = DAT_180030639;
                  local_94e = DAT_180030652;
                  uStack_966 = (undefined6)_DAT_18003063a;
                  uStack_960 = (undefined2)((ulonglong)_DAT_18003063a >> 0x30);
                  uStack_95e = (undefined6)uRam0000000180030642;
                  uStack_958 = (undefined2)((ulonglong)uRam0000000180030642 >> 0x30);
                  uStack_956 = (undefined6)DAT_18003064a;
                  uStack_950 = (undefined2)((ulonglong)DAT_18003064a >> 0x30);
                  iVar11 = strcmp(local_918,&local_968);
                  if (iVar11 != 0) {
                    return 0;
                  }
                }
              }
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}



void FUN_18000c890(longlong param_1,int param_2,int param_3,int param_4,float *param_5)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  
  iVar5 = 0;
  if (-1 < param_3) {
    iVar5 = param_3;
  }
  iVar6 = 0;
  if (-1 < param_4) {
    iVar6 = param_4;
  }
  iVar2 = *(int *)(param_1 + 0x28) + -1;
  if (iVar6 < *(int *)(param_1 + 0x28)) {
    iVar2 = iVar6;
  }
  lVar4 = (longlong)*(int *)(param_1 + 0x20) * (longlong)iVar2 + *(longlong *)(param_1 + 0x18);
  iVar6 = *(int *)(param_1 + 0x24) + -1;
  if (iVar5 < *(int *)(param_1 + 0x24)) {
    iVar6 = iVar5;
  }
  lVar3 = (longlong)iVar6;
  if (param_2 == 2) {
    *param_5 = *(float *)(lVar4 + 4 + lVar3 * 0x10);
    param_5[1] = *(float *)(lVar4 + 8 + lVar3 * 0x10);
    param_5[2] = *(float *)(lVar4 + 0xc + lVar3 * 0x10);
    param_5[3] = *(float *)(lVar4 + lVar3 * 0x10);
    return;
  }
  if (param_2 == 1) {
    fVar7 = 3.0517578e-05;
    *param_5 = (float)*(ushort *)(lVar4 + 2 + lVar3 * 8) * 3.0517578e-05;
    param_5[1] = (float)*(ushort *)(lVar4 + 4 + lVar3 * 8) * 3.0517578e-05;
    param_5[2] = (float)*(ushort *)(lVar4 + 6 + lVar3 * 8) * 3.0517578e-05;
    uVar1 = *(ushort *)(lVar4 + lVar3 * 8);
  }
  else {
    fVar7 = 0.003921569;
    *param_5 = (float)*(byte *)(lVar4 + 1 + lVar3 * 4) * 0.003921569;
    param_5[1] = (float)*(byte *)(lVar4 + 2 + lVar3 * 4) * 0.003921569;
    param_5[2] = (float)*(byte *)(lVar4 + 3 + lVar3 * 4) * 0.003921569;
    uVar1 = (ushort)*(byte *)(lVar4 + lVar3 * 4);
  }
  param_5[3] = (float)uVar1 * fVar7;
  return;
}



char * FUN_18000c9e0(longlong param_1)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(char **)(param_1 + 8) != (char *)0x0) {
    pcVar1 = *(char **)(param_1 + 8);
  }
  return pcVar1;
}



undefined4
EffectMain(undefined4 param_1,longlong param_2,undefined4 *param_3,undefined8 param_4,
          undefined8 param_5,longlong param_6)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 in_stack_fffffffffffffb38;
  undefined4 uVar6;
  longlong local_4b8 [2];
  undefined8 *local_4a8 [59];
  longlong local_2d0;
  
                    // 0xca00  1  EffectMain
  uVar6 = (undefined4)((ulonglong)in_stack_fffffffffffffb38 >> 0x20);
  uVar3 = 0;
  switch(param_1) {
  case 0:
    FUN_180001000(local_4a8,*(undefined8 *)(param_2 + 0x180));
    if (local_2d0 == 0) {
      iVar2 = (*(code *)*local_4a8[0])("PF ANSI Suite",1,local_4b8);
      if ((iVar2 != 0) || (local_4b8[0] == 0)) {
        FUN_180001fc0(local_4a8);
      }
      local_2d0 = local_4b8[0];
    }
    pcVar1 = *(code **)(local_2d0 + 0x78);
    uVar4 = FUN_18000cce0(2);
    uVar5 = FUN_18000cce0(1);
    (*pcVar1)(param_3 + 0x19,"%s v%d.%d\r%s",uVar5,1,CONCAT44(uVar6,1),uVar4);
    FUN_180001040(local_4a8);
    uVar3 = 0;
    break;
  case 1:
    *param_3 = 0x8ae01;
    param_3[0x18] = 0x2008004;
    param_3[100] = 0x8001400;
    uVar3 = 0;
    break;
  case 4:
    uVar3 = FUN_180007880(param_2,param_3,param_4,param_5);
    break;
  case 0xb:
    uVar3 = FUN_1800095b0(param_2,param_3,param_4,param_5);
    break;
  case 0xf:
    uVar3 = 0;
    if ((param_6 != 0) && (*(int *)(param_6 + 8) == 4)) {
      uVar3 = FUN_1800070b0(param_2,param_3,param_4,param_5,param_6);
    }
    break;
  case 0x17:
    uVar3 = FUN_1800091e0(param_2,param_3,param_6);
    break;
  case 0x18:
    uVar3 = FUN_1800096a0(param_2,param_3,param_6);
  }
  return uVar3;
}



void PluginDataEntryFunction2(undefined8 param_1,code *param_2)

{
                    // 0xcc10  2  PluginDataEntryFunction2
  (*param_2)(param_1,"OVN ASCII","OVN ASCII","Oblivixn","EffectMain",0x65464b54,0xd,0x1d,8,
             "https://oblivixn.de/guide#ovn-ascii");
  return;
}



undefined * FUN_18000cc70(void)

{
  return &DAT_180030630;
}



// Library Function - Single Match
//  snprintf
// 
// Library: Visual Studio 2019 Release

int snprintf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res20;
  
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_18000cc70();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 2,param_1,param_2,param_3,0,&local_res20);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



undefined * FUN_18000cce0(int param_1)

{
  return &DAT_18002d014 + (longlong)param_1 * 0x104;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

int FUN_18000cd00(longlong param_1,undefined8 param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  int *piVar7;
  ulonglong uVar8;
  undefined1 auStack_4b8 [32];
  undefined1 *local_498;
  undefined1 local_488;
  undefined1 local_487;
  undefined1 local_486;
  undefined1 local_485;
  undefined1 local_484;
  undefined1 local_483;
  undefined1 local_482;
  undefined1 local_481;
  undefined1 local_480;
  undefined1 local_47f;
  undefined1 local_47e;
  undefined1 local_47d;
  undefined1 local_47c;
  undefined1 local_47b;
  undefined1 local_47a;
  undefined1 local_479;
  undefined1 local_478;
  undefined1 local_477;
  undefined1 local_476;
  undefined1 local_475;
  undefined1 local_474;
  undefined1 local_473;
  undefined1 local_472;
  undefined1 local_471;
  undefined1 local_470;
  undefined1 local_46f;
  undefined1 local_46e;
  undefined1 local_46d;
  undefined2 local_46c;
  undefined1 local_46a;
  byte local_469;
  undefined2 local_468;
  undefined1 local_466;
  byte local_465;
  int local_458;
  int local_454;
  int local_450;
  int local_44c;
  int local_448;
  int local_444;
  int local_440;
  int local_43c;
  int local_438;
  int local_434;
  int local_430;
  int local_42c;
  int local_428;
  int local_424;
  int local_420;
  int local_41c;
  int local_418;
  int local_414;
  int local_410;
  int local_40c;
  int local_408;
  int iStack_404;
  int iStack_400;
  int iStack_3fc;
  int local_3f8;
  int iStack_3f4;
  int iStack_3f0;
  int iStack_3ec;
  undefined8 local_3e8;
  int local_3e0;
  int iStack_3dc;
  int iStack_3d8;
  int iStack_3d4;
  int local_3d0;
  int iStack_3cc;
  int iStack_3c8;
  int iStack_3c4;
  undefined8 local_3c0;
  undefined8 local_3b8;
  undefined8 uStack_3b0;
  undefined8 local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  undefined8 uStack_390;
  undefined8 local_388;
  undefined8 uStack_380;
  undefined8 local_378;
  undefined8 uStack_370;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  undefined8 uStack_320;
  undefined1 local_318 [160];
  undefined1 local_278 [160];
  undefined1 local_1d8 [16];
  undefined1 local_1c8 [32];
  int local_1a8 [40];
  undefined1 local_108 [160];
  undefined1 local_68 [40];
  ulonglong local_40;
  
  local_40 = DAT_180030500 ^ (ulonglong)auStack_4b8;
  local_488 = *(undefined1 *)(param_1 + 0x27);
  uVar6 = *(uint *)(param_1 + 0x20);
  local_487 = *(undefined1 *)(param_1 + 0x26);
  local_486 = *(undefined1 *)(param_1 + 0x25);
  local_485 = *(undefined1 *)(param_1 + 0x24);
  local_484 = *(undefined1 *)(param_1 + 0x2b);
  local_483 = *(undefined1 *)(param_1 + 0x2a);
  local_482 = *(undefined1 *)(param_1 + 0x29);
  local_481 = *(undefined1 *)(param_1 + 0x28);
  local_480 = *(undefined1 *)(param_1 + 0x2f);
  local_47f = *(undefined1 *)(param_1 + 0x2e);
  local_47e = *(undefined1 *)(param_1 + 0x2d);
  local_47d = *(undefined1 *)(param_1 + 0x2c);
  local_47c = *(undefined1 *)(param_1 + 0x33);
  local_47b = *(undefined1 *)(param_1 + 0x32);
  local_47a = *(undefined1 *)(param_1 + 0x31);
  local_479 = *(undefined1 *)(param_1 + 0x30);
  local_478 = *(undefined1 *)(param_1 + 0x37);
  local_477 = *(undefined1 *)(param_1 + 0x36);
  local_476 = *(undefined1 *)(param_1 + 0x35);
  local_475 = *(undefined1 *)(param_1 + 0x34);
  local_474 = *(undefined1 *)(param_1 + 0x3b);
  local_473 = *(undefined1 *)(param_1 + 0x3a);
  local_472 = *(undefined1 *)(param_1 + 0x39);
  local_471 = *(undefined1 *)(param_1 + 0x38);
  local_470 = *(undefined1 *)(param_1 + 0x3f);
  local_46f = *(undefined1 *)(param_1 + 0x3e);
  local_46e = *(undefined1 *)(param_1 + 0x3d);
  local_46d = *(undefined1 *)(param_1 + 0x3c);
  iVar2 = FUN_18000f870(&local_3b8);
  if (((iVar2 != 0) || (iVar2 = FUN_18000f870(local_318,param_1), iVar2 != 0)) ||
     ((int)((ulonglong)CONCAT31(CONCAT21(CONCAT11(local_470,local_46f),local_46e),local_46d) +
            0xefffffff +
            ((ulonglong)CONCAT31(CONCAT21(CONCAT11(local_474,local_473),local_472),local_471) +
             0xffffffff +
             ((ulonglong)CONCAT31(CONCAT21(CONCAT11(local_478,local_477),local_476),local_475) +
              0xffffffff +
              (((ulonglong)CONCAT31(CONCAT21(CONCAT11(local_480,local_47f),local_47e),local_47d) +
                0xeb210621 +
                ((((ulonglong)uVar6 + 0xa30a2c13 >> 0x20) +
                  (ulonglong)CONCAT31(CONCAT21(CONCAT11(local_488,local_487),local_486),local_485) +
                  0xa7ed9ce5 >> 0x20) +
                 (ulonglong)CONCAT31(CONCAT21(CONCAT11(local_484,local_483),local_482),local_481) +
                 0x5d086329 >> 0x20) >> 0x20) +
               (ulonglong)CONCAT31(CONCAT21(CONCAT11(local_47c,local_47b),local_47a),local_479) +
               0xffffffff >> 0x20) >> 0x20) >> 0x20) >> 0x20) != 0)) {
    return -1;
  }
  FUN_18000f4c0(local_278,&local_3b8,&local_458);
  FUN_18000f3b0(local_1a8,&local_3b8);
  FUN_18000efb0(&local_458,local_278,local_1a8);
  FUN_18000f3b0(local_108,&local_458);
  uVar8 = 0xfc;
  uVar6 = 0xfc;
  do {
    if ((*(byte *)(param_3 + (ulonglong)(uVar6 >> 3)) >> ((byte)uVar6 & 7) & 1) != 0) break;
    uVar6 = uVar6 - 1;
  } while (0 < (int)uVar6);
  local_469 = (char)uVar6 + 1;
  local_46c = 0xffff;
  local_46a = 0xff;
  do {
    if ((*(byte *)(param_1 + 0x20 + (uVar8 >> 3)) >> ((byte)uVar8 & 7) & 1) != 0) break;
    uVar6 = (int)uVar8 - 1;
    uVar8 = (ulonglong)uVar6;
  } while (0 < (int)uVar6);
  local_3b8 = 0;
  uStack_3b0 = 0;
  local_398 = 0;
  uStack_390 = 1;
  local_465 = (char)uVar8 + 1;
  local_388 = 0;
  uStack_380 = 0;
  local_368 = 1;
  uStack_360 = 0;
  bVar1 = local_469;
  if (local_469 < local_465) {
    bVar1 = local_465;
  }
  uVar6 = (uint)bVar1;
  local_358 = 0;
  uStack_350 = 0;
  local_338 = 0;
  uStack_330 = 0;
  local_468 = 0xffff;
  local_466 = 0xff;
  local_3a8 = 0;
  uStack_3a0 = 0;
  local_378 = 0;
  uStack_370 = 0;
  local_348 = 0;
  uStack_340 = 0;
  local_328 = 0;
  uStack_320 = 0;
  do {
    FUN_18000f4c0(&local_3b8,&local_3b8,local_278);
    iVar2 = FUN_180010b20(&local_46c,3,uVar6,param_3);
    iVar3 = FUN_180010b20(&local_468,5,uVar6,(uint *)(param_1 + 0x20));
    if (iVar2 < 1) {
      if (iVar2 < 0) {
        piVar7 = &local_458;
        lVar5 = (longlong)-(iVar2 / 2);
        local_430 = local_1a8[lVar5 * 0x28];
        local_42c = local_1a8[lVar5 * 0x28 + 1];
        local_3e0 = -local_1a8[lVar5 * 0x28 + 0x1e];
        iStack_3dc = -local_1a8[lVar5 * 0x28 + 0x1f];
        iStack_3d8 = -local_1a8[lVar5 * 0x28 + 0x20];
        iStack_3d4 = -local_1a8[lVar5 * 0x28 + 0x21];
        local_428 = local_1a8[lVar5 * 0x28 + 2];
        local_424 = local_1a8[lVar5 * 0x28 + 3];
        local_420 = local_1a8[lVar5 * 0x28 + 4];
        local_41c = local_1a8[lVar5 * 0x28 + 5];
        local_418 = local_1a8[lVar5 * 0x28 + 6];
        local_414 = local_1a8[lVar5 * 0x28 + 7];
        local_410 = local_1a8[lVar5 * 0x28 + 8];
        local_40c = local_1a8[lVar5 * 0x28 + 9];
        local_458 = local_1a8[lVar5 * 0x28 + 10];
        local_454 = local_1a8[lVar5 * 0x28 + 0xb];
        local_450 = local_1a8[lVar5 * 0x28 + 0xc];
        local_44c = local_1a8[lVar5 * 0x28 + 0xd];
        local_448 = local_1a8[lVar5 * 0x28 + 0xe];
        local_444 = local_1a8[lVar5 * 0x28 + 0xf];
        local_440 = local_1a8[lVar5 * 0x28 + 0x10];
        local_43c = local_1a8[lVar5 * 0x28 + 0x11];
        local_438 = local_1a8[lVar5 * 0x28 + 0x12];
        local_434 = local_1a8[lVar5 * 0x28 + 0x13];
        local_408 = local_1a8[lVar5 * 0x28 + 0x14];
        iStack_404 = local_1a8[lVar5 * 0x28 + 0x15];
        iStack_400 = local_1a8[lVar5 * 0x28 + 0x16];
        iStack_3fc = local_1a8[lVar5 * 0x28 + 0x17];
        local_3f8 = local_1a8[lVar5 * 0x28 + 0x18];
        iStack_3f4 = local_1a8[lVar5 * 0x28 + 0x19];
        iStack_3f0 = local_1a8[lVar5 * 0x28 + 0x1a];
        local_3d0 = -local_1a8[lVar5 * 0x28 + 0x22];
        iStack_3cc = -local_1a8[lVar5 * 0x28 + 0x23];
        iStack_3c8 = -local_1a8[lVar5 * 0x28 + 0x24];
        iStack_3c4 = -local_1a8[lVar5 * 0x28 + 0x25];
        iStack_3ec = local_1a8[lVar5 * 0x28 + 0x1b];
        local_3e8 = CONCAT44(local_1a8[lVar5 * 0x28 + 0x1d],local_1a8[lVar5 * 0x28 + 0x1c]);
        local_3c0 = CONCAT44(-(int)((ulonglong)*(undefined8 *)(local_1a8 + lVar5 * 0x28 + 0x26) >>
                                   0x20),-(int)*(undefined8 *)(local_1a8 + lVar5 * 0x28 + 0x26));
        goto LAB_18000d339;
      }
    }
    else {
      piVar7 = local_1a8 + (longlong)(iVar2 / 2) * 0x28;
LAB_18000d339:
      FUN_18000efb0(&local_3b8,&local_3b8,piVar7);
    }
    if (iVar3 < 1) {
      if (iVar3 < 0) {
        piVar7 = &local_458;
        lVar5 = (longlong)-(iVar3 / 2) * 0x78;
        local_430 = *(int *)(&DAT_18002a060 + lVar5);
        local_42c = *(int *)(&DAT_18002a064 + lVar5);
        local_408 = -*(int *)(&DAT_18002a0b0 + lVar5);
        iStack_404 = -*(int *)(&UNK_18002a0b4 + lVar5);
        iStack_400 = -*(int *)(&UNK_18002a0b8 + lVar5);
        iStack_3fc = -*(int *)(&UNK_18002a0bc + lVar5);
        local_428 = *(int *)(&DAT_18002a068 + lVar5);
        local_424 = *(int *)(&DAT_18002a06c + lVar5);
        local_420 = *(int *)(&DAT_18002a070 + lVar5);
        local_41c = *(int *)(&DAT_18002a074 + lVar5);
        local_418 = *(int *)(&DAT_18002a078 + lVar5);
        local_414 = *(int *)(&DAT_18002a07c + lVar5);
        local_410 = *(int *)(&DAT_18002a080 + lVar5);
        local_40c = *(int *)(&DAT_18002a084 + lVar5);
        local_458 = *(int *)(&DAT_18002a088 + lVar5);
        local_454 = *(int *)(&DAT_18002a08c + lVar5);
        local_450 = *(int *)(&DAT_18002a090 + lVar5);
        local_44c = *(int *)(&DAT_18002a094 + lVar5);
        local_448 = *(int *)(&DAT_18002a098 + lVar5);
        local_444 = *(int *)(&DAT_18002a09c + lVar5);
        local_3f8 = -*(int *)(&DAT_18002a0c0 + lVar5);
        iStack_3f4 = -*(int *)(&UNK_18002a0c4 + lVar5);
        iStack_3f0 = -*(int *)(&UNK_18002a0c8 + lVar5);
        iStack_3ec = -*(int *)(&UNK_18002a0cc + lVar5);
        local_440 = *(int *)(&DAT_18002a0a0 + lVar5);
        local_43c = *(int *)(&DAT_18002a0a4 + lVar5);
        local_438 = *(int *)(&DAT_18002a0a8 + lVar5);
        local_434 = *(int *)(&DAT_18002a0ac + lVar5);
        local_3e8 = CONCAT44(-(int)((ulonglong)*(undefined8 *)(&DAT_18002a0d0 + lVar5) >> 0x20),
                             -(int)*(undefined8 *)(&DAT_18002a0d0 + lVar5));
        goto LAB_18000d45b;
      }
    }
    else {
      piVar7 = (int *)(&DAT_18002a060 + (longlong)(iVar3 / 2) * 0x78);
LAB_18000d45b:
      local_498 = local_1d8;
      FUN_18000fa30(&local_3b8,&local_3b8,piVar7,local_68);
    }
    uVar6 = uVar6 - 1;
    if ((int)uVar6 < 0) {
      FUN_18000f3b0(local_278,local_318);
      FUN_18000efb0(&local_3b8,&local_3b8,local_278);
      FUN_18000f4c0(&local_3b8,&local_3b8,local_318);
      FUN_18000f4c0(&local_3b8,&local_3b8,local_318);
      FUN_18000f4c0(&local_3b8,&local_3b8,local_318);
      FUN_18000fe50(local_1d8,&local_3b8);
      uVar8 = FUN_180010ca0(local_1c8,&DAT_18002a430);
      uVar4 = FUN_180010ca0(local_1d8,&DAT_18002a420);
      return ((uint)(((uVar8 | uVar4) >> 0x20 | (uVar8 | uVar4) & 0xffffffff) - 1 >> 0x20) & 1) - 1;
    }
  } while( true );
}



void FUN_18000d570(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_48 = *param_2;
  local_44 = param_2[1];
  local_40 = param_2[2];
  local_3c = param_2[3];
  local_38 = param_2[4];
  local_34 = param_2[5];
  local_30 = param_2[6];
  local_2c = param_2[7];
  local_28 = param_2[8];
  local_24 = param_2[9];
  local_20 = param_2[10];
  local_1c = param_2[0xb];
  local_18 = param_2[0xc];
  local_14 = param_2[0xd];
  local_10 = param_2[0xe];
  local_c = param_2[0xf];
  FUN_1800103d0(param_1,&local_48);
  puVar1 = &local_48;
  lVar2 = 0x40;
  do {
    *(undefined1 *)puVar1 = 0;
    puVar1 = (undefined4 *)((longlong)puVar1 + 1);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



void FUN_18000d7e0(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      *(undefined1 *)(uVar1 + param_1) = 0;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}



void FUN_18000d800(int *param_1,uint *param_2,byte param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  ulonglong uVar19;
  longlong lVar20;
  
  uVar12 = (ulonglong)*param_2;
  uVar8 = (ulonglong)*(uint3 *)((longlong)param_2 + 0xd) * 4 + 0x2000000;
  lVar13 = (ulonglong)(uint3)param_2[1] * 0x40 + (uVar12 + 0x2000000 >> 0x1a);
  lVar15 = (uVar8 >> 0x1a) + (ulonglong)param_2[4];
  lVar18 = (ulonglong)*(uint3 *)((longlong)param_2 + 7) * 0x20 + (lVar13 + 0x1000000U >> 0x19);
  uVar19 = lVar18 + 0x2000000;
  lVar16 = (ulonglong)(uint3)param_2[5] * 0x80 + (lVar15 + 0x1000000U >> 0x19);
  lVar5 = (uVar19 >> 0x1a) + (ulonglong)*(uint3 *)((longlong)param_2 + 10) * 8;
  uVar1 = lVar16 + 0x2000000;
  uVar2 = lVar5 + 0x1000000;
  lVar6 = ((uVar2 >> 0x19) - (uVar8 & 0xfffffffffc000000)) +
          (ulonglong)*(uint3 *)((longlong)param_2 + 0xd) * 4;
  lVar20 = (ulonglong)*(uint3 *)((longlong)param_2 + 0x17) * 0x20 + (uVar1 >> 0x1a);
  uVar8 = lVar20 + 0x1000000;
  lVar14 = (ulonglong)*(uint3 *)((longlong)param_2 + 0x1a) * 0x10 + (uVar8 >> 0x19);
  uVar3 = lVar14 + 0x2000000;
  lVar17 = (ulonglong)
           (((uint)*(uint3 *)((longlong)param_2 + 0x1d) & 0xffffff >> (param_3 & 0x1f)) << 2) +
           (uVar3 >> 0x1a);
  uVar4 = lVar17 + 0x1000000;
  lVar7 = ((uVar4 >> 0x19) * 0x13 - (uVar12 + 0x2000000 & 0xfffffffffc000000)) + uVar12;
  iVar11 = (int)(lVar7 + 0x2000000 >> 0x1a);
  param_1[3] = (int)lVar5 - ((uint)uVar2 & 0xfe000000);
  *param_1 = (int)lVar7 + iVar11 * -0x4000000;
  iVar10 = (int)lVar13;
  param_1[2] = (int)lVar18 - ((uint)uVar19 & 0xfc000000);
  iVar9 = (int)(lVar6 + 0x2000000 >> 0x1a);
  param_1[1] = (iVar11 - (iVar10 + 0x1000000U & 0xfe000000)) + iVar10;
  param_1[4] = (int)lVar6 + iVar9 * -0x4000000;
  param_1[7] = (int)lVar20 - ((uint)uVar8 & 0xfe000000);
  iVar10 = (int)lVar15;
  param_1[8] = (int)lVar14 - ((uint)uVar3 & 0xfc000000);
  param_1[5] = (iVar9 - (iVar10 + 0x1000000U & 0xfe000000)) + iVar10;
  param_1[6] = (int)lVar16 - ((uint)uVar1 & 0xfc000000);
  param_1[9] = (int)lVar17 - ((uint)uVar4 & 0xfe000000);
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

uint FUN_18000db40(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_78 [32];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_180030500 ^ (ulonglong)auStack_78;
  FUN_18000ed30(local_58,param_1);
  FUN_18000ed30(local_38,param_2);
  uVar1 = FUN_180010ca0(local_48,local_28);
  uVar2 = FUN_180010ca0(local_58,local_38);
  puVar3 = local_58;
  lVar4 = 0x20;
  lVar5 = 0x20;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  puVar3 = local_38;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return (uint)(((uVar1 | uVar2) >> 0x20 | (uVar1 | uVar2) & 0xffffffff) - 1 >> 0x20) & 1;
}



void FUN_18000dc00(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  int iVar22;
  longlong lVar23;
  longlong lVar24;
  longlong lVar25;
  longlong lVar26;
  longlong lVar27;
  longlong lVar28;
  longlong lVar29;
  longlong lVar30;
  longlong lVar31;
  longlong lVar32;
  longlong lVar33;
  longlong lVar34;
  longlong lVar35;
  longlong lVar36;
  longlong lVar37;
  longlong lVar38;
  longlong lVar39;
  longlong lVar40;
  longlong lVar41;
  longlong lVar42;
  longlong lVar43;
  
  iVar22 = param_3[8];
  iVar1 = param_3[6];
  lVar2 = (longlong)*param_2;
  lVar3 = (longlong)*param_3;
  lVar33 = (longlong)param_3[2];
  lVar34 = (longlong)param_3[3];
  lVar24 = (longlong)param_3[1];
  lVar32 = (longlong)param_3[4];
  lVar36 = (longlong)param_3[5];
  lVar4 = (longlong)param_2[8];
  lVar35 = (longlong)param_2[7];
  lVar41 = (longlong)param_2[5];
  lVar37 = (longlong)param_2[3];
  lVar29 = (longlong)param_2[1];
  lVar30 = (longlong)param_2[9];
  lVar25 = (longlong)(param_3[2] * 0x13);
  lVar5 = (longlong)(param_2[7] * 2);
  lVar31 = (longlong)(param_3[3] * 0x13);
  lVar6 = (longlong)param_2[2];
  lVar7 = (longlong)(iVar22 * 0x13);
  lVar8 = (longlong)param_2[4];
  lVar9 = (longlong)(iVar1 * 0x13);
  lVar10 = (longlong)param_2[6];
  lVar11 = (longlong)(param_3[4] * 0x13);
  lVar12 = (longlong)(param_2[5] * 2);
  lVar13 = (longlong)(param_3[5] * 0x13);
  lVar14 = (longlong)(param_2[3] * 2);
  lVar23 = (longlong)(param_3[7] * 0x13);
  lVar15 = (longlong)(param_2[1] * 2);
  lVar16 = (longlong)(param_3[9] * 0x13);
  lVar17 = (longlong)(param_2[9] * 2);
  lVar18 = lVar3 * lVar2 +
           (param_3[1] * 0x13) * lVar17 + lVar25 * lVar4 + lVar31 * lVar5 + lVar11 * lVar10 +
           lVar13 * lVar12 + lVar9 * lVar8 + lVar23 * lVar14 + lVar7 * lVar6 + lVar16 * lVar15;
  lVar19 = lVar8 * lVar3 +
           lVar24 * lVar14 + lVar33 * lVar6 + lVar34 * lVar15 + lVar32 * lVar2 + lVar17 * lVar13 +
           lVar4 * lVar9 + lVar5 * lVar23 + lVar10 * lVar7 + lVar12 * lVar16;
  lVar20 = lVar18 + 0x2000000 >> 0x1a;
  lVar26 = lVar19 + 0x2000000 >> 0x1a;
  lVar25 = lVar35 * lVar11 + lVar30 * lVar25 + lVar24 * lVar2 + lVar41 * lVar9 + lVar4 * lVar31 +
           lVar10 * lVar13 + lVar8 * lVar23 + lVar37 * lVar7 + lVar29 * lVar3 + lVar20 +
           lVar6 * lVar16;
  lVar21 = lVar41 * lVar3 + lVar26 +
           lVar33 * lVar37 + lVar32 * lVar29 + lVar24 * lVar8 + lVar36 * lVar2 + lVar34 * lVar6 +
           lVar30 * lVar9 + lVar4 * lVar23 + lVar35 * lVar7 + lVar10 * lVar16;
  lVar27 = lVar25 + 0x1000000 >> 0x19;
  lVar31 = lVar27 + lVar14 * lVar16 +
           lVar24 * lVar15 + lVar33 * lVar2 + lVar17 * lVar31 + lVar4 * lVar11 + lVar5 * lVar13 +
           lVar10 * lVar9 + lVar12 * lVar23 + lVar8 * lVar7 + lVar6 * lVar3;
  lVar38 = lVar21 + 0x1000000 >> 0x19;
  lVar42 = lVar38 + lVar5 * lVar16 +
           lVar24 * lVar12 + lVar33 * lVar8 + lVar34 * lVar14 + iVar1 * lVar2 + lVar36 * lVar15 +
           lVar32 * lVar6 + lVar17 * lVar23 + lVar4 * lVar7 + lVar10 * lVar3;
  lVar28 = lVar31 + 0x2000000 >> 0x1a;
  lVar39 = lVar8 * lVar16 +
           lVar37 * lVar3 + lVar28 +
           lVar33 * lVar29 + lVar30 * lVar11 + lVar24 * lVar6 + lVar35 * lVar9 + lVar34 * lVar2 +
           lVar4 * lVar13 + lVar10 * lVar23 + lVar41 * lVar7;
  lVar43 = (longlong)param_3[7];
  lVar9 = lVar42 + 0x2000000 >> 0x1a;
  lVar23 = lVar35 * lVar3 + lVar9 +
           iVar1 * lVar29 + lVar33 * lVar41 + lVar32 * lVar37 + lVar24 * lVar10 + lVar43 * lVar2 +
           lVar34 * lVar8 + lVar36 * lVar6 + lVar30 * lVar7 + lVar4 * lVar16;
  lVar13 = lVar23 + 0x1000000 >> 0x19;
  lVar40 = lVar39 + 0x1000000 >> 0x19;
  lVar7 = lVar19 + lVar26 * -0x4000000 + lVar40;
  lVar5 = lVar17 * lVar16 + lVar13 +
          iVar22 * lVar2 + lVar24 * lVar5 + lVar36 * lVar14 + lVar43 * lVar15 + lVar33 * lVar10 +
          lVar34 * lVar12 + lVar32 * lVar8 + iVar1 * lVar6 + lVar4 * lVar3;
  lVar11 = lVar5 + 0x2000000 >> 0x1a;
  lVar4 = lVar34 * lVar10 + lVar11 +
          param_3[9] * lVar2 + iVar22 * lVar29 + iVar1 * lVar37 + lVar33 * lVar35 + lVar32 * lVar41
          + lVar24 * lVar4 + lVar36 * lVar8 + lVar43 * lVar6 + lVar30 * lVar3;
  param_1[7] = (int)lVar23 + (int)lVar13 * -0x2000000;
  lVar3 = lVar4 + 0x1000000 >> 0x19;
  lVar2 = lVar18 + lVar20 * -0x4000000 + lVar3 * 0x13;
  iVar22 = (int)(lVar2 + 0x2000000 >> 0x1a);
  *param_1 = (int)lVar2 + iVar22 * -0x4000000;
  param_1[1] = iVar22 + (int)lVar25 + (int)lVar27 * -0x2000000;
  param_1[2] = (int)lVar31 + (int)lVar28 * -0x4000000;
  param_1[3] = (int)lVar39 + (int)lVar40 * -0x2000000;
  iVar22 = (int)(lVar7 + 0x2000000 >> 0x1a);
  param_1[4] = (int)lVar7 + iVar22 * -0x4000000;
  param_1[5] = iVar22 + (int)lVar21 + (int)lVar38 * -0x2000000;
  param_1[6] = (int)lVar42 + (int)lVar9 * -0x4000000;
  param_1[8] = (int)lVar5 + (int)lVar11 * -0x4000000;
  param_1[9] = (int)lVar4 + (int)lVar3 * -0x2000000;
  return;
}



void FUN_18000e5a0(int *param_1,int *param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong lVar20;
  
  lVar3 = (longlong)param_3;
  lVar1 = param_2[4] * lVar3 + 0x2000000 >> 0x1a;
  lVar8 = param_2[5] * lVar3 + lVar1;
  lVar18 = *param_2 * lVar3 + 0x2000000 >> 0x1a;
  lVar19 = param_2[1] * lVar3 + lVar18;
  lVar9 = lVar8 + 0x1000000 >> 0x19;
  lVar10 = lVar9 + param_2[6] * lVar3;
  lVar11 = lVar10 + 0x2000000 >> 0x1a;
  lVar15 = param_2[7] * lVar3 + lVar11;
  lVar20 = lVar19 + 0x1000000 >> 0x19;
  lVar13 = param_2[2] * lVar3 + lVar20;
  lVar16 = lVar15 + 0x1000000 >> 0x19;
  lVar17 = param_2[8] * lVar3 + lVar16;
  lVar14 = lVar13 + 0x2000000 >> 0x1a;
  lVar7 = param_2[3] * lVar3 + lVar14;
  lVar6 = lVar17 + 0x2000000 >> 0x1a;
  lVar5 = param_2[9] * lVar3 + lVar6;
  lVar12 = lVar7 + 0x1000000 >> 0x19;
  lVar4 = lVar5 + 0x1000000 >> 0x19;
  lVar1 = lVar12 + param_2[4] * lVar3 + lVar1 * -0x4000000;
  lVar3 = *param_2 * lVar3 + lVar18 * -0x4000000 + lVar4 * 0x13;
  iVar2 = (int)(lVar3 + 0x2000000 >> 0x1a);
  *param_1 = (int)lVar3 + iVar2 * -0x4000000;
  param_1[1] = (int)lVar19 + (int)lVar20 * -0x2000000 + iVar2;
  param_1[2] = (int)lVar13 + (int)lVar14 * -0x4000000;
  iVar2 = (int)(lVar1 + 0x2000000 >> 0x1a);
  param_1[3] = (int)lVar7 + (int)lVar12 * -0x2000000;
  param_1[4] = (int)lVar1 + iVar2 * -0x4000000;
  param_1[5] = iVar2 + (int)lVar8 + (int)lVar9 * -0x2000000;
  param_1[8] = (int)lVar17 + (int)lVar6 * -0x4000000;
  param_1[6] = (int)lVar10 + (int)lVar11 * -0x4000000;
  param_1[7] = (int)lVar15 + (int)lVar16 * -0x2000000;
  param_1[9] = (int)lVar5 + (int)lVar4 * -0x2000000;
  return;
}



void FUN_18000e7b0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  int iVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  longlong lVar22;
  longlong lVar23;
  longlong lVar24;
  longlong lVar25;
  longlong lVar26;
  longlong lVar27;
  longlong lVar28;
  longlong lVar29;
  longlong lVar30;
  longlong lVar31;
  longlong lVar32;
  longlong lVar33;
  
  iVar15 = param_2[9];
  lVar22 = (longlong)param_2[2];
  iVar1 = param_2[5];
  lVar26 = (longlong)iVar1;
  iVar2 = param_2[7];
  lVar18 = (longlong)iVar2;
  iVar3 = param_2[1];
  lVar21 = (longlong)param_2[4];
  iVar4 = param_2[6];
  lVar19 = (longlong)iVar4;
  lVar29 = (longlong)param_2[8];
  lVar31 = (longlong)param_2[3];
  iVar5 = *param_2;
  lVar6 = (longlong)(iVar3 * 2);
  lVar7 = (longlong)(iVar15 * 0x26);
  lVar8 = (longlong)(param_2[2] * 2);
  lVar9 = (longlong)(param_2[8] * 0x13);
  lVar10 = (longlong)(param_2[3] * 2);
  lVar30 = (longlong)(iVar2 * 0x26);
  lVar32 = (longlong)(param_2[4] * 2);
  lVar17 = (longlong)(iVar4 * 0x13);
  lVar11 = lVar7 * lVar6 +
           (iVar1 * 0x26) * lVar26 + lVar17 * lVar32 + lVar30 * lVar10 + lVar9 * lVar8 +
           (longlong)iVar5 * (longlong)iVar5;
  lVar27 = (longlong)(iVar5 * 2);
  lVar23 = (longlong)(iVar1 * 2);
  lVar28 = lVar27 * lVar21 + (iVar4 * 2) * lVar9 + lVar22 * lVar22 + lVar18 * lVar30 +
           lVar23 * lVar7 + lVar10 * lVar6;
  lVar12 = lVar11 + 0x2000000 >> 0x1a;
  lVar16 = lVar28 + 0x2000000 >> 0x1a;
  lVar13 = lVar23 * lVar17 + lVar27 * iVar3 + lVar21 * lVar30 + lVar22 * lVar7 + lVar12 +
           lVar10 * lVar9;
  lVar20 = (longlong)(iVar2 * 2);
  lVar14 = lVar16 + lVar27 * lVar26 + lVar20 * lVar9 + lVar31 * lVar8 + lVar19 * lVar7 +
           lVar21 * lVar6;
  lVar24 = lVar13 + 0x1000000 >> 0x19;
  lVar17 = lVar24 + iVar3 * lVar6 +
           lVar22 * lVar27 + lVar19 * lVar17 + lVar23 * lVar30 + lVar32 * lVar9 + lVar10 * lVar7;
  lVar33 = lVar14 + 0x1000000 >> 0x19;
  lVar25 = lVar23 * lVar6 + lVar33 +
           lVar19 * lVar27 + lVar29 * lVar9 + lVar31 * lVar10 + lVar20 * lVar7 + lVar21 * lVar8;
  lVar32 = lVar17 + 0x2000000 >> 0x1a;
  lVar30 = lVar22 * lVar6 + lVar32 + lVar31 * lVar27 + lVar19 * lVar30 + lVar23 * lVar9 +
           lVar21 * lVar7;
  lVar22 = lVar25 + 0x2000000 >> 0x1a;
  lVar31 = lVar30 + 0x1000000 >> 0x19;
  lVar16 = lVar28 + lVar16 * -0x4000000 + lVar31;
  lVar26 = lVar22 + lVar21 * lVar10 + lVar18 * lVar27 + lVar29 * lVar7 + lVar19 * lVar6 +
           lVar26 * lVar8;
  lVar9 = lVar26 + 0x1000000 >> 0x19;
  lVar20 = lVar20 * lVar6 + lVar9 +
           lVar29 * lVar27 + lVar21 * lVar21 + iVar15 * lVar7 + lVar19 * lVar8 + lVar23 * lVar10;
  lVar7 = lVar20 + 0x2000000 >> 0x1a;
  lVar10 = lVar18 * lVar8 +
           lVar19 * lVar10 + lVar7 + iVar15 * lVar27 + lVar23 * lVar21 + lVar29 * lVar6;
  param_1[3] = (int)lVar30 + (int)lVar31 * -0x2000000;
  lVar8 = lVar10 + 0x1000000 >> 0x19;
  lVar6 = lVar11 + lVar12 * -0x4000000 + lVar8 * 0x13;
  param_1[7] = (int)lVar26 + (int)lVar9 * -0x2000000;
  param_1[8] = (int)lVar20 + (int)lVar7 * -0x4000000;
  iVar15 = (int)(lVar6 + 0x2000000 >> 0x1a);
  *param_1 = (int)lVar6 + iVar15 * -0x4000000;
  param_1[1] = iVar15 + (int)lVar13 + (int)lVar24 * -0x2000000;
  iVar15 = (int)(lVar16 + 0x2000000 >> 0x1a);
  param_1[2] = (int)lVar17 + (int)lVar32 * -0x4000000;
  param_1[4] = (int)lVar16 + iVar15 * -0x4000000;
  param_1[5] = iVar15 + (int)lVar14 + (int)lVar33 * -0x2000000;
  param_1[6] = (int)lVar25 + (int)lVar22 * -0x4000000;
  param_1[9] = (int)lVar10 + (int)lVar8 * -0x2000000;
  return;
}



void FUN_18000ed30(undefined1 *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined1 local_78 [56];
  
  puVar4 = local_78;
  iVar3 = param_2[9];
  iVar7 = param_2[8];
  uVar9 = (((((((((((iVar3 * 0x13 + 0x1000000 >> 0x19) + *param_2 >> 0x1a) + param_2[1] >> 0x19) +
                  param_2[2] >> 0x1a) + param_2[3] >> 0x19) + param_2[4] >> 0x1a) + param_2[5] >>
              0x19) + param_2[6] >> 0x1a) + param_2[7] >> 0x19) + iVar7 >> 0x1a) + iVar3 >> 0x19) *
          0x13 + *param_2;
  uVar10 = uVar9 & 0x3ffffff;
  uVar5 = ((int)uVar9 >> 0x1a) + param_2[1];
  uVar9 = param_2[2] + ((int)uVar5 >> 0x19);
  uVar13 = param_2[3] + ((int)uVar9 >> 0x1a);
  iVar12 = ((int)uVar13 >> 0x19) + param_2[4];
  uVar11 = (iVar12 >> 0x1a) + param_2[5];
  uVar6 = ((int)uVar11 >> 0x19) + param_2[6];
  uVar1 = param_2[7] + ((int)uVar6 >> 0x1a);
  *param_1 = (char)uVar10;
  uVar2 = iVar7 + ((int)uVar1 >> 0x19);
  param_1[1] = (char)(uVar10 >> 8);
  param_1[3] = (byte)(uVar5 * 0x4000000 >> 0x18) | (byte)(uVar10 >> 0x18);
  param_1[2] = (char)(uVar10 >> 0x10);
  uVar5 = (uVar5 & 0x1ffffff) >> 6;
  uVar11 = uVar11 & 0x1ffffff;
  uVar10 = (uVar9 & 0x3ffffff) >> 0xd;
  param_1[4] = (char)uVar5;
  param_1[5] = (char)(uVar5 >> 8);
  param_1[6] = (byte)(uVar9 * 0x80000 >> 0x10) | (byte)(uVar5 >> 0x10);
  param_1[7] = (char)(uVar9 * 0x80000 >> 0x18);
  iVar7 = uVar13 * 0x2000;
  iVar12 = iVar12 * 0x40;
  param_1[8] = (char)uVar10;
  param_1[9] = (byte)((uint)iVar7 >> 8) | (byte)(uVar10 >> 8);
  param_1[10] = (char)((uint)iVar7 >> 0x10);
  param_1[0xd] = (char)((uint)iVar12 >> 8);
  param_1[0xe] = (char)((uint)iVar12 >> 0x10);
  param_1[0xb] = (char)((uint)iVar7 >> 0x18);
  uVar5 = (uVar6 & 0x3ffffff) >> 7;
  param_1[0x10] = (char)uVar11;
  param_1[0x11] = (char)(uVar11 >> 8);
  param_1[0x12] = (char)(uVar11 >> 0x10);
  param_1[0x13] = (byte)(uVar6 * 0x2000000 >> 0x18) | (byte)(uVar11 >> 0x18);
  uVar9 = (uVar1 & 0x1ffffff) >> 0xd;
  param_1[0x14] = (char)uVar5;
  param_1[0x15] = (char)(uVar5 >> 8);
  param_1[0x16] = (byte)(uVar1 * 0x80000 >> 0x10) | (byte)(uVar5 >> 0x10);
  param_1[0x17] = (char)(uVar1 * 0x80000 >> 0x18);
  iVar7 = uVar2 * 0x1000;
  param_1[0xc] = (byte)(uVar13 >> 0x13) & 0x3f ^ (byte)iVar12;
  param_1[0x19] = (byte)((uint)iVar7 >> 8) | (byte)(uVar9 >> 8);
  param_1[0x1a] = (char)((uint)iVar7 >> 0x10);
  param_1[0x18] = (char)uVar9;
  iVar3 = (iVar3 + ((int)uVar2 >> 0x1a) & 0x1ffffffU) << 6;
  param_1[0xf] = (char)((uint)iVar12 >> 0x18);
  param_1[0x1b] = (char)((uint)iVar7 >> 0x18);
  lVar8 = 0x28;
  param_1[0x1c] = (byte)((uVar2 & 0x3ffffff) >> 0x14) | (byte)iVar3;
  param_1[0x1d] = (char)((uint)iVar3 >> 8);
  param_1[0x1e] = (char)((uint)iVar3 >> 0x10);
  param_1[0x1f] = (char)((uint)iVar3 >> 0x18);
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  return;
}



void FUN_18000efb0(int *param_1,int *param_2,longlong param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int *local_50;
  int *local_48;
  
  local_80 = *param_2 + param_2[10];
  local_7c = param_2[1] + param_2[0xb];
  local_78 = param_2[0xc] + param_2[2];
  local_74 = param_2[0xd] + param_2[3];
  local_70 = param_2[0xe] + param_2[4];
  local_6c = param_2[0xf] + param_2[5];
  local_94 = param_2[0xf] - param_2[5];
  local_68 = param_2[0x10] + param_2[6];
  local_90 = param_2[0x10] - param_2[6];
  local_64 = param_2[0x11] + param_2[7];
  local_8c = param_2[0x11] - param_2[7];
  local_60 = param_2[0x12] + param_2[8];
  local_88 = param_2[0x12] - param_2[8];
  local_5c = param_2[0x13] + param_2[9];
  local_84 = param_2[0x13] - param_2[9];
  local_a8 = param_2[10] - *param_2;
  local_a4 = param_2[0xb] - param_2[1];
  local_a0 = param_2[0xc] - param_2[2];
  local_9c = param_2[0xd] - param_2[3];
  local_98 = param_2[0xe] - param_2[4];
  local_58 = param_2;
  local_50 = (int *)param_3;
  FUN_18000dc00(&local_80,&local_80,param_3);
  FUN_18000dc00(&local_a8,&local_a8,param_3 + 0x28);
  piVar6 = local_50;
  piVar5 = local_58;
  param_1[10] = local_a8 + local_80;
  param_1[0xb] = local_a4 + local_7c;
  param_1[0xc] = local_a0 + local_78;
  param_1[0xd] = local_74 + local_9c;
  param_1[0xe] = local_98 + local_70;
  param_1[0xf] = local_94 + local_6c;
  param_1[0x10] = local_90 + local_68;
  param_1[0x11] = local_8c + local_64;
  param_1[0x12] = local_88 + local_60;
  param_1[0x13] = local_84 + local_5c;
  *param_1 = local_80 - local_a8;
  param_1[1] = local_7c - local_a4;
  param_1[2] = local_78 - local_a0;
  param_1[3] = local_74 - local_9c;
  param_1[6] = local_68 - local_90;
  piVar1 = param_1 + 0x14;
  param_1[4] = local_70 - local_98;
  param_1[5] = local_6c - local_94;
  param_1[7] = local_64 - local_8c;
  param_1[8] = local_60 - local_88;
  param_1[9] = local_5c - local_84;
  *piVar1 = local_58[0x14] * 2;
  param_1[0x15] = local_58[0x15] * 2;
  param_1[0x16] = local_58[0x16] * 2;
  param_1[0x17] = local_58[0x17] * 2;
  param_1[0x18] = local_58[0x18] * 2;
  param_1[0x19] = local_58[0x19] * 2;
  param_1[0x1a] = local_58[0x1a] * 2;
  param_1[0x1b] = local_58[0x1b] * 2;
  param_1[0x1c] = local_58[0x1c] * 2;
  param_1[0x1d] = local_58[0x1d] * 2;
  local_48 = piVar1;
  FUN_18000dc00(piVar1,piVar1,(longlong)local_50 + 0x50);
  piVar2 = param_1 + 0x1e;
  local_50 = piVar2;
  FUN_18000dc00(piVar2,piVar5 + 0x1e,(longlong)piVar6 + 0x78);
  local_80 = *piVar2 + *piVar1;
  local_7c = param_1[0x1f] + param_1[0x15];
  iVar3 = param_1[0x26];
  local_78 = param_1[0x20] + param_1[0x16];
  iVar4 = param_1[0x21];
  local_98 = param_1[0x22];
  local_74 = param_1[0x17] + iVar4;
  local_58 = (int *)CONCAT44(local_58._4_4_,local_98);
  local_70 = local_98 + param_1[0x18];
  local_6c = param_1[0x23] + param_1[0x19];
  local_68 = param_1[0x24] + param_1[0x1a];
  local_64 = param_1[0x25] + param_1[0x1b];
  local_60 = iVar3 + param_1[0x1c];
  local_5c = param_1[0x27] + param_1[0x1d];
  local_a8 = *local_48 - *local_50;
  local_a4 = param_1[0x15] - param_1[0x1f];
  local_a0 = param_1[0x16] - param_1[0x20];
  local_9c = param_1[0x17] - iVar4;
  local_98 = param_1[0x18] - local_98;
  local_84 = param_1[0x1d] - param_1[0x27];
  local_90 = param_1[0x1a] - param_1[0x24];
  local_8c = param_1[0x1b] - param_1[0x25];
  local_88 = param_1[0x1c] - iVar3;
  local_94 = param_1[0x19] - param_1[0x23];
  FUN_18000dc00(local_50,param_1,param_1 + 10,iVar3,iVar4);
  FUN_18000dc00(param_1,param_1,&local_a8);
  FUN_18000dc00(param_1 + 10,param_1 + 10,&local_80);
  FUN_18000dc00(local_48,&local_80,&local_a8);
  return;
}



void FUN_18000f3b0(int *param_1,int *param_2)

{
  *param_1 = param_2[10] + *param_2;
  param_1[1] = param_2[0xb] + param_2[1];
  param_1[2] = param_2[0xc] + param_2[2];
  param_1[3] = param_2[0xd] + param_2[3];
  param_1[4] = param_2[0xe] + param_2[4];
  param_1[5] = param_2[0xf] + param_2[5];
  param_1[6] = param_2[0x10] + param_2[6];
  param_1[7] = param_2[0x11] + param_2[7];
  param_1[8] = param_2[0x12] + param_2[8];
  param_1[9] = param_2[0x13] + param_2[9];
  param_1[10] = param_2[10] - *param_2;
  param_1[0xb] = param_2[0xb] - param_2[1];
  param_1[0xc] = param_2[0xc] - param_2[2];
  param_1[0xd] = param_2[0xd] - param_2[3];
  param_1[0xe] = param_2[0xe] - param_2[4];
  param_1[0xf] = param_2[0xf] - param_2[5];
  param_1[0x10] = param_2[0x10] - param_2[6];
  param_1[0x11] = param_2[0x11] - param_2[7];
  param_1[0x12] = param_2[0x12] - param_2[8];
  param_1[0x13] = param_2[0x13] - param_2[9];
  param_1[0x14] = param_2[0x14];
  param_1[0x15] = param_2[0x15];
  param_1[0x16] = param_2[0x16];
  param_1[0x17] = param_2[0x17];
  param_1[0x18] = param_2[0x18];
  param_1[0x19] = param_2[0x19];
  param_1[0x1a] = param_2[0x1a];
  param_1[0x1b] = param_2[0x1b];
  param_1[0x1c] = param_2[0x1c];
  param_1[0x1d] = param_2[0x1d];
  FUN_18000dc00(param_1 + 0x1e,param_2 + 0x1e,&DAT_180029f58);
  return;
}



void FUN_18000f4c0(longlong param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  
  FUN_18000e7b0(param_3);
  FUN_18000e7b0(param_3 + 10,param_2 + 10);
  FUN_18000e7b0(param_3 + 0x14,param_2 + 0x14);
  FUN_18000e5a0(param_3 + 0x14,param_3 + 0x14,2);
  param_3[0x1e] = param_2[10] + *param_2;
  param_3[0x1f] = param_2[0xb] + param_2[1];
  param_3[0x20] = param_2[0xc] + param_2[2];
  param_3[0x21] = param_2[0xd] + param_2[3];
  param_3[0x22] = param_2[0xe] + param_2[4];
  param_3[0x23] = param_2[0xf] + param_2[5];
  param_3[0x24] = param_2[0x10] + param_2[6];
  param_3[0x25] = param_2[0x11] + param_2[7];
  param_3[0x26] = param_2[0x12] + param_2[8];
  param_3[0x27] = param_2[0x13] + param_2[9];
  FUN_18000e7b0(param_1 + 0x78,param_3 + 0x1e);
  iVar14 = param_3[10] + *param_3;
  param_3[0x1e] = iVar14;
  iVar1 = param_3[0xb] + param_3[1];
  param_3[0x1f] = iVar1;
  iVar2 = param_3[0xc] + param_3[2];
  param_3[0x20] = iVar2;
  iVar3 = param_3[0xd] + param_3[3];
  param_3[0x21] = iVar3;
  iVar20 = param_3[0xe] + param_3[4];
  param_3[0x22] = iVar20;
  iVar8 = param_3[10] - *param_3;
  iVar4 = param_3[0xf] + param_3[5];
  param_3[0x23] = iVar4;
  iVar5 = param_3[0x10] + param_3[6];
  param_3[0x24] = iVar5;
  iVar6 = param_3[0x11] + param_3[7];
  param_3[0x25] = iVar6;
  iVar7 = param_3[0x12] + param_3[8];
  param_3[0x26] = iVar7;
  iVar17 = param_3[0x13] + param_3[9];
  param_3[0x27] = iVar17;
  param_3[10] = iVar8;
  iVar9 = param_3[0xb] - param_3[1];
  param_3[0xb] = iVar9;
  iVar10 = param_3[0xc] - param_3[2];
  param_3[0xc] = iVar10;
  iVar16 = param_3[0x12] - param_3[8];
  iVar11 = param_3[0xd] - param_3[3];
  param_3[0xd] = iVar11;
  iVar18 = param_3[0x11] - param_3[7];
  iVar12 = param_3[0xe] - param_3[4];
  param_3[0xe] = iVar12;
  iVar19 = param_3[0x10] - param_3[6];
  iVar15 = param_3[0x13] - param_3[9];
  iVar13 = param_3[0xf] - param_3[5];
  param_3[0xf] = iVar13;
  param_3[0x10] = iVar19;
  param_3[0x11] = iVar18;
  param_3[0x12] = iVar16;
  param_3[0x13] = iVar15;
  *param_3 = *(int *)(param_1 + 0x78) - iVar14;
  param_3[1] = *(int *)(param_1 + 0x7c) - iVar1;
  param_3[2] = *(int *)(param_1 + 0x80) - iVar2;
  param_3[3] = *(int *)(param_1 + 0x84) - iVar3;
  param_3[4] = *(int *)(param_1 + 0x88) - iVar20;
  param_3[5] = *(int *)(param_1 + 0x8c) - iVar4;
  param_3[6] = *(int *)(param_1 + 0x90) - iVar5;
  param_3[7] = *(int *)(param_1 + 0x94) - iVar6;
  param_3[8] = *(int *)(param_1 + 0x98) - iVar7;
  param_3[9] = *(int *)(param_1 + 0x9c) - iVar17;
  param_3[0x14] = param_3[0x14] - iVar8;
  param_3[0x15] = param_3[0x15] - iVar9;
  param_3[0x16] = param_3[0x16] - iVar10;
  param_3[0x17] = param_3[0x17] - iVar11;
  param_3[0x18] = param_3[0x18] - iVar12;
  param_3[0x19] = param_3[0x19] - iVar13;
  param_3[0x1a] = param_3[0x1a] - iVar19;
  param_3[0x1b] = param_3[0x1b] - iVar18;
  param_3[0x1c] = param_3[0x1c] - iVar16;
  param_3[0x1d] = param_3[0x1d] - iVar15;
  FUN_18000dc00(param_1,param_3,param_3 + 0x14);
  FUN_18000dc00(param_1 + 0x28,param_3 + 0x1e,param_3 + 10);
  FUN_18000dc00(param_1 + 0x50,param_3 + 10,param_3 + 0x14);
  FUN_18000dc00(param_1 + 0x78,param_3,param_3 + 0x1e);
  return;
}



undefined8 FUN_18000f870(int *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte *pbVar3;
  longlong lVar4;
  byte local_48 [32];
  
  FUN_18000d800(param_1 + 10,param_2,1);
  param_1[0x14] = 1;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  FUN_18000e7b0(param_1 + 0x1e,param_1 + 10);
  FUN_18000dc00(param_1,param_1 + 0x1e,&DAT_180029f30);
  param_1[0x1e] = param_1[0x1e] - param_1[0x14];
  param_1[0x1f] = param_1[0x1f] - param_1[0x15];
  param_1[0x20] = param_1[0x20] - param_1[0x16];
  param_1[0x21] = param_1[0x21] - param_1[0x17];
  param_1[0x22] = param_1[0x22] - param_1[0x18];
  param_1[0x23] = param_1[0x23] - param_1[0x19];
  param_1[0x24] = param_1[0x24] - param_1[0x1a];
  param_1[0x25] = param_1[0x25] - param_1[0x1b];
  param_1[0x26] = param_1[0x26] - param_1[0x1c];
  param_1[0x27] = param_1[0x27] - param_1[0x1d];
  param_1[6] = param_1[6] + param_1[0x1a];
  param_1[7] = param_1[7] + param_1[0x1b];
  param_1[8] = param_1[8] + param_1[0x1c];
  *param_1 = *param_1 + param_1[0x14];
  param_1[1] = param_1[1] + param_1[0x15];
  param_1[2] = param_1[2] + param_1[0x16];
  param_1[3] = param_1[3] + param_1[0x17];
  param_1[4] = param_1[4] + param_1[0x18];
  param_1[5] = param_1[5] + param_1[0x19];
  param_1[9] = param_1[9] + param_1[0x1d];
  FUN_18000dc00(param_1,param_1 + 0x1e,param_1);
  iVar1 = FUN_18000ff90(param_1,param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_18000dc00(param_1,param_1 + 0x1e,param_1);
    FUN_18000ed30(local_48,param_1);
    pbVar3 = local_48;
    lVar4 = 0x20;
    do {
      *pbVar3 = 0;
      pbVar3 = pbVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if ((byte)(local_48[0] & 1) == (byte)-(*(char *)(param_2 + 0x1f) >> 7)) {
      *param_1 = -*param_1;
      param_1[1] = -param_1[1];
      param_1[2] = -param_1[2];
      param_1[3] = -param_1[3];
      *(ulonglong *)(param_1 + 8) =
           CONCAT44(-(int)((ulonglong)*(undefined8 *)(param_1 + 8) >> 0x20),
                    -(int)*(undefined8 *)(param_1 + 8));
      param_1[4] = -param_1[4];
      param_1[5] = -param_1[5];
      param_1[6] = -param_1[6];
      param_1[7] = -param_1[7];
    }
    FUN_18000dc00(param_1 + 0x1e,param_1,param_1 + 10);
    uVar2 = 0;
  }
  return uVar2;
}



void FUN_18000fa30(int *param_1,int *param_2,longlong param_3,int *param_4,int *param_5)

{
  *param_4 = param_2[10] + *param_2;
  param_4[1] = param_2[0xb] + param_2[1];
  param_4[2] = param_2[0xc] + param_2[2];
  param_4[3] = param_2[0xd] + param_2[3];
  param_4[4] = param_2[0xe] + param_2[4];
  param_4[5] = param_2[0xf] + param_2[5];
  param_4[6] = param_2[0x10] + param_2[6];
  param_4[7] = param_2[0x11] + param_2[7];
  param_4[8] = param_2[0x12] + param_2[8];
  param_4[9] = param_2[0x13] + param_2[9];
  *param_5 = param_2[10] - *param_2;
  param_5[1] = param_2[0xb] - param_2[1];
  param_5[2] = param_2[0xc] - param_2[2];
  param_5[3] = param_2[0xd] - param_2[3];
  param_5[4] = param_2[0xe] - param_2[4];
  param_5[5] = param_2[0xf] - param_2[5];
  param_5[6] = param_2[0x10] - param_2[6];
  param_5[7] = param_2[0x11] - param_2[7];
  param_5[8] = param_2[0x12] - param_2[8];
  param_5[9] = param_2[0x13] - param_2[9];
  FUN_18000dc00(param_4,param_4);
  FUN_18000dc00(param_5,param_5,param_3 + 0x28);
  param_1[10] = *param_4 + *param_5;
  param_1[0xb] = param_4[1] + param_5[1];
  param_1[0xc] = param_4[2] + param_5[2];
  param_1[0xd] = param_4[3] + param_5[3];
  param_1[0xe] = param_4[4] + param_5[4];
  param_1[0xf] = param_4[5] + param_5[5];
  param_1[0x10] = param_4[6] + param_5[6];
  param_1[0x11] = param_4[7] + param_5[7];
  param_1[0x12] = param_4[8] + param_5[8];
  param_1[0x13] = param_4[9] + param_5[9];
  *param_1 = *param_4 - *param_5;
  param_1[1] = param_4[1] - param_5[1];
  param_1[2] = param_4[2] - param_5[2];
  param_1[3] = param_4[3] - param_5[3];
  param_1[4] = param_4[4] - param_5[4];
  param_1[5] = param_4[5] - param_5[5];
  param_1[6] = param_4[6] - param_5[6];
  param_1[7] = param_4[7] - param_5[7];
  param_1[8] = param_4[8] - param_5[8];
  param_1[9] = param_4[9] - param_5[9];
  param_1[0x14] = param_2[0x14] * 2;
  param_1[0x15] = param_2[0x15] * 2;
  param_1[0x16] = param_2[0x16] * 2;
  param_1[0x17] = param_2[0x17] * 2;
  param_1[0x18] = param_2[0x18] * 2;
  param_1[0x19] = param_2[0x19] * 2;
  param_1[0x1a] = param_2[0x1a] * 2;
  param_1[0x1b] = param_2[0x1b] * 2;
  param_1[0x1c] = param_2[0x1c] * 2;
  param_1[0x1d] = param_2[0x1d] * 2;
  FUN_18000dc00(param_1 + 0x1e,param_2 + 0x1e,param_3 + 0x50);
  *param_4 = param_1[0x1e] + param_1[0x14];
  param_4[1] = param_1[0x1f] + param_1[0x15];
  param_4[2] = param_1[0x20] + param_1[0x16];
  param_4[3] = param_1[0x21] + param_1[0x17];
  param_4[4] = param_1[0x22] + param_1[0x18];
  param_4[5] = param_1[0x23] + param_1[0x19];
  param_4[6] = param_1[0x24] + param_1[0x1a];
  param_4[7] = param_1[0x25] + param_1[0x1b];
  param_4[8] = param_1[0x26] + param_1[0x1c];
  param_4[9] = param_1[0x27] + param_1[0x1d];
  *param_5 = param_1[0x14] - param_1[0x1e];
  param_5[1] = param_1[0x15] - param_1[0x1f];
  param_5[2] = param_1[0x16] - param_1[0x20];
  param_5[3] = param_1[0x17] - param_1[0x21];
  param_5[4] = param_1[0x18] - param_1[0x22];
  param_5[5] = param_1[0x19] - param_1[0x23];
  param_5[6] = param_1[0x1a] - param_1[0x24];
  param_5[7] = param_1[0x1b] - param_1[0x25];
  param_5[8] = param_1[0x1c] - param_1[0x26];
  param_5[9] = param_1[0x1d] - param_1[0x27];
  FUN_18000dc00(param_1 + 0x1e,param_1,param_1 + 10);
  FUN_18000dc00(param_1,param_1,param_5);
  FUN_18000dc00(param_1 + 10,param_1 + 10,param_4);
  FUN_18000dc00(param_1 + 0x14,param_4,param_5);
  return;
}



void FUN_18000fe50(longlong param_1,longlong param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char local_88 [40];
  undefined1 local_60 [40];
  undefined1 local_38 [48];
  
  FUN_18000e7b0(local_88,param_2 + 0x50);
  FUN_18000ff90(local_88,local_88);
  FUN_18000e7b0(local_88,local_88);
  FUN_18000dc00(local_60,local_88,param_2 + 0x50);
  lVar4 = 0x28;
  pcVar2 = local_88;
  lVar3 = 0x28;
  do {
    *pcVar2 = '\0';
    pcVar2 = pcVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  FUN_18000dc00(local_38,param_2,local_60);
  FUN_18000dc00(local_88,param_2 + 0x28,local_60);
  FUN_18000ed30(param_1,local_88);
  FUN_18000ed30(local_88,local_38);
  pcVar2 = local_88;
  lVar3 = 0x20;
  do {
    *pcVar2 = '\0';
    pcVar2 = pcVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  puVar1 = local_60;
  *(byte *)(param_1 + 0x1f) = *(byte *)(param_1 + 0x1f) ^ local_88[0] << 7;
  lVar3 = 0x28;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  puVar1 = local_38;
  lVar3 = 0x28;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  pcVar2 = local_88;
  do {
    *pcVar2 = '\0';
    pcVar2 = pcVar2 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



uint FUN_18000ff90(uint *param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  undefined1 *puVar6;
  int *piVar7;
  longlong lVar8;
  longlong lVar9;
  int local_a8 [8];
  undefined8 local_88;
  undefined1 local_80 [40];
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  FUN_18000e7b0(&local_58);
  FUN_18000e7b0(local_80,&local_58);
  FUN_18000e7b0(local_80,local_80);
  FUN_18000dc00(local_80,param_2,local_80);
  FUN_18000dc00(&local_58,&local_58,local_80);
  FUN_18000e7b0(&local_58,&local_58);
  FUN_18000dc00(&local_58,local_80,&local_58);
  FUN_18000e7b0(local_80,&local_58);
  lVar8 = 4;
  do {
    FUN_18000e7b0(local_80,local_80);
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  FUN_18000dc00(&local_58,local_80,&local_58);
  FUN_18000e7b0(local_80,&local_58);
  lVar8 = 9;
  lVar9 = 9;
  do {
    FUN_18000e7b0(local_80,local_80);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  FUN_18000dc00(local_80,local_80,&local_58);
  FUN_18000e7b0(local_a8,local_80);
  lVar9 = 0x13;
  do {
    FUN_18000e7b0(local_a8,local_a8);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  FUN_18000dc00(local_80,local_a8,local_80);
  FUN_18000e7b0(local_80,local_80);
  do {
    FUN_18000e7b0(local_80,local_80);
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  FUN_18000dc00(&local_58,local_80,&local_58);
  FUN_18000e7b0(local_80,&local_58);
  lVar8 = 0x31;
  lVar9 = 0x31;
  do {
    FUN_18000e7b0(local_80,local_80);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  FUN_18000dc00(local_80,local_80,&local_58);
  FUN_18000e7b0(local_a8,local_80);
  lVar9 = 99;
  do {
    FUN_18000e7b0(local_a8,local_a8);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  FUN_18000dc00(local_80,local_a8,local_80);
  FUN_18000e7b0(local_80,local_80);
  do {
    FUN_18000e7b0(local_80,local_80);
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  FUN_18000dc00(&local_58,local_80,&local_58);
  FUN_18000e7b0(&local_58,&local_58);
  FUN_18000e7b0(&local_58,&local_58);
  FUN_18000dc00(&local_58,&local_58,param_2);
  FUN_18000e7b0(local_80,&local_58);
  FUN_18000dc00(local_80,local_80,param_2);
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_88 = lVar8;
  uVar1 = FUN_18000db40(param_2,local_a8);
  local_a8[0] = 1;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_88 = lVar8;
  uVar2 = FUN_18000db40(local_80,local_a8);
  local_a8[1] = -local_a8[1];
  local_a8[0] = -local_a8[0];
  local_a8[3] = -local_a8[3];
  local_a8[2] = -local_a8[2];
  local_a8[5] = -local_a8[5];
  local_a8[4] = -local_a8[4];
  local_a8[7] = -local_a8[7];
  local_a8[6] = -local_a8[6];
  local_88 = CONCAT44(-local_88._4_4_,-(int)local_88);
  uVar3 = FUN_18000db40(local_80,local_a8);
  local_a8[0] = 0x1f15f50;
  local_a8[1] = 0x79362d;
  local_a8[2] = -0x8f189e;
  local_a8[3] = -0x35697f;
  local_a8[4] = -0xbd0c60;
  local_a8[5] = 0x42859;
  local_a8[6] = 0x17fb361;
  local_a8[7] = 0x1e9a96;
  local_88 = 0xff51f36efffb03e2;
  uVar4 = FUN_18000db40(local_80,local_a8);
  FUN_18000dc00(param_1,&local_58,&DAT_180029f08);
  uVar4 = (uVar4 | uVar3) - 1;
  *param_1 = (*param_1 ^ local_58) & uVar4 ^ *param_1;
  param_1[1] = (param_1[1] ^ local_54) & uVar4 ^ param_1[1];
  param_1[2] = (param_1[2] ^ local_50) & uVar4 ^ param_1[2];
  param_1[3] = (param_1[3] ^ local_4c) & uVar4 ^ param_1[3];
  param_1[4] = (param_1[4] ^ local_48) & uVar4 ^ param_1[4];
  param_1[5] = (param_1[5] ^ local_44) & uVar4 ^ param_1[5];
  param_1[6] = (param_1[6] ^ local_40) & uVar4 ^ param_1[6];
  param_1[7] = (param_1[7] ^ local_3c) & uVar4 ^ param_1[7];
  param_1[8] = (param_1[8] ^ local_38) & uVar4 ^ param_1[8];
  puVar5 = &local_58;
  param_1[9] = (param_1[9] ^ local_34) & uVar4 ^ param_1[9];
  lVar8 = 0x28;
  lVar9 = 0x28;
  do {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (uint *)((longlong)puVar5 + 1);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  puVar6 = local_80;
  lVar9 = 0x28;
  do {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  piVar7 = local_a8;
  do {
    *(undefined1 *)piVar7 = 0;
    piVar7 = (int *)((longlong)piVar7 + 1);
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  return uVar3 | uVar2 | uVar1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_1800103d0(undefined1 *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  ulonglong uVar17;
  longlong lVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  int iVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  uint uVar28;
  uint local_c8 [16];
  ulonglong local_88;
  ulonglong uStack_80;
  ulonglong local_78;
  undefined8 uStack_70;
  
  uVar15 = *param_2;
  uVar28 = param_2[8];
  uVar1 = param_2[9];
  uVar23 = 0;
  uVar2 = param_2[10];
  uVar3 = param_2[0xb];
  uVar4 = param_2[0xc];
  uVar5 = param_2[0xd];
  uVar6 = param_2[0xe];
  uVar7 = param_2[1];
  uVar8 = param_2[2];
  uVar9 = param_2[3];
  uVar10 = param_2[4];
  uVar11 = param_2[5];
  uVar12 = param_2[6];
  uVar13 = param_2[7];
  uVar14 = param_2[0xf];
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_c8[6] = 0;
  local_c8[7] = 0;
  local_c8[8] = 0;
  local_c8[9] = 0;
  local_c8[10] = 0;
  local_c8[0xb] = 0;
  local_c8[0xc] = 0;
  local_c8[0xd] = 0;
  local_c8[0xe] = 0;
  local_c8[0xf] = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  do {
    uVar19 = (ulonglong)(uint)(&DAT_18002acb0)[uVar23];
    uVar17 = uVar15 * uVar19 + (ulonglong)local_c8[uVar23];
    local_c8[uVar23] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar7 * uVar19 + (ulonglong)local_c8[uVar23 + 1];
    local_c8[uVar23 + 1] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar8 * uVar19 + (ulonglong)local_c8[uVar23 + 2];
    local_c8[uVar23 + 2] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar9 * uVar19 + (ulonglong)local_c8[uVar23 + 3];
    local_c8[uVar23 + 3] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar10 * uVar19 + (ulonglong)local_c8[uVar23 + 4];
    local_c8[uVar23 + 4] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar11 * uVar19 + (ulonglong)local_c8[uVar23 + 5];
    local_c8[uVar23 + 5] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar12 * uVar19 + (ulonglong)local_c8[uVar23 + 6];
    local_c8[uVar23 + 6] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar13 * uVar19 + (ulonglong)local_c8[uVar23 + 7];
    local_c8[uVar23 + 7] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar28 * uVar19 + (ulonglong)local_c8[uVar23 + 8];
    local_c8[uVar23 + 8] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar1 * uVar19 + (ulonglong)local_c8[uVar23 + 9];
    local_c8[uVar23 + 9] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar2 * uVar19 + (ulonglong)local_c8[uVar23 + 10];
    local_c8[uVar23 + 10] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar3 * uVar19 + (ulonglong)local_c8[uVar23 + 0xb];
    local_c8[uVar23 + 0xb] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar4 * uVar19 + (ulonglong)local_c8[uVar23 + 0xc];
    local_c8[uVar23 + 0xc] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar5 * uVar19 + (ulonglong)local_c8[uVar23 + 0xd];
    local_c8[uVar23 + 0xd] = (uint)uVar17;
    uVar17 = (uVar17 >> 0x20) + uVar6 * uVar19 + (ulonglong)local_c8[uVar23 + 0xe];
    local_c8[uVar23 + 0xe] = (uint)uVar17;
    lVar18 = (uVar17 >> 0x20) + uVar14 * uVar19 + (ulonglong)local_c8[uVar23 + 0xf];
    local_c8[uVar23 + 0xf] = (uint)lVar18;
    local_c8[uVar23 + 0x10] = (uint)((ulonglong)lVar18 >> 0x20);
    uVar23 = uVar23 + 1;
  } while (uVar23 < 9);
  local_c8[0] = 0;
  local_c8[1] = 0;
  uVar17 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  uVar23 = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_c8[6] = 0;
  local_c8[7] = 0;
  do {
    uVar17 = uVar17 + (local_88 & 0xffffffff) * (ulonglong)(uint)(&DAT_18002a040)[uVar23] +
             (ulonglong)local_c8[uVar23];
    local_c8[uVar23] = (uint)uVar17;
    uVar23 = uVar23 + 1;
    uVar17 = uVar17 >> 0x20;
  } while (uVar23 < 8);
  uVar17 = 0;
  uVar23 = 0;
  do {
    uVar17 = uVar17 + (local_88 >> 0x20) * (ulonglong)(uint)(&DAT_18002a040)[uVar23] +
             (ulonglong)local_c8[uVar23 + 1];
    local_c8[uVar23 + 1] = (uint)uVar17;
    uVar23 = uVar23 + 1;
    uVar17 = uVar17 >> 0x20;
  } while (uVar23 < 7);
  uVar17 = 0;
  uVar23 = 0;
  do {
    uVar17 = uVar17 + (uStack_80 & 0xffffffff) * (ulonglong)(uint)(&DAT_18002a040)[uVar23] +
             (ulonglong)local_c8[uVar23 + 2];
    local_c8[uVar23 + 2] = (uint)uVar17;
    uVar23 = uVar23 + 1;
    uVar17 = uVar17 >> 0x20;
  } while (uVar23 < 6);
  uVar17 = 0;
  uVar23 = 0;
  do {
    uVar17 = uVar17 + (uStack_80 >> 0x20) * (ulonglong)(uint)(&DAT_18002a040)[uVar23] +
             (ulonglong)local_c8[uVar23 + 3];
    local_c8[uVar23 + 3] = (uint)uVar17;
    uVar23 = uVar23 + 1;
    uVar17 = uVar17 >> 0x20;
  } while (uVar23 < 5);
  uVar17 = 0;
  uVar23 = 0;
  do {
    uVar17 = uVar17 + (local_78 & 0xffffffff) * (ulonglong)(uint)(&DAT_18002a040)[uVar23] +
             (ulonglong)local_c8[uVar23 + 4];
    local_c8[uVar23 + 4] = (uint)uVar17;
    uVar23 = uVar23 + 1;
    uVar17 = uVar17 >> 0x20;
  } while (uVar23 < 4);
  uVar17 = 0;
  uVar23 = 0;
  do {
    uVar17 = uVar17 + (local_78 >> 0x20) * (ulonglong)(uint)(&DAT_18002a040)[uVar23] +
             (ulonglong)local_c8[uVar23 + 5];
    local_c8[uVar23 + 5] = (uint)uVar17;
    uVar23 = uVar23 + 1;
    uVar17 = uVar17 >> 0x20;
  } while (uVar23 < 3);
  uVar17 = 0;
  uVar23 = 0;
  do {
    uVar17 = uVar17 + (uStack_70 & 0xffffffff) * (ulonglong)(uint)(&DAT_18002a040)[uVar23] +
             (ulonglong)local_c8[uVar23 + 6];
    local_c8[uVar23 + 6] = (uint)uVar17;
    uVar23 = uVar23 + 1;
    uVar17 = uVar17 >> 0x20;
  } while (uVar23 < 2);
  uVar23 = (ulonglong)~local_c8[0] + (ulonglong)*param_2 + 1;
  uVar24 = uVar23 & 0xffffffff;
  uVar23 = (uVar23 >> 0x20) + (ulonglong)param_2[1] + (ulonglong)~local_c8[1];
  uVar17 = uVar23 & 0xffffffff;
  uVar23 = (uVar23 >> 0x20) + (ulonglong)param_2[2] + (ulonglong)~local_c8[2];
  uVar26 = uVar23 & 0xffffffff;
  uVar25 = (ulonglong)param_2[3] + (uVar23 >> 0x20) + (ulonglong)~local_c8[3];
  uVar23 = (uVar25 >> 0x20) + (ulonglong)uVar10 + (ulonglong)~local_c8[4];
  uVar19 = uVar23 & 0xffffffff;
  uVar23 = (uVar23 >> 0x20) + (ulonglong)uVar11 + (ulonglong)~local_c8[5];
  uVar20 = uVar23 & 0xffffffff;
  uVar23 = (ulonglong)uVar12 + (uVar23 >> 0x20) + (ulonglong)~local_c8[6];
  uVar27 = uVar23 & 0xffffffff;
  uVar25 = uVar25 & 0xffffffff;
  uVar28 = (int)(uVar23 >> 0x20) + uVar13 + ~(uStack_70._4_4_ * 0x5cf5d3ed + local_c8[7]);
  uVar23 = (uVar27 + 0xffffffff +
            (uVar20 + 0xffffffff +
             ((uVar25 + 0xeb210621 +
               (((uVar24 + 0xa30a2c13 >> 0x20) + uVar17 + 0xa7ed9ce5 >> 0x20) + 0x5d086329 + uVar26
               >> 0x20) >> 0x20) + uVar19 + 0xffffffff >> 0x20) >> 0x20) >> 0x20) +
           (ulonglong)uVar28 + 0xefffffff;
  uVar15 = -(int)(uVar23 >> 0x20);
  uVar22 = (ulonglong)uVar15;
  uVar24 = ((ulonglong)uVar15 & 0xa30a2c12) + uVar24 + (uVar23 >> 0x20);
  uVar23 = (uVar24 >> 0x20) + ((ulonglong)uVar15 & 0xa7ed9ce5) + uVar17;
  uVar17 = (uVar23 >> 0x20) + (uVar15 & 0x5d086329) + uVar26;
  uVar25 = (uVar17 >> 0x20) + ((ulonglong)uVar15 & 0xeb210621) + uVar25;
  uVar19 = (uVar25 >> 0x20) + uVar22 + uVar19;
  uVar20 = (uVar19 >> 0x20) + uVar22 + uVar20;
  lVar18 = (uVar20 >> 0x20) + uVar22 + uVar27;
  iVar21 = (uVar15 & 0xefffffff) + uVar28 + (int)((ulonglong)lVar18 >> 0x20);
  param_1[1] = (char)(uVar24 >> 8);
  param_1[2] = (char)(uVar24 >> 0x10);
  *param_1 = (char)uVar24;
  param_1[3] = (char)(uVar24 >> 0x18);
  param_1[4] = (char)uVar23;
  param_1[5] = (char)(uVar23 >> 8);
  param_1[6] = (char)(uVar23 >> 0x10);
  param_1[7] = (char)(uVar23 >> 0x18);
  param_1[8] = (char)uVar17;
  param_1[9] = (char)(uVar17 >> 8);
  param_1[10] = (char)(uVar17 >> 0x10);
  param_1[0xb] = (char)(uVar17 >> 0x18);
  param_1[0xc] = (char)uVar25;
  param_1[0xd] = (char)(uVar25 >> 8);
  param_1[0xe] = (char)(uVar25 >> 0x10);
  param_1[0xf] = (char)(uVar25 >> 0x18);
  param_1[0x10] = (char)uVar19;
  param_1[0x11] = (char)(uVar19 >> 8);
  param_1[0x12] = (char)(uVar19 >> 0x10);
  param_1[0x13] = (char)(uVar19 >> 0x18);
  param_1[0x14] = (char)uVar20;
  param_1[0x15] = (char)(uVar20 >> 8);
  param_1[0x16] = (char)(uVar20 >> 0x10);
  param_1[0x17] = (char)(uVar20 >> 0x18);
  param_1[0x18] = (char)lVar18;
  param_1[0x19] = (char)((ulonglong)lVar18 >> 8);
  param_1[0x1a] = (char)((ulonglong)lVar18 >> 0x10);
  param_1[0x1b] = (char)((ulonglong)lVar18 >> 0x18);
  param_1[0x1c] = (char)iVar21;
  param_1[0x1d] = (char)((uint)iVar21 >> 8);
  param_1[0x1e] = (char)((uint)iVar21 >> 0x10);
  puVar16 = local_c8;
  param_1[0x1f] = (char)((uint)iVar21 >> 0x18);
  lVar18 = 100;
  do {
    *(undefined1 *)puVar16 = 0;
    puVar16 = (uint *)((longlong)puVar16 + 1);
    lVar18 = lVar18 + -1;
  } while (lVar18 != 0);
  return;
}



int FUN_180010b20(short *param_1,int param_2,uint param_3,longlong param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char cVar9;
  byte bVar10;
  ushort uVar11;
  uint uVar12;
  int iVar13;
  
  bVar2 = *(byte *)((longlong)param_1 + 3);
  if (param_3 == bVar2) {
    if ((int)param_3 < 0) {
      bVar10 = 0;
    }
    else {
      bVar10 = *(byte *)(((ulonglong)(longlong)(int)param_3 >> 3) + param_4) >> ((byte)param_3 & 7)
               & 1;
    }
    iVar4 = param_3 - 1;
    if (iVar4 < 0) {
      bVar3 = 0;
    }
    else {
      bVar3 = *(byte *)(((longlong)iVar4 >> 3) + param_4) >> ((byte)iVar4 & 7) & 1;
    }
    if (bVar10 == bVar3) {
      cVar9 = bVar2 - 1;
    }
    else {
      iVar8 = param_3 + 1;
      iVar4 = iVar8;
      if (param_2 <= iVar8) {
        iVar4 = param_2;
      }
      if ((int)param_3 < 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *(byte *)(((ulonglong)(longlong)(int)param_3 >> 3) + param_4) >>
                 ((byte)param_3 & 7) & 1;
      }
      iVar1 = iVar4 + -1;
      iVar13 = -(uVar12 << ((byte)iVar1 & 0x1f));
      iVar6 = 0;
      if (0 < iVar1) {
        do {
          iVar5 = (iVar6 - iVar4) + iVar8;
          if (iVar5 < 0) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(byte *)(param_4 + ((longlong)iVar5 >> 3)) >> ((byte)iVar5 & 7) & 1;
          }
          iVar5 = iVar6 + 1;
          iVar13 = iVar13 + (uVar12 << ((byte)iVar6 & 0x1f));
          iVar6 = iVar5;
        } while (iVar5 < iVar1);
      }
      iVar8 = param_3 - iVar4;
      if (iVar8 < 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *(byte *)(((longlong)iVar8 >> 3) + param_4) >> ((byte)iVar8 & 7) & 1;
      }
      uVar12 = uVar12 + iVar13;
      uVar7 = -uVar12 & uVar12;
      uVar11 = -(ushort)((uVar7 & 0xf0) != 0) & 4 | -(ushort)((uVar7 & 0xcc) != 0) & 2 |
               (ushort)((uVar7 & 0xaa) != 0);
      *(char *)(param_1 + 1) = (char)((int)uVar12 >> (sbyte)uVar11);
      *param_1 = (uVar11 - (short)iVar4) + 1 + (short)param_3;
      cVar9 = bVar2 - (char)iVar4;
    }
    *(char *)((longlong)param_1 + 3) = cVar9;
  }
  if (param_3 == (int)*param_1) {
    return (int)(char)param_1[1];
  }
  return 0;
}



ulonglong FUN_180010ca0(ulonglong *param_1,ulonglong *param_2)

{
  return param_1[1] ^ param_2[1] | *param_1 ^ *param_2;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_180010e00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_180030500 ^ (ulonglong)auStack_88;
  local_48 = 0;
  local_50 = 0;
  local_68 = 0x20;
  local_60 = param_3;
  local_58 = param_4;
  FUN_1800118a0(local_38,param_1,0x20,param_2);
  FUN_18000cd00(param_1,param_2,local_38);
  return;
}



void FUN_180010e90(undefined8 *param_1,undefined1 *param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar2 = param_1[0x1a];
  if (uVar2 == 0) {
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
  }
  puVar1 = (ulonglong *)((longlong)param_1 + (uVar2 & 0xfffffffffffffff8) + 0x40);
  *puVar1 = *puVar1 | 0x80L << (((byte)uVar2 & 7) * -8 + 0x38 & 0x3f);
  uVar2 = param_1[0x1a] * 8;
  param_1[0x19] = param_1[0x19] + uVar2;
  if ((ulonglong)param_1[0x19] < uVar2) {
    param_1[0x18] = param_1[0x18] + 1;
  }
  if (0x6f < (ulonglong)param_1[0x1a]) {
    FUN_180011aa0(param_1);
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
  }
  param_1[0x16] = param_1[0x18];
  param_1[0x17] = param_1[0x19];
  FUN_180011aa0(param_1);
  uVar3 = *param_1;
  param_2[7] = (char)uVar3;
  *param_2 = (char)((ulonglong)uVar3 >> 0x38);
  param_2[1] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[2] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[3] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[4] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[5] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[6] = (char)((ulonglong)uVar3 >> 8);
  uVar3 = param_1[1];
  param_2[8] = (char)((ulonglong)uVar3 >> 0x38);
  param_2[9] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[10] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[0xb] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[0xc] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[0xd] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[0xe] = (char)((ulonglong)uVar3 >> 8);
  param_2[0xf] = (char)uVar3;
  uVar3 = param_1[2];
  param_2[0x10] = (char)((ulonglong)uVar3 >> 0x38);
  param_2[0x11] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[0x12] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[0x13] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[0x14] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[0x15] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[0x16] = (char)((ulonglong)uVar3 >> 8);
  param_2[0x17] = (char)uVar3;
  uVar3 = param_1[3];
  param_2[0x18] = (char)((ulonglong)uVar3 >> 0x38);
  param_2[0x19] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[0x1a] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[0x1b] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[0x1c] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[0x1d] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[0x1e] = (char)((ulonglong)uVar3 >> 8);
  param_2[0x1f] = (char)uVar3;
  uVar3 = param_1[4];
  param_2[0x20] = (char)((ulonglong)uVar3 >> 0x38);
  param_2[0x21] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[0x22] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[0x23] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[0x24] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[0x25] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[0x26] = (char)((ulonglong)uVar3 >> 8);
  param_2[0x27] = (char)uVar3;
  uVar3 = param_1[5];
  param_2[0x28] = (char)((ulonglong)uVar3 >> 0x38);
  param_2[0x29] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[0x2a] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[0x2b] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[0x2c] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[0x2d] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[0x2e] = (char)((ulonglong)uVar3 >> 8);
  param_2[0x2f] = (char)uVar3;
  uVar3 = param_1[6];
  param_2[0x30] = (char)((ulonglong)uVar3 >> 0x38);
  param_2[0x31] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[0x32] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[0x33] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[0x34] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[0x35] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[0x36] = (char)((ulonglong)uVar3 >> 8);
  param_2[0x37] = (char)uVar3;
  uVar3 = param_1[7];
  param_2[0x38] = (char)((ulonglong)uVar3 >> 0x38);
  param_2[0x39] = (char)((ulonglong)uVar3 >> 0x30);
  param_2[0x3a] = (char)((ulonglong)uVar3 >> 0x28);
  param_2[0x3b] = (char)((ulonglong)uVar3 >> 0x20);
  param_2[0x3c] = (char)((ulonglong)uVar3 >> 0x18);
  param_2[0x3d] = (char)((ulonglong)uVar3 >> 0x10);
  param_2[0x3e] = (char)((ulonglong)uVar3 >> 8);
  param_2[0x3f] = (char)uVar3;
  FUN_18000d7e0(param_1,0xd8);
  return;
}



void FUN_180011250(longlong param_1,longlong param_2,ulonglong param_3)

{
  byte *pbVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_3 != 0) {
    uVar6 = *(ulonglong *)(param_1 + 0xd0);
    if ((uVar6 & 7) != 0) {
      uVar4 = (ulonglong)(-(int)uVar6 & 7);
      uVar3 = param_3;
      if (uVar4 <= param_3) {
        uVar3 = uVar4;
      }
      if (uVar3 != 0) {
        uVar4 = 0;
        do {
          pbVar1 = (byte *)(param_2 + uVar4);
          uVar4 = uVar4 + 1;
          puVar2 = (ulonglong *)(param_1 + 0x40 + (uVar6 & 0xfffffffffffffff8));
          *puVar2 = *puVar2 | (ulonglong)*pbVar1 << (((byte)uVar6 & 7) * -8 + 0x38 & 0x3f);
          uVar6 = *(longlong *)(param_1 + 0xd0) + 1;
          *(ulonglong *)(param_1 + 0xd0) = uVar6;
        } while (uVar4 < uVar3);
      }
      param_2 = param_2 + uVar3;
      param_3 = param_3 - uVar3;
    }
    if ((uVar6 & 0x7f) != 0) {
      uVar3 = (ulonglong)(-(int)uVar6 & 0x7f);
      if (param_3 < uVar3) {
        uVar3 = param_3;
      }
      FUN_180011a20(param_1 + ((uVar6 >> 3) + 8) * 8,param_2,uVar3 >> 3);
      uVar3 = uVar3 & 0xfffffffffffffff8;
      *(longlong *)(param_1 + 0xd0) = *(longlong *)(param_1 + 0xd0) + uVar3;
      param_2 = param_2 + uVar3;
      uVar6 = *(ulonglong *)(param_1 + 0xd0);
      param_3 = param_3 - uVar3;
    }
    if (uVar6 == 0x80) {
      *(longlong *)(param_1 + 200) = *(longlong *)(param_1 + 200) + 0x400;
      if (*(ulonglong *)(param_1 + 200) < 0x400) {
        *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + 1;
      }
      FUN_180011aa0(param_1);
      *(undefined8 *)(param_1 + 0xd0) = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined8 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x88) = 0;
      *(undefined8 *)(param_1 + 0x90) = 0;
      *(undefined8 *)(param_1 + 0x98) = 0;
      *(undefined8 *)(param_1 + 0xa0) = 0;
      *(undefined8 *)(param_1 + 0xa8) = 0;
      *(undefined8 *)(param_1 + 0xb0) = 0;
      *(undefined8 *)(param_1 + 0xb8) = 0;
    }
    for (uVar6 = param_3 >> 7; uVar6 != 0; uVar6 = uVar6 - 1) {
      uVar3 = 0;
      do {
        *(ulonglong *)(param_1 + 0x40 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 1 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 2 + uVar3 * 8)),
                                                          *(undefined1 *)(param_2 + 3 + uVar3 * 8)),
                                                 *(undefined1 *)(param_2 + 4 + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 5 + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 6 + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 7 + uVar3 * 8));
        *(ulonglong *)(param_1 + 0x48 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + 8 +
                                                                             uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 9 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 10 + uVar3 * 8)),
                                                          *(undefined1 *)(param_2 + 0xb + uVar3 * 8)
                                                         ),
                                                 *(undefined1 *)(param_2 + 0xc + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 0xd + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 0xe + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 0xf + uVar3 * 8));
        *(ulonglong *)(param_1 + 0x50 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + 0x10 +
                                                                             uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 0x11 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 0x12 + uVar3 * 8)),
                                                          *(undefined1 *)
                                                           (param_2 + 0x13 + uVar3 * 8)),
                                                 *(undefined1 *)(param_2 + 0x14 + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 0x15 + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 0x16 + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 0x17 + uVar3 * 8));
        *(ulonglong *)(param_1 + 0x58 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + 0x18 +
                                                                             uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 0x19 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 0x1a + uVar3 * 8)),
                                                          *(undefined1 *)
                                                           (param_2 + 0x1b + uVar3 * 8)),
                                                 *(undefined1 *)(param_2 + 0x1c + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 0x1d + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 0x1e + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 0x1f + uVar3 * 8));
        *(ulonglong *)(param_1 + 0x60 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + 0x20 +
                                                                             uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 0x21 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 0x22 + uVar3 * 8)),
                                                          *(undefined1 *)
                                                           (param_2 + 0x23 + uVar3 * 8)),
                                                 *(undefined1 *)(param_2 + 0x24 + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 0x25 + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 0x26 + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 0x27 + uVar3 * 8));
        *(ulonglong *)(param_1 + 0x68 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + 0x28 +
                                                                             uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 0x29 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 0x2a + uVar3 * 8)),
                                                          *(undefined1 *)
                                                           (param_2 + 0x2b + uVar3 * 8)),
                                                 *(undefined1 *)(param_2 + 0x2c + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 0x2d + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 0x2e + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 0x2f + uVar3 * 8));
        *(ulonglong *)(param_1 + 0x70 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + 0x30 +
                                                                             uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 0x31 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 0x32 + uVar3 * 8)),
                                                          *(undefined1 *)
                                                           (param_2 + 0x33 + uVar3 * 8)),
                                                 *(undefined1 *)(param_2 + 0x34 + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 0x35 + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 0x36 + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 0x37 + uVar3 * 8));
        *(ulonglong *)(param_1 + 0x78 + uVar3 * 8) =
             CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                             (param_2 + 0x38 +
                                                                             uVar3 * 8),
                                                                            *(undefined1 *)
                                                                             (param_2 + 0x39 +
                                                                             uVar3 * 8)),
                                                                   *(undefined1 *)
                                                                    (param_2 + 0x3a + uVar3 * 8)),
                                                          *(undefined1 *)
                                                           (param_2 + 0x3b + uVar3 * 8)),
                                                 *(undefined1 *)(param_2 + 0x3c + uVar3 * 8)),
                                        *(undefined1 *)(param_2 + 0x3d + uVar3 * 8)),
                               *(undefined1 *)(param_2 + 0x3e + uVar3 * 8)),
                      *(undefined1 *)(param_2 + 0x3f + uVar3 * 8));
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x10);
      uVar3 = *(longlong *)(param_1 + 200) + 0x400;
      *(ulonglong *)(param_1 + 200) = uVar3;
      if (uVar3 < 0x400) {
        *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + 1;
      }
      FUN_180011aa0(param_1);
      *(undefined8 *)(param_1 + 0xd0) = 0;
      param_2 = param_2 + 0x80;
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined8 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x88) = 0;
      *(undefined8 *)(param_1 + 0x90) = 0;
      *(undefined8 *)(param_1 + 0x98) = 0;
      *(undefined8 *)(param_1 + 0xa0) = 0;
      *(undefined8 *)(param_1 + 0xa8) = 0;
      *(undefined8 *)(param_1 + 0xb0) = 0;
      *(undefined8 *)(param_1 + 0xb8) = 0;
    }
    uVar5 = (uint)param_3 & 0x7f;
    if ((param_3 & 0x7f) != 0) {
      uVar6 = 0;
      if ((ulonglong)(uVar5 >> 3) != 0) {
        do {
          *(ulonglong *)(param_1 + 0x40 + uVar6 * 8) =
               CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                               (param_2 + uVar6 * 8)
                                                                              ,*(undefined1 *)
                                                                                (param_2 + 1 +
                                                                                uVar6 * 8)),
                                                                     *(undefined1 *)
                                                                      (param_2 + 2 + uVar6 * 8)),
                                                            *(undefined1 *)(param_2 + 3 + uVar6 * 8)
                                                           ),
                                                   *(undefined1 *)(param_2 + 4 + uVar6 * 8)),
                                          *(undefined1 *)(param_2 + 5 + uVar6 * 8)),
                                 *(undefined1 *)(param_2 + 6 + uVar6 * 8)),
                        *(undefined1 *)(param_2 + 7 + uVar6 * 8));
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5 >> 3);
      }
      uVar3 = (ulonglong)((uint)param_3 & 0x78);
      uVar6 = *(longlong *)(param_1 + 0xd0) + uVar3;
      *(ulonglong *)(param_1 + 0xd0) = uVar6;
      if (uVar5 != uVar3) {
        uVar4 = 0;
        do {
          pbVar1 = (byte *)(uVar3 + param_2 + uVar4);
          uVar4 = uVar4 + 1;
          puVar2 = (ulonglong *)(param_1 + 0x40 + (uVar6 & 0xfffffffffffffff8));
          *puVar2 = *puVar2 | (ulonglong)*pbVar1 << (((byte)uVar6 & 7) * -8 + 0x38 & 0x3f);
          uVar6 = *(longlong *)(param_1 + 0xd0) + 1;
          *(ulonglong *)(param_1 + 0xd0) = uVar6;
        } while (uVar4 < uVar5 - uVar3);
      }
    }
  }
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_1800118a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                  undefined8 param_9)

{
  undefined1 auStack_178 [32];
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined1 local_78 [64];
  ulonglong local_38;
  
  local_38 = DAT_180030500 ^ (ulonglong)auStack_178;
  local_158 = 0x6a09e667f3bcc908;
  local_150 = 0xbb67ae8584caa73b;
  local_148 = 0x3c6ef372fe94f82b;
  local_140 = 0xa54ff53a5f1d36f1;
  local_138 = 0x510e527fade682d1;
  local_130 = 0x9b05688c2b3e6c1f;
  local_128 = 0x1f83d9abfb41bd6b;
  local_120 = 0x5be0cd19137e2179;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_118 = 0;
  local_110 = 0;
  local_108 = 0;
  local_100 = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  FUN_180011250(&local_158);
  FUN_180011250(&local_158,param_4,param_5);
  FUN_180011250(&local_158,param_6,param_7);
  FUN_180011250(&local_158,param_8,param_9);
  FUN_180010e90(&local_158,local_78);
  FUN_18000d570(param_1,local_78);
  return;
}



void FUN_180011a20(longlong param_1,longlong param_2,ulonglong param_3)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      *(ulonglong *)(param_1 + uVar1 * 8) =
           CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                           (param_2 + uVar1 * 8),
                                                                          *(undefined1 *)
                                                                           (param_2 + 1 + uVar1 * 8)
                                                                         ),
                                                                 *(undefined1 *)
                                                                  (param_2 + 2 + uVar1 * 8)),
                                                        *(undefined1 *)(param_2 + 3 + uVar1 * 8)),
                                               *(undefined1 *)(param_2 + 4 + uVar1 * 8)),
                                      *(undefined1 *)(param_2 + 5 + uVar1 * 8)),
                             *(undefined1 *)(param_2 + 6 + uVar1 * 8)),
                    *(undefined1 *)(param_2 + 7 + uVar1 * 8));
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_3);
  }
  return;
}



void FUN_180011aa0(ulonglong *param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  ulonglong uVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong uVar21;
  longlong lVar22;
  longlong lVar23;
  ulonglong uVar24;
  ulonglong local_res8;
  ulonglong local_res10;
  
  uVar18 = *param_1;
  uVar15 = param_1[4];
  uVar21 = param_1[1];
  uVar14 = param_1[5];
  lVar19 = param_1[7] +
           ((uVar15 >> 0x29 | uVar15 << 0x17) ^ (uVar15 >> 0x12 | uVar15 << 0x2e) ^
           (uVar15 >> 0xe | uVar15 << 0x32)) + (~uVar15 & param_1[6] ^ uVar14 & uVar15) + param_1[8]
  ;
  lVar22 = ((uVar18 >> 0x1c | uVar18 << 0x24) ^ (uVar18 >> 0x22 | uVar18 << 0x1e) ^
           (uVar18 >> 0x27 | uVar18 << 0x19)) + ((uVar21 ^ uVar18) & param_1[2] ^ uVar21 & uVar18);
  uVar10 = param_1[3] + lVar19 + 0x428a2f98d728ae22;
  uVar9 = lVar22 + 0x428a2f98d728ae22 + lVar19;
  lVar20 = ((uVar10 >> 0x29 | uVar10 * 0x800000) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
           (uVar10 >> 0xe | uVar10 << 0x32)) + (~uVar10 & uVar14 ^ uVar15 & uVar10) + param_1[9] +
           param_1[6];
  lVar2 = (uVar18 & uVar9 ^ (uVar18 ^ uVar9) & uVar21) +
          ((uVar9 >> 0x1c | uVar9 << 0x24) ^ (uVar9 >> 0x22 | uVar9 * 0x40000000) ^
          (uVar9 >> 0x27 | uVar9 * 0x2000000));
  lVar4 = param_1[2] + lVar20;
  uVar12 = lVar4 + 0x7137449123ef65cd;
  uVar13 = lVar2 + 0x7137449123ef65cd + lVar20;
  lVar17 = uVar14 + ((uVar12 >> 0x29 | uVar12 * 0x800000) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
                    (uVar12 >> 0xe | uVar12 << 0x32)) + (~uVar12 & uVar15 ^ uVar10 & uVar12) +
                    param_1[10];
  lVar3 = (uVar9 & uVar13 ^ (uVar9 ^ uVar13) & uVar18) +
          ((uVar13 >> 0x1c | uVar13 << 0x24) ^ (uVar13 >> 0x22 | uVar13 * 0x40000000) ^
          (uVar13 >> 0x27 | uVar13 * 0x2000000));
  uVar14 = lVar17 + uVar21 + 0xb5c0fbcfec4d3b2f;
  uVar11 = lVar3 + -0x4a3f043013b2c4d1 + lVar17;
  lVar16 = (uVar10 & ~uVar14 ^ uVar12 & uVar14) +
           ((uVar14 >> 0x29 | uVar14 * 0x800000) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
           (uVar14 >> 0xe | uVar14 << 0x32)) + param_1[0xb] + uVar15;
  lVar6 = ((uVar13 ^ uVar11) & uVar9 ^ uVar13 & uVar11) +
          ((uVar11 >> 0x1c | uVar11 << 0x24) ^ (uVar11 >> 0x22 | uVar11 * 0x40000000) ^
          (uVar11 >> 0x27 | uVar11 * 0x2000000));
  uVar10 = uVar18 + lVar16 + 0xe9b5dba58189dbbc;
  uVar24 = lVar6 + -0x164a245a7e762444 + lVar16;
  lVar7 = ((uVar10 >> 0x29 | uVar10 * 0x800000) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
          (uVar10 >> 0xe | uVar10 << 0x32)) + (~uVar10 & uVar12 ^ uVar14 & uVar10) + param_1[0xc];
  lVar22 = lVar22 + lVar19 * 2 + param_1[3] + lVar7;
  uVar15 = lVar22 + 0xbe6b218da19a117c;
  lVar7 = lVar7 + param_1[3] + lVar19 +
          ((uVar24 >> 0x1c | uVar24 << 0x24) ^ (uVar24 >> 0x22 | uVar24 * 0x40000000) ^
          (uVar24 >> 0x27 | uVar24 * 0x2000000)) + ((uVar11 ^ uVar24) & uVar13 ^ uVar11 & uVar24);
  uVar9 = lVar7 + 0x7be0f1f4ca71635a;
  lVar19 = ((uVar15 >> 0x29 | uVar15 * 0x800000) ^ (uVar15 >> 0x12 | uVar15 << 0x2e) ^
           (uVar15 >> 0xe | uVar15 << 0x32)) + (~uVar15 & uVar14 ^ uVar10 & uVar15) + param_1[0xd];
  lVar2 = lVar2 + lVar20 * 2 + param_1[2] + lVar19;
  uVar14 = lVar2 + 0x3c5f9b13fde49bb3;
  lVar4 = lVar19 + lVar4 +
          ((uVar9 >> 0x1c | uVar9 << 0x24) ^ (uVar9 >> 0x22 | uVar9 * 0x40000000) ^
          (uVar9 >> 0x27 | uVar9 * 0x2000000)) + ((uVar24 ^ uVar9) & uVar11 ^ uVar24 & uVar9);
  uVar11 = lVar4 + 0xcb285682d9f535e6;
  lVar19 = ((uVar14 >> 0x29 | uVar14 * 0x800000) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
           (uVar14 >> 0xe | uVar14 << 0x32)) + (~uVar14 & uVar10 ^ uVar15 & uVar14) + param_1[0xe];
  lVar3 = lVar3 + lVar17 * 2 + param_1[1] + lVar19;
  uVar10 = lVar3 + 0xfdc17a4487b3c5f9;
  lVar19 = lVar19 + lVar17 + uVar21 +
           ((uVar11 >> 0x1c | uVar11 << 0x24) ^ (uVar11 >> 0x22 | uVar11 * 0x40000000) ^
           (uVar11 >> 0x27 | uVar11 * 0x2000000)) + ((uVar9 ^ uVar11) & uVar24 ^ uVar9 & uVar11);
  uVar12 = lVar19 + 0x48007e749b668aca;
  lVar17 = ((uVar10 >> 0x29 | uVar10 * 0x800000) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
           (uVar10 >> 0xe | uVar10 << 0x32)) + (~uVar10 & uVar15 ^ uVar14 & uVar10) + param_1[0xf];
  lVar23 = lVar6 + lVar16 * 2 + uVar18 + lVar17;
  uVar21 = lVar23 + 0x7e881620dd813890;
  lVar6 = uVar18 + lVar16 + lVar17 +
          ((uVar12 >> 0x1c | uVar12 << 0x24) ^ (uVar12 >> 0x22 | uVar12 * 0x40000000) ^
          (uVar12 >> 0x27 | uVar12 * 0x2000000)) + ((uVar11 ^ uVar12) & uVar9 ^ uVar11 & uVar12);
  uVar18 = lVar6 + 0x94d23a7b5bf75cd4;
  lVar22 = ((uVar21 >> 0x29 | uVar21 * 0x800000) ^ (uVar21 >> 0x12 | uVar21 << 0x2e) ^
           (uVar21 >> 0xe | uVar21 << 0x32)) + (~uVar21 & uVar14 ^ uVar10 & uVar21) + param_1[0x10]
           + lVar22;
  lVar17 = (uVar12 & uVar18 ^ (uVar12 ^ uVar18) & uVar11) +
           ((uVar18 >> 0x1c | uVar18 << 0x24) ^ (uVar18 >> 0x22 | uVar18 * 0x40000000) ^
           (uVar18 >> 0x27 | uVar18 * 0x2000000));
  uVar14 = lVar7 + lVar22 + 0x1253be1b0f0e7718;
  uVar15 = lVar17 + -0x698d33d9bb62ec42 + lVar22;
  lVar2 = (uVar10 & ~uVar14 ^ uVar21 & uVar14) +
          ((uVar14 >> 0x29 | uVar14 * 0x800000) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
          (uVar14 >> 0xe | uVar14 << 0x32)) + param_1[0x11] + lVar2;
  uVar10 = lVar4 + lVar2 + 0x1a0b4c981d4a4157;
  lVar16 = (uVar18 & uVar15 ^ (uVar18 ^ uVar15) & uVar12) +
           ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
           (uVar15 >> 0x27 | uVar15 * 0x2000000));
  uVar12 = lVar16 + 0x4ee2f61543550b71 + lVar2;
  lVar3 = ((uVar10 >> 0x29 | uVar10 * 0x800000) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
          (uVar10 >> 0xe | uVar10 << 0x32)) + (~uVar10 & uVar21 ^ uVar14 & uVar10) + param_1[0x12] +
          lVar3;
  uVar21 = lVar19 + lVar3 + 0x69f37e7771ff034f;
  lVar20 = (uVar15 & uVar12 ^ (uVar15 ^ uVar12) & uVar18) +
           ((uVar12 >> 0x1c | uVar12 << 0x24) ^ (uVar12 >> 0x22 | uVar12 * 0x40000000) ^
           (uVar12 >> 0x27 | uVar12 * 0x2000000));
  uVar18 = lVar20 + 0x21f30002d6987885 + lVar3;
  lVar23 = (uVar14 & ~uVar21 ^ uVar10 & uVar21) +
           ((uVar21 >> 0x29 | uVar21 * 0x800000) ^ (uVar21 >> 0x12 | uVar21 << 0x2e) ^
           (uVar21 >> 0xe | uVar21 << 0x32)) + param_1[0x13] + lVar23;
  uVar14 = lVar6 + lVar23 + 0x6866ce600f784a46;
  lVar5 = (uVar12 & uVar18 ^ (uVar12 ^ uVar18) & uVar15) +
          ((uVar18 >> 0x1c | uVar18 << 0x24) ^ (uVar18 >> 0x22 | uVar18 * 0x40000000) ^
          (uVar18 >> 0x27 | uVar18 * 0x2000000));
  uVar15 = lVar5 + -0x2c6b6c1b4c7f128e + lVar23;
  lVar8 = ((uVar14 >> 0x29 | uVar14 * 0x800000) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
          (uVar14 >> 0xe | uVar14 << 0x32)) + (~uVar14 & uVar10 ^ uVar21 & uVar14) + param_1[0x14];
  uVar10 = lVar8 + 0x1b84e7b646271445 + lVar17 + lVar22 * 2 + lVar7;
  uVar9 = ((uVar18 ^ uVar15) & uVar12 ^ uVar18 & uVar15) + 0x85121b90018a0087 +
          lVar8 + lVar7 + lVar22 +
          ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
          (uVar15 >> 0x27 | uVar15 * 0x2000000));
  lVar22 = ((uVar10 >> 0x29 | uVar10 * 0x800000) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
           (uVar10 >> 0xe | uVar10 << 0x32)) + (~uVar10 & uVar21 ^ uVar14 & uVar10) + param_1[0x15];
  uVar12 = lVar22 + -0x16330b54644a1c87 + lVar16 + lVar2 * 2 + lVar4;
  uVar18 = ((uVar15 ^ uVar9) & uVar18 ^ uVar15 & uVar9) + 0x9ae9fe965860d808 +
           lVar22 + lVar4 + lVar2 +
           ((uVar9 >> 0x1c | uVar9 << 0x24) ^ (uVar9 >> 0x22 | uVar9 * 0x40000000) ^
           (uVar9 >> 0x27 | uVar9 * 0x2000000));
  lVar4 = ((uVar12 >> 0x29 | uVar12 * 0x800000) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
          (uVar12 >> 0xe | uVar12 << 0x32)) + (~uVar12 & uVar14 ^ uVar10 & uVar12) + param_1[0x16];
  local_res8 = lVar4 + 0x27c285216e5e8e09 + lVar20 + lVar3 * 2 + lVar19;
  uVar15 = ((uVar9 ^ uVar18) & uVar15 ^ uVar9 & uVar18) + 0x5cf851e97c61584 +
           lVar4 + lVar19 + lVar3 +
           ((uVar18 >> 0x1c | uVar18 << 0x24) ^ (uVar18 >> 0x22 | uVar18 * 0x40000000) ^
           (uVar18 >> 0x27 | uVar18 * 0x2000000));
  lVar4 = ((local_res8 >> 0x29 | local_res8 * 0x800000) ^ (local_res8 >> 0x12 | local_res8 << 0x2e)
          ^ (local_res8 >> 0xe | local_res8 << 0x32)) + (~local_res8 & uVar10 ^ uVar12 & local_res8)
          + param_1[0x17];
  local_res10 = lVar4 + -0x268ac466d9da1b4 + lVar5 + lVar23 * 2 + lVar6;
  uVar14 = ((uVar18 ^ uVar15) & uVar9 ^ uVar18 & uVar15) + 0x2a02bfd4dee170da +
           lVar4 + lVar6 + lVar23 +
           ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
           (uVar15 >> 0x27 | uVar15 * 0x2000000));
  lVar4 = 0;
  do {
    lVar4 = lVar4 + 0x10;
    uVar21 = 0;
    do {
      uVar1 = (uint)uVar21;
      uVar13 = (ulonglong)(uVar1 + 1 & 0xf);
      uVar11 = param_1[(ulonglong)(uVar1 - 2 & 0xf) + 8];
      param_1[uVar21 + 8] =
           param_1[uVar21 + 8] +
           (uVar11 >> 6 ^ (uVar11 >> 0x3d | uVar11 << 3) ^ (uVar11 >> 0x13 | uVar11 << 0x2d));
      uVar11 = param_1[uVar13 + 8];
      uVar11 = (uVar11 >> 7 ^
               (uVar11 >> 8 | uVar11 << 0x38) ^
               (uVar11 >> 1 | (ulonglong)((uVar11 & 1) != 0) << 0x3f)) + param_1[uVar21 + 8];
      param_1[uVar21 + 8] = uVar11;
      uVar11 = param_1[(ulonglong)(uVar1 - 7 & 0xf) + 8] + uVar11;
      param_1[uVar21 + 8] = uVar11;
      lVar2 = lVar4 * 8 + uVar21 * 8;
      lVar3 = uVar11 + ((local_res10 >> 0x29 | local_res10 << 0x17) ^
                        (local_res10 >> 0x12 | local_res10 << 0x2e) ^
                       (local_res10 >> 0xe | local_res10 << 0x32)) +
                       (~local_res10 & uVar12 ^ local_res8 & local_res10) +
                       *(longlong *)(&DAT_18002ad80 + lVar2) + uVar10;
      uVar10 = lVar3 + uVar9;
      uVar9 = ((uVar15 ^ uVar14) & uVar18 ^ uVar15 & uVar14) +
              lVar3 + ((uVar14 >> 0x1c | uVar14 << 0x24) ^ (uVar14 >> 0x22 | uVar14 << 0x1e) ^
                      (uVar14 >> 0x27 | uVar14 << 0x19));
      uVar11 = param_1[(ulonglong)(uVar1 - 1 & 0xf) + 8];
      param_1[uVar21 + 9] =
           param_1[uVar21 + 9] +
           (uVar11 >> 6 ^ (uVar11 >> 0x3d | uVar11 << 3) ^ (uVar11 >> 0x13 | uVar11 << 0x2d));
      uVar11 = param_1[(ulonglong)(uVar1 + 2 & 0xf) + 8];
      uVar11 = (uVar11 >> 7 ^
               (uVar11 >> 8 | uVar11 << 0x38) ^
               (uVar11 >> 1 | (ulonglong)((uVar11 & 1) != 0) << 0x3f)) + param_1[uVar21 + 9];
      param_1[uVar21 + 9] = uVar11;
      uVar11 = param_1[(ulonglong)(uVar1 - 6 & 0xf) + 8] + uVar11;
      param_1[uVar21 + 9] = uVar11;
      lVar3 = ((uVar10 >> 0x29 | uVar10 * 0x800000) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
              (uVar10 >> 0xe | uVar10 << 0x32)) + (~uVar10 & local_res8 ^ local_res10 & uVar10) +
              *(longlong *)(&UNK_18002ad88 + lVar2) + uVar11 + uVar12;
      uVar12 = lVar3 + uVar18;
      uVar18 = ((uVar14 ^ uVar9) & uVar15 ^ uVar14 & uVar9) +
               lVar3 + ((uVar9 >> 0x1c | uVar9 << 0x24) ^ (uVar9 >> 0x22 | uVar9 * 0x40000000) ^
                       (uVar9 >> 0x27 | uVar9 * 0x2000000));
      uVar11 = param_1[(ulonglong)(uVar1 & 0xf) + 8];
      param_1[uVar21 + 10] =
           param_1[uVar21 + 10] +
           (uVar11 >> 6 ^ (uVar11 >> 0x3d | uVar11 << 3) ^ (uVar11 >> 0x13 | uVar11 << 0x2d));
      uVar11 = param_1[(ulonglong)(uVar1 + 3 & 0xf) + 8];
      uVar11 = (uVar11 >> 7 ^
               (uVar11 >> 8 | uVar11 << 0x38) ^
               (uVar11 >> 1 | (ulonglong)((uVar11 & 1) != 0) << 0x3f)) + param_1[uVar21 + 10];
      param_1[uVar21 + 10] = uVar11;
      uVar11 = param_1[(ulonglong)(uVar1 - 5 & 0xf) + 8] + uVar11;
      param_1[uVar21 + 10] = uVar11;
      lVar3 = ((uVar12 >> 0x29 | uVar12 * 0x800000) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
              (uVar12 >> 0xe | uVar12 << 0x32)) + (~uVar12 & local_res10 ^ uVar10 & uVar12) +
              *(longlong *)(&UNK_18002ad90 + lVar2) + uVar11 + local_res8;
      uVar13 = param_1[uVar13 + 8];
      local_res8 = lVar3 + uVar15;
      uVar11 = uVar21 + 4;
      uVar15 = ((uVar9 ^ uVar18) & uVar14 ^ uVar9 & uVar18) +
               lVar3 + ((uVar18 >> 0x1c | uVar18 << 0x24) ^ (uVar18 >> 0x22 | uVar18 * 0x40000000) ^
                       (uVar18 >> 0x27 | uVar18 * 0x2000000));
      param_1[uVar21 + 0xb] =
           param_1[uVar21 + 0xb] +
           (uVar13 >> 6 ^ (uVar13 >> 0x3d | uVar13 << 3) ^ (uVar13 >> 0x13 | uVar13 << 0x2d));
      uVar13 = param_1[(ulonglong)((uint)uVar11 & 0xf) + 8];
      uVar13 = (uVar13 >> 7 ^
               (uVar13 >> 8 | uVar13 << 0x38) ^
               (uVar13 >> 1 | (ulonglong)((uVar13 & 1) != 0) << 0x3f)) + param_1[uVar21 + 0xb];
      param_1[uVar21 + 0xb] = uVar13;
      uVar13 = param_1[(ulonglong)(uVar1 - 4 & 0xf) + 8] + uVar13;
      param_1[uVar21 + 0xb] = uVar13;
      lVar2 = uVar13 + ((local_res8 >> 0x29 | local_res8 * 0x800000) ^
                        (local_res8 >> 0x12 | local_res8 << 0x2e) ^
                       (local_res8 >> 0xe | local_res8 << 0x32)) +
                       (~local_res8 & uVar10 ^ uVar12 & local_res8) +
                       *(longlong *)(&UNK_18002ad98 + lVar2) + local_res10;
      local_res10 = lVar2 + uVar14;
      uVar14 = ((uVar18 ^ uVar15) & uVar9 ^ uVar18 & uVar15) +
               lVar2 + ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
                       (uVar15 >> 0x27 | uVar15 * 0x2000000));
      uVar21 = uVar11;
    } while (uVar11 < 0x10);
  } while (lVar4 != 0x40);
  *param_1 = *param_1 + uVar14;
  param_1[1] = param_1[1] + uVar15;
  param_1[2] = param_1[2] + uVar18;
  param_1[3] = param_1[3] + uVar9;
  param_1[4] = param_1[4] + local_res10;
  param_1[5] = param_1[5] + local_res8;
  param_1[6] = param_1[6] + uVar12;
  param_1[7] = param_1[7] + uVar10;
  return;
}



void __cdecl std::_Xlength_error(char *param_1)

{
                    // WARNING: Could not recover jumptable at 0x000180012951. Too many branches
                    // WARNING: Treating indirect jump as call
  _Xlength_error(param_1);
  return;
}



void _Thrd_join(void)

{
                    // WARNING: Could not recover jumptable at 0x000180012957. Too many branches
                    // WARNING: Treating indirect jump as call
  _Thrd_join();
  return;
}



void _Thrd_hardware_concurrency(void)

{
                    // WARNING: Could not recover jumptable at 0x00018001295d. Too many branches
                    // WARNING: Treating indirect jump as call
  _Thrd_hardware_concurrency();
  return;
}



void _Thrd_id(void)

{
                    // WARNING: Could not recover jumptable at 0x000180012963. Too many branches
                    // WARNING: Treating indirect jump as call
  _Thrd_id();
  return;
}



void _Cnd_do_broadcast_at_thread_exit(void)

{
                    // WARNING: Could not recover jumptable at 0x000180012969. Too many branches
                    // WARNING: Treating indirect jump as call
  _Cnd_do_broadcast_at_thread_exit();
  return;
}



void __cdecl std::_Throw_Cpp_error(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00018001296f. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _Throw_Cpp_error(param_1);
  return;
}



undefined8 * FUN_180012980(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



void FUN_1800129b0(size_t param_1)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = malloc(param_1);
  while( true ) {
    if (pvVar2 != (void *)0x0) {
      return;
    }
    iVar1 = _callnewh(param_1);
    if (iVar1 == 0) break;
    pvVar2 = malloc(param_1);
  }
  if (param_1 == 0xffffffffffffffff) {
                    // WARNING: Subroutine does not return
    FUN_18000a140();
  }
                    // WARNING: Subroutine does not return
  FUN_1800130e0();
}



void __cdecl free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x00018001397c. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



void FUN_180012a10(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  return;
}



void FUN_180012a20(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  return;
}



undefined8 FUN_180012a30(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  FUN_180012a50(param_2,param_4,*(undefined8 *)(param_4 + 0x38));
  return 1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_180012a50(undefined8 param_1,longlong param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  char *pcVar5;
  longlong lVar6;
  uint uVar7;
  byte bVar8;
  char *pcVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  iVar2 = *param_3;
  pbVar10 = (byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8));
  bVar1 = pbVar10[3];
  if (2 < (*pbVar10 & 7)) {
    if ((bVar1 & 0x1f) != 0) {
      pbVar10 = pbVar10 + (ulonglong)(bVar1 & 0x1f) + 4;
      uVar7 = 0;
      pbVar11 = pbVar10;
      if (bVar1 >> 5 != 0) {
        do {
          pbVar10 = pbVar11 + 3;
          if (*pbVar11 >> 3 != 0) {
            pbVar10 = pbVar11 + (ulonglong)(uint)(*pbVar11 >> 3) + 6;
          }
          uVar7 = uVar7 + 1;
          pbVar11 = pbVar10;
        } while (uVar7 < bVar1 >> 5);
      }
      uVar7 = 0;
      if ((bVar1 & 0x1f) != 0) {
        do {
          bVar8 = *pbVar10;
          pcVar9 = (char *)(ulonglong)bVar8;
          if (((bVar8 < 4) ||
              (pcVar9 = (char *)(ulonglong)(bVar8 & 0xf), (byte)((bVar8 & 0xf) - 8) < 3)) ||
             (pcVar9 = (char *)(ulonglong)(bVar8 & 7), (byte)((bVar8 & 7) - 4) < 4)) {
            if ((char)pcVar9 == '\0') {
              return;
            }
            if (3 < bVar8) {
              pcVar9 = (char *)(ulonglong)(bVar8 & 0xf);
              if ((2 < (byte)((bVar8 & 0xf) - 8)) &&
                 (pcVar9 = (char *)(ulonglong)(bVar8 & 7), 3 < (byte)((bVar8 & 7) - 4)))
              goto LAB_180012b58;
              bVar8 = (byte)pcVar9;
              if (0x20 < bVar8) goto switchD_180012b7c_caseD_4;
            }
          }
          else {
LAB_180012b58:
            if ((bVar8 & 0x3f) != 0x20) goto switchD_180012b7c_caseD_4;
            bVar8 = 0x20;
          }
          bVar8 = *(byte *)((longlong)&UINT_180012bf4 + (ulonglong)bVar8);
          pcVar5 = (char *)(ulonglong)bVar8;
          uVar3 = (&switchD_180012b7c::switchdataD_180012be0)[(longlong)pcVar5];
                    // WARNING (jumptable): Sanity check requires truncation of jumptable
                    // WARNING: Could not find normalized switch variable to match jumptable
          switch(bVar8) {
          case 0:
            lVar6 = 2;
            break;
          case 1:
            lVar6 = 5;
            break;
          case 2:
            lVar6 = 3;
            break;
          case 3:
            lVar6 = 1;
            break;
          case 4:
switchD_180012b7c_caseD_4:
            FUN_180012a10();
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          case 5:
            *pcVar5 = *pcVar5 + bVar8;
            *pcVar5 = *pcVar5 + bVar8;
            *pcVar9 = *pcVar9 + bVar8;
            pcVar9 = (char *)((ulonglong)uVar3 + 0x18200a7fe);
            *pcVar9 = *pcVar9 + (char)(uVar7 >> 8);
            *pcVar5 = *pcVar5 + bVar8;
            *pcVar5 = *pcVar5 + bVar8;
            *pcVar5 = *pcVar5 + bVar8;
            *pcVar5 = *pcVar5 + bVar8;
            *(char *)((longlong)pcVar5 * 2) = *(char *)((longlong)pcVar5 * 2) + bVar8;
                    // WARNING: Could not recover jumptable at 0x000180020118. Too many branches
                    // WARNING: Treating indirect jump as call
            (*(code *)(longlong)iVar2)((ulonglong)uVar3 + 0x180000000,bVar8);
            return;
          }
          pbVar10 = pbVar10 + lVar6;
          uVar7 = uVar7 + 1;
        } while (uVar7 < (bVar1 & 0x1f));
      }
    }
  }
  return;
}



undefined8 FUN_180012c20(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  FUN_180012a50(param_2,param_4,lVar1 + 4);
  if ((*(uint *)(lVar1 + 4) & ((*(byte *)(param_1 + 4) & 0x66) != 0) + 1) == 0) {
    return 1;
  }
  uVar2 = __CxxFrameHandler4(param_1,param_2,param_3,param_4);
  return uVar2;
}



// WARNING: This is an inlined function
// Library Function - Single Match
//  __chkstk
// 
// Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012

void __chkstk(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    puVar2 = StackLimit;
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}



// WARNING: This is an inlined function

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_180030500) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_180012a10(_StackCookie);
  return;
}



ulonglong FUN_180012d20(undefined1 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  
  if (param_2 == 0) {
    uVar2 = FUN_180012e90(param_3 != 0);
    return uVar2;
  }
  if (param_2 == 1) {
    uVar2 = FUN_180012d80(param_1,param_3);
    return uVar2;
  }
  if (param_2 == 2) {
    bVar1 = FUN_180013360();
    return (ulonglong)bVar1;
  }
  if (param_2 == 3) {
    bVar1 = FUN_180013390();
    return (ulonglong)bVar1;
  }
  return 1;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

undefined8 FUN_180012d80(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  longlong *plVar6;
  undefined8 uVar7;
  
  cVar3 = FUN_180013460(0);
  if (cVar3 != '\0') {
    uVar4 = FUN_180013250();
    bVar2 = true;
    if (DAT_180030688 != 0) {
      FUN_1800135b0(7);
      pcVar1 = (code *)swi(3);
      uVar7 = (*pcVar1)();
      return uVar7;
    }
    DAT_180030688 = 1;
    cVar3 = FUN_1800132e0();
    if (cVar3 != '\0') {
      FUN_1800135c0();
      FUN_180013200();
      FUN_180013230();
      iVar5 = _initterm_e(&DAT_180014280,&DAT_180014288);
      if (iVar5 == 0) {
        cVar3 = FUN_1800132a0();
        if (cVar3 != '\0') {
          _initterm(&DAT_180014270,&DAT_180014278);
          DAT_180030688 = 2;
          bVar2 = false;
        }
      }
    }
    FUN_180013540(uVar4);
    if (!bVar2) {
      plVar6 = (longlong *)FUN_1800135a0();
      if (*plVar6 != 0) {
        cVar3 = FUN_1800134a0(plVar6);
        if (cVar3 != '\0') {
          (*(code *)*plVar6)(param_1,2,param_2);
        }
      }
      DAT_180030664 = DAT_180030664 + 1;
      return 1;
    }
  }
  return 0;
}



ulonglong FUN_180012e90(undefined1 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  
  if (DAT_180030664 < 1) {
    return 0;
  }
  DAT_180030664 = DAT_180030664 + -1;
  uVar2 = FUN_180013250();
  if (DAT_180030688 == 2) {
    uVar5 = uVar2;
    FUN_180013400();
    FUN_180013210();
    FUN_180013610();
    DAT_180030688 = 0;
    FUN_180013540(uVar2);
    bVar3 = FUN_180013570(param_1,0,param_3,param_4,uVar5);
    FUN_180013440();
    return (ulonglong)bVar3;
  }
  FUN_1800135b0(7);
  pcVar1 = (code *)swi(3);
  uVar4 = (*pcVar1)();
  return uVar4;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Removing unreachable block (ram,0x000180012ff9)
// WARNING: Removing unreachable block (ram,0x000180012f8a)
// WARNING: Removing unreachable block (ram,0x00018001303a)

int FUN_180012f30(undefined8 param_1,int param_2,longlong param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 == 0) && (DAT_180030664 < 1)) {
    return 0;
  }
  if ((param_2 - 1U < 2) && (iVar1 = FUN_180012d20(param_1,param_2,param_3), iVar1 == 0)) {
    return 0;
  }
  iVar1 = FUN_1800131d0(param_1,param_2,param_3);
  if ((param_2 == 1) && (iVar1 == 0)) {
    FUN_1800131d0(param_1,0,param_3);
    FUN_180012e90(param_3 != 0);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = FUN_180012d20(param_1,param_2,param_3);
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}



void entry(undefined8 param_1,int param_2,undefined8 param_3)

{
  if (param_2 == 1) {
    FUN_180013110();
  }
  FUN_180012f30(param_1,param_2,param_3);
  return;
}



undefined8 * FUN_1800130b0(undefined8 *param_1)

{
  param_1[2] = 0;
  param_1[1] = "bad allocation";
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



void FUN_1800130e0(void)

{
  undefined1 local_28 [40];
  
  FUN_1800130b0(local_28);
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_18002c700);
}



void __cdecl free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x00018001397c. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180013110(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10 [3];
  _FILETIME local_18 [2];
  
  if (DAT_180030500 != 0x2b992ddfa232) {
    _DAT_180030540 = ~DAT_180030500;
    return;
  }
  local_res8.dwLowDateTime = 0;
  local_res8.dwHighDateTime = 0;
  GetSystemTimeAsFileTime(&local_res8);
  local_18[0] = local_res8;
  DVar1 = GetCurrentThreadId();
  local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
  DVar1 = GetCurrentProcessId();
  local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
  QueryPerformanceCounter(local_res10);
  DAT_180030500 =
       (local_res10[0].QuadPart << 0x20 ^ local_res10[0].QuadPart ^ (ulonglong)local_18[0] ^
       (ulonglong)local_18) & 0xffffffffffff;
  if (DAT_180030500 == 0x2b992ddfa232) {
    DAT_180030500 = 0x2b992ddfa233;
  }
  _DAT_180030540 = ~DAT_180030500;
  return;
}



undefined8 FUN_1800131d0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



void FUN_180013200(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013207. Too many branches
                    // WARNING: Treating indirect jump as call
  InitializeSListHead(&DAT_180030670);
  return;
}



void FUN_180013210(void)

{
  __std_type_info_destroy_list(&DAT_180030670);
  return;
}



undefined * FUN_180013220(void)

{
  return &DAT_180030680;
}



void FUN_180013230(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_18000cc70();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_180013220();
  *puVar1 = *puVar1 | 2;
  return;
}



undefined8 FUN_180013250(void)

{
  int iVar1;
  void *pvVar2;
  bool bVar3;
  
  iVar1 = FUN_180013930();
  if (iVar1 != 0) {
    pvVar2 = (void *)0x0;
    LOCK();
    bVar3 = DAT_180030690 == (void *)0x0;
    if (bVar3) {
      DAT_180030690 = StackBase;
    }
    else {
      pvVar2 = DAT_180030690;
    }
    UNLOCK();
    while (!bVar3) {
      if (StackBase == pvVar2) {
        return 1;
      }
      pvVar2 = (void *)0x0;
      LOCK();
      bVar3 = DAT_180030690 == (void *)0x0;
      if (bVar3) {
        DAT_180030690 = StackBase;
      }
      else {
        pvVar2 = DAT_180030690;
      }
      UNLOCK();
    }
  }
  return 0;
}



undefined4 FUN_1800132a0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_180013930();
  if (iVar1 != 0) {
    FUN_180013670();
    return 1;
  }
  uVar2 = FUN_180013920();
  iVar1 = _configure_narrow_argv(uVar2);
  if (iVar1 == 0) {
    _initialize_narrow_environment();
    return 1;
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_1800132e0(void)

{
  int iVar1;
  
  if (DAT_180030699 == '\0') {
    iVar1 = FUN_180013930();
    if (iVar1 == 0) {
      _DAT_1800306a0 = 0xffffffffffffffff;
      uRam00000001800306a8 = 0xffffffffffffffff;
      _DAT_1800306b0 = 0xffffffffffffffff;
      _DAT_1800306b8 = 0xffffffffffffffff;
      uRam00000001800306c0 = 0xffffffffffffffff;
      _DAT_1800306c8 = 0xffffffffffffffff;
    }
    else {
      iVar1 = _initialize_onexit_table(&DAT_1800306a0);
      if (iVar1 != 0) {
        return 0;
      }
      iVar1 = _initialize_onexit_table(&DAT_1800306b8);
      if (iVar1 != 0) {
        return 0;
      }
    }
    DAT_180030699 = '\x01';
  }
  return 1;
}



undefined1 FUN_180013360(void)

{
  char cVar1;
  
  cVar1 = FUN_1800139f0();
  if (cVar1 != '\0') {
    cVar1 = FUN_1800139f0();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_1800139f0();
  }
  return 0;
}



undefined1 FUN_180013390(void)

{
  FUN_1800139f0();
  FUN_1800139f0();
  return 1;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_1800133b0(undefined8 param_1,int param_2,undefined8 param_3,code *param_4,
                  undefined4 param_5,undefined8 param_6)

{
  int iVar1;
  
  iVar1 = FUN_180013930();
  if ((iVar1 == 0) && (param_2 == 1)) {
    (*param_4)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}



void FUN_180013400(void)

{
  int iVar1;
  
  iVar1 = FUN_180013930();
  if (iVar1 != 0) {
    _execute_onexit_table(&DAT_1800306a0);
    return;
  }
  iVar1 = FUN_180013a00();
  if (iVar1 == 0) {
    _cexit();
    return;
  }
  return;
}



void FUN_180013440(void)

{
  FUN_1800139f0(0);
  FUN_1800139f0();
  return;
}



undefined1 FUN_180013460(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    DAT_180030698 = 1;
  }
  FUN_180013670();
  cVar1 = FUN_1800139f0();
  if (cVar1 != '\0') {
    cVar1 = FUN_1800139f0();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_1800139f0(0);
  }
  return 0;
}



// WARNING: Removing unreachable block (ram,0x000180013526)
// WARNING: Enum "SectionFlags": Some values do not have unique names

ulonglong FUN_1800134a0(longlong param_1)

{
  IMAGE_SECTION_HEADER *pIVar1;
  
  pIVar1 = &IMAGE_SECTION_HEADER_180000218;
  while( true ) {
    if (pIVar1 == (IMAGE_SECTION_HEADER *)&DAT_180000308) {
      return 0x180000300;
    }
    if (((ulonglong)(uint)pIVar1->VirtualAddress <= param_1 - 0x180000000U) &&
       (param_1 - 0x180000000U <
        (ulonglong)((pIVar1->Misc).PhysicalAddress + pIVar1->VirtualAddress))) break;
    pIVar1 = pIVar1 + 1;
  }
  if ((int)pIVar1->Characteristics < 0) {
    return (ulonglong)pIVar1 & 0xffffffffffffff00;
  }
  return CONCAT71((int7)((ulonglong)pIVar1 >> 8),1);
}



undefined8 FUN_180013540(char param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_180013930();
  uVar1 = DAT_180030690;
  if (((int)uVar2 != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_180030690 = 0;
    UNLOCK();
    uVar2 = uVar1;
  }
  return uVar2;
}



undefined1 FUN_180013570(undefined1 param_1,char param_2)

{
  if ((DAT_180030698 == '\0') || (param_2 == '\0')) {
    FUN_1800139f0();
    FUN_1800139f0(param_1);
  }
  return 1;
}



undefined * FUN_1800135a0(void)

{
  return &DAT_1800306e0;
}



void FUN_1800135b0(undefined4 param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(param_1);
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Removing unreachable block (ram,0x0001800135e0)
// WARNING: Removing unreachable block (ram,0x0001800135e8)
// WARNING: Removing unreachable block (ram,0x0001800135ee)

void FUN_1800135c0(void)

{
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Removing unreachable block (ram,0x000180013630)
// WARNING: Removing unreachable block (ram,0x000180013638)
// WARNING: Removing unreachable block (ram,0x00018001363e)

void FUN_180013610(void)

{
  return;
}



void _guard_check_icall(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x000180013777)
// WARNING: Removing unreachable block (ram,0x000180013765)
// WARNING: Removing unreachable block (ram,0x000180013753)
// WARNING: Removing unreachable block (ram,0x00018001372c)
// WARNING: Removing unreachable block (ram,0x0001800136a7)
// WARNING: Removing unreachable block (ram,0x000180013682)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_180013670(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulonglong in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  iVar4 = *piVar1;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar5 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    uVar8 = *puVar2 & 0xfff3ff0;
    _DAT_180030558 = 0x8000;
    _DAT_180030560 = 0xffffffffffffffff;
    if ((((uVar8 == 0x106c0) || (uVar8 == 0x20660)) || (uVar8 == 0x20670)) ||
       ((uVar8 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar8 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_1800306d4 = DAT_1800306d4 | 1;
    }
  }
  uVar13 = 0;
  uVar8 = 0;
  uVar11 = 0;
  if (iVar4 < 7) {
    uVar12 = 0;
    uVar10 = 0;
  }
  else {
    piVar1 = (int *)cpuid_Extended_Feature_Enumeration_info(7);
    uVar12 = piVar1[1];
    uVar10 = piVar1[2];
    if ((uVar12 >> 9 & 1) != 0) {
      DAT_1800306d4 = DAT_1800306d4 | 2;
    }
    if (0 < *piVar1) {
      lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
      uVar13 = *(uint *)(lVar3 + 8);
    }
    if (0x23 < iVar4) {
      lVar3 = cpuid(0x24);
      uVar8 = *(uint *)(lVar3 + 4);
    }
    if (0x28 < iVar4) {
      lVar3 = cpuid(0x29);
      uVar11 = *(uint *)(lVar3 + 4);
    }
  }
  _DAT_180030550 = 1;
  DAT_180030554 = 2;
  uVar6 = DAT_180030568 & 0xfffffffffffffffe;
  if ((uVar5 >> 0x14 & 1) != 0) {
    _DAT_180030550 = 2;
    DAT_180030554 = 6;
    uVar6 = DAT_180030568 & 0xffffffffffffffee;
  }
  DAT_180030568 = uVar6;
  if ((uVar5 >> 0x1b & 1) == 0) {
    return 0;
  }
  uVar6 = xinuse(0);
  uVar9 = in_XCR0 & uVar6 & 0xffffffff;
  uVar6 = DAT_180030568;
  if (((uVar5 >> 0x1c & 1) == 0) || (bVar7 = (byte)uVar9, (bVar7 & 6) != 6)) goto LAB_1800138e4;
  _DAT_180030550 = 3;
  uVar5 = DAT_180030554 | 8;
  if ((uVar12 & 0x20) == 0) {
LAB_18001388a:
    DAT_180030568 = uVar6;
    DAT_180030554 = uVar5;
    uVar5 = DAT_180030554;
    uVar6 = DAT_180030568;
  }
  else {
    _DAT_180030550 = 5;
    uVar5 = DAT_180030554 | 0x28;
    uVar6 = DAT_180030568 & 0xfffffffffffffffd;
    if ((uVar12 & 0xd0030000) == 0xd0030000) {
      if ((bVar7 & 0xe0) != 0xe0) goto LAB_18001388a;
      DAT_180030554 = DAT_180030554 | 0x68;
      _DAT_180030550 = 6;
      uVar5 = DAT_180030554;
      uVar6 = DAT_180030568 & 0xffffffffffffffd9;
    }
  }
  DAT_180030568 = uVar6;
  DAT_180030554 = uVar5;
  if ((uVar10 >> 0x17 & 1) != 0) {
    DAT_180030568 = DAT_180030568 & 0xfffffffffeffffff;
  }
  uVar6 = DAT_180030568;
  if (((uVar13 >> 0x13 & 1) != 0) && ((bVar7 & 0xe0) == 0xe0)) {
    _DAT_1800306d8 = uVar8 & 0xff;
    uVar6 = DAT_180030568 & 0xfffffffffeffffd0;
    if (1 < _DAT_1800306d8) {
      uVar6 = DAT_180030568 & 0xfffffffffeffff90;
    }
  }
LAB_1800138e4:
  DAT_180030568 = uVar6;
  if ((((uVar13 >> 0x15 & 1) != 0) && ((uVar11 & 1) != 0)) && ((uVar9 >> 0x13 & 1) != 0)) {
    DAT_180030568 = DAT_180030568 & 0xffffffffffffff7f;
  }
  return 0;
}



undefined8 FUN_180013920(void)

{
  return 1;
}



bool FUN_180013930(void)

{
  return DAT_180030570 != 0;
}



void __CxxFrameHandler4(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013940. Too many branches
                    // WARNING: Treating indirect jump as call
  __CxxFrameHandler4();
  return;
}



void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013946. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    // WARNING: Could not recover jumptable at 0x00018001394c. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}



char * __cdecl strchr(char *_Str,int _Val)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013952. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = strchr(_Str,_Val);
  return pcVar1;
}



char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013958. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}



void __std_exception_copy(void)

{
                    // WARNING: Could not recover jumptable at 0x00018001395e. Too many branches
                    // WARNING: Treating indirect jump as call
  __std_exception_copy();
  return;
}



void __std_exception_destroy(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013964. Too many branches
                    // WARNING: Treating indirect jump as call
  __std_exception_destroy();
  return;
}



void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00018001396a. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



void __std_type_info_destroy_list(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013976. Too many branches
                    // WARNING: Treating indirect jump as call
  __std_type_info_destroy_list();
  return;
}



void __cdecl free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x00018001397c. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



void * __cdecl malloc(size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013982. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = malloc(_Size);
  return pvVar1;
}



float __cdecl cosf(float _X)

{
  float fVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013988. Too many branches
                    // WARNING: Treating indirect jump as call
  fVar1 = cosf(_X);
  return fVar1;
}



float __cdecl floorf(float _X)

{
  float fVar1;
  
                    // WARNING: Could not recover jumptable at 0x00018001398e. Too many branches
                    // WARNING: Treating indirect jump as call
  fVar1 = floorf(_X);
  return fVar1;
}



float __cdecl powf(float _X,float _Y)

{
  float fVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013994. Too many branches
                    // WARNING: Treating indirect jump as call
  fVar1 = powf(_X,_Y);
  return fVar1;
}



float __cdecl sinf(float _X)

{
  float fVar1;
  
                    // WARNING: Could not recover jumptable at 0x00018001399a. Too many branches
                    // WARNING: Treating indirect jump as call
  fVar1 = sinf(_X);
  return fVar1;
}



float __cdecl sqrtf(float _X)

{
  float fVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800139a0. Too many branches
                    // WARNING: Treating indirect jump as call
  fVar1 = sqrtf(_X);
  return fVar1;
}



int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800139a6. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}



size_t __cdecl strlen(char *_Str)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800139ac. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = strlen(_Str);
  return sVar1;
}



int __cdecl _callnewh(size_t _Size)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800139b2. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _callnewh(_Size);
  return iVar1;
}



void _initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139b8. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm();
  return;
}



void _initterm_e(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139be. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm_e();
  return;
}



void _seh_filter_dll(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139c4. Too many branches
                    // WARNING: Treating indirect jump as call
  _seh_filter_dll();
  return;
}



void _configure_narrow_argv(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139ca. Too many branches
                    // WARNING: Treating indirect jump as call
  _configure_narrow_argv();
  return;
}



void _initialize_narrow_environment(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139d0. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_narrow_environment();
  return;
}



void _initialize_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139d6. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_onexit_table();
  return;
}



void _execute_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139dc. Too many branches
                    // WARNING: Treating indirect jump as call
  _execute_onexit_table();
  return;
}



void __cdecl _cexit(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800139e2. Too many branches
                    // WARNING: Treating indirect jump as call
  _cexit();
  return;
}



undefined1 FUN_1800139f0(void)

{
  return 1;
}



undefined8 FUN_180013a00(void)

{
  return 0;
}



// WARNING: This is an inlined function

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    // WARNING: Could not recover jumptable at 0x000180013a20. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



// WARNING: This is an inlined function
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



undefined8 FUN_180013b30(void)

{
  return 0;
}



undefined8 FUN_180013b50(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x90) = 4;
  return 0;
}



undefined8 FUN_180013b80(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x90) = 0x200;
  return 0;
}



undefined8 FUN_180013be0(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x1a8) = 4;
  return 0;
}



undefined8 FUN_180013c10(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x1a8) = 0x200;
  return 0;
}



undefined8 FUN_180013c60(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x4f0) = 0x200;
  return 0;
}



undefined8 FUN_180013c90(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x4f0) = **(undefined4 **)(param_2 + 0x38);
  return 0;
}



void FUN_180013cc0(undefined8 param_1,longlong param_2)

{
  FUN_180013540(*(undefined1 *)(param_2 + 0x60));
  return;
}



void FUN_180013ce0(undefined8 param_1,longlong param_2)

{
  FUN_180013540(*(undefined1 *)(param_2 + 0x20));
  return;
}



void FUN_180013cfa(void)

{
  FUN_180013440();
  return;
}



void FUN_180013d10(undefined8 *param_1,longlong param_2)

{
  FUN_1800133b0(*(undefined8 *)(param_2 + 0x60),*(undefined4 *)(param_2 + 0x68),
                *(undefined8 *)(param_2 + 0x70),FUN_180012d20,*(undefined4 *)*param_1,param_1);
  return;
}



bool FUN_180013d50(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}


