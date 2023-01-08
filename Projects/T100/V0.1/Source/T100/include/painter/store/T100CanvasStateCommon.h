#ifndef T100CANVASSTATECOMMON_H
#define T100CANVASSTATECOMMON_H

#include "T100CanvasState.h"

namespace T100Painter{

class T100CanvasStateCommon : public T100CanvasState
{
    public:
        T100CanvasStateCommon();
        virtual ~T100CanvasStateCommon();

        T100VOID            OnPaint(wxPaintEvent& event, T100PainterCanvas* canvas);

        T100VOID            OnMouseLeftDown(wxMouseEvent& event);
        T100VOID            OnMouseLeftUp(wxMouseEvent& event);
        T100VOID            OnMouseMove(wxMouseEvent& event);
        T100VOID            OnMouseLeftDClick(wxMouseEvent& event);

    protected:

    private:
};

}

#endif // T100CANVASSTATECOMMON_H
