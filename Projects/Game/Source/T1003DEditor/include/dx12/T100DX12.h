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
#include "T100DX12EntityManager.h"

using Microsoft::WRL::ComPtr;

class T100DX12
{
    public:
        T100DX12();
        virtual ~T100DX12();

        virtual T100VOID                    Create(HWND, UINT, UINT);
        virtual T100VOID                    Destroy();

        virtual T100VOID                    SetSize(UINT, UINT);

        virtual T100VOID                    Start();
        virtual T100VOID                    Stop();

        virtual T100VOID                    Update();
        virtual T100VOID                    Render();

        virtual T100VOID                    Append(T100Entity*);

    protected:
        HWND                                m_hwnd;
        UINT                                m_width;
        UINT                                m_height;

        T100BOOL                            m_useWarpDevice;
        static const UINT                   m_frameCount            = 3;
        UINT                                m_frameIndex;

        UINT                                m_rtvDescriptorSize;
        UINT64                              m_fenceValue;
        HANDLE                              m_fenceEvent;

        T100DX12EntityManager               m_entity_manager;

        ComPtr<IDXGIFactory4>               m_factory;
        ComPtr<ID3D12Device>                m_device;
        ComPtr<ID3D12CommandQueue>          m_commandQueue;
        ComPtr<IDXGISwapChain3>             m_swapChain;

        ComPtr<ID3D12DescriptorHeap>        m_rtvHeap;

        ComPtr<ID3D12Resource>              m_renderTargets[m_frameCount];

        ComPtr<ID3D12CommandAllocator>      m_commandAllocator;
        ComPtr<ID3D12GraphicsCommandList>   m_commandList;
        ComPtr<ID3D12PipelineState>         m_pipelineState;
        ComPtr<ID3D12Fence>                 m_fence;

    protected:
        T100VOID                            CreateFactory();
        T100VOID                            CreateDevice();
        T100VOID                            CreateCommandQueue();
        T100VOID                            CreateSwapChain();

        T100VOID                            CreateRtvHeap();

        T100VOID                            CreateRenderTargetView();
        T100VOID                            CreateCommandAllocator();
        T100VOID                            SwapChainPresent();
        T100VOID                            WaitForPreviousFrame();

        T100VOID                            CreateCommandList();
        T100VOID                            CreateFence();

        T100VOID                            PopulateCommandList();
        T100VOID                            ExecuteCommandList();

        T100VOID                            GetHardwareAdapter(
                                                               _In_ IDXGIFactory1* pFactory,
                                                               _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
                                                               T100BOOL requestHighPerformanceAdapter = T100FALSE
                                                               );
    private:

    private:
        T100VOID                            LoadPipeline();
        T100VOID                            LoadPipelineEmpty();
        T100VOID                            LoadAssets();
        T100VOID                            LoadAssetsEmpty();

        T100VOID                            DoUpdate();
        T100VOID                            DoRender();
        T100VOID                            DoRenderEmpty();

};

#endif // T100DX12_H
