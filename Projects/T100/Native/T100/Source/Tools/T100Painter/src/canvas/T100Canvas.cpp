#include "T100Canvas.h"

BEGIN_EVENT_TABLE(T100Canvas,wxScrolledWindow)
    /*
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
    //
    EVT_THREAD(ID_THREAD_LOAD, T100WPainterCanvas::OnThreadLoad)
    */
END_EVENT_TABLE()

T100Canvas::T100Canvas(wxWindow *parent,
                     wxWindowID winid,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style,
                     const wxString& name)
    :wxScrolledWindow(parent, winid, pos, size, style, name)
{
    //ctor
}

T100Canvas::~T100Canvas()
{
    //dtor
}
