#include "gui/T100DC.h"

T100DC::T100DC(T100Window* parent) :
    T100DCBase(parent)
{
    //ctor
    init();
}

T100DC::~T100DC()
{
    //dtor
    uninit();
}

T100VOID T100DC::init()
{
}

T100VOID T100DC::uninit()
{
}

T100VOID T100DC::DrawCircle(T100Point point, T100WORD radius)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    left    = point.x - radius;
    right   = point.x + radius;
    top     = point.y - radius;
    bottom  = point.y + radius;
    Ellipse(m_hdc, left, top, right, bottom);
}

T100VOID T100DC::DrawLine(T100Point start, T100Point end)
{
    MoveToEx(m_hdc, start.x, start.y, T100NULL);
    LineTo(m_hdc, end.x, end.y);
}

T100VOID T100DC::DrawRoundedRectangle(T100Point point, T100Size size, T100FLOAT radius)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    left    = point.x;
    right   = point.x + size.width;
    top     = point.y;
    bottom  = point.y + size.height;
    RoundRect(m_hdc, left, top, right, bottom, radius, radius);
}
