/***************************************************************
 * Name:      T100WxWidgetsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-08-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100WxWidgetsMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100WxWidgetsFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

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

//(*IdInit(T100WxWidgetsFrame)
const long T100WxWidgetsFrame::ID_CUSTOM1 = wxNewId();
const long T100WxWidgetsFrame::idMenuQuit = wxNewId();
const long T100WxWidgetsFrame::idMenuAbout = wxNewId();
const long T100WxWidgetsFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100WxWidgetsFrame,wxFrame)
    //(*EventTable(T100WxWidgetsFrame)
    //*)
END_EVENT_TABLE()

T100WxWidgetsFrame::T100WxWidgetsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100WxWidgetsFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("DiskCtrl："));
    DiskCtrl = new T100TestDiskCtrl(this,ID_CUSTOM1,wxDefaultPosition,wxSize(400,30),0,wxDefaultValidator,_T("ID_CUSTOM1"));
    StaticBoxSizer1->Add(DiskCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(StaticBoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
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
    StaticBoxSizer1->Fit(this);
    StaticBoxSizer1->SetSizeHints(this);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WxWidgetsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100WxWidgetsFrame::OnAbout);
    //*)

    create();
}

T100WxWidgetsFrame::~T100WxWidgetsFrame()
{
    //(*Destroy(T100WxWidgetsFrame)
    //*)

    destroy();
}

T100VOID T100WxWidgetsFrame::create()
{
    DiskCtrl->SetLength(1024);
}

T100VOID T100WxWidgetsFrame::destroy()
{

}

void T100WxWidgetsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100WxWidgetsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
