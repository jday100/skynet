#include "T100TreeCtrlItemData.h"

#include <wx/menu.h>
#include "T100ProjectProjectsPanel.h"

namespace T100PROJECT{

T100TreeCtrlItemData::T100TreeCtrlItemData()
    :wxTreeItemData()
{
    //ctor
}

T100TreeCtrlItemData::~T100TreeCtrlItemData()
{
    //dtor
}

T100VOID T100TreeCtrlItemData::ShowMenu(wxTreeCtrl* parent)
{
    wxMenu*     menu        = T100NEW wxMenu();

    menu->Append(T100ProjectProjectsPanel::ID_TREECTRL_MENUITEM_PROJECT_CREATE, wxT("Create"));

    parent->PopupMenu(menu);
}

}
