#include "T100Panel.h"

#include "gui/layout/T100Layout.h"
#include "T100Win32Application.h"

T100Panel::T100Panel() :
    T100Window()
{
    //ctor
}

T100Panel::T100Panel(T100Win32Application* app, T100Window* parent) :
    T100Window(app, parent)
{
    //ctor
}

T100Panel::~T100Panel()
{
    //dtor
}

T100VOID T100Panel::Create(T100WSTRING label, T100PanelStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        T100PanelStyle      style;
        m_style     = style;
    }
    if(m_style.WindowLabel[0] != L' '){
        m_style.WindowLabel     = L' ' + m_style.WindowLabel;
    }
    T100Window::Create(&m_style);

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnPanelResize);
}

T100VOID T100Panel::Create(T100Win32Application* app, T100Window* parent, T100WSTRING label, T100PanelStyle* style)
{
    m_rootPtr   = app;
    T100ObjectTree::Create(parent);
    Create(label, style);
}

T100VOID T100Panel::OnPanelResize(T100WindowEvent& event)
{
    if(m_layoutPtr){
        m_layoutPtr->Update();
    }

    OnWindowResize(event);
}
