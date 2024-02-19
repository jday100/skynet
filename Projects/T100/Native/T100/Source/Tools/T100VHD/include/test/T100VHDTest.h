#ifndef T100VHDTEST_H
#define T100VHDTEST_H


#include "T100Common.h"


class T100VHDTest
{
    public:
        T100VHDTest();
        virtual ~T100VHDTest();


        T100BOOL            checksum();

    protected:

    private:
};

#endif // T100VHDTEST_H
