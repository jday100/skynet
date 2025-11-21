/***************************************************************
 * Name:      T100DiagramMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-10-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100DiagramMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100DiagramFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100DiagramCommon.h"
#include "T100DiagramInvoking.h"

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

//(*IdInit(T100DiagramFrame)
const long T100DiagramFrame::idMenuQuit = wxNewId();
const long T100DiagramFrame::idMenuAbout = wxNewId();
const long T100DiagramFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100DiagramFrame,wxFrame)
    //(*EventTable(T100DiagramFrame)
    //*)
END_EVENT_TABLE()

T100DiagramFrame::T100DiagramFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100DiagramFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
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
    int __wxStatusBarWidths_1[3] = { -1, -1, -10 };
    int __wxStatusBarStyles_1[3] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(3,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(3,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100DiagramFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100DiagramFrame::OnAbout);
    //*)

    init();
}

T100DiagramFrame::~T100DiagramFrame()
{
    //(*Destroy(T100DiagramFrame)
    //*)

    uninit();
}

T100VOID T100DiagramFrame::init()
{
    T100DiagramInvoking::Init(this);

    Connect(T100DIAGRAM_MENU_FILE_CREATE,                   wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnFileCreate);
    Connect(T100DIAGRAM_MENU_FILE_OPEN,                     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnFileOpen);
    Connect(T100DIAGRAM_MENU_FILE_CLOSE,                    wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnFileClose);
    Connect(T100DIAGRAM_MENU_FILE_SAVE,                     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnFileSave);
    Connect(T100DIAGRAM_MENU_FILE_SAVE_AS,                  wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnFileSaveAs);
    Connect(T100DIAGRAM_MENU_FILE_QUIT,                     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnFileQuit);

    Connect(T100DIAGRAM_MENU_EDIT_UNDO,                     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnEditUndo);
    Connect(T100DIAGRAM_MENU_EDIT_REDO,                     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnEditRedo);
    Connect(T100DIAGRAM_MENU_EDIT_CUT,                      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnEditCut);
    Connect(T100DIAGRAM_MENU_EDIT_COPY,                     wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnEditCopy);
    Connect(T100DIAGRAM_MENU_EDIT_PASTE,                    wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnEditPaste);

    Connect(T100DIAGRAM_MENU_VIEW_MANAGER,                  wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnViewManager);
    Connect(T100DIAGRAM_MENU_VIEW_PROPERTY,                 wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnViewProperty);

    Connect(T100DIAGRAM_MENU_SEARCH_FIND,                   wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnSearchFind);

    Connect(T100DIAGRAM_MENU_DEVELOP_IMPORT,                wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnSourceImport);

    Connect(T100DIAGRAM_MENU_SETUP_CONFIG,                  wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnSetupConfig);

    Connect(T100DIAGRAM_MENU_HELP_ABOUT,                    wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100DiagramFrame::OnHelpAbout);

    Connect(wxEVT_AUI_PANE_CLOSE, (wxObjectEventFunction)&T100DiagramFrame::OnAuiPaneClose);

    T100DiagramInvoking::OnFileCreate();
}

T100VOID T100DiagramFrame::uninit()
{
    T100DiagramInvoking::Uninit();
}

void T100DiagramFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100DiagramFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

T100VOID T100DiagramFrame::OnFileCreate(wxCommandEvent& event)
{
    T100DiagramInvoking::OnFileCreate();
}

T100VOID T100DiagramFrame::OnFileOpen(wxCommandEvent& event)
{
    T100DiagramInvoking::OnFileOpen();
}

T100VOID T100DiagramFrame::OnFileClose(wxCommandEvent& event)
{
    T100DiagramInvoking::OnFileClose();
}

T100VOID T100DiagramFrame::OnFileSave(wxCommandEvent& event)
{
    T100DiagramInvoking::OnFileSave();
}

T100VOID T100DiagramFrame::OnFileSaveAs(wxCommandEvent& event)
{
    T100DiagramInvoking::OnFileSaveAs();
}

T100VOID T100DiagramFrame::OnFileQuit(wxCommandEvent& event)
{
    T100DiagramInvoking::OnFileQuit();
}

T100VOID T100DiagramFrame::OnEditUndo(wxCommandEvent& event)
{
    T100DiagramInvoking::OnEditUndo();
}

T100VOID T100DiagramFrame::OnEditRedo(wxCommandEvent& event)
{
    T100DiagramInvoking::OnEditRedo();
}

T100VOID T100DiagramFrame::OnEditCut(wxCommandEvent& event)
{
    T100DiagramInvoking::OnEditCut();
}

T100VOID T100DiagramFrame::OnEditCopy(wxCommandEvent& event)
{
    T100DiagramInvoking::OnEditCopy();
}

T100VOID T100DiagramFrame::OnEditPaste(wxCommandEvent& event)
{
    T100DiagramInvoking::OnEditPaste();
}

T100VOID T100DiagramFrame::OnViewManager(wxCommandEvent& event)
{
    T100DiagramInvoking::OnViewManager(event.IsChecked());
}

T100VOID T100DiagramFrame::OnViewProperty(wxCommandEvent& event)
{
    T100DiagramInvoking::OnViewProperty(event.IsChecked());
}

T100VOID T100DiagramFrame::OnSearchFind(wxCommandEvent& event)
{
    T100DiagramInvoking::OnSearchFind();
}

T100VOID T100DiagramFrame::OnSourceImport(wxCommandEvent& event)
{
    T100DiagramInvoking::OnDevelopImport();
}

T100VOID T100DiagramFrame::OnSetupConfig(wxCommandEvent& event)
{
    T100DiagramInvoking::OnSetupConfig();
}

T100VOID T100DiagramFrame::OnHelpAbout(wxCommandEvent& event)
{
    T100DiagramInvoking::OnHelpAbout();
}

T100VOID T100DiagramFrame::OnAuiPaneClose(wxAuiManagerEvent& event)
{
    T100DiagramInvoking::OnAuiPaneClose(event.GetPane());
}
