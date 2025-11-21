#include "T100DX12FrameResource.h"

#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

T100DX12FrameResource::T100DX12FrameResource() :
    m_fenceValue(0)
{

}

T100DX12FrameResource::T100DX12FrameResource(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount) :
    m_fenceValue(0),
    m_cityRowCount(cityRowCount),
    m_cityColumnCount(cityColumnCount)
{
    //ctor
    m_modelMatrices.resize(m_cityRowCount * m_cityColumnCount);

    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constant_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constant_desc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * m_cityRowCount * m_cityColumnCount);
    ThrowIfFailed(pDevice->CreateCommittedResource(
        &constant_heap,
        D3D12_HEAP_FLAG_NONE,
        &constant_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_pConstantBuffers)));

    SetCityPositions(15.0f, -15.0f);
}

T100DX12FrameResource::~T100DX12FrameResource()
{
    //dtor
    m_cbvUploadHeap->Unmap(0, nullptr);
    m_pConstantBuffers = nullptr;
}

T100VOID T100DX12FrameResource::Create(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount, UINT cityMaterialCount, float citySpacingInterval)
{
    m_cityRowCount          = cityRowCount;
    m_cityColumnCount       = cityColumnCount;
    m_cityMaterialCount     = cityMaterialCount;

    m_modelMatrices.resize(m_cityRowCount * m_cityColumnCount);

    // The command allocator is used by the main sample class when
    // resetting the command list in the main update loop. Each frame
    // resource needs a command allocator because command allocators
    // cannot be reused until the GPU is done executing the commands
    // associated with it.
    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator)));

    // Create an upload heap for the constant buffers.
    CD3DX12_HEAP_PROPERTIES         cbvUpload(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           cbvUploadDesc       = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * m_cityRowCount * m_cityColumnCount);
    ThrowIfFailed(pDevice->CreateCommittedResource(
        &cbvUpload,
        D3D12_HEAP_FLAG_NONE,
        &cbvUploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_cbvUploadHeap)));

    // Map the constant buffers. Note that unlike D3D11, the resource
    // does not need to be unmapped for use by the GPU. In this sample,
    // the resource stays 'permenantly' mapped to avoid overhead with
    // mapping/unmapping each frame.
    CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
    ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_pConstantBuffers)));

    // Update all of the model matrices once; our cities don't move so
    // we don't need to do this ever again.
    SetCityPositions(citySpacingInterval, -citySpacingInterval);
}

T100VOID T100DX12FrameResource::Create(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount)
{
    m_cityRowCount      = cityRowCount;
    m_cityColumnCount   = cityColumnCount;

    m_modelMatrices.resize(m_cityRowCount * m_cityColumnCount);

    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constant_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constant_desc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * m_cityRowCount * m_cityColumnCount);
    ThrowIfFailed(pDevice->CreateCommittedResource(
        &constant_heap,
        D3D12_HEAP_FLAG_NONE,
        &constant_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_pConstantBuffers)));

    SetCityPositions(15.0f, -15.0f);
}

void T100DX12FrameResource::InitBundle(ID3D12Device* pDevice, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    ThrowIfFailed(pDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), pPso1, IID_PPV_ARGS(&m_bundle)));

    LinePopulateCommandList(m_bundle.Get(), pPso1, pPso2, frameResourceIndex, numIndices, pIndexBufferViewDesc,
        pVertexBufferViewDesc, pCbvSrvDescriptorHeap, cbvSrvDescriptorSize, pSamplerDescriptorHeap, pRootSignature);

    ThrowIfFailed(m_bundle->Close());
}

void T100DX12FrameResource::SetCityPositions(FLOAT intervalX, FLOAT intervalZ)
{
    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        FLOAT cityOffsetZ = i * intervalZ;
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            FLOAT cityOffsetX = j * intervalX;

            XMStoreFloat4x4(&m_modelMatrices[i * m_cityColumnCount + j], XMMatrixTranslation(cityOffsetX, 0.02f * (i * m_cityColumnCount + j), cityOffsetZ));
        }
    }
}

void T100DX12FrameResource::PopulateCommandList(ID3D12GraphicsCommandList* pCommandList, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    pCommandList->SetGraphicsRootSignature(pRootSignature);

    ID3D12DescriptorHeap*       ppHeaps[] = { pCbvSrvDescriptorHeap, pSamplerDescriptorHeap };
    pCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    pCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
    //pCommandList->IASetIndexBuffer(pIndexBufferViewDesc);
    pCommandList->IASetVertexBuffers(0, 1, pVertexBufferViewDesc);
    //pCommandList->SetGraphicsRootDescriptorTable(0, pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart());
    //pCommandList->SetGraphicsRootDescriptorTable(1, pSamplerDescriptorHeap->GetGPUDescriptorHandleForHeapStart());

    UINT frameResourceDescriptorOffset = (frameResourceIndex * m_cityRowCount * m_cityColumnCount);
    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart(), frameResourceDescriptorOffset, cbvSrvDescriptorSize);

    BOOL        usePso1 = TRUE;
    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            pCommandList->SetPipelineState(usePso1 ? pPso1 : pPso2);
            usePso1 = !usePso1;

            //pCommandList->SetGraphicsRootDescriptorTable(2, cbvSrvHandle);
            pCommandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle);
            cbvSrvHandle.Offset(cbvSrvDescriptorSize);

            pCommandList->DrawIndexedInstanced(numIndices, 1, 0, 0, 0);
        }
    }
}

