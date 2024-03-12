#include "T100Asm64.h"

#include "T100Asm64Linker.h"
#include "T100Asm64Compiler.h"
#include "T100Asm64Producer.h"


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
    T100ParseInfo               parse_info;
    T100BuildInfo               build_info;
    T100Asm64Compiler           compiler;
    T100Asm64Linker             linker;
    T100Asm64Producer           producer;

    compiler.run(file, parse_info);
    linker.run(parse_info, build_info);
    producer.run(build_info);

}
