#include "T100DX12Dynamic2.h"

#include <d3dcompiler.h>
#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

const float T100DX12Dynamic2::CitySpacingInterval = 16.0f;


T100DX12Dynamic2::T100DX12Dynamic2(T100DX12Studio* studio) :
    m_studioPtr(studio)
{
    //ctor
}

T100DX12Dynamic2::~T100DX12Dynamic2()
{
    //dtor
}

void T100DX12Dynamic2::Create(HWND hwnd, UINT width, UINT height)
{
    /*
    m_hwnd          = hwnd;
    m_width         = width;
    m_height        = height;

    WCHAR assetsPath[512];
    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath = assetsPath;

    m_aspectRatio   = static_cast<float>(width) / static_cast<float>(height);
    m_viewport      = CD3DX12_VIEWPORT(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height)),
    m_scissorRect   = CD3DX12_RECT(0, 0, static_cast<LONG>(width), static_cast<LONG>(height)),
    */

    WCHAR assetsPath[512];
    GetAssetsPath(assetsPath, _countof(assetsPath));
    m_assetsPath = assetsPath;

    m_studioPtr->m_camera.Init({ (CityColumnCount / 2.0f) * CitySpacingInterval - (CitySpacingInterval / 2.0f), 15, 50 });
    m_studioPtr->m_camera.SetMoveSpeed(CitySpacingInterval * 2.0f);

    //loadPipeline();

}

void T100DX12Dynamic2::Start()
{
    loadAssets();
}

void T100DX12Dynamic2::Update()
{
    //    dx12Update();
    //
    m_studioPtr->m_frame_manager.Update();
}

void T100DX12Dynamic2::Render()
{
    //    dx12Render();
    //
    m_studioPtr->m_frame_manager.Render();
}

