#include "T100WxFolderInfo.h"

T100WxFolderInfo::T100WxFolderInfo() :
    m_label(),
    m_path()
{
    //ctor
}

T100WxFolderInfo::~T100WxFolderInfo()
{
    //dtor
}

T100VOID T100WxFolderInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100WxFolderInfo::GetLabel()
{
    return m_label;
}

T100VOID T100WxFolderInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100WxFolderInfo::GetPath()
{
    return m_path;
}
