/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef INCLUDE_HEADER

#define UTIL__MEM__FUNCS \
    EFUNC(vptr, Mem_Set, vptr Dest, u08 Data, u64 Size) \



#else



// - TODO: Use SIMD on this
internal vptr
Mem_Set(vptr Dest,
        u08 Data,
        u64 Size)
{
    u08 *Dest08 = (u08*)Dest;
    
    while(Size--)
    {
        *Dest08++ = Data;
    }
    
    return Dest;
}

#endif