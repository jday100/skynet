#ifndef T100DXENTITYMANAGER_H
#define T100DXENTITYMANAGER_H

#include <atomic>
#include "T100Entity.h"
class T100DXEntity;
class T100City;

class T100DXEntityManager
{
    public:
        T100DXEntityManager(T100DXEntity*);
        virtual ~T100DXEntityManager();

        virtual T100VOID                    Append(T100Entity*);

        virtual T100BOOL                    Empty();

    protected:
        T100DXEntity*                       m_dx12          = T100NULL;
        T100DX12_ENTITY_VECTOR              m_entities;

    private:
        std::atomic_bool                    m_empty;

        T100VOID                            LoadCity(T100City*);

};

#endif // T100DXENTITYMANAGER_H
