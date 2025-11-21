#include "T100Canvas.h"

#include <wx/textctrl.h>
#include "T100DiagramCommon.h"
#include "T100DiagramConfig.h"
#include "T100DiagramInvoking.h"

#include "T100AllElements.h"

BEGIN_EVENT_TABLE(T100Canvas, wxScrolledWindow)
    EVT_ENTER_WINDOW(OnEnter)
    EVT_LEAVE_WINDOW(OnLeave)
    //
    EVT_PAINT(T100Canvas::OnPaint)
    EVT_ERASE_BACKGROUND(T100Canvas::OnEraseBackGround)
    //
    EVT_MOTION(T100Canvas::OnMouseMove)
    EVT_MOUSEWHEEL(T100Canvas::OnMouseWheel)
    EVT_LEFT_DOWN(T100Canvas::OnMouseLeftDown)
    EVT_LEFT_UP(T100Canvas::OnMouseLeftUp)
    EVT_LEFT_DCLICK(T100Canvas::OnMouseLeftDClick)
    //
    EVT_KEY_DOWN(T100Canvas::OnKeyDown)
    EVT_KEY_UP(T100Canvas::OnKeyUp)
    //
    EVT_SIZE(T100Canvas::OnResize)
    //
    EVT_SCROLLWIN_BOTTOM(T100Canvas::OnScrollBottom)
    EVT_SCROLLWIN_LINEDOWN(T100Canvas::OnScrollLineDown)
    EVT_SCROLLWIN_PAGEDOWN(T100Canvas::OnScrollPageDown)
    EVT_SCROLLWIN_THUMBTRACK(T100Canvas::OnScrollThumbTrack)
    //
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
    init();
}

T100Canvas::~T100Canvas()
{
    //dtor
    uninit();
}

T100VOID T100Canvas::init()
{
    m_manager.Change(T100CANVAS_STATE_NONE);
}

T100VOID T100Canvas::uninit()
{

}

T100BOOL T100Canvas::Change(T100CANVAS_STATE state)
{
    m_manager.Change(state);
    return T100TRUE;
}

T100BOOL T100Canvas::Open(T100DiagramInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    m_diagram   = info;
    m_elements  = info->GetElements();

    T100UINT    x;
    T100UINT    y;

    x   = info->GetCanvas()->WIDTH;
    y   = info->GetCanvas()->HEIGHT;

    if( x == 0 || y == 0){
        wxSize  size    = GetClientSize();

        x   = size.GetWidth();
        y   = size.GetHeight();

        info->GetCanvas()->WIDTH        = x;
        info->GetCanvas()->HEIGHT       = y;
    }

    SetVirtualSize(x, y);

    SetScrollRate(T100DiagramConfig::T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_X, T100DiagramConfig::T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_Y);

    SetScrollbars(T100DiagramConfig::T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_X, T100DiagramConfig::T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_Y,
                  x / T100DiagramConfig::T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_X + 1, y / T100DiagramConfig::T100DIAGRAM_CANVAS_SCROLL_PIXELS_PER_UNIT_Y + 1);

    Change(T100CANVAS_STATE_SHOW);
    Refresh();

    return T100TRUE;
}

T100BOOL T100Canvas::Append()
{
    if(!m_current){
        return T100FALSE;
    }

    m_current   = T100NULL;

    SetCursor(wxCURSOR_ARROW);
    Change(T100CANVAS_STATE_SHOW);
    return T100TRUE;
}

T100BOOL T100Canvas::Save()
{
    return T100TRUE;
}

T100BOOL T100Canvas::Remove()
{
    m_current   = T100NULL;
    Change(T100CANVAS_STATE_SHOW);
    Refresh();
    return T100TRUE;
}

T100BOOL T100Canvas::Edit(T100ElementBase* element)
{
    if(!element){
        return T100FALSE;
    }

    m_current   = element;

    //wxPoint     value(element->GetOriginX(), element->GetOriginY());
    m_edit  = T100NEW wxTextCtrl(this, wxID_ANY, wxEmptyString, m_position, wxDefaultSize, wxTE_MULTILINE);

    m_edit->SetValue(element->GetName());
    m_edit->SetFocus();

    Change(T100CANVAS_STATE_EDIT);
    return T100TRUE;
}

