#ifndef T100DX12ENTITYMANAGER_H
#define T100DX12ENTITYMANAGER_H

#include <atomic>
#include "T100Common.h"

class T100DX12EntityManager
{
    public:
        T100DX12EntityManager();
        virtual ~T100DX12EntityManager();

        T100BOOL                    Empty();

    protected:

    private:
        std::atomic_bool            m_empty;

        T100VOID                    create();
        T100VOID                    destroy();
};

#endif // T100DX12ENTITYMANAGER_H
