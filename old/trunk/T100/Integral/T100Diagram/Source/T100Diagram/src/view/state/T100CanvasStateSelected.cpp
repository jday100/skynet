#include "T100CanvasStateSelected.h"

#include <wx/dcbuffer.h>
#include "T100Canvas.h"
#include "T100DiagramInvoking.h"

T100CanvasStateSelected::T100CanvasStateSelected() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStateSelected::~T100CanvasStateSelected()
{
    //dtor
}

T100VOID T100CanvasStateSelected::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
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

T100VOID T100CanvasStateSelected::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{
    T100BOOL                result;

    if(!canvas){
        return;
    }

    switch(event.GetKeyCode()){
    case WXK_DELETE:
        {
            T100DiagramInvoking::OnEditCut();
        }
        break;
    }
}

T100VOID T100CanvasStateSelected::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{
    T100BOOL                result;

    switch(event.GetKeyCode()){
    case WXK_DELETE:
        {

        }
        break;
    }
}

T100VOID T100CanvasStateSelected::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas->m_current){
        wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());
        canvas->m_current->Move(value.x, value.y);
        canvas->Refresh();
    }
}

T100VOID T100CanvasStateSelected::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateSelected::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas->m_current){
        wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());
        canvas->m_current->Move(value.x, value.y);
        canvas->Select(T100NULL);
        canvas->Change(T100CANVAS_STATE_SHOW);
    }
}

T100VOID T100CanvasStateSelected::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    wxPoint     value   = canvas->GetVirtualPosition(event.GetPosition());

    T100DiagramInvoking::OnMouseDClick(value.x, value.y);
}
