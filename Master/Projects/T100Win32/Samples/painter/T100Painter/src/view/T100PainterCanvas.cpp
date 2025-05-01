#include "T100PainterCanvas.h"

#include "gui/dc/T100DC.h"

T100PainterCanvas::T100PainterCanvas() :
    T100Canvas()
{
    //ctor
}

T100PainterCanvas::~T100PainterCanvas()
{
    //dtor
}

T100VOID T100PainterCanvas::Create(T100Window* parent, T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Canvas::Create(parent, label, width, height);

    Connect(T100EVENT_WINDOW_PAINT, (T100EVENT_CALL)&OnCanvasPaint);
}

T100VOID T100PainterCanvas::OnCanvasPaint(T100WindowEvent& event)
{
    T100DC      dc(this);

    dc.DrawLine(T100Point(), T100Point());
}
