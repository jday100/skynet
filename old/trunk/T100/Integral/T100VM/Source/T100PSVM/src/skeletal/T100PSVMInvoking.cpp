#include "T100PSVMInvoking.h"

T100PSVMSkeletal*       T100PSVMInvoking::m_skeletal            = T100NULL;

T100PSVMInvoking::T100PSVMInvoking()
{
    //ctor
}

T100PSVMInvoking::~T100PSVMInvoking()
{
    //dtor
}

T100VOID T100PSVMInvoking::Init(T100PSVMFrame* frame)
{
    m_skeletal      = T100NEW T100PSVMSkeletal();

    m_skeletal->Create(frame);
}

T100VOID T100PSVMInvoking::Uninit()
{
    m_skeletal->Destroy();

    T100SAFE_DELETE(m_skeletal)
}

T100VOID T100PSVMInvoking::OnFileCreate()
{
    m_skeletal->OnFileCreate();
}

T100VOID T100PSVMInvoking::OnFileOpen()
{
    m_skeletal->OnFileOpen();
}

T100VOID T100PSVMInvoking::OnFileClose()
{
    m_skeletal->OnFileClose();
}

T100VOID T100PSVMInvoking::OnFileSave()
{
    m_skeletal->OnFileSave();
}

T100VOID T100PSVMInvoking::OnFileSaveAs()
{
    m_skeletal->OnFileSaveAs();
}

T100VOID T100PSVMInvoking::OnFileQuit()
{
    m_skeletal->OnFileQuit();
}

T100VOID T100PSVMInvoking::OnVMStart()
{
    m_skeletal->OnVMStart();
}

T100VOID T100PSVMInvoking::OnVMStop()
{
    m_skeletal->OnVMStop();
}

T100VOID T100PSVMInvoking::OnDebugStart()
{
    m_skeletal->OnDebugStart();
}

T100VOID T100PSVMInvoking::OnDebugStop()
{
    m_skeletal->OnDebugStop();
}

T100VOID T100PSVMInvoking::OnHelpAbout()
{
    m_skeletal->OnHelpAbout();
}

T100VOID T100PSVMInvoking::OnLog(T100STRING value)
{
    m_skeletal->OnLog(value);
}