void T100DX12Dynamic2::loadAssets()
{
    m_modelPtr              = T100NEW T100DX12Model();
    m_modelPtr->Type        = T100DX12_MODEL_CITY;

    m_modelPtr->Bundle.USED         = T100TRUE;
    m_modelPtr->Bundle.AMOUNT.X     = CityColumnCount;
    m_modelPtr->Bundle.AMOUNT.Z     = CityRowCount;
    m_modelPtr->Bundle.SPACING.X    = 16;
    m_modelPtr->Bundle.SPACING.Y    = 16;
    m_modelPtr->Bundle.SPACING.Z    = 16;

    const UINT VertexDataOffset = 524288;
    const UINT VertexDataSize = 820248;
    const UINT IndexDataOffset = 1344536;
    const UINT IndexDataSize = 74568;

    const UINT StandardVertexStride = 44;

    const DXGI_FORMAT StandardIndexFormat = DXGI_FORMAT_R32_UINT;

    // Note: ComPtr's are CPU objects but these resources need to stay in scope until
    // the command list that references them has finished executing on the GPU.
    // We will flush the GPU at the end of this method to ensure the resources are not
    // prematurely destroyed.
    ComPtr<ID3D12Resource> vertexBufferUploadHeap;
    ComPtr<ID3D12Resource> indexBufferUploadHeap;
    ComPtr<ID3D12Resource> textureUploadHeap;
    ComPtr<ID3D12Resource> materialsUploadHeap;

    // Create the root signature.
    {
        D3D12_FEATURE_DATA_ROOT_SIGNATURE featureData = {};

        // This is the highest version the sample supports. If CheckFeatureSupport succeeds, the HighestVersion returned will not be greater than this.
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_1;

        if (FAILED(m_studioPtr->GetDevicePtr()->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
        {
            featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
        }

        CD3DX12_DESCRIPTOR_RANGE1 ranges[3];
        ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1 + CityMaterialCount, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);    // Diffuse texture + array of materials.
        ranges[1].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER, 1, 0);
        ranges[2].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

        CD3DX12_ROOT_PARAMETER1 rootParameters[4];
        rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_PIXEL);
        rootParameters[1].InitAsDescriptorTable(1, &ranges[1], D3D12_SHADER_VISIBILITY_PIXEL);
        rootParameters[2].InitAsDescriptorTable(1, &ranges[2], D3D12_SHADER_VISIBILITY_VERTEX);
        rootParameters[3].InitAsConstants(1, 0, 0, D3D12_SHADER_VISIBILITY_PIXEL);

        CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC rootSignatureDesc;
        rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

        ComPtr<ID3DBlob> signature;
        ComPtr<ID3DBlob> error;
        ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
        ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_modelPtr->m_rootSignature)));
    }

    // Create the pipeline state, which includes loading shaders.
    {
        const D3D12_INPUT_ELEMENT_DESC StandardVertexDescription[] =
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, 24, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "TANGENT",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 32, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        };
        UINT StandardVertexDescriptionNumElements = _countof(StandardVertexDescription);

        ComPtr<ID3DBlob>                        vertexShader;
        ComPtr<ID3DBlob>                        pixelShader;

        UINT        compileFlags        = D3DCOMPILE_ENABLE_UNBOUNDED_DESCRIPTOR_TABLES;

        ComPtr<ID3DBlob>        error;

        ThrowIfFailed(D3DCompileFromFile(m_studioPtr->GetScene()->GetAssetFullPath(L"shader_mesh_simple_vert.hlsl").c_str(), nullptr, nullptr, "VSMain", "vs_5_1", compileFlags, 0, &vertexShader, nullptr));
        ThrowIfFailed(D3DCompileFromFile(m_studioPtr->GetScene()->GetAssetFullPath(L"shader_mesh_dynamic_indexing_pixel.hlsl").c_str(), nullptr, nullptr, "PSMain", "ps_5_1", compileFlags, 0, &pixelShader, &error));

        CD3DX12_RASTERIZER_DESC rasterizerStateDesc(D3D12_DEFAULT);
        rasterizerStateDesc.CullMode = D3D12_CULL_MODE_NONE;

        // Describe and create the graphics pipeline state object (PSO).
        D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
        psoDesc.InputLayout = { StandardVertexDescription, StandardVertexDescriptionNumElements };
        psoDesc.pRootSignature = m_modelPtr->m_rootSignature.Get();
        psoDesc.VS = CD3DX12_SHADER_BYTECODE(vertexShader.Get());
        psoDesc.PS = CD3DX12_SHADER_BYTECODE(pixelShader.Get());
        psoDesc.RasterizerState = rasterizerStateDesc;
        psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
        psoDesc.SampleMask = UINT_MAX;
        psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets = 1;
        psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;
        psoDesc.SampleDesc.Count = 1;

        ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_modelPtr->m_pipelineState)));

        //delete pVertexShaderData;
        //delete pPixelShaderData;
    }

    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_studioPtr->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&m_modelPtr->m_commandList)));

    /*
    // Create render target views (RTVs).
    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart());
    for (UINT i = 0; i < m_studioPtr->m_frameCount; i++)
    {
        ThrowIfFailed(m_studioPtr->m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_studioPtr->m_renderTargets[i])));
        m_studioPtr->GetDevicePtr()->CreateRenderTargetView(m_studioPtr->m_renderTargets[i].Get(), nullptr, rtvHandle);
        rtvHandle.Offset(1, m_rtvDescriptorSize);
    }
    */

    // Read in mesh data for vertex/index buffers.
    UINT8* pMeshData;
    UINT meshDataLength;
    //ThrowIfFailed(ReadDataFromFile(GetAssetFullPath(SampleAssets::DataFileName).c_str(), &pMeshData, &meshDataLength));
    ThrowIfFailed(ReadDataFromFile(m_studioPtr->GetScene()->GetAssetFullPath(L"occcity.bin").c_str(), &pMeshData, &meshDataLength));

    // Create the vertex buffer.
    {
        CD3DX12_HEAP_PROPERTIES     vertexHeap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC       vertexHeapDesc      = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
        ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
            &vertexHeap,
            D3D12_HEAP_FLAG_NONE,
            &vertexHeapDesc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&m_modelPtr->m_vertexBuffer)));

        CD3DX12_HEAP_PROPERTIES     vertexUpload(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC       vertexUploadDesc        = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
        ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
            &vertexUpload,
            D3D12_HEAP_FLAG_NONE,
            &vertexUploadDesc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&vertexBufferUploadHeap)));

        // Copy data to the intermediate upload heap and then schedule a copy
        // from the upload heap to the vertex buffer.
        D3D12_SUBRESOURCE_DATA vertexData = {};
        vertexData.pData = pMeshData + VertexDataOffset;
        vertexData.RowPitch = VertexDataSize;
        vertexData.SlicePitch = vertexData.RowPitch;

        UpdateSubresources<1>(m_modelPtr->m_commandList.Get(), m_modelPtr->m_vertexBuffer.Get(), vertexBufferUploadHeap.Get(), 0, 0, 1, &vertexData);

        CD3DX12_RESOURCE_BARRIER    vertexBarrier       = CD3DX12_RESOURCE_BARRIER::Transition(m_modelPtr->m_vertexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
        m_modelPtr->m_commandList->ResourceBarrier(1, &vertexBarrier);

        // Initialize the vertex buffer view.
        m_modelPtr->m_vertexBufferView.BufferLocation = m_modelPtr->m_vertexBuffer->GetGPUVirtualAddress();
        m_modelPtr->m_vertexBufferView.StrideInBytes = StandardVertexStride;
        m_modelPtr->m_vertexBufferView.SizeInBytes = VertexDataSize;
    }

    // Create the index buffer.
    {
        CD3DX12_HEAP_PROPERTIES     indexHeap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC       indexHeapDesc       = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
            &indexHeap,
            D3D12_HEAP_FLAG_NONE,
            &indexHeapDesc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&m_modelPtr->m_indexBuffer)));

        CD3DX12_HEAP_PROPERTIES     indexUpload(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC       indexUploadDesc         = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
            &indexUpload,
            D3D12_HEAP_FLAG_NONE,
            &indexUploadDesc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&indexBufferUploadHeap)));

        // Copy data to the intermediate upload heap and then schedule a copy
        // from the upload heap to the index buffer.
        D3D12_SUBRESOURCE_DATA indexData = {};
        indexData.pData = pMeshData + IndexDataOffset;
        indexData.RowPitch = IndexDataSize;
        indexData.SlicePitch = indexData.RowPitch;

        UpdateSubresources<1>(m_modelPtr->m_commandList.Get(), m_modelPtr->m_indexBuffer.Get(), indexBufferUploadHeap.Get(), 0, 0, 1, &indexData);

        CD3DX12_RESOURCE_BARRIER    indexBarrier        = CD3DX12_RESOURCE_BARRIER::Transition(m_modelPtr->m_indexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_INDEX_BUFFER);
        m_modelPtr->m_commandList->ResourceBarrier(1, &indexBarrier);

        // Describe the index buffer view.
        m_modelPtr->m_indexBufferView.BufferLocation = m_modelPtr->m_indexBuffer->GetGPUVirtualAddress();
        m_modelPtr->m_indexBufferView.Format = StandardIndexFormat;
        m_modelPtr->m_indexBufferView.SizeInBytes = IndexDataSize;

        m_modelPtr->m_numIndices = IndexDataSize / 4;    // R32_UINT (SampleAssets::StandardIndexFormat) = 4 bytes each.
    }

    // Create the textures and sampler.
    {
        // Procedurally generate an array of textures to use as city materials.
        {
            // All of these materials use the same texture desc.
            D3D12_RESOURCE_DESC textureDesc = {};
            textureDesc.MipLevels = 1;
            textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            textureDesc.Width = CityMaterialTextureWidth;
            textureDesc.Height = CityMaterialTextureHeight;
            textureDesc.Flags = D3D12_RESOURCE_FLAG_NONE;
            textureDesc.DepthOrArraySize = 1;
            textureDesc.SampleDesc.Count = 1;
            textureDesc.SampleDesc.Quality = 0;
            textureDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

            // The textures evenly span the color rainbow so that each city gets
            // a different material.
            float materialGradStep = (1.0f / static_cast<float>(CityMaterialCount));

            // Generate texture data.
            std::vector<std::vector<unsigned char>> cityTextureData;
            cityTextureData.resize(CityMaterialCount);
            for (UINT i = 0; i < CityMaterialCount; ++i)
            {
                CD3DX12_HEAP_PROPERTIES materialHeap(D3D12_HEAP_TYPE_DEFAULT);
                ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
                    &materialHeap,
                    D3D12_HEAP_FLAG_NONE,
                    &textureDesc,
                    D3D12_RESOURCE_STATE_COPY_DEST,
                    nullptr,
                    IID_PPV_ARGS(&m_modelPtr->m_cityMaterialTextures[i])));

                // Fill the texture.
                float t = i * materialGradStep;
                cityTextureData[i].resize(CityMaterialTextureWidth * CityMaterialTextureHeight * CityMaterialTextureChannelCount);
                for (int x = 0; x < CityMaterialTextureWidth; ++x)
                {
                    for (int y = 0; y < CityMaterialTextureHeight; ++y)
                    {
                        // Compute the appropriate index into the buffer based on the x/y coordinates.
                        int pixelIndex = (y * CityMaterialTextureChannelCount * CityMaterialTextureWidth) + (x * CityMaterialTextureChannelCount);

                        // Determine this row's position along the rainbow gradient.
                        float tPrime = t + ((static_cast<float>(y) / static_cast<float>(CityMaterialTextureHeight)) * materialGradStep);

                        // Compute the RGB value for this position along the rainbow
                        // and pack the pixel value.
                        XMVECTOR hsl = XMVectorSet(tPrime, 0.5f, 0.5f, 1.0f);
                        XMVECTOR rgb = XMColorHSLToRGB(hsl);
                        cityTextureData[i][pixelIndex + 0] = static_cast<unsigned char>((255 * XMVectorGetX(rgb)));
                        cityTextureData[i][pixelIndex + 1] = static_cast<unsigned char>((255 * XMVectorGetY(rgb)));
                        cityTextureData[i][pixelIndex + 2] = static_cast<unsigned char>((255 * XMVectorGetZ(rgb)));
                        cityTextureData[i][pixelIndex + 3] = 255;
                    }
                }
            }

            // Upload texture data to the default heap resources.
            {
                const UINT subresourceCount = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
                const UINT64 uploadBufferStep = GetRequiredIntermediateSize(m_modelPtr->m_cityMaterialTextures[0].Get(), 0, subresourceCount); // All of our textures are the same size in this case.
                const UINT64 uploadBufferSize = uploadBufferStep * CityMaterialCount;

                CD3DX12_HEAP_PROPERTIES     textureHeap(D3D12_HEAP_TYPE_UPLOAD);
                CD3DX12_RESOURCE_DESC       textureHeapDesc         = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
                ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
                    &textureHeap,
                    D3D12_HEAP_FLAG_NONE,
                    &textureHeapDesc,
                    D3D12_RESOURCE_STATE_GENERIC_READ,
                    nullptr,
                    IID_PPV_ARGS(&materialsUploadHeap)));

                for (int i = 0; i < CityMaterialCount; ++i)
                {
                    // Copy data to the intermediate upload heap and then schedule
                    // a copy from the upload heap to the appropriate texture.
                    D3D12_SUBRESOURCE_DATA textureData = {};
                    textureData.pData = &cityTextureData[i][0];
                    textureData.RowPitch = static_cast<LONG_PTR>((CityMaterialTextureChannelCount * textureDesc.Width));
                    textureData.SlicePitch = textureData.RowPitch * textureDesc.Height;

                    UpdateSubresources(m_modelPtr->m_commandList.Get(), m_modelPtr->m_cityMaterialTextures[i].Get(), materialsUploadHeap.Get(), i * uploadBufferStep, 0, subresourceCount, &textureData);
                    CD3DX12_RESOURCE_BARRIER        textureBarrier      = CD3DX12_RESOURCE_BARRIER::Transition(m_modelPtr->m_cityMaterialTextures[i].Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
                    m_modelPtr->m_commandList->ResourceBarrier(1, &textureBarrier);
                }
            }
        }

        // Load the occcity diffuse texture with baked-in ambient lighting.
        // This texture will be blended with a texture from the materials
        // array in the pixel shader.
        {
            D3D12_RESOURCE_DESC textureDesc = {};
            textureDesc.MipLevels = Textures[0].MipLevels;
            textureDesc.Format = Textures[0].Format;
            textureDesc.Width = Textures[0].Width;
            textureDesc.Height = Textures[0].Height;
            textureDesc.Flags = D3D12_RESOURCE_FLAG_NONE;
            textureDesc.DepthOrArraySize = 1;
            textureDesc.SampleDesc.Count = 1;
            textureDesc.SampleDesc.Quality = 0;
            textureDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

            CD3DX12_HEAP_PROPERTIES textureHeap(D3D12_HEAP_TYPE_DEFAULT);
            ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
                &textureHeap,
                D3D12_HEAP_FLAG_NONE,
                &textureDesc,
                D3D12_RESOURCE_STATE_COPY_DEST,
                nullptr,
                IID_PPV_ARGS(&m_modelPtr->m_cityDiffuseTexture)));

            const UINT subresourceCount = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
            const UINT64 uploadBufferSize = GetRequiredIntermediateSize(m_modelPtr->m_cityDiffuseTexture.Get(), 0, subresourceCount);

            CD3DX12_HEAP_PROPERTIES     textureUpload(D3D12_HEAP_TYPE_UPLOAD);
            CD3DX12_RESOURCE_DESC       textureUploadDesc       = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
            ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
                &textureUpload,
                D3D12_HEAP_FLAG_NONE,
                &textureUploadDesc,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&textureUploadHeap)));

            // Copy data to the intermediate upload heap and then schedule
            // a copy from the upload heap to the diffuse texture.
            D3D12_SUBRESOURCE_DATA textureData = {};
            textureData.pData = pMeshData + Textures[0].Data[0].Offset;
            textureData.RowPitch = Textures[0].Data[0].Pitch;
            textureData.SlicePitch = Textures[0].Data[0].Size;

            UpdateSubresources(m_modelPtr->m_commandList.Get(), m_modelPtr->m_cityDiffuseTexture.Get(), textureUploadHeap.Get(), 0, 0, subresourceCount, &textureData);
            CD3DX12_RESOURCE_BARRIER        textureBarrier      = CD3DX12_RESOURCE_BARRIER::Transition(m_modelPtr->m_cityDiffuseTexture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
            m_modelPtr->m_commandList->ResourceBarrier(1, &textureBarrier);
        }

        // Describe and create a sampler.
        D3D12_SAMPLER_DESC samplerDesc = {};
        samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
        samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        samplerDesc.MinLOD = 0;
        samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;
        samplerDesc.MipLODBias = 0.0f;
        samplerDesc.MaxAnisotropy = 1;
        samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS;
        m_modelPtr->m_samplerHeapIndex  = m_studioPtr->GetHeapManager().GetSamplerHeap().GetTop();
        m_studioPtr->GetDevicePtr()->CreateSampler(&samplerDesc, m_studioPtr->GetHeapManager().GetSamplerHeap().GetCPUStart());

        // Create SRV for the city's diffuse texture.
        m_modelPtr->m_textureHeapIndex  = m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();
        CD3DX12_CPU_DESCRIPTOR_HANDLE srvHandle(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetCPUStart(), m_modelPtr->m_textureHeapIndex, m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
        D3D12_SHADER_RESOURCE_VIEW_DESC diffuseSrvDesc = {};
        diffuseSrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        diffuseSrvDesc.Format = Textures->Format;
        diffuseSrvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
        diffuseSrvDesc.Texture2D.MipLevels = 1;
        m_studioPtr->GetDevicePtr()->CreateShaderResourceView(m_modelPtr->m_cityDiffuseTexture.Get(), &diffuseSrvDesc, srvHandle);
        srvHandle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

        // Create SRVs for each city material.
        for (int i = 0; i < CityMaterialCount; ++i)
        {
            D3D12_SHADER_RESOURCE_VIEW_DESC materialSrvDesc = {};
            materialSrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            materialSrvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            materialSrvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            materialSrvDesc.Texture2D.MipLevels = 1;
            m_studioPtr->GetDevicePtr()->CreateShaderResourceView(m_modelPtr->m_cityMaterialTextures[i].Get(), &materialSrvDesc, srvHandle);

            srvHandle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
        }
    }

    delete pMeshData;

    /*
    // Create the depth stencil view.
    {
        D3D12_DEPTH_STENCIL_VIEW_DESC depthStencilDesc = {};
        depthStencilDesc.Format = DXGI_FORMAT_D32_FLOAT;
        depthStencilDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
        depthStencilDesc.Flags = D3D12_DSV_FLAG_NONE;

        CD3DX12_HEAP_PROPERTIES     depthHeap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC       depthHeapDesc       = CD3DX12_RESOURCE_DESC::Tex2D(DXGI_FORMAT_D32_FLOAT, m_width, m_height, 1, 0, 1, 0, D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL | D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE);
        CD3DX12_CLEAR_VALUE         depthValue(DXGI_FORMAT_D32_FLOAT, 1.0f, 0);
        ThrowIfFailed(m_device->CreateCommittedResource(
            &depthHeap,
            D3D12_HEAP_FLAG_NONE,
            &depthHeapDesc, // Performance tip: Deny shader resource access to resources that don't need shader resource views.
            D3D12_RESOURCE_STATE_DEPTH_WRITE,
            &depthValue, // Performance tip: Tell the runtime at resource creation the desired clear value.
            IID_PPV_ARGS(&m_depthStencil)
            ));

        m_device->CreateDepthStencilView(m_depthStencil.Get(), &depthStencilDesc, m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
    }
    */
    // Close the command list and execute it to begin the initial GPU setup.
    ThrowIfFailed(m_modelPtr->m_commandList->Close());
    ID3D12CommandList* ppCommandLists[] = { m_modelPtr->m_commandList.Get() };
    m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    /*
    // Create synchronization objects and wait until assets have been uploaded to the GPU.
    {
        ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateFence(m_studioPtr->m_fenceValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_studioPtr->m_fence)));
        m_studioPtr->m_fenceValue++;

        // Create an event handle to use for frame synchronization.
        m_studioPtr->m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (m_studioPtr->m_fenceEvent == nullptr)
        {
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }

        // Wait for the command list to execute; we are reusing the same command
        // list in our main loop but for now, we just want to wait for setup to
        // complete before continuing.

        // Signal and increment the fence value.
        const UINT64 fenceToWaitFor = m_studioPtr->m_fenceValue;
        ThrowIfFailed(m_studioPtr->m_commandQueue->Signal(m_studioPtr->m_fence.Get(), fenceToWaitFor));
        m_studioPtr->m_fenceValue++;

        // Wait until the fence is completed.
        ThrowIfFailed(m_studioPtr->m_fence->SetEventOnCompletion(fenceToWaitFor, m_studioPtr->m_fenceEvent));
        WaitForSingleObject(m_studioPtr->m_fenceEvent, INFINITE);
    }
    */
    m_studioPtr->Waiting();

    //CreateFrameResources();

    m_studioPtr->m_frame_manager.Append(m_modelPtr);
}

