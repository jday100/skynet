#include "T100InstructIntel64Je.h"

#include "T100CPUIntel64.h"

T100InstructIntel64Je::T100InstructIntel64Je(T100CPUIntel64* cpu) :
    T100InstructIntel64(cpu)
{
    //ctor
    m_byte      = 0x74;
}

T100InstructIntel64Je::~T100InstructIntel64Je()
{
    //dtor
}

T100VOID T100InstructIntel64Je::Execute(T100BYTE)
{
    T100UINT64  eflags;
    T100BYTE    value;

    eflags  = m_cpu->GetEflags();

    if(!m_cpu->Read(&value)){
        return;
    }

    if(eflags & 0x40){
        T100UINT64  offset  = m_cpu->GetRIP() + value;

        m_cpu->SetRIP(offset);
    }
}
