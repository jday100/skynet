#include "T100DXEntity.h"

#include "T100DX12Tools.h"

T100DXEntity::T100DXEntity() :
    m_hwnd(T100NULL),
    m_width(0),
    m_height(0),
    m_entityManager(this),
    m_useWarpDevice(T100FALSE),
    m_aspectRatio(0),
    m_frameIndex(0),
    m_frameCounter(0),
    m_fenceValue(0),
    m_rtvDescriptorSize(0),
    m_currentFrameResourceIndex(0),
    m_pCurrentFrameResource(T100NULL)
{
    //ctor
}

T100DXEntity::~T100DXEntity()
{
    //dtor
}

T100VOID T100DXEntity::Create(HWND hwnd, UINT width, UINT height)
{
    m_hwnd      = hwnd;
    m_width     = width;
    m_height    = height;
}

T100VOID T100DXEntity::Destroy()
{

}

T100VOID T100DXEntity::SetSize(UINT width, UINT height)
{
    m_width     = width;
    m_height    = height;
}

T100VOID T100DXEntity::Start()
{
    WCHAR       assetsPath[512];
    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath    = assetsPath;

    m_aspectRatio   = static_cast<float>(m_width) / static_cast<float>(m_height);
    m_viewport      = CD3DX12_VIEWPORT(0.0f, 0.0f, static_cast<float>(m_width), static_cast<float>(m_height));
    m_scissorRect   = CD3DX12_RECT(0, 0, static_cast<LONG>(m_width), static_cast<LONG>(m_height));

    if(m_entityManager.Empty())
    {
        m_camera.Init({15, 8, 30});

        LoadPipelineEmpty();
        LoadAssetsEmpty();
    }
    else
    {
        m_camera.Init({15, 8, 30});

        LoadPipeline();
        LoadAssets();
    }
}

T100VOID T100DXEntity::Stop()
{

}

T100VOID T100DXEntity::Update()
{
    if(m_entityManager.Empty())
    {

    }
    else
    {
        UpdateFrameTimer();
        UpdateFence();
        UpdateCamera();
        UpdateFrameResource();
    }
}

T100VOID T100DXEntity::Render()
{
    if(m_entityManager.Empty())
    {
        PopulateCommandListEmpty();
        ExecuteCommandListEmpty();
        SwapChainPresent();
        WaitForPreviousFrame();
    }
    else
    {
        PopulateCommandList(T100TRUE, m_pCurrentFrameResource);
        ExecuteCommandListRender();
        SwapChainPresent();
        FenceSignal();
    }

}

T100VOID T100DXEntity::Append(T100Entity* entity)
{
    m_entityManager.Append(entity);
}

T100VOID T100DXEntity::OnKeyDown(UINT8 key)
{
    m_camera.OnKeyDown(key);
}

T100VOID T100DXEntity::OnKeyUp(UINT8 key)
{
    m_camera.OnKeyUp(key);
}

T100VOID T100DXEntity::LoadPipeline()
{
    CreateFactory();
    CreateDevice();
    CreateCommandQueue();
    CreateSwapChain();
    CreateRtvHeap();
    CreateDsvHeap();
    CreateCbvHeap(0, 0);
    CreateSamplerHeap();
    CreateCommandAllocator();
}

T100VOID T100DXEntity::LoadPipelineEmpty()
{
    CreateFactory();
    CreateDevice();
    CreateCommandQueue();
    CreateSwapChain();
    CreateRtvHeap();
    CreateRenderTargetView();
    CreateCommandAllocator();
}

T100VOID T100DXEntity::CreateFactory()
{
    UINT        dxgiFactoryFlags        = 0;

    ThrowIfFailed(CreateDXGIFactory2(
                                     dxgiFactoryFlags,
                                     IID_PPV_ARGS(&m_factory)
                                     ));
}

T100VOID T100DXEntity::CreateDevice()
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
T100VOID T100DXEntity::GetHardwareAdapter(
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

T100VOID T100DXEntity::CreateCommandQueue()
{
    D3D12_COMMAND_QUEUE_DESC            queueDesc           = {};

    queueDesc.Flags         = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type          = D3D12_COMMAND_LIST_TYPE_DIRECT;

    ThrowIfFailed(m_device->CreateCommandQueue(
                                               &queueDesc,
                                               IID_PPV_ARGS(&m_commandQueue)
                                               ));
}

T100VOID T100DXEntity::CreateSwapChain()
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

T100VOID T100DXEntity::CreateRtvHeap()
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

T100VOID T100DXEntity::CreateDsvHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          dsvHeapDesc         = {};

    dsvHeapDesc.NumDescriptors          = 1;
    dsvHeapDesc.Type                    = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags                   = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &dsvHeapDesc,
                                                 IID_PPV_ARGS(&m_dsvHeap)
                                                 ));
}

