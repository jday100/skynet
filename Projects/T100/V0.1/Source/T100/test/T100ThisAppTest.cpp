#include "T100ThisAppTest.h"

namespace T100ThisAppTest{

T100ThisAppTest::T100ThisAppTest()
    :T100Library::T100Test(),
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
