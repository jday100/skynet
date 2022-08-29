#ifndef T100COMMONTEST_H
#define T100COMMONTEST_H

#include "T100Test.h"
#include "T100FontTest.h"
#include "T100VDiskTest.h"


class T100CommonTest : public T100Test
{
    public:
        T100CommonTest(T100Test*);
        virtual ~T100CommonTest();

    protected:
        T100FontTest                    test_font;
        T100VDiskTest                   test_vdisk;

        T100BOOL                        do_test();

        T100BOOL                        test_common();

    private:
        static T100WSTRING              m_name;

};

#endif // T100COMMONTEST_H