T100VOID T100DXEntity::CreateCbvHeap(UINT row, UINT column)
{
    D3D12_DESCRIPTOR_HEAP_DESC          cbvSrvHeapDesc      = {};

    cbvSrvHeapDesc.NumDescriptors       =
        m_frameCount * row * column
        + 1;
    cbvSrvHeapDesc.Type                 = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    cbvSrvHeapDesc.Flags                = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &cbvSrvHeapDesc,
                                                 IID_PPV_ARGS(&m_cbvSrvHeap)
                                                 ));
    m_cbvSrvDescriptorSize      = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
}

T100VOID T100DXEntity::CreateSamplerHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC          samplerHeapDesc     = {};

    samplerHeapDesc.NumDescriptors      = 1;
    samplerHeapDesc.Type                = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    samplerHeapDesc.Flags               = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    ThrowIfFailed(m_device->CreateDescriptorHeap(
                                                 &samplerHeapDesc,
                                                 IID_PPV_ARGS(&m_samplerHeap)
                                                 ));

}

T100VOID T100DXEntity::CreateCommandAllocator()
{
    ThrowIfFailed(m_device->CreateCommandAllocator(
                                                   D3D12_COMMAND_LIST_TYPE_DIRECT,
                                                   IID_PPV_ARGS(&m_commandAllocator)
                                                   ));
}

T100VOID T100DXEntity::LoadAssetsSingle()
{
    /*
    ComPtr<ID3D12Resource>              vertexBufferUploadHeap;
    ComPtr<ID3D12Resource>              indexBufferUploadHeap;
    ComPtr<ID3D12Resource>              textureUploadHeap;

    CreateRootSignature();

    {
        UINT8*                  pVertexShaderData;
        UINT8*                  pPixelShaderData1;
        UINT8*                  pPixelShaderData2;
        UINT                    vertexShaderDataLength;
        UINT                    pixelShaderDataLength1;
        UINT                    pixelShaderDataLength2;

        LoadShader(
               &pVertexShaderData,
               vertexShaderDataLength,
               &pPixelShaderData1,
               pixelShaderDataLength1,
               &pPixelShaderData2,
               pixelShaderDataLength2
               );

        CreatePipelineState(
                        pVertexShaderData,
                        vertexShaderDataLength,
                        pPixelShaderData1,
                        pixelShaderDataLength1,
                        pPixelShaderData2,
                        pixelShaderDataLength2
                        );

        delete pVertexShaderData;
        delete pPixelShaderData1;
        delete pPixelShaderData2;
    }

    CreateCommandList();
    CreateRenderTargetView();

    UINT8*              pMeshData;
    UINT                meshDataLength;

    LoadMeshData(&pMeshData, meshDataLength);
    CreateVertexBuffer(vertexBufferUploadHeap, pMeshData, meshDataLength);
    CreateIndexBuffer(indexBufferUploadHeap, pMeshData, meshDataLength);

    {


        UINT    subresourceCount;
        UINT64  uploadBufferSize;

        CreateTexture(subresourceCount, uploadBufferSize);

        CD3DX12_HEAP_PROPERTIES         sampler_heap(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC           sampler_desc        = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
        ThrowIfFailed(m_device->CreateCommittedResource(
            &sampler_heap,
            D3D12_HEAP_FLAG_NONE,
            &sampler_desc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&textureUploadHeap)));

        D3D12_SUBRESOURCE_DATA          textureData = {};
        textureData.pData               = pMeshData + SampleAssets::Textures[0].Data[0].Offset;
        textureData.RowPitch            = SampleAssets::Textures[0].Data[0].Pitch;
        textureData.SlicePitch          = SampleAssets::Textures[0].Data[0].Size;

        UpdateSubresources(m_commandList.Get(), m_texture.Get(), textureUploadHeap.Get(), 0, 0, subresourceCount, &textureData);
        CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_texture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
        m_commandList->ResourceBarrier(1, &barrier);

        D3D12_SAMPLER_DESC              samplerDesc = {};
        samplerDesc.Filter              = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
        samplerDesc.AddressU            = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        samplerDesc.AddressV            = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        samplerDesc.AddressW            = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        samplerDesc.MinLOD              = 0;
        samplerDesc.MaxLOD              = D3D12_FLOAT32_MAX;
        samplerDesc.MipLODBias          = 0.0f;
        samplerDesc.MaxAnisotropy       = 1;
        samplerDesc.ComparisonFunc      = D3D12_COMPARISON_FUNC_ALWAYS;
        m_device->CreateSampler(&samplerDesc, m_samplerHeap->GetCPUDescriptorHandleForHeapStart());

        D3D12_SHADER_RESOURCE_VIEW_DESC         srvDesc = {};
        srvDesc.Shader4ComponentMapping         = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        srvDesc.Format                          = SampleAssets::Textures->Format;
        srvDesc.ViewDimension                   = D3D12_SRV_DIMENSION_TEXTURE2D;
        srvDesc.Texture2D.MipLevels             = 1;
        m_device->CreateShaderResourceView(m_texture.Get(), &srvDesc, m_cbvSrvHeap->GetCPUDescriptorHandleForHeapStart());
    }

    delete pMeshData;

    CreateDepthStencilView();

    ExecuteCommandList();

    CreateFence();

    CreateFrameResources(0, 0);
    */
}

