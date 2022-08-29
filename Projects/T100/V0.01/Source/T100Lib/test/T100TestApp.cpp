#include "T100TestApp.h"

#include "T100LibTest.h"


T100TestApp::T100TestApp()
    :T100App()
{
    //ctor
}

T100TestApp::~T100TestApp()
{
    //dtor
}

T100VOID T100TestApp::run(int argc, wchar_t** argv)
{
    T100LibTest         lib;

    lib.argc    = argc;
    lib.argv    = argv;

    lib.test_all();
}
