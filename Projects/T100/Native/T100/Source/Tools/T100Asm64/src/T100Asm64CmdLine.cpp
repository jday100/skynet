#include "T100Asm64CmdLine.h"

#include "T100Unicode.h"
#include "T100Asm64.h"

T100Asm64CmdLine::T100Asm64CmdLine()
    :T100CmdLine()
{
    //ctor
}

T100Asm64CmdLine::~T100Asm64CmdLine()
{
    //dtor
}

T100BOOL T100Asm64CmdLine::parse(int argc, char* argv[])
{
    T100Asm64           asm64;

    T100STRING          file;

    file    = T100Unicode::to_wstring(argv[1]);
    return asm64.run(file);
}
