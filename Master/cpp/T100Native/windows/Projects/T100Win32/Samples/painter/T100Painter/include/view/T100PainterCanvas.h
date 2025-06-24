#ifndef T100PAINTERCANVAS_H
#define T100PAINTERCANVAS_H

#include "gui/T100Canvas.h"
#include "gui/event/T100WindowEvent.h"
#include "gui/event/T100MouseEvent.h"

using namespace T100LIBRARY;
using namespace T100WINDOWS;

class T100PainterCanvas : public T100Canvas
{
    public:
        T100PainterCanvas();
        T100PainterCanvas(T100Window*);
        virtual ~T100PainterCanvas();

        T100VOID            Create(T100Window*, T100WSTRING, T100CanvasStyle* = T100NULL);

    protected:

    private:
        T100VOID            OnCanvasPaint(T100WindowEvent&);
        T100VOID            OnMouseLeftDown(T100MouseEvent&);
        T100VOID            OnMouseLeftUp(T100MouseEvent&);
};

#endif // T100PAINTERCANVAS_H
