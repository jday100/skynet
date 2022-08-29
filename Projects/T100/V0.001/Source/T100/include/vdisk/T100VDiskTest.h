#ifndef T100VDISKTEST_H
#define T100VDISKTEST_H

#include "T100Test.h"


class T100VDiskTest : public T100Test
{
    public:
        T100VDiskTest();
        virtual ~T100VDiskTest();

        T100BOOL                    test_all();

    protected:

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100VDISKTEST_H
