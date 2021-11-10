/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef INCLUDE_HEADER
#   include <shared.h>
#endif

#ifdef _WIN32
#   include <platform/win32/win32.c>
#   include <platform/win32/loader.c>
#endif

#ifdef INCLUDE_HEADER
#define PLATFORM__FUNCS \
    PLATFORM__WIN32_LOADER__FUNCS \

#define IFUNC(Module, ReturnType, Name, ...) \
    typedef ReturnType func_##Module##_##Name(__VA_ARGS__);
#define X_MACRO PLATFORM__FUNCS
#include <macro.h>

typedef struct platform
{
    #define IFUNC(Module, ReturnType, Name, ...) \
        func_##Module##_##Name *Name;
    #define X_MACRO PLATFORM__FUNCS
    #include <macro.h>
} platform;
global platform *Platform;
#endif