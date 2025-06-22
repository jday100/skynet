#include "T100CanvasFrame.h"

#include "gui/T100DC.h"

T100CanvasFrame::T100CanvasFrame() :
    T100Frame(),
    m_canvas()
{
    //ctor
}

T100CanvasFrame::~T100CanvasFrame()
{
    //dtor
}

T100VOID T100CanvasFrame::Create(T100Win32Application* application)
{
    T100Frame::Create(application);
    m_canvas.Create(this);

    init();
}

T100VOID T100CanvasFrame::init()
{
    m_canvas.Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnResize, this);
    m_canvas.Connect(T100EVENT_WINDOW_PAINT, (T100EVENT_FUNCTION)&OnPaint, this);

    m_canvas.SetSize(T100Size(800, 600));
    m_canvas.Show();
}

T100VOID T100CanvasFrame::uninit()
{

}

T100VOID T100CanvasFrame::OnResize(T100WindowEvent& event)
{

}

T100VOID T100CanvasFrame::OnPaint(T100PaintEvent& event)
{
    T100DC      dc(&m_canvas);
    T100Pen     pen(T100COLOUR4_RED, 50, T100LINE_SOLID);

    dc.SetPen(pen);
    dc.DrawCircle(T100Point(100, 100), 50);
}
