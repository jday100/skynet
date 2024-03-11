#ifndef T100ASM64COMPILER_H
#define T100ASM64COMPILER_H

#include "T100Compiler.h"


class T100Asm64Compiler : public T100Compiler
{
    public:
        T100Asm64Compiler();
        virtual ~T100Asm64Compiler();

        T100BOOL            run(T100STRING);

    protected:

    private:
};

#endif // T100ASM64COMPILER_H
