#include "T100PSVMSkeletalBase.h"

T100PSVMSkeletalBase::T100PSVMSkeletalBase()
{
    //ctor
}

T100PSVMSkeletalBase::~T100PSVMSkeletalBase()
{
    //dtor
}

T100BOOL T100PSVMSkeletalBase::FileClose()
{
    if(m_serve->IsOpened()){
        if(m_serve->IsDirty()){
            if(!FileSave()){
                return T100FALSE;
            }
        }
        if(m_serve->Close()){
            if(m_view->Close()){
                return T100TRUE;
            }
        }
    }
    return T100FALSE;
}

T100BOOL T100PSVMSkeletalBase::FileSave()
{
    T100WxFileInfo*     file    = m_store->GetFile();
    T100PSVMInfo*       info    = m_serve->GetPSVMInfo();

    if(file && info){
        if(m_store->Save(file, info)){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100PSVMSkeletalBase::FileSaveAs()
{
    T100WxFileInfo*     file    = T100NEW T100WxFileInfo();

    if(m_view->ShowFileSaveDialog(file)){
        T100PSVMInfo*   info    = m_serve->GetPSVMInfo();

        if(info){
            if(m_store->Save(file, info)){
                if(m_view->SaveAs()){
                    return T100TRUE;
                }
            }
        }
    }else{
        T100SAFE_DELETE(file)
        return T100TRUE;
    }
    T100SAFE_DELETE(file)
    return T100FALSE;
}
