#ifndef T100FULLTEST_H
#define T100FULLTEST_H

#include "T100Test.h"

namespace T100{

class T100FullTest : public T100Library::T100Test
{
    public:
        T100FullTest(T100Test*);
        virtual ~T100FullTest();

    protected:
        T100BOOL                    init();
        T100BOOL                    uninit();

        T100BOOL                    init_font();
        T100BOOL                    init_vdisk();

        T100BOOL                    do_test();

        T100BOOL                    test_full();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100FULLTEST_H
