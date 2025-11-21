#ifndef T100DX12BUNDLE_H
#define T100DX12BUNDLE_H

#include "dx12/T100DX12Header.h"
#include "entity/T100City.h"
#include "renderer/T100DX12FrameResource.h"

class T100DX12Studio;

class T100DX12Bundle
{
    friend class T100DX12Studio;
    public:
        T100DX12Bundle(T100DX12Studio*);
        virtual ~T100DX12Bundle();

    protected:
        T100DX12Studio*         m_studio        = T100NULL;
        T100City*               m_entity        = T100NULL;

        UINT                                    m_frameCounter;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;

        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        UINT                                    m_numIndices;
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        UINT64                                  m_fenceValue;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;

        std::vector<T100DX12FrameResource*>     m_frameResources;
        T100DX12FrameResource*                  pCurrentFrameResource;
        T100UINT                                m_currentFrameResourceIndex;

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
        T100VOID                CreateFrameResources();
        T100VOID                PopulateCommandList(T100DX12FrameResource*);
        T100VOID                BundleUpdate();
        T100VOID                BundleRender();

    private:
        std::wstring                            m_title;

        void    SetCustomWindowText(LPCWSTR text);
        DXGI_FORMAT             ConvertFormat(T100DXGI_FORMAT);


};

#endif // T100DX12BUNDLE_H
