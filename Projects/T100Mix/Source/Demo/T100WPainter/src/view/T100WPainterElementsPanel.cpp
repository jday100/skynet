#include "../../include/view/T100WPainterElementsPanel.h"

//(*InternalHeaders(T100WPainterElementsPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100WPainterElementsPanel)
const long T100WPainterElementsPanel::ID_LISTVIEW1 = wxNewId();
const long T100WPainterElementsPanel::ID_LISTVIEW2 = wxNewId();
const long T100WPainterElementsPanel::ID_LISTVIEW3 = wxNewId();
const long T100WPainterElementsPanel::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100WPainterElementsPanel,wxPanel)
	//(*EventTable(T100WPainterElementsPanel)
	//*)
END_EVENT_TABLE()

T100WPainterElementsPanel::T100WPainterElementsPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100WPainterElementsPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100WPainterElementsPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	ListView1 = new wxListView(Notebook1, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	ListView2 = new wxListView(Notebook1, ID_LISTVIEW2, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW2"));
	ListView3 = new wxListView(Notebook1, ID_LISTVIEW3, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW3"));
	Notebook1->AddPage(ListView1, _("Page name"), false);
	Notebook1->AddPage(ListView2, _("Page name"), false);
	Notebook1->AddPage(ListView3, _("Page name"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100WPainterElementsPanel::~T100WPainterElementsPanel()
{
	//(*Destroy(T100WPainterElementsPanel)
	//*)
}

