#ifndef T100QU32SETUP_H
#define T100QU32SETUP_H

#include "T100Setup.h"

typedef struct{
    T100WORD        OFFSET;
    T100STDSTRING   FILE;
}T100FILE_INFO;

#define T100FILE_INFO_VECTOR        std::vector<T100FILE_INFO*>


class T100QU32Setup : public T100Setup
{
    public:
        T100QU32Setup();
        virtual ~T100QU32Setup();

        static T100WORD                 m_return;

        static T100STDSTRING            m_file;
        static T100BOOL                 m_base;
        static T100WORD                 m_offset;

        static T100WORD                 m_rom_base;
        static T100WORD                 m_rom_size;
        static T100WORD                 m_ram_base;
        static T100WORD                 m_ram_size;

        static T100BOOL                 m_debug;

        static T100FILE_INFO_VECTOR     m_files;

    protected:

    private:
};

#endif // T100QU32SETUP_H
