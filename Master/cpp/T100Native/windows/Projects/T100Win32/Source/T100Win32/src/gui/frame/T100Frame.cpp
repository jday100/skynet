#include "T100Frame.h"

#include "gui/T100FrameStyle.h"

namespace T100WINDOWS{

T100Frame::T100Frame() :
    T100SelfLoopWindow()
{
    //ctor
}

T100Frame::T100Frame(T100Win32Application* application) :
    T100SelfLoopWindow()
{
    //ctor
    m_style     = T100FrameStyle();
    init(application);
}

T100Frame::~T100Frame()
{
    //dtor
    uninit();
}

T100VOID T100Frame::init(T100Win32Application* application)
{
    T100SelfLoopWindow::Create(application, &m_style);
}

T100VOID T100Frame::uninit()
{

}

T100VOID T100Frame::SetMenuBar(T100MenuBar* menuBar)
{
    m_menuBar   = menuBar;
}

T100MenuBar* T100Frame::GetMenuBar()
{
    return m_menuBar;
}

T100VOID T100Frame::Create(T100Win32Application* application, T100FrameStyle* style)
{
    if(style){
        m_style         = *style;
    }else{
        m_style         = T100FrameStyle();
    }
    init(application);
}

T100VOID T100Frame::Destroy()
{

}

}
