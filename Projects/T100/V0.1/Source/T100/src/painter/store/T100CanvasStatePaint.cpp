#include "T100CanvasStatePaint.h"

#include <wx/dcbuffer.h>
#include "T100PainterCallback.h"
#include "T100PainterView.h"
#include "T100PainterServe.h"
#include "T100ElementBase.h"

#include "T100TestTools.h"


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
    wxBufferedPaintDC       dc(canvas);

    T100Library::T100TestTools::Print(L"P1");

    dc.Clear();
    canvas->DoPrepareDC(dc);

    T100Library::T100TestTools::Print(L"P2");

    if(!canvas->m_elements)return;

    for(T100ElementBase* item : *(canvas->m_elements)){
        T100Library::T100TestTools::Print(L"P3");
        if(item){
            item->draw(dc);
        }else{
            T100Library::T100TestTools::Print(L"P4");
        }
    }

    T100Library::T100TestTools::Print(L"P5");
    dc.SetPen(*wxRED_PEN);

    if(canvas->m_current){
        T100Library::T100TestTools::Print(L"P6");
        canvas->m_current->draw(dc);
    }else{
        T100Library::T100TestTools::Print(L"P7");
    }

    T100Library::T100TestTools::Print(L"P8");
}

T100VOID T100CanvasStatePaint::OnMouseLeftDown(wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        current             = T100NULL;
    T100INT                 x, y, vx, vy;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    result = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
    if(!result)return;

    current = T100PainterCallback::getView()->getElementManager()->GetCurrent();
    if(!current)return;

    T100PainterCallback::getView()->getPaintCtrl()->Select(current);

    current->SetPaintStarting(vx, vy);


    //T100PainterCallback::getView()->getPaintCtrl()->Refresh();
}

T100VOID T100CanvasStatePaint::OnMouseLeftUp(wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        element             = T100NULL;
    T100ElementBase*        current             = T100NULL;
    T100INT                 x, y;
    T100INT                 vx, vy;

    T100Library::T100TestTools::Print(L"1");

    element = T100PainterCallback::getView()->getElementManager()->GetCurrent();

    T100Library::T100TestTools::Print(L"2");

    if(element){
        x       = event.GetPosition().x;
        y       = event.GetPosition().y;
        T100Library::T100TestTools::Print(L"3");
        result  = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
        if(!result)return;

        T100Library::T100TestTools::Print(L"4");
        result = element->SetEnding(vx, vy);
        if(result){
            T100Library::T100TestTools::Print(L"5");
            current = element->Clone();
            if(!current)return;

            T100Library::T100TestTools::Print(L"6");
            current->Position();

            T100Library::T100TestTools::Print(L"7");
            T100PainterCallback::getServe()->getCurrent()->getElements()->append(current);
            T100Library::T100TestTools::Print(L"8");
            T100PainterCallback::getView()->getPaintCtrl()->Select(current);
            T100Library::T100TestTools::Print(L"9");
            T100PainterCallback::getView()->getElementManager()->Deselect();
            T100Library::T100TestTools::Print(L"10");
            T100PainterCallback::getView()->getPropertiesPanel()->setElement(current);

            T100Library::T100TestTools::Print(L"11");
            //T100PainterCallback::getView()->getPaintCtrl()->Resize(current->getTailX(), current->getTailY());

            T100Library::T100TestTools::Print(L"12");
            T100PainterCallback::getView()->getPaintCtrl()->Refresh();

            T100Library::T100TestTools::Print(L"13");
            T100PainterCallback::getView()->getPaintCtrl()->SetFocus();
            T100Library::T100TestTools::Print(L"14");
            T100PainterCallback::getView()->getPaintCtrl()->Change(T100CANVAS_STATE_SELECTED);
        }
    }
}

T100VOID T100CanvasStatePaint::OnMouseMove(wxMouseEvent& event)
{
    T100BOOL                result          = T100FALSE;
    T100ElementBase*        current         = T100NULL;

    if(!event.ButtonIsDown(wxMOUSE_BTN_LEFT))return;

    current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
    if(current){
        T100INT     x, y, vx, vy;

        x   = event.GetPosition().x;
        y   = event.GetPosition().y;

        result = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
        result = current->PaintMove(vx, vy);
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
