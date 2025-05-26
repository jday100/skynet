#include "T100DCFrame.h"

#include "gui/T100DC.h"

T100DCFrame::T100DCFrame() :
    T100Frame()
{
    //ctor
}

T100DCFrame::~T100DCFrame()
{
    //dtor
}

T100VOID T100DCFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    init();
}

T100VOID T100DCFrame::init()
{
    Connect(T100EVENT_WINDOW_PAINT, (T100EVENT_FUNCTION)&OnFramePaint);
}

T100VOID T100DCFrame::uninit()
{

}

T100VOID T100DCFrame::OnFramePaint(T100WindowEvent& event)
{
    T100DC      dc(this);

    T100Pen     pen(T100COLOUR_TYPE_RED, 50, T100LINE_SOLID);

    dc.SetPen(&pen);

    dc.DrawLine(T100Point(100, 100), T100Point(300, 300));

    dc.DrawCircle(T100Point(300, 300), 100);

    dc.DrawRoundedRectangle(T100Point(500, 100), T100Size(200, 200), 50);
}
