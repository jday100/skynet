#include "mesh/T100DX12MeshManagerBase.h"

#include <d3dcompiler.h>
#include "T100Unicode.h"
#include "dx12/T100DX12Tools.h"
#include "math/T100DX12MathTools.h"
#include "core/T100DX12Studio.h"

T100DX12MeshManagerBase::T100DX12MeshManagerBase()
{
    //ctor
}

T100DX12MeshManagerBase::~T100DX12MeshManagerBase()
{
    //dtor
}

DXGI_FORMAT T100DX12MeshManagerBase::ConvertFormat(T100DXGI_FORMAT format)
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

T100DX12Mesh* T100DX12MeshManagerBase::ConvertMesh(T1003DMesh* meshPtr, T100UINT width, T100UINT height)
{
    T100DX12Mesh*   resultPtr       = T100NULL;

    resultPtr   = T100NEW T100DX12Mesh();

    MemoryCopy(&resultPtr->Bundle, meshPtr->GetBundlePtr(), sizeof(T100BUNDLE));

    resultPtr->Type                     = meshPtr->Type;
    resultPtr->RenderType               = meshPtr->GetRenderType();
    resultPtr->MotionType               = meshPtr->GetMotionType();

    resultPtr->VertexData.DATA_PTR      = meshPtr->VertexData.DATA_PTR;
    resultPtr->VertexData.LENGTH        = meshPtr->VertexData.LENGTH;

    resultPtr->VertexDescriptions       = (D3D12_INPUT_ELEMENT_DESC*)meshPtr->VertexDescription;
    resultPtr->VertexDescriptionsLength = meshPtr->VertexDescriptionLength;

    resultPtr->SetPosition(meshPtr->GetPosition());
    resultPtr->SetRotation(meshPtr->GetRotation());
    resultPtr->SetScaling(meshPtr->GetScaling());
    resultPtr->SetVisible(meshPtr->IsVisible());

    resultPtr->SetAmount(meshPtr->GetAmount());

    LoadFile(meshPtr->VertexShaderFile, resultPtr->VertexShader);
    LoadFile(meshPtr->PixelShaderFile, resultPtr->PixelShader);

    resultPtr->Stride   = sizeof(Vertex);

    meshPtr->SetInstancePtr(resultPtr);

    return resultPtr;
}

T100VOID T100DX12MeshManagerBase::ConvertScreenMesh(T1003DMesh* source, T100UINT width, T100UINT height, T100DX12Mesh* target)
{
    T100Vector3f    value;

    ScreenToView(source->GetPosition(), width, height, value);

    target->SetPosition(value);
}

T100VOID T100DX12MeshManagerBase::ConvertSpaceMesh(T1003DMesh* source, T100UINT width, T100UINT height, T100DX12Mesh* target)
{
    target->SetPosition(source->GetPosition());
}

T100VOID T100DX12MeshManagerBase::UploadMesh(T100DX12Studio* studioPtr, T100DX12Mesh* meshPtr)
{
    if(meshPtr->RenderType == T1003D_RENDER_SCREEN &&
       meshPtr->MotionType == T1003D_MOTION_STILL){
        CreateEmptyRootSignature(studioPtr, meshPtr);
    }else{
        CreateRootSignatureSingle(studioPtr, meshPtr);
    }


    ComPtr<ID3D12Resource>              vertexBufferUploadHeap;
    ComPtr<ID3D12Resource>              indexBufferUploadHeap;
    ComPtr<ID3D12Resource>              textureUploadHeap;

    CreatePipelineState(studioPtr, meshPtr);
    CreateCommandList(studioPtr, meshPtr);

    CreateVertexBuffer(studioPtr, meshPtr, vertexBufferUploadHeap);

    CloseCommandList(meshPtr);
    ExecuteCommandList(studioPtr, meshPtr);

    studioPtr->Waiting();
}

