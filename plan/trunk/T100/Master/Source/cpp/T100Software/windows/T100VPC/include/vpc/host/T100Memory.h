#ifndef T100MEMORY_H
#define T100MEMORY_H

#include <cstring>
#include <windows.h>
#include <winhvplatform.h>
#include "T100Common.h"

using namespace T100LIBRARY;

#define     T100BYTE_VECTOR         std::vector<T100BYTE>

class T100Memory
{
    public:
        T100Memory();
        virtual ~T100Memory();

        T100UINT64                  GetOffset();

        virtual T100VOID            Create(WHV_PARTITION_HANDLE, T100UINT64, T100UINT64);

        virtual T100VOID            Load(WHV_PARTITION_HANDLE);

    protected:
        WHV_PARTITION_HANDLE        m_partition         = T100NULL;
        T100UINT64                  m_memorySize        = 0;
        T100UINT64                  m_memoryOffset      = 0;
        T100VOID*                   m_memory            = T100NULL;

        T100VOID                    LoadFile(const T100WSTRING&, T100BYTE_VECTOR&);

    private:
};

#endif // T100MEMORY_H
