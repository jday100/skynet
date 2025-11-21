#include "T100CmdLine.h"

#include <string.h>
#include "T100Package.h"

T100CmdLine::T100CmdLine()
{
    //ctor
}

T100CmdLine::~T100CmdLine()
{
    //dtor
}

int T100CmdLine::Run(int argc, char** argv)
{
    if(argc == 3 && strcmp(argv[1], "install") == 0){
        T100Package     package;

        package.Install(argv[2]);
    }
    return 0;
}