void T100DX12Dynamic2::dx12Update()
{

    m_studioPtr->m_timer.Tick(NULL);

    m_studioPtr->m_frameCounter++;

    // Get current GPU progress against submitted workload. Resources still scheduled
    // for GPU execution cannot be modified or else undefined behavior will result.
    const UINT64 lastCompletedFence = m_studioPtr->m_fence->GetCompletedValue();

    // Move to the next frame resource.
    m_currentFrameResourceIndex = (m_currentFrameResourceIndex + 1) % m_studioPtr->m_frameCount;
    m_pCurrentFrameResource = m_frameResources[m_currentFrameResourceIndex];

    // Make sure that this frame resource isn't still in use by the GPU.
    // If it is, wait for it to complete.
    if (m_pCurrentFrameResource->m_fenceValue != 0 && m_pCurrentFrameResource->m_fenceValue > lastCompletedFence)
    {
        ThrowIfFailed(m_studioPtr->m_fence->SetEventOnCompletion(m_pCurrentFrameResource->m_fenceValue, m_studioPtr->m_fenceEvent));
        WaitForSingleObject(m_studioPtr->m_fenceEvent, INFINITE);
    }

    m_studioPtr->m_camera.Update(static_cast<float>(m_studioPtr->m_timer.GetElapsedSeconds()));
    m_pCurrentFrameResource->UpdateConstantBuffers(m_studioPtr->m_camera.GetViewMatrix(), m_studioPtr->m_camera.GetProjectionMatrix());

}

