#ifndef T100WPAINTERCANVASSTATEEDIT_H
#define T100WPAINTERCANVASSTATEEDIT_H

#include "T100WPainterCanvasState.h"

class T100WPainterCanvasStateEdit : public T100WPainterCanvasState
{
    public:
        T100WPainterCanvasStateEdit();
        virtual ~T100WPainterCanvasStateEdit();

        T100VOID            OnEraseBackGround(T100WPainterCanvas*, wxEraseEvent& event);
        T100VOID            OnPaint(T100WPainterCanvas*, wxPaintEvent& event);

        T100VOID            OnMouseEnter(T100WPainterCanvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeave(T100WPainterCanvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeftDown(T100WPainterCanvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeftUp(T100WPainterCanvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeftDClick(T100WPainterCanvas*, wxMouseEvent& event);
        T100VOID            OnMouseMove(T100WPainterCanvas*, wxMouseEvent& event);

        T100VOID            OnKeyUp(T100WPainterCanvas*, wxKeyEvent& event);

        T100VOID            OnResize(T100WPainterCanvas*, wxSizeEvent& event);

        T100VOID            OnScrollBottom(T100WPainterCanvas*, wxScrollWinEvent& event);
        T100VOID            OnScrollLineDown(T100WPainterCanvas*, wxScrollWinEvent& event);
        T100VOID            OnScrollPageDown(T100WPainterCanvas*, wxScrollWinEvent& event);
        T100VOID            OnScrollThumbTrack(T100WPainterCanvas*, wxScrollWinEvent& event);

    protected:

    private:
};

#endif // T100WPAINTERCANVASSTATEEDIT_H
