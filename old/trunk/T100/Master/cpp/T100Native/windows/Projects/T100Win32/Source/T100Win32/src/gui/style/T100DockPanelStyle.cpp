#include "gui/T100DockPanelStyle.h"

#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

T100DockPanelStyle::T100DockPanelStyle() :
    T100WindowStyle()
{
    //ctor
    WindowStyle     = WS_CHILD | WS_BORDER | WS_CAPTION | WS_SYSMENU;
    ExStyle         = WS_EX_TOOLWINDOW;

    ClassType       = T100WINDOW_TYPE_T100DOCK_WINDOW;
    WindowLabel     = T100WINDOW_TYPE_T100PANE;
}

T100DockPanelStyle::~T100DockPanelStyle()
{
    //dtor
}

T100PanelStyle T100DockPanelStyle::ToPanelStyle()
{
    T100PanelStyle      style(*this);

    return style;
}

T100CanvasStyle T100DockPanelStyle::ToCanvasStyle()
{
    T100CanvasStyle     style(*this);

    return style;
}

}
