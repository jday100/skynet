/***************************************************************
 * Name:      T100VHDMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-02-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100VHDMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100VHDFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "wx/filedlg.h"
#include "T100VHD.h"
#include "T100CreateDialog.h"
#include "T100WXOpenTask.h"
#include "T100DiskPoolPanel.h"

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

//(*IdInit(T100VHDFrame)
const long T100VHDFrame::ID_MENUITEM_NEW = wxNewId();
const long T100VHDFrame::ID_MENUITEM_OPEN = wxNewId();
const long T100VHDFrame::ID_MENUITEM_CLOSE = wxNewId();
const long T100VHDFrame::idMenuQuit = wxNewId();
const long T100VHDFrame::idMenuAbout = wxNewId();
const long T100VHDFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VHDFrame,wxFrame)
    //(*EventTable(T100VHDFrame)
    //*)
END_EVENT_TABLE()

T100VHDFrame::T100VHDFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100VHDFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemNew = new wxMenuItem(Menu1, ID_MENUITEM_NEW, _("New"), _("New"), wxITEM_NORMAL);
    Menu1->Append(MenuItemNew);
    MenuItemOpen = new wxMenuItem(Menu1, ID_MENUITEM_OPEN, _("Open"), _("Open"), wxITEM_NORMAL);
    Menu1->Append(MenuItemOpen);
    MenuItemClose = new wxMenuItem(Menu1, ID_MENUITEM_CLOSE, _("Close"), _("Close"), wxITEM_NORMAL);
    Menu1->Append(MenuItemClose);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { -10, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_MENUITEM_NEW,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VHDFrame::OnMenuItemNewSelected);
    Connect(ID_MENUITEM_OPEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VHDFrame::OnMenuItemOpenSelected);
    Connect(ID_MENUITEM_CLOSE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VHDFrame::OnMenuItemCloseSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VHDFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100VHDFrame::OnAbout);
    //*)
}

T100VHDFrame::~T100VHDFrame()
{
    //(*Destroy(T100VHDFrame)
    //*)
}

void T100VHDFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100VHDFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100VHDFrame::OnMenuItemNewSelected(wxCommandEvent& event)
{
    T100CreateDialog            dialog(this);

    if(wxAPPLY == dialog.ShowModal()){

    }else{

    }

    /*
    T100INT64       length;

    length      = 1024 * 1024 * 1024;

    T100VHD         vhd("test.vhd", length);

    vhd.create();
    */

}

void T100VHDFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    wxFileDialog        dialog(T100NULL, _("Please select a file"), "", "", "All files(*.*)|*.*", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_OK == dialog.ShowModal()){
        T100WXOpenTask          task;

        task.setFrame(this);
        task.setFileName(dialog.GetPath().ToStdString());
        task.run();

        T100DiskPoolPanel*      panel   = T100NEW T100DiskPoolPanel(this);


        this->Refresh();
        panel->Show();
    }

}

void T100VHDFrame::OnMenuItemCloseSelected(wxCommandEvent& event)
{
}
