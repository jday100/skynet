#include "T100Window.h"

#include "gui/T100AllStyles.h"
#include "gui/layout/T100Layout.h"
#include "gui/T100Win32Application.h"

T100Window::T100Window() :
    T100WindowBase()
{
    //ctor
}

T100Window::T100Window(T100Win32Application* app, T100Window* parent) :
    T100WindowBase(parent)
{
    //ctor
    m_rootPtr           = app;
    m_parentPtr         = parent;
}

T100Window::~T100Window()
{
    //dtor
}

T100VOID T100Window::Create(T100WindowStyle* style)
{
    if(!GetParentPtr()){
        return;
    }

    if(style){
        m_style     = *style;
    }else{
        T100WindowStyle     value;
        m_style     = value;
    }

    HWND        hwnd;

    if(GetParentPtr()){
        hwnd    = GetParentPtr()->GetHWND();
        GetParentPtr()->AddChild(T100WINDOW_TYPE_T100WINDOW, this);
    }else{
        hwnd    = HWND_DESKTOP;
    }

    if(GetApplicationPtr()->RegisterWindowClass(T100WINDOW_TYPE_T100WINDOW)){
        if(RegisterWindowClass(&m_style, DefWindowProc)){
            m_hwnd  = CreateWindowInstance(hwnd, &m_style, this);

            if(m_hwnd){
                GetApplicationPtr()->GetWindowMessageDispatcher().RegisterWindowHandler(m_hwnd, this);
            }
        }
    }else{
        m_hwnd  = CreateWindowInstance(hwnd, &m_style, this);

        if(m_hwnd){
            GetApplicationPtr()->GetWindowMessageDispatcher().RegisterWindowHandler(m_hwnd, this);
        }
    }

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnWindowResize);
}

T100VOID T100Window::Create(T100Win32Application* app, T100Window* parent, T100WindowStyle* style)
{
    if((!app) || (!parent)){
        return;
    }

    T100ObjectTree::Create(parent);

    Create(style);
}

T100Window* T100Window::GetParentPtr()
{
    return dynamic_cast<T100Window*>(T100ObjectTree::GetParentPtr());
}

T100VOID T100Window::SetLayout(T100Layout* layout)
{
    m_layoutPtr = layout;

    m_layoutPtr->SetParent(this);
    m_layoutPtr->SetChildren(m_children.getVector());
}

T100Layout* T100Window::GetLayoutPtr()
{
    return m_layoutPtr;
}

T100Window* T100Window::ConvertToWindow(T100ObjectTree* node)
{
    return dynamic_cast<T100Window*>(node);
}

T100VOID T100Window::OnWindowResize(T100WindowEvent& event)
{

}

LRESULT CALLBACK DefaultWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100WindowMessageData               data                = {hwnd, message, wParam, lParam};
    T100WindowMessageDispatcher*        dispatcherPtr       = T100NULL;
    T100EventHandler*                   handlerPtr          = reinterpret_cast<T100EventHandler*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if(handlerPtr){
        dispatcherPtr   = &handlerPtr->GetApplicationPtr()->GetWindowMessageDispatcher();
    }

    switch (message)
    {
        case WM_SIZE:
        case WM_PAINT:
        case WM_COMMAND:
            {
                if(dispatcherPtr){
                    dispatcherPtr->DispatchWindowMessage(data);
                }
            }
            break;
        case WM_CREATE:
            {
                LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
                SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));

                T100EventHandler* handlerPtr = reinterpret_cast<T100EventHandler*>(pCreateStruct->lpCreateParams);
                if(handlerPtr){
                    handlerPtr->ProcessWindowMessage(data);
                }
            }
            break;
        case WM_DESTROY:
            {
                if(dispatcherPtr){
                    dispatcherPtr->DispatchWindowMessage(data);
                }
                PostQuitMessage (0);
            }
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
