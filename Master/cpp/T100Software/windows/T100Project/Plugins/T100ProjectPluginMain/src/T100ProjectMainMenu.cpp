#include "T100ProjectMainMenu.h"

#include "gui/T100Win32Application.h"
#include "skeletal/T100ProjectInvoking.h"


T100ProjectMainMenu::T100ProjectMainMenu(T100Win32Application* handler) :
    m_actuator(handler)
{
    //ctor
}

T100ProjectMainMenu::~T100ProjectMainMenu()
{
    //dtor
}

T100VOID T100ProjectMainMenu::Create()
{
    m_menuBar       = T100NEW T100MenuBar();

    m_fileMenu      = T100NEW T100Menu(m_menuBar, L"File");

    m_newItem       = T100NEW T100MenuItem(m_fileMenu, T100MAIN_MENU_FILE_NEW, L"New");
    m_openItem      = T100NEW T100MenuItem(m_fileMenu, T100MAIN_MENU_FILE_OPEN, L"Open");
    m_closeItem     = T100NEW T100MenuItem(m_fileMenu, T100MAIN_MENU_FILE_CLOSE, L"Close");

    m_fileMenu->AppendSeparator();

    m_saveItem      = T100NEW T100MenuItem(m_fileMenu, T100MAIN_MENU_FILE_SAVE, L"Save");
    m_saveAsItem    = T100NEW T100MenuItem(m_fileMenu, T100MAIN_MENU_FILE_SAVE_AS, L"Save As");

    m_fileMenu->AppendSeparator();

    m_quitItem      = T100NEW T100MenuItem(m_fileMenu, T100MAIN_MENU_FILE_QUIT, L"Quit");

    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_FILE_QUIT, T100MAIN_MENU_FILE_QUIT, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnQuit, &m_actuator);
}

T100VOID T100ProjectMainMenu::Destroy()
{
    T100SAFE_DELETE(m_menuBar);
}

T100MenuBar* T100ProjectMainMenu::GetMenuBar()
{
    return m_menuBar;
}
