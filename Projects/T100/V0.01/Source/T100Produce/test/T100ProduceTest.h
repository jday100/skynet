#ifndef T100PRODUCETEST_H
#define T100PRODUCETEST_H

#include "T100Test.h"
#include "T100PartTest.h"


class T100ProduceTest : public T100Test
{
    public:
        T100ProduceTest(T100Test* parent = T100NULL);
        virtual ~T100ProduceTest();

    protected:
        T100PartTest                test_part;

    private:
        static T100WSTRING          m_name;

};

#endif // T100PRODUCETEST_H
