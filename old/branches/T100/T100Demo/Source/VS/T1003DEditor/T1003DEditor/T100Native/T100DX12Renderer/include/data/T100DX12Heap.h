#ifndef T100DX12HEAP_H
#define T100DX12HEAP_H

#include <atomic>
#include "dx12/T100DX12Header.h"

class T100DX12Heap
{
    friend class T100DX12HeapDispenser;
    public:
        T100DX12Heap();
        virtual ~T100DX12Heap();

        T100VOID                            SetSize(T100UINT);
        T100UINT                            GetSize();

        ComPtr<ID3D12DescriptorHeap>        GetHeap();

    protected:
        std::atomic<T100UINT>               m_length;
        T100UINT                            m_size;
        ComPtr<ID3D12DescriptorHeap>        m_heap;

    private:
};

#endif // T100DX12HEAP_H
