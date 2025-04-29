#include "T100ConsoleBase.h"

T100ConsoleBase::T100ConsoleBase()
{
    //ctor
}

T100ConsoleBase::~T100ConsoleBase()
{
    //dtor
}

T100VOID T100ConsoleBase::SetForegroundColour(T100COLOUR_TYPE type)
{
    m_foreground = type;
}

T100COLOUR_TYPE T100ConsoleBase::GetForegroundColour()
{
    return m_foreground;
}

T100VOID T100ConsoleBase::SetBackgroundColour(T100COLOUR_TYPE type)
{
    m_background = type;
}

T100COLOUR_TYPE T100ConsoleBase::GetBackgroundColour()
{
    return m_background;
}
