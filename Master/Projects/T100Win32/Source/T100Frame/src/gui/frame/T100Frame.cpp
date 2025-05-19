#include "T100Frame.h"

#include "gui/T100Win32Application.h"
#include "gui/T100FrameStyle.h"

T100Frame::T100Frame() :
    T100FrameBase()
{
    //ctor
}

T100Frame::T100Frame(T100Win32Application* app, T100WSTRING label) :
    T100FrameBase(app, label)
{
    //ctor
}

T100Frame::~T100Frame()
{
    //dtor
}

T100VOID T100Frame::Create(T100Win32Application* app, T100WSTRING label)
{
    T100FrameBase::Create(app, label);
}

T100VOID T100Frame::Destroy()
{

}
