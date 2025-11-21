#include "data/T100DX12Context.h"

#include "T100DX12Common.h"
#include "dx12/T100DX12Tools.h"
#include "data/T100DX12Frame.h"
#include "core/T100DX12Studio.h"
#include "math/T100DX12MathTools.h"

T100DX12Context::T100DX12Context()
{
    //ctor
    init();
}

T100DX12Context::~T100DX12Context()
{
    //dtor
    uninit();
}

T100VOID T100DX12Context::init()
{

}

T100VOID T100DX12Context::uninit()
{
    m_cbvUploadHeap->Unmap(0, nullptr);
    m_constantBuffersPtr = nullptr;
}

T100VOID T100DX12Context::SetStudioPtr(T100DX12Studio* studioPtr)
{
    m_studioPtr     = studioPtr;
}

T100DX12Studio* T100DX12Context::GetStudioPtr()
{
    return m_studioPtr;
}

T100VOID T100DX12Context::SetFramePtr(T100DX12Frame* framePtr)
{
    m_framePtr  = framePtr;
}

T100DX12Frame* T100DX12Context::GetFramePtr()
{
    return m_framePtr;
}

T100VOID T100DX12Context::SetPosition(XMFLOAT3& source)
{
    if(RenderType == T1003D_RENDER_SCREEN){
        T100UINT        width;
        T100UINT        height;

        width   = m_studioPtr->GetWidth();
        height  = m_studioPtr->GetHeight();
        ScreenToView(source, width, height, m_position);
    }else{
        m_position  = source;
    }
}

T100VOID T100DX12Context::SetPosition(T100Vector3f& value)
{
    if(RenderType == T1003D_RENDER_SCREEN){
        T100Vector3f    position;
        T100UINT        width;
        T100UINT        height;

        width   = m_studioPtr->GetWidth();
        height  = m_studioPtr->GetHeight();

        ScreenToView(value, width, height, position);
        MemoryCopy(&m_position, &position.FLOAT3, sizeof(XMFLOAT3));
    }else{
        MemoryCopy(&m_position, &value.FLOAT3, sizeof(XMFLOAT3));
    }
}

T100VOID T100DX12Context::Clear()
{
    T100DX12Event       event;

    event.Type              = T100DX12_CONTEXT_EVENT_REMOVE;
    event.VoidValue         = this;

    m_events.push(event);
}

T100VOID T100DX12Context::Events()
{
    while(!m_events.empty()){
        T100DX12Event&  event = m_events.front();
        RunEvent(event);
        m_events.pop();
    }
}

T100VOID T100DX12Context::RunEvent(T100DX12Event& event)
{
    //DEBUGPRINT("Location: %f %f %f", event.Value.x, event.Value.y, event.Value.z);

    switch(event.Type){
    case T100DX12_CONTEXT_EVENT_POSITION:
        {
            SetPosition(event.Float3Value);
        }
        break;
    case T100DX12_CONTEXT_EVENT_ROTATION:
        {
            m_rotation  = event.Float3Value;
        }
        break;
    case T100DX12_CONTEXT_EVENT_SCALING:
        {
            m_scaling   = event.Float3Value;
        }
        break;
    case T100DX12_CONTEXT_EVENT_VISIBLE:
        {
            m_visible   = event.BoolValue;
        }
        break;
    case T100DX12_CONTEXT_EVENT_REMOVE:
        {
            m_framePtr->Remove((T100DX12Context*)event.VoidValue);
        }
        break;
    }
}

T100VOID T100DX12Context::AppendEvent(T100UINT type, T100Vector3f& value)
{
    T100DX12Event       event;

    event.Type              = type;
    MemoryCopy(&event.Float3Value, &value.FLOAT3, sizeof(T100FLOAT) * 3);

    m_events.push(event);
}

T100VOID T100DX12Context::AppendEvent(T100UINT type, T100BOOL value)
{
    T100DX12Event       event;

    event.Type              = type;
    event.BoolValue         = value;

    m_events.push(event);
}

