#include "T100ProjectSkeletalBase.h"

T100ProjectSkeletalBase::T100ProjectSkeletalBase()
{
    //ctor
}

T100ProjectSkeletalBase::~T100ProjectSkeletalBase()
{
    //dtor
}

T100BOOL T100ProjectSkeletalBase::WorkSpaceCreate(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WxFolderInfo        folder;

    folder.SetPath(info->GetPath());

    if(m_serve->CheckWorkSpaceFolder(info->GetPath())){
        if(m_serve->CreateWorkSpace(info)){

        }else{
            return T100FALSE;
        }
    }else{
        if(m_view->ShowWorkSpaceNotExistsDialog()){

        }else{
            return T100FALSE;
        }
    }

    if(m_serve->CheckWorkSpaceFile(&folder)){

        T100INT     value   = m_view->ShowWorkSpaceFileExistsDialog();
        switch(value){
        case wxYES:
            {
                if(m_serve->CreateWorkSpaceFile(info)){

                }else{
                    return T100FALSE;
                }
            }
            break;
        case wxNO:
            {

            }
        case wxCANCEL:
            {
                return T100FALSE;
            }
            break;
        }

    }else{
        if(m_serve->CreateWorkSpaceFile(info)){

        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100ProjectSkeletalBase::WorkSpaceOpen(T100WxFolderInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    if(m_serve->CheckWorkSpaceFolder(info->GetPath())){

    }else{
        return T100FALSE;
    }

    if(m_serve->CheckWorkSpaceFile(info)){

    }else{
        m_view->ShowWorkSpaceFileNotExistsDailog();
        return T100FALSE;
    }

    if(m_serve->Create()){

    }else{
        return T100FALSE;
    }

    T100WorkSpaceInfo*      workspace       = m_serve->GetWorkSpaceInfo();

    if(workspace){
        workspace->SetLabel(info->GetLabel());
        workspace->SetPath(info->GetPath());
    }else{
        return T100FALSE;
    }

    if(m_serve->OpenWorkSpaceFile(workspace)){

    }else{
        return T100FALSE;
    }

    if(m_serve->OpenWorkSpace(workspace)){

    }else{
        return T100FALSE;
    }

    if(m_view->WorkSpaceOpen(workspace)){

    }else{
        return T100FALSE;
    }

    m_serve->SetOpened(T100TRUE);
    return T100TRUE;
}

T100BOOL T100ProjectSkeletalBase::WorkSpaceClose()
{
    T100BOOL        result;

    if(m_view->IsDirty()){
        T100INT     value;

        value = m_view->ShowWorkSpaceNotSaveDialog();

        if(value == wxID_YES){
            if(!WorkSpaceSave()){
                return T100FALSE;
            }
        }else if(value == wxID_NO){

        }else if(value == wxID_CANCEL){
            return TRUE;
        }
    }

    result  = m_view->WorkSpaceClose();

    if(result){
        result  = m_serve->CloseWorkSpace();
        if(result){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100ProjectSkeletalBase::WorkSpaceSave()
{
    return T100TRUE;
}

T100BOOL T100ProjectSkeletalBase::ProjectCreate(T100ProjectInfo* info)
{
    T100WorkSpaceInfo*      workspace       = m_serve->GetWorkSpaceInfo();

    if(workspace && info){

    }else{
        return T100FALSE;
    }

    if(m_serve->GetProjectServe().Create(m_serve->GetWorkSpaceInfo(), info)){

    }else{
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100ProjectSkeletalBase::ProjectBuild(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){

    }else{
        return T100FALSE;
    }

    if(m_serve->GetProjectServe().Build(workspace, project)){
        m_view->ProjectBuild();
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectSkeletalBase::ProjectRun(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){

    }else{
        return T100FALSE;
    }

    if(m_serve->GetProjectServe().Run(workspace, project)){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectSkeletalBase::ProjectClean(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){

    }else{
        return T100FALSE;
    }

    if(m_serve->GetProjectServe().Clean(workspace, project)){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ProjectSkeletalBase::FileCreate()
{
    T100FileInfo*   info        = m_serve->GetFileServe().Create();

    if(!info){
        return T100FALSE;
    }


    if(m_view->FileOpen(info)){

    }

}

T100BOOL T100ProjectSkeletalBase::FileRemove()
{
    T100WSTRING         path    = m_view->GetCurrentFilePath();

    if(path.empty()){
        return T100FALSE;
    }

    T100FileInfo*       info    = m_serve->GetFileServe().GetFileInfo(path);

    if(info){

    }else{
        return T100FALSE;
    }

    wxTreeItemId        id      = m_view->GetSelection();

    if(id.IsOk()){

    }else{
        return T100FALSE;
    }

    m_view->FileRemove(id, info);
}

T100BOOL T100ProjectSkeletalBase::FileOpen()
{
    T100WxFileInfo          file;

    if(m_view->ShowFileNameDialog(file) == wxID_OK){
        T100FileServe&      serve       = m_serve->GetFileServe();
        T100FileInfo*       info        = T100NULL;

        if(serve.IsOpened(file.GetPath())){
            m_view->FileSelect(serve.GetFileInfo(file.GetPath()));
        }else{
            if(serve.Open(file)){
                if(m_view->FileOpen(serve.GetFileInfo(file.GetPath()))){

                }
            }
        }
    }
}

T100BOOL T100ProjectSkeletalBase::FileSaveAs()
{
    T100WxFileInfo          file;

    if(m_view->ShowFileNameDialog(file) == wxID_OK){

    }else{
        return T100TRUE;
    }

    m_view->FileSaveAs(&file);
}
