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

T100VOID T100ModuleInfo::SetIncludeFile(T100FileInfo* info)
{
    m_fileInclude       = info;
}

T100FileInfo* T100ModuleInfo::GetIncludeFile()
{
    return m_fileInclude;
}

T100VOID T100ModuleInfo::SetSourceFile(T100FileInfo* info)
{
    m_fileSource        = info;
}

T100FileInfo* T100ModuleInfo::GetSourceFile()
{
    return m_fileSource;
}
