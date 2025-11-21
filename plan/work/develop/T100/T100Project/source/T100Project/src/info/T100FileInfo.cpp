#include "T100FileInfo.h"

T100FileInfo::T100FileInfo()
{
    //ctor
}

T100FileInfo::~T100FileInfo()
{
    //dtor
}

T100VOID T100FileInfo::SetFileName(const T100WSTRING& filename)
{
    m_filename      = filename;
}

const T100WSTRING& T100FileInfo::GetFileName()
{
    return m_filename;
}

T100VOID T100FileInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100FileInfo::GetPath()
{
    return m_path;
}
