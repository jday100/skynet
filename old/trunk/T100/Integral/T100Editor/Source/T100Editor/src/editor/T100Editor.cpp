#include "T100Editor.h"

#include <wx/menu.h>
#include "main.h"
#include "T100MainMain.h"
#include "T100EditorPanel.h"

#include "T100PluginEditorActuator.h"

T100Editor::T100Editor()
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

T100VOID T100Editor::Init(T100MainFrame* frame)
{
    m_frame     = frame;

    MainMenu();

}

T100VOID T100Editor::Uninit()
{

}

T100VOID T100Editor::MainMenu()
{
    wxMenuBar*          menuBar         = m_frame->GetMenuBar();

    if(!menuBar){
        return;
    }

    T100INT             index           = menuBar->FindMenu(L"File");

    if(index < 0){
        return;
    }

    wxMenu*             menuFile        = menuBar->GetMenu(index);

    if(!menuFile){
        return;
    }

    T100INT             idFileCreate    = wxNewId();
    T100INT             idFileOpen      = wxNewId();
    T100INT             idFileClose     = wxNewId();
    T100INT             idFileSave      = wxNewId();
    T100INT             idFileSaveAs    = wxNewId();

    wxMenuItem*         fileCreate      = T100NEW wxMenuItem(T100NULL, idFileCreate, L"New");
    wxMenuItem*         fileOpen        = T100NEW wxMenuItem(T100NULL, idFileOpen, L"Open");
    wxMenuItem*         fileClose       = T100NEW wxMenuItem(T100NULL, idFileClose, L"Close");
    wxMenuItem*         fileSave        = T100NEW wxMenuItem(T100NULL, idFileSave, L"Save");
    wxMenuItem*         fileSaveAs      = T100NEW wxMenuItem(T100NULL, idFileSaveAs, L"Save as...");

    menuFile->Insert(0, fileCreate);
    menuFile->Insert(1, fileOpen);
    menuFile->Insert(2, fileClose);
    menuFile->InsertSeparator(3);
    menuFile->Insert(4, fileSave);
    menuFile->Insert(5, fileSaveAs);
    menuFile->InsertSeparator(6);

    m_frame->Connect(idFileCreate,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PluginEditorActuator::OnFileCreate, T100NULL, m_actuator);
    m_frame->Connect(idFileOpen,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PluginEditorActuator::OnFileOpen, T100NULL, m_actuator);
    m_frame->Connect(idFileClose,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PluginEditorActuator::OnFileClose, T100NULL, m_actuator);
    m_frame->Connect(idFileSave,        wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PluginEditorActuator::OnFileSave, T100NULL, m_actuator);
    m_frame->Connect(idFileSaveAs,      wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100PluginEditorActuator::OnFileSaveAs, T100NULL, m_actuator);
}

T100BOOL T100Editor::Create()
{
    if(m_panel){
        return T100FALSE;
    }

    m_panel     = T100NEW T100EditorPanel(m_frame);
    return T100TRUE;
}
