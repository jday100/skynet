#ifndef T100BUFFER_H
#define T100BUFFER_H

#include "T100Common.h"


class T100Buffer
{
    public:
        T100Buffer();
        virtual ~T100Buffer();

        T100BOOL            empty();
        T100VOID            setLength(INT32);

        T100WCHAR*          data();
        INT32               length();
        INT32               size();

        T100BOOL            next(T100WCHAR&);

    protected:
        INT32               m_size          = 1024;
        INT32               m_length        = 0;
        INT32               m_index         = 0;

    private:
        T100WCHAR           m_buffer[0];
};

#endif // T100BUFFER_H
