#include "T100ProjectSkeletalBase.h"

T100ProjectSkeletalBase::T100ProjectSkeletalBase()
{
    //ctor
}

T100ProjectSkeletalBase::~T100ProjectSkeletalBase()
{
    //dtor
}

T100BOOL T100ProjectSkeletalBase::WorkSpaceNew(T100WorkSpaceInfo* info)
{
    T100BOOL        result      = T100TRUE;

    if(!info){
        return T100FALSE;
    }

    T100WxFolderInfo        folder;

    folder.SetPath(info->GetPath());

    result  = m_serve->CheckWorkSpaceFolder(folder);

    if(!result){
        result  = m_view->ShowWorkSpaceNotExistsDialog();
        if(result){

        }else{
            return T100FALSE;
        }
    }

    result  = m_serve->Create(info);

    if(!result){
        return T100FALSE;
    }

    result  = m_serve->CheckWorkSpaceFile(folder);

    if(!result){
        result  = m_view->ShowWorkSpaceFileExistsDialog();
        if(result){

        }else{

        }
    }

    result  = m_serve->CreateWorkSpaceFile(info);

    if(!result){
        return T100FALSE;
    }

    return result;
}

T100BOOL T100ProjectSkeletalBase::WorkSpaceOpen(const T100WxFolderInfo& info)
{

}










T100BOOL T100ProjectSkeletalBase::WorkSpaceNew(const T100WxFolderInfo& info)
{
    return m_serve->New(info);
}

/*
T100VOID T100ProjectSkeletalBase::WorkSpaceOpen(const T100WxFolderInfo& folder)
{
    if(!m_serve->Open(folder)){
        return;
    }

    T100WorkSpaceInfo*      info        = T100NULL;

    info    = m_serve->GetWorkSpaceInfo();

    if(!info){
        return;
    }

    m_view->WorkSpaceOpen(info);
}
*/

T100BOOL T100ProjectSkeletalBase::WorkSpaceClose()
{
    T100BOOL        result;

    if(!m_view->WorkSpaceClose()){
        return T100FALSE;
    }

    result = m_serve->Close();

    return result;
}

T100VOID T100ProjectSkeletalBase::WorkSpaceSave()
{
    if(!m_serve->Save()){
        return;
    }

    m_view->WorkSpaceSave();
}

T100VOID T100ProjectSkeletalBase::WorkSpaceSaveAs()
{

}

T100VOID T100ProjectSkeletalBase::ProjectNew()
{
    m_view->ShowProjectCreateWizard();
}

T100VOID T100ProjectSkeletalBase::ProjectOpen()
{

}

T100VOID T100ProjectSkeletalBase::ProjectClose()
{

}

T100VOID T100ProjectSkeletalBase::ProjectSave()
{

}

T100VOID T100ProjectSkeletalBase::ProjectSaveAs()
{

}

T100VOID T100ProjectSkeletalBase::FileNew()
{

}

T100VOID T100ProjectSkeletalBase::FileOpen()
{

}

T100VOID T100ProjectSkeletalBase::FileClose()
{

}

T100VOID T100ProjectSkeletalBase::FileSave()
{

}

T100VOID T100ProjectSkeletalBase::FileSaveAs()
{

}

T100VOID T100ProjectSkeletalBase::EditUndo()
{

}

T100VOID T100ProjectSkeletalBase::EditRedo()
{

}

T100VOID T100ProjectSkeletalBase::EditCut()
{

}

T100VOID T100ProjectSkeletalBase::EditCopy()
{

}

T100VOID T100ProjectSkeletalBase::EditPaste()
{

}

T100VOID T100ProjectSkeletalBase::SearchFind()
{

}

T100VOID T100ProjectSkeletalBase::SearchReplace()
{

}

T100VOID T100ProjectSkeletalBase::CompileBuild()
{

}

T100VOID T100ProjectSkeletalBase::SetupEditor()
{

}

T100VOID T100ProjectSkeletalBase::SetupCompiler()
{

}

T100VOID T100ProjectSkeletalBase::HelpAbout()
{
    m_view->ShowAboutDialog();
}
