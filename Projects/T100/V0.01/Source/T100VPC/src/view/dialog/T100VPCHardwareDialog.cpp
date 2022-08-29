#include "T100VPCHardwareDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

#include "icons/wxwin16x16.xpm"

#include "T100VPCCallback.h"
#include "T100VPCSetup.h"
#include "T100DeviceInfo.h"
#include "T100DiskInfo.h"
#include "T100DisplayInfo.h"
#include "T100KeyboardInfo.h"
#include "T100MouseInfo.h"


const long T100VPCHardwareDialog::ID_LISTVIEW_HARDWARE = wxNewId();
const long T100VPCHardwareDialog::ID_BUTTON_APPEND = wxNewId();
const long T100VPCHardwareDialog::ID_BUTTON_REMOVE = wxNewId();
const long T100VPCHardwareDialog::ID_BUTTON_CLOSE = wxNewId();

BEGIN_EVENT_TABLE(T100VPCHardwareDialog,wxDialog)

END_EVENT_TABLE()


T100VPCHardwareDialog::T100VPCHardwareDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
    create();
}

T100VPCHardwareDialog::~T100VPCHardwareDialog()
{
    //dtor
    destroy();
}

void T100VPCHardwareDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
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
	CloseButton = new wxButton(this, ID_BUTTON_CLOSE, _("完成"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CLOSE"));
	BoxSizer3->Add(CloseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	ImageList = new wxImageList(16, 16, 1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_LISTVIEW_HARDWARE,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&T100VPCHardwareDialog::OnHardwareListViewItemSelect);
	Connect(ID_BUTTON_APPEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDialog::OnAppendButtonClick);
	Connect(ID_BUTTON_REMOVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDialog::OnRemoveButtonClick);
	Connect(ID_BUTTON_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&T100VPCHardwareDialog::OnCloseButtonClick);

}

T100VOID T100VPCHardwareDialog::create()
{
    //ImageList->Add(wxIcon(wxT("wxwin16x16_xpm")), wxBITMAP_TYPE_ICO_RESOURCE);
    //HardwareListView->SetImageList(ImageList, wxIMAGE_LIST_NORMAL);

    load();
}

T100VOID T100VPCHardwareDialog::destroy()
{

}

T100BOOL T100VPCHardwareDialog::init()
{
    T100DiskInfo*       disk;
    T100DisplayInfo*    display;
    T100KeyboardInfo*   keyboard;
    T100MouseInfo*      mouse;

    disk        = T100NEW T100DiskInfo();
    display     = T100NEW T100DisplayInfo();
    keyboard    = T100NEW T100KeyboardInfo();
    mouse       = T100NEW T100MouseInfo();

    disk->length    = 1024 * 1024 * 64;
    T100VPCSetup::appendDevice(disk);

    T100VPCSetup::appendDevice(display);
    T100VPCSetup::appendDevice(keyboard);
    T100VPCSetup::appendDevice(mouse);

    return T100TRUE;
}

T100BOOL T100VPCHardwareDialog::load()
{
    if(T100VPCSetup::getDevices().empty()){
        if(!init()){
            return T100FALSE;
        }
    }

    for(T100DeviceInfo* item : T100VPCSetup::getDevices()){
        //HardwareListView->InsertItem(0, item->name.to_wstring(), 0);
        HardwareListView->InsertItem(HardwareListView->GetItemCount(), item->name.to_wstring());
    }

    return T100TRUE;
}

void T100VPCHardwareDialog::OnAppendButtonClick(wxCommandEvent& event)
{
    T100VPCCallback::frame_menu_hardware_select(this);
}

void T100VPCHardwareDialog::OnRemoveButtonClick(wxCommandEvent& event)
{
    if(-1 == m_index){
        return;
    }

    T100DeviceInfo*         info            = T100NULL;

    info = T100VPCSetup::getDevices()[m_index];

    if(info){
        if(T100VPCSetup::removeDevice(info)){
            HardwareListView->DeleteItem(m_index);
        }
    }

    return;
}

void T100VPCHardwareDialog::OnCloseButtonClick(wxCommandEvent& event)
{
    EndModal(wxID_OK);
}

void T100VPCHardwareDialog::OnHardwareListViewItemSelect(wxListEvent& event)
{
    m_index = event.GetIndex();
}
