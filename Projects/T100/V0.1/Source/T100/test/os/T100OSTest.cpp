#include "T100OSTest.h"

namespace T100OS{

T100WSTRING         T100OSTest::m_name                      = L"os";

T100OSTest::T100OSTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100OSTest::~T100OSTest()
{
    //dtor
}

}
