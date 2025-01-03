#ifndef T100FILE_H
#define T100FILE_H

#include <fstream>
#include "T100Common.h"

class T100File
{
    public:
        T100File();
        virtual ~T100File();

        T100BOOL            open(T100WString);
        T100BOOL            close();

        T100BOOL            read();
        T100BOOL            write();

    protected:

    private:
};

#endif // T100FILE_H
