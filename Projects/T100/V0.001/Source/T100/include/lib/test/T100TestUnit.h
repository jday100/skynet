#ifndef T100TESTUNIT_H
#define T100TESTUNIT_H

#include "T100Common.h"
#include "T100Test.h"


class T100TestUnit
{
    public:
        T100TestUnit(T100TEST_UNIT);
        virtual ~T100TestUnit();

        T100BOOL                ok();

    protected:

    private:
        T100VOID                run(T100TEST_UNIT);
};

#endif // T100TESTUNIT_H
