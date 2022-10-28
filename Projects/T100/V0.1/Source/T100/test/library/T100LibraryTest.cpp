#include "T100LibraryTest.h"

namespace T100Library{

T100LibraryTest::T100LibraryTest(T100Test* parent)
    :T100Library::T100Test(parent, L""),
    test_string(this),
    test_log(this)
{
    //ctor
}

T100LibraryTest::~T100LibraryTest()
{
    //dtor
}

}
