#ifndef T100FILE_H
#define T100FILE_H

#include <atomic>
#include <fstream>
#include "T100Common.h"

class T100File
{
    public:
        T100File(T100STRING);
        virtual ~T100File();

        T100BOOL                opened();
        T100BOOL                eof();

        T100BOOL                open();
        T100BOOL                close();

        T100BOOL                seek(T100DWORD);

        T100BOOL                read(T100WCHAR*, T100WORD&);
        T100BOOL                write(T100WCHAR*, T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100STRING              m_filename;
        std::atomic_bool        m_opened;
        std::fstream*           m_stream            = T100NULL;
};

#endif // T100FILE_H
