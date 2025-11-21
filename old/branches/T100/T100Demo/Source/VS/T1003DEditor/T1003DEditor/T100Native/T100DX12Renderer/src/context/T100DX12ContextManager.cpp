#include "context/T100DX12ContextManager.h"

#include "dx12/T100DX12Tools.h"
#include "context/T100DX12AllContexts.h"
#include "core/T100DX12Studio.h"

T100DX12ContextManager::T100DX12ContextManager(T100DX12Studio* studio) :
    T100DX12ContextManagerBase(),
    m_studioPtr(studio)
{
    //ctor
}

T100DX12ContextManager::~T100DX12ContextManager()
{
    //dtor
}

T100DX12Context* T100DX12ContextManager::Convert(T100DX12Frame* framePtr, T100DX12Mesh* meshPtr)
{
    T100DX12Context*        resultPtr       = T100NULL;

    if(meshPtr->Type == T100ENTITY_CITY){
        return ConvertCity(framePtr, meshPtr);
    }

    switch(meshPtr->RenderType){
    case T1003D_RENDER_SCREEN:
        {
            resultPtr   = ConvertScreen(framePtr, meshPtr);
        }
        break;
    case T1003D_RENDER_SPACE:
        {
            resultPtr   = ConvertSpace(framePtr, meshPtr);
        }
        break;
    }

    return resultPtr;
}

T100VOID T100DX12ContextManager::CreateConstantBuffers(T100DX12Context* contextPtr)
{
    if(contextPtr->Bundle.USED){
        if(contextPtr->Type == T100ENTITY_CITY){
            contextPtr->CreateCityBundle();
        }else{
            contextPtr->CreateBundle();
        }
    }else{
        CreateConstantBuffer(contextPtr);
    }
}

T100VOID T100DX12ContextManager::CreateConstantBuffer(T100DX12Context* contextPtr)
{
    contextPtr->m_modelMatrices.resize(1);

    CD3DX12_HEAP_PROPERTIES         constant_heap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constant_desc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer));
    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
        &constant_heap,
        D3D12_HEAP_FLAG_NONE,
        &constant_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&contextPtr->m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(contextPtr->m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&contextPtr->m_constantBuffersPtr)));

    XMStoreFloat4x4(&contextPtr->m_modelMatrices[0], XMMatrixTranslation(0, 0, 0));

    contextPtr->m_cbvSrvHeapIndex          = m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();
    CD3DX12_CPU_DESCRIPTOR_HANDLE       handle  = m_studioPtr->GetHeapManager().GetCbvSrvHeap().Get(1);

    UINT64 cbOffset = 0;

    D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
    cbvDesc.BufferLocation      = contextPtr->m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
    cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
    cbOffset                    += cbvDesc.SizeInBytes;
    m_studioPtr->GetDevicePtr()->CreateConstantBufferView(&cbvDesc, handle);
    handle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

}

T100DX12Context* T100DX12ContextManager::ConvertSpace(T100DX12Frame* framePtr, T100DX12Mesh* meshPtr)
{
    T100DX12Context*        resultPtr       = T100NULL;

    resultPtr   = T100NEW T100DX12MeshContext();
    resultPtr->SetStudioPtr(m_studioPtr);
    resultPtr->SetFramePtr(framePtr);

    MemoryCopy(&resultPtr->Bundle, &meshPtr->Bundle, sizeof(T100BUNDLE));
    MemoryCopy(&resultPtr->m_position, &meshPtr->GetPosition().FLOAT3, sizeof(XMFLOAT3));
    MemoryCopy(&resultPtr->m_rotation, &meshPtr->GetRotation().FLOAT3, sizeof(XMFLOAT3));
    MemoryCopy(&resultPtr->m_scaling, &meshPtr->GetScaling().FLOAT3, sizeof(XMFLOAT3));

    resultPtr->m_visible                = meshPtr->IsVisible();
    resultPtr->m_amount                 = meshPtr->GetAmount();

    resultPtr->Type                     = meshPtr->Type;
    resultPtr->RenderType               = meshPtr->RenderType;
    resultPtr->MotionType               = meshPtr->MotionType;

    CreateAndCloseCommandList(m_studioPtr, framePtr, resultPtr);

    resultPtr->m_rootSignature          = meshPtr->m_rootSignature;
    resultPtr->m_pipelineState          = meshPtr->m_pipelineState;
    resultPtr->m_vertexBufferViewPtr    = &meshPtr->m_vertexBufferView;

    CreateConstantBuffers(resultPtr);

    return resultPtr;
}

