#include "T100PanelStyle.h"

#include "gui/T100DockPanelStyle.h"
#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100PanelStyle::T100PanelStyle() :
    T100WindowStyle()
{
    //ctor
}

T100PanelStyle::T100PanelStyle(const T100DockPanelStyle& style) :
    T100WindowStyle()
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
}

T100PanelStyle::~T100PanelStyle()
{
    //dtor
}

}
