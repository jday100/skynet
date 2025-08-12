#include "T100FolderData.h"

T100FolderData::T100FolderData() :
    T100TreeItemData()
{
    //ctor
}

T100FolderData::T100FolderData(T100FolderInfo* info) :
    T100TreeItemData()
{
    //ctor
}

T100FolderData::~T100FolderData()
{
    //dtor
}

T100VOID T100FolderData::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100FolderData::GetLabel()
{
    return m_label;
}

wxMenu* T100FolderData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();

    return menu;
}
