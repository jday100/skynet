#include "T100VPCTest.h"

T100WSTRING         T100VPCTest::m_name                         = L"vpc";


T100VPCTest::T100VPCTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_qu32(this)
{
    //ctor
}

T100VPCTest::~T100VPCTest()
{
    //dtor
}
