#ifndef T100DX12_H
#define T100DX12_H

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "d3d12/d3dx12.h"

#include "T100Common.h"
#include "T100Entity.h"
#include "T100DX12Timer.h"
#include "T100DX12Camera.h"
#include "T100DX12Resource.h"

using Microsoft::WRL::ComPtr;

class T100DX12
{
    public:
        T100DX12();
        virtual ~T100DX12();

        virtual T100VOID                        Create(HWND, UINT, UINT);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        Load(T100ENTITY_VECTOR&);

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

        float                                   m_aspectRatio;
        T100BOOL                                m_useWarpDevice;

        std::wstring                            GetAssetFullPath(LPCWSTR assetName);
        T100VOID                                SetCustomWindowText(LPCWSTR text);

    private:
        static const UINT                       m_frameCount            = 3;
        UINT                                    m_CityRowCount          = 10;
        UINT                                    m_CityColumnCount       = 3;
        T100BOOL                                m_useBundles            = T100TRUE;

        ComPtr<ID3D12Device>                    m_device;
        ComPtr<IDXGISwapChain3>                 m_swapChain;
        ComPtr<ID3D12CommandQueue>              m_commandQueue;
        ComPtr<ID3D12CommandAllocator>          m_commandAllocator;

        ComPtr<ID3D12Resource>                  m_renderTargets[m_frameCount];
        ComPtr<ID3D12Resource>                  m_depthStencil;

        ComPtr<ID3D12RootSignature>             m_rootSignature;
        ComPtr<ID3D12DescriptorHeap>            m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>            m_samplerHeap;

        ComPtr<ID3D12PipelineState>             m_pipelineState1;
        ComPtr<ID3D12PipelineState>             m_pipelineState2;
        ComPtr<ID3D12GraphicsCommandList>       m_commandList;

        CD3DX12_VIEWPORT                        m_viewport;
        CD3DX12_RECT                            m_scissorRect;

        UINT                                    m_numIndices;
        ComPtr<ID3D12Resource>                  m_vertexBuffer;
        ComPtr<ID3D12Resource>                  m_indexBuffer;
        ComPtr<ID3D12Resource>                  m_texture;
        D3D12_VERTEX_BUFFER_VIEW                m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW                 m_indexBufferView;

        UINT                                    m_frameIndex;
        UINT                                    m_frameCounter;
        HANDLE                                  m_fenceEvent;
        ComPtr<ID3D12Fence>                     m_fence;
        UINT64                                  m_fenceValue;

        UINT                                    m_cbvSrvDescriptorSize;
        UINT                                    m_rtvDescriptorSize;

        std::vector<T100DX12Resource*>          m_frameResources;
        T100DX12Resource*                       m_pCurrentFrameResource;
        UINT                                    m_currentFrameResourceIndex;


        std::wstring                            m_assetsPath;
        std::wstring                            m_title;

        T100DX12Timer                           m_timer;
        T100DX12Camera                          m_camera;

        T100VOID                                LoadPipeline();
        T100VOID                                LoadResource();

        T100VOID                                LoadFile(ComPtr<ID3D12Resource>&, ComPtr<ID3D12Resource>&, ComPtr<ID3D12Resource>&);

        T100VOID                                CreateFrameResources();
        T100VOID                                PopulateCommandList(T100DX12Resource* pFrameResource);

        T100VOID                                GetHardwareAdapter(
                                                                   _In_      IDXGIFactory1*      pFactory,
                                                                   _Outptr_result_maybenull_     IDXGIAdapter1**     ppAdapter,
                                                                   T100BOOL  requestHighPerformanceAdapter = T100FALSE
                                                                   );
};

#endif // T100DX12_H
