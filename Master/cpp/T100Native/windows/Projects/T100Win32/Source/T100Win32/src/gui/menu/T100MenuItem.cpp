#include "T100MenuItem.h"

#include "gui/T100Menu.h"

namespace T100WINDOWS{

T100MenuItem::T100MenuItem(T100UINT id, const T100WSTRING& label) :
    T100MenuBase(),
    m_id(id)
{
    //ctor
    SetLabel(label);
    m_hmenu     = CreateMenu();
}

T100MenuItem::T100MenuItem(T100Menu* parent, T100UINT id, const T100WSTRING& label) :
    T100MenuBase(),
    m_id(id)
{
    //ctor
    SetLabel(label);
    m_hmenu     = CreateMenu();
    AppendMenu(parent->GetHMENU(), MF_STRING, (UINT_PTR)id, label.c_str());
}

T100MenuItem::~T100MenuItem()
{
    //dtor
    DestroyMenu(m_hmenu);
}

T100VOID T100MenuItem::SetID(T100UINT id)
{
    m_id        = id;
}

T100UINT T100MenuItem::GetID()
{
    return m_id;
}

}
