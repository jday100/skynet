#include "gui/style/T100DockPanelStyle.h"

#include "gui/common/T100WindowCommon.h"

T100DockPanelStyle::T100DockPanelStyle() :
    T100PanelStyle()
{
    //ctor
    WindowStyle     = WS_CHILD | WS_BORDER | WS_CAPTION | WS_SYSMENU;
    ExStyle         = WS_EX_TOOLWINDOW;

    WindowLabel     = T100WINDOW_TYPE_T100PANEL;
    ClassType       = L"T100DockWindow";
}

T100DockPanelStyle::~T100DockPanelStyle()
{
    //dtor
}