void T100DX12Dynamic2::dx12Render()
{

    //PIXBeginEvent(m_commandQueue.Get(), 0, L"Render");

    // Record all the commands we need to render the scene into the command list.
    PopulateCommandList(m_pCurrentFrameResource);

    // Execute the command list.
    ID3D12CommandList* ppCommandLists[] = { m_modelPtr->m_commandList.Get() };
    m_studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    //PIXEndEvent(m_commandQueue.Get());

    // Present and update the frame index for the next frame.
    ThrowIfFailed(m_studioPtr->m_swapChain->Present(1, 0));
    m_studioPtr->m_frameIndex = m_studioPtr->m_swapChain->GetCurrentBackBufferIndex();

    // Signal and increment the fence value.
    m_pCurrentFrameResource->m_fenceValue = m_studioPtr->m_fenceValue;
    ThrowIfFailed(m_studioPtr->m_commandQueue->Signal(m_studioPtr->m_fence.Get(), m_studioPtr->m_fenceValue));
    m_studioPtr->m_fenceValue++;
}

void T100DX12Dynamic2::Destroy()
{
    // Ensure that the GPU is no longer referencing resources that are about to be
    // cleaned up by the destructor.
    {
        const UINT64 fence = m_studioPtr->m_fenceValue;
        const UINT64 lastCompletedFence = m_studioPtr->m_fence->GetCompletedValue();

        // Signal and increment the fence value.
        ThrowIfFailed(m_studioPtr->m_commandQueue->Signal(m_studioPtr->m_fence.Get(), m_studioPtr->m_fenceValue));
        m_studioPtr->m_fenceValue++;

        // Wait until the previous frame is finished.
        if (lastCompletedFence < fence)
        {
            ThrowIfFailed(m_studioPtr->m_fence->SetEventOnCompletion(fence, m_studioPtr->m_fenceEvent));
            WaitForSingleObject(m_studioPtr->m_fenceEvent, INFINITE);
        }
    }

    for (UINT i = 0; i < m_frameResources.size(); i++)
    {
        delete m_frameResources.at(i);
    }
}

