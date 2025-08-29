#include "T100WorkSpaceData.h"

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

T100WorkSpaceData::T100WorkSpaceData() :
    T100TreeItemData()
{
    //ctor
}

T100WorkSpaceData::T100WorkSpaceData(T100WorkSpaceInfo* info) :
    T100TreeItemData(),
    m_info(info)
{
    //ctor
}

T100WorkSpaceData::~T100WorkSpaceData()
{
    //dtor
}

T100VOID T100WorkSpaceData::SetWorkSpaceInfo(T100WorkSpaceInfo* info)
{
    m_info      = info;
}

T100WorkSpaceInfo* T100WorkSpaceData::GetWorkSpaceInfo()
{
    return m_info;
}

wxMenu* T100WorkSpaceData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();
    wxMenu*     project = T100NEW wxMenu();

    menu->AppendSubMenu(project, L"Project");
    project->Append(T100PROJECT_TREE_MENU_PROJECT_NEW, L"New");

    menu->Append(T100PROJECT_TREE_MENU_WORKSPACE_PROPERTIES, L"Properties...");

    return menu;
}

T100VOID T100WorkSpaceData::OnItemChanged()
{
    T100ProjectInvoking::OnWorkSpaceSelect();
}

T100VOID T100WorkSpaceData::OnItemActivated()
{

}

T100VOID T100WorkSpaceData::OnItemExpanding()
{

}
