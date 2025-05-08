#include "gui/listctrl/T100ListCtrl.h"

#include <commctrl.h>
#include "T100Win32Application.h"
#include "gui/listctrl/T100ListItem.h"

T100ListCtrl::T100ListCtrl() :
    T100Window()
{
    //ctor
}

T100ListCtrl::~T100ListCtrl()
{
    //dtor
}

T100VOID T100ListCtrl::Create(T100Window* parent)
{
    HWND        hwnd;
    m_width     = 800;
    m_height    = 600;

    if(parent){
        hwnd    = parent->GetHWND();
        parent->AddChildPtr(this);
    }else{
        return;
    }

    m_hwnd = CreateWindow(WC_LISTVIEW, L"", WS_CHILD | WS_VISIBLE, 0, 0, 800, 600, hwnd, T100NULL, T100Win32Application::m_thisInstance, this);

    m_parentPtr = parent;
}

T100VOID T100ListCtrl::Append(T100WSTRING label)
{
    T100ListItem*   item    = T100NEW T100ListItem(label);

    //ListView_GetItem(m_hwnd, &item->m_listItem);

    int i = ListView_InsertItem(m_hwnd, &item->m_listItem);
}