T100VOID T100DXEntity::LoadAssets()
{
    /*
    UINT8*          pVertexShaderData;
    UINT8*          pPixelShaderData1;
    UINT8*          pPixelShaderData2;
    UINT            vertexShaderDataLength;
    UINT            pixelShaderDataLength1;
    UINT            pixelShaderDataLength2;

    UINT8*          pMeshData;
    UINT            meshDataLength;

    UINT            subresourceCount;
    UINT64          uploadBufferSize;

    ComPtr<ID3D12Resource> vertexBufferUploadHeap;
    ComPtr<ID3D12Resource> indexBufferUploadHeap;
    ComPtr<ID3D12Resource> textureUploadHeap;

    CreateRootSignature();
    LoadShader(
               &pVertexShaderData,
               vertexShaderDataLength,
               &pPixelShaderData1,
               pixelShaderDataLength1,
               &pPixelShaderData2,
               pixelShaderDataLength2
               );
    CreatePipelineState(
                        pVertexShaderData,
                        vertexShaderDataLength,
                        pPixelShaderData1,
                        pixelShaderDataLength1,
                        pPixelShaderData2,
                        pixelShaderDataLength2
                        );
    CreateCommandList();
    CreateRenderTargetView();
    LoadMeshData(&pMeshData, meshDataLength);
    CreateVertexBuffer(vertexBufferUploadHeap, pMeshData, meshDataLength);
    CreateIndexBuffer(indexBufferUploadHeap, pMeshData, meshDataLength);
    CreateTexture(subresourceCount, uploadBufferSize);
    CreateSampler(textureUploadHeap, pMeshData, meshDataLength, subresourceCount, uploadBufferSize);
    CreateTextureSRV();
    CreateDepthStencilView();
    ExecuteCommandList();
    CreateFence();
    CreateFrameResources(0, 0);
    */
}

T100VOID T100DXEntity::LoadAssetsEmpty()
{
    CreateCommandListEmpty();
    CreateFence();
}

