#ifndef T100DX12HEAPDISPENSER_H
#define T100DX12HEAPDISPENSER_H

#include <atomic>
#include "data/T100DX12Heap.h"

class T100DX12HeapManager;

class T100DX12HeapDispenser
{
    public:
        T100DX12HeapDispenser(T100DX12HeapManager*);
        virtual ~T100DX12HeapDispenser();

        virtual T100VOID                    Create(ID3D12Device*, D3D12_DESCRIPTOR_HEAP_TYPE, T100UINT);
        virtual T100VOID                    Destroy();

        ID3D12DescriptorHeap*               GetHeap();

        T100UINT                            GetSize();
        T100UINT                            GetTop();
        CD3DX12_CPU_DESCRIPTOR_HANDLE       Get(T100UINT);
        CD3DX12_CPU_DESCRIPTOR_HANDLE       GetCPUStart();
        CD3DX12_GPU_DESCRIPTOR_HANDLE       GetGPUStart();

    protected:
        T100DX12Heap                        m_heap;
        T100DX12HeapManager*                m_manager           = T100NULL;

    protected:
        T100VOID                            CreateRtvHeap(ID3D12Device*, T100DX12Heap&, T100UINT);
        T100VOID                            CreateCbvSrvHeap(ID3D12Device*, T100DX12Heap&, T100UINT);
        T100VOID                            CreateDsvHeap(ID3D12Device*, T100DX12Heap&, T100UINT);
        T100VOID                            CreateSamplerHeap(ID3D12Device*, T100DX12Heap&, T100UINT);

    private:
        std::atomic<CD3DX12_CPU_DESCRIPTOR_HANDLE>          m_current;
        std::atomic<T100UINT>                               m_top;

        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T100DX12HEAPDISPENSER_H
