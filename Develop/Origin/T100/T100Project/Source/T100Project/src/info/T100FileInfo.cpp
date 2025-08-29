#include "T100FileInfo.h"

T100FileInfo::T100FileInfo()
{
    //ctor
}

T100FileInfo::~T100FileInfo()
{
    //dtor
}

T100VOID T100FileInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100FileInfo::GetLabel()
{
    return m_label;
}

T100VOID T100FileInfo::SetFileName(const T100WSTRING& filename)
{
    m_filename      = filename;
}

const T100WSTRING& T100FileInfo::GetFileName()
{
    return m_filename;
}

T100VOID T100FileInfo::SetExtName(const T100WSTRING& name)
{
    m_extname       = name;
}

const T100WSTRING& T100FileInfo::GetExtName()
{
    return m_extname;
}

T100VOID T100FileInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100FileInfo::GetPath()
{
    return m_path;
}

T100VOID T100FileInfo::SetFile(const T100WSTRING& file)
{
    m_file      = file;
}

const T100WSTRING& T100FileInfo::GetFile()
{
    return m_file;
}
