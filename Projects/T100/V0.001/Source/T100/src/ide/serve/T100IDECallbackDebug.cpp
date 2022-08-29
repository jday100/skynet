#include "T100IDECallbackDebug.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackDebug::T100IDECallbackDebug()
{
    //ctor
}

T100IDECallbackDebug::~T100IDECallbackDebug()
{
    //dtor
}

T100BOOL T100IDECallbackDebug::frame_menu_step(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackDebug::frame_menu_pause(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackDebug::frame_menu_run(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackDebug::frame_menu_stop(void* d)
{
    return T100FALSE;
}
