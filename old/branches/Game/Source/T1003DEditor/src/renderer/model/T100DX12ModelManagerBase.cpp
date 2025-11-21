#include "T100DX12ModelManagerBase.h"

#include "T100Debug.h"
#include "T100DX12Tools.h"
#include "T100DX12Studio.h"
#include "T100DX12RootSignatureFactory.h"
#include "T100DX12PipelineStateFactory.h"

T100DX12ModelManagerBase::T100DX12ModelManagerBase()
{
    //ctor
}

T100DX12ModelManagerBase::~T100DX12ModelManagerBase()
{
    //dtor
}

T100VOID T100DX12ModelManagerBase::Upload(T100DX12Studio* studio, T100DX12Model* model)
{
    //DEBUGPRINT("Upload %d...", model->Type);
    switch(model->Type){
    case T100DX12_MODEL_DOT:
        {
            UploadDot(studio, model);
        }
        break;
    case T100DX12_MODEL_LINE:
        {
            UploadLine(studio, model);
        }
        break;
    case T100DX12_MODEL_TRIANGLE:
        {
            UploadTriangle(studio, model);
        }
        break;
    case T100DX12_MODEL_PLANE:
        {
            UploadPlane(studio, model);
        }
        break;
    case T100DX12_MODEL_CITY:
        {
            UploadCity(studio, model);
        }
        break;
    case T100DX12_MODEL_MESH:
        {
            UploadMesh(studio, model);
        }
        break;
    case T100DX12_MODEL_SPHERE:
        {
            UploadSphere(studio, model);
        }
        break;
    case T100DX12_MODEL_RECTANGLE:
        {
            UploadRectangle(studio, model);
        }
        break;
    }
}

T100VOID T100DX12ModelManagerBase::UploadDot(T100DX12Studio* studio, T100DX12Model* model)
{

    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
    {
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
    }

    CD3DX12_DESCRIPTOR_RANGE1               ranges[1];
    ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

    CD3DX12_ROOT_PARAMETER1                 rootParameters[1];
    rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_ALL);

    CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC   rootSignatureDesc;
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));

    CreatePipelineState(studio, model);

    CreateCommandList(studio, model);

    CreateVertexBuffer(studio, model);

    CloseCommandList(model);

    ExecuteCommandList(studio, model);

    studio->Waiting();
}

T100VOID T100DX12ModelManagerBase::UploadLine(T100DX12Studio* studio, T100DX12Model* model)
{
    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
    {
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
    }

    CD3DX12_DESCRIPTOR_RANGE1               ranges[1];
    ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

    CD3DX12_ROOT_PARAMETER1                 rootParameters[1];
    rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_ALL);

    CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC   rootSignatureDesc;
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));

    CreatePipelineState(studio, model);

    CreateCommandList(studio, model);

    CreateVertexBuffer(studio, model);

    CloseCommandList(model);

    ExecuteCommandList(studio, model);

    studio->Waiting();
}

T100VOID T100DX12ModelManagerBase::UploadTriangle(T100DX12Studio* studio, T100DX12Model* model)
{

    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
    {
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
    }

    CD3DX12_DESCRIPTOR_RANGE1               ranges[1];
    ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

    CD3DX12_ROOT_PARAMETER1                 rootParameters[1];
    rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_ALL);

    CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC   rootSignatureDesc;
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));

    CreatePipelineState(studio, model);

    CreateCommandList(studio, model);

    CreateVertexBuffer(studio, model);

    CloseCommandList(model);

    ExecuteCommandList(studio, model);

    studio->Waiting();
}

T100VOID T100DX12ModelManagerBase::UploadPlane(T100DX12Studio* studio, T100DX12Model* model)
{

    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
    {
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
    }

    CD3DX12_DESCRIPTOR_RANGE1               ranges[1];
    ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

    CD3DX12_ROOT_PARAMETER1                 rootParameters[1];
    rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_ALL);

    CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC   rootSignatureDesc;
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));

    CreatePipelineState(studio, model);

    CreateCommandList(studio, model);

    CreateVertexBuffer(studio, model);

    CloseCommandList(model);

    ExecuteCommandList(studio, model);

    studio->Waiting();
}


