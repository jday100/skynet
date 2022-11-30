#ifndef T100MEMORYVIRTAUL_H
#define T100MEMORYVIRTAUL_H

#include "T100MemoryBase.h"

namespace T100QU32{
class T100Gdt32;
class T100MemoryReal;


class T100MemoryVirtaul : public T100MemoryBase
{
    public:
        T100MemoryVirtaul(T100QU32*);
        virtual ~T100MemoryVirtaul();

        T100BOOL            read(T100WORD, T100WORD&);
        T100BOOL            write(T100WORD, T100WORD);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            raw_read(T100WORD, T100WORD, T100WORD&);
        T100BOOL            raw_write(T100WORD, T100WORD, T100WORD);

    private:
        T100Gdt32*          m_gdt               = T100NULL;
        T100MemoryReal*     m_memory            = T100NULL;

};

}

#endif // T100MEMORYVIRTAUL_H
