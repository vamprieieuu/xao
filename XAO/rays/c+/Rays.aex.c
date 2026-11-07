#include "Rays.aex.h"


ulonglong DAT_180004018;
undefined DAT_180004080;
HMODULE DAT_180004060;
FARPROC DAT_180004068;
FARPROC DAT_180004070;
longlong DAT_180004078;
undefined DAT_180004050;
void *DAT_1800040d8;
void *StackBase;
undefined8 DAT_1800040e8;
undefined1 DAT_1800040e0;
char DAT_1800040e1;
undefined DAT_1800040f8;
undefined DAT_180004100;
undefined DAT_180004110;
undefined8 UNK_1800040f0;
undefined8 UNK_180004108;
IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER_180000210;
undefined DAT_180000300;
undefined8 DAT_1800040d8;
char DAT_1800040e0;
uintptr_t DAT_180004018;
int DAT_1800040d0;
int DAT_180004118;
undefined DAT_180003158;
undefined DAT_180003168;
undefined _guard_dispatch_icall;
undefined DAT_180003170;
undefined DAT_180003178;
undefined DAT_180004028;
uint DAT_18000411c;
undefined DAT_180004020;
undefined4 DAT_180004024;
int DAT_180004040;
undefined DAT_180004120;
undefined8 DAT_1800042c8;
undefined DAT_180004268;
undefined DAT_180004140;
undefined DAT_180004250;
undefined DAT_180004130;
undefined DAT_180004134;
undefined DAT_180004148;
undefined8 DAT_180004018;
undefined8 DAT_180004010;
undefined8 DAT_180004150;
pointer PTR_DAT_1800032c8;
undefined DAT_1800041d0;
ulonglong DAT_180004010;
undefined DAT_1800046a0;
undefined DAT_1800046b0;
undefined DAT_1800046b8;
undefined8 DAT_180003748;
undefined8 DAT_180003758;
undefined FUN_180001770;

// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

ulonglong PluginMain(uint param_1,longlong param_2,longlong param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auStack_198 [32];
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  char local_158 [272];
  ulonglong local_48;
  
                    // 0x1010  1  PluginMain
  local_48 = DAT_180004018 ^ (ulonglong)auStack_198;
  local_178 = param_4;
  if (param_1 == 1) {
    uVar9 = param_4;
    uVar2 = (**(code **)(*(longlong *)(param_2 + 0xb0) + 0x1b0))
                      (*(undefined8 *)(param_2 + 0xb8),1,local_158);
    uVar5 = (ulonglong)uVar2;
    if ((uVar2 == 0) && (pcVar3 = strrchr(local_158,0x5c), pcVar3 != (char *)0x0)) {
      pcVar4 = strrchr(local_158,0x2e);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
      }
      pcVar4 = pcVar3 + 1;
      lVar7 = (longlong)&DAT_180004080 - (longlong)pcVar4;
      do {
        cVar1 = *pcVar4;
        pcVar4[lVar7] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      builtin_strncpy(pcVar3 + 1,"BCCPlus.dll",0xc);
    }
    uVar8 = 8;
    DAT_180004060 = LoadLibraryExA(local_158,(HANDLE)0x0,8);
    if (DAT_180004060 == (HMODULE)0x0) {
      FUN_1800012e0(param_3 + 100,"Could not open bundle: %s",local_158,uVar9);
      uVar5 = 0x203;
    }
    else {
      DAT_180004068 = GetProcAddress(DAT_180004060,"get_driver_handle");
      if (DAT_180004060 == (HMODULE)0x0) {
        uVar8 = 0x3e;
        _wassert(L"m_handle",L"..\\driver.cpp",0x3e);
      }
      DAT_180004070 = GetProcAddress(DAT_180004060,"do_command");
      if ((DAT_180004070 == (FARPROC)0x0) || (DAT_180004068 == (FARPROC)0x0)) {
        FUN_1800012e0(param_3 + 100,"Could not find command function.",uVar8,uVar9);
        uVar5 = 0x203;
      }
      if ((int)uVar5 == 0) {
        DAT_180004078 = (*DAT_180004068)(&DAT_180004080);
        if (DAT_180004078 == 0) {
          FUN_1800012e0(param_3 + 100,"Could not find effect based on plugin name.",uVar8,uVar9);
        }
        local_168 = param_6;
        local_170 = param_5;
        uVar5 = (*DAT_180004070)(DAT_180004078,1,param_2,param_3);
        return uVar5;
      }
    }
  }
  else if (param_1 == 3) {
    local_168 = param_6;
    local_170 = param_5;
    uVar6 = (*DAT_180004070)(DAT_180004078,3,param_2,param_3);
    uVar5 = uVar6 & 0xffffffff;
    if (((int)uVar6 == 0) && (uVar5 = 0, DAT_180004060 != (HMODULE)0x0)) {
      FreeLibrary(DAT_180004060);
      DAT_180004060 = (HMODULE)0x0;
    }
  }
  else {
    if (DAT_180004078 == 0) {
      _wassert(L"s_driver_handle",L"..\\driver.cpp",0xf5);
    }
    local_168 = param_6;
    local_170 = param_5;
    uVar5 = (*DAT_180004070)(DAT_180004078,(ulonglong)param_1,param_2,param_3);
  }
  return uVar5;
}



