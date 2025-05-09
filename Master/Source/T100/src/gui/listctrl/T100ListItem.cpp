#include "gui/listctrl/T100ListItem.h"

T100ListItem::T100ListItem(T100WSTRING label) :
    T100Class()
{
    //ctor
    m_listItem.mask         = LVIF_TEXT;
    m_listItem.state        = 0;
    m_listItem.stateMask    = 0;
    m_listItem.iSubItem     = 0;
    m_listItem.iItem        = 0;
    //m_listItem.pszText      = const_cast<wchar_t*>(label.c_str());

    //m_listItem.pszText      = LPSTR_TEXTCALLBACK;
    m_listItem.pszText      = L"item";
}

T100ListItem::~T100ListItem()
{
    //dtor
}
