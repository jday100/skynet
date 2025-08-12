#ifndef T100FILE_H
#define T100FILE_H

#include "T100Common.h"

class T100File
{
    public:
        T100File(const T100WSTRING&);
        virtual ~T100File();

        virtual T100BOOL            IsExists();

    protected:

    private:
};

#endif // T100FILE_H
