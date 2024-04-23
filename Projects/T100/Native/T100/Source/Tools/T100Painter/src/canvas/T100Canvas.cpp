#include "T100Canvas.h"

#include <wx/dcbuffer.h>
#include "T100WxEventData.h"

const long T100Canvas::ID_THREAD_LOAD = wxNewId();

BEGIN_EVENT_TABLE(T100Canvas,wxScrolledWindow)
    EVT_PAINT(T100Canvas::OnPaint)
    EVT_ERASE_BACKGROUND(T100Canvas::OnEraseBackGround)
    //
    EVT_ENTER_WINDOW(T100Canvas::OnMouseEnter)
    EVT_LEAVE_WINDOW(T100Canvas::OnMouseLeave)
    //
    EVT_LEFT_DOWN(T100Canvas::OnMouseLeftDown)
    EVT_LEFT_UP(T100Canvas::OnMouseLeftUp)
    EVT_LEFT_DCLICK(T100Canvas::OnMouseLeftDClick)
    EVT_MOTION(T100Canvas::OnMouseMove)
    //
    EVT_KEY_UP(T100Canvas::OnKeyUp)
    //
    EVT_SIZE(T100Canvas::OnResize)
    //
    EVT_SCROLLWIN_BOTTOM(T100Canvas::OnScrollBottom)
    EVT_SCROLLWIN_LINEDOWN(T100Canvas::OnScrollLineDown)
    EVT_SCROLLWIN_PAGEDOWN(T100Canvas::OnScrollPageDown)
    EVT_SCROLLWIN_THUMBTRACK(T100Canvas::OnScrollThumbTrack)
    //
    EVT_THREAD(ID_THREAD_LOAD, T100Canvas::OnThreadLoad)
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
    create();
}

T100Canvas::~T100Canvas()
{
    //dtor
    destroy();
}

T100VOID T100Canvas::create()
{
    m_transverter.Change(T100CANVAS_STATE_NONE);
}

T100VOID T100Canvas::destroy()
{

}

T100VOID T100Canvas::SetDiagramInfo(T100DiagramInfo* diagram)
{
    m_diagram   = diagram;
}

T100DiagramInfo* T100Canvas::GetDiagramInfo()
{
    return m_diagram;
}

T100VOID T100Canvas::Select(T100ElementBase* element)
{
    std::lock_guard<std::mutex>         lock(m_mutex);
    m_current   = element;
}

T100VOID T100Canvas::Remove(T100ElementBase* element)
{
    //m_diagram->getElements()->find(element);


}

T100ElementBase* T100Canvas::Current()
{
    std::lock_guard<std::mutex>         lock(m_mutex);
    return m_current;
}

T100VOID T100Canvas::Change(T100WORD state)
{
    m_transverter.Change(state);
    Refresh();
}

T100BOOL T100Canvas::GetVirtualPosition(T100INT x, T100INT y, T100INT& vx, T100INT& vy)
{
    T100INT         sx, sy;

    GetViewStart(&sx, &sy);

    vx  = x + sx * 10;
    vy  = y + sy * 10;

    return T100TRUE;
}

T100VOID T100Canvas::Paint()
{
    wxBufferedPaintDC                   dc(this);

    dc.Clear();
    this->DoPrepareDC(dc);

    if(!m_diagram)return;

    T100PAINTER_ELEMENT_VECTOR*         elements            = T100NULL;

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

void T100Canvas::OnEraseBackGround(wxEraseEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnEraseBackGround(this, event);
    }
}

void T100Canvas::OnPaint(wxPaintEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnPaint(this, event);
    }
}

void T100Canvas::OnMouseEnter(wxMouseEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnMouseEnter(this, event);
    }
}

void T100Canvas::OnMouseLeave(wxMouseEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnMouseLeave(this, event);
    }
}

void T100Canvas::OnMouseLeftDown(wxMouseEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnMouseLeftDown(this, event);
    }
}

void T100Canvas::OnMouseLeftUp(wxMouseEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnMouseLeftUp(this, event);
    }
}

void T100Canvas::OnMouseLeftDClick(wxMouseEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnMouseLeftDClick(this, event);
    }
}

void T100Canvas::OnMouseMove(wxMouseEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnMouseMove(this, event);
    }
}

void T100Canvas::OnKeyUp(wxKeyEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnKeyUp(this, event);
    }
}

void T100Canvas::OnResize(wxSizeEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnResize(this, event);
    }
}

void T100Canvas::OnScrollBottom(wxScrollWinEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnScrollBottom(this, event);
    }
}

void T100Canvas::OnScrollLineDown(wxScrollWinEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnScrollLineDown(this, event);
    }
}

void T100Canvas::OnScrollPageDown(wxScrollWinEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnScrollPageDown(this, event);
    }
}

void T100Canvas::OnScrollThumbTrack(wxScrollWinEvent& event)
{
    T100CanvasState*            state           = T100NULL;

    state   = m_transverter.Current();

    if(state){
        state->OnScrollThumbTrack(this, event);
    }
}

void T100Canvas::OnThreadLoad(wxThreadEvent& event)
{
    T100WxEventData*            data            = T100NULL;

    data    = dynamic_cast<T100WxEventData*>(event.GetEventObject());

    if(data){
        T100DiagramInfo*        diagram;

        diagram = (T100DiagramInfo*)data->getData();
        if(diagram){
            m_diagram   = diagram;
            Refresh();
        }
    }
}
