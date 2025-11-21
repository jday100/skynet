#include "T100CmdLine.h"
#include "T100UnAsm.h"

int main(int argc, char** argv)
{
    T100CmdLineInfo*    info    = T100NULL;

    T100CmdLine     cmdline;

    info    = cmdline.Parse(argc, argv);

    if(!info){
        return -1;
    }

    T100UnAsm       unasm;

    return unasm.Execute(info);
}
