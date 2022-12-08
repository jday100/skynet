#ifndef T100OSTEST_H
#define T100OSTEST_H

#include "T100Test.h"
#include "T100OSRomTest.h"

namespace T100OS{

class T100OSTest : public T100Library::T100Test
{
    public:
        T100OSTest(T100Test*);
        virtual ~T100OSTest();

    protected:
        T100BOOL                    init();
        T100BOOL                    uninit();

        T100BOOL                    init_font();
        T100BOOL                    init_vdisk();

        T100OSRomTest               test_rom;

    private:
        static T100WSTRING          m_name;

};

}

#endif // T100OSTEST_H
