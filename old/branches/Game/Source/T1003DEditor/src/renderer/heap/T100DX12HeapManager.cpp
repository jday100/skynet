#include "T100DX12HeapManager.h"

#include "T100DX12Space.h"

T100DX12HeapManager::T100DX12HeapManager(T100DX12Space* space) :
    m_space(space),
    m_rtvHeapDispenser(this),
    m_cbvsrvHeapDispenser(this),
    m_dsvHeapDispenser(this),
    m_samplerHeapDispenser(this)
{
    //ctor
}

T100DX12HeapManager::~T100DX12HeapManager()
{
    //dtor
}

T100DX12HeapDispenser& T100DX12HeapManager::GetRtvHeap()
{
    return m_rtvHeapDispenser;
}

T100DX12HeapDispenser& T100DX12HeapManager::GetCbvSrvHeap()
{
    return m_cbvsrvHeapDispenser;
}

T100DX12HeapDispenser& T100DX12HeapManager::GetDsvHeap()
{
    return m_dsvHeapDispenser;
}

T100DX12HeapDispenser& T100DX12HeapManager::GetSamplerHeap()
{
    return m_samplerHeapDispenser;
}

T100VOID T100DX12HeapManager::Start(T100DX12Config* config)
{
    m_rtvHeapDispenser.Create(m_space->m_device.Get(), D3D12_DESCRIPTOR_HEAP_TYPE_RTV, m_space->m_frameCount);
    m_cbvsrvHeapDispenser.Create(m_space->m_device.Get(), D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, config->CbvSrvHeapSize);
    m_dsvHeapDispenser.Create(m_space->m_device.Get(), D3D12_DESCRIPTOR_HEAP_TYPE_DSV, config->DsvHeapSize);
    m_samplerHeapDispenser.Create(m_space->m_device.Get(), D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER, config->SamplerHeapSize);
}

T100VOID T100DX12HeapManager::Stop()
{

}
