#ifndef T100MEMORY32_H
#define T100MEMORY32_H

#include "T100Common.h"
class T100QU32;


class T100Memory32
{
    friend class T100QU32;
    friend class T100Order;
    friend class T100MemoryDevice;
    friend class T100Interrupt32;
    public:
        T100Memory32(T100QU32*);
        virtual ~T100Memory32();

        T100BOOL                read(T100WORD, T100WORD&);
        T100BOOL                write(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100BOOL                raw_read(T100WORD, T100WORD, T100WORD&);
        T100BOOL                raw_write(T100WORD, T100WORD, T100WORD);

        T100BOOL                load(T100STRING, T100WORD, T100WORD);

    private:
        T100QU32*               m_host          = T100NULL;

        T100WORD_VECTOR         m_rom;
        T100WORD_VECTOR         m_ram;

        T100WORD                m_rom_base;
        T100WORD                m_rom_length;
        T100WORD                m_rom_limit;

        T100WORD                m_ram_base;
        T100WORD                m_ram_length;
        T100WORD                m_ram_limit;

};

#endif // T100MEMORY32_H
