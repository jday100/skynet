#include "T100VPCFrame.h"

#include "gui/T100DC.h"

T100VPCFrame::T100VPCFrame() :
    T100Frame()
{
    //ctor
}

T100VPCFrame::~T100VPCFrame()
{
    //dtor
}

T100VOID T100VPCFrame::Create(T100Win32Application* application)
{
    T100Frame::Create(application);
    init();
}

T100VOID T100VPCFrame::Destroy()
{
    uninit();
    T100Frame::Destroy();
}

T100VOID T100VPCFrame::init()
{
    Connect(T100EVENT_WINDOW_PAINT, (T100EVENT_FUNCTION)&OnPaint);
}

T100VOID T100VPCFrame::uninit()
{

}

T100VOID T100VPCFrame::OnPaint(T100PaintEvent& event)
{
    T100DC      dc(this);

    dc.DrawText(Value, 0, 0);
}
