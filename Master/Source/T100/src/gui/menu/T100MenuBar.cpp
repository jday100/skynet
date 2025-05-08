#include "gui/menu/T100MenuBar.h"

T100MenuBar::T100MenuBar()
{
    //ctor
    m_menuBar   = CreateMenu();
}

T100MenuBar::~T100MenuBar()
{
    //dtor
}

T100VOID T100MenuBar::Create(T100WSTRING& label)
{
    m_menuBar   = CreateMenu();
}

T100VOID T100MenuBar::Destroy()
{

}
