#ifndef T100DX12ENTITYMANAGER_H
#define T100DX12ENTITYMANAGER_H

#include <atomic>
#include <windows.h>
#include "T100Common.h"
#include "T100Entity.h"

class T100DX12;
class T100City;

class T100DX12EntityManager
{
    public:
        T100DX12EntityManager(T100DX12*);
        virtual ~T100DX12EntityManager();

        T100BOOL                    Empty();
        T100VOID                    Append(T100Entity*);

        T100VOID                    Reset(INT);

    protected:
        T100DX12*                   m_dx12          = T100NULL;
        T100DX12_ENTITY_VECTOR      m_entities;

    private:
        std::atomic_bool            m_empty;

        T100VOID                    create();
        T100VOID                    destroy();

        T100VOID                    LoadCity(T100City*);
};

#endif // T100DX12ENTITYMANAGER_H
