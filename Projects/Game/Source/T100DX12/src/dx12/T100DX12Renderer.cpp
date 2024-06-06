#include "T100DX12Renderer.h"
#include "T100DX12RendererHelper.h"

T100DX12Renderer::T100DX12Renderer()
    :T100Renderer()
{
    //ctor
}

T100DX12Renderer::~T100DX12Renderer()
{
    //dtor
}

T100VOID T100DX12Renderer::Start()
{

}

T100VOID T100DX12Renderer::Stop()
{

}

T100VOID T100DX12Renderer::LoadPipeline()
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

    }
}

T100VOID T100DX12Renderer::LoadAssets()
{

}
