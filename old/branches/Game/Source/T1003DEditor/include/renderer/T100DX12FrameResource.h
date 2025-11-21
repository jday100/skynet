#ifndef T100DX12FRAMERESOURCE_H
#define T100DX12FRAMERESOURCE_H

#include <vector>
#include "dx12/T100DX12Header.h"
#include "renderer/data/T100DX12Context.h"

class T100DX12FrameResource
{
    friend class T100DX12Discrete;

    public:
        T100DX12FrameResource();
        T100DX12FrameResource(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount);
        virtual ~T100DX12FrameResource();

        T100VOID            Create(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount);
        T100VOID            Create(ID3D12Device* pDevice, UINT cityRowCount, UINT cityColumnCount, UINT cityMaterialCount, float citySpacingInterval);


        struct SceneConstantBuffer
        {
            XMFLOAT4X4 mvp;
            FLOAT padding[48];
        };

        ComPtr<ID3D12CommandAllocator>              m_commandAllocator;
        ComPtr<ID3D12CommandAllocator>              m_bundleAllocator;
        ComPtr<ID3D12GraphicsCommandList>           m_bundle;
        ComPtr<ID3D12Resource>                      m_cbvUploadHeap;
        SceneConstantBuffer*                        m_pConstantBuffers;
        UINT64                                      m_fenceValue;

        std::vector<XMFLOAT4X4>                     m_modelMatrices;
        UINT                                        m_cityRowCount;
        UINT                                        m_cityColumnCount;
        UINT                                        m_cityMaterialCount;

        void InitBundle(ID3D12Device* pDevice, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
            UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
            ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature);

        void PopulateCommandList(ID3D12GraphicsCommandList* pCommandList, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
            UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
            ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature);

        void XM_CALLCONV UpdateConstantBuffers(FXMMATRIX view, CXMMATRIX projection);


        void LinePopulateCommandList(ID3D12GraphicsCommandList* pCommandList, ID3D12PipelineState* pPso1, ID3D12PipelineState* pPso2,
            UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
            ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature);


        void InitBundle(ID3D12Device* pDevice, ID3D12PipelineState* pPso,
            UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
            ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature);
        void PopulateCommandList(ID3D12GraphicsCommandList* pCommandList,
            UINT frameResourceIndex, UINT numIndices, D3D12_INDEX_BUFFER_VIEW* pIndexBufferViewDesc, D3D12_VERTEX_BUFFER_VIEW* pVertexBufferViewDesc,
            ID3D12DescriptorHeap* pCbvSrvDescriptorHeap, UINT cbvSrvDescriptorSize, ID3D12DescriptorHeap* pSamplerDescriptorHeap, ID3D12RootSignature* pRootSignature);

    protected:
        T100DX12Context*                m_context           = T100NULL;

        T100VOID                        ContextCreate(ID3D12Device* pDevice, T100DX12Context* context, UINT cityRowCount, UINT cityColumnCount);
        T100VOID                        ContextInit(T100DX12Studio* studio, UINT frameResourceIndex, ID3D12RootSignature* pRootSignature);
        T100VOID                        ContextPopulate(T100DX12Studio* studio, UINT frameResourceIndex, ID3D12RootSignature* pRootSignature);
        T100VOID                        ContextUpdate(FXMMATRIX view, CXMMATRIX projection);
        T100VOID                        ContextSetPositions(FLOAT intervalX, FLOAT intervalZ);

        T100VOID                        CreateConstantBufferView(T100DX12Studio*, CD3DX12_CPU_DESCRIPTOR_HANDLE&);

    private:
        void            SetCityPositions(FLOAT intervalX, FLOAT intervalZ);

};

#endif // T100DX12FRAMERESOURCE_H