// Create the resources that will be used every frame.
void T100DX12Dynamic2::CreateFrameResources()
{
    // Initialize each frame resource.
    CD3DX12_CPU_DESCRIPTOR_HANDLE cbvSrvHandle(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetCPUStart(), CityMaterialCount + 1, m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());    // Move past the SRVs.
    for (UINT i = 0; i < m_studioPtr->m_frameCount; i++)
    {
        T100DX12FrameResource* pFrameResource = new T100DX12FrameResource();
        pFrameResource->Create(m_studioPtr->GetDevicePtr(), CityRowCount, CityColumnCount, CityMaterialCount, CitySpacingInterval);

        UINT64 cbOffset = 0;
        for (UINT j = 0; j < CityRowCount; j++)
        {
            for (UINT k = 0; k < CityColumnCount; k++)
            {
                // Describe and create a constant buffer view (CBV).
                D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc = {};
                cbvDesc.BufferLocation = pFrameResource->m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
                cbvDesc.SizeInBytes = sizeof(T100DX12FrameResource::SceneConstantBuffer);
                cbOffset += cbvDesc.SizeInBytes;
                m_studioPtr->GetDevicePtr()->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
                cbvSrvHandle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
            }
        }

        pFrameResource->InitBundle(m_studioPtr->GetDevicePtr(), m_modelPtr->m_pipelineState.Get(), i, m_modelPtr->m_numIndices, &m_modelPtr->m_indexBufferView,
            &m_modelPtr->m_vertexBufferView, m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap(),
            m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize(),
            m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap(), m_modelPtr->m_rootSignature.Get());

        m_frameResources.push_back(pFrameResource);
    }
}

