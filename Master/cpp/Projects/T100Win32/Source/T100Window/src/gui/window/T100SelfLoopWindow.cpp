#include "gui/window/T100SelfLoopWindow.h"

#include "gui/event/T100ApplicationEventHandler.h"
#include "gui/event/T100WindowMessageDispatcher.h"
#include "gui/T100Win32Application.h"

T100SelfLoopWindow::T100SelfLoopWindow() :
    T100Window()
{
    //ctor
}

T100SelfLoopWindow::T100SelfLoopWindow(T100ApplicationEventHandler* app, T100Window* parent, T100WindowStyle* style) :
    T100Window(app, parent, style)
{
    //ctor
}

T100SelfLoopWindow::~T100SelfLoopWindow()
{
    //dtor
}

T100VOID T100SelfLoopWindow::Create(T100ApplicationEventHandler* app, T100Window* parent, T100WindowStyle* style)
{
    T100Window::Create(app, parent, style);
}

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100WindowMessageData               data                = {hwnd, message, wParam, lParam};
    T100WindowMessageDispatcher*        dispatcherPtr       = T100NULL;
    T100ApplicationEventHandler*        handlerPtr          = reinterpret_cast<T100ApplicationEventHandler*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if(handlerPtr){
        T100Win32Application*       application         = T100NULL;

        application = dynamic_cast<T100Win32Application*>(handlerPtr->GetRootPtr());

        if(application){
            dispatcherPtr   = &(application->GetWindowMessageDispatcher());
        }
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
            if(dispatcherPtr){
                dispatcherPtr->DispatchWindowMessage(data);
            }
            PostQuitMessage(0);
        }
        break;
    case WM_COMMAND:
        {
            if(LOWORD(lParam) == 0){
                if(dispatcherPtr){
                    dispatcherPtr->DispatchWindowMessage(data);
                }
            }else{
                if(dispatcherPtr){
                    T100EventHandler*   handler = dispatcherPtr->GetControlHandler(LOWORD(wParam));
                    if(handler){
                        handler->ProcessWindowMessage(data);
                    }
                }
            }
        }
        break;
    case WM_NOTIFY:
        {
            if(dispatcherPtr){
                T100EventHandler*   handler     = dispatcherPtr->GetControlHandler(LOWORD(wParam));
                if(handler){
                    handler->ProcessNotifyMessage(data);
                }
            }
        }
        break;
    default:
        {
            if(dispatcherPtr){
                dispatcherPtr->DispatchWindowMessage(data);
            }
        }
        break;
    }

    return DefWindowProc (hwnd, message, wParam, lParam);
}
