#include "T100Cursor.h"

namespace T100WINDOWS{

T100Cursor::T100Cursor(T100Window* window) :
    m_window(window),
    m_size(),
    m_position()
{
    //ctor
}

T100Cursor::~T100Cursor()
{
    //dtor
}

T100VOID T100Cursor::SetSize(const T100Size& size)
{
    m_size      = size;
}

const T100Size& T100Cursor::GetSize()
{
    return m_size;
}

T100VOID T100Cursor::SetPosition(const T100Point& point)
{
    m_position  = point;
}

const T100Point& T100Cursor::GetPosition()
{
    return m_position;
}

T100VOID T100Cursor::SetBlinkTime(T100INT value)
{
    m_blinkTime     = value;
}

T100INT T100Cursor::GetBlinkTime()
{
    return m_blinkTime;
}

T100VOID T100Cursor::Show()
{

}

T100VOID T100Cursor::Hide()
{

}

T100BOOL T100Cursor::IsShown()
{

}

T100VOID T100Cursor::Move(T100INT, T100INT)
{

}

}
