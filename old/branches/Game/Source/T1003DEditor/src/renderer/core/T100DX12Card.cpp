#include "T100DX12Card.h"

#include "T100DX12Tools.h"

T100DX12Card::T100DX12Card() :
    m_useWarpDevice(T100FALSE)
{
    //ctor
}

T100DX12Card::~T100DX12Card()
{
    //dtor
}

ID3D12Device* T100DX12Card::GetDevicePtr()
{
    return m_device.Get();
}

T100VOID T100DX12Card::Start()
{
    CreateFactory();
    CreateDevice();
    CreateCommandQueue();
    CreateCommandAllocator();
}

T100VOID T100DX12Card::Stop()
{

}

T100VOID T100DX12Card::CreateFactory()
{
    UINT        dxgiFactoryFlags = 0;

    ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_factory)));
}

T100VOID T100DX12Card::CreateDevice()
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
        ComPtr<IDXGIAdapter1>       hardwareAdapter;
        GetHardwareAdapter(m_factory.Get(), &hardwareAdapter);

        ThrowIfFailed(D3D12CreateDevice(
            hardwareAdapter.Get(),
            D3D_FEATURE_LEVEL_12_0,
            IID_PPV_ARGS(&m_device)
            ));
    }
}

T100VOID T100DX12Card::CreateCommandQueue()
{
    D3D12_COMMAND_QUEUE_DESC        queueDesc = {};

    queueDesc.Flags         = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type          = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)));
}

T100VOID T100DX12Card::CreateCommandAllocator()
{
    ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));
}

_Use_decl_annotations_
T100VOID T100DX12Card::GetHardwareAdapter(
    IDXGIFactory1* pFactory,
    IDXGIAdapter1** ppAdapter,
    T100BOOL requestHighPerformanceAdapter)
{
    *ppAdapter = T100NULL;

    ComPtr<IDXGIAdapter1>       adapter;
    ComPtr<IDXGIFactory6>       factory6;

    if(SUCCEEDED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6))))
    {
        for(
            UINT adapterIndex = 0;
            SUCCEEDED(factory6->EnumAdapterByGpuPreference(
                adapterIndex,
                requestHighPerformanceAdapter == T100TRUE ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                IID_PPV_ARGS(&adapter)));
            ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1      desc;

            adapter->GetDesc1(&desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if(SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_12_0, __uuidof(ID3D12Device), T100NULL)))
            {
                break;
            }
        }
    }

    if(adapter.Get() == T100NULL)
    {
        for(UINT adapterIndex = 0; SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter)); ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1      desc;

            adapter->GetDesc1(&desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if(SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_12_0, __uuidof(ID3D12Device), T100NULL)))
            {
                break;
            }
        }
    }

    *ppAdapter = adapter.Detach();
}
