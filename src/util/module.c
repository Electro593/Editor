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



#include <util/intrin.c>
#include <util/mem.c>



#ifdef INCLUDE_HEADER



#define UTIL__FUNCS \
    UTIL__MEM__FUNCS \
    EPROC(void, Util_Load, util *OutUtil, platform *InPlatform) \

#define EPROC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define EFUNC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define IFUNC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define X_MACRO UTIL__FUNCS
#include <macro.h>

struct util
{
    #define EFUNC(ReturnType, Name, ...) \
        func_##Name *Name;
    #define X_MACRO UTIL__FUNCS
    #include <macro.h>
};
global util *Util;



#else



external void
Util_Load(util *OutUtil,
          platform *InPlatform)
{
    #define EFUNC(ReturnType, Name, ...) \
        OutUtil->Name = Name;
    #define X_MACRO UTIL__FUNCS
    #include <macro.h>
    
    Platform = InPlatform;
}



#endif