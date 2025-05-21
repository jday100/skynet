#include "T100Pen.h"

T100Pen::T100Pen()
{
    //ctor
}

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