T100BOOL T100Canvas::EditFinished()
{
    if(m_edit && m_current){
        m_current->SetName(m_edit->GetValue().ToStdWstring());
        T100SAFE_DELETE(m_edit);
    }else{
        return T100FALSE;
    }

    Change(T100CANVAS_STATE_SHOW);
    Refresh();
    return T100TRUE;
}

T100BOOL T100Canvas::Select(T100ElementBase* element)
{
    m_current   = element;

    Change(T100CANVAS_STATE_SELECTED);
    Refresh();
    return T100TRUE;
}

T100BOOL T100Canvas::TieStart(T100ElementBase* element)
{
    switch(m_current->GetType()){
    case T100ELEMENT_LIGATURE:
        {
            T100ElementLigature*    ligature        = dynamic_cast<T100ElementLigature*>(m_current);

            if(ligature){
                ligature->SetStart(element);
                Change(T100CANVAS_STATE_TIE_END);
                return T100TRUE;
            }
        }
        break;
    case T100ELEMENT_SINGLE_TRACK:
        {
            T100ElementSingleTrack*    singletrack          = dynamic_cast<T100ElementSingleTrack*>(m_current);

            if(singletrack){
                singletrack->SetStart(element);
                Change(T100CANVAS_STATE_TIE_END);
                return T100TRUE;
            }
        }
        break;
    case T100ELEMENT_BIDIRECTION:
        {
            T100ElementBidirection*    bidirection          = dynamic_cast<T100ElementBidirection*>(m_current);

            if(bidirection){
                bidirection->SetStart(element);
                Change(T100CANVAS_STATE_TIE_END);
                return T100TRUE;
            }
        }
        break;
    }

    return T100FALSE;
}

T100BOOL T100Canvas::TieEnd(T100ElementBase* element)
{
    switch(m_current->GetType()){
    case T100ELEMENT_LIGATURE:
        {
            T100ElementLigature*    ligature        = dynamic_cast<T100ElementLigature*>(m_current);

            if(ligature){
                ligature->SetEnd(element);
                m_elements->push_back(m_current);
                m_current   = T100NULL;
                SetCursor(wxCURSOR_ARROW);
                Change(T100CANVAS_STATE_SHOW);
                Refresh();
                return T100TRUE;
            }
        }
        break;
    case T100ELEMENT_SINGLE_TRACK:
        {
            T100ElementSingleTrack*    singletrack          = dynamic_cast<T100ElementSingleTrack*>(m_current);

            if(singletrack){
                singletrack->SetEnd(element);
                m_elements->push_back(m_current);
                m_current   = T100NULL;
                SetCursor(wxCURSOR_ARROW);
                Change(T100CANVAS_STATE_SHOW);
                Refresh();
                return T100TRUE;
            }
        }
        break;
    case T100ELEMENT_BIDIRECTION:
        {
            T100ElementBidirection*    bidirection          = dynamic_cast<T100ElementBidirection*>(m_current);

            if(bidirection){
                bidirection->SetEnd(element);
                m_elements->push_back(m_current);
                m_current   = T100NULL;
                SetCursor(wxCURSOR_ARROW);
                Change(T100CANVAS_STATE_SHOW);
                Refresh();
                return T100TRUE;
            }
        }
        break;
    }
    return T100FALSE;
}

T100BOOL T100Canvas::Scale(T100INT value)
{
    if(value >= 0){
        m_scale     *= 1.1;
    }else{
        if(m_scale < 0.1)return T100TRUE;
        m_scale     /= 1.1;
    }
    SetScale(m_scale, m_scale);

    if(m_scale > 1){
        SetVirtualSize(m_diagram->GetCanvas()->WIDTH * m_scale, m_diagram->GetCanvas()->HEIGHT * m_scale);
    }

    Refresh();
}

