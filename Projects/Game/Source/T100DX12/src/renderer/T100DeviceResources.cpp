#include "T100DeviceResources.h"

static const bool   SupportHighResolutions      = false;

static const float  DPIThreshold                = 192.0f;
static const float  WidthThreshold              = 1920.0f;
static const float  HeightThreshold             = 1080.0f;

// 用于计算屏幕旋转的常量。
namespace ScreenRotation
{
	// 0 度 Z 旋转
	static const XMFLOAT4X4 Rotation0(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	// 90 度 Z 旋转
	static const XMFLOAT4X4 Rotation90(
		0.0f, 1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	// 180 度 Z 旋转
	static const XMFLOAT4X4 Rotation180(
		-1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	// 270 度 Z 旋转
	static const XMFLOAT4X4 Rotation270(
		0.0f, -1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
};

T100DeviceResources::T100DeviceResources(DXGI_FORMAT backBufferFormat, DXGI_FORMAT depthBufferFormat) :
    m_currentFrame(0),
    m_screenViewport(),
    m_rtvDescriptorSize(0),
    m_fenceEvent(0),
    m_backBufferFormat(backBufferFormat),
    m_depthBufferFormat(depthBufferFormat),
    m_fenceValues{},
    m_d3dRenderTargetSize(),
    m_outputSize(),
    m_logicalSize(),
    m_nativeOrientation(DisplayOrientations::None),
    m_currentOrientation(DisplayOrientations::None),
    m_dpi(-1.0f),
    m_effectiveDpi(-1.0f),
    m_deviceRemoved(false)
{
    //ctor
    CreateDeviceIndependentResources();
    CreateDeviceResources();
}

T100DeviceResources::~T100DeviceResources()
{
    //dtor
}

T100VOID T100DeviceResources::CreateDeviceIndependentResources()
{

}

T100VOID T100DeviceResources::CreateDeviceResources()
{
#if defined(_DEBUG)
	// 如果项目处于调试生成阶段，请通过 SDK 层启用调试。
	{
		ComPtr<ID3D12Debug> debugController;
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
		{
			debugController->EnableDebugLayer();
		}
	}
#endif

    ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&m_dxgiFactory)));

    ComPtr<IDXGIAdapter1>       adapter;

    GetHardwareAdapter(*adapter);

    HRESULT hr = D3D12CreateDevice(
                                   adapter.Get(),
                                   D3D_FEATURE_LEVEL_11_0,
                                   IID_PPV_ARGS(&m_d3dDevice)
                                   );

#if defined(_DEBUG)
	if (FAILED(hr))
	{
		// 如果初始化失败，则回退到 WARP 设备。
		// 有关 WARP 的详细信息，请参阅:
		// https://go.microsoft.com/fwlink/?LinkId=286690

		ComPtr<IDXGIAdapter> warpAdapter;
		DX::ThrowIfFailed(m_dxgiFactory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

		hr = D3D12CreateDevice(warpAdapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_d3dDevice));
	}
#endif

    ThrowIfFailed(hr);

    D3D12_COMMAND_QUEUE_DESC            queueDesc = {};

    queueDesc.Flags         = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type          = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_d3dDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)));
    NAME_D3D12_OBJECT(m_commandQueue);

    D3D12_DESCRIPTOR_HEAP_DESC          rtvHeapDesc = {};

    rtvHeapDesc.NumDescriptors          = c_frameCount;
    rtvHeapDesc.Type                    = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags                   = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(m_d3dDevice->CreateDescriptionHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap)));
    NAME_D3D12_OBJECT(m_rtvHeap);

    m_rtvDescriptorSize     = m_d3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

    D3D12_DESCRIPTOR_HEAP_DESC          dsvHeapDesc = {};

    dsvHeapDesc.NumDescriptors          = 1;
    dsvHeapDesc.Type                    = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags                   = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(m_d3dDevice->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(&m_dsvHeap)));
    NAME_D3D12_OBJECT(m_dsvHeap);

    for (UINT n = 0; n < c_frameCount; n++)
	{
        ThrowIfFailed(
            m_d3dDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocators[n]))
        );
	}

	ThrowIfFailed(m_d3dDevice->CreateFence(m_fenceValues[m_currentFrame], D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)));
    m_fenceValues[m_currentFrame]++;

    m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
	if (m_fenceEvent == nullptr)
	{
        ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
	}
}

