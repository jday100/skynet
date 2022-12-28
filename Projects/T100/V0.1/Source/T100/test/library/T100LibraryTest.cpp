#include "T100LibraryTest.h"

namespace T100Library{

T100WSTRING         T100LibraryTest::m_name                     = L"library";

T100LibraryTest::T100LibraryTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name),
    test_string(this),
    test_log(this),
    test_test(this),
    test_capacity(this)
{
    //ctor
}

T100LibraryTest::~T100LibraryTest()
{
    //dtor
}

}
