#include "context/T100DX12MeshContext.h"

#include "dx12/T100DX12Tools.h"
#include "data/T100DX12Frame.h"
#include "core/T100DX12Studio.h"

T100DX12MeshContext::T100DX12MeshContext() :
    T100DX12Context()
{
    //ctor
}

T100DX12MeshContext::~T100DX12MeshContext()
{
    //dtor
}

T100VOID T100DX12MeshContext::Update()
{
    Events();

    if(m_visible)
        DoUpdate();
}

T100VOID T100DX12MeshContext::Render()
{
    if(!m_visible)return;

    if(Bundle.USED){
        if(Type == T100ENTITY_CITY){
            //RenderCity();
        }else{
            RenderBundle();
        }
    }else{
        RenderSingle();
    }
}

T100VOID T100DX12MeshContext::DoUpdate()
{
    switch(MotionType){
    case T1003D_MOTION_STILL:
        {

        }
        break;
    case T1003D_MOTION_STAND:
        {

        }
        break;
    case T1003D_MOTION_MOVE:
        {
            if(Bundle.USED){
                UpdateConstantBuffers();
            }else{
                UpdateConstantBuffer();
            }
        }
        break;
    }
}

T100VOID T100DX12MeshContext::RenderSingle()
{
    ThrowIfFailed(m_framePtr->m_commandAllocator->Reset());
    ThrowIfFailed(m_commandList->Reset(m_framePtr->m_commandAllocator.Get(), m_pipelineState.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = { m_framePtr->m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_framePtr->m_studioPtr->m_viewport);
    m_commandList->RSSetScissorRects(1, &m_framePtr->m_studioPtr->m_scissorRect);

    CD3DX12_RESOURCE_BARRIER    barrier1     = CD3DX12_RESOURCE_BARRIER::Transition(m_framePtr->m_studioPtr->m_renderTargets[m_framePtr->m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier1);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
        m_framePtr->m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart(), m_framePtr->m_studioPtr->m_frameIndex,
        m_framePtr->m_studioPtr->GetHeapManager().GetRtvHeap().GetSize());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

    //m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
    m_commandList->IASetVertexBuffers(0, 1, m_vertexBufferViewPtr);

    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(
        m_framePtr->m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetGPUStart(),
        m_cbvSrvHeapIndex,
        m_framePtr->m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

    m_commandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle);
    //m_commandList->DrawInstanced(2, 1, 0, 0);

    DoRender();

    CD3DX12_RESOURCE_BARRIER    barrier2    = CD3DX12_RESOURCE_BARRIER::Transition(m_framePtr->m_studioPtr->m_renderTargets[m_framePtr->m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &barrier2);

    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    m_framePtr->m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    //m_framePtr->m_studioPtr->Waiting();
}

T100VOID T100DX12MeshContext::RenderBundle()
{

    ThrowIfFailed(m_commandList->Reset(m_framePtr->m_commandAllocator.Get(), m_pipelineState.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap() };
        //m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_studioPtr->m_viewport);
    m_commandList->RSSetScissorRects(1, &m_studioPtr->m_scissorRect);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart(), m_studioPtr->m_frameIndex, m_studioPtr->GetHeapManager().GetRtvHeap().GetSize());
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_studioPtr->GetHeapManager().GetDsvHeap().GetCPUStart(), m_framePtr->m_index, m_studioPtr->GetHeapManager().GetDsvHeap().GetSize());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    if (Bundle.USED)
    {
        m_commandList->ExecuteBundle(m_bundleCommandList.Get());
    }
    else
    {
    }

    CD3DX12_RESOURCE_BARRIER        present_barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &present_barrier);

    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    //m_studioPtr->Waiting();
}

T100VOID T100DX12MeshContext::RenderCity()
{
    ThrowIfFailed(m_commandList->Reset(m_framePtr->m_commandAllocator.Get(), m_pipelineState1.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap(),
        m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_studioPtr->m_viewport);
    m_commandList->RSSetScissorRects(1, &m_studioPtr->m_scissorRect);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart(), m_studioPtr->m_frameIndex, m_studioPtr->GetHeapManager().GetRtvHeap().GetSize());
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_studioPtr->GetHeapManager().GetDsvHeap().GetCPUStart(), m_framePtr->m_index, m_studioPtr->GetHeapManager().GetDsvHeap().GetSize());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);
    m_commandList->ClearDepthStencilView(m_studioPtr->GetHeapManager().GetDsvHeap().GetCPUStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    if (Bundle.USED)
    {
        m_commandList->ExecuteBundle(m_bundleCommandList.Get());
    }
    else
    {
    }

    CD3DX12_RESOURCE_BARRIER        present_barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &present_barrier);

    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    //m_studioPtr->Waiting();
}

T100VOID T100DX12MeshContext::DoRender()
{
    switch(Type){
    case T100ENTITY_DOT:
        {
            RenderDot();
        }
        break;
    case T100ENTITY_LINE:
        {
            RenderLine();
        }
        break;
    case T100ENTITY_TRIANGLE:
        {
            RenderTriangle();
        }
        break;
    case T100ENTITY_PLANE:
        {
            RenderPlane();
        }
        break;
    }
}

T100VOID T100DX12MeshContext::UpdateConstantBuffer()
{
    XMMATRIX        project;
    XMMATRIX        view;
    XMMATRIX        world;
    XMFLOAT4X4      mvp;

    T100DX12Camera*     cameraPtr       = T100NULL;

    cameraPtr   = m_studioPtr->GetCameraInstancePtr();

    if(cameraPtr){
        cameraPtr->GetProjectionMatrix(project);
        cameraPtr->GetViewMatrix(view);

        world   = BuildWorld();

        XMStoreFloat4x4(&mvp, XMMatrixTranspose(world * view * project));
    }else{
        world   = XMMatrixTranslation(m_position.x, m_position.y, m_position.z);

        XMStoreFloat4x4(&mvp, XMMatrixTranspose(world));
    }

    memcpy(&m_constantBuffersPtr[0], &mvp, sizeof(mvp));
}

T100VOID T100DX12MeshContext::UpdateConstantBuffers()
{
    XMMATRIX        project;
    XMMATRIX        view;
    XMMATRIX        world;
    XMFLOAT4X4      mvp;

    T100DX12Camera*     cameraPtr       = T100NULL;

    cameraPtr   = m_studioPtr->GetCameraInstancePtr();

    if(cameraPtr){
        cameraPtr->GetProjectionMatrix(project);
        cameraPtr->GetViewMatrix(view);

        UpdateBundle(project, view);
    }else{
        UpdateBundle();
    }
}

T100VOID T100DX12MeshContext::RenderDot()
{
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);
    m_commandList->DrawInstanced(1, 1, 0, 0);
}

T100VOID T100DX12MeshContext::RenderLine()
{
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
    m_commandList->DrawInstanced(2, 1, 0, 0);
}

T100VOID T100DX12MeshContext::RenderTriangle()
{
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_commandList->DrawInstanced(3, 1, 0, 0);
}

T100VOID T100DX12MeshContext::RenderPlane()
{
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
    m_commandList->DrawInstanced(4, 1, 0, 0);
}
