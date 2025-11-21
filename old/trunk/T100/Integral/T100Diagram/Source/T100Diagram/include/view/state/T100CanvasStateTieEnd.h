#ifndef T100CANVASSTATETIEEND_H
#define T100CANVASSTATETIEEND_H

#include "T100CanvasState.h"

class T100CanvasStateTieEnd : public T100CanvasState
{
    public:
        T100CanvasStateTieEnd();
        virtual ~T100CanvasStateTieEnd();

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

#endif // T100CANVASSTATETIEEND_H
