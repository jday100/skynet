#ifndef T100DX12HEAP_H
#define T100DX12HEAP_H

#include "dx12/T100DX12Header.h"

class T100DX12Heap
{
    friend class T100DX12Line;
    friend class T100DX12Discrete;
    friend class T100DX12Triangle;
    friend class T100DX12FrameResource;
    friend class T100DX12FrameManager;

    friend class T100DX12Area;
    friend class T100DX12Model;
    friend class T100DX12Frame;
    friend class T100DX12Studio;
    friend class T100DX12Bundle;
    friend class T100DX12Context;
    friend class T100DX12ModelManager;
    friend class T100DX12HeapDispenser;
    friend class T100DX12ContextManager;
    friend class T100DX12ContextManagerBase;
    friend class T100DX12ModelManagerBase;
    public:
        T100DX12Heap();
        virtual ~T100DX12Heap();

    protected:
        UINT                                m_length;
        UINT                                m_heapDescriptorSize;
        D3D12_DESCRIPTOR_HEAP_TYPE          m_type;
        ComPtr<ID3D12DescriptorHeap>        m_heap;

    private:
};

#endif // T100DX12HEAP_H
