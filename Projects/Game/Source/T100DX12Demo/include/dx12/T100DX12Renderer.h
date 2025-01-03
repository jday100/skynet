#ifndef T100DX12RENDERER_H
#define T100DX12RENDERER_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#include <string>
#include <wrl.h>
#include <shellapi.h>

class T100DX12Renderer
{
    public:
        T100DX12Renderer(HWND hwnd);
        virtual ~T100DX12Renderer();

        void            create();
        void            destroy();

        void            start();
        void            stop();

        void            Render();

    protected:
        UINT            m_width;
        UINT            m_height;
        bool            m_useWarpDevice;
        HWND            m_hwnd;

        void            LoadPipeline();
        void            LoadAssets();

        void            GetHardwareAdapter(
                                           _In_ IDXGIFactory1*  pFactory,
                                           _Outptr_result_maybenull_ IDXGIAdapter1**    ppAdapter,
                                           bool requestHighPerformanceAdapter = false);

        void            PopulateCommandList();
        void            WaitForPreviousFrame();

    private:
        static const UINT   FrameCount  = 2;

        UINT                m_rtvDescriptorSize;
        UINT                m_frameIndex;

        HANDLE              m_fenceEvent;
        UINT64              m_fenceValue;

        Microsoft::WRL::ComPtr<ID3D12Fence>                 m_fence;
        Microsoft::WRL::ComPtr<IDXGISwapChain3>             m_swapChain;
        Microsoft::WRL::ComPtr<ID3D12Device>                m_device;
        Microsoft::WRL::ComPtr<ID3D12Resource>              m_renderTargets[FrameCount];
        Microsoft::WRL::ComPtr<ID3D12CommandAllocator>      m_commandAllocator;
        Microsoft::WRL::ComPtr<ID3D12CommandQueue>          m_commandQueue;
        Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>        m_rtvHeap;
        Microsoft::WRL::ComPtr<ID3D12PipelineState>         m_pipelineState;
        Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>   m_commandList;
};

#endif // T100DX12RENDERER_H
