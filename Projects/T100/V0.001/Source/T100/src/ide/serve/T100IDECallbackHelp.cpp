#include "T100IDECallbackHelp.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDECallbackHelp::T100IDECallbackHelp()
{
    //ctor
}

T100IDECallbackHelp::~T100IDECallbackHelp()
{
    //dtor
}

T100BOOL T100IDECallbackHelp::frame_menu_about(void* d)
{
    return T100FALSE;
}