void T100DX12FrameResource::LinePopulateCommandList(ID3D12GraphicsCommandList* pCommandList, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    pCommandList->SetGraphicsRootSignature(pRootSignature);

    ID3D12DescriptorHeap*       ppHeaps[] = { pCbvSrvDescriptorHeap };
    pCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    pCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
    //pCommandList->IASetIndexBuffer(pIndexBufferViewDesc);
    pCommandList->IASetVertexBuffers(0, 1, pVertexBufferViewDesc);
    //pCommandList->SetGraphicsRootDescriptorTable(0, pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart());
    //pCommandList->SetGraphicsRootDescriptorTable(1, pSamplerDescriptorHeap->GetGPUDescriptorHandleForHeapStart());

    UINT frameResourceDescriptorOffset = (frameResourceIndex * m_cityRowCount * m_cityColumnCount);
    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart(), frameResourceDescriptorOffset, cbvSrvDescriptorSize);

    BOOL        usePso1 = TRUE;
    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            pCommandList->SetPipelineState(usePso1 ? pPso1 : pPso2);
            usePso1 = !usePso1;

            //pCommandList->SetGraphicsRootDescriptorTable(2, cbvSrvHandle);
            pCommandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle);
            cbvSrvHandle.Offset(cbvSrvDescriptorSize);

            pCommandList->DrawIndexedInstanced(numIndices, 1, 0, 0, 0);
        }
    }
}


void XM_CALLCONV T100DX12FrameResource::UpdateConstantBuffers(FXMMATRIX view, CXMMATRIX projection)
{
    XMMATRIX        model;
    XMFLOAT4X4      mvp;

    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            model = XMLoadFloat4x4(&m_modelMatrices[i * m_cityColumnCount + j]);

            XMStoreFloat4x4(&mvp, XMMatrixTranspose(model * view * projection));

            memcpy(&m_pConstantBuffers[i * m_cityColumnCount + j], &mvp, sizeof(mvp));
        }
    }
}



T100VOID T100DX12FrameResource::ContextCreate(ID3D12Device* pDevice, T100DX12Context* context, UINT cityRowCount, UINT cityColumnCount)
{
    m_context           = context;
    m_cityRowCount      = cityRowCount;
    m_cityColumnCount   = cityColumnCount;

    m_context->m_modelMatrices.resize(m_cityRowCount * m_cityColumnCount);

    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
    ThrowIfFailed(pDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_context->m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constant_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constant_desc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * m_cityRowCount * m_cityColumnCount);
    ThrowIfFailed(pDevice->CreateCommittedResource(
        &constant_heap,
        D3D12_HEAP_FLAG_NONE,
        &constant_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_context->m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(m_context->m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_context->m_constantBuffersPtr)));

    ContextSetPositions(15.0f, -15.0f);
}

void T100DX12FrameResource::ContextInit(T100DX12Studio* studio, UINT frameResourceIndex, ID3D12RootSignature* pRootSignature)
{
    ThrowIfFailed(studio->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_context->m_bundleAllocator.Get(), m_context->m_pipelineState1.Get(), IID_PPV_ARGS(&m_context->m_bundleCommandList)));

    ContextPopulate(studio, frameResourceIndex, pRootSignature);

    ThrowIfFailed(m_context->m_bundleCommandList->Close());
}

void T100DX12FrameResource::ContextSetPositions(FLOAT intervalX, FLOAT intervalZ)
{
    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        FLOAT cityOffsetZ = i * intervalZ;
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            FLOAT cityOffsetX = j * intervalX;

            XMStoreFloat4x4(&m_context->m_modelMatrices[i * m_cityColumnCount + j], XMMatrixTranslation(cityOffsetX, 0.02f * (i * m_cityColumnCount + j), cityOffsetZ));
        }
    }
}

