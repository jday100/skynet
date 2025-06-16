#include "T100SelfLoopWindow.h"

#include "gui/T100Win32Application.h"

namespace T100WINDOWS{

T100SelfLoopWindow::T100SelfLoopWindow() :
    T100Window()
{
    //ctor
}

T100SelfLoopWindow::~T100SelfLoopWindow()
{
    //dtor
}

T100VOID T100SelfLoopWindow::Create(T100Win32Application* application, T100WindowStyle* style)
{
    SetRoot(application);
    T100Window::Create(T100NULL, style);
}

T100VOID T100SelfLoopWindow::Destroy()
{

}

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    T100WindowMessageData               data            = {hwnd, message, wParam, lParam};
    T100WindowMessageDispatcher*        dispatcher      = T100NULL;
    T100Win32Application*               application     = reinterpret_cast<T100Win32Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if(application){
        dispatcher  = &application->GetWindowMessageDispatcher();
    }

    switch(message){
    case WM_CREATE:
        {
            LPCREATESTRUCT  pCreateStruct   = reinterpret_cast<LPCREATESTRUCT>(lParam);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));

            T100EventHandler*   handler     = reinterpret_cast<T100EventHandler*>(pCreateStruct->lpCreateParams);
            if(handler){
                handler->ProcessWindowMessage(data);
            }
        }
        break;
    case WM_DESTROY:
        {
            if(dispatcher){
                dispatcher->DispatchWindowMessage(data);
            }
            PostQuitMessage(0);
        }
        break;
    case WM_COMMAND:
        {
            if(LOWORD(lParam) == 0){
                if(dispatcher){
                    dispatcher->DispatchWindowMessage(data);
                }
            }else{
                if(dispatcher){
                    T100EventHandler*   handler = dispatcher->GetControlHandler(LOWORD(wParam));
                    if(handler){
                        handler->ProcessWindowMessage(data);
                    }
                }
            }
        }
        break;
    case WM_NOTIFY:
        {
            if(dispatcher){
                T100EventHandler*   handler     = dispatcher->GetControlHandler(LOWORD(wParam));
                if(handler){
                    handler->ProcessNotifyMessage(data);
                }
            }
        }
        break;
    case WM_SETTEXT:
        {
            if(dispatcher){
                dispatcher->DispatchWindowMessage(data);
            }
        }
        break;
    default:
        {
            if(dispatcher){
                dispatcher->DispatchWindowMessage(data);
            }
        }
        break;
    }

    return DefWindowProc (hwnd, message, wParam, lParam);
}

}
