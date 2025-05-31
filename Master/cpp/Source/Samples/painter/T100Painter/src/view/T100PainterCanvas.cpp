#include "T100PainterCanvas.h"

#include "gui/T100DC.h"
#include "T100PainterInvoking.h"

T100PainterCanvas::T100PainterCanvas() :
    T100Canvas()
{
    //ctor
}

T100PainterCanvas::T100PainterCanvas(T100Win32Application* app, T100Window* parent) :
    T100Canvas(app, parent)
{
    //ctor
}

T100PainterCanvas::~T100PainterCanvas()
{
    //dtor
}

T100VOID T100PainterCanvas::Create(T100Win32Application* app, T100Window* parent, T100WSTRING label, T100WindowStyle* style)
{
    //T100Canvas::Create(app, parent, label, style);
    T100Canvas::Create(parent);

    Connect(T100EVENT_WINDOW_PAINT, (T100EVENT_FUNCTION)&OnCanvasPaint);
    Connect(T100EVENT_MOUSE_LEFT_DOWN, (T100EVENT_FUNCTION)&OnMouseLeftDown);
    Connect(T100EVENT_MOUSE_LEFT_UP, (T100EVENT_FUNCTION)&OnMouseLeftUp);
}

T100VOID T100PainterCanvas::OnCanvasPaint(T100WindowEvent& event)
{
    T100DC      dc(this);

    dc.DrawLine(T100Point(100, 100), T100Point(300, 300));
}

T100VOID T100PainterCanvas::OnMouseLeftDown(T100MouseEvent& event)
{
    T100PainterInvoking::LeftDown();
}

T100VOID T100PainterCanvas::OnMouseLeftUp(T100MouseEvent& event)
{
    T100PainterInvoking::LeftUp();
}
