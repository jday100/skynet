#include "T1003DEditorMainPanel.h"

#include <thread>
#include <iostream>

#include <wx/dcmemory.h>
#include "T1003DEditorView.h"

#include "T1003DEditorCallback.h"

BEGIN_EVENT_TABLE(T1003DEditorMainPanel, wxPanel)
    EVT_SIZE(T1003DEditorMainPanel::OnResize)
    EVT_PAINT(T1003DEditorMainPanel::OnPaint)
    EVT_KEY_DOWN(T1003DEditorMainPanel::OnKeyDown)
    EVT_KEY_UP(T1003DEditorMainPanel::OnKeyUp)
    EVT_LEFT_DOWN(T1003DEditorMainPanel::OnLeftDown)
    EVT_LEFT_UP(T1003DEditorMainPanel::OnLeftUp)
    EVT_MOUSEWHEEL(T1003DEditorMainPanel::OnMouseWheel)
    EVT_MOTION(T1003DEditorMainPanel::OnMouseMove)

    EVT_IDLE(T1003DEditorMainPanel::OnIdle)
END_EVENT_TABLE()

T1003DEditorMainPanel::T1003DEditorMainPanel(wxWindow *parent,
                wxWindowID winid,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxString& name)
    :wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
    init();
}

T1003DEditorMainPanel::~T1003DEditorMainPanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorMainPanel::init()
{
    HWND        hwnd        = this->GetHWND();
    T100UINT    width       = this->GetClientSize().GetWidth();
    T100UINT    height      = this->GetClientSize().GetHeight();
    //T1003DEditorCallback::Create(hwnd, width, height);
}

T100VOID T1003DEditorMainPanel::uninit()
{

}

T100VOID T1003DEditorMainPanel::setView(T1003DEditorView* view)
{
    m_view      = view;
}

void T1003DEditorMainPanel::OnResize(wxSizeEvent& event)
{
    m_width     = event.GetSize().GetWidth();
    m_height    = event.GetSize().GetHeight();

    T1003DEditorCallback::Resize(m_width, m_height);
}

void T1003DEditorMainPanel::OnPaint(wxPaintEvent& event)
{
    //T1003DEditorCallback::Render();
}

void T1003DEditorMainPanel::OnKeyDown(wxKeyEvent& event)
{
    T1003DEditorCallback::KeyDown(event.GetKeyCode());
}

void T1003DEditorMainPanel::OnKeyUp(wxKeyEvent& event)
{
    T1003DEditorCallback::KeyUp(event.GetKeyCode());
}

void T1003DEditorMainPanel::OnLeftDown(wxMouseEvent& event)
{
    //T1003DEditorCallback::Append(m_view->getEntity());
    T1003DEditorCallback::Clear();
    Refresh();
}

void T1003DEditorMainPanel::OnLeftUp(wxMouseEvent& event)
{

}

void T1003DEditorMainPanel::OnMouseWheel(wxMouseEvent& event)
{
    int i = event.GetWheelRotation() / event.GetWheelDelta();

    Refresh();
}

void T1003DEditorMainPanel::OnMouseMove(wxMouseEvent& event)
{
    T100Vector2u    value;

    value.X = event.GetPosition().x;
    value.Y = event.GetPosition().y;

    T1003DEditorCallback::MouseMove(value);
}

T100VOID T1003DEditorMainPanel::DrawLine(wxDC& dc)
{

}

T100VOID T1003DEditorMainPanel::SaveWindow(wxDC& dc)
{
    wxMemoryDC      memory;

    memory.SelectObject(*m_bitmap);
    memory.Blit(wxPoint(0, 0), wxSize(m_width, m_height), &dc, wxPoint(0, 0));

    m_bitmap->SaveFile(wxT("screen1.bmp"), wxBITMAP_TYPE_BMP);

    memory.DrawCircle(100, 100, 50);

    m_bitmap->SaveFile(wxT("screen2.bmp"), wxBITMAP_TYPE_BMP);
}

void T1003DEditorMainPanel::OnIdle(wxIdleEvent& event)
{
    //Refresh();
    //std::cout << "Render..." << std::endl;
}