T100VOID T100DXEntity::CreateRootSignature()
{
    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion  = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(m_device->CheckFeatureSupport(
                                            D3D12_FEATURE_ROOT_SIGNATURE,
                                            &featureData,
                                            sizeof(featureData)
                                            )))
    {
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
    }

    CD3DX12_DESCRIPTOR_RANGE1           ranges[3];

    ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);
    ranges[1].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER, 1, 0);
    ranges[2].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

    CD3DX12_ROOT_PARAMETER1             rootParameters[3];

    rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_PIXEL);
    rootParameters[1].InitAsDescriptorTable(1, &ranges[1], D3D12_SHADER_VISIBILITY_PIXEL);
    rootParameters[2].InitAsDescriptorTable(1, &ranges[2], D3D12_SHADER_VISIBILITY_ALL);

    CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC           rootSignatureDesc;

    rootSignatureDesc.Init_1_1(
                               _countof(rootParameters),
                               rootParameters,
                               0,
                               T100NULL,
                               D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
                               );

    ComPtr<ID3DBlob>        signature;
    ComPtr<ID3DBlob>        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(
                                                        &rootSignatureDesc,
                                                        featureData.HighestVersion,
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

T100VOID T100DXEntity::LoadShader(
                                   UINT8** ppVertexShaderData,
                                   UINT& vertexShaderDataLength,
                                   UINT8** ppPixelShaderData1,
                                   UINT& pixelShaderDataLength1,
                                   UINT8** ppPixelShaderData2,
                                   UINT& pixelShaderDataLength2)
{


    ThrowIfFailed(ReadDataFromFile(
                                   GetAssetFullPath(L"shader_mesh_simple_vert.cso").c_str(),
                                   ppVertexShaderData,
                                   &vertexShaderDataLength));
    ThrowIfFailed(ReadDataFromFile(
                                   GetAssetFullPath(L"shader_mesh_simple_pixel.cso").c_str(),
                                   ppPixelShaderData1,
                                   &pixelShaderDataLength1));
    ThrowIfFailed(ReadDataFromFile(
                                   GetAssetFullPath(L"shader_mesh_alt_pixel.cso").c_str(),
                                   ppPixelShaderData2,
                                   &pixelShaderDataLength2));

}

T100VOID T100DXEntity::CreatePipelineState(
                                             const D3D12_INPUT_ELEMENT_DESC* StandardVertexDescription,
                                             UINT StandardVertexDescriptionNumElements,
                                             UINT8* pVertexShaderData,
                                             UINT vertexShaderDataLength,
                                             UINT8* pPixelShaderData1,
                                             UINT pixelShaderDataLength1,
                                             UINT8* pPixelShaderData2,
                                             UINT pixelShaderDataLength2)
{
    CD3DX12_RASTERIZER_DESC         rasterizerStateDesc(D3D12_DEFAULT);

    rasterizerStateDesc.CullMode    = D3D12_CULL_MODE_NONE;

    D3D12_GRAPHICS_PIPELINE_STATE_DESC          psoDesc     = {};

    psoDesc.InputLayout             = {StandardVertexDescription, StandardVertexDescriptionNumElements};
    psoDesc.pRootSignature          = m_rootSignature.Get();
    psoDesc.VS                      = CD3DX12_SHADER_BYTECODE(pVertexShaderData, vertexShaderDataLength);
    psoDesc.PS                      = CD3DX12_SHADER_BYTECODE(pPixelShaderData1, pixelShaderDataLength1);
    psoDesc.RasterizerState         = rasterizerStateDesc;
    psoDesc.BlendState              = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
    psoDesc.DepthStencilState       = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
    psoDesc.SampleMask              = UINT_MAX;
    psoDesc.PrimitiveTopologyType   = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    psoDesc.NumRenderTargets        = 1;
    psoDesc.RTVFormats[0]           = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.DSVFormat               = DXGI_FORMAT_D32_FLOAT;
    psoDesc.SampleDesc.Count        = 1;

    ThrowIfFailed(m_device->CreateGraphicsPipelineState(
                                                        &psoDesc,
                                                        IID_PPV_ARGS(&m_pipelineState1)
                                                        ));

    psoDesc.PS                      = CD3DX12_SHADER_BYTECODE(pPixelShaderData2, pixelShaderDataLength2);

    ThrowIfFailed(m_device->CreateGraphicsPipelineState(
                                                        &psoDesc,
                                                        IID_PPV_ARGS(&m_pipelineState2)
                                                        ));

    //delete pVertexShaderData;
    //delete pPixelShaderData1;
    //delete pPixelShaderData2;
}

T100VOID T100DXEntity::CreateCommandList()
{
    ThrowIfFailed(m_device->CreateCommandList(
                                              0,
                                              D3D12_COMMAND_LIST_TYPE_DIRECT,
                                              m_commandAllocator.Get(),
                                              T100NULL,
                                              IID_PPV_ARGS(&m_commandList)
                                              ));

}

T100VOID T100DXEntity::CreateCommandListEmpty()
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

T100VOID T100DXEntity::CreateRenderTargetView()
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE           rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

    for(UINT i = 0; i < m_frameCount; i++)
    {
        ThrowIfFailed(m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i])));
        m_device->CreateRenderTargetView(m_renderTargets[i].Get(), T100NULL, rtvHandle);
        rtvHandle.Offset(1, m_rtvDescriptorSize);
    }
}

