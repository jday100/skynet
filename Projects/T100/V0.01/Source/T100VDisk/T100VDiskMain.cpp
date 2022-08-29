/***************************************************************
 * Name:      T100VDiskMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100VDiskMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100VDiskFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100VDiskApp.h"
#include "T100VDiskCallback.h"


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(T100VDiskFrame)
const long T100VDiskFrame::ID_CUSTOM1 = wxNewId();
const long T100VDiskFrame::ID_PANEL1 = wxNewId();
const long T100VDiskFrame::ID_MENU_NEW = wxNewId();
const long T100VDiskFrame::ID_MENU_OPEN = wxNewId();
const long T100VDiskFrame::ID_MENU_SAVE = wxNewId();
const long T100VDiskFrame::ID_MENU_CLOSE = wxNewId();
const long T100VDiskFrame::idMenuQuit = wxNewId();
const long T100VDiskFrame::idMenuAbout = wxNewId();
const long T100VDiskFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VDiskFrame,wxFrame)
    //(*EventTable(T100VDiskFrame)
    //*)
END_EVENT_TABLE()

T100VDiskFrame::T100VDiskFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100VDiskFrame)
    wxBoxSizer* BoxSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuQuit;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    VDiskCtrl = new T100VDiskCtrl(Panel1,ID_CUSTOM1,wxDefaultPosition,wxSize(600,30),0,wxDefaultValidator,_T("ID_CUSTOM1"));
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuNew = new wxMenuItem(Menu1, ID_MENU_NEW, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuNew);
    MenuOpen = new wxMenuItem(Menu1, ID_MENU_OPEN, _("Open"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuOpen);
    MenuSave = new wxMenuItem(Menu1, ID_MENU_SAVE, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuSave);
    MenuClose = new wxMenuItem(Menu1, ID_MENU_CLOSE, _("Close"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuClose);
    Menu1->AppendSeparator();
    MenuQuit = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuQuit);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_MENU_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnMenuNewSelected);
    Connect(ID_MENU_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnMenuOpenSelected);
    Connect(ID_MENU_SAVE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnMenuSaveSelected);
    Connect(ID_MENU_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnMenuCloseSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VDiskFrame::OnAbout);
    //*)

    create();
}

T100VDiskFrame::~T100VDiskFrame()
{
    //(*Destroy(T100VDiskFrame)
    //*)

    destroy();
}

T100VOID T100VDiskFrame::create()
{
    wxGetApp().m_view.setFrame(this);

    T100VDiskCallback::init(&(wxGetApp().m_serve), &(wxGetApp().m_view));

    VDiskCtrl->SetSize(wxSize(600, 30));
    VDiskCtrl->SetLength(1024);

    VDiskCtrl->Hide();
}

T100VOID T100VDiskFrame::destroy()
{

}

void T100VDiskFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100VDiskFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100VDiskFrame::OnMenuNewSelected(wxCommandEvent& event)
{
    T100VDiskCallback::frame_menu_new(this);
}

void T100VDiskFrame::OnMenuOpenSelected(wxCommandEvent& event)
{
    T100VDiskCallback::frame_menu_open(this);
}

void T100VDiskFrame::OnMenuSaveSelected(wxCommandEvent& event)
{
}

void T100VDiskFrame::OnMenuCloseSelected(wxCommandEvent& event)
{
}

T100BOOL T100VDiskFrame::load(T100VDisk* vdisk)
{
    T100VFS_PART_VECTOR             parts;
    T100DISK_PART_VECTOR            ctrls;

    vdisk->part_list(parts);

    for(T100VFS_PART item : parts){
        T100DISK_PART*          part = T100NEW T100DISK_PART();

        part->LOCATION      = item.LOCATION;
        part->LENGTH        = item.LENGTH;
        //part->BOOT          = item->BOOT;

        ctrls.push_back(part);
    }

    VDiskCtrl->Load(ctrls);
    VDiskCtrl->Show();
}
