#include "T100DX12ContextManagerBase.h"

#include "dx12/T100DX12Tools.h"
#include "renderer/core/T100DX12Studio.h"

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
    rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob>                        signature;
    ComPtr<ID3DBlob>                        error;

    ThrowIfFailed(D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error));
    ThrowIfFailed(studio->m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&context->m_rootSignature)));

}

T100VOID T100DX12ContextManagerBase::CreateAndCloseCommandList(
    T100DX12Studio* studio, T100DX12Frame* frame, T100DX12Context* context)
{
    ThrowIfFailed(studio->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, frame->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&context->m_commandList)));
    ThrowIfFailed(context->m_commandList->Close());
}

T100VOID T100DX12ContextManagerBase::CreateConstantBufferView(T100DX12Studio* studio, T100DX12Context* context)
{
    context->m_modelMatrices.resize(1);

    CD3DX12_HEAP_PROPERTIES         constant_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constant_desc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer));
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &constant_heap,
        D3D12_HEAP_FLAG_NONE,
        &constant_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&context->m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(context->m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&context->m_constantBuffersPtr)));

    XMStoreFloat4x4(&context->m_modelMatrices[0], XMMatrixTranslation(0, 0, 0));

    context->m_cbvSrvHeapIndex          = studio->m_heap_manager.GetCbvSrvHeap().GetTop();
    CD3DX12_CPU_DESCRIPTOR_HANDLE       handle  = studio->m_heap_manager.GetCbvSrvHeap().Get(1);

    UINT64 cbOffset = 0;

    D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
    cbvDesc.BufferLocation      = context->m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
    cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
    cbOffset                    += cbvDesc.SizeInBytes;
    studio->m_device->CreateConstantBufferView(&cbvDesc, handle);
    handle.Offset(studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);

}

T100VOID T100DX12ContextManagerBase::CreateBundle(T100DX12Studio* studio, T100DX12Context* context)
{
    context->m_modelMatrices.resize(context->Bundle.AMOUNT.X * context->Bundle.AMOUNT.Y * context->Bundle.AMOUNT.Z);

    ThrowIfFailed(studio->m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&context->m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constant_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constant_desc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * context->Bundle.AMOUNT.X * context->Bundle.AMOUNT.Y * context->Bundle.AMOUNT.Z);
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &constant_heap,
        D3D12_HEAP_FLAG_NONE,
        &constant_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&context->m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(context->m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&context->m_constantBuffersPtr)));

    SetBundlePositions(context);
}

T100VOID T100DX12ContextManagerBase::ConvertModel(T100DX12Model* model, T100DX12Context* context)
{
    context->Type                   = model->Type;

    context->RenderType             = model->RenderType;
    context->MotionType             = model->MotionType;

    context->m_position             = model->m_position;
    context->m_rotation             = model->m_rotation;
    context->m_scaling              = model->m_scaling;

    context->m_visible              = model->m_visible;

    context->m_rootSignature        = model->m_rootSignature;

    context->m_numIndices           = model->m_numIndices;
    context->m_pipelineState        = model->m_pipelineState;
    context->m_pipelineState1       = model->m_pipelineState1;
    context->m_pipelineState2       = model->m_pipelineState2;
    context->m_vertexBufferViewPtr  = &model->m_vertexBufferView;
    context->m_indexBufferViewPtr   = &model->m_indexBufferView;

    context->m_samplerHeapIndex     = model->m_samplerHeapIndex;
    context->m_textureHeapIndex     = model->m_textureHeapIndex;

    context->Bundle                 = model->Bundle;

    memcpy(&context->Bundle, &model->Bundle, sizeof(T100BUNDLE));
}

