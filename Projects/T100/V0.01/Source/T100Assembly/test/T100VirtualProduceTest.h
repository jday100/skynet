#ifndef T100VIRTUALPRODUCETEST_H
#define T100VIRTUALPRODUCETEST_H

#include "T100Test.h"


class T100VirtualProduceTest : public T100Test
{
    public:
        T100VirtualProduceTest(T100Test*);
        virtual ~T100VirtualProduceTest();

    protected:
        T100BOOL                do_test();

        T100BOOL                test_virtual();

    private:
        static T100WSTRING      m_name;

};

#endif // T100VIRTUALPRODUCETEST_H
