#ifndef T100VDISKCONSOLE_H
#define T100VDISKCONSOLE_H

#include "T100VDiskCommon.h"
#include "T100Console.h"


class T100VDiskConsole : public T100Console
{
    public:
        T100VDiskConsole();
        virtual ~T100VDiskConsole();

    protected:
        T100VOID            create();
        T100VOID            destroy();


    private:
};

#endif // T100VDISKCONSOLE_H
