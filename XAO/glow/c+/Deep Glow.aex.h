typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    int64_t;
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

typedef struct _s_UnwindMapEntry _s_UnwindMapEntry, *P_s_UnwindMapEntry;

typedef struct _s_UnwindMapEntry UnwindMapEntry;

typedef int __ehstate_t;

struct _s_UnwindMapEntry {
    __ehstate_t toState;
    ImageBaseOffset32 action;
};

typedef struct _s_IPToStateMapEntry _s_IPToStateMapEntry, *P_s_IPToStateMapEntry;

typedef struct _s_IPToStateMapEntry IPToStateMapEntry;

struct _s_IPToStateMapEntry {
    ImageBaseOffset32 Ip;
    __ehstate_t state;
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

typedef uint64_t __uint64;

typedef struct _s_TryBlockMapEntry _s_TryBlockMapEntry, *P_s_TryBlockMapEntry;

typedef struct _s_TryBlockMapEntry TryBlockMapEntry;

struct _s_TryBlockMapEntry {
    __ehstate_t tryLow;
    __ehstate_t tryHigh;
    __ehstate_t catchHigh;
    int nCatches;
    ImageBaseOffset32 dispHandlerArray;
};

typedef struct _s__RTTICompleteObjectLocator _s__RTTICompleteObjectLocator, *P_s__RTTICompleteObjectLocator;

typedef struct _s__RTTICompleteObjectLocator RTTICompleteObjectLocator;

struct _s__RTTICompleteObjectLocator {
    dword signature;
    dword offset; // offset of vbtable within class
    dword cdOffset; // constructor displacement offset
    ImageBaseOffset32 pTypeDescriptor; // ref to TypeDescriptor (RTTI 0) for class
    ImageBaseOffset32 pClassDescriptor; // ref to ClassHierarchyDescriptor (RTTI 3)
};

typedef struct _s_FuncInfo _s_FuncInfo, *P_s_FuncInfo;

struct _s_FuncInfo {
    uint magicNumber_and_bbtFlags;
    __ehstate_t maxState;
    ImageBaseOffset32 dispUnwindMap;
    uint nTryBlocks;
    ImageBaseOffset32 dispTryBlockMap;
    uint nIPMapEntries;
    ImageBaseOffset32 dispIPToStateMap;
    int dispUnwindHelp;
    ImageBaseOffset32 dispESTypeList;
    int EHFlags;
};

typedef struct _s_HandlerType _s_HandlerType, *P_s_HandlerType;

typedef struct _s_HandlerType HandlerType;

struct _s_HandlerType {
    uint adjectives;
    ImageBaseOffset32 dispType;
    int dispCatchObj;
    ImageBaseOffset32 dispOfHandler;
    dword dispFrame;
};

typedef struct _s_FuncInfo FuncInfo;

typedef struct tagMSG tagMSG, *PtagMSG;

typedef struct tagMSG MSG;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

typedef uint UINT;

typedef ulonglong UINT_PTR;

typedef UINT_PTR WPARAM;

typedef longlong LONG_PTR;

typedef LONG_PTR LPARAM;

typedef ulong DWORD;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

typedef struct tagPOINT POINT;

typedef long LONG;

struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

struct HWND__ {
    int unused;
};

struct tagPOINT {
    LONG x;
    LONG y;
};

typedef struct tagWNDCLASSEXA tagWNDCLASSEXA, *PtagWNDCLASSEXA;

typedef struct tagWNDCLASSEXA WNDCLASSEXA;

typedef LONG_PTR LRESULT;

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ *HICON;

typedef HICON HCURSOR;

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ *HBRUSH;

typedef char CHAR;

typedef CHAR *LPCSTR;

struct tagWNDCLASSEXA {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
};

struct HINSTANCE__ {
    int unused;
};

struct HICON__ {
    int unused;
};

struct HBRUSH__ {
    int unused;
};

typedef struct tagMSG *LPMSG;

typedef struct basic_filebuf<char,std::char_traits<char>_> basic_filebuf<char,std::char_traits<char>_>, *Pbasic_filebuf<char,std::char_traits<char>_>;

struct basic_filebuf<char,std::char_traits<char>_> { // PlaceHolder Class Structure
};

typedef struct tagPIXELFORMATDESCRIPTOR tagPIXELFORMATDESCRIPTOR, *PtagPIXELFORMATDESCRIPTOR;

typedef ushort WORD;

typedef uchar BYTE;

struct tagPIXELFORMATDESCRIPTOR {
    WORD nSize;
    WORD nVersion;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE cColorBits;
    BYTE cRedBits;
    BYTE cRedShift;
    BYTE cGreenBits;
    BYTE cGreenShift;
    BYTE cBlueBits;
    BYTE cBlueShift;
    BYTE cAlphaBits;
    BYTE cAlphaShift;
    BYTE cAccumBits;
    BYTE cAccumRedBits;
    BYTE cAccumGreenBits;
    BYTE cAccumBlueBits;
    BYTE cAccumAlphaBits;
    BYTE cDepthBits;
    BYTE cStencilBits;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dwLayerMask;
    DWORD dwVisibleMask;
    DWORD dwDamageMask;
};

typedef struct tagPIXELFORMATDESCRIPTOR PIXELFORMATDESCRIPTOR;

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef void *LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _SYSTEMTIME _SYSTEMTIME, *P_SYSTEMTIME;

struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef void *HANDLE;

typedef ulonglong ULONG_PTR;

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

typedef struct _SYSTEMTIME SYSTEMTIME;

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

typedef struct _SYSTEMTIME *LPSYSTEMTIME;

typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

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

typedef wchar_t WCHAR;

typedef WCHAR *LPCWSTR;

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

typedef CHAR *LPSTR;

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

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

typedef longlong INT_PTR;

typedef longlong fpos_t;

typedef struct HGLRC__ HGLRC__, *PHGLRC__;

typedef struct HGLRC__ *HGLRC;

struct HGLRC__ {
    int unused;
};

typedef DWORD *LPDWORD;

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME FILETIME;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

typedef struct HDC__ HDC__, *PHDC__;

struct HDC__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef struct _FILETIME *LPFILETIME;

typedef INT_PTR (*FARPROC)(void);

typedef struct HDC__ *HDC;

typedef struct tagRECT tagRECT, *PtagRECT;

struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

typedef int INT;

typedef WORD ATOM;

typedef struct tagRECT *LPRECT;

typedef void *HGDIOBJ;

typedef INT_PTR (*PROC)(void);

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

typedef struct IMAGE_THUNK_DATA64 IMAGE_THUNK_DATA64, *PIMAGE_THUNK_DATA64;

struct IMAGE_THUNK_DATA64 {
    qword StartAddressOfRawData;
    qword EndAddressOfRawData;
    qword AddressOfIndex;
    qword AddressOfCallBacks;
    dword SizeOfZeroFill;
    dword Characteristics;
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

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};

typedef struct _iobuf FILE;

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

typedef ulonglong uintptr_t;

typedef ulong u_long;

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

typedef ushort u_short;

typedef WSADATA *LPWSADATA;

typedef struct sockaddr sockaddr, *Psockaddr;

struct sockaddr {
    u_short sa_family;
    char sa_data[14];
};

typedef struct fd_set fd_set, *Pfd_set;

typedef uint u_int;

struct fd_set {
    u_int fd_count;
    SOCKET fd_array[64];
};

typedef struct timeval timeval, *Ptimeval;

struct timeval {
    long tv_sec;
    long tv_usec;
};

typedef struct _Mbstatet _Mbstatet, *P_Mbstatet;

struct _Mbstatet { // PlaceHolder Structure
};

typedef struct aescriptsLicenseData aescriptsLicenseData, *PaescriptsLicenseData;

struct aescriptsLicenseData { // PlaceHolder Structure
};

typedef struct basic_istream<char,struct_std::char_traits<char>_> basic_istream<char,struct_std::char_traits<char>_>, *Pbasic_istream<char,struct_std::char_traits<char>_>;

struct basic_istream<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct codecvt_base codecvt_base, *Pcodecvt_base;

struct codecvt_base { // PlaceHolder Structure
};

typedef struct locale locale, *Plocale;

struct locale { // PlaceHolder Structure
};

typedef struct basic_istream<char,std::char_traits<char>_> basic_istream<char,std::char_traits<char>_>, *Pbasic_istream<char,std::char_traits<char>_>;

struct basic_istream<char,std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct _Fac_tidy_reg_t _Fac_tidy_reg_t, *P_Fac_tidy_reg_t;

struct _Fac_tidy_reg_t { // PlaceHolder Structure
};

typedef struct vector<CHN*___ptr64,std::allocator<CHN*___ptr64>_> vector<CHN*___ptr64,std::allocator<CHN*___ptr64>_>, *Pvector<CHN*___ptr64,std::allocator<CHN*___ptr64>_>;

struct vector<CHN*___ptr64,std::allocator<CHN*___ptr64>_> { // PlaceHolder Structure
};

typedef struct basic_streambuf<char,std::char_traits<char>_> basic_streambuf<char,std::char_traits<char>_>, *Pbasic_streambuf<char,std::char_traits<char>_>;

struct basic_streambuf<char,std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_iostream<char,std::char_traits<char>_> basic_iostream<char,std::char_traits<char>_>, *Pbasic_iostream<char,std::char_traits<char>_>;

struct basic_iostream<char,std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_streambuf<char,struct_std::char_traits<char>_> basic_streambuf<char,struct_std::char_traits<char>_>, *Pbasic_streambuf<char,struct_std::char_traits<char>_>;

struct basic_streambuf<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct vector<unsigned___int64,std::allocator<unsigned___int64>_> vector<unsigned___int64,std::allocator<unsigned___int64>_>, *Pvector<unsigned___int64,std::allocator<unsigned___int64>_>;

struct vector<unsigned___int64,std::allocator<unsigned___int64>_> { // PlaceHolder Structure
};

typedef struct ios_base ios_base, *Pios_base;

struct ios_base { // PlaceHolder Structure
};

typedef struct basic_ios<char,std::char_traits<char>_> basic_ios<char,std::char_traits<char>_>, *Pbasic_ios<char,std::char_traits<char>_>;

struct basic_ios<char,std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct vector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_> vector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_>, *Pvector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_>;

struct vector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_> { // PlaceHolder Structure
};

typedef struct _Smanip<__int64> _Smanip<__int64>, *P_Smanip<__int64>;

struct _Smanip<__int64> { // PlaceHolder Structure
};

typedef struct vector<GSISymbolEntry,std::allocator<GSISymbolEntry>_> vector<GSISymbolEntry,std::allocator<GSISymbolEntry>_>, *Pvector<GSISymbolEntry,std::allocator<GSISymbolEntry>_>;

struct vector<GSISymbolEntry,std::allocator<GSISymbolEntry>_> { // PlaceHolder Structure
};

typedef struct _Facet_base _Facet_base, *P_Facet_base;

struct _Facet_base { // PlaceHolder Structure
};

typedef struct priority_queue<unsigned___int64,std::vector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_>,std::greater<void>_> priority_queue<unsigned___int64,std::vector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_>,std::greater<void>_>, *Ppriority_queue<unsigned___int64,std::vector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_>,std::greater<void>_>;

struct priority_queue<unsigned___int64,std::vector<unsigned___int64,std::_Parallelism_allocator<unsigned___int64>_>,std::greater<void>_> { // PlaceHolder Structure
};

typedef struct basic_ostream<char,struct_std::char_traits<char>_> basic_ostream<char,struct_std::char_traits<char>_>, *Pbasic_ostream<char,struct_std::char_traits<char>_>;

struct basic_ostream<char,struct_std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct basic_ostream<char,std::char_traits<char>_> basic_ostream<char,std::char_traits<char>_>, *Pbasic_ostream<char,std::char_traits<char>_>;

struct basic_ostream<char,std::char_traits<char>_> { // PlaceHolder Structure
};

typedef struct codecvt<char,char,_Mbstatet> codecvt<char,char,_Mbstatet>, *Pcodecvt<char,char,_Mbstatet>;

struct codecvt<char,char,_Mbstatet> { // PlaceHolder Structure
};

typedef struct fpos<_Mbstatet> fpos<_Mbstatet>, *Pfpos<_Mbstatet>;

struct fpos<_Mbstatet> { // PlaceHolder Structure
};

typedef struct _Lockit _Lockit, *P_Lockit;

struct _Lockit { // PlaceHolder Structure
};

typedef struct _Locimp _Locimp, *P_Locimp;

struct _Locimp { // PlaceHolder Structure
};

typedef struct facet facet, *Pfacet;

struct facet { // PlaceHolder Structure
};

typedef struct id id, *Pid;

struct id { // PlaceHolder Structure
};

typedef int (*_onexit_t)(void);

typedef longlong __time64_t;

typedef ulonglong size_t;

typedef int errno_t;




void FUN_180001000(void);
void FUN_180001030(void);
void FUN_180001060(void);
void FUN_180001090(void);
void FUN_1800010c0(void);
void FUN_1800010f0(void);
void FUN_180001120(void);
void FUN_180001150(void);
void FUN_180001180(void);
void FUN_1800011b0(void);
void FUN_1800011e0(void);
void FUN_180001380(void);
void FUN_1800013f0(void);
void FUN_180001410(void);
basic_ostream<> * FUN_1800014e0(basic_ostream<> *param_1,char *param_2);
size_t FUN_1800016b0(undefined8 *param_1,void *param_2);
float * FUN_180001700(float *param_1,float *param_2,float *param_3);
longlong * FUN_180001cc0(longlong *param_1,longlong *param_2,undefined8 *param_3);
longlong * FUN_180001d50(longlong *param_1,undefined8 *param_2,void *param_3);
void FUN_180001e10(undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,undefined8 *param_5);
void FUN_180001e90(longlong *param_1,longlong *param_2);
longlong FUN_180001f20(longlong *param_1,void *param_2,undefined8 *param_3);
longlong FUN_1800021e0(longlong *param_1,longlong *param_2,undefined8 *param_3);
void FUN_1800023d0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3);
longlong * FUN_180002470(float *param_1,longlong *param_2,undefined8 *param_3,longlong *param_4);
basic_ostream<> * FUN_1800026d0(basic_ostream<> *param_1,char *param_2,ulonglong param_3);
undefined1 * FUN_1800028b0(undefined1 *param_1);
undefined8 *FUN_1800028c0(undefined8 *param_1,ulonglong param_2,undefined8 param_3,size_t param_4,longlong param_5,void *param_6,size_t param_7);
undefined8 *FUN_180002a80(undefined8 *param_1,ulonglong param_2,undefined8 param_3,undefined1 param_4);
undefined8 *FUN_180002be0(undefined8 *param_1,ulonglong param_2,undefined8 param_3,void *param_4,size_t param_5);
undefined8 *FUN_180002d60(undefined8 *param_1,ulonglong param_2,undefined8 param_3,size_t param_4,void *param_5,size_t param_6);
longlong * FUN_180002f00(float *param_1,longlong *param_2,undefined8 *param_3);
longlong * FUN_1800030f0(longlong *param_1,longlong *param_2,longlong *param_3);
basic_ostream<> * FUN_180003170(basic_ostream<> *param_1);
longlong * FUN_1800031b0(longlong param_1,longlong *param_2,longlong *param_3);
undefined8 * FUN_1800032a0(undefined8 *param_1,float *param_2);
_Facet_base * FUN_180003420(locale *param_1);
undefined8 *FUN_180003510(undefined8 *param_1,longlong param_2,undefined8 param_3,undefined4 param_4,longlong param_5,char *param_6);
undefined8 * FUN_1800035c0(undefined8 *param_1,undefined8 *param_2);
longlong * FUN_1800036a0(longlong *param_1,void *param_2);
longlong * FUN_1800036e0(longlong *param_1,ulonglong param_2,char param_3);
undefined8 * FUN_180003850(undefined8 *param_1,undefined4 *param_2);
undefined8 * FUN_180003910(undefined8 *param_1);
longlong *FUN_180003920(longlong *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,HINSTANCE param_8);
undefined8 * FUN_180003d20(undefined8 *param_1,longlong param_2);
undefined8 * FUN_180003d60(undefined8 *param_1);
undefined8 * FUN_180003d90(undefined8 *param_1,longlong param_2);
void FUN_180003dd0(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void FUN_180003e00(longlong param_1);
void FUN_180003e70(basic_streambuf<> *param_1);
void FUN_180003ef0(longlong *param_1);
void FUN_180003f50(basic_streambuf<> *param_1);
void FUN_180004010(longlong *param_1);
void FUN_1800040e0(undefined8 *param_1);
void FUN_180004110(longlong *param_1);
void thunk_FUN_180003e00(longlong param_1);
void __thiscall FID_conflict:~vector<>(void *this);
void __thiscall FID_conflict:~vector<>(void *this);
void FUN_180004220(longlong *param_1);
void FUN_180004290(undefined8 *param_1);
void FUN_180004550(longlong *param_1);
void FUN_1800045a0(longlong param_1);
void FUN_1800045e0(longlong param_1);
void FUN_1800045f0(longlong *param_1);
longlong * FUN_180004640(longlong *param_1,longlong *param_2);
longlong * FUN_180004690(longlong *param_1,longlong *param_2);
void FUN_1800046c0(longlong *param_1,void *param_2);
longlong FUN_1800046e0(longlong *param_1,longlong param_2);
undefined8 FUN_180004700(undefined8 *param_1);
void FUN_180004710(undefined8 param_1,longlong *param_2,undefined8 param_3,undefined8 param_4);
void FUN_180004780(longlong *param_1);
void FUN_1800047f0(longlong *param_1);
void FUN_180004850(longlong param_1,uint param_2);
void FUN_18000485c(longlong param_1,uint param_2);
basic_streambuf<> * FUN_180004870(basic_streambuf<> *param_1,uint param_2);
longlong * FUN_1800048b0(longlong param_1,uint param_2);
basic_streambuf<> * FUN_1800048f0(basic_streambuf<> *param_1,uint param_2);
basic_ios<> * FUN_180004930(basic_ios<> *param_1,uint param_2);
undefined8 * FUN_1800049d0(undefined8 *param_1,ulonglong param_2);
undefined8 FUN_180004a20(longlong param_1,longlong param_2);
void FUN_180005bb0(longlong param_1,longlong param_2);
double * FUN_180006320(double *param_1,longlong param_2,double *param_3,int param_4);
void FUN_180006650(int *param_1);
void FUN_18012c110(undefined8 *param_1);
void FUN_18012c170(longlong param_1);
int FUN_18012c5a0(longlong param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_18012ca00(longlong param_1,undefined4 *param_2,undefined8 param_3,undefined *param_4);
uint FUN_18012cf50(longlong param_1,undefined8 param_2,longlong *param_3);
void FUN_18012d400(undefined8 *param_1);
uint FUN_18012d460(longlong param_1,undefined8 *param_2,undefined8 param_3);
undefined8 FUN_18012def0(longlong param_1,longlong param_2);
void FUN_18012f050(undefined8 *param_1);
undefined8 FUN_18012f0b0(int *param_1,int param_2,int param_3,undefined8 param_4,float *param_5);
undefined8 FUN_18012f1e0(int *param_1,int param_2,int param_3,undefined8 param_4,char *param_5);
uint FUN_180131fc0(undefined8 *param_1,undefined8 param_2,longlong *param_3);
undefined8 FUN_180132590(longlong param_1,undefined8 param_2,longlong *param_3);
uint FUN_180132a40(longlong param_1,longlong param_2,longlong param_3,longlong *param_4);
uint FUN_1801333c0(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4);
undefined8 FUN_180133f60(longlong param_1);
uint FUN_180134550(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4);
void FUN_180134700(float *param_1,longlong param_2,ulonglong param_3);
void FUN_180134f50(longlong *param_1);
void FUN_180134fc0(longlong *param_1,undefined8 param_2,uint param_3,uint param_4);
void FUN_180135520(float *param_1,longlong param_2);
void FUN_180136110(float *param_1,longlong param_2);
bool FUN_180136970(undefined8 *param_1,longlong *param_2,longlong *param_3,longlong *param_4,longlong *param_5,longlong *param_6,undefined1 param_7,longlong *param_8,undefined8 param_9);
uint FUN_180136df0(undefined8 *param_1,longlong param_2,longlong *param_3);
void FUN_1801374a0(HWND param_1,int param_2,undefined8 param_3,longlong *param_4);
ulonglong FUN_180137570(longlong param_1,undefined8 param_2,longlong param_3);
int FUN_180137a70(longlong param_1,undefined8 param_2,LPCSTR ******param_3,undefined *param_4,int *param_5);
void FUN_180138630(undefined8 *param_1);
void FUN_180138690(undefined8 *param_1);
void FUN_180138700(undefined8 param_1,longlong *param_2,longlong *param_3);
void FUN_180138750(undefined8 *param_1,undefined8 *param_2);
void FUN_180138840(undefined8 param_1,longlong *param_2,longlong *param_3);
void FUN_180138860(longlong param_1,longlong *param_2);
bool FUN_180138890(longlong *param_1);
void FUN_180138960(undefined8 param_1,void *param_2);
undefined8 FUN_1801389d0(undefined8 param_1);
void FUN_1801389e0(longlong param_1,longlong param_2);
void FUN_180138b70(basic_streambuf<> *param_1,longlong param_2,int param_3);
void FUN_180138c10(longlong param_1);
undefined8 * FUN_180138c30(undefined8 param_1,undefined8 *param_2,undefined8 param_3);
void FUN_180138c40(ulonglong *param_1,ulonglong param_2);
void __thiscall std::basic_filebuf<>::_Reset_back(basic_filebuf<> *this);
void FUN_180138d60(longlong param_1);
void FUN_180138d80(void);
void FUN_180138da0(void);
void FUN_180138dc0(void);
void FUN_180138de0(void);
ulonglong FUN_180138e00(undefined8 param_1,ulonglong param_2);
void FUN_180138e60(undefined8 param_1,ulonglong param_2);
longlong * FUN_180138ee0(longlong *param_1,void *param_2,ulonglong param_3);
longlong * FUN_180138f70(longlong *param_1,void *param_2,size_t param_3);
undefined8 * FUN_1801390c0(undefined8 *param_1);
int * FUN_1801390d0(int *param_1,undefined8 param_2,longlong param_3,int *param_4);
longlong FUN_1801392a0(int param_1,int param_2,int param_3,int param_4);
int FUN_180139320(undefined8 *param_1,longlong param_2,longlong param_3);
basic_streambuf<> * FUN_180139770(basic_streambuf<> *param_1);
void FUN_1801397f0(longlong param_1,undefined8 param_2);
void FUN_180139b40(undefined8 param_1,void *param_2,ulonglong param_3);
void FUN_180139b80(undefined8 param_1,void *param_2,longlong param_3);
void deallocate(undefined8 param_1,void *param_2,longlong param_3);
void deallocate(undefined8 param_1,void *param_2,longlong param_3);
void FUN_180139c60(undefined8 param_1,void *param_2,longlong param_3);
void FUN_180139cb0(longlong param_1,undefined8 *param_2,undefined1 param_3,undefined8 param_4,undefined4 param_5);
longlong * FUN_180139f20(longlong *param_1,void *param_2);
ulonglong FUN_18013abc0(undefined8 *param_1,undefined4 param_2,undefined8 *param_3,undefined1 param_4);
void FUN_18013ad30(basic_streambuf<> *param_1,locale *param_2);
undefined8 * FUN_18013ad80(undefined8 *param_1,ulonglong param_2,void *param_3,ulonglong param_4);
longlong * FUN_18013ae90(longlong *param_1,int param_2);
void FUN_18013b0c0(LPCSTR param_1);
int FUN_18013b0f0(basic_streambuf<> *param_1,int param_2);
int FUN_18013b290(basic_streambuf<> *param_1,int param_2);
uint FUN_18013b440(longlong param_1,uint param_2);
int FUN_18013b530(longlong param_1,int param_2);
longlong *FUN_18013b590(longlong *param_1,ulonglong param_2,ulonglong param_3,void *param_4,ulonglong param_5);
void FUN_18013b730(undefined8 *param_1,ulonglong param_2);
void aescriptsSaveLicenseToFile(char *param_1,char *param_2,char *param_3,char *param_4);
fpos_t * FUN_18013b8c0(basic_filebuf<> *param_1,fpos_t *param_2,longlong param_3,int param_4);
ulonglong *FUN_18013b990(longlong param_1,ulonglong *param_2,longlong param_3,int param_4,byte param_5);
longlong * FUN_18013bae0(longlong *param_1,longlong *param_2,longlong *param_3);
ulonglong * FUN_18013bbc0(longlong param_1,ulonglong *param_2,longlong *param_3,uint param_4);
basic_streambuf<> * FUN_18013bcb0(basic_streambuf<> *param_1,char *param_2,size_t param_3);
void FUN_18013bd10(longlong param_1);
longlong * FUN_18013efe0(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4);
longlong * FUN_18013f240(longlong *param_1,longlong *param_2,byte *param_3);
void FUN_18013f5e0(undefined8 *param_1,char param_2,longlong *param_3);
void FUN_18013f830(longlong param_1);
longlong * FUN_18013f990(undefined8 *param_1,longlong *param_2,ulonglong param_3,ulonglong param_4);
undefined8 FUN_18013f9f0(longlong *param_1);
longlong * FUN_18013fa40(longlong *param_1,uint param_2);
uint FUN_18013fb20(longlong param_1);
ulonglong FUN_18013fe00(longlong *param_1);
ulonglong FUN_18013fe70(longlong param_1);
void FUN_18013fee0(void *param_1,void *param_2,__int64 param_3,char *param_4,char param_5);
undefined * FUN_18013fef0(longlong param_1);
longlong FUN_18013ff10(basic_streambuf<> *param_1,char *param_2,size_t param_3);
longlong FUN_180140020(basic_streambuf<> *param_1,char *param_2,size_t param_3);
ulonglong EffectMain(int param_1,undefined8 *param_2,undefined *param_3,LPCSTR ******param_4,undefined *param_5,longlong *param_6);
void PluginDataEntryFunction(undefined8 param_1,undefined *param_2);
undefined * FUN_1801405f0(void);
int FUN_180140600(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
int __cdecl FID_conflict:sprintf_s(wchar_t *_Dst,size_t _SizeInWords,wchar_t *_Format,...);
void FUN_1801406c0(longlong *param_1,void *param_2,void *param_3);
longlong FUN_180140880(undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 *param_4);
void FUN_180140900(undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,undefined8 *param_5);
longlong FUN_180140960(undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,undefined8 *param_5);
void FUN_1801409b0(undefined8 param_1,void *param_2);
longlong * FUN_1801409c0(float *param_1,longlong *param_2,undefined8 *param_3,longlong *param_4);
longlong * FUN_180140c20(float *param_1,longlong *param_2,undefined8 *param_3,longlong *param_4);
void FUN_180140e80(longlong param_1,longlong *param_2,undefined8 *param_3);
void FUN_180140ef0(longlong *param_1,ulonglong param_2);
void FUN_1801410d0(undefined8 param_1,longlong param_2,undefined8 *param_3);
longlong * FUN_180141190(float *param_1,longlong *param_2,undefined8 *param_3);
longlong * FUN_180141380(float *param_1,longlong *param_2,undefined8 *param_3);
void FUN_180141570(longlong *param_1,undefined8 *param_2,undefined8 *param_3);
longlong * FUN_180141680(longlong param_1,longlong *param_2,longlong *param_3);
longlong * FUN_180141770(longlong param_1,longlong *param_2,longlong *param_3);
void FUN_180141860(longlong param_1);
void FUN_1801418d0(longlong param_1);
void FUN_180141950(longlong *param_1);
void FUN_180141a20(longlong *param_1);
void thunk_FUN_180141860(longlong param_1);
void thunk_FUN_1801418d0(longlong param_1);
void FUN_180141a60(longlong *param_1);
void FUN_180141ac0(longlong param_1);
void FUN_180141b40(longlong *param_1);
void FUN_180141b70(longlong *param_1);
void FUN_180141bd8(longlong param_1,uint param_2);
longlong * FUN_180141bf0(longlong param_1,uint param_2);
undefined4 FUN_180141c30(longlong param_1);
undefined8 *FUN_180141e70(undefined8 *param_1,undefined4 param_2,float *param_3,char *****param_4,undefined8 *param_5);
int * FUN_180142550(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5,int param_6);
void FUN_1801427a0(int *param_1);
void FUN_180142800(undefined4 *param_1,longlong param_2,int param_3,undefined4 param_4);
undefined4 * FUN_1801428e0(undefined4 *param_1,undefined4 param_2);
undefined4 * FUN_1801428f0(undefined4 *param_1,undefined8 *param_2);
void FUN_180142920(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3);
void FUN_180142b30(undefined4 *param_1,undefined4 param_2,float *param_3,char param_4,double *param_5,char param_6);
void FUN_180142ce0(undefined4 param_1,uint param_2,longlong param_3);
void FUN_1801433c0(uint param_1,longlong param_2);
undefined4 * FUN_180143b30(undefined4 *param_1,undefined4 param_2);
void FUN_180143b40(int param_1,longlong param_2,int param_3);
undefined4 * FUN_180143f40(undefined4 *param_1,undefined4 param_2);
void FUN_180143f50(undefined8 param_1,longlong *param_2,longlong *param_3);
void FUN_180143fa0(undefined8 param_1,longlong *param_2,longlong *param_3);
void FUN_180143ff0(float *param_1,float *param_2);
void FUN_1801440b0(longlong param_1,longlong *param_2);
void FUN_1801440e0(longlong param_1,longlong *param_2);
void FUN_180144110(undefined8 param_1,void *param_2);
void FUN_180144180(undefined8 param_1,void *param_2);
longlong * FUN_1801441f0(longlong param_1,longlong *param_2);
void FUN_180144210(longlong *param_1,ulonglong param_2,undefined8 *param_3);
void FUN_180144360(longlong param_1);
void FUN_180144390(longlong *param_1);
void FUN_180144440(longlong *param_1);
void deallocate(undefined8 param_1,void *param_2,longlong param_3);
void FUN_180144540(undefined8 param_1,void *param_2,longlong param_3);
void FUN_180144580(undefined8 param_1,void *param_2,longlong param_3);
undefined8 *FUN_1801445f0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
int FUN_1801448f0(longlong *param_1,undefined8 param_2);
void FUN_180144b50(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void FUN_180144bf0(int *param_1);
undefined8 * FUN_180144c20(void);
undefined1 FUN_180144c60(longlong param_1);
void FUN_180144c80(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void FUN_180144cd0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
int FUN_180144d30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
longlong * FUN_180144d90(longlong *param_1,longlong param_2);
void FUN_180144dd0(longlong *param_1);
void FUN_180144df0(longlong *param_1);
void FUN_180145d30(void);
longlong FUN_180145d50(longlong param_1);
undefined1 FUN_180145de0(void);
undefined1 FUN_180145f50(void);
undefined1 FUN_1801460c0(void);
undefined1 FUN_1801462c0(void);
undefined1 FUN_180146e90(void);
undefined1 FUN_180146f20(void);
undefined1 FUN_1801471a0(void);
undefined1 FUN_1801473e0(void);
undefined1 FUN_180147850(void);
undefined1 FUN_180147c60(void);
undefined1 FUN_180148090(void);
undefined1 FUN_180148310(void);
undefined1 FUN_1801484e0(void);
undefined1 FUN_180148c40(void);
undefined1 FUN_180149110(void);
undefined1 FUN_180149200(void);
undefined1 FUN_180149290(void);
undefined1 FUN_1801493e0(void);
undefined1 FUN_180149470(void);
undefined1 FUN_180149600(void);
undefined1 FUN_180149770(void);
undefined1 FUN_180149f10(void);
undefined1 FUN_18014a3c0(void);
undefined1 FUN_18014a5c0(void);
undefined1 FUN_18014a790(void);
undefined1 FUN_18014a920(void);
undefined1 FUN_18014aeb0(void);
undefined1 FUN_18014b060(void);
undefined1 FUN_18014ca60(void);
undefined1 FUN_18014cca0(void);
undefined1 FUN_18014cec0(void);
undefined1 FUN_18014d2f0(void);
undefined1 FUN_18014d550(void);
undefined1 FUN_18014d770(void);
undefined1 FUN_18014d8e0(void);
undefined1 FUN_18014de10(void);
undefined1 FUN_18014e110(void);
undefined1 FUN_18014e2c0(void);
undefined1 FUN_18014e4e0(void);
undefined1 FUN_18014e670(void);
undefined1 FUN_18014e800(void);
undefined1 FUN_18014ec30(void);
undefined1 FUN_18014f1e0(void);
undefined1 FUN_18014f9b0(void);
undefined1 FUN_18014fb60(void);
undefined1 FUN_18014fd10(void);
undefined1 FUN_18014fe80(void);
undefined1 FUN_1801500e0(void);
undefined1 FUN_180150270(void);
undefined1 FUN_180150a40(void);
undefined1 FUN_180150bd0(void);
undefined1 FUN_180150d60(void);
undefined1 FUN_180151130(void);
undefined1 FUN_1801512e0(void);
undefined1 FUN_180151500(void);
undefined1 FUN_180151670(void);
undefined1 FUN_180151b60(void);
undefined1 FUN_180152110(void);
undefined1 FUN_1801526d0(void);
undefined1 FUN_180152930(void);
undefined1 FUN_180153490(void);
undefined1 FUN_180153bd0(void);
ulonglong FUN_180153d60(char *param_1,char *param_2,char *param_3);
void FUN_18015c8a0(void);
undefined8 FUN_18015fa10(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4);
basic_istream<> * FUN_18015fb90(basic_istream<> *param_1,longlong *param_2);
basic_ostream<> * FUN_18015fda0(basic_ostream<> *param_1,char param_2);
ulonglong FUN_18015ff60(undefined8 *param_1,void *param_2);
longlong * FUN_18015ffb0(longlong *param_1,longlong *param_2,undefined8 *param_3);
longlong * FUN_180160010(longlong *param_1,longlong *param_2,void *param_3);
longlong * FUN_180160070(longlong *param_1,undefined8 *param_2,undefined8 *param_3);
longlong * FUN_180160120(longlong *param_1,undefined8 *param_2,undefined1 param_3);
longlong * FUN_1801601f0(longlong *param_1,undefined1 param_2,undefined8 *param_3);
undefined8 * FUN_1801602c0(undefined8 *param_1,void *param_2,undefined8 *param_3);
longlong * FUN_180160320(longlong *param_1,void *param_2,undefined8 *param_3);
void FUN_1801603d0(undefined8 *param_1,undefined8 param_2,undefined8 *param_3);
longlong FUN_180160420(longlong *param_1,void *param_2,undefined8 *param_3);
longlong FUN_180160650(longlong *param_1,undefined8 *param_2,undefined8 *param_3);
longlong FUN_180160880(longlong *param_1,undefined8 *param_2,undefined8 *param_3);
longlong FUN_180160ab0(longlong *param_1,undefined8 *param_2,undefined8 *param_3);
longlong FUN_180160d20(longlong *param_1,longlong *param_2,undefined8 *param_3);
undefined8 *FUN_180160ec0(longlong *param_1,undefined8 *param_2,char param_3,undefined8 *param_4,undefined8 param_5,longlong *param_6);
undefined8 *FUN_180161140(longlong *param_1,undefined8 *param_2,longlong *param_3,byte *param_4,longlong *param_5);
undefined8 *FUN_180161330(longlong *param_1,undefined8 *param_2,char param_3,byte *param_4,longlong *param_5);
undefined8 ******* FUN_1801614c0(undefined8 *******param_1,undefined8 *******param_2);
void FUN_180161800(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3);
undefined8 * FUN_1801618c0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3);
void FUN_180161bd0(longlong param_1,longlong param_2,ulonglong param_3,longlong *param_4);
void FUN_180161e70(undefined8 *******param_1,undefined8 *******param_2,longlong param_3,undefined1 param_4);
ulonglong FUN_180162160(longlong param_1,ulonglong param_2,ulonglong param_3,char *param_4,ulonglong param_5);
ulonglong FUN_180162230(char *param_1,ulonglong param_2,ulonglong param_3,char *param_4,ulonglong param_5);
undefined8 * FUN_1801622d0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3);
undefined8 * FUN_180162390(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3);
void FUN_180162440(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3);
void FUN_180162620(undefined8 param_1,undefined8 *param_2,undefined8 *param_3);
void FUN_1801626d0(undefined8 param_1,longlong *param_2);
_Facet_base * FUN_180162730(locale *param_1);
basic_istream<> *FUN_180162820(basic_istream<> *param_1,char *param_2,uint param_3,int param_4,int param_5);
basic_istream<> * FUN_180162950(basic_istream<> *param_1,int param_2);
basic_ostream<> *FUN_180162a30(basic_ostream<> *param_1,char *param_2,uint param_3,int param_4,int param_5);
undefined8 * FUN_180162b60(undefined8 *param_1,undefined8 *param_2);
longlong * FUN_180162bb0(longlong *param_1,longlong *param_2);
longlong * FUN_180162c90(longlong *param_1,longlong *param_2);
undefined1 * FUN_180162db0(undefined1 *param_1);
void FUN_180162f60(longlong param_1);
void FUN_180163020(longlong *param_1);
void FUN_180163060(longlong param_1);
void FUN_1801630f0(longlong *param_1);
void FUN_180163180(longlong *param_1);
void FUN_180163240(longlong param_1);
void FUN_180163460(char *param_1);
void FUN_1801636d0(longlong *param_1);
void FUN_180163740(longlong *param_1);
void FUN_1801637b0(longlong *param_1);
void FUN_1801638f0(char *param_1);
void FUN_180163900(char *param_1);
void _Mtx_destroy_in_situ(void);
void FUN_180163920(longlong *param_1);
longlong * FUN_180163b20(longlong *param_1,byte *param_2);
longlong * FUN_180163bc0(longlong *param_1);
longlong * FUN_180163c30(longlong *param_1);
longlong * FUN_180163cc0(longlong *param_1,longlong *param_2,int *param_3);
void FUN_180163d30(longlong *param_1,undefined8 *param_2);
longlong * FUN_180163d50(longlong *param_1,undefined1 param_2);
void FUN_180163db0(longlong *param_1,void *param_2);
longlong * FUN_180163dd0(longlong *param_1,uint param_2);
undefined8 FUN_180163e70(void);
longlong * FUN_180163ec0(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
ulonglong FUN_180164210(longlong *param_1);
int FUN_1801643d0(longlong *param_1,uint param_2,int param_3,longlong *param_4,longlong *param_5);
void FUN_1801645a0(void);
void FUN_1801645e0(undefined8 *param_1);
undefined8 FUN_180164620(undefined8 *param_1);
void FUN_180164630(undefined8 param_1,longlong *param_2,longlong *param_3);
void FUN_180164670(undefined8 param_1,longlong *param_2,longlong *param_3);
void FUN_1801646b0(undefined8 param_1,longlong *param_2,longlong *param_3);
void FUN_1801646f0(undefined8 param_1,void *param_2);
void FUN_180164720(undefined8 param_1,longlong *param_2);
longlong * FUN_180164780(longlong *param_1,longlong *param_2);
void FUN_180164ae0(undefined8 param_1,void *param_2);
void FUN_180164af0(longlong param_1);
void FUN_180164b80(longlong *param_1,longlong param_2);
void FUN_180164be0(longlong *param_1,longlong *param_2);
void FUN_180164c40(longlong *param_1);
void FUN_180164d00(longlong *param_1,int *param_2,ulonglong param_3);
int __cdecl aescriptsGetLicLibVersionString(char *param_1);
int __cdecl aescriptsSaveLicenseToFileEx(char *param_1,char *param_2,char *param_3,char *param_4,aescriptsLicenseData *param_5);
void FUN_180165eb0(undefined8 param_1,ulonglong param_2);
void FUN_180165f30(undefined8 param_1,ulonglong param_2);
void FUN_180165fb0(longlong *param_1,undefined8 *param_2,ulonglong param_3,ulonglong param_4);
longlong * FUN_180165ff0(longlong *param_1,longlong param_2,uint param_3);
undefined4 FUN_180166200(longlong param_1);
ulonglong FUN_180166520(longlong *param_1,int *param_2,int *param_3);
longlong * FUN_180166d60(longlong *param_1,int param_2);
uint FUN_1801674f0(undefined8 *param_1,undefined8 *param_2);
undefined8 FUN_180167560(int param_1,sockaddr *param_2,int param_3,int param_4);
longlong *FUN_180167680(longlong *param_1,char *******param_2,undefined8 param_3,undefined8 param_4);
int FUN_180167c00(int param_1,uint param_2,int param_3);
void deallocate(undefined8 param_1,void *param_2,longlong param_3);
void FUN_180167d00(undefined8 param_1,void *param_2,longlong param_3);
longlong * FUN_180167d50(longlong *param_1,longlong *param_2);
longlong * FUN_180168550(longlong *param_1,longlong *param_2,byte *param_3);
void FUN_1801686c0(char *param_1);
undefined8 FUN_180168d50(longlong param_1);
DWORD FUN_18016bdd0(longlong *param_1,longlong *param_2);
longlong * FUN_18016d270(longlong *param_1,longlong *param_2,byte *param_3);
undefined8 *FUN_18016d3a0(longlong *param_1,undefined8 *param_2,longlong *param_3,longlong *param_4);
longlong * FUN_18016d540(longlong param_1,longlong *param_2,longlong param_3);
longlong * FUN_18016d690(longlong param_1,longlong *param_2,longlong param_3);
ulonglong FUN_18016d7d0(FILE *param_1);
void FUN_18016d860(undefined8 *param_1,char *param_2,ulonglong param_3);
int FUN_18016d8a0(longlong *param_1,longlong *param_2);
longlong * FUN_18016da40(longlong *param_1,longlong *param_2);
undefined8 FUN_18016dd90(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4,undefined8 *param_5);
undefined8 FUN_18016e1a0(undefined8 *param_1,longlong *param_2);
longlong * FUN_18016e760(longlong *param_1,longlong *param_2);
void FUN_18016e890(longlong *param_1,undefined1 *param_2);
longlong *FUN_18016ea90(longlong *param_1,longlong *param_2,longlong *param_3,longlong param_4,int param_5,longlong *param_6);
ulonglong FUN_18016faa0(void *param_1,void *param_2,__int64 param_3,char param_4,char *param_5);
ulonglong FUN_18016fb40(void *param_1,void *param_2,__uint64 param_3,char param_4,char *param_5);
undefined4 FUN_180170150(char *param_1,char *param_2,char *param_3,char *param_4,longlong *param_5);
undefined8 FUN_180171000(undefined8 *param_1);
undefined8 FUN_180171400(longlong *param_1);
undefined8 FUN_180171df0(longlong *param_1,longlong *param_2,uint param_3);
longlong FUN_180172460(__int64 param_1);
undefined8 FUN_180172730(longlong *param_1,char param_2,char *******param_3,undefined8 param_4,char param_5);
undefined8 **** FUN_180172f00(undefined8 ****param_1,longlong *param_2);
undefined4 FUN_180173350(longlong *param_1);
void FUN_1801735a0(longlong param_1,uint param_2,longlong param_3);
longlong * FUN_180173750(longlong *param_1,longlong *param_2);
void FUN_180173b30(char *param_1,longlong *param_2);
longlong * FUN_180174cb0(longlong *param_1,int param_2);
longlong * FUN_180174e50(longlong *param_1,uint param_2,undefined8 param_3,undefined8 param_4);
undefined4 FUN_180174ed0(char *param_1,longlong *param_2);
longlong * FUN_180175030(longlong *param_1,uint param_2);
longlong * FUN_1801751a0(longlong *param_1,uint param_2,undefined8 *param_3,undefined8 param_4);
longlong * FUN_1801753b0(longlong *param_1,uint param_2,undefined8 *param_3,undefined8 param_4);
longlong *FUN_1801755c0(longlong *param_1,uint param_2,undefined4 param_3,undefined8 param_4,longlong param_5,longlong param_6,char param_7,uint param_8);
longlong *FUN_180175aa0(longlong *param_1,uint param_2,uint param_3,undefined8 param_4,char param_5);
undefined8 FUN_1801790e0(void);
undefined *** FUN_180179af0(undefined ***param_1,longlong *param_2,char param_3);
longlong * FUN_180179ec0(longlong *param_1,__uint64 param_2);
undefined8 FUN_18017a060(char *param_1);
ulonglong * FUN_18017b400(longlong *param_1,uint param_2);
int FUN_18017b780(longlong *param_1,longlong param_2,int param_3);
longlong * FUN_18017b8d0(longlong *param_1,uint param_2,undefined8 param_3,undefined8 param_4);
longlong * FUN_18017b950(longlong *param_1,longlong *param_2,char param_3);
basic_streambuf<> * FUN_18017c0b0(basic_streambuf<> *param_1,char *param_2,int param_3,int param_4);
longlong * FUN_18017c180(longlong *param_1,longlong *param_2,uint param_3);
longlong * FUN_18017c3b0(longlong *param_1,longlong *param_2,int param_3);
undefined4 FUN_18017c5e0(longlong *param_1,longlong param_2);
void FUN_18017cfc0(longlong param_1,int *param_2);
undefined8 FUN_18017d7b0(longlong param_1,longlong *param_2);
void FUN_18017ed30(longlong *param_1,undefined8 *param_2);
void FUN_18017edc0(longlong *param_1,undefined8 *param_2);
int FUN_18017ee40(int param_1,longlong *param_2);
undefined8 * FUN_18017ef30(undefined8 *param_1,longlong *param_2);
int FUN_18017f010(void *param_1,longlong *param_2,void *param_3,char *param_4,void *param_5,char param_6,longlong *param_7,undefined8 param_8,char param_9);
undefined8 FUN_1801809d0(longlong param_1,longlong *param_2);
int FUN_180180d10(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4,longlong *param_5,longlong *param_6,__uint64 param_7,byte *param_8,undefined8 *******param_9);
int FUN_180182270(int param_1,longlong *param_2);
void FUN_180182460(longlong *param_1,DWORD param_2,char param_3,char param_4);
void FUN_1801832b0(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4,longlong *param_5);
undefined8 FUN_180183a60(char *param_1);
longlong * FUN_180183a80(longlong *param_1,undefined8 ****param_2,longlong *param_3,char param_4);
void ** FUN_180183de0(void **param_1,undefined8 *param_2,longlong *param_3,char param_4);
longlong * FUN_180184240(longlong *param_1,undefined8 *param_2);
longlong *FUN_1801842e0(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4,char param_5,char param_6);
longlong * FUN_1801846c0(longlong *param_1,longlong *param_2,longlong *param_3);
longlong * FUN_180184880(longlong *param_1,longlong *param_2,longlong *param_3);
void FUN_180184a40(undefined8 *param_1,char param_2,longlong *param_3,char param_4);
longlong * FUN_180184f00(longlong *param_1,byte *param_2,byte *param_3);
longlong * FUN_180185100(longlong *param_1,undefined8 *param_2);
longlong * FUN_1801851a0(longlong *param_1,longlong *param_2);
undefined8 FUN_180185260(longlong *param_1,longlong *param_2,int *param_3);
undefined8 FUN_1801855f0(void *param_1,void *param_2,__uint64 param_3,longlong param_4,char param_5);
ulonglong FUN_180187ab0(void *param_1,void *param_2,char *param_3,longlong *param_4,char *param_5,char param_6,char param_7);
undefined8 aescriptsAddBlockedSerial(__int64 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
undefined4 aescriptsCheckOveruse(longlong param_1);
undefined8 aescriptsConfigure(int param_1,int param_2);
void aescriptsDropLicenseFromLicenseServer(void *param_1,__int64 param_2);
undefined8 aescriptsGetLicLibVersion(void);
ulonglong aescriptsGetLicenseDataFromFile(byte *param_1,__int64 param_2,char *param_3);
undefined4 aescriptsGetLicenseServerConfig(char *param_1,char *param_2,char *param_3,char *param_4);
bool aescriptsGetMachineId(undefined8 *param_1);
ulonglong aescriptsGetRawLicenseDataFromFile(byte *param_1,void *param_2);
undefined8 aescriptsInitLicenseData(void *param_1);
void aescriptsLoadLicenseFromFile(undefined8 param_1,undefined8 param_2,__int64 param_3);
void aescriptsRequestLicenseFromLicenseServer(void *param_1,void *param_2,__int64 param_3,char *param_4);
void aescriptsSaveLicenseToFile(char *param_1,char *param_2,char *param_3,char *param_4);
ulonglong aescriptsValidateLicense(void *param_1,void *param_2,__int64 param_3,char *param_4,char param_5);
bool __cdecl std::uncaught_exception(void);
void __cdecl std::_Xlength_error(char *param_1);
void __cdecl std::_Xout_of_range(char *param_1);
void __thiscall std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(_Fac_tidy_reg_t *this);
void __cdecl std::_Facet_Register(_Facet_base *param_1);
_Locimp * __cdecl std::locale::_Getgloballocale(void);
__int64 __thiscall std::basic_streambuf<>::xsgetn(basic_streambuf<> *this,char *param_1,__int64 param_2);
__int64 __thiscall std::basic_streambuf<>::xsputn(basic_streambuf<> *this,char *param_1,__int64 param_2);
_iobuf * __cdecl std::_Fiopen(char *param_1,int param_2,int param_3);
void _Mtx_init_in_situ(void);
void _Mtx_destroy_in_situ(void);
void _Mtx_lock(void);
void _Mtx_unlock(void);
void __cdecl std::_Throw_C_error(int param_1);
void __thiscall std::basic_streambuf<>::_Lock(basic_streambuf<> *this);
void __thiscall std::basic_streambuf<>::_Unlock(basic_streambuf<> *this);
void __thiscall std::basic_streambuf<>::imbue(basic_streambuf<> *this,locale *param_1);
basic_streambuf<> * __thiscall std::basic_streambuf<>::setbuf(basic_streambuf<> *this,char *param_1,__int64 param_2);
__int64 __thiscall std::basic_streambuf<>::showmanyc(basic_streambuf<> *this);
int __thiscall std::basic_streambuf<>::sync(basic_streambuf<> *this);
int __thiscall std::basic_streambuf<>::uflow(basic_streambuf<> *this);
void __cdecl std::setw(__int64 param_1);
void _Thrd_start(void);
void _Thrd_detach(void);
void _Mtx_init(void);
void _Mtx_destroy(void);
void _Cnd_init(void);
void _Cnd_destroy(void);
void _Cnd_wait(void);
void _Cnd_signal(void);
void _Cnd_do_broadcast_at_thread_exit(void);
void __cdecl std::_Throw_Cpp_error(int param_1);
void FUN_18018c2ec(size_t param_1);
void __cdecl free(void *_Memory);
void thunk_FUN_18018c2ec(size_t param_1);
ulonglong __scrt_acquire_startup_lock(void);
undefined8 __scrt_dllmain_after_initialize_c(void);
bool FUN_18018c3a8(void);
undefined1 FUN_18018c3c0(void);
undefined1 FUN_18018c3e8(void);
void __scrt_dllmain_exception_filter(undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,undefined4 param_5,undefined8 param_6);
void __scrt_dllmain_uninitialize_c(void);
void FUN_18018c490(void);
longlong __scrt_initialize_crt(int param_1);
undefined8 FUN_18018c4f0(uint param_1);
ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1);
void __scrt_release_startup_lock(char param_1);
undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2);
_onexit_t __cdecl _onexit(_onexit_t _Func);
int __cdecl atexit(_func_5014 *param_1);
void __raise_securityfailure(_EXCEPTION_POINTERS *param_1);
void __cdecl __report_gsfailure(uintptr_t _StackCookie);
void __report_rangecheckfailure(void);
void __report_securityfailure(undefined4 param_1);
void capture_current_context(PCONTEXT param_1);
void capture_previous_context(PCONTEXT param_1);
undefined8 FUN_18018c9b8(void);
void FUN_18018cb18(void);
void _Init_thread_footer(int *param_1);
void _Init_thread_header(int *param_1);
void _Init_thread_notify(void);
void _Init_thread_wait(DWORD param_1);
void tls_callback_1(undefined8 param_1,int param_2);
undefined8 __tlregdtor(undefined8 param_1);
undefined8 __GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4);
ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2);
void FID_conflict:__GSHandlerCheck_EH(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4);
void _alloca_probe(void);
void __cdecl __security_check_cookie(uintptr_t _StackCookie);
undefined8 * FUN_18018cfb4(undefined8 *param_1,ulonglong param_2);
void tls_callback_0(undefined8 param_1,int param_2);
bool FUN_18018d024(int param_1);
ulonglong FUN_18018d030(undefined8 param_1,int param_2,longlong param_3);
undefined8 FUN_18018d080(undefined8 param_1,undefined8 param_2);
bool FUN_18018d19c(undefined8 param_1);
int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3);
void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3);
void __cdecl`eh_vector_constructor_iterator'(void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4,_func_void_void_ptr *param_5);
void __cdecl`eh_vector_destructor_iterator'(void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4);
void __cdecl __ArrayUnwind(void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4);
void __cdecl free(void *_Memory);
undefined8 __isa_available_init(void);
void _guard_check_icall(void);
undefined8 * FUN_18018d668(undefined8 *param_1,longlong param_2);
undefined8 * FUN_18018d6a8(undefined8 *param_1);
undefined8 * FUN_18018d6c8(undefined8 *param_1,longlong param_2);
undefined8 * FUN_18018d708(undefined8 *param_1);
void FUN_18018d728(void);
void FUN_18018d748(void);
void __cdecl free(void *_Memory);
bool __scrt_is_ucrt_dll_in_use(void);
void FUN_18018d77c(void);
void __scrt_fastfail(undefined4 param_1);
void __cdecl __security_init_cookie(void);
undefined8 DllMain(HMODULE param_1,int param_2);
void FUN_18018d9a0(void);
void FUN_18018d9b0(void);
undefined * FUN_18018d9bc(void);
void FUN_18018d9c4(void);
undefined ** FUN_18018d9e0(void);
void FUN_18018d9e8(void);
void FUN_18018da24(void);
void Unwind@18018da60(void);
void __std_exception_copy(void);
void __std_exception_destroy(void);
void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo);
void __CxxFrameHandler3(void);
void * __cdecl memchr(void *_Buf,int _Val,size_t _MaxCount);
int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size);
void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size);
void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size);
void * __cdecl memset(void *_Dst,int _Val,size_t _Size);
void __std_type_info_destroy_list(void);
double __cdecl ceil(double _X);
double __cdecl cos(double _X);
float __cdecl cosf(float _X);
double __cdecl floor(double _X);
double __cdecl sin(double _X);
float __cdecl sinf(float _X);
void __cdecl free(void *_Memory);
void * __cdecl malloc(size_t _Size);
void terminate(void);
int __cdecl _callnewh(size_t _Size);
void _seh_filter_dll(void);
void _configure_narrow_argv(void);
void _initialize_narrow_environment(void);
void _initialize_onexit_table(void);
void _register_onexit_function(void);
void _execute_onexit_table(void);
void _crt_atexit(void);
void __cdecl _cexit(void);
void _initterm(void);
void _initterm_e(void);
int __stdcall __WSAFDIsSet(SOCKET param_1,fd_set *param_2);
void inet_ntop(void);
void GetAdaptersInfo(void);
BOOL __stdcall IsProcessorFeaturePresent(DWORD ProcessorFeature);
undefined1 FUN_18018db38(void);
undefined8 FUN_18018db3c(void);
void _guard_dispatch_icall(void);
undefined * Catch_All@18018db60(undefined8 param_1,longlong param_2);
void Unwind@18018dba0(undefined8 param_1,longlong param_2);
void Unwind@18018dbb0(undefined8 param_1,longlong param_2);
void Unwind@18018dbc0(undefined8 param_1,longlong param_2);
void Catch_All@18018dbf0(undefined8 param_1,longlong param_2);
void Catch_All@18018dc20(undefined8 param_1,longlong param_2);
void Catch_All@18018dc50(undefined8 param_1,longlong param_2);
void Catch_All@18018dca0(undefined8 param_1,longlong param_2);
void Catch_All@18018dcca(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018dd20(undefined8 param_1,longlong param_2);
void Unwind@18018dd60(undefined8 param_1,longlong param_2);
void Unwind@18018dd70(undefined8 param_1,longlong param_2);
void Unwind@18018dd80(undefined8 param_1,longlong param_2);
void Unwind@18018dd90(undefined8 param_1,longlong param_2);
void Unwind@18018ddb0(undefined8 param_1,longlong param_2);
void Unwind@18018ddd0(undefined8 param_1,longlong param_2);
void Unwind@18018ddf0(undefined8 param_1,longlong param_2);
void Unwind@18018de10(undefined8 param_1,longlong param_2);
void Unwind@18018de30(undefined8 param_1,longlong param_2);
void Unwind@18018de50(undefined8 param_1,longlong param_2);
void Unwind@18018de60(undefined8 param_1,longlong param_2);
void Unwind@18018de70(undefined8 param_1,longlong param_2);
void Unwind@18018de80(undefined8 param_1,longlong param_2);
void Unwind@18018de90(undefined8 param_1,longlong param_2);
void Unwind@18018dea0(undefined8 param_1,longlong param_2);
void Unwind@18018deb0(undefined8 param_1,longlong param_2);
void Unwind@18018dec0(undefined8 param_1,longlong param_2);
void Unwind@18018ded0(undefined8 param_1,longlong param_2);
void Unwind@18018dee0(undefined8 param_1,longlong param_2);
void Unwind@18018def0(undefined8 param_1,longlong param_2);
void Unwind@18018df00(undefined8 param_1,longlong param_2);
void Unwind@18018df30(undefined8 param_1,longlong param_2);
void Unwind@18018df50(undefined8 param_1,longlong param_2);
void Unwind@18018df80(undefined8 param_1,longlong param_2);
void Unwind@18018dfb0(undefined8 param_1,longlong param_2);
void Unwind@18018dfd0(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
void Unwind@18018dff0(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
void Unwind@18018e010(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
void Unwind@18018e030(undefined8 param_1,longlong param_2);
void Unwind@18018e040(undefined8 param_1,longlong param_2);
void Unwind@18018e050(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
void Unwind@18018e060(undefined8 param_1,longlong param_2);
void Unwind@18018e070(undefined8 param_1,longlong param_2);
void Unwind@18018e080(undefined8 param_1,longlong param_2);
void Unwind@18018e090(undefined8 param_1,longlong param_2);
void Unwind@18018e0a0(undefined8 param_1,longlong param_2);
void Unwind@18018e0b0(undefined8 param_1,longlong param_2);
void Unwind@18018e0c0(undefined8 param_1,longlong param_2);
void Unwind@18018e0d0(undefined8 param_1,longlong param_2);
void Unwind@18018e0e0(undefined8 param_1,longlong param_2);
void Unwind@18018e0f0(undefined8 param_1,longlong param_2);
void Unwind@18018e100(undefined8 param_1,longlong param_2);
void Unwind@18018e110(undefined8 param_1,longlong param_2);
void Unwind@18018e120(undefined8 param_1,longlong param_2);
void Unwind@18018e130(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
void Unwind@18018e140(undefined8 param_1,longlong param_2);
void Unwind@18018e150(undefined8 param_1,longlong param_2);
void Unwind@18018e160(undefined8 param_1,longlong param_2);
void Unwind@18018e170(undefined8 param_1,longlong param_2);
void Unwind@18018e180(undefined8 param_1,longlong param_2);
void Unwind@18018e190(undefined8 param_1,longlong param_2);
void Unwind@18018e1a0(undefined8 param_1,longlong param_2);
void Unwind@18018e1b0(undefined8 param_1,longlong param_2);
void Unwind@18018e1c0(undefined8 param_1,longlong param_2);
void Unwind@18018e1d0(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
void Unwind@18018e1e0(undefined8 param_1,longlong param_2);
void Unwind@18018e1f0(undefined8 param_1,longlong param_2);
void Unwind@18018e200(undefined8 param_1,longlong param_2);
void Unwind@18018e210(undefined8 param_1,longlong param_2);
void Unwind@18018e220(undefined8 param_1,longlong param_2);
void Unwind@18018e230(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018e260(void);
undefined * Catch_All@18018e27b(void);
void Unwind@18018e2a0(undefined8 param_1,longlong param_2);
void Unwind@18018e2b0(undefined8 param_1,longlong param_2);
void Unwind@18018e2c0(undefined8 param_1,longlong param_2);
void Unwind@18018e2d0(undefined8 param_1,longlong param_2);
void Unwind@18018e2e0(undefined8 param_1,longlong param_2);
void Unwind@18018e2f0(undefined8 param_1,longlong param_2);
void Unwind@18018e300(undefined8 param_1,longlong param_2);
void Unwind@18018e310(undefined8 param_1,longlong param_2);
void Unwind@18018e320(undefined8 param_1,longlong param_2);
void Unwind@18018e350(undefined8 param_1,longlong param_2);
void Catch_All@18018e380(undefined8 param_1,longlong param_2);
void Catch_All@18018e3b0(undefined8 param_1,longlong param_2);
void Unwind@18018e400(undefined8 param_1,longlong param_2);
void Unwind@18018e410(undefined8 param_1,longlong param_2);
void Unwind@18018e420(undefined8 param_1,longlong param_2);
void Unwind@18018e430(undefined8 param_1,longlong param_2);
void Unwind@18018e440(undefined8 param_1,longlong param_2);
void Unwind@18018e450(undefined8 param_1,longlong param_2);
void Unwind@18018e460(undefined8 param_1,longlong param_2);
void Unwind@18018e470(undefined8 param_1,longlong param_2);
void Unwind@18018e480(undefined8 param_1,longlong param_2);
void Unwind@18018e4b0(undefined8 param_1,longlong param_2);
void Unwind@18018e4c0(undefined8 param_1,longlong param_2);
void Unwind@18018e4f0(undefined8 param_1,longlong param_2);
void Unwind@18018e500(undefined8 param_1,longlong param_2);
void Unwind@18018e530(undefined8 param_1,longlong param_2);
void Unwind@18018e560(undefined8 param_1,longlong param_2);
void Unwind@18018e580(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018e5b0(void);
void Unwind@18018e5d0(undefined8 param_1,longlong param_2);
void Unwind@18018e5e0(undefined8 param_1,longlong param_2);
void Unwind@18018e5f0(undefined8 param_1,longlong param_2);
void Unwind@18018e600(undefined8 param_1,longlong param_2);
void Unwind@18018e610(undefined8 param_1,longlong param_2);
void Unwind@18018e620(undefined8 param_1,longlong param_2);
void Unwind@18018e630(undefined8 param_1,longlong param_2);
void Unwind@18018e640(undefined8 param_1,longlong param_2);
void Unwind@18018e650(undefined8 param_1,longlong param_2);
void Unwind@18018e660(undefined8 param_1,longlong param_2);
void Unwind@18018e670(undefined8 param_1,longlong param_2);
void Unwind@18018e680(undefined8 param_1,longlong param_2);
void Unwind@18018e690(undefined8 param_1,longlong param_2);
void Unwind@18018e6a0(undefined8 param_1,longlong param_2);
void Unwind@18018e6b0(undefined8 param_1,longlong param_2);
void Unwind@18018e6c0(undefined8 param_1,longlong param_2);
void Unwind@18018e6d0(undefined8 param_1,longlong param_2);
void Unwind@18018e6e0(undefined8 param_1,longlong param_2);
void Unwind@18018e6f0(undefined8 param_1,longlong param_2);
void Unwind@18018e700(undefined8 param_1,longlong param_2);
void Unwind@18018e710(undefined8 param_1,longlong param_2);
void Unwind@18018e720(undefined8 param_1,longlong param_2);
void Unwind@18018e730(undefined8 param_1,longlong param_2);
void Unwind@18018e760(undefined8 param_1,longlong param_2);
void Unwind@18018e790(undefined8 param_1,longlong param_2);
void Unwind@18018e7c0(undefined8 param_1,longlong param_2);
void Unwind@18018e7f0(undefined8 param_1,longlong param_2);
void Unwind@18018e800(undefined8 param_1,longlong param_2);
void Unwind@18018e830(undefined8 param_1,longlong param_2);
void Unwind@18018e840(undefined8 param_1,longlong param_2);
void Unwind@18018e850(undefined8 param_1,longlong param_2);
void Unwind@18018e860(undefined8 param_1,longlong param_2);
undefined * Catch@18018e870(undefined8 param_1,longlong param_2);
void Catch_All@18018e8a0(undefined8 param_1,longlong param_2);
void Catch_All@18018e8d0(undefined8 param_1,longlong param_2);
void Catch_All@18018e900(undefined8 param_1,longlong param_2);
void Catch_All@18018e930(undefined8 param_1,longlong param_2);
void Catch_All@18018e95a(undefined8 param_1,longlong param_2);
void Catch_All@18018e9b0(undefined8 param_1,longlong param_2);
void Catch_All@18018e9da(undefined8 param_1,longlong param_2);
void Catch_All@18018ea30(undefined8 param_1,longlong param_2);
void Catch_All@18018ea60(undefined8 param_1,longlong param_2);
void Catch_All@18018eaa0(undefined8 param_1,longlong param_2);
void Unwind@18018eaf0(undefined8 param_1,longlong param_2);
void Unwind@18018eb20(undefined8 param_1,longlong param_2);
void Unwind@18018eb30(undefined8 param_1,longlong param_2);
void Unwind@18018eb40(undefined8 param_1,longlong param_2);
void Unwind@18018eb50(undefined8 param_1,longlong param_2);
void Unwind@18018eb60(undefined8 param_1,longlong param_2);
void Unwind@18018eb80(undefined8 param_1,longlong param_2);
void Unwind@18018eb90(undefined8 param_1,longlong param_2);
void Unwind@18018eba0(undefined8 param_1,longlong param_2);
void Unwind@18018ebb0(undefined8 param_1,longlong param_2);
void Unwind@18018ebc0(undefined8 param_1,longlong param_2);
void Unwind@18018ebd0(undefined8 param_1,longlong param_2);
void Unwind@18018ebe0(undefined8 param_1,longlong param_2);
void Unwind@18018ebf0(undefined8 param_1,longlong param_2);
void Unwind@18018ec00(undefined8 param_1,longlong param_2);
void Unwind@18018ec10(undefined8 param_1,longlong param_2);
void Unwind@18018ec20(undefined8 param_1,longlong param_2);
void Unwind@18018ec30(undefined8 param_1,longlong param_2);
void Catch_All@18018ec40(undefined8 param_1,longlong param_2);
void Catch_All@18018ec70(undefined8 param_1,longlong param_2);
void Catch_All@18018eca0(undefined8 param_1,longlong param_2);
void Unwind@18018ecd0(undefined8 param_1,longlong param_2);
void Unwind@18018ece0(undefined8 param_1,longlong param_2);
void Unwind@18018ecf0(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018ed00(undefined8 param_1,longlong param_2);
void Unwind@18018ed40(undefined8 param_1,longlong param_2);
void Unwind@18018ed50(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018ed60(undefined8 param_1,longlong param_2);
void Unwind@18018eda0(undefined8 param_1,longlong param_2);
void Catch_All@18018edd0(undefined8 param_1,longlong param_2);
void Catch_All@18018ee00(undefined8 param_1,longlong param_2);
void Catch_All@18018ee30(undefined8 param_1,longlong param_2);
void Catch_All@18018ee80(undefined8 param_1,longlong param_2);
void Unwind@18018eed0(undefined8 param_1,longlong param_2);
void Catch_All@18018eee0(undefined8 param_1,longlong param_2);
void Catch_All@18018ef30(undefined8 param_1,longlong param_2);
void Catch_All@18018ef80(undefined8 param_1,longlong param_2);
void Catch_All@18018efb0(undefined8 param_1,longlong param_2);
void Unwind@18018efe0(undefined8 param_1,longlong param_2);
void Unwind@18018eff0(undefined8 param_1,longlong param_2);
void Unwind@18018f000(undefined8 param_1,longlong param_2);
void Unwind@18018f010(undefined8 param_1,longlong param_2);
void Unwind@18018f030(undefined8 param_1,longlong param_2);
void Unwind@18018f060(undefined8 param_1,longlong param_2);
void Unwind@18018f080(undefined8 param_1,longlong param_2);
void Unwind@18018f090(undefined8 param_1,longlong param_2);
void Unwind@18018f0a0(undefined8 param_1,longlong param_2);
void Unwind@18018f0d0(undefined8 param_1,longlong param_2);
void Unwind@18018f0f0(undefined8 param_1,longlong param_2);
void Unwind@18018f100(undefined8 param_1,longlong param_2);
void Unwind@18018f130(undefined8 param_1,longlong param_2);
void Unwind@18018f150(undefined8 param_1,longlong param_2);
void Catch_All@18018f160(undefined8 param_1,longlong param_2);
void Catch_All@18018f190(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018f1c0(void);
void Unwind@18018f1e0(undefined8 param_1,longlong param_2);
void Unwind@18018f1f0(undefined8 param_1,longlong param_2);
void Unwind@18018f200(undefined8 param_1,longlong param_2);
void Unwind@18018f220(undefined8 param_1,longlong param_2);
void Unwind@18018f240(undefined8 param_1,longlong param_2);
void Unwind@18018f260(undefined8 param_1,longlong param_2);
void Unwind@18018f270(void);
void Unwind@18018f280(void);
void Unwind@18018f290(void);
void Unwind@18018f2a0(void);
void Unwind@18018f2b0(void);
void Unwind@18018f2c0(void);
void Unwind@18018f2d0(void);
void Unwind@18018f2e0(undefined8 param_1,longlong param_2);
void Unwind@18018f2f0(undefined8 param_1,longlong param_2);
void Unwind@18018f300(undefined8 param_1,longlong param_2);
void Catch_All@18018f310(undefined8 param_1,longlong param_2);
void Catch_All@18018f340(undefined8 param_1,longlong param_2);
void Unwind@18018f370(undefined8 param_1,longlong param_2);
void Unwind@18018f380(undefined8 param_1,longlong param_2);
void Unwind@18018f390(undefined8 param_1,longlong param_2);
void Unwind@18018f3a0(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018f3b0(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018f3d2(undefined8 param_1,longlong param_2);
void Unwind@18018f400(undefined8 param_1,longlong param_2);
void Unwind@18018f430(undefined8 param_1,longlong param_2);
void Unwind@18018f440(undefined8 param_1,longlong param_2);
void Unwind@18018f470(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018f4a0(void);
void Unwind@18018f4c0(undefined8 param_1,longlong param_2);
void Unwind@18018f4f0(undefined8 param_1,longlong param_2);
void Unwind@18018f500(undefined8 param_1,longlong param_2);
void Unwind@18018f510(undefined8 param_1,longlong param_2);
void Unwind@18018f520(undefined8 param_1,longlong param_2);
void Unwind@18018f530(undefined8 param_1,longlong param_2);
void Unwind@18018f540(undefined8 param_1,longlong param_2);
void Unwind@18018f550(undefined8 param_1,longlong param_2);
void Unwind@18018f580(undefined8 param_1,longlong param_2);
void Unwind@18018f590(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018f5c0(void);
void Unwind@18018f5e0(undefined8 param_1,longlong param_2);
void Unwind@18018f5f0(undefined8 param_1,longlong param_2);
void Unwind@18018f620(undefined8 param_1,longlong param_2);
void Unwind@18018f650(undefined8 param_1,longlong param_2);
void Unwind@18018f680(undefined8 param_1,longlong param_2);
void Unwind@18018f690(undefined8 param_1,longlong param_2);
void Unwind@18018f6a0(undefined8 param_1,longlong param_2);
void Unwind@18018f6b0(undefined8 param_1,longlong param_2);
void Unwind@18018f6c0(undefined8 param_1,longlong param_2);
void Unwind@18018f6d0(undefined8 param_1,longlong param_2);
void Unwind@18018f6e0(undefined8 param_1,longlong param_2);
void Unwind@18018f6f0(undefined8 param_1,longlong param_2);
void Unwind@18018f700(undefined8 param_1,longlong param_2);
void Unwind@18018f710(undefined8 param_1,longlong param_2);
void Unwind@18018f720(undefined8 param_1,longlong param_2);
void Unwind@18018f750(undefined8 param_1,longlong param_2);
void Unwind@18018f780(undefined8 param_1,longlong param_2);
void Unwind@18018f7b0(undefined8 param_1,longlong param_2);
void Unwind@18018f7e0(undefined8 param_1,longlong param_2);
void Unwind@18018f810(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018f840(void);
undefined * Catch_All@18018f85b(void);
void Unwind@18018f880(undefined8 param_1,longlong param_2);
void Unwind@18018f890(undefined8 param_1,longlong param_2);
void Unwind@18018f8a0(undefined8 param_1,longlong param_2);
void Unwind@18018f8b0(undefined8 param_1,longlong param_2);
void Unwind@18018f8e0(undefined8 param_1,longlong param_2);
void Unwind@18018f910(undefined8 param_1,longlong param_2);
void Unwind@18018f940(undefined8 param_1,longlong param_2);
void Unwind@18018f950(undefined8 param_1,longlong param_2);
void Unwind@18018f980(undefined8 param_1,longlong param_2);
void Unwind@18018f9b0(undefined8 param_1,longlong param_2);
void Unwind@18018f9e0(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018fa10(undefined8 param_1,longlong param_2);
void Unwind@18018fa40(undefined8 param_1,longlong param_2);
void Unwind@18018fa50(undefined8 param_1,longlong param_2);
void Unwind@18018fa60(undefined8 param_1,longlong param_2);
void Unwind@18018fa70(undefined8 param_1,longlong param_2);
void Unwind@18018fa80(undefined8 param_1,longlong param_2);
void Unwind@18018fa90(undefined8 param_1,longlong param_2);
void Unwind@18018faa0(undefined8 param_1,longlong param_2);
void Unwind@18018fab0(undefined8 param_1,longlong param_2);
void Unwind@18018fac0(undefined8 param_1,longlong param_2);
void Unwind@18018fad0(undefined8 param_1,longlong param_2);
void Unwind@18018fb00(undefined8 param_1,longlong param_2);
void Unwind@18018fb10(undefined8 param_1,longlong param_2);
void Unwind@18018fb20(undefined8 param_1,longlong param_2);
void Unwind@18018fb30(undefined8 param_1,longlong param_2);
void Unwind@18018fb60(undefined8 param_1,longlong param_2);
void Unwind@18018fb80(undefined8 param_1,longlong param_2);
void Unwind@18018fbb0(undefined8 param_1,longlong param_2);
void Unwind@18018fbe0(undefined8 param_1,longlong param_2);
undefined * Catch_All@18018fc10(void);
undefined * Catch_All@18018fc2b(void);
undefined * Catch_All@18018fc46(void);
undefined * Catch_All@18018fc61(void);
void Unwind@18018fc80(undefined8 param_1,longlong param_2);
void Unwind@18018fcb0(undefined8 param_1,longlong param_2);
void Unwind@18018fce0(undefined8 param_1,longlong param_2);
void Unwind@18018fcf0(undefined8 param_1,longlong param_2);
void Unwind@18018fd30(undefined8 param_1,longlong param_2);
void Unwind@18018fd50(undefined8 param_1,longlong param_2);
void Unwind@18018fd60(undefined8 param_1,longlong param_2);
void Unwind@18018fd70(undefined8 param_1,longlong param_2);
void Unwind@18018fd80(undefined8 param_1,longlong param_2);
void Unwind@18018fdb0(undefined8 param_1,longlong param_2);
void Unwind@18018fdc0(undefined8 param_1,longlong param_2);
void Unwind@18018fdd0(undefined8 param_1,longlong param_2);
void Unwind@18018fde0(undefined8 param_1,longlong param_2);
void Unwind@18018fdf0(undefined8 param_1,longlong param_2);
void Unwind@18018fe00(undefined8 param_1,longlong param_2);
void Unwind@18018fe10(undefined8 param_1,longlong param_2);
void Unwind@18018fe20(undefined8 param_1,longlong param_2);
void Unwind@18018fe50(undefined8 param_1,longlong param_2);
void Unwind@18018fe80(undefined8 param_1,longlong param_2);
void Unwind@18018feb0(undefined8 param_1,longlong param_2);
void Unwind@18018fee0(undefined8 param_1,longlong param_2);
void Unwind@18018ff10(undefined8 param_1,longlong param_2);
void Unwind@18018ff40(undefined8 param_1,longlong param_2);
void Unwind@18018ff70(undefined8 param_1,longlong param_2);
void Unwind@18018ffa0(undefined8 param_1,longlong param_2);
void Unwind@18018ffd0(undefined8 param_1,longlong param_2);
void Unwind@180190000(undefined8 param_1,longlong param_2);
void Unwind@180190030(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190060(undefined8 param_1,longlong param_2);
undefined * Catch_All@18019008c(undefined8 param_1,longlong param_2);
void Unwind@1801900c0(undefined8 param_1,longlong param_2);
void Unwind@1801900d0(undefined8 param_1,longlong param_2);
void Unwind@1801900e0(undefined8 param_1,longlong param_2);
void Unwind@1801900f0(undefined8 param_1,longlong param_2);
void Unwind@180190100(undefined8 param_1,longlong param_2);
void Unwind@180190110(undefined8 param_1,longlong param_2);
void Unwind@180190120(undefined8 param_1,longlong param_2);
void Unwind@180190130(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190140(void);
void Unwind@180190160(undefined8 param_1,longlong param_2);
void Unwind@180190170(undefined8 param_1,longlong param_2);
void Unwind@180190180(undefined8 param_1,longlong param_2);
void Unwind@1801901b0(undefined8 param_1,longlong param_2);
void Unwind@1801901d0(undefined8 param_1,longlong param_2);
undefined * Catch_All@1801901e0(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190206(undefined8 param_1,longlong param_2);
void Unwind@180190230(undefined8 param_1,longlong param_2);
void Unwind@180190240(undefined8 param_1,longlong param_2);
void Unwind@180190250(undefined8 param_1,longlong param_2);
void Unwind@180190260(undefined8 param_1,longlong param_2);
void Unwind@180190270(undefined8 param_1,longlong param_2);
void Unwind@180190280(undefined8 param_1,longlong param_2);
void Unwind@180190290(undefined8 param_1,longlong param_2);
void Unwind@1801902a0(undefined8 param_1,longlong param_2);
void Unwind@1801902b0(undefined8 param_1,longlong param_2);
void Unwind@1801902c0(undefined8 param_1,longlong param_2);
void Unwind@1801902d0(undefined8 param_1,longlong param_2);
void Unwind@1801902e0(undefined8 param_1,longlong param_2);
void Unwind@1801902f0(undefined8 param_1,longlong param_2);
void Unwind@180190300(undefined8 param_1,longlong param_2);
void Unwind@180190310(undefined8 param_1,longlong param_2);
void Unwind@180190320(undefined8 param_1,longlong param_2);
void Unwind@180190330(undefined8 param_1,longlong param_2);
void Unwind@180190360(undefined8 param_1,longlong param_2);
void Unwind@180190390(undefined8 param_1,longlong param_2);
void Unwind@1801903a0(undefined8 param_1,longlong param_2);
void Unwind@1801903d0(undefined8 param_1,longlong param_2);
void Unwind@180190400(undefined8 param_1,longlong param_2);
void Unwind@180190410(undefined8 param_1,longlong param_2);
void Unwind@180190420(undefined8 param_1,longlong param_2);
void Unwind@180190430(undefined8 param_1,longlong param_2);
void Unwind@180190440(undefined8 param_1,longlong param_2);
void Unwind@180190450(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190460(void);
undefined * Catch_All@18019047b(void);
void Unwind@1801904a0(undefined8 param_1,longlong param_2);
void Unwind@1801904b0(undefined8 param_1,longlong param_2);
void Unwind@1801904c0(undefined8 param_1,longlong param_2);
void Unwind@1801904d0(undefined8 param_1,longlong param_2);
void Unwind@1801904e0(undefined8 param_1,longlong param_2);
void Unwind@1801904f0(undefined8 param_1,longlong param_2);
void Unwind@180190520(undefined8 param_1,longlong param_2);
void Unwind@180190530(undefined8 param_1,longlong param_2);
void Unwind@180190540(undefined8 param_1,longlong param_2);
void Unwind@180190550(undefined8 param_1,longlong param_2);
void Unwind@180190560(undefined8 param_1,longlong param_2);
void Unwind@180190570(undefined8 param_1,longlong param_2);
void Unwind@180190580(undefined8 param_1,longlong param_2);
void Unwind@180190590(undefined8 param_1,longlong param_2);
void Unwind@1801905a0(undefined8 param_1,longlong param_2);
void Unwind@1801905b0(undefined8 param_1,longlong param_2);
void Unwind@1801905e0(undefined8 param_1,longlong param_2);
void Unwind@180190610(undefined8 param_1,longlong param_2);
void Unwind@180190620(undefined8 param_1,longlong param_2);
void Unwind@180190630(undefined8 param_1,longlong param_2);
void Unwind@180190640(undefined8 param_1,longlong param_2);
void Unwind@180190650(undefined8 param_1,longlong param_2);
void Unwind@180190660(undefined8 param_1,longlong param_2);
void Unwind@180190670(undefined8 param_1,longlong param_2);
void Unwind@180190680(undefined8 param_1,longlong param_2);
void Unwind@180190690(undefined8 param_1,longlong param_2);
void Unwind@1801906a0(undefined8 param_1,longlong param_2);
void Unwind@1801906d0(undefined8 param_1,longlong param_2);
void Unwind@1801906e0(undefined8 param_1,longlong param_2);
void Unwind@1801906f0(undefined8 param_1,longlong param_2);
void Unwind@180190700(undefined8 param_1,longlong param_2);
void Unwind@180190710(undefined8 param_1,longlong param_2);
void Unwind@180190720(undefined8 param_1,longlong param_2);
void Unwind@180190730(undefined8 param_1,longlong param_2);
void Unwind@180190740(undefined8 param_1,longlong param_2);
void Unwind@180190750(undefined8 param_1,longlong param_2);
void Unwind@180190780(undefined8 param_1,longlong param_2);
void Unwind@180190790(undefined8 param_1,longlong param_2);
void Unwind@1801907d0(undefined8 param_1,longlong param_2);
void Unwind@1801907f0(undefined8 param_1,longlong param_2);
void Unwind@180190820(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190850(undefined8 param_1,longlong param_2);
void Unwind@180190880(undefined8 param_1,longlong param_2);
void Unwind@1801908b0(undefined8 param_1,longlong param_2);
void Unwind@1801908e0(undefined8 param_1,longlong param_2);
void Unwind@180190910(undefined8 param_1,longlong param_2);
void Unwind@180190940(undefined8 param_1,longlong param_2);
void Unwind@180190950(undefined8 param_1,longlong param_2);
void Unwind@180190980(undefined8 param_1,longlong param_2);
undefined * Catch_All@1801909b0(undefined8 param_1,longlong param_2);
undefined * Catch_All@1801909e0(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190a10(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190a40(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190a70(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190aa0(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190ac0(undefined8 param_1,longlong param_2);
undefined * Catch_All@180190af0(undefined8 param_1,longlong param_2);
bool FUN_180190b12(undefined8 *param_1);
void FUN_180190b2a(undefined8 *param_1);
void FUN_180190b45(undefined8 param_1,longlong param_2);
void FUN_180190b5c(undefined8 param_1,longlong param_2);
void FUN_180190b78(undefined8 *param_1,longlong param_2);
void FUN_180190bae(undefined8 param_1,longlong param_2);
void FUN_180190bda(undefined8 param_1,longlong param_2);
undefined4`void___cdecl___ArrayUnwind(void*___ptr64,unsigned___int64,int,void_(__cdecl*)(void*___ptr64))'::__l1::filt$0(undefined8 param_1,longlong param_2);
void FUN_180190c50(void);
void FUN_180190cc0(void);
void FUN_180190d30(void);
void FUN_180190da0(void);
void FUN_180190e50(void);
void FUN_180190ec0(void);
void FUN_180190f30(void);
void FUN_180190f40(void);
void FUN_180190fb0(void);
void FUN_180191040(void);
void FUN_1801910fc(void);

