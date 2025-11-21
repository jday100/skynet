#ifndef T100DX12HEAPDISPENSER_H
#define T100DX12HEAPDISPENSER_H

#include <atomic>
#include "renderer/data/T100DX12Heap.h"

class T100DX12HeapManager;

class T100DX12HeapDispenser
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
    friend class T100DX12ContextManager;
    friend class T100DX12ContextManagerBase;
    friend class T100DX12ModelManagerBase;
    public:
        T100DX12HeapDispenser(T100DX12HeapManager*);
        virtual ~T100DX12HeapDispenser();

        virtual T100VOID                Create(ID3D12Device*, D3D12_DESCRIPTOR_HEAP_TYPE, UINT);
        virtual T100VOID                Destroy();

        ID3D12DescriptorHeap*           GetHeap();
        UINT                            GetSize();
        UINT                            GetTop();

        CD3DX12_CPU_DESCRIPTOR_HANDLE   Get(UINT);
        CD3DX12_CPU_DESCRIPTOR_HANDLE   GetCPUStart();
        CD3DX12_GPU_DESCRIPTOR_HANDLE   GetGPUStart();

    protected:
        T100DX12Heap                    m_heap;
        T100DX12HeapManager*            m_manager           = T100NULL;

    protected:
        T100VOID                        CreateRtvHeap(ID3D12Device*, T100DX12Heap&, UINT);
        T100VOID                        CreateCbvSrvHeap(ID3D12Device*, T100DX12Heap&, UINT);
        T100VOID                        CreateDsvHeap(ID3D12Device*, T100DX12Heap&, UINT);
        T100VOID                        CreateSamplerHeap(ID3D12Device*, T100DX12Heap&, UINT);

    private:
        std::atomic<CD3DX12_CPU_DESCRIPTOR_HANDLE>          m_current;
        std::atomic<T100UINT>                               m_top;

        CD3DX12_CPU_DESCRIPTOR_HANDLE   GetCurrent();

        T100VOID                        init();
        T100VOID                        uninit();
};

#endif // T100DX12HEAPDISPENSER_H
