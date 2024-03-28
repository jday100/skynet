#ifndef T100WPAINTERCANVASSTATE_H
#define T100WPAINTERCANVASSTATE_H

#include <wx/event.h>
#include "T100State.h"
#include "T100WPainterCommon.h"
class T100WPainterCanvas;

class T100WPainterCanvasState : public T100State
{
    public:
        T100WPainterCanvasState();
        virtual ~T100WPainterCanvasState();

        virtual T100VOID            OnEraseBackGround(T100WPainterCanvas*, wxEraseEvent& event) = 0;
        virtual T100VOID            OnPaint(T100WPainterCanvas*, wxPaintEvent& event) = 0;

        virtual T100VOID            OnMouseEnter(T100WPainterCanvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeave(T100WPainterCanvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftDown(T100WPainterCanvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftUp(T100WPainterCanvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseLeftDClick(T100WPainterCanvas*, wxMouseEvent& event) = 0;
        virtual T100VOID            OnMouseMove(T100WPainterCanvas*, wxMouseEvent& event) = 0;

        virtual T100VOID            OnKeyUp(T100WPainterCanvas*, wxKeyEvent& event) = 0;

        virtual T100VOID            OnResize(T100WPainterCanvas*, wxSizeEvent& event) = 0;

        virtual T100VOID            OnScrollBottom(T100WPainterCanvas*, wxScrollWinEvent& event) = 0;
        virtual T100VOID            OnScrollLineDown(T100WPainterCanvas*, wxScrollWinEvent& event) = 0;
        virtual T100VOID            OnScrollPageDown(T100WPainterCanvas*, wxScrollWinEvent& event) = 0;
        virtual T100VOID            OnScrollThumbTrack(T100WPainterCanvas*, wxScrollWinEvent& event) = 0;

    protected:

    private:
};

#endif // T100WPAINTERCANVASSTATE_H
