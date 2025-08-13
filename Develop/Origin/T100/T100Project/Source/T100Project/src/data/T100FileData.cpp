#include "T100FileData.h"

#include "T100ProjectInvoking.h"

T100FileData::T100FileData() :
    T100TreeItemData()
{
    //ctor
    init();
}

T100FileData::T100FileData(T100FileInfo* info) :
    T100TreeItemData()
{
    //ctor
    init();
}

T100FileData::~T100FileData()
{
    //dtor
    uninit();
}

T100VOID T100FileData::init()
{
    m_opened    = T100FALSE;
}

T100VOID T100FileData::uninit()
{

}

T100VOID T100FileData::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100FileData::GetLabel()
{
    return m_label;
}

T100VOID T100FileData::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100FileData::GetPath()
{
    return m_path;
}

T100VOID T100FileData::SetOpened(T100BOOL value)
{
    m_opened    = value;
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
