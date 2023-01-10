#include "T100CanvasStatePaint.h"

#include <wx/dcbuffer.h>
#include "T100PainterCallback.h"
#include "T100PainterView.h"
#include "T100PainterServe.h"
#include "T100ElementBase.h"


namespace T100Painter{

T100CanvasStatePaint::T100CanvasStatePaint()
    :T100CanvasState()
{
    //ctor
}

T100CanvasStatePaint::~T100CanvasStatePaint()
{
    //dtor
}

T100VOID T100CanvasStatePaint::OnPaint(wxPaintEvent& event, T100PainterCanvas* canvas)
{
    wxAutoBufferedPaintDC       dc(canvas);

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

T100VOID T100CanvasStatePaint::OnMouseLeftDown(wxMouseEvent& event)
{
    T100ElementBase*        current             = T100NULL;

    current = T100PainterCallback::getView()->getElementManager()->GetCurrent();

    if(current){
        current->MouseLeftDown(event.GetPosition().x, event.GetPosition().y);
        T100PainterCallback::getView()->getPaintCtrl()->Select(current);
    }
}

T100VOID T100CanvasStatePaint::OnMouseLeftUp(wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        element             = T100NULL;
    T100ElementBase*        current             = T100NULL;
    T100INT                 x, y;
    T100INT                 vx, vy;

    element = T100PainterCallback::getView()->getElementManager()->GetCurrent();

    if(element){
        x       = event.GetPosition().x;
        y       = event.GetPosition().y;
        result  = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
        if(!result)return;

        result = element->MouseLeftUp(vx, vy);
        if(result){
            current = element->Clone();
            if(!current)return;

            current->Position();

            T100PainterCallback::getServe()->getCurrent()->getElements()->append(current);
            T100PainterCallback::getView()->getPaintCtrl()->Select(current);
            T100PainterCallback::getView()->getElementManager()->Deselect();
            T100PainterCallback::getView()->getPropertiesPanel()->setElement(current);

            T100PainterCallback::getView()->getPaintCtrl()->Resize(current->getTailX(), current->getTailY());

            T100PainterCallback::getView()->getPaintCtrl()->Refresh();

            T100PainterCallback::getView()->getPaintCtrl()->SetFocus();
            T100PainterCallback::getView()->getPaintCtrl()->Change(T100CANVAS_STATE_SELECTED);
        }
    }
}

T100VOID T100CanvasStatePaint::OnMouseMove(wxMouseEvent& event)
{
    T100BOOL                result          = T100FALSE;
    T100ElementManager*     manager         = T100NULL;
    T100ElementBase*        current         = T100NULL;

    manager = T100PainterCallback::getView()->getElementManager();
    if(!manager)return;

    current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
    if(current){
        T100INT     x, y, vx, vy;

        x   = event.GetPosition().x;
        y   = event.GetPosition().y;

        result = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
        result = current->MouseMove(vx, vy);
        T100PainterCallback::getView()->getPaintCtrl()->MouseMove(vx, vy);
        //T100Library::T100TestTools::Print(L"Refresh");
        T100PainterCallback::getView()->getPaintCtrl()->Refresh();
    }
}

T100VOID T100CanvasStatePaint::OnMouseLeftDClick(wxMouseEvent& event)
{

}

T100VOID T100CanvasStatePaint::OnKeyUp(wxKeyEvent& event)
{

}

}
