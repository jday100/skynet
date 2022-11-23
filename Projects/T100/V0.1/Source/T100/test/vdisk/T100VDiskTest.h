#ifndef T100VDISKTEST_H
#define T100VDISKTEST_H

#include "T100Test.h"

namespace T100VDisk{

class T100VDiskTest : public T100Library::T100Test
{
    public:
        T100VDiskTest(T100Test*);
        virtual ~T100VDiskTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_console();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100VDISKTEST_H