T100VOID T100DX12MeshManagerBase::CreateEmptyRootSignature(T100DX12Studio* studio, T100DX12Mesh* mesh)
{
    CD3DX12_ROOT_SIGNATURE_DESC         rootSignatureDesc;
    rootSignatureDesc.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>        signature;
    ComPtr<ID3DBlob>        error;

    ThrowIfFailed(D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error));
    ThrowIfFailed(studio->GetDevicePtr()->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&mesh->m_rootSignature)));
}

T100VOID T100DX12MeshManagerBase::CreateRootSignature(T100DX12Studio* studio, T100DX12Mesh* mesh)
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
    ThrowIfFailed(studio->GetDevicePtr()->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&mesh->m_rootSignature)));
}


T100VOID T100DX12MeshManagerBase::CreateRootSignatureSingle(T100DX12Studio* studio, T100DX12Mesh* mesh)
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
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&mesh->m_rootSignature)));
}


T100VOID T100DX12MeshManagerBase::CreatePipelineState(T100DX12Studio* studio, T100DX12Mesh* mesh)
{
    D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

    psoDesc.InputLayout                     = { mesh->VertexDescriptions, mesh->VertexDescriptionsLength };
    psoDesc.pRootSignature                  = mesh->m_rootSignature.Get();
    psoDesc.VS                              = CD3DX12_SHADER_BYTECODE(mesh->VertexShader.Get());
    psoDesc.PS                              = CD3DX12_SHADER_BYTECODE(mesh->PixelShader.Get());
    psoDesc.RasterizerState                 = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
    psoDesc.BlendState                      = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
    psoDesc.DepthStencilState.DepthEnable   = FALSE;
    psoDesc.DepthStencilState.StencilEnable = FALSE;
    psoDesc.SampleMask                      = UINT_MAX;
    psoDesc.PrimitiveTopologyType           = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    psoDesc.NumRenderTargets                = 1;
    psoDesc.RTVFormats[0]                   = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.SampleDesc.Count                = 1;

    ThrowIfFailed(studio->GetDevicePtr()->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&mesh->m_pipelineState)));
}

T100VOID T100DX12MeshManagerBase::CreateCommandList(T100DX12Studio* studio, T100DX12Mesh* mesh)
{
    ThrowIfFailed(studio->GetDevicePtr()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, studio->m_commandAllocator.Get(), T100NULL, IID_PPV_ARGS(&mesh->m_commandList)));
}

T100VOID T100DX12MeshManagerBase::CloseCommandList(T100DX12Mesh* mesh)
{
    ThrowIfFailed(mesh->m_commandList->Close());
}

T100VOID T100DX12MeshManagerBase::ExecuteCommandList(T100DX12Studio* studio, T100DX12Mesh* mesh)
{
    ID3D12CommandList*                  ppCommandLists[] = { mesh->m_commandList.Get() };
    studio->m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
}

