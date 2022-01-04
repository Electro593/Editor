/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
**                                                                         **
**  Author: Aria Seiler                                                    **
**                                                                         **
**  This program is in the public domain. There is no implied warranty,    **
**  so use it at your own risk.                                            **
**                                                                         **
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef INCLUDE_HEADER

#define BLACK_BRUSH 4
#define CW_USEDEFAULT ((int)0x80000000)
#define DSSCL_PRIORITY  0x00000002
#define DSSCL_EXCLUSIVE 0x00000003
#define IDC_ARROW       ((c08*)((u64)((u16)(32512))))
#define IDI_APPLICATION ((c08*)((u64)((u16)(32512))))
#define PM_REMOVE 0x1
#define SC_KEYMENU 0xF100
#define WM_DESTROY        0x0002
#define WM_SETFOCUS       0x0007
#define WM_KILLFOCUS      0x0008
#define WM_CLOSE          0x0010
#define WM_QUIT           0x0012
#define WM_KEYDOWN        0x0100
#define WM_KEYUP          0x0101
#define WM_SYSKEYDOWN     0x0104
#define WM_SYSKEYUP       0x0105
#define WM_QUIT           0x0012
#define WM_CREATE_WINDOW  0xFFFF
#define WS_OVERLAPPED 0x00000000L
#define WS_SYSMENU    0x00080000L
#define WS_CAPTION    0x00C00000L
#define WS_VISIBLE    0x10000000L
#define MAX_PATH 260
#define INVALID_HANDLE_VALUE ((vptr)-1)
#define SUCCEEDED(Result) (((s32)(Result)) >= 0)


typedef u16          win32_atom;
typedef vptr         win32_handle;
typedef win32_handle win32_brush;
typedef win32_handle win32_cursor;
typedef win32_handle win32_gdi_object;
typedef win32_handle win32_icon;
typedef win32_handle win32_instance;
typedef win32_handle win32_menu;
typedef win32_handle win32_module;
typedef win32_handle win32_window;



typedef s64 (__stdcall *win32_window_callback)(win32_window Window, u32 Message, s64 WParam, s64 LParam);
typedef u32 (__stdcall *win32_thread_callback)(vptr Parameter);



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

typedef struct win32_guid
{
    u32 Data1;
    u16 Data2;
    u16 Data3;
    u08 Data4[8];
} win32_guid;

typedef struct win32_dsound_capabilities
{
    u32 Size;
    u32 Flags;
    u32 MinSecondarySampleRate;
    u32 MaxSecondarySampleRate;
    u32 PrimaryBuffers;
    u32 MaxHwMixingAllBuffers;
    u32 MaxHwMixingStaticBuffers;
    u32 MaxHwMixingStreamingBuffers;
    u32 FreeHwMixingAllBuffers;
    u32 FreeHwMixingStaticBuffers;
    u32 FreeHwMixingStreamingBuffers;
    u32 MaxHw3DAllBuffers;
    u32 MaxHw3DStaticBuffers;
    u32 MaxHw3DStreamingBuffers;
    u32 FreeHw3DAllBuffers;
    u32 FreeHw3DStaticBuffers;
    u32 FreeHw3DStreamingBuffers;
    u32 TotalHwMemBytes;
    u32 FreeHwMemBytes;
    u32 MaxContigFreeHwMemBytes;
    u32 UnlockTransferRateHwBuffers;
    u32 PlayCpuOverheadSwBuffers;
    u32 Reserved1;
    u32 Reserved2;
} win32_dsound_capabilities;

typedef struct win32_wave_format_ex
{
    #define WAVE_FORMAT_PCM 1
    u16 FormatTag;
    u16 ChannelCount;
    u32 SamplesPerSecond;
    u32 AverageBytesPerSecond;
    u16 BlockAlign;
    u16 BitsPerSample;
    u16 Size;
    u08 _Padding0[2];
} win32_wave_format_ex;

typedef struct win32_dsound_buffer_description
{
    u32 Size;
    u32 Flags;
    u32 BufferBytes;
    u32 Reserved;
    win32_wave_format_ex *WaveFormat;
    win32_guid Algorithm3D;
} win32_dsound_buffer_description;

