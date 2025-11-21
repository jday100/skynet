#include "T100DX12Bundle.h"

#include "T100DX12Tools.h"
#include "T100DX12Studio.h"
#include "T100City.h"

T100DX12Bundle::T100DX12Bundle(T100DX12Studio* studio) :
    m_studio(studio)
{
    //ctor
}

T100DX12Bundle::~T100DX12Bundle()
{
    //dtor
}

T100VOID T100DX12Bundle::LoadAssets()
{
    m_entity    = T100NEW T100City();

    ThrowIfFailed(m_studio->m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator)));

    ComPtr<ID3D12Resource>              vertexBufferUploadHeap;
    ComPtr<ID3D12Resource>              indexBufferUploadHeap;
    ComPtr<ID3D12Resource>              textureUploadHeap;

    {
        D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

        featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

        if(FAILED(m_studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
        {
            featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
        }

        CD3DX12_DESCRIPTOR_RANGE1               ranges[3];

        ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);
        ranges[1].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER, 1, 0);
        ranges[2].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

        CD3DX12_ROOT_PARAMETER1                 rootParameters[3];

        rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_PIXEL);
        rootParameters[1].InitAsDescriptorTable(1, &ranges[1], D3D12_SHADER_VISIBILITY_PIXEL);
        rootParameters[2].InitAsDescriptorTable(1, &ranges[2], D3D12_SHADER_VISIBILITY_ALL);

        CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC   rootSignatureDesc;
        rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

        ComPtr<ID3DBlob>                        signature;
        ComPtr<ID3DBlob>                        error;

        ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
        ThrowIfFailed(m_studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature)));
    }

    {
        UINT8*                  pVertexShaderData;
        UINT8*                  pPixelShaderData1;
        UINT8*                  pPixelShaderData2;
        UINT                    vertexShaderDataLength;
        UINT                    pixelShaderDataLength1;
        UINT                    pixelShaderDataLength2;

        ThrowIfFailed(ReadDataFromFile(m_studio->m_scene_manager.GetScene()->GetAssetFullPath(L"shader_mesh_simple_vert.cso").c_str(), &pVertexShaderData, &vertexShaderDataLength));
        ThrowIfFailed(ReadDataFromFile(m_studio->m_scene_manager.GetScene()->GetAssetFullPath(L"shader_mesh_simple_pixel.cso").c_str(), &pPixelShaderData1, &pixelShaderDataLength1));
        ThrowIfFailed(ReadDataFromFile(m_studio->m_scene_manager.GetScene()->GetAssetFullPath(L"shader_mesh_alt_pixel.cso").c_str(), &pPixelShaderData2, &pixelShaderDataLength2));

        CD3DX12_RASTERIZER_DESC                 rasterizerStateDesc(D3D12_DEFAULT);
        rasterizerStateDesc.CullMode = D3D12_CULL_MODE_NONE;

        D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

        //psoDesc.InputLayout                     = { m_entity->StandardVertexDescription, m_entity->StandardVertexDescriptionNumElements };
        psoDesc.pRootSignature                  = m_rootSignature.Get();
        psoDesc.VS                              = CD3DX12_SHADER_BYTECODE(pVertexShaderData, vertexShaderDataLength);
        psoDesc.PS                              = CD3DX12_SHADER_BYTECODE(pPixelShaderData1, pixelShaderDataLength1);
        psoDesc.RasterizerState                 = rasterizerStateDesc;
        psoDesc.BlendState                      = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState               = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
        psoDesc.SampleMask                      = UINT_MAX;
        psoDesc.PrimitiveTopologyType           = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets                = 1;
        psoDesc.RTVFormats[0]                   = DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.DSVFormat                       = DXGI_FORMAT_D32_FLOAT;
        psoDesc.SampleDesc.Count                = 1;

        ThrowIfFailed(m_studio->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState1)));

        psoDesc.PS = CD3DX12_SHADER_BYTECODE(pPixelShaderData2, pixelShaderDataLength2);

        ThrowIfFailed(m_studio->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState2)));

        delete pVertexShaderData;
        delete pPixelShaderData1;
        delete pPixelShaderData2;
    }

    ThrowIfFailed(m_studio->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&m_commandList)));

    CD3DX12_CPU_DESCRIPTOR_HANDLE               rtvHandle(m_studio->m_heap_manager.GetRtvHeap().GetCPUStart());
    for (UINT i = 0; i < m_studio->m_frameCount; i++)
    {
        ThrowIfFailed(m_studio->m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_studio->m_renderTargets[i])));
        m_studio->m_device->CreateRenderTargetView(m_studio->m_renderTargets[i].Get(), nullptr, rtvHandle);
        rtvHandle.Offset(1, m_studio->m_heap_manager.GetRtvHeap().m_heap.m_heapDescriptorSize);
    }

    UINT8*              pMeshData;
    UINT                meshDataLength;

    ThrowIfFailed(ReadDataFromFile(m_studio->m_scene_manager.GetScene()->GetAssetFullPath(m_entity->MeshDataFile.c_str()).c_str(), &pMeshData, &meshDataLength));

    CD3DX12_HEAP_PROPERTIES         vertex_heap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           vertex_desc         = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
    {
        ThrowIfFailed(m_studio->m_device->CreateCommittedResource(
            &vertex_heap,
            D3D12_HEAP_FLAG_NONE,
            &vertex_desc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&m_vertexBuffer)));
        CD3DX12_HEAP_PROPERTIES     upload_heap(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC       upload_desc             = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
        ThrowIfFailed(m_studio->m_device->CreateCommittedResource(
            &upload_heap,
            D3D12_HEAP_FLAG_NONE,
            &upload_desc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&vertexBufferUploadHeap)));

        D3D12_SUBRESOURCE_DATA      vertexData = {};
        vertexData.pData            = pMeshData + VertexDataOffset;
        vertexData.RowPitch         = VertexDataSize;
        vertexData.SlicePitch       = vertexData.RowPitch;

        UpdateSubresources<1>(m_commandList.Get(), m_vertexBuffer.Get(), vertexBufferUploadHeap.Get(), 0, 0, 1, &vertexData);
        CD3DX12_RESOURCE_BARRIER        barrier     = CD3DX12_RESOURCE_BARRIER::Transition(m_vertexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
        m_commandList->ResourceBarrier(1, &barrier);

        m_vertexBufferView.BufferLocation   = m_vertexBuffer->GetGPUVirtualAddress();
        m_vertexBufferView.StrideInBytes    = StandardVertexStride;
        m_vertexBufferView.SizeInBytes      = VertexDataSize;
    }

    {
        CD3DX12_HEAP_PROPERTIES         index_heap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC           index_desc              = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(m_studio->m_device->CreateCommittedResource(
            &index_heap,
            D3D12_HEAP_FLAG_NONE,
            &index_desc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&m_indexBuffer)));

        CD3DX12_HEAP_PROPERTIES         index_upload_heap(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC           index_upload_desc       = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(m_studio->m_device->CreateCommittedResource(
            &index_upload_heap,
            D3D12_HEAP_FLAG_NONE,
            &index_upload_desc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&indexBufferUploadHeap)));

        D3D12_SUBRESOURCE_DATA          indexData = {};
        indexData.pData         = pMeshData + IndexDataOffset;
        indexData.RowPitch      = IndexDataSize;
        indexData.SlicePitch    = indexData.RowPitch;

        UpdateSubresources<1>(m_commandList.Get(), m_indexBuffer.Get(), indexBufferUploadHeap.Get(), 0, 0, 1, &indexData);
        CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_indexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_INDEX_BUFFER);
        m_commandList->ResourceBarrier(1, &barrier);

        m_indexBufferView.BufferLocation    = m_indexBuffer->GetGPUVirtualAddress();
        m_indexBufferView.Format            = m_studio->GetModelManager().ConvertFormat(StandardIndexFormat);
        m_indexBufferView.SizeInBytes       = IndexDataSize;

        m_numIndices = IndexDataSize / 4;
    }

    {
        D3D12_RESOURCE_DESC             textureDesc = {};
        textureDesc.MipLevels           = Textures[0].MipLevels;
        textureDesc.Format              = ConvertFormat(Textures[0].Format);
        textureDesc.Width               = Textures[0].Width;
        textureDesc.Height              = Textures[0].Height;
        textureDesc.Flags               = D3D12_RESOURCE_FLAG_NONE;
        textureDesc.DepthOrArraySize    = 1;
        textureDesc.SampleDesc.Count    = 1;
        textureDesc.SampleDesc.Quality  = 0;
        textureDesc.Dimension           = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

        CD3DX12_HEAP_PROPERTIES         texture_heap(D3D12_HEAP_TYPE_DEFAULT);
        ThrowIfFailed(m_studio->m_device->CreateCommittedResource(
            &texture_heap,
            D3D12_HEAP_FLAG_NONE,
            &textureDesc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&m_texture)));

        const UINT subresourceCount     = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
        const UINT64 uploadBufferSize   = GetRequiredIntermediateSize(m_texture.Get(), 0, subresourceCount);

        CD3DX12_HEAP_PROPERTIES         sampler_heap(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC           sampler_desc        = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
        ThrowIfFailed(m_studio->m_device->CreateCommittedResource(
            &sampler_heap,
            D3D12_HEAP_FLAG_NONE,
            &sampler_desc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&textureUploadHeap)));

        D3D12_SUBRESOURCE_DATA          textureData = {};
        textureData.pData               = pMeshData + Textures[0].Data[0].Offset;
        textureData.RowPitch            = Textures[0].Data[0].Pitch;
        textureData.SlicePitch          = Textures[0].Data[0].Size;

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
        m_studio->m_device->CreateSampler(&samplerDesc, m_studio->m_heap_manager.GetSamplerHeap().GetCPUStart());

        D3D12_SHADER_RESOURCE_VIEW_DESC         srvDesc = {};
        srvDesc.Shader4ComponentMapping         = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        srvDesc.Format                          = ConvertFormat(Textures->Format);
        srvDesc.ViewDimension                   = D3D12_SRV_DIMENSION_TEXTURE2D;
        srvDesc.Texture2D.MipLevels             = 1;
        m_studio->m_device->CreateShaderResourceView(m_texture.Get(), &srvDesc, m_studio->m_heap_manager.GetCbvSrvHeap().GetCPUStart());
    }

    delete pMeshData;

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
        CD3DX12_RESOURCE_DESC               depth_desc          = CD3DX12_RESOURCE_DESC::Tex2D(DXGI_FORMAT_D32_FLOAT, m_studio->m_width, m_studio->m_height, 1, 0, 1, 0, D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL);
        ThrowIfFailed(m_studio->m_device->CreateCommittedResource(
            &depth_heap,
            D3D12_HEAP_FLAG_NONE,
            &depth_desc,
            D3D12_RESOURCE_STATE_DEPTH_WRITE,
            &depthOptimizedClearValue,
            IID_PPV_ARGS(&m_studio->m_depthStencil)
            ));

        m_studio->m_device->CreateDepthStencilView(m_studio->m_depthStencil.Get(), &depthStencilDesc, m_studio->m_heap_manager.GetDsvHeap().GetCPUStart());
    }

    ThrowIfFailed(m_commandList->Close());
    ID3D12CommandList*                  ppCommandLists[] = { m_commandList.Get() };
    m_studio->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    {
        ThrowIfFailed(m_studio->m_device->CreateFence(m_fenceValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)));
        m_fenceValue++;

        m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (m_fenceEvent == nullptr)
        {
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }

        const UINT64                fenceToWaitFor = m_fenceValue;
        ThrowIfFailed(m_studio->m_commandQueue->Signal(m_fence.Get(), fenceToWaitFor));
        m_fenceValue++;

        ThrowIfFailed(m_fence->SetEventOnCompletion(fenceToWaitFor, m_fenceEvent));
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }

    CreateFrameResources();
}

