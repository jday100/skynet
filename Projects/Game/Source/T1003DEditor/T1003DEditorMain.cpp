/***************************************************************
 * Name:      T1003DEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-01-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T1003DEditorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(T1003DEditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <thread>
#include <wx/dcclient.h>

#include "T100Triangle.h"
#include "T1003DEditorMainPanel.h"

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

//(*IdInit(T1003DEditorFrame)
const long T1003DEditorFrame::idMenuQuit = wxNewId();
const long T1003DEditorFrame::idMenuAbout = wxNewId();
const long T1003DEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T1003DEditorFrame,wxFrame)
    //(*EventTable(T1003DEditorFrame)
    //*)
END_EVENT_TABLE()

T1003DEditorFrame::T1003DEditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(T1003DEditorFrame)
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&T1003DEditorFrame::OnAbout);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&T1003DEditorFrame::OnPaint);
    Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&T1003DEditorFrame::OnKeyDown);
    Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&T1003DEditorFrame::OnKeyUp);
    Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&T1003DEditorFrame::OnLeftDown);
    Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&T1003DEditorFrame::OnLeftUp);
    Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&T1003DEditorFrame::OnRightDown);
    Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&T1003DEditorFrame::OnRightUp);
    Connect(wxEVT_MOTION,(wxObjectEventFunction)&T1003DEditorFrame::OnMouseMove);
    Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&T1003DEditorFrame::OnMouseWheel);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&T1003DEditorFrame::OnResize);
    //*)

    create();
}

T1003DEditorFrame::~T1003DEditorFrame()
{
    //(*Destroy(T1003DEditorFrame)
    //*)

    destroy();
}

T100VOID T1003DEditorFrame::create()
{
    Maximize();

    m_editor    = T100NEW T1003DEditor();
    m_view      = T100NEW T1003DEditorView(this);

    m_view->setEditor(m_editor);

    m_editor->Create(
                     m_view->getMainPanel()->GetHWND(),
                     m_view->getMainPanel()->GetClientSize().GetWidth(),
                     m_view->getMainPanel()->GetClientSize().GetHeight()
                     );
}

T100VOID T1003DEditorFrame::destroy()
{
    T100SAFE_DELETE m_view;
    T100SAFE_DELETE m_editor;
}

void T1003DEditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void T1003DEditorFrame::OnAbout(wxCommandEvent& event)
{
    T100Triangle*   triangle    = T100NEW T100Triangle();

    m_editor->Append(triangle);

    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void T1003DEditorFrame::OnPaint(wxPaintEvent& event)
{
    m_editor->Render();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    wxPaintDC       dc(this);

    dc.DrawCircle(100, 100, 50);

}

void T1003DEditorFrame::OnEraseBackground(wxEraseEvent& event)
{
}

void T1003DEditorFrame::OnKeyDown(wxKeyEvent& event)
{
}

void T1003DEditorFrame::OnKeyUp(wxKeyEvent& event)
{
}

void T1003DEditorFrame::OnMouseWheel(wxMouseEvent& event)
{
}

void T1003DEditorFrame::OnResize(wxSizeEvent& event)
{
    m_editor->SetSize(event.GetSize().GetWidth(), event.GetSize().GetHeight());
}

void T1003DEditorFrame::OnMouseMove(wxMouseEvent& event)
{
}

void T1003DEditorFrame::OnLeftDown(wxMouseEvent& event)
{
}

void T1003DEditorFrame::OnLeftUp(wxMouseEvent& event)
{
}

void T1003DEditorFrame::OnRightDown(wxMouseEvent& event)
{
}

void T1003DEditorFrame::OnRightUp(wxMouseEvent& event)
{
}
