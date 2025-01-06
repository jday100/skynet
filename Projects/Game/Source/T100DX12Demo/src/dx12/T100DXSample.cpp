#include "T100DXSample.h"

#include "stdafx.h"
#include "T100DXSample.h"

using namespace Microsoft::WRL;

T100DXSample::T100DXSample(UINT width, UINT height, std::wstring name) :
    m_width(width),
    m_height(height),
    m_title(name),
    m_useWarpDevice(false)
{
    //ctor
    WCHAR       assetsPath[512];

    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath = assetsPath;

    m_aspectRatio = static_cast<float>(width) / static_cast<float>(height);
}

T100DXSample::~T100DXSample()
{
    //dtor
}

std::wstring T100DXSample::GetAssetFullPath(LPCWSTR assetName)
{
    return m_assetsPath + assetName;
}

_Use_decl_annotations_
void T100DXSample::GetHardwareAdapter(
                                      IDXGIFactory1* pFactory,
                                      IDXGIAdapter1** ppAdapter,
                                      bool requestHighPerformanceAdapter
                                      )
{
    *ppAdapter  = nullptr;

    ComPtr<IDXGIAdapter1>       adapter;

    ComPtr<IDXGIFactory6>       factory6;
    if(SUCCESSED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6))))
    {
        for(
            UINT adapterIndex = 0;
            SUCCEEDED(factory6->EnumAdapterByGpuPreference(
                                                           adapterIndex,
                                                           requestHighPerformanceAdapter == true ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
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

            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
            {
                break;
            }
        }
    }

    if(adapter.Get() == nullptr)
    {
        for (UINT adapterIndex = 0; SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter)); ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1 desc;
            adapter->GetDesc1(&desc);

            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
            {
                break;
            }
        }
    }


    *ppAdapter = adapter.Detach();

}

void T100DXSample::SetCustomWindowText(LPCWSTR text)
{
    std::wstring windowText = m_title + L": " + text;
    SetWindowText(Win32Application::GetHwnd(), windowText.c_str());
}

_Use_decl_annotations_
void T100DXSample::ParseCommandLineArgs(WCHAR* argv[], int argc)
{
    for (int i = 1; i < argc; ++i)
    {
        if (_wcsnicmp(argv[i], L"-warp", wcslen(argv[i])) == 0 ||
            _wcsnicmp(argv[i], L"/warp", wcslen(argv[i])) == 0)
        {
            m_useWarpDevice = true;
            m_title = m_title + L" (WARP)";
        }
    }
}
