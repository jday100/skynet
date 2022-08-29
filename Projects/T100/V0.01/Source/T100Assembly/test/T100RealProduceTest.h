#ifndef T100REALPRODUCETEST_H
#define T100REALPRODUCETEST_H

#include "T100Test.h"


class T100RealProduceTest : public T100Test
{
    public:
        T100RealProduceTest(T100Test*);
        virtual ~T100RealProduceTest();

    protected:
        T100BOOL                do_test();

        T100BOOL                test_basic();

        T100BOOL                test_real();

    private:
        static T100WSTRING      m_name;

};

#endif // T100REALPRODUCETEST_H
