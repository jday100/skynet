#include "T100CanvasStatePaint.h"

#include "T100ElementBase.h"
#include "T100Canvas.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"
#include "T100PainterCallback.h"

T100CanvasStatePaint::T100CanvasStatePaint()
    :T100CanvasState()
{
    //ctor
}

T100CanvasStatePaint::~T100CanvasStatePaint()
{
    //dtor
}

T100VOID T100CanvasStatePaint::OnEraseBackGround(T100Canvas* canvas, wxEraseEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnPaint(T100Canvas* canvas, wxPaintEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnMouseEnter(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnMouseLeave(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnMouseLeftDown(T100Canvas* canvas, wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        current         = T100NULL;
    T100INT                 x, y, vx, vy;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    result  = T100PainterCallback::getView()->getCanvas()->GetVirtualPosition(x, y, vx, vy);
    if(!result)return;

    current = T100PainterCallback::getView()->getElementsPanel()->getElementsDrawer()->Current();
    if(!current)return;

    T100PainterCallback::getView()->getCanvas()->Select(current);

    current->SetStartingPoint(vx, vy);
}

T100VOID T100CanvasStatePaint::OnMouseLeftUp(T100Canvas* canvas, wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        element             = T100NULL;
    T100ElementBase*        current             = T100NULL;
    T100INT                 x, y;
    T100INT                 vx, vy;

    element = T100PainterCallback::getView()->getElementsPanel()->getElementsDrawer()->Current();

    if(element){
        x   = event.GetPosition().x;
        y   = event.GetPosition().y;

        result  = T100PainterCallback::getView()->getCanvas()->GetVirtualPosition(x, y, vx, vy);
        if(!result)return;

        current->Position();

        T100PainterCallback::getServe()->getElementDrawer()->Append(current);
        T100PainterCallback::getView()->getCanvas()->Select(current);
        T100PainterCallback::getServe()->getElementsDrawer()->Deselect();
        T100PainterCallback::getView()->getPropertiesPanel()->setElement(current);

        T100PainterCallback::getView()->getCanvas()->Refresh();

        T100PainterCallback::getView()->getCanvas()->SetFocus();

        T100PainterCallback::getView()->getCanvas()->Change(T100CANVAS_STATE_SELECTED);
    }
}

T100VOID T100CanvasStatePaint::OnMouseLeftDClick(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnMouseMove(T100Canvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnKeyUp(T100Canvas* canvas, wxKeyEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnResize(T100Canvas* canvas, wxSizeEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnScrollBottom(T100Canvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnScrollLineDown(T100Canvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnScrollPageDown(T100Canvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnScrollThumbTrack(T100Canvas* canvas, wxScrollWinEvent& event)
{

}
