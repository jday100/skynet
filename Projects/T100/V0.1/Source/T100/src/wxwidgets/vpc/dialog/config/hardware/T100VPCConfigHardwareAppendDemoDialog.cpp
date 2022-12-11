#include "../../../../../../include/wxwidgets/vpc/dialog/config/hardware/T100VPCConfigHardwareAppendDemoDialog.h"

//(*InternalHeaders(T100VPCConfigHardwareAppendDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCConfigHardwareAppendDemoDialog)
const long T100VPCConfigHardwareAppendDemoDialog::ID_LISTVIEW1 = wxNewId();
const long T100VPCConfigHardwareAppendDemoDialog::ID_BUTTON1 = wxNewId();
const long T100VPCConfigHardwareAppendDemoDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCConfigHardwareAppendDemoDialog,wxDialog)
	//(*EventTable(T100VPCConfigHardwareAppendDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCConfigHardwareAppendDemoDialog::T100VPCConfigHardwareAppendDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCConfigHardwareAppendDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCConfigHardwareAppendDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(ListView1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	ImageList1 = new wxImageList(16, 16, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100VPCConfigHardwareAppendDemoDialog::OnListView1ItemSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCConfigHardwareAppendDemoDialog::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCConfigHardwareAppendDemoDialog::OnButton2Click);
	//*)
}

T100VPCConfigHardwareAppendDemoDialog::~T100VPCConfigHardwareAppendDemoDialog()
{
	//(*Destroy(T100VPCConfigHardwareAppendDemoDialog)
	//*)
}


void T100VPCConfigHardwareAppendDemoDialog::OnListView1ItemSelect(wxListEvent& event)
{
}

void T100VPCConfigHardwareAppendDemoDialog::OnButton1Click(wxCommandEvent& event)
{
}

void T100VPCConfigHardwareAppendDemoDialog::OnButton2Click(wxCommandEvent& event)
{
}
