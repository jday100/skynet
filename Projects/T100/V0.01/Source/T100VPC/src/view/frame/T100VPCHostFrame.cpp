#include "T100VPCHostFrame.h"

#include <wx/intl.h>
#include <wx/string.h>

#include "T100VPCSetup.h"
#include "T100VPCCallback.h"


const long T100VPCHostFrame::ID_MENU_LOAD = wxNewId();
const long T100VPCHostFrame::ID_MENU_RUN = wxNewId();
const long T100VPCHostFrame::ID_STATUSBAR1 = wxNewId();

BEGIN_EVENT_TABLE(T100VPCHostFrame,wxFrame)

END_EVENT_TABLE()

T100VPCHostFrame::T100VPCHostFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
    create();
}

T100VPCHostFrame::~T100VPCHostFrame()
{
    //dtor
    destroy();
}

void T100VPCHostFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
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

	Connect(ID_MENU_LOAD,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCHostFrame::OnMenuLoadSelected);
	Connect(ID_MENU_RUN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VPCHostFrame::OnMenuRunSelected);

}

T100VOID T100VPCHostFrame::create()
{
    SetSize(T100VPCSetup::SCREEN_WIDTH, T100VPCSetup::SCREEN_HEIGHT);
}

T100VOID T100VPCHostFrame::destroy()
{

}

void T100VPCHostFrame::OnMenuLoadSelected(wxCommandEvent& event)
{
    T100VPCCallback::host_menu_load(this);
}

void T100VPCHostFrame::OnMenuRunSelected(wxCommandEvent& event)
{
    T100VPCCallback::host_menu_run(this);
}