T100VOID T100DX12MeshManagerBase::CreateVertexBuffer(T100DX12Studio* studio, T100DX12Mesh* mesh, ComPtr<ID3D12Resource>& vertexBufferUploadHeap)
{
    CD3DX12_HEAP_PROPERTIES         vertexHeap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           vertexDesc      = CD3DX12_RESOURCE_DESC::Buffer(mesh->VertexData.LENGTH);

    ThrowIfFailed(studio->GetDevicePtr()->CreateCommittedResource(
        &vertexHeap,
        D3D12_HEAP_FLAG_NONE,
        &vertexDesc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        T100NULL,
        IID_PPV_ARGS(&mesh->m_vertexBuffer)));

    CD3DX12_HEAP_PROPERTIES     uploadHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC       uploadDesc          = CD3DX12_RESOURCE_DESC::Buffer(mesh->VertexData.LENGTH);
    ThrowIfFailed(studio->GetDevicePtr()->CreateCommittedResource(
        &uploadHeap,
        D3D12_HEAP_FLAG_NONE,
        &uploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        T100NULL,
        IID_PPV_ARGS(&vertexBufferUploadHeap)));

    D3D12_SUBRESOURCE_DATA      vertexData = {};
    vertexData.pData            = mesh->VertexData.DATA_PTR;
    vertexData.RowPitch         = mesh->VertexData.LENGTH;
    vertexData.SlicePitch       = vertexData.RowPitch;

    UpdateSubresources<1>(mesh->m_commandList.Get(), mesh->m_vertexBuffer.Get(), vertexBufferUploadHeap.Get(), 0, 0, 1, &vertexData);
    CD3DX12_RESOURCE_BARRIER        barrier     = CD3DX12_RESOURCE_BARRIER::Transition(mesh->m_vertexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
    mesh->m_commandList->ResourceBarrier(1, &barrier);

    mesh->m_vertexBufferView.BufferLocation      = mesh->m_vertexBuffer->GetGPUVirtualAddress();
    mesh->m_vertexBufferView.StrideInBytes       = mesh->Stride;
    mesh->m_vertexBufferView.SizeInBytes         = mesh->VertexData.LENGTH;
}

T100VOID T100DX12MeshManagerBase::CreateVertexBufferCity(T100DX12Studio* studio, T100DX12Mesh* mesh, ComPtr<ID3D12Resource>& vertexBufferUploadHeap)
{
    CD3DX12_HEAP_PROPERTIES         vertexHeap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           vertexDesc      = CD3DX12_RESOURCE_DESC::Buffer(mesh->VertexDataLength);

    ThrowIfFailed(studio->GetDevicePtr()->CreateCommittedResource(
        &vertexHeap,
        D3D12_HEAP_FLAG_NONE,
        &vertexDesc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        T100NULL,
        IID_PPV_ARGS(&mesh->m_vertexBuffer)));

    CD3DX12_HEAP_PROPERTIES     uploadHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC       uploadDesc          = CD3DX12_RESOURCE_DESC::Buffer(mesh->VertexDataLength);
    ThrowIfFailed(studio->GetDevicePtr()->CreateCommittedResource(
        &uploadHeap,
        D3D12_HEAP_FLAG_NONE,
        &uploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        T100NULL,
        IID_PPV_ARGS(&vertexBufferUploadHeap)));

    D3D12_SUBRESOURCE_DATA      vertexData = {};
    vertexData.pData            = mesh->MeshData.DATA_PTR + mesh->VertexDataOffset;
    vertexData.RowPitch         = mesh->VertexDataLength;
    vertexData.SlicePitch       = vertexData.RowPitch;

    UpdateSubresources<1>(mesh->m_commandList.Get(), mesh->m_vertexBuffer.Get(), vertexBufferUploadHeap.Get(), 0, 0, 1, &vertexData);
    CD3DX12_RESOURCE_BARRIER        barrier     = CD3DX12_RESOURCE_BARRIER::Transition(mesh->m_vertexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
    mesh->m_commandList->ResourceBarrier(1, &barrier);

    mesh->m_vertexBufferView.BufferLocation      = mesh->m_vertexBuffer->GetGPUVirtualAddress();
    mesh->m_vertexBufferView.StrideInBytes       = mesh->Stride;
    mesh->m_vertexBufferView.SizeInBytes         = mesh->VertexDataLength;
}

T100VOID T100DX12MeshManagerBase::CreateIndexBufferCity(T100DX12Studio* studioPtr, T100DX12Mesh* meshPtr, ComPtr<ID3D12Resource>& indexBufferUploadHeap)
{
    CD3DX12_HEAP_PROPERTIES         indexHeap(D3D12_HEAP_TYPE_DEFAULT);
    CD3DX12_RESOURCE_DESC           indexDesc       = CD3DX12_RESOURCE_DESC::Buffer(meshPtr->IndexDataLength);
    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateCommittedResource(
        &indexHeap,
        D3D12_HEAP_FLAG_NONE,
        &indexDesc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        T100NULL,
        IID_PPV_ARGS(&meshPtr->m_indexBuffer)));

    CD3DX12_HEAP_PROPERTIES         uploadHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           uploadDesc      = CD3DX12_RESOURCE_DESC::Buffer(meshPtr->IndexDataLength);
    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateCommittedResource(
        &uploadHeap,
        D3D12_HEAP_FLAG_NONE,
        &uploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        T100NULL,
        IID_PPV_ARGS(&indexBufferUploadHeap)));

    D3D12_SUBRESOURCE_DATA          indexData = {};
    indexData.pData         = meshPtr->MeshData.DATA_PTR + meshPtr->IndexDataOffset;
    indexData.RowPitch      = meshPtr->IndexDataLength;
    indexData.SlicePitch    = indexData.RowPitch;

    UpdateSubresources<1>(meshPtr->m_commandList.Get(), meshPtr->m_indexBuffer.Get(), indexBufferUploadHeap.Get(), 0, 0, 1, &indexData);
    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(meshPtr->m_indexBuffer.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_INDEX_BUFFER);
    meshPtr->m_commandList->ResourceBarrier(1, &barrier);

    meshPtr->m_indexBufferView.BufferLocation    = meshPtr->m_indexBuffer->GetGPUVirtualAddress();
    meshPtr->m_indexBufferView.Format            = meshPtr->IndexFormat;
    meshPtr->m_indexBufferView.SizeInBytes       = meshPtr->IndexDataLength;

    meshPtr->m_amount = meshPtr->IndexDataLength / 4;
}

