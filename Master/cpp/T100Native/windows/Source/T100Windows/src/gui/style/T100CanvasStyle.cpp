#include "gui/T100CanvasStyle.h"

#include "gui/T100DockPanelStyle.h"
#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100CanvasStyle::T100CanvasStyle() :
    T100PanelStyle()
{
    //ctor
    ClassType   = T100WINDOW_TYPE_WINDOW;
    WindowLabel = T100WINDOW_TYPE_T100CANVAS;
}

T100CanvasStyle::T100CanvasStyle(const T100DockPanelStyle& style) :
    T100PanelStyle()
{
    //ctor
    Procedure   = style.Procedure;
    ClassType   = style.ClassType;
    ClassStyle  = style.ClassStyle;

    Icon        = style.Icon;
    IconSmall   = style.IconSmall;
    Cursor      = style.Cursor;
    Background  = style.Background;

    WindowStyle = style.WindowStyle;
    ExStyle     = style.ExStyle;
    X           = style.X;
    Y           = style.Y;
    Width       = style.Width;
    Height      = style.Height;

    Menu        = style.Menu;

    ClassType   = T100WINDOW_TYPE_WINDOW;
    WindowLabel = T100WINDOW_TYPE_T100CANVAS;
}

T100CanvasStyle::~T100CanvasStyle()
{
    //dtor
}

}
