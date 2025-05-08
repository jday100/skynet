#include "gui/menu/T100MenuItem.h"

#include "gui/menu/T100Menu.h"

T100MenuItem::T100MenuItem(T100Menu* menu, T100UINT id, T100WSTRING label) :
    T100MenuItemBase()
{
    //ctor
    AppendMenu(menu->m_menu, MF_STRING, id, label.c_str());
}

T100MenuItem::~T100MenuItem()
{
    //dtor
}
