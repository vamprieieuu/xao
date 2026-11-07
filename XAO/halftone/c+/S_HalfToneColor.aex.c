typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned long long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long long    uint64_t;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef short    wchar_t;
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

typedef uint64_t __uint64;

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef ulong DWORD;

typedef void *LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef long LONG;

typedef void *HANDLE;

typedef ulonglong ULONG_PTR;

typedef ushort WORD;

typedef struct _LIST_ENTRY _LIST_ENTRY, *P_LIST_ENTRY;

typedef struct _LIST_ENTRY LIST_ENTRY;

struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
};

struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD SpareWORD;
};

struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
};

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef LONG (*PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *);

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _CONTEXT *PCONTEXT;

typedef void *PVOID;

typedef ulonglong DWORD64;

typedef union _union_54 _union_54, *P_union_54;

typedef struct _M128A _M128A, *P_M128A;

typedef struct _M128A M128A;

typedef struct _XSAVE_FORMAT _XSAVE_FORMAT, *P_XSAVE_FORMAT;

typedef struct _XSAVE_FORMAT XSAVE_FORMAT;

typedef XSAVE_FORMAT XMM_SAVE_AREA32;

typedef struct _struct_55 _struct_55, *P_struct_55;

typedef ulonglong ULONGLONG;

typedef longlong LONGLONG;

typedef uchar BYTE;

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

struct _struct_55 {
    M128A Header[2];
    M128A Legacy[8];
    M128A Xmm0;
    M128A Xmm1;
    M128A Xmm2;
    M128A Xmm3;
    M128A Xmm4;
    M128A Xmm5;
    M128A Xmm6;
    M128A Xmm7;
    M128A Xmm8;
    M128A Xmm9;
    M128A Xmm10;
    M128A Xmm11;
    M128A Xmm12;
    M128A Xmm13;
    M128A Xmm14;
    M128A Xmm15;
};

struct _M128A {
    ULONGLONG Low;
    LONGLONG High;
};

struct _XSAVE_FORMAT {
    WORD ControlWord;
    WORD StatusWord;
    BYTE TagWord;
    BYTE Reserved1;
    WORD ErrorOpcode;
    DWORD ErrorOffset;
    WORD ErrorSelector;
    WORD Reserved2;
    DWORD DataOffset;
    WORD DataSelector;
    WORD Reserved3;
    DWORD MxCsr;
    DWORD MxCsr_Mask;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
};

union _union_54 {
    XMM_SAVE_AREA32 FltSave;
    struct _struct_55 s;
};

struct _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    WORD SegCs;
    WORD SegDs;
    WORD SegEs;
    WORD SegFs;
    WORD SegGs;
    WORD SegSs;
    DWORD EFlags;
    DWORD64 Dr0;
    DWORD64 Dr1;
    DWORD64 Dr2;
    DWORD64 Dr3;
    DWORD64 Dr6;
    DWORD64 Dr7;
    DWORD64 Rax;
    DWORD64 Rcx;
    DWORD64 Rdx;
    DWORD64 Rbx;
    DWORD64 Rsp;
    DWORD64 Rbp;
    DWORD64 Rsi;
    DWORD64 Rdi;
    DWORD64 R8;
    DWORD64 R9;
    DWORD64 R10;
    DWORD64 R11;
    DWORD64 R12;
    DWORD64 R13;
    DWORD64 R14;
    DWORD64 R15;
    DWORD64 Rip;
    union _union_54 u;
    M128A VectorRegister[26];
    DWORD64 VectorControl;
    DWORD64 DebugControl;
    DWORD64 LastBranchToRip;
    DWORD64 LastBranchFromRip;
    DWORD64 LastExceptionToRip;
    DWORD64 LastExceptionFromRip;
};

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

typedef PVOID PSECURITY_DESCRIPTOR;

typedef struct _ACL _ACL, *P_ACL;

struct _ACL {
    BYTE AclRevision;
    BYTE Sbz1;
    WORD AclSize;
    WORD AceCount;
    WORD Sbz2;
};

typedef char CHAR;

typedef union _LARGE_INTEGER _LARGE_INTEGER, *P_LARGE_INTEGER;

typedef struct _struct_19 _struct_19, *P_struct_19;

typedef struct _struct_20 _struct_20, *P_struct_20;

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

typedef union _LARGE_INTEGER LARGE_INTEGER;

typedef struct _ACL ACL;

typedef ACL *PACL;

typedef struct _RUNTIME_FUNCTION _RUNTIME_FUNCTION, *P_RUNTIME_FUNCTION;

struct _RUNTIME_FUNCTION {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD UnwindData;
};

typedef struct _RUNTIME_FUNCTION *PRUNTIME_FUNCTION;

typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution=0,
    ExceptionContinueSearch=1,
    ExceptionNestedException=2,
    ExceptionCollidedUnwind=3
} _EXCEPTION_DISPOSITION;

typedef enum _EXCEPTION_DISPOSITION EXCEPTION_DISPOSITION;

typedef EXCEPTION_DISPOSITION (EXCEPTION_ROUTINE)(struct _EXCEPTION_RECORD *, PVOID, struct _CONTEXT *, PVOID);

typedef struct _SID_IDENTIFIER_AUTHORITY _SID_IDENTIFIER_AUTHORITY, *P_SID_IDENTIFIER_AUTHORITY;

typedef struct _SID_IDENTIFIER_AUTHORITY *PSID_IDENTIFIER_AUTHORITY;

struct _SID_IDENTIFIER_AUTHORITY {
    BYTE Value[6];
};

typedef struct _M128A *PM128A;

typedef struct _UNWIND_HISTORY_TABLE_ENTRY _UNWIND_HISTORY_TABLE_ENTRY, *P_UNWIND_HISTORY_TABLE_ENTRY;

typedef struct _UNWIND_HISTORY_TABLE_ENTRY UNWIND_HISTORY_TABLE_ENTRY;

struct _UNWIND_HISTORY_TABLE_ENTRY {
    DWORD64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
};

typedef union _union_61 _union_61, *P_union_61;

typedef struct _struct_62 _struct_62, *P_struct_62;

struct _struct_62 {
    PM128A Xmm0;
    PM128A Xmm1;
    PM128A Xmm2;
    PM128A Xmm3;
    PM128A Xmm4;
    PM128A Xmm5;
    PM128A Xmm6;
    PM128A Xmm7;
    PM128A Xmm8;
    PM128A Xmm9;
    PM128A Xmm10;
    PM128A Xmm11;
    PM128A Xmm12;
    PM128A Xmm13;
    PM128A Xmm14;
    PM128A Xmm15;
};

union _union_61 {
    PM128A FloatingContext[16];
    struct _struct_62 s;
};

typedef union _union_63 _union_63, *P_union_63;

typedef ulonglong *PDWORD64;

typedef struct _struct_64 _struct_64, *P_struct_64;

struct _struct_64 {
    PDWORD64 Rax;
    PDWORD64 Rcx;
    PDWORD64 Rdx;
    PDWORD64 Rbx;
    PDWORD64 Rsp;
    PDWORD64 Rbp;
    PDWORD64 Rsi;
    PDWORD64 Rdi;
    PDWORD64 R8;
    PDWORD64 R9;
    PDWORD64 R10;
    PDWORD64 R11;
    PDWORD64 R12;
    PDWORD64 R13;
    PDWORD64 R14;
    PDWORD64 R15;
};

union _union_63 {
    PDWORD64 IntegerContext[16];
    struct _struct_64 s;
};

typedef struct _UNWIND_HISTORY_TABLE _UNWIND_HISTORY_TABLE, *P_UNWIND_HISTORY_TABLE;

typedef struct _UNWIND_HISTORY_TABLE *PUNWIND_HISTORY_TABLE;

struct _UNWIND_HISTORY_TABLE {
    DWORD Count;
    BYTE LocalHint;
    BYTE GlobalHint;
    BYTE Search;
    BYTE Once;
    DWORD64 LowAddress;
    DWORD64 HighAddress;
    UNWIND_HISTORY_TABLE_ENTRY Entry[12];
};

typedef CHAR *LPCSTR;

typedef CHAR *LPSTR;

typedef PVOID PSID;

typedef struct _KNONVOLATILE_CONTEXT_POINTERS _KNONVOLATILE_CONTEXT_POINTERS, *P_KNONVOLATILE_CONTEXT_POINTERS;

typedef struct _KNONVOLATILE_CONTEXT_POINTERS *PKNONVOLATILE_CONTEXT_POINTERS;

union _union_61 {
    PM128A FloatingContext[16];
    struct _struct_62 s;
};

union _union_63 {
    PDWORD64 IntegerContext[16];
    struct _struct_64 s;
};

struct _KNONVOLATILE_CONTEXT_POINTERS {
    union _union_61 u;
    union _union_63 u2;
};

typedef EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;

typedef DWORD ACCESS_MASK;

typedef DWORD LCID;

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

typedef longlong INT_PTR;

typedef DWORD ULONG;

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME *LPFILETIME;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

typedef INT_PTR (*FARPROC)(void);

typedef struct HKEY__ HKEY__, *PHKEY__;

struct HKEY__ {
    int unused;
};

typedef DWORD *LPDWORD;

typedef struct HKEY__ *HKEY;

typedef HKEY *PHKEY;

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

struct HINSTANCE__ {
    int unused;
};

typedef struct HINSTANCE__ *HINSTANCE;

typedef HINSTANCE HMODULE;

typedef void *LPCVOID;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

struct HWND__ {
    int unused;
};

typedef HANDLE HLOCAL;

typedef BYTE *LPBYTE;

typedef uint UINT;

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

typedef enum _TRUSTEE_FORM {
    TRUSTEE_IS_SID=0,
    TRUSTEE_IS_NAME=1,
    TRUSTEE_BAD_FORM=2,
    TRUSTEE_IS_OBJECTS_AND_SID=3,
    TRUSTEE_IS_OBJECTS_AND_NAME=4
} _TRUSTEE_FORM;

typedef enum _MULTIPLE_TRUSTEE_OPERATION {
    NO_MULTIPLE_TRUSTEE=0,
    TRUSTEE_IS_IMPERSONATE=1
} _MULTIPLE_TRUSTEE_OPERATION;

typedef enum _TRUSTEE_FORM TRUSTEE_FORM;

typedef enum _ACCESS_MODE {
    NOT_USED_ACCESS=0,
    GRANT_ACCESS=1,
    SET_ACCESS=2,
    DENY_ACCESS=3,
    REVOKE_ACCESS=4,
    SET_AUDIT_SUCCESS=5,
    SET_AUDIT_FAILURE=6
} _ACCESS_MODE;

typedef struct _EXPLICIT_ACCESS_A _EXPLICIT_ACCESS_A, *P_EXPLICIT_ACCESS_A;

typedef enum _ACCESS_MODE ACCESS_MODE;

typedef struct _TRUSTEE_A _TRUSTEE_A, *P_TRUSTEE_A;

typedef struct _TRUSTEE_A TRUSTEE_A;

typedef enum _MULTIPLE_TRUSTEE_OPERATION MULTIPLE_TRUSTEE_OPERATION;

typedef enum _TRUSTEE_TYPE {
    TRUSTEE_IS_UNKNOWN=0,
    TRUSTEE_IS_USER=1,
    TRUSTEE_IS_GROUP=2,
    TRUSTEE_IS_DOMAIN=3,
    TRUSTEE_IS_ALIAS=4,
    TRUSTEE_IS_WELL_KNOWN_GROUP=5,
    TRUSTEE_IS_DELETED=6,
    TRUSTEE_IS_INVALID=7,
    TRUSTEE_IS_COMPUTER=8
} _TRUSTEE_TYPE;

typedef enum _TRUSTEE_TYPE TRUSTEE_TYPE;

struct _EXPLICIT_ACCESS_A {
    DWORD grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD grfInheritance;
    TRUSTEE_A Trustee;
};

struct _TRUSTEE_A {
    struct _TRUSTEE_A *pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    TRUSTEE_FORM TrusteeForm;
    TRUSTEE_TYPE TrusteeType;
    LPSTR ptstrName;
};

typedef struct _EXPLICIT_ACCESS_A *PEXPLICIT_ACCESS_A;

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

typedef char *va_list;

typedef ulonglong uintptr_t;

typedef struct MemoryCheck MemoryCheck, *PMemoryCheck;

struct MemoryCheck { // PlaceHolder Structure
};

typedef struct SapphireAbortException SapphireAbortException, *PSapphireAbortException;

struct SapphireAbortException { // PlaceHolder Structure
};

typedef ulonglong size_t;

typedef int errno_t;

typedef size_t rsize_t;



undefined DAT_18001a1b0;
undefined DAT_180019040;
undefined8 DAT_180019240;
undefined8 DAT_180019250;
int DAT_180019288;
undefined DAT_1800143e4;
undefined DAT_180018c40;
FARPROC DAT_180019268;
ulonglong *DAT_180019280;
int DAT_18001928c;
int DAT_180019290;
HMODULE DAT_180019260;
undefined DAT_180019278;
undefined *PTR_s___SAPPHIRE_DLL_FAILED__ERR_MSG_S_180018000;
FARPROC DAT_180019270;
longlong DAT_180019280;
undefined DAT_18001c030;
undefined DAT_180019408;
undefined DAT_1800146e0;
int DAT_180018034;
undefined *DAT_18001a198;
undefined *DAT_18001a1a0;
undefined *DAT_18001a1a8;
int DAT_1800193f0;
undefined DAT_180019360;
undefined DAT_180019370;
int DAT_1800193f4;
undefined DAT_180019368;
undefined DAT_180019380;
undefined DAT_180019390;
undefined DAT_1800193a0;
undefined8 DAT_1800193d8;
undefined DAT_18001939c;
undefined DAT_1800193a8;
undefined8 DAT_1800193e0;
undefined DAT_18001803c;
undefined DAT_1800193b0;
undefined1[12] UNK_180019364;
undefined4 UNK_180019374;
undefined4 UNK_18001938c;
undefined1[12] UNK_1800193a4;
undefined DAT_180019410;
ulonglong DAT_180019408;
int DAT_180019464;
uint DAT_180018864;
pointer switchdataD_18001d040;
uint DAT_18001886c;
undefined DAT_18000aff0;
undefined DAT_18000c740;
uint DAT_180018860;
uint DAT_180018868;
undefined DAT_18000e9a0;
ulonglong DAT_180018870;
undefined DAT_18000fa80;
ulonglong DAT_180018bd0;
undefined4 DAT_18001942c;
undefined4 DAT_180019420;
undefined4 DAT_180019424;
uint DAT_180019430;
int DAT_180019434;
int DAT_180019438;
uint DAT_180019440;
int DAT_180019444;
int DAT_180019448;
uint DAT_180019450;
int DAT_180019454;
int DAT_180019458;
int DAT_180018860;
int DAT_180018868;
int DAT_18001886c;
undefined DAT_180018870;
undefined DAT_180019468;
undefined DAT_180018878;
undefined DAT_18001887c;
undefined4 DAT_180019464;
undefined DAT_180019460;
undefined DAT_180018060;
undefined DAT_180018062;
undefined DAT_180018064;
undefined DAT_180019428;
longlong DAT_1800188a0;
undefined *PTR_FUN_1800188b0;
int DAT_180018880;
undefined *PTR_FUN_180018980;
HMODULE DAT_180019a80;
int DAT_180018884;
undefined *PTR_FUN_180018a20;
pointer PTR_DAT_180014a08;
undefined DAT_180014de0;
undefined DAT_18001967e;
undefined DAT_180019680;
undefined DAT_180019880;
undefined *PTR_FUN_180018a40;
undefined *PTR_FUN_180018a60;
undefined *DAT_180018900;
undefined *DAT_180018bb0;
undefined *DAT_180018b70;
undefined *DAT_180018a90;
undefined8 DAT_180019b10;
undefined *DAT_180019b70;
undefined8 DAT_180019b40;
undefined8 DAT_180019ae0;
undefined *DAT_180019b78;
undefined *DAT_180019b80;
undefined *DAT_180019b88;
undefined *DAT_180019b90;
undefined8 DAT_180019aa0;
undefined8 DAT_1800188a0;
undefined1 *DAT_180018bb0;
undefined1 *DAT_180018900;
undefined1 *DAT_180018a90;
undefined1 *DAT_180018ab0;
undefined1 *DAT_180018ac0;
undefined1 *DAT_180018ad0;
undefined1 *DAT_180018ae0;
undefined1 *DAT_180018b70;
undefined1 *DAT_180018b90;
FARPROC DAT_180019b98;
FARPROC DAT_180019b70;
FARPROC DAT_180019b78;
FARPROC DAT_180019b80;
FARPROC DAT_180019b88;
FARPROC DAT_180019b90;
INT_PTR DAT_180019ae0;
INT_PTR DAT_180019b10;
INT_PTR DAT_180019b40;
undefined LAB_180012660;
undefined LAB_180012670;
undefined LAB_180012680;
pointer PTR_FUN_1800188b0;
undefined8 DAT_1800188c0;
pointer[1] vftable;
void *StackLimit;
int DAT_180019bc8;
undefined _guard_dispatch_icall;
int DAT_180019ba0;
undefined DAT_1800142a0;
undefined DAT_1800142b0;
undefined DAT_1800142b8;
undefined DAT_1800142c0;
uintptr_t DAT_180018bd0;
ulonglong DAT_180018bc8;
undefined DAT_180019bb0;
undefined DAT_180019bc0;
void *DAT_180019bd0;
void *StackBase;
undefined DAT_180019be0;
undefined1 DAT_180019bd8;
char DAT_180019bd9;
undefined DAT_180019bf0;
undefined DAT_180019bf8;
undefined DAT_180019c08;
ulonglong UNK_180019be8;
ulonglong UNK_180019c00;
IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER_180000228;
undefined DAT_180000368;
undefined8 DAT_180019bd0;
char DAT_180019bd8;
undefined DAT_18001a1b8;
undefined DAT_180019c10;
undefined8 DAT_180016208;
undefined8 DAT_180016218;
undefined8 DAT_180019db8;
undefined DAT_180019d58;
undefined DAT_180019c30;
undefined DAT_180019d40;
undefined DAT_180019c20;
undefined DAT_180019c24;
undefined DAT_180019c38;
undefined8 DAT_180018bd0;
undefined8 DAT_180018bc8;
undefined8 DAT_180019c40;
pointer PTR_DAT_180015db0;
undefined DAT_180019cc0;
undefined4 DAT_180018bec;
undefined DAT_180018be8;
undefined DAT_180018bf0;
uint DAT_18001a190;
int DAT_180018c00;
undefined FUN_180012724;

int FUN_180001000(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_180001070();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



undefined * FUN_180001070(void)

{
  return &DAT_18001a1b0;
}



uint * FUN_180001080(ulonglong *param_1,char *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ushort uVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  undefined7 extraout_var;
  uint *puVar8;
  char *pcVar9;
  undefined7 extraout_var_00;
  undefined4 extraout_var_01;
  char *pcVar10;
  char *pcVar11;
  uint *puVar12;
  undefined4 extraout_var_02;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  longlong lVar16;
  ulonglong uVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 local_1d8 [128];
  int local_158 [22];
  undefined4 local_100;
  char cStack_fc;
  char cStack_fb;
  char cStack_fa;
  char cStack_f9;
  char cStack_f8;
  char cStack_f7;
  char cStack_f6;
  char cStack_f5;
  char cStack_f4;
  char cStack_f3;
  char cStack_f2;
  char cStack_f1;
  int local_80;
  int local_7c;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined8 local_58;
  undefined2 local_50;
  undefined1 local_4e;
  int local_4c;
  
  bVar5 = FUN_180008a50("Software\\BorisFX\\Sapphire AE");
  puVar8 = (uint *)CONCAT71(extraout_var,bVar5);
  if ((int)puVar8 != 0) {
    puVar8 = FUN_180008320((HKEY)0xffffffff80000002,(uint *)"Software\\BorisFX\\Sapphire AE",
                           "MachineName",&local_100,0x80,(uint *)&DAT_1800143e4,0);
    if ((char)local_100 != '\0') {
      local_58 = 0xba9b05971672d902;
      local_50 = 0x3039;
      local_4e = 0x61;
      local_68 = (undefined1  [16])0x0;
      FUN_180007cc0((undefined8 *)local_158);
      FUN_180001ee0(local_158,(undefined1 (*) [64])"jkfwe",5);
      FUN_180001ee0(local_158,(undefined1 (*) [64])&local_58,0xb);
      FUN_180001ee0(local_158,(undefined1 (*) [64])"jkfwe",5);
      auVar18[0] = -((char)local_100 == '\0');
      auVar18[1] = -(local_100._1_1_ == '\0');
      auVar18[2] = -(local_100._2_1_ == '\0');
      auVar18[3] = -(local_100._3_1_ == '\0');
      auVar18[4] = -(cStack_fc == '\0');
      auVar18[5] = -(cStack_fb == '\0');
      auVar18[6] = -(cStack_fa == '\0');
      auVar18[7] = -(cStack_f9 == '\0');
      auVar18[8] = -(cStack_f8 == '\0');
      auVar18[9] = -(SUB161((undefined1  [16])0x0,9) == cStack_f7);
      auVar18[10] = -(SUB161((undefined1  [16])0x0,10) == cStack_f6);
      auVar18[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cStack_f5);
      auVar18[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cStack_f4);
      auVar18[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cStack_f3);
      auVar18[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cStack_f2);
      auVar18[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cStack_f1);
      uVar4 = (ushort)(SUB161(auVar18 >> 7,0) & 1) | (ushort)(SUB161(auVar18 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar18 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar18 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar18 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar18 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar18 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar18 >> 0x3f,0) & 1) << 7 |
              (ushort)(SUB161(auVar18 >> 0x47,0) & 1) << 8 |
              (ushort)(SUB161(auVar18 >> 0x4f,0) & 1) << 9 |
              (ushort)(SUB161(auVar18 >> 0x57,0) & 1) << 10 |
              (ushort)(SUB161(auVar18 >> 0x5f,0) & 1) << 0xb |
              (ushort)(SUB161(auVar18 >> 0x67,0) & 1) << 0xc |
              (ushort)(SUB161(auVar18 >> 0x6f,0) & 1) << 0xd |
              (ushort)(SUB161(auVar18 >> 0x77,0) & 1) << 0xe | (ushort)(auVar18[0xf] >> 7) << 0xf;
      uVar14 = 0;
      if (uVar4 != 0) {
        for (; (uVar4 >> uVar14 & 1) == 0; uVar14 = uVar14 + 1) {
        }
      }
      if (uVar4 == 0) {
        pcVar9 = FUN_180008c30(0,(longlong)&local_100);
        uVar14 = (uint)pcVar9;
      }
      FUN_180001ee0(local_158,(undefined1 (*) [64])&local_100,uVar14);
      FUN_180004240(&local_68,(undefined1 (*) [64])local_158);
      uVar17 = (ulonglong)local_68[1];
      FUN_180001000(local_1d8,
                    "{%.2X%.2X%.2X%.2X-%.2X%.2X-%.2X%.2X-%.2X%.2X-%.2X%.2X%.2X%.2X%.2X%.2X}",
                    (ulonglong)local_68[0],uVar17);
      FUN_180001000(&DAT_180019040,"SOFTWARE\\Adobe\\%s",local_1d8,uVar17);
      bVar5 = FUN_180008ab0(&DAT_180019040);
      puVar8 = (uint *)CONCAT71(extraout_var_00,bVar5);
      if ((int)puVar8 != 0) {
        local_4c = 0;
        uVar6 = FUN_180008750((HKEY)0xffffffff80000002,&DAT_180019040,"dllcnt",(LPBYTE)&local_4c,0);
        puVar8 = (uint *)CONCAT44(extraout_var_01,uVar6);
        if (local_4c == 0) {
          local_7c = 0;
          FUN_180008750((HKEY)0xffffffff80000002,&DAT_180019040,"dlluse",(LPBYTE)&local_7c,0);
          iVar7 = local_7c;
          FUN_180008820((HKEY)0xffffffff80000002,&DAT_180019040,"dlluse",local_7c + 1);
          if ((iVar7 < 200) || (iVar7 % 100 != 0)) {
            local_80 = 0;
            uVar6 = FUN_180008750((HKEY)0xffffffff80000002,&DAT_180019040,"dllref",(LPBYTE)&local_80
                                  ,0);
            if (local_80 == 0) {
              return (uint *)CONCAT44(extraout_var_02,uVar6);
            }
            if (iVar7 < 10) {
              return (uint *)CONCAT44(extraout_var_02,uVar6);
            }
            if ((iVar7 / 10) * 10 != iVar7) {
              return (uint *)((longlong)iVar7 * 0x66666667 & 0xffffffff);
            }
          }
          pcVar9 = (char *)(*param_1 & 0xfffffffffffffff0);
          auVar21[0] = -(*pcVar9 == '\0');
          auVar21[1] = -(pcVar9[1] == '\0');
          auVar21[2] = -(pcVar9[2] == '\0');
          auVar21[3] = -(pcVar9[3] == '\0');
          auVar21[4] = -(pcVar9[4] == '\0');
          auVar21[5] = -(pcVar9[5] == '\0');
          auVar21[6] = -(pcVar9[6] == '\0');
          auVar21[7] = -(pcVar9[7] == '\0');
          auVar21[8] = -(pcVar9[8] == '\0');
          auVar21[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar9[9]);
          auVar21[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar9[10]);
          auVar21[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar9[0xb]);
          auVar21[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar9[0xc]);
          auVar21[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar9[0xd]);
          auVar21[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar9[0xe]);
          auVar21[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar9[0xf]);
          uVar14 = (uint)*param_1 & 0xf;
          uVar4 = (ushort)((ushort)(SUB161(auVar21 >> 7,0) & 1) |
                           (ushort)(SUB161(auVar21 >> 0xf,0) & 1) << 1 |
                           (ushort)(SUB161(auVar21 >> 0x17,0) & 1) << 2 |
                           (ushort)(SUB161(auVar21 >> 0x1f,0) & 1) << 3 |
                           (ushort)(SUB161(auVar21 >> 0x27,0) & 1) << 4 |
                           (ushort)(SUB161(auVar21 >> 0x2f,0) & 1) << 5 |
                           (ushort)(SUB161(auVar21 >> 0x37,0) & 1) << 6 |
                           (ushort)(SUB161(auVar21 >> 0x3f,0) & 1) << 7 |
                           (ushort)(SUB161(auVar21 >> 0x47,0) & 1) << 8 |
                           (ushort)(SUB161(auVar21 >> 0x4f,0) & 1) << 9 |
                           (ushort)(SUB161(auVar21 >> 0x57,0) & 1) << 10 |
                           (ushort)(SUB161(auVar21 >> 0x5f,0) & 1) << 0xb |
                           (ushort)(SUB161(auVar21 >> 0x67,0) & 1) << 0xc |
                           (ushort)(SUB161(auVar21 >> 0x6f,0) & 1) << 0xd |
                           (ushort)(SUB161(auVar21 >> 0x77,0) & 1) << 0xe |
                          (ushort)(auVar21[0xf] >> 7) << 0xf) >> (sbyte)uVar14;
          iVar7 = 0;
          if (uVar4 != 0) {
            for (; (uVar4 >> iVar7 & 1) == 0; iVar7 = iVar7 + 1) {
            }
          }
          if (uVar4 == 0) {
            pcVar9 = FUN_180008c30((ulonglong)uVar14,(longlong)(pcVar9 + uVar14));
            iVar7 = (int)pcVar9;
          }
          local_78 = (undefined1  [16])0x0;
          FUN_180005f90(&local_78,param_2);
          auVar18 = local_78;
          uVar17 = *param_1;
          local_78[1] = local_78[1] ^ *(byte *)(uVar17 + (longlong)(int)(1 % (longlong)iVar7));
          local_78[0] = local_78[0] ^ *(byte *)(uVar17 + (longlong)(int)(0 % (longlong)iVar7));
          local_78[2] = auVar18[2];
          local_78[2] = local_78[2] ^ *(byte *)(uVar17 + (longlong)(int)(2 % (longlong)iVar7));
          local_78[3] = auVar18[3];
          local_78[3] = local_78[3] ^ *(byte *)(uVar17 + (longlong)(int)(3 % (longlong)iVar7));
          local_78[4] = auVar18[4];
          local_78[4] = local_78[4] ^ *(byte *)(uVar17 + (longlong)(int)(4 % (longlong)iVar7));
          local_78[5] = auVar18[5];
          local_78[5] = local_78[5] ^ *(byte *)(uVar17 + (longlong)(int)(5 % (longlong)iVar7));
          local_78[6] = auVar18[6];
          local_78[6] = local_78[6] ^ *(byte *)(uVar17 + (longlong)(int)(6 % (longlong)iVar7));
          local_78[7] = auVar18[7];
          local_78[7] = local_78[7] ^ *(byte *)(uVar17 + (longlong)(int)(7 % (longlong)iVar7));
          local_78[8] = auVar18[8];
          local_78[8] = local_78[8] ^ *(byte *)(uVar17 + (longlong)(int)(8 % (longlong)iVar7));
          local_78[9] = auVar18[9];
          local_78[9] = local_78[9] ^ *(byte *)(uVar17 + (longlong)(int)(9 % (longlong)iVar7));
          local_78[10] = auVar18[10];
          local_78[10] = local_78[10] ^ *(byte *)(uVar17 + (longlong)(int)(10 % (longlong)iVar7));
          local_78[0xb] = auVar18[0xb];
          local_78[0xb] = local_78[0xb] ^ *(byte *)(uVar17 + (longlong)(int)(0xb % (longlong)iVar7))
          ;
          local_78[0xc] = auVar18[0xc];
          local_78[0xc] = local_78[0xc] ^ *(byte *)(uVar17 + (longlong)(int)(0xc % (longlong)iVar7))
          ;
          local_78[0xd] = auVar18[0xd];
          local_78[0xd] = local_78[0xd] ^ *(byte *)(uVar17 + (longlong)(int)(0xd % (longlong)iVar7))
          ;
          local_78[0xe] = auVar18[0xe];
          local_78[0xf] = auVar18[0xf];
          local_78[0xe] = local_78[0xe] ^ *(byte *)(uVar17 + (longlong)(int)(0xe % (longlong)iVar7))
          ;
          puVar8 = (uint *)0x0;
          local_78[0xf] = local_78[0xf] ^ *(byte *)(uVar17 + (longlong)(int)(0xf % (longlong)iVar7))
          ;
          do {
            if (local_78[(longlong)puVar8] != *(char *)((longlong)puVar8 + 0x18001430b)) {
              FUN_180008820((HKEY)0xffffffff80000002,&DAT_180019040,"dllcnt",1);
              puVar8 = (uint *)FUN_180008820((HKEY)0xffffffff80000002,&DAT_180019040,"dllref",1);
              return puVar8;
            }
            puVar8 = (uint *)((longlong)puVar8 + 1);
          } while (puVar8 < (uint *)0x10);
          return puVar8;
        }
      }
    }
    if (DAT_180019288 == 0) {
      puVar8 = (uint *)param_1[6];
      lVar16 = 0;
      DAT_180019288 = 0;
      lVar1 = *(longlong *)puVar8;
      while (lVar1 != 0) {
        pcVar9 = (char *)(*(ulonglong *)(puVar8 + lVar16 * 2) & 0xfffffffffffffff0);
        auVar19[0] = -(*pcVar9 == '\0');
        auVar19[1] = -(pcVar9[1] == '\0');
        auVar19[2] = -(pcVar9[2] == '\0');
        auVar19[3] = -(pcVar9[3] == '\0');
        auVar19[4] = -(pcVar9[4] == '\0');
        auVar19[5] = -(pcVar9[5] == '\0');
        auVar19[6] = -(pcVar9[6] == '\0');
        auVar19[7] = -(pcVar9[7] == '\0');
        auVar19[8] = -(pcVar9[8] == '\0');
        auVar19[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar9[9]);
        auVar19[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar9[10]);
        auVar19[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar9[0xb]);
        auVar19[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar9[0xc]);
        auVar19[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar9[0xd]);
        auVar19[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar9[0xe]);
        auVar19[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar9[0xf]);
        uVar13 = (uint)*(ulonglong *)(puVar8 + lVar16 * 2) & 0xf;
        uVar4 = (ushort)((ushort)(SUB161(auVar19 >> 7,0) & 1) |
                         (ushort)(SUB161(auVar19 >> 0xf,0) & 1) << 1 |
                         (ushort)(SUB161(auVar19 >> 0x17,0) & 1) << 2 |
                         (ushort)(SUB161(auVar19 >> 0x1f,0) & 1) << 3 |
                         (ushort)(SUB161(auVar19 >> 0x27,0) & 1) << 4 |
                         (ushort)(SUB161(auVar19 >> 0x2f,0) & 1) << 5 |
                         (ushort)(SUB161(auVar19 >> 0x37,0) & 1) << 6 |
                         (ushort)(SUB161(auVar19 >> 0x3f,0) & 1) << 7 |
                         (ushort)(SUB161(auVar19 >> 0x47,0) & 1) << 8 |
                         (ushort)(SUB161(auVar19 >> 0x4f,0) & 1) << 9 |
                         (ushort)(SUB161(auVar19 >> 0x57,0) & 1) << 10 |
                         (ushort)(SUB161(auVar19 >> 0x5f,0) & 1) << 0xb |
                         (ushort)(SUB161(auVar19 >> 0x67,0) & 1) << 0xc |
                         (ushort)(SUB161(auVar19 >> 0x6f,0) & 1) << 0xd |
                         (ushort)(SUB161(auVar19 >> 0x77,0) & 1) << 0xe |
                        (ushort)(auVar19[0xf] >> 7) << 0xf) >> (sbyte)uVar13;
        uVar14 = 0;
        if (uVar4 != 0) {
          for (; (uVar4 >> uVar14 & 1) == 0; uVar14 = uVar14 + 1) {
          }
        }
        pcVar10 = (char *)(ulonglong)uVar14;
        if (uVar4 == 0) {
          pcVar10 = FUN_180008c30((ulonglong)uVar13,(longlong)(pcVar9 + uVar13));
        }
        uVar17 = *(ulonglong *)(param_1[7] + lVar16 * 8);
        pcVar9 = (char *)(uVar17 & 0xfffffffffffffff0);
        auVar20[0] = -(*pcVar9 == '\0');
        auVar20[1] = -(pcVar9[1] == '\0');
        auVar20[2] = -(pcVar9[2] == '\0');
        auVar20[3] = -(pcVar9[3] == '\0');
        auVar20[4] = -(pcVar9[4] == '\0');
        auVar20[5] = -(pcVar9[5] == '\0');
        auVar20[6] = -(pcVar9[6] == '\0');
        auVar20[7] = -(pcVar9[7] == '\0');
        auVar20[8] = -(pcVar9[8] == '\0');
        auVar20[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar9[9]);
        auVar20[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar9[10]);
        auVar20[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar9[0xb]);
        auVar20[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar9[0xc]);
        auVar20[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar9[0xd]);
        auVar20[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar9[0xe]);
        auVar20[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar9[0xf]);
        uVar13 = (uint)uVar17 & 0xf;
        uVar4 = (ushort)((ushort)(SUB161(auVar20 >> 7,0) & 1) |
                         (ushort)(SUB161(auVar20 >> 0xf,0) & 1) << 1 |
                         (ushort)(SUB161(auVar20 >> 0x17,0) & 1) << 2 |
                         (ushort)(SUB161(auVar20 >> 0x1f,0) & 1) << 3 |
                         (ushort)(SUB161(auVar20 >> 0x27,0) & 1) << 4 |
                         (ushort)(SUB161(auVar20 >> 0x2f,0) & 1) << 5 |
                         (ushort)(SUB161(auVar20 >> 0x37,0) & 1) << 6 |
                         (ushort)(SUB161(auVar20 >> 0x3f,0) & 1) << 7 |
                         (ushort)(SUB161(auVar20 >> 0x47,0) & 1) << 8 |
                         (ushort)(SUB161(auVar20 >> 0x4f,0) & 1) << 9 |
                         (ushort)(SUB161(auVar20 >> 0x57,0) & 1) << 10 |
                         (ushort)(SUB161(auVar20 >> 0x5f,0) & 1) << 0xb |
                         (ushort)(SUB161(auVar20 >> 0x67,0) & 1) << 0xc |
                         (ushort)(SUB161(auVar20 >> 0x6f,0) & 1) << 0xd |
                         (ushort)(SUB161(auVar20 >> 0x77,0) & 1) << 0xe |
                        (ushort)(auVar20[0xf] >> 7) << 0xf) >> (sbyte)uVar13;
        uVar14 = 0;
        if (uVar4 != 0) {
          for (; (uVar4 >> uVar14 & 1) == 0; uVar14 = uVar14 + 1) {
          }
        }
        pcVar11 = (char *)(ulonglong)uVar14;
        if (uVar4 == 0) {
          pcVar11 = FUN_180008c30((ulonglong)uVar13,(longlong)(pcVar9 + uVar13));
        }
        puVar12 = malloc((size_t)(pcVar10 + (longlong)pcVar11));
        puVar8 = *(uint **)(param_1[6] + lVar16 * 8);
        puVar15 = puVar12;
        while (((ulonglong)puVar8 & 3) != 0) {
          uVar14 = *puVar8;
          puVar8 = (uint *)((longlong)puVar8 + 1);
          *(char *)puVar15 = (char)uVar14;
          if ((char)uVar14 == '\0') goto LAB_1800013f6;
          puVar15 = (uint *)((longlong)puVar15 + 1);
        }
        FUN_180008c60(puVar8,puVar15);
LAB_1800013f6:
        FUN_180008dc0(puVar8,*(uint **)(param_1[7] + lVar16 * 8));
        pcVar9 = "";
        if (*(char *)((longlong)param_1 + 0x4d) != '\0') {
          pcVar9 = "dynamic";
        }
        FUN_180001000(puVar12,"(def_effect %s (Source) (%s) () (interp Source [1 0 0] .999))",
                      *param_1,pcVar9);
        uVar2 = *(undefined8 *)(param_1[6] + lVar16 * 8);
        uVar3 = *(undefined8 *)(param_1[7] + lVar16 * 8);
        *(uint **)(param_1[6] + lVar16 * 8) = puVar12;
        uVar17 = param_1[7];
        (&DAT_180019240)[lVar16] = uVar2;
        (&DAT_180019250)[lVar16] = uVar3;
        *(undefined **)(uVar17 + lVar16 * 8) = &DAT_1800143e4;
        lVar16 = lVar16 + 1;
        puVar8 = (uint *)param_1[6];
        lVar1 = *(longlong *)(puVar8 + lVar16 * 2);
      }
      DAT_180019288 = 1;
    }
  }
  return puVar8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

ulonglong pluginMain(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6)

{
  ulonglong *puVar1;
  DWORD dwMessageId;
  ulonglong uVar2;
  HMODULE hModule;
  char *pcVar3;
  longlong lVar4;
  undefined *puVar5;
  undefined8 uVar6;
  HLOCAL pvVar7;
  longlong *plVar8;
  CHAR local_a48 [1024];
  uint local_648 [128];
  char local_448 [1024];
  HLOCAL local_48;
  
                    // 0x17a0  6  pluginMain
  if (param_1 == 1) {
    DAT_180019290 = DAT_180019290 + 1;
LAB_180001972:
    FUN_180001000(local_648,"Software\\BorisFX\\Sapphire AE\\%s","2024.0",param_4);
    puVar5 = &DAT_180018c40;
    FUN_180008320((HKEY)0xffffffff80000002,local_648,"ConfigDir",(uint *)&DAT_180018c40,0x3ff,
                  (uint *)"c:/Program Files/BorisFX/Sapphire 2024 Adobe",0);
    FUN_180001000(local_448,"%s/lib64/sapphire_ae.dll",&DAT_180018c40,puVar5);
    if (DAT_180019268 == (FARPROC)0x0) {
LAB_180001a12:
      hModule = LoadLibraryA(local_448);
      DAT_180019260 = hModule;
      if (hModule != (HMODULE)0x0) {
        DAT_180019268 = GetProcAddress(hModule,"sapphire_main");
        _DAT_180019278 = GetProcAddress(hModule,"sapphire_find_pinfo_for_effect");
        DAT_180019280 = (ulonglong *)(*_DAT_180019278)("S_HalfToneColor");
      }
      if (DAT_180019268 == (FARPROC)0x0) {
        dwMessageId = GetLastError();
        uVar6 = 0x400;
        FormatMessageA(0x1300,(LPCVOID)0x0,dwMessageId,0x400,(LPSTR)&local_48,0,(va_list *)0x0);
        pcVar3 = getenv(PTR_s___SAPPHIRE_DLL_FAILED__ERR_MSG_S_180018000);
        if (pcVar3 == (char *)0x0) {
          pvVar7 = local_48;
          FUN_180001000(local_a48,
                        "S_HalfToneColor: Failed to load DLL, cmd=%d, msg=%s: showing msg\n",
                        (ulonglong)param_1,local_48);
          OutputDebugStringA(local_a48);
          _putenv_s(PTR_s___SAPPHIRE_DLL_FAILED__ERR_MSG_S_180018000,"1");
          FUN_180001000(local_a48,
                        "%s: This plug-in failed to load.\nIf you\'re on Premiere Pro CC 2017 or later, please try restarting Premiere. Otherwise please reinstall the plug-ins."
                        ,"S_HalfToneColor",pvVar7);
          MessageBoxA((HWND)0x0,local_a48,"Sapphire Plug-ins Error",0x30);
        }
        else {
          FUN_180001000(local_a48,
                        "S_HalfToneColor: Failed to load DLL, cmd=%d: already showed err msg\n",
                        (ulonglong)param_1,uVar6);
          OutputDebugStringA(local_a48);
        }
        LocalFree(local_48);
        if ((param_1 != 1) && (1 < param_1 - 3)) {
          return 0x200;
        }
        goto LAB_1800018b3;
      }
    }
    else if (DAT_180019290 == 1) {
      if (param_1 != 1) goto LAB_1800017d4;
      goto LAB_180001a12;
    }
    if (param_1 != 1) goto LAB_1800017f6;
LAB_1800017d6:
    FUN_180001080(DAT_180019280,local_448);
  }
  else {
    if (DAT_180019268 == (FARPROC)0x0) goto LAB_180001972;
LAB_1800017d4:
    if (param_1 == 1) goto LAB_1800017d6;
LAB_1800017f6:
    puVar1 = DAT_180019280;
    if (param_1 == 3) {
      if ((DAT_180019288 != 0) && (plVar8 = (longlong *)DAT_180019280[6], *plVar8 != 0)) {
        lVar4 = 0;
        do {
          free((void *)plVar8[lVar4]);
          plVar8[lVar4] = (&DAT_180019240)[lVar4];
          *(undefined8 *)(puVar1[7] + lVar4 * 8) = (&DAT_180019250)[lVar4];
          lVar4 = lVar4 + 1;
          plVar8 = (longlong *)puVar1[6];
        } while (plVar8[lVar4] != 0);
      }
      DAT_180019288 = 0;
    }
  }
  puVar1 = DAT_180019280;
  if ((DAT_180019280 != (ulonglong *)0x0) && (DAT_18001928c == 0)) {
    *(undefined1 (*) [16])(DAT_180019280 + 0xb) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(puVar1 + 0xd) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(puVar1 + 0xf) = (undefined1  [16])0x0;
    DAT_18001928c = 1;
  }
LAB_1800018b3:
  if (DAT_180019268 == (FARPROC)0x0) {
    if ((param_1 == 1) || (param_1 - 3 < 2)) {
      return 0;
    }
    uVar2 = 0x203;
  }
  else {
    uVar2 = (*DAT_180019268)(DAT_180019280,(ulonglong)param_1,param_2,param_3,param_4,param_5,
                             param_6);
    uVar2 = uVar2 & 0xffffffff;
    if ((param_1 == 3) && (DAT_180019290 = DAT_180019290 + -1, DAT_180019290 == 0)) {
      FreeLibrary(DAT_180019260);
      DAT_180019268 = (FARPROC)0x0;
    }
  }
  return uVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

INT_PTR xGPUFilterEntry(uint param_1,undefined8 param_2,uint param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6)

{
  longlong lVar1;
  DWORD dwMessageId;
  INT_PTR IVar2;
  HMODULE hModule;
  char *pcVar3;
  undefined *puVar4;
  undefined8 uVar5;
  HLOCAL pvVar6;
  CHAR local_a38 [1024];
  CHAR local_638 [1024];
  uint local_238 [128];
  HLOCAL local_38 [2];
  
                    // 0x1bb0  7  xGPUFilterEntry
  if (DAT_180019270 == (FARPROC)0x0) {
    FUN_180001000(local_238,"Software\\BorisFX\\Sapphire AE\\%s","2024.0",param_4);
    puVar4 = &DAT_180018c40;
    FUN_180008320((HKEY)0xffffffff80000002,local_238,"ConfigDir",(uint *)&DAT_180018c40,0x3ff,
                  (uint *)"c:/Program Files/BorisFX/Sapphire 2024 Adobe",0);
    FUN_180001000(local_638,"%s/lib64/sapphire_ae.dll",&DAT_180018c40,puVar4);
    if (DAT_180019270 != (FARPROC)0x0) goto LAB_180001bd4;
    hModule = LoadLibraryA(local_638);
    DAT_180019260 = hModule;
    if (hModule != (HMODULE)0x0) {
      DAT_180019270 = GetProcAddress(hModule,"sapphire_gpu");
      _DAT_180019278 = GetProcAddress(hModule,"sapphire_find_pinfo_for_effect");
      DAT_180019280 = (*_DAT_180019278)("S_HalfToneColor");
    }
    if (DAT_180019270 == (FARPROC)0x0) {
      dwMessageId = GetLastError();
      uVar5 = 0x400;
      FormatMessageA(0x1300,(LPCVOID)0x0,dwMessageId,0x400,(LPSTR)local_38,0,(va_list *)0x0);
      pcVar3 = getenv(PTR_s___SAPPHIRE_DLL_FAILED__ERR_MSG_S_180018000);
      if (pcVar3 == (char *)0x0) {
        pvVar6 = local_38[0];
        FUN_180001000(local_a38,"S_HalfToneColor: Failed to load DLL, cmd=%d, msg=%s: showing msg\n"
                      ,2,local_38[0]);
        OutputDebugStringA(local_a38);
        _putenv_s(PTR_s___SAPPHIRE_DLL_FAILED__ERR_MSG_S_180018000,"1");
        FUN_180001000(local_a38,
                      "%s: This plug-in failed to load.\nIf you\'re on Premiere Pro CC 2017 or later, please try restarting Premiere. Otherwise please reinstall the plug-ins."
                      ,"S_HalfToneColor",pvVar6);
        MessageBoxA((HWND)0x0,local_a38,"Sapphire Plug-ins Error",0x30);
      }
      else {
        FUN_180001000(local_a38,
                      "S_HalfToneColor: Failed to load DLL, cmd=%d: already showed err msg\n",2,
                      uVar5);
        OutputDebugStringA(local_a38);
      }
      LocalFree(local_38[0]);
      return 0x200;
    }
    if ((DAT_180019280 != 0) && (DAT_18001928c == 0)) goto LAB_180001c22;
  }
  else {
LAB_180001bd4:
    if ((DAT_180019280 == 0) || (DAT_18001928c != 0)) goto LAB_180001be9;
LAB_180001c22:
    lVar1 = DAT_180019280;
    *(undefined1 (*) [16])(DAT_180019280 + 0x58) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(lVar1 + 0x68) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(lVar1 + 0x78) = (undefined1  [16])0x0;
    DAT_18001928c = 1;
  }
  if (DAT_180019270 == (FARPROC)0x0) {
    return 0;
  }
LAB_180001be9:
  IVar2 = (*DAT_180019270)((ulonglong)param_1,param_2,param_3,param_4,param_5,param_6);
  return IVar2;
}



// private: static void * __ptr64 __cdecl MemoryCheck::operator new[](unsigned __int64)

void * __cdecl MemoryCheck::operator_new__(__uint64 param_1)

{
  undefined4 local_8 [2];
  
                    // 0x1e70  4  ??_UMemoryCheck@@CAPEAX_K@Z
  local_8[0] = 0;
                    // WARNING: Subroutine does not return
  _CxxThrowException(local_8,(ThrowInfo *)&DAT_18001c030);
}



// private: static void __cdecl MemoryCheck::operator delete[](void * __ptr64)

void __cdecl MemoryCheck::operator_delete__(void *param_1)

{
                    // 0x1ea0  5  ??_VMemoryCheck@@CAXPEAX@Z
  return;
}



// public: class MemoryCheck & __ptr64 __cdecl MemoryCheck::operator=(class MemoryCheck && __ptr64)
// __ptr64

MemoryCheck * __thiscall MemoryCheck::operator=(MemoryCheck *this,MemoryCheck *param_1)

{
                    // 0x1eb0  1  ??4MemoryCheck@@QEAAAEAV0@$$QEAV0@@Z
                    // 0x1eb0  2  ??4MemoryCheck@@QEAAAEAV0@AEBV0@@Z
  return this;
}



// public: class SapphireAbortException & __ptr64 __cdecl SapphireAbortException::operator=(class
// SapphireAbortException const & __ptr64) __ptr64

SapphireAbortException * __thiscall
SapphireAbortException::operator=(SapphireAbortException *this,SapphireAbortException *param_1)

{
  undefined8 uVar1;
  
                    // 0x1ec0  3  ??4SapphireAbortException@@QEAAAEAV0@AEBV0@@Z
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)(this + 8) = uVar1;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  return this;
}



void FUN_180001ee0(int *param_1,undefined1 (*param_2) [64],uint param_3)

{
  ulonglong uVar1;
  
  uVar1 = 0x64199d97ff;
  while( true ) {
    if ((uVar1 & CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408)) == uVar1) {
      FUN_180001f80(param_1,param_2,param_3);
      return;
    }
    if ((CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408) & 0x7189d97ff) == 0x7189d97ff) {
      FUN_180002560(param_1,param_2,param_3);
      return;
    }
    if (((uint)DAT_180019408 & 0x9d97ff) == 0x9d97ff) {
      FUN_180002bf0(param_1,param_2,param_3);
      return;
    }
    if (((uint)DAT_180019408 & 0x3ff) == 0x3ff) break;
    if (((uint)DAT_180019408 & 1) != 0) {
      FUN_1800039b0(param_1,param_2,param_3);
      return;
    }
    uVar1 = FUN_180008f60();
  }
  FUN_180003190(param_1,param_2,param_3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180001f80(int *param_1,undefined1 (*param_2) [64],uint param_3)

{
  undefined1 (*pauVar1) [64];
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  int iVar14;
  undefined1 (*pauVar15) [64];
  uint uVar16;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [32];
  undefined1 auVar23 [32];
  undefined1 auVar24 [32];
  undefined1 auVar25 [32];
  undefined1 auVar26 [32];
  undefined1 auVar27 [32];
  ulonglong local_e8;
  undefined1 (*local_58) [64];
  
  uVar16 = param_1[4];
  param_1[4] = param_3 + uVar16;
  if (param_3 + uVar16 < uVar16) {
    param_1[5] = param_1[5] + 1;
  }
  uVar16 = 0x40 - (uVar16 & 0x3f);
  uVar13 = (ulonglong)uVar16;
  if (param_3 < uVar16) {
    FUN_180009540((undefined1 (*) [64])((longlong)param_1 + (0x58 - uVar13)),param_2,
                  (longlong)(int)param_3);
    return;
  }
  pauVar1 = (undefined1 (*) [64])(param_1 + 6);
  FUN_180009540((undefined1 (*) [64])((longlong)pauVar1 + (0x40 - uVar13)),param_2,uVar13);
  auVar21 = vpshufb_avx(*(undefined1 (*) [16])(param_1 + 6),_DAT_1800146e0);
  auVar17 = vpshufb_avx512vl(*(undefined1 (*) [16])(param_1 + 10),_DAT_1800146e0);
  auVar18 = vpshufb_avx512vl(*(undefined1 (*) [16])(param_1 + 0xe),_DAT_1800146e0);
  auVar19 = vpshufb_avx512vl(*(undefined1 (*) [16])(param_1 + 0x12),_DAT_1800146e0);
  auVar20 = vpunpckldq_avx512vl(auVar21,auVar17);
  auVar21 = vpunpckhdq_avx512vl(auVar21,auVar17);
  auVar17 = vpunpckldq_avx512vl(auVar18,auVar19);
  auVar18 = vpunpckhdq_avx512vl(auVar18,auVar19);
  auVar19 = vpunpcklqdq_avx512vl(auVar20,auVar17);
  auVar17 = vpunpckhqdq_avx512vl(auVar20,auVar17);
  auVar20 = vpunpcklqdq_avx512vl(auVar21,auVar18);
  auVar21 = vpunpckhqdq_avx512vl(auVar21,auVar18);
  auVar23 = vpmovzxbd_avx2(auVar21);
  auVar21 = vpsrldq_avx(auVar21,8);
  auVar22 = vpmovzxbd_avx512vl(auVar21);
  auVar27 = vpslld_avx2(auVar23,8);
  auVar23 = vpslld_avx512vl(auVar22,8);
  auVar22 = vpmovzxbd_avx512vl(auVar20);
  auVar21 = vpsrldq_avx(auVar20,8);
  auVar24 = vpmovzxbd_avx512vl(auVar21);
  auVar22 = vpord_avx512vl(auVar27,auVar22);
  auVar23 = vpord_avx512vl(auVar23,auVar24);
  auVar22 = vpslld_avx512vl(auVar22,0x10);
  auVar23 = vpslld_avx512vl(auVar23,0x10);
  auVar24 = vpmovzxbd_avx512vl(auVar17);
  auVar21 = vpsrldq_avx(auVar17,8);
  auVar27 = vpmovzxbd_avx512vl(auVar21);
  auVar24 = vpslld_avx512vl(auVar24,8);
  auVar27 = vpslld_avx512vl(auVar27,8);
  auVar25 = vpmovzxbd_avx512vl(auVar19);
  auVar21 = vpsrldq_avx(auVar19,8);
  auVar26 = vpmovzxbd_avx512vl(auVar21);
  auVar22 = vpternlogd_avx512vl(auVar22,auVar24,auVar25,0xfe);
  auVar24 = vpternlogd_avx512vl(auVar23,auVar27,auVar26,0xfe);
  auVar23 = vmovdqu32_avx512vl(auVar22);
  *(undefined1 (*) [32])(param_1 + 6) = auVar23;
  auVar23 = vmovdqu32_avx512vl(auVar24);
  *(undefined1 (*) [32])(param_1 + 0xe) = auVar23;
  FUN_1800074d0(param_1,(int *)pauVar1);
  iVar14 = param_3 - uVar16;
  pauVar15 = (undefined1 (*) [64])(*param_2 + uVar13);
  if (0x3f < iVar14) {
    local_e8 = 0;
    local_58 = pauVar15;
    do {
      uVar2 = *(undefined8 *)(*local_58 + 8);
      uVar3 = *(undefined8 *)(*local_58 + 0x10);
      uVar4 = *(undefined8 *)(*local_58 + 0x18);
      *(undefined8 *)*pauVar1 = *(undefined8 *)*local_58;
      *(undefined8 *)(param_1 + 8) = uVar2;
      *(undefined8 *)(param_1 + 10) = uVar3;
      *(undefined8 *)(param_1 + 0xc) = uVar4;
      uVar2 = *(undefined8 *)(*local_58 + 0x28);
      uVar3 = *(undefined8 *)(*local_58 + 0x30);
      uVar4 = *(undefined8 *)(*local_58 + 0x38);
      iVar6 = *(int *)(*local_58 + 0x20);
      iVar11 = *(int *)(*local_58 + 0x24);
      iVar5 = *(int *)(*local_58 + 0x28);
      iVar7 = *(int *)(*local_58 + 0x2c);
      iVar10 = *(int *)(*local_58 + 0x30);
      iVar12 = *(int *)(*local_58 + 0x34);
      iVar8 = *(int *)(*local_58 + 0x38);
      iVar9 = *(int *)(*local_58 + 0x3c);
      *(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(*local_58 + 0x20);
      *(undefined8 *)(param_1 + 0x10) = uVar2;
      *(undefined8 *)(param_1 + 0x12) = uVar3;
      *(undefined8 *)(param_1 + 0x14) = uVar4;
      param_1[0x11] = iVar7;
      param_1[0xe] = iVar6;
      param_1[0x14] = iVar8;
      param_1[0x15] = iVar9;
      param_1[0x12] = iVar10;
      param_1[0xf] = iVar11;
      param_1[0x13] = iVar12;
      param_1[8] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x23),
                                     *(undefined1 *)((longlong)param_1 + 0x22)),(short)param_1[8]);
      param_1[0x10] = iVar5;
      param_1[0xb] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x2f),
                                       *(undefined1 *)((longlong)param_1 + 0x2e)),
                              (short)param_1[0xb]);
      param_1[7] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x1e),
                            CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1d),(char)param_1[7]));
      param_1[0xc] = param_1[0xc];
      param_1[6] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1b),
                                     *(undefined1 *)((longlong)param_1 + 0x1a)),
                            CONCAT11(*(undefined1 *)((longlong)param_1 + 0x19),(char)param_1[6]));
      param_1[9] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x26),
                            CONCAT11(*(undefined1 *)((longlong)param_1 + 0x25),(char)param_1[9]));
      param_1[10] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x2a),
                             CONCAT11(*(undefined1 *)((longlong)param_1 + 0x29),(char)param_1[10]));
      param_1[0xd] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x36),
                              CONCAT11(*(undefined1 *)((longlong)param_1 + 0x35),(char)param_1[0xd])
                             );
      FUN_1800074d0(param_1,(int *)pauVar1);
      local_e8 = local_e8 + 1;
      local_58 = local_58 + 1;
    } while (local_e8 <
             (ulonglong)
             -((longlong)(((ulonglong)(-(longlong)iVar14 >> 5) >> 0x3a) - (longlong)iVar14) >> 6));
    iVar14 = iVar14 + (int)local_e8 * -0x40;
    pauVar15 = pauVar15 + local_e8;
  }
  FUN_180009540(pauVar1,pauVar15,(longlong)iVar14);
  return;
}



void FUN_180002560(int *param_1,undefined1 (*param_2) [64],uint param_3)

{
  undefined1 (*pauVar1) [64];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 (*pauVar11) [64];
  ulonglong uVar12;
  uint uVar13;
  undefined1 (*pauVar14) [64];
  int iVar15;
  undefined1 auVar16 [64];
  undefined1 auVar17 [64];
  undefined1 auVar18 [64];
  
  uVar13 = param_1[4];
  param_1[4] = param_3 + uVar13;
  if (param_3 + uVar13 < uVar13) {
    param_1[5] = param_1[5] + 1;
  }
  uVar13 = 0x40 - (uVar13 & 0x3f);
  uVar12 = (ulonglong)uVar13;
  if (param_3 < uVar13) {
    FUN_180009540((undefined1 (*) [64])((longlong)param_1 + (0x58 - uVar12)),param_2,
                  (longlong)(int)param_3);
    return;
  }
  pauVar1 = (undefined1 (*) [64])(param_1 + 6);
  FUN_180009540((undefined1 (*) [64])((longlong)pauVar1 + (0x40 - uVar12)),param_2,uVar12);
  auVar2 = vpinsrb_avx(ZEXT116(*(byte *)((longlong)param_1 + 0x1b)),
                       (uint)*(byte *)((longlong)param_1 + 0x1f),1);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x23),2);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x27),3);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x2b),4);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x2f),5);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x33),6);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x37),7);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x3b),8);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x3f),9);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x43),10);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x47),0xb);
  auVar3 = vpinsrb_avx(ZEXT116(*(byte *)((longlong)param_1 + 0x1a)),
                       (uint)*(byte *)((longlong)param_1 + 0x1e),1);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x4b),0xc);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x4f),0xd);
  auVar3 = vpinsrb_avx(auVar3,(uint)*(byte *)((longlong)param_1 + 0x22),2);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x53),0xe);
  auVar3 = vpinsrb_avx(auVar3,(uint)*(byte *)((longlong)param_1 + 0x26),3);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x57),0xf);
  auVar3 = vpinsrb_avx(auVar3,(uint)*(byte *)((longlong)param_1 + 0x2a),4);
  auVar16 = vpmovzxbd_avx512f(auVar2);
  auVar2 = vpinsrb_avx(auVar3,(uint)*(byte *)((longlong)param_1 + 0x2e),5);
  auVar16 = vpslld_avx512f(auVar16,8);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x32),6);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x36),7);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x3a),8);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x3e),9);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x42),10);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x46),0xb);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x4a),0xc);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x4e),0xd);
  auVar3 = vpinsrb_avx(ZEXT116(*(byte *)((longlong)param_1 + 0x19)),
                       (uint)*(byte *)((longlong)param_1 + 0x1d),1);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x52),0xe);
  auVar3 = vpinsrb_avx(auVar3,(uint)*(byte *)((longlong)param_1 + 0x21),2);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x56),0xf);
  auVar3 = vpinsrb_avx(auVar3,(uint)*(byte *)((longlong)param_1 + 0x25),3);
  auVar17 = vpmovzxbd_avx512f(auVar2);
  auVar2 = vpinsrb_avx(auVar3,(uint)*(byte *)((longlong)param_1 + 0x29),4);
  auVar16 = vpord_avx512f(auVar16,auVar17);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x2d),5);
  auVar16 = vpslld_avx512f(auVar16,0x10);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x31),6);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x35),7);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x39),8);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x3d),9);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x41),10);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x45),0xb);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x49),0xc);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x4d),0xd);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x51),0xe);
  auVar3 = vpinsrb_avx(ZEXT116(*(byte *)(param_1 + 6)),(uint)*(byte *)(param_1 + 7),1);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)((longlong)param_1 + 0x55),0xf);
  auVar3 = vpinsrb_avx(auVar3,(uint)*(byte *)(param_1 + 8),2);
  auVar17 = vpmovzxbd_avx512f(auVar2);
  auVar2 = vpinsrb_avx(auVar3,(uint)*(byte *)(param_1 + 9),3);
  auVar17 = vpslld_avx512f(auVar17,8);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 10),4);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0xb),5);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0xc),6);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0xd),7);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0xe),8);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0xf),9);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0x10),10);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0x11),0xb);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0x12),0xc);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0x13),0xd);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0x14),0xe);
  auVar2 = vpinsrb_avx(auVar2,(uint)*(byte *)(param_1 + 0x15),0xf);
  auVar18 = vpmovzxbd_avx512f(auVar2);
  auVar16 = vpternlogd_avx512f(auVar16,auVar17,auVar18,0xfe);
  auVar16 = vmovdqu32_avx512f(auVar16);
  *(undefined1 (*) [64])(param_1 + 6) = auVar16;
  FUN_1800074d0(param_1,(int *)pauVar1);
  iVar15 = param_3 - uVar13;
  pauVar14 = (undefined1 (*) [64])(*param_2 + uVar12);
  uVar12 = 0;
  if (0x3f < iVar15) {
    pauVar11 = pauVar14;
    do {
      uVar4 = *(undefined8 *)(*pauVar11 + 8);
      uVar5 = *(undefined8 *)(*pauVar11 + 0x10);
      uVar6 = *(undefined8 *)(*pauVar11 + 0x18);
      uVar7 = *(undefined8 *)(*pauVar11 + 0x20);
      uVar8 = *(undefined8 *)(*pauVar11 + 0x28);
      uVar9 = *(undefined8 *)(*pauVar11 + 0x30);
      uVar10 = *(undefined8 *)(*pauVar11 + 0x38);
      *(undefined8 *)*pauVar1 = *(undefined8 *)*pauVar11;
      *(undefined8 *)(param_1 + 8) = uVar4;
      *(undefined8 *)(param_1 + 10) = uVar5;
      *(undefined8 *)(param_1 + 0xc) = uVar6;
      *(undefined8 *)(param_1 + 0xe) = uVar7;
      *(undefined8 *)(param_1 + 0x10) = uVar8;
      *(undefined8 *)(param_1 + 0x12) = uVar9;
      *(undefined8 *)(param_1 + 0x14) = uVar10;
      param_1[6] = param_1[6];
      param_1[7] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1f),
                                     *(undefined1 *)((longlong)param_1 + 0x1e)),
                            CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1d),(char)param_1[7]));
      param_1[8] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x23),
                                     *(undefined1 *)((longlong)param_1 + 0x22)),(short)param_1[8]);
      param_1[9] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x27),
                                     *(undefined1 *)((longlong)param_1 + 0x26)),(short)param_1[9]);
      param_1[10] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x2b),
                                      *(undefined1 *)((longlong)param_1 + 0x2a)),(short)param_1[10])
      ;
      param_1[0xb] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x2f),
                                       *(undefined1 *)((longlong)param_1 + 0x2e)),
                              (short)param_1[0xb]);
      param_1[0xc] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x33),
                                       *(undefined1 *)((longlong)param_1 + 0x32)),
                              (short)param_1[0xc]);
      param_1[0xd] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x37),
                                       *(undefined1 *)((longlong)param_1 + 0x36)),
                              (short)param_1[0xd]);
      param_1[0xe] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x3b),
                                       *(undefined1 *)((longlong)param_1 + 0x3a)),
                              (short)param_1[0xe]);
      param_1[0xf] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x3f),
                                       *(undefined1 *)((longlong)param_1 + 0x3e)),
                              (short)param_1[0xf]);
      param_1[0x10] =
           CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x43),
                             *(undefined1 *)((longlong)param_1 + 0x42)),(short)param_1[0x10]);
      param_1[0x11] =
           CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x47),
                             *(undefined1 *)((longlong)param_1 + 0x46)),(short)param_1[0x11]);
      param_1[0x12] =
           CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x4b),
                             *(undefined1 *)((longlong)param_1 + 0x4a)),(short)param_1[0x12]);
      param_1[0x13] =
           CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x4f),
                             *(undefined1 *)((longlong)param_1 + 0x4e)),(short)param_1[0x13]);
      param_1[0x14] =
           CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x53),
                             *(undefined1 *)((longlong)param_1 + 0x52)),(short)param_1[0x14]);
      param_1[0x15] =
           CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x57),
                             *(undefined1 *)((longlong)param_1 + 0x56)),(short)param_1[0x15]);
      FUN_1800074d0(param_1,(int *)pauVar1);
      uVar12 = uVar12 + 1;
      pauVar11 = pauVar11 + 1;
    } while (uVar12 < (ulonglong)
                      -((longlong)(((ulonglong)(-(longlong)iVar15 >> 5) >> 0x3a) - (longlong)iVar15)
                       >> 6));
    pauVar14 = pauVar14 + uVar12;
    iVar15 = iVar15 + (int)uVar12 * -0x40;
  }
  FUN_180009540(pauVar1,pauVar14,(longlong)iVar15);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180002bf0(int *param_1,undefined1 (*param_2) [64],uint param_3)

{
  undefined1 (*pauVar1) [64];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [32];
  undefined1 auVar7 [32];
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  ulonglong uVar19;
  int iVar20;
  undefined1 (*pauVar21) [64];
  uint uVar22;
  undefined1 auVar23 [16];
  undefined1 auVar24 [32];
  undefined1 auVar25 [32];
  undefined1 auVar26 [32];
  undefined1 auVar27 [16];
  undefined1 auVar28 [32];
  ulonglong local_e8;
  undefined1 (*local_58) [64];
  
  uVar22 = param_1[4];
  param_1[4] = param_3 + uVar22;
  if (param_3 + uVar22 < uVar22) {
    param_1[5] = param_1[5] + 1;
  }
  uVar22 = 0x40 - (uVar22 & 0x3f);
  uVar19 = (ulonglong)uVar22;
  if (param_3 < uVar22) {
    FUN_180009540((undefined1 (*) [64])((longlong)param_1 + (0x58 - uVar19)),param_2,
                  (longlong)(int)param_3);
    return;
  }
  pauVar1 = (undefined1 (*) [64])(param_1 + 6);
  FUN_180009540((undefined1 (*) [64])((longlong)pauVar1 + (0x40 - uVar19)),param_2,uVar19);
  auVar27 = vpshufb_avx(*(undefined1 (*) [16])(param_1 + 6),_DAT_1800146e0);
  auVar23 = vpshufb_avx(*(undefined1 (*) [16])(param_1 + 10),_DAT_1800146e0);
  auVar2 = vpshufb_avx(*(undefined1 (*) [16])(param_1 + 0xe),_DAT_1800146e0);
  auVar3 = vpshufb_avx(*(undefined1 (*) [16])(param_1 + 0x12),_DAT_1800146e0);
  auVar4 = vpunpckldq_avx(auVar27,auVar23);
  auVar27 = vpunpckhdq_avx(auVar27,auVar23);
  auVar5 = vpunpckldq_avx(auVar2,auVar3);
  auVar23 = vpunpckhdq_avx(auVar2,auVar3);
  auVar3 = vpunpcklqdq_avx(auVar4,auVar5);
  auVar2 = vpunpckhqdq_avx(auVar4,auVar5);
  auVar4 = vpunpcklqdq_avx(auVar27,auVar23);
  auVar27 = vpunpckhqdq_avx(auVar27,auVar23);
  auVar6 = vpmovzxbd_avx2(auVar27);
  auVar25 = vpslld_avx2(auVar6,8);
  auVar27 = vpsrldq_avx(auVar27,8);
  auVar6 = vpmovzxbd_avx2(auVar27);
  auVar7 = vpmovzxbd_avx2(auVar4);
  auVar7 = vpor_avx2(auVar25,auVar7);
  auVar25 = vpslld_avx2(auVar6,8);
  auVar27 = vpsrldq_avx(auVar4,8);
  auVar26 = vpslld_avx2(auVar7,0x10);
  auVar6 = vpmovzxbd_avx2(auVar2);
  auVar28 = vpslld_avx2(auVar6,8);
  auVar23 = vpsrldq_avx(auVar2,8);
  auVar6 = vpmovzxbd_avx2(auVar27);
  auVar7 = vpmovzxbd_avx2(auVar23);
  auVar25 = vpor_avx2(auVar25,auVar6);
  auVar24 = vpslld_avx2(auVar7,8);
  auVar6 = vpmovzxbd_avx2(auVar3);
  auVar7 = vpor_avx2(auVar28,auVar6);
  auVar27 = vpsrldq_avx(auVar3,8);
  auVar6 = vpmovzxbd_avx2(auVar27);
  auVar7 = vpor_avx2(auVar26,auVar7);
  auVar25 = vpslld_avx2(auVar25,0x10);
  auVar6 = vpor_avx2(auVar24,auVar6);
  *(undefined1 (*) [32])(param_1 + 6) = auVar7;
  auVar6 = vpor_avx2(auVar25,auVar6);
  *(undefined1 (*) [32])(param_1 + 0xe) = auVar6;
  FUN_1800074d0(param_1,(int *)pauVar1);
  iVar20 = param_3 - uVar22;
  pauVar21 = (undefined1 (*) [64])(*param_2 + uVar19);
  if (0x3f < iVar20) {
    local_e8 = 0;
    local_58 = pauVar21;
    do {
      uVar8 = *(undefined8 *)(*local_58 + 8);
      uVar9 = *(undefined8 *)(*local_58 + 0x10);
      uVar10 = *(undefined8 *)(*local_58 + 0x18);
      *(undefined8 *)*pauVar1 = *(undefined8 *)*local_58;
      *(undefined8 *)(param_1 + 8) = uVar8;
      *(undefined8 *)(param_1 + 10) = uVar9;
      *(undefined8 *)(param_1 + 0xc) = uVar10;
      uVar8 = *(undefined8 *)(*local_58 + 0x28);
      uVar9 = *(undefined8 *)(*local_58 + 0x30);
      uVar10 = *(undefined8 *)(*local_58 + 0x38);
      iVar12 = *(int *)(*local_58 + 0x20);
      iVar17 = *(int *)(*local_58 + 0x24);
      iVar11 = *(int *)(*local_58 + 0x28);
      iVar13 = *(int *)(*local_58 + 0x2c);
      iVar16 = *(int *)(*local_58 + 0x30);
      iVar18 = *(int *)(*local_58 + 0x34);
      iVar14 = *(int *)(*local_58 + 0x38);
      iVar15 = *(int *)(*local_58 + 0x3c);
      *(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(*local_58 + 0x20);
      *(undefined8 *)(param_1 + 0x10) = uVar8;
      *(undefined8 *)(param_1 + 0x12) = uVar9;
      *(undefined8 *)(param_1 + 0x14) = uVar10;
      param_1[0x11] = iVar13;
      param_1[0xe] = iVar12;
      param_1[0x14] = iVar14;
      param_1[0x15] = iVar15;
      param_1[0x12] = iVar16;
      param_1[0xf] = iVar17;
      param_1[0x13] = iVar18;
      param_1[8] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x23),
                                     *(undefined1 *)((longlong)param_1 + 0x22)),(short)param_1[8]);
      param_1[0x10] = iVar11;
      param_1[0xb] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x2f),
                                       *(undefined1 *)((longlong)param_1 + 0x2e)),
                              (short)param_1[0xb]);
      param_1[7] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x1e),
                            CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1d),(char)param_1[7]));
      param_1[0xc] = param_1[0xc];
      param_1[6] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1b),
                                     *(undefined1 *)((longlong)param_1 + 0x1a)),
                            CONCAT11(*(undefined1 *)((longlong)param_1 + 0x19),(char)param_1[6]));
      param_1[9] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x26),
                            CONCAT11(*(undefined1 *)((longlong)param_1 + 0x25),(char)param_1[9]));
      param_1[10] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x2a),
                             CONCAT11(*(undefined1 *)((longlong)param_1 + 0x29),(char)param_1[10]));
      param_1[0xd] = CONCAT22(*(undefined2 *)((longlong)param_1 + 0x36),
                              CONCAT11(*(undefined1 *)((longlong)param_1 + 0x35),(char)param_1[0xd])
                             );
      FUN_1800074d0(param_1,(int *)pauVar1);
      local_e8 = local_e8 + 1;
      local_58 = local_58 + 1;
    } while (local_e8 <
             (ulonglong)
             -((longlong)(((ulonglong)(-(longlong)iVar20 >> 5) >> 0x3a) - (longlong)iVar20) >> 6));
    iVar20 = iVar20 + (int)local_e8 * -0x40;
    pauVar21 = pauVar21 + local_e8;
  }
  FUN_180009540(pauVar1,pauVar21,(longlong)iVar20);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180003190(int *param_1,undefined1 (*param_2) [64],uint param_3)

{
  undefined1 (*pauVar1) [64];
  undefined8 uVar2;
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
  ulonglong uVar15;
  int iVar16;
  undefined1 (*pauVar17) [64];
  uint uVar18;
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  ulonglong uVar36;
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  uint uVar37;
  uint uVar41;
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  ulonglong uVar46;
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  ulonglong local_f8;
  undefined1 (*local_78) [64];
  
  uVar18 = param_1[4];
  param_1[4] = param_3 + uVar18;
  if (param_3 + uVar18 < uVar18) {
    param_1[5] = param_1[5] + 1;
  }
  uVar18 = 0x40 - (uVar18 & 0x3f);
  uVar15 = (ulonglong)uVar18;
  if (param_3 < uVar18) {
    FUN_180009540((undefined1 (*) [64])((longlong)param_1 + (0x58 - uVar15)),param_2,
                  (longlong)(int)param_3);
    return;
  }
  pauVar1 = (undefined1 (*) [64])(param_1 + 6);
  FUN_180009540((undefined1 (*) [64])((longlong)pauVar1 + (0x40 - uVar15)),param_2,uVar15);
  auVar19 = pshufb(*(undefined1 (*) [16])(param_1 + 6),_DAT_1800146e0);
  auVar28 = pshufb(*(undefined1 (*) [16])(param_1 + 10),_DAT_1800146e0);
  auVar42 = pshufb(*(undefined1 (*) [16])(param_1 + 0xe),_DAT_1800146e0);
  auVar38 = pshufb(*(undefined1 (*) [16])(param_1 + 0x12),_DAT_1800146e0);
  auVar25._0_8_ = auVar19._0_8_;
  auVar25._8_4_ = auVar19._4_4_;
  auVar25._12_4_ = auVar28._4_4_;
  auVar24._4_4_ = auVar28._0_4_;
  auVar24._0_4_ = auVar19._0_4_;
  auVar20._0_8_ = CONCAT44(auVar28._8_4_,auVar19._8_4_);
  auVar20._8_4_ = auVar19._12_4_;
  auVar20._12_4_ = auVar28._12_4_;
  uVar41 = auVar38._8_4_;
  auVar43._0_8_ = CONCAT44(uVar41,auVar42._8_4_);
  auVar43._8_4_ = auVar42._12_4_;
  auVar43._12_4_ = auVar38._12_4_;
  auVar32._0_8_ = auVar42._0_8_;
  auVar32._8_4_ = auVar42._4_4_;
  auVar32._12_4_ = auVar38._4_4_;
  uVar36 = auVar32._8_8_;
  uVar37 = auVar38._0_4_;
  auVar35._0_8_ = CONCAT44(uVar37,auVar42._0_4_);
  uVar46 = auVar43._8_8_;
  auVar42._8_8_ = uVar46;
  auVar42._0_8_ = auVar20._8_8_;
  auVar24._8_8_ = auVar35._0_8_;
  auVar19._8_8_ = uVar36;
  auVar19._0_8_ = auVar25._8_8_;
  auVar48._8_8_ = auVar43._0_8_;
  auVar48._0_8_ = auVar20._0_8_;
  auVar25 = pmovzxbd((undefined1  [16])0x0,auVar42);
  auVar21._8_8_ = 0;
  auVar21._0_8_ = uVar46 >> 0x20;
  auVar26._0_4_ = auVar25._0_4_ << 8;
  auVar26._4_4_ = auVar25._4_4_ << 8;
  auVar26._8_4_ = auVar25._8_4_ << 8;
  auVar26._12_4_ = auVar25._12_4_ << 8;
  auVar25 = pmovzxbd(auVar21,auVar21);
  auVar28 = pmovzxbd((undefined1  [16])0x0,auVar48);
  auVar22._0_4_ = auVar25._0_4_ << 8;
  auVar22._4_4_ = auVar25._4_4_ << 8;
  auVar22._8_4_ = auVar25._8_4_ << 8;
  auVar22._12_4_ = auVar25._12_4_ << 8;
  auVar26 = auVar26 | auVar28;
  auVar25 = pmovzxbd(ZEXT416(uVar41),ZEXT416(uVar41));
  auVar29._8_8_ = 0;
  auVar29._0_8_ = uVar46;
  auVar22 = auVar22 | auVar25;
  auVar28 = pmovzxbd((undefined1  [16])0x0,auVar19);
  auVar25 = pmovzxbd(auVar29,auVar29);
  auVar47._0_4_ = auVar28._0_4_ << 8;
  auVar47._4_4_ = auVar28._4_4_ << 8;
  auVar47._8_4_ = auVar28._8_4_ << 8;
  auVar47._12_4_ = auVar28._12_4_ << 8;
  auVar44._8_8_ = 0;
  auVar44._0_8_ = auVar43._0_8_;
  auVar30._0_4_ = auVar25._0_4_ << 8;
  auVar30._4_4_ = auVar25._4_4_ << 8;
  auVar30._8_4_ = auVar25._8_4_ << 8;
  auVar30._12_4_ = auVar25._12_4_ << 8;
  auVar28 = pmovzxbd((undefined1  [16])0x0,auVar24);
  auVar27._0_4_ = auVar26._0_4_ << 0x10;
  auVar27._4_4_ = auVar26._4_4_ << 0x10;
  auVar27._8_4_ = auVar26._8_4_ << 0x10;
  auVar27._12_4_ = auVar26._12_4_ << 0x10;
  auVar25 = pmovzxbd(auVar44,auVar44);
  auVar30 = auVar30 | auVar25;
  auVar25 = pmovzxbd(auVar42 >> 0x20,auVar42 >> 0x20);
  auVar31._0_4_ = auVar30._0_4_ << 0x10;
  auVar31._4_4_ = auVar30._4_4_ << 0x10;
  auVar31._8_4_ = auVar30._8_4_ << 0x10;
  auVar31._12_4_ = auVar30._12_4_ << 0x10;
  auVar33._0_4_ = auVar25._0_4_ << 8;
  auVar33._4_4_ = auVar25._4_4_ << 8;
  auVar33._8_4_ = auVar25._8_4_ << 8;
  auVar33._12_4_ = auVar25._12_4_ << 8;
  auVar23._0_4_ = auVar22._0_4_ << 0x10;
  auVar23._4_4_ = auVar22._4_4_ << 0x10;
  auVar23._8_4_ = auVar22._8_4_ << 0x10;
  auVar23._12_4_ = auVar22._12_4_ << 0x10;
  *(undefined1 (*) [16])(param_1 + 6) = auVar27 | auVar47 | auVar28;
  auVar25 = pmovzxbd(auVar48 >> 0x20,auVar48 >> 0x20);
  auVar19 = pmovzxbd(auVar19 >> 0x20,auVar19 >> 0x20);
  auVar33 = auVar33 | auVar25;
  auVar45._0_4_ = auVar19._0_4_ << 8;
  auVar45._4_4_ = auVar19._4_4_ << 8;
  auVar45._8_4_ = auVar19._8_4_ << 8;
  auVar45._12_4_ = auVar19._12_4_ << 8;
  auVar25 = pmovzxbd(auVar24 >> 0x20,auVar24 >> 0x20);
  auVar34._0_4_ = auVar33._0_4_ << 0x10;
  auVar34._4_4_ = auVar33._4_4_ << 0x10;
  auVar34._8_4_ = auVar33._8_4_ << 0x10;
  auVar34._12_4_ = auVar33._12_4_ << 0x10;
  auVar39._8_8_ = 0;
  auVar39._0_8_ = uVar36;
  auVar28._8_8_ = 0;
  auVar28._0_8_ = uVar36 >> 0x20;
  *(undefined1 (*) [16])(param_1 + 10) = auVar34 | auVar45 | auVar25;
  auVar19 = pmovzxbd(auVar39,auVar39);
  auVar25 = pmovzxbd(auVar28,auVar28);
  auVar40._0_4_ = auVar19._0_4_ << 8;
  auVar40._4_4_ = auVar19._4_4_ << 8;
  auVar40._8_4_ = auVar19._8_4_ << 8;
  auVar40._12_4_ = auVar19._12_4_ << 8;
  auVar35._8_8_ = 0;
  auVar38._0_4_ = auVar25._0_4_ << 8;
  auVar38._4_4_ = auVar25._4_4_ << 8;
  auVar38._8_4_ = auVar25._8_4_ << 8;
  auVar38._12_4_ = auVar25._12_4_ << 8;
  auVar19 = pmovzxbd(auVar35,auVar35);
  auVar25 = pmovzxbd(ZEXT416(uVar37),ZEXT416(uVar37));
  *(undefined1 (*) [16])(param_1 + 0xe) = auVar31 | auVar40 | auVar19;
  *(undefined1 (*) [16])(param_1 + 0x12) = auVar23 | auVar38 | auVar25;
  FUN_1800074d0(param_1,(int *)pauVar1);
  iVar16 = param_3 - uVar18;
  pauVar17 = (undefined1 (*) [64])(*param_2 + uVar15);
  if (0x3f < iVar16) {
    local_f8 = 0;
    local_78 = pauVar17;
    do {
      uVar2 = *(undefined8 *)(*local_78 + 8);
      *(undefined8 *)*pauVar1 = *(undefined8 *)*local_78;
      *(undefined8 *)(param_1 + 8) = uVar2;
      uVar2 = *(undefined8 *)(*local_78 + 0x18);
      iVar3 = *(int *)(*local_78 + 0x10);
      iVar4 = *(int *)(*local_78 + 0x14);
      iVar5 = *(int *)(*local_78 + 0x18);
      iVar6 = *(int *)(*local_78 + 0x1c);
      *(undefined8 *)(param_1 + 10) = *(undefined8 *)(*local_78 + 0x10);
      *(undefined8 *)(param_1 + 0xc) = uVar2;
      uVar2 = *(undefined8 *)(*local_78 + 0x28);
      iVar7 = *(int *)(*local_78 + 0x20);
      iVar8 = *(int *)(*local_78 + 0x24);
      iVar9 = *(int *)(*local_78 + 0x28);
      iVar10 = *(int *)(*local_78 + 0x2c);
      *(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(*local_78 + 0x20);
      *(undefined8 *)(param_1 + 0x10) = uVar2;
      uVar2 = *(undefined8 *)(*local_78 + 0x38);
      iVar11 = *(int *)(*local_78 + 0x30);
      iVar12 = *(int *)(*local_78 + 0x34);
      iVar13 = *(int *)(*local_78 + 0x38);
      iVar14 = *(int *)(*local_78 + 0x3c);
      *(undefined8 *)(param_1 + 0x12) = *(undefined8 *)(*local_78 + 0x30);
      *(undefined8 *)(param_1 + 0x14) = uVar2;
      param_1[10] = iVar3;
      param_1[0xb] = iVar4;
      param_1[0xc] = iVar5;
      param_1[0xd] = iVar6;
      param_1[0xe] = iVar7;
      param_1[0xf] = iVar8;
      param_1[0x10] = iVar9;
      param_1[0x11] = iVar10;
      param_1[0x12] = iVar11;
      param_1[0x13] = iVar12;
      param_1[0x14] = iVar13;
      param_1[0x15] = iVar14;
      param_1[6] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1b),
                                     *(undefined1 *)((longlong)param_1 + 0x1a)),(short)param_1[6]);
      param_1[7] = param_1[7];
      param_1[8] = param_1[8];
      param_1[9] = param_1[9];
      FUN_1800074d0(param_1,(int *)pauVar1);
      local_f8 = local_f8 + 1;
      local_78 = local_78 + 1;
    } while (local_f8 <
             (ulonglong)
             -((longlong)(((ulonglong)(-(longlong)iVar16 >> 5) >> 0x3a) - (longlong)iVar16) >> 6));
    iVar16 = iVar16 + (int)local_f8 * -0x40;
    pauVar17 = pauVar17 + local_f8;
  }
  FUN_180009540(pauVar1,pauVar17,(longlong)iVar16);
  return;
}



void FUN_1800039b0(int *param_1,undefined1 (*param_2) [64],uint param_3)

{
  undefined1 (*pauVar1) [64];
  undefined8 uVar2;
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
  ulonglong uVar15;
  int iVar16;
  undefined1 (*pauVar17) [64];
  uint uVar18;
  ulonglong local_f8;
  undefined1 (*local_78) [64];
  
  uVar18 = param_1[4];
  param_1[4] = param_3 + uVar18;
  if (param_3 + uVar18 < uVar18) {
    param_1[5] = param_1[5] + 1;
  }
  uVar18 = 0x40 - (uVar18 & 0x3f);
  uVar15 = (ulonglong)uVar18;
  if (param_3 < uVar18) {
    FUN_180009540((undefined1 (*) [64])((longlong)param_1 + (0x58 - uVar15)),param_2,
                  (longlong)(int)param_3);
    return;
  }
  pauVar1 = (undefined1 (*) [64])(param_1 + 6);
  FUN_180009540((undefined1 (*) [64])((longlong)pauVar1 + (0x40 - uVar15)),param_2,uVar15);
  param_1[7] = param_1[7];
  param_1[8] = param_1[8];
  param_1[9] = param_1[9];
  param_1[10] = param_1[10];
  param_1[0xb] = param_1[0xb];
  param_1[0xc] = param_1[0xc];
  param_1[0xd] = param_1[0xd];
  param_1[0xe] = param_1[0xe];
  param_1[0xf] = param_1[0xf];
  param_1[0x10] = param_1[0x10];
  param_1[0x11] = param_1[0x11];
  param_1[0x12] = param_1[0x12];
  param_1[0x13] = param_1[0x13];
  param_1[0x14] = param_1[0x14];
  param_1[6] = param_1[6];
  param_1[0x15] = param_1[0x15];
  FUN_1800074d0(param_1,(int *)pauVar1);
  iVar16 = param_3 - uVar18;
  pauVar17 = (undefined1 (*) [64])(*param_2 + uVar15);
  if (0x3f < iVar16) {
    local_f8 = 0;
    local_78 = pauVar17;
    do {
      uVar2 = *(undefined8 *)(*local_78 + 8);
      *(undefined8 *)*pauVar1 = *(undefined8 *)*local_78;
      *(undefined8 *)(param_1 + 8) = uVar2;
      uVar2 = *(undefined8 *)(*local_78 + 0x18);
      iVar3 = *(int *)(*local_78 + 0x10);
      iVar4 = *(int *)(*local_78 + 0x14);
      iVar5 = *(int *)(*local_78 + 0x18);
      iVar6 = *(int *)(*local_78 + 0x1c);
      *(undefined8 *)(param_1 + 10) = *(undefined8 *)(*local_78 + 0x10);
      *(undefined8 *)(param_1 + 0xc) = uVar2;
      uVar2 = *(undefined8 *)(*local_78 + 0x28);
      iVar7 = *(int *)(*local_78 + 0x20);
      iVar8 = *(int *)(*local_78 + 0x24);
      iVar9 = *(int *)(*local_78 + 0x28);
      iVar10 = *(int *)(*local_78 + 0x2c);
      *(undefined8 *)(param_1 + 0xe) = *(undefined8 *)(*local_78 + 0x20);
      *(undefined8 *)(param_1 + 0x10) = uVar2;
      uVar2 = *(undefined8 *)(*local_78 + 0x38);
      iVar11 = *(int *)(*local_78 + 0x30);
      iVar12 = *(int *)(*local_78 + 0x34);
      iVar13 = *(int *)(*local_78 + 0x38);
      iVar14 = *(int *)(*local_78 + 0x3c);
      *(undefined8 *)(param_1 + 0x12) = *(undefined8 *)(*local_78 + 0x30);
      *(undefined8 *)(param_1 + 0x14) = uVar2;
      param_1[10] = iVar3;
      param_1[0xb] = iVar4;
      param_1[0xc] = iVar5;
      param_1[0xd] = iVar6;
      param_1[0xe] = iVar7;
      param_1[0xf] = iVar8;
      param_1[0x10] = iVar9;
      param_1[0x11] = iVar10;
      param_1[0x12] = iVar11;
      param_1[0x13] = iVar12;
      param_1[0x14] = iVar13;
      param_1[0x15] = iVar14;
      param_1[6] = CONCAT22(CONCAT11(*(undefined1 *)((longlong)param_1 + 0x1b),
                                     *(undefined1 *)((longlong)param_1 + 0x1a)),(short)param_1[6]);
      param_1[7] = param_1[7];
      param_1[8] = param_1[8];
      param_1[9] = param_1[9];
      FUN_1800074d0(param_1,(int *)pauVar1);
      local_f8 = local_f8 + 1;
      local_78 = local_78 + 1;
    } while (local_f8 <
             (ulonglong)
             -((longlong)(((ulonglong)(-(longlong)iVar16 >> 5) >> 0x3a) - (longlong)iVar16) >> 6));
    iVar16 = iVar16 + (int)local_f8 * -0x40;
    pauVar17 = pauVar17 + local_f8;
  }
  FUN_180009540(pauVar1,pauVar17,(longlong)iVar16);
  return;
}



void FUN_180004240(undefined1 (*param_1) [16],undefined1 (*param_2) [64])

{
  ulonglong uVar1;
  
  uVar1 = 0x64199d97ff;
  while( true ) {
    if ((uVar1 & CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408)) == uVar1) {
      FUN_1800042e0(param_1,(undefined1 (*) [32])param_2);
      return;
    }
    if ((CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408) & 0x7189d97ff) == 0x7189d97ff) {
      FUN_180004780(param_1,param_2);
      return;
    }
    if (((uint)DAT_180019408 & 0x9d97ff) == 0x9d97ff) {
      FUN_180004d40(param_1,(undefined1 (*) [32])param_2);
      return;
    }
    if (((uint)DAT_180019408 & 0x3ff) == 0x3ff) break;
    if (((uint)DAT_180019408 & 1) != 0) {
      FUN_180005800((undefined8 *)param_1,(undefined1 (*) [16])param_2);
      return;
    }
    uVar1 = FUN_180008f60();
  }
  FUN_1800051e0((undefined8 *)param_1,(undefined1 (*) [16])param_2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_1800042e0(undefined1 (*param_1) [16],undefined1 (*param_2) [32])

{
  undefined1 (*pauVar1) [64];
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  int iVar10;
  undefined2 uVar11;
  undefined4 uVar12;
  longlong lVar13;
  undefined1 (*pauVar14) [64];
  ulonglong uVar15;
  longlong lVar16;
  undefined1 auVar17 [16];
  undefined1 auVar18 [32];
  undefined1 auVar19 [32];
  undefined1 auVar20 [32];
  undefined1 auVar21 [32];
  undefined1 auVar22 [16];
  undefined1 auVar23 [32];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [32];
  
  pauVar1 = (undefined1 (*) [64])(*param_2 + 0x18);
  uVar15 = (ulonglong)(*(uint *)(*param_2 + 0x10) & 0x3f);
  puVar2 = *param_2 + uVar15 + 0x18;
  lVar16 = -uVar15;
  *puVar2 = 0x80;
  lVar13 = lVar16 + 0x37;
  if (lVar16 < -0x37) {
    FUN_180009600((undefined1 (*) [64])(puVar2 + 1),0,lVar16 + 0x3f);
    auVar22 = vpshufb_avx(*(undefined1 (*) [16])*pauVar1,_DAT_1800146e0);
    auVar24 = vpshufb_avx512vl(*(undefined1 (*) [16])(param_2[1] + 8),_DAT_1800146e0);
    auVar25 = vpshufb_avx512vl(*(undefined1 (*) [16])(param_2[1] + 0x18),_DAT_1800146e0);
    auVar17 = vpshufb_avx512vl(*(undefined1 (*) [16])(param_2[2] + 8),_DAT_1800146e0);
    auVar26 = vpunpckldq_avx512vl(auVar22,auVar24);
    auVar22 = vpunpckhdq_avx512vl(auVar22,auVar24);
    auVar24 = vpunpckldq_avx512vl(auVar25,auVar17);
    auVar25 = vpunpckhdq_avx512vl(auVar25,auVar17);
    auVar17 = vpunpcklqdq_avx512vl(auVar26,auVar24);
    auVar24 = vpunpckhqdq_avx512vl(auVar26,auVar24);
    auVar26 = vpunpcklqdq_avx512vl(auVar22,auVar25);
    auVar22 = vpunpckhqdq_avx512vl(auVar22,auVar25);
    auVar18 = vpmovzxbd_avx2(auVar22);
    auVar22 = vpsrldq_avx(auVar22,8);
    auVar23 = vpmovzxbd_avx512vl(auVar22);
    auVar27 = vpslld_avx2(auVar18,8);
    auVar18 = vpslld_avx512vl(auVar23,8);
    auVar23 = vpmovzxbd_avx512vl(auVar26);
    auVar22 = vpsrldq_avx(auVar26,8);
    auVar19 = vpmovzxbd_avx512vl(auVar22);
    auVar23 = vpord_avx512vl(auVar27,auVar23);
    auVar18 = vpord_avx512vl(auVar18,auVar19);
    auVar23 = vpslld_avx512vl(auVar23,0x10);
    auVar18 = vpslld_avx512vl(auVar18,0x10);
    auVar19 = vpmovzxbd_avx512vl(auVar24);
    auVar22 = vpsrldq_avx(auVar24,8);
    auVar27 = vpmovzxbd_avx512vl(auVar22);
    auVar19 = vpslld_avx512vl(auVar19,8);
    auVar27 = vpslld_avx512vl(auVar27,8);
    auVar20 = vpmovzxbd_avx512vl(auVar17);
    auVar22 = vpsrldq_avx(auVar17,8);
    auVar21 = vpmovzxbd_avx512vl(auVar22);
    auVar23 = vpternlogd_avx512vl(auVar23,auVar19,auVar20,0xfe);
    auVar19 = vpternlogd_avx512vl(auVar18,auVar27,auVar21,0xfe);
    auVar18 = vmovdqu32_avx512vl(auVar23);
    *(undefined1 (*) [32])*pauVar1 = auVar18;
    auVar18 = vmovdqu32_avx512vl(auVar19);
    *(undefined1 (*) [32])(param_2[1] + 0x18) = auVar18;
    FUN_1800074d0((int *)param_2,(int *)pauVar1);
    lVar13 = 0x38;
    pauVar14 = pauVar1;
  }
  else {
    pauVar14 = (undefined1 (*) [64])(puVar2 + 1);
  }
  FUN_180009600(pauVar14,0,lVar13 + 8);
  auVar22 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x1b]),(uint)(byte)(*param_2)[0x1f],1);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)param_2[1][3],2);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)param_2[1][7],3);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)param_2[1][0xb],4);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[3][0xb],5);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[3][0x1b],6);
  auVar24 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[4][0xb],7);
  auVar22 = vpinsrb_avx512bw(ZEXT116((byte)(*param_2)[0x1a]),(uint)(byte)param_2[1][10],1);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[1][0x1a],2);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[2][10],3);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[2][0x1a],4);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[3][10],5);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[3][0x1a],6);
  auVar25 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[4][10],7);
  auVar22 = vpinsrb_avx512bw(ZEXT116((byte)(*param_2)[0x19]),(uint)(byte)param_2[1][9],1);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[1][0x19],2);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[2][9],3);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[2][0x19],4);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[3][9],5);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[3][0x19],6);
  auVar17 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[4][9],7);
  uVar3 = param_2[1][0x1e];
  auVar22 = vpinsrb_avx512bw(ZEXT116((byte)*(int *)*pauVar1),(uint)(byte)param_2[1][8],1);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[1][0x18],2);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)param_2[1][4],3);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)param_2[1][8],4);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)param_2[1][0xc],5);
  uVar4 = param_2[1][0x1f];
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)param_2[1][0x10],6);
  uVar12 = *(undefined4 *)param_2[2];
  uVar11 = *(undefined2 *)(param_2[1] + 0x1c);
  uVar5 = param_2[2][7];
  auVar18 = vpmovzxbd_avx512vl(auVar24);
  *(uint *)(param_2[1] + 0x18) =
       CONCAT22(CONCAT11(param_2[1][0x1b],param_2[1][0x1a]),
                CONCAT11(param_2[1][0x19],param_2[1][0x18]));
  *(undefined4 *)param_2[2] = uVar12;
  auVar23 = vpslld_avx2(auVar18,8);
  auVar22 = vpinsrb_avx512bw(auVar22,(uint)(byte)param_2[4][8],7);
  uVar6 = param_2[2][0xb];
  auVar18 = vpmovzxbd_avx512vl(auVar25);
  *(uint *)(param_2[2] + 4) =
       CONCAT22(CONCAT11(uVar5,param_2[2][6]),*(undefined2 *)(param_2[2] + 4));
  auVar18 = vpord_avx512vl(auVar23,auVar18);
  *(uint *)(param_2[2] + 8) =
       CONCAT22(CONCAT11(uVar6,param_2[2][10]),CONCAT11(param_2[2][9],param_2[2][8]));
  uVar5 = param_2[2][0xf];
  auVar23 = vpmovzxbd_avx512vl(auVar17);
  uVar6 = param_2[2][0xe];
  uVar7 = param_2[2][0xd];
  auVar18 = vpslld_avx512vl(auVar18,0x10);
  auVar23 = vpslld_avx512vl(auVar23,8);
  uVar8 = param_2[2][0xc];
  uVar9 = *(uint *)(*param_2 + 0x10);
  auVar19 = vpmovzxbd_avx512vl(auVar22);
  auVar18 = vpternlogd_avx512vl(auVar18,auVar23,auVar19,0xfe);
  auVar18 = vmovdqu32_avx512vl(auVar18);
  *(undefined1 (*) [32])*pauVar1 = auVar18;
  *(uint *)(param_2[2] + 0x10) = uVar9 * 8;
  iVar10 = *(int *)(*param_2 + 0x14);
  *(uint *)(param_2[1] + 0x1c) = CONCAT22(CONCAT11(uVar4,uVar3),uVar11);
  *(uint *)(param_2[2] + 0xc) = CONCAT22(CONCAT11(uVar5,uVar6),CONCAT11(uVar7,uVar8));
  *(uint *)(param_2[2] + 0x14) = iVar10 << 3 | uVar9 >> 0x1d;
  FUN_1800074d0((int *)param_2,(int *)pauVar1);
  auVar22 = vpunpcklbw_avx(ZEXT416(*(uint *)*param_2),ZEXT416(*(uint *)(*param_2 + 4)));
  auVar24 = vpunpcklbw_avx(ZEXT416(*(uint *)(*param_2 + 8)),ZEXT416(*(uint *)(*param_2 + 0xc)));
  auVar17 = vpunpcklwd_avx(auVar22,auVar24);
  auVar24 = vpsrldq_avx(auVar17,8);
  auVar25 = vpsrldq_avx(auVar17,4);
  auVar22 = vpsrldq_avx(auVar24,4);
  auVar22 = vpmovzxbd_avx(auVar22);
  auVar24 = vpmovzxbd_avx(auVar24);
  auVar26 = vpslld_avx(auVar22,8);
  auVar22 = vpmovzxbd_avx(auVar25);
  auVar25 = vpor_avx(auVar26,auVar24);
  auVar24 = vpmovzxbd_avx(auVar17);
  auVar25 = vpslld_avx512vl(auVar25,0x10);
  auVar22 = vpslld_avx512vl(auVar22,8);
  auVar24 = vpternlogd_avx512vl(auVar25,auVar22,auVar24,0xfe);
  auVar22 = vmovdqu32_avx512vl(auVar24);
  *(undefined1 (*) [16])*param_2 = auVar22;
  *param_1 = auVar24;
  *param_2 = (undefined1  [32])0x0;
  param_2[1] = (undefined1  [32])0x0;
  *(undefined1 (*) [16])param_2[2] = ZEXT816(0);
  *(undefined8 *)(param_2[2] + 0x10) = 0;
  return;
}



void FUN_180004780(undefined1 (*param_1) [16],undefined1 (*param_2) [64])

{
  undefined1 (*pauVar1) [64];
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [32];
  longlong lVar15;
  undefined1 (*pauVar16) [64];
  ulonglong uVar17;
  longlong lVar18;
  undefined1 auVar19 [64];
  undefined1 auVar20 [64];
  undefined1 auVar21 [64];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [32];
  undefined1 auVar25 [32];
  
  uVar17 = (ulonglong)(*(uint *)(*param_2 + 0x10) & 0x3f);
  puVar2 = *param_2 + uVar17 + 0x18;
  *puVar2 = 0x80;
  lVar18 = -uVar17;
  pauVar1 = (undefined1 (*) [64])(*param_2 + 0x18);
  lVar15 = lVar18 + 0x37;
  if (lVar18 < -0x37) {
    FUN_180009600((undefined1 (*) [64])(puVar2 + 1),0,lVar18 + 0x3f);
    auVar11 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x1b]),(uint)(byte)(*param_2)[0x1f],1);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x23],2);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x27],3);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2b],4);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2f],5);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x33],6);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x37],7);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x3b],8);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x3f],9);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][3],10);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][7],0xb);
    auVar22 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x1a]),(uint)(byte)(*param_2)[0x1e],1);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0xb],0xc);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0xf],0xd);
    auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x22],2);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x13],0xe);
    auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x26],3);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x17],0xf);
    auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x2a],4);
    auVar19 = vpmovzxbd_avx512f(auVar11);
    auVar11 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x2e],5);
    auVar19 = vpslld_avx512f(auVar19,8);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x32],6);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x36],7);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x3a],8);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x3e],9);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][2],10);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][6],0xb);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][10],0xc);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0xe],0xd);
    auVar22 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x19]),(uint)(byte)(*param_2)[0x1d],1);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x12],0xe);
    auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x21],2);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x16],0xf);
    auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x25],3);
    auVar20 = vpmovzxbd_avx512f(auVar11);
    auVar11 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x29],4);
    auVar19 = vpord_avx512f(auVar19,auVar20);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2d],5);
    auVar19 = vpslld_avx512f(auVar19,0x10);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x31],6);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x35],7);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x39],8);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x3d],9);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][1],10);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][5],0xb);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][9],0xc);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0xd],0xd);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x11],0xe);
    auVar22 = vpinsrb_avx(ZEXT116((byte)*(int *)*pauVar1),(uint)(byte)(*param_2)[0x1c],1);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x15],0xf);
    auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x20],2);
    auVar20 = vpmovzxbd_avx512f(auVar11);
    auVar11 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0x24],3);
    auVar20 = vpslld_avx512f(auVar20,8);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x28],4);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2c],5);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x30],6);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x34],7);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x38],8);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x3c],9);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0],10);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][4],0xb);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][8],0xc);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0xc],0xd);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x10],0xe);
    auVar11 = vpinsrb_avx(auVar11,(uint)(byte)param_2[1][0x14],0xf);
    auVar21 = vpmovzxbd_avx512f(auVar11);
    auVar19 = vpternlogd_avx512f(auVar19,auVar20,auVar21,0xfe);
    auVar19 = vmovdqu32_avx512f(auVar19);
    *pauVar1 = auVar19;
    FUN_1800074d0((int *)param_2,(int *)pauVar1);
    lVar15 = 0x38;
    pauVar16 = pauVar1;
  }
  else {
    pauVar16 = (undefined1 (*) [64])(puVar2 + 1);
  }
  FUN_180009600(pauVar16,0,lVar15 + 8);
  auVar11 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x1b]),(uint)(byte)(*param_2)[0x1f],1);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x23],2);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x27],3);
  uVar3 = param_2[1][2];
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2b],4);
  uVar4 = param_2[1][1];
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2f],5);
  uVar5 = param_2[1][0];
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x33],6);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x37],7);
  auVar14 = vpmovzxbd_avx2(auVar11);
  auVar24 = vpslld_avx2(auVar14,8);
  auVar11 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x1a]),(uint)(byte)(*param_2)[0x1e],1);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x22],2);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x26],3);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2a],4);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2e],5);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x32],6);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x36],7);
  auVar14 = vpmovzxbd_avx2(auVar11);
  auVar14 = vpor_avx2(auVar24,auVar14);
  auVar11 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x19]),(uint)(byte)(*param_2)[0x1d],1);
  auVar25 = vpslld_avx2(auVar14,0x10);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x21],2);
  uVar6 = param_2[1][7];
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x25],3);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x29],4);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2d],5);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x31],6);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x35],7);
  *(uint *)(*param_2 + 0x38) =
       CONCAT22(*(undefined2 *)(*param_2 + 0x3a),CONCAT11((*param_2)[0x39],(*param_2)[0x38]));
  uVar7 = param_2[1][6];
  auVar14 = vpmovzxbd_avx2(auVar11);
  auVar24 = vpslld_avx2(auVar14,8);
  uVar8 = param_2[1][4];
  auVar11 = vpinsrb_avx(ZEXT116((byte)*(int *)*pauVar1),(uint)(byte)(*param_2)[0x1c],1);
  uVar9 = param_2[1][3];
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x20],2);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x24],3);
  *(uint *)(*param_2 + 0x3c) =
       CONCAT22(CONCAT11((*param_2)[0x3f],(*param_2)[0x3e]),
                CONCAT11((*param_2)[0x3d],(*param_2)[0x3c]));
  uVar10 = param_2[1][0xb];
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x28],4);
  *(uint *)param_2[1] = CONCAT22(CONCAT11(uVar9,uVar3),CONCAT11(uVar4,uVar5));
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x2c],5);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x30],6);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0x34],7);
  *(uint *)(param_2[1] + 4) = CONCAT22(CONCAT11(uVar6,uVar7),CONCAT11(param_2[1][5],uVar8));
  uVar3 = param_2[1][10];
  auVar14 = vpmovzxbd_avx2(auVar11);
  uVar4 = param_2[1][9];
  auVar14 = vpor_avx2(auVar24,auVar14);
  uVar5 = param_2[1][8];
  auVar14 = vpor_avx2(auVar25,auVar14);
  *(undefined1 (*) [32])*pauVar1 = auVar14;
  uVar6 = param_2[1][0xe];
  *(uint *)(param_2[1] + 8) = CONCAT22(CONCAT11(uVar10,uVar3),CONCAT11(uVar4,uVar5));
  *(uint *)(param_2[1] + 0xc) =
       CONCAT22(CONCAT11(param_2[1][0xf],uVar6),*(undefined2 *)(param_2[1] + 0xc));
  *(uint *)(param_2[1] + 0x10) = *(uint *)(*param_2 + 0x10) * 8;
  *(uint *)(param_2[1] + 0x14) = *(int *)(*param_2 + 0x14) << 3 | *(uint *)(*param_2 + 0x10) >> 0x1d
  ;
  FUN_1800074d0((int *)param_2,(int *)pauVar1);
  auVar11 = vpinsrb_avx(ZEXT116((byte)(*param_2)[3]),(uint)(byte)(*param_2)[7],1);
  auVar22 = vpinsrb_avx(ZEXT116((byte)(*param_2)[2]),(uint)(byte)(*param_2)[6],1);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0xb],2);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[10],2);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0xf],3);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0xe],3);
  auVar23 = vpinsrb_avx(ZEXT116((byte)(*param_2)[1]),(uint)(byte)(*param_2)[5],1);
  auVar12 = vpmovzxbd_avx(auVar11);
  auVar11 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0]),(uint)(byte)(*param_2)[4],1);
  auVar13 = vpmovzxbd_avx(auVar22);
  auVar22 = vpinsrb_avx(auVar23,(uint)(byte)(*param_2)[9],2);
  auVar23 = vpslld_avx(auVar12,8);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[8],2);
  auVar23 = vpor_avx(auVar23,auVar13);
  auVar22 = vpinsrb_avx(auVar22,(uint)(byte)(*param_2)[0xd],3);
  auVar11 = vpinsrb_avx(auVar11,(uint)(byte)(*param_2)[0xc],3);
  auVar22 = vpmovzxbd_avx(auVar22);
  auVar11 = vpmovzxbd_avx(auVar11);
  auVar23 = vpslld_avx(auVar23,0x10);
  auVar22 = vpslld_avx(auVar22,8);
  auVar11 = vpor_avx(auVar22,auVar11);
  auVar11 = vpor_avx(auVar23,auVar11);
  *(undefined1 (*) [16])*param_2 = auVar11;
  *param_1 = auVar11;
  *param_2 = (undefined1  [64])0x0;
  *(undefined1 (*) [16])param_2[1] = ZEXT816(0);
  *(undefined8 *)(param_2[1] + 0x10) = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180004d40(undefined1 (*param_1) [16],undefined1 (*param_2) [32])

{
  undefined1 (*pauVar1) [64];
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [32];
  undefined2 uVar15;
  longlong lVar16;
  undefined1 (*pauVar17) [64];
  ulonglong uVar18;
  longlong lVar19;
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [32];
  undefined1 auVar23 [32];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [32];
  undefined1 auVar27 [32];
  undefined1 auVar28 [32];
  
  pauVar1 = (undefined1 (*) [64])(*param_2 + 0x18);
  uVar18 = (ulonglong)(*(uint *)(*param_2 + 0x10) & 0x3f);
  puVar2 = *param_2 + uVar18 + 0x18;
  lVar19 = -uVar18;
  *puVar2 = 0x80;
  lVar16 = lVar19 + 0x37;
  if (lVar19 < -0x37) {
    FUN_180009600((undefined1 (*) [64])(puVar2 + 1),0,lVar19 + 0x3f);
    auVar20 = vpshufb_avx(*(undefined1 (*) [16])*pauVar1,_DAT_1800146e0);
    auVar21 = vpshufb_avx(*(undefined1 (*) [16])(param_2[1] + 8),_DAT_1800146e0);
    auVar24 = vpshufb_avx(*(undefined1 (*) [16])(param_2[1] + 0x18),_DAT_1800146e0);
    auVar12 = vpshufb_avx(*(undefined1 (*) [16])(param_2[2] + 8),_DAT_1800146e0);
    auVar25 = vpunpckldq_avx(auVar20,auVar21);
    auVar20 = vpunpckhdq_avx(auVar20,auVar21);
    auVar13 = vpunpckldq_avx(auVar24,auVar12);
    auVar21 = vpunpckhdq_avx(auVar24,auVar12);
    auVar12 = vpunpcklqdq_avx(auVar25,auVar13);
    auVar24 = vpunpckhqdq_avx(auVar25,auVar13);
    auVar25 = vpunpcklqdq_avx(auVar20,auVar21);
    auVar20 = vpunpckhqdq_avx(auVar20,auVar21);
    auVar14 = vpmovzxbd_avx2(auVar20);
    auVar26 = vpslld_avx2(auVar14,8);
    auVar20 = vpsrldq_avx(auVar20,8);
    auVar14 = vpmovzxbd_avx2(auVar20);
    auVar22 = vpmovzxbd_avx2(auVar25);
    auVar22 = vpor_avx2(auVar26,auVar22);
    auVar26 = vpslld_avx2(auVar14,8);
    auVar20 = vpsrldq_avx(auVar25,8);
    auVar28 = vpslld_avx2(auVar22,0x10);
    auVar14 = vpmovzxbd_avx2(auVar24);
    auVar27 = vpslld_avx2(auVar14,8);
    auVar21 = vpsrldq_avx(auVar24,8);
    auVar14 = vpmovzxbd_avx2(auVar20);
    auVar22 = vpmovzxbd_avx2(auVar21);
    auVar26 = vpor_avx2(auVar26,auVar14);
    auVar23 = vpslld_avx2(auVar22,8);
    auVar14 = vpmovzxbd_avx2(auVar12);
    auVar22 = vpor_avx2(auVar27,auVar14);
    auVar20 = vpsrldq_avx(auVar12,8);
    auVar14 = vpmovzxbd_avx2(auVar20);
    auVar22 = vpor_avx2(auVar28,auVar22);
    auVar26 = vpslld_avx2(auVar26,0x10);
    auVar14 = vpor_avx2(auVar23,auVar14);
    *(undefined1 (*) [32])*pauVar1 = auVar22;
    auVar14 = vpor_avx2(auVar26,auVar14);
    *(undefined1 (*) [32])(param_2[1] + 0x18) = auVar14;
    FUN_1800074d0((int *)param_2,(int *)pauVar1);
    lVar16 = 0x38;
    pauVar17 = pauVar1;
  }
  else {
    pauVar17 = (undefined1 (*) [64])(puVar2 + 1);
  }
  FUN_180009600(pauVar17,0,lVar16 + 8);
  auVar20 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x1b]),(uint)(byte)(*param_2)[0x1f],1);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][3],2);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][7],3);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][0xb],4);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][0xf],5);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][0x13],6);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][0x17],7);
  auVar14 = vpmovzxbd_avx2(auVar20);
  auVar20 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x1a]),(uint)(byte)(*param_2)[0x1e],1);
  auVar26 = vpslld_avx2(auVar14,8);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][2],2);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][6],3);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][10],4);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][0xe],5);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][0x12],6);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)param_2[1][0x16],7);
  auVar21 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0x19]),(uint)(byte)(*param_2)[0x1d],1);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)param_2[1][1],2);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)param_2[1][5],3);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)param_2[1][9],4);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)param_2[1][0xd],5);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)param_2[1][0x11],6);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)param_2[1][0x15],7);
  uVar3 = param_2[1][0x1e];
  auVar24 = vpinsrb_avx(ZEXT116((byte)*(int *)*pauVar1),(uint)(byte)(*param_2)[0x1c],1);
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)param_2[1][0],2);
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)param_2[1][4],3);
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)param_2[1][8],4);
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)param_2[1][0xc],5);
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)param_2[1][0x10],6);
  uVar4 = param_2[1][0x1f];
  uVar15 = *(undefined2 *)(param_2[2] + 2);
  uVar5 = param_2[2][1];
  uVar6 = param_2[1][0x1d];
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)param_2[1][0x14],7);
  uVar7 = param_2[2][0];
  uVar8 = param_2[1][0x1c];
  uVar9 = param_2[2][7];
  *(uint *)(param_2[1] + 0x18) =
       CONCAT22(CONCAT11(param_2[1][0x1b],param_2[1][0x1a]),
                CONCAT11(param_2[1][0x19],param_2[1][0x18]));
  *(uint *)param_2[2] = CONCAT22(uVar15,CONCAT11(uVar5,uVar7));
  uVar5 = param_2[2][0xb];
  auVar14 = vpmovzxbd_avx2(auVar20);
  auVar22 = vpmovzxbd_avx2(auVar21);
  *(uint *)(param_2[2] + 4) =
       CONCAT22(CONCAT11(uVar9,param_2[2][6]),*(undefined2 *)(param_2[2] + 4));
  auVar14 = vpor_avx2(auVar26,auVar14);
  auVar22 = vpslld_avx2(auVar22,8);
  auVar26 = vpslld_avx2(auVar14,0x10);
  auVar14 = vpmovzxbd_avx2(auVar24);
  *(uint *)(param_2[2] + 8) =
       CONCAT22(CONCAT11(uVar5,param_2[2][10]),*(undefined2 *)(param_2[2] + 8));
  uVar5 = param_2[2][0xf];
  auVar14 = vpor_avx2(auVar22,auVar14);
  uVar7 = param_2[2][0xe];
  uVar15 = *(undefined2 *)(param_2[2] + 0xc);
  uVar10 = *(uint *)(*param_2 + 0x10);
  auVar14 = vpor_avx2(auVar26,auVar14);
  *(undefined1 (*) [32])*pauVar1 = auVar14;
  *(uint *)(param_2[2] + 0x10) = uVar10 * 8;
  iVar11 = *(int *)(*param_2 + 0x14);
  *(uint *)(param_2[1] + 0x1c) = CONCAT22(CONCAT11(uVar4,uVar3),CONCAT11(uVar6,uVar8));
  *(uint *)(param_2[2] + 0xc) = CONCAT22(CONCAT11(uVar5,uVar7),uVar15);
  *(uint *)(param_2[2] + 0x14) = iVar11 << 3 | uVar10 >> 0x1d;
  FUN_1800074d0((int *)param_2,(int *)pauVar1);
  auVar20 = vpinsrb_avx(ZEXT116((byte)(*param_2)[3]),(uint)(byte)(*param_2)[7],1);
  auVar21 = vpinsrb_avx(ZEXT116((byte)(*param_2)[2]),(uint)(byte)(*param_2)[6],1);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)(*param_2)[0xb],2);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)(*param_2)[10],2);
  auVar20 = vpinsrb_avx(auVar20,(uint)(byte)(*param_2)[0xf],3);
  auVar21 = vpinsrb_avx(auVar21,(uint)(byte)(*param_2)[0xe],3);
  auVar24 = vpinsrb_avx(ZEXT116((byte)(*param_2)[1]),(uint)(byte)(*param_2)[5],1);
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)(*param_2)[9],2);
  auVar12 = vpinsrb_avx(ZEXT116((byte)(*param_2)[0]),(uint)(byte)(*param_2)[4],1);
  auVar24 = vpinsrb_avx(auVar24,(uint)(byte)(*param_2)[0xd],3);
  auVar12 = vpinsrb_avx(auVar12,(uint)(byte)(*param_2)[8],2);
  auVar12 = vpinsrb_avx(auVar12,(uint)(byte)(*param_2)[0xc],3);
  auVar20 = vpmovzxbd_avx(auVar20);
  auVar21 = vpmovzxbd_avx(auVar21);
  auVar25 = vpslld_avx(auVar20,8);
  auVar20 = vpmovzxbd_avx(auVar24);
  auVar24 = vpor_avx(auVar25,auVar21);
  auVar21 = vpmovzxbd_avx(auVar12);
  auVar20 = vpslld_avx(auVar20,8);
  auVar24 = vpslld_avx(auVar24,0x10);
  auVar20 = vpor_avx(auVar20,auVar21);
  auVar20 = vpor_avx(auVar24,auVar20);
  *(undefined1 (*) [16])*param_2 = auVar20;
  *param_1 = auVar20;
  *param_2 = (undefined1  [32])0x0;
  param_2[1] = (undefined1  [32])0x0;
  *(undefined1 (*) [16])param_2[2] = ZEXT816(0);
  *(undefined8 *)(param_2[2] + 0x10) = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_1800051e0(undefined8 *param_1,undefined1 (*param_2) [16])

{
  undefined1 (*pauVar1) [64];
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  longlong lVar10;
  undefined1 (*pauVar11) [64];
  undefined4 uVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  uint uVar33;
  uint uVar37;
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  ulonglong uVar42;
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  
  pauVar1 = (undefined1 (*) [64])(param_2[1] + 8);
  uVar13 = (ulonglong)(*(uint *)param_2[1] & 0x3f);
  puVar2 = param_2[1] + uVar13 + 8;
  lVar14 = -uVar13;
  *puVar2 = 0x80;
  lVar10 = lVar14 + 0x37;
  if (lVar14 < -0x37) {
    FUN_180009600((undefined1 (*) [64])(puVar2 + 1),0,lVar14 + 0x3f);
    auVar16 = pshufb(*(undefined1 (*) [16])*pauVar1,_DAT_1800146e0);
    auVar25 = pshufb(*(undefined1 (*) [16])(param_2[2] + 8),_DAT_1800146e0);
    auVar38 = pshufb(*(undefined1 (*) [16])(param_2[3] + 8),_DAT_1800146e0);
    auVar34 = pshufb(*(undefined1 (*) [16])(param_2[4] + 8),_DAT_1800146e0);
    auVar22._0_8_ = auVar16._0_8_;
    auVar22._8_4_ = auVar16._4_4_;
    auVar22._12_4_ = auVar25._4_4_;
    auVar21._4_4_ = auVar25._0_4_;
    auVar21._0_4_ = auVar16._0_4_;
    auVar17._0_8_ = CONCAT44(auVar25._8_4_,auVar16._8_4_);
    auVar17._8_4_ = auVar16._12_4_;
    auVar17._12_4_ = auVar25._12_4_;
    uVar37 = auVar34._8_4_;
    auVar39._0_8_ = CONCAT44(uVar37,auVar38._8_4_);
    auVar39._8_4_ = auVar38._12_4_;
    auVar39._12_4_ = auVar34._12_4_;
    auVar29._0_8_ = auVar38._0_8_;
    auVar29._8_4_ = auVar38._4_4_;
    auVar29._12_4_ = auVar34._4_4_;
    uVar13 = auVar29._8_8_;
    uVar33 = auVar34._0_4_;
    auVar32._0_8_ = CONCAT44(uVar33,auVar38._0_4_);
    uVar42 = auVar39._8_8_;
    auVar38._8_8_ = uVar42;
    auVar38._0_8_ = auVar17._8_8_;
    auVar21._8_8_ = auVar32._0_8_;
    auVar16._8_8_ = uVar13;
    auVar16._0_8_ = auVar22._8_8_;
    auVar44._8_8_ = auVar39._0_8_;
    auVar44._0_8_ = auVar17._0_8_;
    auVar22 = pmovzxbd((undefined1  [16])0x0,auVar38);
    auVar18._8_8_ = 0;
    auVar18._0_8_ = uVar42 >> 0x20;
    auVar23._0_4_ = auVar22._0_4_ << 8;
    auVar23._4_4_ = auVar22._4_4_ << 8;
    auVar23._8_4_ = auVar22._8_4_ << 8;
    auVar23._12_4_ = auVar22._12_4_ << 8;
    auVar22 = pmovzxbd(auVar18,auVar18);
    auVar25 = pmovzxbd((undefined1  [16])0x0,auVar44);
    auVar19._0_4_ = auVar22._0_4_ << 8;
    auVar19._4_4_ = auVar22._4_4_ << 8;
    auVar19._8_4_ = auVar22._8_4_ << 8;
    auVar19._12_4_ = auVar22._12_4_ << 8;
    auVar23 = auVar23 | auVar25;
    auVar22 = pmovzxbd(ZEXT416(uVar37),ZEXT416(uVar37));
    auVar26._8_8_ = 0;
    auVar26._0_8_ = uVar42;
    auVar19 = auVar19 | auVar22;
    auVar25 = pmovzxbd((undefined1  [16])0x0,auVar16);
    auVar22 = pmovzxbd(auVar26,auVar26);
    auVar43._0_4_ = auVar25._0_4_ << 8;
    auVar43._4_4_ = auVar25._4_4_ << 8;
    auVar43._8_4_ = auVar25._8_4_ << 8;
    auVar43._12_4_ = auVar25._12_4_ << 8;
    auVar40._8_8_ = 0;
    auVar40._0_8_ = auVar39._0_8_;
    auVar27._0_4_ = auVar22._0_4_ << 8;
    auVar27._4_4_ = auVar22._4_4_ << 8;
    auVar27._8_4_ = auVar22._8_4_ << 8;
    auVar27._12_4_ = auVar22._12_4_ << 8;
    auVar25 = pmovzxbd((undefined1  [16])0x0,auVar21);
    auVar24._0_4_ = auVar23._0_4_ << 0x10;
    auVar24._4_4_ = auVar23._4_4_ << 0x10;
    auVar24._8_4_ = auVar23._8_4_ << 0x10;
    auVar24._12_4_ = auVar23._12_4_ << 0x10;
    auVar22 = pmovzxbd(auVar40,auVar40);
    auVar27 = auVar27 | auVar22;
    auVar22 = pmovzxbd(auVar38 >> 0x20,auVar38 >> 0x20);
    auVar28._0_4_ = auVar27._0_4_ << 0x10;
    auVar28._4_4_ = auVar27._4_4_ << 0x10;
    auVar28._8_4_ = auVar27._8_4_ << 0x10;
    auVar28._12_4_ = auVar27._12_4_ << 0x10;
    auVar30._0_4_ = auVar22._0_4_ << 8;
    auVar30._4_4_ = auVar22._4_4_ << 8;
    auVar30._8_4_ = auVar22._8_4_ << 8;
    auVar30._12_4_ = auVar22._12_4_ << 8;
    auVar20._0_4_ = auVar19._0_4_ << 0x10;
    auVar20._4_4_ = auVar19._4_4_ << 0x10;
    auVar20._8_4_ = auVar19._8_4_ << 0x10;
    auVar20._12_4_ = auVar19._12_4_ << 0x10;
    *(undefined1 (*) [16])*pauVar1 = auVar24 | auVar43 | auVar25;
    auVar22 = pmovzxbd(auVar44 >> 0x20,auVar44 >> 0x20);
    auVar16 = pmovzxbd(auVar16 >> 0x20,auVar16 >> 0x20);
    auVar30 = auVar30 | auVar22;
    auVar41._0_4_ = auVar16._0_4_ << 8;
    auVar41._4_4_ = auVar16._4_4_ << 8;
    auVar41._8_4_ = auVar16._8_4_ << 8;
    auVar41._12_4_ = auVar16._12_4_ << 8;
    auVar22 = pmovzxbd(auVar21 >> 0x20,auVar21 >> 0x20);
    auVar31._0_4_ = auVar30._0_4_ << 0x10;
    auVar31._4_4_ = auVar30._4_4_ << 0x10;
    auVar31._8_4_ = auVar30._8_4_ << 0x10;
    auVar31._12_4_ = auVar30._12_4_ << 0x10;
    auVar35._8_8_ = 0;
    auVar35._0_8_ = uVar13;
    auVar25._8_8_ = 0;
    auVar25._0_8_ = uVar13 >> 0x20;
    *(undefined1 (*) [16])(param_2[2] + 8) = auVar31 | auVar41 | auVar22;
    auVar16 = pmovzxbd(auVar35,auVar35);
    auVar22 = pmovzxbd(auVar25,auVar25);
    auVar36._0_4_ = auVar16._0_4_ << 8;
    auVar36._4_4_ = auVar16._4_4_ << 8;
    auVar36._8_4_ = auVar16._8_4_ << 8;
    auVar36._12_4_ = auVar16._12_4_ << 8;
    auVar32._8_8_ = 0;
    auVar34._0_4_ = auVar22._0_4_ << 8;
    auVar34._4_4_ = auVar22._4_4_ << 8;
    auVar34._8_4_ = auVar22._8_4_ << 8;
    auVar34._12_4_ = auVar22._12_4_ << 8;
    auVar16 = pmovzxbd(auVar32,auVar32);
    auVar22 = pmovzxbd(ZEXT416(uVar33),ZEXT416(uVar33));
    *(undefined1 (*) [16])(param_2[3] + 8) = auVar28 | auVar36 | auVar16;
    *(undefined1 (*) [16])(param_2[4] + 8) = auVar20 | auVar34 | auVar22;
    FUN_1800074d0((int *)param_2,(int *)pauVar1);
    lVar10 = 0x38;
    pauVar11 = pauVar1;
  }
  else {
    pauVar11 = (undefined1 (*) [64])(puVar2 + 1);
  }
  FUN_180009600(pauVar11,0,lVar10 + 8);
  uVar8 = *(undefined4 *)(param_2[1] + 0xc);
  uVar7 = *(undefined2 *)(param_2[2] + 2);
  uVar3 = param_2[2][1];
  uVar9 = *(undefined4 *)(param_2[2] + 4);
  *(int *)*pauVar1 = *(int *)*pauVar1;
  uVar4 = param_2[2][0];
  uVar5 = param_2[2][0xb];
  *(undefined4 *)(param_2[1] + 0xc) = uVar8;
  *(undefined4 *)(param_2[2] + 4) = uVar9;
  uVar6 = param_2[2][0xf];
  *(uint *)(param_2[2] + 8) =
       CONCAT22(CONCAT11(uVar5,param_2[2][10]),*(undefined2 *)(param_2[2] + 8));
  *(uint *)(param_2[2] + 0xc) =
       CONCAT22(CONCAT11(uVar6,param_2[2][0xe]),*(undefined2 *)(param_2[2] + 0xc));
  *(undefined4 *)param_2[3] = *(undefined4 *)param_2[3];
  *(undefined4 *)(param_2[3] + 4) = *(undefined4 *)(param_2[3] + 4);
  *(undefined4 *)(param_2[3] + 8) = *(undefined4 *)(param_2[3] + 8);
  *(undefined4 *)(param_2[3] + 0xc) = *(undefined4 *)(param_2[3] + 0xc);
  *(undefined4 *)param_2[4] = *(undefined4 *)param_2[4];
  *(undefined4 *)(param_2[4] + 4) = *(undefined4 *)(param_2[4] + 4);
  *(undefined4 *)(param_2[4] + 8) = *(undefined4 *)(param_2[4] + 8);
  uVar8 = *(undefined4 *)(param_2[4] + 0xc);
  uVar33 = *(uint *)param_2[1];
  *(uint *)param_2[2] = CONCAT22(uVar7,CONCAT11(uVar3,uVar4));
  *(undefined4 *)(param_2[4] + 0xc) = uVar8;
  *(uint *)param_2[5] = uVar33 * 8;
  *(uint *)(param_2[5] + 4) = *(int *)(param_2[1] + 4) << 3 | uVar33 >> 0x1d;
  FUN_1800074d0((int *)param_2,(int *)pauVar1);
  uVar8 = *(undefined4 *)(*param_2 + 8);
  uVar9 = *(undefined4 *)*param_2;
  *(undefined4 *)(*param_2 + 8) = uVar8;
  uVar15 = CONCAT22(CONCAT11((*param_2)[7],(*param_2)[6]),*(undefined2 *)(*param_2 + 4));
  uVar12 = CONCAT22(CONCAT11((*param_2)[0xf],(*param_2)[0xe]),*(undefined2 *)(*param_2 + 0xc));
  *(undefined4 *)*param_2 = uVar9;
  *(undefined4 *)(*param_2 + 4) = uVar15;
  *(undefined4 *)(*param_2 + 0xc) = uVar12;
  *param_1 = CONCAT44(uVar15,uVar9);
  param_1[1] = CONCAT44(uVar12,uVar8);
  *param_2 = (undefined1  [16])0x0;
  param_2[1] = (undefined1  [16])0x0;
  param_2[2] = (undefined1  [16])0x0;
  param_2[3] = (undefined1  [16])0x0;
  param_2[4] = (undefined1  [16])0x0;
  *(undefined8 *)param_2[5] = 0;
  return;
}



void FUN_180005800(undefined8 *param_1,undefined1 (*param_2) [16])

{
  undefined1 (*pauVar1) [64];
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined8 uVar13;
  undefined1 (*pauVar14) [64];
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  
  pauVar1 = (undefined1 (*) [64])(param_2[1] + 8);
  uVar15 = (ulonglong)(*(uint *)param_2[1] & 0x3f);
  puVar2 = param_2[1] + uVar15 + 8;
  lVar16 = -uVar15;
  *puVar2 = 0x80;
  lVar17 = lVar16 + 0x37;
  if (lVar16 < -0x37) {
    FUN_180009600((undefined1 (*) [64])(puVar2 + 1),0,lVar16 + 0x3f);
    uVar7 = *(undefined4 *)(param_2[1] + 0xc);
    *(int *)*pauVar1 = *(int *)*pauVar1;
    *(undefined4 *)param_2[2] = *(undefined4 *)param_2[2];
    uVar3 = param_2[2][0xb];
    uVar4 = param_2[2][9];
    *(undefined4 *)(param_2[1] + 0xc) = uVar7;
    uVar10 = *(undefined2 *)(param_2[2] + 6);
    uVar5 = param_2[2][0xf];
    *(uint *)(param_2[2] + 8) =
         CONCAT22(CONCAT11(uVar3,param_2[2][10]),CONCAT11(uVar4,param_2[2][8]));
    uVar11 = *(undefined2 *)(param_2[2] + 4);
    uVar3 = param_2[3][3];
    *(uint *)(param_2[2] + 0xc) =
         CONCAT22(CONCAT11(uVar5,param_2[2][0xe]),*(undefined2 *)(param_2[2] + 0xc));
    uVar4 = param_2[3][7];
    *(uint *)param_2[3] = CONCAT22(CONCAT11(uVar3,param_2[3][2]),*(undefined2 *)param_2[3]);
    uVar3 = param_2[3][6];
    uVar12 = *(undefined2 *)(param_2[3] + 4);
    *(uint *)(param_2[2] + 4) = CONCAT22(uVar10,uVar11);
    uVar5 = param_2[3][0xb];
    *(uint *)(param_2[3] + 4) = CONCAT22(CONCAT11(uVar4,uVar3),uVar12);
    uVar3 = param_2[3][0xf];
    *(uint *)(param_2[3] + 8) =
         CONCAT22(CONCAT11(uVar5,param_2[3][10]),*(undefined2 *)(param_2[3] + 8));
    uVar4 = param_2[4][3];
    *(uint *)(param_2[3] + 0xc) =
         CONCAT22(CONCAT11(uVar3,param_2[3][0xe]),*(undefined2 *)(param_2[3] + 0xc));
    *(uint *)param_2[4] = CONCAT22(CONCAT11(uVar4,param_2[4][2]),*(undefined2 *)param_2[4]);
    *(undefined4 *)(param_2[4] + 4) = *(undefined4 *)(param_2[4] + 4);
    uVar3 = param_2[4][0xf];
    *(undefined4 *)(param_2[4] + 8) = *(undefined4 *)(param_2[4] + 8);
    uVar4 = param_2[5][3];
    *(uint *)(param_2[4] + 0xc) =
         CONCAT22(CONCAT11(uVar3,param_2[4][0xe]),*(undefined2 *)(param_2[4] + 0xc));
    uVar3 = param_2[5][7];
    *(uint *)param_2[5] = CONCAT22(CONCAT11(uVar4,param_2[5][2]),*(undefined2 *)param_2[5]);
    *(uint *)(param_2[5] + 4) =
         CONCAT22(CONCAT11(uVar3,param_2[5][6]),*(undefined2 *)(param_2[5] + 4));
    FUN_1800074d0((int *)param_2,(int *)pauVar1);
    lVar17 = 0x38;
    pauVar14 = pauVar1;
  }
  else {
    pauVar14 = (undefined1 (*) [64])(puVar2 + 1);
  }
  FUN_180009600(pauVar14,0,lVar17 + 8);
  *(int *)*pauVar1 = *(int *)*pauVar1;
  *(undefined4 *)(param_2[1] + 0xc) = *(undefined4 *)(param_2[1] + 0xc);
  *(undefined4 *)param_2[2] = *(undefined4 *)param_2[2];
  *(undefined4 *)(param_2[2] + 4) = *(undefined4 *)(param_2[2] + 4);
  *(undefined4 *)(param_2[2] + 8) = *(undefined4 *)(param_2[2] + 8);
  *(undefined4 *)(param_2[2] + 0xc) = *(undefined4 *)(param_2[2] + 0xc);
  *(undefined4 *)param_2[3] = *(undefined4 *)param_2[3];
  *(undefined4 *)(param_2[3] + 4) = *(undefined4 *)(param_2[3] + 4);
  *(undefined4 *)(param_2[3] + 8) = *(undefined4 *)(param_2[3] + 8);
  *(undefined4 *)(param_2[3] + 0xc) = *(undefined4 *)(param_2[3] + 0xc);
  *(undefined4 *)param_2[4] = *(undefined4 *)param_2[4];
  *(undefined4 *)(param_2[4] + 4) = *(undefined4 *)(param_2[4] + 4);
  *(undefined4 *)(param_2[4] + 8) = *(undefined4 *)(param_2[4] + 8);
  *(undefined4 *)(param_2[4] + 0xc) = *(undefined4 *)(param_2[4] + 0xc);
  iVar6 = *(int *)(param_2[1] + 4);
  *(uint *)param_2[5] = *(uint *)param_2[1] * 8;
  *(uint *)(param_2[5] + 4) = iVar6 << 3 | *(uint *)param_2[1] >> 0x1d;
  FUN_1800074d0((int *)param_2,(int *)pauVar1);
  uVar7 = *(undefined4 *)(*param_2 + 4);
  uVar8 = *(undefined4 *)(*param_2 + 8);
  uVar9 = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)*param_2 = *(undefined4 *)*param_2;
  *(undefined4 *)(*param_2 + 4) = uVar7;
  *(undefined4 *)(*param_2 + 8) = uVar8;
  *(undefined4 *)(*param_2 + 0xc) = uVar9;
  uVar13 = *(undefined8 *)(*param_2 + 8);
  *param_1 = *(undefined8 *)*param_2;
  param_1[1] = uVar13;
  *param_2 = (undefined1  [16])0x0;
  param_2[1] = (undefined1  [16])0x0;
  param_2[2] = (undefined1  [16])0x0;
  param_2[3] = (undefined1  [16])0x0;
  param_2[4] = (undefined1  [16])0x0;
  *(undefined8 *)param_2[5] = 0;
  return;
}



// WARNING: Function: _alloca_probe replaced with injection: alloca_probe

void FUN_180005f90(undefined1 (*param_1) [16],char *param_2)

{
  undefined1 auVar1 [16];
  undefined4 uVar2;
  int _FileHandle;
  uint uVar3;
  longlong lVar4;
  undefined1 (*pauVar5) [64];
  ulonglong uVar6;
  uint uVar7;
  longlong lVar8;
  int iVar9;
  undefined1 local_4268 [16384];
  undefined1 local_228 [16];
  undefined1 local_218 [16];
  undefined1 auStack_208 [16];
  undefined1 auStack_1f8 [16];
  undefined1 auStack_1e8 [16];
  undefined8 uStack_1d8;
  uint auStack_1d0 [2];
  uint uStack_1c8;
  uint uStack_1c0;
  uint uStack_1b8;
  uint uStack_1b0;
  uint uStack_1a8;
  uint uStack_1a0;
  uint uStack_198;
  uint uStack_190;
  uint uStack_188;
  uint uStack_180;
  uint uStack_178;
  uint uStack_170;
  uint uStack_168;
  uint uStack_160;
  uint uStack_158;
  uint uStack_150;
  uint uStack_148;
  uint uStack_140;
  uint uStack_138;
  uint uStack_130;
  uint uStack_128;
  uint uStack_120;
  uint uStack_118;
  uint uStack_110;
  uint uStack_108;
  uint uStack_100;
  uint uStack_f8;
  uint uStack_f0;
  int iStack_e8;
  uint uStack_e0;
  uint uStack_d8;
  uint uStack_d0;
  uint uStack_c8;
  uint uStack_c0;
  uint uStack_b8;
  uint uStack_b0;
  uint uStack_a8;
  uint uStack_a0;
  uint uStack_98;
  uint uStack_90;
  uint uStack_88;
  uint uStack_80;
  uint uStack_78;
  uint uStack_70;
  undefined1 (*pauStack_68) [64];
  uint uStack_60;
  uint uStack_58;
  uint uStack_50;
  uint uStack_48;
  uint uStack_40;
  uint uStack_38;
  uint uStack_30;
  uint uStack_28;
  uint uStack_20;
  undefined8 uStack_18;
  
  uStack_18 = 0x180005f9d;
  _FileHandle = _open(param_2,0x8000);
  if (_FileHandle == -1) {
    *param_1 = (undefined1  [16])0x0;
    return;
  }
  local_228._8_4_ = 0x98badcfe;
  local_228._0_8_ = 0xefcdab8967452301;
  local_228._12_4_ = 0x10325476;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = local_218._8_8_;
  local_218 = auVar1 << 0x40;
  uVar3 = _read(_FileHandle,local_4268,0x4000);
  auVar1 = local_218;
  while( true ) {
    local_218._0_4_ = auVar1._0_4_;
    uVar2 = local_218._0_4_;
    if ((int)uVar3 < 1) break;
    local_218._0_4_ = uVar3 + local_218._0_4_;
    local_218._4_12_ = auVar1._4_12_;
    if ((uint)local_218._0_4_ < (uint)uVar2) {
      local_218._4_4_ = auVar1._4_4_;
      local_218._8_8_ = auVar1._8_8_;
      local_218._4_4_ = local_218._4_4_ + 1;
    }
    uVar7 = 0x40 - ((byte)auVar1[0] & 0x3f);
    uVar6 = (ulonglong)uVar7;
    if (uVar3 < uVar7) {
      FUN_180009540((undefined1 (*) [64])((longlong)auStack_1d0 - uVar6),
                    (undefined1 (*) [64])local_4268,(longlong)(int)uVar3);
    }
    else {
      FUN_180009540((undefined1 (*) [64])((longlong)auStack_1d0 - uVar6),
                    (undefined1 (*) [64])local_4268,uVar6);
      FUN_1800074d0((int *)local_228,(int *)(local_218 + 8));
      iVar9 = uVar3 - uVar7;
      pauVar5 = (undefined1 (*) [64])(local_4268 + uVar6);
      if (0x3f < iVar9) {
        auStack_1d0[0] = -(int)(((ulonglong)(-(longlong)iVar9 >> 5) >> 0x3a) - (longlong)iVar9 >> 6)
        ;
        uStack_e0 = 0;
        iStack_e8 = iVar9;
        pauStack_68 = pauVar5;
        do {
          uStack_20 = (uint)(byte)(*pauStack_68)[3];
          uStack_1c8 = (uint)(byte)(*pauStack_68)[2];
          uStack_a8 = (uint)(byte)(*pauStack_68)[1];
          uStack_1b8 = (uint)(byte)(*pauStack_68)[6];
          uStack_88 = (uint)(byte)(*pauStack_68)[5];
          uStack_1b0 = (uint)(byte)(*pauStack_68)[4];
          uStack_198 = (uint)(byte)(*pauStack_68)[10];
          uStack_1c0 = (uint)(byte)(*pauStack_68)[0];
          uStack_48 = (uint)(byte)(*pauStack_68)[9];
          uStack_190 = (uint)(byte)(*(undefined1 (*) [16])(*pauStack_68 + 8))[0];
          uStack_178 = (uint)(byte)(*pauStack_68)[0xe];
          uStack_40 = (uint)(byte)(*pauStack_68)[0xd];
          uStack_170 = (uint)(byte)(*pauStack_68)[0xc];
          uStack_158 = (uint)(byte)(*pauStack_68)[0x12];
          uStack_58 = (uint)(byte)(*pauStack_68)[0x11];
          uStack_150 = (uint)(byte)(*pauStack_68)[0x10];
          uStack_138 = (uint)(byte)(*pauStack_68)[0x16];
          uStack_70 = (uint)(byte)(*pauStack_68)[0x15];
          auStack_208 = *(undefined1 (*) [16])(*pauStack_68 + 8);
          uStack_130 = (uint)(byte)(*pauStack_68)[0x14];
          uStack_118 = (uint)(byte)(*pauStack_68)[0x1a];
          uStack_90 = (uint)(byte)(*pauStack_68)[0x19];
          uStack_110 = (uint)(byte)(*(undefined1 (*) [16])(*pauStack_68 + 0x18))[0];
          uStack_f8 = (uint)(byte)(*pauStack_68)[0x1e];
          uStack_b0 = (uint)(byte)(*pauStack_68)[0x1d];
          uStack_f0 = (uint)(byte)(*pauStack_68)[0x1c];
          uStack_30 = (uint)(byte)(*pauStack_68)[0x23];
          uStack_c0 = (uint)(byte)(*pauStack_68)[0x22];
          auStack_1f8 = *(undefined1 (*) [16])(*pauStack_68 + 0x18);
          uStack_b8 = (uint)(byte)(*pauStack_68)[0x21];
          uStack_c8 = (uint)(byte)(*pauStack_68)[0x20];
          uStack_28 = (uint)(byte)(*pauStack_68)[0x27];
          uStack_d8 = (uint)(byte)(*pauStack_68)[0x26];
          uStack_a0 = (uint)(byte)(*pauStack_68)[0x25];
          uStack_d0 = (uint)(byte)(*pauStack_68)[0x24];
          uStack_100 = (uint)(byte)(*pauStack_68)[0x2a];
          uStack_60 = (uint)(byte)(*pauStack_68)[0x2d];
          uStack_120 = (uint)(byte)(*pauStack_68)[0x2e];
          uStack_160 = (uint)(byte)(*pauStack_68)[0x36];
          uStack_108 = (uint)(byte)(*(undefined1 (*) [16])(*pauStack_68 + 0x28))[0];
          uStack_148 = (uint)(byte)(*pauStack_68)[0x30];
          uStack_180 = (uint)(byte)(*pauStack_68)[0x3a];
          uStack_80 = (uint)(byte)(*pauStack_68)[0x29];
          uStack_50 = (uint)(byte)(*pauStack_68)[0x31];
          uStack_168 = (uint)(byte)(*pauStack_68)[0x34];
          uStack_188 = (uint)(byte)(*pauStack_68)[0x38];
          uStack_128 = (uint)(byte)(*pauStack_68)[0x2c];
          uStack_140 = (uint)(byte)(*pauStack_68)[0x32];
          uStack_38 = (uint)(byte)(*pauStack_68)[0x35];
          uStack_78 = (uint)(byte)(*pauStack_68)[0x39];
          uStack_1a0 = (uint)(byte)(*pauStack_68)[0x3e];
          auStack_1e8 = *(undefined1 (*) [16])(*pauStack_68 + 0x28);
          uStack_1d8 = *(undefined8 *)(*pauStack_68 + 0x38);
          uStack_98 = (uint)(byte)(*pauStack_68)[0x3d];
          uStack_1a8 = (uint)(byte)(*pauStack_68)[0x3c];
          local_218._8_4_ = *(undefined4 *)*pauStack_68;
          local_218._12_4_ = *(undefined4 *)(*pauStack_68 + 4);
          FUN_1800074d0((int *)local_228,(int *)(local_218 + 8));
          uStack_e0 = uStack_e0 + 1;
          iVar9 = iStack_e8 + -0x40;
          pauVar5 = pauStack_68 + 1;
          iStack_e8 = iVar9;
          pauStack_68 = pauVar5;
        } while (uStack_e0 < auStack_1d0[0]);
      }
      FUN_180009540((undefined1 (*) [64])(local_218 + 8),pauVar5,(longlong)iVar9);
    }
    uVar3 = _read(_FileHandle,local_4268,0x4000);
    auVar1 = local_218;
  }
  uVar6 = (ulonglong)((byte)auVar1[0] & 0x3f);
  lVar8 = -uVar6;
  local_218[uVar6 + 8] = 0x80;
  pauVar5 = (undefined1 (*) [64])(local_218 + uVar6 + 9);
  lVar4 = lVar8 + 0x37;
  local_218 = auVar1;
  if (lVar8 < -0x37) {
    FUN_180009600(pauVar5,0,lVar8 + 0x3f);
    FUN_1800074d0((int *)local_228,(int *)(local_218 + 8));
    lVar4 = 0x38;
    pauVar5 = (undefined1 (*) [64])(local_218 + 8);
  }
  FUN_180009600(pauVar5,0,lVar4 + 8);
  uStack_1d8 = CONCAT44(local_218._4_4_ << 3 | (uint)local_218._0_4_ >> 0x1d,local_218._0_4_ * 8);
  FUN_1800074d0((int *)local_228,(int *)(local_218 + 8));
  *(undefined8 *)*param_1 = local_228._0_8_;
  *(longlong *)(*param_1 + 8) = local_228._8_8_;
  local_228 = (undefined1  [16])0x0;
  local_218 = (undefined1  [16])0x0;
  auStack_208 = (undefined1  [16])0x0;
  auStack_1f8 = (undefined1  [16])0x0;
  auStack_1e8 = (undefined1  [16])0x0;
  uStack_1d8 = 0;
  _close(_FileHandle);
  return;
}



void FUN_180006027(void)

{
  uint in_EAX;
  undefined1 (*pauVar1) [64];
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int unaff_EBP;
  longlong lVar5;
  int iVar6;
  undefined8 *unaff_R15;
  undefined1 local_res20 [8];
  undefined1 in_stack_00004060 [16];
  uint uVar7;
  undefined1 in_stack_00004070 [16];
  undefined1 auVar8 [16];
  
  do {
    uVar7 = in_stack_00004070._0_4_;
    uVar2 = in_EAX + uVar7;
    auVar8._4_12_ = in_stack_00004070._4_12_;
    auVar8._0_4_ = uVar2;
    if (uVar2 < uVar7) {
      auVar8._8_8_ = in_stack_00004070._8_8_;
      auVar8._4_4_ = in_stack_00004070._4_4_ + 1;
    }
    in_stack_00004070 = auVar8;
    uVar2 = 0x40 - (uVar7 & 0x3f);
    uVar3 = (ulonglong)uVar2;
    if (in_EAX < uVar2) {
      FUN_180009540((undefined1 (*) [64])((longlong)register0x00000020 + (0x40b8 - uVar3)),
                    (undefined1 (*) [64])local_res20,(longlong)(int)in_EAX);
    }
    else {
      FUN_180009540((undefined1 (*) [64])((longlong)register0x00000020 + (0x40b8 - uVar3)),
                    (undefined1 (*) [64])local_res20,uVar3);
      FUN_1800074d0((int *)((longlong)register0x00000020 + 0x4060),
                    (int *)((longlong)register0x00000020 + 0x4078));
      iVar6 = in_EAX - uVar2;
      pauVar1 = (undefined1 (*) [64])(local_res20 + uVar3);
      lVar4 = (longlong)iVar6;
      if (0x3f < iVar6) {
        uVar2 = 0;
        do {
          in_stack_00004070._8_4_ = *(undefined4 *)*pauVar1;
          in_stack_00004070._12_4_ = *(undefined4 *)(*pauVar1 + 4);
          FUN_1800074d0((int *)((longlong)register0x00000020 + 0x4060),
                        (int *)((longlong)register0x00000020 + 0x4078));
          uVar2 = uVar2 + 1;
          iVar6 = iVar6 + -0x40;
          pauVar1 = pauVar1 + 1;
        } while (uVar2 < (uint)-(int)(((ulonglong)(-lVar4 >> 5) >> 0x3a) - lVar4 >> 6));
      }
      FUN_180009540((undefined1 (*) [64])((longlong)register0x00000020 + 0x4078),pauVar1,
                    (longlong)iVar6);
    }
    in_EAX = _read(unaff_EBP,local_res20,0x4000);
  } while (0 < (int)in_EAX);
  uVar3 = (ulonglong)(in_stack_00004070._0_4_ & 0x3f);
  lVar5 = -uVar3;
  *(undefined1 *)((longlong)register0x00000020 + uVar3 + 0x4078) = 0x80;
  pauVar1 = (undefined1 (*) [64])((longlong)register0x00000020 + uVar3 + 0x4079);
  lVar4 = lVar5 + 0x37;
  if (lVar5 < -0x37) {
    FUN_180009600(pauVar1,0,lVar5 + 0x3f);
    FUN_1800074d0((int *)((longlong)register0x00000020 + 0x4060),
                  (int *)((longlong)register0x00000020 + 0x4078));
    lVar4 = 0x38;
    pauVar1 = (undefined1 (*) [64])((longlong)register0x00000020 + 0x4078);
  }
  FUN_180009600(pauVar1,0,lVar4 + 8);
  FUN_1800074d0((int *)((longlong)register0x00000020 + 0x4060),
                (int *)((longlong)register0x00000020 + 0x4078));
  *unaff_R15 = in_stack_00004060._0_8_;
  unaff_R15[1] = in_stack_00004060._8_8_;
  _close(unaff_EBP);
  return;
}



void FUN_180006ba9(void)

{
  longlong lVar1;
  undefined1 (*pauVar2) [64];
  int unaff_EBP;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 *unaff_R15;
  int aiStackX_8 [8];
  undefined1 in_stack_00004060 [16];
  uint in_stack_00004070;
  
  uVar3 = (ulonglong)(in_stack_00004070 & 0x3f);
  lVar4 = -uVar3;
  *(undefined1 *)((longlong)register0x00000020 + uVar3 + 0x4078) = 0x80;
  pauVar2 = (undefined1 (*) [64])((longlong)register0x00000020 + uVar3 + 0x4079);
  lVar1 = lVar4 + 0x37;
  if (lVar4 < -0x37) {
    FUN_180009600(pauVar2,0,lVar4 + 0x3f);
    FUN_1800074d0((int *)((longlong)register0x00000020 + 0x4060),
                  (int *)((longlong)register0x00000020 + 0x4078));
    lVar1 = 0x38;
    pauVar2 = (undefined1 (*) [64])((longlong)register0x00000020 + 0x4078);
  }
  FUN_180009600(pauVar2,0,lVar1 + 8);
  FUN_1800074d0((int *)((longlong)register0x00000020 + 0x4060),
                (int *)((longlong)register0x00000020 + 0x4078));
  *unaff_R15 = in_stack_00004060._0_8_;
  unaff_R15[1] = in_stack_00004060._8_8_;
  _close(unaff_EBP);
  return;
}



void FUN_1800074d0(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
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
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[1];
  iVar5 = *param_2;
  iVar6 = param_2[2];
  iVar7 = param_2[3];
  uVar1 = ((uVar2 ^ uVar3) & uVar4 ^ uVar3) + *param_1 + -0x28955b88 + iVar5;
  uVar23 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar4;
  iVar8 = param_2[1];
  iVar9 = param_2[4];
  uVar1 = ((uVar2 ^ uVar4) & uVar23 ^ uVar2) + uVar3 + -0x173848aa + iVar8;
  uVar25 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar23;
  iVar10 = param_2[7];
  uVar1 = ((uVar4 ^ uVar23) & uVar25 ^ uVar4) + uVar2 + 0x242070db + iVar6;
  uVar24 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar25;
  uVar1 = ((uVar23 ^ uVar25) & uVar24 ^ uVar23) + uVar4 + -0x3e423112 + iVar7;
  uVar21 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar24;
  uVar1 = uVar23 + ((uVar25 ^ uVar24) & uVar21 ^ uVar25) + -0xa83f051 + iVar9;
  iVar11 = param_2[5];
  uVar23 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar21;
  iVar12 = param_2[9];
  uVar1 = uVar25 + ((uVar24 ^ uVar21) & uVar23 ^ uVar24) + 0x4787c62a + iVar11;
  iVar13 = param_2[6];
  uVar25 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar23;
  uVar1 = uVar24 + ((uVar21 ^ uVar23) & uVar25 ^ uVar21) + -0x57cfb9ed + iVar13;
  uVar24 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar25;
  iVar14 = param_2[8];
  uVar1 = uVar21 + ((uVar23 ^ uVar25) & uVar24 ^ uVar23) + -0x2b96aff + iVar10;
  uVar22 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar24;
  uVar1 = uVar23 + ((uVar25 ^ uVar24) & uVar22 ^ uVar25) + 0x698098d8 + iVar14;
  uVar23 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar22;
  iVar15 = param_2[10];
  uVar1 = uVar25 + ((uVar24 ^ uVar22) & uVar23 ^ uVar24) + -0x74bb0851 + iVar12;
  uVar21 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar23;
  iVar16 = param_2[0xb];
  uVar1 = uVar24 + ((uVar22 ^ uVar23) & uVar21 ^ uVar22) + -0xa44f + iVar15;
  uVar25 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar21;
  iVar17 = param_2[0xc];
  uVar1 = uVar22 + ((uVar23 ^ uVar21) & uVar25 ^ uVar23) + -0x76a32842 + iVar16;
  uVar24 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar25;
  iVar18 = param_2[0xd];
  uVar1 = uVar23 + ((uVar21 ^ uVar25) & uVar24 ^ uVar21) + 0x6b901122 + iVar17;
  uVar23 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar24;
  uVar1 = uVar21 + ((uVar25 ^ uVar24) & uVar23 ^ uVar25) + -0x2678e6d + iVar18;
  uVar22 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar23;
  iVar19 = param_2[0xe];
  iVar20 = param_2[0xf];
  uVar1 = uVar25 + ((uVar24 ^ uVar23) & uVar22 ^ uVar24) + -0x5986bc72 + iVar19;
  uVar25 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar22;
  uVar1 = uVar24 + ((uVar23 ^ uVar22) & uVar25 ^ uVar23) + 0x49b40821 + iVar20;
  uVar21 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar25;
  uVar1 = uVar23 + ((uVar21 ^ uVar25) & uVar22 ^ uVar25) + -0x9e1da9e + iVar8;
  uVar23 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar21;
  uVar1 = uVar22 + ((uVar21 ^ uVar23) & uVar25 ^ uVar21) + -0x3fbf4cc0 + iVar13;
  uVar22 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar23;
  uVar1 = uVar25 + ((uVar23 ^ uVar22) & uVar21 ^ uVar23) + 0x265e5a51 + iVar16;
  uVar24 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar22;
  uVar1 = uVar21 + ((uVar22 ^ uVar24) & uVar23 ^ uVar22) + -0x16493856 + iVar5;
  uVar21 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar24;
  uVar1 = uVar23 + ((uVar24 ^ uVar21) & uVar22 ^ uVar24) + -0x29d0efa3 + iVar11;
  uVar23 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar21;
  uVar1 = uVar22 + ((uVar21 ^ uVar23) & uVar24 ^ uVar21) + 0x2441453 + iVar15;
  uVar22 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar23;
  uVar1 = uVar24 + ((uVar23 ^ uVar22) & uVar21 ^ uVar23) + -0x275e197f + iVar20;
  uVar24 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar22;
  uVar1 = uVar21 + ((uVar22 ^ uVar24) & uVar23 ^ uVar22) + -0x182c0438 + iVar9;
  uVar21 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar24;
  uVar1 = uVar23 + ((uVar24 ^ uVar21) & uVar22 ^ uVar24) + 0x21e1cde6 + iVar12;
  uVar25 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar21;
  uVar1 = uVar22 + ((uVar21 ^ uVar25) & uVar24 ^ uVar21) + -0x3cc8f82a + iVar19;
  uVar23 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar25;
  uVar1 = uVar24 + ((uVar25 ^ uVar23) & uVar21 ^ uVar25) + -0xb2af279 + iVar7;
  uVar24 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar23;
  uVar1 = uVar21 + ((uVar23 ^ uVar24) & uVar25 ^ uVar23) + 0x455a14ed + iVar14;
  uVar21 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar24;
  uVar1 = uVar25 + ((uVar24 ^ uVar21) & uVar23 ^ uVar24) + -0x561c16fb + iVar18;
  uVar25 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar21;
  uVar1 = uVar23 + ((uVar21 ^ uVar25) & uVar24 ^ uVar21) + -0x3105c08 + iVar6;
  uVar23 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar25;
  uVar1 = uVar24 + ((uVar25 ^ uVar23) & uVar21 ^ uVar25) + 0x676f02d9 + iVar10;
  uVar24 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar23;
  uVar1 = uVar21 + ((uVar23 ^ uVar24) & uVar25 ^ uVar23) + -0x72d5b376 + iVar17;
  uVar21 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar24;
  uVar1 = uVar25 + (uVar24 ^ uVar21 ^ uVar23) + -0x5c6be + iVar11;
  uVar25 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar21;
  uVar1 = uVar23 + (uVar21 ^ uVar25 ^ uVar24) + -0x788e097f + iVar14;
  uVar22 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar25;
  uVar1 = uVar24 + (uVar25 ^ uVar22 ^ uVar21) + 0x6d9d6122 + iVar16;
  uVar23 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar22;
  uVar1 = uVar21 + (uVar22 ^ uVar23 ^ uVar25) + -0x21ac7f4 + iVar19;
  uVar24 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar23;
  uVar1 = uVar25 + (uVar23 ^ uVar24 ^ uVar22) + -0x5b4115bc + iVar8;
  uVar21 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar24;
  uVar1 = uVar22 + (uVar24 ^ uVar21 ^ uVar23) + 0x4bdecfa9 + iVar9;
  uVar25 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar21;
  uVar1 = uVar23 + (uVar21 ^ uVar25 ^ uVar24) + -0x944b4a0 + iVar10;
  uVar23 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar25;
  uVar1 = uVar24 + (uVar25 ^ uVar23 ^ uVar21) + -0x41404390 + iVar15;
  uVar24 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar23;
  uVar1 = uVar21 + (uVar23 ^ uVar24 ^ uVar25) + 0x289b7ec6 + iVar18;
  uVar21 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar24;
  uVar1 = uVar25 + (uVar24 ^ uVar21 ^ uVar23) + -0x155ed806 + iVar5;
  uVar25 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar21;
  uVar1 = uVar23 + (uVar21 ^ uVar25 ^ uVar24) + -0x2b10cf7b + iVar7;
  uVar23 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar25;
  uVar1 = uVar24 + (uVar25 ^ uVar23 ^ uVar21) + 0x4881d05 + iVar13;
  uVar24 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar23;
  uVar1 = uVar21 + (uVar23 ^ uVar24 ^ uVar25) + -0x262b2fc7 + iVar12;
  uVar26 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar24;
  uVar1 = uVar25 + (uVar24 ^ uVar26 ^ uVar23) + -0x1924661b + iVar17;
  uVar22 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar26;
  uVar1 = uVar23 + (uVar26 ^ uVar22 ^ uVar24) + 0x1fa27cf8 + iVar20;
  uVar21 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar22;
  uVar1 = uVar24 + (uVar22 ^ uVar21 ^ uVar26) + -0x3b53a99b + iVar6;
  uVar23 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar21;
  uVar1 = uVar26 + ((~uVar22 | uVar23) ^ uVar21) + -0xbd6ddbc + iVar5;
  uVar25 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar23;
  uVar1 = uVar22 + ((~uVar21 | uVar25) ^ uVar23) + 0x432aff97 + iVar10;
  uVar24 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar25;
  uVar1 = uVar21 + ((~uVar23 | uVar24) ^ uVar25) + -0x546bdc59 + iVar19;
  uVar21 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar24;
  uVar1 = uVar23 + ((~uVar25 | uVar21) ^ uVar24) + -0x36c5fc7 + iVar11;
  uVar23 = (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar21;
  uVar1 = uVar25 + ((~uVar24 | uVar23) ^ uVar21) + 0x655b59c3 + iVar17;
  uVar25 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar23;
  uVar1 = uVar24 + ((~uVar21 | uVar25) ^ uVar23) + -0x70f3336e + iVar7;
  uVar24 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar25;
  uVar1 = uVar21 + ((~uVar23 | uVar24) ^ uVar25) + -0x100b83 + iVar15;
  uVar21 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar24;
  uVar1 = uVar23 + ((~uVar25 | uVar21) ^ uVar24) + -0x7a7ba22f + iVar8;
  uVar23 = (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar21;
  uVar1 = uVar25 + ((~uVar24 | uVar23) ^ uVar21) + 0x6fa87e4f + iVar14;
  uVar25 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar23;
  uVar1 = uVar24 + ((~uVar21 | uVar25) ^ uVar23) + -0x1d31920 + iVar20;
  uVar24 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar25;
  uVar1 = uVar21 + ((~uVar23 | uVar24) ^ uVar25) + -0x5cfebcec + iVar13;
  uVar21 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar24;
  uVar1 = uVar23 + ((~uVar25 | uVar21) ^ uVar24) + 0x4e0811a1 + iVar18;
  uVar22 = (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar21;
  uVar1 = uVar25 + ((~uVar24 | uVar22) ^ uVar21) + -0x8ac817e + iVar9;
  uVar25 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar22;
  *param_1 = *param_1 + uVar25;
  uVar1 = iVar16 + uVar24 + -0x42c50dcb + ((~uVar21 | uVar25) ^ uVar22);
  uVar24 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar25;
  uVar1 = iVar6 + uVar21 + 0x2ad7d2bb + ((~uVar22 | uVar24) ^ uVar25);
  uVar23 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar24;
  param_1[3] = uVar24 + uVar3;
  uVar1 = iVar12 + uVar22 + -0x14792c6f + ((~uVar25 | uVar23) ^ uVar24);
  param_1[1] = uVar4 + (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar23;
  param_1[2] = uVar23 + uVar2;
  return;
}



void FUN_180007cc0(undefined8 *param_1)

{
  ulonglong uVar1;
  
  uVar1 = 0x64199d97ff;
  while( true ) {
    if ((uVar1 & CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408)) == uVar1) {
      *param_1 = 0xefcdab8967452301;
      param_1[1] = 0x1032547698badcfe;
      *(undefined4 *)(param_1 + 2) = 0;
      *(undefined4 *)((longlong)param_1 + 0x14) = 0;
      return;
    }
    if ((CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408) & 0x7189d97ff) == 0x7189d97ff) {
      *param_1 = 0xefcdab8967452301;
      param_1[1] = 0x1032547698badcfe;
      *(undefined4 *)(param_1 + 2) = 0;
      *(undefined4 *)((longlong)param_1 + 0x14) = 0;
      return;
    }
    if (((uint)DAT_180019408 & 0x9d97ff) == 0x9d97ff) {
      *param_1 = 0xefcdab8967452301;
      param_1[1] = 0x1032547698badcfe;
      *(undefined4 *)(param_1 + 2) = 0;
      *(undefined4 *)((longlong)param_1 + 0x14) = 0;
      return;
    }
    if (((uint)DAT_180019408 & 0x17ff) == 0x17ff) break;
    if (((uint)DAT_180019408 & 1) != 0) {
      *param_1 = 0xefcdab8967452301;
      param_1[1] = 0x1032547698badcfe;
      *(undefined4 *)(param_1 + 2) = 0;
      *(undefined4 *)((longlong)param_1 + 0x14) = 0;
      return;
    }
    FUN_180008f60();
  }
  *param_1 = 0xefcdab8967452301;
  param_1[1] = 0x1032547698badcfe;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
  return;
}



undefined1 (*) [64] FUN_180007e00(undefined1 (*param_1) [64],char *param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  char *pcVar5;
  sbyte sVar6;
  longlong lVar7;
  longlong lVar8;
  byte bVar9;
  uint uVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  
  FUN_180007f70(param_2,param_1);
  if (*param_2 != '\0') {
    uVar4 = (uint)param_2;
    pcVar5 = (char *)((ulonglong)param_2 & 0xfffffffffffffff0);
    auVar13[0] = -(*pcVar5 == '\0');
    auVar13[1] = -(pcVar5[1] == '\0');
    auVar13[2] = -(pcVar5[2] == '\0');
    auVar13[3] = -(pcVar5[3] == '\0');
    auVar13[4] = -(pcVar5[4] == '\0');
    auVar13[5] = -(pcVar5[5] == '\0');
    auVar13[6] = -(pcVar5[6] == '\0');
    auVar13[7] = -(pcVar5[7] == '\0');
    auVar13[8] = -(pcVar5[8] == '\0');
    auVar13[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar5[9]);
    auVar13[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar5[10]);
    auVar13[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar5[0xb]);
    auVar13[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar5[0xc]);
    auVar13[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar5[0xd]);
    auVar13[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar5[0xe]);
    auVar13[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar5[0xf]);
    auVar11[0] = -(*pcVar5 == '=');
    auVar11[1] = -(pcVar5[1] == '=');
    auVar11[2] = -(pcVar5[2] == '=');
    auVar11[3] = -(pcVar5[3] == '=');
    auVar11[4] = -(pcVar5[4] == '=');
    auVar11[5] = -(pcVar5[5] == '=');
    auVar11[6] = -(pcVar5[6] == '=');
    auVar11[7] = -(pcVar5[7] == '=');
    auVar11[8] = -(pcVar5[8] == '=');
    auVar11[9] = -(pcVar5[9] == '=');
    auVar11[10] = -(pcVar5[10] == '=');
    auVar11[0xb] = -(pcVar5[0xb] == '=');
    auVar11[0xc] = -(pcVar5[0xc] == '=');
    auVar11[0xd] = -(pcVar5[0xd] == '=');
    auVar11[0xe] = -(pcVar5[0xe] == '=');
    auVar11[0xf] = -(pcVar5[0xf] == '=');
    sVar6 = (sbyte)(uVar4 & 0xf);
    uVar2 = (ushort)((ushort)(SUB161(auVar11 >> 7,0) & 1) |
                     (ushort)(SUB161(auVar11 >> 0xf,0) & 1) << 1 |
                     (ushort)(SUB161(auVar11 >> 0x17,0) & 1) << 2 |
                     (ushort)(SUB161(auVar11 >> 0x1f,0) & 1) << 3 |
                     (ushort)(SUB161(auVar11 >> 0x27,0) & 1) << 4 |
                     (ushort)(SUB161(auVar11 >> 0x2f,0) & 1) << 5 |
                     (ushort)(SUB161(auVar11 >> 0x37,0) & 1) << 6 |
                     (ushort)(SUB161(auVar11 >> 0x3f,0) & 1) << 7 |
                     (ushort)(SUB161(auVar11 >> 0x47,0) & 1) << 8 |
                     (ushort)(SUB161(auVar11 >> 0x4f,0) & 1) << 9 |
                     (ushort)(SUB161(auVar11 >> 0x57,0) & 1) << 10 |
                     (ushort)(SUB161(auVar11 >> 0x5f,0) & 1) << 0xb |
                     (ushort)(SUB161(auVar11 >> 0x67,0) & 1) << 0xc |
                     (ushort)(SUB161(auVar11 >> 0x6f,0) & 1) << 0xd |
                     (ushort)(SUB161(auVar11 >> 0x77,0) & 1) << 0xe |
                    (ushort)(auVar11[0xf] >> 7) << 0xf) >> sVar6;
    uVar3 = (ushort)((ushort)(SUB161(auVar13 >> 7,0) & 1) |
                     (ushort)(SUB161(auVar13 >> 0xf,0) & 1) << 1 |
                     (ushort)(SUB161(auVar13 >> 0x17,0) & 1) << 2 |
                     (ushort)(SUB161(auVar13 >> 0x1f,0) & 1) << 3 |
                     (ushort)(SUB161(auVar13 >> 0x27,0) & 1) << 4 |
                     (ushort)(SUB161(auVar13 >> 0x2f,0) & 1) << 5 |
                     (ushort)(SUB161(auVar13 >> 0x37,0) & 1) << 6 |
                     (ushort)(SUB161(auVar13 >> 0x3f,0) & 1) << 7 |
                     (ushort)(SUB161(auVar13 >> 0x47,0) & 1) << 8 |
                     (ushort)(SUB161(auVar13 >> 0x4f,0) & 1) << 9 |
                     (ushort)(SUB161(auVar13 >> 0x57,0) & 1) << 10 |
                     (ushort)(SUB161(auVar13 >> 0x5f,0) & 1) << 0xb |
                     (ushort)(SUB161(auVar13 >> 0x67,0) & 1) << 0xc |
                     (ushort)(SUB161(auVar13 >> 0x6f,0) & 1) << 0xd |
                     (ushort)(SUB161(auVar13 >> 0x77,0) & 1) << 0xe |
                    (ushort)(auVar13[0xf] >> 7) << 0xf) >> sVar6;
    if (uVar2 == 0) {
      if (uVar3 != 0) goto LAB_180007e88;
      pcVar5 = FUN_180009680();
    }
    else {
      uVar10 = 0;
      if (uVar2 != 0) {
        for (; (uVar2 >> uVar10 & 1) == 0; uVar10 = uVar10 + 1) {
        }
      }
      iVar1 = 0;
      if (uVar3 != 0) {
        for (; (uVar3 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
        }
      }
      if ((uVar3 == 0) || ((int)uVar10 <= iVar1)) {
        pcVar5 = pcVar5 + (ulonglong)uVar10 + (ulonglong)(uVar4 & 0xf);
      }
      else {
LAB_180007e88:
        pcVar5 = (char *)0x0;
      }
    }
    if (pcVar5 == (char *)0x0) {
      pcVar5 = (char *)((ulonglong)param_2 & 0xfffffffffffffff0);
      auVar12[0] = -(*pcVar5 == '\0');
      auVar12[1] = -(pcVar5[1] == '\0');
      auVar12[2] = -(pcVar5[2] == '\0');
      auVar12[3] = -(pcVar5[3] == '\0');
      auVar12[4] = -(pcVar5[4] == '\0');
      auVar12[5] = -(pcVar5[5] == '\0');
      auVar12[6] = -(pcVar5[6] == '\0');
      auVar12[7] = -(pcVar5[7] == '\0');
      auVar12[8] = -(pcVar5[8] == '\0');
      auVar12[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar5[9]);
      auVar12[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar5[10]);
      auVar12[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar5[0xb]);
      auVar12[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar5[0xc]);
      auVar12[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar5[0xd]);
      auVar12[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar5[0xe]);
      auVar12[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar5[0xf]);
      uVar10 = uVar4 & 0xf;
      uVar2 = (ushort)((ushort)(SUB161(auVar12 >> 7,0) & 1) |
                       (ushort)(SUB161(auVar12 >> 0xf,0) & 1) << 1 |
                       (ushort)(SUB161(auVar12 >> 0x17,0) & 1) << 2 |
                       (ushort)(SUB161(auVar12 >> 0x1f,0) & 1) << 3 |
                       (ushort)(SUB161(auVar12 >> 0x27,0) & 1) << 4 |
                       (ushort)(SUB161(auVar12 >> 0x2f,0) & 1) << 5 |
                       (ushort)(SUB161(auVar12 >> 0x37,0) & 1) << 6 |
                       (ushort)(SUB161(auVar12 >> 0x3f,0) & 1) << 7 |
                       (ushort)(SUB161(auVar12 >> 0x47,0) & 1) << 8 |
                       (ushort)(SUB161(auVar12 >> 0x4f,0) & 1) << 9 |
                       (ushort)(SUB161(auVar12 >> 0x57,0) & 1) << 10 |
                       (ushort)(SUB161(auVar12 >> 0x5f,0) & 1) << 0xb |
                       (ushort)(SUB161(auVar12 >> 0x67,0) & 1) << 0xc |
                       (ushort)(SUB161(auVar12 >> 0x6f,0) & 1) << 0xd |
                       (ushort)(SUB161(auVar12 >> 0x77,0) & 1) << 0xe |
                      (ushort)(auVar12[0xf] >> 7) << 0xf) >> (sbyte)uVar10;
      uVar4 = 0;
      if (uVar2 != 0) {
        for (; (uVar2 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
        }
      }
      if (uVar2 == 0) {
        pcVar5 = FUN_180008c30((ulonglong)uVar10,(longlong)(pcVar5 + uVar10));
        uVar4 = (uint)pcVar5;
      }
    }
    else {
      uVar4 = (int)pcVar5 - uVar4;
    }
    uVar10 = uVar4 & 0x80000003;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
    }
    if (uVar4 != 0) {
      if ((uVar10 < 2) || (uVar10 == 2)) {
        lVar8 = (longlong)((int)(((uint)((int)uVar4 >> 1) >> 0x1e) + uVar4) >> 2) * 3 + 1;
      }
      else {
        lVar7 = (longlong)((int)(((uint)((int)uVar4 >> 1) >> 0x1e) + uVar4) >> 2);
        lVar8 = lVar7 * 3 + 1;
        if (uVar10 == 3) {
          lVar8 = lVar7 * 3 + 2;
        }
      }
      goto LAB_180007ef7;
    }
  }
  lVar8 = 0;
LAB_180007ef7:
  (*param_1)[lVar8] = 0;
  bVar9 = (*param_1)[0];
  if (bVar9 != 0) {
    lVar8 = 0;
    do {
      (*param_1)[lVar8 * 2] = bVar9 ^ 0xaa;
      if ((*param_1)[lVar8 * 2 + 1] == 0) {
        return param_1;
      }
      (*param_1)[lVar8 * 2 + 1] = (*param_1)[lVar8 * 2 + 1] ^ 0xaa;
      bVar9 = (*param_1)[lVar8 * 2 + 2];
      lVar8 = lVar8 + 1;
    } while (bVar9 != 0);
  }
  return param_1;
}



void FUN_180007f70(char *param_1,undefined1 (*param_2) [64])

{
  char cVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  char *pcVar7;
  sbyte sVar8;
  size_t sVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  
  if (*param_1 == '\0') {
    return;
  }
  uVar6 = (uint)param_1;
  pcVar7 = (char *)((ulonglong)param_1 & 0xfffffffffffffff0);
  auVar15[0] = -(*pcVar7 == '\0');
  auVar15[1] = -(pcVar7[1] == '\0');
  auVar15[2] = -(pcVar7[2] == '\0');
  auVar15[3] = -(pcVar7[3] == '\0');
  auVar15[4] = -(pcVar7[4] == '\0');
  auVar15[5] = -(pcVar7[5] == '\0');
  auVar15[6] = -(pcVar7[6] == '\0');
  auVar15[7] = -(pcVar7[7] == '\0');
  auVar15[8] = -(pcVar7[8] == '\0');
  auVar15[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar7[9]);
  auVar15[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar7[10]);
  auVar15[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar7[0xb]);
  auVar15[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar7[0xc]);
  auVar15[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar7[0xd]);
  auVar15[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar7[0xe]);
  auVar15[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar7[0xf]);
  auVar13[0] = -(*pcVar7 == '=');
  auVar13[1] = -(pcVar7[1] == '=');
  auVar13[2] = -(pcVar7[2] == '=');
  auVar13[3] = -(pcVar7[3] == '=');
  auVar13[4] = -(pcVar7[4] == '=');
  auVar13[5] = -(pcVar7[5] == '=');
  auVar13[6] = -(pcVar7[6] == '=');
  auVar13[7] = -(pcVar7[7] == '=');
  auVar13[8] = -(pcVar7[8] == '=');
  auVar13[9] = -(pcVar7[9] == '=');
  auVar13[10] = -(pcVar7[10] == '=');
  auVar13[0xb] = -(pcVar7[0xb] == '=');
  auVar13[0xc] = -(pcVar7[0xc] == '=');
  auVar13[0xd] = -(pcVar7[0xd] == '=');
  auVar13[0xe] = -(pcVar7[0xe] == '=');
  auVar13[0xf] = -(pcVar7[0xf] == '=');
  sVar8 = (sbyte)(uVar6 & 0xf);
  uVar4 = (ushort)((ushort)(SUB161(auVar13 >> 7,0) & 1) |
                   (ushort)(SUB161(auVar13 >> 0xf,0) & 1) << 1 |
                   (ushort)(SUB161(auVar13 >> 0x17,0) & 1) << 2 |
                   (ushort)(SUB161(auVar13 >> 0x1f,0) & 1) << 3 |
                   (ushort)(SUB161(auVar13 >> 0x27,0) & 1) << 4 |
                   (ushort)(SUB161(auVar13 >> 0x2f,0) & 1) << 5 |
                   (ushort)(SUB161(auVar13 >> 0x37,0) & 1) << 6 |
                   (ushort)(SUB161(auVar13 >> 0x3f,0) & 1) << 7 |
                   (ushort)(SUB161(auVar13 >> 0x47,0) & 1) << 8 |
                   (ushort)(SUB161(auVar13 >> 0x4f,0) & 1) << 9 |
                   (ushort)(SUB161(auVar13 >> 0x57,0) & 1) << 10 |
                   (ushort)(SUB161(auVar13 >> 0x5f,0) & 1) << 0xb |
                   (ushort)(SUB161(auVar13 >> 0x67,0) & 1) << 0xc |
                   (ushort)(SUB161(auVar13 >> 0x6f,0) & 1) << 0xd |
                   (ushort)(SUB161(auVar13 >> 0x77,0) & 1) << 0xe |
                  (ushort)(auVar13[0xf] >> 7) << 0xf) >> sVar8;
  uVar5 = (ushort)((ushort)(SUB161(auVar15 >> 7,0) & 1) |
                   (ushort)(SUB161(auVar15 >> 0xf,0) & 1) << 1 |
                   (ushort)(SUB161(auVar15 >> 0x17,0) & 1) << 2 |
                   (ushort)(SUB161(auVar15 >> 0x1f,0) & 1) << 3 |
                   (ushort)(SUB161(auVar15 >> 0x27,0) & 1) << 4 |
                   (ushort)(SUB161(auVar15 >> 0x2f,0) & 1) << 5 |
                   (ushort)(SUB161(auVar15 >> 0x37,0) & 1) << 6 |
                   (ushort)(SUB161(auVar15 >> 0x3f,0) & 1) << 7 |
                   (ushort)(SUB161(auVar15 >> 0x47,0) & 1) << 8 |
                   (ushort)(SUB161(auVar15 >> 0x4f,0) & 1) << 9 |
                   (ushort)(SUB161(auVar15 >> 0x57,0) & 1) << 10 |
                   (ushort)(SUB161(auVar15 >> 0x5f,0) & 1) << 0xb |
                   (ushort)(SUB161(auVar15 >> 0x67,0) & 1) << 0xc |
                   (ushort)(SUB161(auVar15 >> 0x6f,0) & 1) << 0xd |
                   (ushort)(SUB161(auVar15 >> 0x77,0) & 1) << 0xe |
                  (ushort)(auVar15[0xf] >> 7) << 0xf) >> sVar8;
  if (uVar4 == 0) {
    if (uVar5 == 0) {
      pcVar7 = FUN_180009680();
      goto LAB_180007ffa;
    }
  }
  else {
    uVar10 = 0;
    if (uVar4 != 0) {
      for (; (uVar4 >> uVar10 & 1) == 0; uVar10 = uVar10 + 1) {
      }
    }
    iVar3 = 0;
    if (uVar5 != 0) {
      for (; (uVar5 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
      }
    }
    if ((uVar5 == 0) || ((int)uVar10 <= iVar3)) {
      pcVar7 = pcVar7 + (ulonglong)uVar10 + (ulonglong)(uVar6 & 0xf);
      goto LAB_180007ffa;
    }
  }
  pcVar7 = (char *)0x0;
LAB_180007ffa:
  if (pcVar7 == (char *)0x0) {
    pcVar7 = (char *)((ulonglong)param_1 & 0xfffffffffffffff0);
    auVar14[0] = -(*pcVar7 == '\0');
    auVar14[1] = -(pcVar7[1] == '\0');
    auVar14[2] = -(pcVar7[2] == '\0');
    auVar14[3] = -(pcVar7[3] == '\0');
    auVar14[4] = -(pcVar7[4] == '\0');
    auVar14[5] = -(pcVar7[5] == '\0');
    auVar14[6] = -(pcVar7[6] == '\0');
    auVar14[7] = -(pcVar7[7] == '\0');
    auVar14[8] = -(pcVar7[8] == '\0');
    auVar14[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar7[9]);
    auVar14[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar7[10]);
    auVar14[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar7[0xb]);
    auVar14[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar7[0xc]);
    auVar14[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar7[0xd]);
    auVar14[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar7[0xe]);
    auVar14[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar7[0xf]);
    uVar10 = uVar6 & 0xf;
    uVar4 = (ushort)((ushort)(SUB161(auVar14 >> 7,0) & 1) |
                     (ushort)(SUB161(auVar14 >> 0xf,0) & 1) << 1 |
                     (ushort)(SUB161(auVar14 >> 0x17,0) & 1) << 2 |
                     (ushort)(SUB161(auVar14 >> 0x1f,0) & 1) << 3 |
                     (ushort)(SUB161(auVar14 >> 0x27,0) & 1) << 4 |
                     (ushort)(SUB161(auVar14 >> 0x2f,0) & 1) << 5 |
                     (ushort)(SUB161(auVar14 >> 0x37,0) & 1) << 6 |
                     (ushort)(SUB161(auVar14 >> 0x3f,0) & 1) << 7 |
                     (ushort)(SUB161(auVar14 >> 0x47,0) & 1) << 8 |
                     (ushort)(SUB161(auVar14 >> 0x4f,0) & 1) << 9 |
                     (ushort)(SUB161(auVar14 >> 0x57,0) & 1) << 10 |
                     (ushort)(SUB161(auVar14 >> 0x5f,0) & 1) << 0xb |
                     (ushort)(SUB161(auVar14 >> 0x67,0) & 1) << 0xc |
                     (ushort)(SUB161(auVar14 >> 0x6f,0) & 1) << 0xd |
                     (ushort)(SUB161(auVar14 >> 0x77,0) & 1) << 0xe |
                    (ushort)(auVar14[0xf] >> 7) << 0xf) >> (sbyte)uVar10;
    uVar6 = 0;
    if (uVar4 != 0) {
      for (; (uVar4 >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
      }
    }
    if (uVar4 == 0) {
      pcVar7 = FUN_180008c30((ulonglong)uVar10,(longlong)(pcVar7 + uVar10));
      uVar6 = (uint)pcVar7;
    }
  }
  else {
    uVar6 = (int)pcVar7 - uVar6;
  }
  uVar10 = uVar6 & 0x80000003;
  if ((int)uVar10 < 0) {
    uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
  }
  if (uVar6 != 0) {
    lVar11 = (longlong)((int)(((uint)((int)uVar6 >> 1) >> 0x1e) + uVar6) >> 2) * 3;
    if ((uVar10 < 2) || (uVar10 == 2)) {
      sVar9 = lVar11 + 1;
    }
    else {
      sVar9 = lVar11 + 1;
      if (uVar10 == 3) {
        sVar9 = lVar11 + 2;
      }
    }
    if (sVar9 != 0) {
      FUN_180009600(param_2,0,sVar9);
      lVar12 = 0;
      lVar11 = 0;
      cVar1 = *param_1;
      while ((cVar1 != '\0' && (bVar2 = param_1[lVar12], bVar2 != 0x3d))) {
        uVar6 = (uint)lVar12 & 0x80000003;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
        }
        if (uVar6 == 0) {
          uVar6 = bVar2 - 0x41;
          if (0x19 < bVar2 - 0x41) {
            if (bVar2 - 0x61 < 0x1a) {
              uVar6 = bVar2 + 0x39;
            }
            else if (bVar2 - 0x30 < 10) {
              uVar6 = bVar2 + 4;
            }
            else {
              uVar10 = (uint)bVar2;
              if (uVar10 == 0x2b) {
                uVar6 = 0x3e;
              }
              else {
                uVar6 = 0x3f;
                if (uVar10 != 0x2f) {
                  uVar6 = uVar10;
                }
              }
            }
          }
          (*param_2)[lVar11] = (*param_2)[lVar11] | (byte)(uVar6 << 2);
        }
        else if (uVar6 == 1) {
          uVar6 = bVar2 - 0x41;
          if (0x19 < bVar2 - 0x41) {
            if (bVar2 - 0x61 < 0x1a) {
              uVar6 = bVar2 + 0x39;
            }
            else if (bVar2 - 0x30 < 10) {
              uVar6 = bVar2 + 4;
            }
            else {
              uVar10 = (uint)bVar2;
              if (uVar10 == 0x2b) {
                uVar6 = 0x3e;
              }
              else {
                uVar6 = 0x3f;
                if (uVar10 != 0x2f) {
                  uVar6 = uVar10;
                }
              }
            }
          }
          (*param_2)[lVar11] = (*param_2)[lVar11] | (byte)((uVar6 & 0x30) >> 4);
          lVar11 = lVar11 + 1;
          if (lVar11 < (longlong)sVar9) {
            bVar2 = param_1[lVar12];
            uVar6 = bVar2 - 0x41;
            if (0x19 < bVar2 - 0x41) {
              if (bVar2 - 0x61 < 0x1a) {
                uVar6 = bVar2 + 9;
              }
              else if (bVar2 - 0x30 < 10) {
                uVar6 = bVar2 + 4;
              }
              else {
                uVar10 = (uint)bVar2;
                if (uVar10 == 0x2b) {
                  uVar6 = 0x3e;
                }
                else {
                  uVar6 = 0x3f;
                  if (uVar10 != 0x2f) {
                    uVar6 = uVar10;
                  }
                }
              }
            }
            (*param_2)[lVar11] = (*param_2)[lVar11] | (byte)(uVar6 << 4);
          }
        }
        else if (uVar6 == 2) {
          uVar6 = bVar2 - 0x41;
          if (0x19 < bVar2 - 0x41) {
            if (bVar2 - 0x61 < 0x1a) {
              uVar6 = bVar2 + 0x39;
            }
            else if (bVar2 - 0x30 < 10) {
              uVar6 = bVar2 + 4;
            }
            else {
              uVar10 = (uint)bVar2;
              if (uVar10 == 0x2b) {
                uVar6 = 0x3e;
              }
              else {
                uVar6 = 0x3f;
                if (uVar10 != 0x2f) {
                  uVar6 = uVar10;
                }
              }
            }
          }
          (*param_2)[lVar11] = (*param_2)[lVar11] | (byte)((uVar6 & 0x3c) >> 2);
          lVar11 = lVar11 + 1;
          if (lVar11 < (longlong)sVar9) {
            bVar2 = param_1[lVar12];
            uVar6 = bVar2 - 0x41;
            if (0x19 < bVar2 - 0x41) {
              if (bVar2 - 0x61 < 0x1a) {
                uVar6 = bVar2 + 1;
              }
              else {
                uVar10 = (uint)bVar2;
                if (bVar2 - 0x30 < 10) {
                  uVar6 = uVar10;
                }
                else if (uVar10 == 0x2b) {
                  uVar6 = 0x3e;
                }
                else {
                  uVar6 = 0x3f;
                  if (uVar10 != 0x2f) {
                    uVar6 = uVar10;
                  }
                }
              }
            }
            (*param_2)[lVar11] = (*param_2)[lVar11] | (byte)(uVar6 << 6);
          }
        }
        else if (uVar6 == 3) {
          uVar6 = bVar2 - 0x41;
          if (0x19 < bVar2 - 0x41) {
            if (bVar2 - 0x61 < 0x1a) {
              uVar6 = bVar2 + 0x39;
            }
            else if (bVar2 - 0x30 < 10) {
              uVar6 = bVar2 + 4;
            }
            else {
              uVar10 = (uint)bVar2;
              if (uVar10 == 0x2b) {
                uVar6 = 0x3e;
              }
              else {
                uVar6 = 0x3f;
                if (uVar10 != 0x2f) {
                  uVar6 = uVar10;
                }
              }
            }
          }
          (*param_2)[lVar11] = (*param_2)[lVar11] | (byte)uVar6 & 0x3f;
          lVar11 = lVar11 + 1;
        }
        lVar12 = lVar12 + 1;
        cVar1 = param_1[lVar12];
      }
    }
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x0001800086f4)
// WARNING: Removing unreachable block (ram,0x0001800086ff)
// WARNING: Removing unreachable block (ram,0x000180008654)
// WARNING: Removing unreachable block (ram,0x00018000865f)

uint * FUN_180008320(HKEY param_1,uint *param_2,char *param_3,uint *param_4,DWORD param_5,
                    uint *param_6,int param_7)

{
  ushort uVar1;
  LSTATUS LVar2;
  int iVar3;
  wchar_t *_Dest;
  wchar_t *pwVar4;
  char *pcVar5;
  size_t sVar6;
  undefined1 (*pauVar7) [64];
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  char *pcVar12;
  uint *puVar13;
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined8 in_stack_fffffffffffff268;
  undefined4 uVar17;
  uint local_d88 [128];
  HKEY local_b88 [16];
  wchar_t local_b08 [4];
  uint local_b00;
  wchar_t local_324 [122];
  char local_230 [4];
  char cStack_22c;
  char cStack_22b;
  char cStack_22a;
  char cStack_229;
  char cStack_228;
  char cStack_227;
  char cStack_226;
  char cStack_225;
  undefined4 uStack_224;
  uint local_124 [32];
  undefined1 local_a4 [4];
  undefined4 local_a0 [2];
  HKEY local_98;
  short *local_90;
  undefined4 local_88;
  undefined8 local_80;
  undefined8 local_78;
  short local_70 [4];
  wchar_t *local_68;
  short local_60 [4];
  wchar_t *local_58;
  undefined8 local_50 [2];
  
  puVar10 = param_6;
  if (param_7 != 0) {
    if (DAT_180018034 < 0) {
      DAT_180018034 = 0;
    }
    else if (DAT_180018034 != 0) {
      pcVar12 = (char *)((ulonglong)param_2 & 0xfffffffffffffff0);
      auVar14[0] = -(*pcVar12 == '\0');
      auVar14[1] = -(pcVar12[1] == '\0');
      auVar14[2] = -(pcVar12[2] == '\0');
      auVar14[3] = -(pcVar12[3] == '\0');
      auVar14[4] = -(pcVar12[4] == '\0');
      auVar14[5] = -(pcVar12[5] == '\0');
      auVar14[6] = -(pcVar12[6] == '\0');
      auVar14[7] = -(pcVar12[7] == '\0');
      auVar14[8] = -(pcVar12[8] == '\0');
      auVar14[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar12[9]);
      auVar14[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar12[10]);
      auVar14[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar12[0xb]);
      auVar14[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar12[0xc]);
      auVar14[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar12[0xd]);
      auVar14[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar12[0xe]);
      auVar14[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar12[0xf]);
      uVar8 = (uint)param_2 & 0xf;
      uVar1 = (ushort)((ushort)(SUB161(auVar14 >> 7,0) & 1) |
                       (ushort)(SUB161(auVar14 >> 0xf,0) & 1) << 1 |
                       (ushort)(SUB161(auVar14 >> 0x17,0) & 1) << 2 |
                       (ushort)(SUB161(auVar14 >> 0x1f,0) & 1) << 3 |
                       (ushort)(SUB161(auVar14 >> 0x27,0) & 1) << 4 |
                       (ushort)(SUB161(auVar14 >> 0x2f,0) & 1) << 5 |
                       (ushort)(SUB161(auVar14 >> 0x37,0) & 1) << 6 |
                       (ushort)(SUB161(auVar14 >> 0x3f,0) & 1) << 7 |
                       (ushort)(SUB161(auVar14 >> 0x47,0) & 1) << 8 |
                       (ushort)(SUB161(auVar14 >> 0x4f,0) & 1) << 9 |
                       (ushort)(SUB161(auVar14 >> 0x57,0) & 1) << 10 |
                       (ushort)(SUB161(auVar14 >> 0x5f,0) & 1) << 0xb |
                       (ushort)(SUB161(auVar14 >> 0x67,0) & 1) << 0xc |
                       (ushort)(SUB161(auVar14 >> 0x6f,0) & 1) << 0xd |
                       (ushort)(SUB161(auVar14 >> 0x77,0) & 1) << 0xe |
                      (ushort)(auVar14[0xf] >> 7) << 0xf) >> (sbyte)uVar8;
      iVar3 = 0;
      if (uVar1 != 0) {
        for (; (uVar1 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
        }
      }
      if (uVar1 == 0) {
        pcVar12 = FUN_180008c30((ulonglong)uVar8,(longlong)(pcVar12 + uVar8));
        iVar3 = (int)pcVar12;
      }
      puVar13 = &uStack_224;
      puVar11 = param_2;
      while (((ulonglong)puVar11 & 3) != 0) {
        uVar8 = *puVar11;
        puVar11 = (uint *)((longlong)puVar11 + 1);
        *(char *)puVar13 = (char)uVar8;
        if ((char)uVar8 == '\0') goto LAB_1800084ba;
        puVar13 = (uint *)((longlong)puVar13 + 1);
      }
      FUN_180008c60(puVar11,puVar13);
LAB_1800084ba:
      if (param_1 == (HKEY)0xffffffff80000002) {
        pauVar7 = FUN_180007e00((undefined1 (*) [64])local_b88,"9vjPzcPZ3tjT9ufLycLDxM8=");
        FUN_180001000(local_d88,"%s\\%s",pauVar7,param_2);
        FUN_180008c60(local_d88,&uStack_224);
        auVar16[0] = -(local_230[0] == '\0');
        auVar16[1] = -(local_230[1] == '\0');
        auVar16[2] = -(local_230[2] == '\0');
        auVar16[3] = -(local_230[3] == '\0');
        auVar16[4] = -(cStack_22c == '\0');
        auVar16[5] = -(cStack_22b == '\0');
        auVar16[6] = -(cStack_22a == '\0');
        auVar16[7] = -(cStack_229 == '\0');
        auVar16[8] = -(cStack_228 == '\0');
        auVar16[9] = -(SUB161((undefined1  [16])0x0,9) == cStack_227);
        auVar16[10] = -(SUB161((undefined1  [16])0x0,10) == cStack_226);
        auVar16[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cStack_225);
        auVar16[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == (char)uStack_224);
        auVar16[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == uStack_224._1_1_);
        auVar16[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == uStack_224._2_1_);
        auVar16[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == uStack_224._3_1_);
        uVar8 = (uint)&uStack_224 & 0xf;
        uVar1 = (ushort)((ushort)(SUB161(auVar16 >> 7,0) & 1) |
                         (ushort)(SUB161(auVar16 >> 0xf,0) & 1) << 1 |
                         (ushort)(SUB161(auVar16 >> 0x17,0) & 1) << 2 |
                         (ushort)(SUB161(auVar16 >> 0x1f,0) & 1) << 3 |
                         (ushort)(SUB161(auVar16 >> 0x27,0) & 1) << 4 |
                         (ushort)(SUB161(auVar16 >> 0x2f,0) & 1) << 5 |
                         (ushort)(SUB161(auVar16 >> 0x37,0) & 1) << 6 |
                         (ushort)(SUB161(auVar16 >> 0x3f,0) & 1) << 7 |
                         (ushort)(SUB161(auVar16 >> 0x47,0) & 1) << 8 |
                         (ushort)(SUB161(auVar16 >> 0x4f,0) & 1) << 9 |
                         (ushort)(SUB161(auVar16 >> 0x57,0) & 1) << 10 |
                         (ushort)(SUB161(auVar16 >> 0x5f,0) & 1) << 0xb |
                         (ushort)(SUB161(auVar16 >> 0x67,0) & 1) << 0xc |
                         (ushort)(SUB161(auVar16 >> 0x6f,0) & 1) << 0xd |
                         (ushort)(SUB161(auVar16 >> 0x77,0) & 1) << 0xe |
                        (ushort)(auVar16[0xf] >> 7) << 0xf) >> (sbyte)uVar8;
        iVar3 = 0;
        if (uVar1 != 0) {
          for (; (uVar1 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
          }
        }
        if (uVar1 == 0) {
          pcVar12 = FUN_180008c30((ulonglong)uVar8,(longlong)(local_230 + uVar8));
          iVar3 = (int)pcVar12;
        }
        param_1 = (HKEY)0x0;
      }
      _Dest = malloc((longlong)iVar3 * 2 + 2);
      mbstowcs(_Dest,(char *)&uStack_224,(longlong)iVar3 + 1);
      pwVar4 = wcschr(_Dest,L'~');
      uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffff268 >> 0x20);
      while (pwVar4 != (wchar_t *)0x0) {
        *pwVar4 = L'\0';
        pwVar4 = wcschr(pwVar4 + 1,L'~');
        uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffff268 >> 0x20);
      }
      local_90 = local_60;
      local_a0[0] = 0x30;
      local_88 = 0x40;
      local_80 = 0;
      local_78 = 0;
      local_98 = param_1;
      local_60[0] = (short)iVar3 * 2;
      local_58 = _Dest;
      iVar3 = (*DAT_18001a198)(local_50,0x20019,local_a0);
      free(_Dest);
      puVar13 = param_4;
      if (-1 < iVar3) {
        pcVar12 = (char *)((ulonglong)param_3 & 0xfffffffffffffff0);
        auVar15[0] = -(*pcVar12 == '\0');
        auVar15[1] = -(pcVar12[1] == '\0');
        auVar15[2] = -(pcVar12[2] == '\0');
        auVar15[3] = -(pcVar12[3] == '\0');
        auVar15[4] = -(pcVar12[4] == '\0');
        auVar15[5] = -(pcVar12[5] == '\0');
        auVar15[6] = -(pcVar12[6] == '\0');
        auVar15[7] = -(pcVar12[7] == '\0');
        auVar15[8] = -(pcVar12[8] == '\0');
        auVar15[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar12[9]);
        auVar15[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar12[10]);
        auVar15[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar12[0xb]);
        auVar15[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar12[0xc]);
        auVar15[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar12[0xd]);
        auVar15[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar12[0xe]);
        auVar15[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar12[0xf]);
        uVar9 = (uint)param_3 & 0xf;
        uVar1 = (ushort)((ushort)(SUB161(auVar15 >> 7,0) & 1) |
                         (ushort)(SUB161(auVar15 >> 0xf,0) & 1) << 1 |
                         (ushort)(SUB161(auVar15 >> 0x17,0) & 1) << 2 |
                         (ushort)(SUB161(auVar15 >> 0x1f,0) & 1) << 3 |
                         (ushort)(SUB161(auVar15 >> 0x27,0) & 1) << 4 |
                         (ushort)(SUB161(auVar15 >> 0x2f,0) & 1) << 5 |
                         (ushort)(SUB161(auVar15 >> 0x37,0) & 1) << 6 |
                         (ushort)(SUB161(auVar15 >> 0x3f,0) & 1) << 7 |
                         (ushort)(SUB161(auVar15 >> 0x47,0) & 1) << 8 |
                         (ushort)(SUB161(auVar15 >> 0x4f,0) & 1) << 9 |
                         (ushort)(SUB161(auVar15 >> 0x57,0) & 1) << 10 |
                         (ushort)(SUB161(auVar15 >> 0x5f,0) & 1) << 0xb |
                         (ushort)(SUB161(auVar15 >> 0x67,0) & 1) << 0xc |
                         (ushort)(SUB161(auVar15 >> 0x6f,0) & 1) << 0xd |
                         (ushort)(SUB161(auVar15 >> 0x77,0) & 1) << 0xe |
                        (ushort)(auVar15[0xf] >> 7) << 0xf) >> (sbyte)uVar9;
        uVar8 = 0;
        if (uVar1 != 0) {
          for (; (uVar1 >> uVar8 & 1) == 0; uVar8 = uVar8 + 1) {
          }
        }
        pcVar5 = (char *)(ulonglong)uVar8;
        if (uVar1 == 0) {
          pcVar5 = FUN_180008c30((ulonglong)uVar9,(longlong)(pcVar12 + uVar9));
        }
        mbstowcs(local_324,param_3,(size_t)(pcVar5 + 1));
        local_68 = local_324;
        sVar6 = wcslen(local_324);
        local_70[0] = (short)sVar6 * 2;
        iVar3 = (*DAT_18001a1a0)(local_50[0],local_70,1,local_b08,CONCAT44(uVar17,0x7e4),local_a4);
        if (-1 < iVar3) {
          wcstombs((char *)local_124,(wchar_t *)((longlong)local_b08 + (ulonglong)local_b00),0x80);
          (*DAT_18001a1a8)(local_50[0]);
          FUN_180008c60(local_124,param_4);
          return param_4;
        }
      }
      while( true ) {
        if (((ulonglong)puVar10 & 3) == 0) {
          FUN_180008c60(puVar10,puVar13);
          return param_4;
        }
        uVar8 = *puVar10;
        puVar10 = (uint *)((longlong)puVar10 + 1);
        *(char *)puVar13 = (char)uVar8;
        if ((char)uVar8 == '\0') break;
        puVar13 = (uint *)((longlong)puVar13 + 1);
      }
      return param_4;
    }
  }
  *(undefined1 *)param_4 = 0;
  FUN_180008b10("~",&DAT_1800143e4,(char *)param_2,local_d88);
  LVar2 = RegOpenKeyExA(param_1,(LPCSTR)local_d88,0,0x20019,local_b88);
  puVar13 = param_4;
  if (LVar2 != 0) {
    while( true ) {
      if (((ulonglong)puVar10 & 3) == 0) {
        FUN_180008c60(puVar10,puVar13);
        return param_4;
      }
      uVar8 = *puVar10;
      puVar10 = (uint *)((longlong)puVar10 + 1);
      *(char *)puVar13 = (char)uVar8;
      if ((char)uVar8 == '\0') break;
      puVar13 = (uint *)((longlong)puVar13 + 1);
    }
    return param_4;
  }
  LVar2 = RegQueryValueExA(local_b88[0],param_3,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)param_4,&param_5);
  RegCloseKey(local_b88[0]);
  if (LVar2 != 0) {
    while (((ulonglong)puVar10 & 3) != 0) {
      uVar8 = *puVar10;
      puVar10 = (uint *)((longlong)puVar10 + 1);
      *(char *)puVar13 = (char)uVar8;
      if ((char)uVar8 == '\0') {
        return param_4;
      }
      puVar13 = (uint *)((longlong)puVar13 + 1);
    }
    FUN_180008c60(puVar10,puVar13);
  }
  return param_4;
}



undefined4
FUN_180008750(HKEY param_1,LPCSTR param_2,LPCSTR param_3,LPBYTE param_4,undefined4 param_5)

{
  LSTATUS LVar1;
  HKEY local_28;
  DWORD local_20 [4];
  
  if ((((param_2 == (LPCSTR)0x0) || (*param_2 == '\0')) || (param_3 == (LPCSTR)0x0)) ||
     (*param_3 == '\0')) {
    return param_5;
  }
  local_20[0] = 4;
  LVar1 = RegOpenKeyExA(param_1,param_2,0,0x20019,&local_28);
  if (LVar1 != 0) {
    *(undefined4 *)param_4 = param_5;
    return 0;
  }
  LVar1 = RegQueryValueExA(local_28,param_3,(LPDWORD)0x0,(LPDWORD)0x0,param_4,local_20);
  RegCloseKey(local_28);
  if (LVar1 == 0) {
    return 1;
  }
  *(undefined4 *)param_4 = param_5;
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180008820(HKEY param_1,LPCSTR param_2,LPCSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  BOOL BVar2;
  undefined4 local_res20 [2];
  HKEY local_48 [5];
  
  if ((param_3 == (LPCSTR)0x0) || (*param_3 == '\0')) {
    return;
  }
  local_res20[0] = param_4;
  if (DAT_1800193f0 == 0) {
    _DAT_180019370 = 0;
    DAT_180019360_4 = SUB1612((undefined1  [16])0x0,4);
    _DAT_180019360 = 0x18;
    if (DAT_1800193f4 == 0) {
      BVar2 = AllocateAndInitializeSid
                        ((PSID_IDENTIFIER_AUTHORITY)&DAT_18001803c,'\x01',0,0,0,0,0,0,0,0,
                         (PSID *)&DAT_1800193d8);
      if (BVar2 != 0) {
        DAT_180019380_12 = SUB164((undefined1  [16])0x0,0xc);
        _DAT_180019380 = ZEXT812(0x1000f003f);
        _DAT_180019390 = SUB1612((undefined1  [16])0x0,0);
        _DAT_18001939c = 0;
        DAT_1800193a0_4 = SUB1612((undefined1  [16])0x0,4);
        _DAT_1800193a0 = 5;
        _DAT_1800193a8 = DAT_1800193d8;
        SetEntriesInAclA(1,(PEXPLICIT_ACCESS_A)&DAT_180019380,(PACL)0x0,&DAT_1800193e0);
        IsValidAcl(DAT_1800193e0);
      }
      InitializeSecurityDescriptor(&DAT_1800193b0,1);
      SetSecurityDescriptorDacl(&DAT_1800193b0,1,DAT_1800193e0,0);
      DAT_1800193f4 = 1;
    }
    _DAT_180019368 = &DAT_1800193b0;
    _DAT_180019370 = CONCAT44(DAT_180019370_4,1);
    DAT_1800193f0 = 1;
  }
  LVar1 = RegCreateKeyExA(param_1,param_2,0,(LPSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)&DAT_180019360,local_48,(LPDWORD)0x0);
  if (LVar1 == 0) {
    RegSetValueExA(local_48[0],param_3,0,4,(BYTE *)local_res20,4);
    RegCloseKey(local_48[0]);
  }
  return;
}



bool FUN_180008a50(LPCSTR param_1)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
  if ((param_1 == (LPCSTR)0x0) || (*param_1 == '\0')) {
    return false;
  }
  LVar1 = RegOpenKeyExA((HKEY)0xffffffff80000002,param_1,0,0x20019,local_18);
  RegCloseKey(local_18[0]);
  return LVar1 == 0;
}



bool FUN_180008ab0(LPCSTR param_1)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
  if ((param_1 == (LPCSTR)0x0) || (*param_1 == '\0')) {
    return false;
  }
  LVar1 = RegOpenKeyExA((HKEY)0xffffffff80000002,param_1,0,0x2001f,local_18);
  RegCloseKey(local_18[0]);
  return LVar1 == 0;
}



void FUN_180008b10(char *param_1,void *param_2,char *param_3,void *param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  size_t _Size;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  while( true ) {
    pcVar4 = strstr(param_3,param_1);
    if (pcVar4 == (char *)0x0) break;
    pcVar7 = (char *)((ulonglong)param_1 & 0xfffffffffffffff0);
    auVar9[0] = -(*pcVar7 == '\0');
    auVar9[1] = -(pcVar7[1] == '\0');
    auVar9[2] = -(pcVar7[2] == '\0');
    auVar9[3] = -(pcVar7[3] == '\0');
    auVar9[4] = -(pcVar7[4] == '\0');
    auVar9[5] = -(pcVar7[5] == '\0');
    auVar9[6] = -(pcVar7[6] == '\0');
    auVar9[7] = -(pcVar7[7] == '\0');
    auVar9[8] = -(pcVar7[8] == '\0');
    auVar9[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar7[9]);
    auVar9[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar7[10]);
    auVar9[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar7[0xb]);
    auVar9[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar7[0xc]);
    auVar9[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar7[0xd]);
    auVar9[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar7[0xe]);
    auVar9[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar7[0xf]);
    uVar5 = (uint)param_1 & 0xf;
    uVar1 = (ushort)((ushort)(SUB161(auVar9 >> 7,0) & 1) |
                     (ushort)(SUB161(auVar9 >> 0xf,0) & 1) << 1 |
                     (ushort)(SUB161(auVar9 >> 0x17,0) & 1) << 2 |
                     (ushort)(SUB161(auVar9 >> 0x1f,0) & 1) << 3 |
                     (ushort)(SUB161(auVar9 >> 0x27,0) & 1) << 4 |
                     (ushort)(SUB161(auVar9 >> 0x2f,0) & 1) << 5 |
                     (ushort)(SUB161(auVar9 >> 0x37,0) & 1) << 6 |
                     (ushort)(SUB161(auVar9 >> 0x3f,0) & 1) << 7 |
                     (ushort)(SUB161(auVar9 >> 0x47,0) & 1) << 8 |
                     (ushort)(SUB161(auVar9 >> 0x4f,0) & 1) << 9 |
                     (ushort)(SUB161(auVar9 >> 0x57,0) & 1) << 10 |
                     (ushort)(SUB161(auVar9 >> 0x5f,0) & 1) << 0xb |
                     (ushort)(SUB161(auVar9 >> 0x67,0) & 1) << 0xc |
                     (ushort)(SUB161(auVar9 >> 0x6f,0) & 1) << 0xd |
                     (ushort)(SUB161(auVar9 >> 0x77,0) & 1) << 0xe |
                    (ushort)(auVar9[0xf] >> 7) << 0xf) >> (sbyte)uVar5;
    iVar2 = 0;
    if (uVar1 != 0) {
      for (; (uVar1 >> iVar2 & 1) == 0; iVar2 = iVar2 + 1) {
      }
    }
    if (uVar1 == 0) {
      pcVar7 = FUN_180008c30((ulonglong)uVar5,(longlong)(pcVar7 + uVar5));
      iVar2 = (int)pcVar7;
    }
    iVar8 = (int)pcVar4;
    pcVar4 = (char *)((ulonglong)param_2 & 0xfffffffffffffff0);
    auVar10[0] = -(*pcVar4 == '\0');
    auVar10[1] = -(pcVar4[1] == '\0');
    auVar10[2] = -(pcVar4[2] == '\0');
    auVar10[3] = -(pcVar4[3] == '\0');
    auVar10[4] = -(pcVar4[4] == '\0');
    auVar10[5] = -(pcVar4[5] == '\0');
    auVar10[6] = -(pcVar4[6] == '\0');
    auVar10[7] = -(pcVar4[7] == '\0');
    auVar10[8] = -(pcVar4[8] == '\0');
    auVar10[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar4[9]);
    auVar10[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar4[10]);
    auVar10[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar4[0xb]);
    auVar10[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar4[0xc]);
    auVar10[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar4[0xd]);
    auVar10[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar4[0xe]);
    auVar10[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar4[0xf]);
    uVar5 = (uint)param_2 & 0xf;
    uVar1 = (ushort)((ushort)(SUB161(auVar10 >> 7,0) & 1) |
                     (ushort)(SUB161(auVar10 >> 0xf,0) & 1) << 1 |
                     (ushort)(SUB161(auVar10 >> 0x17,0) & 1) << 2 |
                     (ushort)(SUB161(auVar10 >> 0x1f,0) & 1) << 3 |
                     (ushort)(SUB161(auVar10 >> 0x27,0) & 1) << 4 |
                     (ushort)(SUB161(auVar10 >> 0x2f,0) & 1) << 5 |
                     (ushort)(SUB161(auVar10 >> 0x37,0) & 1) << 6 |
                     (ushort)(SUB161(auVar10 >> 0x3f,0) & 1) << 7 |
                     (ushort)(SUB161(auVar10 >> 0x47,0) & 1) << 8 |
                     (ushort)(SUB161(auVar10 >> 0x4f,0) & 1) << 9 |
                     (ushort)(SUB161(auVar10 >> 0x57,0) & 1) << 10 |
                     (ushort)(SUB161(auVar10 >> 0x5f,0) & 1) << 0xb |
                     (ushort)(SUB161(auVar10 >> 0x67,0) & 1) << 0xc |
                     (ushort)(SUB161(auVar10 >> 0x6f,0) & 1) << 0xd |
                     (ushort)(SUB161(auVar10 >> 0x77,0) & 1) << 0xe |
                    (ushort)(auVar10[0xf] >> 7) << 0xf) >> (sbyte)uVar5;
    iVar3 = 0;
    if (uVar1 != 0) {
      for (; (uVar1 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
      }
    }
    if (uVar1 == 0) {
      pcVar4 = FUN_180008c30((ulonglong)uVar5,(longlong)(pcVar4 + uVar5));
      iVar3 = (int)pcVar4;
    }
    _Size = (size_t)(int)(iVar8 - (uint)param_3);
    memmove(param_4,param_3,_Size);
    memmove((void *)((longlong)param_4 + _Size),param_2,(longlong)iVar3);
    param_4 = (void *)((longlong)((longlong)param_4 + _Size) + (longlong)iVar3);
    param_3 = param_3 + _Size + (longlong)iVar2;
  }
  pcVar4 = (char *)((ulonglong)param_3 & 0xfffffffffffffff0);
  auVar11[0] = -(*pcVar4 == '\0');
  auVar11[1] = -(pcVar4[1] == '\0');
  auVar11[2] = -(pcVar4[2] == '\0');
  auVar11[3] = -(pcVar4[3] == '\0');
  auVar11[4] = -(pcVar4[4] == '\0');
  auVar11[5] = -(pcVar4[5] == '\0');
  auVar11[6] = -(pcVar4[6] == '\0');
  auVar11[7] = -(pcVar4[7] == '\0');
  auVar11[8] = -(pcVar4[8] == '\0');
  auVar11[9] = -(SUB161((undefined1  [16])0x0,9) == pcVar4[9]);
  auVar11[10] = -(SUB161((undefined1  [16])0x0,10) == pcVar4[10]);
  auVar11[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == pcVar4[0xb]);
  auVar11[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == pcVar4[0xc]);
  auVar11[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == pcVar4[0xd]);
  auVar11[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == pcVar4[0xe]);
  auVar11[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == pcVar4[0xf]);
  uVar6 = (uint)param_3 & 0xf;
  uVar1 = (ushort)((ushort)(SUB161(auVar11 >> 7,0) & 1) |
                   (ushort)(SUB161(auVar11 >> 0xf,0) & 1) << 1 |
                   (ushort)(SUB161(auVar11 >> 0x17,0) & 1) << 2 |
                   (ushort)(SUB161(auVar11 >> 0x1f,0) & 1) << 3 |
                   (ushort)(SUB161(auVar11 >> 0x27,0) & 1) << 4 |
                   (ushort)(SUB161(auVar11 >> 0x2f,0) & 1) << 5 |
                   (ushort)(SUB161(auVar11 >> 0x37,0) & 1) << 6 |
                   (ushort)(SUB161(auVar11 >> 0x3f,0) & 1) << 7 |
                   (ushort)(SUB161(auVar11 >> 0x47,0) & 1) << 8 |
                   (ushort)(SUB161(auVar11 >> 0x4f,0) & 1) << 9 |
                   (ushort)(SUB161(auVar11 >> 0x57,0) & 1) << 10 |
                   (ushort)(SUB161(auVar11 >> 0x5f,0) & 1) << 0xb |
                   (ushort)(SUB161(auVar11 >> 0x67,0) & 1) << 0xc |
                   (ushort)(SUB161(auVar11 >> 0x6f,0) & 1) << 0xd |
                   (ushort)(SUB161(auVar11 >> 0x77,0) & 1) << 0xe |
                  (ushort)(auVar11[0xf] >> 7) << 0xf) >> (sbyte)uVar6;
  uVar5 = 0;
  if (uVar1 != 0) {
    for (; (uVar1 >> uVar5 & 1) == 0; uVar5 = uVar5 + 1) {
    }
  }
  pcVar7 = (char *)(ulonglong)uVar5;
  if (uVar1 == 0) {
    pcVar7 = FUN_180008c30((ulonglong)uVar6,(longlong)(pcVar4 + uVar6));
  }
  memmove(param_4,param_3,(size_t)(pcVar7 + 1));
  return;
}



char * FUN_180008c30(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  ushort uVar2;
  char *in_RAX;
  char *pcVar3;
  undefined1 auVar4 [16];
  
  do {
    pcVar3 = in_RAX + 0x10;
    auVar4[0] = -(*pcVar3 == '\0');
    auVar4[1] = -(in_RAX[0x11] == '\0');
    auVar4[2] = -(in_RAX[0x12] == '\0');
    auVar4[3] = -(in_RAX[0x13] == '\0');
    auVar4[4] = -(in_RAX[0x14] == '\0');
    auVar4[5] = -(in_RAX[0x15] == '\0');
    auVar4[6] = -(in_RAX[0x16] == '\0');
    auVar4[7] = -(in_RAX[0x17] == '\0');
    auVar4[8] = -(in_RAX[0x18] == '\0');
    auVar4[9] = -(in_RAX[0x19] == '\0');
    auVar4[10] = -(in_RAX[0x1a] == '\0');
    auVar4[0xb] = -(in_RAX[0x1b] == '\0');
    auVar4[0xc] = -(in_RAX[0x1c] == '\0');
    auVar4[0xd] = -(in_RAX[0x1d] == '\0');
    auVar4[0xe] = -(in_RAX[0x1e] == '\0');
    auVar4[0xf] = -(in_RAX[0x1f] == '\0');
    uVar2 = (ushort)(SUB161(auVar4 >> 7,0) & 1) | (ushort)(SUB161(auVar4 >> 0xf,0) & 1) << 1 |
            (ushort)(SUB161(auVar4 >> 0x17,0) & 1) << 2 |
            (ushort)(SUB161(auVar4 >> 0x1f,0) & 1) << 3 |
            (ushort)(SUB161(auVar4 >> 0x27,0) & 1) << 4 |
            (ushort)(SUB161(auVar4 >> 0x2f,0) & 1) << 5 |
            (ushort)(SUB161(auVar4 >> 0x37,0) & 1) << 6 |
            (ushort)(SUB161(auVar4 >> 0x3f,0) & 1) << 7 |
            (ushort)(SUB161(auVar4 >> 0x47,0) & 1) << 8 |
            (ushort)(SUB161(auVar4 >> 0x4f,0) & 1) << 9 |
            (ushort)(SUB161(auVar4 >> 0x57,0) & 1) << 10 |
            (ushort)(SUB161(auVar4 >> 0x5f,0) & 1) << 0xb |
            (ushort)(SUB161(auVar4 >> 0x67,0) & 1) << 0xc |
            (ushort)(SUB161(auVar4 >> 0x6f,0) & 1) << 0xd |
            (ushort)(SUB161(auVar4 >> 0x77,0) & 1) << 0xe | (ushort)(auVar4[0xf] >> 7) << 0xf;
    in_RAX = pcVar3;
  } while (uVar2 == 0);
  uVar1 = 0;
  if (uVar2 != 0) {
    for (; (uVar2 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
    }
  }
  return pcVar3 + ((ulonglong)uVar1 - param_2);
}



void FUN_180008c60(uint *param_1,uint *param_2)

{
  undefined8 uVar1;
  int iVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  
  uVar22 = ~*param_1 ^ *param_1 + 0x7efefeff;
  uVar21 = *param_1;
  do {
    puVar20 = param_1 + 1;
    if ((uVar22 & 0x81010100) != 0) {
      if ((char)uVar21 == '\0') {
        *(undefined1 *)param_2 = 0;
        return;
      }
      if ((uVar21 & 0xff00) == 0) {
        *(short *)param_2 = (short)uVar21;
        return;
      }
      if ((uVar21 & 0xff0000) == 0) {
        *(short *)param_2 = (short)uVar21;
        *(undefined1 *)((longlong)param_2 + 2) = 0;
        return;
      }
      if ((uVar21 & 0xff000000) == 0) {
        *param_2 = uVar21;
        return;
      }
    }
    *param_2 = uVar21;
    param_2 = param_2 + 1;
    if (((ulonglong)puVar20 & 0xf) == 0) {
      cVar16 = (char)*puVar20;
      cVar4 = *(char *)((longlong)param_1 + 5);
      cVar5 = *(char *)((longlong)param_1 + 6);
      cVar6 = *(char *)((longlong)param_1 + 7);
      cVar17 = (char)puVar20[1];
      cVar7 = *(char *)((longlong)param_1 + 9);
      cVar8 = *(char *)((longlong)param_1 + 10);
      cVar9 = *(char *)((longlong)param_1 + 0xb);
      cVar18 = (char)puVar20[2];
      cVar10 = *(char *)((longlong)param_1 + 0xd);
      cVar11 = *(char *)((longlong)param_1 + 0xe);
      cVar12 = *(char *)((longlong)param_1 + 0xf);
      cVar19 = (char)puVar20[3];
      cVar13 = *(char *)((longlong)param_1 + 0x11);
      cVar14 = *(char *)((longlong)param_1 + 0x12);
      cVar15 = *(char *)((longlong)param_1 + 0x13);
      auVar24[0] = -(cVar16 == '\0');
      auVar24[1] = -(cVar4 == '\0');
      auVar24[2] = -(cVar5 == '\0');
      auVar24[3] = -(cVar6 == '\0');
      auVar24[4] = -(cVar17 == '\0');
      auVar24[5] = -(cVar7 == '\0');
      auVar24[6] = -(cVar8 == '\0');
      auVar24[7] = -(cVar9 == '\0');
      auVar24[8] = -(cVar18 == '\0');
      auVar24[9] = -(SUB161((undefined1  [16])0x0,9) == cVar10);
      auVar24[10] = -(SUB161((undefined1  [16])0x0,10) == cVar11);
      auVar24[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar12);
      auVar24[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar19);
      auVar24[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar13);
      auVar24[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar14);
      auVar24[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar15);
      uVar3 = (ushort)(SUB161(auVar24 >> 7,0) & 1) | (ushort)(SUB161(auVar24 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar24 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar24 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar24 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar24 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar24 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar24 >> 0x3f,0) & 1) << 7 |
              (ushort)(SUB161(auVar24 >> 0x47,0) & 1) << 8 |
              (ushort)(SUB161(auVar24 >> 0x4f,0) & 1) << 9 |
              (ushort)(SUB161(auVar24 >> 0x57,0) & 1) << 10 |
              (ushort)(SUB161(auVar24 >> 0x5f,0) & 1) << 0xb |
              (ushort)(SUB161(auVar24 >> 0x67,0) & 1) << 0xc |
              (ushort)(SUB161(auVar24 >> 0x6f,0) & 1) << 0xd |
              (ushort)(SUB161(auVar24 >> 0x77,0) & 1) << 0xe | (ushort)(auVar24[0xf] >> 7) << 0xf;
      while (uVar3 == 0) {
        *(ulonglong *)param_2 =
             CONCAT17(cVar9,CONCAT16(cVar8,CONCAT15(cVar7,CONCAT14(cVar17,CONCAT13(cVar6,CONCAT12(
                                                  cVar5,CONCAT11(cVar4,cVar16)))))));
        *(ulonglong *)(param_2 + 2) =
             CONCAT17(cVar15,CONCAT16(cVar14,CONCAT15(cVar13,CONCAT14(cVar19,CONCAT13(cVar12,
                                                  CONCAT12(cVar11,CONCAT11(cVar10,cVar18)))))));
        param_2 = param_2 + 4;
        cVar16 = (char)puVar20[4];
        cVar4 = *(char *)((longlong)puVar20 + 0x11);
        cVar5 = *(char *)((longlong)puVar20 + 0x12);
        cVar6 = *(char *)((longlong)puVar20 + 0x13);
        cVar17 = (char)puVar20[5];
        cVar7 = *(char *)((longlong)puVar20 + 0x15);
        cVar8 = *(char *)((longlong)puVar20 + 0x16);
        cVar9 = *(char *)((longlong)puVar20 + 0x17);
        cVar18 = (char)puVar20[6];
        cVar10 = *(char *)((longlong)puVar20 + 0x19);
        cVar11 = *(char *)((longlong)puVar20 + 0x1a);
        cVar12 = *(char *)((longlong)puVar20 + 0x1b);
        cVar19 = (char)puVar20[7];
        cVar13 = *(char *)((longlong)puVar20 + 0x1d);
        cVar14 = *(char *)((longlong)puVar20 + 0x1e);
        cVar15 = *(char *)((longlong)puVar20 + 0x1f);
        auVar23[0] = -(cVar16 == '\0');
        auVar23[1] = -(cVar4 == '\0');
        auVar23[2] = -(cVar5 == '\0');
        auVar23[3] = -(cVar6 == '\0');
        auVar23[4] = -(cVar17 == '\0');
        auVar23[5] = -(cVar7 == '\0');
        auVar23[6] = -(cVar8 == '\0');
        auVar23[7] = -(cVar9 == '\0');
        auVar23[8] = -(cVar18 == '\0');
        auVar23[9] = -(SUB161((undefined1  [16])0x0,9) == cVar10);
        auVar23[10] = -(SUB161((undefined1  [16])0x0,10) == cVar11);
        auVar23[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar12);
        auVar23[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar19);
        auVar23[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar13);
        auVar23[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar14);
        auVar23[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar15);
        puVar20 = puVar20 + 4;
        uVar3 = (ushort)(SUB161(auVar23 >> 7,0) & 1) | (ushort)(SUB161(auVar23 >> 0xf,0) & 1) << 1 |
                (ushort)(SUB161(auVar23 >> 0x17,0) & 1) << 2 |
                (ushort)(SUB161(auVar23 >> 0x1f,0) & 1) << 3 |
                (ushort)(SUB161(auVar23 >> 0x27,0) & 1) << 4 |
                (ushort)(SUB161(auVar23 >> 0x2f,0) & 1) << 5 |
                (ushort)(SUB161(auVar23 >> 0x37,0) & 1) << 6 |
                (ushort)(SUB161(auVar23 >> 0x3f,0) & 1) << 7 |
                (ushort)(SUB161(auVar23 >> 0x47,0) & 1) << 8 |
                (ushort)(SUB161(auVar23 >> 0x4f,0) & 1) << 9 |
                (ushort)(SUB161(auVar23 >> 0x57,0) & 1) << 10 |
                (ushort)(SUB161(auVar23 >> 0x5f,0) & 1) << 0xb |
                (ushort)(SUB161(auVar23 >> 0x67,0) & 1) << 0xc |
                (ushort)(SUB161(auVar23 >> 0x6f,0) & 1) << 0xd |
                (ushort)(SUB161(auVar23 >> 0x77,0) & 1) << 0xe | (ushort)(auVar23[0xf] >> 7) << 0xf;
      }
      iVar2 = 0;
      if (uVar3 != 0) {
        for (; (uVar3 >> iVar2 & 1) == 0; iVar2 = iVar2 + 1) {
        }
      }
      uVar21 = iVar2 + 1;
      if ((uVar21 & 0xf) == 0) {
        *(ulonglong *)param_2 =
             CONCAT17(cVar9,CONCAT16(cVar8,CONCAT15(cVar7,CONCAT14(cVar17,CONCAT13(cVar6,CONCAT12(
                                                  cVar5,CONCAT11(cVar4,cVar16)))))));
        *(ulonglong *)(param_2 + 2) =
             CONCAT17(cVar15,CONCAT16(cVar14,CONCAT15(cVar13,CONCAT14(cVar19,CONCAT13(cVar12,
                                                  CONCAT12(cVar11,CONCAT11(cVar10,cVar18)))))));
        return;
      }
      if ((uVar21 & 8) != 0) {
        uVar1 = *(undefined8 *)puVar20;
        puVar20 = puVar20 + 2;
        *(undefined8 *)param_2 = uVar1;
        param_2 = param_2 + 2;
      }
      if ((uVar21 & 4) != 0) {
        uVar22 = *puVar20;
        puVar20 = puVar20 + 1;
        *param_2 = uVar22;
        param_2 = param_2 + 1;
      }
      if ((uVar21 & 2) != 0) {
        uVar22 = *puVar20;
        puVar20 = (uint *)((longlong)puVar20 + 2);
        *(short *)param_2 = (short)uVar22;
        param_2 = (uint *)((longlong)param_2 + 2);
      }
      if ((uVar21 & 1) != 0) {
        *(char *)param_2 = (char)*puVar20;
      }
      return;
    }
    uVar22 = ~*puVar20 ^ *puVar20 + 0x7efefeff;
    uVar21 = *puVar20;
    param_1 = puVar20;
  } while( true );
}



void FUN_180008cc7(uint *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  ushort uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  char cVar20;
  uint *puVar21;
  uint uVar22;
  uint *in_R10;
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  
  do {
    puVar21 = param_1;
    uVar22 = *puVar21;
    param_1 = puVar21 + 1;
    if (((~*puVar21 ^ *puVar21 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar22 == '\0') {
        *(undefined1 *)in_R10 = 0;
        return;
      }
      if ((uVar22 & 0xff00) == 0) {
        *(short *)in_R10 = (short)uVar22;
        return;
      }
      if ((uVar22 & 0xff0000) == 0) {
        *(short *)in_R10 = (short)uVar22;
        *(undefined1 *)((longlong)in_R10 + 2) = 0;
        return;
      }
      if ((uVar22 & 0xff000000) == 0) {
        *in_R10 = uVar22;
        return;
      }
    }
    *in_R10 = uVar22;
    in_R10 = in_R10 + 1;
    if (((ulonglong)param_1 & 0xf) == 0) {
      cVar17 = (char)*param_1;
      cVar5 = *(char *)((longlong)puVar21 + 5);
      cVar6 = *(char *)((longlong)puVar21 + 6);
      cVar7 = *(char *)((longlong)puVar21 + 7);
      cVar18 = (char)puVar21[2];
      cVar8 = *(char *)((longlong)puVar21 + 9);
      cVar9 = *(char *)((longlong)puVar21 + 10);
      cVar10 = *(char *)((longlong)puVar21 + 0xb);
      cVar19 = (char)puVar21[3];
      cVar11 = *(char *)((longlong)puVar21 + 0xd);
      cVar12 = *(char *)((longlong)puVar21 + 0xe);
      cVar13 = *(char *)((longlong)puVar21 + 0xf);
      cVar20 = (char)puVar21[4];
      cVar14 = *(char *)((longlong)puVar21 + 0x11);
      cVar15 = *(char *)((longlong)puVar21 + 0x12);
      cVar16 = *(char *)((longlong)puVar21 + 0x13);
      auVar24[0] = -(cVar17 == '\0');
      auVar24[1] = -(cVar5 == '\0');
      auVar24[2] = -(cVar6 == '\0');
      auVar24[3] = -(cVar7 == '\0');
      auVar24[4] = -(cVar18 == '\0');
      auVar24[5] = -(cVar8 == '\0');
      auVar24[6] = -(cVar9 == '\0');
      auVar24[7] = -(cVar10 == '\0');
      auVar24[8] = -(cVar19 == '\0');
      auVar24[9] = -(SUB161((undefined1  [16])0x0,9) == cVar11);
      auVar24[10] = -(SUB161((undefined1  [16])0x0,10) == cVar12);
      auVar24[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar13);
      auVar24[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar20);
      auVar24[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar14);
      auVar24[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar15);
      auVar24[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar16);
      uVar4 = (ushort)(SUB161(auVar24 >> 7,0) & 1) | (ushort)(SUB161(auVar24 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar24 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar24 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar24 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar24 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar24 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar24 >> 0x3f,0) & 1) << 7 |
              (ushort)(SUB161(auVar24 >> 0x47,0) & 1) << 8 |
              (ushort)(SUB161(auVar24 >> 0x4f,0) & 1) << 9 |
              (ushort)(SUB161(auVar24 >> 0x57,0) & 1) << 10 |
              (ushort)(SUB161(auVar24 >> 0x5f,0) & 1) << 0xb |
              (ushort)(SUB161(auVar24 >> 0x67,0) & 1) << 0xc |
              (ushort)(SUB161(auVar24 >> 0x6f,0) & 1) << 0xd |
              (ushort)(SUB161(auVar24 >> 0x77,0) & 1) << 0xe | (ushort)(auVar24[0xf] >> 7) << 0xf;
      while (uVar4 == 0) {
        *(ulonglong *)in_R10 =
             CONCAT17(cVar10,CONCAT16(cVar9,CONCAT15(cVar8,CONCAT14(cVar18,CONCAT13(cVar7,CONCAT12(
                                                  cVar6,CONCAT11(cVar5,cVar17)))))));
        *(ulonglong *)(in_R10 + 2) =
             CONCAT17(cVar16,CONCAT16(cVar15,CONCAT15(cVar14,CONCAT14(cVar20,CONCAT13(cVar13,
                                                  CONCAT12(cVar12,CONCAT11(cVar11,cVar19)))))));
        in_R10 = in_R10 + 4;
        cVar17 = (char)param_1[4];
        cVar5 = *(char *)((longlong)param_1 + 0x11);
        cVar6 = *(char *)((longlong)param_1 + 0x12);
        cVar7 = *(char *)((longlong)param_1 + 0x13);
        cVar18 = (char)param_1[5];
        cVar8 = *(char *)((longlong)param_1 + 0x15);
        cVar9 = *(char *)((longlong)param_1 + 0x16);
        cVar10 = *(char *)((longlong)param_1 + 0x17);
        cVar19 = (char)param_1[6];
        cVar11 = *(char *)((longlong)param_1 + 0x19);
        cVar12 = *(char *)((longlong)param_1 + 0x1a);
        cVar13 = *(char *)((longlong)param_1 + 0x1b);
        cVar20 = (char)param_1[7];
        cVar14 = *(char *)((longlong)param_1 + 0x1d);
        cVar15 = *(char *)((longlong)param_1 + 0x1e);
        cVar16 = *(char *)((longlong)param_1 + 0x1f);
        auVar23[0] = -(cVar17 == '\0');
        auVar23[1] = -(cVar5 == '\0');
        auVar23[2] = -(cVar6 == '\0');
        auVar23[3] = -(cVar7 == '\0');
        auVar23[4] = -(cVar18 == '\0');
        auVar23[5] = -(cVar8 == '\0');
        auVar23[6] = -(cVar9 == '\0');
        auVar23[7] = -(cVar10 == '\0');
        auVar23[8] = -(cVar19 == '\0');
        auVar23[9] = -(SUB161((undefined1  [16])0x0,9) == cVar11);
        auVar23[10] = -(SUB161((undefined1  [16])0x0,10) == cVar12);
        auVar23[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar13);
        auVar23[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar20);
        auVar23[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar14);
        auVar23[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar15);
        auVar23[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar16);
        param_1 = param_1 + 4;
        uVar4 = (ushort)(SUB161(auVar23 >> 7,0) & 1) | (ushort)(SUB161(auVar23 >> 0xf,0) & 1) << 1 |
                (ushort)(SUB161(auVar23 >> 0x17,0) & 1) << 2 |
                (ushort)(SUB161(auVar23 >> 0x1f,0) & 1) << 3 |
                (ushort)(SUB161(auVar23 >> 0x27,0) & 1) << 4 |
                (ushort)(SUB161(auVar23 >> 0x2f,0) & 1) << 5 |
                (ushort)(SUB161(auVar23 >> 0x37,0) & 1) << 6 |
                (ushort)(SUB161(auVar23 >> 0x3f,0) & 1) << 7 |
                (ushort)(SUB161(auVar23 >> 0x47,0) & 1) << 8 |
                (ushort)(SUB161(auVar23 >> 0x4f,0) & 1) << 9 |
                (ushort)(SUB161(auVar23 >> 0x57,0) & 1) << 10 |
                (ushort)(SUB161(auVar23 >> 0x5f,0) & 1) << 0xb |
                (ushort)(SUB161(auVar23 >> 0x67,0) & 1) << 0xc |
                (ushort)(SUB161(auVar23 >> 0x6f,0) & 1) << 0xd |
                (ushort)(SUB161(auVar23 >> 0x77,0) & 1) << 0xe | (ushort)(auVar23[0xf] >> 7) << 0xf;
      }
      iVar3 = 0;
      if (uVar4 != 0) {
        for (; (uVar4 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
        }
      }
      uVar22 = iVar3 + 1;
      if ((uVar22 & 0xf) == 0) {
        *(ulonglong *)in_R10 =
             CONCAT17(cVar10,CONCAT16(cVar9,CONCAT15(cVar8,CONCAT14(cVar18,CONCAT13(cVar7,CONCAT12(
                                                  cVar6,CONCAT11(cVar5,cVar17)))))));
        *(ulonglong *)(in_R10 + 2) =
             CONCAT17(cVar16,CONCAT16(cVar15,CONCAT15(cVar14,CONCAT14(cVar20,CONCAT13(cVar13,
                                                  CONCAT12(cVar12,CONCAT11(cVar11,cVar19)))))));
        return;
      }
      if ((uVar22 & 8) != 0) {
        uVar2 = *(undefined8 *)param_1;
        param_1 = param_1 + 2;
        *(undefined8 *)in_R10 = uVar2;
        in_R10 = in_R10 + 2;
      }
      if ((uVar22 & 4) != 0) {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        *in_R10 = uVar1;
        in_R10 = in_R10 + 1;
      }
      if ((uVar22 & 2) != 0) {
        uVar1 = *param_1;
        param_1 = (uint *)((longlong)param_1 + 2);
        *(short *)in_R10 = (short)uVar1;
        in_R10 = (uint *)((longlong)in_R10 + 2);
      }
      if ((uVar22 & 1) != 0) {
        *(char *)in_R10 = (char)*param_1;
      }
      return;
    }
  } while( true );
}



void FUN_180008ce9(char *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  ushort uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  char cVar20;
  char cVar21;
  uint uVar22;
  char *in_R10;
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  
  cVar6 = *param_1;
  cVar7 = param_1[1];
  cVar8 = param_1[2];
  cVar9 = param_1[3];
  cVar10 = param_1[4];
  cVar11 = param_1[5];
  cVar12 = param_1[6];
  cVar13 = param_1[7];
  cVar14 = param_1[8];
  cVar15 = param_1[9];
  cVar16 = param_1[10];
  cVar17 = param_1[0xb];
  cVar18 = param_1[0xc];
  cVar19 = param_1[0xd];
  cVar20 = param_1[0xe];
  cVar21 = param_1[0xf];
  auVar24[0] = -(cVar6 == '\0');
  auVar24[1] = -(cVar7 == '\0');
  auVar24[2] = -(cVar8 == '\0');
  auVar24[3] = -(cVar9 == '\0');
  auVar24[4] = -(cVar10 == '\0');
  auVar24[5] = -(cVar11 == '\0');
  auVar24[6] = -(cVar12 == '\0');
  auVar24[7] = -(cVar13 == '\0');
  auVar24[8] = -(cVar14 == '\0');
  auVar24[9] = -(SUB161((undefined1  [16])0x0,9) == cVar15);
  auVar24[10] = -(SUB161((undefined1  [16])0x0,10) == cVar16);
  auVar24[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar17);
  auVar24[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar18);
  auVar24[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar19);
  auVar24[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar20);
  auVar24[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar21);
  uVar5 = (ushort)(SUB161(auVar24 >> 7,0) & 1) | (ushort)(SUB161(auVar24 >> 0xf,0) & 1) << 1 |
          (ushort)(SUB161(auVar24 >> 0x17,0) & 1) << 2 |
          (ushort)(SUB161(auVar24 >> 0x1f,0) & 1) << 3 |
          (ushort)(SUB161(auVar24 >> 0x27,0) & 1) << 4 |
          (ushort)(SUB161(auVar24 >> 0x2f,0) & 1) << 5 |
          (ushort)(SUB161(auVar24 >> 0x37,0) & 1) << 6 |
          (ushort)(SUB161(auVar24 >> 0x3f,0) & 1) << 7 |
          (ushort)(SUB161(auVar24 >> 0x47,0) & 1) << 8 |
          (ushort)(SUB161(auVar24 >> 0x4f,0) & 1) << 9 |
          (ushort)(SUB161(auVar24 >> 0x57,0) & 1) << 10 |
          (ushort)(SUB161(auVar24 >> 0x5f,0) & 1) << 0xb |
          (ushort)(SUB161(auVar24 >> 0x67,0) & 1) << 0xc |
          (ushort)(SUB161(auVar24 >> 0x6f,0) & 1) << 0xd |
          (ushort)(SUB161(auVar24 >> 0x77,0) & 1) << 0xe | (ushort)(auVar24[0xf] >> 7) << 0xf;
  while (uVar5 == 0) {
    *(ulonglong *)in_R10 =
         CONCAT17(cVar13,CONCAT16(cVar12,CONCAT15(cVar11,CONCAT14(cVar10,CONCAT13(cVar9,CONCAT12(
                                                  cVar8,CONCAT11(cVar7,cVar6)))))));
    *(ulonglong *)(in_R10 + 8) =
         CONCAT17(cVar21,CONCAT16(cVar20,CONCAT15(cVar19,CONCAT14(cVar18,CONCAT13(cVar17,CONCAT12(
                                                  cVar16,CONCAT11(cVar15,cVar14)))))));
    in_R10 = in_R10 + 0x10;
    cVar6 = param_1[0x10];
    cVar7 = param_1[0x11];
    cVar8 = param_1[0x12];
    cVar9 = param_1[0x13];
    cVar10 = param_1[0x14];
    cVar11 = param_1[0x15];
    cVar12 = param_1[0x16];
    cVar13 = param_1[0x17];
    cVar14 = param_1[0x18];
    cVar15 = param_1[0x19];
    cVar16 = param_1[0x1a];
    cVar17 = param_1[0x1b];
    cVar18 = param_1[0x1c];
    cVar19 = param_1[0x1d];
    cVar20 = param_1[0x1e];
    cVar21 = param_1[0x1f];
    auVar23[0] = -(cVar6 == '\0');
    auVar23[1] = -(cVar7 == '\0');
    auVar23[2] = -(cVar8 == '\0');
    auVar23[3] = -(cVar9 == '\0');
    auVar23[4] = -(cVar10 == '\0');
    auVar23[5] = -(cVar11 == '\0');
    auVar23[6] = -(cVar12 == '\0');
    auVar23[7] = -(cVar13 == '\0');
    auVar23[8] = -(cVar14 == '\0');
    auVar23[9] = -(SUB161((undefined1  [16])0x0,9) == cVar15);
    auVar23[10] = -(SUB161((undefined1  [16])0x0,10) == cVar16);
    auVar23[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar17);
    auVar23[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar18);
    auVar23[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar19);
    auVar23[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar20);
    auVar23[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar21);
    param_1 = param_1 + 0x10;
    uVar5 = (ushort)(SUB161(auVar23 >> 7,0) & 1) | (ushort)(SUB161(auVar23 >> 0xf,0) & 1) << 1 |
            (ushort)(SUB161(auVar23 >> 0x17,0) & 1) << 2 |
            (ushort)(SUB161(auVar23 >> 0x1f,0) & 1) << 3 |
            (ushort)(SUB161(auVar23 >> 0x27,0) & 1) << 4 |
            (ushort)(SUB161(auVar23 >> 0x2f,0) & 1) << 5 |
            (ushort)(SUB161(auVar23 >> 0x37,0) & 1) << 6 |
            (ushort)(SUB161(auVar23 >> 0x3f,0) & 1) << 7 |
            (ushort)(SUB161(auVar23 >> 0x47,0) & 1) << 8 |
            (ushort)(SUB161(auVar23 >> 0x4f,0) & 1) << 9 |
            (ushort)(SUB161(auVar23 >> 0x57,0) & 1) << 10 |
            (ushort)(SUB161(auVar23 >> 0x5f,0) & 1) << 0xb |
            (ushort)(SUB161(auVar23 >> 0x67,0) & 1) << 0xc |
            (ushort)(SUB161(auVar23 >> 0x6f,0) & 1) << 0xd |
            (ushort)(SUB161(auVar23 >> 0x77,0) & 1) << 0xe | (ushort)(auVar23[0xf] >> 7) << 0xf;
  }
  iVar4 = 0;
  if (uVar5 != 0) {
    for (; (uVar5 >> iVar4 & 1) == 0; iVar4 = iVar4 + 1) {
    }
  }
  uVar22 = iVar4 + 1;
  if ((uVar22 & 0xf) == 0) {
    *(ulonglong *)in_R10 =
         CONCAT17(cVar13,CONCAT16(cVar12,CONCAT15(cVar11,CONCAT14(cVar10,CONCAT13(cVar9,CONCAT12(
                                                  cVar8,CONCAT11(cVar7,cVar6)))))));
    *(ulonglong *)(in_R10 + 8) =
         CONCAT17(cVar21,CONCAT16(cVar20,CONCAT15(cVar19,CONCAT14(cVar18,CONCAT13(cVar17,CONCAT12(
                                                  cVar16,CONCAT11(cVar15,cVar14)))))));
    return;
  }
  if ((uVar22 & 8) != 0) {
    uVar3 = *(undefined8 *)param_1;
    param_1 = param_1 + 8;
    *(undefined8 *)in_R10 = uVar3;
    in_R10 = in_R10 + 8;
  }
  if ((uVar22 & 4) != 0) {
    uVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    *(undefined4 *)in_R10 = uVar2;
    in_R10 = in_R10 + 4;
  }
  if ((uVar22 & 2) != 0) {
    uVar1 = *(undefined2 *)param_1;
    param_1 = param_1 + 2;
    *(undefined2 *)in_R10 = uVar1;
    in_R10 = in_R10 + 2;
  }
  if ((uVar22 & 1) != 0) {
    *in_R10 = *param_1;
  }
  return;
}



void FUN_180008d03(char *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  ushort uVar5;
  char *pcVar6;
  uint uVar7;
  char *in_R10;
  char *pcVar8;
  undefined1 auVar9 [16];
  char local_res20;
  char cStackX_21;
  char cStackX_22;
  char cStackX_23;
  char cStackX_24;
  char cStackX_25;
  char cStackX_26;
  char cStackX_27;
  char in_stack_00000028;
  char in_stack_00000029;
  char in_stack_0000002a;
  char in_stack_0000002b;
  char in_stack_0000002c;
  char in_stack_0000002d;
  char in_stack_0000002e;
  char in_stack_0000002f;
  
  do {
    pcVar8 = in_R10;
    pcVar6 = param_1;
    param_1 = pcVar6 + 0x10;
    *(ulonglong *)pcVar8 =
         CONCAT17(cStackX_27,
                  CONCAT16(cStackX_26,
                           CONCAT15(cStackX_25,
                                    CONCAT14(cStackX_24,
                                             CONCAT13(cStackX_23,
                                                      CONCAT12(cStackX_22,
                                                               CONCAT11(cStackX_21,local_res20))))))
                 );
    *(ulonglong *)(pcVar8 + 8) =
         CONCAT17(in_stack_0000002f,
                  CONCAT16(in_stack_0000002e,
                           CONCAT15(in_stack_0000002d,
                                    CONCAT14(in_stack_0000002c,
                                             CONCAT13(in_stack_0000002b,
                                                      CONCAT12(in_stack_0000002a,
                                                               CONCAT11(in_stack_00000029,
                                                                        in_stack_00000028)))))));
    in_R10 = pcVar8 + 0x10;
    local_res20 = *param_1;
    cStackX_21 = pcVar6[0x11];
    cStackX_22 = pcVar6[0x12];
    cStackX_23 = pcVar6[0x13];
    cStackX_24 = pcVar6[0x14];
    cStackX_25 = pcVar6[0x15];
    cStackX_26 = pcVar6[0x16];
    cStackX_27 = pcVar6[0x17];
    in_stack_00000028 = pcVar6[0x18];
    in_stack_00000029 = pcVar6[0x19];
    in_stack_0000002a = pcVar6[0x1a];
    in_stack_0000002b = pcVar6[0x1b];
    in_stack_0000002c = pcVar6[0x1c];
    in_stack_0000002d = pcVar6[0x1d];
    in_stack_0000002e = pcVar6[0x1e];
    in_stack_0000002f = pcVar6[0x1f];
    uVar3 = *(undefined8 *)(pcVar6 + 0x18);
    auVar9[0] = -(local_res20 == '\0');
    auVar9[1] = -(cStackX_21 == '\0');
    auVar9[2] = -(cStackX_22 == '\0');
    auVar9[3] = -(cStackX_23 == '\0');
    auVar9[4] = -(cStackX_24 == '\0');
    auVar9[5] = -(cStackX_25 == '\0');
    auVar9[6] = -(cStackX_26 == '\0');
    auVar9[7] = -(cStackX_27 == '\0');
    auVar9[8] = -(in_stack_00000028 == '\0');
    auVar9[9] = -(SUB161((undefined1  [16])0x0,9) == in_stack_00000029);
    auVar9[10] = -(SUB161((undefined1  [16])0x0,10) == in_stack_0000002a);
    auVar9[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == in_stack_0000002b);
    auVar9[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == in_stack_0000002c);
    auVar9[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == in_stack_0000002d);
    auVar9[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == in_stack_0000002e);
    auVar9[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == in_stack_0000002f);
    uVar5 = (ushort)(SUB161(auVar9 >> 7,0) & 1) | (ushort)(SUB161(auVar9 >> 0xf,0) & 1) << 1 |
            (ushort)(SUB161(auVar9 >> 0x17,0) & 1) << 2 |
            (ushort)(SUB161(auVar9 >> 0x1f,0) & 1) << 3 |
            (ushort)(SUB161(auVar9 >> 0x27,0) & 1) << 4 |
            (ushort)(SUB161(auVar9 >> 0x2f,0) & 1) << 5 |
            (ushort)(SUB161(auVar9 >> 0x37,0) & 1) << 6 |
            (ushort)(SUB161(auVar9 >> 0x3f,0) & 1) << 7 |
            (ushort)(SUB161(auVar9 >> 0x47,0) & 1) << 8 |
            (ushort)(SUB161(auVar9 >> 0x4f,0) & 1) << 9 |
            (ushort)(SUB161(auVar9 >> 0x57,0) & 1) << 10 |
            (ushort)(SUB161(auVar9 >> 0x5f,0) & 1) << 0xb |
            (ushort)(SUB161(auVar9 >> 0x67,0) & 1) << 0xc |
            (ushort)(SUB161(auVar9 >> 0x6f,0) & 1) << 0xd |
            (ushort)(SUB161(auVar9 >> 0x77,0) & 1) << 0xe | (ushort)(auVar9[0xf] >> 7) << 0xf;
  } while (uVar5 == 0);
  iVar4 = 0;
  if (uVar5 != 0) {
    for (; (uVar5 >> iVar4 & 1) == 0; iVar4 = iVar4 + 1) {
    }
  }
  uVar7 = iVar4 + 1;
  if ((uVar7 & 0xf) == 0) {
    *(undefined8 *)in_R10 = *(undefined8 *)param_1;
    *(undefined8 *)(pcVar8 + 0x18) = uVar3;
    return;
  }
  if ((uVar7 & 8) != 0) {
    uVar3 = *(undefined8 *)param_1;
    param_1 = pcVar6 + 0x18;
    *(undefined8 *)in_R10 = uVar3;
    in_R10 = pcVar8 + 0x18;
  }
  if ((uVar7 & 4) != 0) {
    uVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    *(undefined4 *)in_R10 = uVar2;
    in_R10 = in_R10 + 4;
  }
  if ((uVar7 & 2) != 0) {
    uVar1 = *(undefined2 *)param_1;
    param_1 = param_1 + 2;
    *(undefined2 *)in_R10 = uVar1;
    in_R10 = in_R10 + 2;
  }
  if ((uVar7 & 1) != 0) {
    *in_R10 = *param_1;
  }
  return;
}



void FUN_180008d30(undefined8 *param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 *in_R10;
  undefined8 uStackX_20;
  
  iVar4 = 0;
  if (param_2 != 0) {
    for (; (param_2 >> iVar4 & 1) == 0; iVar4 = iVar4 + 1) {
    }
  }
  uVar5 = iVar4 + 1;
  if ((uVar5 & 0xf) == 0) {
    *in_R10 = uStackX_20;
    in_R10[1] = param_5;
    return;
  }
  if ((uVar5 & 8) != 0) {
    uVar3 = *param_1;
    param_1 = param_1 + 1;
    *in_R10 = uVar3;
    in_R10 = in_R10 + 1;
  }
  if ((uVar5 & 4) != 0) {
    uVar2 = *(undefined4 *)param_1;
    param_1 = (undefined8 *)((longlong)param_1 + 4);
    *(undefined4 *)in_R10 = uVar2;
    in_R10 = (undefined8 *)((longlong)in_R10 + 4);
  }
  if ((uVar5 & 2) != 0) {
    uVar1 = *(undefined2 *)param_1;
    param_1 = (undefined8 *)((longlong)param_1 + 2);
    *(undefined2 *)in_R10 = uVar1;
    in_R10 = (undefined8 *)((longlong)in_R10 + 2);
  }
  if ((uVar5 & 1) != 0) {
    *(undefined1 *)in_R10 = *(undefined1 *)param_1;
  }
  return;
}



void FUN_180008dc0(undefined8 param_1,uint *param_2)

{
  longlong lVar1;
  int iVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  uint *puVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  char cVar20;
  uint uVar21;
  ulonglong in_RAX;
  ulonglong uVar22;
  char *pcVar23;
  char *pcVar24;
  uint *puVar25;
  uint uVar26;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  
  pcVar23 = (char *)(in_RAX - (in_RAX & 0xf));
  auVar28[0] = -(*pcVar23 == '\0');
  auVar28[1] = -(pcVar23[1] == '\0');
  auVar28[2] = -(pcVar23[2] == '\0');
  auVar28[3] = -(pcVar23[3] == '\0');
  auVar28[4] = -(pcVar23[4] == '\0');
  auVar28[5] = -(pcVar23[5] == '\0');
  auVar28[6] = -(pcVar23[6] == '\0');
  auVar28[7] = -(pcVar23[7] == '\0');
  auVar28[8] = -(pcVar23[8] == '\0');
  auVar28[9] = -(pcVar23[9] == '\0');
  auVar28[10] = -(pcVar23[10] == '\0');
  auVar28[0xb] = -(pcVar23[0xb] == '\0');
  auVar28[0xc] = -(pcVar23[0xc] == '\0');
  auVar28[0xd] = -(pcVar23[0xd] == '\0');
  auVar28[0xe] = -(pcVar23[0xe] == '\0');
  auVar28[0xf] = -(pcVar23[0xf] == '\0');
  uVar3 = (ushort)((ushort)(SUB161(auVar28 >> 7,0) & 1) |
                   (ushort)(SUB161(auVar28 >> 0xf,0) & 1) << 1 |
                   (ushort)(SUB161(auVar28 >> 0x17,0) & 1) << 2 |
                   (ushort)(SUB161(auVar28 >> 0x1f,0) & 1) << 3 |
                   (ushort)(SUB161(auVar28 >> 0x27,0) & 1) << 4 |
                   (ushort)(SUB161(auVar28 >> 0x2f,0) & 1) << 5 |
                   (ushort)(SUB161(auVar28 >> 0x37,0) & 1) << 6 |
                   (ushort)(SUB161(auVar28 >> 0x3f,0) & 1) << 7 |
                   (ushort)(SUB161(auVar28 >> 0x47,0) & 1) << 8 |
                   (ushort)(SUB161(auVar28 >> 0x4f,0) & 1) << 9 |
                   (ushort)(SUB161(auVar28 >> 0x57,0) & 1) << 10 |
                   (ushort)(SUB161(auVar28 >> 0x5f,0) & 1) << 0xb |
                   (ushort)(SUB161(auVar28 >> 0x67,0) & 1) << 0xc |
                   (ushort)(SUB161(auVar28 >> 0x6f,0) & 1) << 0xd |
                   (ushort)(SUB161(auVar28 >> 0x77,0) & 1) << 0xe |
                  (ushort)(auVar28[0xf] >> 7) << 0xf) >> (sbyte)(in_RAX & 0xf);
  if (uVar3 == 0) {
    do {
      pcVar24 = pcVar23 + 0x10;
      auVar27[0] = -(*pcVar24 == '\0');
      auVar27[1] = -(pcVar23[0x11] == '\0');
      auVar27[2] = -(pcVar23[0x12] == '\0');
      auVar27[3] = -(pcVar23[0x13] == '\0');
      auVar27[4] = -(pcVar23[0x14] == '\0');
      auVar27[5] = -(pcVar23[0x15] == '\0');
      auVar27[6] = -(pcVar23[0x16] == '\0');
      auVar27[7] = -(pcVar23[0x17] == '\0');
      auVar27[8] = -(pcVar23[0x18] == '\0');
      auVar27[9] = -(pcVar23[0x19] == '\0');
      auVar27[10] = -(pcVar23[0x1a] == '\0');
      auVar27[0xb] = -(pcVar23[0x1b] == '\0');
      auVar27[0xc] = -(pcVar23[0x1c] == '\0');
      auVar27[0xd] = -(pcVar23[0x1d] == '\0');
      auVar27[0xe] = -(pcVar23[0x1e] == '\0');
      auVar27[0xf] = -(pcVar23[0x1f] == '\0');
      uVar3 = (ushort)(SUB161(auVar27 >> 7,0) & 1) | (ushort)(SUB161(auVar27 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar27 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar27 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar27 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar27 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar27 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar27 >> 0x3f,0) & 1) << 7 |
              (ushort)(SUB161(auVar27 >> 0x47,0) & 1) << 8 |
              (ushort)(SUB161(auVar27 >> 0x4f,0) & 1) << 9 |
              (ushort)(SUB161(auVar27 >> 0x57,0) & 1) << 10 |
              (ushort)(SUB161(auVar27 >> 0x5f,0) & 1) << 0xb |
              (ushort)(SUB161(auVar27 >> 0x67,0) & 1) << 0xc |
              (ushort)(SUB161(auVar27 >> 0x6f,0) & 1) << 0xd |
              (ushort)(SUB161(auVar27 >> 0x77,0) & 1) << 0xe | (ushort)(auVar27[0xf] >> 7) << 0xf;
      pcVar23 = pcVar24;
    } while (uVar3 == 0);
    iVar2 = 0;
    if (uVar3 != 0) {
      for (; (uVar3 >> iVar2 & 1) == 0; iVar2 = iVar2 + 1) {
      }
    }
    pcVar24 = pcVar24 + ((longlong)iVar2 - in_RAX);
  }
  else {
    iVar2 = 0;
    if (uVar3 != 0) {
      for (; (uVar3 >> iVar2 & 1) == 0; iVar2 = iVar2 + 1) {
      }
    }
    pcVar24 = (char *)(longlong)iVar2;
  }
  puVar25 = (uint *)(pcVar24 + in_RAX);
  while (((ulonglong)param_2 & 3) != 0) {
    uVar21 = *param_2;
    param_2 = (uint *)((longlong)param_2 + 1);
    *(char *)puVar25 = (char)uVar21;
    if ((char)uVar21 == '\0') {
      return;
    }
    puVar25 = (uint *)((longlong)puVar25 + 1);
  }
  uVar21 = *param_2;
  uVar26 = ~uVar21 ^ uVar21 + 0x7efefeff;
  do {
    puVar16 = param_2 + 1;
    if ((uVar26 & 0x81010100) != 0) {
      if ((char)uVar21 == '\0') {
        *(char *)puVar25 = '\0';
        return;
      }
      if ((uVar21 & 0xff00) == 0) {
        *(short *)puVar25 = (short)uVar21;
        return;
      }
      if ((uVar21 & 0xff0000) == 0) {
        *(short *)puVar25 = (short)uVar21;
        *(char *)((longlong)puVar25 + 2) = '\0';
        return;
      }
      if ((uVar21 & 0xff000000) == 0) {
        *puVar25 = uVar21;
        return;
      }
    }
    *puVar25 = uVar21;
    puVar25 = puVar25 + 1;
    if (((ulonglong)puVar16 & 0xf) == 0) {
      cVar17 = (char)*puVar16;
      cVar4 = *(char *)((longlong)param_2 + 5);
      cVar5 = *(char *)((longlong)param_2 + 6);
      cVar6 = *(char *)((longlong)param_2 + 7);
      cVar18 = (char)param_2[2];
      cVar7 = *(char *)((longlong)param_2 + 9);
      cVar8 = *(char *)((longlong)param_2 + 10);
      cVar9 = *(char *)((longlong)param_2 + 0xb);
      cVar19 = (char)param_2[3];
      cVar10 = *(char *)((longlong)param_2 + 0xd);
      cVar11 = *(char *)((longlong)param_2 + 0xe);
      cVar12 = *(char *)((longlong)param_2 + 0xf);
      cVar20 = (char)param_2[4];
      cVar13 = *(char *)((longlong)param_2 + 0x11);
      cVar14 = *(char *)((longlong)param_2 + 0x12);
      cVar15 = *(char *)((longlong)param_2 + 0x13);
      auVar29[0] = -(cVar17 == '\0');
      auVar29[1] = -(cVar4 == '\0');
      auVar29[2] = -(cVar5 == '\0');
      auVar29[3] = -(cVar6 == '\0');
      auVar29[4] = -(cVar18 == '\0');
      auVar29[5] = -(cVar7 == '\0');
      auVar29[6] = -(cVar8 == '\0');
      auVar29[7] = -(cVar9 == '\0');
      auVar29[8] = -(cVar19 == '\0');
      auVar29[9] = -(SUB161((undefined1  [16])0x0,9) == cVar10);
      auVar29[10] = -(SUB161((undefined1  [16])0x0,10) == cVar11);
      auVar29[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar12);
      auVar29[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar20);
      auVar29[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar13);
      auVar29[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar14);
      auVar29[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar15);
      uVar3 = (ushort)(SUB161(auVar29 >> 7,0) & 1) | (ushort)(SUB161(auVar29 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar29 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar29 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar29 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar29 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar29 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar29 >> 0x3f,0) & 1) << 7 |
              (ushort)(SUB161(auVar29 >> 0x47,0) & 1) << 8 |
              (ushort)(SUB161(auVar29 >> 0x4f,0) & 1) << 9 |
              (ushort)(SUB161(auVar29 >> 0x57,0) & 1) << 10 |
              (ushort)(SUB161(auVar29 >> 0x5f,0) & 1) << 0xb |
              (ushort)(SUB161(auVar29 >> 0x67,0) & 1) << 0xc |
              (ushort)(SUB161(auVar29 >> 0x6f,0) & 1) << 0xd |
              (ushort)(SUB161(auVar29 >> 0x77,0) & 1) << 0xe | (ushort)(auVar29[0xf] >> 7) << 0xf;
      while (uVar3 == 0) {
        *(char *)puVar25 = cVar17;
        *(char *)((longlong)puVar25 + 1) = cVar4;
        *(char *)((longlong)puVar25 + 2) = cVar5;
        *(char *)((longlong)puVar25 + 3) = cVar6;
        *(char *)(puVar25 + 1) = cVar18;
        *(char *)((longlong)puVar25 + 5) = cVar7;
        *(char *)((longlong)puVar25 + 6) = cVar8;
        *(char *)((longlong)puVar25 + 7) = cVar9;
        *(char *)(puVar25 + 2) = cVar19;
        *(char *)((longlong)puVar25 + 9) = cVar10;
        *(char *)((longlong)puVar25 + 10) = cVar11;
        *(char *)((longlong)puVar25 + 0xb) = cVar12;
        *(char *)(puVar25 + 3) = cVar20;
        *(char *)((longlong)puVar25 + 0xd) = cVar13;
        *(char *)((longlong)puVar25 + 0xe) = cVar14;
        *(char *)((longlong)puVar25 + 0xf) = cVar15;
        puVar25 = puVar25 + 4;
        cVar17 = (char)puVar16[4];
        cVar4 = *(char *)((longlong)puVar16 + 0x11);
        cVar5 = *(char *)((longlong)puVar16 + 0x12);
        cVar6 = *(char *)((longlong)puVar16 + 0x13);
        cVar18 = (char)puVar16[5];
        cVar7 = *(char *)((longlong)puVar16 + 0x15);
        cVar8 = *(char *)((longlong)puVar16 + 0x16);
        cVar9 = *(char *)((longlong)puVar16 + 0x17);
        cVar19 = (char)puVar16[6];
        cVar10 = *(char *)((longlong)puVar16 + 0x19);
        cVar11 = *(char *)((longlong)puVar16 + 0x1a);
        cVar12 = *(char *)((longlong)puVar16 + 0x1b);
        cVar20 = (char)puVar16[7];
        cVar13 = *(char *)((longlong)puVar16 + 0x1d);
        cVar14 = *(char *)((longlong)puVar16 + 0x1e);
        cVar15 = *(char *)((longlong)puVar16 + 0x1f);
        auVar30[0] = -(cVar17 == '\0');
        auVar30[1] = -(cVar4 == '\0');
        auVar30[2] = -(cVar5 == '\0');
        auVar30[3] = -(cVar6 == '\0');
        auVar30[4] = -(cVar18 == '\0');
        auVar30[5] = -(cVar7 == '\0');
        auVar30[6] = -(cVar8 == '\0');
        auVar30[7] = -(cVar9 == '\0');
        auVar30[8] = -(cVar19 == '\0');
        auVar30[9] = -(SUB161((undefined1  [16])0x0,9) == cVar10);
        auVar30[10] = -(SUB161((undefined1  [16])0x0,10) == cVar11);
        auVar30[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == cVar12);
        auVar30[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == cVar20);
        auVar30[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == cVar13);
        auVar30[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == cVar14);
        auVar30[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == cVar15);
        puVar16 = puVar16 + 4;
        uVar3 = (ushort)(SUB161(auVar30 >> 7,0) & 1) | (ushort)(SUB161(auVar30 >> 0xf,0) & 1) << 1 |
                (ushort)(SUB161(auVar30 >> 0x17,0) & 1) << 2 |
                (ushort)(SUB161(auVar30 >> 0x1f,0) & 1) << 3 |
                (ushort)(SUB161(auVar30 >> 0x27,0) & 1) << 4 |
                (ushort)(SUB161(auVar30 >> 0x2f,0) & 1) << 5 |
                (ushort)(SUB161(auVar30 >> 0x37,0) & 1) << 6 |
                (ushort)(SUB161(auVar30 >> 0x3f,0) & 1) << 7 |
                (ushort)(SUB161(auVar30 >> 0x47,0) & 1) << 8 |
                (ushort)(SUB161(auVar30 >> 0x4f,0) & 1) << 9 |
                (ushort)(SUB161(auVar30 >> 0x57,0) & 1) << 10 |
                (ushort)(SUB161(auVar30 >> 0x5f,0) & 1) << 0xb |
                (ushort)(SUB161(auVar30 >> 0x67,0) & 1) << 0xc |
                (ushort)(SUB161(auVar30 >> 0x6f,0) & 1) << 0xd |
                (ushort)(SUB161(auVar30 >> 0x77,0) & 1) << 0xe | (ushort)(auVar30[0xf] >> 7) << 0xf;
      }
      iVar2 = 0;
      if (uVar3 != 0) {
        for (; (uVar3 >> iVar2 & 1) == 0; iVar2 = iVar2 + 1) {
        }
      }
      uVar22 = (ulonglong)(iVar2 + 1U);
      if ((iVar2 + 1U & 0xf) == 0) {
        *(char *)puVar25 = cVar17;
        *(char *)((longlong)puVar25 + 1) = cVar4;
        *(char *)((longlong)puVar25 + 2) = cVar5;
        *(char *)((longlong)puVar25 + 3) = cVar6;
        *(char *)(puVar25 + 1) = cVar18;
        *(char *)((longlong)puVar25 + 5) = cVar7;
        *(char *)((longlong)puVar25 + 6) = cVar8;
        *(char *)((longlong)puVar25 + 7) = cVar9;
        *(char *)(puVar25 + 2) = cVar19;
        *(char *)((longlong)puVar25 + 9) = cVar10;
        *(char *)((longlong)puVar25 + 10) = cVar11;
        *(char *)((longlong)puVar25 + 0xb) = cVar12;
        *(char *)(puVar25 + 3) = cVar20;
        *(char *)((longlong)puVar25 + 0xd) = cVar13;
        *(char *)((longlong)puVar25 + 0xe) = cVar14;
        *(char *)((longlong)puVar25 + 0xf) = cVar15;
      }
      else {
        do {
          lVar1 = uVar22 - 4;
          uVar22 = uVar22 - 4;
          *(undefined4 *)(uVar22 + (longlong)puVar25) = *(undefined4 *)(lVar1 + (longlong)puVar16);
        } while (0 < (longlong)uVar22);
      }
      return;
    }
    uVar21 = *puVar16;
    uVar26 = ~uVar21 ^ uVar21 + 0x7efefeff;
    param_2 = puVar16;
  } while( true );
}



void FUN_180008ed6(undefined8 param_1,char *param_2)

{
  longlong lVar1;
  int iVar2;
  ushort uVar3;
  ulonglong uVar4;
  char *pcVar5;
  char *in_R10;
  char *pcVar6;
  char in_XMM0_Ba;
  char in_XMM0_Bb;
  char in_XMM0_Bc;
  char in_XMM0_Bd;
  char in_XMM0_Be;
  char in_XMM0_Bf;
  char in_XMM0_Bg;
  char in_XMM0_Bh;
  char in_XMM0_Bi;
  char in_XMM0_Bj;
  char in_XMM0_Bk;
  char in_XMM0_Bl;
  char in_XMM0_Bm;
  char in_XMM0_Bn;
  char in_XMM0_Bo;
  char in_XMM0_Bp;
  undefined1 auVar7 [16];
  
  do {
    pcVar6 = in_R10;
    pcVar5 = param_2 + 0x10;
    *pcVar6 = in_XMM0_Ba;
    pcVar6[1] = in_XMM0_Bb;
    pcVar6[2] = in_XMM0_Bc;
    pcVar6[3] = in_XMM0_Bd;
    pcVar6[4] = in_XMM0_Be;
    pcVar6[5] = in_XMM0_Bf;
    pcVar6[6] = in_XMM0_Bg;
    pcVar6[7] = in_XMM0_Bh;
    pcVar6[8] = in_XMM0_Bi;
    pcVar6[9] = in_XMM0_Bj;
    pcVar6[10] = in_XMM0_Bk;
    pcVar6[0xb] = in_XMM0_Bl;
    pcVar6[0xc] = in_XMM0_Bm;
    pcVar6[0xd] = in_XMM0_Bn;
    pcVar6[0xe] = in_XMM0_Bo;
    pcVar6[0xf] = in_XMM0_Bp;
    in_R10 = pcVar6 + 0x10;
    in_XMM0_Ba = *pcVar5;
    in_XMM0_Bb = param_2[0x11];
    in_XMM0_Bc = param_2[0x12];
    in_XMM0_Bd = param_2[0x13];
    in_XMM0_Be = param_2[0x14];
    in_XMM0_Bf = param_2[0x15];
    in_XMM0_Bg = param_2[0x16];
    in_XMM0_Bh = param_2[0x17];
    in_XMM0_Bi = param_2[0x18];
    in_XMM0_Bj = param_2[0x19];
    in_XMM0_Bk = param_2[0x1a];
    in_XMM0_Bl = param_2[0x1b];
    in_XMM0_Bm = param_2[0x1c];
    in_XMM0_Bn = param_2[0x1d];
    in_XMM0_Bo = param_2[0x1e];
    in_XMM0_Bp = param_2[0x1f];
    auVar7[0] = -(in_XMM0_Ba == '\0');
    auVar7[1] = -(in_XMM0_Bb == '\0');
    auVar7[2] = -(in_XMM0_Bc == '\0');
    auVar7[3] = -(in_XMM0_Bd == '\0');
    auVar7[4] = -(in_XMM0_Be == '\0');
    auVar7[5] = -(in_XMM0_Bf == '\0');
    auVar7[6] = -(in_XMM0_Bg == '\0');
    auVar7[7] = -(in_XMM0_Bh == '\0');
    auVar7[8] = -(in_XMM0_Bi == '\0');
    auVar7[9] = -(SUB161((undefined1  [16])0x0,9) == in_XMM0_Bj);
    auVar7[10] = -(SUB161((undefined1  [16])0x0,10) == in_XMM0_Bk);
    auVar7[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == in_XMM0_Bl);
    auVar7[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == in_XMM0_Bm);
    auVar7[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == in_XMM0_Bn);
    auVar7[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == in_XMM0_Bo);
    auVar7[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == in_XMM0_Bp);
    uVar3 = (ushort)(SUB161(auVar7 >> 7,0) & 1) | (ushort)(SUB161(auVar7 >> 0xf,0) & 1) << 1 |
            (ushort)(SUB161(auVar7 >> 0x17,0) & 1) << 2 |
            (ushort)(SUB161(auVar7 >> 0x1f,0) & 1) << 3 |
            (ushort)(SUB161(auVar7 >> 0x27,0) & 1) << 4 |
            (ushort)(SUB161(auVar7 >> 0x2f,0) & 1) << 5 |
            (ushort)(SUB161(auVar7 >> 0x37,0) & 1) << 6 |
            (ushort)(SUB161(auVar7 >> 0x3f,0) & 1) << 7 |
            (ushort)(SUB161(auVar7 >> 0x47,0) & 1) << 8 |
            (ushort)(SUB161(auVar7 >> 0x4f,0) & 1) << 9 |
            (ushort)(SUB161(auVar7 >> 0x57,0) & 1) << 10 |
            (ushort)(SUB161(auVar7 >> 0x5f,0) & 1) << 0xb |
            (ushort)(SUB161(auVar7 >> 0x67,0) & 1) << 0xc |
            (ushort)(SUB161(auVar7 >> 0x6f,0) & 1) << 0xd |
            (ushort)(SUB161(auVar7 >> 0x77,0) & 1) << 0xe | (ushort)(auVar7[0xf] >> 7) << 0xf;
    param_2 = pcVar5;
  } while (uVar3 == 0);
  iVar2 = 0;
  if (uVar3 != 0) {
    for (; (uVar3 >> iVar2 & 1) == 0; iVar2 = iVar2 + 1) {
    }
  }
  uVar4 = (ulonglong)(iVar2 + 1U);
  if ((iVar2 + 1U & 0xf) == 0) {
    *in_R10 = in_XMM0_Ba;
    pcVar6[0x11] = in_XMM0_Bb;
    pcVar6[0x12] = in_XMM0_Bc;
    pcVar6[0x13] = in_XMM0_Bd;
    pcVar6[0x14] = in_XMM0_Be;
    pcVar6[0x15] = in_XMM0_Bf;
    pcVar6[0x16] = in_XMM0_Bg;
    pcVar6[0x17] = in_XMM0_Bh;
    pcVar6[0x18] = in_XMM0_Bi;
    pcVar6[0x19] = in_XMM0_Bj;
    pcVar6[0x1a] = in_XMM0_Bk;
    pcVar6[0x1b] = in_XMM0_Bl;
    pcVar6[0x1c] = in_XMM0_Bm;
    pcVar6[0x1d] = in_XMM0_Bn;
    pcVar6[0x1e] = in_XMM0_Bo;
    pcVar6[0x1f] = in_XMM0_Bp;
  }
  else {
    do {
      lVar1 = uVar4 - 4;
      uVar4 = uVar4 - 4;
      *(undefined4 *)(in_R10 + uVar4) = *(undefined4 *)(pcVar5 + lVar1);
    } while (0 < (longlong)uVar4);
  }
  return;
}



void FUN_180008f05(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  uint in_ECX;
  ulonglong uVar3;
  undefined8 *in_R10;
  undefined8 in_XMM0_Qb;
  
  iVar2 = 0;
  if (in_ECX != 0) {
    for (; (in_ECX >> iVar2 & 1) == 0; iVar2 = iVar2 + 1) {
    }
  }
  uVar3 = (ulonglong)(iVar2 + 1U);
  if ((iVar2 + 1U & 0xf) == 0) {
    *in_R10 = param_1;
    in_R10[1] = in_XMM0_Qb;
  }
  else {
    do {
      lVar1 = uVar3 - 4;
      uVar3 = uVar3 - 4;
      *(undefined4 *)(uVar3 + (longlong)in_R10) = *(undefined4 *)(lVar1 + param_2);
    } while (0 < (longlong)uVar3);
  }
  return;
}



undefined8 FUN_180008f60(void)

{
  undefined8 in_RAX;
  
  FUN_180008f80();
  return in_RAX;
}



// WARNING: Removing unreachable block (ram,0x000180009231)
// WARNING: Removing unreachable block (ram,0x0001800091bc)
// WARNING: Removing unreachable block (ram,0x0001800091ab)
// WARNING: Removing unreachable block (ram,0x0001800090df)
// WARNING: Removing unreachable block (ram,0x00018000900e)
// WARNING: Removing unreachable block (ram,0x000180008fc7)
// WARNING: Removing unreachable block (ram,0x000180008f9b)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180008f80(void)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  int in_EAX;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  uint in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  if ((*piVar1 == 0) ||
     ((in_EAX == 1 &&
      (((piVar1[1] != 0x756e6547 || (piVar1[2] != 0x49656e69)) || (piVar1[3] != 0x6c65746e)))))) {
    DAT_180019408 = 1;
    return;
  }
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar9 = puVar2[2];
  uVar3 = puVar2[3];
  lVar7 = (ulonglong)((uVar9 & 0x8000) >> 0xd) + 1 + (ulonglong)(uVar9 & 1) * 2;
  if ((uVar9 & 0x800000) != 0) {
    lVar7 = lVar7 + 8;
  }
  if ((uVar9 & 0x1000000) == 0) {
    lVar10 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar9 = *(uint *)(lVar10 + 4);
    uVar12 = *(uint *)(lVar10 + 8);
    uVar11 = *(uint *)(lVar10 + 0xc);
    uVar8 = lVar7 + (ulonglong)((uVar3 & 0x40000000) >> 0xd);
  }
  else {
    lVar10 = lVar7 + 0x10;
    if ((uVar9 & 0x2000000) != 0) {
      lVar10 = lVar7 + 0x30;
    }
    if ((uVar3 & 1) != 0) {
      lVar10 = lVar10 + 0x80;
    }
    uVar8 = (ulonglong)((uVar9 & 0x4000000) >> 0x14) + lVar10 | (ulonglong)((uVar3 & 0x200) >> 1);
    if ((uVar3 & 0x400000) != 0) {
      uVar8 = uVar8 | 0x800;
    }
    uVar8 = uVar8 | (uVar3 & 0x80000) >> 10;
    if ((uVar3 & 0x100000) != 0) {
      uVar8 = uVar8 | 0x400;
    }
    uVar8 = uVar8 | (uVar3 & 0x800000) >> 0xb;
    if ((uVar3 & 2) != 0) {
      uVar8 = uVar8 | 0x2000;
    }
    uVar8 = uVar8 | (uVar3 & 0x2000000) >> 0xb;
    lVar7 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar9 = *(uint *)(lVar7 + 4);
    uVar12 = *(uint *)(lVar7 + 8);
    uVar11 = *(uint *)(lVar7 + 0xc);
    if ((uVar9 & 0x20000000) != 0) {
      uVar8 = uVar8 | 0x800000000;
    }
    uVar8 = uVar8 | (uVar3 & 0x40000000) >> 0xd;
  }
  if ((uVar9 & 0x108) == 0x108) {
    uVar8 = uVar8 | 0x80000;
  }
  uVar8 = (ulonglong)(uVar9 & 4) << 0x33 | uVar8;
  if ((uVar9 & 0x10) != 0) {
    uVar8 = uVar8 | 0x200000;
  }
  uVar8 = uVar8 | (ulonglong)(uVar9 & 0x800) << 0xb;
  if ((uVar9 & 0x80000) != 0) {
    uVar8 = uVar8 | 0x10000000;
  }
  uVar8 = uVar8 | (ulonglong)(uVar9 & 0x40000) << 0xb;
  if ((uVar9 & 0x1000000) != 0) {
    uVar8 = uVar8 | 0x2000000000000;
  }
  lVar7 = cpuid(0x80000001);
  uVar8 = uVar8 | (ulonglong)(*(uint *)(lVar7 + 0xc) & 0x20) << 0xf;
  lVar7 = cpuid(0x80000008);
  if ((*(uint *)(lVar7 + 4) & 0x200) != 0) {
    uVar8 = uVar8 | 0x40000000000000;
  }
  uVar8 = (ulonglong)(uVar11 & 0x100) << 0x25 | uVar8;
  if ((uVar11 & 0x400000) != 0) {
    uVar8 = uVar8 | 0x4000000000000;
  }
  uVar8 = (ulonglong)(uVar11 & 0x80) << 0x2d | uVar8;
  if ((uVar12 & 0x100000) != 0) {
    uVar8 = uVar8 | 0x8000000000000;
  }
  uVar8 = (ulonglong)(uVar12 & 0x40000) << 0x25 | uVar8;
  lVar7 = cpuid(0x14);
  if ((*(uint *)(lVar7 + 4) & 0x10) != 0) {
    uVar8 = uVar8 | 0x2000000;
  }
  _DAT_180019410 = uVar8;
  if ((uVar3 & 0x8000000) != 0) {
    uVar4 = xinuse(0);
    uVar5 = in_XCR0 & (uint)uVar4;
    _DAT_180019410 = uVar8 | 1;
    if ((uVar5 & 6) == 6) {
      if ((uVar3 & 0x10000000) != 0) {
        _DAT_180019410 = uVar8 | 0x10001;
        if ((uVar11 & 0x200) != 0) {
          _DAT_180019410 = uVar8 | 0x400000010001;
        }
        _DAT_180019410 = _DAT_180019410 | (ulonglong)(uVar11 & 0x400) << 0x25;
      }
      if ((uVar3 & 0x20000000) != 0) {
        _DAT_180019410 = _DAT_180019410 | 0x8000;
      }
      uVar8 = _DAT_180019410 | (ulonglong)(uVar9 & 0x20) << 0x12;
      if ((uVar3 & 0x1000) != 0) {
        uVar8 = uVar8 | 0x40000;
      }
      _DAT_180019410 = uVar8;
      if ((uVar5 & 0x18) == 0x18) {
        _DAT_180019410 = uVar8 | 1;
        if ((uVar9 & 0x4000) != 0) {
          _DAT_180019410 = uVar8 | 0x1000000001;
        }
      }
      if ((uVar5 & 0xe0) == 0xe0) {
        uVar8 = _DAT_180019410 | 1;
        if ((uVar9 & 0x10000) != 0) {
          uVar8 = _DAT_180019410 | 0x8000001;
        }
        uVar8 = (ulonglong)(uVar9 & 0x10000000) << 6 | uVar8;
        if ((uVar9 & 0x8000000) != 0) {
          uVar8 = uVar8 | 0x100000000;
        }
        uVar8 = (ulonglong)(uVar9 & 0x4000000) << 7 | uVar8;
        if ((uVar9 & 0x20000) != 0) {
          uVar8 = uVar8 | 0x1000000;
        }
        uVar8 = (ulonglong)(uVar9 & 0x40000000) << 7 | uVar8;
        if ((uVar9 & 0x80000000) == 0x80000000) {
          uVar8 = uVar8 | 0x4000000000;
        }
        uVar8 = uVar8 | (ulonglong)(uVar9 & 0x200000) << 9;
        if ((uVar11 & 2) != 0) {
          uVar8 = uVar8 | 0x8000000000;
        }
        uVar8 = (ulonglong)(uVar11 & 0x4000) << 0x1c | uVar8;
        if ((uVar12 & 4) != 0) {
          uVar8 = uVar8 | 0x20000000000;
        }
        uVar8 = (ulonglong)(uVar12 & 8) << 0x25 | uVar8;
        if ((uVar11 & 0x1000) != 0) {
          uVar8 = uVar8 | 0x80000000000;
        }
        _DAT_180019410 = (ulonglong)(uVar11 & 0x40) << 0x26 | uVar8;
        if ((uVar11 & 0x800) != 0) {
          _DAT_180019410 = _DAT_180019410 | 0x1000000000000;
        }
      }
    }
  }
  iVar6 = (*puVar2 >> 0xc & 0xf0) + (*puVar2 >> 4 & 0xf);
  if (((iVar6 == 0x1c) || (iVar6 == 0x26)) || (iVar6 == 0x27)) {
    _DAT_180019410 = _DAT_180019410 | 0x80000000;
  }
  if (in_EAX == 1) {
    DAT_180019408 = _DAT_180019410;
    return;
  }
  return;
}



void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



undefined8 * thunk_FUN_1800096d0(undefined8 *param_1,undefined8 *param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  
  puVar1 = FUN_1800096d0(param_1,param_2,param_3);
  return puVar1;
}



void thunk_FUN_18000a780(undefined1 (*param_1) [32],undefined1 (*param_2) [32],ulonglong param_3)

{
  FUN_18000a780(param_1,param_2,param_3);
  return;
}



void thunk_FUN_18000c040(undefined1 (*param_1) [64],undefined1 (*param_2) [64],ulonglong param_3)

{
  FUN_18000c040(param_1,param_2,param_3);
  return;
}



void FUN_180009540(undefined1 (*param_1) [64],undefined1 (*param_2) [64],size_t param_3)

{
  ulonglong uVar1;
  
  uVar1 = 0x7189d97ff;
  while( true ) {
    if ((CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408) & uVar1) == uVar1) {
      thunk_FUN_18000c040(param_1,param_2,param_3);
      return;
    }
    if (((uint)DAT_180019408 & 0x9d97ff) == 0x9d97ff) {
      thunk_FUN_18000a780((undefined1 (*) [32])param_1,(undefined1 (*) [32])param_2,param_3);
      return;
    }
    if (((byte)DAT_180019408 & 0x7f) == 0x7f) {
      thunk_FUN_1800096d0((undefined8 *)param_1,(undefined8 *)param_2,param_3);
      return;
    }
    if (((uint)DAT_180019408 & 1) != 0) break;
    FUN_180008f60();
  }
  memcpy(param_1,param_2,param_3);
  return;
}



void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



byte * thunk_FUN_18000db80(byte *param_1,byte param_2,longlong param_3)

{
  byte *pbVar1;
  
  pbVar1 = FUN_18000db80(param_1,param_2,param_3);
  return pbVar1;
}



undefined1 (*) [32]
thunk_FUN_18000e580(undefined1 (*param_1) [32],ulonglong param_2,ulonglong param_3)

{
  undefined1 (*pauVar1) [32];
  
  pauVar1 = FUN_18000e580(param_1,param_2,param_3);
  return pauVar1;
}



undefined1 (*) [64]
thunk_FUN_18000f5c0(undefined1 (*param_1) [64],ulonglong param_2,ulonglong param_3)

{
  undefined1 (*pauVar1) [64];
  
  pauVar1 = FUN_18000f5c0(param_1,param_2,param_3);
  return pauVar1;
}



void FUN_180009600(undefined1 (*param_1) [64],ulonglong param_2,size_t param_3)

{
  ulonglong uVar1;
  
  uVar1 = 0x7189d97ff;
  while( true ) {
    if ((CONCAT44(DAT_180019408._4_4_,(uint)DAT_180019408) & uVar1) == uVar1) {
      thunk_FUN_18000f5c0(param_1,param_2,param_3);
      return;
    }
    if (((uint)DAT_180019408 & 0x9d97ff) == 0x9d97ff) {
      thunk_FUN_18000e580((undefined1 (*) [32])param_1,param_2,param_3);
      return;
    }
    if (((byte)DAT_180019408 & 0x7f) == 0x7f) {
      thunk_FUN_18000db80((byte *)param_1,(byte)param_2,param_3);
      return;
    }
    if (((uint)DAT_180019408 & 1) != 0) break;
    FUN_180008f60();
  }
  memset(param_1,(int)param_2,param_3);
  return;
}



char * FUN_180009680(void)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  char *in_RAX;
  char *pcVar4;
  undefined1 auVar5 [16];
  char in_XMM1_Ba;
  char in_XMM1_Bb;
  char in_XMM1_Bc;
  char in_XMM1_Bd;
  char in_XMM1_Be;
  char in_XMM1_Bf;
  char in_XMM1_Bg;
  char in_XMM1_Bh;
  char in_XMM1_Bi;
  char in_XMM1_Bj;
  char in_XMM1_Bk;
  char in_XMM1_Bl;
  char in_XMM1_Bm;
  char in_XMM1_Bn;
  char in_XMM1_Bo;
  char in_XMM1_Bp;
  undefined1 auVar6 [16];
  
  while( true ) {
    pcVar4 = in_RAX + 0x10;
    auVar5[0] = -(*pcVar4 == '\0');
    auVar5[1] = -(in_RAX[0x11] == '\0');
    auVar5[2] = -(in_RAX[0x12] == '\0');
    auVar5[3] = -(in_RAX[0x13] == '\0');
    auVar5[4] = -(in_RAX[0x14] == '\0');
    auVar5[5] = -(in_RAX[0x15] == '\0');
    auVar5[6] = -(in_RAX[0x16] == '\0');
    auVar5[7] = -(in_RAX[0x17] == '\0');
    auVar5[8] = -(in_RAX[0x18] == '\0');
    auVar5[9] = -(SUB161((undefined1  [16])0x0,9) == in_RAX[0x19]);
    auVar5[10] = -(SUB161((undefined1  [16])0x0,10) == in_RAX[0x1a]);
    auVar5[0xb] = -(SUB161((undefined1  [16])0x0,0xb) == in_RAX[0x1b]);
    auVar5[0xc] = -(SUB161((undefined1  [16])0x0,0xc) == in_RAX[0x1c]);
    auVar5[0xd] = -(SUB161((undefined1  [16])0x0,0xd) == in_RAX[0x1d]);
    auVar5[0xe] = -(SUB161((undefined1  [16])0x0,0xe) == in_RAX[0x1e]);
    auVar5[0xf] = -(SUB161((undefined1  [16])0x0,0xf) == in_RAX[0x1f]);
    auVar6[0] = -(*pcVar4 == in_XMM1_Ba);
    auVar6[1] = -(in_RAX[0x11] == in_XMM1_Bb);
    auVar6[2] = -(in_RAX[0x12] == in_XMM1_Bc);
    auVar6[3] = -(in_RAX[0x13] == in_XMM1_Bd);
    auVar6[4] = -(in_RAX[0x14] == in_XMM1_Be);
    auVar6[5] = -(in_RAX[0x15] == in_XMM1_Bf);
    auVar6[6] = -(in_RAX[0x16] == in_XMM1_Bg);
    auVar6[7] = -(in_RAX[0x17] == in_XMM1_Bh);
    auVar6[8] = -(in_RAX[0x18] == in_XMM1_Bi);
    auVar6[9] = -(in_RAX[0x19] == in_XMM1_Bj);
    auVar6[10] = -(in_RAX[0x1a] == in_XMM1_Bk);
    auVar6[0xb] = -(in_RAX[0x1b] == in_XMM1_Bl);
    auVar6[0xc] = -(in_RAX[0x1c] == in_XMM1_Bm);
    auVar6[0xd] = -(in_RAX[0x1d] == in_XMM1_Bn);
    auVar6[0xe] = -(in_RAX[0x1e] == in_XMM1_Bo);
    auVar6[0xf] = -(in_RAX[0x1f] == in_XMM1_Bp);
    uVar3 = (ushort)(SUB161(auVar6 >> 7,0) & 1) | (ushort)(SUB161(auVar6 >> 0xf,0) & 1) << 1 |
            (ushort)(SUB161(auVar6 >> 0x17,0) & 1) << 2 |
            (ushort)(SUB161(auVar6 >> 0x1f,0) & 1) << 3 |
            (ushort)(SUB161(auVar6 >> 0x27,0) & 1) << 4 |
            (ushort)(SUB161(auVar6 >> 0x2f,0) & 1) << 5 |
            (ushort)(SUB161(auVar6 >> 0x37,0) & 1) << 6 |
            (ushort)(SUB161(auVar6 >> 0x3f,0) & 1) << 7 |
            (ushort)(SUB161(auVar6 >> 0x47,0) & 1) << 8 |
            (ushort)(SUB161(auVar6 >> 0x4f,0) & 1) << 9 |
            (ushort)(SUB161(auVar6 >> 0x57,0) & 1) << 10 |
            (ushort)(SUB161(auVar6 >> 0x5f,0) & 1) << 0xb |
            (ushort)(SUB161(auVar6 >> 0x67,0) & 1) << 0xc |
            (ushort)(SUB161(auVar6 >> 0x6f,0) & 1) << 0xd |
            (ushort)(SUB161(auVar6 >> 0x77,0) & 1) << 0xe | (ushort)(auVar6[0xf] >> 7) << 0xf;
    if (uVar3 != 0) break;
    in_RAX = pcVar4;
    if ((((((((((((((((SUB161(auVar5 >> 7,0) & 1) != 0 || (SUB161(auVar5 >> 0xf,0) & 1) != 0) ||
                    (SUB161(auVar5 >> 0x17,0) & 1) != 0) || (SUB161(auVar5 >> 0x1f,0) & 1) != 0) ||
                  (SUB161(auVar5 >> 0x27,0) & 1) != 0) || (SUB161(auVar5 >> 0x2f,0) & 1) != 0) ||
                (SUB161(auVar5 >> 0x37,0) & 1) != 0) || (SUB161(auVar5 >> 0x3f,0) & 1) != 0) ||
              (SUB161(auVar5 >> 0x47,0) & 1) != 0) || (SUB161(auVar5 >> 0x4f,0) & 1) != 0) ||
            (SUB161(auVar5 >> 0x57,0) & 1) != 0) || (SUB161(auVar5 >> 0x5f,0) & 1) != 0) ||
          (SUB161(auVar5 >> 0x67,0) & 1) != 0) || (SUB161(auVar5 >> 0x6f,0) & 1) != 0) ||
        (SUB161(auVar5 >> 0x77,0) & 1) != 0) || (char)auVar5[0xf] < '\0') {
      return (char *)0x0;
    }
  }
  uVar1 = 0;
  if (uVar3 != 0) {
    for (; (uVar3 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
    }
  }
  uVar3 = (ushort)(SUB161(auVar5 >> 7,0) & 1) | (ushort)(SUB161(auVar5 >> 0xf,0) & 1) << 1 |
          (ushort)(SUB161(auVar5 >> 0x17,0) & 1) << 2 | (ushort)(SUB161(auVar5 >> 0x1f,0) & 1) << 3
          | (ushort)(SUB161(auVar5 >> 0x27,0) & 1) << 4 |
          (ushort)(SUB161(auVar5 >> 0x2f,0) & 1) << 5 | (ushort)(SUB161(auVar5 >> 0x37,0) & 1) << 6
          | (ushort)(SUB161(auVar5 >> 0x3f,0) & 1) << 7 |
          (ushort)(SUB161(auVar5 >> 0x47,0) & 1) << 8 | (ushort)(SUB161(auVar5 >> 0x4f,0) & 1) << 9
          | (ushort)(SUB161(auVar5 >> 0x57,0) & 1) << 10 |
          (ushort)(SUB161(auVar5 >> 0x5f,0) & 1) << 0xb |
          (ushort)(SUB161(auVar5 >> 0x67,0) & 1) << 0xc |
          (ushort)(SUB161(auVar5 >> 0x6f,0) & 1) << 0xd |
          (ushort)(SUB161(auVar5 >> 0x77,0) & 1) << 0xe | (ushort)(auVar5[0xf] >> 7) << 0xf;
  if (uVar3 != 0) {
    uVar2 = 0;
    if (uVar3 != 0) {
      for (; (uVar3 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
      }
    }
    if (uVar2 < uVar1) {
      return (char *)0x0;
    }
  }
  return pcVar4 + uVar1;
}



// WARNING: Removing unreachable block (ram,0x00018000a4bd)
// WARNING: Removing unreachable block (ram,0x00018000a0fd)
// WARNING: Removing unreachable block (ram,0x00018000a0eb)
// WARNING: Removing unreachable block (ram,0x00018000a18b)
// WARNING: Removing unreachable block (ram,0x00018000a19d)
// WARNING: Removing unreachable block (ram,0x00018000a28d)
// WARNING: Removing unreachable block (ram,0x00018000a27b)
// WARNING: Removing unreachable block (ram,0x00018000a31b)
// WARNING: Removing unreachable block (ram,0x00018000a32d)
// WARNING: Removing unreachable block (ram,0x00018000a41d)
// WARNING: Removing unreachable block (ram,0x00018000a40b)
// WARNING: Removing unreachable block (ram,0x00018000a45b)
// WARNING: Removing unreachable block (ram,0x00018000a46d)
// WARNING: Removing unreachable block (ram,0x00018000a3bb)
// WARNING: Removing unreachable block (ram,0x00018000a3cd)
// WARNING: Removing unreachable block (ram,0x00018000a2dd)
// WARNING: Removing unreachable block (ram,0x00018000a2cb)
// WARNING: Removing unreachable block (ram,0x00018000a22b)
// WARNING: Removing unreachable block (ram,0x00018000a23d)
// WARNING: Removing unreachable block (ram,0x00018000a14d)
// WARNING: Removing unreachable block (ram,0x00018000a13b)
// WARNING: Removing unreachable block (ram,0x00018000a09b)
// WARNING: Removing unreachable block (ram,0x00018000a0ad)
// WARNING: Removing unreachable block (ram,0x00018000a4ab)
// WARNING: Removing unreachable block (ram,0x00018000a061)
// WARNING: Removing unreachable block (ram,0x00018000a04b)
// WARNING: Removing unreachable block (ram,0x00018000a1db)
// WARNING: Removing unreachable block (ram,0x00018000a37d)
// WARNING: Removing unreachable block (ram,0x00018000a36b)
// WARNING: Removing unreachable block (ram,0x00018000a1ed)

undefined8 * FUN_1800096d0(undefined8 *param_1,undefined8 *param_2,ulonglong param_3)

{
  undefined1 (*pauVar1) [16];
  undefined8 *puVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 *puVar25;
  longlong lVar26;
  undefined1 (*pauVar27) [16];
  longlong lVar28;
  undefined1 (*pauVar29) [16];
  ulonglong uVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  
  puVar25 = param_1;
  if (param_3 == 1) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    return puVar25;
  }
  if ((longlong)param_3 < 9) {
    lVar26 = (longlong)param_1 + param_3;
    lVar28 = (longlong)param_2 + param_3;
    switch(param_3) {
    case 0:
      goto switchD_1800096f3_caseD_0;
    case 1:
      goto switchD_1800096f3_caseD_1;
    case 2:
      goto switchD_1800096f3_caseD_2;
    case 3:
      goto switchD_1800096f3_caseD_3;
    case 4:
      goto switchD_1800096f3_caseD_4;
    case 5:
      goto switchD_1800096f3_caseD_5;
    case 6:
      goto switchD_1800096f3_caseD_6;
    case 7:
      goto switchD_1800096f3_caseD_7;
    }
  }
  else {
    switch((ulonglong)param_1 & 7) {
    case 1:
      uVar6 = *(undefined2 *)((longlong)param_2 + 1);
      uVar7 = *(undefined4 *)((longlong)param_2 + 3);
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      *(undefined2 *)((longlong)param_1 + 1) = uVar6;
      *(undefined4 *)((longlong)param_1 + 3) = uVar7;
      param_3 = param_3 - 7;
      param_1 = (undefined8 *)((longlong)param_1 + 7);
      param_2 = (undefined8 *)((longlong)param_2 + 7);
      break;
    case 2:
      uVar7 = *(undefined4 *)((longlong)param_2 + 2);
      *(undefined2 *)param_1 = *(undefined2 *)param_2;
      *(undefined4 *)((longlong)param_1 + 2) = uVar7;
      param_3 = param_3 - 6;
      param_1 = (undefined8 *)((longlong)param_1 + 6);
      param_2 = (undefined8 *)((longlong)param_2 + 6);
      break;
    case 3:
      uVar7 = *(undefined4 *)((longlong)param_2 + 1);
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      *(undefined4 *)((longlong)param_1 + 1) = uVar7;
      param_3 = param_3 - 5;
      param_1 = (undefined8 *)((longlong)param_1 + 5);
      param_2 = (undefined8 *)((longlong)param_2 + 5);
      break;
    case 4:
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
      param_3 = param_3 - 4;
      param_1 = (undefined8 *)((longlong)param_1 + 4);
      param_2 = (undefined8 *)((longlong)param_2 + 4);
      break;
    case 5:
      uVar6 = *(undefined2 *)((longlong)param_2 + 1);
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      *(undefined2 *)((longlong)param_1 + 1) = uVar6;
      param_3 = param_3 - 3;
      param_1 = (undefined8 *)((longlong)param_1 + 3);
      param_2 = (undefined8 *)((longlong)param_2 + 3);
      break;
    case 6:
      *(undefined2 *)param_1 = *(undefined2 *)param_2;
      param_3 = param_3 - 2;
      param_1 = (undefined8 *)((longlong)param_1 + 2);
      param_2 = (undefined8 *)((longlong)param_2 + 2);
      break;
    case 7:
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_3 = param_3 - 1;
      param_1 = (undefined8 *)((longlong)param_1 + 1);
      param_2 = (undefined8 *)((longlong)param_2 + 1);
    }
    if ((longlong)param_3 < 0xb1) {
      lVar26 = (longlong)param_1 + param_3;
      lVar28 = (longlong)param_2 + param_3;
      switch(param_3) {
      case 0:
        goto switchD_1800096f3_caseD_0;
      case 1:
        goto switchD_1800096f3_caseD_1;
      case 2:
        goto switchD_1800096f3_caseD_2;
      case 3:
        goto switchD_1800096f3_caseD_3;
      case 4:
        goto switchD_1800096f3_caseD_4;
      case 5:
        goto switchD_1800096f3_caseD_5;
      case 6:
        goto switchD_1800096f3_caseD_6;
      case 7:
        goto switchD_1800096f3_caseD_7;
      case 0xa9:
        *(undefined8 *)(lVar26 + -0xa9) = *(undefined8 *)(lVar28 + -0xa9);
      case 0xa1:
switchD_180009723_caseD_a1:
        *(undefined8 *)(lVar26 + -0xa1) = *(undefined8 *)(lVar28 + -0xa1);
      case 0x99:
switchD_180009723_caseD_99:
        *(undefined8 *)(lVar26 + -0x99) = *(undefined8 *)(lVar28 + -0x99);
      case 0x91:
switchD_180009723_caseD_91:
        *(undefined8 *)(lVar26 + -0x91) = *(undefined8 *)(lVar28 + -0x91);
      case 0x89:
switchD_180009723_caseD_89:
        *(undefined8 *)(lVar26 + -0x89) = *(undefined8 *)(lVar28 + -0x89);
      case 0x81:
switchD_180009723_caseD_81:
        *(undefined8 *)(lVar26 + -0x81) = *(undefined8 *)(lVar28 + -0x81);
      case 0x79:
switchD_180009723_caseD_79:
        *(undefined8 *)(lVar26 + -0x79) = *(undefined8 *)(lVar28 + -0x79);
      case 0x71:
switchD_180009723_caseD_71:
        *(undefined8 *)(lVar26 + -0x71) = *(undefined8 *)(lVar28 + -0x71);
      case 0x69:
switchD_180009723_caseD_69:
        *(undefined8 *)(lVar26 + -0x69) = *(undefined8 *)(lVar28 + -0x69);
      case 0x61:
switchD_180009723_caseD_61:
        *(undefined8 *)(lVar26 + -0x61) = *(undefined8 *)(lVar28 + -0x61);
      case 0x59:
switchD_180009723_caseD_59:
        *(undefined8 *)(lVar26 + -0x59) = *(undefined8 *)(lVar28 + -0x59);
      case 0x51:
switchD_180009723_caseD_51:
        *(undefined8 *)(lVar26 + -0x51) = *(undefined8 *)(lVar28 + -0x51);
      case 0x49:
switchD_180009723_caseD_49:
        *(undefined8 *)(lVar26 + -0x49) = *(undefined8 *)(lVar28 + -0x49);
      case 0x41:
switchD_180009723_caseD_41:
        *(undefined8 *)(lVar26 + -0x41) = *(undefined8 *)(lVar28 + -0x41);
      case 0x39:
switchD_180009723_caseD_39:
        *(undefined8 *)(lVar26 + -0x39) = *(undefined8 *)(lVar28 + -0x39);
      case 0x31:
switchD_180009723_caseD_31:
        *(undefined8 *)(lVar26 + -0x31) = *(undefined8 *)(lVar28 + -0x31);
      case 0x29:
switchD_180009723_caseD_29:
        *(undefined8 *)(lVar26 + -0x29) = *(undefined8 *)(lVar28 + -0x29);
      case 0x21:
switchD_180009723_caseD_21:
        *(undefined8 *)(lVar26 + -0x21) = *(undefined8 *)(lVar28 + -0x21);
      case 0x19:
switchD_180009723_caseD_19:
        *(undefined8 *)(lVar26 + -0x19) = *(undefined8 *)(lVar28 + -0x19);
      case 0x11:
switchD_180009723_caseD_11:
        *(undefined8 *)(lVar26 + -0x11) = *(undefined8 *)(lVar28 + -0x11);
      case 9:
switchD_180009723_caseD_9:
        *(undefined8 *)(lVar26 + -9) = *(undefined8 *)(lVar28 + -9);
switchD_1800096f3_caseD_1:
        *(undefined1 *)(lVar26 + -1) = *(undefined1 *)(lVar28 + -1);
        return puVar25;
      case 0xaa:
        *(undefined8 *)(lVar26 + -0xaa) = *(undefined8 *)(lVar28 + -0xaa);
      case 0xa2:
switchD_180009723_caseD_a2:
        *(undefined8 *)(lVar26 + -0xa2) = *(undefined8 *)(lVar28 + -0xa2);
      case 0x9a:
switchD_180009723_caseD_9a:
        *(undefined8 *)(lVar26 + -0x9a) = *(undefined8 *)(lVar28 + -0x9a);
      case 0x92:
switchD_180009723_caseD_92:
        *(undefined8 *)(lVar26 + -0x92) = *(undefined8 *)(lVar28 + -0x92);
      case 0x8a:
switchD_180009723_caseD_8a:
        *(undefined8 *)(lVar26 + -0x8a) = *(undefined8 *)(lVar28 + -0x8a);
      case 0x82:
switchD_180009723_caseD_82:
        *(undefined8 *)(lVar26 + -0x82) = *(undefined8 *)(lVar28 + -0x82);
      case 0x7a:
switchD_180009723_caseD_7a:
        *(undefined8 *)(lVar26 + -0x7a) = *(undefined8 *)(lVar28 + -0x7a);
      case 0x72:
switchD_180009723_caseD_72:
        *(undefined8 *)(lVar26 + -0x72) = *(undefined8 *)(lVar28 + -0x72);
      case 0x6a:
switchD_180009723_caseD_6a:
        *(undefined8 *)(lVar26 + -0x6a) = *(undefined8 *)(lVar28 + -0x6a);
      case 0x62:
switchD_180009723_caseD_62:
        *(undefined8 *)(lVar26 + -0x62) = *(undefined8 *)(lVar28 + -0x62);
      case 0x5a:
switchD_180009723_caseD_5a:
        *(undefined8 *)(lVar26 + -0x5a) = *(undefined8 *)(lVar28 + -0x5a);
      case 0x52:
switchD_180009723_caseD_52:
        *(undefined8 *)(lVar26 + -0x52) = *(undefined8 *)(lVar28 + -0x52);
      case 0x4a:
switchD_180009723_caseD_4a:
        *(undefined8 *)(lVar26 + -0x4a) = *(undefined8 *)(lVar28 + -0x4a);
      case 0x42:
switchD_180009723_caseD_42:
        *(undefined8 *)(lVar26 + -0x42) = *(undefined8 *)(lVar28 + -0x42);
      case 0x3a:
switchD_180009723_caseD_3a:
        *(undefined8 *)(lVar26 + -0x3a) = *(undefined8 *)(lVar28 + -0x3a);
      case 0x32:
switchD_180009723_caseD_32:
        *(undefined8 *)(lVar26 + -0x32) = *(undefined8 *)(lVar28 + -0x32);
      case 0x2a:
switchD_180009723_caseD_2a:
        *(undefined8 *)(lVar26 + -0x2a) = *(undefined8 *)(lVar28 + -0x2a);
      case 0x22:
switchD_180009723_caseD_22:
        *(undefined8 *)(lVar26 + -0x22) = *(undefined8 *)(lVar28 + -0x22);
      case 0x1a:
switchD_180009723_caseD_1a:
        *(undefined8 *)(lVar26 + -0x1a) = *(undefined8 *)(lVar28 + -0x1a);
      case 0x12:
switchD_180009723_caseD_12:
        *(undefined8 *)(lVar26 + -0x12) = *(undefined8 *)(lVar28 + -0x12);
      case 10:
switchD_180009723_caseD_a:
        *(undefined8 *)(lVar26 + -10) = *(undefined8 *)(lVar28 + -10);
switchD_1800096f3_caseD_2:
        *(undefined2 *)(lVar26 + -2) = *(undefined2 *)(lVar28 + -2);
        return puVar25;
      case 0xab:
        *(undefined8 *)(lVar26 + -0xab) = *(undefined8 *)(lVar28 + -0xab);
      case 0xa3:
switchD_180009723_caseD_a3:
        *(undefined8 *)(lVar26 + -0xa3) = *(undefined8 *)(lVar28 + -0xa3);
      case 0x9b:
switchD_180009723_caseD_9b:
        *(undefined8 *)(lVar26 + -0x9b) = *(undefined8 *)(lVar28 + -0x9b);
      case 0x93:
switchD_180009723_caseD_93:
        *(undefined8 *)(lVar26 + -0x93) = *(undefined8 *)(lVar28 + -0x93);
      case 0x8b:
switchD_180009723_caseD_8b:
        *(undefined8 *)(lVar26 + -0x8b) = *(undefined8 *)(lVar28 + -0x8b);
      case 0x83:
switchD_180009723_caseD_83:
        *(undefined8 *)(lVar26 + -0x83) = *(undefined8 *)(lVar28 + -0x83);
      case 0x7b:
switchD_180009723_caseD_7b:
        *(undefined8 *)(lVar26 + -0x7b) = *(undefined8 *)(lVar28 + -0x7b);
      case 0x73:
switchD_180009723_caseD_73:
        *(undefined8 *)(lVar26 + -0x73) = *(undefined8 *)(lVar28 + -0x73);
      case 0x6b:
switchD_180009723_caseD_6b:
        *(undefined8 *)(lVar26 + -0x6b) = *(undefined8 *)(lVar28 + -0x6b);
      case 99:
switchD_180009723_caseD_63:
        *(undefined8 *)(lVar26 + -99) = *(undefined8 *)(lVar28 + -99);
      case 0x5b:
switchD_180009723_caseD_5b:
        *(undefined8 *)(lVar26 + -0x5b) = *(undefined8 *)(lVar28 + -0x5b);
      case 0x53:
switchD_180009723_caseD_53:
        *(undefined8 *)(lVar26 + -0x53) = *(undefined8 *)(lVar28 + -0x53);
      case 0x4b:
switchD_180009723_caseD_4b:
        *(undefined8 *)(lVar26 + -0x4b) = *(undefined8 *)(lVar28 + -0x4b);
      case 0x43:
switchD_180009723_caseD_43:
        *(undefined8 *)(lVar26 + -0x43) = *(undefined8 *)(lVar28 + -0x43);
      case 0x3b:
switchD_180009723_caseD_3b:
        *(undefined8 *)(lVar26 + -0x3b) = *(undefined8 *)(lVar28 + -0x3b);
      case 0x33:
switchD_180009723_caseD_33:
        *(undefined8 *)(lVar26 + -0x33) = *(undefined8 *)(lVar28 + -0x33);
      case 0x2b:
switchD_180009723_caseD_2b:
        *(undefined8 *)(lVar26 + -0x2b) = *(undefined8 *)(lVar28 + -0x2b);
      case 0x23:
switchD_180009723_caseD_23:
        *(undefined8 *)(lVar26 + -0x23) = *(undefined8 *)(lVar28 + -0x23);
      case 0x1b:
switchD_180009723_caseD_1b:
        *(undefined8 *)(lVar26 + -0x1b) = *(undefined8 *)(lVar28 + -0x1b);
      case 0x13:
switchD_180009723_caseD_13:
        *(undefined8 *)(lVar26 + -0x13) = *(undefined8 *)(lVar28 + -0x13);
      case 0xb:
switchD_180009723_caseD_b:
        *(undefined8 *)(lVar26 + -0xb) = *(undefined8 *)(lVar28 + -0xb);
switchD_1800096f3_caseD_3:
        uVar5 = *(undefined1 *)(lVar28 + -1);
        *(undefined2 *)(lVar26 + -3) = *(undefined2 *)(lVar28 + -3);
        *(undefined1 *)(lVar26 + -1) = uVar5;
        return puVar25;
      case 0xac:
        *(undefined8 *)(lVar26 + -0xac) = *(undefined8 *)(lVar28 + -0xac);
      case 0xa4:
switchD_180009723_caseD_a4:
        *(undefined8 *)(lVar26 + -0xa4) = *(undefined8 *)(lVar28 + -0xa4);
      case 0x9c:
switchD_180009723_caseD_9c:
        *(undefined8 *)(lVar26 + -0x9c) = *(undefined8 *)(lVar28 + -0x9c);
      case 0x94:
switchD_180009723_caseD_94:
        *(undefined8 *)(lVar26 + -0x94) = *(undefined8 *)(lVar28 + -0x94);
      case 0x8c:
switchD_180009723_caseD_8c:
        *(undefined8 *)(lVar26 + -0x8c) = *(undefined8 *)(lVar28 + -0x8c);
      case 0x84:
switchD_180009723_caseD_84:
        *(undefined8 *)(lVar26 + -0x84) = *(undefined8 *)(lVar28 + -0x84);
      case 0x7c:
switchD_180009723_caseD_7c:
        *(undefined8 *)(lVar26 + -0x7c) = *(undefined8 *)(lVar28 + -0x7c);
      case 0x74:
switchD_180009723_caseD_74:
        *(undefined8 *)(lVar26 + -0x74) = *(undefined8 *)(lVar28 + -0x74);
      case 0x6c:
switchD_180009723_caseD_6c:
        *(undefined8 *)(lVar26 + -0x6c) = *(undefined8 *)(lVar28 + -0x6c);
      case 100:
switchD_180009723_caseD_64:
        *(undefined8 *)(lVar26 + -100) = *(undefined8 *)(lVar28 + -100);
      case 0x5c:
switchD_180009723_caseD_5c:
        *(undefined8 *)(lVar26 + -0x5c) = *(undefined8 *)(lVar28 + -0x5c);
      case 0x54:
switchD_180009723_caseD_54:
        *(undefined8 *)(lVar26 + -0x54) = *(undefined8 *)(lVar28 + -0x54);
      case 0x4c:
switchD_180009723_caseD_4c:
        *(undefined8 *)(lVar26 + -0x4c) = *(undefined8 *)(lVar28 + -0x4c);
      case 0x44:
switchD_180009723_caseD_44:
        *(undefined8 *)(lVar26 + -0x44) = *(undefined8 *)(lVar28 + -0x44);
      case 0x3c:
switchD_180009723_caseD_3c:
        *(undefined8 *)(lVar26 + -0x3c) = *(undefined8 *)(lVar28 + -0x3c);
      case 0x34:
switchD_180009723_caseD_34:
        *(undefined8 *)(lVar26 + -0x34) = *(undefined8 *)(lVar28 + -0x34);
      case 0x2c:
switchD_180009723_caseD_2c:
        *(undefined8 *)(lVar26 + -0x2c) = *(undefined8 *)(lVar28 + -0x2c);
      case 0x24:
switchD_180009723_caseD_24:
        *(undefined8 *)(lVar26 + -0x24) = *(undefined8 *)(lVar28 + -0x24);
      case 0x1c:
switchD_180009723_caseD_1c:
        *(undefined8 *)(lVar26 + -0x1c) = *(undefined8 *)(lVar28 + -0x1c);
      case 0x14:
switchD_180009723_caseD_14:
        *(undefined8 *)(lVar26 + -0x14) = *(undefined8 *)(lVar28 + -0x14);
      case 0xc:
switchD_180009723_caseD_c:
        *(undefined8 *)(lVar26 + -0xc) = *(undefined8 *)(lVar28 + -0xc);
switchD_1800096f3_caseD_4:
        *(undefined4 *)(lVar26 + -4) = *(undefined4 *)(lVar28 + -4);
        return puVar25;
      case 0xad:
        *(undefined8 *)(lVar26 + -0xad) = *(undefined8 *)(lVar28 + -0xad);
      case 0xa5:
switchD_180009723_caseD_a5:
        *(undefined8 *)(lVar26 + -0xa5) = *(undefined8 *)(lVar28 + -0xa5);
      case 0x9d:
switchD_180009723_caseD_9d:
        *(undefined8 *)(lVar26 + -0x9d) = *(undefined8 *)(lVar28 + -0x9d);
      case 0x95:
switchD_180009723_caseD_95:
        *(undefined8 *)(lVar26 + -0x95) = *(undefined8 *)(lVar28 + -0x95);
      case 0x8d:
switchD_180009723_caseD_8d:
        *(undefined8 *)(lVar26 + -0x8d) = *(undefined8 *)(lVar28 + -0x8d);
      case 0x85:
switchD_180009723_caseD_85:
        *(undefined8 *)(lVar26 + -0x85) = *(undefined8 *)(lVar28 + -0x85);
      case 0x7d:
switchD_180009723_caseD_7d:
        *(undefined8 *)(lVar26 + -0x7d) = *(undefined8 *)(lVar28 + -0x7d);
      case 0x75:
switchD_180009723_caseD_75:
        *(undefined8 *)(lVar26 + -0x75) = *(undefined8 *)(lVar28 + -0x75);
      case 0x6d:
switchD_180009723_caseD_6d:
        *(undefined8 *)(lVar26 + -0x6d) = *(undefined8 *)(lVar28 + -0x6d);
      case 0x65:
switchD_180009723_caseD_65:
        *(undefined8 *)(lVar26 + -0x65) = *(undefined8 *)(lVar28 + -0x65);
      case 0x5d:
switchD_180009723_caseD_5d:
        *(undefined8 *)(lVar26 + -0x5d) = *(undefined8 *)(lVar28 + -0x5d);
      case 0x55:
switchD_180009723_caseD_55:
        *(undefined8 *)(lVar26 + -0x55) = *(undefined8 *)(lVar28 + -0x55);
      case 0x4d:
switchD_180009723_caseD_4d:
        *(undefined8 *)(lVar26 + -0x4d) = *(undefined8 *)(lVar28 + -0x4d);
      case 0x45:
switchD_180009723_caseD_45:
        *(undefined8 *)(lVar26 + -0x45) = *(undefined8 *)(lVar28 + -0x45);
      case 0x3d:
switchD_180009723_caseD_3d:
        *(undefined8 *)(lVar26 + -0x3d) = *(undefined8 *)(lVar28 + -0x3d);
      case 0x35:
switchD_180009723_caseD_35:
        *(undefined8 *)(lVar26 + -0x35) = *(undefined8 *)(lVar28 + -0x35);
      case 0x2d:
switchD_180009723_caseD_2d:
        *(undefined8 *)(lVar26 + -0x2d) = *(undefined8 *)(lVar28 + -0x2d);
      case 0x25:
switchD_180009723_caseD_25:
        *(undefined8 *)(lVar26 + -0x25) = *(undefined8 *)(lVar28 + -0x25);
      case 0x1d:
switchD_180009723_caseD_1d:
        *(undefined8 *)(lVar26 + -0x1d) = *(undefined8 *)(lVar28 + -0x1d);
      case 0x15:
switchD_180009723_caseD_15:
        *(undefined8 *)(lVar26 + -0x15) = *(undefined8 *)(lVar28 + -0x15);
      case 0xd:
switchD_180009723_caseD_d:
        *(undefined8 *)(lVar26 + -0xd) = *(undefined8 *)(lVar28 + -0xd);
switchD_1800096f3_caseD_5:
        uVar5 = *(undefined1 *)(lVar28 + -1);
        *(undefined4 *)(lVar26 + -5) = *(undefined4 *)(lVar28 + -5);
        *(undefined1 *)(lVar26 + -1) = uVar5;
        return puVar25;
      case 0xae:
        *(undefined8 *)(lVar26 + -0xae) = *(undefined8 *)(lVar28 + -0xae);
      case 0xa6:
switchD_180009723_caseD_a6:
        *(undefined8 *)(lVar26 + -0xa6) = *(undefined8 *)(lVar28 + -0xa6);
      case 0x9e:
switchD_180009723_caseD_9e:
        *(undefined8 *)(lVar26 + -0x9e) = *(undefined8 *)(lVar28 + -0x9e);
      case 0x96:
switchD_180009723_caseD_96:
        *(undefined8 *)(lVar26 + -0x96) = *(undefined8 *)(lVar28 + -0x96);
      case 0x8e:
switchD_180009723_caseD_8e:
        *(undefined8 *)(lVar26 + -0x8e) = *(undefined8 *)(lVar28 + -0x8e);
      case 0x86:
switchD_180009723_caseD_86:
        *(undefined8 *)(lVar26 + -0x86) = *(undefined8 *)(lVar28 + -0x86);
      case 0x7e:
switchD_180009723_caseD_7e:
        *(undefined8 *)(lVar26 + -0x7e) = *(undefined8 *)(lVar28 + -0x7e);
      case 0x76:
switchD_180009723_caseD_76:
        *(undefined8 *)(lVar26 + -0x76) = *(undefined8 *)(lVar28 + -0x76);
      case 0x6e:
switchD_180009723_caseD_6e:
        *(undefined8 *)(lVar26 + -0x6e) = *(undefined8 *)(lVar28 + -0x6e);
      case 0x66:
switchD_180009723_caseD_66:
        *(undefined8 *)(lVar26 + -0x66) = *(undefined8 *)(lVar28 + -0x66);
      case 0x5e:
switchD_180009723_caseD_5e:
        *(undefined8 *)(lVar26 + -0x5e) = *(undefined8 *)(lVar28 + -0x5e);
      case 0x56:
switchD_180009723_caseD_56:
        *(undefined8 *)(lVar26 + -0x56) = *(undefined8 *)(lVar28 + -0x56);
      case 0x4e:
switchD_180009723_caseD_4e:
        *(undefined8 *)(lVar26 + -0x4e) = *(undefined8 *)(lVar28 + -0x4e);
      case 0x46:
switchD_180009723_caseD_46:
        *(undefined8 *)(lVar26 + -0x46) = *(undefined8 *)(lVar28 + -0x46);
      case 0x3e:
switchD_180009723_caseD_3e:
        *(undefined8 *)(lVar26 + -0x3e) = *(undefined8 *)(lVar28 + -0x3e);
      case 0x36:
switchD_180009723_caseD_36:
        *(undefined8 *)(lVar26 + -0x36) = *(undefined8 *)(lVar28 + -0x36);
      case 0x2e:
switchD_180009723_caseD_2e:
        *(undefined8 *)(lVar26 + -0x2e) = *(undefined8 *)(lVar28 + -0x2e);
      case 0x26:
switchD_180009723_caseD_26:
        *(undefined8 *)(lVar26 + -0x26) = *(undefined8 *)(lVar28 + -0x26);
      case 0x1e:
switchD_180009723_caseD_1e:
        *(undefined8 *)(lVar26 + -0x1e) = *(undefined8 *)(lVar28 + -0x1e);
      case 0x16:
switchD_180009723_caseD_16:
        *(undefined8 *)(lVar26 + -0x16) = *(undefined8 *)(lVar28 + -0x16);
      case 0xe:
switchD_180009723_caseD_e:
        *(undefined8 *)(lVar26 + -0xe) = *(undefined8 *)(lVar28 + -0xe);
switchD_1800096f3_caseD_6:
        uVar6 = *(undefined2 *)(lVar28 + -2);
        *(undefined4 *)(lVar26 + -6) = *(undefined4 *)(lVar28 + -6);
        *(undefined2 *)(lVar26 + -2) = uVar6;
        return puVar25;
      case 0xaf:
        *(undefined8 *)(lVar26 + -0xaf) = *(undefined8 *)(lVar28 + -0xaf);
      case 0xa7:
switchD_180009723_caseD_a7:
        *(undefined8 *)(lVar26 + -0xa7) = *(undefined8 *)(lVar28 + -0xa7);
      case 0x9f:
switchD_180009723_caseD_9f:
        *(undefined8 *)(lVar26 + -0x9f) = *(undefined8 *)(lVar28 + -0x9f);
      case 0x97:
switchD_180009723_caseD_97:
        *(undefined8 *)(lVar26 + -0x97) = *(undefined8 *)(lVar28 + -0x97);
      case 0x8f:
switchD_180009723_caseD_8f:
        *(undefined8 *)(lVar26 + -0x8f) = *(undefined8 *)(lVar28 + -0x8f);
      case 0x87:
switchD_180009723_caseD_87:
        *(undefined8 *)(lVar26 + -0x87) = *(undefined8 *)(lVar28 + -0x87);
      case 0x7f:
switchD_180009723_caseD_7f:
        *(undefined8 *)(lVar26 + -0x7f) = *(undefined8 *)(lVar28 + -0x7f);
      case 0x77:
switchD_180009723_caseD_77:
        *(undefined8 *)(lVar26 + -0x77) = *(undefined8 *)(lVar28 + -0x77);
      case 0x6f:
switchD_180009723_caseD_6f:
        *(undefined8 *)(lVar26 + -0x6f) = *(undefined8 *)(lVar28 + -0x6f);
      case 0x67:
switchD_180009723_caseD_67:
        *(undefined8 *)(lVar26 + -0x67) = *(undefined8 *)(lVar28 + -0x67);
      case 0x5f:
switchD_180009723_caseD_5f:
        *(undefined8 *)(lVar26 + -0x5f) = *(undefined8 *)(lVar28 + -0x5f);
      case 0x57:
switchD_180009723_caseD_57:
        *(undefined8 *)(lVar26 + -0x57) = *(undefined8 *)(lVar28 + -0x57);
      case 0x4f:
switchD_180009723_caseD_4f:
        *(undefined8 *)(lVar26 + -0x4f) = *(undefined8 *)(lVar28 + -0x4f);
      case 0x47:
switchD_180009723_caseD_47:
        *(undefined8 *)(lVar26 + -0x47) = *(undefined8 *)(lVar28 + -0x47);
      case 0x3f:
switchD_180009723_caseD_3f:
        *(undefined8 *)(lVar26 + -0x3f) = *(undefined8 *)(lVar28 + -0x3f);
      case 0x37:
switchD_180009723_caseD_37:
        *(undefined8 *)(lVar26 + -0x37) = *(undefined8 *)(lVar28 + -0x37);
      case 0x2f:
switchD_180009723_caseD_2f:
        *(undefined8 *)(lVar26 + -0x2f) = *(undefined8 *)(lVar28 + -0x2f);
      case 0x27:
switchD_180009723_caseD_27:
        *(undefined8 *)(lVar26 + -0x27) = *(undefined8 *)(lVar28 + -0x27);
      case 0x1f:
switchD_180009723_caseD_1f:
        *(undefined8 *)(lVar26 + -0x1f) = *(undefined8 *)(lVar28 + -0x1f);
      case 0x17:
switchD_180009723_caseD_17:
        *(undefined8 *)(lVar26 + -0x17) = *(undefined8 *)(lVar28 + -0x17);
      case 0xf:
switchD_180009723_caseD_f:
        *(undefined8 *)(lVar26 + -0xf) = *(undefined8 *)(lVar28 + -0xf);
switchD_1800096f3_caseD_7:
        uVar6 = *(undefined2 *)(lVar28 + -3);
        uVar5 = *(undefined1 *)(lVar28 + -1);
        *(undefined4 *)(lVar26 + -7) = *(undefined4 *)(lVar28 + -7);
        *(undefined2 *)(lVar26 + -3) = uVar6;
        *(undefined1 *)(lVar26 + -1) = uVar5;
        return puVar25;
      case 0xb0:
        *(undefined8 *)(lVar26 + -0xb0) = *(undefined8 *)(lVar28 + -0xb0);
      case 0xa8:
        *(undefined8 *)(lVar26 + -0xa8) = *(undefined8 *)(lVar28 + -0xa8);
      case 0xa0:
switchD_180009723_caseD_a0:
        *(undefined8 *)(lVar26 + -0xa0) = *(undefined8 *)(lVar28 + -0xa0);
      case 0x98:
switchD_180009723_caseD_98:
        *(undefined8 *)(lVar26 + -0x98) = *(undefined8 *)(lVar28 + -0x98);
      case 0x90:
switchD_180009723_caseD_90:
        *(undefined8 *)(lVar26 + -0x90) = *(undefined8 *)(lVar28 + -0x90);
      case 0x88:
switchD_180009723_caseD_88:
        *(undefined8 *)(lVar26 + -0x88) = *(undefined8 *)(lVar28 + -0x88);
      case 0x80:
switchD_180009723_caseD_80:
        *(undefined8 *)(lVar26 + -0x80) = *(undefined8 *)(lVar28 + -0x80);
      case 0x78:
switchD_180009723_caseD_78:
        *(undefined8 *)(lVar26 + -0x78) = *(undefined8 *)(lVar28 + -0x78);
      case 0x70:
switchD_180009723_caseD_70:
        *(undefined8 *)(lVar26 + -0x70) = *(undefined8 *)(lVar28 + -0x70);
      case 0x68:
switchD_180009723_caseD_68:
        *(undefined8 *)(lVar26 + -0x68) = *(undefined8 *)(lVar28 + -0x68);
      case 0x60:
switchD_180009723_caseD_60:
        *(undefined8 *)(lVar26 + -0x60) = *(undefined8 *)(lVar28 + -0x60);
      case 0x58:
switchD_180009723_caseD_58:
        *(undefined8 *)(lVar26 + -0x58) = *(undefined8 *)(lVar28 + -0x58);
      case 0x50:
switchD_180009723_caseD_50:
        *(undefined8 *)(lVar26 + -0x50) = *(undefined8 *)(lVar28 + -0x50);
      case 0x48:
switchD_180009723_caseD_48:
        *(undefined8 *)(lVar26 + -0x48) = *(undefined8 *)(lVar28 + -0x48);
      case 0x40:
switchD_180009723_caseD_40:
        *(undefined8 *)(lVar26 + -0x40) = *(undefined8 *)(lVar28 + -0x40);
      case 0x38:
switchD_180009723_caseD_38:
        *(undefined8 *)(lVar26 + -0x38) = *(undefined8 *)(lVar28 + -0x38);
      case 0x30:
switchD_180009723_caseD_30:
        *(undefined8 *)(lVar26 + -0x30) = *(undefined8 *)(lVar28 + -0x30);
      case 0x28:
switchD_180009723_caseD_28:
        *(undefined8 *)(lVar26 + -0x28) = *(undefined8 *)(lVar28 + -0x28);
      case 0x20:
switchD_180009723_caseD_20:
        *(undefined8 *)(lVar26 + -0x20) = *(undefined8 *)(lVar28 + -0x20);
      case 0x18:
switchD_180009723_caseD_18:
        *(undefined8 *)(lVar26 + -0x18) = *(undefined8 *)(lVar28 + -0x18);
      case 0x10:
switchD_180009723_caseD_10:
        *(undefined8 *)(lVar26 + -0x10) = *(undefined8 *)(lVar28 + -0x10);
      }
    }
    else {
      if (DAT_180019464 != 2) {
        if ((longlong)(ulonglong)DAT_180018864 < (longlong)param_3) {
          do {
            param_3 = param_3 - 0x40;
            *param_1 = *param_2;
            param_1[1] = param_2[1];
            param_1[2] = param_2[2];
            param_1[3] = param_2[3];
            param_1[4] = param_2[4];
            param_1[5] = param_2[5];
            param_1[6] = param_2[6];
            param_1[7] = param_2[7];
            param_2 = param_2 + 8;
            param_1 = param_1 + 8;
          } while (0x3f < (longlong)param_3);
        }
        else {
          do {
            uVar8 = param_2[1];
            param_3 = param_3 - 0x40;
            *param_1 = *param_2;
            param_1[1] = uVar8;
            uVar8 = param_2[3];
            param_1[2] = param_2[2];
            param_1[3] = uVar8;
            uVar8 = param_2[5];
            param_1[4] = param_2[4];
            param_1[5] = uVar8;
            puVar25 = param_2 + 6;
            uVar8 = param_2[7];
            param_2 = param_2 + 8;
            param_1[6] = *puVar25;
            param_1[7] = uVar8;
            param_1 = param_1 + 8;
          } while (0x40 < (longlong)param_3);
        }
                    // WARNING: Could not recover jumptable at 0x00018000a64f. Too many branches
                    // WARNING: Treating indirect jump as call
        puVar25 = (undefined8 *)
                  (*(code *)(&switchD_1800096f3::switchdataD_18001d040)[param_3])
                            (param_3 + (longlong)param_1,param_3 + (longlong)param_2);
        return puVar25;
      }
      if (((ulonglong)param_1 & 0xf) != 0) {
        *param_1 = *param_2;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        param_3 = param_3 - 8;
      }
      if ((longlong)(ulonglong)DAT_180018864 < (longlong)param_3) {
        do {
          puVar25 = param_1 + 8;
          puVar2 = param_2 + 8;
          param_3 = param_3 - 0x40;
          uVar8 = param_2[1];
          uVar23 = param_2[2];
          uVar24 = param_2[3];
          *param_1 = *param_2;
          param_1[1] = uVar8;
          param_1[2] = uVar23;
          param_1[3] = uVar24;
          uVar8 = param_2[5];
          uVar23 = param_2[6];
          uVar24 = param_2[7];
          param_1[4] = param_2[4];
          param_1[5] = uVar8;
          param_1[6] = uVar23;
          param_1[7] = uVar24;
          param_1 = puVar25;
          param_2 = puVar2;
        } while (0x3f < (longlong)param_3);
        uVar30 = param_3 & 0xfffffffffffffff0;
        lVar26 = param_3 - uVar30;
        switch(param_3) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
          uVar8 = *(undefined8 *)((longlong)puVar2 + (uVar30 - 0x28));
          *(undefined8 *)((longlong)puVar25 + (uVar30 - 0x30)) =
               *(undefined8 *)((longlong)puVar2 + (uVar30 - 0x30));
          *(undefined8 *)((longlong)puVar25 + (uVar30 - 0x28)) = uVar8;
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case 0x2e:
        case 0x2f:
          uVar8 = *(undefined8 *)((longlong)puVar2 + (uVar30 - 0x18));
          *(undefined8 *)((longlong)puVar25 + (uVar30 - 0x20)) =
               *(undefined8 *)((longlong)puVar2 + (uVar30 - 0x20));
          *(undefined8 *)((longlong)puVar25 + (uVar30 - 0x18)) = uVar8;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x1f:
          uVar8 = *(undefined8 *)((longlong)puVar2 + (uVar30 - 8));
          *(undefined8 *)((longlong)puVar25 + (uVar30 - 0x10)) =
               *(undefined8 *)((longlong)puVar2 + (uVar30 - 0x10));
          *(undefined8 *)((longlong)puVar25 + (uVar30 - 8)) = uVar8;
        default:
                    // WARNING: Could not recover jumptable at 0x00018000a724. Too many branches
                    // WARNING: Treating indirect jump as call
          puVar25 = (undefined8 *)
                    (*(code *)(&switchD_1800096f3::switchdataD_18001d040)[lVar26])
                              ((longlong)puVar25 + lVar26 + uVar30,
                               (longlong)puVar2 + lVar26 + uVar30);
          return puVar25;
        }
      }
      if (((ulonglong)param_2 & 0xf) != 0) {
        uVar30 = (ulonglong)param_2 & 0xf;
        uVar8 = param_2[1];
        *param_1 = *param_2;
        param_1[1] = uVar8;
        pauVar29 = (undefined1 (*) [16])((longlong)param_2 + (0x10 - uVar30));
        pauVar27 = (undefined1 (*) [16])(param_1 + 2);
        lVar26 = param_3 - 0x10;
        auVar38 = *pauVar29;
        switch(uVar30) {
        case 1:
          do {
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            lVar26 = lVar26 + -0x20;
            auVar9._8_8_ = 0;
            auVar9._0_8_ = auVar3._0_8_ << 0x38;
            auVar10._8_8_ = 0;
            auVar10._0_8_ = auVar4._0_8_ << 0x38;
            *pauVar27 = auVar9 << 0x40 | auVar38 >> 8;
            pauVar27[1] = auVar10 << 0x40 | auVar3 >> 8;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 2:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar11._8_8_ = 0;
            auVar11._0_8_ = auVar3._0_8_ << 0x30;
            auVar12._8_8_ = 0;
            auVar12._0_8_ = auVar4._0_8_ << 0x30;
            *pauVar27 = auVar11 << 0x40 | auVar38 >> 0x10;
            pauVar27[1] = auVar12 << 0x40 | auVar3 >> 0x10;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 3:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar13._8_8_ = 0;
            auVar13._0_8_ = auVar3._0_8_ << 0x28;
            auVar14._8_8_ = 0;
            auVar14._0_8_ = auVar4._0_8_ << 0x28;
            *pauVar27 = auVar13 << 0x40 | auVar38 >> 0x18;
            pauVar27[1] = auVar14 << 0x40 | auVar3 >> 0x18;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 4:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar15._8_8_ = 0;
            auVar15._0_8_ = auVar3._0_8_ << 0x20;
            auVar16._8_8_ = 0;
            auVar16._0_8_ = auVar4._0_8_ << 0x20;
            *pauVar27 = auVar15 << 0x40 | auVar38 >> 0x20;
            pauVar27[1] = auVar16 << 0x40 | auVar3 >> 0x20;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 5:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar17._8_8_ = 0;
            auVar17._0_8_ = auVar3._0_8_ << 0x18;
            auVar18._8_8_ = 0;
            auVar18._0_8_ = auVar4._0_8_ << 0x18;
            *pauVar27 = auVar17 << 0x40 | auVar38 >> 0x28;
            pauVar27[1] = auVar18 << 0x40 | auVar3 >> 0x28;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 6:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar19._8_8_ = 0;
            auVar19._0_8_ = auVar3._0_8_ << 0x10;
            auVar20._8_8_ = 0;
            auVar20._0_8_ = auVar4._0_8_ << 0x10;
            *pauVar27 = auVar19 << 0x40 | auVar38 >> 0x30;
            pauVar27[1] = auVar20 << 0x40 | auVar3 >> 0x30;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 7:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar21._8_8_ = 0;
            auVar21._0_8_ = auVar3._0_8_ << 8;
            auVar22._8_8_ = 0;
            auVar22._0_8_ = auVar4._0_8_ << 8;
            *pauVar27 = auVar21 << 0x40 | auVar38 >> 0x38;
            pauVar27[1] = auVar22 << 0x40 | auVar3 >> 0x38;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 8:
          do {
            lVar26 = lVar26 + -0x20;
            pauVar1 = pauVar29 + 1;
            uVar8 = *(undefined8 *)(pauVar29[1] + 8);
            auVar3 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar4._8_8_ = 0;
            auVar4._0_8_ = *(ulonglong *)*pauVar1;
            *pauVar27 = auVar4 << 0x40 | auVar38 >> 0x40;
            *(undefined8 *)pauVar27[1] = uVar8;
            *(longlong *)((longlong)pauVar27[1] + 8) = auVar3._0_8_;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar3;
          } while (0x1f < lVar26);
          break;
        case 9:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar39._0_8_ = auVar3._0_8_ << 0x38;
            auVar39._8_8_ = auVar3._8_8_ << 0x38 | auVar3._0_8_ >> 8;
            auVar31._0_8_ = auVar4._0_8_ << 0x38;
            auVar31._8_8_ = auVar4._8_8_ << 0x38 | auVar4._0_8_ >> 8;
            *pauVar27 = auVar39 | auVar38 >> 0x48;
            pauVar27[1] = auVar31 | auVar3 >> 0x48;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 10:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar40._0_8_ = auVar3._0_8_ << 0x30;
            auVar40._8_8_ = auVar3._8_8_ << 0x30 | auVar3._0_8_ >> 0x10;
            auVar32._0_8_ = auVar4._0_8_ << 0x30;
            auVar32._8_8_ = auVar4._8_8_ << 0x30 | auVar4._0_8_ >> 0x10;
            *pauVar27 = auVar40 | auVar38 >> 0x50;
            pauVar27[1] = auVar32 | auVar3 >> 0x50;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 0xb:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar41._0_8_ = auVar3._0_8_ << 0x28;
            auVar41._8_8_ = auVar3._8_8_ << 0x28 | auVar3._0_8_ >> 0x18;
            auVar33._0_8_ = auVar4._0_8_ << 0x28;
            auVar33._8_8_ = auVar4._8_8_ << 0x28 | auVar4._0_8_ >> 0x18;
            *pauVar27 = auVar41 | auVar38 >> 0x58;
            pauVar27[1] = auVar33 | auVar3 >> 0x58;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 0xc:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar42._0_8_ = auVar3._0_8_ << 0x20;
            auVar42._8_8_ = auVar3._8_8_ << 0x20 | auVar3._0_8_ >> 0x20;
            auVar34._0_8_ = auVar4._0_8_ << 0x20;
            auVar34._8_8_ = auVar4._8_8_ << 0x20 | auVar4._0_8_ >> 0x20;
            *pauVar27 = auVar42 | auVar38 >> 0x60;
            pauVar27[1] = auVar34 | auVar3 >> 0x60;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 0xd:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar43._0_8_ = auVar3._0_8_ << 0x18;
            auVar43._8_8_ = auVar3._8_8_ << 0x18 | auVar3._0_8_ >> 0x28;
            auVar35._0_8_ = auVar4._0_8_ << 0x18;
            auVar35._8_8_ = auVar4._8_8_ << 0x18 | auVar4._0_8_ >> 0x28;
            *pauVar27 = auVar43 | auVar38 >> 0x68;
            pauVar27[1] = auVar35 | auVar3 >> 0x68;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 0xe:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar44._0_8_ = auVar3._0_8_ << 0x10;
            auVar44._8_8_ = auVar3._8_8_ << 0x10 | auVar3._0_8_ >> 0x30;
            auVar36._0_8_ = auVar4._0_8_ << 0x10;
            auVar36._8_8_ = auVar4._8_8_ << 0x10 | auVar4._0_8_ >> 0x30;
            *pauVar27 = auVar44 | auVar38 >> 0x70;
            pauVar27[1] = auVar36 | auVar3 >> 0x70;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
          break;
        case 0xf:
          do {
            lVar26 = lVar26 + -0x20;
            auVar3 = pauVar29[1];
            auVar4 = pauVar29[2];
            pauVar29 = pauVar29 + 2;
            auVar45._0_8_ = auVar3._0_8_ << 8;
            auVar45._8_8_ = auVar3._8_8_ << 8 | auVar3._0_8_ >> 0x38;
            auVar37._0_8_ = auVar4._0_8_ << 8;
            auVar37._8_8_ = auVar4._8_8_ << 8 | auVar4._0_8_ >> 0x38;
            *pauVar27 = auVar45 | auVar38 >> 0x78;
            pauVar27[1] = auVar37 | auVar3 >> 0x78;
            pauVar27 = pauVar27 + 2;
            auVar38 = auVar4;
          } while (0x1f < lVar26);
        }
                    // WARNING: Could not recover jumptable at 0x00018000a4e9. Too many branches
                    // WARNING: Treating indirect jump as call
        puVar25 = (undefined8 *)
                  (*(code *)(&switchD_1800096f3::switchdataD_18001d040)[lVar26])
                            ((longlong)*pauVar27 + lVar26,*pauVar29 + lVar26 + uVar30);
        return puVar25;
      }
      do {
        uVar8 = param_2[1];
        uVar23 = param_2[2];
        uVar24 = param_2[3];
        *param_1 = *param_2;
        param_1[1] = uVar8;
        param_1[2] = uVar23;
        param_1[3] = uVar24;
        param_3 = param_3 - 0x80;
        uVar8 = param_2[5];
        uVar23 = param_2[6];
        uVar24 = param_2[7];
        param_1[4] = param_2[4];
        param_1[5] = uVar8;
        param_1[6] = uVar23;
        param_1[7] = uVar24;
        uVar8 = param_2[9];
        uVar23 = param_2[10];
        uVar24 = param_2[0xb];
        param_1[8] = param_2[8];
        param_1[9] = uVar8;
        param_1[10] = uVar23;
        param_1[0xb] = uVar24;
        puVar2 = param_2 + 0xc;
        uVar8 = param_2[0xd];
        uVar23 = param_2[0xe];
        uVar24 = param_2[0xf];
        param_2 = param_2 + 0x10;
        param_1[0xc] = *puVar2;
        param_1[0xd] = uVar8;
        param_1[0xe] = uVar23;
        param_1[0xf] = uVar24;
        param_1 = param_1 + 0x10;
      } while (0xa7 < (longlong)param_3);
      lVar26 = (longlong)param_1 + param_3;
      lVar28 = (longlong)param_2 + param_3;
      switch(param_3) {
      case 0:
        goto switchD_1800096f3_caseD_0;
      case 1:
        goto switchD_1800096f3_caseD_1;
      case 2:
        goto switchD_1800096f3_caseD_2;
      case 3:
        goto switchD_1800096f3_caseD_3;
      case 4:
        goto switchD_1800096f3_caseD_4;
      case 5:
        goto switchD_1800096f3_caseD_5;
      case 6:
        goto switchD_1800096f3_caseD_6;
      case 7:
        goto switchD_1800096f3_caseD_7;
      case 9:
        goto switchD_180009723_caseD_9;
      case 10:
        goto switchD_180009723_caseD_a;
      case 0xb:
        goto switchD_180009723_caseD_b;
      case 0xc:
        goto switchD_180009723_caseD_c;
      case 0xd:
        goto switchD_180009723_caseD_d;
      case 0xe:
        goto switchD_180009723_caseD_e;
      case 0xf:
        goto switchD_180009723_caseD_f;
      case 0x10:
        goto switchD_180009723_caseD_10;
      case 0x11:
        goto switchD_180009723_caseD_11;
      case 0x12:
        goto switchD_180009723_caseD_12;
      case 0x13:
        goto switchD_180009723_caseD_13;
      case 0x14:
        goto switchD_180009723_caseD_14;
      case 0x15:
        goto switchD_180009723_caseD_15;
      case 0x16:
        goto switchD_180009723_caseD_16;
      case 0x17:
        goto switchD_180009723_caseD_17;
      case 0x18:
        goto switchD_180009723_caseD_18;
      case 0x19:
        goto switchD_180009723_caseD_19;
      case 0x1a:
        goto switchD_180009723_caseD_1a;
      case 0x1b:
        goto switchD_180009723_caseD_1b;
      case 0x1c:
        goto switchD_180009723_caseD_1c;
      case 0x1d:
        goto switchD_180009723_caseD_1d;
      case 0x1e:
        goto switchD_180009723_caseD_1e;
      case 0x1f:
        goto switchD_180009723_caseD_1f;
      case 0x20:
        goto switchD_180009723_caseD_20;
      case 0x21:
        goto switchD_180009723_caseD_21;
      case 0x22:
        goto switchD_180009723_caseD_22;
      case 0x23:
        goto switchD_180009723_caseD_23;
      case 0x24:
        goto switchD_180009723_caseD_24;
      case 0x25:
        goto switchD_180009723_caseD_25;
      case 0x26:
        goto switchD_180009723_caseD_26;
      case 0x27:
        goto switchD_180009723_caseD_27;
      case 0x28:
        goto switchD_180009723_caseD_28;
      case 0x29:
        goto switchD_180009723_caseD_29;
      case 0x2a:
        goto switchD_180009723_caseD_2a;
      case 0x2b:
        goto switchD_180009723_caseD_2b;
      case 0x2c:
        goto switchD_180009723_caseD_2c;
      case 0x2d:
        goto switchD_180009723_caseD_2d;
      case 0x2e:
        goto switchD_180009723_caseD_2e;
      case 0x2f:
        goto switchD_180009723_caseD_2f;
      case 0x30:
        goto switchD_180009723_caseD_30;
      case 0x31:
        goto switchD_180009723_caseD_31;
      case 0x32:
        goto switchD_180009723_caseD_32;
      case 0x33:
        goto switchD_180009723_caseD_33;
      case 0x34:
        goto switchD_180009723_caseD_34;
      case 0x35:
        goto switchD_180009723_caseD_35;
      case 0x36:
        goto switchD_180009723_caseD_36;
      case 0x37:
        goto switchD_180009723_caseD_37;
      case 0x38:
        goto switchD_180009723_caseD_38;
      case 0x39:
        goto switchD_180009723_caseD_39;
      case 0x3a:
        goto switchD_180009723_caseD_3a;
      case 0x3b:
        goto switchD_180009723_caseD_3b;
      case 0x3c:
        goto switchD_180009723_caseD_3c;
      case 0x3d:
        goto switchD_180009723_caseD_3d;
      case 0x3e:
        goto switchD_180009723_caseD_3e;
      case 0x3f:
        goto switchD_180009723_caseD_3f;
      case 0x40:
        goto switchD_180009723_caseD_40;
      case 0x41:
        goto switchD_180009723_caseD_41;
      case 0x42:
        goto switchD_180009723_caseD_42;
      case 0x43:
        goto switchD_180009723_caseD_43;
      case 0x44:
        goto switchD_180009723_caseD_44;
      case 0x45:
        goto switchD_180009723_caseD_45;
      case 0x46:
        goto switchD_180009723_caseD_46;
      case 0x47:
        goto switchD_180009723_caseD_47;
      case 0x48:
        goto switchD_180009723_caseD_48;
      case 0x49:
        goto switchD_180009723_caseD_49;
      case 0x4a:
        goto switchD_180009723_caseD_4a;
      case 0x4b:
        goto switchD_180009723_caseD_4b;
      case 0x4c:
        goto switchD_180009723_caseD_4c;
      case 0x4d:
        goto switchD_180009723_caseD_4d;
      case 0x4e:
        goto switchD_180009723_caseD_4e;
      case 0x4f:
        goto switchD_180009723_caseD_4f;
      case 0x50:
        goto switchD_180009723_caseD_50;
      case 0x51:
        goto switchD_180009723_caseD_51;
      case 0x52:
        goto switchD_180009723_caseD_52;
      case 0x53:
        goto switchD_180009723_caseD_53;
      case 0x54:
        goto switchD_180009723_caseD_54;
      case 0x55:
        goto switchD_180009723_caseD_55;
      case 0x56:
        goto switchD_180009723_caseD_56;
      case 0x57:
        goto switchD_180009723_caseD_57;
      case 0x58:
        goto switchD_180009723_caseD_58;
      case 0x59:
        goto switchD_180009723_caseD_59;
      case 0x5a:
        goto switchD_180009723_caseD_5a;
      case 0x5b:
        goto switchD_180009723_caseD_5b;
      case 0x5c:
        goto switchD_180009723_caseD_5c;
      case 0x5d:
        goto switchD_180009723_caseD_5d;
      case 0x5e:
        goto switchD_180009723_caseD_5e;
      case 0x5f:
        goto switchD_180009723_caseD_5f;
      case 0x60:
        goto switchD_180009723_caseD_60;
      case 0x61:
        goto switchD_180009723_caseD_61;
      case 0x62:
        goto switchD_180009723_caseD_62;
      case 99:
        goto switchD_180009723_caseD_63;
      case 100:
        goto switchD_180009723_caseD_64;
      case 0x65:
        goto switchD_180009723_caseD_65;
      case 0x66:
        goto switchD_180009723_caseD_66;
      case 0x67:
        goto switchD_180009723_caseD_67;
      case 0x68:
        goto switchD_180009723_caseD_68;
      case 0x69:
        goto switchD_180009723_caseD_69;
      case 0x6a:
        goto switchD_180009723_caseD_6a;
      case 0x6b:
        goto switchD_180009723_caseD_6b;
      case 0x6c:
        goto switchD_180009723_caseD_6c;
      case 0x6d:
        goto switchD_180009723_caseD_6d;
      case 0x6e:
        goto switchD_180009723_caseD_6e;
      case 0x6f:
        goto switchD_180009723_caseD_6f;
      case 0x70:
        goto switchD_180009723_caseD_70;
      case 0x71:
        goto switchD_180009723_caseD_71;
      case 0x72:
        goto switchD_180009723_caseD_72;
      case 0x73:
        goto switchD_180009723_caseD_73;
      case 0x74:
        goto switchD_180009723_caseD_74;
      case 0x75:
        goto switchD_180009723_caseD_75;
      case 0x76:
        goto switchD_180009723_caseD_76;
      case 0x77:
        goto switchD_180009723_caseD_77;
      case 0x78:
        goto switchD_180009723_caseD_78;
      case 0x79:
        goto switchD_180009723_caseD_79;
      case 0x7a:
        goto switchD_180009723_caseD_7a;
      case 0x7b:
        goto switchD_180009723_caseD_7b;
      case 0x7c:
        goto switchD_180009723_caseD_7c;
      case 0x7d:
        goto switchD_180009723_caseD_7d;
      case 0x7e:
        goto switchD_180009723_caseD_7e;
      case 0x7f:
        goto switchD_180009723_caseD_7f;
      case 0x80:
        goto switchD_180009723_caseD_80;
      case 0x81:
        goto switchD_180009723_caseD_81;
      case 0x82:
        goto switchD_180009723_caseD_82;
      case 0x83:
        goto switchD_180009723_caseD_83;
      case 0x84:
        goto switchD_180009723_caseD_84;
      case 0x85:
        goto switchD_180009723_caseD_85;
      case 0x86:
        goto switchD_180009723_caseD_86;
      case 0x87:
        goto switchD_180009723_caseD_87;
      case 0x88:
        goto switchD_180009723_caseD_88;
      case 0x89:
        goto switchD_180009723_caseD_89;
      case 0x8a:
        goto switchD_180009723_caseD_8a;
      case 0x8b:
        goto switchD_180009723_caseD_8b;
      case 0x8c:
        goto switchD_180009723_caseD_8c;
      case 0x8d:
        goto switchD_180009723_caseD_8d;
      case 0x8e:
        goto switchD_180009723_caseD_8e;
      case 0x8f:
        goto switchD_180009723_caseD_8f;
      case 0x90:
        goto switchD_180009723_caseD_90;
      case 0x91:
        goto switchD_180009723_caseD_91;
      case 0x92:
        goto switchD_180009723_caseD_92;
      case 0x93:
        goto switchD_180009723_caseD_93;
      case 0x94:
        goto switchD_180009723_caseD_94;
      case 0x95:
        goto switchD_180009723_caseD_95;
      case 0x96:
        goto switchD_180009723_caseD_96;
      case 0x97:
        goto switchD_180009723_caseD_97;
      case 0x98:
        goto switchD_180009723_caseD_98;
      case 0x99:
        goto switchD_180009723_caseD_99;
      case 0x9a:
        goto switchD_180009723_caseD_9a;
      case 0x9b:
        goto switchD_180009723_caseD_9b;
      case 0x9c:
        goto switchD_180009723_caseD_9c;
      case 0x9d:
        goto switchD_180009723_caseD_9d;
      case 0x9e:
        goto switchD_180009723_caseD_9e;
      case 0x9f:
        goto switchD_180009723_caseD_9f;
      case 0xa0:
        goto switchD_180009723_caseD_a0;
      case 0xa1:
        goto switchD_180009723_caseD_a1;
      case 0xa2:
        goto switchD_180009723_caseD_a2;
      case 0xa3:
        goto switchD_180009723_caseD_a3;
      case 0xa4:
        goto switchD_180009723_caseD_a4;
      case 0xa5:
        goto switchD_180009723_caseD_a5;
      case 0xa6:
        goto switchD_180009723_caseD_a6;
      case 0xa7:
        goto switchD_180009723_caseD_a7;
      }
    }
  }
  *(undefined8 *)(lVar26 + -8) = *(undefined8 *)(lVar28 + -8);
switchD_1800096f3_caseD_0:
  return puVar25;
}



void FUN_18000a780(undefined1 (*param_1) [32],undefined1 (*param_2) [32],ulonglong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  longlong lVar23;
  longlong lVar24;
  undefined1 (*pauVar25) [32];
  
  switch(param_3) {
  case 0:
    break;
  case 1:
    (*param_1)[0] = (*param_2)[0];
    break;
  case 2:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    break;
  case 3:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    (*param_1)[2] = (*param_2)[2];
    break;
  case 4:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    break;
  case 5:
  case 6:
  case 7:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    *(undefined4 *)(param_1[-1] + param_3 + 0x1c) = *(undefined4 *)(param_2[-1] + param_3 + 0x1c);
    break;
  case 8:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x18) = *(undefined8 *)(param_2[-1] + param_3 + 0x18);
    break;
  case 0x10:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    uVar7 = *(undefined8 *)((longlong)(param_2[-1] + param_3 + 0x10) + 8);
    *(undefined8 *)(param_1[-1] + param_3 + 0x10) = *(undefined8 *)(param_2[-1] + param_3 + 0x10);
    *(undefined8 *)((longlong)(param_1[-1] + param_3 + 0x10) + 8) = uVar7;
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0xa1:
  case 0xa2:
  case 0xa3:
  case 0xa4:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb1:
  case 0xb2:
  case 0xb3:
  case 0xb4:
  case 0xb5:
  case 0xb6:
  case 0xb7:
  case 0xb8:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[4] + 8);
    uVar8 = *(undefined8 *)(param_2[4] + 0x10);
    uVar9 = *(undefined8 *)(param_2[4] + 0x18);
    *(undefined8 *)param_1[4] = *(undefined8 *)param_2[4];
    *(undefined8 *)(param_1[4] + 8) = uVar7;
    *(undefined8 *)(param_1[4] + 0x10) = uVar8;
    *(undefined8 *)(param_1[4] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
  case 0xc6:
  case 199:
  case 200:
  case 0xc9:
  case 0xca:
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
  case 0xdb:
  case 0xdc:
  case 0xdd:
  case 0xde:
  case 0xdf:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[4] + 8);
    uVar8 = *(undefined8 *)(param_2[4] + 0x10);
    uVar9 = *(undefined8 *)(param_2[4] + 0x18);
    *(undefined8 *)param_1[4] = *(undefined8 *)param_2[4];
    *(undefined8 *)(param_1[4] + 8) = uVar7;
    *(undefined8 *)(param_1[4] + 0x10) = uVar8;
    *(undefined8 *)(param_1[4] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[5] + 8);
    uVar8 = *(undefined8 *)(param_2[5] + 0x10);
    uVar9 = *(undefined8 *)(param_2[5] + 0x18);
    *(undefined8 *)param_1[5] = *(undefined8 *)param_2[5];
    *(undefined8 *)(param_1[5] + 8) = uVar7;
    *(undefined8 *)(param_1[5] + 0x10) = uVar8;
    *(undefined8 *)(param_1[5] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0xe1:
  case 0xe2:
  case 0xe3:
  case 0xe4:
  case 0xe5:
  case 0xe6:
  case 0xe7:
  case 0xe8:
  case 0xe9:
  case 0xea:
  case 0xeb:
  case 0xec:
  case 0xed:
  case 0xee:
  case 0xef:
  case 0xf0:
  case 0xf1:
  case 0xf2:
  case 0xf3:
  case 0xf4:
  case 0xf5:
  case 0xf6:
  case 0xf7:
  case 0xf8:
  case 0xf9:
  case 0xfa:
  case 0xfb:
  case 0xfc:
  case 0xfd:
  case 0xfe:
  case 0xff:
    uVar7 = *(undefined8 *)(*param_2 + 8);
    uVar8 = *(undefined8 *)(*param_2 + 0x10);
    uVar9 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar7;
    *(undefined8 *)(*param_1 + 0x10) = uVar8;
    *(undefined8 *)(*param_1 + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[1] + 8);
    uVar8 = *(undefined8 *)(param_2[1] + 0x10);
    uVar9 = *(undefined8 *)(param_2[1] + 0x18);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar7;
    *(undefined8 *)(param_1[1] + 0x10) = uVar8;
    *(undefined8 *)(param_1[1] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[2] + 8);
    uVar8 = *(undefined8 *)(param_2[2] + 0x10);
    uVar9 = *(undefined8 *)(param_2[2] + 0x18);
    *(undefined8 *)param_1[2] = *(undefined8 *)param_2[2];
    *(undefined8 *)(param_1[2] + 8) = uVar7;
    *(undefined8 *)(param_1[2] + 0x10) = uVar8;
    *(undefined8 *)(param_1[2] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[3] + 8);
    uVar8 = *(undefined8 *)(param_2[3] + 0x10);
    uVar9 = *(undefined8 *)(param_2[3] + 0x18);
    *(undefined8 *)param_1[3] = *(undefined8 *)param_2[3];
    *(undefined8 *)(param_1[3] + 8) = uVar7;
    *(undefined8 *)(param_1[3] + 0x10) = uVar8;
    *(undefined8 *)(param_1[3] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[4] + 8);
    uVar8 = *(undefined8 *)(param_2[4] + 0x10);
    uVar9 = *(undefined8 *)(param_2[4] + 0x18);
    *(undefined8 *)param_1[4] = *(undefined8 *)param_2[4];
    *(undefined8 *)(param_1[4] + 8) = uVar7;
    *(undefined8 *)(param_1[4] + 0x10) = uVar8;
    *(undefined8 *)(param_1[4] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[5] + 8);
    uVar8 = *(undefined8 *)(param_2[5] + 0x10);
    uVar9 = *(undefined8 *)(param_2[5] + 0x18);
    *(undefined8 *)param_1[5] = *(undefined8 *)param_2[5];
    *(undefined8 *)(param_1[5] + 8) = uVar7;
    *(undefined8 *)(param_1[5] + 0x10) = uVar8;
    *(undefined8 *)(param_1[5] + 0x18) = uVar9;
    uVar7 = *(undefined8 *)(param_2[6] + 8);
    uVar8 = *(undefined8 *)(param_2[6] + 0x10);
    uVar9 = *(undefined8 *)(param_2[6] + 0x18);
    *(undefined8 *)param_1[6] = *(undefined8 *)param_2[6];
    *(undefined8 *)(param_1[6] + 8) = uVar7;
    *(undefined8 *)(param_1[6] + 0x10) = uVar8;
    *(undefined8 *)(param_1[6] + 0x18) = uVar9;
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  case 0x100:
    puVar1 = (undefined8 *)(param_2[-8] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-8] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0xe0:
    puVar1 = (undefined8 *)(param_2[-7] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-7] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0xc0:
    puVar1 = (undefined8 *)(param_2[-6] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-6] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0xa0:
    puVar1 = (undefined8 *)(param_2[-5] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-5] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x80:
    puVar1 = (undefined8 *)(param_2[-4] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-4] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x60:
    puVar1 = (undefined8 *)(param_2[-3] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-3] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x40:
    puVar1 = (undefined8 *)(param_2[-2] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-2] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
  case 0x20:
    puVar1 = (undefined8 *)(param_2[-1] + param_3);
    uVar7 = puVar1[1];
    uVar8 = puVar1[2];
    uVar9 = puVar1[3];
    puVar2 = (undefined8 *)(param_1[-1] + param_3);
    *puVar2 = *puVar1;
    puVar2[1] = uVar7;
    puVar2[2] = uVar8;
    puVar2[3] = uVar9;
    break;
  default:
    uVar22 = (ulonglong)param_1 & 0x1f;
    pauVar25 = param_1;
    if (uVar22 != 0) {
      lVar23 = -uVar22;
      lVar24 = lVar23 + 0x20;
      param_3 = param_3 - lVar24;
      switch(uVar22) {
      default:
        uVar7 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar7;
        uVar7 = *(undefined8 *)((longlong)param_2 + lVar23 + 0x18);
        *(undefined8 *)((longlong)param_1 + lVar23 + 0x10) =
             *(undefined8 *)((longlong)param_2 + lVar23 + 0x10);
        *(undefined8 *)((longlong)param_1 + lVar23 + 0x18) = uVar7;
        break;
      case 0x10:
        uVar7 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar7;
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)((longlong)param_1 + lVar23 + 0x18) =
             *(undefined8 *)((longlong)param_2 + lVar23 + 0x18);
        break;
      case 0x18:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        break;
      case 0x19:
      case 0x1a:
      case 0x1b:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        *(undefined4 *)((longlong)param_1 + lVar23 + 0x1c) =
             *(undefined4 *)((longlong)param_2 + lVar23 + 0x1c);
        break;
      case 0x1c:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        break;
      case 0x1d:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        (*param_1)[2] = (*param_2)[2];
        break;
      case 0x1e:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        break;
      case 0x1f:
        (*param_1)[0] = (*param_2)[0];
      }
      pauVar25 = (undefined1 (*) [32])((longlong)param_1 + lVar24);
      param_2 = (undefined1 (*) [32])((longlong)param_2 + lVar24);
    }
    if (0xff < (longlong)param_3) {
      if ((ulonglong)DAT_18001886c - (ulonglong)(DAT_18001886c >> 2) <= param_3) {
        if (param_3 < DAT_180018864) {
          for (; param_3 != 0; param_3 = param_3 - 1) {
            (*pauVar25)[0] = (*param_2)[0];
            param_2 = (undefined1 (*) [32])(*param_2 + 1);
            pauVar25 = (undefined1 (*) [32])(*pauVar25 + 1);
          }
          return;
        }
        do {
          auVar3 = param_2[1];
          auVar4 = param_2[2];
          auVar5 = param_2[3];
          auVar6 = vmovntdq_avx(*param_2);
          *pauVar25 = auVar6;
          auVar3 = vmovntdq_avx(auVar3);
          pauVar25[1] = auVar3;
          auVar3 = vmovntdq_avx(auVar4);
          pauVar25[2] = auVar3;
          auVar3 = vmovntdq_avx(auVar5);
          pauVar25[3] = auVar3;
          param_3 = param_3 - 0x100;
          auVar3 = param_2[5];
          auVar4 = param_2[6];
          auVar5 = param_2[7];
          auVar6 = vmovntdq_avx(param_2[4]);
          pauVar25[4] = auVar6;
          auVar3 = vmovntdq_avx(auVar3);
          pauVar25[5] = auVar3;
          auVar3 = vmovntdq_avx(auVar4);
          pauVar25[6] = auVar3;
          auVar3 = vmovntdq_avx(auVar5);
          pauVar25[7] = auVar3;
          pauVar25 = pauVar25 + 8;
          param_2 = param_2 + 8;
        } while (0x2ff < (longlong)param_3);
      }
      do {
        uVar7 = *(undefined8 *)(*param_2 + 8);
        uVar8 = *(undefined8 *)(*param_2 + 0x10);
        uVar9 = *(undefined8 *)(*param_2 + 0x18);
        uVar10 = *(undefined8 *)param_2[1];
        uVar11 = *(undefined8 *)(param_2[1] + 8);
        uVar12 = *(undefined8 *)(param_2[1] + 0x10);
        uVar13 = *(undefined8 *)(param_2[1] + 0x18);
        uVar14 = *(undefined8 *)param_2[2];
        uVar15 = *(undefined8 *)(param_2[2] + 8);
        uVar16 = *(undefined8 *)(param_2[2] + 0x10);
        uVar17 = *(undefined8 *)(param_2[2] + 0x18);
        uVar18 = *(undefined8 *)param_2[3];
        uVar19 = *(undefined8 *)(param_2[3] + 8);
        uVar20 = *(undefined8 *)(param_2[3] + 0x10);
        uVar21 = *(undefined8 *)(param_2[3] + 0x18);
        *(undefined8 *)*pauVar25 = *(undefined8 *)*param_2;
        *(undefined8 *)(*pauVar25 + 8) = uVar7;
        *(undefined8 *)(*pauVar25 + 0x10) = uVar8;
        *(undefined8 *)(*pauVar25 + 0x18) = uVar9;
        *(undefined8 *)pauVar25[1] = uVar10;
        *(undefined8 *)(pauVar25[1] + 8) = uVar11;
        *(undefined8 *)(pauVar25[1] + 0x10) = uVar12;
        *(undefined8 *)(pauVar25[1] + 0x18) = uVar13;
        *(undefined8 *)pauVar25[2] = uVar14;
        *(undefined8 *)(pauVar25[2] + 8) = uVar15;
        *(undefined8 *)(pauVar25[2] + 0x10) = uVar16;
        *(undefined8 *)(pauVar25[2] + 0x18) = uVar17;
        *(undefined8 *)pauVar25[3] = uVar18;
        *(undefined8 *)(pauVar25[3] + 8) = uVar19;
        *(undefined8 *)(pauVar25[3] + 0x10) = uVar20;
        *(undefined8 *)(pauVar25[3] + 0x18) = uVar21;
        uVar7 = *(undefined8 *)(param_2[4] + 8);
        uVar8 = *(undefined8 *)(param_2[4] + 0x10);
        uVar9 = *(undefined8 *)(param_2[4] + 0x18);
        uVar10 = *(undefined8 *)param_2[5];
        uVar11 = *(undefined8 *)(param_2[5] + 8);
        uVar12 = *(undefined8 *)(param_2[5] + 0x10);
        uVar13 = *(undefined8 *)(param_2[5] + 0x18);
        uVar14 = *(undefined8 *)param_2[6];
        uVar15 = *(undefined8 *)(param_2[6] + 8);
        uVar16 = *(undefined8 *)(param_2[6] + 0x10);
        uVar17 = *(undefined8 *)(param_2[6] + 0x18);
        uVar18 = *(undefined8 *)param_2[7];
        uVar19 = *(undefined8 *)(param_2[7] + 8);
        uVar20 = *(undefined8 *)(param_2[7] + 0x10);
        uVar21 = *(undefined8 *)(param_2[7] + 0x18);
        *(undefined8 *)pauVar25[4] = *(undefined8 *)param_2[4];
        *(undefined8 *)(pauVar25[4] + 8) = uVar7;
        *(undefined8 *)(pauVar25[4] + 0x10) = uVar8;
        *(undefined8 *)(pauVar25[4] + 0x18) = uVar9;
        *(undefined8 *)pauVar25[5] = uVar10;
        *(undefined8 *)(pauVar25[5] + 8) = uVar11;
        *(undefined8 *)(pauVar25[5] + 0x10) = uVar12;
        *(undefined8 *)(pauVar25[5] + 0x18) = uVar13;
        *(undefined8 *)pauVar25[6] = uVar14;
        *(undefined8 *)(pauVar25[6] + 8) = uVar15;
        *(undefined8 *)(pauVar25[6] + 0x10) = uVar16;
        *(undefined8 *)(pauVar25[6] + 0x18) = uVar17;
        *(undefined8 *)pauVar25[7] = uVar18;
        *(undefined8 *)(pauVar25[7] + 8) = uVar19;
        *(undefined8 *)(pauVar25[7] + 0x10) = uVar20;
        *(undefined8 *)(pauVar25[7] + 0x18) = uVar21;
        pauVar25 = pauVar25 + 8;
        param_2 = param_2 + 8;
        param_3 = param_3 - 0x100;
      } while (0xff < param_3);
    }
                    // WARNING: Could not recover jumptable at 0x00018000aab4. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)(&DAT_18000aff0 + -*(longlong *)(&DAT_18000aff0 + param_3 * 8)))
              (param_1,*pauVar25 + param_3,param_3,
               &DAT_18000aff0 + -*(longlong *)(&DAT_18000aff0 + param_3 * 8));
    return;
  }
  return;
}



void FUN_18000c040(undefined1 (*param_1) [64],undefined1 (*param_2) [64],ulonglong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 (*pauVar8) [64];
  ulonglong uVar9;
  undefined1 (*pauVar10) [64];
  undefined1 auVar11 [64];
  
  switch(param_3) {
  case 0:
    break;
  case 1:
    (*param_1)[0] = (*param_2)[0];
    break;
  case 2:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    break;
  case 3:
    *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
    (*param_1)[2] = (*param_2)[2];
    break;
  case 4:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    break;
  case 5:
  case 6:
  case 7:
    *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
    *(undefined4 *)(param_1[-1] + param_3 + 0x3c) = *(undefined4 *)(param_2[-1] + param_3 + 0x3c);
    break;
  case 8:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    break;
  case 0x10:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    uVar1 = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    *(undefined8 *)(param_1[-1] + param_3 + 0x30) = *(undefined8 *)(param_2[-1] + param_3 + 0x30);
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = uVar1;
    break;
  case 0x20:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    uVar1 = *(undefined8 *)(param_2[-1] + param_3 + 0x28);
    uVar2 = *(undefined8 *)(param_2[-1] + param_3 + 0x30);
    uVar3 = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    *(undefined8 *)(param_1[-1] + param_3 + 0x20) = *(undefined8 *)(param_2[-1] + param_3 + 0x20);
    *(undefined8 *)(param_1[-1] + param_3 + 0x28) = uVar1;
    *(undefined8 *)(param_1[-1] + param_3 + 0x30) = uVar2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = uVar3;
    break;
  case 0x40:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    uVar4 = *(undefined8 *)(*param_2 + 0x20);
    uVar5 = *(undefined8 *)(*param_2 + 0x28);
    uVar6 = *(undefined8 *)(*param_2 + 0x30);
    uVar7 = *(undefined8 *)(*param_2 + 0x38);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    *(undefined8 *)(*param_1 + 0x20) = uVar4;
    *(undefined8 *)(*param_1 + 0x28) = uVar5;
    *(undefined8 *)(*param_1 + 0x30) = uVar6;
    *(undefined8 *)(*param_1 + 0x38) = uVar7;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
    uVar1 = *(undefined8 *)(*param_2 + 8);
    uVar2 = *(undefined8 *)(*param_2 + 0x10);
    uVar3 = *(undefined8 *)(*param_2 + 0x18);
    uVar4 = *(undefined8 *)(*param_2 + 0x20);
    uVar5 = *(undefined8 *)(*param_2 + 0x28);
    uVar6 = *(undefined8 *)(*param_2 + 0x30);
    uVar7 = *(undefined8 *)(*param_2 + 0x38);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar1;
    *(undefined8 *)(*param_1 + 0x10) = uVar2;
    *(undefined8 *)(*param_1 + 0x18) = uVar3;
    *(undefined8 *)(*param_1 + 0x20) = uVar4;
    *(undefined8 *)(*param_1 + 0x28) = uVar5;
    *(undefined8 *)(*param_1 + 0x30) = uVar6;
    *(undefined8 *)(*param_1 + 0x38) = uVar7;
    uVar1 = *(undefined8 *)(param_2[-1] + param_3 + 8);
    uVar2 = *(undefined8 *)(param_2[-1] + param_3 + 0x10);
    uVar3 = *(undefined8 *)(param_2[-1] + param_3 + 0x18);
    uVar4 = *(undefined8 *)(param_2[-1] + param_3 + 0x20);
    uVar5 = *(undefined8 *)(param_2[-1] + param_3 + 0x28);
    uVar6 = *(undefined8 *)(param_2[-1] + param_3 + 0x30);
    uVar7 = *(undefined8 *)(param_2[-1] + param_3 + 0x38);
    *(undefined8 *)(param_1[-1] + param_3) = *(undefined8 *)(param_2[-1] + param_3);
    *(undefined8 *)(param_1[-1] + param_3 + 8) = uVar1;
    *(undefined8 *)(param_1[-1] + param_3 + 0x10) = uVar2;
    *(undefined8 *)(param_1[-1] + param_3 + 0x18) = uVar3;
    *(undefined8 *)(param_1[-1] + param_3 + 0x20) = uVar4;
    *(undefined8 *)(param_1[-1] + param_3 + 0x28) = uVar5;
    *(undefined8 *)(param_1[-1] + param_3 + 0x30) = uVar6;
    *(undefined8 *)(param_1[-1] + param_3 + 0x38) = uVar7;
    break;
  default:
    uVar9 = 0x40U - (longlong)param_1 & 0x3f;
    if (uVar9 != 0) {
      param_3 = param_3 - uVar9;
      switch(uVar9) {
      case 1:
        (*param_1)[0] = (*param_2)[0];
        break;
      case 2:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        break;
      case 3:
        *(undefined2 *)*param_1 = *(undefined2 *)*param_2;
        (*param_1)[2] = (*param_2)[2];
        break;
      case 4:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        break;
      case 5:
      case 6:
      case 7:
        *(undefined4 *)*param_1 = *(undefined4 *)*param_2;
        *(undefined4 *)(param_1[-1] + uVar9 + 0x3c) = *(undefined4 *)(param_2[-1] + uVar9 + 0x3c);
        break;
      case 8:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        break;
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(param_1[-1] + uVar9 + 0x38) = *(undefined8 *)(param_2[-1] + uVar9 + 0x38);
        break;
      case 0x10:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x1f:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        uVar1 = *(undefined8 *)(param_2[-1] + uVar9 + 0x38);
        *(undefined8 *)(param_1[-1] + uVar9 + 0x30) = *(undefined8 *)(param_2[-1] + uVar9 + 0x30);
        *(undefined8 *)(param_1[-1] + uVar9 + 0x38) = uVar1;
        break;
      case 0x20:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        uVar2 = *(undefined8 *)(*param_2 + 0x10);
        uVar3 = *(undefined8 *)(*param_2 + 0x18);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        *(undefined8 *)(*param_1 + 0x10) = uVar2;
        *(undefined8 *)(*param_1 + 0x18) = uVar3;
        break;
      default:
        uVar1 = *(undefined8 *)(*param_2 + 8);
        uVar2 = *(undefined8 *)(*param_2 + 0x10);
        uVar3 = *(undefined8 *)(*param_2 + 0x18);
        *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
        *(undefined8 *)(*param_1 + 8) = uVar1;
        *(undefined8 *)(*param_1 + 0x10) = uVar2;
        *(undefined8 *)(*param_1 + 0x18) = uVar3;
        uVar1 = *(undefined8 *)(param_2[-1] + uVar9 + 0x28);
        uVar2 = *(undefined8 *)(param_2[-1] + uVar9 + 0x30);
        uVar3 = *(undefined8 *)(param_2[-1] + uVar9 + 0x38);
        *(undefined8 *)(param_1[-1] + uVar9 + 0x20) = *(undefined8 *)(param_2[-1] + uVar9 + 0x20);
        *(undefined8 *)(param_1[-1] + uVar9 + 0x28) = uVar1;
        *(undefined8 *)(param_1[-1] + uVar9 + 0x30) = uVar2;
        *(undefined8 *)(param_1[-1] + uVar9 + 0x38) = uVar3;
      }
      param_1 = (undefined1 (*) [64])(*param_1 + uVar9);
      param_2 = (undefined1 (*) [64])(*param_2 + uVar9);
    }
    pauVar8 = param_2;
    pauVar10 = param_1;
    if (0x1ff < (longlong)param_3) {
      if (param_3 < DAT_180018864) {
        do {
          auVar11 = vmovdqu64_avx512f(*param_2);
          *param_1 = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[1]);
          param_1[1] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[2]);
          param_1[2] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[3]);
          param_1[3] = auVar11;
          pauVar10 = param_1 + 8;
          pauVar8 = param_2 + 8;
          param_3 = param_3 - 0x200;
          auVar11 = vmovdqu64_avx512f(param_2[4]);
          param_1[4] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[5]);
          param_1[5] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[6]);
          param_1[6] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[7]);
          param_1[7] = auVar11;
          param_2 = pauVar8;
          param_1 = pauVar10;
        } while (0x1ff < (longlong)param_3);
      }
      else {
        do {
          auVar11 = vmovdqu64_avx512f(*param_2);
          auVar11 = vmovntdq_avx512f(auVar11);
          *param_1 = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[1]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[1] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[2]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[2] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[3]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[3] = auVar11;
          pauVar10 = param_1 + 8;
          pauVar8 = param_2 + 8;
          param_3 = param_3 - 0x200;
          auVar11 = vmovdqu64_avx512f(param_2[4]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[4] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[5]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[5] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[6]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[6] = auVar11;
          auVar11 = vmovdqu64_avx512f(param_2[7]);
          auVar11 = vmovntdq_avx512f(auVar11);
          param_1[7] = auVar11;
          param_2 = pauVar8;
          param_1 = pauVar10;
        } while (0x1ff < (longlong)param_3);
      }
    }
                    // WARNING: Could not recover jumptable at 0x00018000c3de. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)(&DAT_18000c740 + -*(longlong *)(&DAT_18000c740 + param_3 * 8)))
              (*pauVar10 + param_3,
               (longlong)pauVar8 +
               (param_3 -
               ((longlong)(*pauVar10 + param_3) -
               ((ulonglong)(*pauVar10 + param_3) & 0xffffffffffffffc0))),param_3,
               &DAT_18000c740 + -*(longlong *)(&DAT_18000c740 + param_3 * 8));
    return;
  }
  return;
}



byte * FUN_18000db80(byte *param_1,byte param_2,longlong param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  pbVar1 = param_1;
  if (param_3 == 1) {
    *param_1 = param_2;
    return pbVar1;
  }
  if (param_3 < 1) {
    return pbVar1;
  }
  lVar6 = (ulonglong)param_2 * 0x101010101010101;
  bVar3 = (byte)lVar6;
  uVar4 = (undefined2)lVar6;
  uVar5 = (undefined4)lVar6;
  if ((((ulonglong)param_1 & 7) != 0) && (8 < param_3)) {
    uVar8 = (ulonglong)param_1 & 7;
    lVar7 = 8 - uVar8;
    param_1 = param_1 + lVar7;
    param_3 = param_3 - lVar7;
    switch(uVar8) {
    case 1:
      *(undefined4 *)(param_1 + -7) = uVar5;
    case 5:
      *(undefined2 *)(param_1 + -3) = uVar4;
      param_1[-1] = bVar3;
      break;
    case 2:
      *(undefined4 *)(param_1 + -6) = uVar5;
    case 6:
      *(undefined2 *)(param_1 + -2) = uVar4;
      break;
    case 3:
      *(undefined4 *)(param_1 + -5) = uVar5;
    case 7:
      param_1[-1] = bVar3;
      break;
    case 4:
      *(undefined4 *)(param_1 + -4) = uVar5;
    }
  }
  if (param_3 < 0x80) {
    pbVar2 = param_1 + param_3;
    switch(param_3) {
    case 0:
      goto switchD_18000dbc3_caseD_0;
    case 1:
      goto switchD_18000dbc3_caseD_1;
    case 2:
      goto switchD_18000dbc3_caseD_2;
    case 3:
      goto switchD_18000dbc3_caseD_3;
    case 4:
      goto switchD_18000dbc3_caseD_4;
    case 5:
      goto switchD_18000dbc3_caseD_5;
    case 6:
      goto switchD_18000dbc3_caseD_6;
    case 7:
      goto switchD_18000dbc3_caseD_7;
    case 8:
      goto switchD_18000dbc3_caseD_8;
    case 9:
      goto switchD_18000dbc3_caseD_9;
    case 10:
      goto switchD_18000dbc3_caseD_a;
    case 0xb:
      goto switchD_18000dbc3_caseD_b;
    case 0xc:
      goto switchD_18000dbc3_caseD_c;
    case 0xd:
      goto switchD_18000dbc3_caseD_d;
    case 0xe:
      goto switchD_18000dbc3_caseD_e;
    case 0xf:
      goto switchD_18000dbc3_caseD_f;
    case 0x10:
      goto switchD_18000dbc3_caseD_10;
    case 0x11:
      goto switchD_18000dbc3_caseD_11;
    case 0x12:
      goto switchD_18000dbc3_caseD_12;
    case 0x13:
      goto switchD_18000dbc3_caseD_13;
    case 0x14:
      goto switchD_18000dbc3_caseD_14;
    case 0x15:
      goto switchD_18000dbc3_caseD_15;
    case 0x16:
      goto switchD_18000dbc3_caseD_16;
    case 0x17:
      goto switchD_18000dbc3_caseD_17;
    case 0x18:
      goto switchD_18000dbc3_caseD_18;
    case 0x19:
      goto switchD_18000dbc3_caseD_19;
    case 0x1a:
      goto switchD_18000dbc3_caseD_1a;
    case 0x1b:
      goto switchD_18000dbc3_caseD_1b;
    case 0x1c:
      goto switchD_18000dbc3_caseD_1c;
    case 0x1d:
      goto switchD_18000dbc3_caseD_1d;
    case 0x1e:
      goto switchD_18000dbc3_caseD_1e;
    case 0x1f:
      goto switchD_18000dbc3_caseD_1f;
    case 0x20:
      goto switchD_18000dbc3_caseD_20;
    case 0x21:
      goto switchD_18000dbc3_caseD_21;
    case 0x22:
      goto switchD_18000dbc3_caseD_22;
    case 0x23:
      goto switchD_18000dbc3_caseD_23;
    case 0x24:
      goto switchD_18000dbc3_caseD_24;
    case 0x25:
      goto switchD_18000dbc3_caseD_25;
    case 0x26:
      goto switchD_18000dbc3_caseD_26;
    case 0x27:
      goto switchD_18000dbc3_caseD_27;
    case 0x28:
      goto switchD_18000dbc3_caseD_28;
    case 0x29:
      goto switchD_18000dbc3_caseD_29;
    case 0x2a:
      goto switchD_18000dbc3_caseD_2a;
    case 0x2b:
      goto switchD_18000dbc3_caseD_2b;
    case 0x2c:
      goto switchD_18000dbc3_caseD_2c;
    case 0x2d:
      goto switchD_18000dbc3_caseD_2d;
    case 0x2e:
      goto switchD_18000dbc3_caseD_2e;
    case 0x2f:
      goto switchD_18000dbc3_caseD_2f;
    case 0x30:
      goto switchD_18000dbc3_caseD_30;
    case 0x31:
      goto switchD_18000dbc3_caseD_31;
    case 0x32:
      goto switchD_18000dbc3_caseD_32;
    case 0x33:
      goto switchD_18000dbc3_caseD_33;
    case 0x34:
      goto switchD_18000dbc3_caseD_34;
    case 0x35:
      goto switchD_18000dbc3_caseD_35;
    case 0x36:
      goto switchD_18000dbc3_caseD_36;
    case 0x37:
      goto switchD_18000dbc3_caseD_37;
    case 0x38:
      break;
    case 0x39:
      goto switchD_18000dbc3_caseD_39;
    case 0x3a:
      goto switchD_18000dbc3_caseD_3a;
    case 0x3b:
      goto switchD_18000dbc3_caseD_3b;
    case 0x3c:
      goto switchD_18000dbc3_caseD_3c;
    case 0x3d:
      goto switchD_18000dbc3_caseD_3d;
    case 0x3e:
      goto switchD_18000dbc3_caseD_3e;
    case 0x3f:
      goto switchD_18000dbc3_caseD_3f;
    case 0x78:
      *(longlong *)(pbVar2 + -0x78) = lVar6;
    case 0x70:
      *(longlong *)(pbVar2 + -0x70) = lVar6;
    case 0x68:
      *(longlong *)(pbVar2 + -0x68) = lVar6;
    case 0x60:
      *(longlong *)(pbVar2 + -0x60) = lVar6;
    case 0x58:
      *(longlong *)(pbVar2 + -0x58) = lVar6;
    case 0x50:
      *(longlong *)(pbVar2 + -0x50) = lVar6;
    case 0x48:
      *(longlong *)(pbVar2 + -0x48) = lVar6;
    case 0x40:
switchD_18000dbc3_caseD_40:
      *(longlong *)(pbVar2 + -0x40) = lVar6;
      break;
    case 0x79:
      *(longlong *)(pbVar2 + -0x79) = lVar6;
    case 0x71:
      *(longlong *)(pbVar2 + -0x71) = lVar6;
    case 0x69:
      *(longlong *)(pbVar2 + -0x69) = lVar6;
    case 0x61:
      *(longlong *)(pbVar2 + -0x61) = lVar6;
    case 0x59:
      *(longlong *)(pbVar2 + -0x59) = lVar6;
    case 0x51:
      *(longlong *)(pbVar2 + -0x51) = lVar6;
    case 0x49:
      *(longlong *)(pbVar2 + -0x49) = lVar6;
    case 0x41:
      *(longlong *)(pbVar2 + -0x41) = lVar6;
switchD_18000dbc3_caseD_39:
      *(longlong *)(pbVar2 + -0x39) = lVar6;
      goto switchD_18000dbc3_caseD_31;
    case 0x7a:
      *(longlong *)(pbVar2 + -0x7a) = lVar6;
    case 0x72:
      *(longlong *)(pbVar2 + -0x72) = lVar6;
    case 0x6a:
      *(longlong *)(pbVar2 + -0x6a) = lVar6;
    case 0x62:
      *(longlong *)(pbVar2 + -0x62) = lVar6;
    case 0x5a:
      *(longlong *)(pbVar2 + -0x5a) = lVar6;
    case 0x52:
      *(longlong *)(pbVar2 + -0x52) = lVar6;
    case 0x4a:
      *(longlong *)(pbVar2 + -0x4a) = lVar6;
    case 0x42:
      *(longlong *)(pbVar2 + -0x42) = lVar6;
switchD_18000dbc3_caseD_3a:
      *(longlong *)(pbVar2 + -0x3a) = lVar6;
      goto switchD_18000dbc3_caseD_32;
    case 0x7b:
      *(longlong *)(pbVar2 + -0x7b) = lVar6;
    case 0x73:
      *(longlong *)(pbVar2 + -0x73) = lVar6;
    case 0x6b:
      *(longlong *)(pbVar2 + -0x6b) = lVar6;
    case 99:
      *(longlong *)(pbVar2 + -99) = lVar6;
    case 0x5b:
      *(longlong *)(pbVar2 + -0x5b) = lVar6;
    case 0x53:
      *(longlong *)(pbVar2 + -0x53) = lVar6;
    case 0x4b:
      *(longlong *)(pbVar2 + -0x4b) = lVar6;
    case 0x43:
      *(longlong *)(pbVar2 + -0x43) = lVar6;
switchD_18000dbc3_caseD_3b:
      *(longlong *)(pbVar2 + -0x3b) = lVar6;
      goto switchD_18000dbc3_caseD_33;
    case 0x7c:
      *(longlong *)(pbVar2 + -0x7c) = lVar6;
    case 0x74:
      *(longlong *)(pbVar2 + -0x74) = lVar6;
    case 0x6c:
      *(longlong *)(pbVar2 + -0x6c) = lVar6;
    case 100:
      *(longlong *)(pbVar2 + -100) = lVar6;
    case 0x5c:
      *(longlong *)(pbVar2 + -0x5c) = lVar6;
    case 0x54:
      *(longlong *)(pbVar2 + -0x54) = lVar6;
    case 0x4c:
      *(longlong *)(pbVar2 + -0x4c) = lVar6;
    case 0x44:
      *(longlong *)(pbVar2 + -0x44) = lVar6;
switchD_18000dbc3_caseD_3c:
      *(longlong *)(pbVar2 + -0x3c) = lVar6;
      goto switchD_18000dbc3_caseD_34;
    case 0x7d:
      *(longlong *)(pbVar2 + -0x7d) = lVar6;
    case 0x75:
      *(longlong *)(pbVar2 + -0x75) = lVar6;
    case 0x6d:
      *(longlong *)(pbVar2 + -0x6d) = lVar6;
    case 0x65:
      *(longlong *)(pbVar2 + -0x65) = lVar6;
    case 0x5d:
      *(longlong *)(pbVar2 + -0x5d) = lVar6;
    case 0x55:
      *(longlong *)(pbVar2 + -0x55) = lVar6;
    case 0x4d:
      *(longlong *)(pbVar2 + -0x4d) = lVar6;
    case 0x45:
      *(longlong *)(pbVar2 + -0x45) = lVar6;
switchD_18000dbc3_caseD_3d:
      *(longlong *)(pbVar2 + -0x3d) = lVar6;
      goto switchD_18000dbc3_caseD_35;
    case 0x7e:
      *(longlong *)(pbVar2 + -0x7e) = lVar6;
    case 0x76:
      *(longlong *)(pbVar2 + -0x76) = lVar6;
    case 0x6e:
      *(longlong *)(pbVar2 + -0x6e) = lVar6;
    case 0x66:
      *(longlong *)(pbVar2 + -0x66) = lVar6;
    case 0x5e:
      *(longlong *)(pbVar2 + -0x5e) = lVar6;
    case 0x56:
      *(longlong *)(pbVar2 + -0x56) = lVar6;
    case 0x4e:
      *(longlong *)(pbVar2 + -0x4e) = lVar6;
    case 0x46:
      *(longlong *)(pbVar2 + -0x46) = lVar6;
switchD_18000dbc3_caseD_3e:
      *(longlong *)(pbVar2 + -0x3e) = lVar6;
      goto switchD_18000dbc3_caseD_36;
    case 0x7f:
      *(longlong *)(pbVar2 + -0x7f) = lVar6;
    case 0x77:
      *(longlong *)(pbVar2 + -0x77) = lVar6;
    case 0x6f:
      *(longlong *)(pbVar2 + -0x6f) = lVar6;
    case 0x67:
      *(longlong *)(pbVar2 + -0x67) = lVar6;
    case 0x5f:
      *(longlong *)(pbVar2 + -0x5f) = lVar6;
    case 0x57:
      *(longlong *)(pbVar2 + -0x57) = lVar6;
    case 0x4f:
      *(longlong *)(pbVar2 + -0x4f) = lVar6;
    case 0x47:
      *(longlong *)(pbVar2 + -0x47) = lVar6;
switchD_18000dbc3_caseD_3f:
      *(longlong *)(pbVar2 + -0x3f) = lVar6;
      goto switchD_18000dbc3_caseD_37;
    }
switchD_18000dbc3_caseD_38:
    *(longlong *)(pbVar2 + -0x38) = lVar6;
    goto switchD_18000dbc3_caseD_30;
  }
  if (1 < DAT_180019464) {
    uVar8 = 0x10 - ((ulonglong)param_1 & 0xf) & 0xf;
    pbVar2 = param_1 + uVar8;
    lVar7 = param_3 - uVar8;
    switch(uVar8) {
    case 8:
      *(longlong *)(pbVar2 + -8) = lVar6;
    case 0:
      break;
    case 9:
      *(longlong *)(pbVar2 + -9) = lVar6;
    case 1:
      pbVar2[-1] = bVar3;
      break;
    case 10:
      *(longlong *)(pbVar2 + -10) = lVar6;
    case 2:
      *(undefined2 *)(pbVar2 + -2) = uVar4;
      break;
    case 0xb:
      *(longlong *)(pbVar2 + -0xb) = lVar6;
    case 3:
      *(undefined2 *)(pbVar2 + -3) = uVar4;
      pbVar2[-1] = bVar3;
      break;
    case 0xc:
      *(longlong *)(pbVar2 + -0xc) = lVar6;
    case 4:
      *(undefined4 *)(pbVar2 + -4) = uVar5;
      break;
    case 0xd:
      *(longlong *)(pbVar2 + -0xd) = lVar6;
    case 5:
      *(undefined4 *)(pbVar2 + -5) = uVar5;
      pbVar2[-1] = bVar3;
      break;
    case 0xe:
      *(longlong *)(pbVar2 + -0xe) = lVar6;
    case 6:
      *(undefined4 *)(pbVar2 + -6) = uVar5;
      *(undefined2 *)(pbVar2 + -2) = uVar4;
      break;
    case 0xf:
      *(longlong *)(pbVar2 + -0xf) = lVar6;
    case 7:
      *(undefined4 *)(pbVar2 + -7) = uVar5;
      *(undefined2 *)(pbVar2 + -3) = uVar4;
      pbVar2[-1] = bVar3;
    }
    if (lVar7 < 0xb0) {
      pbVar2 = pbVar2 + lVar7;
      switch(lVar7) {
      case 0:
        goto switchD_18000df12_caseD_0;
      case 1:
        goto switchD_18000df12_caseD_1;
      case 2:
        goto switchD_18000df12_caseD_2;
      case 3:
        goto switchD_18000df12_caseD_3;
      case 4:
        goto switchD_18000df12_caseD_4;
      case 5:
        goto switchD_18000df12_caseD_5;
      case 6:
        goto switchD_18000df12_caseD_6;
      case 7:
        goto switchD_18000df12_caseD_7;
      case 8:
        goto switchD_18000df12_caseD_8;
      case 9:
        goto switchD_18000df12_caseD_9;
      case 10:
        goto switchD_18000df12_caseD_a;
      case 0xb:
        goto switchD_18000df12_caseD_b;
      case 0xc:
        goto switchD_18000df12_caseD_c;
      case 0xd:
        goto switchD_18000df12_caseD_d;
      case 0xe:
        goto switchD_18000df12_caseD_e;
      case 0xf:
        goto switchD_18000df12_caseD_f;
      case 0x10:
        goto switchD_18000df12_caseD_10;
      case 0x11:
        goto switchD_18000df12_caseD_11;
      case 0x12:
        goto switchD_18000df12_caseD_12;
      case 0x13:
        goto switchD_18000df12_caseD_13;
      case 0x14:
        goto switchD_18000df12_caseD_14;
      case 0x15:
        goto switchD_18000df12_caseD_15;
      case 0x16:
        goto switchD_18000df12_caseD_16;
      case 0x17:
        goto switchD_18000df12_caseD_17;
      case 0x18:
        goto switchD_18000df12_caseD_18;
      case 0x19:
        goto switchD_18000df12_caseD_19;
      case 0x1a:
        goto switchD_18000df12_caseD_1a;
      case 0x1b:
        goto switchD_18000df12_caseD_1b;
      case 0x1c:
        goto switchD_18000df12_caseD_1c;
      case 0x1d:
        goto switchD_18000df12_caseD_1d;
      case 0x1e:
        goto switchD_18000df12_caseD_1e;
      case 0x1f:
        goto switchD_18000df12_caseD_1f;
      case 0x20:
        goto switchD_18000df12_caseD_20;
      case 0x21:
        goto switchD_18000df12_caseD_21;
      case 0x22:
        goto switchD_18000df12_caseD_22;
      case 0x23:
        goto switchD_18000df12_caseD_23;
      case 0x24:
        goto switchD_18000df12_caseD_24;
      case 0x25:
        goto switchD_18000df12_caseD_25;
      case 0x26:
        goto switchD_18000df12_caseD_26;
      case 0x27:
        goto switchD_18000df12_caseD_27;
      case 0x28:
        goto switchD_18000df12_caseD_28;
      case 0x29:
        goto switchD_18000df12_caseD_29;
      case 0x2a:
        goto switchD_18000df12_caseD_2a;
      case 0x2b:
        goto switchD_18000df12_caseD_2b;
      case 0x2c:
        goto switchD_18000df12_caseD_2c;
      case 0x2d:
        goto switchD_18000df12_caseD_2d;
      case 0x2e:
        goto switchD_18000df12_caseD_2e;
      case 0x2f:
        goto switchD_18000df12_caseD_2f;
      case 0x30:
        goto switchD_18000df12_caseD_30;
      case 0x31:
        goto switchD_18000df12_caseD_31;
      case 0x32:
        goto switchD_18000df12_caseD_32;
      case 0x33:
        goto switchD_18000df12_caseD_33;
      case 0x34:
        goto switchD_18000df12_caseD_34;
      case 0x35:
        goto switchD_18000df12_caseD_35;
      case 0x36:
        goto switchD_18000df12_caseD_36;
      case 0x37:
        goto switchD_18000df12_caseD_37;
      case 0x38:
        goto switchD_18000df12_caseD_38;
      case 0x39:
        goto switchD_18000df12_caseD_39;
      case 0x3a:
        goto switchD_18000df12_caseD_3a;
      case 0x3b:
        goto switchD_18000df12_caseD_3b;
      case 0x3c:
        goto switchD_18000df12_caseD_3c;
      case 0x3d:
        goto switchD_18000df12_caseD_3d;
      case 0x3e:
        goto switchD_18000df12_caseD_3e;
      case 0x3f:
        goto switchD_18000df12_caseD_3f;
      case 0x40:
        goto switchD_18000df12_caseD_40;
      case 0x41:
        goto switchD_18000df12_caseD_41;
      case 0x42:
        goto switchD_18000df12_caseD_42;
      case 0x43:
        goto switchD_18000df12_caseD_43;
      case 0x44:
        goto switchD_18000df12_caseD_44;
      case 0x45:
        goto switchD_18000df12_caseD_45;
      case 0x46:
        goto switchD_18000df12_caseD_46;
      case 0x47:
        goto switchD_18000df12_caseD_47;
      case 0x48:
        goto switchD_18000df12_caseD_48;
      case 0x49:
        goto switchD_18000df12_caseD_49;
      case 0x4a:
        goto switchD_18000df12_caseD_4a;
      case 0x4b:
        goto switchD_18000df12_caseD_4b;
      case 0x4c:
        goto switchD_18000df12_caseD_4c;
      case 0x4d:
        goto switchD_18000df12_caseD_4d;
      case 0x4e:
        goto switchD_18000df12_caseD_4e;
      case 0x4f:
        goto switchD_18000df12_caseD_4f;
      case 0x50:
        goto switchD_18000df12_caseD_50;
      case 0x51:
        goto switchD_18000df12_caseD_51;
      case 0x52:
        goto switchD_18000df12_caseD_52;
      case 0x53:
        goto switchD_18000df12_caseD_53;
      case 0x54:
        goto switchD_18000df12_caseD_54;
      case 0x55:
        goto switchD_18000df12_caseD_55;
      case 0x56:
        goto switchD_18000df12_caseD_56;
      case 0x57:
        goto switchD_18000df12_caseD_57;
      case 0x58:
        goto switchD_18000df12_caseD_58;
      case 0x59:
        goto switchD_18000df12_caseD_59;
      case 0x5a:
        goto switchD_18000df12_caseD_5a;
      case 0x5b:
        goto switchD_18000df12_caseD_5b;
      case 0x5c:
        goto switchD_18000df12_caseD_5c;
      case 0x5d:
        goto switchD_18000df12_caseD_5d;
      case 0x5e:
        goto switchD_18000df12_caseD_5e;
      case 0x5f:
        goto switchD_18000df12_caseD_5f;
      case 0x60:
        goto switchD_18000df12_caseD_60;
      case 0x61:
        goto switchD_18000df12_caseD_61;
      case 0x62:
        goto switchD_18000df12_caseD_62;
      case 99:
        goto switchD_18000df12_caseD_63;
      case 100:
        goto switchD_18000df12_caseD_64;
      case 0x65:
        goto switchD_18000df12_caseD_65;
      case 0x66:
        goto switchD_18000df12_caseD_66;
      case 0x67:
        goto switchD_18000df12_caseD_67;
      case 0x68:
        goto switchD_18000df12_caseD_68;
      case 0x69:
        goto switchD_18000df12_caseD_69;
      case 0x6a:
        goto switchD_18000df12_caseD_6a;
      case 0x6b:
        goto switchD_18000df12_caseD_6b;
      case 0x6c:
        goto switchD_18000df12_caseD_6c;
      case 0x6d:
        goto switchD_18000df12_caseD_6d;
      case 0x6e:
        goto switchD_18000df12_caseD_6e;
      case 0x6f:
        goto switchD_18000df12_caseD_6f;
      case 0x70:
        break;
      case 0x71:
        goto switchD_18000df12_caseD_71;
      case 0x72:
        goto switchD_18000df12_caseD_72;
      case 0x73:
        goto switchD_18000df12_caseD_73;
      case 0x74:
        goto switchD_18000df12_caseD_74;
      case 0x75:
        goto switchD_18000df12_caseD_75;
      case 0x76:
        goto switchD_18000df12_caseD_76;
      case 0x77:
        goto switchD_18000df12_caseD_77;
      case 0x78:
        goto switchD_18000df12_caseD_78;
      case 0x79:
        goto switchD_18000df12_caseD_79;
      case 0x7a:
        goto switchD_18000df12_caseD_7a;
      case 0x7b:
        goto switchD_18000df12_caseD_7b;
      case 0x7c:
        goto switchD_18000df12_caseD_7c;
      case 0x7d:
        goto switchD_18000df12_caseD_7d;
      case 0x7e:
        goto switchD_18000df12_caseD_7e;
      case 0x7f:
        goto switchD_18000df12_caseD_7f;
      case 0xa0:
        *(longlong *)(pbVar2 + -0xa0) = lVar6;
        *(longlong *)(pbVar2 + -0x98) = lVar6;
      case 0x90:
        *(longlong *)(pbVar2 + -0x90) = lVar6;
        *(longlong *)(pbVar2 + -0x88) = lVar6;
      case 0x80:
        *(longlong *)(pbVar2 + -0x80) = lVar6;
        *(longlong *)(pbVar2 + -0x78) = lVar6;
        break;
      case 0xa1:
        *(longlong *)(pbVar2 + -0xa1) = lVar6;
        *(longlong *)(pbVar2 + -0x99) = lVar6;
      case 0x91:
        *(longlong *)(pbVar2 + -0x91) = lVar6;
        *(longlong *)(pbVar2 + -0x89) = lVar6;
      case 0x81:
        *(longlong *)(pbVar2 + -0x81) = lVar6;
        *(longlong *)(pbVar2 + -0x79) = lVar6;
switchD_18000df12_caseD_71:
        *(longlong *)(pbVar2 + -0x71) = lVar6;
        *(longlong *)(pbVar2 + -0x69) = lVar6;
        goto switchD_18000df12_caseD_61;
      case 0xa2:
        *(longlong *)(pbVar2 + -0xa2) = lVar6;
        *(longlong *)(pbVar2 + -0x9a) = lVar6;
      case 0x92:
        *(longlong *)(pbVar2 + -0x92) = lVar6;
        *(longlong *)(pbVar2 + -0x8a) = lVar6;
      case 0x82:
        *(longlong *)(pbVar2 + -0x82) = lVar6;
        *(longlong *)(pbVar2 + -0x7a) = lVar6;
switchD_18000df12_caseD_72:
        *(longlong *)(pbVar2 + -0x72) = lVar6;
        *(longlong *)(pbVar2 + -0x6a) = lVar6;
        goto switchD_18000df12_caseD_62;
      case 0xa3:
        *(longlong *)(pbVar2 + -0xa3) = lVar6;
        *(longlong *)(pbVar2 + -0x9b) = lVar6;
      case 0x93:
        *(longlong *)(pbVar2 + -0x93) = lVar6;
        *(longlong *)(pbVar2 + -0x8b) = lVar6;
      case 0x83:
        *(longlong *)(pbVar2 + -0x83) = lVar6;
        *(longlong *)(pbVar2 + -0x7b) = lVar6;
switchD_18000df12_caseD_73:
        *(longlong *)(pbVar2 + -0x73) = lVar6;
        *(longlong *)(pbVar2 + -0x6b) = lVar6;
        goto switchD_18000df12_caseD_63;
      case 0xa4:
        *(longlong *)(pbVar2 + -0xa4) = lVar6;
        *(longlong *)(pbVar2 + -0x9c) = lVar6;
      case 0x94:
        *(longlong *)(pbVar2 + -0x94) = lVar6;
        *(longlong *)(pbVar2 + -0x8c) = lVar6;
      case 0x84:
        *(longlong *)(pbVar2 + -0x84) = lVar6;
        *(longlong *)(pbVar2 + -0x7c) = lVar6;
switchD_18000df12_caseD_74:
        *(longlong *)(pbVar2 + -0x74) = lVar6;
        *(longlong *)(pbVar2 + -0x6c) = lVar6;
        goto switchD_18000df12_caseD_64;
      case 0xa5:
        *(longlong *)(pbVar2 + -0xa5) = lVar6;
        *(longlong *)(pbVar2 + -0x9d) = lVar6;
      case 0x95:
        *(longlong *)(pbVar2 + -0x95) = lVar6;
        *(longlong *)(pbVar2 + -0x8d) = lVar6;
      case 0x85:
        *(longlong *)(pbVar2 + -0x85) = lVar6;
        *(longlong *)(pbVar2 + -0x7d) = lVar6;
switchD_18000df12_caseD_75:
        *(longlong *)(pbVar2 + -0x75) = lVar6;
        *(longlong *)(pbVar2 + -0x6d) = lVar6;
        goto switchD_18000df12_caseD_65;
      case 0xa6:
        *(longlong *)(pbVar2 + -0xa6) = lVar6;
        *(longlong *)(pbVar2 + -0x9e) = lVar6;
      case 0x96:
        *(longlong *)(pbVar2 + -0x96) = lVar6;
        *(longlong *)(pbVar2 + -0x8e) = lVar6;
      case 0x86:
        *(longlong *)(pbVar2 + -0x86) = lVar6;
        *(longlong *)(pbVar2 + -0x7e) = lVar6;
switchD_18000df12_caseD_76:
        *(longlong *)(pbVar2 + -0x76) = lVar6;
        *(longlong *)(pbVar2 + -0x6e) = lVar6;
        goto switchD_18000df12_caseD_66;
      case 0xa7:
        *(longlong *)(pbVar2 + -0xa7) = lVar6;
        *(longlong *)(pbVar2 + -0x9f) = lVar6;
      case 0x97:
        *(longlong *)(pbVar2 + -0x97) = lVar6;
        *(longlong *)(pbVar2 + -0x8f) = lVar6;
      case 0x87:
        *(longlong *)(pbVar2 + -0x87) = lVar6;
        *(longlong *)(pbVar2 + -0x7f) = lVar6;
switchD_18000df12_caseD_77:
        *(longlong *)(pbVar2 + -0x77) = lVar6;
        *(longlong *)(pbVar2 + -0x6f) = lVar6;
        goto switchD_18000df12_caseD_67;
      case 0xa8:
        *(longlong *)(pbVar2 + -0xa8) = lVar6;
        *(longlong *)(pbVar2 + -0xa0) = lVar6;
      case 0x98:
        *(longlong *)(pbVar2 + -0x98) = lVar6;
        *(longlong *)(pbVar2 + -0x90) = lVar6;
      case 0x88:
        *(longlong *)(pbVar2 + -0x88) = lVar6;
        *(longlong *)(pbVar2 + -0x80) = lVar6;
switchD_18000df12_caseD_78:
        *(longlong *)(pbVar2 + -0x78) = lVar6;
        *(longlong *)(pbVar2 + -0x70) = lVar6;
        goto switchD_18000df12_caseD_68;
      case 0xa9:
        *(longlong *)(pbVar2 + -0xa9) = lVar6;
        *(longlong *)(pbVar2 + -0xa1) = lVar6;
      case 0x99:
        *(longlong *)(pbVar2 + -0x99) = lVar6;
        *(longlong *)(pbVar2 + -0x91) = lVar6;
      case 0x89:
        *(longlong *)(pbVar2 + -0x89) = lVar6;
        *(longlong *)(pbVar2 + -0x81) = lVar6;
switchD_18000df12_caseD_79:
        *(longlong *)(pbVar2 + -0x79) = lVar6;
        *(longlong *)(pbVar2 + -0x71) = lVar6;
        goto switchD_18000df12_caseD_69;
      case 0xaa:
        *(longlong *)(pbVar2 + -0xaa) = lVar6;
        *(longlong *)(pbVar2 + -0xa2) = lVar6;
      case 0x9a:
        *(longlong *)(pbVar2 + -0x9a) = lVar6;
        *(longlong *)(pbVar2 + -0x92) = lVar6;
      case 0x8a:
        *(longlong *)(pbVar2 + -0x8a) = lVar6;
        *(longlong *)(pbVar2 + -0x82) = lVar6;
switchD_18000df12_caseD_7a:
        *(longlong *)(pbVar2 + -0x7a) = lVar6;
        *(longlong *)(pbVar2 + -0x72) = lVar6;
        goto switchD_18000df12_caseD_6a;
      case 0xab:
        *(longlong *)(pbVar2 + -0xab) = lVar6;
        *(longlong *)(pbVar2 + -0xa3) = lVar6;
      case 0x9b:
        *(longlong *)(pbVar2 + -0x9b) = lVar6;
        *(longlong *)(pbVar2 + -0x93) = lVar6;
      case 0x8b:
        *(longlong *)(pbVar2 + -0x8b) = lVar6;
        *(longlong *)(pbVar2 + -0x83) = lVar6;
switchD_18000df12_caseD_7b:
        *(longlong *)(pbVar2 + -0x7b) = lVar6;
        *(longlong *)(pbVar2 + -0x73) = lVar6;
        goto switchD_18000df12_caseD_6b;
      case 0xac:
        *(longlong *)(pbVar2 + -0xac) = lVar6;
        *(longlong *)(pbVar2 + -0xa4) = lVar6;
      case 0x9c:
        *(longlong *)(pbVar2 + -0x9c) = lVar6;
        *(longlong *)(pbVar2 + -0x94) = lVar6;
      case 0x8c:
        *(longlong *)(pbVar2 + -0x8c) = lVar6;
        *(longlong *)(pbVar2 + -0x84) = lVar6;
switchD_18000df12_caseD_7c:
        *(longlong *)(pbVar2 + -0x7c) = lVar6;
        *(longlong *)(pbVar2 + -0x74) = lVar6;
        goto switchD_18000df12_caseD_6c;
      case 0xad:
        *(longlong *)(pbVar2 + -0xad) = lVar6;
        *(longlong *)(pbVar2 + -0xa5) = lVar6;
      case 0x9d:
        *(longlong *)(pbVar2 + -0x9d) = lVar6;
        *(longlong *)(pbVar2 + -0x95) = lVar6;
      case 0x8d:
        *(longlong *)(pbVar2 + -0x8d) = lVar6;
        *(longlong *)(pbVar2 + -0x85) = lVar6;
switchD_18000df12_caseD_7d:
        *(longlong *)(pbVar2 + -0x7d) = lVar6;
        *(longlong *)(pbVar2 + -0x75) = lVar6;
        goto switchD_18000df12_caseD_6d;
      case 0xae:
        *(longlong *)(pbVar2 + -0xae) = lVar6;
        *(longlong *)(pbVar2 + -0xa6) = lVar6;
      case 0x9e:
        *(longlong *)(pbVar2 + -0x9e) = lVar6;
        *(longlong *)(pbVar2 + -0x96) = lVar6;
      case 0x8e:
        *(longlong *)(pbVar2 + -0x8e) = lVar6;
        *(longlong *)(pbVar2 + -0x86) = lVar6;
switchD_18000df12_caseD_7e:
        *(longlong *)(pbVar2 + -0x7e) = lVar6;
        *(longlong *)(pbVar2 + -0x76) = lVar6;
        goto switchD_18000df12_caseD_6e;
      case 0xaf:
        *(longlong *)(pbVar2 + -0xaf) = lVar6;
        *(longlong *)(pbVar2 + -0xa7) = lVar6;
      case 0x9f:
        *(longlong *)(pbVar2 + -0x9f) = lVar6;
        *(longlong *)(pbVar2 + -0x97) = lVar6;
      case 0x8f:
        *(longlong *)(pbVar2 + -0x8f) = lVar6;
        *(longlong *)(pbVar2 + -0x87) = lVar6;
switchD_18000df12_caseD_7f:
        *(longlong *)(pbVar2 + -0x7f) = lVar6;
        *(longlong *)(pbVar2 + -0x77) = lVar6;
        goto switchD_18000df12_caseD_6f;
      }
switchD_18000df12_caseD_70:
      *(longlong *)(pbVar2 + -0x70) = lVar6;
      *(longlong *)(pbVar2 + -0x68) = lVar6;
      goto switchD_18000df12_caseD_60;
    }
    if (((longlong)(ulonglong)DAT_180018860 < lVar7) && ((ulonglong)DAT_180018860 != 0)) {
      do {
        lVar7 = lVar7 + -0x80;
        *(longlong *)pbVar2 = lVar6;
        *(longlong *)(pbVar2 + 8) = lVar6;
        *(longlong *)(pbVar2 + 0x10) = lVar6;
        *(longlong *)(pbVar2 + 0x18) = lVar6;
        *(longlong *)(pbVar2 + 0x20) = lVar6;
        *(longlong *)(pbVar2 + 0x28) = lVar6;
        *(longlong *)(pbVar2 + 0x30) = lVar6;
        *(longlong *)(pbVar2 + 0x38) = lVar6;
        *(longlong *)(pbVar2 + 0x40) = lVar6;
        *(longlong *)(pbVar2 + 0x48) = lVar6;
        *(longlong *)(pbVar2 + 0x50) = lVar6;
        *(longlong *)(pbVar2 + 0x58) = lVar6;
        *(longlong *)(pbVar2 + 0x60) = lVar6;
        *(longlong *)(pbVar2 + 0x68) = lVar6;
        *(longlong *)(pbVar2 + 0x70) = lVar6;
        *(longlong *)(pbVar2 + 0x78) = lVar6;
        pbVar2 = pbVar2 + 0x80;
      } while (0x7f < lVar7);
      pbVar2 = pbVar2 + lVar7;
      switch(lVar7) {
      case 0:
        goto switchD_18000df12_caseD_0;
      case 1:
        goto switchD_18000df12_caseD_1;
      case 2:
        goto switchD_18000df12_caseD_2;
      case 3:
        goto switchD_18000df12_caseD_3;
      case 4:
        goto switchD_18000df12_caseD_4;
      case 5:
        goto switchD_18000df12_caseD_5;
      case 6:
        goto switchD_18000df12_caseD_6;
      case 7:
        goto switchD_18000df12_caseD_7;
      case 8:
        goto switchD_18000df12_caseD_8;
      case 9:
        goto switchD_18000df12_caseD_9;
      case 10:
        goto switchD_18000df12_caseD_a;
      case 0xb:
        goto switchD_18000df12_caseD_b;
      case 0xc:
        goto switchD_18000df12_caseD_c;
      case 0xd:
        goto switchD_18000df12_caseD_d;
      case 0xe:
        goto switchD_18000df12_caseD_e;
      case 0xf:
        goto switchD_18000df12_caseD_f;
      case 0x11:
        goto switchD_18000df12_caseD_11;
      case 0x12:
        goto switchD_18000df12_caseD_12;
      case 0x13:
        goto switchD_18000df12_caseD_13;
      case 0x14:
        goto switchD_18000df12_caseD_14;
      case 0x15:
        goto switchD_18000df12_caseD_15;
      case 0x16:
        goto switchD_18000df12_caseD_16;
      case 0x17:
        goto switchD_18000df12_caseD_17;
      case 0x18:
        goto switchD_18000df12_caseD_18;
      case 0x19:
        goto switchD_18000df12_caseD_19;
      case 0x1a:
        goto switchD_18000df12_caseD_1a;
      case 0x1b:
        goto switchD_18000df12_caseD_1b;
      case 0x1c:
        goto switchD_18000df12_caseD_1c;
      case 0x1d:
        goto switchD_18000df12_caseD_1d;
      case 0x1e:
        goto switchD_18000df12_caseD_1e;
      case 0x1f:
        goto switchD_18000df12_caseD_1f;
      case 0x20:
        goto switchD_18000df12_caseD_20;
      case 0x21:
        goto switchD_18000df12_caseD_21;
      case 0x22:
        goto switchD_18000df12_caseD_22;
      case 0x23:
        goto switchD_18000df12_caseD_23;
      case 0x24:
        goto switchD_18000df12_caseD_24;
      case 0x25:
        goto switchD_18000df12_caseD_25;
      case 0x26:
        goto switchD_18000df12_caseD_26;
      case 0x27:
        goto switchD_18000df12_caseD_27;
      case 0x28:
        goto switchD_18000df12_caseD_28;
      case 0x29:
        goto switchD_18000df12_caseD_29;
      case 0x2a:
        goto switchD_18000df12_caseD_2a;
      case 0x2b:
        goto switchD_18000df12_caseD_2b;
      case 0x2c:
        goto switchD_18000df12_caseD_2c;
      case 0x2d:
        goto switchD_18000df12_caseD_2d;
      case 0x2e:
        goto switchD_18000df12_caseD_2e;
      case 0x2f:
        goto switchD_18000df12_caseD_2f;
      case 0x30:
        goto switchD_18000df12_caseD_30;
      case 0x31:
        goto switchD_18000df12_caseD_31;
      case 0x32:
        goto switchD_18000df12_caseD_32;
      case 0x33:
        goto switchD_18000df12_caseD_33;
      case 0x34:
        goto switchD_18000df12_caseD_34;
      case 0x35:
        goto switchD_18000df12_caseD_35;
      case 0x36:
        goto switchD_18000df12_caseD_36;
      case 0x37:
        goto switchD_18000df12_caseD_37;
      case 0x38:
        goto switchD_18000df12_caseD_38;
      case 0x39:
        goto switchD_18000df12_caseD_39;
      case 0x3a:
        goto switchD_18000df12_caseD_3a;
      case 0x3b:
        goto switchD_18000df12_caseD_3b;
      case 0x3c:
        goto switchD_18000df12_caseD_3c;
      case 0x3d:
        goto switchD_18000df12_caseD_3d;
      case 0x3e:
        goto switchD_18000df12_caseD_3e;
      case 0x3f:
        goto switchD_18000df12_caseD_3f;
      case 0x40:
        goto switchD_18000df12_caseD_40;
      case 0x41:
        goto switchD_18000df12_caseD_41;
      case 0x42:
        goto switchD_18000df12_caseD_42;
      case 0x43:
        goto switchD_18000df12_caseD_43;
      case 0x44:
        goto switchD_18000df12_caseD_44;
      case 0x45:
        goto switchD_18000df12_caseD_45;
      case 0x46:
        goto switchD_18000df12_caseD_46;
      case 0x47:
        goto switchD_18000df12_caseD_47;
      case 0x48:
        goto switchD_18000df12_caseD_48;
      case 0x49:
        goto switchD_18000df12_caseD_49;
      case 0x4a:
        goto switchD_18000df12_caseD_4a;
      case 0x4b:
        goto switchD_18000df12_caseD_4b;
      case 0x4c:
        goto switchD_18000df12_caseD_4c;
      case 0x4d:
        goto switchD_18000df12_caseD_4d;
      case 0x4e:
        goto switchD_18000df12_caseD_4e;
      case 0x4f:
        goto switchD_18000df12_caseD_4f;
      case 0x50:
        goto switchD_18000df12_caseD_50;
      case 0x51:
        goto switchD_18000df12_caseD_51;
      case 0x52:
        goto switchD_18000df12_caseD_52;
      case 0x53:
        goto switchD_18000df12_caseD_53;
      case 0x54:
        goto switchD_18000df12_caseD_54;
      case 0x55:
        goto switchD_18000df12_caseD_55;
      case 0x56:
        goto switchD_18000df12_caseD_56;
      case 0x57:
        goto switchD_18000df12_caseD_57;
      case 0x58:
        goto switchD_18000df12_caseD_58;
      case 0x59:
        goto switchD_18000df12_caseD_59;
      case 0x5a:
        goto switchD_18000df12_caseD_5a;
      case 0x5b:
        goto switchD_18000df12_caseD_5b;
      case 0x5c:
        goto switchD_18000df12_caseD_5c;
      case 0x5d:
        goto switchD_18000df12_caseD_5d;
      case 0x5e:
        goto switchD_18000df12_caseD_5e;
      case 0x5f:
        goto switchD_18000df12_caseD_5f;
      case 0x60:
        goto switchD_18000df12_caseD_60;
      case 0x61:
        goto switchD_18000df12_caseD_61;
      case 0x62:
        goto switchD_18000df12_caseD_62;
      case 99:
        goto switchD_18000df12_caseD_63;
      case 100:
        goto switchD_18000df12_caseD_64;
      case 0x65:
        goto switchD_18000df12_caseD_65;
      case 0x66:
        goto switchD_18000df12_caseD_66;
      case 0x67:
        goto switchD_18000df12_caseD_67;
      case 0x68:
        goto switchD_18000df12_caseD_68;
      case 0x69:
        goto switchD_18000df12_caseD_69;
      case 0x6a:
        goto switchD_18000df12_caseD_6a;
      case 0x6b:
        goto switchD_18000df12_caseD_6b;
      case 0x6c:
        goto switchD_18000df12_caseD_6c;
      case 0x6d:
        goto switchD_18000df12_caseD_6d;
      case 0x6e:
        goto switchD_18000df12_caseD_6e;
      case 0x6f:
        goto switchD_18000df12_caseD_6f;
      case 0x70:
        goto switchD_18000df12_caseD_70;
      case 0x71:
        goto switchD_18000df12_caseD_71;
      case 0x72:
        goto switchD_18000df12_caseD_72;
      case 0x73:
        goto switchD_18000df12_caseD_73;
      case 0x74:
        goto switchD_18000df12_caseD_74;
      case 0x75:
        goto switchD_18000df12_caseD_75;
      case 0x76:
        goto switchD_18000df12_caseD_76;
      case 0x77:
        goto switchD_18000df12_caseD_77;
      case 0x78:
        goto switchD_18000df12_caseD_78;
      case 0x79:
        goto switchD_18000df12_caseD_79;
      case 0x7a:
        goto switchD_18000df12_caseD_7a;
      case 0x7b:
        goto switchD_18000df12_caseD_7b;
      case 0x7c:
        goto switchD_18000df12_caseD_7c;
      case 0x7d:
        goto switchD_18000df12_caseD_7d;
      case 0x7e:
        goto switchD_18000df12_caseD_7e;
      case 0x7f:
        goto switchD_18000df12_caseD_7f;
      }
    }
    else {
      do {
        lVar7 = lVar7 + -0x80;
        *(longlong *)pbVar2 = lVar6;
        *(longlong *)(pbVar2 + 8) = lVar6;
        *(longlong *)(pbVar2 + 0x10) = lVar6;
        *(longlong *)(pbVar2 + 0x18) = lVar6;
        *(longlong *)(pbVar2 + 0x20) = lVar6;
        *(longlong *)(pbVar2 + 0x28) = lVar6;
        *(longlong *)(pbVar2 + 0x30) = lVar6;
        *(longlong *)(pbVar2 + 0x38) = lVar6;
        *(longlong *)(pbVar2 + 0x40) = lVar6;
        *(longlong *)(pbVar2 + 0x48) = lVar6;
        *(longlong *)(pbVar2 + 0x50) = lVar6;
        *(longlong *)(pbVar2 + 0x58) = lVar6;
        *(longlong *)(pbVar2 + 0x60) = lVar6;
        *(longlong *)(pbVar2 + 0x68) = lVar6;
        *(longlong *)(pbVar2 + 0x70) = lVar6;
        *(longlong *)(pbVar2 + 0x78) = lVar6;
        pbVar2 = pbVar2 + 0x80;
      } while (0x7f < lVar7);
      pbVar2 = pbVar2 + lVar7;
      switch(lVar7) {
      case 0:
        goto switchD_18000df12_caseD_0;
      case 1:
        goto switchD_18000df12_caseD_1;
      case 2:
        goto switchD_18000df12_caseD_2;
      case 3:
        goto switchD_18000df12_caseD_3;
      case 4:
        goto switchD_18000df12_caseD_4;
      case 5:
        goto switchD_18000df12_caseD_5;
      case 6:
        goto switchD_18000df12_caseD_6;
      case 7:
        goto switchD_18000df12_caseD_7;
      case 8:
        goto switchD_18000df12_caseD_8;
      case 9:
        goto switchD_18000df12_caseD_9;
      case 10:
        goto switchD_18000df12_caseD_a;
      case 0xb:
        goto switchD_18000df12_caseD_b;
      case 0xc:
        goto switchD_18000df12_caseD_c;
      case 0xd:
        goto switchD_18000df12_caseD_d;
      case 0xe:
        goto switchD_18000df12_caseD_e;
      case 0xf:
        goto switchD_18000df12_caseD_f;
      case 0x10:
        break;
      case 0x60:
switchD_18000df12_caseD_60:
        *(longlong *)(pbVar2 + -0x60) = lVar6;
        *(longlong *)(pbVar2 + -0x58) = lVar6;
      case 0x50:
switchD_18000df12_caseD_50:
        *(longlong *)(pbVar2 + -0x50) = lVar6;
        *(longlong *)(pbVar2 + -0x48) = lVar6;
      case 0x40:
switchD_18000df12_caseD_40:
        *(longlong *)(pbVar2 + -0x40) = lVar6;
        *(longlong *)(pbVar2 + -0x38) = lVar6;
      case 0x30:
switchD_18000df12_caseD_30:
        *(longlong *)(pbVar2 + -0x30) = lVar6;
        *(longlong *)(pbVar2 + -0x28) = lVar6;
      case 0x20:
switchD_18000df12_caseD_20:
        *(longlong *)(pbVar2 + -0x20) = lVar6;
        *(longlong *)(pbVar2 + -0x18) = lVar6;
        break;
      case 0x61:
switchD_18000df12_caseD_61:
        *(longlong *)(pbVar2 + -0x61) = lVar6;
        *(longlong *)(pbVar2 + -0x59) = lVar6;
      case 0x51:
switchD_18000df12_caseD_51:
        *(longlong *)(pbVar2 + -0x51) = lVar6;
        *(longlong *)(pbVar2 + -0x49) = lVar6;
      case 0x41:
switchD_18000df12_caseD_41:
        *(longlong *)(pbVar2 + -0x41) = lVar6;
        *(longlong *)(pbVar2 + -0x39) = lVar6;
      case 0x31:
switchD_18000df12_caseD_31:
        *(longlong *)(pbVar2 + -0x31) = lVar6;
        *(longlong *)(pbVar2 + -0x29) = lVar6;
      case 0x21:
switchD_18000df12_caseD_21:
        *(longlong *)(pbVar2 + -0x21) = lVar6;
        *(longlong *)(pbVar2 + -0x19) = lVar6;
      case 0x11:
switchD_18000df12_caseD_11:
        *(longlong *)(pbVar2 + -0x11) = lVar6;
        *(longlong *)(pbVar2 + -9) = lVar6;
switchD_18000df12_caseD_1:
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 0x62:
switchD_18000df12_caseD_62:
        *(longlong *)(pbVar2 + -0x62) = lVar6;
        *(longlong *)(pbVar2 + -0x5a) = lVar6;
      case 0x52:
switchD_18000df12_caseD_52:
        *(longlong *)(pbVar2 + -0x52) = lVar6;
        *(longlong *)(pbVar2 + -0x4a) = lVar6;
      case 0x42:
switchD_18000df12_caseD_42:
        *(longlong *)(pbVar2 + -0x42) = lVar6;
        *(longlong *)(pbVar2 + -0x3a) = lVar6;
      case 0x32:
switchD_18000df12_caseD_32:
        *(longlong *)(pbVar2 + -0x32) = lVar6;
        *(longlong *)(pbVar2 + -0x2a) = lVar6;
      case 0x22:
switchD_18000df12_caseD_22:
        *(longlong *)(pbVar2 + -0x22) = lVar6;
        *(longlong *)(pbVar2 + -0x1a) = lVar6;
      case 0x12:
switchD_18000df12_caseD_12:
        *(longlong *)(pbVar2 + -0x12) = lVar6;
        *(longlong *)(pbVar2 + -10) = lVar6;
switchD_18000df12_caseD_2:
        *(undefined2 *)(pbVar2 + -2) = uVar4;
        return pbVar1;
      case 99:
switchD_18000df12_caseD_63:
        *(longlong *)(pbVar2 + -99) = lVar6;
        *(longlong *)(pbVar2 + -0x5b) = lVar6;
      case 0x53:
switchD_18000df12_caseD_53:
        *(longlong *)(pbVar2 + -0x53) = lVar6;
        *(longlong *)(pbVar2 + -0x4b) = lVar6;
      case 0x43:
switchD_18000df12_caseD_43:
        *(longlong *)(pbVar2 + -0x43) = lVar6;
        *(longlong *)(pbVar2 + -0x3b) = lVar6;
      case 0x33:
switchD_18000df12_caseD_33:
        *(longlong *)(pbVar2 + -0x33) = lVar6;
        *(longlong *)(pbVar2 + -0x2b) = lVar6;
      case 0x23:
switchD_18000df12_caseD_23:
        *(longlong *)(pbVar2 + -0x23) = lVar6;
        *(longlong *)(pbVar2 + -0x1b) = lVar6;
      case 0x13:
switchD_18000df12_caseD_13:
        *(longlong *)(pbVar2 + -0x13) = lVar6;
        *(longlong *)(pbVar2 + -0xb) = lVar6;
switchD_18000df12_caseD_3:
        *(undefined2 *)(pbVar2 + -3) = uVar4;
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 100:
switchD_18000df12_caseD_64:
        *(longlong *)(pbVar2 + -100) = lVar6;
        *(longlong *)(pbVar2 + -0x5c) = lVar6;
      case 0x54:
switchD_18000df12_caseD_54:
        *(longlong *)(pbVar2 + -0x54) = lVar6;
        *(longlong *)(pbVar2 + -0x4c) = lVar6;
      case 0x44:
switchD_18000df12_caseD_44:
        *(longlong *)(pbVar2 + -0x44) = lVar6;
        *(longlong *)(pbVar2 + -0x3c) = lVar6;
      case 0x34:
switchD_18000df12_caseD_34:
        *(longlong *)(pbVar2 + -0x34) = lVar6;
        *(longlong *)(pbVar2 + -0x2c) = lVar6;
      case 0x24:
switchD_18000df12_caseD_24:
        *(longlong *)(pbVar2 + -0x24) = lVar6;
        *(longlong *)(pbVar2 + -0x1c) = lVar6;
      case 0x14:
switchD_18000df12_caseD_14:
        *(longlong *)(pbVar2 + -0x14) = lVar6;
        *(longlong *)(pbVar2 + -0xc) = lVar6;
switchD_18000df12_caseD_4:
        *(undefined4 *)(pbVar2 + -4) = uVar5;
        return pbVar1;
      case 0x65:
switchD_18000df12_caseD_65:
        *(longlong *)(pbVar2 + -0x65) = lVar6;
        *(longlong *)(pbVar2 + -0x5d) = lVar6;
      case 0x55:
switchD_18000df12_caseD_55:
        *(longlong *)(pbVar2 + -0x55) = lVar6;
        *(longlong *)(pbVar2 + -0x4d) = lVar6;
      case 0x45:
switchD_18000df12_caseD_45:
        *(longlong *)(pbVar2 + -0x45) = lVar6;
        *(longlong *)(pbVar2 + -0x3d) = lVar6;
      case 0x35:
switchD_18000df12_caseD_35:
        *(longlong *)(pbVar2 + -0x35) = lVar6;
        *(longlong *)(pbVar2 + -0x2d) = lVar6;
      case 0x25:
switchD_18000df12_caseD_25:
        *(longlong *)(pbVar2 + -0x25) = lVar6;
        *(longlong *)(pbVar2 + -0x1d) = lVar6;
      case 0x15:
switchD_18000df12_caseD_15:
        *(longlong *)(pbVar2 + -0x15) = lVar6;
        *(longlong *)(pbVar2 + -0xd) = lVar6;
switchD_18000df12_caseD_5:
        *(undefined4 *)(pbVar2 + -5) = uVar5;
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 0x66:
switchD_18000df12_caseD_66:
        *(longlong *)(pbVar2 + -0x66) = lVar6;
        *(longlong *)(pbVar2 + -0x5e) = lVar6;
      case 0x56:
switchD_18000df12_caseD_56:
        *(longlong *)(pbVar2 + -0x56) = lVar6;
        *(longlong *)(pbVar2 + -0x4e) = lVar6;
      case 0x46:
switchD_18000df12_caseD_46:
        *(longlong *)(pbVar2 + -0x46) = lVar6;
        *(longlong *)(pbVar2 + -0x3e) = lVar6;
      case 0x36:
switchD_18000df12_caseD_36:
        *(longlong *)(pbVar2 + -0x36) = lVar6;
        *(longlong *)(pbVar2 + -0x2e) = lVar6;
      case 0x26:
switchD_18000df12_caseD_26:
        *(longlong *)(pbVar2 + -0x26) = lVar6;
        *(longlong *)(pbVar2 + -0x1e) = lVar6;
      case 0x16:
switchD_18000df12_caseD_16:
        *(longlong *)(pbVar2 + -0x16) = lVar6;
        *(longlong *)(pbVar2 + -0xe) = lVar6;
switchD_18000df12_caseD_6:
        *(undefined4 *)(pbVar2 + -6) = uVar5;
        *(undefined2 *)(pbVar2 + -2) = uVar4;
        return pbVar1;
      case 0x67:
switchD_18000df12_caseD_67:
        *(longlong *)(pbVar2 + -0x67) = lVar6;
        *(longlong *)(pbVar2 + -0x5f) = lVar6;
      case 0x57:
switchD_18000df12_caseD_57:
        *(longlong *)(pbVar2 + -0x57) = lVar6;
        *(longlong *)(pbVar2 + -0x4f) = lVar6;
      case 0x47:
switchD_18000df12_caseD_47:
        *(longlong *)(pbVar2 + -0x47) = lVar6;
        *(longlong *)(pbVar2 + -0x3f) = lVar6;
      case 0x37:
switchD_18000df12_caseD_37:
        *(longlong *)(pbVar2 + -0x37) = lVar6;
        *(longlong *)(pbVar2 + -0x2f) = lVar6;
      case 0x27:
switchD_18000df12_caseD_27:
        *(longlong *)(pbVar2 + -0x27) = lVar6;
        *(longlong *)(pbVar2 + -0x1f) = lVar6;
      case 0x17:
switchD_18000df12_caseD_17:
        *(longlong *)(pbVar2 + -0x17) = lVar6;
        *(longlong *)(pbVar2 + -0xf) = lVar6;
switchD_18000df12_caseD_7:
        *(undefined4 *)(pbVar2 + -7) = uVar5;
        *(undefined2 *)(pbVar2 + -3) = uVar4;
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 0x68:
switchD_18000df12_caseD_68:
        *(longlong *)(pbVar2 + -0x68) = lVar6;
        *(longlong *)(pbVar2 + -0x60) = lVar6;
      case 0x58:
switchD_18000df12_caseD_58:
        *(longlong *)(pbVar2 + -0x58) = lVar6;
        *(longlong *)(pbVar2 + -0x50) = lVar6;
      case 0x48:
switchD_18000df12_caseD_48:
        *(longlong *)(pbVar2 + -0x48) = lVar6;
        *(longlong *)(pbVar2 + -0x40) = lVar6;
      case 0x38:
switchD_18000df12_caseD_38:
        *(longlong *)(pbVar2 + -0x38) = lVar6;
        *(longlong *)(pbVar2 + -0x30) = lVar6;
      case 0x28:
switchD_18000df12_caseD_28:
        *(longlong *)(pbVar2 + -0x28) = lVar6;
        *(longlong *)(pbVar2 + -0x20) = lVar6;
      case 0x18:
switchD_18000df12_caseD_18:
        *(longlong *)(pbVar2 + -0x18) = lVar6;
        *(longlong *)(pbVar2 + -0x10) = lVar6;
switchD_18000df12_caseD_8:
        *(longlong *)(pbVar2 + -8) = lVar6;
        return pbVar1;
      case 0x69:
switchD_18000df12_caseD_69:
        *(longlong *)(pbVar2 + -0x69) = lVar6;
        *(longlong *)(pbVar2 + -0x61) = lVar6;
      case 0x59:
switchD_18000df12_caseD_59:
        *(longlong *)(pbVar2 + -0x59) = lVar6;
        *(longlong *)(pbVar2 + -0x51) = lVar6;
      case 0x49:
switchD_18000df12_caseD_49:
        *(longlong *)(pbVar2 + -0x49) = lVar6;
        *(longlong *)(pbVar2 + -0x41) = lVar6;
      case 0x39:
switchD_18000df12_caseD_39:
        *(longlong *)(pbVar2 + -0x39) = lVar6;
        *(longlong *)(pbVar2 + -0x31) = lVar6;
      case 0x29:
switchD_18000df12_caseD_29:
        *(longlong *)(pbVar2 + -0x29) = lVar6;
        *(longlong *)(pbVar2 + -0x21) = lVar6;
      case 0x19:
switchD_18000df12_caseD_19:
        *(longlong *)(pbVar2 + -0x19) = lVar6;
        *(longlong *)(pbVar2 + -0x11) = lVar6;
switchD_18000df12_caseD_9:
        *(longlong *)(pbVar2 + -9) = lVar6;
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 0x6a:
switchD_18000df12_caseD_6a:
        *(longlong *)(pbVar2 + -0x6a) = lVar6;
        *(longlong *)(pbVar2 + -0x62) = lVar6;
      case 0x5a:
switchD_18000df12_caseD_5a:
        *(longlong *)(pbVar2 + -0x5a) = lVar6;
        *(longlong *)(pbVar2 + -0x52) = lVar6;
      case 0x4a:
switchD_18000df12_caseD_4a:
        *(longlong *)(pbVar2 + -0x4a) = lVar6;
        *(longlong *)(pbVar2 + -0x42) = lVar6;
      case 0x3a:
switchD_18000df12_caseD_3a:
        *(longlong *)(pbVar2 + -0x3a) = lVar6;
        *(longlong *)(pbVar2 + -0x32) = lVar6;
      case 0x2a:
switchD_18000df12_caseD_2a:
        *(longlong *)(pbVar2 + -0x2a) = lVar6;
        *(longlong *)(pbVar2 + -0x22) = lVar6;
      case 0x1a:
switchD_18000df12_caseD_1a:
        *(longlong *)(pbVar2 + -0x1a) = lVar6;
        *(longlong *)(pbVar2 + -0x12) = lVar6;
switchD_18000df12_caseD_a:
        *(longlong *)(pbVar2 + -10) = lVar6;
        *(undefined2 *)(pbVar2 + -2) = uVar4;
        return pbVar1;
      case 0x6b:
switchD_18000df12_caseD_6b:
        *(longlong *)(pbVar2 + -0x6b) = lVar6;
        *(longlong *)(pbVar2 + -99) = lVar6;
      case 0x5b:
switchD_18000df12_caseD_5b:
        *(longlong *)(pbVar2 + -0x5b) = lVar6;
        *(longlong *)(pbVar2 + -0x53) = lVar6;
      case 0x4b:
switchD_18000df12_caseD_4b:
        *(longlong *)(pbVar2 + -0x4b) = lVar6;
        *(longlong *)(pbVar2 + -0x43) = lVar6;
      case 0x3b:
switchD_18000df12_caseD_3b:
        *(longlong *)(pbVar2 + -0x3b) = lVar6;
        *(longlong *)(pbVar2 + -0x33) = lVar6;
      case 0x2b:
switchD_18000df12_caseD_2b:
        *(longlong *)(pbVar2 + -0x2b) = lVar6;
        *(longlong *)(pbVar2 + -0x23) = lVar6;
      case 0x1b:
switchD_18000df12_caseD_1b:
        *(longlong *)(pbVar2 + -0x1b) = lVar6;
        *(longlong *)(pbVar2 + -0x13) = lVar6;
switchD_18000df12_caseD_b:
        *(longlong *)(pbVar2 + -0xb) = lVar6;
        *(undefined2 *)(pbVar2 + -3) = uVar4;
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 0x6c:
switchD_18000df12_caseD_6c:
        *(longlong *)(pbVar2 + -0x6c) = lVar6;
        *(longlong *)(pbVar2 + -100) = lVar6;
      case 0x5c:
switchD_18000df12_caseD_5c:
        *(longlong *)(pbVar2 + -0x5c) = lVar6;
        *(longlong *)(pbVar2 + -0x54) = lVar6;
      case 0x4c:
switchD_18000df12_caseD_4c:
        *(longlong *)(pbVar2 + -0x4c) = lVar6;
        *(longlong *)(pbVar2 + -0x44) = lVar6;
      case 0x3c:
switchD_18000df12_caseD_3c:
        *(longlong *)(pbVar2 + -0x3c) = lVar6;
        *(longlong *)(pbVar2 + -0x34) = lVar6;
      case 0x2c:
switchD_18000df12_caseD_2c:
        *(longlong *)(pbVar2 + -0x2c) = lVar6;
        *(longlong *)(pbVar2 + -0x24) = lVar6;
      case 0x1c:
switchD_18000df12_caseD_1c:
        *(longlong *)(pbVar2 + -0x1c) = lVar6;
        *(longlong *)(pbVar2 + -0x14) = lVar6;
switchD_18000df12_caseD_c:
        *(longlong *)(pbVar2 + -0xc) = lVar6;
        *(undefined4 *)(pbVar2 + -4) = uVar5;
        return pbVar1;
      case 0x6d:
switchD_18000df12_caseD_6d:
        *(longlong *)(pbVar2 + -0x6d) = lVar6;
        *(longlong *)(pbVar2 + -0x65) = lVar6;
      case 0x5d:
switchD_18000df12_caseD_5d:
        *(longlong *)(pbVar2 + -0x5d) = lVar6;
        *(longlong *)(pbVar2 + -0x55) = lVar6;
      case 0x4d:
switchD_18000df12_caseD_4d:
        *(longlong *)(pbVar2 + -0x4d) = lVar6;
        *(longlong *)(pbVar2 + -0x45) = lVar6;
      case 0x3d:
switchD_18000df12_caseD_3d:
        *(longlong *)(pbVar2 + -0x3d) = lVar6;
        *(longlong *)(pbVar2 + -0x35) = lVar6;
      case 0x2d:
switchD_18000df12_caseD_2d:
        *(longlong *)(pbVar2 + -0x2d) = lVar6;
        *(longlong *)(pbVar2 + -0x25) = lVar6;
      case 0x1d:
switchD_18000df12_caseD_1d:
        *(longlong *)(pbVar2 + -0x1d) = lVar6;
        *(longlong *)(pbVar2 + -0x15) = lVar6;
switchD_18000df12_caseD_d:
        *(longlong *)(pbVar2 + -0xd) = lVar6;
        *(undefined4 *)(pbVar2 + -5) = uVar5;
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 0x6e:
switchD_18000df12_caseD_6e:
        *(longlong *)(pbVar2 + -0x6e) = lVar6;
        *(longlong *)(pbVar2 + -0x66) = lVar6;
      case 0x5e:
switchD_18000df12_caseD_5e:
        *(longlong *)(pbVar2 + -0x5e) = lVar6;
        *(longlong *)(pbVar2 + -0x56) = lVar6;
      case 0x4e:
switchD_18000df12_caseD_4e:
        *(longlong *)(pbVar2 + -0x4e) = lVar6;
        *(longlong *)(pbVar2 + -0x46) = lVar6;
      case 0x3e:
switchD_18000df12_caseD_3e:
        *(longlong *)(pbVar2 + -0x3e) = lVar6;
        *(longlong *)(pbVar2 + -0x36) = lVar6;
      case 0x2e:
switchD_18000df12_caseD_2e:
        *(longlong *)(pbVar2 + -0x2e) = lVar6;
        *(longlong *)(pbVar2 + -0x26) = lVar6;
      case 0x1e:
switchD_18000df12_caseD_1e:
        *(longlong *)(pbVar2 + -0x1e) = lVar6;
        *(longlong *)(pbVar2 + -0x16) = lVar6;
switchD_18000df12_caseD_e:
        *(longlong *)(pbVar2 + -0xe) = lVar6;
        *(undefined4 *)(pbVar2 + -6) = uVar5;
        *(undefined2 *)(pbVar2 + -2) = uVar4;
        return pbVar1;
      case 0x6f:
switchD_18000df12_caseD_6f:
        *(longlong *)(pbVar2 + -0x6f) = lVar6;
        *(longlong *)(pbVar2 + -0x67) = lVar6;
      case 0x5f:
switchD_18000df12_caseD_5f:
        *(longlong *)(pbVar2 + -0x5f) = lVar6;
        *(longlong *)(pbVar2 + -0x57) = lVar6;
      case 0x4f:
switchD_18000df12_caseD_4f:
        *(longlong *)(pbVar2 + -0x4f) = lVar6;
        *(longlong *)(pbVar2 + -0x47) = lVar6;
      case 0x3f:
switchD_18000df12_caseD_3f:
        *(longlong *)(pbVar2 + -0x3f) = lVar6;
        *(longlong *)(pbVar2 + -0x37) = lVar6;
      case 0x2f:
switchD_18000df12_caseD_2f:
        *(longlong *)(pbVar2 + -0x2f) = lVar6;
        *(longlong *)(pbVar2 + -0x27) = lVar6;
      case 0x1f:
switchD_18000df12_caseD_1f:
        *(longlong *)(pbVar2 + -0x1f) = lVar6;
        *(longlong *)(pbVar2 + -0x17) = lVar6;
switchD_18000df12_caseD_f:
        *(longlong *)(pbVar2 + -0xf) = lVar6;
        *(undefined4 *)(pbVar2 + -7) = uVar5;
        *(undefined2 *)(pbVar2 + -3) = uVar4;
        pbVar2[-1] = bVar3;
        return pbVar1;
      case 0x70:
        goto switchD_18000df12_caseD_70;
      case 0x71:
        goto switchD_18000df12_caseD_71;
      case 0x72:
        goto switchD_18000df12_caseD_72;
      case 0x73:
        goto switchD_18000df12_caseD_73;
      case 0x74:
        goto switchD_18000df12_caseD_74;
      case 0x75:
        goto switchD_18000df12_caseD_75;
      case 0x76:
        goto switchD_18000df12_caseD_76;
      case 0x77:
        goto switchD_18000df12_caseD_77;
      case 0x78:
        goto switchD_18000df12_caseD_78;
      case 0x79:
        goto switchD_18000df12_caseD_79;
      case 0x7a:
        goto switchD_18000df12_caseD_7a;
      case 0x7b:
        goto switchD_18000df12_caseD_7b;
      case 0x7c:
        goto switchD_18000df12_caseD_7c;
      case 0x7d:
        goto switchD_18000df12_caseD_7d;
      case 0x7e:
        goto switchD_18000df12_caseD_7e;
      case 0x7f:
        goto switchD_18000df12_caseD_7f;
      }
    }
switchD_18000df12_caseD_10:
    *(longlong *)(pbVar2 + -0x10) = lVar6;
    *(longlong *)(pbVar2 + -8) = lVar6;
switchD_18000df12_caseD_0:
    return pbVar1;
  }
  if (((longlong)(ulonglong)DAT_180018860 < param_3) && ((ulonglong)DAT_180018860 != 0)) {
    do {
      *(longlong *)param_1 = lVar6;
      *(longlong *)(param_1 + 8) = lVar6;
      param_3 = param_3 + -0x40;
      *(longlong *)(param_1 + 0x10) = lVar6;
      *(longlong *)(param_1 + 0x18) = lVar6;
      *(longlong *)(param_1 + 0x20) = lVar6;
      *(longlong *)(param_1 + 0x28) = lVar6;
      *(longlong *)(param_1 + 0x30) = lVar6;
      *(longlong *)(param_1 + 0x38) = lVar6;
      param_1 = param_1 + 0x40;
    } while (0x3f < param_3);
    pbVar2 = param_1 + param_3;
    switch(param_3) {
    case 0:
      goto switchD_18000dbc3_caseD_0;
    case 1:
      goto switchD_18000dbc3_caseD_1;
    case 2:
      goto switchD_18000dbc3_caseD_2;
    case 3:
      goto switchD_18000dbc3_caseD_3;
    case 4:
      goto switchD_18000dbc3_caseD_4;
    case 5:
      goto switchD_18000dbc3_caseD_5;
    case 6:
      goto switchD_18000dbc3_caseD_6;
    case 7:
      goto switchD_18000dbc3_caseD_7;
    case 9:
      goto switchD_18000dbc3_caseD_9;
    case 10:
      goto switchD_18000dbc3_caseD_a;
    case 0xb:
      goto switchD_18000dbc3_caseD_b;
    case 0xc:
      goto switchD_18000dbc3_caseD_c;
    case 0xd:
      goto switchD_18000dbc3_caseD_d;
    case 0xe:
      goto switchD_18000dbc3_caseD_e;
    case 0xf:
      goto switchD_18000dbc3_caseD_f;
    case 0x10:
      goto switchD_18000dbc3_caseD_10;
    case 0x11:
      goto switchD_18000dbc3_caseD_11;
    case 0x12:
      goto switchD_18000dbc3_caseD_12;
    case 0x13:
      goto switchD_18000dbc3_caseD_13;
    case 0x14:
      goto switchD_18000dbc3_caseD_14;
    case 0x15:
      goto switchD_18000dbc3_caseD_15;
    case 0x16:
      goto switchD_18000dbc3_caseD_16;
    case 0x17:
      goto switchD_18000dbc3_caseD_17;
    case 0x18:
      goto switchD_18000dbc3_caseD_18;
    case 0x19:
      goto switchD_18000dbc3_caseD_19;
    case 0x1a:
      goto switchD_18000dbc3_caseD_1a;
    case 0x1b:
      goto switchD_18000dbc3_caseD_1b;
    case 0x1c:
      goto switchD_18000dbc3_caseD_1c;
    case 0x1d:
      goto switchD_18000dbc3_caseD_1d;
    case 0x1e:
      goto switchD_18000dbc3_caseD_1e;
    case 0x1f:
      goto switchD_18000dbc3_caseD_1f;
    case 0x20:
      goto switchD_18000dbc3_caseD_20;
    case 0x21:
      goto switchD_18000dbc3_caseD_21;
    case 0x22:
      goto switchD_18000dbc3_caseD_22;
    case 0x23:
      goto switchD_18000dbc3_caseD_23;
    case 0x24:
      goto switchD_18000dbc3_caseD_24;
    case 0x25:
      goto switchD_18000dbc3_caseD_25;
    case 0x26:
      goto switchD_18000dbc3_caseD_26;
    case 0x27:
      goto switchD_18000dbc3_caseD_27;
    case 0x28:
      goto switchD_18000dbc3_caseD_28;
    case 0x29:
      goto switchD_18000dbc3_caseD_29;
    case 0x2a:
      goto switchD_18000dbc3_caseD_2a;
    case 0x2b:
      goto switchD_18000dbc3_caseD_2b;
    case 0x2c:
      goto switchD_18000dbc3_caseD_2c;
    case 0x2d:
      goto switchD_18000dbc3_caseD_2d;
    case 0x2e:
      goto switchD_18000dbc3_caseD_2e;
    case 0x2f:
      goto switchD_18000dbc3_caseD_2f;
    case 0x30:
      goto switchD_18000dbc3_caseD_30;
    case 0x31:
      goto switchD_18000dbc3_caseD_31;
    case 0x32:
      goto switchD_18000dbc3_caseD_32;
    case 0x33:
      goto switchD_18000dbc3_caseD_33;
    case 0x34:
      goto switchD_18000dbc3_caseD_34;
    case 0x35:
      goto switchD_18000dbc3_caseD_35;
    case 0x36:
      goto switchD_18000dbc3_caseD_36;
    case 0x37:
      goto switchD_18000dbc3_caseD_37;
    case 0x38:
      goto switchD_18000dbc3_caseD_38;
    case 0x39:
      goto switchD_18000dbc3_caseD_39;
    case 0x3a:
      goto switchD_18000dbc3_caseD_3a;
    case 0x3b:
      goto switchD_18000dbc3_caseD_3b;
    case 0x3c:
      goto switchD_18000dbc3_caseD_3c;
    case 0x3d:
      goto switchD_18000dbc3_caseD_3d;
    case 0x3e:
      goto switchD_18000dbc3_caseD_3e;
    case 0x3f:
      goto switchD_18000dbc3_caseD_3f;
    }
  }
  else {
    do {
      *(longlong *)param_1 = lVar6;
      *(longlong *)(param_1 + 8) = lVar6;
      param_3 = param_3 + -0x40;
      *(longlong *)(param_1 + 0x10) = lVar6;
      *(longlong *)(param_1 + 0x18) = lVar6;
      *(longlong *)(param_1 + 0x20) = lVar6;
      *(longlong *)(param_1 + 0x28) = lVar6;
      *(longlong *)(param_1 + 0x30) = lVar6;
      *(longlong *)(param_1 + 0x38) = lVar6;
      param_1 = param_1 + 0x40;
    } while (0x40 < param_3);
    pbVar2 = param_1 + param_3;
    switch(param_3) {
    case 0:
      goto switchD_18000dbc3_caseD_0;
    case 1:
      goto switchD_18000dbc3_caseD_1;
    case 2:
      goto switchD_18000dbc3_caseD_2;
    case 3:
      goto switchD_18000dbc3_caseD_3;
    case 4:
      goto switchD_18000dbc3_caseD_4;
    case 5:
      goto switchD_18000dbc3_caseD_5;
    case 6:
      goto switchD_18000dbc3_caseD_6;
    case 7:
      goto switchD_18000dbc3_caseD_7;
    case 8:
      break;
    case 0x30:
switchD_18000dbc3_caseD_30:
      *(longlong *)(pbVar2 + -0x30) = lVar6;
    case 0x28:
switchD_18000dbc3_caseD_28:
      *(longlong *)(pbVar2 + -0x28) = lVar6;
    case 0x20:
switchD_18000dbc3_caseD_20:
      *(longlong *)(pbVar2 + -0x20) = lVar6;
    case 0x18:
switchD_18000dbc3_caseD_18:
      *(longlong *)(pbVar2 + -0x18) = lVar6;
    case 0x10:
switchD_18000dbc3_caseD_10:
      *(longlong *)(pbVar2 + -0x10) = lVar6;
      break;
    case 0x31:
switchD_18000dbc3_caseD_31:
      *(longlong *)(pbVar2 + -0x31) = lVar6;
    case 0x29:
switchD_18000dbc3_caseD_29:
      *(longlong *)(pbVar2 + -0x29) = lVar6;
    case 0x21:
switchD_18000dbc3_caseD_21:
      *(longlong *)(pbVar2 + -0x21) = lVar6;
    case 0x19:
switchD_18000dbc3_caseD_19:
      *(longlong *)(pbVar2 + -0x19) = lVar6;
    case 0x11:
switchD_18000dbc3_caseD_11:
      *(longlong *)(pbVar2 + -0x11) = lVar6;
    case 9:
switchD_18000dbc3_caseD_9:
      *(longlong *)(pbVar2 + -9) = lVar6;
switchD_18000dbc3_caseD_1:
      pbVar2[-1] = bVar3;
      return pbVar1;
    case 0x32:
switchD_18000dbc3_caseD_32:
      *(longlong *)(pbVar2 + -0x32) = lVar6;
    case 0x2a:
switchD_18000dbc3_caseD_2a:
      *(longlong *)(pbVar2 + -0x2a) = lVar6;
    case 0x22:
switchD_18000dbc3_caseD_22:
      *(longlong *)(pbVar2 + -0x22) = lVar6;
    case 0x1a:
switchD_18000dbc3_caseD_1a:
      *(longlong *)(pbVar2 + -0x1a) = lVar6;
    case 0x12:
switchD_18000dbc3_caseD_12:
      *(longlong *)(pbVar2 + -0x12) = lVar6;
    case 10:
switchD_18000dbc3_caseD_a:
      *(longlong *)(pbVar2 + -10) = lVar6;
switchD_18000dbc3_caseD_2:
      *(undefined2 *)(pbVar2 + -2) = uVar4;
      return pbVar1;
    case 0x33:
switchD_18000dbc3_caseD_33:
      *(longlong *)(pbVar2 + -0x33) = lVar6;
    case 0x2b:
switchD_18000dbc3_caseD_2b:
      *(longlong *)(pbVar2 + -0x2b) = lVar6;
    case 0x23:
switchD_18000dbc3_caseD_23:
      *(longlong *)(pbVar2 + -0x23) = lVar6;
    case 0x1b:
switchD_18000dbc3_caseD_1b:
      *(longlong *)(pbVar2 + -0x1b) = lVar6;
    case 0x13:
switchD_18000dbc3_caseD_13:
      *(longlong *)(pbVar2 + -0x13) = lVar6;
    case 0xb:
switchD_18000dbc3_caseD_b:
      *(longlong *)(pbVar2 + -0xb) = lVar6;
switchD_18000dbc3_caseD_3:
      *(undefined2 *)(pbVar2 + -3) = uVar4;
      pbVar2[-1] = bVar3;
      return pbVar1;
    case 0x34:
switchD_18000dbc3_caseD_34:
      *(longlong *)(pbVar2 + -0x34) = lVar6;
    case 0x2c:
switchD_18000dbc3_caseD_2c:
      *(longlong *)(pbVar2 + -0x2c) = lVar6;
    case 0x24:
switchD_18000dbc3_caseD_24:
      *(longlong *)(pbVar2 + -0x24) = lVar6;
    case 0x1c:
switchD_18000dbc3_caseD_1c:
      *(longlong *)(pbVar2 + -0x1c) = lVar6;
    case 0x14:
switchD_18000dbc3_caseD_14:
      *(longlong *)(pbVar2 + -0x14) = lVar6;
    case 0xc:
switchD_18000dbc3_caseD_c:
      *(longlong *)(pbVar2 + -0xc) = lVar6;
switchD_18000dbc3_caseD_4:
      *(undefined4 *)(pbVar2 + -4) = uVar5;
      return pbVar1;
    case 0x35:
switchD_18000dbc3_caseD_35:
      *(longlong *)(pbVar2 + -0x35) = lVar6;
    case 0x2d:
switchD_18000dbc3_caseD_2d:
      *(longlong *)(pbVar2 + -0x2d) = lVar6;
    case 0x25:
switchD_18000dbc3_caseD_25:
      *(longlong *)(pbVar2 + -0x25) = lVar6;
    case 0x1d:
switchD_18000dbc3_caseD_1d:
      *(longlong *)(pbVar2 + -0x1d) = lVar6;
    case 0x15:
switchD_18000dbc3_caseD_15:
      *(longlong *)(pbVar2 + -0x15) = lVar6;
    case 0xd:
switchD_18000dbc3_caseD_d:
      *(longlong *)(pbVar2 + -0xd) = lVar6;
switchD_18000dbc3_caseD_5:
      *(undefined4 *)(pbVar2 + -5) = uVar5;
      pbVar2[-1] = bVar3;
      return pbVar1;
    case 0x36:
switchD_18000dbc3_caseD_36:
      *(longlong *)(pbVar2 + -0x36) = lVar6;
    case 0x2e:
switchD_18000dbc3_caseD_2e:
      *(longlong *)(pbVar2 + -0x2e) = lVar6;
    case 0x26:
switchD_18000dbc3_caseD_26:
      *(longlong *)(pbVar2 + -0x26) = lVar6;
    case 0x1e:
switchD_18000dbc3_caseD_1e:
      *(longlong *)(pbVar2 + -0x1e) = lVar6;
    case 0x16:
switchD_18000dbc3_caseD_16:
      *(longlong *)(pbVar2 + -0x16) = lVar6;
    case 0xe:
switchD_18000dbc3_caseD_e:
      *(longlong *)(pbVar2 + -0xe) = lVar6;
switchD_18000dbc3_caseD_6:
      *(undefined4 *)(pbVar2 + -6) = uVar5;
      *(undefined2 *)(pbVar2 + -2) = uVar4;
      return pbVar1;
    case 0x37:
switchD_18000dbc3_caseD_37:
      *(longlong *)(pbVar2 + -0x37) = lVar6;
    case 0x2f:
switchD_18000dbc3_caseD_2f:
      *(longlong *)(pbVar2 + -0x2f) = lVar6;
    case 0x27:
switchD_18000dbc3_caseD_27:
      *(longlong *)(pbVar2 + -0x27) = lVar6;
    case 0x1f:
switchD_18000dbc3_caseD_1f:
      *(longlong *)(pbVar2 + -0x1f) = lVar6;
    case 0x17:
switchD_18000dbc3_caseD_17:
      *(longlong *)(pbVar2 + -0x17) = lVar6;
    case 0xf:
switchD_18000dbc3_caseD_f:
      *(longlong *)(pbVar2 + -0xf) = lVar6;
switchD_18000dbc3_caseD_7:
      *(undefined4 *)(pbVar2 + -7) = uVar5;
      *(undefined2 *)(pbVar2 + -3) = uVar4;
      pbVar2[-1] = bVar3;
      return pbVar1;
    case 0x38:
      goto switchD_18000dbc3_caseD_38;
    case 0x39:
      goto switchD_18000dbc3_caseD_39;
    case 0x3a:
      goto switchD_18000dbc3_caseD_3a;
    case 0x3b:
      goto switchD_18000dbc3_caseD_3b;
    case 0x3c:
      goto switchD_18000dbc3_caseD_3c;
    case 0x3d:
      goto switchD_18000dbc3_caseD_3d;
    case 0x3e:
      goto switchD_18000dbc3_caseD_3e;
    case 0x3f:
      goto switchD_18000dbc3_caseD_3f;
    case 0x40:
      goto switchD_18000dbc3_caseD_40;
    }
  }
switchD_18000dbc3_caseD_8:
  *(longlong *)(pbVar2 + -8) = lVar6;
switchD_18000dbc3_caseD_0:
  return pbVar1;
}



undefined1 (*) [32] FUN_18000e580(undefined1 (*param_1) [32],ulonglong param_2,ulonglong param_3)

{
  undefined1 (*pauVar1) [32];
  ulonglong uVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [32];
  
  lVar6 = (param_2 & 0xff) * 0x101010101010101;
  uVar7 = (undefined4)lVar6;
  auVar8._0_8_ = CONCAT44(uVar7,uVar7);
  auVar8._8_4_ = uVar7;
  auVar8._12_4_ = uVar7;
  auVar9._16_4_ = uVar7;
  auVar9._0_16_ = auVar8;
  auVar9._20_4_ = uVar7;
  auVar9._24_4_ = uVar7;
  auVar9._28_4_ = uVar7;
  uVar4 = (undefined1)lVar6;
  uVar5 = (undefined2)lVar6;
  switch(param_3) {
  case 0:
    break;
  case 1:
    (*param_1)[0] = uVar4;
    break;
  case 2:
    *(undefined2 *)*param_1 = uVar5;
    break;
  case 3:
    *(undefined2 *)*param_1 = uVar5;
    (*param_1)[2] = uVar4;
    break;
  case 4:
    *(undefined4 *)*param_1 = uVar7;
    break;
  case 5:
  case 6:
  case 7:
    *(undefined4 *)*param_1 = uVar7;
    *(undefined4 *)(param_1[-1] + param_3 + 0x1c) = uVar7;
    break;
  case 8:
    *(longlong *)*param_1 = lVar6;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *(longlong *)*param_1 = lVar6;
    *(longlong *)(param_1[-1] + param_3 + 0x18) = lVar6;
    break;
  case 0x10:
    *(undefined1 (*) [16])*param_1 = auVar8;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    *(undefined1 (*) [16])*param_1 = auVar8;
    *(undefined1 (*) [16])(param_1[-1] + param_3 + 0x10) = auVar8;
    break;
  case 0x20:
    *param_1 = auVar9;
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    *param_1 = auVar9;
    *(undefined1 (*) [32])(param_1[-1] + param_3) = auVar9;
    break;
  case 0x40:
    *param_1 = auVar9;
    param_1[1] = auVar9;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
    *param_1 = auVar9;
    param_1[1] = auVar9;
    *(undefined1 (*) [32])(param_1[-1] + param_3) = auVar9;
    *(undefined1 (*) [32])(param_1[-2] + param_3) = auVar9;
    break;
  case 0x80:
    *param_1 = auVar9;
    param_1[1] = auVar9;
    param_1[2] = auVar9;
    param_1[3] = auVar9;
    break;
  default:
    uVar2 = (ulonglong)param_1 & 0x1f;
    pauVar1 = param_1;
    if (uVar2 != 0) {
      lVar3 = -uVar2;
      param_3 = param_3 - (lVar3 + 0x20);
      switch(uVar2) {
      default:
        *(undefined1 (*) [16])*param_1 = auVar8;
        *(undefined1 (*) [16])((longlong)param_1 + lVar3 + 0x10) = auVar8;
        break;
      case 0x10:
        *(undefined1 (*) [16])*param_1 = auVar8;
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
        *(longlong *)*param_1 = lVar6;
        *(longlong *)((longlong)param_1 + lVar3 + 0x18) = lVar6;
        break;
      case 0x18:
        *(longlong *)*param_1 = lVar6;
        break;
      case 0x19:
      case 0x1a:
      case 0x1b:
        *(undefined4 *)*param_1 = uVar7;
        *(undefined4 *)((longlong)param_1 + lVar3 + 0x1c) = uVar7;
        break;
      case 0x1c:
        *(undefined4 *)*param_1 = uVar7;
        break;
      case 0x1d:
        *(undefined2 *)*param_1 = uVar5;
        (*param_1)[2] = uVar4;
        break;
      case 0x1e:
        *(undefined2 *)*param_1 = uVar5;
        break;
      case 0x1f:
        (*param_1)[0] = uVar4;
      }
      pauVar1 = (undefined1 (*) [32])((longlong)param_1 + lVar3 + 0x20);
    }
    if (0xff < (longlong)param_3) {
      if ((ulonglong)DAT_180018868 - (ulonglong)(DAT_180018868 >> 4) <= param_3) {
        for (; param_3 != 0; param_3 = param_3 - 1) {
          (*pauVar1)[0] = uVar4;
          pauVar1 = (undefined1 (*) [32])(*pauVar1 + 1);
        }
        return param_1;
      }
      do {
        *pauVar1 = auVar9;
        pauVar1[1] = auVar9;
        pauVar1[2] = auVar9;
        pauVar1[3] = auVar9;
        param_3 = param_3 - 0x100;
        pauVar1[4] = auVar9;
        pauVar1[5] = auVar9;
        pauVar1[6] = auVar9;
        pauVar1[7] = auVar9;
        pauVar1 = pauVar1 + 8;
      } while (0xff < (longlong)param_3);
    }
                    // WARNING: Could not recover jumptable at 0x00018000e735. Too many branches
                    // WARNING: Treating indirect jump as call
    pauVar1 = (undefined1 (*) [32])
              (*(code *)(&DAT_18000e9a0 + -*(longlong *)(&DAT_18000e9a0 + param_3 * 8)))
                        (auVar8._0_8_,&DAT_18000e9a0 + -*(longlong *)(&DAT_18000e9a0 + param_3 * 8))
    ;
    return pauVar1;
  }
  return param_1;
}



undefined1 (*) [64] FUN_18000f5c0(undefined1 (*param_1) [64],ulonglong param_2,ulonglong param_3)

{
  undefined1 auVar1 [64];
  undefined1 (*pauVar2) [64];
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 auVar8 [64];
  undefined1 auVar9 [16];
  undefined1 auVar10 [32];
  
  lVar6 = (param_2 & 0xff) * 0x101010101010101;
  auVar8 = vpbroadcastd_avx512f();
  uVar5 = (undefined4)lVar6;
  uVar3 = (undefined1)lVar6;
  uVar4 = (undefined2)lVar6;
  auVar9 = auVar8._0_16_;
  auVar10 = auVar8._0_32_;
  switch(param_3) {
  case 0:
    break;
  case 1:
    (*param_1)[0] = uVar3;
    break;
  case 2:
    *(undefined2 *)*param_1 = uVar4;
    break;
  case 3:
    *(undefined2 *)*param_1 = uVar4;
    (*param_1)[2] = uVar3;
    break;
  case 4:
    *(undefined4 *)*param_1 = uVar5;
    break;
  case 5:
  case 6:
  case 7:
    *(undefined4 *)*param_1 = uVar5;
    *(undefined4 *)(param_1[-1] + param_3 + 0x3c) = uVar5;
    break;
  case 8:
    *(longlong *)*param_1 = lVar6;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *(longlong *)*param_1 = lVar6;
    *(longlong *)(param_1[-1] + param_3 + 0x38) = lVar6;
    break;
  case 0x10:
    *(undefined1 (*) [16])*param_1 = auVar9;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    *(undefined1 (*) [16])*param_1 = auVar9;
    *(undefined1 (*) [16])(param_1[-1] + param_3 + 0x30) = auVar9;
    break;
  case 0x20:
    *(undefined1 (*) [32])*param_1 = auVar10;
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    *(undefined1 (*) [32])*param_1 = auVar10;
    *(undefined1 (*) [32])(param_1[-1] + param_3 + 0x20) = auVar10;
    break;
  case 0x40:
    *param_1 = auVar8;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
    *param_1 = auVar8;
    *(undefined1 (*) [64])(param_1[-1] + param_3) = auVar8;
    break;
  default:
    uVar7 = 0x40U - (longlong)param_1 & 0x3f;
    if (uVar7 != 0) {
      param_3 = param_3 - uVar7;
      switch(uVar7) {
      case 1:
        (*param_1)[0] = uVar3;
        break;
      case 2:
        *(undefined2 *)*param_1 = uVar4;
        break;
      case 3:
        *(undefined2 *)*param_1 = uVar4;
        (*param_1)[2] = uVar3;
        break;
      case 4:
        *(undefined4 *)*param_1 = uVar5;
        break;
      case 5:
      case 6:
      case 7:
        *(undefined4 *)*param_1 = uVar5;
        *(undefined4 *)(param_1[-1] + uVar7 + 0x3c) = uVar5;
        break;
      case 8:
        *(longlong *)*param_1 = lVar6;
        break;
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
        *(longlong *)*param_1 = lVar6;
        *(longlong *)(param_1[-1] + uVar7 + 0x38) = lVar6;
        break;
      case 0x10:
        *(undefined1 (*) [16])*param_1 = auVar9;
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x1f:
        *(undefined1 (*) [16])*param_1 = auVar9;
        *(undefined1 (*) [16])(param_1[-1] + uVar7 + 0x30) = auVar9;
        break;
      case 0x20:
        *(undefined1 (*) [32])*param_1 = auVar10;
        break;
      default:
        *(undefined1 (*) [32])*param_1 = auVar10;
        *(undefined1 (*) [32])(param_1[-1] + uVar7 + 0x20) = auVar10;
      }
      param_1 = (undefined1 (*) [64])(*param_1 + uVar7);
    }
    if (0x1ff < (longlong)param_3) {
      pauVar2 = param_1;
      if (param_3 < DAT_180018870) {
        do {
          *pauVar2 = auVar8;
          pauVar2[1] = auVar8;
          pauVar2[2] = auVar8;
          pauVar2[3] = auVar8;
          param_1 = pauVar2 + 8;
          param_3 = param_3 - 0x200;
          pauVar2[4] = auVar8;
          pauVar2[5] = auVar8;
          pauVar2[6] = auVar8;
          pauVar2[7] = auVar8;
          pauVar2 = param_1;
        } while (0x1ff < (longlong)param_3);
      }
      else {
        do {
          auVar1 = vmovntdq_avx512f(auVar8);
          *pauVar2 = auVar1;
          auVar1 = vmovntdq_avx512f(auVar8);
          pauVar2[1] = auVar1;
          auVar1 = vmovntdq_avx512f(auVar8);
          pauVar2[2] = auVar1;
          auVar1 = vmovntdq_avx512f(auVar8);
          pauVar2[3] = auVar1;
          param_1 = pauVar2 + 8;
          param_3 = param_3 - 0x200;
          auVar1 = vmovntdq_avx512f(auVar8);
          pauVar2[4] = auVar1;
          auVar1 = vmovntdq_avx512f(auVar8);
          pauVar2[5] = auVar1;
          auVar1 = vmovntdq_avx512f(auVar8);
          pauVar2[6] = auVar1;
          auVar1 = vmovntdq_avx512f(auVar8);
          pauVar2[7] = auVar1;
          pauVar2 = param_1;
        } while (0x1ff < (longlong)param_3);
      }
    }
                    // WARNING: Could not recover jumptable at 0x00018000f773. Too many branches
                    // WARNING: Treating indirect jump as call
    pauVar2 = (undefined1 (*) [64])
              (*(code *)(&DAT_18000fa80 + -*(longlong *)(&DAT_18000fa80 + param_3 * 8)))
                        (auVar8._0_8_,&DAT_18000fa80 + -*(longlong *)(&DAT_18000fa80 + param_3 * 8),
                         (ulonglong)(*param_1 + param_3) & 0xffffffffffffffc0);
    return pauVar2;
  }
  return param_1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Removing unreachable block (ram,0x000180011248)
// WARNING: Removing unreachable block (ram,0x000180010f17)
// WARNING: Removing unreachable block (ram,0x000180011419)
// WARNING: Removing unreachable block (ram,0x000180011447)
// WARNING: Removing unreachable block (ram,0x0001800110e2)
// WARNING: Removing unreachable block (ram,0x000180011116)
// WARNING: Removing unreachable block (ram,0x000180011430)
// WARNING: Removing unreachable block (ram,0x0001800115c7)
// WARNING: Removing unreachable block (ram,0x0001800112b9)
// WARNING: Removing unreachable block (ram,0x0001800110a2)
// WARNING: Removing unreachable block (ram,0x0001800113f7)
// WARNING: Removing unreachable block (ram,0x000180011053)
// WARNING: Removing unreachable block (ram,0x000180011074)
// WARNING: Removing unreachable block (ram,0x000180011080)
// WARNING: Removing unreachable block (ram,0x00018001108c)
// WARNING: Removing unreachable block (ram,0x0001800110c0)
// WARNING: Removing unreachable block (ram,0x0001800110c6)
// WARNING: Removing unreachable block (ram,0x000180011100)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180010ec0(ulonglong param_1)

{
  ushort uVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  longlong lVar12;
  uint uVar13;
  ulonglong unaff_RBX;
  ulonglong *puVar14;
  undefined1 *puVar15;
  ulonglong *puVar16;
  undefined8 unaff_RDI;
  uint *puVar17;
  ulonglong *puVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong uVar21;
  int iVar22;
  ulonglong unaff_R12;
  ulonglong unaff_R13;
  longlong lVar23;
  undefined8 unaff_R14;
  undefined4 uVar24;
  bool bVar25;
  byte in_AF;
  byte bVar26;
  bool bVar27;
  byte in_TF;
  byte in_IF;
  bool bVar28;
  bool bVar29;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  ulonglong uVar30;
  ulonglong uVar31;
  undefined1 auStack_1b8 [32];
  undefined1 *local_198;
  undefined4 local_190;
  int local_18c;
  byte *local_188;
  uint *local_178;
  ulonglong local_170;
  ulonglong local_168;
  undefined8 local_160;
  undefined8 local_158;
  uint local_144;
  uint *local_140;
  int local_128;
  uint local_124;
  undefined4 local_11c;
  uint local_114;
  ulonglong *local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined1 local_100 [4];
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  undefined4 local_ec;
  uint local_e8 [30];
  byte local_70 [4];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  char *local_20;
  
  bVar28 = false;
  puVar14 = (ulonglong *)auStack_1b8;
  puVar15 = auStack_1b8;
  uVar24 = 0;
  uVar21 = 0;
  puVar18 = (ulonglong *)0x0;
  pcVar11 = (char *)(DAT_180018bd0 ^ (ulonglong)&local_198);
  local_20 = pcVar11;
  bVar25 = false;
  bVar29 = false;
  bVar27 = (int)DAT_18001942c < 0;
  bVar3 = POPCOUNT(DAT_18001942c & 0xff);
  bVar26 = 1;
  if (DAT_18001942c == 0) goto LAB_1800111e5;
  do {
    if (DAT_180019420 == 0) {
      puVar18 = &local_170;
      local_160 = 0x69746e6568747541;
      local_158 = CONCAT35(local_158._5_3_,0x444d4163);
      local_108 = 0;
      *(undefined8 *)((longlong)puVar14 + -8) = 0x69746e6568747541;
      *(ulonglong *)((longlong)puVar14 + -0x10) = unaff_RBX;
      *(ulonglong *)((longlong)puVar14 + -0x18) = param_1;
      *(undefined8 *)((longlong)puVar14 + -0x20) = 0;
      lVar19 = cpuid_basic_info(0);
      local_170 = (ulonglong)*(uint *)(lVar19 + 4);
      local_168 = (ulonglong)*(uint *)(lVar19 + 8);
      unaff_RBX = *(ulonglong *)((longlong)puVar14 + -0x10);
      pcVar11 = (char *)0x68747541;
      local_110 = puVar18;
    }
    else {
      if (DAT_180019424 != 0) {
        *(ulonglong *)((longlong)puVar14 + -8) = unaff_RBX;
        puVar4 = (undefined4 *)cpuid_Version_info(1);
        local_104 = *puVar4;
        local_11c = puVar4[1];
        local_114 = puVar4[2];
        if ((local_114 & 0x4000000) == 0) {
          if ((local_114 & 0x800000) != 0) {
            uVar24 = 1;
          }
        }
        else {
          uVar24 = 2;
        }
      }
      if (DAT_180019430 != 0) {
        uVar21 = (ulonglong)DAT_180019430;
        puVar18 = (ulonglong *)(ulonglong)(uint)(DAT_180019434 * DAT_180019438);
      }
      if ((uint)uVar21 < DAT_180019440) {
        uVar21 = (ulonglong)DAT_180019440;
        puVar18 = (ulonglong *)(ulonglong)(uint)(DAT_180019444 * DAT_180019448);
      }
      if ((uint)uVar21 < DAT_180019450) {
        uVar21 = (ulonglong)DAT_180019450;
        puVar18 = (ulonglong *)(ulonglong)(uint)(DAT_180019454 * DAT_180019458);
      }
      if (DAT_180019430 == 0) {
        *(undefined8 *)((longlong)puVar14 + -8) = 0x18001119c;
        pcVar11 = getenv("__INTEL_LIBIRC_DEBUG");
        unaff_RBX = 0;
        if ((pcVar11 != (char *)0x0) && (*pcVar11 != '\0')) {
          *(undefined8 *)((longlong)puVar14 + -8) = 0x1800111b5;
          FUN_180011660(1,0,0,puVar18);
          *(undefined8 *)((longlong)puVar14 + -8) = 0x1800111c7;
          FUN_180011660(1,0x3d,0,puVar18);
          *(undefined8 *)((longlong)puVar14 + -8) = 0x1800111d6;
          FUN_180011660(1,0,0,puVar18);
                    // WARNING: Subroutine does not return
          *(undefined8 *)((longlong)puVar14 + -8) = 0x1800111e0;
          exit(1);
        }
      }
      else {
        DAT_180018868 = DAT_180019430 * 0x400;
        DAT_180018860 = (int)uVar21 * 0x400;
        pcVar11 = (char *)(ulonglong)(uint)-(DAT_180018860 >> 0x1f);
        DAT_180018864 = DAT_180018860 / 2;
        uVar21 = (ulonglong)DAT_180018864;
        DAT_18001886c = DAT_180018868 / 2;
        _DAT_180018878 = DAT_180019430 * 0x1800;
        unaff_RBX = (ulonglong)_DAT_180018878;
        DAT_180018870._0_4_ = (int)(((uint)(DAT_180018868 >> 1) >> 0x1e) + DAT_180018868) >> 2;
        _DAT_180019468 = SUB84(puVar18,0);
        DAT_180018870._4_4_ = 0x2000;
        _DAT_18001887c = 0x800;
      }
    }
    pcVar8 = local_20;
    DAT_180019464 = uVar24;
    _DAT_180019460 = uVar24;
    local_20 = (char *)0x0;
    param_1 = (ulonglong)pcVar8 ^ (ulonglong)&local_198;
    bVar25 = param_1 < DAT_180018bd0;
    bVar29 = SBORROW8(param_1,DAT_180018bd0);
    uVar31 = param_1 - DAT_180018bd0;
    bVar27 = (longlong)uVar31 < 0;
    bVar3 = POPCOUNT(uVar31 & 0xff);
    if (uVar31 == 0) {
      return;
    }
    puVar15 = (undefined1 *)((longlong)puVar14 + -8);
    *(undefined8 *)((longlong)puVar14 + -8) = 0x1800111e5;
    bVar26 = 0;
LAB_1800111e5:
    *(char **)(puVar15 + -8) = pcVar11;
    puVar16 = (ulonglong *)(puVar15 + -0x10);
    *(ulonglong *)(puVar15 + -0x10) = param_1;
    *(ulonglong *)(puVar15 + -0x18) =
         (ulonglong)(in_NT & 1) * 0x4000 | (ulonglong)bVar29 * 0x800 | (ulonglong)bVar28 * 0x400 |
         (ulonglong)(in_IF & 1) * 0x200 | (ulonglong)(in_TF & 1) * 0x100 | (ulonglong)bVar27 * 0x80
         | (ulonglong)bVar26 * 0x40 | (ulonglong)(in_AF & 1) * 0x10 |
         (ulonglong)((bVar3 & 1) == 0) * 4 | (ulonglong)bVar25 | (ulonglong)(in_ID & 1) * 0x200000 |
         (ulonglong)(in_VIP & 1) * 0x100000 | (ulonglong)(in_VIF & 1) * 0x80000 |
         (ulonglong)(in_AC & 1) * 0x40000;
    uVar31 = *(ulonglong *)(puVar15 + -0x18);
    uVar9 = (uint)uVar31;
    *(ulonglong *)(puVar15 + -0x18) = (ulonglong)(uVar9 ^ 0x200000);
    uVar30 = *(ulonglong *)(puVar15 + -0x18);
    *(ulonglong *)(puVar15 + -0x18) =
         (ulonglong)((uVar30 & 0x4000) != 0) * 0x4000 | (ulonglong)((uVar30 & 0x800) != 0) * 0x800 |
         (ulonglong)((uVar30 & 0x400) != 0) * 0x400 | (ulonglong)((uVar30 & 0x200) != 0) * 0x200 |
         (ulonglong)((uVar30 & 0x100) != 0) * 0x100 | (ulonglong)((uVar30 & 0x80) != 0) * 0x80 |
         (ulonglong)((uVar30 & 0x40) != 0) * 0x40 | (ulonglong)((uVar30 & 0x10) != 0) * 0x10 |
         (ulonglong)((uVar30 & 4) != 0) * 4 | (ulonglong)((uVar30 & 1) != 0) |
         (ulonglong)((uVar30 & 0x200000) != 0) * 0x200000 |
         (ulonglong)((uVar30 & 0x40000) != 0) * 0x40000;
    uVar7 = *(undefined8 *)(puVar15 + -0x18);
    if ((uint)uVar7 != uVar9) {
      puVar16 = (ulonglong *)(puVar15 + -0x18);
      *(ulonglong *)(puVar15 + -0x18) = uVar31 & 0xffffffff;
    }
    local_124 = (uint)((uint)uVar7 != uVar9);
    uVar31 = *puVar16;
    in_NT = (uVar31 & 0x4000) != 0;
    bVar28 = (uVar31 & 0x400) != 0;
    in_IF = (uVar31 & 0x200) != 0;
    in_TF = (uVar31 & 0x100) != 0;
    in_AF = (uVar31 & 0x10) != 0;
    in_ID = (uVar31 & 0x200000) != 0;
    in_AC = (uVar31 & 0x40000) != 0;
    in_VIP = 0;
    in_VIF = 0;
    param_1 = puVar16[1];
    if (local_124 != 0) {
      local_140 = &local_144;
      local_30 = 0x49656e69756e6547;
      local_28 = 0x6c65746e;
      local_128 = 0;
      local_144 = 0;
      puVar16[2] = (ulonglong)local_140;
      puVar16[1] = unaff_RBX;
      *puVar16 = 0;
      puVar16[-1] = 0x49656e69756e6547;
      puVar17 = (uint *)cpuid_basic_info(0);
      if (((puVar17[1] == 0x756e6547) && (puVar17[2] == 0x49656e69)) && (puVar17[3] == 0x6c65746e))
      {
        local_128 = 1;
        local_144 = *puVar17;
      }
      param_1 = *puVar16;
      unaff_RBX = puVar16[1];
      uVar31 = (ulonglong)local_144;
      DAT_180019420 = local_128;
      DAT_180019424 = local_144;
      if (3 < (int)local_144) {
        local_178 = &local_f0;
        puVar16[2] = (ulonglong)local_178;
        puVar16[1] = unaff_RBX;
        *puVar16 = param_1;
        puVar16[-1] = uVar31;
        puVar16[-2] = unaff_RDI;
        local_18c = 0;
        puVar17 = local_178;
        while( true ) {
          puVar5 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
          uVar9 = puVar5[1];
          uVar13 = puVar5[2];
          uVar6 = puVar5[3];
          if ((*puVar5 & 0x1f) == 0) break;
          *puVar17 = *puVar5;
          puVar17[1] = uVar9;
          puVar17[2] = uVar6;
          puVar17[3] = uVar13;
          local_18c = local_18c + 1;
          if (7 < local_18c) break;
          puVar17 = puVar17 + 4;
        }
        uVar31 = puVar16[-1];
        param_1 = *puVar16;
        lVar19 = 0;
        unaff_RBX = 0;
        local_158 = unaff_RDI;
        if (0 < (longlong)local_18c) {
          do {
            bVar3 = *(byte *)((longlong)local_e8 + (unaff_RBX - 8));
            uVar31 = CONCAT71((int7)(uVar31 >> 8),bVar3);
            if ((bVar3 & 0x1d) == 1) {
              uVar30 = (ulonglong)(bVar3 >> 5);
              uVar31 = uVar30 * 0x10;
              uVar9 = *(uint *)((longlong)local_e8 + (unaff_RBX - 4));
              uVar13 = (*(ushort *)((longlong)local_e8 + (unaff_RBX - 4)) & 0xfff) + 1;
              param_1 = (ulonglong)uVar13;
              (&DAT_180019424)[uVar30 * 4] = uVar13;
              uVar1 = *(ushort *)((longlong)local_e8 + (unaff_RBX - 2));
              iVar10 = ((uVar9 & 0x3ff000) >> 0xc) + 1;
              *(int *)(&DAT_180019428 + uVar31) = iVar10;
              iVar22 = (uVar1 >> 6) + 1;
              iVar2 = *(int *)((longlong)local_e8 + unaff_RBX);
              (&DAT_18001942c)[uVar30 * 4] = iVar22;
              (&DAT_180019420)[uVar30 * 4] = (iVar2 + 1) * uVar13 * iVar10 * iVar22 >> 10;
            }
            lVar19 = lVar19 + 1;
            unaff_RBX = unaff_RBX + 0x10;
          } while (lVar19 < local_18c);
          local_170 = unaff_R12;
          local_168 = unaff_R13;
          local_160 = unaff_R14;
        }
      }
      if ((DAT_180019430 == 0) && (1 < (int)local_144)) {
        local_188 = local_70;
        puVar16[2] = (ulonglong)local_188;
        puVar16[1] = unaff_RBX;
        *puVar16 = param_1;
        puVar16[-1] = uVar31;
        puVar4 = (undefined4 *)cpuid_cache_tlb_info(2);
        local_70[0] = (byte)*puVar4;
        local_6c = puVar4[1];
        local_68 = puVar4[3];
        local_64 = puVar4[2];
        if ('\x01' < (char)local_70[0]) {
          if ('\x02' < (char)local_70[0]) {
            if ('\x03' < (char)local_70[0]) {
              puVar4 = (undefined4 *)cpuid_cache_tlb_info(2);
              local_40 = *puVar4;
              local_3c = puVar4[1];
              local_38 = puVar4[3];
              local_34 = puVar4[2];
            }
            puVar4 = (undefined4 *)cpuid_cache_tlb_info(2);
            local_50 = *puVar4;
            local_4c = puVar4[1];
            local_48 = puVar4[3];
            local_44 = puVar4[2];
          }
          puVar4 = (undefined4 *)cpuid_cache_tlb_info(2);
          local_60 = *puVar4;
          local_5c = puVar4[1];
          local_58 = puVar4[3];
          local_54 = puVar4[2];
        }
        param_1 = *puVar16;
        unaff_RBX = puVar16[1];
        if (local_70[0] < 5) {
          lVar19 = (ulonglong)local_70[0] << 2;
          if ((ulonglong)local_70[0] == 0) goto LAB_180011591;
        }
        else {
          lVar19 = 0x10;
        }
        lVar20 = 0;
        lVar12 = lVar19;
        do {
          if ((local_70[lVar20 * 4 + 3] & 0x80) == 0) {
            lVar23 = 0;
            do {
              uVar31 = (ulonglong)local_70[lVar23 + lVar20 * 4];
              if (uVar31 == 0xff) {
                _DAT_180019430 = (undefined1  [16])0x0;
                _DAT_180019440 = (undefined1  [16])0x0;
                _DAT_180019450 = (undefined1  [16])0x0;
                local_170 = unaff_R12;
                local_168 = unaff_R13;
                local_160 = unaff_R14;
                local_158 = unaff_RDI;
                goto LAB_180011591;
              }
              bVar3 = (&DAT_180018060)[uVar31 * 8];
              param_1 = CONCAT71((int7)(param_1 >> 8),bVar3) & 0xffffffffffffff07;
              uVar30 = (ulonglong)bVar3 & 7;
              if ((bVar3 & 7) != 0) {
                if ((uVar30 == 2) && (uVar31 == 0x49)) {
                  local_190 = 1;
                  local_198 = local_100;
                  puVar16[2] = lVar12;
                  puVar16[1] = unaff_RBX;
                  *puVar16 = param_1;
                  puVar16[-1] = (ulonglong)local_198;
                  puVar17 = (uint *)cpuid_Version_info(1);
                  uVar9 = *puVar17;
                  local_fc = puVar17[1];
                  local_f4 = puVar17[2];
                  local_f8 = puVar17[3];
                  lVar12 = puVar16[2];
                  if (((uVar9 & 0xf00) == 0xf00) &&
                     (((uVar9 & 0xf000000) == 0 && ((uVar9 >> 0xc & 0xf0 | uVar9 >> 4 & 0xf) == 6)))
                     ) {
                    uVar30 = 3;
                  }
                }
                unaff_RBX = 0x180000000;
                (&DAT_180019424)[uVar30 * 4] =
                     (*(ushort *)(&DAT_180018060 + uVar31 * 8) & 0x7ff8) >> 3;
                param_1 = 0x180000000;
                *(uint *)(&DAT_180019428 + uVar30 * 0x10) =
                     (*(uint *)(&DAT_180018060 + uVar31 * 8) & 0x3f8000) >> 0xf;
                (&DAT_18001942c)[uVar30 * 4] = (uint)(*(ushort *)(&DAT_180018062 + uVar31 * 8) >> 6)
                ;
                (&DAT_180019420)[uVar30 * 4] = *(undefined4 *)(&DAT_180018064 + uVar31 * 8);
              }
              lVar23 = lVar23 + 1;
            } while (lVar23 < 4);
          }
          lVar20 = lVar20 + 1;
        } while (lVar20 < lVar19);
        local_170 = unaff_R12;
        local_168 = unaff_R13;
        local_160 = unaff_R14;
        local_158 = unaff_RDI;
      }
    }
LAB_180011591:
    puVar14 = puVar16 + 3;
    DAT_18001942c = 1;
  } while( true );
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_180011660(int param_1,int param_2,int param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  LCID LVar3;
  DWORD DVar4;
  size_t sVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined8 local_res20;
  undefined8 uStackY_100;
  undefined1 auStackY_f8 [32];
  char *local_b8;
  undefined8 *local_b0;
  CHAR local_a8 [128];
  ulonglong local_28 [2];
  
  puVar6 = auStackY_f8;
  local_28[0] = DAT_180018bd0 ^ (ulonglong)auStackY_f8;
  local_res20 = param_4;
  if (param_2 == 0) {
    if (param_1 != 1) {
      puVar2 = auStackY_f8;
      if (DAT_1800188a0 == 0) goto LAB_1800118bc;
      goto LAB_1800116ba;
    }
    if (DAT_1800188a0 == 0) {
      FUN_180012100();
    }
    puVar6 = auStackY_f8;
    goto LAB_1800116ba;
  }
  if (DAT_180018880 == 0) {
LAB_180011760:
    if (DAT_180018884 != 0) {
      pcVar7 = (&PTR_DAT_180014a08)[(longlong)param_2 * 2];
      goto LAB_1800117fe;
    }
  }
  else {
    DAT_180018880 = 0;
    LVar3 = GetThreadLocale();
    if (DAT_1800188a0 == 0) {
      FUN_180012100();
    }
    (*(code *)PTR_FUN_180018980)(local_a8,"%lu/%s",LVar3,"irc_msg.dll");
    DAT_180019a80 = LoadLibraryA(local_a8);
    if (DAT_180019a80 == (HMODULE)0x0) goto LAB_180011760;
    DAT_180018884 = 0;
  }
  pcVar7 = (&PTR_DAT_180014a08)[(longlong)param_2 * 2];
  DVar4 = FormatMessageA(0x900,DAT_180019a80,param_2 + 0x80000000,0x409,(LPSTR)&local_b8,0x200,
                         (va_list *)0x0);
  if ((((DVar4 != 0) && (sVar5 = strlen(local_b8), pcVar7 = local_b8, 1 < sVar5)) &&
      (local_b8[sVar5 - 2] == '\r')) && (local_b8[sVar5 - 1] == '\n')) {
    strncpy(&DAT_180019680,local_b8,sVar5 - 2);
    pcVar7 = &DAT_180019680;
    (&DAT_18001967e)[sVar5] = 0;
  }
LAB_1800117fe:
  puVar6 = auStackY_f8;
  if (0 < param_3) {
    local_b0 = &local_res20;
    if (DAT_1800188a0 == 0) {
      FUN_180012100();
    }
    (*(code *)PTR_FUN_180018a20)(&DAT_180019880,pcVar7,local_b0);
    local_b0 = (undefined8 *)0x0;
    pcVar7 = &DAT_180019880;
  }
  if (param_1 == 1) {
    if (DAT_1800188a0 == 0) {
      FUN_180012100();
    }
    (*(code *)PTR_FUN_1800188b0)(pcVar7);
    if (DAT_1800188a0 == 0) {
      FUN_180012100();
    }
  }
  else {
    if (DAT_1800188a0 == 0) {
      FUN_180012100();
    }
    (*(code *)PTR_FUN_1800188b0)(pcVar7);
    if (DAT_1800188a0 == 0) {
      FUN_180012100();
    }
  }
  (*(code *)PTR_FUN_1800188b0)(&DAT_180014de0);
  uVar1 = local_28[0];
  local_28[0] = 0;
  if ((uVar1 ^ (ulonglong)auStackY_f8) == DAT_180018bd0) {
    return;
  }
  do {
    *(undefined8 *)(puVar6 + -8) = 0x1800118bc;
    puVar2 = puVar6 + -8;
LAB_1800118bc:
    puVar6 = puVar2;
    *(undefined8 *)(puVar6 + -8) = 0x1800118c1;
    FUN_180012100();
LAB_1800116ba:
    *(undefined8 *)(puVar6 + -8) = 0x1800116c3;
    (*(code *)PTR_FUN_1800188b0)(&DAT_180014de0);
    uVar1 = *(ulonglong *)(puVar6 + 0xd0);
    *(undefined8 *)(puVar6 + 0xd0) = 0;
  } while ((uVar1 ^ (ulonglong)puVar6) != DAT_180018bd0);
  return;
}



void FUN_180011980(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*(code *)PTR_FUN_180018a20)(param_1,param_3,&local_res20);
  return;
}



void FUN_1800119c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5)

{
  (*(code *)PTR_FUN_180018a40)(param_1,param_3,param_4,&param_5);
  return;
}



void FUN_180011a00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*(code *)PTR_FUN_180018a60)(param_1,param_3,&local_res20);
  return;
}



undefined4 FUN_180011a90(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  
  lVar1 = (*DAT_180018900)(param_2,param_3);
  *param_1 = lVar1;
  if (lVar1 == 0) {
    puVar2 = (undefined4 *)(*DAT_180018bb0)();
    return *puVar2;
  }
  return 0;
}



undefined4 FUN_180011ad0(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  
  lVar1 = (*DAT_180018b70)(param_2,param_3,param_4);
  *param_1 = lVar1;
  if (lVar1 == 0) {
    puVar2 = (undefined4 *)(*DAT_180018bb0)();
    return *puVar2;
  }
  return 0;
}



undefined4 FUN_180011b10(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  
  lVar1 = (*DAT_180018a90)(param_2,param_3);
  *param_1 = lVar1;
  if (lVar1 == 0) {
    puVar2 = (undefined4 *)(*DAT_180018bb0)();
    return *puVar2;
  }
  return 0;
}



undefined8
FUN_180011b60(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if ((undefined8 **)DAT_180019b10 == &DAT_180019ae0) {
    puVar2 = DAT_180019ae0;
  }
  else {
    puVar2 = DAT_180019b10;
    if (((undefined8 **)DAT_180019b10 != &DAT_180019b10) &&
       ((undefined8 **)DAT_180019b10 == &DAT_180019b40)) {
      puVar2 = DAT_180019b40;
    }
  }
  if (puVar2 < (undefined8 *)0x61) {
    uVar1 = 0xffffffff;
  }
  else {
    local_res10 = param_2;
    local_res18 = param_3;
    local_res20 = param_4;
    uVar1 = (*DAT_180019b70)(4,puVar2,param_1,0,&local_res10);
  }
  return uVar1;
}



undefined8
FUN_180011c00(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if ((undefined8 **)param_1 == &DAT_180019ae0) {
    param_1 = DAT_180019ae0;
  }
  else if ((undefined8 **)param_1 == &DAT_180019b10) {
    param_1 = DAT_180019b10;
  }
  else if ((undefined8 **)param_1 == &DAT_180019b40) {
    param_1 = DAT_180019b40;
  }
  if (param_1 < (undefined8 *)0x61) {
    uVar1 = 0xffffffff;
  }
  else {
    local_res18 = param_3;
    local_res20 = param_4;
    uVar1 = (*DAT_180019b70)(4,param_1,param_2,0,&local_res18);
  }
  return uVar1;
}



undefined8 FUN_180011ca0(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if ((undefined8 **)DAT_180019b10 == &DAT_180019ae0) {
    puVar1 = DAT_180019ae0;
  }
  else {
    puVar1 = DAT_180019b10;
    if (((undefined8 **)DAT_180019b10 != &DAT_180019b10) &&
       ((undefined8 **)DAT_180019b10 == &DAT_180019b40)) {
      puVar1 = DAT_180019b40;
    }
  }
  if (puVar1 < (undefined8 *)0x61) {
    return 0xffffffff;
  }
  uVar2 = (*DAT_180019b70)(4,puVar1,param_1,0,param_2);
  return uVar2;
}



undefined8 FUN_180011d20(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if ((undefined8 **)param_1 == &DAT_180019ae0) {
    param_1 = DAT_180019ae0;
  }
  else if ((undefined8 **)param_1 == &DAT_180019b10) {
    param_1 = DAT_180019b10;
  }
  else if ((undefined8 **)param_1 == &DAT_180019b40) {
    param_1 = DAT_180019b40;
  }
  if (param_1 < (undefined8 *)0x61) {
    return 0xffffffff;
  }
  uVar1 = (*DAT_180019b70)(4,param_1,param_2,0,param_3);
  return uVar1;
}



undefined8
FUN_180011da0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if ((undefined8 **)DAT_180019b10 == &DAT_180019ae0) {
    puVar2 = DAT_180019ae0;
  }
  else {
    puVar2 = DAT_180019b10;
    if (((undefined8 **)DAT_180019b10 != &DAT_180019b10) &&
       ((undefined8 **)DAT_180019b10 == &DAT_180019b40)) {
      puVar2 = DAT_180019b40;
    }
  }
  if (puVar2 < (undefined8 *)0x61) {
    uVar1 = 0xffffffff;
  }
  else {
    local_res10 = param_2;
    local_res18 = param_3;
    local_res20 = param_4;
    uVar1 = (*DAT_180019b78)(4,puVar2,param_1,0,&local_res10);
  }
  return uVar1;
}



undefined8
FUN_180011e40(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if ((undefined8 **)param_1 == &DAT_180019ae0) {
    param_1 = DAT_180019ae0;
  }
  else if ((undefined8 **)param_1 == &DAT_180019b10) {
    param_1 = DAT_180019b10;
  }
  else if ((undefined8 **)param_1 == &DAT_180019b40) {
    param_1 = DAT_180019b40;
  }
  if (param_1 < (undefined8 *)0x61) {
    uVar1 = 0xffffffff;
  }
  else {
    local_res18 = param_3;
    local_res20 = param_4;
    uVar1 = (*DAT_180019b78)(4,param_1,param_2,0,&local_res18);
  }
  return uVar1;
}



void FUN_180011ee0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  (*DAT_180019b80)(5,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  return;
}



void FUN_180011f40(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*DAT_180019b80)(5,param_1,param_2,param_3,0,&local_res20);
  return;
}



void FUN_180011fa0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  (*DAT_180019b80)(5,param_1,0xffffffffffffffff,param_2,0,param_3);
  return;
}



void FUN_180011fe0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  (*DAT_180019b80)(5,param_1,param_2,param_3,0,param_4);
  return;
}



int FUN_180012020(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = (*DAT_180019b80)(5,0,0,param_1,0,param_2);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



void FUN_180012060(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  (*DAT_180019b88)(4,param_1,0xffffffffffffffff,param_2,0,param_3);
  return;
}



void FUN_1800120a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  (*DAT_180019b90)(2,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

int FUN_180012100(void)

{
  char *_Src;
  longlong lVar1;
  HMODULE hModule;
  DWORD DVar2;
  BOOL BVar3;
  FARPROC pFVar4;
  byte bVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined1 auStack_1a8 [8];
  undefined8 uStack_1a0;
  undefined1 auStack_198 [16];
  undefined1 auStack_188 [16];
  HMODULE local_178 [2];
  CHAR local_168 [256];
  undefined4 local_68;
  undefined1 local_64;
  char *local_58 [3];
  ulonglong local_40;
  
  BVar3 = 0;
  lVar6 = 0x100;
  local_40 = DAT_180018bd0 ^ (ulonglong)auStack_198;
  local_178[0] = (HMODULE)0x0;
  local_68 = 0;
  local_64 = 0;
  do {
    *(undefined1 (*) [16])((longlong)local_178 + lVar6) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(auStack_188 + lVar6) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(auStack_198 + lVar6) = (undefined1  [16])0x0;
    *(undefined1 (*) [16])(auStack_1a8 + lVar6) = (undefined1  [16])0x0;
    lVar6 = lVar6 + -0x40;
  } while (lVar6 != 0);
  local_58[2] = (char *)0x0;
  local_58[1] = "ucrtbase.dll";
  local_58[0] = "msvcrt.dll";
  if (DAT_180019aa0 == 0) {
    uStack_1a0 = 0x180012653;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_180019aa0);
  }
  puVar7 = auStack_198;
  puVar8 = auStack_198;
  uStack_1a0 = 0x1800121b4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180019aa0);
  if (DAT_1800188a0 == -1) {
    uStack_1a0 = 0x18001260e;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180019aa0);
    uVar9 = local_40;
    local_40 = 0;
    if ((uVar9 ^ (ulonglong)auStack_198) != DAT_180018bd0) goto LAB_180012306;
    return 0;
  }
  uStack_1a0 = 0x1800121da;
  DVar2 = GetEnvironmentVariableA("SYSTEMROOT",local_168,0x105);
  uVar9 = (ulonglong)DVar2;
  if (uVar9 != 0) {
    uStack_1a0 = 0x1800121f8;
    strcat_s(local_168,0x105,"\\system32\\");
    uVar9 = uVar9 + 10;
  }
  lVar6 = 0;
  if (local_178[0] == (HMODULE)0x0) {
LAB_18001220c:
    do {
      if (local_58[lVar6] == (char *)0x0) {
        bVar5 = 0;
        lVar6 = 0;
        do {
          bVar5 = bVar5 + 1;
          *(undefined1 **)((longlong)&PTR_FUN_1800188b0 + lVar6) = &LAB_180012670;
          *(undefined1 **)((longlong)&DAT_1800188c0 + lVar6) = &LAB_180012670;
          lVar6 = lVar6 + 0x20;
        } while (bVar5 < 0x18);
        BVar3 = -1;
        DAT_180018bb0 = &LAB_180012670;
        puVar8 = auStack_198;
        goto LAB_180012319;
      }
      _Src = local_58[lVar6];
      local_168[uVar9] = '\0';
      uStack_1a0 = 0x180012238;
      strcat_s(local_168,0x105,_Src);
      uStack_1a0 = 0x18001224d;
      BVar3 = GetModuleHandleExA(1,local_168,local_178);
      if (local_178[0] == (HMODULE)0x0) {
        uStack_1a0 = 0x1800125a6;
        local_178[0] = LoadLibraryExA(local_168,(HANDLE)0x0,0);
        if (local_178[0] == (HMODULE)0x0) {
          lVar6 = lVar6 + 1;
          goto LAB_18001220c;
        }
      }
      hModule = local_178[0];
      if (local_58[lVar6] != "ucrtbase.dll") break;
      uStack_1a0 = 0x180012440;
      DAT_180019b98 = GetProcAddress(local_178[0],"__acrt_iob_func");
      uStack_1a0 = 0x180012457;
      DAT_180019b70 = GetProcAddress(hModule,"__stdio_common_vfprintf");
      if (DAT_180019b70 == (FARPROC)0x0) {
        DAT_180019b70 = (FARPROC)&LAB_180012670;
      }
      uStack_1a0 = 0x180012483;
      DAT_180019b70 = GetProcAddress(hModule,"__stdio_common_vfprintf");
      if (DAT_180019b70 == (FARPROC)0x0) {
        DAT_180019b70 = (FARPROC)&LAB_180012670;
      }
      uStack_1a0 = 0x1800124af;
      DAT_180019b78 = GetProcAddress(hModule,"__stdio_common_vfwprintf");
      if (DAT_180019b78 == (FARPROC)0x0) {
        DAT_180019b78 = (FARPROC)&LAB_180012670;
      }
      uStack_1a0 = 0x1800124db;
      DAT_180019b80 = GetProcAddress(hModule,"__stdio_common_vsprintf");
      if (DAT_180019b80 == (FARPROC)0x0) {
        DAT_180019b80 = (FARPROC)&LAB_180012670;
      }
      uStack_1a0 = 0x180012507;
      DAT_180019b88 = GetProcAddress(hModule,"__stdio_common_vswprintf");
      if (DAT_180019b88 == (FARPROC)0x0) {
        DAT_180019b88 = (FARPROC)&LAB_180012670;
      }
      uStack_1a0 = 0x180012533;
      DAT_180019b90 = GetProcAddress(hModule,"__stdio_common_vsscanf");
      if (DAT_180019b90 == (FARPROC)0x0) {
        DAT_180019b90 = (FARPROC)&LAB_180012670;
      }
      uStack_1a0 = 0x180012557;
      DAT_180019ae0 = (*DAT_180019b98)(0);
      uStack_1a0 = 0x180012569;
      DAT_180019b10 = (*DAT_180019b98)(1);
      uStack_1a0 = 0x18001257b;
      DAT_180019b40 = (*DAT_180019b98)(2);
      lVar6 = lVar6 + 1;
    } while (local_178[0] == (HMODULE)0x0);
  }
  lVar10 = 1;
  lVar6 = 0x10;
  do {
    uStack_1a0 = 0x180012295;
    pFVar4 = GetProcAddress(local_178[0],(LPCSTR)(*(longlong *)(lVar6 + 0x1800188a8) + 1));
    if (pFVar4 == (FARPROC)0x0) {
      lVar1 = *(longlong *)((longlong)&DAT_1800188a0 + lVar6);
      if (lVar1 == 0) {
        *(undefined1 **)((longlong)&DAT_1800188a0 + lVar6) = &LAB_180012670;
      }
      else if (lVar1 < lVar10) {
        *(longlong *)((longlong)&DAT_1800188a0 + lVar6) = (&DAT_1800188a0)[lVar1 * 2];
      }
    }
    else {
      *(FARPROC *)((longlong)&DAT_1800188a0 + lVar6) = pFVar4;
    }
    lVar10 = lVar10 + 1;
    lVar6 = lVar6 + 0x10;
  } while (lVar10 < 0x32);
  puVar7 = auStack_198;
  if (BVar3 == -1) goto LAB_180012319;
  while( true ) {
    DAT_1800188a0 = -1;
    *(undefined8 *)(puVar7 + -8) = 0x1800122d1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180019aa0);
    uVar9 = *(ulonglong *)(puVar7 + 0x158);
    *(undefined8 *)(puVar7 + 0x158) = 0;
    if ((uVar9 ^ (ulonglong)puVar7) == DAT_180018bd0) break;
LAB_180012306:
    puVar8 = puVar7 + -8;
    *(undefined8 *)(puVar7 + -8) = 0x18001230b;
LAB_180012319:
    if (DAT_180018900 == &LAB_180012670) {
      DAT_180018900 = &LAB_180012680;
    }
    if (DAT_180018a90 == &LAB_180012670) {
      DAT_180018a90 = &LAB_180012680;
    }
    if (DAT_180018ab0 == &LAB_180012670) {
      DAT_180018ab0 = &LAB_180012680;
    }
    if (DAT_180018ac0 == &LAB_180012670) {
      DAT_180018ac0 = &LAB_180012680;
    }
    if (DAT_180018ad0 == &LAB_180012670) {
      DAT_180018ad0 = &LAB_180012680;
    }
    if (DAT_180018ae0 == &LAB_180012670) {
      DAT_180018ae0 = &LAB_180012680;
    }
    if (DAT_180018b70 == &LAB_180012670) {
      DAT_180018b70 = &LAB_180012680;
    }
    if (DAT_180018b90 == &LAB_180012670) {
      DAT_180018b90 = &LAB_180012680;
    }
    puVar7 = puVar8;
    if (DAT_180018bb0 == &LAB_180012670) {
      DAT_180018bb0 = &LAB_180012660;
    }
  }
  return BVar3;
}



undefined8 * FUN_180012690(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    free(param_1);
  }
  return param_1;
}



// WARNING: This is an inlined function
// Library Function - Single Match
//  _alloca_probe
// 
// Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019

void _alloca_probe(void)

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



ulonglong FUN_180012724(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar2 = FUN_180012890(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar2);
  }
  if (param_2 == 1) {
    uVar3 = FUN_180012774(param_1,param_3);
    return uVar3;
  }
  if (param_2 == 2) {
    bVar1 = FUN_180012cf0();
  }
  else {
    if (param_2 != 3) {
      return 1;
    }
    bVar1 = FUN_180012d18();
  }
  return (ulonglong)bVar1;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

undefined8 FUN_180012774(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  
  lVar4 = __scrt_initialize_crt(0);
  if ((char)lVar4 != '\0') {
    uVar5 = __scrt_acquire_startup_lock();
    bVar1 = true;
    if (DAT_180019bc8 != 0) {
                    // WARNING: Subroutine does not return
      __scrt_fastfail(7);
    }
    DAT_180019bc8 = 1;
    bVar2 = FUN_180012cd8();
    if (bVar2) {
      FUN_180013140();
      FUN_180012c28();
      FUN_180012c4c();
      iVar3 = _initterm_e(&DAT_1800142b8,&DAT_1800142c0);
      if ((iVar3 == 0) && (uVar6 = __scrt_dllmain_after_initialize_c(), (char)uVar6 != '\0')) {
        _initterm(&DAT_1800142a0,&DAT_1800142b0);
        DAT_180019bc8 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar5);
    if (!bVar1) {
      plVar7 = (longlong *)FUN_180012fe4();
      if ((*plVar7 != 0) &&
         (uVar8 = __scrt_is_nonwritable_in_current_image((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)*plVar7)(param_1,2,param_2,_guard_dispatch_icall);
      }
      DAT_180019ba0 = DAT_180019ba0 + 1;
      return 1;
    }
  }
  return 0;
}



bool FUN_180012890(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  bool bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_180019ba0 < 1) {
    bVar5 = false;
  }
  else {
    DAT_180019ba0 = DAT_180019ba0 + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_180019bc8 != 2) {
                    // WARNING: Subroutine does not return
      __scrt_fastfail(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_180012c38();
    FUN_18001317c();
    DAT_180019bc8 = 0;
    FUN_180012dc0();
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = cVar2 != '\0';
  }
  return bVar5;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Removing unreachable block (ram,0x0001800129e4)
// WARNING: Removing unreachable block (ram,0x000180012973)
// WARNING: Removing unreachable block (ram,0x000180012a27)
// Library Function - Single Match
//  int __cdecl dllmain_dispatch(struct HINSTANCE__ * __ptr64 const,unsigned long,void * __ptr64
// const)
// 
// Library: Visual Studio 2017 Release

int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  if ((param_2 == 0) && (DAT_180019ba0 < 1)) {
    iVar1 = 0;
  }
  else {
    if ((param_2 - 1 < 2) &&
       (uVar2 = FUN_180012724(param_1,param_2,(longlong)param_3), (int)uVar2 == 0)) {
      return 0;
    }
    uVar3 = DllMain(param_1,param_2);
    iVar1 = (int)uVar3;
    if ((param_2 == 1) && (iVar1 == 0)) {
      DllMain(param_1,0);
      FUN_180012724(param_1,0,(longlong)param_3);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar2 = FUN_180012724(param_1,param_2,(longlong)param_3);
      iVar1 = 0;
      if ((int)uVar2 != 0) {
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}



void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}



// WARNING: This is an inlined function
// Library Function - Single Match
//  __security_check_cookie
// 
// Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != DAT_180018bd0) || ((short)(_StackCookie >> 0x30) != 0)) {
                    // WARNING: Subroutine does not return
    __report_gsfailure(_StackCookie);
  }
  return;
}



// Library Function - Single Match
//  __GSHandlerCheck
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// Library Function - Single Match
//  __GSHandlerCheckCommon
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}



void __cdecl free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x000180013506. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



// Library Function - Single Match
//  __security_init_cookie
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  _FILETIME local_res10;
  LARGE_INTEGER local_res18;
  
  if (DAT_180018bd0 == 0x2b992ddfa232) {
    local_res10.dwLowDateTime = 0;
    local_res10.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res10);
    local_res8 = local_res10;
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res18);
    DAT_180018bd0 =
         ((ulonglong)local_res18.s.LowPart << 0x20 ^
          CONCAT44(local_res18.s.HighPart,local_res18.s.LowPart) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
    if (DAT_180018bd0 == 0x2b992ddfa232) {
      DAT_180018bd0 = 0x2b992ddfa233;
    }
  }
  DAT_180018bc8 = ~DAT_180018bd0;
  return;
}



// Library Function - Single Match
//  DllMain
// 
// Library: Visual Studio 2017 Release

undefined8 DllMain(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



void FUN_180012c28(void)

{
                    // WARNING: Could not recover jumptable at 0x000180012c2f. Too many branches
                    // WARNING: Treating indirect jump as call
  InitializeSListHead(&DAT_180019bb0);
  return;
}



void FUN_180012c38(void)

{
  __std_type_info_destroy_list(&DAT_180019bb0);
  return;
}



undefined * FUN_180012c44(void)

{
  return &DAT_180019bc0;
}



void FUN_180012c4c(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_180001070();
  *puVar1 = *puVar1 | 4;
  puVar1 = (ulonglong *)FUN_180012c44();
  *puVar1 = *puVar1 | 2;
  return;
}



// Library Function - Single Match
//  __scrt_acquire_startup_lock
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_180012c96:
    uVar3 = (ulonglong)pvVar2 & 0xffffffffffffff00;
  }
  else {
    do {
      pvVar2 = (void *)0x0;
      LOCK();
      bVar1 = DAT_180019bd0 == (void *)0x0;
      if (bVar1) {
        DAT_180019bd0 = StackBase;
      }
      else {
        pvVar2 = DAT_180019bd0;
      }
      UNLOCK();
      if (bVar1) goto LAB_180012c96;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



// Library Function - Single Match
//  __scrt_dllmain_after_initialize_c
// 
// Library: Visual Studio 2017 Release

undefined8 __scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar3 = FUN_1800134bc();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _initialize_narrow_environment();
  }
  else {
    uVar2 = __isa_available_init();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



bool FUN_180012cd8(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_180012e20(0);
  return (char)uVar1 != '\0';
}



undefined1 FUN_180012cf0(void)

{
  char cVar1;
  
  cVar1 = FUN_180013560();
  if (cVar1 != '\0') {
    cVar1 = FUN_180013560();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_180013560();
  }
  return 0;
}



undefined1 FUN_180012d18(void)

{
  FUN_180013560();
  FUN_180013560();
  return 1;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// Library Function - Single Match
//  __scrt_dllmain_exception_filter
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __scrt_dllmain_exception_filter
               (undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,
               undefined4 param_5,undefined8 param_6)

{
  bool bVar1;
  undefined7 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) && (param_2 == 1)) {
    (*(code *)param_4)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}



// Library Function - Single Match
//  __scrt_dllmain_uninitialize_c
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _execute_onexit_table(&DAT_180019be0);
    return;
  }
  uVar2 = FUN_180013564();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}



void FUN_180012dc0(void)

{
  FUN_180013560();
  FUN_180013560();
  return;
}



// Library Function - Single Match
//  __scrt_initialize_crt
// 
// Library: Visual Studio 2017 Release

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_180019bd8 = 1;
  }
  __isa_available_init();
  cVar1 = FUN_180013560();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_180013560();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_180013560();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_180012e20(uint param_1)

{
  byte bVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_180019bd9 == '\0') {
    if (1 < param_1) {
                    // WARNING: Subroutine does not return
      __scrt_fastfail(5);
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      bVar1 = 0x40 - ((byte)DAT_180018bd0 & 0x3f) & 0x3f;
      in_RAX = (0xffffffffffffffffU >> bVar1 | -1L << 0x40 - bVar1) ^ DAT_180018bd0;
      _DAT_180019be0 = in_RAX;
      uRam0000000180019be8 = in_RAX;
      _DAT_180019bf0 = in_RAX;
      _DAT_180019bf8 = in_RAX;
      uRam0000000180019c00 = in_RAX;
      _DAT_180019c08 = in_RAX;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_180019be0);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_180019bf8), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_180019bd9 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



// WARNING: Removing unreachable block (ram,0x000180012f86)
// WARNING: Enum "SectionFlags": Some values do not have unique names
// Library Function - Single Match
//  __scrt_is_nonwritable_in_current_image
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_180000228; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_180000368;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x180000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x180000000U < uVar1)) goto LAB_180012f6f;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_180012f6f:
  if (pIVar3 == (IMAGE_SECTION_HEADER *)0x0) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (uint7)(uVar1 >> 8);
    if ((int)pIVar3->Characteristics < 0) {
      uVar1 = (ulonglong)uVar2 << 8;
    }
    else {
      uVar1 = CONCAT71(uVar2,1);
    }
  }
  return uVar1;
}



// Library Function - Single Match
//  __scrt_release_startup_lock
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_180019bd0 = 0;
    UNLOCK();
  }
  return;
}



// Library Function - Single Match
//  __scrt_uninitialize_crt
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_180019bd8 == '\0') || (param_2 == '\0')) {
    FUN_180013560();
    FUN_180013560();
  }
  return 1;
}



undefined * FUN_180012fe4(void)

{
  return &DAT_18001a1b8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180012fec(void)

{
  _DAT_180019c10 = 0;
  return;
}



// Library Function - Single Match
//  __scrt_fastfail
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __scrt_fastfail(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar4 = auStack_5c8;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x180013027;
  FUN_180012fec();
  *(undefined8 *)(puVar4 + -8) = 0x180013038;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180013042;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x18001305c;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x18001309d;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = local_res18 + -0x10;
  *(undefined8 *)(puVar4 + -8) = 0x1800130cf;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x1800130f1;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x180013112;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x18001311d;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x18001312d;
    FUN_180012fec();
  }
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_180013140(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &DAT_180016208; puVar1 < &DAT_180016208; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_18001317c(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &DAT_180016218; puVar1 < &DAT_180016218; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



void _guard_check_icall(void)

{
  return;
}



// Library Function - Single Match
//  __raise_securityfailure
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    // WARNING: Could not recover jumptable at 0x0001800131e9. Too many branches
                    // WARNING: Treating indirect jump as call
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __report_gsfailure
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar3 = auStack_38;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x18001321a;
  capture_previous_context((PCONTEXT)&DAT_180019cc0);
  _DAT_180019c30 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_180019d58 = puVar3 + 0x40;
  _DAT_180019d40 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180019c20 = 0xc0000409;
  _DAT_180019c24 = 1;
  _DAT_180019c38 = 1;
  DAT_180019c40 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_180018bd0;
  *(undefined8 *)(puVar3 + 0x28) = DAT_180018bc8;
  *(undefined8 *)(puVar3 + -8) = 0x1800132bc;
  DAT_180019db8 = _DAT_180019c30;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180015db0);
  return;
}



// Library Function - Single Match
//  capture_previous_context
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



void __cdecl free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x000180013506. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



// WARNING: Removing unreachable block (ram,0x00018001340e)
// WARNING: Removing unreachable block (ram,0x00018001338c)
// WARNING: Removing unreachable block (ram,0x000180013367)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __isa_available_init
// 
// Library: Visual Studio 2017 Release

undefined8 __isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  byte in_XCR0;
  
  DAT_180018bec = 2;
  _DAT_180018be8 = 1;
  piVar1 = (int *)cpuid_basic_info(0);
  uVar7 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[1] == 0x756e6547 && piVar1[3] == 0x6c65746e) && piVar1[2] == 0x49656e69) {
    _DAT_180018bf0 = 0xffffffffffffffff;
    uVar6 = *puVar2 & 0xfff3ff0;
    if ((((uVar6 == 0x106c0) || (uVar6 == 0x20660)) || (uVar6 == 0x20670)) ||
       ((uVar6 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar6 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_18001a190 = DAT_18001a190 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar7 = *(uint *)(lVar3 + 4);
    if ((uVar7 >> 9 & 1) != 0) {
      DAT_18001a190 = DAT_18001a190 | 2;
    }
  }
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_180018be8 = 2;
    DAT_180018bec = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) &&
       (uVar5 = xinuse(0), (in_XCR0 & (byte)uVar5 & 6) == 6)) {
      _DAT_180018be8 = 3;
      DAT_180018bec = 0xe;
      if ((uVar7 & 0x20) != 0) {
        _DAT_180018be8 = 5;
        DAT_180018bec = 0x2e;
      }
    }
  }
  return 0;
}



undefined8 FUN_1800134bc(void)

{
  return 1;
}



// Library Function - Single Match
//  __scrt_is_ucrt_dll_in_use
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_180018c00 != 0;
}



void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    // WARNING: Could not recover jumptable at 0x0001800134d0. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}



wchar_t * __cdecl wcschr(wchar_t *_Str,wchar_t _Ch)

{
  wchar_t *pwVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800134d6. Too many branches
                    // WARNING: Treating indirect jump as call
  pwVar1 = wcschr(_Str,_Ch);
  return pwVar1;
}



char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800134dc. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}



void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800134e2. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800134e8. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800134ee. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



void __std_type_info_destroy_list(void)

{
                    // WARNING: Could not recover jumptable at 0x0001800134fa. Too many branches
                    // WARNING: Treating indirect jump as call
  __std_type_info_destroy_list();
  return;
}



char * __cdecl getenv(char *_VarName)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013500. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = getenv(_VarName);
  return pcVar1;
}



void __cdecl free(void *_Memory)

{
                    // WARNING: Could not recover jumptable at 0x000180013506. Too many branches
                    // WARNING: Treating indirect jump as call
  free(_Memory);
  return;
}



char * __cdecl strncpy(char *_Dest,char *_Source,size_t _Count)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x00018001350c. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = strncpy(_Dest,_Source,_Count);
  return pcVar1;
}



void __cdecl exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x000180013512. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  exit(_Code);
  return;
}



size_t __cdecl strlen(char *_Str)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x000180013518. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = strlen(_Str);
  return sVar1;
}



errno_t __cdecl strcat_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  errno_t eVar1;
  
                    // WARNING: Could not recover jumptable at 0x00018001351e. Too many branches
                    // WARNING: Treating indirect jump as call
  eVar1 = strcat_s(_Dst,_SizeInBytes,_Src);
  return eVar1;
}



void _initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x00018001352a. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm();
  return;
}



void _initterm_e(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013530. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm_e();
  return;
}



void _seh_filter_dll(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013536. Too many branches
                    // WARNING: Treating indirect jump as call
  _seh_filter_dll();
  return;
}



void _configure_narrow_argv(void)

{
                    // WARNING: Could not recover jumptable at 0x00018001353c. Too many branches
                    // WARNING: Treating indirect jump as call
  _configure_narrow_argv();
  return;
}



void _initialize_narrow_environment(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013542. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_narrow_environment();
  return;
}



void _initialize_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013548. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_onexit_table();
  return;
}



void _execute_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x00018001354e. Too many branches
                    // WARNING: Treating indirect jump as call
  _execute_onexit_table();
  return;
}



void __cdecl _cexit(void)

{
                    // WARNING: Could not recover jumptable at 0x000180013554. Too many branches
                    // WARNING: Treating indirect jump as call
  _cexit();
  return;
}



BOOL __stdcall IsProcessorFeaturePresent(DWORD ProcessorFeature)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00018001355a. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = IsProcessorFeaturePresent(ProcessorFeature);
  return BVar1;
}



undefined1 FUN_180013560(void)

{
  return 1;
}



undefined8 FUN_180013564(void)

{
  return 0;
}



// WARNING: This is an inlined function

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    // WARNING: Could not recover jumptable at 0x000180013580. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



void FUN_180013582(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}



void FUN_180013599(undefined8 param_1,longlong param_2)

{
  FUN_180012dc0();
  __scrt_release_startup_lock(*(char *)(param_2 + 0x38));
  return;
}



void FUN_1800135b5(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_180012724,*(undefined4 *)*param_1,param_1);
  return;
}



bool FUN_1800135eb(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}


