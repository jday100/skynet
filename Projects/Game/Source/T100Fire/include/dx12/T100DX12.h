#ifndef T100DX12_H
#define T100DX12_H

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"

using Microsoft::WRL::ComPtr;

class T100DX12
{
    public:
        T100DX12();
        virtual ~T100DX12();

        virtual T100VOID                        Create(HWND, UINT, UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        Init();
        virtual T100VOID                        Update();
        virtual T100VOID                        Render();

        virtual T100VOID                        SetSize(UINT, UINT);

        virtual T100VOID                        OnKeyDown(UINT8);
        virtual T100VOID                        OnKeyUp(UINT8);

    protected:
        HWND                                    m_hwnd;

        UINT                                    m_width;
        UINT                                    m_height;

        T100BOOL                                m_useWarpDevice;

    private:
        UINT                                    m_frameCount            = 3;
        UINT                                    m_CityRowCount          = 10;
        UINT                                    m_CityColumnCount       = 3;
        T100BOOL                                m_useBundles            = T100TRUE;

        UINT                                    m_frameIndex;
        UINT                                    m_frameCounter;

        ComPtr<ID3D12Device>                    m_device;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;

        UINT                                    m_cbvSrvDescriptorSize;
        UINT                                    m_rtvDescriptorSize;

        T100VOID                                LoadPipeline();
        T100VOID                                LoadResource();

        T100VOID                                GetHardwareAdapter(
                                                                   _In_      IDXGIFactory1*      pFactory,
                                                                   _Outptr_result_maybenull_     IDXGIAdapter1**     ppAdapter,
                                                                   T100BOOL  requestHighPerformanceAdapter = T100FALSE
                                                                   );
};

#endif // T100DX12_H
