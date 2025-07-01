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

    m_editMenu      = T100NEW T100Menu(m_menuBar, L"Edit");

    m_undoItem      = T100NEW T100MenuItem(m_editMenu, T100MAIN_MENU_EDIT_UNDO, L"Undo");
    m_redoItem      = T100NEW T100MenuItem(m_editMenu, T100MAIN_MENU_EDIT_REDO, L"Redo");

    m_editMenu->AppendSeparator();

    m_cutItem       = T100NEW T100MenuItem(m_editMenu, T100MAIN_MENU_EDIT_CUT, L"Cut");
    m_copyItem      = T100NEW T100MenuItem(m_editMenu, T100MAIN_MENU_EDIT_COPY, L"Cut");
    m_pasteItem     = T100NEW T100MenuItem(m_editMenu, T100MAIN_MENU_EDIT_PASTE, L"Paste");

    m_searchMenu    = T100NEW T100Menu(m_menuBar, L"Search");

    m_findItem      = T100NEW T100MenuItem(m_searchMenu, T100MAIN_MENU_SEARCH_FIND, L"Find");
    m_replaceItem   = T100NEW T100MenuItem(m_searchMenu, T100MAIN_MENU_SEARCH_REPLACE, L"Replace");

    m_helpMenu      = T100NEW T100Menu(m_menuBar, L"Help");

    m_aboutItem     = T100NEW T100MenuItem(m_helpMenu, T100MAIN_MENU_HELP_ABOUT, L"About");

    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_FILE_NEW, T100MAIN_MENU_FILE_NEW, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnNew, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_FILE_OPEN, T100MAIN_MENU_FILE_OPEN, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnOpen, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_FILE_CLOSE, T100MAIN_MENU_FILE_CLOSE, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnClose, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_FILE_SAVE, T100MAIN_MENU_FILE_SAVE, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnSave, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_FILE_SAVE_AS, T100MAIN_MENU_FILE_SAVE_AS, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnSaveAs, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_FILE_QUIT, T100MAIN_MENU_FILE_QUIT, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnQuit, &m_actuator);

    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_EDIT_UNDO, T100MAIN_MENU_EDIT_UNDO, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnUndo, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_EDIT_REDO, T100MAIN_MENU_EDIT_REDO, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnRedo, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_EDIT_CUT, T100MAIN_MENU_EDIT_CUT, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnCut, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_EDIT_COPY, T100MAIN_MENU_EDIT_COPY, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnCopy, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_EDIT_PASTE, T100MAIN_MENU_EDIT_PASTE, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnPaste, &m_actuator);

    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_SEARCH_FIND, T100MAIN_MENU_SEARCH_FIND, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnFind, &m_actuator);
    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_SEARCH_REPLACE, T100MAIN_MENU_SEARCH_REPLACE, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnReplace, &m_actuator);

    T100ProjectInvoking::BindMenu(T100PROJECT_VIEW_MAIN_MENU_HELP_ABOUT, T100MAIN_MENU_HELP_ABOUT, (T100EVENT_FUNCTION)T100ProjectMainMenuActuator::OnAbout, &m_actuator);
}

T100VOID T100ProjectMainMenu::Destroy()
{
    T100SAFE_DELETE(m_menuBar);
}

T100MenuBar* T100ProjectMainMenu::GetMenuBar()
{
    return m_menuBar;
}
