#include "T100Instruct64Test.h"

T100Instruct64Test::T100Instruct64Test(T100CPU64* cpu) :
    T100Instruct64(cpu)
{
    //ctor
}

T100Instruct64Test::~T100Instruct64Test()
{
    //dtor
}

T100VOID T100Instruct64Test::Append(T100INSTRUCT_HASH& instructs)
{
    instructs[0xA8]     = this;
}

T100VOID T100Instruct64Test::Execute(T100BYTE data)
{

}
