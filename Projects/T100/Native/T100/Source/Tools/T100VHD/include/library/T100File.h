#ifndef T100FILE_H
#define T100FILE_H

#include <fstream>
#include "T100Common.h"


class T100File
{
    public:
        T100File(T100STRING);
        virtual ~T100File();

        T100BOOL            create();
        T100BOOL            remove();

        T100BOOL            open();
        T100BOOL            close();

        T100BOOL            read(T100BYTE*, T100INT32&);
        T100BOOL            write(T100BYTE*, T100INT32);

        T100BOOL            seek(T100INT64);

    protected:

    private:
        T100STRING          m_filename;
        std::fstream*       m_fs            = T100NULL;
};

#endif // T100FILE_H
