#ifndef T100DX12BUNDLETEST_H
#define T100DX12BUNDLETEST_H

#include "dx12/T100DX12header.h"

#include "data/T100DX12Timer.h"
#include "data/T100DX12Camera.h"
#include "test/T100DX12FrameResourceTest.h"



class T100DX12BundleTest
{
    public:
        T100DX12BundleTest();
        virtual ~T100DX12BundleTest();

        T100VOID        init(HWND);
        T100VOID        update();
        T100VOID        render();

        HWND            m_hwnd;
        UINT            m_width;
        UINT            m_height;

    LPCWSTR DataFileName = L"occcity.bin";

    const D3D12_INPUT_ELEMENT_DESC StandardVertexDescription[4] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, 24, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "TANGENT",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 32, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
    };
    UINT StandardVertexDescriptionNumElements = _countof(StandardVertexDescription);

    const UINT StandardVertexStride = 44;

    const DXGI_FORMAT StandardIndexFormat = DXGI_FORMAT_R32_UINT;

    struct TextureResource
    {
        UINT Width;
        UINT Height;
        UINT16 MipLevels;
        DXGI_FORMAT Format;
        struct DataProperties
        {
            UINT Offset;
            UINT Size;
            UINT Pitch;
        } Data[D3D12_REQ_MIP_LEVELS];
    };

    struct DrawParameters
    {
        INT DiffuseTextureIndex;
        INT NormalTextureIndex;
        INT SpecularTextureIndex;
        UINT IndexStart;
        UINT IndexCount;
        UINT VertexBase;
    };

    const UINT VertexDataOffset = 524288;
    const UINT VertexDataSize = 820248;
    const UINT IndexDataOffset = 1344536;
    const UINT IndexDataSize = 74568;

    TextureResource Textures[1] =
    {
        { 1024, 1024, 1, DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } }, // city.dds
    };

    DrawParameters Draws[1] =
    {
        { 0, -1, -1, 0, 18642, 0 },
    };

    protected:
        T100VOID        LoadPipeline();
        T100VOID        LoadAssets();

        T100VOID        CreateFrameResources();
        void PopulateCommandList(T100DX12FrameResourceTest* pFrameResource);

    private:

        T100DX12Timer   m_timer;

        bool m_useWarpDevice;


        float m_aspectRatio;

        std::wstring m_assetsPath;
        std::wstring GetAssetFullPath(LPCWSTR assetName);

    void GetHardwareAdapter(
        _In_ IDXGIFactory1* pFactory,
        _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
        bool requestHighPerformanceAdapter = false);

private:
    static const UINT FrameCount = 3;
    static const UINT CityRowCount = 10;
    static const UINT CityColumnCount = 3;
    static const bool UseBundles = false;

    // Pipeline objects.
    CD3DX12_VIEWPORT m_viewport;
    CD3DX12_RECT m_scissorRect;
    ComPtr<IDXGISwapChain3> m_swapChain;
    ComPtr<ID3D12Device> m_device;
    ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
    ComPtr<ID3D12Resource> m_depthStencil;
    ComPtr<ID3D12CommandAllocator> m_commandAllocator;
    ComPtr<ID3D12CommandQueue> m_commandQueue;
    ComPtr<ID3D12RootSignature >m_rootSignature;
    ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    ComPtr<ID3D12DescriptorHeap> m_cbvSrvHeap;
    ComPtr<ID3D12DescriptorHeap> m_dsvHeap;
    ComPtr<ID3D12DescriptorHeap> m_samplerHeap;
    ComPtr<ID3D12PipelineState> m_pipelineState1;
    ComPtr<ID3D12PipelineState> m_pipelineState2;
    ComPtr<ID3D12GraphicsCommandList> m_commandList;

    // App resources.
    UINT m_numIndices;
    ComPtr<ID3D12Resource> m_vertexBuffer;
    ComPtr<ID3D12Resource> m_indexBuffer;
    ComPtr<ID3D12Resource> m_texture;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
    D3D12_INDEX_BUFFER_VIEW m_indexBufferView;

    UINT m_cbvSrvDescriptorSize;
    UINT m_rtvDescriptorSize;
    T100DX12Camera m_camera;

    // Frame resources.
    std::vector<T100DX12FrameResourceTest*> m_frameResources;
    T100DX12FrameResourceTest* m_pCurrentFrameResource;
    UINT m_currentFrameResourceIndex;

    // Synchronization objects.
    UINT m_frameIndex;
    UINT m_frameCounter;
    HANDLE m_fenceEvent;
    ComPtr<ID3D12Fence> m_fence;
    UINT64 m_fenceValue;
};

#endif // T100DX12BUNDLETEST_H
