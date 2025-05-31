#include "gui/base/T100Brush.h"

T100Brush::T100Brush(T100Colour colour, T100BRUSH_TYPE type) :
    T100Class(),
    m_colour(colour),
    m_type(type)
{
    //ctor
    Init();
}

T100Brush::T100Brush(T100COLOUR_TYPE colour, T100BRUSH_TYPE type) :
    T100Class(),
    m_type(type)
{
    //ctor
    Init();
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
    Init();
}

T100Colour& T100Brush::GetColour()
{
    return m_colour;
}

T100VOID T100Brush::SetType(T100BRUSH_TYPE type)
{
    m_type      = type;
    Init();
}

T100BRUSH_TYPE& T100Brush::GetType()
{
    return m_type;
}

T100VOID T100Brush::Init()
{
    LOGBRUSH        brush;

    brush.lbColor   = m_colour.GetColour();
    brush.lbStyle   = m_type;

    m_brush = CreateBrushIndirect(&brush);
}
