/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef X_MACRO
#   ifndef IPROC
#       define IPROC(Module, ReturnType, Name, ...)
#   endif
#   ifndef EPROC
#       define EPROC(ReturnType, Name, ...)
#   endif
#   ifndef IFUNC
#       define IFUNC(ReturnType, Name, ...)
#   endif
#   ifndef EFUNC
#       define EFUNC(ReturnType, Name, ...)
#   endif
    
    X_MACRO
    
#   undef IPROC
#   undef EPROC
#   undef IFUNC
#   undef EFUNC
#   undef X_MACRO
#endif