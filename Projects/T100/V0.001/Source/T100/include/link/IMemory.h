#ifndef IMEMORY_H
#define IMEMORY_H

#include "T100Common.h"
class IComputer;


class IMemory
{
    friend class T100MemoryDevice;
    public:
        IMemory(IComputer*, T100WORD, T100WORD);
        virtual ~IMemory();

        virtual T100WORD            read(T100WORD)=0;
        virtual T100VOID            write(T100WORD, T100WORD)=0;

        virtual T100WORD            read(T100WORD, T100WORD)=0;
        virtual T100VOID            write(T100WORD, T100WORD, T100WORD)=0;

        virtual T100WORD            raw_read(T100WORD)=0;
        virtual T100VOID            raw_write(T100WORD, T100WORD)=0;

    protected:
        T100WORD                    m_rom_base          = 0;
        T100WORD                    m_rom_size          = 1024;

        T100WORD                    m_ram_base          = 0x40000000;
        T100WORD                    m_ram_size          = 1024;

    private:
        IComputer*                  m_host              = T100NULL;
};

#endif // IMEMORY_H
