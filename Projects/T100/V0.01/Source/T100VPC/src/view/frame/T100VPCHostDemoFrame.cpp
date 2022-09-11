#include "../../../include/view/frame/T100VPCHostDemoFrame.h"

//(*InternalHeaders(T100VPCHostDemoFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCHostDemoFrame)
const long T100VPCHostDemoFrame::ID_PANEL1 = wxNewId();
const long T100VPCHostDemoFrame::ID_MENU_LOAD = wxNewId();
const long T100VPCHostDemoFrame::ID_MENU_RUN = wxNewId();
const long T100VPCHostDemoFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCHostDemoFrame,wxFrame)
	//(*EventTable(T100VPCHostDemoFrame)
	//*)
END_EVENT_TABLE()

T100VPCHostDemoFrame::T100VPCHostDemoFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCHostDemoFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCHostDemoFrame)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuLoad = new wxMenuItem(Menu1, ID_MENU_LOAD, _("Load"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuLoad);
	MenuRun = new wxMenuItem(Menu1, ID_MENU_RUN, _("Run"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuRun);
	MenuBar1->Append(Menu1, _("File"));
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_MENU_LOAD,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCHostDemoFrame::OnMenuLoadSelected);
	Connect(ID_MENU_RUN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCHostDemoFrame::OnMenuRunSelected);
	//*)
}

T100VPCHostDemoFrame::~T100VPCHostDemoFrame()
{
	//(*Destroy(T100VPCHostDemoFrame)
	//*)
}


void T100VPCHostDemoFrame::OnMenuLoadSelected(wxCommandEvent& event)
{
}

void T100VPCHostDemoFrame::OnMenuRunSelected(wxCommandEvent& event)
{
}
