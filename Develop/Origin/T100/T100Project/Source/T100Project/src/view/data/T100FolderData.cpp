#include "T100FolderData.h"

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

T100FolderData::T100FolderData(T100FolderInfo* info) :
    T100TreeItemData(),
    m_info(info)
{
    //ctor
}

T100FolderData::~T100FolderData()
{
    //dtor
}

T100FolderInfo* T100FolderData::GetFolderInfo()
{
    return m_info;
}

wxMenu* T100FolderData::CreateMenu()
{
    wxMenu*     menu        = T100NEW wxMenu();
    wxMenu*     file        = T100NEW wxMenu();
    wxMenu*     folder      = T100NEW wxMenu();

    menu->AppendSubMenu(file, L"File");
    menu->AppendSubMenu(folder, L"Folder");

    file->Append(T100PROJECT_TREE_MENU_FILE_NEW, L"New");
    folder->Append(T100PROJECT_TREE_MENU_FOLDER_NEW, L"New");

    return menu;
}

T100VOID T100FolderData::OnItemChanged()
{
    //T100ProjectInvoking::OnFolderSelect();
}

T100VOID T100FolderData::OnItemActivated()
{

}

T100VOID T100FolderData::OnItemExpanding()
{
    if(m_opened){

    }else{
        T100ProjectInvoking::OnFolderList(this);
    }
}
