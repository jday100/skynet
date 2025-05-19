#ifndef T100PAINTERCANVAS_H
#define T100PAINTERCANVAS_H

#include "gui/T100Canvas.h"
#include "gui/T100WindowEvent.h"

class T100Win32Application;

class T100PainterCanvas : public T100Canvas
{
    public:
        T100PainterCanvas();
        T100PainterCanvas(T100Win32Application*, T100Window*);
        virtual ~T100PainterCanvas();

        T100VOID            Create(T100Win32Application*, T100Window*, T100WSTRING, T100WindowStyle*);

    protected:

    private:
        T100VOID            OnCanvasPaint(T100WindowEvent&);
};

#endif // T100PAINTERCANVAS_H
