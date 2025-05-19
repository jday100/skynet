#include "T100SelfLoopWindow.h"

#include <commctrl.h>
#include "T100Win32Application.h"

T100SelfLoopWindow::T100SelfLoopWindow() :
    T100Window()
{
    //ctor
}

T100SelfLoopWindow::T100SelfLoopWindow(T100Win32Application* app, T100Window* parent) :
    T100Window(app, parent)
{
    //ctor
}

T100SelfLoopWindow::~T100SelfLoopWindow()
{
    //dtor
}

T100VOID T100SelfLoopWindow::Create()
{
    if(!GetApplicationPtr()){
        return;
    }

    HWND        hwnd;

    if(m_parentPtr){
        T100Window* win     = GetParentPtr();

        if(win){
            hwnd    = win->GetHWND();
            if(!hwnd){
                hwnd    = HWND_DESKTOP;
            }
        }else{
            hwnd    = HWND_DESKTOP;
        }

        m_parentPtr->AddChild(T100WINDOW_TYPE_T100SELFLOOP_WINDOW, this);
    }else{
        hwnd    = HWND_DESKTOP;
    }

    if(GetApplicationPtr()->RegisterWindowClass(T100WINDOW_TYPE_T100SELFLOOP_WINDOW)){
        if(RegisterSelfLoopWindowClass(GetApplicationPtr(), T100WINDOW_TYPE_T100SELFLOOP_WINDOW)){
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
}

T100VOID T100SelfLoopWindow::Create(T100Win32Application* appPtr, T100SelfLoopWindow* parentPtr)
{
    HWND    hwnd;

    if(!appPtr){
        return;
    }

    m_rootPtr   = appPtr;
    m_parentPtr = parentPtr;

    if(parentPtr){
        hwnd    = parentPtr->GetHWND();
    }else{
        hwnd    = HWND_DESKTOP;
    }

    if(appPtr->RegisterWindowClass(T100WINDOW_TYPE_T100SELFLOOP_WINDOW)){
        if(RegisterSelfLoopWindowClass(appPtr, T100WINDOW_TYPE_T100SELFLOOP_WINDOW)){
            m_hwnd  = CreateWindowInstance(hwnd, &m_style, this);

            if(m_hwnd){
                appPtr->GetWindowMessageDispatcher().RegisterWindowHandler(m_hwnd, this);
            }
        }
    }else{
        m_hwnd  = CreateWindowInstance(hwnd, &m_style, this);

        if(m_hwnd){
            appPtr->GetWindowMessageDispatcher().RegisterWindowHandler(m_hwnd, this);
        }
    }
}

T100BOOL T100SelfLoopWindow::RegisterSelfLoopWindowClass(T100Win32Application* appPtr, T100WSTRING type)
{
    HWND        hwnd;
    WNDCLASSEX  wincl;

    wincl.hInstance         = appPtr->GetThisInstance();
    wincl.lpszClassName     = type.c_str();
    wincl.lpfnWndProc       = DefaultSelfLoopWindowProcedure;
    wincl.style             = CS_DBLCLKS;
    wincl.cbSize            = sizeof (WNDCLASSEX);

    wincl.hIcon             = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm           = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor           = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName      = NULL;
    wincl.cbClsExtra        = 0;
    wincl.cbWndExtra        = 0;

    wincl.hbrBackground     = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl)){
        return T100FALSE;
    }
    return T100TRUE;
}

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100WindowMessageData               data                = {hwnd, message, wParam, lParam};
    T100WindowMessageDispatcher*        dispatcherPtr       = T100NULL;
    T100EventHandler*                   handlerPtr          = reinterpret_cast<T100EventHandler*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if(handlerPtr){
        dispatcherPtr   = &handlerPtr->GetApplicationPtr()->GetWindowMessageDispatcher();
    }

    switch (message)
    {
        case LVM_GETHOTITEM:
            {

            }
            break;
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
