#include "T100ProjectInfo.h"

T100ProjectInfo::T100ProjectInfo()
{
    //ctor
}

T100ProjectInfo::~T100ProjectInfo()
{
    //dtor
}

T100VOID T100ProjectInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100ProjectInfo::GetLabel()
{
    return m_label;
}

T100VOID T100ProjectInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100ProjectInfo::GetPath()
{
    return m_path;
}

T100VOID T100ProjectInfo::SetFileName(const T100WSTRING& filename)
{
    m_filename      = filename;
}

const T100WSTRING& T100ProjectInfo::GetFileName()
{
    return m_filename;
}