undefined * FUN_1800012d0(void)

{
  return &DAT_180004050;
}



int FUN_1800012e0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_1800012d0();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
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
LAB_18000136e:
    uVar3 = (ulonglong)pvVar2 & 0xffffffffffffff00;
  }
  else {
    do {
      pvVar2 = (void *)0x0;
      LOCK();
      bVar1 = DAT_1800040d8 == (void *)0x0;
      if (bVar1) {
        DAT_1800040d8 = StackBase;
      }
      else {
        pvVar2 = DAT_1800040d8;
      }
      UNLOCK();
      if (bVar1) goto LAB_18000136e;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



// Library Function - Single Match
//  __scrt_dllmain_after_initialize_c
// 
// Library: Visual Studio 2019 Release

undefined8 __scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar3 = FUN_180001c74();
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



bool FUN_1800013b0(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_1800014f8(0);
  return (char)uVar1 != '\0';
}



undefined1 FUN_1800013c8(void)

{
  char cVar1;
  
  cVar1 = FUN_180002144();
  if (cVar1 != '\0') {
    cVar1 = FUN_180002144();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_180002144();
  }
  return 0;
}



undefined1 FUN_1800013f0(void)

{
  FUN_180002144();
  FUN_180002144();
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
    _execute_onexit_table(&DAT_1800040e8);
    return;
  }
  uVar2 = FUN_180002148();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}



void FUN_180001498(void)

{
  FUN_180002144();
  FUN_180002144();
  return;
}



// Library Function - Single Match
//  __scrt_initialize_crt
// 
// Library: Visual Studio 2019 Release

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_1800040e0 = 1;
  }
  __isa_available_init();
  cVar1 = FUN_180002144();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_180002144();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_180002144();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_1800014f8(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_1800040e1 == '\0') {
    if (1 < param_1) {
                    // WARNING: Subroutine does not return
      FUN_180001c90(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_1800040e8 = 0xffffffffffffffff;
      uRam00000001800040f0 = 0xffffffffffffffff;
      _DAT_1800040f8 = 0xffffffffffffffff;
      _DAT_180004100 = 0xffffffffffffffff;
      uRam0000000180004108 = 0xffffffffffffffff;
      _DAT_180004110 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_1800040e8);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_180004100), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_1800040e1 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



// WARNING: Removing unreachable block (ram,0x000180001611)
// WARNING: Enum "SectionFlags": Some values do not have unique names
// Library Function - Single Match
//  __scrt_is_nonwritable_in_current_image
// 
// Library: Visual Studio 2019 Release

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_180000210; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_180000300;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x180000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x180000000U < uVar1)) goto LAB_1800015fa;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_1800015fa:
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
    DAT_1800040d8 = 0;
    UNLOCK();
  }
  return;
}



// Library Function - Single Match
//  __scrt_uninitialize_crt
// 
// Library: Visual Studio 2019 Release

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_1800040e0 == '\0') || (param_2 == '\0')) {
    FUN_180002144();
    FUN_180002144();
  }
  return 1;
}



// Library Function - Single Match
//  _onexit
// 
// Library: Visual Studio 2019 Release

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_1800040e8 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_1800040e8);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



// Library Function - Single Match
//  atexit
// 
// Library: Visual Studio 2019 Release

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
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



// WARNING: This is an inlined function

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_180004018) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_180001e14();
  return;
}



ulonglong FUN_180001770(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    bVar1 = FUN_1800018d8(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,bVar1);
  }
  if (param_2 == 1) {
    uVar2 = FUN_1800017c0(param_1,param_3);
    return uVar2;
  }
  if (param_2 == 2) {
    bVar1 = FUN_1800013c8();
  }
  else {
    if (param_2 != 3) {
      return 1;
    }
    bVar1 = FUN_1800013f0();
  }
  return (ulonglong)bVar1;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