void T100DX12FrameResource::ContextPopulate(T100DX12Studio* studio, UINT frameResourceIndex, ID3D12RootSignature* pRootSignature)
{
    m_context->m_bundleCommandList->SetGraphicsRootSignature(pRootSignature);

    ID3D12DescriptorHeap*       ppHeaps[] = {
        studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heap.Get(),
        studio->m_heap_manager.GetSamplerHeap().m_heap.m_heap.Get() };
    m_context->m_bundleCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    m_context->m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_context->m_bundleCommandList->IASetIndexBuffer(m_context->m_indexBufferViewPtr);
    m_context->m_bundleCommandList->IASetVertexBuffers(0, 1, m_context->m_vertexBufferViewPtr);
    //m_context->m_bundleCommandList->SetGraphicsRootDescriptorTable(0, studio->m_heap_manager.GetCbvSrvHeap().GetGPUStart());
    //m_context->m_bundleCommandList->SetGraphicsRootDescriptorTable(1, studio->m_heap_manager.GetSamplerHeap().GetGPUStart());

    UINT frameResourceDescriptorOffset = 1 + (frameResourceIndex * m_cityRowCount * m_cityColumnCount);
    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(
        studio->m_heap_manager.GetCbvSrvHeap().GetGPUStart(),
        frameResourceDescriptorOffset,
        studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);

    BOOL        usePso1 = TRUE;
    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            m_context->m_bundleCommandList->SetPipelineState(usePso1 ? m_context->m_pipelineState1.Get() : m_context->m_pipelineState2.Get());
            usePso1 = !usePso1;

            //m_context->m_bundleCommandList->SetGraphicsRootDescriptorTable(2, cbvSrvHandle);
            m_context->m_bundleCommandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle);
            cbvSrvHandle.Offset(studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);

            m_context->m_bundleCommandList->DrawIndexedInstanced(m_context->m_numIndices, 1, 0, 0, 0);
        }
    }
}

void XM_CALLCONV T100DX12FrameResource::ContextUpdate(FXMMATRIX view, CXMMATRIX projection)
{
    XMMATRIX        model;
    XMFLOAT4X4      mvp;

    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            model = XMLoadFloat4x4(&m_context->m_modelMatrices[i * m_cityColumnCount + j]);

            XMStoreFloat4x4(&mvp, XMMatrixTranspose(model * view * projection));

            memcpy(&m_context->m_constantBuffersPtr[i * m_cityColumnCount + j], &mvp, sizeof(mvp));
        }
    }
}

T100VOID T100DX12FrameResource::CreateConstantBufferView(T100DX12Studio* studio, CD3DX12_CPU_DESCRIPTOR_HANDLE& cbvSrvHandle)
{
    UINT64 cbOffset = 0;
    for (UINT j = 0; j < m_cityRowCount; j++)
    {
        for (UINT k = 0; k < m_cityColumnCount; k++)
        {
            D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
            cbvDesc.BufferLocation      = m_context->m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
            cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
            cbOffset                    += cbvDesc.SizeInBytes;
            studio->m_device->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
            cbvSrvHandle.Offset(studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);
        }
    }
}

void T100DX12FrameResource::InitBundle(ID3D12Device* pDevice, ID3D12PipelineState* pPso,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    ThrowIfFailed(pDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), pPso, IID_PPV_ARGS(&m_bundle)));

    PopulateCommandList(m_bundle.Get(), frameResourceIndex, numIndices, pIndexBufferViewDesc,
        pVertexBufferViewDesc, pCbvSrvDescriptorHeap, cbvSrvDescriptorSize, pSamplerDescriptorHeap, pRootSignature);

    ThrowIfFailed(m_bundle->Close());
}

void T100DX12FrameResource::PopulateCommandList(ID3D12GraphicsCommandList* pCommandList,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    // If the root signature matches the root signature of the caller, then
    // bindings are inherited, otherwise the bind space is reset.
    pCommandList->SetGraphicsRootSignature(pRootSignature);

    ID3D12DescriptorHeap* ppHeaps[] = { pCbvSrvDescriptorHeap, pSamplerDescriptorHeap };
    pCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    pCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    pCommandList->IASetIndexBuffer(pIndexBufferViewDesc);
    pCommandList->IASetVertexBuffers(0, 1, pVertexBufferViewDesc);
    pCommandList->SetGraphicsRootDescriptorTable(0, pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart());
    pCommandList->SetGraphicsRootDescriptorTable(1, pSamplerDescriptorHeap->GetGPUDescriptorHandleForHeapStart());

    // Calculate the descriptor offset due to multiple frame resources.
    // (m_cityMaterialCount + 1) SRVs + how many CBVs we have currently.
    UINT frameResourceDescriptorOffset = (m_cityMaterialCount + 1) + (frameResourceIndex * m_cityRowCount * m_cityColumnCount);
    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart(), frameResourceDescriptorOffset, cbvSrvDescriptorSize);

    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            // Set the city's root constant for dynamically indexing into the material array.
            pCommandList->SetGraphicsRoot32BitConstant(3, (i * m_cityColumnCount) + j, 0);

            // Set this city's CBV table and move to the next descriptor.
            pCommandList->SetGraphicsRootDescriptorTable(2, cbvSrvHandle);
            cbvSrvHandle.Offset(cbvSrvDescriptorSize);

            pCommandList->DrawIndexedInstanced(numIndices, 1, 0, 0, 0);
        }
    }
}
