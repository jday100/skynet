#include "T100FileInfo.h"

T100FileInfo::T100FileInfo() :
    m_label(),
    m_filename(),
    m_extname(),
    m_path(),
    m_folder()
{
    //ctor
    m_opened        = T100FALSE;
}

T100FileInfo::~T100FileInfo()
{
    //dtor
}

T100VOID T100FileInfo::SetOpened(T100BOOL value)
{
    m_opened        = value;
}

T100BOOL T100FileInfo::IsOpened()
{
    return m_opened;
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

T100VOID T100FileInfo::SetFolder(const T100WSTRING& folder)
{
    m_folder        = folder;
}

const T100WSTRING& T100FileInfo::GetFolder()
{
    return m_folder;
}