T100VOID T100DX12ModelManagerBase::UploadCity(T100DX12Studio* studio, T100DX12Model* model)
{
    ComPtr<ID3D12Resource> vertexBufferUploadHeap;
    ComPtr<ID3D12Resource> indexBufferUploadHeap;
    ComPtr<ID3D12Resource> textureUploadHeap;
    ComPtr<ID3D12Resource> materialsUploadHeap;

    {
        D3D12_FEATURE_DATA_ROOT_SIGNATURE featureData = {};

        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_1;

        if (FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
        {
            featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
        }

        CD3DX12_DESCRIPTOR_RANGE1 ranges[3];
        ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1 + model->CityMaterialCount, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);    // Diffuse texture + array of materials.
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
        ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));
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

        CD3DX12_RASTERIZER_DESC rasterizerStateDesc(D3D12_DEFAULT);
        rasterizerStateDesc.CullMode = D3D12_CULL_MODE_NONE;

        // Describe and create the graphics pipeline state object (PSO).
        D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
        psoDesc.InputLayout = { StandardVertexDescription, StandardVertexDescriptionNumElements };
        psoDesc.pRootSignature = model->m_rootSignature.Get();
        psoDesc.VS = CD3DX12_SHADER_BYTECODE(model->vertexShader.Get());
        psoDesc.PS = CD3DX12_SHADER_BYTECODE(model->pixelShader.Get());
        psoDesc.RasterizerState = rasterizerStateDesc;
        psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
        psoDesc.SampleMask = UINT_MAX;
        psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets = 1;
        psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;
        psoDesc.SampleDesc.Count = 1;

        ThrowIfFailed(studio->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&model->m_pipelineState)));

        //delete pVertexShaderData;
        //delete pPixelShaderData;
    }

    ThrowIfFailed(studio->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, studio->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&model->m_commandList)));

    /*
    // Create render target views (RTVs).
    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());
    for (UINT i = 0; i < FrameCount; i++)
    {
        ThrowIfFailed(m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i])));
        m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, rtvHandle);
        rtvHandle.Offset(1, m_rtvDescriptorSize);
    }
    */

    const UINT StandardVertexStride = 44;
    const DXGI_FORMAT StandardIndexFormat = DXGI_FORMAT_R32_UINT;
    const UINT VertexDataOffset = 524288;
    const UINT VertexDataSize = 820248;
    const UINT IndexDataOffset = 1344536;
    const UINT IndexDataSize = 74568;
    // Create the vertex buffer.
    {
        CD3DX12_HEAP_PROPERTIES     vertexHeap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC       vertexHeapDesc      = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
        ThrowIfFailed(studio->m_device->CreateCommittedResource(
            &vertexHeap,
            D3D12_HEAP_FLAG_NONE,
            &vertexHeapDesc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&model->m_vertexBuffer)));

        CD3DX12_HEAP_PROPERTIES     vertexUpload(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC       vertexUploadDesc        = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
        ThrowIfFailed(studio->m_device->CreateCommittedResource(
            &vertexUpload,
            D3D12_HEAP_FLAG_NONE,
            &vertexUploadDesc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&vertexBufferUploadHeap)));

        // Copy data to the intermediate upload heap and then schedule a copy
        // from the upload heap to the vertex buffer.
        D3D12_SUBRESOURCE_DATA vertexData = {};
        vertexData.pData = model->pMeshData + VertexDataOffset;
        vertexData.RowPitch = VertexDataSize;
        vertexData.SlicePitch = vertexData.RowPitch;

        UpdateSubresources<1>(model->m_commandList.Get(), model->m_vertexBuffer.Get(), vertexBufferUploadHeap.Get(), 0, 0, 1, &vertexData);

        CD3DX12_RESOURCE_BARRIER    vertexBarrier       = CD3DX12_RESOURCE_BARRIER::Transition(model->m_vertexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
        model->m_commandList->ResourceBarrier(1, &vertexBarrier);

        // Initialize the vertex buffer view.
        model->m_vertexBufferView.BufferLocation = model->m_vertexBuffer->GetGPUVirtualAddress();
        model->m_vertexBufferView.StrideInBytes = StandardVertexStride;
        model->m_vertexBufferView.SizeInBytes = VertexDataSize;
    }

    // Create the index buffer.
    {
        CD3DX12_HEAP_PROPERTIES     indexHeap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC       indexHeapDesc       = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(studio->m_device->CreateCommittedResource(
            &indexHeap,
            D3D12_HEAP_FLAG_NONE,
            &indexHeapDesc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&model->m_indexBuffer)));

        CD3DX12_HEAP_PROPERTIES     indexUpload(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC       indexUploadDesc         = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(studio->m_device->CreateCommittedResource(
            &indexUpload,
            D3D12_HEAP_FLAG_NONE,
            &indexUploadDesc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&indexBufferUploadHeap)));

        // Copy data to the intermediate upload heap and then schedule a copy
        // from the upload heap to the index buffer.
        D3D12_SUBRESOURCE_DATA indexData = {};
        indexData.pData = model->pMeshData + IndexDataOffset;
        indexData.RowPitch = IndexDataSize;
        indexData.SlicePitch = indexData.RowPitch;

        UpdateSubresources<1>(model->m_commandList.Get(), model->m_indexBuffer.Get(), indexBufferUploadHeap.Get(), 0, 0, 1, &indexData);

        CD3DX12_RESOURCE_BARRIER    indexBarrier        = CD3DX12_RESOURCE_BARRIER::Transition(model->m_indexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_INDEX_BUFFER);
        model->m_commandList->ResourceBarrier(1, &indexBarrier);

        // Describe the index buffer view.
        model->m_indexBufferView.BufferLocation = model->m_indexBuffer->GetGPUVirtualAddress();
        model->m_indexBufferView.Format = StandardIndexFormat;
        model->m_indexBufferView.SizeInBytes = IndexDataSize;

        model->m_numIndices = IndexDataSize / 4;    // R32_UINT (SampleAssets::StandardIndexFormat) = 4 bytes each.
    }

    // Create the textures and sampler.
    {
        // Procedurally generate an array of textures to use as city materials.
        {
            // All of these materials use the same texture desc.
            D3D12_RESOURCE_DESC textureDesc = {};
            textureDesc.MipLevels = 1;
            textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            textureDesc.Width = model->CityMaterialTextureWidth;
            textureDesc.Height = model->CityMaterialTextureHeight;
            textureDesc.Flags = D3D12_RESOURCE_FLAG_NONE;
            textureDesc.DepthOrArraySize = 1;
            textureDesc.SampleDesc.Count = 1;
            textureDesc.SampleDesc.Quality = 0;
            textureDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

            // The textures evenly span the color rainbow so that each city gets
            // a different material.
            float materialGradStep = (1.0f / static_cast<float>(model->CityMaterialCount));

            // Generate texture data.
            std::vector<std::vector<unsigned char>> cityTextureData;
            cityTextureData.resize(model->CityMaterialCount);
            for (UINT i = 0; i < model->CityMaterialCount; ++i)
            {
                CD3DX12_HEAP_PROPERTIES materialHeap(D3D12_HEAP_TYPE_DEFAULT);
                ThrowIfFailed(studio->m_device->CreateCommittedResource(
                    &materialHeap,
                    D3D12_HEAP_FLAG_NONE,
                    &textureDesc,
                    D3D12_RESOURCE_STATE_COPY_DEST,
                    nullptr,
                    IID_PPV_ARGS(&model->m_cityMaterialTextures[i])));

                // Fill the texture.
                float t = i * materialGradStep;
                cityTextureData[i].resize(model->CityMaterialTextureWidth * model->CityMaterialTextureHeight * model->CityMaterialTextureChannelCount);
                for (int x = 0; x < model->CityMaterialTextureWidth; ++x)
                {
                    for (int y = 0; y < model->CityMaterialTextureHeight; ++y)
                    {
                        // Compute the appropriate index into the buffer based on the x/y coordinates.
                        int pixelIndex = (y * model->CityMaterialTextureChannelCount * model->CityMaterialTextureWidth) + (x * model->CityMaterialTextureChannelCount);

                        // Determine this row's position along the rainbow gradient.
                        float tPrime = t + ((static_cast<float>(y) / static_cast<float>(model->CityMaterialTextureHeight)) * materialGradStep);

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
                const UINT64 uploadBufferStep = GetRequiredIntermediateSize(model->m_cityMaterialTextures[0].Get(), 0, subresourceCount); // All of our textures are the same size in this case.
                const UINT64 uploadBufferSize = uploadBufferStep * model->CityMaterialCount;

                CD3DX12_HEAP_PROPERTIES     textureHeap(D3D12_HEAP_TYPE_UPLOAD);
                CD3DX12_RESOURCE_DESC       textureHeapDesc         = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
                ThrowIfFailed(studio->m_device->CreateCommittedResource(
                    &textureHeap,
                    D3D12_HEAP_FLAG_NONE,
                    &textureHeapDesc,
                    D3D12_RESOURCE_STATE_GENERIC_READ,
                    nullptr,
                    IID_PPV_ARGS(&materialsUploadHeap)));

                for (int i = 0; i < model->CityMaterialCount; ++i)
                {
                    // Copy data to the intermediate upload heap and then schedule
                    // a copy from the upload heap to the appropriate texture.
                    D3D12_SUBRESOURCE_DATA textureData = {};
                    textureData.pData = &cityTextureData[i][0];
                    textureData.RowPitch = static_cast<LONG_PTR>((model->CityMaterialTextureChannelCount * textureDesc.Width));
                    textureData.SlicePitch = textureData.RowPitch * textureDesc.Height;

                    UpdateSubresources(model->m_commandList.Get(), model->m_cityMaterialTextures[i].Get(), materialsUploadHeap.Get(), i * uploadBufferStep, 0, subresourceCount, &textureData);
                    CD3DX12_RESOURCE_BARRIER        textureBarrier      = CD3DX12_RESOURCE_BARRIER::Transition(model->m_cityMaterialTextures[i].Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
                    model->m_commandList->ResourceBarrier(1, &textureBarrier);
                }
            }
        }

        DX12TextureResource Textures[] =
        {
            { 1024, 1024, 1, DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } }, // city.dds
        };

        DX12DrawParameters Draws[] =
        {
            { 0, -1, -1, 0, 18642, 0 },
        };

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
            ThrowIfFailed(studio->m_device->CreateCommittedResource(
                &textureHeap,
                D3D12_HEAP_FLAG_NONE,
                &textureDesc,
                D3D12_RESOURCE_STATE_COPY_DEST,
                nullptr,
                IID_PPV_ARGS(&model->m_cityDiffuseTexture)));

            const UINT subresourceCount = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
            const UINT64 uploadBufferSize = GetRequiredIntermediateSize(model->m_cityDiffuseTexture.Get(), 0, subresourceCount);

            CD3DX12_HEAP_PROPERTIES     textureUpload(D3D12_HEAP_TYPE_UPLOAD);
            CD3DX12_RESOURCE_DESC       textureUploadDesc       = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
            ThrowIfFailed(studio->m_device->CreateCommittedResource(
                &textureUpload,
                D3D12_HEAP_FLAG_NONE,
                &textureUploadDesc,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&textureUploadHeap)));

            // Copy data to the intermediate upload heap and then schedule
            // a copy from the upload heap to the diffuse texture.
            D3D12_SUBRESOURCE_DATA textureData = {};
            textureData.pData = model->pMeshData + Textures[0].Data[0].Offset;
            textureData.RowPitch = Textures[0].Data[0].Pitch;
            textureData.SlicePitch = Textures[0].Data[0].Size;

            UpdateSubresources(model->m_commandList.Get(), model->m_cityDiffuseTexture.Get(), textureUploadHeap.Get(), 0, 0, subresourceCount, &textureData);
            CD3DX12_RESOURCE_BARRIER        textureBarrier      = CD3DX12_RESOURCE_BARRIER::Transition(model->m_cityDiffuseTexture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
            model->m_commandList->ResourceBarrier(1, &textureBarrier);
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

        model->m_samplerHeapIndex       = studio->GetHeapManager().GetSamplerHeap().GetTop();
        CD3DX12_CPU_DESCRIPTOR_HANDLE   samplerHandle(studio->GetHeapManager().GetSamplerHeap().GetCPUStart(), model->m_samplerHeapIndex, studio->GetHeapManager().GetSamplerHeap().GetSize());
        studio->m_device->CreateSampler(&samplerDesc, samplerHandle);

        // Create SRV for the city's diffuse texture.
        model->m_textureHeapIndex       = studio->GetHeapManager().GetCbvSrvHeap().GetTop();

        CD3DX12_CPU_DESCRIPTOR_HANDLE srvHandle     = studio->GetHeapManager().GetCbvSrvHeap().Get(model->CityMaterialCount + 1);
        D3D12_SHADER_RESOURCE_VIEW_DESC diffuseSrvDesc = {};
        diffuseSrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        diffuseSrvDesc.Format = Textures->Format;
        diffuseSrvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
        diffuseSrvDesc.Texture2D.MipLevels = 1;
        studio->m_device->CreateShaderResourceView(model->m_cityDiffuseTexture.Get(), &diffuseSrvDesc, srvHandle);
        srvHandle.Offset(studio->GetHeapManager().GetCbvSrvHeap().GetSize());

        // Create SRVs for each city material.
        for (int i = 0; i < model->CityMaterialCount; ++i)
        {
            D3D12_SHADER_RESOURCE_VIEW_DESC materialSrvDesc = {};
            materialSrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            materialSrvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            materialSrvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            materialSrvDesc.Texture2D.MipLevels = 1;
            studio->m_device->CreateShaderResourceView(model->m_cityMaterialTextures[i].Get(), &materialSrvDesc, srvHandle);

            srvHandle.Offset(studio->GetHeapManager().GetCbvSrvHeap().GetSize());
        }
    }

    //delete pMeshData;

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
    ThrowIfFailed(model->m_commandList->Close());
    ID3D12CommandList* ppCommandLists[] = { model->m_commandList.Get() };
    studio->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    // Create synchronization objects and wait until assets have been uploaded to the GPU.
    {
        ThrowIfFailed(studio->m_device->CreateFence(studio->m_fenceValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&studio->m_fence)));
        studio->m_fenceValue++;

        // Create an event handle to use for frame synchronization.
        studio->m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (studio->m_fenceEvent == nullptr)
        {
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }

        // Wait for the command list to execute; we are reusing the same command
        // list in our main loop but for now, we just want to wait for setup to
        // complete before continuing.

        // Signal and increment the fence value.
        const UINT64 fenceToWaitFor = studio->m_fenceValue;
        ThrowIfFailed(studio->m_commandQueue->Signal(studio->m_fence.Get(), fenceToWaitFor));
        studio->m_fenceValue++;

        // Wait until the fence is completed.
        ThrowIfFailed(studio->m_fence->SetEventOnCompletion(fenceToWaitFor, studio->m_fenceEvent));
        WaitForSingleObject(studio->m_fenceEvent, INFINITE);
    }
}


