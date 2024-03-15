#include "../include/T100PaintElementsPanel.h"

//(*InternalHeaders(T100PaintElementsPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/image.h>

//(*IdInit(T100PaintElementsPanel)
const long T100PaintElementsPanel::ID_LISTVIEW1 = wxNewId();
const long T100PaintElementsPanel::ID_LISTVIEW2 = wxNewId();
const long T100PaintElementsPanel::ID_LISTVIEW3 = wxNewId();
const long T100PaintElementsPanel::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100PaintElementsPanel,wxPanel)
	//(*EventTable(T100PaintElementsPanel)
	//*)
END_EVENT_TABLE()

T100PaintElementsPanel::T100PaintElementsPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
	create();
}

void T100PaintElementsPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100PaintElementsPanel)
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
	static const char *ImageList1_0_XPM[] = {
	"64 64 58 1",
	"* c Black",
	"0 c #696969",
	"> c #B4B4B4",
	"t c #C3C3C3",
	"i c #D2D2D2",
	", c #262626",
	"n c #F0F0F0",
	"_ c #FFFFFF",
	"o c #ADADAD",
	"j c #CBCBCB",
	"3 c #6A6A6A",
	"4 c #A6A6A6",
	"v c #C4C4C4",
	"p c #727272",
	"c c #818181",
	"9 c #B6B6B6",
	"b c #C5C5C5",
	"M c #828282",
	"y c #BEBEBE",
	"w c #CDCDCD",
	"g c #EBEBEB",
	"8 c #FAFAFA",
	"- c #A8A8A8",
	"x c #E4E4E4",
	"N c #565656",
	"z c #656565",
	"f c #A1A1A1",
	"$ c #BFBFBF",
	"X c #CECECE",
	"; c #222222",
	"@ c #404040",
	"O c #8B8B8B",
	"u c #9A9A9A",
	"q c #B8B8B8",
	"h c #E5E5E5",
	"V c #2A2A2A",
	": c #F4F4F4",
	"+ c #666666",
	"d c #DEDEDE",
	"m c #7D7D7D",
	"a c #AAAAAA",
	"s c #B9B9B9",
	"5 c #C8C8C8",
	"< c #D7D7D7",
	"= c #E6E6E6",
	"r c #585858",
	"k c #B2B2B2",
	"1 c #C1C1C1",
	"6 c #DFDFDF",
	". c #EEEEEE",
	"e c #FDFDFD",
	"& c #7E7E7E",
	"C c #E7E7E7",
	"2 c #3B3B3B",
	"B c #B3B3B3",
	"# c #161616",
	"7 c #EFEFEF",
	"l c #8E8E8E",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________.XoO+@####@+OoX.________________________",
	"_____________________.$&****************&$._____________________",
	"___________________=-;********************;-=___________________",
	"_________________:>,************************,>:_________________",
	"________________<&****************************&<________________",
	"_______________12**********3456776543**********21_______________",
	"_____________89*********0q=__________=q0*********98_____________",
	"____________8>********&we______________ew&********>8____________",
	"____________>*******rte__________________etr*******>____________",
	"___________y*******u=______________________=u*******y___________",
	"__________i,******98________________________89******,i__________",
	"_________.p******1____________________________1******p._________",
	"_________a******s______________________________s******a_________",
	"________d******fe______________________________ef******d________",
	"________u*****3g________________________________g3*****u________",
	"_______h******j__________________________________j******h_______",
	"_______k*****l____________________________________l*****k_______",
	"_______z*****<____________________________________<*****z_______",
	"______x*****c______________________________________c*****x______",
	"______v*****b______________________________________b*****v______",
	"______f*****n______________________________________n*****f______",
	"______m****M________________________________________M****m______",
	"______N****B________________________________________B****N______",
	"______V****i________________________________________i****V______",
	"______*****C________________________________________C*****______",
	"______*****:________________________________________:*****______",
	"______*****C________________________________________C*****______",
	"______V****i________________________________________i****V______",
	"______N****B________________________________________B****N______",
	"______m****M________________________________________M****m______",
	"______f*****n______________________________________n*****f______",
	"______v*****b______________________________________b*****v______",
	"______x*****c______________________________________c*****x______",
	"_______z*****<____________________________________<*****z_______",
	"_______k*****l____________________________________l*****k_______",
	"_______h******j__________________________________j******h_______",
	"________u*****3g________________________________g3*****u________",
	"________d******fe______________________________ef******d________",
	"_________a******s______________________________s******a_________",
	"_________.p******1____________________________1******p._________",
	"__________i,******98________________________89******,i__________",
	"___________y*******u=______________________=u*******y___________",
	"____________>*******rte__________________etr*******>____________",
	"____________8>********&we______________ew&********>8____________",
	"_____________89*********0q=__________=q0*********98_____________",
	"_______________12**********3456776543**********21_______________",
	"________________<&****************************&<________________",
	"_________________:>,************************,>:_________________",
	"___________________=-;********************;-=___________________",
	"_____________________.$&****************&$._____________________",
	"________________________.XoO+@####@+OoX.________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________",
	"________________________________________________________________"
	};
	ImageList1 = new wxImageList(64, 64, 2);
	ImageList1->Add(wxBitmap(ImageList1_0_XPM));
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100PaintElementsPanel::OnListView1ItemSelect);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&T100PaintElementsPanel::OnListView1ItemDeselect);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&T100PaintElementsPanel::OnListView1ItemActivated);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_FOCUSED,(wxObjectEventFunction)&T100PaintElementsPanel::OnListView1ItemFocused);
	//*)
}

T100PaintElementsPanel::~T100PaintElementsPanel()
{
	//(*Destroy(T100PaintElementsPanel)
	//*)

	destroy();
}

void T100PaintElementsPanel::create()
{
    bool        result;
    wxImage     image;

    result  = image.LoadFile(wxT("images\\circle.png"), wxBITMAP_TYPE_PNG);

    ImageList1->Add(image);

    ListView1->SetImageList(ImageList1, wxIMAGE_LIST_NORMAL);
    ListView1->InsertItem(0, wxT("Circle"), 1);
}

void T100PaintElementsPanel::destroy()
{

}


void T100PaintElementsPanel::OnListView1ItemSelect(wxListEvent& event)
{
}

void T100PaintElementsPanel::OnListView1ItemDeselect(wxListEvent& event)
{
}

void T100PaintElementsPanel::OnListView1ItemFocused(wxListEvent& event)
{
}

void T100PaintElementsPanel::OnListView1ItemActivated(wxListEvent& event)
{
}
