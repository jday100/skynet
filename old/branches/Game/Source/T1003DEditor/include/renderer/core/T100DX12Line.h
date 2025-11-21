#ifndef T100DX12LINE_H
#define T100DX12LINE_H

#include "dx12/T100DX12Header.h"
#include "entity/T100City.h"
#include "renderer/T100DX12FrameResource.h"
#include "renderer/data/T100DX12Context.h"

class T100DX12Studio;

class T100DX12Line
{
    public:
        T100DX12Line(T100DX12Studio*);
        virtual ~T100DX12Line();

        virtual T100VOID        Start();
        virtual T100VOID        Stop();

        virtual T100VOID        Update();
        virtual T100VOID        Render();

        T100City*               m_entity        = T100NULL;

    protected:
        T100DX12Studio*         m_studio            = T100NULL;

        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        ComPtr<ID3D12RootSignature>             m_rootSignature;

        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;


        ComPtr<ID3D12Resource>                  m_cbvUploadHeap;
        SceneConstantBuffer*                    m_pConstantBuffers;
        UINT64                                  m_fenceValue;
        std::vector<XMFLOAT4X4>                 m_modelMatrices;

        UINT                                    m_cbvSrv_value;
        //D3D12_INDEX_BUFFER_VIEW*                m_indexBufferView;

        const T100D3D12_INPUT_ELEMENT_DESC      StandardVertexDescription[2] =
        {
            { L"POSITION", 0, T100DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { L"COLOR",   0, T100DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
        };
        T100UINT StandardVertexDescriptionNumElements = _countof(StandardVertexDescription);

        const T100UINT VertexDataOffset     = 524288;
        const T100UINT VertexDataSize       = 820248;
        const T100UINT IndexDataOffset      = 1344536;
        const T100UINT IndexDataSize        = 74568;
        const T100UINT StandardVertexStride = 44;

        const T100DXGI_FORMAT StandardIndexFormat = T100DXGI_FORMAT_R32_UINT;

        TextureResource Textures[1] =
        {
            { 1024, 1024, 1, T100DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } },
        };

        DrawParameters Draws[1] =
        {
            { 0, -1, -1, 0, 18642, 0 },
        };

    protected:
        T100VOID                LoadAssets();
        T100VOID                PopulateCommandList();

        T100VOID                TestLoad();
        T100VOID                TestRender();

        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        UINT                                    m_numIndices;
        //ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        //D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        //UINT64                                  m_fenceValue;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;

        std::vector<T100DX12FrameResource*>     m_frameResources;
        T100DX12FrameResource*                  pCurrentFrameResource;
        T100UINT                                m_currentFrameResourceIndex;

        T100VOID                BundleLoad();
        T100VOID                BundleUpdate();
        T100VOID                BundleRender();

        T100VOID                PopulateCommandList(T100DX12FrameResource*);


        T100VOID                VertexLoad();
        T100VOID                VertexUpdate();
        T100VOID                VertexRender();
        T100VOID                VertexPopulate(T100DX12FrameResource*);

        T100VOID                LineLoad();
        T100VOID                LineUpdate();
        T100VOID                LineRender();
        T100VOID                LinePopulate(T100DX12FrameResource*);

    private:
        DXGI_FORMAT             ConvertFormat(T100DXGI_FORMAT);
};

#endif // T100DX12LINE_H
