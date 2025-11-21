#ifndef T100MEMORY64_H
#define T100MEMORY64_H

#include <atomic>
#include "T100Memory.h"

class T100Host64;

class T100Memory64 : public T100Memory
{
    public:
        T100Memory64(T100Host64*);
        virtual ~T100Memory64();

        T100VOID                Pulse();

        T100VOID                Acquire();

        T100BOOL                Read(T100UINT64, T100BYTE*);

    protected:
        T100Host64*             m_host      = T100NULL;
        std::atomic_bool        m_flag;
        std::atomic_bool        m_ready;
        std::atomic_uint        m_count;
        std::atomic_uint        m_delay;

        T100BYTE_VECTOR         m_ram;
        T100BYTE_VECTOR         m_rom;

        T100UINT                m_offset    = 0xfffff - 0x100;
        T100UINT                m_length    = 0x100;

        T100BOOL                Load(T100STRING&);

    private:
        T100VOID                Copy();

        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100MEMORY64_H
