#ifndef T100RESOURCE_H
#define T100RESOURCE_H

#include "stdafx.h"
#include "DXSampleHelper.h"

using namespace DirectX;
using Microsoft::WRL::ComPtr;

class T100Resource
{
    public:
        T100Resource(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount);
        virtual ~T100Resource();

        struct SceneConstantBuffer
        {
            XMFLOAT4X4 mvp;        // Model-view-projection (MVP) matrix.
            FLOAT padding[48];
        };

        ComPtr<ID3D12CommandAllocator> m_commandAllocator;
        ComPtr<ID3D12CommandAllocator> m_bundleAllocator;
        ComPtr<ID3D12GraphicsCommandList> m_bundle;
        ComPtr<ID3D12Resource> m_cbvUploadHeap;
        SceneConstantBuffer* m_pConstantBuffers;
        UINT64 m_fenceValue;

        std::vector<XMFLOAT4X4> m_modelMatrices;
        UINT m_cityRowCount;
        UINT m_cityColumnCount;

        void InitBundle(ID3D12Device* pDevice, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
            UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
            ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature);

        void PopulateCommandList(ID3D12GraphicsCommandList* pCommandList, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
            UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
            ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature);

        void XM_CALLCONV UpdateConstantBuffers(FXMMATRIX view, CXMMATRIX projection);


    protected:

    private:
        void SetCityPositions(FLOAT intervalX, FLOAT intervalZ);
};

#endif // T100RESOURCE_H
