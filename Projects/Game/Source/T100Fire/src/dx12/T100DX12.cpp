#include "T100DX12.h"

#include "T100DX12Tools.h"

T100DX12::T100DX12() :
    m_useWarpDevice(T100FALSE)
{
    //ctor
}

T100DX12::~T100DX12()
{
    //dtor
}

T100VOID T100DX12::Create(HWND hwnd, UINT width, UINT height)
{
    m_hwnd      = hwnd;
    SetSize(width, height);
}

T100VOID T100DX12::Destroy()
{

}

T100VOID T100DX12::Init()
{
    LoadPipeline();
    LoadResource();
}

T100VOID T100DX12::Update()
{

}

T100VOID T100DX12::Render()
{

}

T100VOID T100DX12::SetSize(UINT width, UINT height)
{
    m_width     = width;
    m_height    = height;
}

T100VOID T100DX12::OnKeyDown(UINT8 key)
{

}

T100VOID T100DX12::OnKeyUp(UINT8 key)
{

}

T100VOID T100DX12::LoadPipeline()
{
    UINT                            dxgiFactoryFlags        = 0;

    ComPtr<IDXGIFactory4>           factory;

    ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&factory)));

    if(m_useWarpDevice)
    {
        ComPtr<IDXGIAdapter>        warpAdapter;

        ThrowIfFailed(factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

        ThrowIfFailed(D3D12CreateDevice(
                      warpAdapter.Get(),
                      D3D_FEATURE_LEVEL_11_0,
                      IID_PPV_ARGS(&m_device)
                      ));
    }
    else
    {
        ComPtr<IDXGIAdapter1>       hardwareAdapter;
        GetHardwareAdapter(factory.Get(), &hardwareAdapter);

        ThrowIfFailed(D3D12CreateDevice(
                      hardwareAdapter.Get(),
                      D3D_FEATURE_LEVEL_11_0,
                      IID_PPV_ARGS(&m_device)
                      ));
    }

    D3D12_COMMAND_QUEUE_DESC        queueDesc       = {};

    queueDesc.Flags     = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type      = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)));

    DXGI_SWAP_CHAIN_DESC1               swapChainDesc   = {};

    swapChainDesc.BufferCount           = m_frameCount;
    swapChainDesc.Width                 = m_width;
    swapChainDesc.Height                = m_height;
    swapChainDesc.Format                = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count      = 1;

    ComPtr<IDXGISwapChain1>             swapChain;

    ThrowIfFailed(factory->CreateSwapChainForHwnd(
                  m_commandQueue.Get(),
                  m_hwnd,
                  &swapChainDesc,
                  nullptr,
                  nullptr,
                  &swapChain
                  ));

    ThrowIfFailed(factory->MakeWindowAssociation(m_hwnd, DXGI_MWA_NO_ALT_ENTER));

    ThrowIfFailed(swapChain.As(&m_swapChain));
    m_frameIndex    = m_swapChain->GetCurrentBackBufferIndex();

    {
        D3D12_DESCRIPTOR_HEAP_DESC      rtvHeapDesc     = {};

        rtvHeapDesc.NumDescriptors      = m_frameCount;
        rtvHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        ThrowIfFailed(m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap)));

        D3D12_DESCRIPTOR_HEAP_DESC      dsvHeapDesc     = {};

        dsvHeapDesc.NumDescriptors      = 1;
        dsvHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
        dsvHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        ThrowIfFailed(m_device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(&m_dsvHeap)));

        D3D12_DESCRIPTOR_HEAP_DESC      cbvSrvHeapDesc      = {};

        cbvSrvHeapDesc.NumDescriptors   =
            m_frameCount * m_CityRowCount * m_CityColumnCount
            + 1;

        cbvSrvHeapDesc.Type             = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        cbvSrvHeapDesc.Flags            = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

        ThrowIfFailed(m_device->CreateDescriptorHeap(&cbvSrvHeapDesc, IID_PPV_ARGS(&m_cbvSrvHeap)));

        D3D12_DESCRIPTOR_HEAP_DESC      samplerHeapDesc      = {};

        samplerHeapDesc.NumDescriptors  = 1;
        samplerHeapDesc.Type            = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
        samplerHeapDesc.Flags           = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

        ThrowIfFailed(m_device->CreateDescriptorHeap(&samplerHeapDesc, IID_PPV_ARGS(&m_samplerHeap)));

        m_rtvDescriptorSize             = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
        m_cbvSrvDescriptorSize          = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
    }

    ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));

}

T100VOID T100DX12::LoadResource()
{

}

_Use_decl_annotations_
T100VOID T100DX12::GetHardwareAdapter(
    IDXGIFactory1* pFactory,
    IDXGIAdapter1** ppAdapter,
    T100BOOL requestHighPerformanceAdapter)
{
    *ppAdapter      = T100NULL;

    ComPtr<IDXGIAdapter1>       adapter;
    ComPtr<IDXGIFactory6>       factory6;

    if (SUCCEEDED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6))))
    {
        for (
            UINT            adapterIndex = 0;
            SUCCEEDED(factory6->EnumAdapterByGpuPreference(
                adapterIndex,
                requestHighPerformanceAdapter == T100TRUE ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                IID_PPV_ARGS(&adapter)));
            ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1              desc;
            adapter->GetDesc1(&desc);

            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), T100NULL)))
            {
                break;
            }
        }
    }

    if(adapter.Get() == T100NULL)
    {
        for (UINT adapterIndex = 0; SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter)); ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1          desc;
            adapter->GetDesc1(&desc);

            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), T100NULL)))
            {
                break;
            }
        }
    }

    *ppAdapter = adapter.Detach();
}
