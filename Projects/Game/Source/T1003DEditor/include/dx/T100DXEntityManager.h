#ifndef T100DXENTITYMANAGER_H
#define T100DXENTITYMANAGER_H

#include <atomic>
#include "T100Common.h"
class T100DXEntity;

class T100DXEntityManager
{
    public:
        T100DXEntityManager(T100DXEntity*);
        virtual ~T100DXEntityManager();

        T100BOOL                        Empty();

    protected:
        T100DXEntity*                   m_dx12          = T100NULL;

    private:
        std::atomic_bool                m_empty;
};

#endif // T100DXENTITYMANAGER_H
