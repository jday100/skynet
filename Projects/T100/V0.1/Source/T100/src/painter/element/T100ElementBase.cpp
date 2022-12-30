#include "T100ElementBase.h"

namespace T100Painter{

T100ElementBase::T100ElementBase()
{
    //ctor
}

T100ElementBase::~T100ElementBase()
{
    //dtor
}

T100STRING T100ElementBase::getName()
{
    return m_name;
}

T100STRING T100ElementBase::getLabel()
{
    return m_label;
}

T100STRING T100ElementBase::getKey()
{
    return m_key;
}

T100BOOL T100ElementBase::Append(wxListView* panel)
{
    T100BOOL        result;
    T100LONG        parent;
    T100LONG        index;
    wxUIntPtr       ptr;

    parent  = panel->GetItemCount();

    index   = panel->InsertItem(parent, m_label.to_wstring());

    ptr     = (wxUIntPtr)&m_key;

    panel->SetItemPtrData(index, ptr);

    return T100TRUE;
}

T100BOOL T100ElementBase::MouseLeftDown(T100INT, T100INT)
{
    return T100TRUE;
}

T100BOOL T100ElementBase::MouseLeftUp(T100INT, T100INT)
{
    return T100TRUE;
}

T100BOOL T100ElementBase::MouseMoving()
{
    return T100TRUE;
}

}
