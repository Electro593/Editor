/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// *
// * Modules
// *

#if _BUILD_MODE==0
#   define _DEBUG
#else
#   error "Unsupported Build Mode"
#endif

#if _COMPILER==0
#   define _MSVC
#else
#   error "Unsupported Compiler"
#endif

#if _PLATFORM==0
// #   define _WIN32
#else
#   error "Unsupported Platform"
#endif

#if _ARCHITECTURE==0
#   define _X64
#else
#   error "Unsupported Architecture"
#endif

// *
// * Defines
// *

#define global static
#define persistant static
#define internal inline static
#define external

#define RETURNS(...)

// *
// * Typedefs
// *

typedef          __int8  s08;
typedef          __int16 s16;
typedef          __int32 s32;
typedef          __int64 s64;

typedef unsigned __int8  u08;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;

typedef float r32;
typedef double r64;

typedef u08 c08;

typedef u08 b08;

typedef void * vptr;
typedef void (*fptr)(void);

// *
// * Generics
// *

#define TYPES \
    ENUM(U32, sizeof(u32)) \

typedef enum type_name
{
    #define ENUM(Name, Size) \
        TYPE__##Name,
    TYPES
    #undef ENUM
} type_name;

typedef struct type
{
    type_name Name;
    u32 Size;
} type;

#define ENUM(Name, Size) \
    global type Name = {TYPE__##Name, Size};
TYPES
#undef ENUM

#undef TYPES

// *
// * Includes
// *

#define INCLUDE_HEADER
#include <util/module.c>
#include <base/module.c>
#include <platform/module.c>
#undef  INCLUDE_HEADER

// *
// * Misc
// *

s32 _fltused;