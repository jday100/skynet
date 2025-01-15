#ifndef T100DXENTITY_H
#define T100DXENTITY_H

#include "T100DXBase.h"
#include "T100DXFrameResource.h"
#include "T100DXEntityManager.h"

class T100DXEntity : public T100DXBase
{
    public:
        T100DXEntity();
        virtual ~T100DXEntity();

        virtual T100VOID                        Start();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        Append(T100Entity*);

    protected:
        UINT                                    m_cbvSrvDescriptorSize;

        UINT                                    m_numIndices;

    protected:
        T100DXEntityManager                     m_entity_manager;

        std::vector<T100DXFrameResource*>       m_frameResources;
        T100DXFrameResource*                    m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;

        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;

        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

    private:
        T100VOID                                LoadPipeline();
        T100VOID                                LoadAssets();

        T100VOID                                CreateDsvHeap();
        T100VOID                                CreateCbvHeap(UINT, UINT);
        T100VOID                                CreateSamplerHeap();

        T100VOID                                UpdateFrameTimer();
        T100VOID                                UpdateFence();
        T100VOID                                UpdateCamera();
        T100VOID                                UpdateFrameResource();

        T100VOID                                PopulateCommandList(T100BOOL, T100DXFrameResource*);
        T100VOID                                ExecuteCommandList();
        T100VOID                                SwapChainPresent();
        T100VOID                                FenceSignal();
};

#endif // T100DXENTITY_H
