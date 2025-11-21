#include "T100CanvasStateMoving.h"

#include <wx/dcbuffer.h>
#include "T100Canvas.h"
#include "T100DiagramInvoking.h"

T100CanvasStateMoving::T100CanvasStateMoving() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStateMoving::~T100CanvasStateMoving()
{
    //dtor
}

T100VOID T100CanvasStateMoving::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    wxBufferedPaintDC       dc(canvas);

    dc.Clear();
    canvas->DoPrepareDC(dc);

    if(!canvas->m_elements)return;

    wxPen   black(*wxBLACK);

    dc.SetPen(black);

    for(T100ElementBase* item : *(canvas->m_elements)){
        item->Draw(dc);
    }

    wxPen   pen(*wxRED);

    dc.SetPen(pen);

    if(canvas->m_current){
        canvas->m_current->Draw(dc);
    }
}

T100VOID T100CanvasStateMoving::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateMoving::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateMoving::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas->m_current){
        wxPoint     value   = event.GetPosition();
        canvas->m_current->Move(value.x, value.y);
        canvas->Refresh();
    }
}

T100VOID T100CanvasStateMoving::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateMoving::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas->m_current){
        wxPoint     value   = event.GetPosition();
        canvas->m_current->Move(value.x, value.y);

        T100DiagramInvoking::OnItemAppend();
    }
}

T100VOID T100CanvasStateMoving::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{
    wxPoint     value   = event.GetPosition();

    T100DiagramInvoking::OnMouseDClick(value.x, value.y);
}
