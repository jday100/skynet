#include "T100InstructIntel64Mov.h"

#include "T100BitTypes.h"
#include "T100CPUIntel64.h"

T100InstructIntel64Mov::T100InstructIntel64Mov(T100CPUIntel64* cpu) :
    T100InstructIntel64(cpu)
{
    //ctor
    m_byte      = 0xBF;
}

T100InstructIntel64Mov::~T100InstructIntel64Mov()
{
    //dtor
}

T100VOID T100InstructIntel64Mov::Execute(T100BYTE)
{
    T100DATA16_BITS     value;

    if(m_cpu->Read(&(value.DATA16))){

    }
}
