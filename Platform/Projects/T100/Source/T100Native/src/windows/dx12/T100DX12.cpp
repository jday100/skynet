#include "T100DX12.h"
#include "T100DX12Helper.h"

#include "d3dx12_root_signature.h"
#include "d3dx12_barriers.h"

T100DX12::T100DX12(HWND hwnd)
    :m_hwnd(hwnd)
{
    //ctor
    create();
}

T100DX12::~T100DX12()
{
    //dtor
    destroy();
}

T100VOID T100DX12::create()
{

}

T100VOID T100DX12::destroy()
{

}

T100BOOL T100DX12::run()
{

}

void T100DX12::start()
{
    LoadPipeline();
    LoadAssets();
}

void T100DX12::stop()
{

}


void T100DX12::render()
{
    PopulateCommandList();

    ID3D12CommandList*      ppCommandLists[] = { m_commandList.Get() };
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    ThrowIfFailed(m_swapChain->Present(1, 0));

    WaitForPreviousFrame();
}

void T100DX12::GetHardwareAdapter(IDXGIFactory1*  pFactory,
                                               IDXGIAdapter1** ppAdapter,
                                               bool requestHighPerformanceAdapter)
{
    *ppAdapter      = NULL;
    Microsoft::WRL::ComPtr<IDXGIAdapter1>           adapter;
    Microsoft::WRL::ComPtr<IDXGIFactory6>           factory6;

    if(SUCCEEDED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6)))){
        for(
            UINT adapterIndex = 0;
            SUCCEEDED(factory6->EnumAdapterByGpuPreference(
                                                           adapterIndex,
                                                           requestHighPerformanceAdapter == TRUE ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                                                           IID_PPV_ARGS(&adapter)
                                                           ));
            ++adapterIndex
            ){
            DXGI_ADAPTER_DESC1          desc;
            adapter->GetDesc1(&desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE){
                continue;
            }

            if(SUCCEEDED(D3D12CreateDevice(adapter.Get(),
                                           D3D_FEATURE_LEVEL_11_0,
                                           __uuidof(ID3D12Device),
                                           NULL))){
                                                break;
                                           }
        }
    }

    if(adapter.Get() == NULL){
        for(
            UINT adapterIndex = 0;
            SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter));
            ++adapterIndex){
                DXGI_ADAPTER_DESC1          desc;
                adapter->GetDesc1(&desc);

                if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE){
                    continue;
                }

                if(SUCCEEDED(D3D12CreateDevice(
                                               adapter.Get(),
                                               D3D_FEATURE_LEVEL_11_0,
                                               __uuidof(ID3D12Device),
                                               NULL))){
                                                    break;
                                               }
            }
    }

    *ppAdapter = adapter.Detach();
}

void T100DX12::LoadPipeline()
{
    UINT    dxgiFactoryFlags            = 0;

    Microsoft::WRL::ComPtr<IDXGIFactory4>               factory;

    ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&factory)));

    if(m_useWarpDevice){
        Microsoft::WRL::ComPtr<IDXGIAdapter>            warpAdapter;

        ThrowIfFailed(factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

        ThrowIfFailed(D3D12CreateDevice(
                                        warpAdapter.Get(),
                                        D3D_FEATURE_LEVEL_11_0,
                                        IID_PPV_ARGS(&m_device)
                                        ));
    }else{
        Microsoft::WRL::ComPtr<IDXGIAdapter1>           hardwareAdapter;
        GetHardwareAdapter(factory.Get(), &hardwareAdapter);

        ThrowIfFailed(D3D12CreateDevice(
                                        hardwareAdapter.Get(),
                                        D3D_FEATURE_LEVEL_11_0,
                                        IID_PPV_ARGS(&m_device)
                                        ));
    }

    D3D12_COMMAND_QUEUE_DESC            queueDesc = {};

    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type  = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)));

    DXGI_SWAP_CHAIN_DESC1               swapChainDesc = {};

    swapChainDesc.BufferCount       = FrameCount;
    swapChainDesc.Width             = m_width;
    swapChainDesc.Height            = m_height;
    swapChainDesc.Format            = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect        = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count  = 1;

    Microsoft::WRL::ComPtr<IDXGISwapChain1>     swapChain;
    ThrowIfFailed(factory->CreateSwapChainForHwnd(
                                                  m_commandQueue.Get(),
                                                  m_hwnd,
                                                  &swapChainDesc,
                                                  NULL,
                                                  NULL,
                                                  &swapChain));

    ThrowIfFailed(factory->MakeWindowAssociation(m_hwnd, DXGI_MWA_NO_ALT_ENTER));

    ThrowIfFailed(swapChain.As(&m_swapChain));
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();


    {
        D3D12_DESCRIPTOR_HEAP_DESC          rtvHeapDesc = {};

        rtvHeapDesc.NumDescriptors  = FrameCount;
        rtvHeapDesc.Type            = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.Flags           = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        ThrowIfFailed(m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap)));

        m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    }

    {
        CD3DX12_CPU_DESCRIPTOR_HANDLE           rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

        for(UINT n=0;n<FrameCount;n++){
            ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
            m_device->CreateRenderTargetView(m_renderTargets[n].Get(), NULL, rtvHandle);
            rtvHandle.Offset(1, m_rtvDescriptorSize);
        }
    }

    ThrowIfFailed(m_device->CreateCommandAllocator(
                                                   D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
}

void T100DX12::LoadAssets()
{
    ThrowIfFailed(m_device->CreateCommandList(
                                              0,
                                              D3D12_COMMAND_LIST_TYPE_DIRECT,
                                              m_commandAllocator.Get(),
                                              NULL,
                                              IID_PPV_ARGS(&m_commandList)));

    ThrowIfFailed(m_commandList->Close());

    {
        ThrowIfFailed(m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)));

        m_fenceValue    = 1;

        m_fenceEvent    = CreateEvent(NULL, FALSE, FALSE, NULL);
        if(m_fenceEvent == NULL){
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }
    }

}

void T100DX12::PopulateCommandList()
{
    ThrowIfFailed(m_commandAllocator->Reset());

    ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get()));

    CD3DX12_RESOURCE_BARRIER    barrier;
    barrier     = CD3DX12_RESOURCE_BARRIER::Transition(
                                                       m_renderTargets[m_frameIndex].Get(),
                                                       D3D12_RESOURCE_STATE_PRESENT,
                                                       D3D12_RESOURCE_STATE_RENDER_TARGET);

    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE           rtvHandle(
                                                      m_rtvHeap->GetCPUDescriptorHandleForHeapStart(),
                                                      m_frameIndex,
                                                      m_rtvDescriptorSize);


    const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };

    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, NULL);

    barrier     = CD3DX12_RESOURCE_BARRIER::Transition(
                                                       m_renderTargets[m_frameIndex].Get(),
                                                       D3D12_RESOURCE_STATE_RENDER_TARGET,
                                                       D3D12_RESOURCE_STATE_PRESENT);

    m_commandList->ResourceBarrier(1, &barrier);
    ThrowIfFailed(m_commandList->Close());
}

void T100DX12::WaitForPreviousFrame()
{
    const UINT64    fence   = m_fenceValue;

    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fence));
    m_fenceValue++;

    if(m_fence->GetCompletedValue() < fence){
        ThrowIfFailed(m_fence->SetEventOnCompletion(fence, m_fenceEvent));
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }

    m_frameIndex    = m_swapChain->GetCurrentBackBufferIndex();
}
