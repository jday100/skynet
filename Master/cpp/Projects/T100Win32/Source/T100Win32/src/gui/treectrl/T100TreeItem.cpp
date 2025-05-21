#include "T100TreeItem.h"

T100TreeItem::T100TreeItem(T100WSTRING label)
{
    //ctor
    m_treeItem.mask         = TVIF_TEXT;
    m_treeItem.state        = 0;
    m_treeItem.stateMask    = 0;
    m_treeItem.cChildren    = 0;
    m_treeItem.hItem        = TVI_ROOT;
    m_treeItem.lParam       = 0;
    m_treeItem.cchTextMax   = MAX_PATH;
    m_treeItem.pszText      = const_cast<wchar_t*>(label.c_str());
}

T100TreeItem::~T100TreeItem()
{
    //dtor
}
