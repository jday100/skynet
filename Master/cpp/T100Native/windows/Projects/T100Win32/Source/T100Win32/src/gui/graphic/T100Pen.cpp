#include "T100Pen.h"

namespace T100WINDOWS{

T100Pen::T100Pen(const T100Colour4& colour, T100UINT width, T100LINE_TYPE type) :
    T100Class(),
    m_type(type),
    m_width(width),
    m_colour4(colour)
{
    //ctor
    init();
}

T100Pen::T100Pen(T100COLOUR4_TYPE colour, T100UINT width, T100LINE_TYPE type) :
    T100Class(),
    m_type(type),
    m_width(width),
    m_colour4()
{
    //ctor
    m_colour4       = T100Colour4(colour);
    init();
}

T100Pen::~T100Pen()
{
    //dtor
}

T100VOID T100Pen::init()
{
    m_hpen  = CreatePen(m_type, m_width, m_colour4.GetColour());
}

T100VOID T100Pen::uninit()
{

}

HPEN T100Pen::GetHPEN()
{
    return m_hpen;
}

T100VOID T100Pen::SetColour4(const T100Colour4& colour)
{
    m_colour4   = colour;
    init();
}

const T100Colour4& T100Pen::GetColour4()
{
    return m_colour4;
}

T100VOID T100Pen::SetType(T100LINE_TYPE type)
{
    m_type      = type;
    init();
}

T100LINE_TYPE T100Pen::GetType()
{
    return m_type;
}

T100VOID T100Pen::SetWidth(T100UINT width)
{
    m_width     = width;
    init();
}

T100UINT T100Pen::GetWidth()
{
    return m_width;
}

}
