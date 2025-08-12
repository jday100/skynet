#include "T100FolderData.h"

#include "T100ProjectInvoking.h"

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

T100VOID T100FolderData::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100FolderData::GetPath()
{
    return m_path;
}

wxMenu* T100FolderData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();

    return menu;
}

T100VOID T100FolderData::OnItemExpanding()
{
    T100ProjectInvoking::OnFolderOpen(this);
}
