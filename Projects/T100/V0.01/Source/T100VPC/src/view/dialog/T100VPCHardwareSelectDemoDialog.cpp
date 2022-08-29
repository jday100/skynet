#include "../../../include/view/dialog/T100VPCHardwareSelectDemoDialog.h"

//(*InternalHeaders(T100VPCHardwareSelectDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCHardwareSelectDemoDialog)
const long T100VPCHardwareSelectDemoDialog::ID_LISTVIEW1 = wxNewId();
const long T100VPCHardwareSelectDemoDialog::ID_BUTTON1 = wxNewId();
const long T100VPCHardwareSelectDemoDialog::ID_BUTTON2 = wxNewId();
const long T100VPCHardwareSelectDemoDialog::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCHardwareSelectDemoDialog,wxDialog)
	//(*EventTable(T100VPCHardwareSelectDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCHardwareSelectDemoDialog::T100VPCHardwareSelectDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCHardwareSelectDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCHardwareSelectDemoDialog)
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
	Button2 = new wxButton(this, ID_BUTTON2, _("设置"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	ImageList1 = new wxImageList(16, 16, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

T100VPCHardwareSelectDemoDialog::~T100VPCHardwareSelectDemoDialog()
{
	//(*Destroy(T100VPCHardwareSelectDemoDialog)
	//*)
}


void T100VPCHardwareSelectDemoDialog::OnCloseButtonClick(wxCommandEvent& event)
{
}

void T100VPCHardwareSelectDemoDialog::OnSettingButtonClick(wxCommandEvent& event)
{
}

void T100VPCHardwareSelectDemoDialog::OnAppendButtonClick(wxCommandEvent& event)
{
}
