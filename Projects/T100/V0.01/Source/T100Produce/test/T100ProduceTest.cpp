#include "T100ProduceTest.h"

T100WSTRING         T100ProduceTest::m_name                     = L"produce";


T100ProduceTest::T100ProduceTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_part(this)
{
    //ctor
}

T100ProduceTest::~T100ProduceTest()
{
    //dtor
}
