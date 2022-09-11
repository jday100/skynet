#ifndef T100OSTEST_H
#define T100OSTEST_H

#include "T100Test.h"


class T100OSTest : public T100Test
{
    public:
        T100OSTest();
        virtual ~T100OSTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            test_int();

    private:
};

#endif // T100OSTEST_H
