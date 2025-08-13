#include "T100ProjectData.h"

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

T100ProjectData::T100ProjectData() :
    T100TreeItemData()
{
    //ctor
}

T100ProjectData::T100ProjectData(T100ProjectInfo* info) :
    T100TreeItemData()
{
    //ctor
    m_label     = info->GetLabel();
}

T100ProjectData::~T100ProjectData()
{
    //dtor
}

T100VOID T100ProjectData::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100ProjectData::GetLabel()
{
    return m_label;
}

wxMenu* T100ProjectData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();
    wxMenu*     file    = T100NEW wxMenu();
    wxMenu*     clazz   = T100NEW wxMenu();

    menu->AppendSubMenu(file, L"File");
    menu->AppendSubMenu(clazz, L"Class");

    file->Append(T100PROJECT_TREE_MENU_FILE_NEW, L"New");
    clazz->Append(T100PROJECT_TREE_MENU_CLASS_NEW, L"New");

    return menu;
}

T100VOID T100ProjectData::OnItemChanged()
{
    T100ProjectInvoking::OnProjectSelected();
}

T100VOID T100ProjectData::OnItemActivated()
{

}

T100VOID T100ProjectData::OnItemExpanding()
{

}
