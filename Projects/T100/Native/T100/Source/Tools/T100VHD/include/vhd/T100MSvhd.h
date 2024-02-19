#ifndef T100MSVHD_H
#define T100MSVHD_H

#include "T100Common.h"


class T100MSvhd
{
    public:
        T100MSvhd();
        virtual ~T100MSvhd();

        T100BOOL            create();

        T100BOOL            create3();

        T100BOOL            create2();

        T100BOOL            create1();

    protected:

    private:
};

#endif // T100MSVHD_H
