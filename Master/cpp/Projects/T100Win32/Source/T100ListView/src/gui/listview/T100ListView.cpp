#include "gui/T100ListView.h"

#include <commctrl.h>
#include "gui/common/T100WindowCommon.h"
#include "gui/T100Win32Application.h"
#include "gui/T100ListItem.h"
#include "gui/T100ListViewStyle.h"

T100ListView::T100ListView() :
    T100Control()
{
    //ctor
}

T100ListView::T100ListView(T100Win32Application* app, T100Window* parent) :
    T100Control()
{
    //ctor
}

T100ListView::~T100ListView()
{
    //dtor
}

T100VOID T100ListView::Create(T100Win32Application* app, T100Window* parent)
{
    if((!app) || (!parent)){
        return;
    }

    T100ListViewStyle       thisStyle;

    m_style     = thisStyle;

    T100Control::Create(parent, &m_style);

    /*
    HWND        hwnd;

    m_style.Width       = 800;
    m_style.Height      = 600;

    if(parent){
        hwnd    = parent->GetHWND();
        parent->AddChild(T100WINDOW_TYPE_T100LISTVIEW, this);
    }else{
        return;
    }

    m_hwnd = CreateWindow(WC_LISTVIEW, L"", WS_CHILD | WS_VISIBLE, 0, 0, 800, 600, hwnd, T100NULL, app->GetThisInstance(), this);
    */
}

T100VOID T100ListView::Append(T100WSTRING label)
{
    T100ListItem*   item    = T100NEW T100ListItem(label);

    int i = ListView_InsertItem(m_hwnd, &item->m_listItem);
}

T100VOID T100ListView::ProcessWindowMessage(T100WindowMessageData& data)
{
    T100Control::ProcessWindowMessage(data);
}

T100VOID T100ListView::ProcessNotifyMessage(T100WindowMessageData& message)
{
    NMHDR*  pNMHDR      = (NMHDR*)message.WINDOW_LPARAM;

    switch(pNMHDR->code){
    case NM_CLICK:
        {
            NM_LISTVIEW*  nmlv = (NM_LISTVIEW*)pNMHDR;
            T100NotifyEvent     event(message);
            event.SetID(nmlv->iItem);
            CallNotify(NM_CLICK, event);
        }
        break;
    }

    T100Control::ProcessNotifyMessage(message);
}
