#include "T100ConsoleBase.h"

T100ConsoleBase::T100ConsoleBase()
{
    //ctor
}

T100ConsoleBase::~T100ConsoleBase()
{
    //dtor
}

T100VOID T100ConsoleBase::setForegroundColour(T100COLOUR_PRIMITIVE_TYPE type)
{
    m_foreground    = type;
}

T100COLOUR_PRIMITIVE_TYPE T100ConsoleBase::getForegroundColour()
{
    return m_foreground;
}

T100VOID T100ConsoleBase::setBackgroundColour(T100COLOUR_PRIMITIVE_TYPE type)
{
    m_background    = type;
}

T100COLOUR_PRIMITIVE_TYPE T100ConsoleBase::getBackgroundColour()
{
    return m_background;
}
