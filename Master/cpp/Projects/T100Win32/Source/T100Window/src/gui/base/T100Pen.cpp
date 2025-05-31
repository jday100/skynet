#include "gui/base/T100Pen.h"

T100Pen::T100Pen(T100Colour colour, T100WORD width, T100LINE_TYPE type) :
    m_colour(colour),
    m_width(width),
    m_type(type)
{
    //ctor
    Init();
}

T100Pen::T100Pen(T100COLOUR_TYPE colour, T100WORD width, T100LINE_TYPE type) :
    m_colour(colour),
    m_width(width),
    m_type(type)
{
    //ctor
    Init();
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
    Init();
}

T100Colour& T100Pen::GetColour()
{
    return m_colour;
}

T100VOID T100Pen::SetType(T100LINE_TYPE type)
{
    m_type      = type;
    Init();
}

T100LINE_TYPE& T100Pen::GetType()
{
    return m_type;
}

T100VOID T100Pen::SetWidth(T100WORD width)
{
    m_width     = width;
    Init();
}

T100WORD T100Pen::GetWidth()
{
    return m_width;
}

T100VOID T100Pen::Init()
{
    m_pen   = CreatePen(m_type, m_width, m_colour.GetColour());
}
