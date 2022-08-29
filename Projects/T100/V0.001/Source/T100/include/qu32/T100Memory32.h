#ifndef T100MEMORY32_H
#define T100MEMORY32_H

#include "T100DataTypes.h"
#include "T100String.h"
#include "IMemory.h"
class T100QU32;


class T100Memory32 : public IMemory
{
    friend class T100MemoryDevice;
    friend class T100VPCDebugFrame;
    public:
        T100Memory32(T100QU32*, T100WORD, T100WORD);
        virtual ~T100Memory32();

        T100BOOL                load(T100String, T100WORD);
        T100BOOL                load(T100WORD_VECTOR&, T100WORD);

        T100VOID                write(T100WORD, T100WORD);
        T100WORD                read(T100WORD);

        T100VOID                write(T100WORD, T100WORD, T100WORD);
        T100WORD                read(T100WORD, T100WORD);

        T100VOID                raw_write(T100WORD, T100WORD);
        T100WORD                raw_read(T100WORD);

        T100BOOL                open(T100WORD, T100WORD);
        T100BOOL                close();

    protected:
        T100QU32*               m_host                  = T100NULL;
        T100WORD_VECTOR         m_rom;
        T100WORD_VECTOR         m_ram;

        T100VOID                create();
        T100VOID                destroy();

    private:
        T100WORD                m_rom_base              = 0;
        T100WORD                m_rom_length            = 1024;
        T100WORD                m_rom_limit             = 1024 * 1024;      //1024 * 1024 * 1024;

        T100WORD                m_ram_base              = m_rom_limit;
        T100WORD                m_ram_length            = 1024;
        T100WORD                m_ram_limit             = 0xffffffff;

        T100BOOL                m_ram_window            = T100FALSE;
        T100WORD                m_ram_window_begin      = 0;
        T100WORD                m_ram_window_end        = 0;
};

#endif // T100MEMORY32_H
