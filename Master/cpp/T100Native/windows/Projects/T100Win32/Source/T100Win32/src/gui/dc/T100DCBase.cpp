#include "T100DCBase.h"

namespace T100WINDOWS{

T100DCBase::T100DCBase() :
    T100Class()
{
    //ctor
    init();
}

T100DCBase::~T100DCBase()
{
    //dtor
    uninit();
}

T100VOID T100DCBase::init()
{

}

T100VOID T100DCBase::uninit()
{

}

T100VOID T100DCBase::SetPen(const T100Pen& pen)
{
    m_pen       = pen;
}

const T100Pen& T100DCBase::GetPen()
{
    return m_pen;
}

T100VOID T100DCBase::SetBrush(const T100Brush& brush)
{
    m_brush     = brush;
}

const T100Brush& T100DCBase::GetBrush()
{
    return m_brush;
}

T100VOID T100DCBase::SetFont(const T100Font& font)
{
    m_font      = font;
}

const T100Font& T100DCBase::GetFont()
{
    return m_font;
}

}
