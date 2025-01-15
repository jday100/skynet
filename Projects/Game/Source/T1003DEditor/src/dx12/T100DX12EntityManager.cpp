#include "T100DX12EntityManager.h"

#include "T100DX12Entity.h"

T100DX12EntityManager::T100DX12EntityManager(T100DX12Entity* dx12)
    :m_dx12(dx12),
    m_entities(),
    m_empty(T100TRUE)
{
    //ctor
}

T100DX12EntityManager::~T100DX12EntityManager()
{
    //dtor
}

T100VOID T100DX12EntityManager::Append(T100Entity* entity)
{
    ComPtr<ID3D12Resource>              vertexBufferUploadHeap;
    ComPtr<ID3D12Resource>              indexBufferUploadHeap;
    ComPtr<ID3D12Resource>              textureUploadHeap;

    if(m_empty)
    {
        m_dx12->CreateDsvHeap();
        m_dx12->CreateCbvHeap();
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

        m_dx12->LoadShader(
               &pVertexShaderData,
               vertexShaderDataLength,
               &pPixelShaderData1,
               pixelShaderDataLength1,
               &pPixelShaderData2,
               pixelShaderDataLength2
               );

        m_dx12->CreatePipelineState(
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

    m_dx12->LoadMeshData(&pMeshData, meshDataLength);
    m_dx12->CreateVertexBuffer(vertexBufferUploadHeap, pMeshData, meshDataLength);
    m_dx12->CreateIndexBuffer(indexBufferUploadHeap, pMeshData, meshDataLength);
    m_dx12->CreateTexture(subresourceCount, uploadBufferSize);
    m_dx12->CreateSampler(textureUploadHeap, pMeshData, meshDataLength, subresourceCount, uploadBufferSize);
    m_dx12->CreateTextureSRV();
    delete pMeshData;

    if(m_empty)
    {
        m_dx12->CreateDepthStencilView();
        m_dx12->ExecuteCommandList();
        m_dx12->CreateFence();
        m_dx12->CreateFrameResources();
    }

    m_entities.push_back(entity);
    m_empty = T100FALSE;
}

T100BOOL T100DX12EntityManager::Empty()
{
    return m_empty;
}
