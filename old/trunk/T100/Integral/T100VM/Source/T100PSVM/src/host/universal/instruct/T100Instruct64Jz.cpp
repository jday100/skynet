#include "T100Instruct64Jz.h"

T100Instruct64Jz::T100Instruct64Jz(T100CPU64* cpu) :
    T100Instruct64(cpu)
{
    //ctor
}

T100Instruct64Jz::~T100Instruct64Jz()
{
    //dtor
}

T100VOID T100Instruct64Jz::Append(T100INSTRUCT_HASH& instructs)
{
    instructs[0x74]     = this;
}

T100VOID T100Instruct64Jz::Execute(T100BYTE data)
{

}
