#include "T100InstructIntel64Test.h"

#include "T100CPUIntel64.h"

T100InstructIntel64Test::T100InstructIntel64Test(T100CPUIntel64* cpu) :
    T100InstructIntel64(cpu)
{
    //ctor
    m_byte      = 0xA8;
}

T100InstructIntel64Test::~T100InstructIntel64Test()
{
    //dtor
}

T100VOID T100InstructIntel64Test::Execute(T100BYTE)
{
    T100BYTE    value;
    T100UINT16  al;

    if(!m_cpu->Read(&value)){
        return;
    }
    al  = m_cpu->GetAL();

    if(value & al){

    }else{
        T100UINT64      eflags  = m_cpu->GetEflags();

        eflags  = eflags | 0x44;

        m_cpu->SetEflags(eflags);
    }
}
