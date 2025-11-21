#include "T100Memory.h"

#include "storage/file/binary/T100BinaryFile.h"
#include "T100VPCCommon.h"

using namespace T100LIBRARY;

T100Memory::T100Memory()
{
    //ctor
}

T100Memory::~T100Memory()
{
    //dtor
}

T100UINT64 T100Memory::GetOffset()
{
    return m_memoryOffset;
}

T100VOID T100Memory::Create(WHV_PARTITION_HANDLE handler, T100UINT64 size, T100UINT64 offset)
{
    m_partition     = handler;

    m_memorySize    = size;
    m_memoryOffset  = offset;

    m_memory    = VirtualAlloc(T100NULL, m_memorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    ENSURE(m_memory != T100NULL);

    ENSURE(WHvMapGpaRange(handler, m_memory, m_memoryOffset, m_memorySize,
        WHvMapGpaRangeFlagRead | WHvMapGpaRangeFlagWrite | WHvMapGpaRangeFlagExecute) == S_OK);
}

T100VOID T100Memory::Load(WHV_PARTITION_HANDLE handler)
{
    std::vector<T100BYTE>          memory;
    //C:\znew\trunk\T100\Bench\T100BFLC\Samples\main\T100Console\bin\Debug

    memory.insert(memory.end(), {0xba, 0xf8, 0x03});
    for(T100BYTE value : T100STDSTRING("Hello, Hyper-V!\n")){
        memory.insert(memory.end(), {0xb0, value, 0xee});
    }
    memory.insert(memory.end(), {0xf4});

    T100WSTRING         filename    = L"./resources/firmware/OVMF.fd";

    //
    filename    = L"./resources/print.bin";

    LoadFile(filename, memory);

    std::memcpy(m_memory, memory.data(), memory.size());
}

T100VOID T100Memory::LoadFile(const T100WSTRING& filename, T100BYTE_VECTOR& data)
{
    T100BinaryFile          file(filename);

    if(!file.IsExists()){
        return;
    }

    T100BinaryFileReader*   reader      = file.CreateReader();

    if(!reader){
        return;
    }

    T100UINT    length      = file.GetLength();

    data.resize(length);

    reader->Read(data.data(), length);

    file.DestroyReader(reader);
}
