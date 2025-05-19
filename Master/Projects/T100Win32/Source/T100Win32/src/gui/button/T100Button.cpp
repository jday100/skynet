#include "T100Button.h"

#include "gui/T100Win32Application.h"

T100Button::T100Button() :
    T100Control()
{
    //ctor
}

T100Button::T100Button(T100Win32Application* app, T100Window* parent) :
    T100Control(app, parent)
{
    //ctor
}

T100Button::~T100Button()
{
    //dtor
}

T100VOID T100Button::Create(T100WSTRING label, T100ButtonStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        T100ButtonStyle     style;
        m_style     = style;
    }

    T100Window::Create(&m_style);
}

T100VOID T100Button::Create(T100Win32Application* app, T100Window* parent, T100WSTRING label, T100ButtonStyle* style)
{
    if((!app) || (!parent)){
        return;
    }

    m_rootPtr   = app;
    m_parentPtr = parent;

    //Create(label, style);


    if(!GetParentPtr()){
        return;
    }

    if(style){
        m_style     = *style;
    }else{
        T100ButtonStyle     value;
        m_style     = value;
    }

    m_style.WindowLabel = label;

    HWND        hwnd;

    if(GetParentPtr()){
        hwnd    = GetParentPtr()->GetHWND();
        GetParentPtr()->AddChild(T100WINDOW_TYPE_T100BUTTON, this);
    }else{
        hwnd    = HWND_DESKTOP;
    }

    T100INT     id      = app->GetIDManager().Next();

    m_style.Menu    = (HMENU)id;

    if(GetApplicationPtr()->RegisterWindowClass(T100WINDOW_TYPE_T100BUTTON)){
        //if(RegisterWindowClass(&m_style, DefWindowProc)){
            m_hwnd  = CreateWindowInstance(hwnd, &m_style, this);

            if(m_hwnd){
                app->GetWindowMessageDispatcher().RegisterControlHandler(id, this);
                GetApplicationPtr()->GetWindowMessageDispatcher().RegisterWindowHandler(m_hwnd, this);
            }
        //}
    }else{
        m_hwnd  = CreateWindowInstance(hwnd, &m_style, this);

        if(m_hwnd){
            app->GetWindowMessageDispatcher().RegisterControlHandler(id, this);
            GetApplicationPtr()->GetWindowMessageDispatcher().RegisterWindowHandler(m_hwnd, this);
        }
    }

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnWindowResize);
}
