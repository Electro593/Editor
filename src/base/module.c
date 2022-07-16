/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef INCLUDE_HEADER
#include <shared.h>
#endif



#include <base/util/intrin.c>
#include <base/util/mem.c>



#ifdef INCLUDE_HEADER



#define BASE__FUNCS \
    UTIL__MEM__FUNCS \
    EFUNC(void, Base_Init, void) \
    EPROC(void, Base_Load, base *OutBase, platform *InPlatform) \

#define EPROC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define EFUNC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define IFUNC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define X_MACRO BASE__FUNCS
#include <macro.h>

struct base
{
    #define EFUNC(ReturnType, Name, ...) \
        func_##Name *Name;
    #define X_MACRO BASE__FUNCS
    #include <macro.h>
};
global base *Base;



#else



internal void
Base_Init(void)
{
    
}

external _API_EXPORT void
Base_Load(base *OutBase,
          platform *InPlatform)
{
    #define EFUNC(ReturnType, Name, ...) \
        OutBase->Name = Name;
    #define X_MACRO BASE__FUNCS
    #include <macro.h>
    
    Platform = InPlatform;
}



#endif