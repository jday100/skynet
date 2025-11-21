#include "T100DX12PipelineStateFactory.h"

#include "T100Unicode.h"
#include "T100DX12Tools.h"
#include "T100DX12Model.h"
#include "T100DX12Studio.h"

T100DX12PipelineStateFactory::T100DX12PipelineStateFactory()
{
    //ctor
}

T100DX12PipelineStateFactory::~T100DX12PipelineStateFactory()
{
    //dtor
}

ComPtr<ID3D12PipelineState> T100DX12PipelineStateFactory::Create(T100DX12Studio* studioPtr, T100DX12Model* modelPtr)
{
    D3D12_INPUT_ELEMENT_DESC*       descs;

    descs   = CreateDescriptions(modelPtr);

    D3D12_GRAPHICS_PIPELINE_STATE_DESC      psoDesc = {};

    T100DX12Model&  value = *modelPtr;

    psoDesc.InputLayout                     = { descs, modelPtr->VertexDescriptionsPtr->Amount };
    psoDesc.pRootSignature                  = modelPtr->m_rootSignature.Get();
    psoDesc.VS                              = CD3DX12_SHADER_BYTECODE(modelPtr->vertexShader.Get());
    psoDesc.PS                              = CD3DX12_SHADER_BYTECODE(modelPtr->pixelShader.Get());
    psoDesc.RasterizerState                 = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
    psoDesc.BlendState                      = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
    psoDesc.DepthStencilState.DepthEnable   = FALSE;
    psoDesc.DepthStencilState.StencilEnable = FALSE;
    psoDesc.SampleMask                      = UINT_MAX;
    psoDesc.PrimitiveTopologyType           = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    psoDesc.NumRenderTargets                = 1;
    psoDesc.RTVFormats[0]                   = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.SampleDesc.Count                = 1;

    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&modelPtr->m_pipelineState)));
}

D3D12_INPUT_ELEMENT_DESC* T100DX12PipelineStateFactory::CreateDescriptions(T100DX12Model* modelPtr)
{
    D3D12_INPUT_ELEMENT_DESC*       result          = T100NULL;

    result      = T100NEW D3D12_INPUT_ELEMENT_DESC[modelPtr->VertexDescriptionsPtr->Amount];

    for(T100UINT i = 0; i < modelPtr->VertexDescriptionsPtr->Amount; i++){
        CreateElement(result[i], modelPtr->VertexDescriptionsPtr->Descs[i]);
    }

    return result;
}

T100VOID T100DX12PipelineStateFactory::CreateElement(D3D12_INPUT_ELEMENT_DESC& target, T100D3D12_INPUT_ELEMENT_DESC& source)
{
    T100WSTRING     name            = source.SemanticName;
    target.SemanticName             = T100Unicode::to_string8(name).c_str();
    target.SemanticIndex            = source.SemanticIndex;
    target.Format                   = ConvertFormat(source.Format);
    target.InputSlot                = source.InputSlot;
    target.AlignedByteOffset        = source.AlignedByteOffset;
    target.InputSlotClass           = Convert(source.InputSlotClass);
    target.InstanceDataStepRate     = source.InstanceDataStepRate;
}

DXGI_FORMAT T100DX12PipelineStateFactory::ConvertFormat(T100DXGI_FORMAT format)
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

D3D12_INPUT_CLASSIFICATION T100DX12PipelineStateFactory::Convert(T100D3D12_INPUT_CLASSIFICATION value)
{
    D3D12_INPUT_CLASSIFICATION      result;

    switch(value){
    case T100D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA:
        {
            result  = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        }
        break;
    case T100D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA:
        {
            result  = D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA;
        }
        break;
    }

    return result;
}
