#include "T100AssemblyApp.h"

#include "T100Assembly.h"
#include "T100AssemblyCmdLineParser.h"
#include "T100TestApp.h"
#include "T100AssemblyCmdLineResult.h"


T100AssemblyApp::T100AssemblyApp()
{
    //ctor
}

T100AssemblyApp::~T100AssemblyApp()
{
    //dtor
}

T100BOOL T100AssemblyApp::run()
{
    T100BOOL                        result          = T100TRUE;
    int                             argc;
    wchar_t**                       argv;
    T100AssemblyCmdLineResult       data;
    T100AssemblyCmdLineParser       parser;

    getCmdLine(argc, argv);

    result = parser.parse(argc, argv, data);
    if(result){
        if(data.TEST){
            T100TestApp             app;

            result = app.run();
        }else{
            T100Assembly            assembly;

            result = assembly.run(data.SOURCE, data.TARGET);
        }
    }

    return result;
}

