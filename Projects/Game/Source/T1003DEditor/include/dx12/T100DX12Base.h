#ifndef T100DX12BASE_H
#define T100DX12BASE_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"
#include "T100DX12FrameResource.h"
#include "T100DX12EntityManager.h"

using Microsoft::WRL::ComPtr;

class T100DX12Base
{
    public:
        T100DX12Base();
        virtual ~T100DX12Base();

        virtual T100VOID                    Create(HWND, UINT, UINT);
        virtual T100VOID                    Destroy();

        virtual T100VOID                    SetSize(UINT, UINT);

        virtual T100VOID                    Start();
        virtual T100VOID                    Stop();

        virtual T100VOID                    Update();
        virtual T100VOID                    Render();

    protected:
        HWND                                m_hwnd;
        UINT                                m_width;
        UINT                                m_height;

        T100DX12FrameResource               m_frameResource;
        T100DX12EntityManager               m_entityManager;

    protected:
        T100BOOL                            m_useWarpDevice;
        static const UINT                   m_frameCount            = 3;
        UINT                                m_frameIndex;
        UINT                                m_frameCounter;
        UINT                                m_rtvDescriptorSize;

        ComPtr<ID3D12Resource>              m_renderTargets[m_frameCount];

        ComPtr<ID3D12Fence>                 m_fence;
        HANDLE                              m_fenceEvent;
        UINT64                              m_fenceValue;

        ComPtr<IDXGIFactory4>               m_factory;
        ComPtr<ID3D12Device>                m_device;
        ComPtr<IDXGISwapChain3>             m_swapChain;
        ComPtr<ID3D12CommandQueue>          m_commandQueue;
        ComPtr<ID3D12CommandAllocator>      m_commandAllocator;

        ComPtr<ID3D12GraphicsCommandList>   m_commandList;
        ComPtr<ID3D12PipelineState>         m_pipelineState;

        ComPtr<ID3D12DescriptorHeap>        m_rtvHeap;


    protected:
        virtual T100VOID                    LoadPipeline();
        virtual T100VOID                    GetHardwareAdapter(
                                                               _In_ IDXGIFactory1* pFactory,
                                                               _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                                               T100BOOL requestHighPerformanceAdapter = T100FALSE
                                                               );
        virtual T100VOID                    CreateFactory();
        virtual T100VOID                    CreateDevice();
        virtual T100VOID                    CreateCommandQueue();
        virtual T100VOID                    CreateSwapChain();
        virtual T100VOID                    CreateRtvHeap();
        virtual T100VOID                    CreateRenderTargetView();
        virtual T100VOID                    CreateCommandAllocator();

        virtual T100VOID                    LoadAssets();
        virtual T100VOID                    CreateCommandList();
        virtual T100VOID                    CreateFence();

        virtual T100VOID                    PopulateCommandList();
        virtual T100VOID                    ExecuteCommandList();
        virtual T100VOID                    SwapChainPresent();
        virtual T100VOID                    WaitForPreviousFrame();

    private:
        T100VOID                            init();
        T100VOID                            uninit();

};

#endif // T100DX12BASE_H
