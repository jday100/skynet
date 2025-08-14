#include "T100TreeItemData.h"

T100TreeItemData::T100TreeItemData() :
    wxTreeItemData()
{
    //ctor
    init();
}

T100TreeItemData::~T100TreeItemData()
{
    //dtor
    uninit();
}

T100VOID T100TreeItemData::init()
{
    m_opened    = T100FALSE;
}

T100VOID T100TreeItemData::uninit()
{

}

T100VOID T100TreeItemData::SetOpened(T100BOOL value)
{
    m_opened        = value;
}
