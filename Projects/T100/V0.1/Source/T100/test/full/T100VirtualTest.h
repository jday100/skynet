#ifndef T100VIRTUALTEST_H
#define T100VIRTUALTEST_H

#include "T100Test.h"

namespace T100{

class T100VirtualTest : public T100Library::T100Test
{
    public:
        T100VirtualTest(T100Test*);
        virtual ~T100VirtualTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_virtual();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100VIRTUALTEST_H
