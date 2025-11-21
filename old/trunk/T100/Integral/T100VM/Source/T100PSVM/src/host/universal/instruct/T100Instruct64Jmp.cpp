#include "T100Instruct64Jmp.h"

#include "T100BitTypes.h"
#include "T100CPU64.h"

T100Instruct64Jmp::T100Instruct64Jmp(T100CPU64* cpu) :
    T100Instruct64(cpu)
{
    //ctor
}

T100Instruct64Jmp::~T100Instruct64Jmp()
{
    //dtor
}

T100VOID T100Instruct64Jmp::Append(T100INSTRUCT_HASH& instructs)
{
    instructs[0xE9]     = this;
}

T100VOID T100Instruct64Jmp::Execute(T100BYTE data)
{

}
