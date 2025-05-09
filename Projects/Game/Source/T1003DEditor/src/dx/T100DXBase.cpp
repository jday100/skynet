#include "T100DXBase.h"

#include "T100DX12Tools.h"

T100DXBase::T100DXBase() :
    m_useWarpDevice(T100FALSE),
    m_frameIndex(0),
    m_rtvDescriptorSize(0),
    m_fenceValue(0)
{
    //ctor
}

T100DXBase::~T100DXBase()
{
    //dtor
}

T100VOID T100DXBase::Create(HWND hwnd, UINT width, UINT height)
{
    m_hwnd      = hwnd;
    m_width     = width;
    m_height    = height;
}

T100VOID T100DXBase::Destroy()
{

}

T100VOID T100DXBase::SetSize(UINT width, UINT height)
{
    m_width     = width;
    m_height    = height;
}

T100VOID T100DXBase::Start()
{
    LoadPipeline();
    LoadAssets();
}

T100VOID T100DXBase::Stop()
{

}

T100VOID T100DXBase::Update()
{

}

T100VOID T100DXBase::Render()
{
    PopulateCommandList();
    ExecuteCommandList();
    SwapChainPresent();
    WaitForPreviousFrame();
}

T100VOID T100DXBase::Append(T100Entity* entity)
{

}

T100VOID T100DXBase::CreateFactory()
{
    UINT        dxgiFactoryFlags        = 0;

    ThrowIfFailed(CreateDXGIFactory2(
                                     dxgiFactoryFlags,
                                     IID_PPV_ARGS(&m_factory)
                                     ));
}

T100VOID T100DXBase::CreateDevice()
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
T100VOID T100DXBase::GetHardwareAdapter(
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

T100VOID T100DXBase::CreateCommandQueue()
{
    D3D12_COMMAND_QUEUE_DESC            queueDesc           = {};

    queueDesc.Flags         = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type          = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(
                                               &queueDesc,
                                               IID_PPV_ARGS(&m_commandQueue)
                                               ));
}

T100VOID T100DXBase::CreateSwapChain()
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

T100VOID T100DXBase::CreateRtvHeap()
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

T100VOID T100DXBase::CreateRenderTargetView()
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE       rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

    for(UINT n = 0; n < m_frameCount; n++)
    {
        ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
        m_device->CreateRenderTargetView(m_renderTargets[n].Get(), T100NULL, rtvHandle);
        rtvHandle.Offset(1, m_rtvDescriptorSize);
    }
}

T100VOID T100DXBase::CreateCommandAllocator()
{
    ThrowIfFailed(m_device->CreateCommandAllocator(
                                                   D3D12_COMMAND_LIST_TYPE_DIRECT,
                                                   IID_PPV_ARGS(&m_commandAllocator)
                                                   ));
}

T100VOID T100DXBase::LoadPipeline()
{
    CreateFactory();
    CreateDevice();
    CreateCommandQueue();
    CreateSwapChain();
    CreateRtvHeap();
    CreateRenderTargetView();
    CreateCommandAllocator();
}

T100VOID T100DXBase::LoadAssets()
{
    CreateCommandList();
    CreateFence();
}

T100VOID T100DXBase::CreateCommandList()
{
    ThrowIfFailed(m_device->CreateCommandList(
                                              0,
                                              D3D12_COMMAND_LIST_TYPE_DIRECT,
                                              m_commandAllocator.Get(),
                                              T100NULL,
                                              IID_PPV_ARGS(&m_commandList)
                                              ));
    ThrowIfFailed(m_commandList->Close());
}

T100VOID T100DXBase::CreateFence()
{
    ThrowIfFailed(m_device->CreateFence(
                                        0,
                                        D3D12_FENCE_FLAG_NONE,
                                        IID_PPV_ARGS(&m_fence)
                                        ));
    m_fenceValue        = 1;

    m_fenceEvent        = CreateEvent(T100NULL, T100FALSE, T100FALSE, T100NULL);
    if(m_fenceEvent == T100NULL)
    {
        ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
    }
}

T100VOID T100DXBase::PopulateCommandList()
{
    ThrowIfFailed(m_commandAllocator->Reset());

    ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get()));

    CD3DX12_RESOURCE_BARRIER    barrier1 = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                m_renderTargets[m_frameIndex].Get(),
                                                                                D3D12_RESOURCE_STATE_PRESENT,
                                                                                D3D12_RESOURCE_STATE_RENDER_TARGET
                                                                                );
    m_commandList->ResourceBarrier(1, &barrier1);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);

    const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);

    CD3DX12_RESOURCE_BARRIER    barrier2 = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                m_renderTargets[m_frameIndex].Get(),
                                                                                D3D12_RESOURCE_STATE_RENDER_TARGET,
                                                                                D3D12_RESOURCE_STATE_PRESENT
                                                                                );
    m_commandList->ResourceBarrier(1, &barrier2);

    ThrowIfFailed(m_commandList->Close());
}

T100VOID T100DXBase::ExecuteCommandList()
{
    ID3D12CommandList* ppCommandLists[] = {m_commandList.Get()};
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
}

T100VOID T100DXBase::SwapChainPresent()
{
    ThrowIfFailed(m_swapChain->Present(1, 0));
}

T100VOID T100DXBase::WaitForPreviousFrame()
{
    const UINT64        fence = m_fenceValue;
    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fence));
    m_fenceValue++;

    if(m_fence->GetCompletedValue() < fence)
    {
        ThrowIfFailed(m_fence->SetEventOnCompletion(fence, m_fenceEvent));
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
}
