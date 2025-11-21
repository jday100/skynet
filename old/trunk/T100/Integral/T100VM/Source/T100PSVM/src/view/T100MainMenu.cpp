#include "T100MainMenu.h"

#include "T100PSVMCommon.h"
#include "T100PSVMMain.h"

T100MainMenu::T100MainMenu()
{
    //ctor
}

T100MainMenu::~T100MainMenu()
{
    //dtor
}

T100VOID T100MainMenu::Create(T100PSVMFrame* frame)
{
    m_frame     = frame;

    wxMenuBar*      menuBar     = T100NEW wxMenuBar();
    wxMenu*         menuFile    = T100NEW wxMenu();
    wxMenu*         menuVM      = T100NEW wxMenu();
    wxMenu*         menuDebug   = T100NEW wxMenu();
    wxMenu*         menuHelp    = T100NEW wxMenu();

    m_fileCreate    = T100NEW wxMenuItem(menuFile, T100PSVM_MENU_ITEM_FILE_NEW, "New");
    m_fileOpen      = T100NEW wxMenuItem(menuFile, T100PSVM_MENU_ITEM_FILE_OPEN, "Open");
    m_fileClose     = T100NEW wxMenuItem(menuFile, T100PSVM_MENU_ITEM_FILE_CLOSE, "Close");
    m_fileSave      = T100NEW wxMenuItem(menuFile, T100PSVM_MENU_ITEM_FILE_SAVE, "Save");
    m_fileSaveAs    = T100NEW wxMenuItem(menuFile, T100PSVM_MENU_ITEM_FILE_SAVE_AS, "Save as...");
    m_fileQuit      = T100NEW wxMenuItem(menuFile, T100PSVM_MENU_ITEM_FILE_QUIT, "Quit");

    m_vmStart       = T100NEW wxMenuItem(menuVM, T100PSVM_MENU_ITEM_VM_START, "Start");
    m_vmStop        = T100NEW wxMenuItem(menuVM, T100PSVM_MENU_ITEM_VM_STOP, "Stop");

    m_debugStart    = T100NEW wxMenuItem(menuDebug, T100PSVM_MENU_ITEM_DEBUG_START, "Start");
    m_debugStop     = T100NEW wxMenuItem(menuDebug, T100PSVM_MENU_ITEM_DEBUG_STOP, "Stop");

    m_helpAbout     = T100NEW wxMenuItem(menuHelp, T100PSVM_MENU_ITEM_HELP_ABOUT, "About");

    menuFile->Append(m_fileCreate);
    menuFile->Append(m_fileOpen);
    menuFile->Append(m_fileClose);
    menuFile->AppendSeparator();
    menuFile->Append(m_fileSave);
    menuFile->Append(m_fileSaveAs);
    menuFile->AppendSeparator();
    menuFile->Append(m_fileQuit);

    menuVM->Append(m_vmStart);
    menuVM->Append(m_vmStop);

    menuDebug->Append(m_debugStart);
    menuDebug->Append(m_debugStop);

    menuHelp->Append(m_helpAbout);

    menuBar->Append(menuFile, "File");
    menuBar->Append(menuVM, "VM");
    menuBar->Append(menuDebug, "Debug");
    menuBar->Append(menuHelp, "Help");

    m_frame->SetMenuBar(menuBar);

    init();
}

T100VOID T100MainMenu::Destroy()
{
    uninit();
}

T100VOID T100MainMenu::init()
{
    m_fileCreate->Enable(T100TRUE);
    m_fileOpen->Enable(T100TRUE);
    m_fileClose->Enable(T100FALSE);
    m_fileSave->Enable(T100FALSE);
    m_fileSaveAs->Enable(T100FALSE);
    m_fileQuit->Enable(T100TRUE);

    m_vmStart->Enable(T100FALSE);
    m_vmStop->Enable(T100FALSE);

    m_debugStart->Enable(T100FALSE);
    m_debugStop->Enable(T100FALSE);

    m_helpAbout->Enable(T100TRUE);
}

T100VOID T100MainMenu::uninit()
{

}

T100VOID T100MainMenu::Create()
{
    m_fileClose->Enable(T100TRUE);
    m_fileSave->Enable(T100TRUE);
    m_fileSaveAs->Enable(T100TRUE);

    m_vmStart->Enable(T100TRUE);
    m_vmStop->Enable(T100FALSE);

    m_debugStart->Enable(T100TRUE);
    m_debugStop->Enable(T100FALSE);
}

T100VOID T100MainMenu::Open()
{
    m_fileClose->Enable(T100TRUE);
    m_fileSaveAs->Enable(T100TRUE);

    m_vmStart->Enable(T100TRUE);
    m_vmStop->Enable(T100FALSE);

    m_debugStart->Enable(T100TRUE);
    m_debugStop->Enable(T100FALSE);
}

T100VOID T100MainMenu::Close()
{
    m_fileClose->Enable(T100FALSE);
    m_fileSave->Enable(T100FALSE);
    m_fileSaveAs->Enable(T100FALSE);

    m_vmStart->Enable(T100FALSE);
    m_vmStop->Enable(T100FALSE);

    m_debugStart->Enable(T100FALSE);
    m_debugStop->Enable(T100FALSE);
}

T100VOID T100MainMenu::Save()
{
    m_fileSave->Enable(T100FALSE);
}

T100VOID T100MainMenu::Dirty()
{
    m_fileSave->Enable(T100TRUE);
}

T100VOID T100MainMenu::Start()
{
    m_vmStart->Enable(T100FALSE);
    m_vmStop->Enable(T100TRUE);

    m_debugStart->Enable(T100FALSE);
    m_debugStop->Enable(T100FALSE);
}

T100VOID T100MainMenu::Stop()
{
    m_vmStart->Enable(T100TRUE);
    m_vmStop->Enable(T100FALSE);

    m_debugStart->Enable(T100TRUE);
    m_debugStop->Enable(T100FALSE);
}
