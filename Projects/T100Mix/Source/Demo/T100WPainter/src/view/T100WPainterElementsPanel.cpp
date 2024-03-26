#include "../../include/view/T100WPainterElementsPanel.h"

//(*InternalHeaders(T100WPainterElementsPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100ElementInfo.h"
#include "T100WxEventData.h"
#include "T100WPainterCallback.h"
#include "T100WPainterElementsPanelLoadThreadTask.h"

//(*IdInit(T100WPainterElementsPanel)
const long T100WPainterElementsPanel::ID_LISTVIEW1 = wxNewId();
const long T100WPainterElementsPanel::ID_LISTVIEW2 = wxNewId();
const long T100WPainterElementsPanel::ID_LISTVIEW3 = wxNewId();
const long T100WPainterElementsPanel::ID_NOTEBOOK1 = wxNewId();
//*)

const long T100WPainterElementsPanel::ID_THREAD_IMAGE = wxNewId();

BEGIN_EVENT_TABLE(T100WPainterElementsPanel,wxPanel)
	//(*EventTable(T100WPainterElementsPanel)
	//*)
	EVT_THREAD(ID_THREAD_IMAGE, T100WPainterElementsPanel::OnThreadImage)
END_EVENT_TABLE()

T100WPainterElementsPanel::T100WPainterElementsPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
	create();
}

void T100WPainterElementsPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100WPainterElementsPanel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	ListView1 = new wxListView(Notebook1, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_ICON, wxDefaultValidator, _T("ID_LISTVIEW1"));
	ListView2 = new wxListView(Notebook1, ID_LISTVIEW2, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW2"));
	ListView3 = new wxListView(Notebook1, ID_LISTVIEW3, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW3"));
	Notebook1->AddPage(ListView1, _("Page name"), false);
	Notebook1->AddPage(ListView2, _("Page name"), false);
	Notebook1->AddPage(ListView3, _("Page name"), false);
	BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	ImageList1 = new wxImageList(64, 64, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100WPainterElementsPanel::OnListView1ItemSelect);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&T100WPainterElementsPanel::OnListView1ItemDeselect);
	//*)
}

T100WPainterElementsPanel::~T100WPainterElementsPanel()
{
	//(*Destroy(T100WPainterElementsPanel)
	//*)
	destroy();
}

T100VOID T100WPainterElementsPanel::create()
{
    ListView1->SetImageList(ImageList1, wxIMAGE_LIST_NORMAL);

    T100WPainterElementsPanelLoadThreadTask*                task            = T100NULL;

    task    = T100NEW T100WPainterElementsPanelLoadThreadTask();

    task->setPanel(this);
    task->start();
}

T100VOID T100WPainterElementsPanel::destroy()
{

}

void T100WPainterElementsPanel::OnThreadImage(wxThreadEvent& event)
{
    wxImage*        image;
    long            id;

    image   = dynamic_cast<wxImage*>(event.GetEventObject());

    if(image){
        id  = ListView1->InsertItem(0, wxT("Test"), 0);

        T100ElementInfo*    info        = T100NEW T100ElementInfo();
        wxUIntPtr           data        = (wxUIntPtr)info;

        info->type  = 1;
        ListView1->SetItemPtrData(id, data);
    }
}


void T100WPainterElementsPanel::OnListView1ItemSelect(wxListEvent& event)
{
    wxUIntPtr               data            = event.GetData();
    T100ElementInfo*        info            = T100NULL;

    info    = (T100ElementInfo*)data;

    int type    = info->type;

    T100WPainterCallback::elements_item_select((void*)data);
}

void T100WPainterElementsPanel::OnListView1ItemDeselect(wxListEvent& event)
{
}
