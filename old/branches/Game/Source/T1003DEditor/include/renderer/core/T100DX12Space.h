#ifndef T100DX12SPACE_H
#define T100DX12SPACE_H

#include "renderer/data/T100DX12Config.h"
#include "renderer/core/T100DX12Card.h"
#include "renderer/heap/T100DX12HeapManager.h"

class T100DX12Space : public T100DX12Card
{
    friend class T100DX12FrameResource;

    friend class T100DX12ContextManager;
    friend class T100DX12ContextManagerBase;
    friend class T100DX12ModelManagerBase;
    public:
        T100DX12Space();
        virtual ~T100DX12Space();

        virtual T100VOID                    Start();
        virtual T100VOID                    Stop();

        virtual T100VOID                    SetConfig(T100DX12Config*);
        virtual T100DX12Config*             GetConfig();

    protected:
        T100DX12Config*                     m_config            = T100NULL;

        T100DX12HeapManager                 m_heap_manager;

    protected:

    private:
        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T100DX12SPACE_H
