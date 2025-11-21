/***************************************************************
 * Name:      T100PSVMMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-10
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100PSVMMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100PSVMFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100PSVMCommon.h"
#include "T100PSVMInvoking.h"

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

//(*IdInit(T100PSVMFrame)
const long T100PSVMFrame::ID_TEXTCTRL1 = wxNewId();
const long T100PSVMFrame::idMenuQuit = wxNewId();
const long T100PSVMFrame::idMenuAbout = wxNewId();
const long T100PSVMFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100PSVMFrame,wxFrame)
    //(*EventTable(T100PSVMFrame)
    //*)
END_EVENT_TABLE()

T100PSVMFrame::T100PSVMFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100PSVMFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    TextCtrl = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(224,256), wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PSVMFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100PSVMFrame::OnAbout);
    //*)

    init();
}

T100PSVMFrame::~T100PSVMFrame()
{
    //(*Destroy(T100PSVMFrame)
    //*)

    uninit();
}

T100VOID T100PSVMFrame::init()
{
    T100PSVMInvoking::Init(this);

    Connect(T100PSVM_MENU_ITEM_FILE_NEW,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuFileCreate);
    Connect(T100PSVM_MENU_ITEM_FILE_OPEN,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuFileOpen);
    Connect(T100PSVM_MENU_ITEM_FILE_CLOSE,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuFileClose);
    Connect(T100PSVM_MENU_ITEM_FILE_SAVE,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuFileSave);
    Connect(T100PSVM_MENU_ITEM_FILE_SAVE_AS,    wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuFileSaveAs);
    Connect(T100PSVM_MENU_ITEM_FILE_QUIT,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuFileQuit);

    Connect(T100PSVM_MENU_ITEM_VM_START,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuVMStart);
    Connect(T100PSVM_MENU_ITEM_VM_STOP,         wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuVMStop);

    Connect(T100PSVM_MENU_ITEM_DEBUG_START,     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuDebugStart);
    Connect(T100PSVM_MENU_ITEM_DEBUG_STOP,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuDebugStop);

    Connect(T100PSVM_MENU_ITEM_HELP_ABOUT,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PSVMFrame::OnMenuHelpAbout);
}

T100VOID T100PSVMFrame::uninit()
{
    T100PSVMInvoking::Uninit();
}

void T100PSVMFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100PSVMFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

T100VOID T100PSVMFrame::Log(T100STRING& value)
{
    TextCtrl->AppendText(value);
    TextCtrl->AppendText("\n");
}

T100VOID T100PSVMFrame::OnMenuFileCreate(wxCommandEvent& event)
{
    T100PSVMInvoking::OnFileCreate();
}

T100VOID T100PSVMFrame::OnMenuFileOpen(wxCommandEvent& event)
{
    T100PSVMInvoking::OnFileOpen();
}

T100VOID T100PSVMFrame::OnMenuFileClose(wxCommandEvent& event)
{
    T100PSVMInvoking::OnFileClose();
}

T100VOID T100PSVMFrame::OnMenuFileSave(wxCommandEvent& event)
{
    T100PSVMInvoking::OnFileSave();
}

T100VOID T100PSVMFrame::OnMenuFileSaveAs(wxCommandEvent& event)
{
    T100PSVMInvoking::OnFileSaveAs();
}

T100VOID T100PSVMFrame::OnMenuFileQuit(wxCommandEvent& event)
{
    T100PSVMInvoking::OnFileQuit();
}

T100VOID T100PSVMFrame::OnMenuVMStart(wxCommandEvent& event)
{
    T100PSVMInvoking::OnVMStart();
}

T100VOID T100PSVMFrame::OnMenuVMStop(wxCommandEvent& event)
{
    T100PSVMInvoking::OnVMStop();
}

T100VOID T100PSVMFrame::OnMenuDebugStart(wxCommandEvent& event)
{
    T100PSVMInvoking::OnDebugStart();
}

T100VOID T100PSVMFrame::OnMenuDebugStop(wxCommandEvent& event)
{
    T100PSVMInvoking::OnDebugStop();
}

T100VOID T100PSVMFrame::OnMenuHelpAbout(wxCommandEvent& event)
{
    T100PSVMInvoking::OnHelpAbout();
}

