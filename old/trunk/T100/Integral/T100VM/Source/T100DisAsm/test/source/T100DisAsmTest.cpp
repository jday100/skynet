#include "T100DisAsmTest.h"

#include "T100UnAsm.h"

T100DisAsmTest::T100DisAsmTest()
{
    //ctor
}

T100DisAsmTest::~T100DisAsmTest()
{
    //dtor
}

T100BOOL T100DisAsmTest::Test()
{
    T100STRING          file    = "test\\resource\\nop.bin";
    T100CmdLineInfo     info;

    info.FILE       = file;
    info.OFFSET     = 0;

    T100UnAsm       unasm;

    T100BOOL        result;

    result  = unasm.Execute(&info);

    if(!result){
        info.FILE       = "test\\resource\\hlt.bin";
        result  = unasm.Execute(&info);
    }

    return !result;
}
