#include "T100DX12EntityManager.h"

#include "T100DX12.h"
#include "T100City.h"

T100DX12EntityManager::T100DX12EntityManager(T100DX12* dx12)
    :m_dx12(dx12),
    m_entities()
{
    //ctor
    create();
}

T100DX12EntityManager::~T100DX12EntityManager()
{
    //dtor
    destroy();
}

T100VOID T100DX12EntityManager::create()
{
    m_empty = T100TRUE;
}

T100VOID T100DX12EntityManager::destroy()
{

}

T100BOOL T100DX12EntityManager::Empty()
{
    return m_empty;
}

T100VOID T100DX12EntityManager::Append(T100Entity* entity)
{
    T100City*       city        = T100NULL;

    city    = dynamic_cast<T100City*>(entity);

    LoadCity(city);

    m_entities.push_back(entity);
    m_empty = T100FALSE;
}

T100VOID T100DX12EntityManager::LoadCity(T100City* city)
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