T100VOID T100DXEntity::CreateVertexBuffer(UINT VertexDataSize, UINT VertexDataOffset, UINT StandardVertexStride,
                                            ComPtr<ID3D12Resource>& vertexBufferUploadHeap,
                                            UINT8* pMeshData, UINT meshDataLength)
{
    CD3DX12_HEAP_PROPERTIES         vertex_heap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           vertex_desc         = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);

    ThrowIfFailed(m_device->CreateCommittedResource(
                                                    &vertex_heap,
                                                    D3D12_HEAP_FLAG_NONE,
                                                    &vertex_desc,
                                                    D3D12_RESOURCE_STATE_COPY_DEST,
                                                    T100NULL,
                                                    IID_PPV_ARGS(&m_vertexBuffer)
                                                    ));

    CD3DX12_HEAP_PROPERTIES         upload_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           upload_desc         = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);

    ThrowIfFailed(m_device->CreateCommittedResource(
                                                    &upload_heap,
                                                    D3D12_HEAP_FLAG_NONE,
                                                    &upload_desc,
                                                    D3D12_RESOURCE_STATE_GENERIC_READ,
                                                    T100NULL,
                                                    IID_PPV_ARGS(&vertexBufferUploadHeap)
                                                    ));

    D3D12_SUBRESOURCE_DATA          vertexData      = {};

    vertexData.pData        = pMeshData + VertexDataOffset;
    vertexData.RowPitch     = VertexDataSize;
    vertexData.SlicePitch   = vertexData.RowPitch;

    UpdateSubresources<1>(
                          m_commandList.Get(),
                          m_vertexBuffer.Get(),
                          vertexBufferUploadHeap.Get(),
                          0,
                          0,
                          1,
                          &vertexData
                          );

    CD3DX12_RESOURCE_BARRIER        barrier     = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                       m_vertexBuffer.Get(),
                                                                                       D3D12_RESOURCE_STATE_COPY_DEST,
                                                                                       D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
    m_commandList->ResourceBarrier(1, &barrier);

    m_vertexBufferView.BufferLocation       = m_vertexBuffer->GetGPUVirtualAddress();
    m_vertexBufferView.StrideInBytes        = StandardVertexStride;
    m_vertexBufferView.SizeInBytes          = VertexDataSize;
}

T100VOID T100DXEntity::CreateIndexBuffer(UINT IndexDataSize, UINT IndexDataOffset, const DXGI_FORMAT StandardIndexFormat,
                                           ComPtr<ID3D12Resource>& indexBufferUploadHeap, UINT8* pMeshData, UINT meshDataLength)
{
    CD3DX12_HEAP_PROPERTIES         index_heap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           index_desc      = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);

    ThrowIfFailed(m_device->CreateCommittedResource(
                                                    &index_heap,
                                                    D3D12_HEAP_FLAG_NONE,
                                                    &index_desc,
                                                    D3D12_RESOURCE_STATE_COPY_DEST,
                                                    T100NULL,
                                                    IID_PPV_ARGS(&m_indexBuffer)
                                                    ));

    CD3DX12_HEAP_PROPERTIES         index_upload_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           index_upload_desc       = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);

    ThrowIfFailed(m_device->CreateCommittedResource(
                                                    &index_upload_heap,
                                                    D3D12_HEAP_FLAG_NONE,
                                                    &index_upload_desc,
                                                    D3D12_RESOURCE_STATE_GENERIC_READ,
                                                    T100NULL,
                                                    IID_PPV_ARGS(&indexBufferUploadHeap)
                                                    ));

    D3D12_SUBRESOURCE_DATA          indexData       = {};

    indexData.pData         = pMeshData + IndexDataOffset;
    indexData.RowPitch      = IndexDataSize;
    indexData.SlicePitch    = indexData.RowPitch;

    UpdateSubresources<1>(
                          m_commandList.Get(),
                          m_indexBuffer.Get(),
                          indexBufferUploadHeap.Get(),
                          0,
                          0,
                          1,
                          &indexData);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                           m_indexBuffer.Get(),
                                                                                           D3D12_RESOURCE_STATE_COPY_DEST,
                                                                                           D3D12_RESOURCE_STATE_INDEX_BUFFER);
    m_commandList->ResourceBarrier(1, &barrier);

    m_indexBufferView.BufferLocation    = m_indexBuffer->GetGPUVirtualAddress();
    m_indexBufferView.Format            = StandardIndexFormat;
    m_indexBufferView.SizeInBytes       = IndexDataSize;

    m_numIndices = IndexDataSize / 4;
}

