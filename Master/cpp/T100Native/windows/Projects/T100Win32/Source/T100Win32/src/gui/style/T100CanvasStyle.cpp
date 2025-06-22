#include "T100CanvasStyle.h"

#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100CanvasStyle::T100CanvasStyle() :
    T100PanelStyle()
{
    //ctor
    ClassType   = T100WINDOW_TYPE_WINDOW;
    WindowLabel = T100WINDOW_TYPE_T100CANVAS;
}

T100CanvasStyle::~T100CanvasStyle()
{
    //dtor
}

}
