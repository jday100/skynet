#ifndef T100BUSINTEL64_H
#define T100BUSINTEL64_H

#include "T100Bus.h"

class T100MemoryIntel64;

class T100BusIntel64 : public T100Bus
{
    public:
        T100BusIntel64();
        virtual ~T100BusIntel64();

        virtual T100VOID            Plug(T100Device*);
        virtual T100VOID            Unplug(T100Device*);

        virtual T100VOID            PlugMemory(T100MemoryIntel64*);

        virtual T100BOOL            Read(T100UINT64, T100BYTE*);
        virtual T100BOOL            Read(T100UINT64, T100UINT16*);
        virtual T100BOOL            Read(T100UINT64, T100UINT32*);

    protected:
        T100MemoryIntel64*          m_memory        = T100NULL;

    private:
};

#endif // T100BUSINTEL64_H
