#include "T100Brush.h"

namespace T100WINDOWS{

T100Brush::T100Brush(const T100Colour4& colour, T100BRUSH_TYPE type) :
    T100Class(),
    m_colour4(colour),
    m_type(type)
{
    //ctor
    init();
}

T100Brush::T100Brush(T100COLOUR4_TYPE colour, T100BRUSH_TYPE type) :
    T100Class(),
    m_type(type)
{
    //ctor
    m_colour4.SetColour4(colour);
    init();
}

T100Brush::~T100Brush()
{
    //dtor
    uninit();
}

T100VOID T100Brush::init()
{
    if(m_hbrush){

    }

    LOGBRUSH        brush;

    brush.lbColor   = m_colour4.GetColour();
    brush.lbStyle   = m_type;

    m_hbrush    = CreateBrushIndirect(&brush);
}

T100VOID T100Brush::uninit()
{

}

HBRUSH T100Brush::GetHBRUSH()
{
    return m_hbrush;
}

T100VOID T100Brush::SetColour4(const T100Colour4& colour)
{
    m_colour4   = colour;
    init();
}

const T100Colour4& T100Brush::GetColour4()
{
    return m_colour4;
}

T100VOID T100Brush::SetType(T100BRUSH_TYPE type)
{
    m_type      = type;
    init();
}

T100BRUSH_TYPE T100Brush::GetType()
{
    return m_type;
}

}
