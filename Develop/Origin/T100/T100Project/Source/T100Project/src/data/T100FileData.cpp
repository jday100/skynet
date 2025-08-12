#include "T100FileData.h"

T100FileData::T100FileData() :
    T100TreeItemData()
{
    //ctor
}

T100FileData::T100FileData(T100FileInfo* info) :
    T100TreeItemData()
{
    //ctor
}

T100FileData::~T100FileData()
{
    //dtor
}

T100VOID T100FileData::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100FileData::GetLabel()
{
    return m_label;
}

wxMenu* T100FileData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();

    return menu;
}
