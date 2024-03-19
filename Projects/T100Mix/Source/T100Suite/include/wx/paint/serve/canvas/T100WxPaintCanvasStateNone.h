#ifndef T100WXPAINTCANVASSTATENONE_H
#define T100WXPAINTCANVASSTATENONE_H

#include "T100WxPaintCanvasStateBase.h"

class T100WxPaintCanvasStateNone : public T100WxPaintCanvasStateBase
{
    public:
        T100WxPaintCanvasStateNone();
        virtual ~T100WxPaintCanvasStateNone();

        virtual T100VOID            OnPaint(wxPaintEvent& event, T100WxPaintCanvas* canvas);

        virtual T100VOID            OnMouseLeftDown(wxMouseEvent& event);
        virtual T100VOID            OnMouseLeftUp(wxMouseEvent& event);
        virtual T100VOID            OnMouseLeftDClick(wxMouseEvent& event);
        virtual T100VOID            OnMouseMove(wxMouseEvent& event);

        virtual T100VOID            OnKeyUp(wxKeyEvent& event);

    protected:

    private:
};

#endif // T100WXPAINTCANVASSTATENONE_H
