#include "T100ButtonStyle.h"

#include "gui/common/T100WindowCommon.h"

T100ButtonStyle::T100ButtonStyle() :
    T100WindowStyle()
{
    //ctor
    WindowStyle     = WS_CHILD | BS_PUSHBUTTON | BS_DEFPUSHBUTTON;
    ExStyle         = 0;

    WindowLabel     = T100WINDOW_TYPE_T100BUTTON;
    ClassType       = T100WINDOW_TYPE_BUTTON;

    Width           = 50;
    Height          = 30;
}

T100ButtonStyle::~T100ButtonStyle()
{
    //dtor
}
