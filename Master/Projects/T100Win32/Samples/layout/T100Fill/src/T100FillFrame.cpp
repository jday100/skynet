#include "T100FillFrame.h"

#include "gui/ctrls/T100Button.h"
#include "gui/layout/T100FillLayout.h"

T100FillFrame::T100FillFrame() :
    T100Frame()
{
    //ctor
}

T100FillFrame::~T100FillFrame()
{
    //dtor
}

T100VOID T100FillFrame::Create(T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(label, width, height);

    init();
}

T100VOID T100FillFrame::init()
{
    T100Button*     button1     = T100NEW T100Button(this, L"Button1");
    T100Button*     button2     = T100NEW T100Button(this, L"Button2");
    T100Button*     button3     = T100NEW T100Button(this, L"Button3");

    T100Button*         button      = T100NEW T100Button();

    button->SetLabel(L"OK");
    button->Create(this);

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    //layout->SetOrientationType(T100HORIZONTAL);

    this->SetLayoutPtr(layout);

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_CALL)&OnResize);
}

T100VOID T100FillFrame::uninit()
{

}
