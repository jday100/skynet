#ifndef T100OSINITTEST_H
#define T100OSINITTEST_H

#include "T100Test.h"

namespace T100OS{

class T100OSInitTest : public T100Library::T100Test
{
    public:
        T100OSInitTest(T100Test*);
        virtual ~T100OSInitTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            test_init();
        T100BOOL            test_kernel();
        T100BOOL            test_vdisk();
        T100BOOL            test_run();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100OSINITTEST_H