undefined8 FUN_1800017c0(undefined8 param_1,undefined8 param_2)

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
    if (DAT_1800040d0 != 0) {
                    // WARNING: Subroutine does not return
      FUN_180001c90(7);
    }
    DAT_1800040d0 = 1;
    bVar2 = FUN_1800013b0();
    if (bVar2) {
      FUN_180002074();
      FUN_18000202c();
      FUN_180002050();
      iVar3 = _initterm_e(&DAT_180003170,&DAT_180003178);
      if ((iVar3 == 0) && (uVar6 = __scrt_dllmain_after_initialize_c(), (char)uVar6 != '\0')) {
        _initterm(&DAT_180003158,&DAT_180003168);
        DAT_1800040d0 = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar5);
    if (!bVar1) {
      plVar7 = (longlong *)FUN_18000206c();
      if ((*plVar7 != 0) &&
         (uVar8 = __scrt_is_nonwritable_in_current_image((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)*plVar7)(param_1,2,param_2,_guard_dispatch_icall);
      }
      DAT_180004118 = DAT_180004118 + 1;
      return 1;
    }
  }
  return 0;
}



byte FUN_1800018d8(undefined8 param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar1 = (undefined1)param_1;
  if (DAT_180004118 < 1) {
    bVar5 = 0;
  }
  else {
    DAT_180004118 = DAT_180004118 + -1;
    uVar3 = __scrt_acquire_startup_lock();
    if (DAT_1800040d0 != 2) {
                    // WARNING: Subroutine does not return
      FUN_180001c90(7);
    }
    __scrt_dllmain_uninitialize_c();
    FUN_18000203c();
    FUN_1800020b0();
    DAT_1800040d0 = 0;
    uVar4 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar3);
    cVar2 = __scrt_uninitialize_crt(CONCAT71(uVar4,uVar1),'\0');
    bVar5 = -(cVar2 != '\0') & 1;
    FUN_180001498();
  }
  return bVar5;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Removing unreachable block (ram,0x000180001a1e)
// WARNING: Removing unreachable block (ram,0x0001800019af)
// WARNING: Removing unreachable block (ram,0x000180001a61)
// Library Function - Single Match
//  int __cdecl dllmain_dispatch(struct HINSTANCE__ * __ptr64 const,unsigned long,void * __ptr64
// const)
// 
// Library: Visual Studio 2019 Release

int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  HINSTANCE__ *pHVar4;
  
  if ((param_2 == 0) && (DAT_180004118 < 1)) {
    iVar1 = 0;
  }
  else {
    if ((param_2 - 1 < 2) &&
       (uVar2 = FUN_180001770(param_1,param_2,(longlong)param_3), (int)uVar2 == 0)) {
      return 0;
    }
    uVar3 = DllMain(param_1,param_2);
    iVar1 = (int)uVar3;
    if ((param_2 == 1) && (iVar1 == 0)) {
      pHVar4 = param_1;
      DllMain(param_1,0);
      FUN_1800018d8(CONCAT71((int7)((ulonglong)pHVar4 >> 8),param_3 != (void *)0x0));
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      uVar2 = FUN_180001770(param_1,param_2,(longlong)param_3);
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



// WARNING: Removing unreachable block (ram,0x000180001b8f)
// WARNING: Removing unreachable block (ram,0x000180001b0a)
// WARNING: Removing unreachable block (ram,0x000180001ae3)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __isa_available_init
// 
// Library: Visual Studio 2019 Release

undefined8 __isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar8 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[1] == 0x756e6547 && piVar1[3] == 0x6c65746e) && piVar1[2] == 0x49656e69) {
    _DAT_180004028 = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_18000411c = DAT_18000411c | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_18000411c = DAT_18000411c | 2;
    }
  }
  _DAT_180004020 = 1;
  DAT_180004024 = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_180004020 = 2;
    DAT_180004024 = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        _DAT_180004020 = 3;
        DAT_180004024 = 0xe;
        if ((uVar8 & 0x20) != 0) {
          _DAT_180004020 = 5;
          DAT_180004024 = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            DAT_180004024 = 0x6e;
            _DAT_180004020 = 6;
          }
        }
      }
    }
  }
  return 0;
}



undefined8 FUN_180001c74(void)

{
  return 1;
}



// Library Function - Single Match
//  __scrt_is_ucrt_dll_in_use
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_180004040 != 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180001c88(void)

{
  _DAT_180004120 = 0;
  return;
}



