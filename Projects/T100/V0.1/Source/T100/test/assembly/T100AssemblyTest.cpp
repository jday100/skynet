#include "T100AssemblyTest.h"

namespace T100Assembly{

T100WSTRING         T100AssemblyTest::m_name                        = L"assembly";

T100AssemblyTest::T100AssemblyTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name),
    test_scanner(this)
{
    //ctor
}

T100AssemblyTest::~T100AssemblyTest()
{
    //dtor
}

}
