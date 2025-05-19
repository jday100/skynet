#include "T100Frame.h"

#include "gui/layout/T100Layout.h"
#include "gui/T100AllStyles.h"

T100Frame::T100Frame() :
    T100FrameBase()
{
    //ctor
}

T100Frame::T100Frame(T100Win32Application* app, T100Window* parent) :
    T100FrameBase(app, parent)
{
    //ctor
}

T100Frame::~T100Frame()
{
    //dtor
}

T100VOID T100Frame::Create(T100Win32Application* app, T100WSTRING label, T100FrameStyle* style)
{
    T100EventHandler::Create((T100EventHandler*)app);
    Create(label, style);
}

T100VOID T100Frame::Create(T100WSTRING label, T100FrameStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        T100FrameStyle      style;
        m_style     = style;
    }

    m_style.WindowLabel = label;

    T100SelfLoopWindow::Create();

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnFrameResize);
}

T100VOID T100Frame::OnFrameResize(T100WindowEvent& event)
{
    T100Size    size    = GetSize();

    if(size.width < 800){
        size.width  = 800;
        SetSize(size);
    }


    if(m_layoutPtr){
        m_layoutPtr->Update();
    }

    OnWindowResize(event);
}
