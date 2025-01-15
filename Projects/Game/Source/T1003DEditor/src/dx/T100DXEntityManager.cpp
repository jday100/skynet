#include "T100DXEntityManager.h"

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
