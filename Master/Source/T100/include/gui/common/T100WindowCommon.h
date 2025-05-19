#ifndef T100WINDOWCOMMON_H
#define T100WINDOWCOMMON_H

typedef enum T100ORIENTATION_TYPE{
    T100HORIZONTAL,
    T100VERTICAL,
    T100BOTH
}T100ORIENTATION_TYPE;

typedef enum T100LINE_TYPE{
    T100LINE_NONE           = PS_NULL,
    T100LINE_SOLID          = PS_SOLID,
    T100LINE_DASH           = PS_DASH,
    T100LINE_DOT            = PS_DOT,
    T100LINE_DASHDOT        = PS_DASHDOT,
    T100LINE_DASHDOTDOT     = PS_DASHDOTDOT,
    T100LINE_INSIDEFRAME    = PS_INSIDEFRAME,
    T100LINE_USERSTYLE      = PS_USERSTYLE,
    T100LINE_ALTERNATE      = PS_ALTERNATE
}T100LINE_TYPE;

typedef enum T100BRUSH_TYPE{
    T100BRUSH_TYPE_SOLID
}T100BRUSH_TYPE;

#define     T100WINDOW_TYPE_T100WINDOW                  L"T100Window"
#define     T100WINDOW_TYPE_T100SELFLOOP_WINDOW         L"T100SelfLoopWindow"

#define     T100WINDOW_TYPE_WINDOW                      L"window"
#define     T100WINDOW_TYPE_BUTTON                      L"button"
#define     T100WINDOW_TYPE EDIT                        L"edit"

#define     T100WINDOW_TYPE_T100WINDOW                  L"T100Window"
#define     T100WINDOW_TYPE_T100SELFLOOP_WINDOW         L"T100SelfLoopWindow"
#define     T100WINDOW_TYPE_T100PANEL                   L"T100Panel"
#define     T100WINDOW_TYPE_T100FRAME                   L"T100Frame"
#define     T100WINDOW_TYPE_T100BUTTON                  L"T100Button"
#define     T100WINDOW_TYPE_T100LISTVIEW                L"T100ListView"

#endif // T100WINDOWCOMMON_H
