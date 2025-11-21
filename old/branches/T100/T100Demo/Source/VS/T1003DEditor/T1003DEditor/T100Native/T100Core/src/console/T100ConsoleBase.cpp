#include "console/T100ConsoleBase.h"

namespace T100NATIVE{

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
    m_foregroundColour  = type;
}

T100COLOUR_TYPE T100ConsoleBase::GetForegroundColour()
{
    return m_foregroundColour;
}

T100VOID T100ConsoleBase::SetBackgroundColour(T100COLOUR_TYPE type)
{
    m_backgroundColour  = type;
}

T100COLOUR_TYPE T100ConsoleBase::GetBackgroundColour()
{
    return m_backgroundColour;
}

}
