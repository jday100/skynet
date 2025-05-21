#include "T100FrameStyle.h"

#include "gui/T100Win32Common.h"

T100FrameStyle::T100FrameStyle() :
    T100WindowStyle()
{
    //ctor
    WindowStyle     = WS_OVERLAPPEDWINDOW;
    ExStyle         = 0;

    WindowLabel     = T100WINDOW_TYPE_T100FRAME;
    ClassType       = T100WINDOW_TYPE_T100SELFLOOP_WINDOW;
    X               = CW_USEDEFAULT;
    Y               = CW_USEDEFAULT;
    Width           = CW_USEDEFAULT;
    Height          = CW_USEDEFAULT;
}

T100FrameStyle::~T100FrameStyle()
{
    //dtor
}
