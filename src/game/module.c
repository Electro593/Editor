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

#ifdef INCLUDE_HEADER



#define GAME__FUNCS \
    EFUNC(void, Game_Init, void) \
    EPROC(void, Game_Load, game *OutGame, platform *InPlatform, util *InUtil) \

#define EPROC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define EFUNC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define IFUNC(ReturnType, Name, ...) typedef ReturnType func_##Name(__VA_ARGS__);
#define X_MACRO GAME__FUNCS
#include <macro.h>

struct game
{
    #define EFUNC(ReturnType, Name, ...) \
        func_##Name *Name;
    #define X_MACRO GAME__FUNCS
    #include <macro.h>
};
global game *Game;



#else



internal void
Game_Init(void)
{
    
}

external void
Game_Load(game *OutGame,
          platform *InPlatform,
          util *InUtil)
{
    #define EFUNC(ReturnType, Name, ...) \
        OutGame->Name = Name;
    #define X_MACRO GAME__FUNCS
    #include <macro.h>
    
    Platform = InPlatform;
    Util = InUtil;
}



#endif