typedef struct win32_dsound_buffer_capabilities
{
    u32 Size;
    enum win32_dsound_buffer_capability_flags
    {
        DSoundBufferCapabilities_PrimaryBuffer               = 0x00000001,
        DSoundBufferCapabilities_Static                      = 0x00000002,
        DSoundBufferCapabilities_LOCHardware                 = 0x00000004,
        DSoundBufferCapabilities_LOCSoftware                 = 0x00000008,
        DSoundBufferCapabilities_Control3D                   = 0x00000010,
        DSoundBufferCapabilities_ControlFrequency            = 0x00000020,
        DSoundBufferCapabilities_ControlPan                  = 0x00000040,
        DSoundBufferCapabilities_ControlVolume               = 0x00000080,
        DSoundBufferCapabilities_ControlPositionNotification = 0x00000100,
        DSoundBufferCapabilities_ControlEffects              = 0x00000200,
        DSoundBufferCapabilities_StickyFocus                 = 0x00004000,
        DSoundBufferCapabilities_GlobalFocus                 = 0x00008000,
        DSoundBufferCapabilities_GetCurrentPosition2         = 0x00010000,
        DSoundBufferCapabilities_Mute3DAtMaxDistance         = 0x00020000,
        DSoundBufferCapabilities_LOCDefer                    = 0x00040000,
        DSoundBufferCapabilities_TruePosition                = 0x00080000,
    } Flags;
    u32 BufferBytes;
    u32 UnlockTransferRate;
    u32 PlayCpuOverhead;
} win32_dsound_buffer_capabilities;

typedef struct win32_unknown
{
    struct win32_unknown_vtable
    {
        s32 (__stdcall *QueryInterface) (struct win32_unknown *This, win32_guid *RIID, vptr *UnknownObject);
        u32 (__stdcall *AddRef)         (struct win32_unknown *This);
        u32 (__stdcall *Release)        (struct win32_unknown *This);
    } *VTable;
} win32_unknown;

typedef struct win32_dsound win32_dsound;
typedef struct win32_dsound_buffer
{
    struct win32_dsound_buffer_vtable
    {
        s32 (__stdcall *QueryInterface)     (struct win32_dsound_buffer *This, win32_guid *RIID, vptr *UnknownObject);
        u32 (__stdcall *AddRef)             (struct win32_dsound_buffer *This);
        u32 (__stdcall *Release)            (struct win32_dsound_buffer *This);
        s32 (__stdcall *GetCaps)            (struct win32_dsound_buffer *This, win32_dsound_buffer_capabilities *BufferCapabilities);
        s32 (__stdcall *GetCurrentPosition) (struct win32_dsound_buffer *This, u32 *CurrentPlayCursor, u32 *wCurrentWriteCursor);
        s32 (__stdcall *GetFormat)          (struct win32_dsound_buffer *This, win32_wave_format_ex *Format, u32 SizeAllocated, u32 *SizeWritten);
        s32 (__stdcall *GetVolume)          (struct win32_dsound_buffer *This, s32 *Volume);
        s32 (__stdcall *GetPan)             (struct win32_dsound_buffer *This, s32 *Pan);
        s32 (__stdcall *GetFrequency)       (struct win32_dsound_buffer *This, u32 *Frequency);
        s32 (__stdcall *GetStatus)          (struct win32_dsound_buffer *This, u32 *Status);
        s32 (__stdcall *Initialize)         (struct win32_dsound_buffer *This, win32_dsound *DirectSound, win32_dsound_buffer_description *BufferDescription);
        s32 (__stdcall *Lock)               (struct win32_dsound_buffer *This, u32 Offset, u32 Bytes, vptr *AudioPtr1, u32 *AudioBytes1, vptr *AudioPtr2, u32 *AudioBytes2, u32 Flags);
        s32 (__stdcall *Play)               (struct win32_dsound_buffer *This, u32 Reserved1, u32 Priority, u32 Flags);
        s32 (__stdcall *SetCurrentPosition) (struct win32_dsound_buffer *This, u32 NewPosition);
        s32 (__stdcall *SetFormat)          (struct win32_dsound_buffer *This, win32_wave_format_ex *Format);
        s32 (__stdcall *SetVolume)          (struct win32_dsound_buffer *This, s32 Volume);
        s32 (__stdcall *SetPan)             (struct win32_dsound_buffer *This, s32 Pan);
        s32 (__stdcall *SetFrequency)       (struct win32_dsound_buffer *This, u32 Frequency);
        s32 (__stdcall *Stop)               (struct win32_dsound_buffer *This);
        s32 (__stdcall *Unlock)             (struct win32_dsound_buffer *This, vptr AudioPtr1, u32 AudioBytes1, vptr AudioPtr2, u32 AudioBytes2);
        s32 (__stdcall *Restore)            (struct win32_dsound_buffer *This);
    } *VTable;
} win32_dsound_buffer;

