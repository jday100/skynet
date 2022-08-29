#include "T100TestApp.h"

T100TestApp::T100TestApp()
    :T100App(),
    test_common(T100NULL)
{
    //ctor
}

T100TestApp::~T100TestApp()
{
    //dtor
}

T100VOID T100TestApp::run(int argc, wchar_t** argv)
{
    test_common.test_all();

}
