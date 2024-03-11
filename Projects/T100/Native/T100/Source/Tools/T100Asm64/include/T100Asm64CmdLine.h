#ifndef T100ASM64CMDLINE_H
#define T100ASM64CMDLINE_H

#include "T100CmdLine.h"


class T100Asm64CmdLine : public T100CmdLine
{
    public:
        T100Asm64CmdLine();
        virtual ~T100Asm64CmdLine();

        T100BOOL            parse(int argc, char* argv[]);

    protected:

    private:
};

#endif // T100ASM64CMDLINE_H
