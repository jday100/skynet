#include "T100ThisAppTest.h"

namespace T100ThisAppTest{

T100WSTRING         T100ThisAppTest::m_name                     = L"T100";

T100ThisAppTest::T100ThisAppTest()
    :T100Library::T100Test(T100NULL, m_name),
    test_library(this),
    test_assembly(this)
{
    //ctor
}

T100ThisAppTest::~T100ThisAppTest()
{
    //dtor
}

}
