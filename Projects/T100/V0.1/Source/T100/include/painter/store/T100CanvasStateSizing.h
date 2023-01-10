#ifndef T100CANVASSTATESIZING_H
#define T100CANVASSTATESIZING_H

#include "T100CanvasState.h"

namespace T100Painter{

class T100CanvasStateSizing : public T100CanvasState
{
    public:
        T100CanvasStateSizing();
        virtual ~T100CanvasStateSizing();

        T100VOID            OnPaint(wxPaintEvent& event, T100PainterCanvas* canvas);

        T100VOID            OnMouseLeftDown(wxMouseEvent& event);
        T100VOID            OnMouseLeftUp(wxMouseEvent& event);
        T100VOID            OnMouseMove(wxMouseEvent& event);
        T100VOID            OnMouseLeftDClick(wxMouseEvent& event);

        T100VOID            OnKeyUp(wxKeyEvent& event);

    protected:

    private:
};

}

#endif // T100CANVASSTATESIZING_H
