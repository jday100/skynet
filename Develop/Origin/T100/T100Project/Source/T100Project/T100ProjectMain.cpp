/***************************************************************
 * Name:      T100ProjectMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-09-03
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ProjectMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T100ProjectFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

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

//(*IdInit(T100ProjectFrame)
const long T100ProjectFrame::idMenuQuit = wxNewId();
const long T100ProjectFrame::idMenuAbout = wxNewId();
const long T100ProjectFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100ProjectFrame,wxFrame)
    //(*EventTable(T100ProjectFrame)
    //*)
    EVT_AUI_PANE_CLOSE(T100ProjectFrame::OnAuiPaneClose)
END_EVENT_TABLE()

T100ProjectFrame::T100ProjectFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100ProjectFrame)
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
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100ProjectFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100ProjectFrame::OnAbout);
    //*)

    init();
    T100ProjectInvoking::Init(this);
}

T100ProjectFrame::~T100ProjectFrame()
{
    //(*Destroy(T100ProjectFrame)
    //*)

    T100ProjectInvoking::Uninit();
    uninit();
}

T100VOID T100ProjectFrame::init()
{
    Connect(T100PROJECT_MENU_WORKSPACE_NEW,                 wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnWorkSpaceCreate);
    Connect(T100PROJECT_MENU_WORKSPACE_OPEN,                wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnWorkSpaceOpen);
    Connect(T100PROJECT_MENU_WORKSPACE_CLOSE,               wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnWorkSpaceClose);
    Connect(T100PROJECT_MENU_WORKSPACE_SAVE,                wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnWorkSpaceSave);
    Connect(T100PROJECT_MENU_WORKSPACE_QUIT,                wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnWorkSpaceQuit);

    Connect(T100PROJECT_MENU_PROJECT_NEW,                   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnProjectCreate);
    Connect(T100PROJECT_MENU_PROJECT_REMOVE,                wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnProjectRemove);
    Connect(T100PROJECT_MENU_PROJECT_OPEN,                  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnProjectOpen);
    Connect(T100PROJECT_MENU_PROJECT_CLOSE,                 wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnProjectClose);
    Connect(T100PROJECT_MENU_PROJECT_SAVE,                  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnProjectSave);
    Connect(T100PROJECT_MENU_PROJECT_SAVE_AS,               wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnProjectSaveAs);

    Connect(T100PROJECT_MENU_FILE_NEW,                      wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnFileCreate);
    Connect(T100PROJECT_MENU_FILE_REMOVE,                   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnFileRemove);
    Connect(T100PROJECT_MENU_FILE_OPEN,                     wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnFileOpen);
    Connect(T100PROJECT_MENU_FILE_CLOSE,                    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnFileClose);
    Connect(T100PROJECT_MENU_FILE_SAVE,                     wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnFileSave);
    Connect(T100PROJECT_MENU_FILE_SAVE_AS,                  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnFileSaveAs);

    Connect(T100PROJECT_MENU_EDIT_UNDO,                     wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnEditUndo);
    Connect(T100PROJECT_MENU_EDIT_REDO,                     wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnEditRedo);
    Connect(T100PROJECT_MENU_EDIT_CUT,                      wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnEditCut);
    Connect(T100PROJECT_MENU_EDIT_COPY,                     wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnEditCopy);
    Connect(T100PROJECT_MENU_EDIT_PASTE,                    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnEditPaste);

    Connect(T100PROJECT_MENU_VIEW_WORKSPACE,                wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnViewWorkSpaceTree);
    Connect(T100PROJECT_MENU_VIEW_SEARCH,                   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnViewSearchResult);
    Connect(T100PROJECT_MENU_VIEW_OUTPUT,                   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnViewCompileOutput);

    Connect(T100PROJECT_MENU_SEARCH_FIND,                   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnSearchFind);
    Connect(T100PROJECT_MENU_SEARCH_REPLACE,                wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnSearchReplace);

    Connect(T100PROJECT_MENU_COMPILE_RUN,                   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnCompileRun);
    Connect(T100PROJECT_MENU_COMPILE_BUILD_AND_RUN,         wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnCompileBuildAndRun);
    Connect(T100PROJECT_MENU_COMPILE_BUILD,                 wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnCompileBuild);
    Connect(T100PROJECT_MENU_COMPILE_CLEAN,                 wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnCompileClean);
    Connect(T100PROJECT_MENU_COMPILE_REBUILD,               wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnCompileRebuild);

    Connect(T100PROJECT_MENU_DEBUG_START,                   wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnDebugStart);
    Connect(T100PROJECT_MENU_DEBUG_STOP,                    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnDebugStop);

    Connect(T100PROJECT_MENU_SETUP_EDITOR,                  wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnSetupEditor);
    Connect(T100PROJECT_MENU_SETUP_COMPILER,                wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnSetupCompiler);

    Connect(T100PROJECT_MENU_HELP_ABOUT,                    wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100ProjectFrame::OnHelpAbout);
}

T100VOID T100ProjectFrame::uninit()
{

}

void T100ProjectFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100ProjectFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

T100VOID T100ProjectFrame::OnAuiPaneClose(wxAuiManagerEvent& event)
{
    T100ProjectInvoking::OnAuiPaneClose(event.GetPane());
}

T100VOID T100ProjectFrame::OnWorkSpaceCreate(wxCommandEvent& event)
{
    T100ProjectInvoking::OnWorkSpaceCreate();
}

T100VOID T100ProjectFrame::OnWorkSpaceOpen(wxCommandEvent& event)
{
    T100ProjectInvoking::OnWorkSpaceOpen();
}

T100VOID T100ProjectFrame::OnWorkSpaceClose(wxCommandEvent& event)
{
    T100ProjectInvoking::OnWorkSpaceClose();
}

T100VOID T100ProjectFrame::OnWorkSpaceSave(wxCommandEvent& event)
{
    T100ProjectInvoking::OnWorkSpaceSave();
}

T100VOID T100ProjectFrame::OnWorkSpaceQuit(wxCommandEvent& event)
{
    T100ProjectInvoking::OnWorkSpaceQuit();
}


T100VOID T100ProjectFrame::OnProjectCreate(wxCommandEvent& event)
{
    T100ProjectInvoking::OnProjectCreate();
}

T100VOID T100ProjectFrame::OnProjectRemove(wxCommandEvent& event)
{
    T100ProjectInvoking::OnProjectRemove();
}

T100VOID T100ProjectFrame::OnProjectOpen(wxCommandEvent& event)
{
    //T100ProjectInvoking::OnProjectOpen();
}

T100VOID T100ProjectFrame::OnProjectClose(wxCommandEvent& event)
{
    T100ProjectInvoking::OnProjectClose();
}

T100VOID T100ProjectFrame::OnProjectSave(wxCommandEvent& event)
{
    T100ProjectInvoking::OnProjectSave();
}

T100VOID T100ProjectFrame::OnProjectSaveAs(wxCommandEvent& event)
{
    T100ProjectInvoking::OnProjectSaveAs();
}


T100VOID T100ProjectFrame::OnFileCreate(wxCommandEvent& event)
{
    T100ProjectInvoking::OnFileCreate();
}

T100VOID T100ProjectFrame::OnFileRemove(wxCommandEvent& event)
{
    T100ProjectInvoking::OnFileRemove();
}

T100VOID T100ProjectFrame::OnFileOpen(wxCommandEvent& event)
{
    T100ProjectInvoking::OnFileOpen();
}

T100VOID T100ProjectFrame::OnFileClose(wxCommandEvent& event)
{
    T100ProjectInvoking::OnFileClose();
}

T100VOID T100ProjectFrame::OnFileSave(wxCommandEvent& event)
{
    T100ProjectInvoking::OnFileSave();
}

T100VOID T100ProjectFrame::OnFileSaveAs(wxCommandEvent& event)
{
    T100ProjectInvoking::OnFileSaveAs();
}



T100VOID T100ProjectFrame::OnEditUndo(wxCommandEvent& event)
{
    T100ProjectInvoking::OnEditUndo();
}

T100VOID T100ProjectFrame::OnEditRedo(wxCommandEvent& event)
{
    T100ProjectInvoking::OnEditRedo();
}

T100VOID T100ProjectFrame::OnEditCut(wxCommandEvent& event)
{
    T100ProjectInvoking::OnEditCut();
}

T100VOID T100ProjectFrame::OnEditCopy(wxCommandEvent& event)
{
    T100ProjectInvoking::OnEditCopy();
}

T100VOID T100ProjectFrame::OnEditPaste(wxCommandEvent& event)
{
    T100ProjectInvoking::OnEditPaste();
}


T100VOID T100ProjectFrame::OnViewWorkSpaceTree(wxCommandEvent& event)
{
    T100ProjectInvoking::OnViewWorkSpaceTree(event.IsChecked());
}

T100VOID T100ProjectFrame::OnViewSearchResult(wxCommandEvent& event)
{
    T100ProjectInvoking::OnViewSearchResult(event.IsChecked());
}

T100VOID T100ProjectFrame::OnViewCompileOutput(wxCommandEvent& event)
{
    T100ProjectInvoking::OnViewCompileOutput(event.IsChecked());
}


T100VOID T100ProjectFrame::OnSearchFind(wxCommandEvent& event)
{
    T100ProjectInvoking::OnSearchFind();
}

T100VOID T100ProjectFrame::OnSearchReplace(wxCommandEvent& event)
{
    T100ProjectInvoking::OnSearchReplace();
}


T100VOID T100ProjectFrame::OnCompileRun(wxCommandEvent& event)
{
    T100ProjectInvoking::OnCompileRun();
}

T100VOID T100ProjectFrame::OnCompileBuildAndRun(wxCommandEvent& event)
{
    T100ProjectInvoking::OnCompileBuildAndRun();
}

T100VOID T100ProjectFrame::OnCompileBuild(wxCommandEvent& event)
{
    T100ProjectInvoking::OnCompileBuild();
}

T100VOID T100ProjectFrame::OnCompileClean(wxCommandEvent& event)
{
    T100ProjectInvoking::OnCompileClean();
}

T100VOID T100ProjectFrame::OnCompileRebuild(wxCommandEvent& event)
{
    T100ProjectInvoking::OnCompileRebuild();
}


T100VOID T100ProjectFrame::OnDebugStart(wxCommandEvent& event)
{
    T100ProjectInvoking::OnDebugStart();
}

T100VOID T100ProjectFrame::OnDebugStop(wxCommandEvent& event)
{
    T100ProjectInvoking::OnDebugStop();
}


T100VOID T100ProjectFrame::OnSetupEditor(wxCommandEvent& event)
{
    T100ProjectInvoking::OnSetupEditor();
}

T100VOID T100ProjectFrame::OnSetupCompiler(wxCommandEvent& event)
{
    T100ProjectInvoking::OnSetupCompiler();
}


T100VOID T100ProjectFrame::OnHelpAbout(wxCommandEvent& event)
{
    T100ProjectInvoking::OnHelpAbout();
}