T100VOID T100DX12Bundle::CreateFrameResources()
{

    CD3DX12_CPU_DESCRIPTOR_HANDLE           cbvSrvHandle(m_studio->m_heap_manager.GetCbvSrvHeap().GetCPUStart(), 1,
                                                        m_studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);
    for (UINT i = 0; i < m_studio->m_frameCount; i++)
    {
        T100DX12FrameResource* pFrameResource = new T100DX12FrameResource(m_studio->m_device.Get(), m_entity->CityRowCount, m_entity->CityColumnCount);

        UINT64 cbOffset = 0;
        for (UINT j = 0; j < m_entity->CityRowCount; j++)
        {
            for (UINT k = 0; k < m_entity->CityColumnCount; k++)
            {
                D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
                cbvDesc.BufferLocation      = pFrameResource->m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
                cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
                cbOffset                    += cbvDesc.SizeInBytes;
                m_studio->m_device->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
                cbvSrvHandle.Offset(m_studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);
            }
        }

        pFrameResource->InitBundle(m_studio->m_device.Get(), m_pipelineState1.Get(), m_pipelineState2.Get(), i, m_numIndices, &m_indexBufferView,
            &m_vertexBufferView, m_studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heap.Get(), m_studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize,
            m_studio->m_heap_manager.GetSamplerHeap().m_heap.m_heap.Get(), m_rootSignature.Get());

        m_frameResources.push_back(pFrameResource);
    }
}

