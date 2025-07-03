#include "T100CPPTest.h"

#include "compiler/cx/T100CXCompiler.h"

T100CPPTest::T100CPPTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label),
    test_scanner(this, L"Scanner")
{
    //ctor
}

T100CPPTest::~T100CPPTest()
{
    //dtor
}

T100BOOL T100CPPTest::DoTest()
{
    T100CXCompiler          compiler;

    return ToBool(compiler.Run(L"../../resources/main.cpp"));
}
