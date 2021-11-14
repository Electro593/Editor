/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef INCLUDE_HEADER

#ifdef _DEBUG
#   define DLL_PATH(Module) ("build/" #Module ".dll")
#   define DLL_LOCKED_PATH(Module) ("build/" #Module "_Locked.dll")
#else
#   define DLL_PATH(Module) (#Module ".dll")
#   define DLL_LOCKED_PATH(Module) (#Module "_Locked.dll")
#endif
#define DLL_LOAD_FUNC(Module) (#Module "_Load")



typedef enum execution_state
{
    Execution_Stopped,
    Execution_Running,
    Execution_Paused,
} execution_state;

typedef enum audio_state
{
    AudioFlag_Enabled   = 0b01,
    AudioFlag_Exclusive = 0b10,
    
    Audio_Disabled      = 0,
} audio_state;

typedef enum scancode
{
    ScanCode_Unknown          = 0x00,
    
    ScanCode_Escape           = 0x01,
    ScanCode_1                = 0x02,
    ScanCode_2                = 0x03,
    ScanCode_3                = 0x04,
    ScanCode_4                = 0x05,
    ScanCode_5                = 0x06,
    ScanCode_6                = 0x07,
    ScanCode_7                = 0x08,
    ScanCode_8                = 0x09,
    ScanCode_9                = 0x0A,
    ScanCode_0                = 0x0B,
    ScanCode_Hyphen           = 0x0C,
    ScanCode_Equals           = 0x0D,
    ScanCode_Backspace        = 0x0E,
    ScanCode_Tab              = 0x0F,
    ScanCode_Q                = 0x10,
    ScanCode_W                = 0x11,
    ScanCode_E                = 0x12,
    ScanCode_R                = 0x13,
    ScanCode_T                = 0x14,
    ScanCode_Y                = 0x15,
    ScanCode_U                = 0x16,
    ScanCode_I                = 0x17,
    ScanCode_O                = 0x18,
    ScanCode_P                = 0x19,
    ScanCode_BracketLeft      = 0x1A,
    ScanCode_BracketRight     = 0x1B,
    ScanCode_Enter            = 0x1C,
    ScanCode_ControlLeft      = 0x1D,
    ScanCode_A                = 0x1E,
    ScanCode_S                = 0x1F,
    ScanCode_D                = 0x20,
    ScanCode_F                = 0x21,
    ScanCode_G                = 0x22,
    ScanCode_H                = 0x23,
    ScanCode_K                = 0x25,
    ScanCode_J                = 0x24,
    ScanCode_L                = 0x26,
    ScanCode_Semicolon        = 0x27,
    ScanCode_Apostrophe       = 0x28,
    ScanCode_Grave            = 0x29,
    ScanCode_ShiftLeft        = 0x2A,
    ScanCode_Backslash        = 0x2B,
    ScanCode_Z                = 0x2C,
    ScanCode_X                = 0x2D,
    ScanCode_C                = 0x2E,
    ScanCode_V                = 0x2F,
    ScanCode_B                = 0x30,
    ScanCode_N                = 0x31,
    ScanCode_M                = 0x32,
    ScanCode_Comma            = 0x33,
    ScanCode_Period           = 0x34,
    ScanCode_Slash            = 0x35,
    ScanCode_ShiftRight       = 0x36,
    ScanCode_Multiply         = 0x37,
    ScanCode_AltLeft          = 0x38,
    ScanCode_Space            = 0x39,
    ScanCode_CapsLock         = 0x3A,
    ScanCode_F1               = 0x3B,
    ScanCode_F2               = 0x3C,
    ScanCode_F3               = 0x3D,
    ScanCode_F4               = 0x3E,
    ScanCode_F5               = 0x3F,
    ScanCode_F6               = 0x40,
    ScanCode_F7               = 0x41,
    ScanCode_F8               = 0x42,
    ScanCode_F9               = 0x43,
    ScanCode_F10              = 0x44,
    ScanCode_NumLock          = 0x45,
    ScanCode_ScrollLock       = 0x46,
    ScanCode_Numpad7          = 0x47,
    ScanCode_Numpad8          = 0x48,
    ScanCode_Numpad9          = 0x49,
    ScanCode_NumpadSubtract   = 0x4A,
    ScanCode_Numpad4          = 0x4B,
    ScanCode_Numpad5          = 0x4C,
    ScanCode_Numpad6          = 0x4D,
    ScanCode_NumpadAdd        = 0x4E,
    ScanCode_Numpad1          = 0x4F,
    ScanCode_Numpad2          = 0x50,
    ScanCode_Numpad3          = 0x51,
    ScanCode_Numpad0          = 0x52,
    ScanCode_NumpadDecimal    = 0x53,
    ScanCode_AltPrintScreen   = 0x54,
    ScanCode_AngleBracket     = 0x59,
    ScanCode_F11              = 0x57,
    ScanCode_F12              = 0x58,
    ScanCode_OEM1             = 0x5A,
    ScanCode_OEM2             = 0x5B,
    ScanCode_OEM3             = 0x5C,
    ScanCode_EraseEOF         = 0x5D,
    ScanCode_OEM4             = 0x5E,
    ScanCode_OEM5             = 0x5F,
    ScanCode_Zoom             = 0x62,
    ScanCode_Help             = 0x63,
    ScanCode_F13              = 0x64,
    ScanCode_F14              = 0x65,
    ScanCode_F15              = 0x66,
    ScanCode_F16              = 0x67,
    ScanCode_F17              = 0x68,
    ScanCode_F18              = 0x69,
    ScanCode_F19              = 0x6A,
    ScanCode_F20              = 0x6B,
    ScanCode_F21              = 0x6C,
    ScanCode_F22              = 0x6D,
    ScanCode_F23              = 0x6E,
    ScanCode_OEM6             = 0x6F,
    ScanCode_Katakana         = 0x70,
    ScanCode_OEM7             = 0x71,
    ScanCode_F24              = 0x76,
    ScanCode_SBCS             = 0x77,
    ScanCode_Convert          = 0x79,
    ScanCode_NonConvert       = 0x7B,
    
    ScanCode_MediaPrev        = 0xE010,
    ScanCode_MediaNext        = 0xE019,
    ScanCode_NumpadEnter      = 0xE01C,
    ScanCode_ControlRight     = 0xE01D,
    ScanCode_VolumeMute       = 0xE020,
    ScanCode_LaunchApp2       = 0xE021,
    ScanCode_MediaPlay        = 0xE022,
    ScanCode_MediaStop        = 0xE024,
    ScanCode_VolumeDown       = 0xE02E,
    ScanCode_VolumeUp         = 0xE030,
    ScanCode_BrowserHome      = 0xE032,
    ScanCode_NumpadDivide     = 0xE035,
    ScanCode_PrintScreen      = 0xE037,
    ScanCode_AltRight         = 0xE038,
    ScanCode_Cancel           = 0xE046,
    ScanCode_Home             = 0xE047,
    ScanCode_ArrowUp          = 0xE048,
    ScanCode_PageUp           = 0xE049,
    ScanCode_ArrowLeft        = 0xE04B,
    ScanCode_ArrowRight       = 0xE04D,
    ScanCode_End              = 0xE04F,
    ScanCode_ArrowDown        = 0xE050,
    ScanCode_PageDown         = 0xE051,
    ScanCode_Insert           = 0xE052,
    ScanCode_Delete           = 0xE053,
    ScanCode_MetaLeft         = 0xE05B,
    ScanCode_MetaRight        = 0xE05C,
    ScanCode_Application      = 0xE05D,
    ScanCode_Power            = 0xE05E,
    ScanCode_Sleep            = 0xE05F,
    ScanCode_Wake             = 0xE063,
    ScanCode_BrowserSearch    = 0xE065,
    ScanCode_BrowserFavorites = 0xE066,
    ScanCode_BrowserRefresh   = 0xE067,
    ScanCode_BrowserStop      = 0xE068,
    ScanCode_BrowserForward   = 0xE069,
    ScanCode_BrowserBack      = 0xE06A,
    ScanCode_LaunchApp1       = 0xE06B,
    ScanCode_LaunchEmail      = 0xE06C,
    ScanCode_LaunchMedia      = 0xE06D,
    
    ScanCode_Pause            = 0xE11D45,
} scancode;

