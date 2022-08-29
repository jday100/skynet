#ifndef T100SCANNERTEST_H
#define T100SCANNERTEST_H

#include "T100Test.h"


class T100ScannerTest : public T100Test
{
    public:
        T100ScannerTest(T100Test*);
        virtual ~T100ScannerTest();

    protected:
        T100BOOL                        do_test();

        T100BOOL                        test_byte();
        T100BOOL                        test_char();
        T100BOOL                        test_string();
        T100BOOL                        test_keyword();

    private:
        static T100WSTRING              m_name;

};

#endif // T100SCANNERTEST_H
