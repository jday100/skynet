#include "T100DCBase.h"

#include "gui/window/T100Window.h"

T100DCBase::T100DCBase(T100Window* parent) :
    T100Class(),
    m_windowPtr(parent),
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
    m_hdc   = BeginPaint(m_windowPtr->GetHWND(), &m_paintStruct);
}

T100VOID T100DCBase::uninit()
{
    EndPaint(m_windowPtr->GetHWND(), &m_paintStruct);
}

T100VOID T100DCBase::SetPen(T100Pen* pen)
{
    m_penPtr    = pen;
    SelectObject(m_hdc, pen->GetHPEN());
}

T100Pen* T100DCBase::GetPenPtr()
{
    return m_penPtr;
}

T100VOID T100DCBase::SetBrush(T100Brush* brush)
{
    m_brushPtr  = brush;

}

T100Brush* T100DCBase::GetBrushPtr()
{
    return m_brushPtr;
}
