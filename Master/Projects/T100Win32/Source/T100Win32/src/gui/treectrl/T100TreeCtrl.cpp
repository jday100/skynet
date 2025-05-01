#include "T100TreeCtrl.h"

#include <tchar.h>
#include <commctrl.h>
#include "T100Win32Application.h"

T100TreeCtrl::T100TreeCtrl() :
    T100Window()
{
    //ctor
}

T100TreeCtrl::~T100TreeCtrl()
{
    //dtor
}

T100VOID T100TreeCtrl::Append(T100WSTRING label)
{
    TVITEM          item;
    TVINSERTSTRUCT  tvis;

    item.mask       = TVIF_TEXT | TVIF_PARAM;
    item.hItem      = NULL;
    item.pszText    = L"test";

    TreeView_GetItem(m_hwnd, &item);

    tvis.hParent    = NULL;
    tvis.item       = item;

    TreeView_InsertItem(m_hwnd, &tvis);
}
