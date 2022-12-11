#include "T100VPCConfigHardwareDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

#include "icons/wxwin16x16.xpm"

#include "T100VPCSetup.h"
#include "T100VPCCallback.h"


namespace T100VPC{
const long T100VPCConfigHardwareDialog::ID_LISTVIEW = wxNewId();
const long T100VPCConfigHardwareDialog::ID_BUTTON_SETUP = wxNewId();
const long T100VPCConfigHardwareDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCConfigHardwareDialog::ID_BUTTON_REMOVE = wxNewId();
const long T100VPCConfigHardwareDialog::ID_BUTTON_FINISH = wxNewId();

BEGIN_EVENT_TABLE(T100VPCConfigHardwareDialog, wxDialog)

END_EVENT_TABLE()


T100VPCConfigHardwareDialog::T100VPCConfigHardwareDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100VPCConfigHardwareDialog::~T100VPCConfigHardwareDialog()
{
    //dtor
}

void T100VPCConfigHardwareDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView  = new wxListView(this, ID_LISTVIEW, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW"));
	BoxSizer2->Add(ListView, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	SetupButton = new wxButton(this, ID_BUTTON_SETUP, _("设置"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SETUP"));
	BoxSizer3->Add(SetupButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	BoxSizer3->Add(AppendButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RemoveButton = new wxButton(this, ID_BUTTON_REMOVE, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_REMOVE"));
	BoxSizer3->Add(RemoveButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FinishButton = new wxButton(this, ID_BUTTON_FINISH, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FINISH"));
	BoxSizer3->Add(FinishButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	ImageList = new wxImageList(16, 16, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON_SETUP,    wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100VPCConfigHardwareDialog::OnButtonSetupClick);
	Connect(ID_BUTTON_APPEND,   wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100VPCConfigHardwareDialog::OnButtonAppendClick);
	Connect(ID_BUTTON_REMOVE,   wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100VPCConfigHardwareDialog::OnButtonRemoveClick);
	Connect(ID_BUTTON_FINISH,   wxEVT_COMMAND_BUTTON_CLICKED,   (wxObjectEventFunction)&T100VPCConfigHardwareDialog::OnButtonFinishClick);

    //ImageList->Add(wxIcon(wxT("wxwin16x16_xpm")), wxBITMAP_TYPE_ICO_RESOURCE);
    //ListView->SetImageList(ImageList, wxIMAGE_LIST_NORMAL);
}

void T100VPCConfigHardwareDialog::OnButtonSetupClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_hardware_setup();
}

void T100VPCConfigHardwareDialog::OnButtonAppendClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_hardware_append();
}

void T100VPCConfigHardwareDialog::OnButtonRemoveClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_hardware_remove();
}

void T100VPCConfigHardwareDialog::OnButtonFinishClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_hardware_finish();
    Close();
}

T100VPCConfigHardwareAppendDialog* T100VPCConfigHardwareDialog::getAppendDialog()
{
    if(!m_append_dialog){
        m_append_dialog = T100NEW T100VPCConfigHardwareAppendDialog(this);
    }
    return m_append_dialog;
}

T100BOOL T100VPCConfigHardwareDialog::load()
{
    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        ListView->InsertItem(ListView->GetItemCount(), item->name.to_wstring());
    }
    return T100TRUE;
}

}
