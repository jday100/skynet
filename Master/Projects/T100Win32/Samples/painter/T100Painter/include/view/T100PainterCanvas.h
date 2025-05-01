#ifndef T100PAINTERCANVAS_H
#define T100PAINTERCANVAS_H

#include "gui/canvas/T100Canvas.h"

class T100PainterCanvas : public T100Canvas
{
    public:
        T100PainterCanvas();
        virtual ~T100PainterCanvas();

        T100VOID            Create(T100Window*, T100WSTRING, T100UINT, T100UINT);

    protected:

    private:
        T100VOID            OnCanvasPaint(T100WindowEvent&);
};

#endif // T100PAINTERCANVAS_H