T100VOID T100DX12ModelManagerBase::UploadMesh(T100DX12Studio* studio, T100DX12Model* model)
{
    ComPtr<ID3D12Resource>              vertexBufferUploadHeap;
    ComPtr<ID3D12Resource>              indexBufferUploadHeap;
    ComPtr<ID3D12Resource>              textureUploadHeap;

    CreateRootSignatureMesh(studio, model);
    CreatePipelineStateMesh(studio, model);

    CreateCommandList(studio, model);

    CreateVertexBuffer(studio, model, vertexBufferUploadHeap);
    CreateIndexBuffer(studio, model, indexBufferUploadHeap);
    CreateTextureBuffer(studio, model, textureUploadHeap);

    CloseCommandList(model);

    ExecuteCommandList(studio, model);

    studio->Waiting();

    //DEBUGPRINT("Upload City.");
}

T100VOID T100DX12ModelManagerBase::UploadSphere(T100DX12Studio* studio, T100DX12Model* model)
{

    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
    {
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
    }

    CD3DX12_DESCRIPTOR_RANGE1               ranges[1];
    ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

    CD3DX12_ROOT_PARAMETER1                 rootParameters[1];
    rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_ALL);

    CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC   rootSignatureDesc;
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));

    CreatePipelineState(studio, model);

    CreateCommandList(studio, model);

    CreateVertexBuffer(studio, model);

    CloseCommandList(model);

    ExecuteCommandList(studio, model);

    studio->Waiting();
}

