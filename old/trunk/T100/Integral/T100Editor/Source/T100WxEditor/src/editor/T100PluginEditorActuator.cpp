#include "T100PluginEditorActuator.h"

#include <wx/msgdlg.h>

T100PluginEditorActuator::T100PluginEditorActuator() :
    wxEvtHandler()
{
    //ctor
}

T100PluginEditorActuator::~T100PluginEditorActuator()
{
    //dtor
}

T100VOID T100PluginEditorActuator::OnFileNew(wxCommandEvent& event)
{
    wxMessageBox(L"New");
    m_editor.Create();
}

T100VOID T100PluginEditorActuator::OnFileQuit(wxCommandEvent& event)
{
    wxMessageBox(L"Quit");
}
