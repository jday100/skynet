#include "T100SimpleStyle.h"

T100SimpleStyle::T100SimpleStyle() :
    T100WindowStyle()
{
    //ctor
    WindowStyle     = WS_OVERLAPPEDWINDOW;
    ExStyle         = WS_EX_TOOLWINDOW;
}

T100SimpleStyle::~T100SimpleStyle()
{
    //dtor
}
