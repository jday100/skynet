#ifndef T100QU32INTERFACE_H
#define T100QU32INTERFACE_H

#include "T100Common.h"


class T100QU32Interface
{
    public:
        T100QU32Interface();
        virtual ~T100QU32Interface();

        virtual T100BOOL            notify_memory_update(T100WORD, T100WORD) = 0;
        virtual T100BOOL            notify_port_update(T100WORD, T100WORD) = 0;

    protected:

    private:
};

#endif // T100QU32INTERFACE_H
