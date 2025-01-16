#ifndef T100DX12_H
#define T100DX12_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"
#include "T100Entity.h"
#include "T100City.h"
#include "T100DX12Timer.h"
#include "T100DX12Camera.h"
#include "T100DX12EntityManager.h"
#include "T100DX12FrameResource.h"

using Microsoft::WRL::ComPtr;

class T100DX12
{
    friend class T100DX12EntityManager;
    public:
        T100DX12();
        virtual ~T100DX12();

        virtual T100VOID                        Create(HWND, UINT, UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        SetSize(UINT, UINT);

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        Append(T100Entity*);

    protected:
        HWND                                    m_hwnd;
        UINT                                    m_width;
        UINT                                    m_height;

        T100BOOL                                m_useWarpDevice;
        static const UINT                       m_frameCount            = 3;

        UINT                                    m_rtvDescriptorSize;
        UINT                                    m_cbvSrvDescriptorSize;

        float                                   m_aspectRatio;

        UINT                                    m_frameIndex;
        UINT                                    m_frameCounter;
        HANDLE                                  m_fenceEvent;
        UINT64                                  m_fenceValue;

        T100DX12EntityManager                   m_entity_manager;
        T100DX12Timer                           m_timer;
        T100DX12Camera                          m_camera;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;

        UINT                                    m_numIndices;
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        ComPtr<ID3D12Resource>                  m_depthStencil;

        std::vector<T100DX12FrameResource*>     m_frameResources;
        T100DX12FrameResource*                  m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;

        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;

        ComPtr<IDXGIFactory4>                   m_factory;
        ComPtr<ID3D12Device>                    m_device;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<IDXGISwapChain3>                 m_swapChain;

        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;

        ComPtr<ID3D12Resource>                  m_renderTargets[m_frameCount];

        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;
        ComPtr<ID3D12PipelineState>             m_pipelineState;
        ComPtr<ID3D12Fence>                     m_fence;

    protected:
        T100VOID                                CreateFactory();
        T100VOID                                CreateDevice();
        T100VOID                                CreateCommandQueue();
        T100VOID                                CreateSwapChain();

        T100VOID                                CreateRtvHeap();
        T100VOID                                CreateDsvHeap();
        T100VOID                                CreateCbvHeap(UINT, UINT);
        T100VOID                                CreateSamplerHeap();

        T100VOID                                CreateRenderTargetView();
        T100VOID                                CreateCommandAllocator();
        T100VOID                                SwapChainPresent();
        T100VOID                                WaitForPreviousFrame();

        T100VOID                                CreateCommandList();
        T100VOID                                CreateFence();

        T100VOID                                PopulateCommandList();
        T100VOID                                ExecuteCommandList();

        T100VOID                                GetHardwareAdapter(
                                                               _In_ IDXGIFactory1* pFactory,
                                                               _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                                               T100BOOL requestHighPerformanceAdapter = T100FALSE
                                                               );

    protected:
        T100VOID                                CreateRootSignature();
        T100VOID                                LoadShaderFile(T100WSTRING, UINT8**, UINT&);
        T100VOID                                CreatePipelineState(const D3D12_INPUT_ELEMENT_DESC*, UINT,
                                                                UINT8*, UINT,
                                                                UINT8*, UINT,
                                                                UINT8*, UINT);
        T100VOID                                LoadMeshFile(T100WSTRING, UINT8**, UINT&);
        T100VOID                                CreateVertexBuffer(
                                                               UINT, UINT, UINT,
                                                               ComPtr<ID3D12Resource>&, UINT8*, UINT);
        T100VOID                                CreateIndexBuffer(
                                                              UINT, UINT, const DXGI_FORMAT,
                                                              ComPtr<ID3D12Resource>&, UINT8*, UINT);
        T100VOID                                CreateTexture(const T100City::TextureResource*, UINT&, UINT64&);
        T100VOID                                CreateSampler(const T100City::TextureResource*, ComPtr<ID3D12Resource>&, UINT8*, UINT, UINT, UINT64);
        T100VOID                                CreateTextureSRV(const T100City::TextureResource*);
        T100VOID                                CreateDepthStencilView();

        T100VOID                                CreateFrameResources(UINT, UINT);

        T100VOID                                UpdateFrameTimer();
        T100VOID                                UpdateFence();
        T100VOID                                UpdateCamera();
        T100VOID                                UpdateFrameResource();

        T100VOID                                PopulateCommandList(T100BOOL, T100DX12FrameResource*);
        T100VOID                                ExecuteCommandListRender();
        T100VOID                                FenceSignal();

        std::wstring                            GetAssetFullPath(LPCWSTR assetName);
        void                                    SetCustomWindowText(LPCWSTR text);

    private:
        std::wstring                            m_assetsPath;
        std::wstring                            m_title;

    private:
        T100VOID                                LoadPipeline();
        T100VOID                                LoadPipelineEmpty();
        T100VOID                                LoadAssets();
        T100VOID                                LoadAssetsEmpty();

        T100VOID                                DoUpdate();
        T100VOID                                DoRender();
        T100VOID                                DoRenderEmpty();

};

#endif // T100DX12_H
