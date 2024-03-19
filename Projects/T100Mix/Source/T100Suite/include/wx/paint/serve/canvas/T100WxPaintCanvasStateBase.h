#ifndef T100WXPAINTCANVASSTATEBASE_H
#define T100WXPAINTCANVASSTATEBASE_H

#include <wx/event.h>
#include "base\T100State.h"

class T100WxPaintCanvas;

class T100WxPaintCanvasStateBase : public T100State
{
    public:
        T100WxPaintCanvasStateBase();
        virtual ~T100WxPaintCanvasStateBase();

        virtual T100VOID            OnPaint(wxPaintEvent& event, T100WxPaintCanvas* canvas) = 0;

        virtual T100VOID            OnMouseLeftDown(wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftUp(wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftDClick(wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseMove(wxMouseEvent& event) = 0;

        virtual T100VOID            OnKeyUp(wxKeyEvent& event) = 0;

    protected:

    private:
};

#endif // T100WXPAINTCANVASSTATEBASE_H