T100VOID T100DXEntity::CreateTexture(const T100City::TextureResource* Textures, UINT& subresourceCount, UINT64& uploadBufferSize)
{
    D3D12_RESOURCE_DESC             textureDesc         = {};

    textureDesc.MipLevels           = Textures[0].MipLevels;
    textureDesc.Format              = Textures[0].Format;
    textureDesc.Width               = Textures[0].Width;
    textureDesc.Height              = Textures[0].Height;
    textureDesc.Flags               = D3D12_RESOURCE_FLAG_NONE;
    textureDesc.DepthOrArraySize    = 1;
    textureDesc.SampleDesc.Count    = 1;
    textureDesc.SampleDesc.Quality  = 0;
    textureDesc.Dimension           = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

    CD3DX12_HEAP_PROPERTIES         texture_heap(D3D12_HEAP_TYPE_DEFAULT);
    ThrowIfFailed(m_device->CreateCommittedResource(
                                                    &texture_heap,
                                                    D3D12_HEAP_FLAG_NONE,
                                                    &textureDesc,
                                                    D3D12_RESOURCE_STATE_COPY_DEST,
                                                    T100NULL,
                                                    IID_PPV_ARGS(&m_texture)
                                                    ));
    subresourceCount        = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
    uploadBufferSize        = GetRequiredIntermediateSize(m_texture.Get(), 0, subresourceCount);
}

T100VOID T100DXEntity::CreateSampler(
                                       const T100City::TextureResource* Textures,
                                       ComPtr<ID3D12Resource>& textureUploadHeap,
                                       UINT8* pMeshData,
                                       UINT meshDataLength,
                                       UINT subresourceCount,
                                       UINT64 uploadBufferSize)
{
    CD3DX12_HEAP_PROPERTIES         sampler_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           sampler_desc        = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
    ThrowIfFailed(m_device->CreateCommittedResource(
                                                    &sampler_heap,
                                                    D3D12_HEAP_FLAG_NONE,
                                                    &sampler_desc,
                                                    D3D12_RESOURCE_STATE_GENERIC_READ,
                                                    T100NULL,
                                                    IID_PPV_ARGS(&textureUploadHeap)
                                                    ));

    D3D12_SUBRESOURCE_DATA          textureData         = {};

    textureData.pData           = pMeshData + Textures[0].Data[0].Offset;
    textureData.RowPitch        = Textures[0].Data[0].Pitch;
    textureData.SlicePitch      = Textures[0].Data[0].Size;

    UpdateSubresources(
                       m_commandList.Get(),
                       m_texture.Get(),
                       textureUploadHeap.Get(),
                       0,
                       0,
                       subresourceCount,
                       &textureData);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(
                                                                                           m_texture.Get(),
                                                                                           D3D12_RESOURCE_STATE_COPY_DEST,
                                                                                           D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
    m_commandList->ResourceBarrier(1, &barrier);

    D3D12_SAMPLER_DESC          samplerDesc         = {};

    samplerDesc.Filter          = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
    samplerDesc.AddressU        = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    samplerDesc.AddressV        = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    samplerDesc.AddressW        = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    samplerDesc.MinLOD          = 0;
    samplerDesc.MaxLOD          = D3D12_FLOAT32_MAX;
    samplerDesc.MipLODBias      = 0.0f;
    samplerDesc.MaxAnisotropy   = 1;
    samplerDesc.ComparisonFunc  = D3D12_COMPARISON_FUNC_ALWAYS;

    m_device->CreateSampler(&samplerDesc, m_samplerHeap->GetCPUDescriptorHandleForHeapStart());

    //delete pMeshData;
}

T100VOID T100DXEntity::CreateTextureSRV(const T100City::TextureResource* Textures)
{
    D3D12_SHADER_RESOURCE_VIEW_DESC             srvDesc         = {};

    srvDesc.Shader4ComponentMapping             = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Format                              = Textures->Format;
    srvDesc.ViewDimension                       = D3D12_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels                 = 1;

    m_device->CreateShaderResourceView(
                                       m_texture.Get(),
                                       &srvDesc,
                                       m_cbvSrvHeap->GetCPUDescriptorHandleForHeapStart());

}

T100VOID T100DXEntity::CreateDepthStencilView()
{
    D3D12_DEPTH_STENCIL_VIEW_DESC           depthStencilDesc        = {};

    depthStencilDesc.Format             = DXGI_FORMAT_D32_FLOAT;
    depthStencilDesc.ViewDimension      = D3D12_DSV_DIMENSION_TEXTURE2D;
    depthStencilDesc.Flags              = D3D12_DSV_FLAG_NONE;

    D3D12_CLEAR_VALUE                       depthOptimizedClearValue = {};

    depthOptimizedClearValue.Format                 = DXGI_FORMAT_D32_FLOAT;
    depthOptimizedClearValue.DepthStencil.Depth     = 1.0f;
    depthOptimizedClearValue.DepthStencil.Stencil   = 0;

    CD3DX12_HEAP_PROPERTIES         depth_heap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           depth_desc          = CD3DX12_RESOURCE_DESC::Tex2D(
                                                                                       DXGI_FORMAT_D32_FLOAT,
                                                                                       m_width,
                                                                                       m_height,
                                                                                       1,
                                                                                       0,
                                                                                       1,
                                                                                       0,
                                                                                       D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL);

    ThrowIfFailed(m_device->CreateCommittedResource(
                                                    &depth_heap,
                                                    D3D12_HEAP_FLAG_NONE,
                                                    &depth_desc,
                                                    D3D12_RESOURCE_STATE_DEPTH_WRITE,
                                                    &depthOptimizedClearValue,
                                                    IID_PPV_ARGS(&m_depthStencil)
                                                    ));

    m_device->CreateDepthStencilView(
                                     m_depthStencil.Get(),
                                     &depthStencilDesc,
                                     m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
}

T100VOID T100DXEntity::ExecuteCommandList()
{
    ThrowIfFailed(m_commandList->Close());

    ID3D12CommandList*      ppCommandLists[] = {m_commandList.Get()};

    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
}

T100VOID T100DXEntity::CreateFence()
{
    ThrowIfFailed(m_device->CreateFence(
                                        m_fenceValue,
                                        D3D12_FENCE_FLAG_NONE,
                                        IID_PPV_ARGS(&m_fence)
                                        ));
    m_fenceValue++;

    m_fenceEvent        = CreateEvent(T100NULL, T100FALSE, T100FALSE, T100NULL);
    if(m_fenceEvent == T100NULL)
    {
        ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
    }

    const UINT64 fenceToWaitFor     = m_fenceValue;

    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fenceToWaitFor));
    m_fenceValue++;

    ThrowIfFailed(m_fence->SetEventOnCompletion(fenceToWaitFor, m_fenceEvent));
    WaitForSingleObject(m_fenceEvent, INFINITE);

}

