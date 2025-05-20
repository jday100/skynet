#include "gui/T100Frame.h"

#include "gui/T100Win32Application.h"
#include "gui/T100FrameStyle.h"

T100Frame::T100Frame() :
    T100FrameBase()
{
    //ctor
}

T100Frame::T100Frame(T100Win32Application* app, T100FrameStyle* style) :
    T100FrameBase(app, style)
{
    //ctor
}

T100Frame::~T100Frame()
{
    //dtor
}

T100VOID T100Frame::Create(T100Win32Application* app, T100FrameStyle* style)
{
    T100FrameBase::Create(app, style);
}

T100VOID T100Frame::Destroy()
{

}
