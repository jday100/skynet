#include "../../../../include/wxwidgets/painter/panel/T100PainterPropertiesDemoPanel.h"

//(*InternalHeaders(T100PainterPropertiesDemoPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100PainterPropertiesDemoPanel)
const long T100PainterPropertiesDemoPanel::ID_LISTVIEW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100PainterPropertiesDemoPanel,wxPanel)
	//(*EventTable(T100PainterPropertiesDemoPanel)
	//*)
END_EVENT_TABLE()

T100PainterPropertiesDemoPanel::T100PainterPropertiesDemoPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100PainterPropertiesDemoPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100PainterPropertiesDemoPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer1->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100PainterPropertiesDemoPanel::~T100PainterPropertiesDemoPanel()
{
	//(*Destroy(T100PainterPropertiesDemoPanel)
	//*)
}

