#include "gui/T100ButtonStyle.h"

#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100ButtonStyle::T100ButtonStyle() :
    T100WindowStyle()
{
    //ctor
    ClassType   = T100WINDOW_TYPE_BUTTON;
    WindowLabel = T100WINDOW_TYPE_BUTTON;

    Width       = 90;
    Height      = 30;
}

T100ButtonStyle::~T100ButtonStyle()
{
    //dtor
}

}
