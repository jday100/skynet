#include "T100Demo.h"

#include "occcity.h"

T100Demo::T100Demo(UINT widht, UINT height, std::wstring name) :
    T100DX12(width, height, name),
    m_frameIndex(0),
    m_viewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height)),
    m_scissorRect(0, 0, static_cast<LONG>(width), static_cast<LONG>(height)),
    m_frameCounter(0),
    m_fenceValue(0),
    m_rtvDescriptorSize(0),
    m_currentFrameResourceIndex(0),
    m_pCurrentFrameResource(nullptr)

{
    //ctor
}

T100Demo::~T100Demo()
{
    //dtor
}

void T100Demo::OnInit()
{
    m_camera.Init({8, 8, 30});

    LoadPipeline();
    LoadAssets();
}

void T100Demo::LoadPipeline()
{
    UINT            dxgiFactoryFlags        = 0;

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

    D3D12_COMMAND_QUEUE_DESC            queueDesc       = {};

    queueDesc.Flags     = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type      = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)));

    DXGI_SWAP_CHAIN_DESC1               swapChainDesc   = {};

    swapChainDesc.BufferCount           = FrameCount;
    swapChainDesc.Width                 = m_width;
    swapChainDesc.Height                = m_height;
    swapChainDesc.Format                = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count      = 1;

    ComPtr<IDXGISwapChain1>             swapChain;

    ThrowIfFailed(factory->CreateSwapChainForHwnd(
                  m_commandQueue.Get(),
                  T100Application::GetHwnd(),
                  &swapChainDesc,
                  nullptr,
                  nullptr,
                  &swapChain
                  ));

    ThrowIfFailed(factory->MakeWindowAssociation(T100Application::GetHwnd(), DXGI_MWA_NO_ALT_ENTER));

    ThrowIfFailed(swapChain.As(&m_swapChain));
    m_frameIndex    = m_swapChain->GetCurrentBackBufferIndex();

    {

    }


}
