#include "T100DX12Bundles.h"

#include "occcity.h"
#include "T100DX12Tools.h"

T100DX12Bundles::T100DX12Bundles()
    :T100DX12Base()
{
    //ctor
}

T100DX12Bundles::~T100DX12Bundles()
{
    //dtor
}

T100VOID T100DX12Bundles::Append(T100Entity* entity)
{
    LoadEntity(entity);
    m_entityManager.Append(entity);
}

T100VOID T100DX12Bundles::LoadEntity(T100Entity* entity)
{
    T100WSTRING     vertexFilename      = L"shader_mesh_simple_vert.cso";
    T100WSTRING     pixelFilename1      = L"shader_mesh_simple_pixel.cso";
    T100WSTRING     pixelFilename2      = L"shader_mesh_alt_pixel.cso";

    UINT8*          pVertexShaderData;
    UINT8*          pPixelShaderData1;
    UINT8*          pPixelShaderData2;
    UINT            vertexShaderDataLength;
    UINT            pixelShaderDataLength1;
    UINT            pixelShaderDataLength2;

    CreateRootSignature();

    LoadShader(vertexFilename, &pVertexShaderData, vertexShaderDataLength);
    LoadShader(pixelFilename1, &pPixelShaderData1, pixelShaderDataLength1);
    LoadShader(pixelFilename2, &pPixelShaderData2, pixelShaderDataLength2);

    CreatePipelineState(
                        pVertexShaderData, vertexShaderDataLength,
                        pPixelShaderData1, pixelShaderDataLength1,
                        pPixelShaderData2, pixelShaderDataLength2
                        );

    delete pVertexShaderData;
    delete pPixelShaderData1;
    delete pPixelShaderData2;

    CreateCommandList();
    CreateRenderTargetView();

    LoadMesh();

    CreateDepthStencilView();

    ExecuteCommandList();

    CreateFence();

    CreateFrameResources();

}


T100VOID T100DX12Bundles::CreateRootSignature()
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

T100VOID T100DX12Bundles::LoadShader(T100WSTRING filename, UINT8** ppShaderData, UINT& shaderLength)
{
    ThrowIfFailed(ReadDataFromFile(
                                   GetAssetFullPath(filename.c_str()).c_str(),
                                   ppShaderData,
                                   &shaderLength));
}



T100VOID T100DX12Bundles::CreatePipelineState(
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

    psoDesc.InputLayout             = {SampleAssets::StandardVertexDescription, SampleAssets::StandardVertexDescriptionNumElements};
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

}









