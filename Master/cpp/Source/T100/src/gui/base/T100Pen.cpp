#include "gui/base/T100Pen.h"

T100Pen::T100Pen(T100Colour colour, T100WORD width, T100LINE_TYPE type)
{
    //ctor
}

T100Pen::T100Pen(T100COLOUR_TYPE colour, T100WORD width, T100LINE_TYPE type)
{
    //ctor
    m_pen   = CreatePen(type, width, T100Colour(colour).GetColour());
}

T100Pen::~T100Pen()
{
    //dtor
}

HPEN T100Pen::GetHPEN()
{
    return m_pen;
}

T100VOID T100Pen::SetColour(T100Colour colour)
{
    m_colour    = colour;
}

T100Colour& T100Pen::GetColour()
{
    return m_colour;
}

T100VOID T100Pen::SetType(T100LINE_TYPE type)
{
    m_type      = type;
}

T100LINE_TYPE& T100Pen::GetType()
{
    return m_type;
}
