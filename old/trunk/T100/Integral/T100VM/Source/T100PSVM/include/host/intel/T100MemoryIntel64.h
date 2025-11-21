#ifndef T100MEMORYINTEL64_H
#define T100MEMORYINTEL64_H

#include "T100Memory.h"

class T100MemoryIntel64 : public T100Memory
{
    public:
        T100MemoryIntel64();
        virtual ~T100MemoryIntel64();

        virtual T100BOOL            Read(T100UINT64, T100BYTE*);
        virtual T100BOOL            Read(T100UINT64, T100UINT16*);
        virtual T100BOOL            Read(T100UINT64, T100UINT32*);

    protected:
        T100UINT                    m_offset    = 0xfffff - 0x100;
        T100UINT                    m_length    = 0x100;

        T100BOOL                    Load(T100STRING&);

    private:
        T100VOID                    Copy();

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100MEMORYINTEL64_H
