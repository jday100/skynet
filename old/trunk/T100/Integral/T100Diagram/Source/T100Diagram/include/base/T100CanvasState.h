#ifndef T100CANVASSTATE_H
#define T100CANVASSTATE_H

#include <wx/event.h>
#include "T100State.h"

class T100Canvas;

class T100CanvasState : public T100State
{
    public:
        T100CanvasState();
        virtual ~T100CanvasState();

        virtual T100VOID            OnPaint(wxPaintEvent&, T100Canvas*) = 0;

        virtual T100VOID            OnKeyDown(wxKeyEvent&, T100Canvas*) = 0;
        virtual T100VOID            OnKeyUp(wxKeyEvent&, T100Canvas*) = 0;

        virtual T100VOID            OnMouseMove(wxMouseEvent&, T100Canvas*) = 0;
        virtual T100VOID            OnMouseWheel(wxMouseEvent&, T100Canvas*) = 0;
        virtual T100VOID            OnMouseLeftDown(wxMouseEvent&, T100Canvas*) = 0;
        virtual T100VOID            OnMouseLeftDClick(wxMouseEvent&, T100Canvas*) = 0;

    protected:

    private:
};

#endif // T100CANVASSTATE_H
