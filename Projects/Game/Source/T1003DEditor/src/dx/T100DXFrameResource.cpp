#include "T100DXFrameResource.h"

#include "T100DX12Tools.h"

T100DXFrameResource::T100DXFrameResource(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount) :
    m_fenceValue(0),
    m_cityRowCount(cityRowCount),
    m_cityColumnCount(cityColumnCount)
{
    //ctor
}

T100DXFrameResource::~T100DXFrameResource()
{
    //dtor
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

void T100DXFrameResource::InitBundle(ID3D12Device* pDevice, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
    UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
    ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature)
{
    ThrowIfFailed(pDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), pPso1, IID_PPV_ARGS(&m_bundle)));

    PopulateCommandList(m_bundle.Get(), pPso1, pPso2, frameResourceIndex, numIndices, pIndexBufferViewDesc,
        pVertexBufferViewDesc, pCbvSrvDescriptorHeap, cbvSrvDescriptorSize, pSamplerDescriptorHeap, pRootSignature);

    ThrowIfFailed(m_bundle->Close());
}
