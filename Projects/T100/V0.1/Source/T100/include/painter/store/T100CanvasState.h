#ifndef T100CANVASSTATE_H
#define T100CANVASSTATE_H

#include <wx/event.h>
#include "T100State.h"

namespace T100Painter{

class T100CanvasState : public T100Component::T100State
{
    public:
        T100CanvasState();
        virtual ~T100CanvasState();

        virtual T100VOID        OnPaint(wxPaintEvent& event) = 0;

        virtual T100VOID        OnMouseLeftDown(wxMouseEvent& event) = 0;
        virtual T100VOID        OnMouseLeftUp(wxMouseEvent& event) = 0;
        virtual T100VOID        OnMouseMove(wxMouseEvent& event) = 0;
        virtual T100VOID        OnMouseLeftDClick(wxMouseEvent& event) = 0;

    protected:

    private:
};

}

#endif // T100CANVASSTATE_H
