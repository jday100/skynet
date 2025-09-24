#include "T100MainMenu.h"

#include "T100ProjectMain.h"
#include "T100ProjectCommon.h"

T100MainMenu::T100MainMenu()
{
    //ctor
}

T100MainMenu::~T100MainMenu()
{
    //dtor
}

T100VOID T100MainMenu::Create(T100ProjectFrame* frame)
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
    wxMenu*         debugMenu       = T100NEW wxMenu();
    wxMenu*         setupMenu       = T100NEW wxMenu();
    wxMenu*         helpMenu        = T100NEW wxMenu();

    m_workNew       = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_NEW, L"New");
    m_workOpen      = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_OPEN, L"Open");
    m_workClose     = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_CLOSE, L"Close");
    m_workSave      = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_SAVE, L"Save");
    //m_workSaveAs    = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_SAVE_AS, L"Save as...");
    m_workQuit      = T100NEW wxMenuItem(workMenu, T100PROJECT_MENU_WORKSPACE_QUIT, L"Quit\tAlt-F4");

    workMenu->Append(m_workNew);
    workMenu->Append(m_workOpen);
    workMenu->Append(m_workClose);
    workMenu->AppendSeparator();
    workMenu->Append(m_workSave);
    //workMenu->Append(m_workSaveAs);
    workMenu->AppendSeparator();
    workMenu->Append(m_workQuit);

    menuBar->Append(workMenu, L"WorkSpace");

    m_projectNew    = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_NEW, L"New");
    m_projectOpen   = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_OPEN, L"Open");
    m_projectClose  = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_CLOSE, L"Close");
    m_projectSave   = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_SAVE, L"Save");
    m_projectSaveAs = T100NEW wxMenuItem(projectMenu, T100PROJECT_MENU_PROJECT_SAVE_AS, L"Save as...");

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
    m_fileSave      = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_SAVE, L"Save\tCtrl-S");
    m_fileSaveAs    = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_SAVE_AS, L"Save as...");
    m_fileRemove    = T100NEW wxMenuItem(fileMenu, T100PROJECT_MENU_FILE_REMOVE, L"Remove");

    fileMenu->Append(m_fileNew);
    fileMenu->Append(m_fileOpen);
    fileMenu->Append(m_fileClose);
    fileMenu->AppendSeparator();
    fileMenu->Append(m_fileSave);
    fileMenu->Append(m_fileSaveAs);
    fileMenu->AppendSeparator();
    fileMenu->Append(m_fileRemove);

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

    m_viewWork      = T100NEW wxMenuItem(viewMenu, T100PROJECT_MENU_VIEW_WORKSPACE, L"WorkSpace view", wxEmptyString, T100TRUE);
    m_viewSearch    = T100NEW wxMenuItem(viewMenu, T100PROJECT_MENU_VIEW_SEARCH, L"Search result", wxEmptyString, T100TRUE);
    m_viewOutput    = T100NEW wxMenuItem(viewMenu, T100PROJECT_MENU_VIEW_OUTPUT, L"Compile output", wxEmptyString, T100TRUE);

    viewMenu->Append(m_viewWork);
    viewMenu->Append(m_viewSearch);
    viewMenu->Append(m_viewOutput);

    menuBar->Append(viewMenu, L"View");

    m_find      = T100NEW wxMenuItem(searchMenu, T100PROJECT_MENU_SEARCH_FIND, L"Find...");
    m_replace   = T100NEW wxMenuItem(searchMenu, T100PROJECT_MENU_SEARCH_REPLACE, L"Replace...");

    searchMenu->Append(m_find);
    searchMenu->Append(m_replace);

    menuBar->Append(searchMenu, L"Search");

    m_run           = T100NEW wxMenuItem(compileMenu, T100PROJECT_MENU_COMPILE_RUN, L"Run");
    m_buildAndRun   = T100NEW wxMenuItem(compileMenu, T100PROJECT_MENU_COMPILE_BUILD_AND_RUN, L"Build and Run");
    m_clean         = T100NEW wxMenuItem(compileMenu, T100PROJECT_MENU_COMPILE_CLEAN, L"Clean");
    m_build         = T100NEW wxMenuItem(compileMenu, T100PROJECT_MENU_COMPILE_BUILD, L"Build");
    m_rebuild       = T100NEW wxMenuItem(compileMenu, T100PROJECT_MENU_COMPILE_REBUILD, L"Rebuild");

    compileMenu->Append(m_run);
    compileMenu->Append(m_buildAndRun);
    compileMenu->AppendSeparator();
    compileMenu->Append(m_clean);
    compileMenu->Append(m_build);
    compileMenu->AppendSeparator();
    compileMenu->Append(m_rebuild);

    menuBar->Append(compileMenu, L"Compile");

    m_start         = T100NEW wxMenuItem(debugMenu, T100PROJECT_MENU_DEBUG_START, L"Start");
    m_stop          = T100NEW wxMenuItem(debugMenu, T100PROJECT_MENU_DEBUG_STOP, L"Stop");

    debugMenu->Append(m_start);
    debugMenu->Append(m_stop);

    menuBar->Append(debugMenu, L"Debug");

    m_setupEditor   = T100NEW wxMenuItem(setupMenu, T100PROJECT_MENU_SETUP_EDITOR, L"Editor...");
    m_setupCompiler = T100NEW wxMenuItem(setupMenu, T100PROJECT_MENU_SETUP_COMPILER, L"Compiler...");

    setupMenu->Append(m_setupEditor);
    setupMenu->Append(m_setupCompiler);

    menuBar->Append(setupMenu, L"Setup");

    m_about     = T100NEW wxMenuItem(helpMenu, T100PROJECT_MENU_HELP_ABOUT, L"About");

    helpMenu->Append(m_about);

    menuBar->Append(helpMenu, L"Help");

    init();

    frame->SetMenuBar(menuBar);
}

