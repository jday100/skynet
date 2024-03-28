#include "T100WPainterCanvas.h"

#include <wx/dcclient.h>

BEGIN_EVENT_TABLE(T100WPainterCanvas,wxScrolledWindow)
    EVT_PAINT(T100WPainterCanvas::OnPaint)
    EVT_ERASE_BACKGROUND(T100WPainterCanvas::OnEraseBackGround)
    //
    EVT_ENTER_WINDOW(T100WPainterCanvas::OnMouseEnter)
    EVT_LEAVE_WINDOW(T100WPainterCanvas::OnMouseLeave)
    //
    EVT_LEFT_DOWN(T100WPainterCanvas::OnMouseLeftDown)
    EVT_LEFT_UP(T100WPainterCanvas::OnMouseLeftUp)
    EVT_LEFT_DCLICK(T100WPainterCanvas::OnMouseLeftDClick)
    EVT_MOTION(T100WPainterCanvas::OnMouseMove)
    //
    EVT_KEY_UP(T100WPainterCanvas::OnKeyUp)
    //
    EVT_SIZE(T100WPainterCanvas::OnResize)
    //
    EVT_SCROLLWIN_BOTTOM(T100WPainterCanvas::OnScrollBottom)
    EVT_SCROLLWIN_LINEDOWN(T100WPainterCanvas::OnScrollLineDown)
    EVT_SCROLLWIN_PAGEDOWN(T100WPainterCanvas::OnScrollPageDown)
    EVT_SCROLLWIN_THUMBTRACK(T100WPainterCanvas::OnScrollThumbTrack)
END_EVENT_TABLE()

T100WPainterCanvas::T100WPainterCanvas(wxWindow *parent,
                     wxWindowID winid,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style,
                     const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name)
{
    //ctor
    create();
}

T100WPainterCanvas::~T100WPainterCanvas()
{
    //dtor
    destroy();
}

T100VOID T100WPainterCanvas::create()
{
    m_transverter.Change(T100CANVAS_STATE_NONE);
}

T100VOID T100WPainterCanvas::destroy()
{

}

T100VOID T100WPainterCanvas::Change(T100WORD state)
{
    m_transverter.Change(state);
    Refresh();
}

void T100WPainterCanvas::OnEraseBackGround(wxEraseEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnEraseBackGround(this, event);
    }
}

void T100WPainterCanvas::OnPaint(wxPaintEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnPaint(this, event);
    }
}

void T100WPainterCanvas::OnMouseEnter(wxMouseEvent& event)
{

}

void T100WPainterCanvas::OnMouseLeave(wxMouseEvent& event)
{

}

void T100WPainterCanvas::OnMouseLeftDown(wxMouseEvent& event)
{

}

void T100WPainterCanvas::OnMouseLeftUp(wxMouseEvent& event)
{

}

void T100WPainterCanvas::OnMouseLeftDClick(wxMouseEvent& event)
{

}

void T100WPainterCanvas::OnMouseMove(wxMouseEvent& event)
{

}

void T100WPainterCanvas::OnKeyUp(wxKeyEvent& event)
{

}

void T100WPainterCanvas::OnResize(wxSizeEvent& event)
{

}

void T100WPainterCanvas::OnScrollBottom(wxScrollWinEvent& event)
{

}

void T100WPainterCanvas::OnScrollLineDown(wxScrollWinEvent& event)
{

}

void T100WPainterCanvas::OnScrollPageDown(wxScrollWinEvent& event)
{

}

void T100WPainterCanvas::OnScrollThumbTrack(wxScrollWinEvent& event)
{

}
