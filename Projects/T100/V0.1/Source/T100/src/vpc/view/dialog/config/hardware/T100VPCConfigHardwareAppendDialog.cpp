#include "T100VPCConfigHardwareAppendDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

namespace T100VPC{
const long T100VPCConfigHardwareAppendDialog::ID_LISTVIEW = wxNewId();
const long T100VPCConfigHardwareAppendDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCConfigHardwareAppendDialog::ID_BUTTON_FINISH = wxNewId();

BEGIN_EVENT_TABLE(T100VPCConfigHardwareAppendDialog, wxDialog)

END_EVENT_TABLE()

T100VPCConfigHardwareAppendDialog::T100VPCConfigHardwareAppendDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);

    load();
}

T100VPCConfigHardwareAppendDialog::~T100VPCConfigHardwareAppendDialog()
{
    //dtor
}

void T100VPCConfigHardwareAppendDialog::BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	ListView = new wxListView(this, ID_LISTVIEW, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW"));
	BoxSizer2->Add(ListView, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	AppendButton = new wxButton(this, ID_BUTTON_APPEND, _("添加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_APPEND"));
	BoxSizer3->Add(AppendButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FinishButton = new wxButton(this, ID_BUTTON_FINISH, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_FINISH"));
	BoxSizer3->Add(FinishButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	ImageList = new wxImageList(16, 16, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTVIEW,        wxEVT_COMMAND_LIST_ITEM_SELECTED,   (wxObjectEventFunction)&T100VPCConfigHardwareAppendDialog::OnListViewItemSelect);
	Connect(ID_BUTTON_APPEND,   wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T100VPCConfigHardwareAppendDialog::OnButtonAppendClick);
	Connect(ID_BUTTON_FINISH,   wxEVT_COMMAND_BUTTON_CLICKED,       (wxObjectEventFunction)&T100VPCConfigHardwareAppendDialog::OnButtonFinishClick);

}

T100VOID T100VPCConfigHardwareAppendDialog::load()
{
    m_cu        = T100NEW T100CUDeviceInfo();
    m_au        = T100NEW T100AUDeviceInfo();
    m_memory    = T100NEW T100MemoryInfo();
    m_port      = T100NEW T100PortDeviceInfo();

    m_display   = T100NEW T100DisplayInfo();
    m_disk      = T100NEW T100DiskInfo();
    m_keyboard  = T100NEW T100KeyboardInfo();
    m_mouse     = T100NEW T100MouseInfo();

    m_cu->insert(ListView);
    m_au->insert(ListView);
    m_memory->insert(ListView);
    m_port->insert(ListView);

    m_display->insert(ListView);
    m_disk->insert(ListView);
    m_keyboard->insert(ListView);
    m_mouse->insert(ListView);
}

void T100VPCConfigHardwareAppendDialog::OnListViewItemSelect(wxListEvent& event)
{
    T100LONG        index;
    wxUIntPtr       data;

    index = event.GetIndex();

    data = ListView->GetItemData(index);

    if(data){
        m_current = (T100DeviceInfo*)data;
    }
}

void T100VPCConfigHardwareAppendDialog::OnButtonAppendClick(wxCommandEvent& event)
{
    if(m_current){
        if(!m_current->verify()){
            m_current->setup();
        }
    }
}

void T100VPCConfigHardwareAppendDialog::OnButtonFinishClick(wxCommandEvent& event)
{
    Close();
}

}
