#include "T100PainterCanvas.h"

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include "T100ElementBase.h"
#include "T100PainterCallback.h"

#include "T100TestTools.h"

#include "T100CanvasState.h"

namespace T100Painter{

const long T100PainterCanvas::ID_TITLE = wxNewId();

BEGIN_EVENT_TABLE(T100PainterCanvas,wxScrolledWindow)
    EVT_PAINT(T100PainterCanvas::OnPaint)
    EVT_ERASE_BACKGROUND(T100PainterCanvas::OnEraseBackGround)
    //
    EVT_LEFT_DOWN(T100PainterCanvas::OnMouseLeftDown)
    EVT_LEFT_UP(T100PainterCanvas::OnMouseLeftUp)
    EVT_MOTION(T100PainterCanvas::OnMouseMove)
    EVT_LEFT_DCLICK(T100PainterCanvas::OnMouseLeftDClick)
    //
    EVT_SIZE(T100PainterCanvas::OnResize)
    //
END_EVENT_TABLE()

T100PainterCanvas::T100PainterCanvas(wxWindow *parent, wxWindowID winid, const wxPoint& pos,
                     const wxSize& size, long style, const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name), m_manager()
{
    //ctor
    create();
}

T100PainterCanvas::~T100PainterCanvas()
{
    //dtor
    destroy();
}

T100VOID T100PainterCanvas::create()
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    SetBackgroundColour(*wxWHITE);

    m_manager.Change(T100CANVAS_STATE_NONE);
}

T100VOID T100PainterCanvas::destroy()
{

}

T100ElementBase* T100PainterCanvas::GetCurrent()
{
    return m_current;
}

T100VOID T100PainterCanvas::Select(T100ElementBase* element)
{
    m_current = element;
}

T100VOID T100PainterCanvas::Deselect()
{
    m_current = T100NULL;
}

T100BOOL T100PainterCanvas::Load(T100PAINTER_ELEMENT_VECTOR* elements)
{
    m_elements = elements;
    return T100TRUE;
}

void T100PainterCanvas::OnEraseBackGround(wxEraseEvent& event)
{

}

void T100PainterCanvas::OnPaint(wxPaintEvent& event)
{
    T100CanvasState*        current         = T100NULL;

    current = static_cast<T100CanvasState*>(m_manager.GetCurrent());
    if(!current)return;

    current->OnPaint(event);
    //


    T100Library::T100TestTools::Print(L"Paint");

    wxAutoBufferedPaintDC       dc(this);
    //wxClientDC      dc(this);

    dc.Clear();
    DoPrepareDC(dc);


    if(!m_elements)return;

    for(T100ElementBase* item : *m_elements){
        item->draw(dc);
    }

    dc.SetPen(*wxRED_PEN);

    if(m_current){
        T100Library::T100TestTools::Print(L"Paint...");
        m_current->draw(dc);
    }
}

T100BOOL T100PainterCanvas::Hit(T100INT x, T100INT y)
{
    T100BOOL        result          = T100FALSE;

    if(m_elements){
        m_current = T100NULL;

        for(T100ElementBase* item : *m_elements){
            if(item->Hit(x, y)){
                result = T100TRUE;
                m_current = item;
            }
        }
        return result;
    }
    return T100FALSE;
}

void T100PainterCanvas::OnMouseLeftDown(wxMouseEvent& event)
{
    T100CanvasState*        current         = T100NULL;

    current = static_cast<T100CanvasState*>(m_manager.GetCurrent());
    if(!current)return;

    current->OnMouseLeftDown(event);

    T100Library::T100TestTools::Print(L"MouseLeftDown");
}

void T100PainterCanvas::OnMouseLeftUp(wxMouseEvent& event)
{
    T100CanvasState*        current         = T100NULL;

    current = static_cast<T100CanvasState*>(m_manager.GetCurrent());
    if(!current)return;

    current->OnMouseLeftUp(event);

    T100Library::T100TestTools::Print(L"MouseLeftUp");
}

void T100PainterCanvas::OnMouseMove(wxMouseEvent& event)
{
    T100CanvasState*        current         = T100NULL;

    current = static_cast<T100CanvasState*>(m_manager.GetCurrent());
    if(!current)return;

    current->OnMouseMove(event);

    T100Library::T100TestTools::Print(L"MouseMove");
}

void T100PainterCanvas::OnMouseLeftDClick(wxMouseEvent& event)
{
    T100BOOL        result;

    T100CanvasState*        current         = T100NULL;

    current = static_cast<T100CanvasState*>(m_manager.GetCurrent());
    if(!current)return;

    current->OnMouseLeftDClick(event);
    return;

    T100Library::T100TestTools::Print(L"MouseLeftDClick");
    result = Hit(event.GetPosition().x, event.GetPosition().y);
    if(result){
        Edit();
    }
}

void T100PainterCanvas::Edit()
{
    m_title = T100NEW wxTextCtrl(this, ID_TITLE);

    if(m_title){
        Connect(ID_TITLE, wxEVT_COMMAND_TEXT_UPDATED, (wxObjectEventFunction)&T100PainterCanvas::OnTitleUpdated);
        Connect(ID_TITLE, wxEVT_COMMAND_KILL_FOCUS, (wxObjectEventFunction)&T100PainterCanvas::OnLostFocus);

        Connect(ID_TITLE, wxEVT_LEAVE_WINDOW, (wxObjectEventFunction)&T100PainterCanvas::OnLeave);
        m_title->Show();
    }
}

void T100PainterCanvas::OnResize(wxSizeEvent& event)
{
    T100Library::T100TestTools::Print(L"Resize");
    Refresh();
}

void T100PainterCanvas::OnTitleUpdated(wxCommandEvent& event)
{
    T100Library::T100TestTools::Print(L"Updated");
    if(m_title && m_current){
        m_current->setLabel(m_title->GetValue().ToStdWstring());
    }
}

void T100PainterCanvas::OnLostFocus(wxFocusEvent& event)
{
    T100Library::T100TestTools::Print(L"LostFocus");
    if(m_title && m_current){
        m_current->setLabel(m_title->GetValue().ToStdWstring());
        T100SAFE_DELETE(m_title);
    }
}

void T100PainterCanvas::OnLeave(wxCommandEvent& event)
{
    T100Library::T100TestTools::Print(L"Leave");
    if(m_title && m_current){
        m_current->setLabel(m_title->GetValue().ToStdWstring());
        T100SAFE_DELETE(m_title);
    }
}

T100BOOL T100PainterCanvas::MouseMove(T100INT x, T100INT y)
{
    T100INT vx, vy;

    //T100Library::T100TestTools::Print(L"MouseMove...");

    GetVirtualSize(&vx, &vy);

    if(x >= vx - 10){
        T100Library::T100TestTools::Print(L"MouseMove...");
        vx = x + 10;
        SetScrollbars(10, 10, vx, vy);
    }

    if(y >= vy - 10){
        T100Library::T100TestTools::Print(L"MouseMove...");
        vy = y + 10;
        SetScrollbars(10, 10, vx, vy);
    }

    return T100TRUE;
}

T100BOOL T100PainterCanvas::GetVirtualPosition(T100INT x, T100INT y, T100INT& vx, T100INT& vy)
{
    T100INT sx, sy;

    GetViewStart(&sx, &sy);

    vx  = x + sx * 10;
    vy  = y + sy * 10;

    return T100TRUE;
}

T100BOOL T100PainterCanvas::Change(T100CANVAS_STATE state)
{
    m_manager.Change(state);
    return T100TRUE;
}

}
