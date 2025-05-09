#include "gui/menu/T100Menu.h"

#include "gui/menu/T100MenuBar.h"

T100Menu::T100Menu(T100MenuBar* menuBar, T100WSTRING label) :
    T100Class()
{
    //ctor
    m_menuBar   = menuBar->m_menuBar;
    m_menu      = CreateMenu();

    AppendMenu(m_menuBar, MF_POPUP, (UINT_PTR)m_menu, label.c_str());
}

T100Menu::~T100Menu()
{
    //dtor
}

T100VOID T100Menu::Create(T100UINT id, T100WSTRING& label)
{
    m_menu      = CreateMenu();
    AppendMenu(m_menu, MF_STRING, id, label.c_str());
}
