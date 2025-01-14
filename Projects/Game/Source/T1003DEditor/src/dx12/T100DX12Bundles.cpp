#include "T100DX12Bundles.h"

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
    LoadVertexBuffer(entity);
    LoadPixelBuffer(entity);
    LoadTexture(entity);
}

T100VOID T100DX12Bundles::LoadVertexBuffer(T100Entity* entity)
{

}

T100VOID T100DX12Bundles::LoadPixelBuffer(T100Entity* entity)
{

}

T100VOID T100DX12Bundles::LoadTexture(T100Entity* entity)
{

}
