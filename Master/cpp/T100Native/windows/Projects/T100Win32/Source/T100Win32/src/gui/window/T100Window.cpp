#include "T100Window.h"

#include "gui/T100Win32Application.h"

namespace T100WINDOWS{

T100Window::T100Window() :
    T100WindowBase(),
    m_module()
{
    //ctor
}

T100Window::T100Window(T100Window* parent) :
    T100WindowBase()
{
    //ctor
    init(parent);
}

T100Window::~T100Window()
{
    //dtor
    uninit();
}

T100VOID T100Window::init(T100Window* parent)
{
    HWND                        hwnd;
    HINSTANCE                   instance;
    T100Win32Application*       application         = T100NULL;

    application = GetApplication();

    if(parent){
        hwnd    = parent->GetHWND();
        m_root  = parent->GetRoot();
        parent->AppendChild(this);
    }else{
        hwnd    = HWND_DESKTOP;
    }

    instance    = application->GetInstance();

    if(application->IsRegistered(m_style.ClassType)){
        m_hwnd  = m_module.CreateWindowHandler(application, instance, hwnd, &m_style, this, application);
    }else{
        if(application->RegisterWindowClass(m_style.ClassType)){
            if(m_module.RegisterWindowClass(instance, m_style)){
                m_hwnd  = m_module.CreateWindowHandler(application, instance, hwnd, &m_style, this, application);
            }
        }
    }

}

T100VOID T100Window::uninit()
{

}

T100VOID T100Window::Create(T100Window* parent, T100WindowStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        m_style     = T100WindowStyle();
    }
    init(parent);
}

T100VOID T100Window::Destroy()
{

}

T100Window* T100Window::ConvertToWindow(T100Tree* node)
{
    return dynamic_cast<T100Window*>(node);
}

}