T100VOID T100DX12Bundle::PopulateCommandList(T100DX12FrameResource* frameResource)
{

    ThrowIfFailed(pCurrentFrameResource->m_commandAllocator->Reset());

    ThrowIfFailed(m_commandList->Reset(pCurrentFrameResource->m_commandAllocator.Get(), m_pipelineState1.Get()));

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = {
        m_studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heap.Get(),
        m_studio->m_heap_manager.GetSamplerHeap().m_heap.m_heap.Get() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_studio->m_viewport);
    m_commandList->RSSetScissorRects(1, &m_studio->m_scissorRect);

    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studio->m_renderTargets[m_studio->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_studio->m_heap_manager.GetRtvHeap().GetCPUStart(), m_studio->m_frameIndex, m_studio->m_heap_manager.GetRtvHeap().m_heap.m_heapDescriptorSize);
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_studio->m_heap_manager.GetDsvHeap().GetCPUStart());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    const float         clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->ClearDepthStencilView(m_studio->m_heap_manager.GetDsvHeap().GetCPUStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    if (m_entity->m_bundle.USED)
    {
        m_commandList->ExecuteBundle(frameResource->m_bundle.Get());
    }
    else
    {
        frameResource->PopulateCommandList(m_commandList.Get(), m_pipelineState1.Get(), m_pipelineState2.Get(), m_currentFrameResourceIndex, m_numIndices, &m_indexBufferView,
            &m_vertexBufferView, m_studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heap.Get(), m_studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize,
            m_studio->m_heap_manager.GetSamplerHeap().m_heap.m_heap.Get(), m_rootSignature.Get());
    }

    CD3DX12_RESOURCE_BARRIER        present_barrier         = CD3DX12_RESOURCE_BARRIER::Transition(m_studio->m_renderTargets[m_studio->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_commandList->ResourceBarrier(1, &present_barrier);

    ThrowIfFailed(m_commandList->Close());
}

T100VOID T100DX12Bundle::BundleUpdate()
{
    m_studio->m_timer.Tick(NULL);

    if (m_frameCounter == 500)
    {
        wchar_t         fps[64];
        swprintf_s(fps, L"%ufps", m_studio->m_timer.GetFramesPerSecond());
        SetCustomWindowText(fps);
        m_frameCounter = 0;
    }

    m_frameCounter++;

    const UINT64        lastCompletedFence  = m_fence->GetCompletedValue();

    m_currentFrameResourceIndex             = (m_currentFrameResourceIndex + 1) % m_studio->m_frameCount;
    pCurrentFrameResource                   = m_frameResources[m_currentFrameResourceIndex];

    if (pCurrentFrameResource->m_fenceValue != 0 && pCurrentFrameResource->m_fenceValue > lastCompletedFence)
    {
        ThrowIfFailed(m_fence->SetEventOnCompletion(pCurrentFrameResource->m_fenceValue, m_fenceEvent));
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }

    m_studio->m_camera.Update(static_cast<float>(m_studio->m_timer.GetElapsedSeconds()));
    pCurrentFrameResource->UpdateConstantBuffers(m_studio->m_camera.GetViewMatrix(), m_studio->m_camera.GetProjectionMatrix());

}

T100VOID T100DX12Bundle::BundleRender()
{
    PopulateCommandList(pCurrentFrameResource);

    ID3D12CommandList*          ppCommandLists[] = { m_commandList.Get() };
    m_studio->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    ThrowIfFailed(m_studio->m_swapChain->Present(1, 0));
    m_studio->m_frameIndex = m_studio->m_swapChain->GetCurrentBackBufferIndex();

    pCurrentFrameResource->m_fenceValue = m_fenceValue;
    ThrowIfFailed(m_studio->m_commandQueue->Signal(m_fence.Get(), m_fenceValue));
    m_fenceValue++;
}

void T100DX12Bundle::SetCustomWindowText(LPCWSTR text)
{
    std::wstring windowText = m_title + L": " + text;
    SetWindowTextW(m_studio->m_hwnd, windowText.c_str());
}

DXGI_FORMAT T100DX12Bundle::ConvertFormat(T100DXGI_FORMAT format)
{

}
