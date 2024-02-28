#ifndef T100VDISKCALLBACK_H
#define T100VDISKCALLBACK_H

#include "T100Common.h"


class T100VDiskCallback
{
    public:
        T100VDiskCallback();
        virtual ~T100VDiskCallback();

        virtual T100VOID            create(T100VOID*, T100BYTE) = 0;
        virtual T100VOID            create_finished(T100VOID*, T100BYTE) = 0;

    protected:

    private:
};

#endif // T100VDISKCALLBACK_H
