#include "gui/T100Menu.h"

#include "gui/T100MenuBar.h"

namespace T100WINDOWS{

T100Menu::T100Menu(const T100WSTRING& label) :
    T100MenuBase()
{
    //ctor
    SetLabel(label);
    m_hmenu = CreateMenu();
}

T100Menu::T100Menu(T100MenuBar* parent, const T100WSTRING& label) :
    T100MenuBase()
{
    //ctor
    SetLabel(label);
    m_hmenu = CreateMenu();
    AppendMenu(parent->GetHMENU(), MF_POPUP, (UINT_PTR)m_hmenu, label.c_str());
}

T100Menu::~T100Menu()
{
    //dtor
}

T100VOID T100Menu::Append(T100UINT id, const T100WSTRING& label)
{
    AppendMenu(m_hmenu, MF_STRING, (UINT_PTR)id, label.c_str());
}

T100VOID T100Menu::Append(T100MenuItem* item)
{
    AppendMenu(m_hmenu, MF_STRING, item->GetID(), item->GetLabel().c_str());
}

T100VOID T100Menu::Remove(T100MenuItem* item)
{

}

T100VOID T100Menu::AppendSeparator()
{
    AppendMenu(m_hmenu, MF_SEPARATOR, 0, 0);
}

}
