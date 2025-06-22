#include "T100DCBase.h"

#include "gui/T100Window.h"

namespace T100WINDOWS{

T100DCBase::T100DCBase(T100Window* window) :
    T100Class(),
    m_window(window),
    m_pen(),
    m_font(),
    m_brush(),
    m_paintStruct()
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
    ZeroMemory(&m_paintStruct, sizeof(m_paintStruct));
    m_hdc   = BeginPaint(m_window->GetHWND(), &m_paintStruct);
}

T100VOID T100DCBase::uninit()
{
    EndPaint(m_window->GetHWND(), &m_paintStruct);
}

T100VOID T100DCBase::SetPen(const T100Pen& pen)
{
    m_pen       = pen;
    SelectObject(m_hdc, m_pen.GetHPEN());
}

const T100Pen& T100DCBase::GetPen()
{
    return m_pen;
}

T100VOID T100DCBase::SetBrush(const T100Brush& brush)
{
    m_brush     = brush;
    SelectObject(m_hdc, m_brush.GetHBRUSH());
}

const T100Brush& T100DCBase::GetBrush()
{
    return m_brush;
}

T100VOID T100DCBase::SetFont(const T100Font& font)
{
    m_font      = font;
    SelectObject(m_hdc, m_font.GetHFONT());
}

const T100Font& T100DCBase::GetFont()
{
    return m_font;
}

}
