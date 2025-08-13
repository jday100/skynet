#include "T100FolderData.h"

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

T100FolderData::T100FolderData() :
    T100TreeItemData()
{
    //ctor
    init();
}

T100FolderData::T100FolderData(T100FolderInfo* info) :
    T100TreeItemData()
{
    //ctor
    init();
}

T100FolderData::~T100FolderData()
{
    //dtor
    uninit();
}

T100VOID T100FolderData::init()
{
    m_opened    = T100FALSE;
}

T100VOID T100FolderData::uninit()
{

}

T100VOID T100FolderData::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100FolderData::GetLabel()
{
    return m_label;
}

T100VOID T100FolderData::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100FolderData::GetPath()
{
    return m_path;
}

T100VOID T100FolderData::SetOpened(T100BOOL value)
{
    m_opened        = value;
}

wxMenu* T100FolderData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();
    wxMenu*     file    = T100NEW wxMenu();
    wxMenu*     folder  = T100NEW wxMenu();

    menu->AppendSubMenu(file, L"File");
    menu->AppendSubMenu(folder, L"Folder");

    file->Append(T100PROJECT_TREE_MENU_FILE_NEW, L"New");
    folder->Append(T100PROJECT_TREE_MENU_FOLDER_NEW, L"New");

    return menu;
}

T100VOID T100FolderData::OnItemActivated()
{

}

T100VOID T100FolderData::OnItemExpanding()
{
    if(m_opened){

    }else{
        T100ProjectInvoking::OnFolderOpen(this);
    }
}
