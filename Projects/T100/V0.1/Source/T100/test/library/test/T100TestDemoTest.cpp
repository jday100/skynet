#include "T100TestDemoTest.h"

namespace T100Test{

T100WSTRING         T100TestDemoTest::m_name                        = L"test.demo";

T100TestDemoTest::T100TestDemoTest()
    :T100Library::T100TestNew(T100NULL, m_name)
{
    //ctor
}

T100TestDemoTest::~T100TestDemoTest()
{
    //dtor
}

T100BOOL T100TestDemoTest::do_test()
{

}

T100BOOL T100TestDemoTest::test_test()
{

}

}
