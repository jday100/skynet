#include "T100Instruct64Je.h"

T100Instruct64Je::T100Instruct64Je(T100CPU64* cpu) :
    T100Instruct64(cpu)
{
    //ctor
}

T100Instruct64Je::~T100Instruct64Je()
{
    //dtor
}

T100VOID T100Instruct64Je::Append(T100INSTRUCT_HASH& instructs)
{
    instructs[0x74]     = this;
}

T100VOID T100Instruct64Je::Execute(T100BYTE data)
{

}
