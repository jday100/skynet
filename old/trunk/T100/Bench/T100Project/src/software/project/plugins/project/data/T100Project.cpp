#include "T100Project.h"

T100Project::T100Project(const T100WSTRING& label) :
    m_label(label),
    m_includeFiles(T100NULL, L"include"),
    m_sourceFiles(T100NULL, L"source")
{
    //ctor
}

T100Project::~T100Project()
{
    //dtor
}

T100VOID T100Project::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100Project::GetLabel()
{
    return m_label;
}

T100VOID T100Project::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100Project::GetPath()
{
    return m_path;
}
