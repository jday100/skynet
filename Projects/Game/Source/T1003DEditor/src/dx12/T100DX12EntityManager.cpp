#include "T100DX12EntityManager.h"

T100DX12EntityManager::T100DX12EntityManager()
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
