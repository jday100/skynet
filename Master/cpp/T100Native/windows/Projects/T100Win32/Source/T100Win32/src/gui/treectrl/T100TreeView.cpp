#include "T100TreeView.h"

#include <commctrl.h>

namespace T100WINDOWS{

T100TreeView::T100TreeView() :
    T100Control()
{
    //ctor
}

T100TreeView::T100TreeView(T100Window* parent) :
    T100Control()
{
    //ctor
}

T100TreeView::~T100TreeView()
{
    //dtor
}

T100VOID T100TreeView::init(T100Window* parent)
{
    T100Control::Create(parent, &m_style);
}

T100VOID T100TreeView::uninit()
{

}

T100VOID T100TreeView::Create(T100Window* parent, T100TreeCtrlStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        m_style     = T100TreeCtrlStyle();
    }
    init(parent);
}

T100VOID T100TreeView::Destroy()
{

}

T100VOID T100TreeView::Append(const T100WSTRING& label)
{
    TVITEM              item;
    TVINSERTSTRUCT      tvis;

    item.mask       = TVIF_TEXT;
    item.pszText    = const_cast<T100WCHAR*>(label.c_str());
    item.cchTextMax = label.size();

    tvis.item       = item;
    tvis.hParent    = TVI_ROOT;

    TreeView_InsertItem(m_hwnd, &tvis);
}

}
