#include "T100WorkSpaceInfo.h"

T100WorkSpaceInfo::T100WorkSpaceInfo() :
    m_label(),
    m_path(),
    m_filename(),
    m_pythonFile(),
    m_pathCompiler(),
    m_pathExecute(),
    m_files(),
    m_folders(),
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

T100VOID T100WorkSpaceInfo::SetPythonFile(const T100WSTRING& file)
{
    m_pythonFile        = file;
}

const T100WSTRING& T100WorkSpaceInfo::GetPythonFile()
{
    return m_pythonFile;
}

T100VOID T100WorkSpaceInfo::SetCompilerPath(const T100WSTRING& path)
{
    m_pathCompiler      = path;
}

const T100WSTRING& T100WorkSpaceInfo::GetCompilerPath()
{
    return m_pathCompiler;
}

T100VOID T100WorkSpaceInfo::SetExecutePath(const T100WSTRING& path)
{
    m_pathExecute       = path;
}

const T100WSTRING& T100WorkSpaceInfo::GetExecutePath()
{
    return m_pathExecute;
}

T100PROJECT_INFO_VECTOR& T100WorkSpaceInfo::GetProjects()
{
    return m_projects;
}

T100FILE_INFO_VECTOR& T100WorkSpaceInfo::GetFiles()
{
    return m_files;
}

T100FOLDER_INFO_VECTOR& T100WorkSpaceInfo::GetSubFolders()
{
    return m_folders;
}
