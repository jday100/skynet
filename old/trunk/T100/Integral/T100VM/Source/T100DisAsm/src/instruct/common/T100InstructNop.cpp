#include "T100InstructNop.h"

#include "T100Console.h"

T100InstructNop::T100InstructNop() :
    T100Instruct()
{
    //ctor
}

T100InstructNop::~T100InstructNop()
{
    //dtor
}

T100BOOL T100InstructNop::Execute()
{
    return T100TRUE;
}

T100BOOL T100InstructNop::Parse()
{
    T100Console::Out("Nop\n");
    return T100TRUE;
}
