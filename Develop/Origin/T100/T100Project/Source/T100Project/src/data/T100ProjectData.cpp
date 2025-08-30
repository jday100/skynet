#include "T100ProjectData.h"

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

T100ProjectData::T100ProjectData() :
    T100TreeItemData()
{
    //ctor
}

T100ProjectData::T100ProjectData(T100ProjectInfo* info) :
    T100TreeItemData(),
    m_info(info)
{
    //ctor
}

T100ProjectData::~T100ProjectData()
{
    //dtor
}

T100VOID T100ProjectData::SetProjectInfo(T100ProjectInfo* info)
{
    m_info      = info;
}

T100ProjectInfo* T100ProjectData::GetProjectInfo()
{
    return m_info;
}

wxMenu* T100ProjectData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();
    wxMenu*     file    = T100NEW wxMenu();
    wxMenu*     folder  = T100NEW wxMenu();
    wxMenu*     clazz   = T100NEW wxMenu();

    menu->AppendSubMenu(file, L"File");
    menu->AppendSubMenu(folder, L"Folder");
    menu->AppendSubMenu(clazz, L"Class");

    file->Append(T100PROJECT_TREE_MENU_FILE_NEW, L"New");
    folder->Append(T100PROJECT_TREE_MENU_FOLDER_NEW, L"New");
    clazz->Append(T100PROJECT_TREE_MENU_CLASS_NEW, L"New");

    return menu;
}

T100VOID T100ProjectData::OnItemChanged()
{
    T100ProjectInvoking::OnProjectSelect();
}

T100VOID T100ProjectData::OnItemActivated()
{

}

T100VOID T100ProjectData::OnItemExpanding()
{
    if(m_opened){

    }else{
        T100ProjectInvoking::OnProjectOpen(this);
    }
}
