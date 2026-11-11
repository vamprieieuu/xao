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
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

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

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

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

typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY _IMAGE_RUNTIME_FUNCTION_ENTRY, *P_IMAGE_RUNTIME_FUNCTION_ENTRY;

struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
    ImageBaseOffset32 BeginAddress;
    dword EndAddress; // Apply ImageBaseOffset32 to see reference
    ImageBaseOffset32 UnwindInfoAddressOrData;
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

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY IMAGE_LOAD_CONFIG_CODE_INTEGRITY, *PIMAGE_LOAD_CONFIG_CODE_INTEGRITY;

struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY {
    word Flags;
    word Catalog;
    dword CatalogOffset;
    dword Reserved;
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

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY64 IMAGE_LOAD_CONFIG_DIRECTORY64, *PIMAGE_LOAD_CONFIG_DIRECTORY64;

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




int FUN_180001000(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined * FUN_180001070(void);
uint * FUN_180001080(ulonglong *param_1,char *param_2);
ulonglong pluginMain(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6);
INT_PTR xGPUFilterEntry(uint param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6);
void * __cdecl MemoryCheck::operator_new[](__uint64 param_1);
void __cdecl MemoryCheck::operator_delete[](void *param_1);
MemoryCheck * __thiscall MemoryCheck::operator=(MemoryCheck *this,MemoryCheck *param_1);
SapphireAbortException * __thiscall SapphireAbortException::operator=(SapphireAbortException *this,SapphireAbortException *param_1);
void FUN_180001ee0(int *param_1,undefined1 (*param_2) [64],uint param_3);
void FUN_180001f80(int *param_1,undefined1 (*param_2) [64],uint param_3);
void FUN_180002560(int *param_1,undefined1 (*param_2) [64],uint param_3);
void FUN_180002bf0(int *param_1,undefined1 (*param_2) [64],uint param_3);
void FUN_180003190(int *param_1,undefined1 (*param_2) [64],uint param_3);
void FUN_1800039b0(int *param_1,undefined1 (*param_2) [64],uint param_3);
void FUN_180004240(undefined1 (*param_1) [16],undefined1 (*param_2) [64]);
void FUN_1800042e0(undefined1 (*param_1) [16],undefined1 (*param_2) [32]);
void FUN_180004780(undefined1 (*param_1) [16],undefined1 (*param_2) [64]);
void FUN_180004d40(undefined1 (*param_1) [16],undefined1 (*param_2) [32]);
void FUN_1800051e0(undefined8 *param_1,undefined1 (*param_2) [16]);
void FUN_180005800(undefined8 *param_1,undefined1 (*param_2) [16]);
void FUN_180005f90(undefined1 (*param_1) [16],char *param_2);
void FUN_180006027(void);
void FUN_180006ba9(void);
void FUN_1800074d0(int *param_1,int *param_2);
void FUN_180007cc0(undefined8 *param_1);
undefined1 (*) [64] FUN_180007e00(undefined1 (*param_1) [64],char *param_2);
void FUN_180007f70(char *param_1,undefined1 (*param_2) [64]);
uint * FUN_180008320(HKEY param_1,uint *param_2,char *param_3,uint *param_4,DWORD param_5,uint *param_6,int param_7);
undefined4 FUN_180008750(HKEY param_1,LPCSTR param_2,LPCSTR param_3,LPBYTE param_4,undefined4 param_5);
void FUN_180008820(HKEY param_1,LPCSTR param_2,LPCSTR param_3,undefined4 param_4);
bool FUN_180008a50(LPCSTR param_1);
bool FUN_180008ab0(LPCSTR param_1);
void FUN_180008b10(char *param_1,void *param_2,char *param_3,void *param_4);
char * FUN_180008c30(undefined8 param_1,longlong param_2);
void FUN_180008c60(uint *param_1,uint *param_2);
void FUN_180008cc7(uint *param_1);
void FUN_180008ce9(char *param_1);
void FUN_180008d03(char *param_1);
void FUN_180008d30(undefined8 *param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
void FUN_180008dc0(undefined8 param_1,uint *param_2);
void FUN_180008ed6(undefined8 param_1,char *param_2);
void FUN_180008f05(uint param_1,longlong param_2);
undefined8 FUN_180008f60(void);
void FUN_180008f80(void);
void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size);
undefined8 * thunk_FUN_1800096d0(undefined8 *param_1,undefined8 *param_2,ulonglong param_3);
void thunk_FUN_18000a780(undefined1 (*param_1) [32],undefined1 (*param_2) [32],ulonglong param_3);
void thunk_FUN_18000c040(undefined1 (*param_1) [64],undefined1 (*param_2) [64],ulonglong param_3);
void FUN_180009540(undefined1 (*param_1) [64],undefined1 (*param_2) [64],size_t param_3);
void * __cdecl memset(void *_Dst,int _Val,size_t _Size);
byte * thunk_FUN_18000db80(byte *param_1,byte param_2,longlong param_3);
undefined1 (*) [32]thunk_FUN_18000e580(undefined1 (*param_1) [32],ulonglong param_2,ulonglong param_3);
undefined1 (*) [64]thunk_FUN_18000f5c0(undefined1 (*param_1) [64],ulonglong param_2,ulonglong param_3);
void FUN_180009600(undefined1 (*param_1) [64],ulonglong param_2,size_t param_3);
char * FUN_180009680(void);
undefined8 * FUN_1800096d0(undefined8 *param_1,undefined8 *param_2,ulonglong param_3);
void FUN_18000a780(undefined1 (*param_1) [32],undefined1 (*param_2) [32],ulonglong param_3);
void FUN_18000c040(undefined1 (*param_1) [64],undefined1 (*param_2) [64],ulonglong param_3);
byte * FUN_18000db80(byte *param_1,byte param_2,longlong param_3);
undefined1 (*) [32] FUN_18000e580(undefined1 (*param_1) [32],ulonglong param_2,ulonglong param_3);
undefined1 (*) [64] FUN_18000f5c0(undefined1 (*param_1) [64],ulonglong param_2,ulonglong param_3);
void FUN_180010ec0(ulonglong param_1);
void FUN_180011660(int param_1,int param_2,int param_3,undefined8 param_4);
void FUN_180011980(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void FUN_1800119c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined1 param_5);
void FUN_180011a00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined4 FUN_180011a90(longlong *param_1,undefined8 param_2,undefined8 param_3);
undefined4 FUN_180011ad0(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined4 FUN_180011b10(longlong *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_180011b60(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_180011c00(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_180011ca0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_180011d20(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_180011da0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_180011e40(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void FUN_180011ee0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void FUN_180011f40(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void FUN_180011fa0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void FUN_180011fe0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
int FUN_180012020(undefined8 param_1,undefined8 param_2);
void FUN_180012060(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void FUN_1800120a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
int FUN_180012100(void);
undefined8 * FUN_180012690(undefined8 *param_1,ulonglong param_2);
void _alloca_probe(void);
ulonglong FUN_180012724(undefined8 param_1,int param_2,longlong param_3);
undefined8 FUN_180012774(undefined8 param_1,undefined8 param_2);
bool FUN_180012890(undefined8 param_1);
int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3);
void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3);
void __cdecl __security_check_cookie(uintptr_t _StackCookie);
undefined8 __GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4);
ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2);
void __cdecl free(void *_Memory);
void __cdecl __security_init_cookie(void);
undefined8 DllMain(HMODULE param_1,int param_2);
void FUN_180012c28(void);
void FUN_180012c38(void);
undefined * FUN_180012c44(void);
void FUN_180012c4c(void);
ulonglong __scrt_acquire_startup_lock(void);
undefined8 __scrt_dllmain_after_initialize_c(void);
bool FUN_180012cd8(void);
undefined1 FUN_180012cf0(void);
undefined1 FUN_180012d18(void);
void __scrt_dllmain_exception_filter(undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,undefined4 param_5,undefined8 param_6);
void __scrt_dllmain_uninitialize_c(void);
void FUN_180012dc0(void);
longlong __scrt_initialize_crt(int param_1);
undefined8 FUN_180012e20(uint param_1);
ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1);
void __scrt_release_startup_lock(char param_1);
undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2);
undefined * FUN_180012fe4(void);
void FUN_180012fec(void);
void __scrt_fastfail(undefined4 param_1);
void FUN_180013140(void);
void FUN_18001317c(void);
void _guard_check_icall(void);
void __raise_securityfailure(_EXCEPTION_POINTERS *param_1);
void __cdecl __report_gsfailure(uintptr_t _StackCookie);
void capture_previous_context(PCONTEXT param_1);
void __cdecl free(void *_Memory);
undefined8 __isa_available_init(void);
undefined8 FUN_1800134bc(void);
bool __scrt_is_ucrt_dll_in_use(void);
void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo);
wchar_t * __cdecl wcschr(wchar_t *_Str,wchar_t _Ch);
char * __cdecl strstr(char *_Str,char *_SubStr);
void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size);
void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size);
void * __cdecl memset(void *_Dst,int _Val,size_t _Size);
void __std_type_info_destroy_list(void);
char * __cdecl getenv(char *_VarName);
void __cdecl free(void *_Memory);
char * __cdecl strncpy(char *_Dest,char *_Source,size_t _Count);
void __cdecl exit(int _Code);
size_t __cdecl strlen(char *_Str);
errno_t __cdecl strcat_s(char *_Dst,rsize_t _SizeInBytes,char *_Src);
void _initterm(void);
void _initterm_e(void);
void _seh_filter_dll(void);
void _configure_narrow_argv(void);
void _initialize_narrow_environment(void);
void _initialize_onexit_table(void);
void _execute_onexit_table(void);
void __cdecl _cexit(void);
BOOL __stdcall IsProcessorFeaturePresent(DWORD ProcessorFeature);
undefined1 FUN_180013560(void);
undefined8 FUN_180013564(void);
void _guard_dispatch_icall(void);
void FUN_180013582(undefined8 param_1,longlong param_2);
void FUN_180013599(undefined8 param_1,longlong param_2);
void FUN_1800135b5(undefined8 *param_1,longlong param_2);
bool FUN_1800135eb(undefined8 *param_1);