T100VOID T100DX12ModelManagerBase::UploadRectangle(T100DX12Studio* studioPtr, T100DX12Model* modelPtr)
{
    ComPtr<ID3D12Resource> vertexBufferUploadHeap;
    ComPtr<ID3D12Resource> indexBufferUploadHeap;
    ComPtr<ID3D12Resource> textureUploadHeap;
    ComPtr<ID3D12Resource> materialsUploadHeap;

    {
        D3D12_FEATURE_DATA_ROOT_SIGNATURE featureData = {};

        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_1;

        if (FAILED(studioPtr->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
        {
            featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
        }

        CD3DX12_DESCRIPTOR_RANGE1 ranges[3];
        ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1 + modelPtr->CityMaterialCount, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);    // Diffuse texture + array of materials.
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
        ThrowIfFailed(studioPtr->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&modelPtr->m_rootSignature)));
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

        CD3DX12_RASTERIZER_DESC rasterizerStateDesc(D3D12_DEFAULT);
        rasterizerStateDesc.CullMode = D3D12_CULL_MODE_NONE;

        // Describe and create the graphics pipeline state object (PSO).
        D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
        psoDesc.InputLayout = { StandardVertexDescription, StandardVertexDescriptionNumElements };
        psoDesc.pRootSignature = modelPtr->m_rootSignature.Get();
        psoDesc.VS = CD3DX12_SHADER_BYTECODE(modelPtr->vertexShader.Get());
        psoDesc.PS = CD3DX12_SHADER_BYTECODE(modelPtr->pixelShader.Get());
        psoDesc.RasterizerState = rasterizerStateDesc;
        psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
        psoDesc.SampleMask = UINT_MAX;
        psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets = 1;
        psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;
        psoDesc.SampleDesc.Count = 1;

        ThrowIfFailed(studioPtr->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&modelPtr->m_pipelineState)));

        //delete pVertexShaderData;
        //delete pPixelShaderData;
    }

    ThrowIfFailed(studioPtr->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, studioPtr->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&modelPtr->m_commandList)));

    /*
    // Create render target views (RTVs).
    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());
    for (UINT i = 0; i < FrameCount; i++)
    {
        ThrowIfFailed(m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i])));
        m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, rtvHandle);
        rtvHandle.Offset(1, m_rtvDescriptorSize);
    }
    */

    const UINT StandardVertexStride = 44;
    const DXGI_FORMAT StandardIndexFormat = DXGI_FORMAT_R32_UINT;
    const UINT VertexDataOffset = 524288;
    const UINT VertexDataSize = 820248;
    const UINT IndexDataOffset = 1344536;
    const UINT IndexDataSize = 74568;
    // Create the vertex buffer.
    {
        CD3DX12_HEAP_PROPERTIES     vertexHeap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC       vertexHeapDesc      = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
        ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
            &vertexHeap,
            D3D12_HEAP_FLAG_NONE,
            &vertexHeapDesc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&modelPtr->m_vertexBuffer)));

        CD3DX12_HEAP_PROPERTIES     vertexUpload(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC       vertexUploadDesc        = CD3DX12_RESOURCE_DESC::Buffer(VertexDataSize);
        ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
            &vertexUpload,
            D3D12_HEAP_FLAG_NONE,
            &vertexUploadDesc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&vertexBufferUploadHeap)));

        // Copy data to the intermediate upload heap and then schedule a copy
        // from the upload heap to the vertex buffer.
        D3D12_SUBRESOURCE_DATA vertexData = {};
        vertexData.pData = modelPtr->pMeshData + VertexDataOffset;
        vertexData.RowPitch = VertexDataSize;
        vertexData.SlicePitch = vertexData.RowPitch;

        UpdateSubresources<1>(modelPtr->m_commandList.Get(), modelPtr->m_vertexBuffer.Get(), vertexBufferUploadHeap.Get(), 0, 0, 1, &vertexData);

        CD3DX12_RESOURCE_BARRIER    vertexBarrier       = CD3DX12_RESOURCE_BARRIER::Transition(modelPtr->m_vertexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
        modelPtr->m_commandList->ResourceBarrier(1, &vertexBarrier);

        // Initialize the vertex buffer view.
        modelPtr->m_vertexBufferView.BufferLocation = modelPtr->m_vertexBuffer->GetGPUVirtualAddress();
        modelPtr->m_vertexBufferView.StrideInBytes = StandardVertexStride;
        modelPtr->m_vertexBufferView.SizeInBytes = VertexDataSize;
    }

    // Create the index buffer.
    {
        CD3DX12_HEAP_PROPERTIES     indexHeap(D3D12_HEAP_TYPE_DEFAULT);
        CD3DX12_RESOURCE_DESC       indexHeapDesc       = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
            &indexHeap,
            D3D12_HEAP_FLAG_NONE,
            &indexHeapDesc,
            D3D12_RESOURCE_STATE_COPY_DEST,
            nullptr,
            IID_PPV_ARGS(&modelPtr->m_indexBuffer)));

        CD3DX12_HEAP_PROPERTIES     indexUpload(D3D12_HEAP_TYPE_UPLOAD);
        CD3DX12_RESOURCE_DESC       indexUploadDesc         = CD3DX12_RESOURCE_DESC::Buffer(IndexDataSize);
        ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
            &indexUpload,
            D3D12_HEAP_FLAG_NONE,
            &indexUploadDesc,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&indexBufferUploadHeap)));

        // Copy data to the intermediate upload heap and then schedule a copy
        // from the upload heap to the index buffer.
        D3D12_SUBRESOURCE_DATA indexData = {};
        indexData.pData = modelPtr->pMeshData + IndexDataOffset;
        indexData.RowPitch = IndexDataSize;
        indexData.SlicePitch = indexData.RowPitch;

        UpdateSubresources<1>(modelPtr->m_commandList.Get(), modelPtr->m_indexBuffer.Get(), indexBufferUploadHeap.Get(), 0, 0, 1, &indexData);

        CD3DX12_RESOURCE_BARRIER    indexBarrier        = CD3DX12_RESOURCE_BARRIER::Transition(modelPtr->m_indexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_INDEX_BUFFER);
        modelPtr->m_commandList->ResourceBarrier(1, &indexBarrier);

        // Describe the index buffer view.
        modelPtr->m_indexBufferView.BufferLocation = modelPtr->m_indexBuffer->GetGPUVirtualAddress();
        modelPtr->m_indexBufferView.Format = StandardIndexFormat;
        modelPtr->m_indexBufferView.SizeInBytes = IndexDataSize;

        modelPtr->m_numIndices = IndexDataSize / 4;    // R32_UINT (SampleAssets::StandardIndexFormat) = 4 bytes each.
    }

    // Create the textures and sampler.
    {
        // Procedurally generate an array of textures to use as city materials.
        {
            // All of these materials use the same texture desc.
            D3D12_RESOURCE_DESC textureDesc = {};
            textureDesc.MipLevels = 1;
            textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            textureDesc.Width = modelPtr->CityMaterialTextureWidth;
            textureDesc.Height = modelPtr->CityMaterialTextureHeight;
            textureDesc.Flags = D3D12_RESOURCE_FLAG_NONE;
            textureDesc.DepthOrArraySize = 1;
            textureDesc.SampleDesc.Count = 1;
            textureDesc.SampleDesc.Quality = 0;
            textureDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

            // The textures evenly span the color rainbow so that each city gets
            // a different material.
            float materialGradStep = (1.0f / static_cast<float>(modelPtr->CityMaterialCount));

            // Generate texture data.
            std::vector<std::vector<unsigned char>> cityTextureData;
            cityTextureData.resize(modelPtr->CityMaterialCount);
            for (UINT i = 0; i < modelPtr->CityMaterialCount; ++i)
            {
                CD3DX12_HEAP_PROPERTIES materialHeap(D3D12_HEAP_TYPE_DEFAULT);
                ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
                    &materialHeap,
                    D3D12_HEAP_FLAG_NONE,
                    &textureDesc,
                    D3D12_RESOURCE_STATE_COPY_DEST,
                    nullptr,
                    IID_PPV_ARGS(&modelPtr->m_cityMaterialTextures[i])));

                // Fill the texture.
                float t = i * materialGradStep;
                cityTextureData[i].resize(modelPtr->CityMaterialTextureWidth * modelPtr->CityMaterialTextureHeight * modelPtr->CityMaterialTextureChannelCount);
                for (int x = 0; x < modelPtr->CityMaterialTextureWidth; ++x)
                {
                    for (int y = 0; y < modelPtr->CityMaterialTextureHeight; ++y)
                    {
                        // Compute the appropriate index into the buffer based on the x/y coordinates.
                        int pixelIndex = (y * modelPtr->CityMaterialTextureChannelCount * modelPtr->CityMaterialTextureWidth) + (x * modelPtr->CityMaterialTextureChannelCount);

                        // Determine this row's position along the rainbow gradient.
                        float tPrime = t + ((static_cast<float>(y) / static_cast<float>(modelPtr->CityMaterialTextureHeight)) * materialGradStep);

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
                const UINT64 uploadBufferStep = GetRequiredIntermediateSize(modelPtr->m_cityMaterialTextures[0].Get(), 0, subresourceCount); // All of our textures are the same size in this case.
                const UINT64 uploadBufferSize = uploadBufferStep * modelPtr->CityMaterialCount;

                CD3DX12_HEAP_PROPERTIES     textureHeap(D3D12_HEAP_TYPE_UPLOAD);
                CD3DX12_RESOURCE_DESC       textureHeapDesc         = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
                ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
                    &textureHeap,
                    D3D12_HEAP_FLAG_NONE,
                    &textureHeapDesc,
                    D3D12_RESOURCE_STATE_GENERIC_READ,
                    nullptr,
                    IID_PPV_ARGS(&materialsUploadHeap)));

                for (int i = 0; i < modelPtr->CityMaterialCount; ++i)
                {
                    // Copy data to the intermediate upload heap and then schedule
                    // a copy from the upload heap to the appropriate texture.
                    D3D12_SUBRESOURCE_DATA textureData = {};
                    textureData.pData = &cityTextureData[i][0];
                    textureData.RowPitch = static_cast<LONG_PTR>((modelPtr->CityMaterialTextureChannelCount * textureDesc.Width));
                    textureData.SlicePitch = textureData.RowPitch * textureDesc.Height;

                    UpdateSubresources(modelPtr->m_commandList.Get(), modelPtr->m_cityMaterialTextures[i].Get(), materialsUploadHeap.Get(), i * uploadBufferStep, 0, subresourceCount, &textureData);
                    CD3DX12_RESOURCE_BARRIER        textureBarrier      = CD3DX12_RESOURCE_BARRIER::Transition(modelPtr->m_cityMaterialTextures[i].Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
                    modelPtr->m_commandList->ResourceBarrier(1, &textureBarrier);
                }
            }
        }

        DX12TextureResource Textures[] =
        {
            { 1024, 1024, 1, DXGI_FORMAT_BC1_UNORM, { { 0, 524288, 2048 }, } }, // city.dds
        };

        DX12DrawParameters Draws[] =
        {
            { 0, -1, -1, 0, 18642, 0 },
        };

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
            ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
                &textureHeap,
                D3D12_HEAP_FLAG_NONE,
                &textureDesc,
                D3D12_RESOURCE_STATE_COPY_DEST,
                nullptr,
                IID_PPV_ARGS(&modelPtr->m_cityDiffuseTexture)));

            const UINT subresourceCount = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
            const UINT64 uploadBufferSize = GetRequiredIntermediateSize(modelPtr->m_cityDiffuseTexture.Get(), 0, subresourceCount);

            CD3DX12_HEAP_PROPERTIES     textureUpload(D3D12_HEAP_TYPE_UPLOAD);
            CD3DX12_RESOURCE_DESC       textureUploadDesc       = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
            ThrowIfFailed(studioPtr->m_device->CreateCommittedResource(
                &textureUpload,
                D3D12_HEAP_FLAG_NONE,
                &textureUploadDesc,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&textureUploadHeap)));

            // Copy data to the intermediate upload heap and then schedule
            // a copy from the upload heap to the diffuse texture.
            D3D12_SUBRESOURCE_DATA textureData = {};
            textureData.pData = modelPtr->pMeshData + Textures[0].Data[0].Offset;
            textureData.RowPitch = Textures[0].Data[0].Pitch;
            textureData.SlicePitch = Textures[0].Data[0].Size;

            UpdateSubresources(modelPtr->m_commandList.Get(), modelPtr->m_cityDiffuseTexture.Get(), textureUploadHeap.Get(), 0, 0, subresourceCount, &textureData);
            CD3DX12_RESOURCE_BARRIER        textureBarrier      = CD3DX12_RESOURCE_BARRIER::Transition(modelPtr->m_cityDiffuseTexture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
            modelPtr->m_commandList->ResourceBarrier(1, &textureBarrier);
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

        modelPtr->m_samplerHeapIndex       = studioPtr->GetHeapManager().GetSamplerHeap().GetTop();
        CD3DX12_CPU_DESCRIPTOR_HANDLE   samplerHandle(studioPtr->GetHeapManager().GetSamplerHeap().GetCPUStart(), modelPtr->m_samplerHeapIndex, studioPtr->GetHeapManager().GetSamplerHeap().GetSize());
        studioPtr->m_device->CreateSampler(&samplerDesc, samplerHandle);

        // Create SRV for the city's diffuse texture.
        modelPtr->m_textureHeapIndex       = studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();

        CD3DX12_CPU_DESCRIPTOR_HANDLE srvHandle     = studioPtr->GetHeapManager().GetCbvSrvHeap().Get(modelPtr->CityMaterialCount + 1);
        D3D12_SHADER_RESOURCE_VIEW_DESC diffuseSrvDesc = {};
        diffuseSrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        diffuseSrvDesc.Format = Textures->Format;
        diffuseSrvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
        diffuseSrvDesc.Texture2D.MipLevels = 1;
        studioPtr->m_device->CreateShaderResourceView(modelPtr->m_cityDiffuseTexture.Get(), &diffuseSrvDesc, srvHandle);
        srvHandle.Offset(studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

        // Create SRVs for each city material.
        for (int i = 0; i < modelPtr->CityMaterialCount; ++i)
        {
            D3D12_SHADER_RESOURCE_VIEW_DESC materialSrvDesc = {};
            materialSrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            materialSrvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            materialSrvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            materialSrvDesc.Texture2D.MipLevels = 1;
            studioPtr->m_device->CreateShaderResourceView(modelPtr->m_cityMaterialTextures[i].Get(), &materialSrvDesc, srvHandle);

            srvHandle.Offset(studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
        }
    }

    //delete pMeshData;

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
    ThrowIfFailed(modelPtr->m_commandList->Close());
    ID3D12CommandList* ppCommandLists[] = { modelPtr->m_commandList.Get() };
    studioPtr->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    /*
    // Create synchronization objects and wait until assets have been uploaded to the GPU.
    {
        ThrowIfFailed(studioPtr->m_device->CreateFence(studio->m_fenceValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&studio->m_fence)));
        studio->m_fenceValue++;

        // Create an event handle to use for frame synchronization.
        studio->m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (studio->m_fenceEvent == nullptr)
        {
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }

        // Wait for the command list to execute; we are reusing the same command
        // list in our main loop but for now, we just want to wait for setup to
        // complete before continuing.

        // Signal and increment the fence value.
        const UINT64 fenceToWaitFor = studio->m_fenceValue;
        ThrowIfFailed(studio->m_commandQueue->Signal(studio->m_fence.Get(), fenceToWaitFor));
        studio->m_fenceValue++;

        // Wait until the fence is completed.
        ThrowIfFailed(studio->m_fence->SetEventOnCompletion(fenceToWaitFor, studio->m_fenceEvent));
        WaitForSingleObject(studio->m_fenceEvent, INFINITE);
    }
    */
    studioPtr->Waiting();
}

T100VOID T100DX12ModelManagerBase::CreateEmptyRootSignature(T100DX12Studio* studio, T100DX12Model* model)
{
    CD3DX12_ROOT_SIGNATURE_DESC         rootSignatureDesc;
    rootSignatureDesc.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>        signature;
    ComPtr<ID3DBlob>        error;

    ThrowIfFailed(D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));
}

