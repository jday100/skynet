#include "gui/T100TextCtrlStyle.h"

#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100TextCtrlStyle::T100TextCtrlStyle() :
    T100WindowStyle()
{
    //ctor
    ClassType       = T100WINDOW_TYPE_EDIT;
    WindowStyle     = WS_CHILD | WS_VSCROLL | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL;
    WindowLabel     = T100WINDOW_TYPE_T100TEXTCTRL;
}

T100TextCtrlStyle::~T100TextCtrlStyle()
{
    //dtor
}

}
