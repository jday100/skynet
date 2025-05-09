#include "T100DXFrameResource.h"


T100DXFrameResource::T100DXFrameResource(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount) :
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

T100DXFrameResource::~T100DXFrameResource()
{
    //dtor
    m_cbvUploadHeap->Unmap(0, nullptr);
    m_pConstantBuffers = nullptr;
}

void T100DXFrameResource::InitBundle(ID3D12Device* pDevice, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    ThrowIfFailed(pDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), pPso1, IID_PPV_ARGS(&m_bundle)));

    PopulateCommandList(m_bundle.Get(), pPso1, pPso2, frameResourceIndex, numIndices, pIndexBufferViewDesc,
        pVertexBufferViewDesc, pCbvSrvDescriptorHeap, cbvSrvDescriptorSize, pSamplerDescriptorHeap, pRootSignature);

    ThrowIfFailed(m_bundle->Close());
}

void T100DXFrameResource::SetCityPositions(FLOAT intervalX, FLOAT intervalZ)
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

void T100DXFrameResource::PopulateCommandList(ID3D12GraphicsCommandList* pCommandList, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    pCommandList->SetGraphicsRootSignature(pRootSignature);

    ID3D12DescriptorHeap*       ppHeaps[] = { pCbvSrvDescriptorHeap, pSamplerDescriptorHeap };
    pCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    pCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    pCommandList->IASetIndexBuffer(pIndexBufferViewDesc);
    pCommandList->IASetVertexBuffers(0, 1, pVertexBufferViewDesc);
    pCommandList->SetGraphicsRootDescriptorTable(0, pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart());
    pCommandList->SetGraphicsRootDescriptorTable(1, pSamplerDescriptorHeap->GetGPUDescriptorHandleForHeapStart());

    UINT frameResourceDescriptorOffset = 1 + (frameResourceIndex * m_cityRowCount * m_cityColumnCount);
    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(pCbvSrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart(), frameResourceDescriptorOffset, cbvSrvDescriptorSize);

    BOOL        usePso1 = TRUE;
    for (UINT i = 0; i < m_cityRowCount; i++)
    {
        for (UINT j = 0; j < m_cityColumnCount; j++)
        {
            pCommandList->SetPipelineState(usePso1 ? pPso1 : pPso2);
            usePso1 = !usePso1;

            pCommandList->SetGraphicsRootDescriptorTable(2, cbvSrvHandle);
            cbvSrvHandle.Offset(cbvSrvDescriptorSize);

            pCommandList->DrawIndexedInstanced(numIndices, 1, 0, 0, 0);
        }
    }
}

void XM_CALLCONV T100DXFrameResource::UpdateConstantBuffers(FXMMATRIX view, CXMMATRIX projection)
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