T100VOID T100DX12ContextManagerBase::SetBundlePositions(T100DX12Context* context)
{
    UINT    m = 0;
    FLOAT   x = 0;
    for(UINT i = 0; i < context->Bundle.AMOUNT.X; i++)
    {
        x   += context->Bundle.SPACING.X;
        FLOAT   y = 0;
        for(UINT j = 0; j < context->Bundle.AMOUNT.Y; j++)
        {
            y   += context->Bundle.SPACING.Y;
            FLOAT   z = 0;
            for(UINT k = 0; k < context->Bundle.AMOUNT.Z; k++)
            {
                z   += context->Bundle.SPACING.Z;
                XMStoreFloat4x4(&context->m_modelMatrices[m++], XMMatrixTranslation(x, y, z));
            }
        }
    }
}

T100VOID T100DX12ContextManagerBase::CreateBundle1(T100DX12Studio* studio, T100DX12Context* context)
{
    context->m_modelMatrices.resize(context->Bundle.AMOUNT.X * context->Bundle.AMOUNT.Y * context->Bundle.AMOUNT.Z);

    ThrowIfFailed(studio->m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&context->m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constant_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constant_desc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * context->Bundle.AMOUNT.X * context->Bundle.AMOUNT.Y * context->Bundle.AMOUNT.Z);
    ThrowIfFailed(studio->m_device->CreateCommittedResource(
        &constant_heap,
        D3D12_HEAP_FLAG_NONE,
        &constant_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&context->m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(context->m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&context->m_constantBuffersPtr)));

    UINT    m = 0;
    FLOAT   x = 0;
    for(UINT i = 0; i < context->Bundle.AMOUNT.X; i++)
    {
        x   += context->Bundle.SPACING.X;
        FLOAT   y = 0;
        for(UINT j = 0; j < context->Bundle.AMOUNT.Y; j++)
        {
            y   += context->Bundle.SPACING.Y;
            FLOAT   z = 0;
            for(UINT k = 0; k < context->Bundle.AMOUNT.Z; k++)
            {
                z   += context->Bundle.SPACING.Z;
                XMStoreFloat4x4(&context->m_modelMatrices[m++], XMMatrixTranslation(x, y, z));
            }
        }
    }

    ThrowIfFailed(studio->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, context->m_bundleAllocator.Get(), context->m_pipelineState1.Get(), IID_PPV_ARGS(&context->m_bundleCommandList)));


    context->m_bundleCommandList->SetGraphicsRootSignature(context->m_rootSignature.Get());

    ID3D12DescriptorHeap*       ppHeaps[] = {
        studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heap.Get(),
        studio->m_heap_manager.GetSamplerHeap().m_heap.m_heap.Get() };
    context->m_bundleCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    context->m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
    //context->m_bundleCommandList->IASetIndexBuffer(context->m_indexBufferView);
    context->m_bundleCommandList->IASetVertexBuffers(0, 1, context->m_vertexBufferViewPtr);

    CD3DX12_GPU_DESCRIPTOR_HANDLE handle(
        studio->m_heap_manager.GetCbvSrvHeap().GetGPUStart(), context->m_textureHeapIndex,
        studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);

    //context->m_bundleCommandList->SetGraphicsRootDescriptorTable(0, handle);
    //context->m_bundleCommandList->SetGraphicsRootDescriptorTable(1, studio->m_heap_manager.GetSamplerHeap().GetGPUStart());

    UINT frameResourceDescriptorOffset = context->m_cbvSrvHeapIndex;
    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(
        studio->m_heap_manager.GetCbvSrvHeap().GetGPUStart(), frameResourceDescriptorOffset,
        studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);

    BOOL        usePso1 = TRUE;

    T100DX12Context& item = *context;
    for (UINT i = 0; i < context->Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < context->Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < context->Bundle.AMOUNT.Z; k++)
            {
                context->m_bundleCommandList->SetPipelineState(context->m_pipelineState.Get());
                context->m_bundleCommandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle);
                cbvSrvHandle.Offset(studio->m_heap_manager.GetCbvSrvHeap().m_heap.m_heapDescriptorSize);

                context->m_bundleCommandList->DrawIndexedInstanced(context->m_numIndices, 1, 0, 0, 0);
            }
        }
    }

    ThrowIfFailed(context->m_bundleCommandList->Close());
}
