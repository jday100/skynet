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

    m_workNew       = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_NEW, L"New");
    m_workOpen      = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_OPEN, L"Open");
    m_workClose     = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_CLOSE, L"Close");
    m_workSave      = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_SAVE, L"Save");
    m_workSaveAs    = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_SAVE_AS, L"Save as ...");
    m_workQuit      = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_QUIT, L"Quit");

    workMenu->Append(m_workNew);
    workMenu->Append(m_workOpen);
    workMenu->Append(m_workClose);
    workMenu->AppendSeparator();
    workMenu->Append(m_workSave);
    workMenu->Append(m_workSaveAs);
    workMenu->AppendSeparator();
    workMenu->Append(m_workQuit);

    menuBar->Append(workMenu, L"WorkSpace");

    m_projectNew    = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_NEW, L"New");
    m_projectOpen   = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_OPEN, L"Open");
    m_projectClose  = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_CLOSE, L"Close");
    m_projectSave   = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_SAVE, L"Save");
    m_projectSaveAs = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_SAVE_AS, L"Save as ...");

    projectMenu->Append(m_projectNew);
    projectMenu->Append(m_projectOpen);
    projectMenu->Append(m_projectClose);
    projectMenu->AppendSeparator();
    projectMenu->Append(m_projectSave);
    projectMenu->Append(m_projectSaveAs);

    menuBar->Append(projectMenu, L"Project");

    m_fileNew       = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_NEW, L"New");
    m_fileOpen      = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_OPEN, L"Open");
    m_fileClose     = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_CLOSE, L"Close");
    m_fileSave      = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_SAVE, L"Save");
    m_fileSaveAs    = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_SAVE_AS, L"Save as ...");

    fileMenu->Append(m_fileNew);
    fileMenu->Append(m_fileOpen);
    fileMenu->Append(m_fileClose);
    fileMenu->AppendSeparator();
    fileMenu->Append(m_fileSave);
    fileMenu->Append(m_fileSaveAs);

    menuBar->Append(fileMenu, L"File");

    m_undo      = T100NEW wxMenuItem(editMenu, T100PROJECT_MENU_EDIT_UNDO, L"Undo");
    m_redo      = T100NEW wxMenuItem(editMenu, T100PROJECT_MENU_EDIT_REDO, L"Redo");
    m_cut       = T100NEW wxMenuItem(editMenu, T100PROJECT_MENU_EDIT_CUT, L"Cut");
    m_copy      = T100NEW wxMenuItem(editMenu, T100PROJECT_MENU_EDIT_COPY, L"Copy");
    m_paste     = T100NEW wxMenuItem(editMenu, T100PROJECT_MENU_EDIT_PASTE, L"Paste");

    editMenu->Append(m_undo);
    editMenu->Append(m_redo);
    editMenu->AppendSeparator();
    editMenu->Append(m_cut);
    editMenu->Append(m_copy);
    editMenu->Append(m_paste);

    menuBar->Append(editMenu, L"Edit");

    menuBar->Append(viewMenu, L"View");

    m_find      = T100NEW wxMenuItem(searchMenu, T100PROJECT_MENU_SEARCH_FIND, L"Find ...");
    m_replace   = T100NEW wxMenuItem(searchMenu, T100PROJECT_MENU_SEARCH_REPLACE, L"Replace ...");

    searchMenu->Append(m_find);
    searchMenu->Append(m_replace);

    menuBar->Append(searchMenu, L"Search");

    helpMenu->Append(T100PROJECT_MENU_HELP_ABOUT, L"About");

    m_build     = T100NEW wxMenuItem(compileMenu, T100PROJECT_MENU_COMPILE_BUILD, L"Build");

    compileMenu->Append(m_build);

    menuBar->Append(compileMenu, L"Compile");

    m_editor    = T100NEW wxMenuItem(setupMenu, T100PROJECT_MENU_SETUP_EDITOR, L"Editor ...");
    m_compiler  = T100NEW wxMenuItem(setupMenu, T100PROJECT_MENU_SETUP_COMPILER, L"Compiler ...");

    setupMenu->Append(m_editor);
    setupMenu->Append(m_compiler);

    menuBar->Append(setupMenu, L"Setup");

    menuBar->Append(helpMenu, L"Help");

    init();

    frame->SetMenuBar(menuBar);
}

T100VOID T100ProjectViewMainMenu::Destroy()
{
    uninit();
}

T100VOID T100ProjectViewMainMenu::init()
{
    m_workNew->Enable(T100TRUE);
    m_workOpen->Enable(T100TRUE);
    m_workClose->Enable(T100FALSE);
    m_workSave->Enable(T100FALSE);
    m_workSaveAs->Enable(T100FALSE);
    m_workQuit->Enable(T100TRUE);

    m_projectNew->Enable(T100FALSE);
    m_projectOpen->Enable(T100FALSE);
    m_projectClose->Enable(T100FALSE);
    m_projectSave->Enable(T100FALSE);
    m_projectSaveAs->Enable(T100FALSE);

    m_fileNew->Enable(T100FALSE);
    m_fileOpen->Enable(T100FALSE);
    m_fileClose->Enable(T100FALSE);
    m_fileSave->Enable(T100FALSE);
    m_fileSaveAs->Enable(T100FALSE);

    m_undo->Enable(T100FALSE);
    m_redo->Enable(T100FALSE);
    m_cut->Enable(T100FALSE);
    m_copy->Enable(T100FALSE);
    m_paste->Enable(T100FALSE);

    m_find->Enable(T100FALSE);
    m_replace->Enable(T100FALSE);

    m_build->Enable(T100FALSE);

    m_editor->Enable(T100TRUE);
    m_compiler->Enable(T100TRUE);

}

T100VOID T100ProjectViewMainMenu::uninit()
{

}

T100VOID T100ProjectViewMainMenu::ProjectSelected()
{
    m_fileNew->Enable(T100TRUE);
}

T100VOID T100ProjectViewMainMenu::FileOpen()
{
    m_fileClose->Enable(T100TRUE);
    m_fileSaveAs->Enable(T100TRUE);
}

T100VOID T100ProjectViewMainMenu::FileModified()
{
    m_fileSave->Enable(T100TRUE);
}

T100VOID T100ProjectViewMainMenu::FolderSelected()
{
    m_fileNew->Enable(T100TRUE);
}
