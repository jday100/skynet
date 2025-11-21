#include "frame/T100DX12FrameManager.h"

#include "dx12/T100DX12Tools.h"
#include "core/T100DX12Studio.h"

T100DX12FrameManager::T100DX12FrameManager(T100DX12Studio* studio) :
    m_studioPtr(studio),
    m_frames()
{
    //ctor
}

T100DX12FrameManager::~T100DX12FrameManager()
{
    //dtor
}

T100VOID T100DX12FrameManager::Create()
{
    for(T100UINT i = 0; i < m_studioPtr->GetFrameCount(); i++){
        T100DX12Frame*  frame   = T100NEW T100DX12Frame(m_studioPtr);

        frame->SetIndex(i);

        m_frames.push_back(frame);
    }

    m_currentPtr    = m_frames[m_frameIndex];
}

T100VOID T100DX12FrameManager::Destroy()
{
    for(T100DX12Frame* frame : m_frames){
        T100SAFE_DELETE frame;
    }
    m_frames.clear();
}

T100VOID T100DX12FrameManager::Start()
{
    for(T100DX12Frame* framePtr : m_frames){
        CreateCommandAllocator(framePtr);
        CreateAndCloseCommandList(framePtr);
    }
}

T100VOID T100DX12FrameManager::Stop()
{

}

T100VOID T100DX12FrameManager::Update()
{
    const UINT64 lastCompletedFence = m_studioPtr->m_fence->GetCompletedValue();

    m_frameIndex    = (m_studioPtr->m_frameIndex + 1) % m_studioPtr->m_frameCount;
    m_currentPtr    = m_frames[m_frameIndex];

    if(m_currentPtr->m_fenceValue != 0 && m_currentPtr->m_fenceValue > lastCompletedFence){
        ThrowIfFailed(m_studioPtr->m_fence->SetEventOnCompletion(m_currentPtr->m_fenceValue, m_studioPtr->m_fenceEvent));
        WaitForSingleObject(m_studioPtr->m_fenceEvent, INFINITE);
    }

    m_currentPtr->Update();
}

T100VOID T100DX12FrameManager::Render()
{
    m_currentPtr->Render();
}

T100VOID T100DX12FrameManager::Append(T100DX12Mesh* meshPtr)
{
    for(T100DX12Frame* framePtr : m_frames){
        T100DX12Context*    contextPtr      = T100NULL;

        contextPtr  = m_studioPtr->GetContextManager().Convert(framePtr, meshPtr);

        meshPtr->Append(contextPtr);
        framePtr->Append(contextPtr);
    }
}

T100VOID T100DX12FrameManager::Remove(T100DX12Mesh* mesh)
{

}

T100VOID T100DX12FrameManager::CreateCommandAllocator(T100DX12Frame* framePtr)
{
    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&framePtr->m_commandAllocator)));
}

T100VOID T100DX12FrameManager::CreateAndCloseCommandList(T100DX12Frame* framePtr)
{
    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, framePtr->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&framePtr->m_commandList)));
    ThrowIfFailed(framePtr->m_commandList->Close());
}
