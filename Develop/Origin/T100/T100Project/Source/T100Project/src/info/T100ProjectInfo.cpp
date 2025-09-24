#include "T100ProjectInfo.h"

T100ProjectInfo::T100ProjectInfo() :
    m_label(),
    m_path(),
    m_filename(),
    m_folder(),
    m_files(),
    m_folders()
{
    //ctor
    m_opened        = T100FALSE;
    init();
}

T100ProjectInfo::~T100ProjectInfo()
{
    //dtor
    uninit();
}

T100VOID T100ProjectInfo::init()
{

}

T100VOID T100ProjectInfo::uninit()
{
    m_files.clear();
    m_folders.clear();
    m_opened        = T100FALSE;
}

T100VOID T100ProjectInfo::SetOpened(T100BOOL value)
{
    m_opened        = value;
}

T100BOOL T100ProjectInfo::IsOpened()
{
    return m_opened;
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

T100VOID T100ProjectInfo::SetFolder(const T100WSTRING& folder)
{
    m_folder        = folder;
}

const T100WSTRING& T100ProjectInfo::GetFolder()
{
    return m_folder;
}

T100VOID T100ProjectInfo::SetBuildTreeId(wxTreeItemId id)
{
    m_treeIdBuild       = id;
}

wxTreeItemId T100ProjectInfo::GetBuildTreeId()
{
    return m_treeIdBuild;
}

T100VOID T100ProjectInfo::SetCodeTreeId(wxTreeItemId id)
{
    m_treeIdCode        = id;
}

wxTreeItemId T100ProjectInfo::GetCodeTreeId()
{
    return m_treeIdCode;
}

T100VOID T100ProjectInfo::SetIncludeTreeId(wxTreeItemId id)
{
    m_treeIdInclude     = id;
}

wxTreeItemId T100ProjectInfo::GetIncludeTreeId()
{
    return m_treeIdInclude;
}

T100VOID T100ProjectInfo::SetSourceTreeId(wxTreeItemId id)
{
    m_treeIdSource      = id;
}

wxTreeItemId T100ProjectInfo::GetSourceTreeId()
{
    return m_treeIdSource;
}

T100VOID T100ProjectInfo::SetBuildPath(const T100WSTRING& path)
{
    m_pathBuild     = path;
}

const T100WSTRING& T100ProjectInfo::GetBuildPath()
{
    return m_pathBuild;
}

T100VOID T100ProjectInfo::SetCodePath(const T100WSTRING& path)
{
    m_pathCode      = path;
}

const T100WSTRING& T100ProjectInfo::GetCodePath()
{
    return m_pathCode;
}

T100VOID T100ProjectInfo::SetIncludePath(const T100WSTRING& path)
{
    m_pathInclude       = path;
}

const T100WSTRING& T100ProjectInfo::GetIncludePath()
{
    return m_pathInclude;
}

T100VOID T100ProjectInfo::SetSourcePath(const T100WSTRING& path)
{
    m_pathSource        = path;
}

const T100WSTRING& T100ProjectInfo::GetSourcePath()
{
    return m_pathSource;
}

T100VOID T100ProjectInfo::SetBuildFileName(const T100WSTRING& filename)
{
    m_fileNameBuild     = filename;
}

const T100WSTRING& T100ProjectInfo::GetBuildFileName()
{
    return m_fileNameBuild;
}

T100FILE_INFO_VECTOR& T100ProjectInfo::GetFiles()
{
    return m_files;
}

T100FOLDER_INFO_VECTOR& T100ProjectInfo::GetSubFolders()
{
    return m_folders;
}
