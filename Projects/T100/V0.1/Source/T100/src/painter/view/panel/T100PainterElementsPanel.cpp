#include "T100PainterElementsPanel.h"

#include <wx/intl.h>
#include <wx/string.h>

#include "T100PainterCallback.h"
#include "T100ElementBase.h"


namespace T100Painter{

const long T100PainterElementsPanel::ID_NOTEBOOK1 = wxNewId();

const long T100PainterElementsPanel::ID_PANEL1 = wxNewId();
const long T100PainterElementsPanel::ID_PANEL2 = wxNewId();
const long T100PainterElementsPanel::ID_PANEL3 = wxNewId();

const long T100PainterElementsPanel::ID_LISTVIEW1 = wxNewId();
const long T100PainterElementsPanel::ID_LISTVIEW2 = wxNewId();
const long T100PainterElementsPanel::ID_LISTVIEW3 = wxNewId();


BEGIN_EVENT_TABLE(T100PainterElementsPanel,wxPanel)

END_EVENT_TABLE()


T100PainterElementsPanel::T100PainterElementsPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100PainterElementsPanel::~T100PainterElementsPanel()
{
    //dtor
}

void T100PainterElementsPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
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
	BoxSizer2->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(4,9), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ListView2 = new wxListView(Panel2, ID_LISTVIEW2, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW2"));
	BoxSizer3->Add(ListView2, 1, wxALL|wxEXPAND, 5);
	Panel2->SetSizer(BoxSizer3);
	BoxSizer3->Fit(Panel2);
	BoxSizer3->SetSizeHints(Panel2);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(7,12), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	ListView3 = new wxListView(Panel3, ID_LISTVIEW3, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW3"));
	BoxSizer4->Add(ListView3, 1, wxALL|wxEXPAND, 5);
	Panel3->SetSizer(BoxSizer4);
	BoxSizer4->Fit(Panel3);
	BoxSizer4->SetSizeHints(Panel3);
	Notebook1->AddPage(Panel1, _("Graphic"), false);
	Notebook1->AddPage(Panel2, _("Diagram"), false);
	Notebook1->AddPage(Panel3, _("Other"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&T100PainterElementsPanel::OnNotebook1PageChanged);

    Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100PainterElementsPanel::OnPanel1ListCtrlItemSelect);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&T100PainterElementsPanel::OnPanel1ListCtrlItemDeselect);

    Connect(ID_LISTVIEW2,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100PainterElementsPanel::OnPanel2ListCtrlItemSelect);
	Connect(ID_LISTVIEW2,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&T100PainterElementsPanel::OnPanel2ListCtrlItemDeselect);

    Connect(ID_LISTVIEW3,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100PainterElementsPanel::OnPanel3ListCtrlItemSelect);
	Connect(ID_LISTVIEW3,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&T100PainterElementsPanel::OnPanel3ListCtrlItemDeselect);

}

T100BOOL T100PainterElementsPanel::Append(wxString panel, T100ElementBase* element)
{
    if(wxT("Graphic") == panel){
        element->Append(ListView1);
    }else if(wxT("Diagram") == panel){
        element->Append(ListView2);
    }else if(wxT("Other") == panel){
        element->Append(ListView3);
    }

    return T100TRUE;
}

void T100PainterElementsPanel::OnNotebook1PageChanged(wxNotebookEvent& event)
{
}

void T100PainterElementsPanel::OnPanel1ListCtrlItemSelect(wxListEvent& event)
{
    T100LONG        index;
    wxUIntPtr       ptr;
    T100STRING*     key         = T100NULL;

    index = event.GetIndex();

    ptr = ListView1->GetItemData(index);

    key = (T100STRING*)ptr;

    if(key){
        T100PainterCallback::view_element_select(key);
    }
}

void T100PainterElementsPanel::OnPanel1ListCtrlItemDeselect(wxListEvent& event)
{

}

void T100PainterElementsPanel::OnPanel2ListCtrlItemSelect(wxListEvent& event)
{
    T100LONG        index;
    wxUIntPtr       ptr;
    T100STRING*     key         = T100NULL;

    index = event.GetIndex();

    ptr = ListView2->GetItemData(index);

    key = (T100STRING*)ptr;

    if(key){
        T100PainterCallback::view_element_select(key);
    }

    event.Skip();
}

void T100PainterElementsPanel::OnPanel2ListCtrlItemDeselect(wxListEvent& event)
{

}

void T100PainterElementsPanel::OnPanel3ListCtrlItemSelect(wxListEvent& event)
{
    T100LONG        index;
    wxUIntPtr       ptr;
    T100STRING*     key         = T100NULL;

    index = event.GetIndex();

    ptr = ListView3->GetItemData(index);

    key = (T100STRING*)ptr;

    if(key){
        T100PainterCallback::view_element_select(key);
    }

    event.Skip();
}

void T100PainterElementsPanel::OnPanel3ListCtrlItemDeselect(wxListEvent& event)
{

}

}
