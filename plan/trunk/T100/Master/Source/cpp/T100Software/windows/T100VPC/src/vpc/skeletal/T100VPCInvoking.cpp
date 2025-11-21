#include "T100VPCInvoking.h"

T100VPCFrame*           T100VPCInvoking::m_frame            = T100NULL;
T100Host*               T100VPCInvoking::m_host             = T100NULL;

T100VPCInvoking::T100VPCInvoking()
{
    //ctor
}

T100VPCInvoking::~T100VPCInvoking()
{
    //dtor
}

T100VOID T100VPCInvoking::Init(T100VPCFrame* frame)
{
    m_frame     = frame;
    m_host      = T100NEW T100Host();
}

T100VOID T100VPCInvoking::Uninit()
{
    T100SAFE_DELETE(m_host);
}

T100VOID T100VPCInvoking::OnStart()
{
    m_host->Start();
}

T100VOID T100VPCInvoking::OnStop()
{
    m_host->Stop();
}

HRESULT CALLBACK T100VPCInvoking::OnIoPortCallback(void* context, WHV_EMULATOR_IO_ACCESS_INFO* info)
{

}

HRESULT CALLBACK T100VPCInvoking::OnMemoryCallback(void* context, WHV_EMULATOR_MEMORY_ACCESS_INFO* info)
{

}

HRESULT CALLBACK T100VPCInvoking::OnGetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, WHV_REGISTER_VALUE*)
{

}

HRESULT CALLBACK T100VPCInvoking::OnSetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, const WHV_REGISTER_VALUE*)
{

}

HRESULT CALLBACK T100VPCInvoking::OnTranslateGvaPageCallback(void*, WHV_GUEST_VIRTUAL_ADDRESS, WHV_TRANSLATE_GVA_FLAGS, WHV_TRANSLATE_GVA_RESULT_CODE*, WHV_GUEST_PHYSICAL_ADDRESS*)
{

}
