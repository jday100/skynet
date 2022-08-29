#include "T100VDiskConsole.h"


T100VDiskConsole::T100VDiskConsole()
{
    //ctor
    create();
}

T100VDiskConsole::~T100VDiskConsole()
{
    //dtor
    destroy();
}

T100VOID T100VDiskConsole::create()
{
    T100Log::trace(T100VDISK_HINT_CONSOLE_START);
}

T100VOID T100VDiskConsole::destroy()
{
    T100Log::trace(T100VDISK_HINT_CONSOLE_STOP);
}