T100VOID T100DeviceResources::CreateWindowSizeDependentResources()
{
    WaitForGpu();

    for (UINT n = 0; n < c_frameCount; n++)
	{
		m_renderTargets[n]  = nullptr;
		m_fenceValues[n]    = m_fenceValues[m_currentFrame];
	}

	UpdateRenderTargetSize();

	DXGI_MODE_ROTATION          displayRotation = ComputeDisplayRotation();

    bool                        swapDimensions  = displayRotation == DXGI_MODE_ROTATION_ROTATE90 || displayRotation == DXGI_MODE_ROTATION_ROTATE270;

    m_d3dRenderTargetSize.Width     = swapDimensions ? m_outputSize.Height : m_outputSize.Width;
    m_d3dRenderTargetSize.Height    = swapDimensions ? m_outputSize.Width : m_outputSize.Height;

    UINT backBufferWidth            = lround(m_d3dRenderTargetSize.Width);
    UINT backBufferHeight           = lround(m_d3dRenderTargetSize.Height);

    if(m_swapChain != T100NULL)
    {
        HRESULT hr = m_swapChain->ResizeBuffers(c_frameCount, backBufferWidth, backBufferHeight, m_backBufferFormat, 0);

        if(hr == DXGI_ERROR_DEVIE_REMOVED || hr == DXGI_ERROR_DEVIDE_RESET)
        {
            m_deviceRemoved = true;
            return;
        }
        else
        {
            ThrowIfFailed(hr);
        }
    }
    else
    {
        DXGI_SCALING scaling = DisplayMetrics::SupportHighResolutions ? DXGI_SCALING_NONE : DXGI_SCALING_STRETCH;
        DXGI_SWAP_CHAIN_DESC1           swapChainDesc = {};

        swapChainDesc.Width             = backBufferWidth;
        swapChainDesc.Height            = backBufferHeight;
        swapChainDesc.FORMAT            = m_backBufferFormat;
        swapChainDesc.Stereo            = false;
        swapChainDesc.SampleDesc.Count  = 1;
        swapChainDesc.SampleDesc.Quality    = 0;
        swapChainDesc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.BufferCount           = c_frameCount;
        swapChainDesc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        swapChainDesc.Flags                 = 0;
        swapChainDesc.Scaling               = scaling;
        swapChainDesc.AlphaMode             = DXGI_ALPHA_MODE_IGNORE;

        ComPtr<IDXGISwapChain1>             swapChain;

        ThrowIfFailed(
                      m_dxgiFactory->CreateSwapChainForCoreWindow(
                                                                  m_commandQueue.Get(),
                                                                  reinterpret_cast<IUnknown*>(m_window.Get()),
                                                                  &swapChainDesc,
                                                                  T100NULL,
                                                                  &swapChain
                                                                  )
                      );

        ThrowIfFailed(swapChain.As(&m_swapChain));

        switch (displayRotation)
        {
        case DXGI_MODE_ROTATION_IDENTITY:
            m_orientationTransform3D = ScreenRotation::Rotation0;
            break;

        case DXGI_MODE_ROTATION_ROTATE90:
            m_orientationTransform3D = ScreenRotation::Rotation270;
            break;

        case DXGI_MODE_ROTATION_ROTATE180:
            m_orientationTransform3D = ScreenRotation::Rotation180;
            break;

        case DXGI_MODE_ROTATION_ROTATE270:
            m_orientationTransform3D = ScreenRotation::Rotation90;
            break;

        default:
            throw new std::runtime_error("");
        }

        ThrowIfFailed(m_swapChain->SetRotation(displayRotation));

        {
            m_currentFrame = m_swapChain->GetCurrentBackBufferIndex();
            CD3DX12_CPU_DESCRIPTOR_HANDLE rtvDescriptor(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());
            for (UINT n = 0; n < c_frameCount; n++)
            {
                ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
                m_d3dDevice->CreateRenderTargetView(m_renderTargets[n].Get(), nullptr, rtvDescriptor);
                rtvDescriptor.Offset(m_rtvDescriptorSize);

                WCHAR name[25];
                if (swprintf_s(name, L"m_renderTargets[%u]", n) > 0)
                {
                    SetName(m_renderTargets[n].Get(), name);
                }
            }
        }

        {
            D3D12_HEAP_PROPERTIES depthHeapProperties = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);

            D3D12_RESOURCE_DESC depthResourceDesc = CD3DX12_RESOURCE_DESC::Tex2D(m_depthBufferFormat, backBufferWidth, backBufferHeight, 1, 1);
            depthResourceDesc.Flags |= D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

            CD3DX12_CLEAR_VALUE depthOptimizedClearValue(m_depthBufferFormat, 1.0f, 0);

            ThrowIfFailed(m_d3dDevice->CreateCommittedResource(
                &depthHeapProperties,
                D3D12_HEAP_FLAG_NONE,
                &depthResourceDesc,
                D3D12_RESOURCE_STATE_DEPTH_WRITE,
                &depthOptimizedClearValue,
                IID_PPV_ARGS(&m_depthStencil)
                ));

                NAME_D3D12_OBJECT(m_depthStencil);

                D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
                dsvDesc.Format = m_depthBufferFormat;
                dsvDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
                dsvDesc.Flags = D3D12_DSV_FLAG_NONE;

                m_d3dDevice->CreateDepthStencilView(m_depthStencil.Get(), &dsvDesc, m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
            }

        m_screenViewport = { 0.0f, 0.0f, m_d3dRenderTargetSize.Width, m_d3dRenderTargetSize.Height, 0.0f, 1.0f };
    }
}

