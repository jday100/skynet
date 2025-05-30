#ifndef T100CANVASSTATESELECTED_H
#define T100CANVASSTATESELECTED_H

#include "T100CanvasState.h"

class T100CanvasStateSelected : public T100CanvasState
{
    public:
        T100CanvasStateSelected();
        virtual ~T100CanvasStateSelected();

        T100VOID            OnEraseBackGround(T100Canvas*, wxEraseEvent& event);
        T100VOID            OnPaint(T100Canvas*, wxPaintEvent& event);

        T100VOID            OnMouseEnter(T100Canvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeave(T100Canvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeftDown(T100Canvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeftUp(T100Canvas*, wxMouseEvent& event);
        T100VOID            OnMouseLeftDClick(T100Canvas*, wxMouseEvent& event);
        T100VOID            OnMouseMove(T100Canvas*, wxMouseEvent& event);

        T100VOID            OnKeyUp(T100Canvas*, wxKeyEvent& event);

        T100VOID            OnResize(T100Canvas*, wxSizeEvent& event);

        T100VOID            OnScrollBottom(T100Canvas*, wxScrollWinEvent& event);
        T100VOID            OnScrollLineDown(T100Canvas*, wxScrollWinEvent& event);
        T100VOID            OnScrollPageDown(T100Canvas*, wxScrollWinEvent& event);
        T100VOID            OnScrollThumbTrack(T100Canvas*, wxScrollWinEvent& event);

    protected:

    private:
};

#endif // T100CANVASSTATESELECTED_H
