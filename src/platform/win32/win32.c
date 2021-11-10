/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef INCLUDE_HEADER

typedef vptr win32_module;

typedef struct win32_ldr_data_table_entry
{
    u08 Padding0[48];
    vptr DLLBase;
} win32_ldr_data_table_entry;

typedef struct win32_list_entry
{
    struct win32_list_entry *Next;
    struct win32_list_entry *Prev;
} win32_list_entry;

typedef struct win32_peb_ldr_data
{
    u08 Padding[32];
    win32_list_entry MemoryOrderList;
} win32_peb_ldr_data;

typedef struct win32_peb
{
    u08 Padding[24];
    win32_peb_ldr_data *LDR;
} win32_peb;

typedef struct win32_teb
{
    u08 Padding[96];
    win32_peb *PEB;
} win32_teb;

#define WIN32__FUNCS \
    IPROC(Kernel32, fptr,         GetProcAddress, win32_module Module, c08 *Name) \
    IPROC(Kernel32, void,         ExitProcess,    u32 ExitCode) \
    IPROC(Kernel32, win32_module, LoadLibraryA,   c08 *Name) \

#define IPROC(Module, ReturnType, Name, ...) \
    typedef ReturnType func_##Win32##_##Name(__VA_ARGS__);
#define X_MACRO WIN32__FUNCS
#include <macro.h>

typedef struct win32
{
    #define IPROC(Module, ReturnType, Name, ...) \
        func_##Win32##_##Name *Name;
    #define X_MACRO WIN32__FUNCS
    #include <macro.h>
} win32;
global win32 *Win32;

#endif