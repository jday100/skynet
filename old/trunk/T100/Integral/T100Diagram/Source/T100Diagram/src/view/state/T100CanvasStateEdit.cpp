#include "T100CanvasStateEdit.h"

#include <wx/dcbuffer.h>
#include "T100Canvas.h"
#include "T100DiagramInvoking.h"

T100CanvasStateEdit::T100CanvasStateEdit() :
    T100CanvasState()
{
    //ctor
}

T100CanvasStateEdit::~T100CanvasStateEdit()
{
    //dtor
}

T100VOID T100CanvasStateEdit::OnPaint(wxPaintEvent& event, T100Canvas* canvas)
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

T100VOID T100CanvasStateEdit::OnKeyDown(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateEdit::OnKeyUp(wxKeyEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateEdit::OnMouseMove(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateEdit::OnMouseWheel(wxMouseEvent& event, T100Canvas* canvas)
{

}

T100VOID T100CanvasStateEdit::OnMouseLeftDown(wxMouseEvent& event, T100Canvas* canvas)
{
    if(!canvas){
        return;
    }

    if(canvas){
        canvas->EditFinished();
    }
}

T100VOID T100CanvasStateEdit::OnMouseLeftDClick(wxMouseEvent& event, T100Canvas* canvas)
{

}
