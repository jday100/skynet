#include "T100Caret.h"

namespace T100WINDOWS{

T100Caret::T100Caret(T100Window* window) :
    m_window(window),
    m_size(),
    m_position()
{
    //ctor
}

T100Caret::~T100Caret()
{
    //dtor
}

T100VOID T100Caret::SetSize(const T100Size& size)
{
    m_size      = size;
}

const T100Size& T100Caret::GetSize()
{
    return m_size;
}

T100VOID T100Caret::SetPosition(const T100Point& point)
{
    m_position  = point;
}

const T100Point& T100Caret::GetPosition()
{
    return m_position;
}

T100VOID T100Caret::SetBlinkTime(T100INT value)
{
    m_blinkTime     = value;
}

T100INT T100Caret::GetBlinkTime()
{
    return m_blinkTime;
}

T100VOID T100Caret::Show()
{

}

T100VOID T100Caret::Hide()
{

}

T100BOOL T100Caret::IsShown()
{

}

T100VOID T100Caret::Move(T100INT, T100INT)
{

}

}
