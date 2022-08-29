#include "T100OSTest.h"

T100STDSTRING       T100OSTest::m_unit      = "os";


T100OSTest::T100OSTest(T100App* app)
    :T100Test(m_unit), m_app(app),
    test_lib(app), test_fs(app), test_boot(app), test_kernel(app)
{
    //ctor
}

T100OSTest::~T100OSTest()
{
    //dtor
}

T100VOID T100OSTest::load()
{

}

T100BOOL T100OSTest::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_lib.test_all()){
        result = T100FALSE;
    }

    if(result && (!test_fs.test_all())){
        result = T100FALSE;
    }

    if(result && (!test_boot.test_all())){
        result = T100FALSE;
    }

    if(result && (!test_kernel.test_all())){
        result = T100FALSE;
    }

    return result;
}
