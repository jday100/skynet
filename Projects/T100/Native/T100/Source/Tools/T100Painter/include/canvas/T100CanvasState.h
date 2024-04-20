#ifndef T100CANVASSTATE_H
#define T100CANVASSTATE_H

#include <wx/event.h>
#include "T100State.h"
#include "T100CanvasCommon.h"
class T100Canvas;

class T100CanvasState : public T100State
{
    public:
        T100CanvasState();
        virtual ~T100CanvasState();

        virtual T100VOID            OnEraseBackGround(T100Canvas*, wxEraseEvent& event) = 0;
        virtual T100VOID            OnPaint(T100Canvas*, wxPaintEvent& event) = 0;

        virtual T100VOID            OnMouseEnter(T100Canvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeave(T100Canvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftDown(T100Canvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftUp(T100Canvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftDClick(T100Canvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseMove(T100Canvas*, wxMouseEvent& event) = 0;

        virtual T100VOID            OnKeyUp(T100Canvas*, wxKeyEvent& event) = 0;

        virtual T100VOID            OnResize(T100Canvas*, wxSizeEvent& event) = 0;

        virtual T100VOID            OnScrollBottom(T100Canvas*, wxScrollWinEvent& event) = 0;
        virtual T100VOID            OnScrollLineDown(T100Canvas*, wxScrollWinEvent& event) = 0;
        virtual T100VOID            OnScrollPageDown(T100Canvas*, wxScrollWinEvent& event) = 0;
        virtual T100VOID            OnScrollThumbTrack(T100Canvas*, wxScrollWinEvent& event) = 0;

    protected:

    private:
};

#endif // T100CANVASSTATE_H
