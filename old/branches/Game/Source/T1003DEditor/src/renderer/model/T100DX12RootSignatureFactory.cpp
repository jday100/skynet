#include "T100DX12RootSignatureFactory.h"

#include "T100DX12Tools.h"
#include "T100DX12Studio.h"

T100DX12RootSignatureFactory::T100DX12RootSignatureFactory()
{
    //ctor
}

T100DX12RootSignatureFactory::~T100DX12RootSignatureFactory()
{
    //dtor
}

ComPtr<ID3D12RootSignature> T100DX12RootSignatureFactory::Create(T100DX12Studio* studioPtr, T100DX12Model* modelPtr)
{

    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studioPtr->GetDevicePtr()->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
    {
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
    }

    CD3DX12_DESCRIPTOR_RANGE1*              ranges;

    ranges  = CreateRanges(modelPtr->ShaderParametersPtr);

    CD3DX12_ROOT_PARAMETER1*                rootParameters;

    rootParameters      = CreateParameters(modelPtr->ShaderParametersPtr, ranges);

    CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC   rootSignatureDesc;
    rootSignatureDesc.Init_1_1(modelPtr->ShaderParametersPtr->Amount, rootParameters, 0, T100NULL, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studioPtr->GetDevicePtr()->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&modelPtr->m_rootSignature)));

    return modelPtr->m_rootSignature;
}

CD3DX12_DESCRIPTOR_RANGE1* T100DX12RootSignatureFactory::CreateRanges(T100ShaderParameters* parametersPtr)
{
    CD3DX12_DESCRIPTOR_RANGE1*      result      = T100NULL;

    result  = T100NEW CD3DX12_DESCRIPTOR_RANGE1[parametersPtr->Amount];

    for(T100UINT i = 0; i < parametersPtr->Amount; i++){
        CreateRange(result[i], parametersPtr->Parameters[i]);
    }

    return result;
}

CD3DX12_ROOT_PARAMETER1* T100DX12RootSignatureFactory::CreateParameters(T100ShaderParameters* parametersPtr, CD3DX12_DESCRIPTOR_RANGE1* rangesPtr)
{
    CD3DX12_ROOT_PARAMETER1*        result      = T100NULL;

    result  = T100NEW CD3DX12_ROOT_PARAMETER1[parametersPtr->Amount];

    for(T100UINT i = 0; i < parametersPtr->Amount; i++){
        CreateParameter(result[i], rangesPtr[i], parametersPtr->Parameters[i]);
    }

    return result;
}

T100VOID T100DX12RootSignatureFactory::CreateRange(CD3DX12_DESCRIPTOR_RANGE1& range, T100ShaderParameter& parameter)
{
    /*
    range.RangeType                             = ConvertType(parameter.RangeType);
    range.NumDescriptors                        = parameter.DescriptorsLength;
    range.BaseShaderRegister                    = parameter.BaseShaderRegister;
    range.RegisterSpace                         = parameter.RegisterSpace;
    range.Flags                                 = ConvertFlags(parameter.Flags);
    range.OffsetInDescriptorsFromTableStart     = parameter.OffsetInDescriptorsFromTableStart;
    */
    range.Init(ConvertType(parameter.RangeType),
               parameter.DescriptorsLength,
               parameter.BaseShaderRegister,
               parameter.RegisterSpace,
               ConvertFlags(parameter.Flags),
               parameter.OffsetInDescriptorsFromTableStart);
}

T100VOID T100DX12RootSignatureFactory::CreateParameter(CD3DX12_ROOT_PARAMETER1& result, CD3DX12_DESCRIPTOR_RANGE1& range, T100ShaderParameter& parameter)
{
    result.InitAsDescriptorTable(parameter.NumRanges, &range, Convert(parameter.Visibility));
}

D3D12_DESCRIPTOR_RANGE_TYPE T100DX12RootSignatureFactory::ConvertType(T100D3D12_DESCRIPTOR_RANGE_TYPE type)
{
    D3D12_DESCRIPTOR_RANGE_TYPE         result;

    switch(type){
    case T100D3D12_DESCRIPTOR_RANGE_TYPE_SRV:
        {
            result  = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_TYPE_UAV:
        {
            result  = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_TYPE_CBV:
        {
            result  = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER:
        {
            result  = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
        }
        break;
    }

    return result;
}

D3D12_DESCRIPTOR_RANGE_FLAGS T100DX12RootSignatureFactory::ConvertFlags(T100D3D12_DESCRIPTOR_RANGE_FLAGS flags)
{
    D3D12_DESCRIPTOR_RANGE_FLAGS        result;

    switch(flags){
    case T100D3D12_DESCRIPTOR_RANGE_FLAG_NONE:
        {
            result  = D3D12_DESCRIPTOR_RANGE_FLAG_NONE;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_VOLATILE:
        {
            result  = D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_VOLATILE;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_FLAG_DATA_VOLATILE:
        {
            result  = D3D12_DESCRIPTOR_RANGE_FLAG_DATA_VOLATILE;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE:
        {
            result  = D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC:
        {
            result  = D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC;
        }
        break;
    case T100D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_STATIC_KEEPING_BUFFER_BOUNDS_CHECKS:
        {
            result  = D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_STATIC_KEEPING_BUFFER_BOUNDS_CHECKS;
        }
        break;
    }

    return result;
}

D3D12_SHADER_VISIBILITY T100DX12RootSignatureFactory::Convert(T100D3D12_SHADER_VISIBILITY visibility)
{
    D3D12_SHADER_VISIBILITY     result;

    switch(visibility){
    case T100D3D12_SHADER_VISIBILITY_ALL:
        {
            result  = D3D12_SHADER_VISIBILITY_ALL;
        }
        break;
    case T100D3D12_SHADER_VISIBILITY_VERTEX:
        {
            result  = D3D12_SHADER_VISIBILITY_VERTEX;
        }
        break;
    case T100D3D12_SHADER_VISIBILITY_HULL:
        {
            result  = D3D12_SHADER_VISIBILITY_HULL;
        }
        break;
    case T100D3D12_SHADER_VISIBILITY_DOMAIN:
        {
            result  = D3D12_SHADER_VISIBILITY_DOMAIN;
        }
        break;
    case T100D3D12_SHADER_VISIBILITY_GEOMETRY:
        {
            result  = D3D12_SHADER_VISIBILITY_GEOMETRY;
        }
        break;
    case T100D3D12_SHADER_VISIBILITY_PIXEL:
        {
            result  = D3D12_SHADER_VISIBILITY_PIXEL;
        }
        break;
    case T100D3D12_SHADER_VISIBILITY_AMPLIFICATION:
        {
            result  = D3D12_SHADER_VISIBILITY_AMPLIFICATION;
        }
        break;
    case T100D3D12_SHADER_VISIBILITY_MESH:
        {
            result  = D3D12_SHADER_VISIBILITY_MESH;
        }
        break;
    }

    return result;
}
