#ifndef T100OSROMTEST_H
#define T100OSROMTEST_H

#include "T100Test.h"

namespace T100OS{

class T100OSRomTest : public T100Library::T100Test
{
    public:
        T100OSRomTest(T100Test*);
        virtual ~T100OSRomTest();

    protected:
        T100BOOL                    init();
        T100BOOL                    uninit();

        T100BOOL                    init_vdisk();

        T100BOOL                    do_test();

        T100BOOL                    test_rom();

        T100BOOL                    do_rom();
        T100BOOL                    do_boot();
        T100BOOL                    do_vdisk();

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100OSROMTEST_H