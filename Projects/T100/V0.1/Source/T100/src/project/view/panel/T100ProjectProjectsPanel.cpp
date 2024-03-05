#include "../../../../incluce/project/view/panel/T100ProjectProjectsPanel.h"

//(*InternalHeaders(T100ProjectProjectsPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100ProjectProjectsPanel)
//*)

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
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100ProjectProjectsPanel::~T100ProjectProjectsPanel()
{
	//(*Destroy(T100ProjectProjectsPanel)
	//*)
}