typedef enum keycode
{
    Keycode_Unknown = 0,
} keycode;

typedef enum key_state
{
    Key_Released,
    Key_Pressed,
    Key_Repeated,
} key_state;

typedef struct loader_dll
{
    win32_module DLL;
    win32_file_time LastWritten;
} loader_dll;



#define PLATFORM__FUNCS \
    EFUNC(void,            Assert,                c08 *File, u32 Line, c08 *Message) \
    EPROC(void,            Entry,                 void) \
    IFUNC(win32_find_data, GetFileData,           c08 *FileName) \
    IFUNC(void,            LoadGameDLL,           loader_dll *DLL) \
    IFUNC(void,            LoadExternalFunctions, void) \
    IFUNC(void,            LoadUtilDLL,           loader_dll *DLL) \
    IFUNC(s64,             WindowCallback,        win32_window Window, u32 Message, s64 WParam, s64 LParam) \

#define EPROC(ReturnType, Name, ...) typedef ReturnType func_Platform_##Name(__VA_ARGS__);
#define EFUNC(ReturnType, Name, ...) typedef ReturnType func_Platform_##Name(__VA_ARGS__);
#define IFUNC(ReturnType, Name, ...) typedef ReturnType func_Platform_##Name(__VA_ARGS__);
#define X_MACRO PLATFORM__FUNCS
#include <macro.h>

