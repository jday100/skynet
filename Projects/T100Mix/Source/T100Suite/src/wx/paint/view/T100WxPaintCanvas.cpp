#include "wx\paint\view\T100WxPaintCanvas.h"


BEGIN_EVENT_TABLE(T100WxPaintCanvas,wxScrolledWindow)
    EVT_PAINT(T100WxPaintCanvas::OnPaint)
    EVT_ERASE_BACKGROUND(T100WxPaintCanvas::OnEraseBackGround)
    //
    EVT_MOUSEWHEEL(T100WxPaintCanvas::OnMouseWheel)
    EVT_LEFT_DCLICK(T100WxPaintCanvas::OnLeftDClick)
END_EVENT_TABLE()

T100WxPaintCanvas::T100WxPaintCanvas(wxWindow *parent,
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

T100WxPaintCanvas::~T100WxPaintCanvas()
{
    //dtor
    destroy();
}

T100VOID T100WxPaintCanvas::create()
{
    SetSize(600, 400);

    m_manager.Change(T100WX_PAINT_CANVAS_STATE_NONE);
}

T100VOID T100WxPaintCanvas::destroy()
{

}

void T100WxPaintCanvas::OnPaint(wxPaintEvent& event)
{
    T100WxPaintCanvasStateBase*     current         = T100NULL;

    std::lock_guard<std::mutex>     lock(m_mutex);

    current = m_manager.GetCurrent();
    if(!current)return;

    current->OnPaint(event, this);
}

void T100WxPaintCanvas::OnEraseBackGround(wxEraseEvent& event)
{
}

void T100WxPaintCanvas::OnMouseWheel(wxMouseEvent& event)
{
    m_scale = m_scale * 1.2;
    Refresh();
}

void T100WxPaintCanvas::OnResize(wxSizeEvent& event)
{
}

void T100WxPaintCanvas::OnLeftDClick(wxMouseEvent& event)
{
    T100WxPaintCanvasStateBase*     current         = T100NULL;

    std::lock_guard<std::mutex>     lock(m_mutex);

    current = m_manager.GetCurrent();
    if(!current)return;

    current->OnMouseLeftDClick(event);
}

void T100WxPaintCanvas::OnLeftDown(wxMouseEvent& event)
{
    m_scale = 1.2 * m_scale;
    Refresh();
}
