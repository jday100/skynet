#include "T100Brush.h"

T100Brush::T100Brush()
{
    //ctor
}

T100Brush::T100Brush(T100Colour colour, T100BRUSH_TYPE type)
{
    //ctor
}

T100Brush::T100Brush(T100COLOUR_TYPE colour, T100BRUSH_TYPE type)
{
    //ctor
    //tagLOGBRUSH
    //m_brush     = CreateBrushIndirect(RGB(0, 0, 0));
}

T100Brush::~T100Brush()
{
    //dtor
}

HBRUSH T100Brush::GetHBRUSH()
{
    return m_brush;
}
