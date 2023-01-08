#include "T100CanvasStateCommon.h"

#include "T100PainterCallback.h"
#include "T100PainterView.h"
#include "T100ElementBase.h"

#include <wx/dcbuffer.h>

namespace T100Painter{

T100CanvasStateCommon::T100CanvasStateCommon()
    :T100CanvasState()
{
    //ctor
}

T100CanvasStateCommon::~T100CanvasStateCommon()
{
    //dtor
}

T100VOID T100CanvasStateCommon::OnPaint(wxPaintEvent& event, T100PainterCanvas* canvas)
{
    wxAutoBufferedPaintDC       dc(canvas);

    dc.Clear();
    canvas->DoPrepareDC(dc);

    if(!canvas->m_elements)return;

    for(T100ElementBase* item : *(canvas->m_elements)){
        item->draw(dc);
    }
}

T100VOID T100CanvasStateCommon::OnMouseLeftDown(wxMouseEvent& event)
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

T100VOID T100CanvasStateCommon::OnMouseLeftUp(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateCommon::OnMouseMove(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateCommon::OnMouseLeftDClick(wxMouseEvent& event)
{

}

}
