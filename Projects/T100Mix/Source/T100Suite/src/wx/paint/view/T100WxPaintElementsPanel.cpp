#include "T100WxPaintElementsPanel.h"

#include <wx/intl.h>
#include <wx/string.h>


const long T100WxPaintElementsPanel::ID_NOTEBOOK1 = wxNewId();
const long T100WxPaintElementsPanel::ID_LISTVIEW1 = wxNewId();
const long T100WxPaintElementsPanel::ID_LISTVIEW2 = wxNewId();
const long T100WxPaintElementsPanel::ID_LISTVIEW3 = wxNewId();

BEGIN_EVENT_TABLE(T100WxPaintElementsPanel,wxPanel)

END_EVENT_TABLE()


T100WxPaintElementsPanel::T100WxPaintElementsPanel(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size ,
            long style,
            const wxString& name)
{
    //ctor
    BuildContent(parent,winid,pos,size);
    create();
}

T100WxPaintElementsPanel::~T100WxPaintElementsPanel()
{
    //dtor
    destroy();
}

void T100WxPaintElementsPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(266,412), 0, _T("ID_NOTEBOOK1"));
	ListView1 = new wxListView(Notebook1, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_ICON, wxDefaultValidator, _T("ID_LISTVIEW1"));
	ListView2 = new wxListView(Notebook1, ID_LISTVIEW2, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW2"));
	ListView3 = new wxListView(Notebook1, ID_LISTVIEW3, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW3"));
	Notebook1->AddPage(ListView1, _("Page name"), false);
	Notebook1->AddPage(ListView2, _("Page name"), false);
	Notebook1->AddPage(ListView3, _("Page name"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	ImageList1 = new wxImageList(64, 64, 2);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
}

T100VOID T100WxPaintElementsPanel::create()
{
    m_load_task = T100NEW T100WxPaintElementsLoadThreadTask();
}

T100VOID T100WxPaintElementsPanel::destroy()
{
    T100SAFE_DELETE(m_load_task)
}
