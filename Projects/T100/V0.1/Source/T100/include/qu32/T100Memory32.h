#ifndef T100MEMORY32_H
#define T100MEMORY32_H

#include "T100Common.h"
#include "T100String.h"

#include "T100MemoryReal.h"
#include "T100MemoryVirtaul.h"


namespace T100QU32{
class T100QU32;


class T100Memory32
{
    friend class T100CU32;
    friend class T100QU32;
    friend class T100Order;
    friend class T100OrderBase;
    friend class T100OrderOperator;
    friend class T100Interrupt32;
    friend class T100MemoryDevice;
    public:
        T100Memory32(T100QU32*);
        virtual ~T100Memory32();

        T100MemoryReal*         getMemory();

        T100BOOL                enter();
        T100BOOL                quit();

        T100BOOL                read(T100WORD, T100WORD&);
        T100BOOL                write(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100BOOL                raw_read(T100WORD, T100WORD, T100WORD&);
        T100BOOL                raw_write(T100WORD, T100WORD, T100WORD);

        T100BOOL                load(T100STRING, T100WORD);

        T100WORD                getRomBase();
        T100WORD                getRomLength();

        T100WORD                getRamBase();
        T100WORD                getRamLength();

    private:
        T100QU32*               m_host          = T100NULL;

        T100MemoryBase*         m_memory        = T100NULL;

        T100MemoryReal*         m_real          = T100NULL;

        T100MemoryVirtaul*      m_virtual       = T100NULL;


};

}

#endif // T100MEMORY32_H
