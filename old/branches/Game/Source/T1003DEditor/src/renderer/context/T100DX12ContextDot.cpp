#include "T100DX12ContextDot.h"

#include "T100DX12Header.h"
#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

T100DX12ContextDot::T100DX12ContextDot() :
    T100DX12Context()
{
    //ctor
}

T100DX12ContextDot::~T100DX12ContextDot()
{
    //dtor
}

T100VOID T100DX12ContextDot::Create()
{
    if(Bundle.USED){
        CreateBundle();
    }else{
        CreateSingle();
    }
}

T100VOID T100DX12ContextDot::Destroy()
{

}

T100VOID T100DX12ContextDot::Update()
{
    if(Bundle.USED){
        UpdateBundle();
    }else{
        UpdateSingle();
    }
}

T100VOID T100DX12ContextDot::Render()
{
    if(Bundle.USED){
        RenderBundle();
    }else{
        RenderSingle();
    }
}

T100VOID T100DX12ContextDot::CreateSingle()
{
    m_modelMatrices.resize(1);

    CD3DX12_HEAP_PROPERTIES         constantHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constantDesc        = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer));
    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
        &constantHeap,
        D3D12_HEAP_FLAG_NONE,
        &constantDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_constantBuffersPtr)));

    XMStoreFloat4x4(&m_modelMatrices[0], XMMatrixTranslation(0, 0, 0));

    m_cbvSrvHeapIndex           = m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();
    CD3DX12_CPU_DESCRIPTOR_HANDLE       handle  = m_studioPtr->GetHeapManager().GetCbvSrvHeap().Get(1);

    UINT64 cbOffset = 0;

    D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
    cbvDesc.BufferLocation      = m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
    cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
    cbOffset                    += cbvDesc.SizeInBytes;
    m_studioPtr->GetDevicePtr()->CreateConstantBufferView(&cbvDesc, handle);
    handle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
}

T100VOID T100DX12ContextDot::UpdateSingle()
{
    XMMATRIX        projection;
    XMMATRIX        view;
    XMMATRIX        model;
    XMFLOAT4X4      mvp;
    XMMATRIX        result;

    projection      = m_studioPtr->GetCamera().GetProjectionMatrix();
    view            = m_studioPtr->GetCamera().GetViewMatrix();

    model   = XMMatrixTranslation(m_position.x, m_position.y, m_position.z);
    result  = model * view * projection;

    XMStoreFloat4x4(&mvp, XMMatrixTranspose(model * view * projection));

    memcpy(&m_constantBuffersPtr[0], &mvp, sizeof(mvp));
}

T100VOID T100DX12ContextDot::RenderSingle()
{

    ThrowIfFailed(m_commandList->Reset(m_framePtr->m_commandAllocator.Get(), m_pipelineState.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, m_studioPtr->GetViewport());
    m_commandList->RSSetScissorRects(1, m_studioPtr->GetScissorRect());

    CD3DX12_RESOURCE_BARRIER    barrier1     = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier1);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
        m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart(), m_studioPtr->m_frameIndex,
        m_studioPtr->GetHeapManager().GetRtvHeap().GetSize());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);
    m_commandList->IASetVertexBuffers(0, 1, m_vertexBufferViewPtr);

    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetGPUStart(), m_cbvSrvHeapIndex,
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

    m_commandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle);
    m_commandList->DrawInstanced(1, 1, 0, 0);

    CD3DX12_RESOURCE_BARRIER    barrier2    = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &barrier2);

    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    m_studioPtr->Waiting();
}

T100VOID T100DX12ContextDot::CreateBundle()
{

    T100UINT    length  = Bundle.AMOUNT.X * Bundle.AMOUNT.Y * Bundle.AMOUNT.Z;

    m_modelMatrices.resize(length);

    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constantHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constantDesc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * length);
    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
        &constantHeap,
        D3D12_HEAP_FLAG_NONE,
        &constantDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_constantBuffersPtr)));

    SetBundlePositions();

    m_cbvSrvHeapIndex          = m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();
    CD3DX12_CPU_DESCRIPTOR_HANDLE       cbvSrvHandle  = m_studioPtr->GetHeapManager().GetCbvSrvHeap().Get(length);

    UINT64 cbOffset = 0;
    for (UINT j = 0; j < Bundle.AMOUNT.X; j++)
    {
        for (UINT k = 0; k < Bundle.AMOUNT.Y; k++)
        {
            for (UINT l = 0; l < Bundle.AMOUNT.Z; l++)
            {
                D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
                cbvDesc.BufferLocation      = m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
                cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
                cbOffset                    += cbvDesc.SizeInBytes;
                m_studioPtr->GetDevicePtr()->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
                cbvSrvHandle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
            }
        }
    }

    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_bundleCommandList)));

    m_bundleCommandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap*       ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap() };
    m_bundleCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);
    m_bundleCommandList->IASetVertexBuffers(0, 1, m_vertexBufferViewPtr);

    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle2(
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetGPUStart(), m_cbvSrvHeapIndex,
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

    BOOL        usePso1 = TRUE;
    for (UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                m_bundleCommandList->SetPipelineState(usePso1 ? m_pipelineState.Get() : m_pipelineState.Get());
                usePso1 = !usePso1;

                m_bundleCommandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle2);
                cbvSrvHandle2.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

                m_bundleCommandList->DrawInstanced(m_numIndices, 1, 0, 0);
            }
        }
    }

    ThrowIfFailed(m_bundleCommandList->Close());
}

T100VOID T100DX12ContextDot::UpdateBundle()
{

    XMMATRIX        model;
    XMFLOAT4X4      mvp;
    UINT            m   = 0;

    XMMATRIX        item;
    XMMATRIX        temp;

    XMMATRIX        projection;
    XMMATRIX        view;

    XMMATRIX        result;

    projection      = m_studioPtr->GetCamera().GetProjectionMatrix();
    view            = m_studioPtr->GetCamera().GetViewMatrix();

    item            = BuildWorld();

    for (UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                XMFLOAT4X4  value;

                value = m_modelMatrices[m];

                model = XMLoadFloat4x4(&value);

                temp    = item * model;

                result  = temp * view * projection;

                XMStoreFloat4x4(&mvp, XMMatrixTranspose(result));

                memcpy(&m_constantBuffersPtr[m], &mvp, sizeof(mvp));

                m++;
            }
        }
    }
}

T100VOID T100DX12ContextDot::RenderBundle()
{

    ThrowIfFailed(m_commandList->Reset(m_framePtr->m_commandAllocator.Get(), m_pipelineState.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, m_studioPtr->GetViewport());
    m_commandList->RSSetScissorRects(1, m_studioPtr->GetScissorRect());

    CD3DX12_RESOURCE_BARRIER    barrier1     = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier1);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
        m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart(), m_studioPtr->m_frameIndex,
        m_studioPtr->GetHeapManager().GetRtvHeap().GetSize());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

    m_commandList->ExecuteBundle(m_bundleCommandList.Get());

    CD3DX12_RESOURCE_BARRIER    barrier2    = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &barrier2);

    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    m_studioPtr->Waiting();
}
