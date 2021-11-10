/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef INCLUDE_HEADER

#define PLATFORM__WIN32_LOADER__FUNCS \
    EPROC(Platform, void, Entry, void) \
    IFUNC(Platform, void, LoadExternalFunctions, void) \

#else

internal void
Platform_LoadExternalFunctions(void)
{
    win32_teb *TEB = (win32_teb*)Asm_ReadGSQWord(48);
    win32_list_entry *Entry = TEB->PEB->LDR->MemoryOrderList.Next;
    Entry = Entry->Next->Next;
    win32_module *Kernel32 = (win32_module*)(Entry + 2);
    
    
    Win32->GetProcAddress = ;
    
    Win32->LoadLibraryA = (func_Win32_LoadLibraryA*)Win32->GetProcAddress(Kernel32, "LoadLibraryA");
    
    #define IPROC(Module, ReturnType, Name, ...) \
        Win32->Name = (func_Win32_##Name*)Win32->GetProcAddress(Module, #Name);
    #define X_MACRO WIN32__FUNCS
    #include <macro.h>
}

external void
Platform_Entry(void)
{
    platform P;
    win32 W;
    Platform = &P;
    Win32 = &W;
    
    #define IFUNC(Module, ReturnType, Name, ...) \
        Platform->Name = Module##_##Name;
    #define X_MACRO PLATFORM__FUNCS
    #include <macro.h>
    
    Platform->LoadExternalFunctions();
    
    
    
    Win32->ExitProcess(0);
}

#endif