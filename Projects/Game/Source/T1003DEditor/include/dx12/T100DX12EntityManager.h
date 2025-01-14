#ifndef T100DX12ENTITYMANAGER_H
#define T100DX12ENTITYMANAGER_H

#include "T100Entity.h"

class T100DX12EntityManager
{
    public:
        T100DX12EntityManager();
        virtual ~T100DX12EntityManager();

        virtual T100VOID                    Append(T100Entity*);

    protected:
        T100DX12_ENTITY_VECTOR              m_entities;

    private:
};

#endif // T100DX12ENTITYMANAGER_H
