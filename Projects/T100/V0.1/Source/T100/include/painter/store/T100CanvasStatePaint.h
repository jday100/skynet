#ifndef T100CANVASSTATEPAINT_H
#define T100CANVASSTATEPAINT_H

#include "T100CanvasState.h"

namespace T100Painter{

class T100CanvasStatePaint : public T100CanvasState
{
    public:
        T100CanvasStatePaint();
        virtual ~T100CanvasStatePaint();

        T100VOID            OnPaint(wxPaintEvent& event);

        T100VOID            OnMouseLeftDown(wxMouseEvent& event);
        T100VOID            OnMouseLeftUp(wxMouseEvent& event);
        T100VOID            OnMouseMove(wxMouseEvent& event);
        T100VOID            OnMouseLeftDClick(wxMouseEvent& event);

    protected:

    private:
};

}

#endif // T100CANVASSTATEPAINT_H
