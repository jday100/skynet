#include "T100CanvasStateShow.h"

#include <wx/dcbuffer.h>
#include "T100Canvas.h"
#include "T100DiagramInvoking.h"

T100CanvasStateShow::T100CanvasStateShow() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStateShow::~T100CanvasStateShow()
{
    //dtor
}

T100VOID T100CanvasStateShow::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
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

T100VOID T100CanvasStateShow::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateShow::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateShow::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateShow::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    T100INT     value;

    value   = event.GetWheelRotation() / event.GetWheelDelta();

    canvas->Scale(value);
}

T100VOID T100CanvasStateShow::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());

    T100DiagramInvoking::OnSelect(value.x, value.y);
}

T100VOID T100CanvasStateShow::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());

    T100DiagramInvoking::OnMouseDClick(value.x, value.y);
}
