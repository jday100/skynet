#include "T100DX12FrameManager.h"

#include <iostream>
#include "T100Debug.h"
#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

T100DX12FrameManager::T100DX12FrameManager(T100DX12Studio* studio) :
    m_studio(studio),
    m_currentFrameResourceIndex(0)
{
    //ctor
}

T100DX12FrameManager::~T100DX12FrameManager()
{
    //dtor
}

T100DX12Frame* T100DX12FrameManager::GetCurrentFrame()
{
    return m_current;
}

T100VOID T100DX12FrameManager::Start()
{
    FrameManagerStart();
}

T100VOID T100DX12FrameManager::Stop()
{
    FrameManagerStop();
}

T100VOID T100DX12FrameManager::Update()
{
    FrameManagerUpdate();
}

T100VOID T100DX12FrameManager::Render()
{
    FrameManagerRender();
}

T100VOID T100DX12FrameManager::Append(T100DX12Model* model)
{
    ContextAppend(model);
}

T100VOID T100DX12FrameManager::Remove(T100DX12Model* model)
{
    FrameManagerRemove(model);
}

T100VOID T100DX12FrameManager::CreateFrames()
{
    for(UINT i = 0; i < m_studio->m_frameCount; i++)
    {
        T100DX12Frame*      frame   = T100NEW T100DX12Frame();

        frame->m_currentFrameResourceIndex   = i;

        m_frames.push_back(frame);
    }

    m_current   = m_frames[0];
    m_back      = m_frames[1];
}

T100VOID T100DX12FrameManager::CreateCommandAllocators()
{
    for(T100DX12Frame* frame : m_frames)
    {
        ThrowIfFailed(m_studio->m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&frame->m_commandAllocator)));
        CreateAndCloseCommandList(frame);
    }
}

T100VOID T100DX12FrameManager::FrameManagerStart()
{
    CreateFrames();
}

T100VOID T100DX12FrameManager::FrameManagerStop()
{

}

T100VOID T100DX12FrameManager::FrameManagerUpdate()
{
    //DEBUGPRINT("Update...");

    m_studio->m_timer.Tick(NULL);

    if (m_frameCounter == 500)
    {
        wchar_t         fps[64];
        swprintf_s(fps, L"%ufps", m_studio->m_timer.GetFramesPerSecond());
        SetCustomWindowText(fps);
        m_frameCounter = 0;
    }

    m_frameCounter++;

    const UINT64        lastCompletedFence  = m_studio->m_fence->GetCompletedValue();

    m_currentFrameResourceIndex             = (m_currentFrameResourceIndex + 1) % m_studio->m_frameCount;
    m_current                               = m_frames[m_currentFrameResourceIndex];

    if (m_current->m_fenceValue != 0 && m_current->m_fenceValue > lastCompletedFence)
    {
        ThrowIfFailed(m_studio->m_fence->SetEventOnCompletion(m_current->m_fenceValue, m_studio->m_fenceEvent));
        WaitForSingleObject(m_studio->m_fenceEvent, INFINITE);
    }

    m_studio->m_camera.Update(static_cast<float>(m_studio->m_timer.GetElapsedSeconds()));

    m_current->Update(m_studio);
}

T100VOID T100DX12FrameManager::FrameManagerRender()
{
    //DEBUGPRINT("Render...");

    PopulateCommandList(m_current);

    ThrowIfFailed(m_studio->m_swapChain->Present(1, 0));
    m_studio->m_frameIndex = m_studio->m_swapChain->GetCurrentBackBufferIndex();

    m_current->m_fenceValue = m_studio->m_fenceValue;
    ThrowIfFailed(m_studio->m_commandQueue->Signal(m_studio->m_fence.Get(), m_studio->m_fenceValue));
    m_studio->m_fenceValue++;
}

T100VOID T100DX12FrameManager::FrameManagerAppend(T100DX12Model* model)
{

}

T100VOID T100DX12FrameManager::FrameManagerRemove(T100DX12Model* model)
{
    for(T100DX12Context* context : model->m_contexts)
    {
        T100DX12Frame*  frame   = m_frames[context->m_frameIndex];
        frame->Remove(context);
    }

}

T100VOID T100DX12FrameManager::ContextAppend(T100DX12Model* model)
{
    for(T100DX12Frame* frame : m_frames)
    {
        T100DX12Context*    context         = T100NULL;
        //DEBUGPRINT("Convert %d", model->Type);
        m_studio->m_context_manager.Convert(frame, model, &context);
        //DEBUGPRINT("Convert %d", context->Type);
        model->m_contexts.push_back(context);
        frame->Append(context);
    }
}


T100VOID T100DX12FrameManager::PopulateCommandList(T100DX12Frame* frameResource)
{

    ThrowIfFailed(m_current->m_commandAllocator->Reset());

    frameResource->Render(m_studio);
}

void T100DX12FrameManager::SetCustomWindowText(LPCWSTR text)
{
    std::wstring windowText = m_title + L": " + text;
    SetWindowTextW(m_studio->m_hwnd, windowText.c_str());
}

T100VOID T100DX12FrameManager::CreateAndCloseCommandList(T100DX12Frame* frame)
{
    ThrowIfFailed(m_studio->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, frame->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&frame->m_commandList)));
    ThrowIfFailed(frame->m_commandList->Close());
}

T100VOID T100DX12FrameManager::Remove(T100DX12Context* context)
{
    m_frames[context->m_frameIndex]->Remove(context);
}