void FUN_180001c90(undefined4 param_1)

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
  *(undefined8 *)(puVar4 + -8) = 0x180001cc4;
  FUN_180001c88();
  *(undefined8 *)(puVar4 + -8) = 0x180001cd5;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180001cdf;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x180001cf9;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x180001d3a;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = local_res18 + -0x10;
  *(undefined8 *)(puVar4 + -8) = 0x180001d6c;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x180001d8e;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x180001daf;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x180001dba;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x180001dca;
    FUN_180001c88();
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
                    // WARNING: Could not recover jumptable at 0x000180001e0d. Too many branches
                    // WARNING: Treating indirect jump as call
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_180001e14(void)

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
  *(undefined8 *)(puVar3 + -8) = 0x180001e3f;
  capture_previous_context((PCONTEXT)&DAT_1800041d0);
  _DAT_180004140 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_180004268 = puVar3 + 0x40;
  _DAT_180004250 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180004130 = 0xc0000409;
  _DAT_180004134 = 1;
  _DAT_180004148 = 1;
  DAT_180004150 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_180004018;
  *(undefined8 *)(puVar3 + 0x28) = DAT_180004010;
  *(undefined8 *)(puVar3 + -8) = 0x180001ee1;
  DAT_1800042c8 = _DAT_180004140;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1800032c8);
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
  
  if (DAT_180004018 == 0x2b992ddfa232) {
    local_res10.dwLowDateTime = 0;
    local_res10.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res10);
    local_res8 = local_res10;
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res18);
    DAT_180004018 =
         ((ulonglong)local_res18.s.LowPart << 0x20 ^
          CONCAT44(local_res18.s.HighPart,local_res18.s.LowPart) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
    if (DAT_180004018 == 0x2b992ddfa232) {
      DAT_180004018 = 0x2b992ddfa233;
    }
  }
  DAT_180004010 = ~DAT_180004018;
  return;
}



// Library Function - Single Match
//  DllMain
// 
// Library: Visual Studio 2019 Release

undefined8 DllMain(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



void FUN_18000202c(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002033. Too many branches
                    // WARNING: Treating indirect jump as call
  InitializeSListHead(&DAT_1800046a0);
  return;
}



void FUN_18000203c(void)

{
  __std_type_info_destroy_list(&DAT_1800046a0);
  return;
}



undefined * FUN_180002048(void)

{
  return &DAT_1800046b0;
}



void FUN_180002050(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_1800012d0();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_180002048();
  *puVar1 = *puVar1 | 2;
  return;
}



undefined * FUN_18000206c(void)

{
  return &DAT_1800046b8;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_180002074(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &DAT_180003748; puVar1 < &DAT_180003748; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_1800020b0(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &DAT_180003758; puVar1 < &DAT_180003758; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



char * __cdecl strrchr(char *_Str,int _Ch)

{
  char *pcVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800020f0. Too many branches
                    // WARNING: Treating indirect jump as call
  pcVar1 = strrchr(_Str,_Ch);
  return pcVar1;
}



void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x0001800020fc. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



void __std_type_info_destroy_list(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002102. Too many branches
                    // WARNING: Treating indirect jump as call
  __std_type_info_destroy_list();
  return;
}



void _seh_filter_dll(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002108. Too many branches
                    // WARNING: Treating indirect jump as call
  _seh_filter_dll();
  return;
}



void _configure_narrow_argv(void)

{
                    // WARNING: Could not recover jumptable at 0x00018000210e. Too many branches
                    // WARNING: Treating indirect jump as call
  _configure_narrow_argv();
  return;
}



void _initialize_narrow_environment(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002114. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_narrow_environment();
  return;
}



void _initialize_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x00018000211a. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_onexit_table();
  return;
}



void _register_onexit_function(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002120. Too many branches
                    // WARNING: Treating indirect jump as call
  _register_onexit_function();
  return;
}



void _execute_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002126. Too many branches
                    // WARNING: Treating indirect jump as call
  _execute_onexit_table();
  return;
}



void _crt_atexit(void)

{
                    // WARNING: Could not recover jumptable at 0x00018000212c. Too many branches
                    // WARNING: Treating indirect jump as call
  _crt_atexit();
  return;
}



void __cdecl _cexit(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002132. Too many branches
                    // WARNING: Treating indirect jump as call
  _cexit();
  return;
}



void _initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x000180002138. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm();
  return;
}



void _initterm_e(void)

{
                    // WARNING: Could not recover jumptable at 0x00018000213e. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm_e();
  return;
}



undefined1 FUN_180002144(void)

{
  return 1;
}



undefined8 FUN_180002148(void)

{
  return 0;
}



// WARNING: This is an inlined function

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    // WARNING: Could not recover jumptable at 0x000180002160. Too many branches
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



bool FUN_180002186(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



void FUN_18000219e(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}



void FUN_1800021b5(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}



void FUN_1800021ce(void)

{
  FUN_180001498();
  return;
}



void FUN_1800021e2(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),FUN_180001770,*(undefined4 *)*param_1,param_1);
  return;
}



void FUN_180002220(void)

{
  if (DAT_180004060 != (HMODULE)0x0) {
    FreeLibrary(DAT_180004060);
    DAT_180004060 = (HMODULE)0x0;
  }
  return;
}