T100VOID T100DeviceResources::UpdateRenderTargetSize()
{
    m_effectiveDPI  = m_dpi;

    if(!DisplayMetrics::SupportHighResolutions && m_dpi > DisplayMetrics::DpiThreshold)
    {
        float width = ConvertDipsToPixels(m_logicalSize.Width, m_dpi);
        float height = ConvertDipsToPixels(m_logicalSize.Height, m_dpi);

        if(max(width, height) > DisplayMetrics::WidthThreshold && min(width, height) > DisplayMetrics::HeightThreshold)
        {
            m_effectiveDPI /= 2.0f;
        }
    }

    m_outputSize.Width      = ConvertDipsToPixels(m_logicalSize.Width, m_effectiveDpi);
    m_outputSize.Height     = ConvertDipsToPixels(m_logicalSize.Height, m_effectiveDpi);

    m_outputSize.Width      = max(m_outputSize.Width, 1);
    m_outputSize.Height     = max(m_outputSize.Height, 1);
}

T100VOID T100DeviceResources::SetFrame(T100Frame* window)
{
    DisplayInformation^ currentDisplayInformation = DisplayInformation::GetForCurrentView();

    m_window                = window;
    m_logicalSize           = Windows::Foundation::Size(window->Bounds.Width, window->Bounds.Height);
    m_nativeOrientation     = currentDisplayInformation->NativeOrientation;
    m_currentOrientation    = currentDisplayInformation->CurrentOrientation;
    m_dpi = currentDisplayInformation->LogicalDpi;

    CreateWindowSizeDependentResources();
}

T100VOID T100DeviceResources::SetLogicalRect(RECT logicalRect)
{
    if(m_logicalSize != logicalSize)
    {
        m_logicalSize = logicalSize;
        CreateWindowSizeDependentResources();
    }
}

T100VOID T100DeviceResources::SetDPI(float dpi)
{
    if(dpi != m_dpi)
    {
        m_dpi = dpi;

        m_logicalSize = Size(m_window->Width, m_window->Height);

        CreateWindowSizeDependentResources();
    }
}

T100VOID T100DeviceResources::SetCurrentOrientation(T100Orientation currentOrientation)
{
	if (m_currentOrientation != currentOrientation)
	{
		m_currentOrientation = currentOrientation;
		CreateWindowSizeDependentResources();
	}
}

T100VOID T100DeviceResources::ValidateDevice()
{
    DXGI_ADAPTER_DESC       previousDesc;
    {
        ComPtr<IDXGIAdapter1>       previousDefaultAdapter;

        ThrowIfFailed(m_dxgiFactory->EnumAdapters1(0, &previousDefaultAdapter));
        ThrowIfFailed(previousDefaultAdapter->GetDesc(&previousDesc));
    }

    DXGI_ADAPTER_DESC       currentDesc;
    {
        ComPtr<IDXGIFactory4>       currentDXGIFactory;

        ThrowIfFailed(CreateDXGIFactor1(IID_PPV_ARGS(&currentDXGIFactory)));

        ComPtr<IDXGIAdapter1>       currentDefaultAdapter;

        ThrowIfFailed(currentDXGIFactory->EnumAdapters1(0, &currentDefaultAdapter));
        ThrowIfFailed(currentDefaultAdapter->GetDesc(&currentDesc));
    }

    if (previousDesc.AdapterLuid.LowPart != currentDesc.AdapterLuid.LowPart ||
        previousDesc.AdapterLuid.HighPart != currentDesc.AdapterLuid.HighPart ||
        FAILED(m_d3dDevice->GetDeviceRemovedReason()))
    {
        m_deviceRemoved = true;
    }
}

T100VOID T100DeviceResources::Present()
{
    HRESULT hr = m_swapChain->Present(1, 0);

    if(hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
    {
        m_deviceRemoved = true;
    }
    else
    {
        ThrowIfFailed(hr);
        MoveToNextFrame();
    }
}

T100VOID T100DeviceResources::WaitForGpu()
{
    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), m_fenceValues[m_currentFrame]));

    ThrowIfFailed(m_fence->SetEventOnCompletion(m_fenceValues[m_currentFrame]));
    WaitForSingleObjectEx(m_fenceEvent, INFINITE, FALSE);

    m_fenceValues[m_currentFrame]++;
}