void T100DX12Dynamic2::PopulateCommandList(T100DX12FrameResource* pFrameResource)
{
    // Command list allocators can only be reset when the associated
    // command lists have finished execution on the GPU; apps should use
    // fences to determine GPU execution progress.
    ThrowIfFailed(m_pCurrentFrameResource->m_commandAllocator->Reset());

    // However, when ExecuteCommandList() is called on a particular command
    // list, that command list can then be reset at any time and must be before
    // re-recording.
    ThrowIfFailed(m_modelPtr->m_commandList->Reset(m_pCurrentFrameResource->m_commandAllocator.Get(), m_modelPtr->m_pipelineState.Get()));

    // Set necessary state.
    m_modelPtr->m_commandList->SetGraphicsRootSignature(m_modelPtr->m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap(),
        m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap()
    };
    m_modelPtr->m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_modelPtr->m_commandList->RSSetViewports(1, &m_studioPtr->m_viewport);
    m_modelPtr->m_commandList->RSSetScissorRects(1, &m_studioPtr->m_scissorRect);

    // Indicate that the back buffer will be used as a render target.
    CD3DX12_RESOURCE_BARRIER    barrier  = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
    m_modelPtr->m_commandList->ResourceBarrier(1, &barrier);

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_studioPtr->GetHeapManager().GetRtvHeap().GetCPUStart(), m_studioPtr->m_frameIndex, m_studioPtr->GetHeapManager().GetRtvHeap().GetSize());
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_studioPtr->GetHeapManager().GetDsvHeap().GetCPUStart());
    m_modelPtr->m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    // Record commands.
    const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_modelPtr->m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_modelPtr->m_commandList->ClearDepthStencilView(m_studioPtr->GetHeapManager().GetDsvHeap().GetCPUStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    //PIXBeginEvent(m_commandList.Get(), 0, L"Draw cities");
    if (UseBundles)
    {
        // Execute the prebuilt bundle.
        m_modelPtr->m_commandList->ExecuteBundle(pFrameResource->m_bundle.Get());
    }
    else
    {
        // Populate a new command list.
        pFrameResource->PopulateCommandList(m_modelPtr->m_commandList.Get(), m_currentFrameResourceIndex, m_modelPtr->m_numIndices, &m_modelPtr->m_indexBufferView,
            &m_modelPtr->m_vertexBufferView, m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap(),
            m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize(),
            m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap(), m_modelPtr->m_rootSignature.Get());
    }
    //PIXEndEvent(m_commandList.Get());

    // Indicate that the back buffer will now be used to present.
    CD3DX12_RESOURCE_BARRIER    barrier2        = CD3DX12_RESOURCE_BARRIER::Transition(m_studioPtr->m_renderTargets[m_studioPtr->m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
    m_modelPtr->m_commandList->ResourceBarrier(1, &barrier2);

    ThrowIfFailed(m_modelPtr->m_commandList->Close());
}

std::wstring T100DX12Dynamic2::GetAssetFullPath(LPCWSTR assetName)
{
    return m_assetsPath + L"..\\..\\resources\\" + assetName;
}