T100VOID T100DX12Context::CreateBundle()
{
    T100UINT    length  = Bundle.AMOUNT.X * Bundle.AMOUNT.Y * Bundle.AMOUNT.Z;

    m_modelMatrices.resize(length);

    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constantHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constantDesc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * length);
    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
        &constantHeap,
        D3D12_HEAP_FLAG_NONE,
        &constantDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_constantBuffersPtr)));

    SetBundlePositions();

    m_cbvSrvHeapIndex          = m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();
    CD3DX12_CPU_DESCRIPTOR_HANDLE       cbvSrvHandle  = m_studioPtr->GetHeapManager().GetCbvSrvHeap().Get(length);

    UINT64 cbOffset = 0;
    for (UINT j = 0; j < Bundle.AMOUNT.X; j++)
    {
        for (UINT k = 0; k < Bundle.AMOUNT.Y; k++)
        {
            for (UINT l = 0; l < Bundle.AMOUNT.Z; l++)
            {
                D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
                cbvDesc.BufferLocation      = m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
                cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
                cbOffset                    += cbvDesc.SizeInBytes;
                m_studioPtr->GetDevicePtr()->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
                cbvSrvHandle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
            }
        }
    }

    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_bundleCommandList)));

    m_bundleCommandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap*       ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap() };
        //m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap() };
    m_bundleCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    //m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);

    DrawBundle();

    m_bundleCommandList->IASetIndexBuffer(m_indexBufferViewPtr);
    m_bundleCommandList->IASetVertexBuffers(0, 1, m_vertexBufferViewPtr);

    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle2(
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetGPUStart(), m_cbvSrvHeapIndex,
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

    BOOL        usePso1 = TRUE;
    for (UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                m_bundleCommandList->SetPipelineState(usePso1 ? m_pipelineState.Get() : m_pipelineState.Get());
                usePso1 = !usePso1;

                m_bundleCommandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle2);
                cbvSrvHandle2.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

                m_bundleCommandList->DrawIndexedInstanced(m_amount, 1, 0, 0, 0);
            }
        }
    }

    ThrowIfFailed(m_bundleCommandList->Close());
}

T100VOID T100DX12Context::CreateCityBundle()
{
    T100UINT    length  = Bundle.AMOUNT.X * Bundle.AMOUNT.Y * Bundle.AMOUNT.Z;

    m_modelMatrices.resize(length);

    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator)));

    CD3DX12_HEAP_PROPERTIES         constantHeap(D3D12_HEAP_TYPE_UPLOAD);
    CD3DX12_RESOURCE_DESC           constantDesc           = CD3DX12_RESOURCE_DESC::Buffer(sizeof(SceneConstantBuffer) * length);
    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommittedResource(
        &constantHeap,
        D3D12_HEAP_FLAG_NONE,
        &constantDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&m_cbvUploadHeap)));

    CD3DX12_RANGE readRange(0, 0);
    ThrowIfFailed(m_cbvUploadHeap->Map(0, &readRange, reinterpret_cast<void**>(&m_constantBuffersPtr)));

    SetBundlePositions();

    m_cbvSrvHeapIndex          = m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetTop();
    CD3DX12_CPU_DESCRIPTOR_HANDLE       cbvSrvHandle  = m_studioPtr->GetHeapManager().GetCbvSrvHeap().Get(length);

    UINT64 cbOffset = 0;
    for (UINT j = 0; j < Bundle.AMOUNT.X; j++)
    {
        for (UINT k = 0; k < Bundle.AMOUNT.Y; k++)
        {
            for (UINT l = 0; l < Bundle.AMOUNT.Z; l++)
            {
                D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
                cbvDesc.BufferLocation      = m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
                cbvDesc.SizeInBytes         = sizeof(SceneConstantBuffer);
                cbOffset                    += cbvDesc.SizeInBytes;
                m_studioPtr->GetDevicePtr()->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
                cbvSrvHandle.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());
            }
        }
    }

    ThrowIfFailed(m_studioPtr->GetDevicePtr()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_bundleCommandList)));

    m_bundleCommandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap*       ppHeaps[] = {
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetHeap(),
        m_studioPtr->GetHeapManager().GetSamplerHeap().GetHeap() };
    m_bundleCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
    m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    m_bundleCommandList->IASetIndexBuffer(m_indexBufferViewPtr);
    m_bundleCommandList->IASetVertexBuffers(0, 1, m_vertexBufferViewPtr);
    m_bundleCommandList->SetGraphicsRootDescriptorTable(0, m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetGPUStart());
    m_bundleCommandList->SetGraphicsRootDescriptorTable(1, m_studioPtr->GetHeapManager().GetSamplerHeap().GetGPUStart());

    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle2(
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetGPUStart(), m_cbvSrvHeapIndex,
        m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

    BOOL        usePso1 = TRUE;
    for (UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                m_bundleCommandList->SetPipelineState(usePso1 ? m_pipelineState1.Get() : m_pipelineState2.Get());
                usePso1 = !usePso1;

                m_bundleCommandList->SetGraphicsRootDescriptorTable(0, cbvSrvHandle2);
                cbvSrvHandle2.Offset(m_studioPtr->GetHeapManager().GetCbvSrvHeap().GetSize());

                m_bundleCommandList->DrawIndexedInstanced(m_amount, 1, 0, 0, 0);
            }
        }
    }

    ThrowIfFailed(m_bundleCommandList->Close());
}

