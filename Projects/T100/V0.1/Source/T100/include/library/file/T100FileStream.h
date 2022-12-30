#ifndef T100FILESTREAM_H
#define T100FILESTREAM_H

#include <atomic>
#include <fstream>
#include "T100Common.h"
#include "T100Stream.h"


namespace T100Library{

class T100FileStream : public T100Stream
{
    public:
        T100FileStream(T100WSTRING);
        virtual ~T100FileStream();

        T100BOOL                    open();
        T100BOOL                    close();
        T100BOOL                    opened();

        T100BOOL                    seek(T100DWORD);

        T100BOOL                    put(T100WORD);
        T100BOOL                    get(T100WORD&);

        T100BOOL                    read(T100WORD*, T100WORD&);
        T100BOOL                    write(T100WORD*, T100WORD);

    protected:
        T100WSTRING                 m_file;
        std::atomic_bool            m_opened;
        std::fstream*               m_stream            = T100NULL;

        std::atomic_llong           m_seek;

        T100VOID                    create();
        T100VOID                    destroy();

    private:
};

}

#endif // T100FILESTREAM_H
