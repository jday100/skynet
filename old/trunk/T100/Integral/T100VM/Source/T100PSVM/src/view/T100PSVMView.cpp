#include "T100PSVMView.h"

#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include "T100PSVMCreateDialog.h"
#include "T100PSVMMain.h"

T100PSVMView::T100PSVMView()
{
    //ctor
}

T100PSVMView::~T100PSVMView()
{
    //dtor
}

T100VOID T100PSVMView::Create(T100PSVMFrame* frame)
{
    m_frame     = frame;

    m_mainMenu  = T100NEW T100MainMenu();

    m_mainMenu->Create(frame);
}

T100VOID T100PSVMView::Destroy()
{
    m_mainMenu->Destroy();

    m_frame->Destroy();
}

T100BOOL T100PSVMView::Create(T100PSVMInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    m_mainMenu->Create();

    return T100TRUE;
}

T100BOOL T100PSVMView::Open(T100PSVMInfo* info)
{
    if(!info){
        return T100FALSE;
    }


    m_mainMenu->Open();

    return T100TRUE;
}

T100BOOL T100PSVMView::Save(T100PSVMInfo* info)
{
    if(!info){
        return T100FALSE;
    }



    return T100TRUE;
}

T100BOOL T100PSVMView::SaveAs()
{
    m_mainMenu->Save();
    return T100TRUE;
}

T100BOOL T100PSVMView::Close()
{
    m_mainMenu->Close();
    return T100TRUE;
}

T100BOOL T100PSVMView::Start()
{
    if(m_vm){
        return T100FALSE;
    }

    m_vm    = T100NEW T100VMFrame(m_frame);

    if(!m_vm){
        return T100FALSE;
    }

    m_mainMenu->Start();
    m_vm->Show();

    return T100TRUE;
}

T100BOOL T100PSVMView::Stop()
{
    if(!m_vm){
        return T100FALSE;
    }

    T100SAFE_DELETE(m_vm)
    m_mainMenu->Stop();

    return T100TRUE;
}

T100BOOL T100PSVMView::DebugStart(T100VM* vm)
{
    m_vm    = T100NEW T100VMFrame(m_frame);
    m_debug = T100NEW T100DebugFrame(m_vm);

    m_debug->SetVM(vm);

    m_vm->Show();
    m_debug->Show();
}

T100BOOL T100PSVMView::DebugStop()
{

}

T100VOID T100PSVMView::Dirty()
{
    m_mainMenu->Dirty();
}

T100VOID T100PSVMView::Log(T100STRING& value)
{
    m_frame->Log(value);
}

T100BOOL T100PSVMView::ShowFileOpenDialog(T100WxFileInfo* info)
{
    T100BOOL        result      = T100FALSE;

    if(!info){
        return result;
    }

    T100INT         value;

    wxFileDialog    dialog(m_frame, wxFileSelectorPromptStr, wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    value   = dialog.ShowModal();

    if(value == wxID_OK){
        info->m_filename    = dialog.GetFilename().ToStdString();
        info->m_path        = dialog.GetPath().ToStdString();
        result  = T100TRUE;
    }

    return result;
}

T100BOOL T100PSVMView::ShowFileSaveDialog(T100WxFileInfo* info)
{
    T100BOOL        result      = T100FALSE;

    if(!info){
        return result;
    }

    T100INT         value;

    wxFileDialog    dialog(m_frame, wxFileSelectorPromptStr, wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE);

    value   = dialog.ShowModal();

    if(value == wxID_OK){
        info->m_filename    = dialog.GetFilename().ToStdString();
        info->m_path        = dialog.GetPath().ToStdString();
        result  = T100TRUE;
    }

    return result;
}

T100BOOL T100PSVMView::ShowDebugFrame()
{

}

T100BOOL T100PSVMView::ShowCreateDialog(T100PSVMInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100PSVMCreateDialog        dialog(m_frame);

    if(dialog.ShowModal() == wxID_OK){
        info->m_firmware    = dialog.GetValue();
        return T100TRUE;
    }
    return T100FALSE;
}

T100VOID T100PSVMView::ShowCreateFailureDialog()
{
    wxMessageBox(L"Create failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}

T100VOID T100PSVMView::ShowOpenFailureDialog()
{
    wxMessageBox(L"Open failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}

T100VOID T100PSVMView::ShowCloseFailureDialog()
{
    wxMessageBox(L"Close failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}

T100VOID T100PSVMView::ShowVMStartFailureDialog()
{
    wxMessageBox(L"Start failure!", "Error", wxICON_ERROR | wxCLOSE, m_frame);
}
