#include "T100FrameStyle.h"

#include "gui/common/T100WindowCommon.h"

T100FrameStyle::T100FrameStyle() :
    T100WindowStyle()
{
    //ctor

    WindowStyle     = WS_OVERLAPPEDWINDOW;
    WindowLabel     = T100WINDOW_TYPE_T100FRAME;
}

T100FrameStyle::~T100FrameStyle()
{
    //dtor
}
