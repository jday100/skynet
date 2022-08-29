#ifndef T100READER_H
#define T100READER_H

#include "T100Common.h"


class T100Reader
{
    public:
        T100Reader();
        virtual ~T100Reader();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
};

#endif // T100READER_H
