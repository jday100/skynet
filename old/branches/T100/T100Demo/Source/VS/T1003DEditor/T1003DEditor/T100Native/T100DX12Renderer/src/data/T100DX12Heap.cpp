#include "data/T100DX12Heap.h"

T100DX12Heap::T100DX12Heap() :
    m_size(0)
{
    //ctor
}

T100DX12Heap::~T100DX12Heap()
{
    //dtor
}

T100VOID T100DX12Heap::SetSize(T100UINT size)
{
    m_size  = size;
}

T100UINT T100DX12Heap::GetSize()
{
    return m_size;
}

ComPtr<ID3D12DescriptorHeap> T100DX12Heap::GetHeap()
{
    return m_heap;
}
