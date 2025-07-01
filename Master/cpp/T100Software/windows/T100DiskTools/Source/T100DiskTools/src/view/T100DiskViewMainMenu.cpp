#include "T100DiskViewMainMenu.h"

T100DiskViewMainMenu::T100DiskViewMainMenu()
{
    //ctor
}

T100DiskViewMainMenu::~T100DiskViewMainMenu()
{
    //dtor
}

T100VOID T100DiskViewMainMenu::Create(T100Frame* frame)
{
    m_frame         = frame;

    m_menuBar       = T100NEW T100MenuBar();

    m_fileMenu      = T100NEW T100Menu(m_menuBar, L"File");

    m_openItem      = T100NEW T100MenuItem(m_fileMenu, 0, L"Open");
    m_closeItem     = T100NEW T100MenuItem(m_fileMenu, 1, L"Close");

    m_fileMenu->AppendSeparator();

    m_quitItem      = T100NEW T100MenuItem(m_fileMenu, 1003, L"Quit");

    m_helpMenu      = T100NEW T100Menu(m_menuBar, L"Help");

    m_aboutItem     = T100NEW T100MenuItem(m_helpMenu, 2, L"About");

    m_frame->SetMenuBar(m_menuBar);
}

T100VOID T100DiskViewMainMenu::Destroy()
{

}