T100VOID T100DXEntity::UpdateFrameTimer()
{
    m_timer.Tick(T100NULL);

    if(m_frameCounter == 500)
    {
        wchar_t         fps[64];

        swprintf_s(fps, L"%ufps", m_timer.GetFramesPerSecond());
        SetCustomWindowText(fps);
        m_frameCounter  = 0;
    }

    m_frameCounter++;
}

T100VOID T100DXEntity::UpdateFence()
{
    const UINT64 lastCompletedFence = m_fence->GetCompletedValue();

    m_currentFrameResourceIndex     = (m_currentFrameResourceIndex + 1) % m_frameCount;
    m_pCurrentFrameResource         = m_frameResources[m_currentFrameResourceIndex];

    if(m_pCurrentFrameResource->m_fenceValue != 0 && m_pCurrentFrameResource->m_fenceValue > lastCompletedFence)
    {
        ThrowIfFailed(m_fence->SetEventOnCompletion(m_pCurrentFrameResource->m_fenceValue, m_fenceEvent));
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }
}

T100VOID T100DXEntity::UpdateCamera()
{
    m_camera.Update(static_cast<float>(m_timer.GetElapsedSeconds()));
}

T100VOID T100DXEntity::UpdateFrameResource()
{
    m_pCurrentFrameResource->UpdateConstantBuffers(
                                                   m_camera.GetViewMatrix(),
                                                   m_camera.GetProjectionMatrix(0.8f, m_aspectRatio));
}

