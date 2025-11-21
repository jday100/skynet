#ifndef T100FILE_H
#define T100FILE_H

#include "T100Common.h"

class T100File
{
    public:
        T100File(T100WSTRING);
        virtual ~T100File();

        T100BOOL            IsExists();

    protected:
        T100WSTRING         m_path;

    private:
};

#endif // T100FILE_H
