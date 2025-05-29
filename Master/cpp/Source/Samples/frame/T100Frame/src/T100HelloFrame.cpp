#include "T100HelloFrame.h"

T100HelloFrame::T100HelloFrame() :
    T100Frame()
{
    //ctor
}

T100HelloFrame::~T100HelloFrame()
{
    //dtor
}

T100VOID T100HelloFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    this->SetLabel(L"MyFrame");
}
