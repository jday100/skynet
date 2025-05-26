#include "gui/base/T100Brush.h"

T100Brush::T100Brush(T100Colour colour, T100BRUSH_TYPE type) :
    T100Class()
{
    //ctor
}

T100Brush::T100Brush(T100COLOUR_TYPE colour, T100BRUSH_TYPE brush) :
    T100Class()
{
    //ctor
}

T100Brush::~T100Brush()
{
    //dtor
}

HBRUSH T100Brush::GetHBRUSH()
{
    return m_brush;
}

T100VOID T100Brush::SetColour(T100Colour colour)
{
    m_colour    = colour;
}

T100Colour& T100Brush::GetColour()
{
    return m_colour;
}

T100VOID T100Brush::SetType(T100BRUSH_TYPE type)
{
    m_type      = type;
}

T100BRUSH_TYPE& T100Brush::GetType()
{
    return m_type;
}
