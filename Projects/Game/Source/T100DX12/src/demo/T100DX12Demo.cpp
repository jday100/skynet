#include "T100DX12Demo.h"

T100DX12Demo::T100DX12Demo(UINT width, UINT height, std::wstring name)
    :T100Game(width, height, name)
{
    //ctor
}

T100DX12Demo::~T100DX12Demo()
{
    //dtor
}

T100VOID T100DX12Demo::OnInit()
{
    m_camera.Init({8, 8, 30});

    LoadPipeline();
    LoadAssets();
}

T100VOID T100DX12Demo::OnUpdate()
{

}

T100VOID T100DX12Demo::OnRender()
{

}

T100VOID T100DX12Demo::OnDestroy()
{

}

void T100DX12Demo::LoadPipeline()
{
    UINT    dxgiFactoryFlags    = 0;

    #if defined(_DEBUG)
        {
            ComPtr<ID3D12Debug> debugController;
            if(SUCCEEDED(D3D12GetDebugInsterface(IID_PPV_ARGS(&debugController))))
            {
                debugController->EnableDebugLayer();

                dxgiFactoryFlags != DXGI_CREATE_FACTORY_DEBUG;
            }
        }
    #endif // defined

    ComPtr<IDXGIFactory4>       factory;
    ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&factory)));

    if(m_useWarpDevice)
    {
        ComPtr<IDXGIAdapter>    warpAdapter;
        ThrowIfFailed(factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

        ThrowIfFailed(D3D12CreateDevice(
                                    warpAdapter.Get(),
                                    D3D_FEATURE_LEVEL_11_0,
                                    IID_PPV_ARGS(&m_device)
                                    ));
    }
    else
    {
        ComPtr<IDXGIAdapter>    hardwareAdapter;
        GetHardwareAdapter(factory.Get(), &hardwareAdapter);

        ThrowIfFailed(D3D12CreateDevice(
                                        hardwareAdapter.Get(),
                                        D3D_FEATURE_LEVEL_11_0,
                                        IID_PPV_ARGS(&m_device)
                                        ));
    }

    D3D12_COMMAND_QUEUE_DESC        queueDesc   = {};

    queueDesc.Flags     = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type      = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)));
    NAME_D3D12_OBJECT(m_commandQueue);

    DXGI_SWAP_CHAIN_DESC1       swapChainDesc       = {};

    swapChainDesc.BufferCount       = FrameCount;
    swapChainDesc.Width             = m_width;
    swapChainDesc.Height            = m_height;
    swapChainDesc.Format            = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect        = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count  = 1;

    ComPtr<IDXGISwapChain1>     swapChain;
    ThrowIfFailed(factory->CreateSwapChainForHwnd(
                                                  m_commandQueue.Get(),
                                                  T100Frame::GetHwnd(),
                                                  &swapChainDesc,
                                                  nullptr,
                                                  nullptr,
                                                  &swapChain
                                                  ));

    ThrowIfFailed(factory->MakeWindowAssociation(T100Frame::GetHwnd(), DXGI_MWA_NO_ALT_ENTER));

    ThrowIfFailed(swapChain.As(&m_swapChain));
    m_frameIndex    = m_swapChain->GetCurrentBackBufferIndex();

    {
        D3D12_DESCRIPTOR_HEAP_DESC      rtvHeapDesc     = {};

        rtvHeapDesc.NumDescriptors      = FrameCount;
        rtvHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        ThrowIfFailed(m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap)));

        D3D12_DESCRIPTOR_HEAP_DESC      dsvHeapDesc     = {};

        dsvHeapDesc.NumDescriptors      = 1;
        dsvHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
        dsvHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        ThrowIfFailed(m_device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(&m_dsvHeap)));

        D3D12_DESCRIPTOR_HEAP_DESC      cbvSrvHeapDesc  = {};

        cbvSrvHeapDesc.NumDescriptors   = FrameCount * CityRowCount * CityColumnCount + 1;
        cbvSrvHeapDesc.TYpe             = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        cbvSrvHeapDesc.Flags            = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        ThrowIfFailed(m_device->CreateDescriptorHeap(&cbvSrvHeapDesc, IID_PPV_ARGS(&m_cbvSrvHeap)));
        NAME_D3D12_OBJECT(m_cbvSrvHeap);

        D3D12_DESCRIPTOR_HEAP_DESC      samplerHeapDesc = {};

        samplerHeapDesc.NumDescriptors  = 1;
        samplerHeapDesc.Type            = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
        samplerHeapDesc.Flags           = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        ThrowIfFailed(m_device->CreateDescriptorHeap(&samplerHeapDesc, IID_PPV_ARGS(&m_samplerHeap)));

        m_rtvDescriptorSize     = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
        m_cbvSrvDescriptorSize  = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
    }

    ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
}

void T100DX12Demo::LoadAssets()
{

}
