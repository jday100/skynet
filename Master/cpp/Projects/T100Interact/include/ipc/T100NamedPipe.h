#ifndef T100NAMEDPIPE_H
#define T100NAMEDPIPE_H

#include "T100Common.h"

class T100NamedPipe
{
    public:
        T100NamedPipe();
        virtual ~T100NamedPipe();

        T100VOID            Create();
        T100VOID            Destroy();

    protected:

    private:
};

#endif // T100NAMEDPIPE_H
