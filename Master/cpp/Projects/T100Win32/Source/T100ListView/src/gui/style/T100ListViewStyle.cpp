#include "T100ListViewStyle.h"

#include "gui/common/T100WindowCommon.h"

T100ListViewStyle::T100ListViewStyle() :
    T100WindowStyle()
{
    //ctor
    WindowStyle     = WS_CHILD | WS_BORDER;
    ExStyle         = 0;

    WindowLabel     = T100WINDOW_TYPE_T100LISTVIEW;
    ClassType       = T100WINDOW_TYPE_LISTVIEW;

    Width           = 800;
    Height          = 600;
}

T100ListViewStyle::~T100ListViewStyle()
{
    //dtor
}
