#include "T100IDECallbackBuild.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackBuild::T100IDECallbackBuild()
{
    //ctor
}

T100IDECallbackBuild::~T100IDECallbackBuild()
{
    //dtor
}

T100BOOL T100IDECallbackBuild::frame_menu_build(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackBuild::frame_menu_run(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackBuild::frame_menu_clean(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackBuild::frame_menu_stop(void* d)
{
    return T100FALSE;
}
