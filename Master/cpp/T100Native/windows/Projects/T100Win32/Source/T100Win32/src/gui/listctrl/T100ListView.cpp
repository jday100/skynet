#include "T100ListView.h"

#include <commctrl.h>

namespace T100WINDOWS{

T100ListView::T100ListView() :
    T100Control()
{
    //ctor
}

T100ListView::T100ListView(T100Window* parent) :
    T100Control()
{
    //ctor
    m_style     = T100ListViewStyle();
    init(parent);
}

T100ListView::~T100ListView()
{
    //dtor
    uninit();
}

T100VOID T100ListView::init(T100Window* parent)
{
    T100Control::Create(parent, &m_style);
}

T100VOID T100ListView::uninit()
{

}

T100VOID T100ListView::Create(T100Window* parent, T100ListViewStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        m_style     = T100ListViewStyle();
    }
    init(parent);
}

T100VOID T100ListView::Destroy()
{

}

T100VOID T100ListView::Append(const T100WSTRING& label)
{
    LVITEM          item;

    ZeroMemory(&item, sizeof(LVITEM));

    item.mask       = LVIF_TEXT;
    item.pszText    = const_cast<T100WCHAR*>(label.c_str());
    item.cchTextMax = label.size();

    ListView_InsertItem(m_hwnd, &item);
}

T100VOID T100ListView::Remove()
{

}

}