T100VOID T100DX12MeshManagerBase::CreateTextureBufferCity(T100DX12Studio* studioPtr, T100DX12Mesh* meshPtr, ComPtr<ID3D12Resource>& textureUploadHeap)
{
    D3D12_RESOURCE_DESC             textureDesc = {};

    textureDesc.MipLevels           = meshPtr->Textures[0].MipLevels;
    textureDesc.Format              = meshPtr->Textures[0].Format;
    textureDesc.Width               = meshPtr->Textures[0].Width;
    textureDesc.Height              = meshPtr->Textures[0].Height;
    textureDesc.Flags               = D3D12_RESOURCE_FLAG_NONE;
    textureDesc.DepthOrArraySize    = 1;
    textureDesc.SampleDesc.Count    = 1;
    textureDesc.SampleDesc.Quality  = 0;
    textureDesc.Dimension           = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

    CD3DX12_HEAP_PROPERTIES         textureHeap(D3D12_HEAP_TYPE_DEFAULT);
    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateCommittedResource(
        &textureHeap,
        D3D12_HEAP_FLAG_NONE,
        &textureDesc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        T100NULL,
        IID_PPV_ARGS(&meshPtr->m_texture)));

    const UINT subresourceCount     = textureDesc.DepthOrArraySize * textureDesc.MipLevels;
    const UINT64 uploadBufferSize   = GetRequiredIntermediateSize(meshPtr->m_texture.Get(), 0, subresourceCount);

    CD3DX12_HEAP_PROPERTIES         samplerUploadHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           samplerUploadDesc         = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateCommittedResource(
        &samplerUploadHeap,
        D3D12_HEAP_FLAG_NONE,
        &samplerUploadDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        T100NULL,
        IID_PPV_ARGS(&textureUploadHeap)));

    D3D12_SUBRESOURCE_DATA          textureData = {};
    textureData.pData               = meshPtr->MeshData.DATA_PTR + meshPtr->Textures[0].Data[0].Offset;
    textureData.RowPitch            = meshPtr->Textures[0].Data[0].Pitch;
    textureData.SlicePitch          = meshPtr->Textures[0].Data[0].Size;

    UpdateSubresources(meshPtr->m_commandList.Get(), meshPtr->m_texture.Get(), textureUploadHeap.Get(), 0, 0, subresourceCount, &textureData);
    CD3DX12_RESOURCE_BARRIER        barrier         = CD3DX12_RESOURCE_BARRIER::Transition(meshPtr->m_texture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
    meshPtr->m_commandList->ResourceBarrier(1, &barrier);

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
    studioPtr->GetDevicePtr()->CreateSampler(&samplerDesc, studioPtr->GetHeapManager().GetSamplerHeap().Get(1));

    D3D12_SHADER_RESOURCE_VIEW_DESC         srvDesc = {};
    srvDesc.Shader4ComponentMapping         = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Format                          = meshPtr->Textures->Format;
    srvDesc.ViewDimension                   = D3D12_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels             = 1;

    meshPtr->m_textureHeapIndex   = studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();

    studioPtr->GetDevicePtr()->CreateShaderResourceView(meshPtr->m_texture.Get(), &srvDesc, studioPtr->GetHeapManager().GetCbvSrvHeap().Get(1));

}

