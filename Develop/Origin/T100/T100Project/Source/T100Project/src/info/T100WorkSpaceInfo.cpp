#include "T100WorkSpaceInfo.h"

T100WorkSpaceInfo::T100WorkSpaceInfo() :
    m_label(),
    m_path(),
    m_filename(),
    m_projects()
{
    //ctor
}

T100WorkSpaceInfo::~T100WorkSpaceInfo()
{
    //dtor
}

T100VOID T100WorkSpaceInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100WorkSpaceInfo::GetLabel()
{
    return m_label;
}

T100VOID T100WorkSpaceInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100WorkSpaceInfo::GetPath()
{
    return m_path;
}

T100VOID T100WorkSpaceInfo::SetFileName(const T100WSTRING& filename)
{
    m_filename      = filename;
}

const T100WSTRING& T100WorkSpaceInfo::GetFileName()
{
    return m_filename;
}

T100PROJECT_INFO_VECTOR& T100WorkSpaceInfo::GetProjects()
{
    return m_projects;
}

T100FILE_INFO_VECTOR& T100WorkSpaceInfo::GetFiles()
{
    return m_files;
}

T100FOLDER_INFO_VECTOR& T100WorkSpaceInfo::GetFolders()
{
    return m_folders;
}
