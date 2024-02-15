#ifndef T100MEMORY64_H
#define T100MEMORY64_H

#include "T100Bus64.h"


class T100Memory64
{
    public:
        T100Memory64(T100Bus64*, INT64);
        virtual ~T100Memory64();

        T100VOID            read(INT64, INT64&);
        T100VOID            write(INT64, INT64);

    protected:

    private:
        INT64               m_length        = 0;
        T100Bus64*          m_bus           = T100NULL;
        INT64               m_buffer[0];
};

#endif // T100MEMORY64_H
