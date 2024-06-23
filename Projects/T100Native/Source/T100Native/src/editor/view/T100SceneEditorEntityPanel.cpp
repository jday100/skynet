#include "../../../include/editor/view/T100SceneEditorEntityPanel.h"

//(*InternalHeaders(T100SceneEditorEntityPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100SceneEditorEntityPanel)
const long T100SceneEditorEntityPanel::ID_PANEL1 = wxNewId();
const long T100SceneEditorEntityPanel::ID_PANEL2 = wxNewId();
const long T100SceneEditorEntityPanel::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100SceneEditorEntityPanel,wxPanel)
	//(*EventTable(T100SceneEditorEntityPanel)
	//*)
END_EVENT_TABLE()

T100SceneEditorEntityPanel::T100SceneEditorEntityPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100SceneEditorEntityPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100SceneEditorEntityPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(204,123), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxPoint(28,40), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Notebook1->AddPage(Panel1, _("Entity"), false);
	Notebook1->AddPage(Panel2, _("Page name"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100SceneEditorEntityPanel::~T100SceneEditorEntityPanel()
{
	//(*Destroy(T100SceneEditorEntityPanel)
	//*)
}

