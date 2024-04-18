#include "../../include/view/T100PainterElementsPanel.h"

//(*InternalHeaders(T100PainterElementsPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100PainterElementsPanel)
const long T100PainterElementsPanel::ID_LISTVIEW1 = wxNewId();
const long T100PainterElementsPanel::ID_NOTEBOOK1 = wxNewId();
//*)

const long T100PainterElementsPanel::ID_THREAD_IMAGE = wxNewId();

BEGIN_EVENT_TABLE(T100PainterElementsPanel,wxPanel)
	//(*EventTable(T100PainterElementsPanel)
	//*)
END_EVENT_TABLE()

T100PainterElementsPanel::T100PainterElementsPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100PainterElementsPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100PainterElementsPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	ListView1 = new wxListView(Notebook1, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_ICON, wxDefaultValidator, _T("ID_LISTVIEW1"));
	Notebook1->AddPage(ListView1, _("Graphics"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	ImageList1 = new wxImageList(16, 16, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100PainterElementsPanel::~T100PainterElementsPanel()
{
	//(*Destroy(T100PainterElementsPanel)
	//*)
}

