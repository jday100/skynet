#include "T100ProjectSkeletal.h"

#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include "T100PathTools.h"
#include "T100ProjectMain.h"
#include "T100WxFolderInfo.h"

#include "T100FileData.h"
#include "T100FolderData.h"
#include "T100ProjectData.h"
#include "T100WxProjectInfo.h"

#include "T100EditorPack.h"

#include "T100ProjectConfig.h"
#include "T100DebugTools.h"

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
    T100BOOL        result      = T100TRUE;

    if(m_serve->IsOpened()){
        result  = WorkSpaceClose();
    }

    if(!result){
        return;
    }

    T100WorkSpaceInfo*      info        = T100NEW T100WorkSpaceInfo();

    if(!m_view->ShowWorkSpaceCreateDialog(info)){
        return;
    }

    if(!WorkSpaceNew(info)){
        T100SAFE_DELETE(info);
        return;
    }

    T100WxFolderInfo        folder;

    folder.SetPath(info->GetPath());
    T100SAFE_DELETE(info);

    if(!WorkSpaceOpen(folder)){
        return;
    }
}

T100VOID T100ProjectSkeletal::OnWorkSpaceOpen()
{
    T100BOOL        result      = T100TRUE;

    if(m_serve->IsOpened()){
        result  = WorkSpaceClose();
    }

    if(!result){
        return;
    }

    T100WSTRING         path;

    if(m_view->ShowDirDialog(path) == wxID_OK){

    }else{
        return;
    }

    T100WSTRING         folder;
    T100WSTRING         label;

    T100PathTools::Split(path, folder, label);

    T100WxFolderInfo    info;

    info.SetLabel(label);
    info.SetPath(path);

    if(WorkSpaceOpen(info)){
        return;
    }

    m_view->ShowWorkSpaceOpenFailureDialog();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceClose()
{
    if(m_serve->IsOpened()){

    }else{
        return;
    }

    WorkSpaceClose();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceSave()
{
    if(m_serve->IsOpened()){

    }else{
        return;
    }

    WorkSpaceSave();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceSaveAs()
{
    if(m_serve->IsOpened()){

    }else{
        return;
    }

    WorkSpaceSaveAs();
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

    info->SetLabel(L"unnamed");

    m_view->FileOpen(0, info);
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

    m_view->FileOpen(0, info);
}

T100VOID T100ProjectSkeletal::OnFileClose()
{

}

T100VOID T100ProjectSkeletal::OnFileSave()
{
    m_view->FileSave();
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

T100VOID T100ProjectSkeletal::OnCompileRun()
{
    m_serve->Run();
}

T100VOID T100ProjectSkeletal::OnCompileBuildAndRun()
{
    //m_serve->Build();
}

T100VOID T100ProjectSkeletal::OnCompileClean()
{
    //m_serve->Clean();
}

T100VOID T100ProjectSkeletal::OnCompileBuild()
{
    m_serve->Build();
    m_view->Build();
}

T100VOID T100ProjectSkeletal::OnCompileRebuild()
{
    //m_serve->Rebuild();
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

T100VOID T100ProjectSkeletal::OnWorkSpaceProperties()
{
    m_view->ShowWorkSpacePropertiesDialog();
}

T100VOID T100ProjectSkeletal::OnFolderNew()
{

}

T100VOID T100ProjectSkeletal::OnFolderSelect()
{
    m_view->FolderSelect();
}

T100VOID T100ProjectSkeletal::OnModuleNew()
{
    m_view->ShowModuleCreateDialog();
}

T100VOID T100ProjectSkeletal::OnModuleNew(T100ModuleInfo* info)
{
    if(!info){
        return;
    }

    T100ProjectLogic&       logic       = m_serve->GetProjectServe()->GetProjectLogic();

    if(logic.CreateModule(info)){

    }else{
        return;
    }

    m_view->AppendModule(m_serve->GetWorkSpaceInfo(), m_serve->GetProjectServe()->GetProjectInfo(), info);
}

T100VOID T100ProjectSkeletal::OnFileOpen(T100FileData* data)
{
    if(!data){
        return;
    }

    T100FileLogic&      logic       = m_serve->GetProjectServe()->GetFileLogic();
    T100FileInfo*       info        = data->GetFileInfo();

    if(!info){
        return;
    }

    if(!logic.IsExists(info->GetPath())){
        return;
    }

    if(!logic.Open(info->GetPath(), info)){
        return;
    }

    m_view->FileOpen(data->GetId(), info);
}

T100VOID T100ProjectSkeletal::OnFolderOpen(T100FolderData* data)
{
    T100FolderLogic&    logic       = m_serve->GetProjectServe()->GetFolderLogic();

    if(!logic.IsExists(data->GetFolderInfo()->GetPath())){
        return T100FALSE;
    }

    T100FolderInfo*     info        = T100NEW T100FolderInfo();

    if(!logic.List(data->GetFolderInfo()->GetPath(), info)){
        T100SAFE_DELETE(info);
        return T100FALSE;
    }

    m_view->FolderOpen(data->GetId(), info);
}

T100VOID T100ProjectSkeletal::OnProjectOpen(T100ProjectData* data)
{
    if(!data){
        return;
    }

    T100ProjectInfo*        info    = data->GetProjectInfo();

    if(!info){
        return;
    }

    if(info->IsOpened()){
        return;
    }

    T100ProjectLogic&       logic       = m_serve->GetProjectServe()->GetProjectLogic();

    if(!logic.Open(info->GetPath(), info)){
        return T100FALSE;
    }

    m_view->ProjectOpen(data->GetId(), info);
}

T100VOID T100ProjectSkeletal::OnProjectSelect()
{
    m_view->ProjectSelect();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceSelect()
{
    m_view->WorkSpaceSelect();
}

T100VOID T100ProjectSkeletal::OnPageChanged()
{
    m_view->PageChanged();
}

T100VOID T100ProjectSkeletal::OnPageClosing(T100Pack* pack)
{
    T100EditorPack*     editor      = dynamic_cast<T100EditorPack*>(pack);

    if(editor){
        m_serve->GetProjectServe()->GetFileLogic().Close(editor->GetEditor()->GetPath());
    }

    m_view->FileClose(pack);
}

T100VOID T100ProjectSkeletal::OnPageClosed(T100Pack* pack)
{
    m_view->PageClose(pack);
}

T100VOID T100ProjectSkeletal::OnItemExpanding()
{
    /*
    T100WSTRING         label;
    T100ProjectServe*   serve   = m_serve->GetProjectServe();

    if(!serve){
        return;
    }

    serve->Open(label);

    m_view->New();
    */
}

T100VOID T100ProjectSkeletal::OnModified(const T100WSTRING& path)
{
    m_view->SetDirty();

    m_view->FileModified(path);

}

T100VOID T100ProjectSkeletal::OnProjectCreateWizardFinished(T100WxProjectInfo* info)
{
    T100DebugTools::Print(L"T100ProjectSkeletal::OnProjectCreateWizardFinished(T100WxProjectInfo*)...");
    T100WxFolderInfo        folder;

    m_serve->GetFolderInfo(folder);

    T100WorkSpaceInfo*      workspace   = T100NULL;
    T100ProjectInfo*        project     = T100NULL;

    T100WSTRING     path    = folder.GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + info->GetLabel();

    folder.SetLabel(info->GetLabel());
    folder.SetPath(path);

    if(!m_serve->GetProjectServe()->New(folder, m_serve->GetWorkSpaceInfo())){
        return;
    }

    workspace   = m_serve->GetWorkSpaceInfo();

    project     = T100NEW T100ProjectInfo();

    project->SetLabel(info->GetLabel());
    project->SetPath(workspace->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + info->GetLabel());

    //ProjectAppend(project);

    m_view->ProjectAppend(project);
}

T100VOID T100ProjectSkeletal::OnBuildMessage(const T100WSTRING& value)
{
    m_view->AppendBuildMessage(value);
}
