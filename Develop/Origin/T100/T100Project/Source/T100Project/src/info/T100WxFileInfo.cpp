#include "T100WxFileInfo.h"

T100WxFileInfo::T100WxFileInfo() :
    m_label(),
    m_path()
{
    //ctor
}

T100WxFileInfo::~T100WxFileInfo()
{
    //dtor
}

T100VOID T100WxFileInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100WxFileInfo::GetLabel()
{
    return m_label;
}

T100VOID T100WxFileInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100WxFileInfo::GetPath()
{
    return m_path;
}
