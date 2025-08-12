#include "T100ProjectSkeletal.h"

#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include "T100PathTools.h"
#include "T100ProjectMain.h"
#include "T100WxFolderInfo.h"

#include "T100FolderData.h"

T100ProjectSkeletal::T100ProjectSkeletal() :
    T100ProjectSkeletalBase()
{
    //ctor
}

T100ProjectSkeletal::~T100ProjectSkeletal()
{
    //dtor
}

T100VOID T100ProjectSkeletal::Create(T100ProjectFrame* frame)
{
    m_view      = T100NEW T100ProjectView();
    m_serve     = T100NEW T100WorkSpaceServe();

    m_view->Create(frame);
}

T100VOID T100ProjectSkeletal::Destroy()
{
    m_view->Destroy();
    T100SAFE_DELETE(m_serve);
    T100SAFE_DELETE(m_view);
}

T100VOID T100ProjectSkeletal::OnWorkSpaceNew()
{
    if(m_serve->IsOpened()){
        WorkSpaceClose();
    }

    T100WSTRING     path;

    if(m_view->ShowDirDialog(path) == wxID_CANCEL){
        return;
    }

    T100WSTRING     dir;
    T100WSTRING     name;


    T100PathTools::Split(path, dir, name);

    T100WxFolderInfo        info;

    info.SetLabel(name);
    info.SetPath(path);

    if(!WorkSpaceNew(info)){
        return;
    }

    WorkSpaceOpen(info);
}

T100VOID T100ProjectSkeletal::OnWorkSpaceOpen()
{
    if(m_serve->IsOpened()){
        WorkSpaceClose();
    }

    T100WSTRING         path;

    if(m_view->ShowDirDialog(path) == wxID_CANCEL){
        return;
    }

    T100WSTRING     dir;
    T100WSTRING     name;


    T100PathTools::Split(path, dir, name);

    T100WxFolderInfo        info;

    info.SetLabel(name);
    info.SetPath(path);

    WorkSpaceOpen(info);
}

T100VOID T100ProjectSkeletal::OnWorkSpaceClose()
{
    m_serve->Clear();
    m_view->Clear();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceSave()
{

}

T100VOID T100ProjectSkeletal::OnWorkSpaceSaveAs()
{

}

T100VOID T100ProjectSkeletal::OnProjectNew()
{
    ProjectNew();
}

T100VOID T100ProjectSkeletal::OnProjectOpen()
{

}

T100VOID T100ProjectSkeletal::OnProjectClose()
{

}

T100VOID T100ProjectSkeletal::OnProjectSave()
{

}

T100VOID T100ProjectSkeletal::OnProjectSaveAs()
{

}

T100VOID T100ProjectSkeletal::OnFileNew()
{
    T100FileInfo*       info        = T100NEW T100FileInfo();

    info->SetFileName(L"unnamed");

    m_view->New(info);
}

T100VOID T100ProjectSkeletal::OnFileOpen()
{
    wxFileDialog        dialog(m_view->GetFrame());

    if(dialog.ShowModal() == wxID_CANCEL){
        return;
    }

    T100FileInfo*       info        = T100NEW T100FileInfo();

    info->SetFileName(dialog.GetFilename().ToStdWstring());
    info->SetPath(dialog.GetPath().ToStdWstring());

    m_view->Open(info);
}

T100VOID T100ProjectSkeletal::OnFileClose()
{

}

T100VOID T100ProjectSkeletal::OnFileSave()
{
    m_view->Save();
}

T100VOID T100ProjectSkeletal::OnFileSaveAs()
{

}

T100VOID T100ProjectSkeletal::OnEditUndo()
{

}

T100VOID T100ProjectSkeletal::OnEditRedo()
{

}

T100VOID T100ProjectSkeletal::OnEditCut()
{

}

T100VOID T100ProjectSkeletal::OnEditCopy()
{

}

T100VOID T100ProjectSkeletal::OnEditPaste()
{

}

T100VOID T100ProjectSkeletal::OnSearchFind()
{

}

T100VOID T100ProjectSkeletal::OnSearchReplace()
{

}

T100VOID T100ProjectSkeletal::OnCompileBuild()
{
    m_serve->Build();
}

T100VOID T100ProjectSkeletal::OnSetupEditor()
{
    m_view->ShowSetupEditorDialog();
}

T100VOID T100ProjectSkeletal::OnSetupCompiler()
{
    m_view->ShowSetupCompilerDialog();
}

T100VOID T100ProjectSkeletal::OnHelpAbout()
{
    m_view->About();
}

T100VOID T100ProjectSkeletal::OnResize()
{
    m_view->OnResize();
}

T100VOID T100ProjectSkeletal::OnQuit()
{

}

T100VOID T100ProjectSkeletal::OnFolderOpen(T100FolderData* data)
{
    T100FolderLogic&    logic       = m_serve->GetProjectServe()->GetFolderLogic();

    if(!logic.IsExists(data->GetPath())){
        return T100FALSE;
    }

    T100FolderInfo*     info        = T100NEW T100FolderInfo();

    if(!logic.Open(data->GetPath(), info)){
        return T100FALSE;
    }

    m_view->FolderOpen(info);
}

T100VOID T100ProjectSkeletal::OnItemExpanding()
{
    T100WSTRING         label;
    T100ProjectServe*   serve   = m_serve->GetProjectServe();

    if(!serve){
        return;
    }

    serve->Open(label);

    m_view->New();

}

T100VOID T100ProjectSkeletal::OnModified()
{
    m_view->SetDirty();

}

T100VOID T100ProjectSkeletal::OnProjectCreateWizardFinished()
{
    T100WxFolderInfo        info;

    m_serve->GetFolderInfo(info);

    T100ProjectInfo*        project     = T100NULL;

    if(!m_serve->GetProjectServe()->New(info)){
        return;
    }

    project = m_serve->GetProjectServe()->GetProjectInfo();
    if(!project){
        return;
    }

    m_view->ProjectOpen(project);
}
