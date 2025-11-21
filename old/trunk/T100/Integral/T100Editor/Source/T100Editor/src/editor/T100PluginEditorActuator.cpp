#include "T100PluginEditorActuator.h"

#include <wx/msgdlg.h>
#include "library\thread\T100Thread.h"
#include "T100MainMain.h"

T100PluginEditorActuator::T100PluginEditorActuator(const wxEvtHandler& handler) :
    T100WxPluginActuator(handler),
    m_editor()
{
    //ctor
}

T100PluginEditorActuator::~T100PluginEditorActuator()
{
    //dtor
}

T100VOID T100PluginEditorActuator::SetFrame(T100MainFrame* frame)
{
    m_frame     = frame;
}

T100MainFrame* T100PluginEditorActuator::GetFrame()
{
    return m_frame;
}

T100VOID T100PluginEditorActuator::SignIn()
{
    m_frame->Maximize();

    m_editor.Init(m_frame);
}

T100VOID T100PluginEditorActuator::SignOut()
{
    m_editor.Uninit();
}

T100VOID T100PluginEditorActuator::OnFileCreate(wxCommandEvent& event)
{
    wxMessageBox(L"New");
    //m_editor.Create();

    T100Thread      thread(&T100Editor::Create, &m_editor);

    thread.Detach();
}

T100VOID T100PluginEditorActuator::OnFileOpen(wxCommandEvent& event)
{
    wxMessageBox(L"Open");
}

T100VOID T100PluginEditorActuator::OnFileClose(wxCommandEvent& event)
{
    wxMessageBox(L"Close");
}

T100VOID T100PluginEditorActuator::OnFileSave(wxCommandEvent& event)
{
    wxMessageBox(L"Save");
}

T100VOID T100PluginEditorActuator::OnFileSaveAs(wxCommandEvent& event)
{
    wxMessageBox(L"Save as");
}
