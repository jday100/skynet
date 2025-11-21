#ifndef T100CANVASSTATESHOW_H
#define T100CANVASSTATESHOW_H

#include "T100CanvasState.h"

class T100CanvasStateShow : public T100CanvasState
{
    public:
        T100CanvasStateShow();
        virtual ~T100CanvasStateShow();

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

#endif // T100CANVASSTATESHOW_H
