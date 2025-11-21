#ifndef T100DX12DYNAMIC_H
#define T100DX12DYNAMIC_H

#include "dx12/T100DX12Header.h"
#include "renderer/utils/T100DX12Timer.h"
#include "renderer/data/T100DX12Camera.h"
#include "renderer/T100DX12FrameResource.h"

#include "renderer/data/T100DX12Model.h"

class T100DX12Studio;

class T100DX12Dynamic
{
    public:
        T100DX12Dynamic(T100DX12Studio*);
        virtual ~T100DX12Dynamic();

        T100VOID                Create(HWND, UINT, UINT);
        T100VOID                Destroy();
        T100VOID                Start();

        T100VOID                Update();
        T100VOID                Render();

    DX12TextureResource Textures[1] =
    {
        { 1024, 1024, 1, DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } }, // city.dds
    };

    DX12DrawParameters Draws[1] =
    {
        { 0, -1, -1, 0, 18642, 0 },
    };

    protected:
        T100DX12Studio*             m_studioPtr         = T100NULL;


        HWND                        m_hwnd;
        UINT                        m_width;
        UINT                        m_height;
        float                       m_aspectRatio;
        bool                        m_useWarpDevice             = false;

        static const UINT           FrameCount = 3;
        static const UINT           CityRowCount = 15;
        static const UINT           CityColumnCount = 8;
        static const UINT           CityMaterialCount = CityRowCount * CityColumnCount;
        static const UINT           CityMaterialTextureWidth = 64;
        static const UINT           CityMaterialTextureHeight = 64;
        static const UINT           CityMaterialTextureChannelCount = 4;
        static const bool           UseBundles = true;
        static const float          CitySpacingInterval;

        struct Vertex
        {
            XMFLOAT3 position;
            XMFLOAT4 color;
        };

        // Pipeline objects.
        CD3DX12_VIEWPORT                    m_viewport;
        CD3DX12_RECT                        m_scissorRect;
        ComPtr<IDXGISwapChain3>             m_swapChain;
        ComPtr<ID3D12Device>                m_device;
        ComPtr<ID3D12Resource>              m_renderTargets[FrameCount];
        ComPtr<ID3D12Resource>              m_depthStencil;
        ComPtr<ID3D12CommandAllocator>      m_commandAllocator;
        ComPtr<ID3D12CommandQueue>          m_commandQueue;
        ComPtr<ID3D12RootSignature>         m_rootSignature;
        ComPtr<ID3D12DescriptorHeap>        m_rtvHeap;
        ComPtr<ID3D12DescriptorHeap>        m_cbvSrvHeap;
        ComPtr<ID3D12DescriptorHeap>        m_dsvHeap;
        ComPtr<ID3D12DescriptorHeap>        m_samplerHeap;
        ComPtr<ID3D12PipelineState>         m_pipelineState;
        ComPtr<ID3D12GraphicsCommandList>   m_commandList;

        // App resources.
        UINT                                m_numIndices;
        ComPtr<ID3D12Resource>              m_vertexBuffer;
        ComPtr<ID3D12Resource>              m_indexBuffer;
        ComPtr<ID3D12Resource>              m_cityDiffuseTexture;
        ComPtr<ID3D12Resource>              m_cityMaterialTextures[CityMaterialCount];
        D3D12_VERTEX_BUFFER_VIEW            m_vertexBufferView;
        D3D12_INDEX_BUFFER_VIEW             m_indexBufferView;

        UINT                                m_cbvSrvDescriptorSize;
        UINT                                m_rtvDescriptorSize;

        T100DX12Timer                       m_timer;
        T100DX12Camera                      m_camera;

        // Frame resources.
        std::vector<T100DX12FrameResource*>         m_frameResources;
        T100DX12FrameResource*                      m_pCurrentFrameResource;
        UINT                                        m_currentFrameResourceIndex;

        // Synchronization objects.
        UINT                                m_frameIndex;
        UINT                                m_frameCounter;
        HANDLE                              m_fenceEvent;
        ComPtr<ID3D12Fence>                 m_fence;
        UINT64                              m_fenceValue;

        void PopulateCommandList(T100DX12FrameResource* pFrameResource);
        void GetHardwareAdapter(
            _In_ IDXGIFactory1* pFactory,
            _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
            bool requestHighPerformanceAdapter = false);


    private:
        std::wstring    m_assetsPath;
        std::wstring    GetAssetFullPath(LPCWSTR assetName);

        void            loadPipeline();
        void            loadAssets();
        void            dx12Update();
        void            dx12Render();

        void            CreateFrameResources();
};

#endif // T100DX12DYNAMIC_H
