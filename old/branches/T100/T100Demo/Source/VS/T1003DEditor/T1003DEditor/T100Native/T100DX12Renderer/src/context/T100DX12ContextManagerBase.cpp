#include "context/T100DX12ContextManagerBase.h"

#include "dx12/T100DX12Tools.h"
#include "core/T100DX12Studio.h"

T100DX12ContextManagerBase::T100DX12ContextManagerBase()
{
    //ctor
}

T100DX12ContextManagerBase::~T100DX12ContextManagerBase()
{
    //dtor
}

T100VOID T100DX12ContextManagerBase::CreateRootSignature(T100DX12Studio* studio, T100DX12Context* context)
{

    D3D12_FEATURE_DATA_ROOT_SIGNATURE       featureData         = {};

    featureData.HighestVersion              = D3D_ROOT_SIGNATURE_VERSION_1_1;

    if(FAILED(studio->GetDevicePtr()->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
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
    ThrowIfFailed(studio->GetDevicePtr()->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&context->m_rootSignature)));

}

T100VOID T100DX12ContextManagerBase::CreateAndCloseCommandList(
    T100DX12Studio* studio, T100DX12Frame* frame, T100DX12Context* context)
{
    ThrowIfFailed(studio->GetDevicePtr()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, frame->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&context->m_commandList)));
    ThrowIfFailed(context->m_commandList->Close());
}
