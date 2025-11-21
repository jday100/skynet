#include "heap/T100DX12HeapDispenser.h"

#include "dx12/T100DX12Tools.h"

T100DX12HeapDispenser::T100DX12HeapDispenser(T100DX12HeapManager* manager) :
    m_manager(manager),
    m_heap()
{
    //ctor
    init();
}

T100DX12HeapDispenser::~T100DX12HeapDispenser()
{
    //dtor
    uninit();
}

T100VOID T100DX12HeapDispenser::init()
{
    m_top   = 0;
}

T100VOID T100DX12HeapDispenser::uninit()
{

}

T100VOID T100DX12HeapDispenser::Create(ID3D12Device* device, D3D12_DESCRIPTOR_HEAP_TYPE type, T100UINT length)
{
    switch(type){
    case D3D12_DESCRIPTOR_HEAP_TYPE_RTV:
        {
            CreateRtvHeap(device, m_heap, length);
        }
        break;
    case D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV:
        {
            CreateCbvSrvHeap(device, m_heap, length);
        }
        break;
    case D3D12_DESCRIPTOR_HEAP_TYPE_DSV:
        {
            CreateDsvHeap(device, m_heap, length);
        }
        break;
    case D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER:
        {
            CreateSamplerHeap(device, m_heap, length);
        }
        break;
    }
    m_heap.m_length = length;
    m_current       = CD3DX12_CPU_DESCRIPTOR_HANDLE(m_heap.m_heap->GetCPUDescriptorHandleForHeapStart());
}

T100VOID T100DX12HeapDispenser::Destroy()
{

}

ID3D12DescriptorHeap* T100DX12HeapDispenser::GetHeap()
{
    return m_heap.GetHeap().Get();
}

T100UINT T100DX12HeapDispenser::GetSize()
{
    return m_heap.m_size;
}

T100UINT T100DX12HeapDispenser::GetTop()
{
    T100UINT    value   = m_top;
    return m_top;
}

CD3DX12_CPU_DESCRIPTOR_HANDLE T100DX12HeapDispenser::Get(UINT length)
{
    if(m_top + length > m_heap.m_length){
        throw std::exception();
    }

    CD3DX12_CPU_DESCRIPTOR_HANDLE   result      = m_current;

    m_current   = CD3DX12_CPU_DESCRIPTOR_HANDLE(m_current, length, m_heap.m_size);
    m_top       += length;
    return result;
}

CD3DX12_CPU_DESCRIPTOR_HANDLE T100DX12HeapDispenser::GetCPUStart()
{
    return CD3DX12_CPU_DESCRIPTOR_HANDLE(m_heap.m_heap->GetCPUDescriptorHandleForHeapStart());
}

CD3DX12_GPU_DESCRIPTOR_HANDLE T100DX12HeapDispenser::GetGPUStart()
{
    return CD3DX12_GPU_DESCRIPTOR_HANDLE(m_heap.m_heap->GetGPUDescriptorHandleForHeapStart());
}

T100VOID T100DX12HeapDispenser::CreateRtvHeap(ID3D12Device* device, T100DX12Heap& heap, UINT length)
{
    D3D12_DESCRIPTOR_HEAP_DESC      rtvHeapDesc = {};

    rtvHeapDesc.NumDescriptors      = length;
    rtvHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&heap.m_heap)));
    heap.m_size = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
}

T100VOID T100DX12HeapDispenser::CreateCbvSrvHeap(ID3D12Device* device, T100DX12Heap& heap, UINT length)
{
    D3D12_DESCRIPTOR_HEAP_DESC      cbvSrvHeapDesc      = {};

    cbvSrvHeapDesc.NumDescriptors   = length;

    cbvSrvHeapDesc.Type             = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    cbvSrvHeapDesc.Flags            = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(device->CreateDescriptorHeap(&cbvSrvHeapDesc, IID_PPV_ARGS(&heap.m_heap)));
    heap.m_size = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
}

T100VOID T100DX12HeapDispenser::CreateDsvHeap(ID3D12Device* device, T100DX12Heap& heap, UINT length)
{
    D3D12_DESCRIPTOR_HEAP_DESC          dsvHeapDesc     = {};

    dsvHeapDesc.NumDescriptors      = length;
    dsvHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(&heap.m_heap)));
}

T100VOID T100DX12HeapDispenser::CreateSamplerHeap(ID3D12Device* device, T100DX12Heap& heap, UINT length)
{
    D3D12_DESCRIPTOR_HEAP_DESC      samplerHeapDesc      = {};

    samplerHeapDesc.NumDescriptors  = length;
    samplerHeapDesc.Type            = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    samplerHeapDesc.Flags           = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(device->CreateDescriptorHeap(&samplerHeapDesc, IID_PPV_ARGS(&heap.m_heap)));
}