T100VOID T100DX12MeshManagerBase::LoadFile(T100SHADER_FILE& file, ComPtr<ID3DBlob>& shader)
{

    CompileFile(file.REALPATH, file.ENTRY, file.TARGET, shader);

}

T100VOID T100DX12MeshManagerBase::LoadDataFile(T100WSTRING file, UINT8** data, UINT* length)
{
    ThrowIfFailed(ReadDataFromFile(file.c_str(), data, length));
}

T100VOID T100DX12MeshManagerBase::CompileFile(T100WSTRING file, T100WSTRING entrypoint, T100WSTRING target, ComPtr<ID3DBlob>& shader)
{
    T100STRING      entry;
    T100STRING      version;
    T100UINT        compileFlags        = 0;

    ComPtr<ID3DBlob>        error;

    entry       = T100Unicode::to_string8(entrypoint);
    version     = T100Unicode::to_string8(target);

    ThrowIfFailed(D3DCompileFromFile(file.c_str(), nullptr, nullptr, entry.c_str(), version.c_str(), compileFlags, 0, &shader, nullptr));

}

T100VOID T100DX12MeshManagerBase::CreateRootSignatureCity(T100DX12Studio* studioPtr, T100DX12Mesh* meshPtr)
{

    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studioPtr->GetDevicePtr()->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
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
    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&meshPtr->m_rootSignature)));

}

T100VOID T100DX12MeshManagerBase::CreatePipelineStateCity(T100DX12Studio* studioPtr, T100DX12Mesh* meshPtr)
{

    CD3DX12_RASTERIZER_DESC                 rasterizerStateDesc(D3D12_DEFAULT);
    rasterizerStateDesc.CullMode = D3D12_CULL_MODE_NONE;

    D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

    psoDesc.InputLayout                     = { meshPtr->VertexDescriptions, meshPtr->VertexDescriptionsLength };
    psoDesc.pRootSignature                  = meshPtr->m_rootSignature.Get();
    psoDesc.VS                              = CD3DX12_SHADER_BYTECODE(meshPtr->VertexData.DATA_PTR, meshPtr->VertexData.LENGTH);
    psoDesc.PS                              = CD3DX12_SHADER_BYTECODE(meshPtr->PixelData1.DATA_PTR, meshPtr->PixelData1.LENGTH);
    psoDesc.RasterizerState                 = rasterizerStateDesc;
    psoDesc.BlendState                      = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
    psoDesc.DepthStencilState               = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
    psoDesc.SampleMask                      = UINT_MAX;
    psoDesc.PrimitiveTopologyType           = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    psoDesc.NumRenderTargets                = 1;
    psoDesc.RTVFormats[0]                   = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.DSVFormat                       = DXGI_FORMAT_D32_FLOAT;
    psoDesc.SampleDesc.Count                = 1;

    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&meshPtr->m_pipelineState1)));

    psoDesc.PS = CD3DX12_SHADER_BYTECODE(meshPtr->PixelData2.DATA_PTR, meshPtr->PixelData2.LENGTH);

    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&meshPtr->m_pipelineState2)));

}
