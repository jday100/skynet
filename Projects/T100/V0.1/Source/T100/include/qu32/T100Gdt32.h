#ifndef T100GDT32_H
#define T100GDT32_H

#include "T100QU32Common.h"

#define     T100GDT_ITEM_LENGTH         2

namespace T100QU32{
class T100QU32;


class T100Gdt32
{
    public:
        T100Gdt32(T100QU32*);
        virtual ~T100Gdt32();

        T100BOOL            load(T100WORD, T100WORD);

        T100BOOL            getEntry(T100WORD, T100WORD&);

        T100BOOL            enter(T100WORD, T100WORD);

        T100BOOL            quit(T100WORD, T100WORD);

        T100QU32*           getHost();

    protected:
        T100WORD            m_offset;
        T100WORD            m_length;

        T100WORD            m_index;

        T100BOOL            loadGdtItem(T100WORD&);

    private:
        T100QU32*           m_host          = T100NULL;

        T100GDT_VECTOR      m_gdt;

};

}

#endif // T100GDT32_H
