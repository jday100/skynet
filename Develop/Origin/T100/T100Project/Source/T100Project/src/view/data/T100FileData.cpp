#include "T100FileData.h"

#include "T100ProjectCommon.h"
#include "T100ProjectInvoking.h"

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

T100FileInfo* T100FileData::GetFileInfo()
{
    return m_info;
}

wxMenu* T100FileData::CreateMenu()
{
    wxMenu*     menu        = T100NEW wxMenu();
    wxMenu*     file        = T100NEW wxMenu();

    menu->AppendSubMenu(file, L"File");

    file->Append(T100PROJECT_TREE_MENU_FILE_REMOVE, L"Remove");

    return menu;
}

T100VOID T100FileData::OnItemChanged()
{
    T100ProjectInvoking::OnFileSelect();
}

T100VOID T100FileData::OnItemActivated()
{
    if(m_opened){

    }else{
        T100ProjectInvoking::OnFileOpenDone(this);
    }
}

T100VOID T100FileData::OnItemExpanding()
{

}
