#include "T100WxPaintElementsPanel.h"


const long T100WxPaintElementsPanel::ID_NOTEBOOK1 = wxNewId();

BEGIN_EVENT_TABLE(T100WxPaintElementsPanel,wxPanel)

END_EVENT_TABLE()


T100WxPaintElementsPanel::T100WxPaintElementsPanel(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size ,
            long style,
            const wxString& name)
    :wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
    BuildContent(parent,winid,pos,size);
}

T100WxPaintElementsPanel::~T100WxPaintElementsPanel()
{
    //dtor
}

void T100WxPaintElementsPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));

	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);

	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
}
