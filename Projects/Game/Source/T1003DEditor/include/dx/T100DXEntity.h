#ifndef T100DXENTITY_H
#define T100DXENTITY_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"
#include "T100Entity.h"
#include "T100DXTimer.h"
#include "T100DXCamera.h"
#include "T100DXResource.h"

using Microsoft::WRL::ComPtr;

#define     T100DX12_COMMANDLIST_VECTOR         std::vector<ComPtr<ID3D12GraphicsCommandList>>

class T100DXEntity
{
    public:
        T100DXEntity();
        virtual ~T100DXEntity();

        virtual T100VOID                        Create(HWND, UINT, UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        SetSize(UINT, UINT);

        virtual T100VOID                        Append(T100Entity*);

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        static const bool                       m_useBundles            = T100TRUE;
        UINT                                    m_cityRowCount          = 10;
        UINT                                    m_cityColumnCount       = 3;

    protected:
        HWND                                    m_hwnd;
        UINT                                    m_width;
        UINT                                    m_height;

        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;

        float                                   m_aspectRatio;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        UINT                                    m_numIndices;
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        UINT                                    m_cbvSrvDescriptorSize;
        UINT                                    m_rtvDescriptorSize;

        ComPtr<ID3D12Resource>                  m_depthStencil;

        std::vector<T100DXResource*>            m_frameResources;
        T100DXResource*                         m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;

        static const UINT                       m_frameCount            = 3;

        T100BOOL                                m_useWarpDevice;

        ComPtr<IDXGIFactory4>                   m_factory;
        ComPtr<ID3D12Device>                    m_device;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;

        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;

        ComPtr<ID3D12Resource>                  m_renderTargets[m_frameCount];

        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;
        ComPtr<ID3D12Fence>                     m_fence;
        HANDLE                                  m_fenceEvent;
        UINT64                                  m_fenceValue;

        T100DXTimer                             m_timer;
        T100DXCamera                            m_camera;

        UINT                                    m_frameIndex;
        UINT                                    m_frameCounter;

    private:
        T100DX12_COMMANDLIST_VECTOR             m_commandLists;
        T100DX12_ENTITY_VECTOR                  m_entities;

        T100VOID                                LoadPipeline();

        T100VOID                                GetHardwareAdapter(
                                                                   _In_ IDXGIFactory1* pFactory,
                                                                   _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                                                   T100BOOL requestHighPerformanceAdapter = T100FALSE
                                                                   );
        T100VOID                                CreateFactory();
        T100VOID                                CreateDevice();
        T100VOID                                CreateCommandQueue();
        T100VOID                                CreateSwapChain();
        T100VOID                                CreateRtvHeap();
        T100VOID                                CreateDsvHeap();
        T100VOID                                CreateCbvHeap();
        T100VOID                                CreateSamplerHeap();
        T100VOID                                CreateRenderTargetViewEmpty();
        T100VOID                                CreateCommandAllocator();

        T100VOID                                LoadAssets();
        T100VOID                                CreateCommandListEmpty();
        T100VOID                                CreateFence();

        T100VOID                                PopulateCommandListEmpty();
        T100VOID                                ExecuteCommandListEmpty();
        T100VOID                                SwapChainPresent();
        T100VOID                                WaitForPreviousFrame();

        T100VOID                                LoadAllEntities();
        T100VOID                                LoadEntity(T100Entity*);

        T100VOID                                CreateRootSignature();
        T100VOID                                LoadShader(UINT8**, UINT&, UINT8**, UINT&, UINT8**, UINT&);
        T100VOID                                CreatePipelineState(UINT8*, UINT, UINT8*, UINT, UINT8*, UINT);
        T100VOID                                CreateCommandList();
        T100VOID                                CreateRenderTargetView();
        T100VOID                                LoadMeshData(UINT8**, UINT&);
        T100VOID                                CreateVertexBuffer(ComPtr<ID3D12Resource>&, UINT8*, UINT);
        T100VOID                                CreateIndexBuffer(ComPtr<ID3D12Resource>&, UINT8*, UINT);
        T100VOID                                CreateTexture(UINT&, UINT64&);
        T100VOID                                CreateSampler(ComPtr<ID3D12Resource>&, UINT8*, UINT, UINT, UINT64);
        T100VOID                                CreateTextureSRV();
        T100VOID                                CreateDepthStencilView();
        T100VOID                                ExecuteCommandList();

        T100VOID                                CreateFrameResources();

        T100VOID                                UpdateFrameTimer();
        T100VOID                                UpdateFence();
        T100VOID                                UpdateCamera();
        T100VOID                                UpdateFrameResource();

        T100VOID                                ExecuteCommandListRender();

        T100VOID                                PopulateCommandList(T100DXResource*);
        T100VOID                                FenceSignal();

        std::wstring                            m_assetsPath;
        std::wstring                            m_title;

        std::wstring                            GetAssetFullPath(LPCWSTR assetName);
        void                                    SetCustomWindowText(LPCWSTR text);

};

#endif // T100DXENTITY_H
