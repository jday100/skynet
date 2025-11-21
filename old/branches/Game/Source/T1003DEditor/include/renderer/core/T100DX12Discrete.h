#ifndef T100DX12DISCRETE_H
#define T100DX12DISCRETE_H

#include "dx12/T100DX12Header.h"
#include "entity/T100City.h"
#include "renderer/data/T100DX12Model.h"
#include "renderer/data/T100DX12Context.h"
#include "renderer/T100DX12FrameResource.h"

class T100DX12Studio;

class T100DX12Discrete
{
    friend class T100DX12Studio;
    public:
        T100DX12Discrete(T100DX12Studio*);
        virtual ~T100DX12Discrete();

        T100VOID                Start();
        T100VOID                Update();
        T100VOID                Render();


        T100DX12Studio*         m_studio        = T100NULL;
        T100City*               m_entity        = T100NULL;
        T100DX12Model*          m_model         = T100NULL;
        T100DX12Context*        m_context       = T100NULL;

        UINT                                    m_frameCounter;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;

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

        T100VOID                PopulateContext(T100DX12FrameResource*);
    protected:
        T100VOID                CreateCommandAllocator();
        T100VOID                CreateRootSignature();
        T100VOID                CreatePipelineState1And2(UINT8*, UINT, UINT8*, UINT, UINT8*, UINT);
        T100VOID                CreateCommandList();
        T100VOID                CloseCommandList();
        T100VOID                ExecuteCommandList();
        T100VOID                CreateRenderTargetView();

        T100VOID                CreateVertexBuffer(UINT8*, ComPtr<ID3D12Resource>&);
        T100VOID                CreateIndexBuffer(UINT8*, ComPtr<ID3D12Resource>&);
        T100VOID                CreateTextureBuffer(UINT8*, ComPtr<ID3D12Resource>&);

        T100VOID                CreateDepthStencilView();
        T100VOID                CreateFence();

        T100VOID                Waiting();

        T100VOID                CreateConstantBufferView(CD3DX12_CPU_DESCRIPTOR_HANDLE&, T100DX12FrameResource*);

    private:
        std::wstring                            m_title;

        void    SetCustomWindowText(LPCWSTR text);
        DXGI_FORMAT             ConvertFormat(T100DXGI_FORMAT);
};

#endif // T100DX12DISCRETE_H
