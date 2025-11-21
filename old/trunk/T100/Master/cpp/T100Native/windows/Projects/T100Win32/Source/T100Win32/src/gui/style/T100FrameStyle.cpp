#include "gui/T100FrameStyle.h"

#include "gui/common/T100WindowCommon.h"
#include "gui/window/T100SelfLoopWindow.h"

namespace T100WINDOWS{

T100FrameStyle::T100FrameStyle() :
    T100WindowStyle()
{
    //ctor
    Procedure       = DefaultSelfLoopWindowProcedure;
    ClassType       = T100WINDOW_TYPE_WINDOW;

    WindowStyle     = WS_OVERLAPPEDWINDOW;
    WindowLabel     = T100WINDOW_TYPE_T100FRAME;
}

T100FrameStyle::~T100FrameStyle()
{
    //dtor
}

}
