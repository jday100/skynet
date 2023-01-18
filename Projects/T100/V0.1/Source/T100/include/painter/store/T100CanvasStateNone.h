#ifndef T100CANVASSTATENONE_H
#define T100CANVASSTATENONE_H

#include "T100CanvasState.h"

namespace T100Painter{

class T100CanvasStateNone : public T100CanvasState
{
    public:
        T100CanvasStateNone();
        virtual ~T100CanvasStateNone();

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

#endif // T100CANVASSTATENONE_H