struct platform
{
    execution_state ExecutionState;
    audio_state AudioState;
    
    struct
    {
        u08 Keys[0x100];
    } Input;
    
    #define EFUNC(ReturnType, Name, ...) \
        func_Platform_##Name *Name;
    #define X_MACRO PLATFORM__FUNCS
    #include <macro.h>
};
global platform *Platform;



#else



internal void
Platform_Assert(c08 *File,
                u32 Line,
                c08 *Message)
{
    c08 LineStr[12];
    u32 Value = Line;
    u32 Index = 1;
    while(Value /= 10) Index++;
    LineStr[Index] = '\0';
    while(Index--)
    {
        LineStr[Index] = (Line % 10) + '0';
        Line /= 10;
    }
    
    Win32.OutputDebugStringA("\n");
    Win32.OutputDebugStringA(File);
    Win32.OutputDebugStringA("(");
    Win32.OutputDebugStringA(LineStr);
    Win32.OutputDebugStringA("): ");
    Win32.OutputDebugStringA(Message);
    Win32.OutputDebugStringA("\n");
}

internal void
Platform_LoadExternalFunctions(void)
{
    win32_teb *TEB = (win32_teb*)Asm_ReadGSQWord(48);
    win32_list_entry *Entry = TEB->PEB->LDR->MemoryOrderList.Next;
    Entry = Entry->Next->Next;
    win32_module Kernel32 = *(win32_module*)((u08*)Entry + 16 + 16);
    
    u08 *DOSHeader = (u08*)Kernel32;
    u08 *NTHeader = DOSHeader + *(s32*)(DOSHeader + 60);
    u08 *ImageExportDirectory = DOSHeader + *(u32*)(NTHeader + 24 + 112);
    u32 *ExportAddressTable = (u32*)(DOSHeader + *(u32*)(ImageExportDirectory + 28));
    u32 *ExportNameTable    = (u32*)(DOSHeader + *(u32*)(ImageExportDirectory + 32));
    u16 *ExportOrdinalTable = (u16*)(DOSHeader + *(u32*)(ImageExportDirectory + 36));
    
    u32 Index;
    u32 Low = 0;
    u32 High = *(u32*)(ImageExportDirectory + 24) - 1;
    while(TRUE)
    {
        Index = (High + Low) / 2;
        c08 *Goal = "GetProcAddress";
        c08 *Curr = (c08*)(DOSHeader + ExportNameTable[Index]);
        while(*Goal && *Curr && *Goal == *Curr)
        {
            Goal++;
            Curr++;
        }
        
        if(*Goal == *Curr) break;
        if(*Goal > *Curr) Low = Index;
        else High = Index;
    }
    
    u16 GetProcAddressOrdinal = ExportOrdinalTable[Index];
    u32 GetProcAddressRVA = ExportAddressTable[GetProcAddressOrdinal];
    Win32.GetProcAddress = (func_Win32_GetProcAddress*)(DOSHeader + GetProcAddressRVA);
    
    Win32.LoadLibraryA = (func_Win32_LoadLibraryA*)Win32.GetProcAddress(Kernel32, "LoadLibraryA");
    win32_module User32 = Win32.LoadLibraryA("user32.dll");
    
    #define IPROC(Module, ReturnType, Name, ...) \
        Win32.Name = (func_Win32_##Name*)Win32.GetProcAddress(Module, #Name);
    #define X_MACRO WIN32__FUNCS
    #include <macro.h>
}

internal win32_find_data
Platform_GetFileData(c08 *FileName)
{
    win32_find_data FindData;
    win32_handle FindHandle = Win32.FindFirstFileA(FileName, &FindData);
    ASSERT(FindHandle != INVALID_HANDLE_VALUE, "Didn't to find file");
    Win32.FindClose(FindHandle);
    return FindData;
}

internal void
Platform_LoadUtilDLL(loader_dll *DLL)
{
    if(DLL->DLL)
        Win32.FreeLibrary(DLL->DLL);
    
    Win32.CopyFileA(DLL_PATH(Util), DLL_LOCKED_PATH(Util), FALSE);
    DLL->DLL = Win32.LoadLibraryA(DLL_LOCKED_PATH(Util));
    DLL->LastWritten = Platform_GetFileData(DLL_LOCKED_PATH(Util)).LastWriteTime;
    
    func_Util_Load *Util_Load = (func_Util_Load*)Win32.GetProcAddress(DLL->DLL, DLL_LOAD_FUNC(Util));
    Util_Load(Util, Platform);
}

internal void
Platform_LoadGameDLL(loader_dll *DLL)
{
    if(DLL->DLL)
        Win32.FreeLibrary(DLL->DLL);
    
    Win32.CopyFileA(DLL_PATH(Game), DLL_LOCKED_PATH(Game), FALSE);
    DLL->DLL = Win32.LoadLibraryA(DLL_LOCKED_PATH(Game));
    DLL->LastWritten = Platform_GetFileData(DLL_LOCKED_PATH(Game)).LastWriteTime;
    
    func_Game_Load *Game_Load = (func_Game_Load*)Win32.GetProcAddress(DLL->DLL, DLL_LOAD_FUNC(Game));
    Game_Load(Game, Platform, Util);
}

external s64
Platform_WindowCallback(win32_window Window,
                        u32 Message,
                        s64 WParam,
                        s64 LParam)
{
    switch(Message)
    {
        case WM_SETFOCUS:
        {
            Platform->ExecutionState = Execution_Running;
            FLAG_SET(Platform->AudioState, AudioFlag_Enabled);
            Util->Mem_Set(Platform->Input.Keys, 0, sizeof(Platform->Input.Keys));
        } return 0;
        
        case WM_KILLFOCUS:
        {
            Platform->ExecutionState = Execution_Paused;
            FLAG_RESET(Platform->AudioState, AudioFlag_Enabled);
        } return 0;
        
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
        case WM_KEYDOWN:
        case WM_KEYUP:
        {
            u08 ScanCode    = (LParam >> 16) & 0xFF;
            b08 IsExtended  = (LParam >> 24) & 0x01;
            b08 WasDown     = (LParam >> 30) & 0x01;
            b08 IsUp        = (LParam >> 31) & 0x01;
            
            key_state KeyState;
            if(IsUp == TRUE && WasDown == TRUE) KeyState = Key_Released;
            else if(IsUp == FALSE && WasDown == FALSE) KeyState = Key_Pressed;
            else KeyState = Key_Repeated;
            
            if(IsExtended)
            {
                // Exclude NumLock
                if(ScanCode != 0x45)
                    ScanCode |= 0x80;
            }
            else
            {
                // Pause key
                if(ScanCode == 0x45)
                    ScanCode = 0xFF;
                // Alt + PrintScreen
                else if(ScanCode == 0x54)
                    ScanCode = 0x80 | 0x37;
            }
            
            Platform->Input.Keys[ScanCode] = KeyState;
        } return 0;
        
        case WM_SYSCOMMAND:
        {
            switch(WParam & 0xFFF0)
            {
                case SC_KEYMENU:
                {
                    return 0;
                } break;
            }
        } break;
    }
    
    return Win32.DefWindowProcA(Window, Message, WParam, LParam);
}

external void
Platform_Entry(void)
{
    platform P;
    game G;
    util U;
    Platform = &P;
    Game = &G;
    Util = &U;
    
    #define EFUNC(ReturnType, Name, ...) \
        Platform->Name = Platform_##Name;
    #define X_MACRO PLATFORM__FUNCS
    #include <macro.h>
    
    loader_dll UtilDLL;
    loader_dll GameDLL;
    Platform_LoadExternalFunctions();
    Platform_LoadUtilDLL(&UtilDLL);
    Platform_LoadGameDLL(&GameDLL);
    
    win32_instance Instance = Win32.GetModuleHandleA(NULL);
    win32_window_class_a WindowClass = {0};
    WindowClass.Callback = Platform_WindowCallback;
    WindowClass.Instance = Instance;
    WindowClass.ClassName = "Editor";
    Win32.RegisterClassA(&WindowClass);
    
    win32_window Window = Win32.CreateWindowExA(0, "Editor", WindowClass.ClassName,
                                                WS_OVERLAPPED|WS_SYSMENU|WS_CAPTION|WS_VISIBLE,
                                                CW_USEDEFAULT, CW_USEDEFAULT,
                                                CW_USEDEFAULT, CW_USEDEFAULT,
                                                NULL, NULL, Instance, NULL);
    ASSERT(Window, "Could not create window");
    
    Platform->ExecutionState = Execution_Running;
    Platform->AudioState = AudioFlag_Enabled|AudioFlag_Exclusive;
    
    while(Platform->ExecutionState != Execution_Stopped)
    {
        if(Platform->ExecutionState == Execution_Paused)
            Win32.WaitMessage();
        
        win32_message Message;
        while(Win32.PeekMessageA(&Message, Window, 0, 0, PM_REMOVE))
        {
            if(Message.Message == WM_QUIT)
            {
                Platform->ExecutionState = Execution_Stopped;
                break;
            }
            
            Win32.TranslateMessage(&Message);
            Win32.DispatchMessageA(&Message);
        }
        
        if(Platform->ExecutionState == Execution_Running)
        {
            win32_file_time GameDLLWriteTime = Platform_GetFileData(DLL_PATH(Game)).LastWriteTime;
            win32_file_time UtilDLLWriteTime = Platform_GetFileData(DLL_PATH(Util)).LastWriteTime;
            if(Win32.CompareFileTime(&GameDLLWriteTime, &GameDLL.LastWritten) > 0)
            {
                Platform_LoadGameDLL(&GameDLL);
            }
            if(Win32.CompareFileTime(&UtilDLLWriteTime, &UtilDLL.LastWritten) > 0)
            {
                Platform_LoadUtilDLL(&UtilDLL);
            }
            
            if((Platform->Input.Keys[ScanCode_AltLeft]  == Key_Pressed ||
                Platform->Input.Keys[ScanCode_AltRight] == Key_Pressed) &&
               Platform->Input.Keys[ScanCode_F4] == Key_Pressed)
            {
                Platform->ExecutionState = Execution_Stopped;
                break;
            }
        }
    }
    
    Win32.ExitProcess(0);
}



#endif