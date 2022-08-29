#ifndef T100FILE_H
#define T100FILE_H

#include <fstream>
#include "T100FileCommon.h"


class T100File
{
    friend class T100HintLib;
    public:
        T100File(T100String);
        virtual ~T100File();

        virtual T100BOOL        exists();

        virtual T100BOOL        create();
        virtual T100BOOL        remove();

        virtual T100BOOL        open(T100FILE_MODE);
        virtual T100BOOL        close();
        virtual T100BOOL        opened();

        virtual T100BOOL        seek(T100DWORD);
        virtual T100DWORD       length();

        virtual T100BOOL        get(T100WORD&);
        virtual T100BOOL        put(T100WORD);

        virtual T100BOOL        read(T100WORD*, T100WORD&);
        virtual T100BOOL        write(T100WORD*, T100WORD&);


    protected:
        T100String              m_file;
        T100BOOL                m_opened        = T100FALSE;
        T100DWORD               m_seek          = 0;
        T100DWORD               m_length        = 0;

    private:
        std::fstream*           m_fs            = T100NULL;
};

#endif // T100FILE_H