T100VOID T100MainMenu::Destroy()
{
    uninit();
}

T100VOID T100MainMenu::init()
{
    m_workNew->Enable(T100TRUE);
    m_workOpen->Enable(T100TRUE);
    m_workClose->Enable(T100FALSE);
    m_workSave->Enable(T100FALSE);
    m_workQuit->Enable(T100TRUE);

    m_projectNew->Enable(T100FALSE);
    m_projectOpen->Enable(T100FALSE);
    m_projectClose->Enable(T100FALSE);
    m_projectSave->Enable(T100FALSE);
    m_projectSaveAs->Enable(T100FALSE);

    m_fileNew->Enable(T100TRUE);
    m_fileOpen->Enable(T100TRUE);
    m_fileClose->Enable(T100FALSE);
    m_fileSave->Enable(T100FALSE);
    m_fileSaveAs->Enable(T100FALSE);
    m_fileRemove->Enable(T100FALSE);

    m_undo->Enable(T100FALSE);
    m_redo->Enable(T100FALSE);
    m_cut->Enable(T100FALSE);
    m_copy->Enable(T100FALSE);
    m_paste->Enable(T100FALSE);

    m_viewWork->Enable(T100TRUE);
    m_viewSearch->Enable(T100TRUE);
    m_viewOutput->Enable(T100TRUE);

    m_find->Enable(T100FALSE);
    m_replace->Enable(T100FALSE);

    m_run->Enable(T100FALSE);
    m_buildAndRun->Enable(T100FALSE);
    m_build->Enable(T100FALSE);
    m_clean->Enable(T100FALSE);
    m_rebuild->Enable(T100FALSE);

    m_start->Enable(T100FALSE);
    m_stop->Enable(T100FALSE);

    m_setupEditor->Enable(T100TRUE);
    m_setupCompiler->Enable(T100TRUE);

    m_about->Enable(T100TRUE);
}

T100VOID T100MainMenu::uninit()
{

}

T100VOID T100MainMenu::WorkSpaceOpen()
{
    m_workClose->Enable(T100TRUE);

    m_projectNew->Enable(T100TRUE);
    m_projectOpen->Enable(T100TRUE);

    m_fileNew->Enable(T100TRUE);
    m_fileOpen->Enable(T100TRUE);
}

T100VOID T100MainMenu::WorkSpaceClose()
{
    m_workClose->Enable(T100FALSE);

    m_projectNew->Enable(T100FALSE);
    m_projectOpen->Enable(T100FALSE);

    m_fileNew->Enable(T100FALSE);
    m_fileOpen->Enable(T100FALSE);
}

T100VOID T100MainMenu::WorkSpaceModify()
{
    m_workSave->Enable(T100TRUE);
}

T100VOID T100MainMenu::WorkSpaceSave()
{
    m_workSave->Enable(T100FALSE);
}

T100VOID T100MainMenu::ProjectOpen()
{
    m_projectClose->Enable(T100TRUE);
}

T100VOID T100MainMenu::ProjectSelect()
{
    m_build->Enable(T100TRUE);
    m_buildAndRun->Enable(T100TRUE);
}

T100VOID T100MainMenu::ProjectBuild()
{
    m_run->Enable(T100TRUE);
    m_clean->Enable(T100TRUE);
}

T100VOID T100MainMenu::FolderSelect()
{

}

T100VOID T100MainMenu::FileOpen()
{
    m_fileClose->Enable(T100TRUE);
    m_fileSaveAs->Enable(T100TRUE);
}

T100VOID T100MainMenu::FileSelect()
{
    m_fileRemove->Enable(T100TRUE);
}

T100VOID T100MainMenu::FileModified()
{
    m_fileSave->Enable(T100TRUE);
}

T100VOID T100MainMenu::FileSave()
{
    m_fileSave->Enable(T100FALSE);
}

T100VOID T100MainMenu::ViewWorkSpaceTree(T100BOOL value)
{
    m_viewWork->Check(value);
}

T100VOID T100MainMenu::ViewSearchResult(T100BOOL value)
{
    m_viewSearch->Check(value);
}

T100VOID T100MainMenu::ViewCompileOutput(T100BOOL value)
{
    m_viewOutput->Check(value);
}

T100VOID T100MainMenu::Clear()
{
    init();
}
