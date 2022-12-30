#include "../../../../include/wxwidgets/painter/panel/T100PainterElementsDemoPanel.h"

//(*InternalHeaders(T100PainterElementsDemoPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100PainterElementsDemoPanel)
const long T100PainterElementsDemoPanel::ID_LISTVIEW1 = wxNewId();
const long T100PainterElementsDemoPanel::ID_PANEL1 = wxNewId();
const long T100PainterElementsDemoPanel::ID_LISTVIEW2 = wxNewId();
const long T100PainterElementsDemoPanel::ID_PANEL2 = wxNewId();
const long T100PainterElementsDemoPanel::ID_LISTVIEW3 = wxNewId();
const long T100PainterElementsDemoPanel::ID_PANEL3 = wxNewId();
const long T100PainterElementsDemoPanel::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100PainterElementsDemoPanel,wxPanel)
	//(*EventTable(T100PainterElementsDemoPanel)
	//*)
END_EVENT_TABLE()

T100PainterElementsDemoPanel::T100PainterElementsDemoPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100PainterElementsDemoPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100PainterElementsDemoPanel)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxPoint(3,34), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(Panel1, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(ListView1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(4,9), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ListView2 = new wxListView(Panel2, ID_LISTVIEW2, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW2"));
	BoxSizer3->Add(ListView2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2->SetSizer(BoxSizer3);
	BoxSizer3->Fit(Panel2);
	BoxSizer3->SetSizeHints(Panel2);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(7,12), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	ListView3 = new wxListView(Panel3, ID_LISTVIEW3, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW3"));
	BoxSizer4->Add(ListView3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3->SetSizer(BoxSizer4);
	BoxSizer4->Fit(Panel3);
	BoxSizer4->SetSizeHints(Panel3);
	Notebook1->AddPage(Panel1, _("Page name"), false);
	Notebook1->AddPage(Panel2, _("Page name"), false);
	Notebook1->AddPage(Panel3, _("Page name"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&T100PainterElementsDemoPanel::OnNotebook1PageChanged);
	//*)
}

T100PainterElementsDemoPanel::~T100PainterElementsDemoPanel()
{
	//(*Destroy(T100PainterElementsDemoPanel)
	//*)
}


void T100PainterElementsDemoPanel::OnNotebook1PageChanged(wxNotebookEvent& event)
{
}
