#include "../../../../../../include/wxwidgets/vpc/dialog/config/hardware/T100VPCConfigHardwareDemoDialog.h"

//(*InternalHeaders(T100VPCConfigHardwareDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCConfigHardwareDemoDialog)
const long T100VPCConfigHardwareDemoDialog::ID_LISTVIEW1 = wxNewId();
const long T100VPCConfigHardwareDemoDialog::ID_BUTTON1 = wxNewId();
const long T100VPCConfigHardwareDemoDialog::ID_BUTTON2 = wxNewId();
const long T100VPCConfigHardwareDemoDialog::ID_BUTTON3 = wxNewId();
const long T100VPCConfigHardwareDemoDialog::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCConfigHardwareDemoDialog,wxDialog)
	//(*EventTable(T100VPCConfigHardwareDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCConfigHardwareDemoDialog::T100VPCConfigHardwareDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCConfigHardwareDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCConfigHardwareDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST|wxVSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(ListView1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("设置"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer3->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	ImageList1 = new wxImageList(16, 16, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCConfigHardwareDemoDialog::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCConfigHardwareDemoDialog::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCConfigHardwareDemoDialog::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCConfigHardwareDemoDialog::OnButton4Click);
	//*)
}

T100VPCConfigHardwareDemoDialog::~T100VPCConfigHardwareDemoDialog()
{
	//(*Destroy(T100VPCConfigHardwareDemoDialog)
	//*)
}


void T100VPCConfigHardwareDemoDialog::OnButton1Click(wxCommandEvent& event)
{
}

void T100VPCConfigHardwareDemoDialog::OnButton2Click(wxCommandEvent& event)
{
}

void T100VPCConfigHardwareDemoDialog::OnButton3Click(wxCommandEvent& event)
{
}

void T100VPCConfigHardwareDemoDialog::OnButton4Click(wxCommandEvent& event)
{
}