T100DX12Context* T100DX12ContextManager::ConvertScreen(T100DX12Frame* framePtr, T100DX12Mesh* meshPtr)
{
    T100DX12Context*        resultPtr       = T100NULL;

    resultPtr   = T100NEW T100DX12ScreenContext();
    resultPtr->SetStudioPtr(m_studioPtr);
    resultPtr->SetFramePtr(framePtr);

    MemoryCopy(&resultPtr->Bundle, &meshPtr->Bundle, sizeof(T100BUNDLE));
    //MemoryCopy(&resultPtr->m_position, &meshPtr->GetPosition().FLOAT3, sizeof(XMFLOAT3));
    MemoryCopy(&resultPtr->m_rotation, &meshPtr->GetRotation().FLOAT3, sizeof(XMFLOAT3));
    MemoryCopy(&resultPtr->m_scaling, &meshPtr->GetScaling().FLOAT3, sizeof(XMFLOAT3));

    resultPtr->m_visible                = meshPtr->IsVisible();
    resultPtr->m_amount                 = meshPtr->GetAmount();

    resultPtr->Type                     = meshPtr->Type;
    resultPtr->RenderType               = meshPtr->RenderType;
    resultPtr->MotionType               = meshPtr->MotionType;

    resultPtr->SetPosition(meshPtr->GetPosition());

    CreateAndCloseCommandList(m_studioPtr, framePtr, resultPtr);

    resultPtr->m_rootSignature          = meshPtr->m_rootSignature;
    resultPtr->m_pipelineState          = meshPtr->m_pipelineState;
    resultPtr->m_vertexBufferViewPtr    = &meshPtr->m_vertexBufferView;
    //resultPtr->m_indexBufferViewPtr     = &meshPtr->m_indexBufferView;

    CreateConstantBuffers(resultPtr);

    return resultPtr;
}

T100DX12Context* T100DX12ContextManager::ConvertCity(T100DX12Frame* framePtr, T100DX12Mesh* meshPtr)
{
    T100DX12Context*        resultPtr       = T100NULL;

    resultPtr   = T100NEW T100DX12MeshContext();
    resultPtr->SetStudioPtr(m_studioPtr);
    resultPtr->SetFramePtr(framePtr);

    MemoryCopy(&resultPtr->Bundle, &meshPtr->Bundle, sizeof(T100BUNDLE));
    MemoryCopy(&resultPtr->m_position, &meshPtr->GetPosition().FLOAT3, sizeof(XMFLOAT3));
    MemoryCopy(&resultPtr->m_rotation, &meshPtr->GetRotation().FLOAT3, sizeof(XMFLOAT3));
    MemoryCopy(&resultPtr->m_scaling, &meshPtr->GetScaling().FLOAT3, sizeof(XMFLOAT3));

    resultPtr->m_visible                = meshPtr->IsVisible();
    resultPtr->m_amount                 = meshPtr->GetAmount();

    resultPtr->Type                     = meshPtr->Type;
    resultPtr->RenderType               = meshPtr->RenderType;
    resultPtr->MotionType               = meshPtr->MotionType;

    CreateAndCloseCommandList(m_studioPtr, framePtr, resultPtr);

    resultPtr->m_rootSignature          = meshPtr->m_rootSignature;
    resultPtr->m_pipelineState1         = meshPtr->m_pipelineState1;
    resultPtr->m_pipelineState2         = meshPtr->m_pipelineState2;
    resultPtr->m_vertexBufferViewPtr    = &meshPtr->m_vertexBufferView;
    resultPtr->m_indexBufferViewPtr     = &meshPtr->m_indexBufferView;

    CreateConstantBuffers(resultPtr);

    return resultPtr;
}
