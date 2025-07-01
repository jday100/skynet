#include "T100CVMViewMainMenu.h"

T100CVMViewMainMenu::T100CVMViewMainMenu(T100Frame* frame) :
    m_frame(frame)
{
    //ctor
}

T100CVMViewMainMenu::~T100CVMViewMainMenu()
{
    //dtor
}

T100VOID T100CVMViewMainMenu::Create()
{
    m_menuBar       = T100NEW T100MenuBar();

    m_vmMenu        = T100NEW T100Menu(m_menuBar, L"Vm");
    m_newItem       = T100NEW T100MenuItem(m_vmMenu, 0, L"New");

    m_vmMenu->AppendSeparator();

    m_startItem     = T100NEW T100MenuItem(m_vmMenu, 100, L"Start");
    m_stopItem      = T100NEW T100MenuItem(m_vmMenu, 101, L"Stop");

    m_helpMenu      = T100NEW T100Menu(m_menuBar, L"Help");
    m_aboutItem     = T100NEW T100MenuItem(m_helpMenu, 0, L"About");

    m_frame->SetMenuBar(m_menuBar);
}

T100VOID T100CVMViewMainMenu::Destroy()
{

}
