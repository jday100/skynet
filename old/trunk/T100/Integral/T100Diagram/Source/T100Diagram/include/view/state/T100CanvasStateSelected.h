#ifndef T100CANVASSTATESELECTED_H
#define T100CANVASSTATESELECTED_H

#include "T100CanvasState.h"

class T100CanvasStateSelected : public T100CanvasState
{
    public:
        T100CanvasStateSelected();
        virtual ~T100CanvasStateSelected();

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

#endif // T100CANVASSTATESELECTED_H
