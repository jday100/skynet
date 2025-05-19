#include "T100PanelStyle.h"

#include "gui/T100Win32Common.h"

T100PanelStyle::T100PanelStyle() :
    T100WindowStyle()
{
    //ctor
    WindowStyle     = WS_CHILD | WS_BORDER;
    ExStyle         = 0;

    WindowLabel     = T100WINDOW_TYPE_T100PANEL;
    ClassType       = T100WINDOW_TYPE_T100PANEL;

    Width           = 800;
    Height          = 600;
}

T100PanelStyle::~T100PanelStyle()
{
    //dtor
}
