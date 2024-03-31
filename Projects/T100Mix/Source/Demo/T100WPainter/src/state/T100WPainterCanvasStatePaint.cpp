#include "T100WPainterCanvasStatePaint.h"

#include <wx/dcclient.h>
#include "T100ElementBase.h"
#include "T100WPainterCanvas.h"
#include "T100WPainterServe.h"
#include "T100WPainterView.h"
#include "T100WPainterCallback.h"

T100WPainterCanvasStatePaint::T100WPainterCanvasStatePaint()
    :T100WPainterCanvasState()
{
    //ctor
}

T100WPainterCanvasStatePaint::~T100WPainterCanvasStatePaint()
{
    //dtor
}

T100VOID T100WPainterCanvasStatePaint::OnEraseBackGround(T100WPainterCanvas* canvas, wxEraseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnPaint(T100WPainterCanvas* canvas, wxPaintEvent& event)
{
    wxClientDC          dc(canvas);

    dc.DrawCircle(100, 100, 10);

    if(canvas){
        canvas->Paint();
    }
}

T100VOID T100WPainterCanvasStatePaint::OnMouseEnter(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeave(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeftDown(T100WPainterCanvas* canvas, wxMouseEvent& event)
{
    T100BOOL                    result;
    T100ElementBase*            current             = T100NULL;
    T100INT                     x, y, vx, vy;

    x       = event.GetPosition().x;
    y       = event.GetPosition().y;

    current = T100WPainterCallback::getServe()->getElementDrawer()->Create();

    current->SetStartingPoint(x, y);

    T100WPainterCallback::getView()->getCanvas()->Select(current);

}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeftUp(T100WPainterCanvas* canvas, wxMouseEvent& event)
{
    T100BOOL                    result;
    T100ElementBase*            current             = T100NULL;
    T100INT                     x, y, vx, vy;

    x       = event.GetPosition().x;
    y       = event.GetPosition().y;

    current = T100WPainterCallback::getView()->getCanvas()->Current();

    current->SetTerminalPoint(x, y);

    T100WPainterCallback::getServe()->getElementDrawer()->Append(current);
    T100WPainterCallback::getView()->getCanvas()->Select(current);

    T100WPainterCallback::getView()->getCanvas()->Change(T100CANVAS_STATE_NONE);
}

T100VOID T100WPainterCanvasStatePaint::OnMouseLeftDClick(T100WPainterCanvas* canvas, wxMouseEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnMouseMove(T100WPainterCanvas* canvas, wxMouseEvent& event)
{
    T100BOOL                    result;
    T100ElementBase*            current             = T100NULL;
    T100INT                     x, y, vx, vy;

    if(event.LeftIsDown()){
        x       = event.GetPosition().x;
        y       = event.GetPosition().y;

        current = T100WPainterCallback::getView()->getCanvas()->Current();

        if(current){
            current->SetTerminalPoint(x, y);
            canvas->Refresh();
        }
    }else{

    }
}

T100VOID T100WPainterCanvasStatePaint::OnKeyUp(T100WPainterCanvas* canvas, wxKeyEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnResize(T100WPainterCanvas* canvas, wxSizeEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollBottom(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollLineDown(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollPageDown(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

T100VOID T100WPainterCanvasStatePaint::OnScrollThumbTrack(T100WPainterCanvas* canvas, wxScrollWinEvent& event)
{

}

