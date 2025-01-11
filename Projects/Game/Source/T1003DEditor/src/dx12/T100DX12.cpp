#include "T100DX12.h"

#include <d3dcompiler.h>
#include "T100DX12Tools.h"

T100DX12::T100DX12() :
    m_useWarpDevice(T100FALSE)
{
    //ctor
}

T100DX12::~T100DX12()
{
    //dtor
}

T100VOID T100DX12::Create(HWND hwnd, UINT width, UINT height)
{
    m_hwnd      = hwnd;

    SetSize(width, height);
}

T100VOID T100DX12::Destroy()
{

}

T100VOID T100DX12::Start()
{
    LoadPipeline();

    LoadAssets();


    //LoadEntities();
}

T100VOID T100DX12::Stop()
{

}

T100VOID T100DX12::Update()
{

}

T100VOID T100DX12::Render()
{
    PopulateCommandList();

    ID3D12CommandList* ppCommandLists[] = { m_commandList.Get() };
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    ThrowIfFailed(m_swapChain->Present(1, 0));

    WaitForPreviousFrame();
}

T100VOID T100DX12::Append(T100Entity* entity)
{
    m_entities.push_back(entity);
}

T100VOID T100DX12::Remove(T100Entity* entity)
{
    T100DX12_ENTITY_VECTOR::iterator it;

    for(it = m_entities.begin();it != m_entities.end();it++)
    {
        if(*it == entity){
            m_entities.erase(it);
            break;
        }
    }
}

T100VOID T100DX12::SetSize(UINT width, UINT height)
{


    m_width     = width;
    m_height    = height;
}

T100VOID T100DX12::LoadPipeline()
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
                                        D3D_FEATURE_LEVEL_12_0,
                                        IID_PPV_ARGS(&m_device)
                                        ));
    }
    else
    {
        ComPtr<IDXGIAdapter1>           hardwareAdapter;
        GetHardwareAdapter(factory.Get(), &hardwareAdapter);

        ThrowIfFailed(D3D12CreateDevice(
                                        hardwareAdapter.Get(),
                                        D3D_FEATURE_LEVEL_12_0,
                                        IID_PPV_ARGS(&m_device)
                                        ));

        D3D12_COMMAND_QUEUE_DESC        queueDesc       = {};

        queueDesc.Flags         = D3D12_COMMAND_QUEUE_FLAG_NONE;
        queueDesc.Type          = D3D12_COMMAND_LIST_TYPE_DIRECT;

        ThrowIfFailed(m_device->CreateCommandQueue(
                                                   &queueDesc,
                                                   IID_PPV_ARGS(&m_commandQueue)
                                                   ));

        DXGI_SWAP_CHAIN_DESC1           swapChainDesc   = {};

        swapChainDesc.BufferCount       = m_frameCount;
        swapChainDesc.Width             = m_width;
        swapChainDesc.Height            = m_height;
        swapChainDesc.Format            = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChainDesc.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.SwapEffect        = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        swapChainDesc.SampleDesc.Count  = 1;

        ComPtr<IDXGISwapChain1>         swapChain;
        ThrowIfFailed(factory->CreateSwapChainForHwnd(
                                                      m_commandQueue.Get(),
                                                      m_hwnd,
                                                      &swapChainDesc,
                                                      T100NULL,
                                                      T100NULL,
                                                      &swapChain
                                                      ));
        ThrowIfFailed(factory->MakeWindowAssociation(
                                                     m_hwnd,
                                                     DXGI_MWA_NO_ALT_ENTER
                                                     ));

        ThrowIfFailed(swapChain.As(&m_swapChain));
        m_frameIndex    = m_swapChain->GetCurrentBackBufferIndex();

        {
            D3D12_DESCRIPTOR_HEAP_DESC          rtvHeadDesc     = {};

            rtvHeadDesc.NumDescriptors      = m_frameCount;
            rtvHeadDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
            rtvHeadDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

            ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                         &rtvHeadDesc,
                                                         IID_PPV_ARGS(&m_rtvHeap)
                                                         ));

            m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
        }

        {
            CD3DX12_CPU_DESCRIPTOR_HANDLE   rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

            for(UINT n= 0; n < m_frameCount; n++)
            {
                ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
                m_device->CreateRenderTargetView(m_renderTargets[n].Get(), T100NULL, rtvHandle);
                rtvHandle.Offset(1, m_rtvDescriptorSize);
            }
        }

        ThrowIfFailed(m_device->CreateCommandAllocator(
                                                       D3D12_COMMAND_LIST_TYPE_DIRECT,
                                                       IID_PPV_ARGS(&m_commandAllocator)
                                                       ));
    }
}

