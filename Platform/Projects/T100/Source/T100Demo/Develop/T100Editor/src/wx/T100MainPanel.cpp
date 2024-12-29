#include "../../include/wx/T100MainPanel.h"

//(*InternalHeaders(T100MainPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100MainPanel)
const long T100MainPanel::ID_NOTEBOOK = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100MainPanel,wxPanel)
	//(*EventTable(T100MainPanel)
	//*)
END_EVENT_TABLE()

T100MainPanel::T100MainPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100MainPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100MainPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook = new wxNotebook(this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK"));
	BoxSizer1->Add(Notebook, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100MainPanel::~T100MainPanel()
{
	//(*Destroy(T100MainPanel)
	//*)
}

