#include "T100HyperVInvoking.h"

T100HyperVInvoking::T100HyperVInvoking()
{
    //ctor
}

T100HyperVInvoking::~T100HyperVInvoking()
{
    //dtor
}

HRESULT CALLBACK T100HyperVInvoking::OnIoPortCallback(void* context, WHV_EMULATOR_IO_ACCESS_INFO* info)
{

}

HRESULT CALLBACK T100HyperVInvoking::OnMemoryCallback(void* context, WHV_EMULATOR_MEMORY_ACCESS_INFO* info)
{

}

HRESULT CALLBACK T100HyperVInvoking::OnGetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, WHV_REGISTER_VALUE*)
{

}

HRESULT CALLBACK T100HyperVInvoking::OnSetRegistersCallback(void*, const WHV_REGISTER_NAME*, UINT32, const WHV_REGISTER_VALUE*)
{

}

HRESULT CALLBACK T100HyperVInvoking::OnTranslateGvaPageCallback(void*, WHV_GUEST_VIRTUAL_ADDRESS, WHV_TRANSLATE_GVA_FLAGS, WHV_TRANSLATE_GVA_RESULT_CODE*, WHV_GUEST_PHYSICAL_ADDRESS*)
{

}
