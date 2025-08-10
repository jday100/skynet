#include "T100ProjectViewMainMenu.h"

#include <wx/menu.h>
#include "T100ProjectMain.h"
#include "T100ProjectCommon.h"

T100ProjectViewMainMenu::T100ProjectViewMainMenu()
{
    //ctor
}

T100ProjectViewMainMenu::~T100ProjectViewMainMenu()
{
    //dtor
}

T100VOID T100ProjectViewMainMenu::Create(T100ProjectFrame* frame)
{
    m_frame     = frame;

    wxMenuBar*      menuBar         = T100NEW wxMenuBar();
    wxMenu*         workMenu        = T100NEW wxMenu();
    wxMenu*         projectMenu     = T100NEW wxMenu();
    wxMenu*         fileMenu        = T100NEW wxMenu();
    wxMenu*         editMenu        = T100NEW wxMenu();
    wxMenu*         viewMenu        = T100NEW wxMenu();
    wxMenu*         searchMenu      = T100NEW wxMenu();
    wxMenu*         compileMenu     = T100NEW wxMenu();
    wxMenu*         setupMenu       = T100NEW wxMenu();
    wxMenu*         helpMenu        = T100NEW wxMenu();

    workMenu->Append(T100PROJECT_MENU_WORKSPACE_NEW, L"New");
    workMenu->Append(T100PROJECT_MENU_WORKSPACE_OPEN, L"Open");
    workMenu->Append(T100PROJECT_MENU_WORKSPACE_CLOSE, L"Close");
    workMenu->AppendSeparator();
    workMenu->Append(T100PROJECT_MENU_WORKSPACE_SAVE, L"Save");
    workMenu->Append(T100PROJECT_MENU_WORKSPACE_SAVE_AS, L"Save as");
    workMenu->AppendSeparator();
    workMenu->Append(T100PROJECT_MENU_WORKSPACE_QUIT, L"Quit");

    menuBar->Append(workMenu, L"WorkSpace");

    projectMenu->Append(T100PROJECT_MENU_PROJECT_NEW, L"New");
    projectMenu->Append(T100PROJECT_MENU_PROJECT_OPEN, L"Open");
    projectMenu->Append(T100PROJECT_MENU_PROJECT_CLOSE, L"Close");
    projectMenu->AppendSeparator();
    projectMenu->Append(T100PROJECT_MENU_PROJECT_SAVE, L"Save");
    projectMenu->Append(T100PROJECT_MENU_PROJECT_SAVE_AS, L"Save as");

    menuBar->Append(projectMenu, L"Project");

    fileMenu->Append(T100PROJECT_MENU_FILE_NEW, L"New");
    fileMenu->Append(T100PROJECT_MENU_FILE_OPEN, L"Open");
    fileMenu->Append(T100PROJECT_MENU_FILE_CLOSE, L"Close");
    fileMenu->AppendSeparator();
    fileMenu->Append(T100PROJECT_MENU_FILE_SAVE, L"Save");
    fileMenu->Append(T100PROJECT_MENU_FILE_SAVE_AS, L"Save as");

    menuBar->Append(fileMenu, L"File");

    editMenu->Append(T100PROJECT_MENU_EDIT_UNDO, L"Undo");
    editMenu->Append(T100PROJECT_MENU_EDIT_REDO, L"Redo");
    editMenu->AppendSeparator();
    editMenu->Append(T100PROJECT_MENU_EDIT_CUT, L"Cut");
    editMenu->Append(T100PROJECT_MENU_EDIT_COPY, L"Copy");
    editMenu->Append(T100PROJECT_MENU_EDIT_PASTE, L"Paste");

    menuBar->Append(editMenu, L"Edit");

    menuBar->Append(viewMenu, L"View");

    searchMenu->Append(T100PROJECT_MENU_SEARCH_FIND, L"Find");
    searchMenu->Append(T100PROJECT_MENU_SEARCH_REPLACE, L"Replace");

    menuBar->Append(searchMenu, L"Search");

    helpMenu->Append(T100PROJECT_MENU_HELP_ABOUT, L"About");

    compileMenu->Append(T100PROJECT_MENU_COMPILE_BUILD, L"Build");

    menuBar->Append(compileMenu, L"Compile");

    setupMenu->Append(T100PROJECT_MENU_SETUP_EDITOR, L"Editor");
    setupMenu->Append(T100PROJECT_MENU_SETUP_COMPILER, L"Compiler");

    menuBar->Append(setupMenu, L"Setup");

    menuBar->Append(helpMenu, L"Help");

    frame->SetMenuBar(menuBar);
}

T100VOID T100ProjectViewMainMenu::Destroy()
{

}
