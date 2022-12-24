#ifndef T100OSBOOTTEST_H
#define T100OSBOOTTEST_H

#include "T100Test.h"

namespace T100OS{

class T100OSBootTest : public T100Library::T100Test
{
    public:
        T100OSBootTest(T100Test*);
        virtual ~T100OSBootTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            test_boot();
        T100BOOL            test_init();
        T100BOOL            test_vdisk();
        T100BOOL            test_run();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100OSBOOTTEST_H
