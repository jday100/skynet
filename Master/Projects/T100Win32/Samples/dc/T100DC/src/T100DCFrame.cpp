#include "T100DCFrame.h"

#include "gui/dc/T100DC.h"

T100DCFrame::T100DCFrame() :
    T100Frame()
{
    //ctor
}

T100DCFrame::~T100DCFrame()
{
    //dtor
}

T100VOID T100DCFrame::Create(T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(label, width, height);

    init();
}

T100VOID T100DCFrame::init()
{
    Connect(T100EVENT_WINDOW_PAINT, (T100EVENT_CALL)&OnFramePaint);
}

T100VOID T100DCFrame::uninit()
{

}

T100VOID T100DCFrame::OnFramePaint(T100WindowEvent& event)
{
    T100DC      dc(this);

    dc.DrawLine(T100Point(), T100Point());
}
