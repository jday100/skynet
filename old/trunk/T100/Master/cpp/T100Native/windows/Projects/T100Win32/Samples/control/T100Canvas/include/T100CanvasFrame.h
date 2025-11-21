#ifndef T100CANVASFRAME_H
#define T100CANVASFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100Canvas.h"

using namespace T100WINDOWS;

class T100CanvasFrame : public T100Frame
{
    public:
        T100CanvasFrame();
        virtual ~T100CanvasFrame();

        T100VOID            Create(T100Win32Application*);

    protected:
        T100VOID            OnResize(T100WindowEvent&);
        T100VOID            OnPaint(T100PaintEvent&);

    private:
        T100Canvas          m_canvas;

        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CANVASFRAME_H
