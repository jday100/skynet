#include "T100InstructIntel64Jmp.h"

#include "T100BitTypes.h"
#include "T100CPUIntel64.h"

T100InstructIntel64Jmp::T100InstructIntel64Jmp(T100CPUIntel64* cpu) :
    T100InstructIntel64(cpu)
{
    //ctor
    m_byte      = 0xE9;
}

T100InstructIntel64Jmp::~T100InstructIntel64Jmp()
{
    //dtor
}

T100VOID T100InstructIntel64Jmp::Execute(T100BYTE)
{
    /*
    T100DATA32_BITS     value;

    if(m_cpu->Read(&(value.DATA32))){
        m_cpu->SetRIP(value.DATA32);
    }
    */

    T100DATA16_BITS     value;

    if(m_cpu->Read(&(value.DATA16))){
        m_cpu->SetRIP(value.DATA16 - 2);
    }
}