T100VOID T100DX12::LoadAssets()
{
    WCHAR       assetsPath[512];
    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath    = assetsPath;

    m_aspectRatio   = static_cast<float>(m_width) / static_cast<float>(m_height);

    m_viewport      = CD3DX12_VIEWPORT(0.0f, 0.0f, static_cast<float>(m_width), static_cast<float>(m_height));
    m_scissorRect   = CD3DX12_RECT(0, 0, static_cast<LONG>(m_width), static_cast<LONG>(m_height));

    {
        CD3DX12_ROOT_SIGNATURE_DESC         rootSignatureDesc;
        rootSignatureDesc.Init(0, T100NULL, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

        ComPtr<ID3DBlob>            signature;
        ComPtr<ID3DBlob>            error;
        ThrowIfFailed(D3D12SerializeRootSignature(
                                                  &rootSignatureDesc,
                                                  D3D_ROOT_SIGNATURE_VERSION_1,
                                                  &signature,
                                                  &error
                                                  ));
        ThrowIfFailed(m_device->CreateRootSignature(
                                                    0,
                                                    signature->GetBufferPointer(),
                                                    signature->GetBufferSize(),
                                                    IID_PPV_ARGS(&m_rootSignature)
                                                    ));
    }

    {
        ComPtr<ID3DBlob>            vertexShader;
        ComPtr<ID3DBlob>            pixelShader;

        UINT        compileFlags    = 0;

        ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(L"shaders.hlsl").c_str(), T100NULL, T100NULL, "VSMain", "vs_5_0", compileFlags, 0, &vertexShader, T100NULL));
        ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(L"shaders.hlsl").c_str(), T100NULL, T100NULL, "PSMain", "ps_5_0", compileFlags, 0, &pixelShader, T100NULL));

        D3D12_INPUT_ELEMENT_DESC        inputElementDescs[] =
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
        };

        D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

        psoDesc.InputLayout         = { inputElementDescs, _countof(inputElementDescs) };
        psoDesc.pRootSignature      = m_rootSignature.Get();
        psoDesc.VS                  = CD3DX12_SHADER_BYTECODE(vertexShader.Get());
        psoDesc.PS                  = CD3DX12_SHADER_BYTECODE(pixelShader.Get());
        psoDesc.RasterizerState     = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
        psoDesc.BlendState          = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState.DepthEnable       = T100FALSE;
        psoDesc.DepthStencilState.StencilEnable     = T100FALSE;
        psoDesc.SampleMask          = UINT_MAX;
        psoDesc.PrimitiveTopologyType   = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets        = 1;
        psoDesc.RTVFormats[0]       = DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.SampleDesc.Count    = 1;

        ThrowIfFailed(m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState)));


    }



    ThrowIfFailed(m_device->CreateCommandList(
                                              0,
                                              D3D12_COMMAND_LIST_TYPE_DIRECT,
                                              m_commandAllocator.Get(),
                                              m_pipelineState.Get(),
                                              IID_PPV_ARGS(&m_commandList)
                                              ));

    ThrowIfFailed(m_commandList->Close());

    {
        Vertex      triangleVertices[] =
        {
            { { 0.0f, 0.25f * m_aspectRatio, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
            { { 0.25f, -0.25f * m_aspectRatio, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
            { { -0.25f, -0.25f * m_aspectRatio, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
        };

        const UINT vertexBufferSize     = sizeof(triangleVertices);

        CD3DX12_HEAP_PROPERTIES         uploadHeap(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC           resourceDesc = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);

        ThrowIfFailed(m_device->CreateCommittedResource(
                                                        &uploadHeap,
                                                        D3D12_HEAP_FLAG_NONE,
                                                        &resourceDesc,
                                                        D3D12_RESOURCE_STATE_GENERIC_READ,
                                                        nullptr,
                                                        IID_PPV_ARGS(&m_vertexBuffer)
                                                        ));

        UINT8*          pVertexDataBegin;
        CD3DX12_RANGE   readRange(0, 0);

        ThrowIfFailed(m_vertexBuffer->Map(
                                          0,
                                          &readRange,
                                          reinterpret_cast<void**>(&pVertexDataBegin)
                                          ));
        memcpy(pVertexDataBegin, triangleVertices, sizeof(triangleVertices));
        m_vertexBuffer->Unmap(0, T100NULL);

        m_vertexBufferView.BufferLocation   = m_vertexBuffer->GetGPUVirtualAddress();
        m_vertexBufferView.StrideInBytes    = sizeof(Vertex);
        m_vertexBufferView.SizeInBytes      = vertexBufferSize;
    }

    {
        ThrowIfFailed(m_device->CreateFence(
                                            0,
                                            D3D12_FENCE_FLAG_NONE,
                                            IID_PPV_ARGS(&m_fence)
                                            ));
        m_fenceValue = 1;

        m_fenceEvent = CreateEvent(T100NULL, FALSE, FALSE, T100NULL);
        if (m_fenceEvent == T100NULL)
        {
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }

        WaitForPreviousFrame();
    }
}

T100VOID T100DX12::LoadEntities()
{
    for(T100Entity* entity : m_entities){
        LoadEntity(entity);
    }
}

T100VOID T100DX12::LoadEntity(T100Entity* entity)
{

}


T100VOID T100DX12::PopulateCommandList()
{
    ThrowIfFailed(m_commandAllocator->Reset());

    ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());
    m_commandList->RSSetViewports(1, &m_viewport);
    m_commandList->RSSetScissorRects(1, &m_scissorRect);


    CD3DX12_RESOURCE_BARRIER    barrier1 = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                m_renderTargets[m_frameIndex].Get(),
                                                                                D3D12_RESOURCE_STATE_PRESENT,
                                                                                D3D12_RESOURCE_STATE_RENDER_TARGET
                                                                                );
    m_commandList->ResourceBarrier(1, &barrier1);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);
    m_commandList->OMSetRenderTargets(1, &rtvHandle, T100FALSE, T100NULL);

    const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_commandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
    m_commandList->DrawInstanced(3, 1, 0, 0);

    CD3DX12_RESOURCE_BARRIER    barrier2 = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                m_renderTargets[m_frameIndex].Get(),
                                                                                D3D12_RESOURCE_STATE_RENDER_TARGET,
                                                                                D3D12_RESOURCE_STATE_PRESENT
                                                                                );
    m_commandList->ResourceBarrier(1, &barrier2);

    ThrowIfFailed(m_commandList->Close());
}

T100VOID T100DX12::WaitForPreviousFrame()
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

_Use_decl_annotations_
T100VOID T100DX12::GetHardwareAdapter(
    IDXGIFactory1* pFactory,
    IDXGIAdapter1** ppAdapter,
    T100BOOL requestHighPerformanceAdapter)
{
    *ppAdapter                  = T100NULL;

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
            ++adapterIndex
            )
        {
            DXGI_ADAPTER_DESC1          desc;
            adapter->GetDesc1(&desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if(SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), nullptr)))
            {
                break;
            }
        }
    }

    if(adapter.Get() == nullptr)
    {
        for(UINT adapterIndex = 0; SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter)); ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1      desc;
            adapter->GetDesc1(&desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                continue;
            }

            if(SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), nullptr)))
            {
                break;
            }
        }
    }

    *ppAdapter = adapter.Detach();
}

std::wstring T100DX12::GetAssetFullPath(LPCWSTR assetName)
{
    return m_assetsPath + L"..\\..\\resources\\" + assetName;
}
