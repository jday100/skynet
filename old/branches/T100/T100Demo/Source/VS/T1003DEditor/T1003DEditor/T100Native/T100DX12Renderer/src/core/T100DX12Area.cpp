#include "core/T100DX12Area.h"

#include "dx12/T100DX12Tools.h"

T100DX12Area::T100DX12Area() :
    T100DX12Stance(),
    m_hwnd(T100NULL),
    m_width(0),
    m_height(0),
    m_frameIndex(0),
    m_aspectRatio(0.0f)
{
    //ctor
}

T100DX12Area::~T100DX12Area()
{
    //dtor
}

CD3DX12_VIEWPORT& T100DX12Area::GetViewport()
{
    return m_viewport;
}

CD3DX12_RECT& T100DX12Area::GetScissorRect()
{
    return m_scissorRect;
}

T100FLOAT T100DX12Area::GetAspectRatio()
{
    return m_aspectRatio;
}

T100VOID T100DX12Area::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    m_hwnd      = hwnd;
    SetSize(width, height);
}

T100VOID T100DX12Area::Destroy()
{

}

T100VOID T100DX12Area::SetSize(T100UINT width, T100UINT height)
{
    m_width     = width;
    m_height    = height;

    m_viewport      = CD3DX12_VIEWPORT(0.0f, 0.0f, static_cast<float>(m_width), static_cast<float>(m_height));
    m_scissorRect   = CD3DX12_RECT(0, 0, static_cast<LONG>(m_width), static_cast<LONG>(m_height));
    m_aspectRatio   = static_cast<float>(m_width) / static_cast<float>(m_height);
}

T100VOID T100DX12Area::Start()
{
    T100DX12Stance::Start();

    CreateSwapChain();
    CreateRenderTargetView();
    CreateDepthStencilView();
}

T100VOID T100DX12Area::Stop()
{
    T100DX12Stance::Stop();
}

T100VOID T100DX12Area::Present()
{
    ThrowIfFailed(m_swapChain->Present(1, 0));
}

T100VOID T100DX12Area::UpdateFrameIndex()
{
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
}

T100VOID T100DX12Area::CreateSwapChain()
{
    DXGI_SWAP_CHAIN_DESC1           swapChainDesc = {};

    swapChainDesc.BufferCount       = m_frameCount;
    swapChainDesc.Width             = m_width;
    swapChainDesc.Height            = m_height;
    swapChainDesc.Format            = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect        = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count  = 1;

    ComPtr<IDXGISwapChain1>         swapChain;

    ThrowIfFailed(m_factory->CreateSwapChainForHwnd(
        m_commandQueue.Get(),
        m_hwnd,
        &swapChainDesc,
        T100NULL,
        T100NULL,
        &swapChain
        ));

    ThrowIfFailed(m_factory->MakeWindowAssociation(m_hwnd, DXGI_MWA_NO_ALT_ENTER));

    ThrowIfFailed(swapChain.As(&m_swapChain));
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
}

T100VOID T100DX12Area::CreateRenderTargetView()
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE       rtvHandle = m_heapManager.GetRtvHeap().GetCPUStart();

    for(UINT n = 0; n < m_frameCount; n++)
    {
        ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
        m_device->CreateRenderTargetView(m_renderTargets[n].Get(), T100NULL, rtvHandle);
        rtvHandle.Offset(1, m_heapManager.GetRtvHeap().GetSize());
    }
}

T100VOID T100DX12Area::CreateDepthStencilView()
{
    D3D12_DEPTH_STENCIL_VIEW_DESC       depthStencilDesc = {};
    depthStencilDesc.Format             = DXGI_FORMAT_D32_FLOAT;
    depthStencilDesc.ViewDimension      = D3D12_DSV_DIMENSION_TEXTURE2D;
    depthStencilDesc.Flags              = D3D12_DSV_FLAG_NONE;

    D3D12_CLEAR_VALUE                   depthOptimizedClearValue = {};
    depthOptimizedClearValue.Format                     = DXGI_FORMAT_D32_FLOAT;
    depthOptimizedClearValue.DepthStencil.Depth         = 1.0f;
    depthOptimizedClearValue.DepthStencil.Stencil       = 0;

    CD3DX12_HEAP_PROPERTIES             depth_heap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC               depth_desc          = CD3DX12_RESOURCE_DESC::Tex2D(DXGI_FORMAT_D32_FLOAT, m_width, m_height, 1, 0, 1, 0, D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL);
    ThrowIfFailed(m_device->CreateCommittedResource(
        &depth_heap,
        D3D12_HEAP_FLAG_NONE,
        &depth_desc,
        D3D12_RESOURCE_STATE_DEPTH_WRITE,
        &depthOptimizedClearValue,
        IID_PPV_ARGS(&m_depthStencil)
        ));

    m_device->CreateDepthStencilView(m_depthStencil.Get(), &depthStencilDesc, m_heapManager.GetDsvHeap().GetCPUStart());
}
