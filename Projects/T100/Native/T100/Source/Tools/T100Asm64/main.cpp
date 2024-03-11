#include "T100Asm64CmdLine.h"

int main(int argc, char* argv[])
{
    T100Asm64CmdLine        cmdline;

    return cmdline.parse(argc, argv);
}
