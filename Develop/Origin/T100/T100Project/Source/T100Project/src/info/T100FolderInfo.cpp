#include "T100FolderInfo.h"

T100FolderInfo::T100FolderInfo() :
    m_label(),
    m_path(),
    m_folder(),
    m_files(),
    m_folders()
{
    //ctor
    m_opened        = T100FALSE;
    init();
}

T100FolderInfo::~T100FolderInfo()
{
    //dtor
    uninit();
}

T100VOID T100FolderInfo::init()
{

}

T100VOID T100FolderInfo::uninit()
{
    m_files.clear();
    m_folders.clear();
    m_opened    = T100FALSE;
}

T100VOID T100FolderInfo::SetOpened(T100BOOL value)
{
    m_opened        = value;
}

T100BOOL T100FolderInfo::IsOpened()
{
    return m_opened;
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

T100VOID T100FolderInfo::SetFolder(const T100WSTRING& folder)
{
    m_folder    = folder;
}

const T100WSTRING& T100FolderInfo::GetFolder()
{
    return m_folder;
}

T100FILE_INFO_VECTOR& T100FolderInfo::GetFiles()
{
    return m_files;
}

T100FOLDER_INFO_VECTOR& T100FolderInfo::GetSubFolders()
{
    return m_folders;
}
