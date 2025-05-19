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

T100VOID T100HelloFrame::Create(T100Win32Application* app, T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(app, label);
    T100Frame::SetSize(width, height);
}
