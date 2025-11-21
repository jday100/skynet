#ifndef T100DX12SPACE_H
#define T100DX12SPACE_H

#include "link/T1003DConfig.h"
#include "core/T100DX12Card.h"
#include "heap/T100DX12HeapManager.h"

class T100DX12Space : public T100DX12Card
{
    public:
        T100DX12Space();
        virtual ~T100DX12Space();

        T100DX12HeapManager&        GetHeapManager();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            SetConfigPtr(T1003DConfig*);
        virtual T1003DConfig*       GetConfigPtr();

    protected:
        T1003DConfig*               m_config            = T100NULL;
        T100DX12HeapManager         m_heapManager;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100DX12SPACE_H
