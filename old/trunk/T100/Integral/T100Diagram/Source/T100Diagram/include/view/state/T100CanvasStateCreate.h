#ifndef T100CANVASSTATECREATE_H
#define T100CANVASSTATECREATE_H

#include "T100CanvasState.h"

class T100CanvasStateCreate : public T100CanvasState
{
    public:
        T100CanvasStateCreate();
        virtual ~T100CanvasStateCreate();

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

#endif // T100CANVASSTATECREATE_H
