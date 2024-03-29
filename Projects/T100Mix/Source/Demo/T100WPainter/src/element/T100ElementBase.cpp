#include "T100ElementBase.h"

T100ElementBase::T100ElementBase()
{
    //ctor
}

T100ElementBase::~T100ElementBase()
{
    //dtor
}

T100VOID T100ElementBase::SetStartingPoint(T100INT x, T100INT y)
{
    m_starting_x    = x;
    m_starting_y    = y;
}

T100VOID T100ElementBase::SetTerminalPoint(T100INT x, T100INT y)
{
    m_terminal_x    = x;
    m_terminal_y    = y;
}