T100BOOL T100Canvas::Clear()
{
    T100SAFE_DELETE(m_diagram)
    m_current   = T100NULL;
    m_diagram   = T100NULL;
    m_elements  = T100NULL;
    Change(T100CANVAS_STATE_SHOW);
    Refresh();
    return T100TRUE;
}

T100BOOL T100Canvas::UpdateDiagram()
{
    SetVirtualSize(m_diagram->GetCanvas()->WIDTH, m_diagram->GetCanvas()->HEIGHT);
    Refresh();
    return T100TRUE;
}

T100VOID T100Canvas::OnEnter(wxMouseEvent& event)
{
    //SetCursor(wxCURSOR_CROSS);
    //Change(T100CANVAS_STATE_MOVING);
    SetFocus();
}

T100VOID T100Canvas::OnLeave(wxMouseEvent& event)
{

}

T100VOID T100Canvas::OnEraseBackGround(wxEraseEvent& event)
{

}

T100VOID T100Canvas::OnPaint(wxPaintEvent& event)
{
    T100CanvasState*    current     = T100NULL;

    current     = m_manager.GetCurrent();

    if(!current){
        return;
    }

    current->OnPaint(event, this);
}

T100VOID T100Canvas::OnMouseMove(wxMouseEvent& event)
{
    T100CanvasState*    current     = T100NULL;

    current     = m_manager.GetCurrent();

    if(!current){
        return;
    }

    T100STRING      value;
    wxPoint         point   = GetVirtualPosition(event.GetPosition());

    value   = "Position: X " + std::to_string(point.x) + " Y " + std::to_string(point.y);
    T100DiagramInvoking::OnCanvasPosition(value);
    current->OnMouseMove(event, this);
}

T100VOID T100Canvas::OnMouseWheel(wxMouseEvent& event)
{
    T100CanvasState*    current     = T100NULL;

    current     = m_manager.GetCurrent();

    if(!current){
        return;
    }

    current->OnMouseWheel(event, this);
}

T100VOID T100Canvas::OnMouseLeftDown(wxMouseEvent& event)
{
    T100CanvasState*    current     = T100NULL;

    current     = m_manager.GetCurrent();

    if(!current){
        return;
    }

    current->OnMouseLeftDown(event, this);
}

T100VOID T100Canvas::OnMouseLeftUp(wxMouseEvent& event)
{

}

T100VOID T100Canvas::OnMouseLeftDClick(wxMouseEvent& event)
{
    T100CanvasState*    current     = T100NULL;

    current     = m_manager.GetCurrent();

    if(!current){
        return;
    }

    m_position  = event.GetPosition();
    current->OnMouseLeftDClick(event, this);
}

T100VOID T100Canvas::OnKeyDown(wxKeyEvent& event)
{
    T100CanvasState*    current     = T100NULL;

    current     = m_manager.GetCurrent();

    if(!current){
        return;
    }

    current->OnKeyDown(event, this);
}

T100VOID T100Canvas::OnKeyUp(wxKeyEvent& event)
{
    T100CanvasState*    current     = T100NULL;

    current     = m_manager.GetCurrent();

    if(!current){
        return;
    }

    current->OnKeyUp(event, this);
}

T100VOID T100Canvas::OnResize(wxSizeEvent& event)
{

}

T100VOID T100Canvas::OnScrollBottom(wxScrollWinEvent& event)
{

}

T100VOID T100Canvas::OnScrollLineDown(wxScrollWinEvent& event)
{

}

T100VOID T100Canvas::OnScrollPageDown(wxScrollWinEvent& event)
{

}

T100VOID T100Canvas::OnScrollThumbTrack(wxScrollWinEvent& event)
{

}

wxPoint T100Canvas::GetVirtualPosition(wxPoint point)
{
    T100INT     x,  y;
    T100INT     sx, sy;
    T100INT     vx, vy;
    T100INT     ux, uy;

    GetViewStart(&x, &y);
    GetScrollPixelsPerUnit(&ux, &uy);

    sx  = ux * x + point.x;
    sy  = uy * y + point.y;

    vx  = sx / m_scale;
    vy  = sy / m_scale;

    return wxPoint(vx, vy);
}
