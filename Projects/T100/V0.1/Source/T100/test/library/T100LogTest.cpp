#include "T100LogTest.h"

namespace T100Library{

T100WSTRING         T100LogTest::m_name                     = L"log";

T100LogTest::T100LogTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
{
    //ctor
}

T100LogTest::~T100LogTest()
{
    //dtor
}

}
