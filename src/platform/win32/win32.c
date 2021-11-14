/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef INCLUDE_HEADER

#define CW_USEDEFAULT ((int)0x80000000)
#define PM_REMOVE     0x1
#define SC_KEYMENU    0xF100
#define WM_SETFOCUS   0x0007
#define WM_KILLFOCUS  0x0008
#define WM_KEYDOWN    0x0100
#define WM_KEYUP      0x0101
#define WM_SYSKEYDOWN 0x0104
#define WM_SYSKEYUP   0x0105
#define WM_SYSCOMMAND 0x0112
#define WM_QUIT       0x0012
#define WS_OVERLAPPED 0x00000000L
#define WS_SYSMENU    0x00080000L
#define WS_CAPTION    0x00C00000L
#define WS_VISIBLE    0x10000000L
#define MAX_PATH      260
#define INVALID_HANDLE_VALUE ((vptr)-1)



typedef u16          win32_atom;
typedef vptr         win32_handle;
typedef win32_handle win32_brush;
typedef win32_handle win32_cursor;
typedef win32_handle win32_icon;
typedef win32_handle win32_instance;
typedef win32_handle win32_menu;
typedef win32_handle win32_module;
typedef win32_handle win32_window;



typedef s64 (*win32_window_callback)(win32_window Window, u32 Message, s64 WParam, s64 LParam);



typedef struct win32_point {
  s32 x;
  s32 y;
} win32_point;

typedef struct win32_message {
    win32_window Window;
    u32 Message;
    u08 _Padding0[4];
    s64 WParam;
    s64 LParam;
    u32 Time;
    win32_point Point;
    u32 Private;
} win32_message;

typedef struct win32_ldr_data_table_entry
{
    u08 _Padding0[48];
    vptr DLLGame;
} win32_ldr_data_table_entry;

typedef struct win32_list_entry
{
    struct win32_list_entry *Next;
    struct win32_list_entry *Prev;
} win32_list_entry;

typedef struct win32_peb_ldr_data
{
    u08 _Padding0[4 + 1 + 3 + 8 + 16];
    win32_list_entry MemoryOrderList;
} win32_peb_ldr_data;

typedef struct win32_peb
{
    u08 _Padding0[1 + 1 + 1 + 1 + 4 + 8 + 8];
    win32_peb_ldr_data *LDR;
} win32_peb;

typedef struct win32_teb
{
    u08 _Padding0[56 + 8 + 16 + 8 + 8];
    win32_peb *PEB;
} win32_teb;

typedef struct win32_window_class_a
{
    u32 Style;
    u08 _Padding0[4];
    win32_window_callback Callback;
    s32 ClsExtra;
    s32 WndExtra;
    win32_instance Instance;
    win32_icon Icon;
    win32_cursor Cursor;
    win32_brush Background;
    c08 *MenuName;
    c08 *ClassName;
} win32_window_class_a;

typedef struct win32_file_time
{
  u32 LowDateTime;
  u32 HighDateTime;
} win32_file_time;

typedef struct win32_find_data {
  u32 FileAttributes;
  win32_file_time CreationTime;
  win32_file_time LastAccessTime;
  win32_file_time LastWriteTime;
  u32 FileSizeHigh;
  u32 FileSizeLow;
  u32 Reserved0;
  u32 Reserved1;
  c08 FileName[MAX_PATH];
  c08 AlternateFileName[14];
  u08 _Padding0[2];
  u32 FileType;
  u32 CreatorType;
  u16 FinderFlags;
  u08 _Padding1[2];
} win32_find_data;

typedef struct win32_security_attributes
{
    u32 Length;
    u08 _Padding0[4];
    vptr SecurityDescriptor;
    b32 InheritHandle;
    u08 _Padding1[4];
} win32_security_attributes;



#define WIN32__FUNCS \
    IPROC(Kernel32, s32,          CompareFileTime,            win32_file_time *FileTime1, win32_file_time *FileTime2) \
    IPROC(Kernel32, b32,          CopyFileA,                  c08 *ExistingFileName, c08 *NewFileName, b32 FailIfExists) \
    IPROC(Kernel32, win32_handle, CreateFileA,                c08 *FileName, u32 DesiredAccess, u32 ShareMode, win32_security_attributes *SecurityAttributes, u32 CreationDisposition, u32 FlagsAndAttributes, win32_handle TemplateFile) \
    IPROC(Kernel32, win32_module, GetModuleHandleA,           c08 *ModuleName) \
    IPROC(Kernel32, fptr,         GetProcAddress,             win32_module Module, c08 *FunctionName) \
    IPROC(Kernel32, void,         ExitProcess,                u32 ExitCode) \
    IPROC(Kernel32, b32,          FindClose,                  win32_handle FindHandle) \
    IPROC(Kernel32, win32_handle, FindFirstFileA,             c08 *FileName, win32_find_data *FindData) \
    IPROC(Kernel32, b32,          FreeLibrary,                win32_module Module) \
    IPROC(Kernel32, win32_module, LoadLibraryA,               c08 *ModuleName) \
    IPROC(Kernel32, void,         OutputDebugStringA,         c08 *String) \
    IPROC(User32,   win32_window, CreateWindowExA,            u32 StyleEx, c08 *ClassName, c08 *WindowName, u32 Style, s32 x, s32 y, s32 Width, s32 Height, win32_window ParentWindow, win32_menu Menu, win32_instance Instance, vptr Param) \
    IPROC(User32,   s32,          DefWindowProcA,             win32_window Window, u32 Message, s64 WParam, s64 LParam) \
    IPROC(User32,   s64,          DispatchMessageA,           win32_message *Message) \
    IPROC(User32,   b32,          PeekMessageA,               win32_message *Message, win32_window Window, u32 MessageFilterMin, u32 MessageFilterMax, u32 RemoveMessage) \
    IPROC(User32,   win32_atom,   RegisterClassA,             win32_window_class_a *WindowClass) \
    IPROC(User32,   b32,          TranslateMessage,           win32_message *Message) \
    IPROC(User32,   b08,          WaitMessage,                void) \

#define IPROC(Module, ReturnType, Name, ...) \
    typedef ReturnType func_Win32_##Name(__VA_ARGS__);
#define X_MACRO WIN32__FUNCS
#include <macro.h>

typedef struct win32
{
    #define IPROC(Module, ReturnType, Name, ...) \
        func_Win32_##Name *Name;
    #define X_MACRO WIN32__FUNCS
    #include <macro.h>
} win32;
global win32 Win32;

#endif