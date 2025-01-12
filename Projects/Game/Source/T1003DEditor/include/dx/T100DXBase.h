#ifndef T100DXBASE_H
#define T100DXBASE_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"

using Microsoft::WRL::ComPtr;

class T100DXBase
{
    public:
        T100DXBase();
        virtual ~T100DXBase();

        virtual T100VOID                        Create(HWND, UINT, UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        Start();
        virtual T100VOID                        Stop();

        virtual T100VOID                        SetSize(UINT, UINT);

        virtual T100VOID                        Render();

        UINT                                    m_cityRowCount;
        UINT                                    m_cityColumnCount;


    protected:
        HWND                                    m_hwnd;
        UINT                                    m_width;
        UINT                                    m_height;

        static const UINT                       m_frameCount            = 3;

        T100BOOL                                m_useWarpDevice;

        UINT                                    m_frameIndex;

        UINT                                    m_rtvDescriptorSize;
        UINT                                    m_cbvSrvDescriptorSize;

        ComPtr<IDXGIFactory4>                   m_factory;
        ComPtr<ID3D12Device>                    m_device;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;

        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;

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
};

#endif // T100DXBASE_H
