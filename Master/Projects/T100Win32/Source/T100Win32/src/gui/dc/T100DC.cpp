#include "T100DC.h"

#include "gui/T100Window.h"

T100DC::T100DC(T100Window* parent) :
    m_windowPtr(parent)
{
    //ctor
    init();
}

T100DC::~T100DC()
{
    //dtor
    uninit();
}

T100VOID T100DC::init()
{
    m_hdc   = BeginPaint(m_windowPtr->GetHWND(), &m_paintStruct);
}

T100VOID T100DC::uninit()
{
    EndPaint(m_windowPtr->GetHWND(), &m_paintStruct);
}

T100VOID T100DC::DrawLine(T100Point start, T100Point end)
{
    SetPixel(m_hdc, 100, 100, RGB(255, 255, 255));
    MoveToEx(m_hdc, 100, 100, T100NULL);
    LineTo(m_hdc, 300, 300);
}
