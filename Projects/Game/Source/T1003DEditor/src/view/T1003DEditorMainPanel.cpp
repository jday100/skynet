#include "T1003DEditorMainPanel.h"

#include <thread>
#include <wx/dcmemory.h>
#include "T1003DEditor.h"
#include "T1003DEditorView.h"

BEGIN_EVENT_TABLE(T1003DEditorMainPanel, wxPanel)
    EVT_SIZE(T1003DEditorMainPanel::OnResize)
    EVT_PAINT(T1003DEditorMainPanel::OnPaint)
    EVT_KEY_DOWN(T1003DEditorMainPanel::OnKeyDown)
    EVT_KEY_UP(T1003DEditorMainPanel::OnKeyUp)
    EVT_LEFT_DOWN(T1003DEditorMainPanel::OnLeftDown)
    EVT_LEFT_UP(T1003DEditorMainPanel::OnLeftUp)
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
}

T1003DEditorMainPanel::~T1003DEditorMainPanel()
{
    //dtor
}

T100VOID T1003DEditorMainPanel::setEditor(T1003DEditor* editor)
{
    m_editor    = editor;
}

T100VOID T1003DEditorMainPanel::setView(T1003DEditorView* view)
{
    m_view      = view;
}

void T1003DEditorMainPanel::OnResize(wxSizeEvent& event)
{
    if(m_bitmap){
        T100SAFE_DELETE m_bitmap;
        m_bitmap    = T100NULL;

    }
    m_width     = event.GetSize().GetWidth();
    m_height    = event.GetSize().GetHeight();
    m_bitmap    = T100NEW wxBitmap(m_width, m_height);
}

void T1003DEditorMainPanel::OnPaint(wxPaintEvent& event)
{
    m_editor->Render();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    if(m_drawLine){
        wxPaintDC       dc(this);
        DrawLine(dc);
    }

    wxPaintDC       dc(this);

    //SaveWindow(dc);
}

void T1003DEditorMainPanel::OnKeyDown(wxKeyEvent& event)
{

}

void T1003DEditorMainPanel::OnKeyUp(wxKeyEvent& event)
{

}

void T1003DEditorMainPanel::OnLeftDown(wxMouseEvent& event)
{
    m_view->getEditor()->Append(m_view->getEntity());

    m_drawLine  = T100TRUE;

    Refresh();
}

void T1003DEditorMainPanel::OnLeftUp(wxMouseEvent& event)
{

}

T100VOID T1003DEditorMainPanel::DrawLine(wxDC& dc)
{
    wxMemoryDC      memory;

    memory.SelectObject(*m_bitmap);

    memory.Blit(wxPoint(0, 0), wxSize(m_width, m_height), &dc, wxPoint(0, 0));

    //m_bitmap->SaveFile(wxT("screen1.bmp"), wxBITMAP_TYPE_BMP);

    memory.DrawCircle(100, 100, 50);

    dc.Blit(wxPoint(0, 0), wxSize(m_width, m_height), &memory, wxPoint(0, 0));

    //m_bitmap->SaveFile(wxT("screen2.bmp"), wxBITMAP_TYPE_BMP);
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
