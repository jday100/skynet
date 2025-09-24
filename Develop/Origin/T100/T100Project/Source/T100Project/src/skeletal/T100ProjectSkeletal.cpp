#include "T100ProjectSkeletal.h"

#include "T100PathTools.h"
#include "T100FileData.h"
#include "T100FolderData.h"
#include "T100ProjectData.h"
#include "T100EditorPack.h"

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
    m_view->UpdateTitle();
}

T100VOID T100ProjectSkeletal::Destroy()
{
    m_view->Destroy();
    T100SAFE_DELETE(m_serve);
    T100SAFE_DELETE(m_view);
}

T100VOID T100ProjectSkeletal::OnWorkSpaceCreate()
{
    if(m_serve->IsOpened()){
        if(WorkSpaceClose()){

        }else{
            return;
        }
    }

    m_view->ShowWorkSpaceCreateWizard();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceCreateDone(T100WorkSpaceInfo* info)
{
    if(info){
        if(m_serve->IsOpened()){
            if(WorkSpaceClose()){

            }else{
                m_view->ShowWorkSpaceCreateFailureDialog();
                return;
            }
        }

        if(WorkSpaceCreate(info)){

        }else{
            m_view->ShowWorkSpaceCreateFailureDialog();
            return;
        }

        T100WxFolderInfo        folder;

        folder.SetPath(info->GetPath());

        if(WorkSpaceOpen(&folder)){
            return;
        }
    }

    m_view->ShowWorkSpaceCreateFailureDialog();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceRemove()
{

}

T100VOID T100ProjectSkeletal::OnWorkSpaceOpen()
{
    if(m_serve->IsOpened()){
        if(WorkSpaceClose()){

        }else{
            return;
        }
    }

    T100WSTRING     path;

    if(m_view->ShowFolderDialog(path) == wxID_OK){

    }else{
        return;
    }

    T100WSTRING         folder;
    T100WSTRING         label;

    T100PathTools::Split(path, folder, label);

    T100WxFolderInfo    info;

    info.SetLabel(label);
    info.SetPath(path);

    if(WorkSpaceOpen(&info)){
        return;
    }

    m_view->ShowWorkSpaceOpenFailureDialog();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceOpenDone()
{

}

T100VOID T100ProjectSkeletal::OnWorkSpaceClose()
{
    WorkSpaceClose();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceSave()
{

}

T100VOID T100ProjectSkeletal::OnWorkSpaceSaveAs()
{

}

T100VOID T100ProjectSkeletal::OnWorkSpaceQuit()
{
    if(m_serve->IsOpened()){
        if(WorkSpaceClose()){

        }else{
            return;
        }
    }else{
        if(m_view->IsDirty()){
            T100INT     value;

            value = m_view->ShowWorkSpaceNotSaveDialog();

            if(value == wxYES){
                /*if(!WorkSpaceSave()){
                    return T100FALSE;
                }*/
            }else if(value == wxNO){

            }else if(value == wxCANCEL){
                return;
            }
        }
    }

    m_view->Quit();
}

T100VOID T100ProjectSkeletal::OnWorkSpaceMouseRightDown()
{
    m_view->ShowWorkSpacePopupMenu(m_serve->IsOpened());
}


T100VOID T100ProjectSkeletal::OnProjectCreate()
{
    m_view->ShowProjectCreateWizard();
}

T100VOID T100ProjectSkeletal::OnProjectCreateDone(T100ProjectInfo* info)
{
    if(!info){
        return;
    }

    if(ProjectCreate(info)){
        T100ProjectInfo*    project     = m_serve->GetProjectServe().GetCurrentProject();

        if(project){
            if(m_view->ProjectAppend(project)){
                return;
            }
        }
    }

    m_view->ShowProjectCreateFailureDialog();
}

T100VOID T100ProjectSkeletal::OnProjectRemove()
{

}

T100VOID T100ProjectSkeletal::OnProjectOpen(T100ProjectData* data)
{
    if(!data){
        return;
    }

    T100ProjectInfo*        info        = data->GetProjectInfo();

    if(!info){
        return;
    }

    if(info->IsOpened()){
        return;
    }

    if(m_serve->GetProjectServe().Open(info)){
        if(m_view->ProjectOpen(data->GetId(), info)){

        }
    }else{

    }
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

T100VOID T100ProjectSkeletal::OnProjectActivated()
{

}

T100VOID T100ProjectSkeletal::OnProjectSelect()
{
    m_view->ProjectSelect();
}


T100VOID T100ProjectSkeletal::OnFileCreate()
{
    FileCreate();
}

T100VOID T100ProjectSkeletal::OnFileRemove()
{
    FileRemove();
}

T100VOID T100ProjectSkeletal::OnFileOpen()
{
    FileOpen();
}

T100VOID T100ProjectSkeletal::OnFileOpenDone(T100FileData* data)
{
    if(!data){
        return;
    }

    T100FileServe&      serve   = m_serve->GetFileServe();
    T100FileInfo*       info    = data->GetFileInfo();

    if(!info){
        return;
    }

    if(serve.IsOpened(info->GetPath())){
        m_view->FileSelect(data->GetId(), info);
    }else{
        if(serve.Open(info)){
            if(m_view->FileOpen(data->GetId(), info)){
                m_view->ClearDirty();
                m_view->UpdateTitle();
            }
        }else{
            m_view->ShowFileOpenFailureDialog();
        }
    }
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
    FileSaveAs();
}

T100VOID T100ProjectSkeletal::OnFileSelect()
{
    m_view->FileSelect();
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


T100VOID T100ProjectSkeletal::OnViewWorkSpaceTree(T100BOOL value)
{
    m_view->ShowViewWorkSpaceTree(value);
}

T100VOID T100ProjectSkeletal::OnViewSearchResult(T100BOOL value)
{
    m_view->ShowViewSearchResult(value);
}

T100VOID T100ProjectSkeletal::OnViewCompileOutput(T100BOOL value)
{
    m_view->ShowViewCompileOutput(value);
}


T100VOID T100ProjectSkeletal::OnSearchFind()
{

}

T100VOID T100ProjectSkeletal::OnSearchReplace()
{

}


T100VOID T100ProjectSkeletal::OnCompileRun()
{
    T100WorkSpaceInfo*      workspace       = m_serve->GetWorkSpaceInfo();
    T100ProjectInfo*        project         = m_serve->GetProjectServe().GetCurrentProject();

    if(workspace && project){
        if(ProjectRun(workspace, project)){
            return;
        }
    }

    m_view->ShowProjectCreateFailureDialog();
}

T100VOID T100ProjectSkeletal::OnCompileBuildAndRun()
{

}

T100VOID T100ProjectSkeletal::OnCompileBuild()
{
    T100WorkSpaceInfo*      workspace   = m_serve->GetWorkSpaceInfo();
    T100ProjectInfo*        project     = m_serve->GetProjectServe().GetCurrentProject();

    if(workspace && project){
        if(ProjectBuild(workspace, project)){
            return;
        }
    }

    m_view->ShowProjectCreateFailureDialog();
}

T100VOID T100ProjectSkeletal::OnCompileClean()
{
    T100WorkSpaceInfo*      workspace   = m_serve->GetWorkSpaceInfo();
    T100ProjectInfo*        project     = m_serve->GetProjectServe().GetCurrentProject();

    if(workspace && project){
        if(ProjectClean(workspace, project)){
            return;
        }
    }
}

T100VOID T100ProjectSkeletal::OnCompileRebuild()
{

}


T100VOID T100ProjectSkeletal::OnDebugStart()
{

}

T100VOID T100ProjectSkeletal::OnDebugStop()
{

}


T100VOID T100ProjectSkeletal::OnDebugPrint(const T100WSTRING& value)
{
    m_view->DebugPrint(value);
}


T100VOID T100ProjectSkeletal::OnSetupEditor()
{

}

T100VOID T100ProjectSkeletal::OnSetupCompiler()
{
    m_view->ShowSetupCompilerDialog();
}


T100VOID T100ProjectSkeletal::OnHelpAbout()
{

}

T100VOID T100ProjectSkeletal::OnFolderList(T100FolderData* data)
{
    T100FolderInfo*     info    = data->GetFolderInfo();

    m_serve->GetFolderServe().List(info);

    m_view->FolderList(data->GetId(), info);
}

T100VOID T100ProjectSkeletal::OnMainPanelPageChanged()
{
    m_view->UpdateTitle();
}

T100VOID T100ProjectSkeletal::OnMainPanelPageClosing(T100Pack* pack)
{
    T100EditorPack*     editor      = dynamic_cast<T100EditorPack*>(pack);

    if(editor){
        if(m_serve->GetFileServe().Close(editor->GetEditor()->GetPath())){

        }
    }
}

T100VOID T100ProjectSkeletal::OnMainPanelPageClosed(T100Pack* pack)
{
    m_view->UpdateTitle();
}

T100VOID T100ProjectSkeletal::OnModified(const T100WSTRING& path)
{
    m_view->FileModified();
}

T100VOID T100ProjectSkeletal::OnModuleCreate()
{
    m_view->ShowModuleCreateDialog();
}

T100VOID T100ProjectSkeletal::OnModuleCreateDone(T100ModuleInfo* info)
{
    if(!info){
        return;
    }

    T100ProjectServe&           serve           = m_serve->GetProjectServe();
    T100WorkSpaceInfo*          workspace       = T100NULL;

    workspace   = m_serve->GetWorkSpaceInfo();

    if(!workspace){
        return;
    }

    if(serve.ModuleCreate(workspace, info)){

    }else{
        return;
    }

    if(m_view->ModuleAppend(m_serve->GetWorkSpaceInfo(), serve.GetCurrentProject(), info)){
        return;
    }
}

T100VOID T100ProjectSkeletal::OnAuiPaneClose(wxAuiPaneInfo* info)
{
    if(!info){
        return;
    }

    T100WSTRING         name;

    name    = info->name.ToStdWstring();

    if(name == L"WorkSpace"){
        m_view->ShowViewWorkSpaceTree(T100FALSE);
    }else if(name == L"CompileOutput"){
        m_view->ShowViewCompileOutput(T100FALSE);
    }else if(name == L"DebugOutput"){
        m_view->ShowViewCompileOutput(T100FALSE);
    }
}