struct win32_dsound
{
    struct win32_dsound_vtable
    {
        s32 (__stdcall *QueryInterface)      (win32_dsound *This, win32_guid *RIID, vptr *UnknownObject);
        u32 (__stdcall *AddRef)              (win32_dsound *This);
        u32 (__stdcall *Release)             (win32_dsound *This);
        s32 (__stdcall *CreateSoundBuffer)   (win32_dsound *This, win32_dsound_buffer_description *BufferDescription, win32_dsound_buffer **Buffer, win32_unknown *Unknown);
        s32 (__stdcall *GetCaps)             (win32_dsound *This, win32_dsound_capabilities *Capabilities);
        s32 (__stdcall *DuplicateSoundBuffer)(win32_dsound *This, win32_dsound_buffer *OriginalBuffer, win32_dsound_buffer **DuplicateBuffer);
        s32 (__stdcall *SetCooperativeLevel) (win32_dsound *This, win32_window Window, u32 Level);
        s32 (__stdcall *Compact)             (win32_dsound *This);
        s32 (__stdcall *GetSpeakerConfig)    (win32_dsound *This, u32 *SpeakerConfig);
        s32 (__stdcall *SetSpeakerConfig)    (win32_dsound *This, u32 SpeakerConfig);
        s32 (__stdcall *Initialize)          (win32_dsound *This, win32_guid GuidDevice);
    } *VTable;
};


#define WIN32__FUNCS \
    IPROC(Gdi32,    win32_gdi_object, GetStockObject,     s32 I) \
    IPROC(DSound,   s32,              DirectSoundCreate,  win32_guid *GUIDDevice, win32_dsound **DSound, win32_unknown *Unknown) \
    IPROC(Kernel32, s32,              CompareFileTime,    win32_file_time *FileTime1, win32_file_time *FileTime2) \
    IPROC(Kernel32, b32,              CopyFileA,          c08 *ExistingFileName, c08 *NewFileName, b32 FailIfExists) \
    IPROC(Kernel32, win32_handle,     CreateFileA,        c08 *FileName, u32 DesiredAccess, u32 ShareMode, win32_security_attributes *SecurityAttributes, u32 CreationDisposition, u32 FlagsAndAttributes, win32_handle TemplateFile) \
    IPROC(Kernel32, win32_handle,     CreateThread,       win32_security_attributes *ThreadAttributes, u64 StackSize, win32_thread_callback *StartAddress, vptr Parameter, u32 CreationFlags, u32 *ThreadId) \
    IPROC(Kernel32, u32,              GetLastError,       void) \
    IPROC(Kernel32, win32_module,     GetModuleHandleA,   c08 *ModuleName) \
    IPROC(Kernel32, fptr,             GetProcAddress,     win32_module Module, c08 *FunctionName) \
    IPROC(Kernel32, void,             ExitProcess,        u32 ExitCode) \
    IPROC(Kernel32, b32,              FindClose,          win32_handle FindHandle) \
    IPROC(Kernel32, win32_handle,     FindFirstFileA,     c08 *FileName, win32_find_data *FindData) \
    IPROC(Kernel32, b32,              FreeLibrary,        win32_module Module) \
    IPROC(Kernel32, win32_module,     LoadLibraryA,       c08 *ModuleName) \
    IPROC(Kernel32, void,             OutputDebugStringA, c08 *String) \
    IPROC(User32,   win32_window,     CreateWindowExA,    u32 StyleEx, c08 *ClassName, c08 *WindowName, u32 Style, s32 x, s32 y, s32 Width, s32 Height, win32_window ParentWindow, win32_menu Menu, win32_instance Instance, vptr Param) \
    IPROC(User32,   s32,              DefWindowProcA,     win32_window Window, u32 Message, s64 WParam, s64 LParam) \
    IPROC(User32,   s64,              DispatchMessageA,   win32_message *Message) \
    IPROC(User32,   b32,              GetMessageA,        win32_message *Msg, win32_window Window, u32 MessageFilterMin, u32 MessageFilterMax) \
    IPROC(User32,   win32_cursor,     LoadCursorA,        win32_instance Instance, c08 *CursorName) \
    IPROC(User32,   win32_icon,       LoadIconA,          win32_instance Instance, c08 *IconName) \
    IPROC(User32,   b32,              PeekMessageA,       win32_message *Message, win32_window Window, u32 MessageFilterMin, u32 MessageFilterMax, u32 RemoveMessage) \
    IPROC(User32,   b32,              PostThreadMessageA, u32 Thread, u32 Message, s64 WParam, s64 LParam) \
    IPROC(User32,   win32_atom,       RegisterClassA,     win32_window_class_a *WindowClass) \
    IPROC(User32,   s64,              SendMessageA,       win32_window Window, u32 Message, s64 WParam, s64 LParam) \
    IPROC(User32,   b32,              TranslateMessage,   win32_message *Message) \
    IPROC(User32,   b08,              WaitMessage,        void) \

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
global win32 *Win32;

#endif