T100VOID T100DX12ModelManagerBase::CreateRootSignature(T100DX12Studio* studio, T100DX12Model* model)
{
    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
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
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));
}

T100VOID T100DX12ModelManagerBase::CreateCommandList(T100DX12Studio* studio, T100DX12Model* model)
{
    ThrowIfFailed(studio->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, studio->m_commandAllocator.Get(), T100NULL, IID_PPV_ARGS(&model->m_commandList)));
}

T100VOID T100DX12ModelManagerBase::CloseCommandList(T100DX12Model* model)
{
    ThrowIfFailed(model->m_commandList->Close());
}

T100VOID T100DX12ModelManagerBase::ExecuteCommandList(T100DX12Studio* studio, T100DX12Model* model)
{
    ID3D12CommandList*                  ppCommandLists[] = { model->m_commandList.Get() };
    studio->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
}

T100VOID T100DX12ModelManagerBase::CreatePipelineState(T100DX12Studio* studio, T100DX12Model* model)
{
    D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

    T100DX12Model&  value = *model;

    psoDesc.InputLayout                     = { model->VertexDescriptions, model->VertexDescriptionsLength };
    psoDesc.pRootSignature                  = model->m_rootSignature.Get();
    psoDesc.VS                              = CD3DX12_SHADER_BYTECODE(model->vertexShader.Get());
    psoDesc.PS                              = CD3DX12_SHADER_BYTECODE(model->pixelShader.Get());
    psoDesc.RasterizerState                 = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
    psoDesc.BlendState                      = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
    psoDesc.DepthStencilState.DepthEnable   = FALSE;
    psoDesc.DepthStencilState.StencilEnable = FALSE;
    psoDesc.SampleMask                      = UINT_MAX;
    psoDesc.PrimitiveTopologyType           = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    psoDesc.NumRenderTargets                = 1;
    psoDesc.RTVFormats[0]                   = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.SampleDesc.Count                = 1;

    ThrowIfFailed(studio->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&model->m_pipelineState)));
}

