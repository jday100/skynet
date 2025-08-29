#include "T100FileData.h"

#include "T100ProjectInvoking.h"

T100FileData::T100FileData() :
    T100TreeItemData()
{
    //ctor
}

T100FileData::T100FileData(T100FileInfo* info) :
    T100TreeItemData(),
    m_info(info)
{
    //ctor
}

T100FileData::~T100FileData()
{
    //dtor
}

T100VOID T100FileData::SetFileInfo(T100FileInfo* info)
{
    m_info      = info;
}

T100FileInfo* T100FileData::GetFileInfo()
{
    return m_info;
}

wxMenu* T100FileData::ShowMenu()
{
    wxMenu*     menu    = T100NEW wxMenu();

    return menu;
}

T100VOID T100FileData::OnItemChanged()
{

}

T100VOID T100FileData::OnItemActivated()
{
    if(m_opened){

    }else{
        T100ProjectInvoking::OnFileOpen(this);
    }
}

T100VOID T100FileData::OnItemExpanding()
{
    if(m_opened){

    }else{
        T100ProjectInvoking::OnFileOpen(this);
    }
}
