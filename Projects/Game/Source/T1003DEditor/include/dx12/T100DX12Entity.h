#ifndef T100DX12ENTITY_H
#define T100DX12ENTITY_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"
#include "T100Entity.h"

#include "T100DX12Timer.h"
#include "T100DX12Camera.h"
#include "T100DX12FrameResource.h"
#include "T100DX12EntityManager.h"

class T100DX12Entity
{
    friend class T100DX12EntityManager;
    public:
        T100DX12Entity();
        virtual ~T100DX12Entity();

        virtual T100VOID                        Create(HWND, UINT, UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        SetSize(UINT, UINT);

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        Append(T100Entity*);

        virtual T100VOID                        OnKeyDown(UINT8);
        virtual T100VOID                        OnKeyUp(UINT8);

        static const bool                       m_useBundles            = T100TRUE;
        UINT                                    m_cityRowCount          = 10;
        UINT                                    m_cityColumnCount       = 3;

    protected:
        HWND                                    m_hwnd;
        UINT                                    m_width;
        UINT                                    m_height;

        T100BOOL                                m_useWarpDevice;
        static const UINT                       m_frameCount            = 3;

        T100DX12EntityManager                   m_entityManager;

        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;

        ComPtr<IDXGIFactory4>                   m_factory;
        ComPtr<ID3D12Device>                    m_device;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;

        ComPtr<ID3D12Resource>                  m_renderTargets[m_frameCount];

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

        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;

        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;

        ComPtr<ID3D12Resource>                  m_depthStencil;

        std::vector<T100DX12FrameResource*>     m_frameResources;
        T100DX12FrameResource*                  m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;

        UINT                                    m_frameIndex;
        UINT                                    m_frameCounter;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;
        UINT64                                  m_fenceValue;

        T100DX12Timer                           m_timer;
        T100DX12Camera                          m_camera;

        float                                   m_aspectRatio;

    private:
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
        T100VOID                                CreateCommandAllocator();

        T100VOID                                LoadAssets();
        T100VOID                                LoadAssetsSingle();

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
        T100VOID                                CreateFence();
        T100VOID                                CreateFrameResources();

        T100VOID                                UpdateFrameTimer();
        T100VOID                                UpdateFence();
        T100VOID                                UpdateCamera();
        T100VOID                                UpdateFrameResource();

        T100VOID                                PopulateCommandList(T100DX12FrameResource*);
        T100VOID                                ExecuteCommandListRender();
        T100VOID                                SwapChainPresent();
        T100VOID                                FenceSignal();
        T100VOID                                WaitForPreviousFrame();

        std::wstring                            m_assetsPath;
        std::wstring                            m_title;

        std::wstring                            GetAssetFullPath(LPCWSTR assetName);
        void                                    SetCustomWindowText(LPCWSTR text);

    private:
        T100VOID                                LoadPipelineEmpty();
        T100VOID                                LoadAssetsEmpty();
        T100VOID                                CreateCommandListEmpty();
        T100VOID                                PopulateCommandListEmpty();
        T100VOID                                ExecuteCommandListEmpty();
};

#endif // T100DX12ENTITY_H
