#ifndef T100CAPACITYTEST_H
#define T100CAPACITYTEST_H

#include "T100Test.h"

namespace T100Library{

class T100CapacityTest : public T100Test
{
    public:
        T100CapacityTest(T100Test*);
        virtual ~T100CapacityTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            test_capacity();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100CAPACITYTEST_H
