#include "T100PSVMSkeletal.h"

T100PSVMSkeletal::T100PSVMSkeletal() :
    T100PSVMSkeletalBase()
{
    //ctor
}

T100PSVMSkeletal::~T100PSVMSkeletal()
{
    //dtor
}

T100VOID T100PSVMSkeletal::Create(T100PSVMFrame* frame)
{
    m_view      = T100NEW T100PSVMView();
    m_serve     = T100NEW T100PSVMServe();
    m_store     = T100NEW T100PSVMStore();

    m_view->Create(frame);
}

T100VOID T100PSVMSkeletal::Destroy()
{
    m_view->Destroy();

    T100SAFE_DELETE(m_store)
    T100SAFE_DELETE(m_serve)
    T100SAFE_DELETE(m_view)
}

T100VOID T100PSVMSkeletal::OnFileCreate()
{
    T100PSVMInfo*       info        = T100NULL;

    if(m_serve->IsOpened()){
        if(!FileClose()){
            m_view->ShowCreateFailureDialog();
            return;
        }
    }

    if(m_serve->Create(info)){
        if(m_view->ShowCreateDialog(info)){
            if(m_serve->Open(info)){
                if(m_view->Create(info)){
                    return;
                }
            }
        }else{
            T100SAFE_DELETE(info)
            return;
        }
        T100SAFE_DELETE(info)
    }
    m_view->ShowCreateFailureDialog();
}

T100VOID T100PSVMSkeletal::OnFileOpen()
{
    if(m_serve->IsOpened()){
        if(!FileClose()){
            m_view->ShowOpenFailureDialog();
            return;
        }
    }

    T100WxFileInfo*     file    = T100NEW T100WxFileInfo();
    T100PSVMInfo*       info    = T100NULL;

    if(m_view->ShowFileOpenDialog(file)){
        if(m_serve->Create(info)){
            if(m_store->Load(file, info)){
                if(m_serve->Open(info)){
                    if(m_view->Open(info)){
                        return;
                    }
                }
            }
            T100SAFE_DELETE(info)
        }
    }else{
        T100SAFE_DELETE(file)
        return;
    }
    T100SAFE_DELETE(file)
    m_view->ShowOpenFailureDialog();
}

T100VOID T100PSVMSkeletal::OnFileClose()
{
    if(m_serve->IsOpened()){
        if(FileClose()){
            return;
        }
    }
    m_view->ShowCloseFailureDialog();
}

T100VOID T100PSVMSkeletal::OnFileSave()
{
    if(m_serve->IsOpened()){
        T100WxFileInfo*     file    = m_store->GetFile();

        if(file){
            if(FileSave()){
                return;
            }
        }else{
            if(FileSaveAs()){
                return;
            }
        }
    }
}

T100VOID T100PSVMSkeletal::OnFileSaveAs()
{

}

T100VOID T100PSVMSkeletal::OnFileQuit()
{

}

T100VOID T100PSVMSkeletal::OnVMStart()
{
    if(m_serve->IsOpened()){
        if(m_serve->GetVMServe().Start()){
            if(m_view->Start()){
                return;
            }
        }
    }
    m_view->ShowVMStartFailureDialog();
}

T100VOID T100PSVMSkeletal::OnVMStop()
{

}

T100VOID T100PSVMSkeletal::OnDebugStart()
{
    if(m_serve->IsOpened()){
        if(m_serve->GetVMServe().DebugStart()){
            if(m_view->DebugStart(m_serve->GetVMServe().GetVM())){
                return;
            }
        }
    }
    m_view->ShowVMStartFailureDialog();
}

T100VOID T100PSVMSkeletal::OnDebugStop()
{

}

T100VOID T100PSVMSkeletal::OnHelpAbout()
{

}

T100VOID T100PSVMSkeletal::OnLog(T100STRING& value)
{
    m_view->Log(value);
}
