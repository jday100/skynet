#include "T100TestDemoTest.h"

namespace T100Test{

T100WSTRING         T100TestDemoTest::m_name                        = L"test.demo";

T100TestDemoTest::T100TestDemoTest()
    :T100Library::T100Test(T100NULL, m_name)
{
    //ctor
}

T100TestDemoTest::~T100TestDemoTest()
{
    //dtor
}

}
