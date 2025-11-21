#include "T100DiagramSkeletalBase.h"

T100DiagramSkeletalBase::T100DiagramSkeletalBase()
{
    //ctor
}

T100DiagramSkeletalBase::~T100DiagramSkeletalBase()
{
    //dtor
}

T100BOOL T100DiagramSkeletalBase::FileCreate()
{
    if(m_serve->Create()){
        if(m_view->Create()){
            T100DiagramInfo*        info        = T100NULL;
            info = m_serve->GetDiagramInfo();
            if(info){
                if(m_view->Open(info)){
                    return T100TRUE;
                }
            }
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramSkeletalBase::FileOpen()
{
    T100WSTRING             path;
    T100DiagramInfo*        info    = T100NULL;

    if(m_view->ShowOpenFileDialog(path)){
        if(m_store->Load(path, info)){
            if(m_serve->Open(info)){
                if(m_view->Open(info)){
                    return T100TRUE;
                }
            }
            T100SAFE_DELETE(info)
        }
    }else{
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramSkeletalBase::FileClose()
{
    if(m_serve->Close()){
        if(m_view->Close()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramSkeletalBase::FileSave()
{
    T100WSTRING             path;
    T100DiagramInfo*        info    = T100NULL;

    info    = m_serve->GetDiagramInfo();

    if(!info){
        return T100FALSE;
    }

    path    = info->GetPath();

    if(path.empty()){
        if(m_view->ShowSaveFileDialog(path)){
            if(path.empty()){
                return T100FALSE;
            }
            info->SetPath(path);
        }else{
            return T100TRUE;
        }
    }

    if(m_store->Save(path, info)){
        if(m_view->Save()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramSkeletalBase::FileSaveAs()
{
    T100WSTRING             path;
    T100DiagramInfo*        info    = T100NULL;

    info    = m_serve->GetDiagramInfo();

    if(!info){
        return T100FALSE;
    }

    if(m_view->ShowSaveFileDialog(path)){
        if(path.empty()){
            return T100FALSE;
        }
        info->SetPath(path);
    }else{
        return T100TRUE;
    }

    if(m_store->Save(path, info)){
        if(m_view->Save()){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramSkeletalBase::FileQuit()
{
    m_view->Quit();
    return T100TRUE;
}
