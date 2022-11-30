#ifndef T100MEMORYREAL_H
#define T100MEMORYREAL_H

#include "T100MemoryBase.h"
#include "T100String.h"

namespace T100QU32{

class T100MemoryReal : public T100MemoryBase
{
    friend class T100Memory32;
    friend class T100MemoryVirtaul;
    public:
        T100MemoryReal(T100QU32*);
        virtual ~T100MemoryReal();

        T100BOOL                read(T100WORD, T100WORD&);
        T100BOOL                write(T100WORD, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

        T100BOOL                raw_read(T100WORD, T100WORD, T100WORD&);
        T100BOOL                raw_write(T100WORD, T100WORD, T100WORD);

        T100BOOL                load(T100STRING, T100WORD);

        T100BOOL                notify(T100WORD, T100WORD);

    private:
        T100WORD_VECTOR         m_rom;
        T100WORD_VECTOR         m_ram;

        T100WORD                m_rom_base;
        T100WORD                m_rom_length;
        T100WORD                m_rom_limit;

        T100WORD                m_ram_base;
        T100WORD                m_ram_length;
        T100WORD                m_ram_limit;

};

}

#endif // T100MEMORYREAL_H
