#include "T100PluginEditor.h"

#include <wx/menu.h>
#include <wx/frame.h>
#include "T100WxMainMain.h"

T100PluginEditor::T100PluginEditor() :
    T100Plugin()
{
    //ctor
}

T100PluginEditor::~T100PluginEditor()
{
    //dtor
}

T100BOOL T100PluginEditor::Create(T100VOID* value)
{
    wxFrame*    frame   = (wxFrame*)value;

    if(!frame){
        return T100FALSE;
    }

    m_actuator.m_editor.SetFrame(frame);

    long    id      = wxNewId();

    wxMenuItem*     fileNew     = T100NEW wxMenuItem(T100NULL, id, L"New");

    frame->GetMenuBar()->GetMenu(0)->Insert(0, fileNew);

    frame->Connect(id,      wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T100PluginEditorActuator::OnFileNew, T100NULL, &m_actuator);


    T100WxMainFrame*    mainFrame   = (T100WxMainFrame*)frame;

    if(!mainFrame){
        return T100FALSE;
    }

    long temp  = mainFrame->GetQuitID();

    //frame->Disconnect(mainFrame->GetQuitID(),   wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T100WxMainFrame::OnQuit);
    //frame->Disconnect(mainFrame->GetQuitID(),   wxEVT_COMMAND_MENU_SELECTED);
    //frame->Connect(mainFrame->GetQuitID(),      wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T100PluginEditorActuator::OnFileQuit, T100NULL, &m_actuator);

    frame->Connect(100,      wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T100PluginEditorActuator::OnFileQuit, T100NULL, &m_actuator);

    return T100TRUE;
}
