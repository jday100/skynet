#include "T100Caret.h"

#include <windows.h>

T100Caret::T100Caret(T100Window* parent) :
    T100Class(),
    m_window(parent)
{
    //ctor
}

T100Caret::~T100Caret()
{
    //dtor
}

T100VOID T100Caret::SetSize(T100Size size)
{
    m_size      = size;
}

T100Size& T100Caret::GetSize()
{
    return m_size;
}

T100VOID T100Caret::SetPosition(T100Point position)
{
    m_position  = position;
    SetCaretPos(position.x, position.y);
}

T100Point& T100Caret::GetPosition()
{
    return m_position;
}

T100VOID T100Caret::SetBlinkTime(T100INT time)
{
    m_blinkTime = time;
    SetCaretBlinkTime(time);
}

T100INT T100Caret::GetBlinkTime()
{
    return m_blinkTime;
}

T100VOID T100Caret::Hide()
{
    HideCaret(m_window->GetHWND());
}

T100VOID T100Caret::Show()
{
    ShowCaret(m_window->GetHWND());
}

T100BOOL T100Caret::IsShown()
{

}

T100VOID T100Caret::Move(T100INT x, T100INT y)
{
    SetCaretPos(x, y);
    m_position.x    = x;
    m_position.y    = y;
}
