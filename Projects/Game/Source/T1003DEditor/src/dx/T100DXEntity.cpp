#include "T100DXEntity.h"

#include "T100DX12Tools.h"

T100DXEntity::T100DXEntity()
    :T100DXBase(),
    m_entity_manager(this),
    m_pCurrentFrameResource(T100NULL),
    m_currentFrameResourceIndex(0),
    m_cbvSrvDescriptorSize(0),
    m_numIndices(0)
{
    //ctor
}

T100DXEntity::~T100DXEntity()
{
    //dtor
}

T100VOID T100DXEntity::Start()
{
    if(m_entity_manager.Empty())
    {
        T100DXBase::Start();
    }
    else
    {
        LoadPipeline();
        LoadAssets();
    }
}

T100VOID T100DXEntity::Update()
{
    if(m_entity_manager.Empty())
    {

    }
    else
    {
        UpdateFrameTimer();
        UpdateFence();
        UpdateCamera();
        UpdateFrameResource();
    }
}

T100VOID T100DXEntity::Render()
{
    if(m_entity_manager.Empty())
    {
        T100DXBase::Render();
    }
    else
    {
        PopulateCommandList(T100TRUE, m_pCurrentFrameResource);
        ExecuteCommandList();
        SwapChainPresent();
        FenceSignal();
    }
}

T100VOID T100DXEntity::Append(T100Entity* entity)
{
    m_entity_manager.Append(entity);
}

T100VOID T100DXEntity::LoadPipeline()
{
    CreateFactory();
    CreateDevice();
    CreateCommandQueue();
    CreateSwapChain();
    CreateRtvHeap();
    CreateDsvHeap();
    CreateCbvHeap(0, 0);
    CreateSamplerHeap();
    CreateCommandAllocator();
}

T100VOID T100DXEntity::LoadAssets()
{

}

T100VOID T100DXEntity::CreateDsvHeap()
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

T100VOID T100DXEntity::CreateCbvHeap(UINT row, UINT column)
{
    D3D12_DESCRIPTOR_HEAP_DESC          cbvSrvHeapDesc      = {};

    cbvSrvHeapDesc.NumDescriptors       =
        m_frameCount * row * column
        + 1;
    cbvSrvHeapDesc.Type                 = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    cbvSrvHeapDesc.Flags                = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &cbvSrvHeapDesc,
                                                 IID_PPV_ARGS(&m_cbvSrvHeap)
                                                 ));
    m_cbvSrvDescriptorSize      = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
}

T100VOID T100DXEntity::CreateSamplerHeap()
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

T100VOID T100DXEntity::UpdateFrameTimer()
{

}

T100VOID T100DXEntity::UpdateFence()
{

}

T100VOID T100DXEntity::UpdateCamera()
{

}

T100VOID T100DXEntity::UpdateFrameResource()
{

}

T100VOID T100DXEntity::PopulateCommandList(T100BOOL useBundles, T100DXFrameResource* pFrameResource)
{
    ThrowIfFailed(m_pCurrentFrameResource->m_commandAllocator->Reset());

    ThrowIfFailed(m_commandList->Reset(m_pCurrentFrameResource->m_commandAllocator.Get(), m_pipelineState1.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = { m_cbvSrvHeap.Get(), m_samplerHeap.Get() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_viewport);
    m_commandList->RSSetScissorRects(1, &m_scissorRect);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    const float         clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->ClearDepthStencilView(m_dsvHeap->GetCPUDescriptorHandleForHeapStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    if (useBundles)
    {
        m_commandList->ExecuteBundle(pFrameResource->m_bundle.Get());
    }
    else
    {
        pFrameResource->PopulateCommandList(m_commandList.Get(), m_pipelineState1.Get(), m_pipelineState2.Get(), m_currentFrameResourceIndex, m_numIndices, &m_indexBufferView,
            &m_vertexBufferView, m_cbvSrvHeap.Get(), m_cbvSrvDescriptorSize, m_samplerHeap.Get(), m_rootSignature.Get());
    }

    CD3DX12_RESOURCE_BARRIER        present_barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &present_barrier);

    ThrowIfFailed(m_commandList->Close());
}

T100VOID T100DXEntity::ExecuteCommandList()
{
    ID3D12CommandList* ppCommandLists[] = {m_commandList.Get()};
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
}

T100VOID T100DXEntity::SwapChainPresent()
{
    ThrowIfFailed(m_swapChain->Present(1, 0));
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
}

T100VOID T100DXEntity::FenceSignal()
{
    m_pCurrentFrameResource->m_fenceValue = m_fenceValue;
    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), m_fenceValue));
    m_fenceValue++;
}

