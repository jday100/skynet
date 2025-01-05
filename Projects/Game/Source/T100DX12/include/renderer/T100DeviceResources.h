#ifndef T100DEVICERESOURCES_H
#define T100DEVICERESOURCES_H

#include <windows.h>

#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_6.h>
#include <d3dx12.h>

#include <wrl.h>

#include "T100Common.h"
#include "T100Size.h"
#include "directxmath.h"
#include "T100Frame.h"


using namespace DirectX;
using namespace Microsoft::WRL;


struct T100Orientation{
};


static const UINT       c_frameCount        = 3;

class T100DeviceResources
{
    public:
        T100DeviceResources(DXGI_FORMAT backBufferFormat = DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT depthBufferFormat = DXGI_FORMAT_D32_FLOAT);
        virtual ~T100DeviceResources();

        T100VOID                            SetFrame(T100Frame*);
        T100VOID                            SetLogicalSize(T100Size);
        T100VOID                            SetCurrentOrientation(T100Orientation currentOrientation);
        T100VOID                            SetDPI(float dpi);
        T100VOID                            ValidateDevice();
        T100VOID                            Present();
        T100VOID                            WaitForGpu();

        T100Size                            GetOutputSize() const;
        T100Size                            GetLogicalSize() const;

        float                               GetDPI() const;
        bool                                IsDeviceRemoved() const;

        ID3D12Device*                       GetD3DDevice() const;
        IDXGISwapChain3*                    GetSwapChain() const;
        ID3D12Resource*                     GetRenderTarget() const;
        ID3D12Resource*                     GetDepthStencil() const;
        ID3D12CommandQueue*                 GetCommandQueue() const;
        ID3D12CommandAllocator*             GetCommandAllocator() const;
        DXGI_FORMAT                         GetBackBufferFormat() const;
        DXGI_FORMAT                         GetDepthBufferFormat() const;
        D3D12_VIEWPORT                      GetScreenViewport() const;
        XMFLOAT4X4                          GetOrientationTransform3D() const;
        UINT                                GetCurrentFrameIndex() const;

        CD3DX12_CPU_DESCRIPTOR_HANDLE       GetRenderTargetView() const;
        CD3DX12_CPU_DESCRIPTOR_HANDLE       GetDepthStencilView() const;

    protected:

    private:
        T100VOID                            CreateDeviceIndependentResources();
        T100VOID                            CreateDeviceResources();
        T100VOID                            CreateWindowSizeDependentResources();
        T100VOID                            UpdateRenderTargetSize();
        T100VOID                            MoveToNextFrame();
        DXGI_MODE_ROTATION                  ComputeDisplayRotation();
        T100VOID                            GetHardwareAdapter(IDXGIAdapter1** ppAdapter);

        UINT                                m_currentFrame;

        ComPtr<ID3D12Device>                m_d3dDevice;
        ComPtr<IDXGIFactory4>               m_dxgiFactory;
        ComPtr<IDXGISwapChain3>             m_swapChain;
        ComPtr<ID3D12Resource>              m_renderTargets[c_frameCount];
        ComPtr<ID3D12Resource>              m_depthStencil;
        ComPtr<ID3D12DescriptorHeap>        m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>        m_dsvHeap;
        ComPtr<ID3D12CommandQueue>          m_commandQueue;
        ComPtr<ID3D12CommandAllocator>      m_commandAllocators[c_frameCount];

        DXGI_FORMAT                         m_backBufferFormat;
        DXGI_FORMAT                         m_depthBufferFormat;
        D3D12_VIEWPORT                      m_screenViewport;
        UINT                                m_rtvDescriptorSize;
        bool                                m_deviceRemoved;

        ComPtr<ID3D12Fence>                 m_fence;
        UINT64                              m_fenceValues[c_frameCount];
        HANDLE                              m_fenceEvent;

        T100Frame*                          m_frame;

        T100Size                            m_d3dRenderTargetSize;
        T100Size                            m_outputSize;
        T100Size                            m_logicalSize;
        T100Orientation                     m_nativeOrientation;
        T100Orientation                     m_currentOrientation;
        float                               m_dpi;

        float                               m_effectiveDPI;

        XMFLOAT4X4                          m_orientationTransform3D;
};

#endif // T100DEVICERESOURCES_H