T100VOID T100DX12ModelManagerBase::CreatePipelineState1And2(T100DX12Studio* studio, T100DX12Model* model)
{
    CD3DX12_RASTERIZER_DESC                 rasterizerStateDesc(D3D12_DEFAULT);
    rasterizerStateDesc.CullMode = D3D12_CULL_MODE_NONE;

    D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

    psoDesc.InputLayout                     = { model->VertexDescriptions, model->VertexDescriptionsLength };
    psoDesc.pRootSignature                  = model->m_rootSignature.Get();
    psoDesc.VS                              = CD3DX12_SHADER_BYTECODE(model->pVertexShaderData, model->VertexShaderDataLength);
    psoDesc.PS                              = CD3DX12_SHADER_BYTECODE(model->pPixelShaderData1, model->PixelShaderDataLength1);
    psoDesc.RasterizerState                 = rasterizerStateDesc;
    psoDesc.BlendState                      = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
    psoDesc.DepthStencilState               = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
    psoDesc.SampleMask                      = UINT_MAX;
    psoDesc.PrimitiveTopologyType           = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    psoDesc.NumRenderTargets                = 1;
    psoDesc.RTVFormats[0]                   = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.DSVFormat                       = DXGI_FORMAT_D32_FLOAT;
    psoDesc.SampleDesc.Count                = 1;

    ThrowIfFailed(studio->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&model->m_pipelineState1)));

    psoDesc.PS = CD3DX12_SHADER_BYTECODE(model->pPixelShaderData2, model->PixelShaderDataLength2);

    ThrowIfFailed(studio->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&model->m_pipelineState2)));
}

