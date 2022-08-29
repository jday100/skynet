#include "../../../../include/ide/view/panel/T100IDEPanelProject.h"

//(*InternalHeaders(T100IDEPanelProject)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100IDEPanelProject)
const long T100IDEPanelProject::ID_TREECTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100IDEPanelProject,wxPanel)
	//(*EventTable(T100IDEPanelProject)
	//*)
END_EVENT_TABLE()

T100IDEPanelProject::T100IDEPanelProject(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100IDEPanelProject::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100IDEPanelProject)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	TreeCtrl1 = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	BoxSizer1->Add(TreeCtrl1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100IDEPanelProject::~T100IDEPanelProject()
{
	//(*Destroy(T100IDEPanelProject)
	//*)
}

