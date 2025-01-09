#ifndef T100DX12_H
#define T100DX12_H

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "d3dx12/d3dx12.h"

#include "T100Common.h"
#include "T100DX12Timer.h"
#include "T100DX12Camera.h"
#include "T100FrameResource.h"

using Microsoft::WRL::ComPtr;

class T100DX12
{
    public:
        T100DX12();
        virtual ~T100DX12();

        virtual T100BOOL                        Create(HWND, UINT, UINT);
        virtual T100BOOL                        Destroy();

        virtual T100BOOL                        Init();
        virtual T100BOOL                        Update();
        virtual T100BOOL                        Render();

        virtual T100VOID                        OnKeyDown(UINT8);
        virtual T100VOID                        OnKeyUp(UINT8);

    protected:
        HWND                                    m_hwnd;

        UINT                                    m_width;
        UINT                                    m_height;

        float                                   m_aspectRatio;
        T100BOOL                                m_useWarpDevice;

        std::wstring                            GetAssetFullPath(LPCWSTR assetName);
        void                                    SetCustomWindowText(LPCWSTR text);

    private:
        static const UINT                       FrameCount          = 3;
        static const UINT                       CityRowCount        = 10;
        static const UINT                       CityColumnCount     = 3;
        static const bool                       UseBundles          = true;

        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12Device>                    m_device;
        ComPtr<ID3D12Resource>                  m_renderTargets[FrameCount];
        ComPtr<ID3D12Resource>                  m_depthStencil;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;
        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;

        UINT                                    m_numIndices;
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        UINT                                    m_cbvSrvDescriptorSize;
        UINT                                    m_rtvDescriptorSize;

        std::vector<T100FrameResource*>         m_frameResources;
        T100FrameResource*                      m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;

        UINT                                    m_frameIndex;
        UINT                                    m_frameCounter;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;
        UINT64                                  m_fenceValue;

        std::wstring                            m_assetsPath;
        std::wstring                            m_title;

        T100DX12Timer                           m_timer;
        T100DX12Camera                          m_camera;

    private:
        T100BOOL                    m_load_pipeline();
        T100BOOL                    m_load_assets();
        T100BOOL                    m_create_frame_resources();
        T100BOOL                    m_populate_command_list(T100FrameResource* pFrameResource);


        T100BOOL                    m_get_hardwareAdapter(
                                                          _In_      IDXGIFactory1*      pFactory,
                                                          _Outptr_result_maybenull_     IDXGIAdapter1**     ppAdapter,
                                                          T100BOOL  requestHighPerformanceAdapter = T100FALSE
                                                          );

};

#endif // T100DX12_H
