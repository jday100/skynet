#include "T100CanvasStateSelected.h"

#include <wx/dcbuffer.h>
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
T100VOID T100CanvasStateSelected::OnPaint(wxPaintEvent& event, T100PainterCanvas* canvas)
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
    if(result){
        current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
        if(!current)return;

        current->MouseLeftDown(vx, vy);

        T100PainterCallback::getView()->getPropertiesPanel()->setElement(current);
    }else{
        T100PainterCallback::getView()->getPropertiesPanel()->Clear();
        T100PainterCallback::getView()->getPaintCtrl()->Change(T100CANVAS_STATE_COMMON);
    }

    T100PainterCallback::getView()->getPaintCtrl()->Refresh();
}

T100VOID T100CanvasStateSelected::OnMouseLeftUp(wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        current             = T100NULL;
    T100INT                 x, y, vx, vy;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    result = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
    if(!result)return;

    current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
    if(!current)return;

    current->MouseLeftUp(vx, vy);
    current->Move(vx, vy);
}

T100VOID T100CanvasStateSelected::OnMouseMove(wxMouseEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        current         = T100NULL;

    if(event.ButtonIsDown(wxMOUSE_BTN_LEFT)){
        T100INT             x, y, vx, vy;

        x   = event.GetPosition().x;
        y   = event.GetPosition().y;

        result = T100PainterCallback::getView()->getPaintCtrl()->GetVirtualPosition(x, y, vx, vy);
        if(!result)return;

        current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
        if(!current)return;

        current->Move(vx, vy);

        T100PainterCallback::getView()->getPaintCtrl()->Refresh();
    }
}

T100VOID T100CanvasStateSelected::OnMouseLeftDClick(wxMouseEvent& event)
{

}

T100VOID T100CanvasStateSelected::OnKeyUp(wxKeyEvent& event)
{
    T100BOOL                result;
    T100ElementBase*        current         = T100NULL;

    switch(event.GetKeyCode()){
    case WXK_DELETE:
        {
            current = T100PainterCallback::getView()->getPaintCtrl()->GetCurrent();
            if(!current)return;

            result = T100PainterCallback::getView()->getPaintCtrl()->Remove(current);

            if(result){
                T100PainterCallback::getView()->getPropertiesPanel()->Clear();
                T100PainterCallback::getView()->getPaintCtrl()->Change(T100CANVAS_STATE_COMMON);

                T100PainterCallback::getView()->getPaintCtrl()->Refresh();
            }
        }
        break;
    }

}

}
