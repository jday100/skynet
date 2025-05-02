#include "T100DC.h"

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

T100VOID T100DC::DrawCircle(T100Point point, T100UINT radius)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    left    = point.m_x - radius;
    right   = point.m_x + radius;
    top     = point.m_y - radius;
    bottom  = point.m_y + radius;
    Ellipse(m_hdc, left, top, right, bottom);
}

T100VOID T100DC::DrawLine(T100Point start, T100Point end)
{
    MoveToEx(m_hdc, start.m_x, start.m_y, T100NULL);
    LineTo(m_hdc, end.m_x, end.m_y);
}

T100VOID T100DC::DrawRoundedRectangle(T100Point point, T100Size size, T100FLOAT radius)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    left    = point.m_x;
    right   = point.m_x + size.m_x;
    top     = point.m_y;
    bottom  = point.m_y + size.m_y;
    RoundRect(m_hdc, left, top, right, bottom, radius, radius);
}
