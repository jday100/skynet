#include "../../include/wx/T100BrowsePanel.h"

//(*InternalHeaders(T100BrowsePanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100BrowsePanel)
//*)

BEGIN_EVENT_TABLE(T100BrowsePanel,wxPanel)
	//(*EventTable(T100BrowsePanel)
	//*)
END_EVENT_TABLE()

T100BrowsePanel::T100BrowsePanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100BrowsePanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100BrowsePanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100BrowsePanel::~T100BrowsePanel()
{
	//(*Destroy(T100BrowsePanel)
	//*)
}

