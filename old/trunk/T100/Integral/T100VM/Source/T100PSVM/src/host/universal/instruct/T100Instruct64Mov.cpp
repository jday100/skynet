#include "T100Instruct64Mov.h"

#include "T100CPU64.h"

T100Instruct64Mov::T100Instruct64Mov(T100CPU64* cpu) :
    T100Instruct64(cpu)
{
    //ctor
    m_count     = 0;
}

T100Instruct64Mov::~T100Instruct64Mov()
{
    //dtor
}

T100VOID T100Instruct64Mov::Append(T100INSTRUCT_HASH& instructs)
{
    instructs[0x0F]     = this;
    instructs[0xBF]     = this;
}

T100VOID T100Instruct64Mov::Execute(T100BYTE data)
{
    switch(m_count){
    case 0:
        {
            switch(data){
            case 0x0F:
                {
                }
                break;
            }
            m_count++;
        }
        break;
    case 1:
        {
            switch(data){
            case 0x20:
                {
                }
                break;
            }
            m_count++;
        }
        break;
    case 2:
        {
            switch(data){
            case 0xB0:
                {
                    m_cpu->m_rax.SetValue(m_cpu->m_cr0.GetValue());
                    m_count = 0;
                }
                break;
            }
            m_count++;
        }
        break;
    }
}
