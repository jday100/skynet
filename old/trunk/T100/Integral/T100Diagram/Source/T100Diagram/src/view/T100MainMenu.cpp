#include "T100MainMenu.h"

#include "T100DiagramCommon.h"
#include "T100DiagramMain.h"

T100MainMenu::T100MainMenu()
{
    //ctor
}

T100MainMenu::~T100MainMenu()
{
    //dtor
}

T100VOID T100MainMenu::Create(T100DiagramFrame* frame)
{
    m_frame         = frame;

    wxMenuBar*      menuBar         = T100NEW wxMenuBar();

    wxMenu*         fileMenu        = T100NEW wxMenu();
    wxMenu*         editMenu        = T100NEW wxMenu();
    wxMenu*         viewMenu        = T100NEW wxMenu();
    wxMenu*         searchMenu      = T100NEW wxMenu();
    wxMenu*         developMenu     = T100NEW wxMenu();
    wxMenu*         setupMenu       = T100NEW wxMenu();
    wxMenu*         helpMenu        = T100NEW wxMenu();

    m_fileCreate            = T100NEW wxMenuItem(fileMenu, T100DIAGRAM_MENU_FILE_CREATE, L"New");
    m_fileOpen              = T100NEW wxMenuItem(fileMenu, T100DIAGRAM_MENU_FILE_OPEN, L"Open");
    m_fileClose             = T100NEW wxMenuItem(fileMenu, T100DIAGRAM_MENU_FILE_CLOSE, L"Close");
    m_fileSave              = T100NEW wxMenuItem(fileMenu, T100DIAGRAM_MENU_FILE_SAVE, L"Save");
    m_fileSaveAs            = T100NEW wxMenuItem(fileMenu, T100DIAGRAM_MENU_FILE_SAVE_AS, L"Save as...");
    m_fileQuit              = T100NEW wxMenuItem(fileMenu, T100DIAGRAM_MENU_FILE_QUIT, L"Quit");

    fileMenu->Append(m_fileCreate);
    fileMenu->Append(m_fileOpen);
    fileMenu->AppendSeparator();
    fileMenu->Append(m_fileClose);
    fileMenu->AppendSeparator();
    fileMenu->Append(m_fileSave);
    fileMenu->Append(m_fileSaveAs);
    fileMenu->AppendSeparator();
    fileMenu->Append(m_fileQuit);

    menuBar->Append(fileMenu, L"File");

    m_undo                  = T100NEW wxMenuItem(editMenu, T100DIAGRAM_MENU_EDIT_UNDO, L"Undo");
    m_redo                  = T100NEW wxMenuItem(editMenu, T100DIAGRAM_MENU_EDIT_REDO, L"Redo");
    m_cut                   = T100NEW wxMenuItem(editMenu, T100DIAGRAM_MENU_EDIT_CUT, L"Cut");
    m_copy                  = T100NEW wxMenuItem(editMenu, T100DIAGRAM_MENU_EDIT_COPY, L"Copy");
    m_paste                 = T100NEW wxMenuItem(editMenu, T100DIAGRAM_MENU_EDIT_PASTE, L"Paste");

    editMenu->Append(m_undo);
    editMenu->Append(m_redo);
    editMenu->AppendSeparator();
    editMenu->Append(m_cut);
    editMenu->Append(m_copy);
    editMenu->Append(m_paste);

    menuBar->Append(editMenu, L"Edit");

    m_viewManager           = T100NEW wxMenuItem(viewMenu, T100DIAGRAM_MENU_VIEW_MANAGER, L"Manager view", wxEmptyString, T100TRUE);
    m_viewProperty          = T100NEW wxMenuItem(viewMenu, T100DIAGRAM_MENU_VIEW_PROPERTY, L"Property view", wxEmptyString, T100TRUE);
    m_find                  = T100NEW wxMenuItem(searchMenu, T100DIAGRAM_MENU_SEARCH_FIND, L"Find");
    m_import                = T100NEW wxMenuItem(developMenu, T100DIAGRAM_MENU_DEVELOP_IMPORT, L"Import");
    m_config                = T100NEW wxMenuItem(setupMenu, T100DIAGRAM_MENU_SETUP_CONFIG, L"Config");
    m_about                 = T100NEW wxMenuItem(helpMenu, T100DIAGRAM_MENU_HELP_ABOUT, L"About");

    viewMenu->Append(m_viewManager);
    viewMenu->Append(m_viewProperty);
    searchMenu->Append(m_find);
    developMenu->Append(m_import);
    setupMenu->Append(m_config);
    helpMenu->Append(m_about);

    menuBar->Append(viewMenu, L"View");
    menuBar->Append(searchMenu, L"Search");
    menuBar->Append(developMenu, L"Develop");
    menuBar->Append(setupMenu, L"Setup");
    menuBar->Append(helpMenu, L"Help");

    init();

    frame->SetMenuBar(menuBar);
}

T100VOID T100MainMenu::Destroy()
{

}

T100VOID T100MainMenu::init()
{
    m_fileCreate->Enable(T100TRUE);
    m_fileOpen->Enable(T100TRUE);
    m_fileClose->Enable(T100FALSE);
    m_fileSave->Enable(T100FALSE);
    m_fileSaveAs->Enable(T100FALSE);
    m_fileQuit->Enable(T100TRUE);

    m_undo->Enable(T100FALSE);
    m_redo->Enable(T100FALSE);
    m_cut->Enable(T100FALSE);
    m_copy->Enable(T100FALSE);
    m_paste->Enable(T100FALSE);

    m_viewManager->Enable(T100TRUE);
    m_viewProperty->Enable(T100TRUE);

    m_find->Enable(T100FALSE);

    m_config->Enable(T100TRUE);

    m_about->Enable(T100TRUE);
}

T100VOID T100MainMenu::ViewManager(T100BOOL flag)
{
    m_viewManager->Check(flag);
}

T100VOID T100MainMenu::ViewProperty(T100BOOL flag)
{
    m_viewProperty->Check(flag);
}

T100VOID T100MainMenu::Dirty()
{
    m_fileSave->Enable(T100TRUE);
}

T100VOID T100MainMenu::Open()
{
    m_fileClose->Enable(T100TRUE);
    m_fileSaveAs->Enable(T100TRUE);
    m_find->Enable(T100TRUE);
    m_import->Enable(T100TRUE);
}

T100VOID T100MainMenu::Close()
{
    m_fileClose->Enable(T100FALSE);
    m_fileSave->Enable(T100FALSE);
    m_fileSaveAs->Enable(T100FALSE);

    m_find->Enable(T100FALSE);

    m_import->Enable(T100FALSE);
}

T100VOID T100MainMenu::Save()
{
    m_fileSave->Enable(T100FALSE);
}
