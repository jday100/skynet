#include "T100CmdLine.h"

#include <stdlib.h>
#include "T100Console.h"

T100CmdLine::T100CmdLine()
{
    //ctor
}

T100CmdLine::~T100CmdLine()
{
    //dtor
}

T100CmdLineInfo* T100CmdLine::Parse(int argc, char** argv)
{
    T100CmdLineInfo*    result      = T100NULL;

    switch(argc){
    case 2:
        {
            result  = T100NEW T100CmdLineInfo();

            result->FILE    = argv[1];
        }
        break;
    case 3:
        {
            result  = T100NEW T100CmdLineInfo();

            result->FILE    = argv[1];
            result->OFFSET  = atoi(argv[2]);
        }
        break;
    default:
        T100Console::Out("T100DisAsm file offset");
    }

    return result;
}
