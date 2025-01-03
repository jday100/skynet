#ifndef T100FILEREADER_H
#define T100FILEREADER_H

#include <atomic>
#include <fstream>
#include "T100Common.h"

class T100FileReader
{
    public:
        T100FileReader();
        virtual ~T100FileReader();

        T100BOOL                open(T100WString);
        T100BOOL                close();

        T100BOOL                read(T100WChar*, T100WORD&);

        T100BOOL                opened();
        T100BOOL                eof();
        T100BOOL                seek(T100DWORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100WString             m_filename;
        std::atomic_bool        m_opened;
        std::atomic_llong       m_seek;

        std::ifstream*          m_stream            = T100NULL;
};

#endif // T100FILEREADER_H
