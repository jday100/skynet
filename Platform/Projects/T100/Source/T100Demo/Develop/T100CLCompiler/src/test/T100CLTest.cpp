#include "T100CLTest.h"

T100CLTest::T100CLTest()
{
    //ctor
}

T100CLTest::~T100CLTest()
{
    //dtor
}

T100BOOL T100CLTest::test()
{
    T100WString             in;
    T100WString             out;

    T100CLParser            parser;
    T100CLAnalyzer          analyzer;
    T100CLGenerator         generator;

    T100CLCompiler          compiler;

    compiler.setParser(&parser);
    compiler.setAnalyzer(&analyzer);
    compiler.setGenerator(&generator);

    in  = "test/test_main/main.cpp";
    out = "test/build/out";

    compiler.run(in, out);
}
