#include "T100OSRomTest.h"

#include "T100ThisAppSetup.h"
#include "T100OSTestHint.h"
#include "T100Assembly.h"
#include "T100FileTools.h"
#include "T100VPC.h"

namespace T100OS{

T100WSTRING     T100OSRomTest::m_name                       = L"os.rom";

T100OSRomTest::T100OSRomTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100OSRomTest::~T100OSRomTest()
{
    //dtor
}

T100BOOL T100OSRomTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_rom();
    if(!value){
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100OSRomTest::test_rom()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_OS_ROM_TEST_START);

    show_result(result, T100TEST_HINT_OS_ROM_TEST_STOP);
    return result;
}

}
