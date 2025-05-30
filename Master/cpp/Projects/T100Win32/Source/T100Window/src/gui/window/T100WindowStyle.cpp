#include "gui/window/T100WindowStyle.h"

#include "gui/common/T100WindowCommon.h"
#include "gui/window/T100SelfLoopWindow.h"

T100WindowStyle::T100WindowStyle()
{
    //ctor
    //Procedure       = DefWindowProc;
    Procedure       = DefaultSelfLoopWindowProcedure;
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
