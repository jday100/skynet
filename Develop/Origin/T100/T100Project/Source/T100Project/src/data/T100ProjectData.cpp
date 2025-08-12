#include "T100ProjectData.h"

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
    return menu;
}

T100VOID T100ProjectData::OnItemExpanding()
{

}
