#ifndef T100CANVASSTATEPAINT_H
#define T100CANVASSTATEPAINT_H

#include "T100CanvasState.h"

class T100CanvasStatePaint : public T100CanvasState
{
    public:
        T100CanvasStatePaint();
        virtual ~T100CanvasStatePaint();

        virtual T100VOID            OnPaint(wxPaintEvent&, T100Canvas*);

        virtual T100VOID            OnKeyDown(wxKeyEvent&, T100Canvas*);
        virtual T100VOID            OnKeyUp(wxKeyEvent&, T100Canvas*);

        virtual T100VOID            OnMouseMove(wxMouseEvent&, T100Canvas*);
        virtual T100VOID            OnMouseWheel(wxMouseEvent&, T100Canvas*);
        virtual T100VOID            OnMouseLeftDown(wxMouseEvent&, T100Canvas*);
        virtual T100VOID            OnMouseLeftDClick(wxMouseEvent&, T100Canvas*);

    protected:

    private:
};

#endif // T100CANVASSTATEPAINT_H
