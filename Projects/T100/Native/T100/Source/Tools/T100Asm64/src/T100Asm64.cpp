#include "T100Asm64.h"

#include "T100Asm64Linker.h"
#include "T100Asm64Compiler.h"


T100Asm64::T100Asm64()
{
    //ctor
}

T100Asm64::~T100Asm64()
{
    //dtor
}

INT32 T100Asm64::run(T100STRING file)
{
    T100Asm64Compiler           compiler;


    compiler.run(file);
}
