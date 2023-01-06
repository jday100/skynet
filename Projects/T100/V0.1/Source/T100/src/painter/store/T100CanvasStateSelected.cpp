#include "T100CanvasStateSelected.h"

#include "T100PainterCallback.h"
#include "T100PainterView.h"

namespace T100Painter{

T100CanvasStateSelected::T100CanvasStateSelected()
    :T100CanvasState()
{
    //ctor
}

T100CanvasStateSelected::~T100CanvasStateSelected()
{
    //dtor
}
T100VOID T100CanvasStateSelected::OnPaint(wxPaintEvent& event)
{
    T100PainterCallback::canvas_state_selected_paint(&event);
}

T100VOID T100CanvasStateSelected::OnMouseLeftDown(wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        current             = T100NULL;
    T100INT                 x, y, vx, vy;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    result = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
    if(!result)return;

    result = T100PainterCallback::getView()->getPaintCtrl()->Hit(vx, vy);
    T100PainterCallback::getView()->getPaintCtrl()->Refresh();
    if(!result)return;

    current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
    if(!current)return;

    T100PainterCallback::getView()->getPropertiesPanel()->setElement(current);
}

T100VOID T100CanvasStateSelected::OnMouseLeftUp(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateSelected::OnMouseMove(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateSelected::OnMouseLeftDClick(wxMouseEvent& event)
{

}

}
