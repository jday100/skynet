#include "T100WindowStyle.h"

#include "gui/T100Win32Common.h"

T100WindowStyle::T100WindowStyle()
{
    //ctor
    ClassType       = T100WINDOW_TYPE_T100WINDOW;
    ClassStyle      = CS_DBLCLKS;

    Icon            = LoadIcon (NULL, IDI_APPLICATION);
    IconSmall       = LoadIcon (NULL, IDI_APPLICATION);
    Cursor          = LoadCursor (NULL, IDC_ARROW);
    Background      = (HBRUSH) COLOR_BACKGROUND;

    WindowLabel     = T100WINDOW_TYPE_T100WINDOW;
    WindowStyle     = WS_CHILD;
    ExStyle         = 0;
    X               = CW_USEDEFAULT;
    Y               = CW_USEDEFAULT;
    Width           = CW_USEDEFAULT;
    Height          = CW_USEDEFAULT;

    Menu            = 0;
}

T100WindowStyle::~T100WindowStyle()
{
    //dtor
}
