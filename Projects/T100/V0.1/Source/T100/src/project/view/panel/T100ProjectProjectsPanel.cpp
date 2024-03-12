#include "../../../../include/project/view/panel/T100ProjectProjectsPanel.h"

//(*InternalHeaders(T100ProjectProjectsPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100MansionInfo.h"
#include "T100MansionDrawer.h"
#include "T100ProjectInfo.h"
#include "T100TreeCtrlItemData.h"
#include "T100ProjectCallback.h"

#include "T100ProjectCreateDialog.h"


//(*IdInit(T100ProjectProjectsPanel)
const long T100ProjectProjectsPanel::ID_TREECTRL_PROJECTS = wxNewId();
//*)

const long T100ProjectProjectsPanel::ID_TREECTRL_MENUITEM_PROJECT_CREATE = wxNewId();

BEGIN_EVENT_TABLE(T100ProjectProjectsPanel,wxPanel)
	//(*EventTable(T100ProjectProjectsPanel)
	//*)
END_EVENT_TABLE()

T100ProjectProjectsPanel::T100ProjectProjectsPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100ProjectProjectsPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	TreeCtrlProjects = new wxTreeCtrl(this, ID_TREECTRL_PROJECTS, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL_PROJECTS"));
	BoxSizer1->Add(TreeCtrlProjects, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_BEGIN_DRAG,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsBeginDrag);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_BEGIN_RDRAG,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsBeginRDrag);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_END_DRAG,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsEndDrag);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsBeginLabelEdit);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_END_LABEL_EDIT,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsEndLabelEdit);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_DELETE_ITEM,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsDeleteItem);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_ITEM_COLLAPSED,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsItemCollapsed);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_ITEM_COLLAPSING,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsItemCollapsing);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_ITEM_EXPANDED,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsItem_bExpanded);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_ITEM_EXPANDING,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsItem_bExpanding);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsItemRightClick);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsItemMiddleClick);
	Connect(ID_TREECTRL_PROJECTS,wxEVT_COMMAND_TREE_ITEM_MENU,(wxObjectEventFunction)&T100ProjectProjectsPanel::OnTreeCtrlProjectsItemMenu);
	//*)
}

T100ProjectProjectsPanel::~T100ProjectProjectsPanel()
{
	//(*Destroy(T100ProjectProjectsPanel)
	//*)
	destroy();
}

T100BOOL T100ProjectProjectsPanel::create()
{
    T100MansionInfo*                            info        = T100NEW T100MansionInfo();
    T100PROJECT::T100MansionDrawer*             drawer      = T100NEW T100PROJECT::T100MansionDrawer();
    T100PROJECT_INFO_VECTOR*                    projects    = T100NEW T100PROJECT_INFO_VECTOR();

    drawer->load(info, projects);

    TreeCtrlProjects->DeleteAllItems();
    wxTreeItemId    root    = TreeCtrlProjects->AddRoot(L"root");

    T100PROJECT::T100TreeCtrlItemData*       data        = T100NEW T100PROJECT::T100TreeCtrlItemData();

    TreeCtrlProjects->SetItemData(root, data);

    for(auto item : *projects){
        if(item){
            TreeCtrlProjects->AppendItem(root, item->getName().to_wstring());
        }
    }


    Connect(ID_TREECTRL_MENUITEM_PROJECT_CREATE,        wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T100ProjectProjectsPanel::OnItemMenuProjectCreate);

}

T100VOID T100ProjectProjectsPanel::destroy()
{

}


void T100ProjectProjectsPanel::OnTreeCtrlProjectsBeginDrag(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsBeginRDrag(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsEndDrag(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsBeginLabelEdit(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsEndLabelEdit(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsDeleteItem(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsItemCollapsed(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsItemCollapsing(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsItem_bExpanded(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsItem_bExpanding(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsItemRightClick(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsItemMiddleClick(wxTreeEvent& event)
{
}

void T100ProjectProjectsPanel::OnTreeCtrlProjectsItemMenu(wxTreeEvent& event)
{
    TreeCtrlProjects->GetItemData(event.GetItem());

    wxTreeItemId        current;

    current = event.GetItem();

    if(current.IsOk()){
        wxTreeItemData*     data        = T100NULL;

        data    = TreeCtrlProjects->GetItemData(current);

        if(data){
            T100PROJECT::T100TreeCtrlItemData*       item        = T100NULL;

            item    = dynamic_cast<T100PROJECT::T100TreeCtrlItemData*>(data);

            if(item){
                item->ShowMenu(TreeCtrlProjects);
            }
        }
    }
}

void T100ProjectProjectsPanel::OnItemMenuProjectCreate(wxCommandEvent& event)
{
    T100ProjectCreateDialog         dialog(this);

    if(wxID_OK == dialog.ShowModal()){

    }



    T100PROJECT::T100ProjectCallback::treectrl_menu_project_create();
}