T100VOID T100DeviceResources::MoveToNextFrame()
{
    const UINT64    currentFenceValue   = m_fenceValues[m_currentFrame];

    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), currentFenceValue));

    m_currentFrame  = m_swapChain->GetCurrentBackBufferIndex();

    if(m_fence->GetCompletedValue() < m_fenceValues[m_currentFrame])
    {
        ThrowIfFailed(m_fence->SetEventOnCompletion(m_fenceValues[m_currentFrame]));
        WaitForSingleObjectEx(m_fenceEvent, INFINITE, FALSE);
    }

    m_fenceValues[m_currentFrame] = currentFenceValue + 1;
}

DXGI_MODE_ROTATION T100DeviceResources::ComputeDisplayRotation()
{
    DXGI_MODE_ROTATION      rotation    = DXGI_MODE_ROTATION_UNSPECIFIED;

    switch(m_nativeOrientation)
    {
    case DisplayOrientations::Landscape:
        switch(m_currentOrientation)
        {
        case DisplayOrientations::Landscape:
            rotation    = DXGI_MODE_ROTATION_IDENTITY;
            break;
        case DisplayOrientations::Portrait:
            rotation    = DXGI_MODE_ROTATION_ROTATE270;
            break;
        case DisplayOrientations:LandscapeFlipped:
            rotation    = DXGI_MODE_ROTATION_ROTATE90;
            break;
        }
        break;
    case DisplayOrientations::Portrait:
        switch(m_currentOrientation)
        {
        case DisplayOrientations::Landscape:
            rotation    = DXGI_MODE_ROTATION_ROTATE90;
            break;
        case DisplayOrientations::Portrait:
            rotation    = DXGI_MODE_ROTATION_IDENTITY;
            break;
        case DisplayOrientations:LandscapeFlipped:
            rotation    = DXGI_MODE_ROTATION_ROTATE270;
            break;
        case DisplayOrientations:PortraitFlipped:
            rotation    = DXGI_MODE_ROTATION_ROTATE180;
            break;
        }
        break;
    }
    return rotation;
}

T100VOID T100DeviceResources::GetHardwareAdapter(IDXGIAdapter1** ppAdapter)
{
    ComPtr<IDXGIAdapter1>       adapter;
    *ppAdapter  = T100NULL;

    for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != m_dxgiFactory->EnumAdapters1(adapterIndex, &adapter); adapterIndex++)
	{
		DXGI_ADAPTER_DESC1 desc;
		adapter->GetDesc1(&desc);

		if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
		{
			// 不要选择基本呈现驱动程序适配器。
			continue;
		}

		// 检查适配器是否支持 Direct3D 12，但不要创建
		// 仍为实际设备。
		if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
		{
			break;
		}
	}

	*ppAdapter = adapter.Detach();
}

size T100DeviceResources::GetOutputSize() const
{
    return m_outputSize;
}

size T100DeviceResources::GetLogicalSize() const;
{
    return m_logicalSize;
}

float T100DeviceResources::GetDPI() const
{
    return m_effectiveDpi;
}

bool T100DeviceResources::IsDeviceRemove() const
{
    return m_deviceRemoved;
}

ID3D12Device* T100DeviceResources::GetD3DDevice() const
{
    return m_d3dDevice.Get();
}

IDXGISwapChain3* T100DeviceResources::GetSwapChain() const
{
    return m_swapChain.Get();
}

ID3D12Resource* T100DeviceResources::GetRenderTarget() const
{
    return m_renderTargets[m_currentFrame].Get();
}

ID3D12Resource* T100DeviceResources::GetDepthStencil() const
{
    return m_depthStencil.Get();
}

ID3D12CommandQueue* T100DeviceResources::GetCommandQueue() const
{
    return m_commandQueue.Get();
}

ID3D12CommandAllocator* T100DeviceResources::GetCommandAllocator() const
{
    return m_commandAllocators[m_currentFrame].Get();
}

DXGI_FORMAT T100DeviceResources::GetBackBufferFormat() const
{
    return m_backBufferFormat;
}

DXGI_FORMAT T100DeviceResources::GetDepthBufferFormat() const
{
    return m_depthBufferFormat;
}

D3D12_VIEWPORT T100DeviceResources::GetScreenViewport() const
{
    return m_screenViewport;
}

XMFLOAT4X4 T100DeviceResources:GetOrientationTransform3D() const
{
    return m_orientationTransform3D;
}

UINT T100DeviceResources::GetCurrentFrameIndex() const
{
    return m_currentFrame;
}

CD3DX12_CPU_DESCRIPTOR_HANDLE T100DeviceResources::GetRenderTargetView() const
{
    return CD3DX12_CPU_DESCRIPTOR_HANDLE(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_currentFrame, m_rtvDescriptorSize);
}

CD3DX12_CPU_DESCRIPTOR_HANDLE T100DeviceResources::GetDepthStencilView() const
{
    return CD3DX12_CPU_DESCRIPTOR_HANDLE(m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
}

