#include "T100QU32Callback.h"


T100Callback        T100QU32Callback::m_start;
T100Callback        T100QU32Callback::m_stop;
T100Callback        T100QU32Callback::m_done;

T100Callback        T100QU32Callback::m_debug;
T100Callback        T100QU32Callback::m_debug_rom;
T100Callback        T100QU32Callback::m_debug_ram;

T100Callback        T100QU32Callback::m_debug_device;
T100Callback        T100QU32Callback::m_debug_block;
T100Callback        T100QU32Callback::m_debug_page;


T100QU32Callback::T100QU32Callback()
{
    //ctor
}

T100QU32Callback::~T100QU32Callback()
{
    //dtor
}

T100BOOL T100QU32Callback::bindStart(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_start.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindStart(T100CALLBACK_HANDLE handle)
{
    return m_start.clear();
}

T100BOOL T100QU32Callback::bindStop(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_stop.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindStop(T100CALLBACK_HANDLE handle)
{
    return m_stop.clear();
}

T100BOOL T100QU32Callback::bindDone(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_done.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindDone(T100CALLBACK_HANDLE handle)
{
    return m_done.clear();
}

T100BOOL T100QU32Callback::bindHangup()
{
    return T100FALSE;
}

T100BOOL T100QU32Callback::bindAwaken()
{
    return T100FALSE;
}

T100BOOL T100QU32Callback::bindStep()
{
    return T100FALSE;
}

T100BOOL T100QU32Callback::bindDebug(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_debug.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindDebug(T100CALLBACK_HANDLE handle)
{
    return m_debug.clear();
}

T100BOOL T100QU32Callback::bindDebugRom(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_debug_rom.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindDebugRom(T100CALLBACK_HANDLE handle)
{
    return m_debug_rom.clear();
}

T100BOOL T100QU32Callback::bindDebugRam(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_debug_ram.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindDebugRam(T100CALLBACK_HANDLE handle)
{
    return m_debug_ram.clear();
}

T100BOOL T100QU32Callback::bindDebugDevice(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_debug_device.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindDebugDevice(T100CALLBACK_HANDLE handle)
{
    return m_debug_device.clear();
}

T100BOOL T100QU32Callback::bindDebugBlock(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_debug_block.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindDebugBlock(T100CALLBACK_HANDLE handle)
{
    return m_debug_block.clear();
}

T100BOOL T100QU32Callback::bindDebugPage(T100CALLBACK_HANDLE handle, void* v, void* s, void* d)
{
    return m_debug_page.add(handle, v, s, d);
    return T100FALSE;
}

T100BOOL T100QU32Callback::unbindDebugPage(T100CALLBACK_HANDLE handle)
{
    return m_debug_page.clear();
}

////

T100BOOL T100QU32Callback::callStart()
{
    return m_start.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callStop()
{
    return m_stop.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callDone()
{
    return m_done.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callHangup()
{
    return T100FALSE;
}

T100BOOL T100QU32Callback::callAwaken()
{
    return T100FALSE;
}

T100BOOL T100QU32Callback::callStep()
{
    return T100FALSE;
}

T100BOOL T100QU32Callback::callDebug()
{
    return m_debug.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callDebugRom()
{
    return m_debug_rom.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callDebugRam()
{
    return m_debug_ram.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callDebugDevice()
{
    return m_debug_device.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callDebugBlock()
{
    return m_debug_block.run(T100NULL);
    return T100FALSE;
}

T100BOOL T100QU32Callback::callDebugPage()
{
    return m_debug_page.run(T100NULL);
    return T100FALSE;
}

