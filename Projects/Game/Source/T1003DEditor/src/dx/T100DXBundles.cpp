#include "T100DXBundles.h"

#include "T100DX12Tools.h"

T100DXBundles::T100DXBundles()
    :T100DXBase()
{
    //ctor
}

T100DXBundles::~T100DXBundles()
{
    //dtor
}

T100VOID T100DXBundles::CreateRtvHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          rtvHeapDesc         = {};

    rtvHeapDesc.NumDescriptors          = m_frameCount;
    rtvHeapDesc.Type                    = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags                   = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &rtvHeapDesc,
                                                 IID_PPV_ARGS(&m_rtvHeap)
                                                 ));
    m_rtvDescriptorSize     = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
}

T100VOID T100DXBundles::CreateDsvHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          dsvHeapDesc         = {};

    dsvHeapDesc.NumDescriptors          = 1;
    dsvHeapDesc.Type                    = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags                   = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &dsvHeapDesc,
                                                 IID_PPV_ARGS(&m_dsvHeap)
                                                 ));
}

T100VOID T100DXBundles::CreateCbvHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          cbvSrvHeapDesc      = {};

    cbvSrvHeapDesc.NumDescriptors       =
        m_frameCount * m_cityRowCount * m_cityColumnCount
        + 1;
    cbvSrvHeapDesc.Type                 = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    cbvSrvHeapDesc.Flags                = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &cbvSrvHeapDesc,
                                                 IID_PPV_ARGS(&m_cbvSrvHeap)
                                                 ));
    m_cbvSrvDescriptorSize      = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
}

T100VOID T100DXBundles::CreateSamplerHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          samplerHeapDesc     = {};

    samplerHeapDesc.NumDescriptors      = 1;
    samplerHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    samplerHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &samplerHeapDesc,
                                                 IID_PPV_ARGS(&m_samplerHeap)
                                                 ));

}
