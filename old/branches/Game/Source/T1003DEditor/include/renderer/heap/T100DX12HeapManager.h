#ifndef T100DX12HEAPMANAGER_H
#define T100DX12HEAPMANAGER_H

#include "renderer/heap/T100DX12HeapDispenser.h"
#include "renderer/data/T100DX12Config.h"

class T100DX12Space;

class T100DX12HeapManager
{
    public:
        T100DX12HeapManager(T100DX12Space*);
        virtual ~T100DX12HeapManager();

        T100DX12HeapDispenser&              GetRtvHeap();
        T100DX12HeapDispenser&              GetCbvSrvHeap();
        T100DX12HeapDispenser&              GetDsvHeap();
        T100DX12HeapDispenser&              GetSamplerHeap();

        virtual T100VOID                    Start(T100DX12Config*);
        virtual T100VOID                    Stop();

    protected:
        T100DX12Space*                      m_space             = T100NULL;

        T100DX12HeapDispenser               m_rtvHeapDispenser;
        T100DX12HeapDispenser               m_cbvsrvHeapDispenser;
        T100DX12HeapDispenser               m_dsvHeapDispenser;
        T100DX12HeapDispenser               m_samplerHeapDispenser;

    private:
};

#endif // T100DX12HEAPMANAGER_H
