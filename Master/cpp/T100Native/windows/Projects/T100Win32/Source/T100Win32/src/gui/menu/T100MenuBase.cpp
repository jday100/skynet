#include "T100MenuBase.h"

namespace T100WINDOWS{

T100MenuBase::T100MenuBase() :
    T100Control()
{
    //ctor
}

T100MenuBase::~T100MenuBase()
{
    //dtor
}

HMENU T100MenuBase::GetHMENU()
{
    return m_hmenu;
}

T100VOID T100MenuBase::Enable()
{

}

T100VOID T100MenuBase::Disable()
{

}

T100BOOL T100MenuBase::IsEnabled()
{

}

T100VOID T100MenuBase::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100MenuBase::GetLabel()
{
    return m_label;
}

T100VOID T100MenuBase::SetFont(const T100Font& font)
{
    m_font      = font;
}

const T100Font& T100MenuBase::GetFont()
{
    return m_font;
}

T100VOID T100MenuBase::SetHelp(const T100WSTRING& value)
{
    m_help      = value;
}

const T100WSTRING& T100MenuBase::GetHelp()
{
    return m_help;
}

}
