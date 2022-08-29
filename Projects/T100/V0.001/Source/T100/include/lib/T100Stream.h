#ifndef T100STREAM_H
#define T100STREAM_H

#include <fstream>
#include "T100VDiskCommon.h"



class T100Stream
{
    public:
        T100Stream(T100STDSTRING);
        virtual ~T100Stream();

        T100BOOL            open(T100FILE_MODE);
        T100BOOL            close();
        T100BOOL            opened();

        T100BOOL            seek(T100DWORD);

        T100BOOL            get(T100WORD&);
        T100BOOL            put(T100WORD);

        T100BOOL            read(T100WORD*, T100WORD&);
        T100BOOL            write(T100WORD*, T100WORD&);

    protected:

    private:
        T100STDSTRING       m_file;
        T100BOOL            m_opened    = T100FALSE;
        T100DWORD           m_seek      = 0;
        std::fstream*       m_fs        = T100NULL;
};

#endif // T100STREAM_H