T100VOID T100DXEntity::PopulateCommandList(T100BOOL useBundles, T100DXFrameResource* pFrameResource)
{
    ThrowIfFailed(m_pCurrentFrameResource->m_commandAllocator->Reset());

    ThrowIfFailed(m_commandList->Reset(m_pCurrentFrameResource->m_commandAllocator.Get(), m_pipelineState1.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = { m_cbvSrvHeap.Get(), m_samplerHeap.Get() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_viewport);
    m_commandList->RSSetScissorRects(1, &m_scissorRect);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    const float         clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->ClearDepthStencilView(m_dsvHeap->GetCPUDescriptorHandleForHeapStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    if (useBundles)
    {
        m_commandList->ExecuteBundle(pFrameResource->m_bundle.Get());
    }
    else
    {
        pFrameResource->PopulateCommandList(m_commandList.Get(), m_pipelineState1.Get(), m_pipelineState2.Get(), m_currentFrameResourceIndex, m_numIndices, &m_indexBufferView,
            &m_vertexBufferView, m_cbvSrvHeap.Get(), m_cbvSrvDescriptorSize, m_samplerHeap.Get(), m_rootSignature.Get());
    }

    CD3DX12_RESOURCE_BARRIER        present_barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &present_barrier);

    ThrowIfFailed(m_commandList->Close());
}

T100VOID T100DXEntity::ExecuteCommandListRender()
{
    ID3D12CommandList*      ppCommandLists[] = {m_commandList.Get()};
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
}


T100VOID T100DXEntity::PopulateCommandListEmpty()
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

T100VOID T100DXEntity::ExecuteCommandListEmpty()
{
    ID3D12CommandList* ppCommandLists[] = {m_commandList.Get()};
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
}

T100VOID T100DXEntity::SwapChainPresent()
{
    ThrowIfFailed(m_swapChain->Present(1, 0));
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
}

T100VOID T100DXEntity::FenceSignal()
{
    m_pCurrentFrameResource->m_fenceValue = m_fenceValue;
    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), m_fenceValue));
    m_fenceValue++;
}

T100VOID T100DXEntity::WaitForPreviousFrame()
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

std::wstring T100DXEntity::GetAssetFullPath(LPCWSTR assetName)
{
    return m_assetsPath + L"..\\..\\resources\\" + assetName;
}

void T100DXEntity::SetCustomWindowText(LPCWSTR text)
{
    std::wstring windowText = m_title + L": " + text;
    SetWindowTextW(m_hwnd, windowText.c_str());
}

T100VOID T100DXEntity::LoadShaderFile(
                                        T100WSTRING filename,
                                        UINT8** ppShaderData,
                                        UINT& shaderDataLength)
{


    ThrowIfFailed(ReadDataFromFile(
                                   GetAssetFullPath(filename.c_str()).c_str(),
                                   ppShaderData,
                                   &shaderDataLength));
}

T100VOID T100DXEntity::LoadMeshFile(
                                      T100WSTRING filename,
                                      UINT8** ppMeshData,
                                      UINT& meshDataLength)
{
    ThrowIfFailed(ReadDataFromFile(GetAssetFullPath(filename.c_str()).c_str(), ppMeshData, &meshDataLength));
}

T100VOID T100DXEntity::CreateFrameResources(UINT row, UINT column)
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE           cbvSrvHandle(
                                                         m_cbvSrvHeap->GetCPUDescriptorHandleForHeapStart(),
                                                         1,
                                                         m_cbvSrvDescriptorSize);
    for(UINT i = 0; i < m_frameCount; i++)
    {
        T100DXFrameResource* pFrameResource = new T100DXFrameResource(m_device.Get(), row, column);

        UINT64      cbOffset = 0;
        for(UINT j = 0; j < row; j++)
        {
            for(UINT k = 0; k < column; k++)
            {
                D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
                cbvDesc.BufferLocation      = pFrameResource->m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
                cbvDesc.SizeInBytes         = sizeof(T100DXFrameResource::SceneConstantBuffer);
                cbOffset                    += cbvDesc.SizeInBytes;
                m_device->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
                cbvSrvHandle.Offset(m_cbvSrvDescriptorSize);
            }
        }

        pFrameResource->InitBundle(m_device.Get(), m_pipelineState1.Get(), m_pipelineState2.Get(), i, m_numIndices, &m_indexBufferView,
            &m_vertexBufferView, m_cbvSrvHeap.Get(), m_cbvSrvDescriptorSize, m_samplerHeap.Get(), m_rootSignature.Get());

        m_frameResources.push_back(pFrameResource);
    }
}
