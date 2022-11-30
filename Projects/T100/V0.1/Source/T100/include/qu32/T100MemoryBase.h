#ifndef T100MEMORYBASE_H
#define T100MEMORYBASE_H

#include "T100Common.h"

namespace T100QU32{
class T100QU32;

class T100MemoryBase
{
    friend class T100Memory32;
    public:
        T100MemoryBase(T100QU32*);
        virtual ~T100MemoryBase();

        T100QU32*               getHost();

        virtual T100BOOL        read(T100WORD, T100WORD&) = 0;
        virtual T100BOOL        write(T100WORD, T100WORD) = 0;

    protected:
        virtual T100BOOL        raw_read(T100WORD, T100WORD, T100WORD&) = 0;
        virtual T100BOOL        raw_write(T100WORD, T100WORD, T100WORD) = 0;

    private:
        T100QU32*               m_host          = T100NULL;

};

}

#endif // T100MEMORYBASE_H
