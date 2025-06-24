#include "T100DC.h"

namespace T100WINDOWS{

T100DC::T100DC(T100Window* window) :
    T100DCBase(window)
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

T100VOID T100DC::Clear()
{

}

T100VOID T100DC::DrawArc(const T100Point& a, const T100Point& b, const T100Point& c, const T100Point& d)
{
    Arc(m_hdc, a.X, a.Y, b.X, b.Y, c.X, c.Y, d.X, d.Y);
}

T100VOID T100DC::DrawBitmap()
{

}

T100VOID T100DC::DrawCircle(const T100Point& point, T100UINT radius)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    left    = point.X - radius;
    right   = point.X + radius;
    top     = point.Y - radius;
    bottom  = point.Y + radius;
    Ellipse(m_hdc, left, top, right, bottom);
}

T100VOID T100DC::DrawEllipse(const T100Point& point, const T100Size& size)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    T100INT     hx;
    T100INT     hy;

    hx  = size.Width / 2;
    hy  = size.Height / 2;

    left    = point.X - hx;
    right   = point.X + hx;
    top     = point.Y - hy;
    bottom  = point.Y + hy;

    Ellipse(m_hdc, left, top, right, bottom);
}

T100VOID T100DC::DrawEllipticArc()
{

}

T100VOID T100DC::DrawIcon()
{

}

T100VOID T100DC::DrawLabel()
{

}

T100VOID T100DC::DrawLine(const T100Point& head, const T100Point& tail)
{
    MoveToEx(m_hdc, head.X, head.Y, T100NULL);
    LineTo(m_hdc, tail.X, tail.Y);
}

T100VOID T100DC::DrawLines()
{

}

T100VOID T100DC::DrawPoint(const T100Point& point)
{
    COLORREF        colour;

    SetPixel(m_hdc, point.X, point.Y, colour);
}

T100VOID T100DC::DrawPolygon(const T100Point& point, T100INT value)
{
    POINT   temp    = {point.X, point.Y};

    Polygon(m_hdc, &temp, value);
}

T100VOID T100DC::DrawPolyPolygon()
{

}

T100VOID T100DC::DrawRectangle(const T100Point& point, const T100Size& size)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    T100INT     hx;
    T100INT     hy;

    hx  = size.Width / 2;
    hy  = size.Height / 2;

    left    = point.X - hx;
    right   = point.X + hx;
    top     = point.Y - hy;
    bottom  = point.Y + hy;

    Rectangle(m_hdc, left, top, right, bottom);
}

T100VOID T100DC::DrawRotatedText()
{

}

T100VOID T100DC::DrawRoundedRectangle(const T100Point& point, const T100Size& size, T100FLOAT radius)
{
    T100INT     left;
    T100INT     right;
    T100INT     top;
    T100INT     bottom;

    left    = point.X;
    right   = point.X + size.Width;
    top     = point.Y;
    bottom  = point.Y + size.Height;

    RoundRect(m_hdc, left, top, right, bottom, radius, radius);
}

T100VOID T100DC::DrawSpline()
{

}

T100VOID T100DC::DrawText(const T100WSTRING& value, T100INT x, T100INT y)
{
    RECT        rect;

    rect.left   = x;
    rect.top    = y;

    rect.right  = x + m_font.GetWidth() * value.size();
    rect.bottom = y + m_font.GetHeight();

    ::DrawTextW(m_hdc, value.c_str(), value.size(), &rect, DT_LEFT);
}

}
