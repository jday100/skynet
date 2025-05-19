#include "T100TreeCtrl.h"

#include <commctrl.h>
#include "T100Win32Application.h"
#include "gui/treectrl/T100TreeItem.h"

T100TreeCtrl::T100TreeCtrl() :
    T100Window()
{
    //ctor
}

T100TreeCtrl::T100TreeCtrl(T100Win32Application* app, T100Window* parent) :
    T100Window(app, parent)
{
    //ctor
}

T100TreeCtrl::~T100TreeCtrl()
{
    //dtor
}

T100VOID T100TreeCtrl::Create(T100Win32Application* app, T100Window* parent)
{
    if((!app) || (!parent)){
        return;
    }

    HWND        hwnd;

    m_style.Width       = 800;
    m_style.Height      = 600;

    if(parent){
        hwnd    = parent->GetHWND();
        parent->AddChild(T100WINDOW_TYPE_T100LISTVIEW, this);
    }else{
        return;
    }

    m_hwnd = CreateWindow(WC_TREEVIEW, L"", WS_CHILD | WS_VISIBLE, 0, 0, 800, 600, hwnd, T100NULL, app->GetThisInstance(), this);

    //SetWindowLongPtr(m_hwnd, GWLP_WNDPROC, (LONG_PTR)DefaultTreeCtrlWindowProcedure);

    //SetWindowSubclass(m_hwnd, DefaultTreeCtrlWindowProcedure, 0, 0);
}

T100VOID T100TreeCtrl::Append(T100WSTRING label)
{
    TVINSERTSTRUCT      tvis;

    tvis.hInsertAfter   = 0;
    tvis.hParent        = TVI_ROOT;
    tvis.item.mask      = TVIF_TEXT;
    tvis.item.pszText   = const_cast<wchar_t*>(label.c_str());

    TreeView_InsertItem(m_hwnd, &tvis);
}

LRESULT CALLBACK DefaultTreeCtrlWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //return DefSubclassProc (hwnd, message, wParam, lParam);


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

    return DefWindowProc (hwnd, message, wParam, lParam);
}
