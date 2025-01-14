#ifndef T100DX12ENTITYMANAGER_H
#define T100DX12ENTITYMANAGER_H

#include <atomic>
#include "T100Entity.h"

class T100DX12EntityManager
{
    public:
        T100DX12EntityManager();
        virtual ~T100DX12EntityManager();

        virtual T100VOID                    Append(T100Entity*);

        virtual T100BOOL                    Empty();

    protected:
        T100DX12_ENTITY_VECTOR              m_entities;

    private:
        std::atomic_bool                    m_empty;
};

#endif // T100DX12ENTITYMANAGER_H
