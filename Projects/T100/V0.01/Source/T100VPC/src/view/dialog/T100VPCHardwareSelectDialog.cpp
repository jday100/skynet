#include "T100VPCHardwareSelectDialog.h"

#include <wx/intl.h>
#include <wx/string.h>
#include "T100VPCSetup.h"


const long T100VPCHardwareSelectDialog::ID_LISTVIEW_DEVICE = wxNewId();
const long T100VPCHardwareSelectDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCHardwareSelectDialog::ID_BUTTON_SETTING = wxNewId();
const long T100VPCHardwareSelectDialog::ID_BUTTON_CLOSE = wxNewId();


BEGIN_EVENT_TABLE(T100VPCHardwareSelectDialog,wxDialog)

END_EVENT_TABLE()


T100VPCHardwareSelectDialog::T100VPCHardwareSelectDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
    create();
}

T100VPCHardwareSelectDialog::~T100VPCHardwareSelectDialog()
{
    //dtor
    destroy();
}

void T100VPCHardwareSelectDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	DeviceListView = new wxListView(this, ID_LISTVIEW_DEVICE, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	BoxSizer2->Add(DeviceListView, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	BoxSizer3->Add(AppendButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SettingButton = new wxButton(this, ID_BUTTON_SETTING, _("设置"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SETTING"));
	BoxSizer3->Add(SettingButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CloseButton = new wxButton(this, ID_BUTTON_CLOSE, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLOSE"));
	BoxSizer3->Add(CloseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON_APPEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareSelectDialog::OnAppendButtonClick);
	Connect(ID_BUTTON_SETTING,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareSelectDialog::OnSettingButtonClick);
	Connect(ID_BUTTON_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareSelectDialog::OnCloseButtonClick);

	//BoxSizer1->Add(CreateStdDialogButtonSizer(wxOK | wxCANCEL),
    //               wxSizerFlags().Right().Border());

    //SetSizerAndFit(BoxSizer1);
}

T100VOID T100VPCHardwareSelectDialog::create()
{
    init();
}

T100VOID T100VPCHardwareSelectDialog::destroy()
{

}

T100VOID T100VPCHardwareSelectDialog::init()
{
    DeviceListView->InsertItem(DeviceListView->GetItemCount(), m_disk_info.name.to_wstring());
    DeviceListView->InsertItem(DeviceListView->GetItemCount(), m_display_info.name.to_wstring());
    DeviceListView->InsertItem(DeviceListView->GetItemCount(), m_keyboard_info.name.to_wstring());
    DeviceListView->InsertItem(DeviceListView->GetItemCount(), m_mouse_info.name.to_wstring());

}

void T100VPCHardwareSelectDialog::OnCloseButtonClick(wxCommandEvent& event)
{
    EndModal(wxID_OK);
}

void T100VPCHardwareSelectDialog::OnSettingButtonClick(wxCommandEvent& event)
{
}

void T100VPCHardwareSelectDialog::OnAppendButtonClick(wxCommandEvent& event)
{
}
