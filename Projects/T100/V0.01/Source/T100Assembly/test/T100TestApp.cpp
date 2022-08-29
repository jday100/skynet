#include "T100TestApp.h"
#include "T100AssemblyTest.h"



T100TestApp::T100TestApp()
    :T100App()
{
    //ctor
}

T100TestApp::~T100TestApp()
{
    //dtor
}

T100BOOL T100TestApp::run()
{
    T100BOOL                result          = T100TRUE;
    int                     argc;
    wchar_t**               argv;
    T100AssemblyTest        assembly;

    getCmdLine(argc, argv);

    assembly.argc   = argc;
    assembly.argv   = argv;

    assembly.test_all();

    assembly.find();

    return result;
}
