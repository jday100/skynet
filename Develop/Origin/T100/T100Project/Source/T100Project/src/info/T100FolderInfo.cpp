#include "T100FolderInfo.h"

T100FolderInfo::T100FolderInfo()
{
    //ctor
}

T100FolderInfo::~T100FolderInfo()
{
    //dtor
}

T100VOID T100FolderInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100FolderInfo::GetLabel()
{
    return m_label;
}

T100VOID T100FolderInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100FolderInfo::GetPath()
{
    return m_path;
}

T100FILE_INFO_VECTOR& T100FolderInfo::GetFiles()
{
    return m_files;
}

T100FOLDER_INFO_VECTOR& T100FolderInfo::GetSubFolders()
{
    return m_folders;
}
