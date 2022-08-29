#include "T100TestApp.h"

T100TestApp::T100TestApp()
    :T100App(),
    test_vpc()
{
    //ctor
}

T100TestApp::~T100TestApp()
{
    //dtor
}

T100VOID T100TestApp::run(int argc, wchar_t** argv)
{
    test_vpc.test_all();
}
