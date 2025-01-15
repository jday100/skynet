#ifndef T100DX12ENTITYMANAGER_H
#define T100DX12ENTITYMANAGER_H

#include <atomic>
#include "T100Entity.h"
class T100DX12Entity;
class T100City;

class T100DX12EntityManager
{
    public:
        T100DX12EntityManager(T100DX12Entity*);
        virtual ~T100DX12EntityManager();

        virtual T100VOID                    Append(T100Entity*);

        virtual T100BOOL                    Empty();

    protected:
        T100DX12Entity*                     m_dx12          = T100NULL;
        T100DX12_ENTITY_VECTOR              m_entities;

    private:
        std::atomic_bool                    m_empty;

        T100VOID                            LoadCity(T100City*);
};

#endif // T100DX12ENTITYMANAGER_H
