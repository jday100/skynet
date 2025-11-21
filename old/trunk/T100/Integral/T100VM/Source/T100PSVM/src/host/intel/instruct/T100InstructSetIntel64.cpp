#include "T100InstructSetIntel64.h"

#include "T100AllInstructsIntel64.h"

T100InstructSetIntel64::T100InstructSetIntel64(T100CPUIntel64* cpu) :
    m_cpu(cpu)
{
    //ctor
}

T100InstructSetIntel64::~T100InstructSetIntel64()
{
    //dtor
}

T100VOID T100InstructSetIntel64::Append(T100INSTRUCT_HASH& instructs)
{
    T100InstructIntel64Je*          je          = T100NEW T100InstructIntel64Je(m_cpu);

    instructs[je->m_byte]           = je;

    T100InstructIntel64Jz*          jz          = T100NEW T100InstructIntel64Jz(m_cpu);

    instructs[jz->m_byte]           = jz;

    T100InstructIntel64Jmp*         jmp         = T100NEW T100InstructIntel64Jmp(m_cpu);

    instructs[jmp->m_byte]          = jmp;

    T100InstructIntel64Mov*         mov         = T100NEW T100InstructIntel64Mov(m_cpu);

    instructs[mov->m_byte]          = mov;

    T100InstructIntel64Test*        test        = T100NEW T100InstructIntel64Test(m_cpu);

    instructs[test->m_byte]         = test;


}
