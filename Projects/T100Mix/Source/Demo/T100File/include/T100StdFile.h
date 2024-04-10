#ifndef T100STDFILE_H
#define T100STDFILE_H

#include <atomic>
#include <fstream>
#include "T100Common.h"

class T100StdFile
{
    public:
        T100StdFile(T100STRING);
        virtual ~T100StdFile();

        T100BOOL                    opened();
        T100BOOL                    eof();

        T100BOOL                    open();
        T100BOOL                    close();

        T100BOOL                    seek(T100DWORD);

        T100BOOL                    read(T100CHAR*, T100WORD&);
        T100BOOL                    write(T100CHAR*, T100WORD);

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100STRING                  m_filename;
        std::atomic_bool            m_opened;
        std::fstream*               m_stream            = T100NULL;
};

#endif // T100STDFILE_H
