#include "T100TreeItemData.h"

T100TreeItemData::T100TreeItemData() :
    wxTreeItemData()
{
    //ctor
    m_opened        = T100FALSE;
}

T100TreeItemData::~T100TreeItemData()
{
    //dtor
}

T100VOID T100TreeItemData::SetOpened(T100BOOL value)
{
    m_opened        = value;
}

T100BOOL T100TreeItemData::IsOpened()
{
    return m_opened;
}
