#ifndef T100VPCTEST_H
#define T100VPCTEST_H

#include "T100Test.h"
#include "T100QU32Test.h"

namespace T100VPC{

class T100VPCTest : public T100Library::T100Test
{
    public:
        T100VPCTest(T100Test*);
        virtual ~T100VPCTest();

    protected:
        T100QU32Test                    test_qu32;

        T100BOOL                        do_test();

        T100BOOL                        test_vpc();

    private:
        static T100WSTRING              m_name;

};

}

#endif // T100VPCTEST_H
