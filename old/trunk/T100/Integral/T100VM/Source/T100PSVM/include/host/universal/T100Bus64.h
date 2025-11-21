#ifndef T100BUS64_H
#define T100BUS64_H

#include <atomic>
#include "T100Bus.h"

class T100Host64;
class T100Memory64;

class T100Bus64 : public T100Bus
{
    public:
        T100Bus64(T100Host64*);
        virtual ~T100Bus64();

        T100VOID                Pulse();

        T100VOID                Plug(T100Device*);
        T100VOID                Unplug(T100Device*);

        T100VOID                PlugMemory(T100Memory64*);

        T100BOOL                IsBusy();

        T100VOID                Ready();
        T100VOID                Acquire();
        T100BOOL                IsReady();
        T100BOOL                Read(T100UINT64, T100BYTE*);

    protected:
        T100Host64*             m_host      = T100NULL;
        T100Memory64*           m_memory    = T100NULL;

        std::atomic_bool        m_busy;
        std::atomic_bool        m_ready;

    private:
};

#endif // T100BUS64_H
