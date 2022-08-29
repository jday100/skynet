#ifndef T100PARTSCANNERTEST_H
#define T100PARTSCANNERTEST_H

#include "T100Test.h"


class T100PartScannerTest : public T100Test
{
    public:
        T100PartScannerTest(T100Test*);
        virtual ~T100PartScannerTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_part();

    private:
        static T100WSTRING          m_name;

};

#endif // T100PARTSCANNERTEST_H