T100VOID T100DX12ModelManagerBase::CreateVertexBuffer(T100DX12Studio* studio, T100DX12Model* model, ComPtr<ID3D12Resource>& vertexBufferUploadHeap)
{
    CD3DX12_HEAP_PROPERTIES         vertexHeap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           vertexDesc      = CD3DX12_RESOURCE_DESC::Buffer(model->VertexDataLength);

    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &vertexHeap,
        D3D12_HEAP_FLAG_NONE,
        &vertexDesc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        T100NULL,
        IID_PPV_ARGS(&model->m_vertexBuffer)));

    CD3DX12_HEAP_PROPERTIES     uploadHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC       uploadDesc          = CD3DX12_RESOURCE_DESC::Buffer(model->VertexDataLength);
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &uploadHeap,
        D3D12_HEAP_FLAG_NONE,
        &uploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        T100NULL,
        IID_PPV_ARGS(&vertexBufferUploadHeap)));

    D3D12_SUBRESOURCE_DATA      vertexData = {};
    vertexData.pData            = model->pMeshData + model->VertexDataOffset;
    vertexData.RowPitch         = model->VertexDataLength;
    vertexData.SlicePitch       = vertexData.RowPitch;

    UpdateSubresources<1>(model->m_commandList.Get(), model->m_vertexBuffer.Get(), vertexBufferUploadHeap.Get(), 0, 0, 1, &vertexData);
    CD3DX12_RESOURCE_BARRIER        barrier     = CD3DX12_RESOURCE_BARRIER::Transition(model->m_vertexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
    model->m_commandList->ResourceBarrier(1, &barrier);

    model->m_vertexBufferView.BufferLocation      = model->m_vertexBuffer->GetGPUVirtualAddress();
    model->m_vertexBufferView.StrideInBytes       = model->VertexStride;
    model->m_vertexBufferView.SizeInBytes         = model->VertexDataLength;
}

T100VOID T100DX12ModelManagerBase::CreateIndexBuffer(T100DX12Studio* studio, T100DX12Model* model, ComPtr<ID3D12Resource>& indexBufferUploadHeap)
{
    CD3DX12_HEAP_PROPERTIES         indexHeap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           indexDesc       = CD3DX12_RESOURCE_DESC::Buffer(model->IndexDataLength);
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &indexHeap,
        D3D12_HEAP_FLAG_NONE,
        &indexDesc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        T100NULL,
        IID_PPV_ARGS(&model->m_indexBuffer)));

    CD3DX12_HEAP_PROPERTIES         uploadHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           uploadDesc      = CD3DX12_RESOURCE_DESC::Buffer(model->IndexDataLength);
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &uploadHeap,
        D3D12_HEAP_FLAG_NONE,
        &uploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        T100NULL,
        IID_PPV_ARGS(&indexBufferUploadHeap)));

    D3D12_SUBRESOURCE_DATA          indexData = {};
    indexData.pData         = model->pMeshData + model->IndexDataOffset;
    indexData.RowPitch      = model->IndexDataLength;
    indexData.SlicePitch    = indexData.RowPitch;

    UpdateSubresources<1>(model->m_commandList.Get(), model->m_indexBuffer.Get(), indexBufferUploadHeap.Get(), 0, 0, 1, &indexData);
    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(model->m_indexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_INDEX_BUFFER);
    model->m_commandList->ResourceBarrier(1, &barrier);

    model->m_indexBufferView.BufferLocation    = model->m_indexBuffer->GetGPUVirtualAddress();
    model->m_indexBufferView.Format            = model->IndexFormat;
    model->m_indexBufferView.SizeInBytes       = model->IndexDataLength;

    model->m_numIndices = model->IndexDataLength / 4;
}

T100VOID T100DX12ModelManagerBase::CreateTextureBuffer(T100DX12Studio* studio, T100DX12Model* model, ComPtr<ID3D12Resource>& textureUploadHeap)
{
    D3D12_RESOURCE_DESC             textureDesc = {};

    textureDesc.MipLevels           = model->Textures[0].MipLevels;
    textureDesc.Format              = model->Textures[0].Format;
    textureDesc.Width               = model->Textures[0].Width;
    textureDesc.Height              = model->Textures[0].Height;
    textureDesc.Flags               = D3D12_RESOURCE_FLAG_NONE;
    textureDesc.DepthOrArraySize    = 1;
    textureDesc.SampleDesc.Count    = 1;
    textureDesc.SampleDesc.Quality  = 0;
    textureDesc.Dimension           = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

    CD3DX12_HEAP_PROPERTIES         textureHeap(D3D12_HEAP_TYPE_DEFAULT);
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &textureHeap,
        D3D12_HEAP_FLAG_NONE,
        &textureDesc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        T100NULL,
        IID_PPV_ARGS(&model->m_texture)));

    const UINT subresourceCount     = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
    const UINT64 uploadBufferSize   = GetRequiredIntermediateSize(model->m_texture.Get(), 0, subresourceCount);

    CD3DX12_HEAP_PROPERTIES         samplerUploadHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           samplerUploadDesc         = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &samplerUploadHeap,
        D3D12_HEAP_FLAG_NONE,
        &samplerUploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        T100NULL,
        IID_PPV_ARGS(&textureUploadHeap)));

    D3D12_SUBRESOURCE_DATA          textureData = {};
    textureData.pData               = model->pMeshData + model->Textures[0].Data[0].Offset;
    textureData.RowPitch            = model->Textures[0].Data[0].Pitch;
    textureData.SlicePitch          = model->Textures[0].Data[0].Size;

    UpdateSubresources(model->m_commandList.Get(), model->m_texture.Get(), textureUploadHeap.Get(), 0, 0, subresourceCount, &textureData);
    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(model->m_texture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
    model->m_commandList->ResourceBarrier(1, &barrier);

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

    model->m_samplerHeapIndex   = studio->m_heap_manager.GetSamplerHeap().GetTop();
    studio->m_device->CreateSampler(&samplerDesc, studio->m_heap_manager.GetSamplerHeap().Get(1));

    D3D12_SHADER_RESOURCE_VIEW_DESC         srvDesc = {};
    srvDesc.Shader4ComponentMapping         = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Format                          = model->Textures->Format;
    srvDesc.ViewDimension                   = D3D12_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels             = 1;

    model->m_textureHeapIndex   = studio->m_heap_manager.GetCbvSrvHeap().GetTop();
    studio->m_device->CreateShaderResourceView(model->m_texture.Get(), &srvDesc, studio->m_heap_manager.GetCbvSrvHeap().Get(1));

}

