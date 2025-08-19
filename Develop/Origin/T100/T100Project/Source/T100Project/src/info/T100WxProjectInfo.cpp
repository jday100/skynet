#include "T100WxProjectInfo.h"

T100WxProjectInfo::T100WxProjectInfo()
{
    //ctor
}

T100WxProjectInfo::~T100WxProjectInfo()
{
    //dtor
}

T100VOID T100WxProjectInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100WxProjectInfo::GetLabel()
{
    return m_label;
}
