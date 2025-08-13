#include "T100WorkSpaceData.h"

#include "T100ProjectCommon.h"

T100WorkSpaceData::T100WorkSpaceData() :
    T100TreeItemData()
{
    //ctor
}

T100WorkSpaceData::~T100WorkSpaceData()
{
    //dtor
}

wxMenu* T100WorkSpaceData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();
    wxMenu*     project = T100NEW wxMenu();

    menu->AppendSubMenu(project, L"Project");
    project->Append(T100PROJECT_TREE_MENU_PROJECT_NEW, L"New");

    return menu;
}

T100VOID T100WorkSpaceData::OnItemChanged()
{

}

T100VOID T100WorkSpaceData::OnItemActivated()
{

}

T100VOID T100WorkSpaceData::OnItemExpanding()
{

}
