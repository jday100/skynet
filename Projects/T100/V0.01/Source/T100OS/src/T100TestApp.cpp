#include "T100TestApp.h"

#include "T100OSTest.h"


T100TestApp::T100TestApp()
{
    //ctor
}

T100TestApp::~T100TestApp()
{
    //dtor
}

T100VOID T100TestApp::run(int argc, wchar_t** argv)
{
    T100OSTest      test;

    test.test_all();
}
