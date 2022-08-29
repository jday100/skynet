#ifndef T100STRINGSCANNERTEST_H
#define T100STRINGSCANNERTEST_H

#include "T100Test.h"


class T100StringScannerTest : public T100Test
{
    public:
        T100StringScannerTest(T100Test*);
        virtual ~T100StringScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_string();

    private:
        static T100WSTRING          m_name;

};

#endif // T100STRINGSCANNERTEST_H
