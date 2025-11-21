#include "data/T100DX12Frame.h"

#include "dx12/T100DX12Tools.h"
#include "core/T100DX12Studio.h"

T100DX12Frame::T100DX12Frame(T100DX12Studio* studio) :
    m_studioPtr(studio)
{
    //ctor
    init();
}

T100DX12Frame::~T100DX12Frame()
{
    //dtor
    uninit();
}

T100VOID T100DX12Frame::init()
{
    m_append    = T100FALSE;
    m_remove    = T100FALSE;
}

T100VOID T100DX12Frame::uninit()
{

}

T100VOID T100DX12Frame::SetIndex(T100UINT index)
{
    m_index = index;
}

T100UINT T100DX12Frame::GetIndex()
{
    return m_index;
}

T100VOID T100DX12Frame::Update()
{
    if(m_append){
        AppendContexts();
    }
    if(m_remove){
        RemoveContexts();
    }

    for(T100DX12Context* contextPtr : m_contexts)
    {
        contextPtr->Update();
    }
}

T100VOID T100DX12Frame::Render()
{
    FrameRender();

    for(T100DX12Context* contextPtr : m_contexts){
        contextPtr->Render();
    }
}

T100VOID T100DX12Frame::Append(T100DX12Context* contextPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    m_pendingAppends.push_back(contextPtr);
    m_append    = T100TRUE;
}

T100VOID T100DX12Frame::Remove(T100DX12Context* contextPtr)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    m_pendingRemoves.push_back(contextPtr);
    m_remove    = T100TRUE;
}

T100VOID T100DX12Frame::AppendContexts()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    for(T100DX12Context* contextPtr : m_pendingAppends)
    {
        m_contexts.push_back(contextPtr);
    }

    m_pendingAppends.clear();
}

T100VOID T100DX12Frame::RemoveContexts()
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    for(T100DX12Context* contextPtr : m_pendingRemoves)
    {
        RemoveContext(contextPtr);
    }

    m_pendingRemoves.clear();
}

T100VOID T100DX12Frame::RemoveContext(T100DX12Context* contextPtr)
{
    T100DX12_CONTEXT_VECTOR::iterator       it;

    for(it = m_contexts.begin(); it != m_contexts.end(); ++it){
        if(contextPtr == *it){
            m_contexts.erase(it);
            return;
        }
    }
}

T100VOID T100DX12Frame::FrameRender()
{
    ThrowIfFailed(m_commandAllocator->Reset());
    ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get()));

    ID3D12DescriptorHeap* ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap(),
        m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_studioPtr->m_viewport);
    m_commandList->RSSetScissorRects(1, &m_studioPtr->m_scissorRect);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart(), m_studioPtr->m_frameIndex, m_studioPtr->GetHeapManager().GetRtvHeap().GetSize());
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_studioPtr->GetHeapManager().GetDsvHeap().GetCPUStart(), m_index, m_studioPtr->GetHeapManager().GetDsvHeap().GetSize());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    const float         clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->ClearDepthStencilView(m_studioPtr->GetHeapManager().GetDsvHeap().GetCPUStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    CD3DX12_RESOURCE_BARRIER        present_barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &present_barrier);

    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

}
