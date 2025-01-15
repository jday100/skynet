#ifndef T100DXENTITYMANAGER_H
#define T100DXENTITYMANAGER_H

#include <atomic>
#include "T100Common.h"
#include "T100Entity.h"
#include "T100City.h"
class T100DXEntity;

class T100DXEntityManager
{
    public:
        T100DXEntityManager(T100DXEntity*);
        virtual ~T100DXEntityManager();

        T100BOOL                        Empty();

        T100VOID                        Append(T100Entity*);

    protected:
        T100DXEntity*                   m_dx12          = T100NULL;
        T100DX12_ENTITY_VECTOR          m_entities;

        T100VOID                        LoadCity(T100City*);

    private:
        std::atomic_bool                m_empty;
};

#endif // T100DXENTITYMANAGER_H
