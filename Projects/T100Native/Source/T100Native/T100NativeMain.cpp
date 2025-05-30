/***************************************************************
 * Name:      T100NativeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100NativeMain.h"
#include <wx/msgdlg.h>
#include "T100Editor.h"
#include "T100EditorView.h"

//(*InternalHeaders(T100NativeFrame)
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

//(*IdInit(T100NativeFrame)
const long T100NativeFrame::idMenuQuit = wxNewId();
const long T100NativeFrame::ID_MENUITEM_SCENE_EDITOR = wxNewId();
const long T100NativeFrame::idMenuAbout = wxNewId();
const long T100NativeFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100NativeFrame,wxFrame)
    //(*EventTable(T100NativeFrame)
    //*)
END_EVENT_TABLE()

T100NativeFrame::T100NativeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T100NativeFrame)
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
    Menu3 = new wxMenu();
    MenuItemSceneEditor = new wxMenuItem(Menu3, ID_MENUITEM_SCENE_EDITOR, _("Editor"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItemSceneEditor);
    MenuBar1->Append(Menu3, _("Scene"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100NativeFrame::OnQuit);
    Connect(ID_MENUITEM_SCENE_EDITOR,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100NativeFrame::OnMenuItemSceneEditorSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T100NativeFrame::OnAbout);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100NativeFrame::OnPaint);
    Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&T100NativeFrame::OnKeyDown);
    Connect(wxEVT_CHAR,(wxObjectEventFunction)&T100NativeFrame::OnChar);
    Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&T100NativeFrame::OnLeftDown);
    Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&T100NativeFrame::OnLeftUp);
    Connect(wxEVT_MOTION,(wxObjectEventFunction)&T100NativeFrame::OnMouseMove);
    //*)

    //TurnOn();
}

T100NativeFrame::~T100NativeFrame()
{
    //(*Destroy(T100NativeFrame)
    //*)
    //TurnOff();
}

T100VOID T100NativeFrame::TurnOn()
{
    T100INT         width, height;

    m_render    = T100NEW T100WxRender(this, wxID_ANY);

    GetSize(&width, &height);

    m_render->SetSize(width, height);
}

T100VOID T100NativeFrame::TurnOff()
{
    T100SAFE_DELETE(m_render)
}

T100VOID T100NativeFrame::SetRender(T100WxRender* render)
{
    m_render    = render;
}

T100WxRender& T100NativeFrame::GetRender()
{
    return *m_render;
}

void T100NativeFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T100NativeFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T100NativeFrame::OnPaint(wxPaintEvent& event)
{
    m_render->Refresh();
}

void T100NativeFrame::OnKeyDown(wxKeyEvent& event)
{
}

void T100NativeFrame::OnChar(wxKeyEvent& event)
{
}

void T100NativeFrame::OnMenuItemSceneEditorSelected(wxCommandEvent& event)
{
    T100Editor*     editor      = T100NEW T100Editor();

    editor->GetView()->Show();
}

void T100NativeFrame::OnMouseMove(wxMouseEvent& event)
{
}

void T100NativeFrame::OnLeftDown(wxMouseEvent& event)
{
}

void T100NativeFrame::OnLeftUp(wxMouseEvent& event)
{
}
