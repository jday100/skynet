#include "T100DX12Frame.h"

#include "T100Debug.h"
#include "T100DX12Tools.h"
#include "T100DX12Studio.h"
#include "T100DX12AllContexts.h"

T100DX12Frame::T100DX12Frame() :
    m_contexts(),
    m_pendingAppend(),
    m_pendingRemove(),
    m_fenceValue(0)
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

T100VOID T100DX12Frame::Append(T100DX12Context* context)
{
    //DEBUGPRINT("Append %d", context->Type);
    FrameAppend(context);
}

T100VOID T100DX12Frame::Remove(T100DX12Context* context)
{
    //DEBUGPRINT("Remove %d", context->Type);
    FrameRemove(context);
}

T100VOID T100DX12Frame::Update(T100DX12Studio* studio)
{
    FrameUpdate(studio);
}

T100VOID T100DX12Frame::Render(T100DX12Studio* studio)
{
    FrameRender(studio);
}

T100VOID T100DX12Frame::AppendContexts(T100DX12Studio* studio)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    for(T100DX12Context* context : m_pendingAppend)
    {
        m_contexts.push_back(context);
    }

    m_pendingAppend.clear();
}

T100VOID T100DX12Frame::RemoveContexts(T100DX12Studio* studio)
{
    std::lock_guard<std::mutex>     lock(m_mutex);

    for(T100DX12Context* context : m_pendingRemove)
    {
        RemoveContext(context);
    }

    m_pendingRemove.clear();
}

T100VOID T100DX12Frame::RemoveContext(T100DX12Context* context)
{
    //std::lock_guard<std::mutex>     lock(m_mutex);

    T100DX12_CONTEXT_VECTOR::iterator     it;

    for(it = m_contexts.begin(); it != m_contexts.end(); ++it){
        if(context == *it){
            m_contexts.erase(it);
            T100SAFE_DELETE context;
            return;
        }
    }
}

T100VOID T100DX12Frame::RenderCommands(T100DX12Studio* studio)
{
    studio->m_commandQueue->ExecuteCommandLists(m_commands.size(), m_commands.data());
}

T100VOID T100DX12Frame::FrameAppend(T100DX12Context* context)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    //DEBUGPRINT("Pending Size %u", m_pending.size());
    m_pendingAppend.push_back(context);
    //DEBUGPRINT("Pending Size %u", m_pending.size());
    m_append    = T100TRUE;
}

T100VOID T100DX12Frame::FrameRemove(T100DX12Context* context)
{
    std::lock_guard<std::mutex>     lock(m_mutex);
    m_pendingRemove.push_back(context);
    m_remove    = T100TRUE;
}

T100VOID T100DX12Frame::FrameUpdate(T100DX12Studio* studio)
{
    if(m_append){
        AppendContexts(studio);
        m_append    = T100FALSE;
    }
    if(m_remove){
        RemoveContexts(studio);
        m_remove    = T100FALSE;
    }

    for(T100DX12Context* context : m_contexts)
    {
        studio->m_context_manager.Events(context);

        switch(context->Type){
        case T100ENTITY_DOT:
            {
                T100DX12ContextDot*     dot    = T100NULL;

                dot     = dynamic_cast<T100DX12ContextDot*>(context);

                if(dot){
                    dot->Update();
                }
            }
            break;
        case T100ENTITY_LINE:
            {
                T100DX12ContextLine*    line    = T100NULL;

                line    = dynamic_cast<T100DX12ContextLine*>(context);

                if(line){
                    line->Update();
                }

            }
            break;
        case T100ENTITY_TRIANGLE:
            {
                T100DX12ContextTriangle*        triangle        = T100NULL;

                triangle    = dynamic_cast<T100DX12ContextTriangle*>(context);

                if(triangle){
                    triangle->Update();
                }

            }
            break;
        case T100ENTITY_PLANE:
            {
                T100DX12ContextPlane*       plane        = T100NULL;

                plane    = dynamic_cast<T100DX12ContextPlane*>(context);

                if(plane){
                    plane->Update();
                }

            }
            break;
        case T100ENTITY_CITY:
            {
                T100DX12ContextCity*        city        = T100NULL;

                city    = dynamic_cast<T100DX12ContextCity*>(context);

                if(city){
                    city->Update();
                }

            }
            break;
        case T100ENTITY_SPHERE:
            {
                T100DX12ContextSphere*        sphere        = T100NULL;

                sphere    = dynamic_cast<T100DX12ContextSphere*>(context);

                if(sphere){
                    sphere->Update();
                }

            }
            break;
        case T100ENTITY_RECTANGLE:
            {
                T100DX12ContextRectangle*        rectangle        = T100NULL;

                rectangle    = dynamic_cast<T100DX12ContextRectangle*>(context);

                if(rectangle){
                    rectangle->Update();
                }

            }
            break;
        default:
            {

            }
        }
    }
}

