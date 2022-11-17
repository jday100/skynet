#ifndef T100ASSEMBLYSCANNERTEST_H
#define T100ASSEMBLYSCANNERTEST_H

#include "T100Test.h"

namespace T100Assembly{

class T100AssemblyScannerTest : public T100Library::T100Test
{
    public:
        T100AssemblyScannerTest(T100Test*);
        virtual ~T100AssemblyScannerTest();

    protected:
        T100BOOL                do_test();

        T100BOOL                test_byte();
        T100BOOL                test_char();

    private:
        static T100WSTRING      m_name;

};

}

#endif // T100ASSEMBLYSCANNERTEST_H
