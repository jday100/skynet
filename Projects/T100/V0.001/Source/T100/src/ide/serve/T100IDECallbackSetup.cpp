#include "T100IDECallbackSetup.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackSetup::T100IDECallbackSetup()
{
    //ctor
}

T100IDECallbackSetup::~T100IDECallbackSetup()
{
    //dtor
}

T100BOOL T100IDECallbackSetup::frame_menu_config(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackSetup::frame_menu_editor(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackSetup::frame_menu_compiler(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackSetup::frame_menu_debugger(void* d)
{
    return T100FALSE;
}
