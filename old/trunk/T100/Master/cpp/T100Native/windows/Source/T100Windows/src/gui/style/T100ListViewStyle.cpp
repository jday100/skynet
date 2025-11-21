#include "gui/T100ListViewStyle.h"

#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100ListViewStyle::T100ListViewStyle() :
    T100WindowStyle()
{
    //ctor
    ClassType   = T100WINDOW_TYPE_LISTVIEW;
    WindowLabel = T100WINDOW_TYPE_T100LISTVIEW;
}

T100ListViewStyle::~T100ListViewStyle()
{
    //dtor
}

}
