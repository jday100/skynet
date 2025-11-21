#include "T100InstructSet64.h"

#include "T100AllInstructs64.h"

T100InstructSet64::T100InstructSet64(T100CPU64* cpu) :
    m_cpu(cpu)
{
    //ctor
}

T100InstructSet64::~T100InstructSet64()
{
    //dtor
}

T100VOID T100InstructSet64::Append(T100INSTRUCT_HASH& instructs)
{
    T100Instruct64Je*       je      = T100NEW T100Instruct64Je(m_cpu);

    je->Append(instructs);

    T100Instruct64Jz*       jz      = T100NEW T100Instruct64Jz(m_cpu);

    jz->Append(instructs);

    T100Instruct64Jmp*      jmp     = T100NEW T100Instruct64Jmp(m_cpu);

    jmp->Append(instructs);

    T100Instruct64Mov*      mov     = T100NEW T100Instruct64Mov(m_cpu);

    mov->Append(instructs);

    T100Instruct64Test*     test    = T100NEW T100Instruct64Test(m_cpu);

    test->Append(instructs);
}