T100VOID T100DX12Frame::FrameRender(T100DX12Studio* studio)
{
    m_index     = 0;

    ThrowIfFailed(m_commandAllocator->Reset());
    ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = {
        studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heap.Get(),
        studio->m_heap_manager.GetSamplerHeap().m_heap.m_heap.Get() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &studio->m_viewport);
    m_commandList->RSSetScissorRects(1, &studio->m_scissorRect);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(studio->m_renderTargets[studio->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(studio->m_heap_manager.GetRtvHeap().GetCPUStart(), studio->m_frameIndex, studio->m_heap_manager.GetRtvHeap().m_heap.m_heapDescriptorSize);
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(studio->m_heap_manager.GetDsvHeap().GetCPUStart(), m_index++, studio->m_heap_manager.GetDsvHeap().m_heap.m_heapDescriptorSize);
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    const float         clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->ClearDepthStencilView(studio->m_heap_manager.GetDsvHeap().GetCPUStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    CD3DX12_RESOURCE_BARRIER        present_barrier         = CD3DX12_RESOURCE_BARRIER::Transition(studio->m_renderTargets[studio->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &present_barrier);

    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    studio->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    std::lock_guard<std::mutex>     lock(m_mutex);

    int i = 0;
    for(T100DX12Context* context : m_contexts)
    {
        T100DX12Context&    value = *context;
        //DEBUGPRINT("Populate %u", i++);
        if(context->m_visible){
            //DEBUGPRINT("Populate %u", i);

            switch(context->Type){
            case T100ENTITY_DOT:
                {
                    T100DX12ContextDot*     dot    = T100NULL;

                    dot     = dynamic_cast<T100DX12ContextDot*>(context);

                    if(dot){
                        dot->Render();
                    }
                }
                break;
            case T100ENTITY_LINE:
                {
                    T100DX12ContextLine*    line    = T100NULL;

                    line    = dynamic_cast<T100DX12ContextLine*>(context);

                    if(line){
                        line->Render();
                    }

                }
                break;
            case T100ENTITY_TRIANGLE:
                {
                    T100DX12ContextTriangle*        triangle        = T100NULL;

                    triangle    = dynamic_cast<T100DX12ContextTriangle*>(context);

                    if(triangle){
                        triangle->Render();
                    }

                }
                break;
            case T100ENTITY_PLANE:
                {
                    T100DX12ContextPlane*        plane        = T100NULL;

                    plane    = dynamic_cast<T100DX12ContextPlane*>(context);

                    if(plane){
                        plane->Render();
                    }

                }
                break;
            case T100ENTITY_CITY:
                {
                    T100DX12ContextCity*        city        = T100NULL;

                    city    = dynamic_cast<T100DX12ContextCity*>(context);

                    if(city){
                        city->Render();
                    }

                }
                break;
            case T100ENTITY_SPHERE:
                {
                    T100DX12ContextSphere*        sphere        = T100NULL;

                    sphere    = dynamic_cast<T100DX12ContextSphere*>(context);

                    if(sphere){
                        sphere->Render();
                    }

                }
                break;
            case T100ENTITY_RECTANGLE:
                {
                    T100DX12ContextRectangle*        rectangle        = T100NULL;

                    rectangle    = dynamic_cast<T100DX12ContextRectangle*>(context);

                    if(rectangle){
                        rectangle->Render();
                    }

                }
                break;
            default:
                {

                }
            }
        }
    }
}


T100VOID T100DX12Frame::CreateCommandAllocator(T100DX12Studio* studio)
{
    ThrowIfFailed(studio->m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
}
