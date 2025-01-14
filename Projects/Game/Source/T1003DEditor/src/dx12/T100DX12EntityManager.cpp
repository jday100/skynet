#include "T100DX12EntityManager.h"

T100DX12EntityManager::T100DX12EntityManager()
    :m_entities()
{
    //ctor
}

T100DX12EntityManager::~T100DX12EntityManager()
{
    //dtor
}

T100VOID T100DX12EntityManager::Append(T100Entity* entity)
{
    m_entities.push_back(entity);
}
