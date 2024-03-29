#include "T100WPainterCanvas.h"

#include <wx/dcclient.h>
#include "T100WxEventData.h"

const long T100WPainterCanvas::ID_THREAD_LOAD = wxNewId();

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
    //
    EVT_THREAD(ID_THREAD_LOAD, T100WPainterCanvas::OnThreadLoad)
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

T100VOID T100WPainterCanvas::SetDiagramInfo(T100DiagramInfo* diagram)
{
    m_diagram   = diagram;
}

T100DiagramInfo* T100WPainterCanvas::GetDiagramInfo()
{
    return m_diagram;
}

T100VOID T100WPainterCanvas::Select(T100ElementBase* element)
{
    std::lock_guard<std::mutex>         lock(m_mutex);
    m_current   = element;
}

T100VOID T100WPainterCanvas::Deselect()
{
    std::lock_guard<std::mutex>         lock(m_mutex);
    m_current   = T100NULL;
}

T100VOID T100WPainterCanvas::Remove(T100ElementBase* element)
{
    /*
    if(m_diagram->getElements()->erase(element)){
        m_current   = T100NULL;
        return T100TRUE;
    }
    */
}

T100ElementBase* T100WPainterCanvas::Current()
{
    std::lock_guard<std::mutex>         lock(m_mutex);
    return m_current;
}

T100VOID T100WPainterCanvas::Change(T100WORD state)
{
    m_transverter.Change(state);
    Refresh();
}

T100VOID T100WPainterCanvas::Paint()
{
    if(!m_diagram)return;

    T100WPAINTER_ELEMENT_VECTOR*        elements            = T100NULL;
    wxClientDC                          dc(this);

    elements    = m_diagram->getElements();

    if(elements){
        for(T100ElementBase* element : *elements){
            if(element){
                element->Draw(dc);
            }
        }
    }

    if(m_current){
        m_current->Draw(dc);
    }
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
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnMouseEnter(this, event);
    }
}

void T100WPainterCanvas::OnMouseLeave(wxMouseEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnMouseLeave(this, event);
    }
}

void T100WPainterCanvas::OnMouseLeftDown(wxMouseEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnMouseLeftDown(this, event);
    }
}

void T100WPainterCanvas::OnMouseLeftUp(wxMouseEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnMouseLeftUp(this, event);
    }
}

void T100WPainterCanvas::OnMouseLeftDClick(wxMouseEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnMouseLeftDClick(this, event);
    }
}

void T100WPainterCanvas::OnMouseMove(wxMouseEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnMouseMove(this, event);
    }
}

void T100WPainterCanvas::OnKeyUp(wxKeyEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnKeyUp(this, event);
    }
}

void T100WPainterCanvas::OnResize(wxSizeEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnResize(this, event);
    }
}

void T100WPainterCanvas::OnScrollBottom(wxScrollWinEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnScrollBottom(this, event);
    }
}

void T100WPainterCanvas::OnScrollLineDown(wxScrollWinEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnScrollLineDown(this, event);
    }
}

void T100WPainterCanvas::OnScrollPageDown(wxScrollWinEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnScrollPageDown(this, event);
    }
}

void T100WPainterCanvas::OnScrollThumbTrack(wxScrollWinEvent& event)
{
    T100WPainterCanvasState*            state           = T100NULL;
    state   = m_transverter.GetCurrent();

    if(state){
        state->OnScrollThumbTrack(this, event);
    }
}

void T100WPainterCanvas::OnThreadLoad(wxThreadEvent& event)
{
    T100WxEventData*        data            = T100NULL;

    data    = dynamic_cast<T100WxEventData*>(event.GetEventObject());

    if(data){
        T100DiagramInfo*    diagram;

        diagram = (T100DiagramInfo*)data->getData();
        if(diagram){
            m_diagram   = diagram;
        }
    }
}
