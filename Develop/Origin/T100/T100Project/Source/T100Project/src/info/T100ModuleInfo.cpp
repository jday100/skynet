#include "T100ModuleInfo.h"

T100ModuleInfo::T100ModuleInfo()
{
    //ctor
}

T100ModuleInfo::~T100ModuleInfo()
{
    //dtor
}

T100VOID T100ModuleInfo::SetLabel(const T100WSTRING& label)
{
    m_label         = label;
}

const T100WSTRING& T100ModuleInfo::GetLabel()
{
    return m_label;
}