T100VOID T100DX12Context::SetBundlePositions()
{
    UINT    m = 0;
    FLOAT   x = 0;
    for(UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        FLOAT   y = 0;
        for(UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            FLOAT   z = 0;
            for(UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                XMStoreFloat4x4(&m_modelMatrices[m++], XMMatrixTranslation(x, y, z));
                z   += Bundle.SPACING.Z;
            }
            y   += Bundle.SPACING.Y;
        }
        x   += Bundle.SPACING.X;
    }
}

XMMATRIX T100DX12Context::BuildWorld()
{
    XMMATRIX    result;
    XMMATRIX    position;
    XMMATRIX    rotationX;
    XMMATRIX    rotationY;
    XMMATRIX    rotationZ;
    XMMATRIX    scaling;

    position    = XMMatrixTranslation(m_position.x, m_position.y, m_position.z);
    rotationX   = XMMatrixRotationX(m_rotation.x);
    rotationY   = XMMatrixRotationY(m_rotation.y);
    rotationZ   = XMMatrixRotationZ(m_rotation.z);
    scaling     = XMMatrixScaling(m_scaling.x, m_scaling.y, m_scaling.z);

    result      = scaling * rotationX * rotationY * rotationZ * position;

    return result;
}


T100VOID T100DX12Context::UpdateBundle()
{
    XMMATRIX        item;
    XMMATRIX        model;
    XMFLOAT4X4      mvp;
    UINT            m   = 0;

    item    = BuildWorld();

    for (UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                XMFLOAT4X4  value;

                value = m_modelMatrices[m];

                model = XMLoadFloat4x4(&value);

                XMStoreFloat4x4(&mvp, XMMatrixTranspose(item * model));

                memcpy(&m_constantBuffersPtr[m], &mvp, sizeof(mvp));

                m++;
            }
        }
    }
}

T100VOID T100DX12Context::UpdateBundle(XMMATRIX& projection, XMMATRIX& view)
{
    XMMATRIX        model;
    XMFLOAT4X4      mvp;
    UINT            m   = 0;

    XMMATRIX        item;
    XMMATRIX        temp;

    item    = BuildWorld();

    for (UINT i = 0; i < Bundle.AMOUNT.X; i++)
    {
        for (UINT j = 0; j < Bundle.AMOUNT.Y; j++)
        {
            for (UINT k = 0; k < Bundle.AMOUNT.Z; k++)
            {
                XMFLOAT4X4  value;

                value = m_modelMatrices[m];

                model = XMLoadFloat4x4(&value);

                //temp    = item * model;
                temp    = model;

                XMStoreFloat4x4(&mvp, XMMatrixTranspose(temp * view * projection));

                memcpy(&m_constantBuffersPtr[m], &mvp, sizeof(mvp));

                m++;
            }
        }
    }
}

T100VOID T100DX12Context::DrawBundle()
{
    switch(Type){
    case T100ENTITY_DOT:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_POINTLIST);
        }
        break;
    case T100ENTITY_LINE:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
        }
        break;
    case T100ENTITY_TRIANGLE:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        }
        break;
    case T100ENTITY_PLANE:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        }
        break;
    case T100ENTITY_CITY:
        {
            m_bundleCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        }
        break;
    }
}
