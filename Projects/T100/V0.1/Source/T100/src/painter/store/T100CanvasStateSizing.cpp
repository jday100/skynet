#include "T100CanvasStateSizing.h"

#include "T100PainterCallback.h"
#include "T100PainterView.h"
#include "T100ElementBase.h"

#include <wx/dcbuffer.h>

namespace T100Painter{

T100CanvasStateSizing::T100CanvasStateSizing()
    :T100CanvasState()
{
    //ctor
}

T100CanvasStateSizing::~T100CanvasStateSizing()
{
    //dtor
}

T100VOID T100CanvasStateSizing::OnPaint(wxPaintEvent& event, T100PainterCanvas* canvas)
{
    wxBufferedPaintDC       dc(canvas);

    dc.Clear();
    canvas->DoPrepareDC(dc);

    if(!canvas->m_elements)return;

    for(T100ElementBase* item : *(canvas->m_elements)){
        item->draw(dc);
    }

    dc.SetPen(*wxRED_PEN);

    if(canvas->m_current){
        canvas->m_current->draw(dc);
    }
}

T100VOID T100CanvasStateSizing::OnMouseLeftDown(wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        current             = T100NULL;
    T100INT                 x, y, vx, vy;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    result = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
    if(!result)return;

    result = T100PainterCallback::getView()->getPaintCtrl()->Hit(vx, vy);
    if(result){
        current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
        if(!current)return;

        T100PainterCallback::getView()->getPropertiesPanel()->setElement(current);
        T100PainterCallback::getView()->getPaintCtrl()->Change(T100CANVAS_STATE_SELECTED);
    }else{
        T100PainterCallback::getView()->getPropertiesPanel()->Clear();
    }

    T100PainterCallback::getView()->getPaintCtrl()->Refresh();
}

T100VOID T100CanvasStateSizing::OnMouseLeftUp(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateSizing::OnMouseMove(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateSizing::OnMouseLeftDClick(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateSizing::OnKeyUp(wxKeyEvent& event)
{

}

}
