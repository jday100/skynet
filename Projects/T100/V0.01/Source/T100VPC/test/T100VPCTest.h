#ifndef T100VPCTEST_H
#define T100VPCTEST_H

#include "T100Test.h"
#include "T100QU32Test.h"


class T100VPCTest : public T100Test
{
    public:
        T100VPCTest(T100Test* parent = T100NULL);
        virtual ~T100VPCTest();

    protected:
        T100QU32Test                    test_qu32;


    private:
        static T100WSTRING              m_name;

};

#endif // T100VPCTEST_H
