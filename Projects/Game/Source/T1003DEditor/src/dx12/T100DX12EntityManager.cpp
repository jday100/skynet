#include "T100DX12EntityManager.h"

T100DX12EntityManager::T100DX12EntityManager()
    :m_entities(),
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
    m_entities.push_back(entity);
}

T100BOOL T100DX12EntityManager::Empty()
{
    return m_empty;
}
