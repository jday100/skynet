#include "gui/frame/T100FrameBase.h"

#include "gui/T100Win32Application.h"
#include "gui/T100FrameStyle.h"

T100FrameBase::T100FrameBase() :
    T100SelfLoopWindow()
{
    //ctor
}

T100FrameBase::T100FrameBase(T100Win32Application* app, T100FrameStyle* style) :
    T100SelfLoopWindow(app, T100NULL, style)
{
    //ctor
}

T100FrameBase::~T100FrameBase()
{
    //dtor
}

T100VOID T100FrameBase::Create(T100Win32Application* appPtr, T100FrameStyle* style)
{
    if(!style){
        m_style     = T100FrameStyle();
    }
    T100SelfLoopWindow::Create(appPtr, T100NULL, style);
}

T100VOID T100FrameBase::SetClientSize(T100Size size)
{
    m_clientSize    = size;
}

T100Size T100FrameBase::GetClientSize()
{
    RECT        rect;
    GetClientRect(m_hwnd, &rect);

    m_clientSize.width  = rect.right - rect.left;
    m_clientSize.height = rect.bottom - rect.top;
    return m_clientSize;
}

T100VOID T100FrameBase::SetMenuBar(T100MenuBar* menuBarPtr)
{
    m_menuBarPtr    = menuBarPtr;
    SetMenu(m_hwnd, m_menuBarPtr->m_menuBar);
}

T100MenuBar* T100FrameBase::GetMenuBarPtr()
{
    return m_menuBarPtr;
}

T100VOID T100FrameBase::Maximize()
{
    ShowWindow(m_hwnd, SW_MAXIMIZE);
}

T100VOID T100FrameBase::Minimize()
{
    ShowWindow(m_hwnd, SW_MINIMIZE);
}
