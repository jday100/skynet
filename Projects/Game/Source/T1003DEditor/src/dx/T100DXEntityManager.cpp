#include "T100DXEntityManager.h"

#include "T100DXEntity.h"

T100DXEntityManager::T100DXEntityManager(T100DXEntity* dx12)
    :m_dx12(dx12),
    m_empty(T100TRUE)
{
    //ctor
}

T100DXEntityManager::~T100DXEntityManager()
{
    //dtor
}

T100BOOL T100DXEntityManager::Empty()
{
    return m_empty;
}

T100VOID T100DXEntityManager::Append(T100Entity* entity)
{
    T100City*       city        = T100NULL;

    city    = dynamic_cast<T100City*>(entity);

    LoadCity(city);

    m_entities.push_back(entity);
    m_empty = T100FALSE;
}

T100VOID T100DXEntityManager::LoadCity(T100City* city)
{
    ComPtr<ID3D12Resource>              vertexBufferUploadHeap;
    ComPtr<ID3D12Resource>              indexBufferUploadHeap;
    ComPtr<ID3D12Resource>              textureUploadHeap;

    if(m_empty)
    {
        m_dx12->CreateDsvHeap();
        m_dx12->CreateCbvHeap(city->CityRowCount, city->CityColumnCount);
        m_dx12->CreateSamplerHeap();

        m_dx12->CreateRootSignature();
    }

    {
        UINT8*                  pVertexShaderData;
        UINT8*                  pPixelShaderData1;
        UINT8*                  pPixelShaderData2;
        UINT                    vertexShaderDataLength;
        UINT                    pixelShaderDataLength1;
        UINT                    pixelShaderDataLength2;

        m_dx12->LoadShaderFile(
                               L"shader_mesh_simple_vert.cso",
                               &pVertexShaderData,
                               vertexShaderDataLength
                               );
        m_dx12->LoadShaderFile(
                               L"shader_mesh_simple_pixel.cso",
                               &pPixelShaderData1,
                               pixelShaderDataLength1
                               );
        m_dx12->LoadShaderFile(
                               L"shader_mesh_alt_pixel.cso",
                               &pPixelShaderData2,
                               pixelShaderDataLength2
                               );

        m_dx12->CreatePipelineState(
                                    city->StandardVertexDescription,
                                    city->StandardVertexDescriptionNumElements,
                                    pVertexShaderData,
                                    vertexShaderDataLength,
                                    pPixelShaderData1,
                                    pixelShaderDataLength1,
                                    pPixelShaderData2,
                                    pixelShaderDataLength2
                                    );

        delete pVertexShaderData;
        delete pPixelShaderData1;
        delete pPixelShaderData2;
    }
    if(m_empty)
    {
        m_dx12->CreateCommandList();
        m_dx12->CreateRenderTargetView();
    }

    UINT8*              pMeshData;
    UINT                meshDataLength;
    UINT                subresourceCount;
    UINT64              uploadBufferSize;

    m_dx12->LoadMeshFile(L"occcity.bin", &pMeshData, meshDataLength);
    m_dx12->CreateVertexBuffer(
                               city->VertexDataSize, city->VertexDataOffset, city->StandardVertexStride,
                               vertexBufferUploadHeap, pMeshData, meshDataLength);
    m_dx12->CreateIndexBuffer(
                              city->IndexDataSize, city->IndexDataOffset,
                              city->StandardIndexFormat,
                              indexBufferUploadHeap, pMeshData, meshDataLength);
    m_dx12->CreateTexture(city->Textures, subresourceCount, uploadBufferSize);
    m_dx12->CreateSampler(city->Textures, textureUploadHeap, pMeshData, meshDataLength, subresourceCount, uploadBufferSize);
    m_dx12->CreateTextureSRV(city->Textures);
    delete pMeshData;

    if(m_empty)
    {
        m_dx12->CreateDepthStencilView();
        m_dx12->ExecuteCommandList();
        m_dx12->CreateFence();
        m_dx12->CreateFrameResources(city->CityRowCount, city->CityColumnCount);
    }
}

T100VOID T100DXEntity::CreateFrameResources(UINT row, UINT column)
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE           cbvSrvHandle(
                                                         m_cbvSrvHeap->GetCPUDescriptorHandleForHeapStart(),
                                                         1,
                                                         m_cbvSrvDescriptorSize);
    for(UINT i = 0; i < m_frameCount; i++)
    {
        T100DXFrameResource* pFrameResource = new T100DXFrameResource(m_device.Get(), row, column);

        UINT64      cbOffset = 0;
        for(UINT j = 0; j < row; j++)
        {
            for(UINT k = 0; k < column; k++)
            {
                D3D12_CONSTANT_BUFFER_VIEW_DESC         cbvDesc = {};
                cbvDesc.BufferLocation      = pFrameResource->m_cbvUploadHeap->GetGPUVirtualAddress() + cbOffset;
                cbvDesc.SizeInBytes         = sizeof(T100DXFrameResource::SceneConstantBuffer);
                cbOffset                    += cbvDesc.SizeInBytes;
                m_device->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);
                cbvSrvHandle.Offset(m_cbvSrvDescriptorSize);
            }
        }

        pFrameResource->InitBundle(m_device.Get(), m_pipelineState1.Get(), m_pipelineState2.Get(), i, m_numIndices, &m_indexBufferView,
            &m_vertexBufferView, m_cbvSrvHeap.Get(), m_cbvSrvDescriptorSize, m_samplerHeap.Get(), m_rootSignature.Get());

        m_frameResources.push_back(pFrameResource);
    }
}
