#ifndef T100CANVASSTATEEDIT_H
#define T100CANVASSTATEEDIT_H

#include "T100CanvasState.h"

namespace T100Painter{

class T100CanvasStateEdit : public T100CanvasState
{
    public:
        T100CanvasStateEdit();
        virtual ~T100CanvasStateEdit();

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

#endif // T100CANVASSTATEEDIT_H
