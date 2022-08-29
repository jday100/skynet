#ifndef T100PARTTEST_H
#define T100PARTTEST_H

#include "T100Test.h"


class T100PartTest : public T100Test
{
    public:
        T100PartTest(T100Test*);
        virtual ~T100PartTest();

    protected:
        T100BOOL                    do_test();
        T100BOOL                    test_part();

    private:
        static T100WSTRING          m_name;

};

#endif // T100PARTTEST_H
