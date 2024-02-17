#ifndef T100BYTETOOLS_H
#define T100BYTETOOLS_H

#include "T100Common.h"


typedef union{
    T100BYTE    DATA[8];
    T100INT64   VALUE;
}T100INT64_MIX;


class T100ByteTools
{
    public:
        T100ByteTools();
        virtual ~T100ByteTools();

        static T100INT64            swop(T100INT64);
        static T100VOID             swop(T100BYTE*, T100BYTE*, T100INT32);

    protected:

    private:
};

#endif // T100BYTETOOLS_H