DXGI_FORMAT T100DX12ModelManagerBase::ConvertFormat(T100DXGI_FORMAT format)
{
    DXGI_FORMAT     result;

    switch(format){
    case T100DXGI_FORMAT_BC1_UNORM:
        {
            result  = DXGI_FORMAT_BC1_UNORM;
        }
        break;
    case T100DXGI_FORMAT_R32_UINT:
        {
            result  = DXGI_FORMAT_R32_UINT;
        }
        break;
    }

    return result;
}

T100VOID T100DX12ModelManagerBase::CreateVertexBuffer(T100DX12Studio* studio, T100DX12Model* model)
{
    CD3DX12_HEAP_PROPERTIES     upload          = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC       uploadDesc      = CD3DX12_RESOURCE_DESC::Buffer(model->Length);

    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &upload,
        D3D12_HEAP_FLAG_NONE,
        &uploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&model->m_vertexBuffer)));

    UINT8*              pVertexDataBegin;
    CD3DX12_RANGE       readRange(0, 0);

    ThrowIfFailed(model->m_vertexBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pVertexDataBegin)));
    memcpy(pVertexDataBegin, model->vertex, model->Length);
    model->m_vertexBuffer->Unmap(0, nullptr);

    model->m_vertexBufferView.BufferLocation    = model->m_vertexBuffer->GetGPUVirtualAddress();
    model->m_vertexBufferView.StrideInBytes     = sizeof(Vertex);
    model->m_vertexBufferView.SizeInBytes       = model->Length;
}

T100VOID T100DX12ModelManagerBase::CreateRootSignatureMesh(T100DX12Studio* studio, T100DX12Model* model)
{
    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
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
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&model->m_rootSignature)));
}

T100VOID T100DX12ModelManagerBase::CreatePipelineStateMesh(T100DX12Studio* studio, T100DX12Model* model)
{
    D3D12_INPUT_ELEMENT_DESC vertElem[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "TANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "BITANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
    };

    D3D12_BLEND_DESC        alphaBlend = {};
    alphaBlend.IndependentBlendEnable = FALSE;
    alphaBlend.RenderTarget[0].BlendEnable = FALSE;
    alphaBlend.RenderTarget[0].SrcBlend = D3D12_BLEND_SRC_ALPHA;
    alphaBlend.RenderTarget[0].DestBlend = D3D12_BLEND_INV_SRC_ALPHA;
    alphaBlend.RenderTarget[0].BlendOp = D3D12_BLEND_OP_ADD;
    alphaBlend.RenderTarget[0].SrcBlendAlpha = D3D12_BLEND_ONE;
    alphaBlend.RenderTarget[0].DestBlendAlpha = D3D12_BLEND_INV_SRC_ALPHA;
    alphaBlend.RenderTarget[0].BlendOpAlpha = D3D12_BLEND_OP_ADD;
    alphaBlend.RenderTarget[0].RenderTargetWriteMask = 0;

    D3D12_DEPTH_STENCIL_DESC DepthStateDisabled;
    D3D12_DEPTH_STENCIL_DESC DepthStateReadWrite;
    D3D12_DEPTH_STENCIL_DESC DepthStateReadOnly;
    D3D12_DEPTH_STENCIL_DESC DepthStateTestEqual;

    DepthStateDisabled.DepthEnable = FALSE;
    DepthStateDisabled.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ZERO;
    DepthStateDisabled.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;
    DepthStateDisabled.StencilEnable = FALSE;
    DepthStateDisabled.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;
    DepthStateDisabled.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;
    DepthStateDisabled.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;
    DepthStateDisabled.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
    DepthStateDisabled.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
    DepthStateDisabled.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
    DepthStateDisabled.BackFace = DepthStateDisabled.FrontFace;

    DepthStateReadWrite = DepthStateDisabled;
    DepthStateReadWrite.DepthEnable = TRUE;
    DepthStateReadWrite.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
    DepthStateReadWrite.DepthFunc = D3D12_COMPARISON_FUNC_GREATER_EQUAL;

    DepthStateReadOnly = DepthStateReadWrite;
    DepthStateReadOnly.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ZERO;

    DepthStateTestEqual = DepthStateReadOnly;
    DepthStateTestEqual.DepthFunc = D3D12_COMPARISON_FUNC_EQUAL;

    D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

    T100DX12Model&  value = *model;

    psoDesc.InputLayout                     = { vertElem, 5 };
    psoDesc.pRootSignature                  = model->m_rootSignature.Get();
    psoDesc.VS                              = CD3DX12_SHADER_BYTECODE(model->pVertexShaderData, model->VertexShaderDataLength);
    psoDesc.PS                              = CD3DX12_SHADER_BYTECODE(model->pPixelShaderData, model->PixelShaderDataLength);
    psoDesc.RasterizerState                 = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
    psoDesc.BlendState                      = alphaBlend;
    psoDesc.DepthStencilState               = DepthStateTestEqual;
    psoDesc.SampleMask                      = UINT_MAX;
    psoDesc.PrimitiveTopologyType           = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    psoDesc.NumRenderTargets                = 2;
    psoDesc.RTVFormats[0]                   = DXGI_FORMAT_R11G11B10_FLOAT;
    psoDesc.RTVFormats[1]                   = DXGI_FORMAT_R16G16B16A16_FLOAT;
    psoDesc.SampleDesc.Count                = 1;

    ThrowIfFailed(studio->m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&model->m_pipelineState)));
}

T100VOID T100DX12ModelManagerBase::CreateLightBuffer(T100DX12Studio* studio, T100DX12Model* model)
{
    T100DX12_LIGHT_VECTOR&      lights      = studio->GetLightManager().GetLights();
    T100UINT                    length      = lights.size();

    T100UINT                    size        = sizeof(Light) * length;

    CD3DX12_HEAP_PROPERTIES     upload          = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC       uploadDesc      = CD3DX12_RESOURCE_DESC::Buffer(size);

    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &upload,
        D3D12_HEAP_FLAG_NONE,
        &uploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&model->m_lightBuffer)));

    UINT8*              pLightDataBegin;
    CD3DX12_RANGE       readRange(0, 0);

    ThrowIfFailed(model->m_lightBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pLightDataBegin)));
    //memcpy(pLightDataBegin, model->vertex, model->Length);
    model->m_lightBuffer->Unmap(0, nullptr);

    model->m_lightBufferView.BufferLocation                 = model->m_lightBuffer->GetGPUVirtualAddress();
    model->m_lightBufferView.SizeInBytes                    = sizeof(Light);
    model->m_lightBufferView.BufferFilledSizeLocation       = size;
}
