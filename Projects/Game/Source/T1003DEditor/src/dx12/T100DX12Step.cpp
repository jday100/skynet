#include "T100DX12Step.h"

#include "T100DX12Tools.h"

T100DX12Step::T100DX12Step() :
    m_useWarpDevice(T100FALSE)
{
    //ctor
}

T100DX12Step::~T100DX12Step()
{
    //dtor
}

T100VOID T100DX12Step::Create(HWND hwnd, UINT width, UINT height)
{
    m_hwnd      = hwnd;
    SetSize(width, height);
}

T100VOID T100DX12Step::Destroy()
{

}

T100VOID T100DX12Step::SetSize(UINT width, UINT height)
{

}

T100VOID T100DX12Step::Append()
{

}


T100VOID T100DX12Step::Start()
{
    Init();
}

T100VOID T100DX12Step::Stop()
{

}

T100VOID T100DX12Step::Init()
{

}

T100VOID T100DX12Step::Update()
{

}

T100VOID T100DX12Step::Render()
{

}

T100VOID T100DX12Step::LoadPipeline()
{
    CreateFactory();
    CreateDevice();
    CreateCommandQueue();
    CreateSwapChain();
    CreateRtvHeap();
    CreateDsvHeap();
    CreateCbvHeap();
    CreateSamplerHeap();
    CreateCommandAllocator();
}

T100VOID T100DX12Step::CreateFactory()
{
    UINT        dxgiFactoryFlags        = 0;

    ThrowIfFailed(CreateDXGIFactory2(
                                     dxgiFactoryFlags,
                                     IID_PPV_ARGS(&m_factory)
                                     ));
}

T100VOID T100DX12Step::CreateDevice()
{
    if(m_useWarpDevice)
    {
        ComPtr<IDXGIAdapter>        warpAdapter;

        ThrowIfFailed(m_factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

        ThrowIfFailed(D3D12CreateDevice(
                                        warpAdapter.Get(),
                                        D3D_FEATURE_LEVEL_12_0,
                                        IID_PPV_ARGS(&m_device)
                                        ));
    }
    else
    {
        ComPtr<IDXGIAdapter1>           hardwareAdapter;
        GetHardwareAdapter(m_factory.Get(), &hardwareAdapter);

        ThrowIfFailed(D3D12CreateDevice(
                                        hardwareAdapter.Get(),
                                        D3D_FEATURE_LEVEL_12_0,
                                        IID_PPV_ARGS(&m_device)
                                        ));
    }
}

_Use_decl_annotations_
T100VOID T100DX12Step::GetHardwareAdapter(
                                          IDXGIFactory1* pFactory,
                                          IDXGIAdapter1** ppAdapter,
                                          T100BOOL requestHighPerformanceAdapter
                                          )
{
    *ppAdapter          = T100NULL;

    ComPtr<IDXGIAdapter1>       adapter;
    ComPtr<IDXGIFactory6>       factory6;

    if(SUCCEEDED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6))))
    {
        for(
            UINT adapterIndex = 0;
            SUCCEEDED(factory6->EnumAdapterByGpuPreference(
                                                           adapterIndex,
                                                           requestHighPerformanceAdapter == T100TRUE ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                                                           IID_PPV_ARGS(&adapter)
                                                           ));
            ++adapterIndex
            )
        {
            DXGI_ADAPTER_DESC1          desc;
            adapter->GetDesc1(&desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if(SUCCEEDED(D3D12CreateDevice(
                                           adapter.Get(),
                                           D3D_FEATURE_LEVEL_12_0,
                                           __uuidof(ID3D12Device),
                                           T100NULL
                                           )))
            {
                break;
            }
        }
    }

    if(adapter.Get() == T100NULL)
    {
        for(
            UINT adapterIndex = 0;
            SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter));
            ++adapterIndex
            )
        {
            DXGI_ADAPTER_DESC1          desc;
            adapter->GetDesc1(&desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if(SUCCEEDED(D3D12CreateDevice(
                                           adapter.Get(),
                                           D3D_FEATURE_LEVEL_12_0,
                                           __uuidof(ID3D12Device),
                                           T100NULL
                                           )))
            {
                break;
            }
        }
    }

    *ppAdapter = adapter.Detach();
}

T100VOID T100DX12Step::CreateCommandQueue()
{
    D3D12_COMMAND_QUEUE_DESC            queueDesc           = {};

    queueDesc.Flags         = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type          = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(
                                               &queueDesc,
                                               IID_PPV_ARGS(&m_commandQueue)
                                               ));
}

T100VOID T100DX12Step::CreateSwapChain()
{
    DXGI_SWAP_CHAIN_DESC1               swapChainDesc       = {};

    swapChainDesc.BufferCount           = m_frameCount;
    swapChainDesc.Width                 = m_width;
    swapChainDesc.Height                = m_height;
    swapChainDesc.Format                = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count      = 1;

    ComPtr<IDXGISwapChain1>             swapChain;

    ThrowIfFailed(m_factory->CreateSwapChainForHwnd(
                                                    m_commandQueue.Get(),
                                                    m_hwnd,
                                                    &swapChainDesc,
                                                    T100NULL,
                                                    T100NULL,
                                                    &swapChain
                                                    ));

    ThrowIfFailed(m_factory->MakeWindowAssociation(
                                                   m_hwnd,
                                                   DXGI_MWA_NO_ALT_ENTER
                                                   ));

    ThrowIfFailed(swapChain.As(&m_swapChain));
    m_frameIndex    = m_swapChain->GetCurrentBackBufferIndex();
}

T100VOID T100DX12Step::CreateRtvHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          rtvHeapDesc         = {};

    rtvHeapDesc.NumDescriptors          = m_frameCount;
    rtvHeapDesc.Type                    = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags                   = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &rtvHeapDesc,
                                                 IID_PPV_ARGS(&m_rtvHeap)
                                                 ));
    m_rtvDescriptorSize     = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
}

T100VOID T100DX12Step::CreateDsvHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          dsvHeapDesc         = {};

    dsvHeapDesc.NumDescriptors          = 1;
    dsvHeapDesc.Type                    = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags                   = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &dsvHeapDesc,
                                                 IID_PPV_ARGS(&m_dsvHeap)
                                                 ));
}

T100VOID T100DX12Step::CreateCbvHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          cbvSrvHeapDesc      = {};

    cbvSrvHeapDesc.NumDescriptors       =
        m_frameCount * m_cityRowCount * m_cityColumnCount
        + 1;
    cbvSrvHeapDesc.Type                 = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    cbvSrvHeapDesc.Flags                = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &cbvSrvHeapDesc,
                                                 IID_PPV_ARGS(&m_cbvSrvHeap)
                                                 ));
    m_cbvSrvDescriptorSize      = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
}

T100VOID T100DX12Step::CreateSamplerHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          samplerHeapDesc     = {};

    samplerHeapDesc.NumDescriptors      = 1;
    samplerHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    samplerHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &samplerHeapDesc,
                                                 IID_PPV_ARGS(&m_samplerHeap)
                                                 ));

}

T100VOID T100DX12Step::CreateCommandAllocator()
{
    ThrowIfFailed(m_device->CreateCommandAllocator(
                                                   D3D12_COMMAND_LIST_TYPE_DIRECT,
                                                   IID_PPV_ARGS(&m_commandAllocator)
                                                   ));
}


