#include "../../../include/view/dialog/T100VPCHardwareDemoDialog.h"

//(*InternalHeaders(T100VPCHardwareDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VPCHardwareSelectDemoDialog.h"

//(*IdInit(T100VPCHardwareDemoDialog)
const long T100VPCHardwareDemoDialog::ID_LISTVIEW_HARDWARE = wxNewId();
const long T100VPCHardwareDemoDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCHardwareDemoDialog::ID_BUTTON_REMOVE = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCHardwareDemoDialog,wxDialog)
	//(*EventTable(T100VPCHardwareDemoDialog)
	//*)
END_EVENT_TABLE()

T100VPCHardwareDemoDialog::T100VPCHardwareDemoDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCHardwareDemoDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCHardwareDemoDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,300));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	HardwareListView = new wxListView(this, ID_LISTVIEW_HARDWARE, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW_HARDWARE"));
	BoxSizer2->Add(HardwareListView, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	BoxSizer3->Add(AppendButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RemoveButton = new wxButton(this, ID_BUTTON_REMOVE, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	BoxSizer3->Add(RemoveButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CloseButton = new wxButton(this, wxID_CLOSE, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CLOSE"));
	BoxSizer3->Add(CloseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	ImageList = new wxImageList(16, 16, 1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_LISTVIEW_HARDWARE,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100VPCHardwareDemoDialog::OnHardwareListViewItemSelect);
	Connect(ID_BUTTON_APPEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDemoDialog::OnAppendButtonClick);
	Connect(ID_BUTTON_REMOVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDemoDialog::OnRemoveButtonClick);
	Connect(wxID_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDemoDialog::OnCloseButtonClick);
	//*)
}

T100VPCHardwareDemoDialog::~T100VPCHardwareDemoDialog()
{
	//(*Destroy(T100VPCHardwareDemoDialog)
	//*)
}


void T100VPCHardwareDemoDialog::OnAppendButtonClick(wxCommandEvent& event)
{
    T100VPCHardwareSelectDemoDialog     dialog(this);

    if(dialog.ShowModal() == wxID_OK){

    }
}

void T100VPCHardwareDemoDialog::OnRemoveButtonClick(wxCommandEvent& event)
{
}

void T100VPCHardwareDemoDialog::OnHardwareListViewItemSelect(wxListEvent& event)
{
}

void T100VPCHardwareDemoDialog::OnCloseButtonClick(wxCommandEvent& event)
{
}
