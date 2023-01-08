#include "T100ElementBase.h"

#include <wx/textctrl.h>

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

T100STRING T100ElementBase::getPanel()
{
    return m_panel;
}

T100VOID T100ElementBase::setLabel(T100STRING label)
{
    m_label = label;
    //
    m_name  = label;
}

T100STRING T100ElementBase::getLabel()
{
    return m_label;
}

T100STRING T100ElementBase::getKey()
{
    return m_key;
}

T100WORD T100ElementBase::getType()
{
    return m_type;
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

T100BOOL T100ElementBase::Update(wxPropertyGrid* panel)
{
    return T100TRUE;
}

T100BOOL T100ElementBase::Update(wxPropertyGridEvent& event)
{
    return T100TRUE;
}

T100BOOL T100ElementBase::MouseLeftDown(T100INT x, T100INT y)
{
    m_starting_x    = x;
    m_starting_y    = y;

    return T100TRUE;
}

T100BOOL T100ElementBase::MouseLeftUp(T100INT, T100INT)
{
    return T100TRUE;
}

T100BOOL T100ElementBase::MouseMove(T100INT, T100INT)
{
    return T100TRUE;
}

T100BOOL T100ElementBase::Move(T100INT x, T100INT y)
{
    T100INT     dx, dy;

    dx = x - m_starting_x;
    dy = y = m_starting_y;

    m_starting_x    = x;
    m_starting_y    = y;

    return T100TRUE;
}

}
