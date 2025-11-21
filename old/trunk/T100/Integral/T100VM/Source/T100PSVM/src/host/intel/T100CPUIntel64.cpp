#include "T100CPUIntel64.h"

#include "T100BusIntel64.h"
#include "T100InstructSetIntel64.h"

#include "T100TypeTools.h"
#include "T100DebugFrame.h"

#include "T100TypeTools.h"
#include "T100PSVMInvoking.h"

T100CPUIntel64::T100CPUIntel64() :
    T100CPU()
{
    //ctor
    init();
}

T100CPUIntel64::~T100CPUIntel64()
{
    //dtor
    uninit();
}

T100VOID T100CPUIntel64::init()
{
    m_rdx.SetValue(0x60fb1);
    m_rip.SetValue(0xfff0);
    m_eflags.SetValue(0x2);
    m_cs.SetValue(0xf000);

    m_cr0.SetValue(0x60000010);
    m_mxcsr.SetValue(0x1f80);


    T100InstructSetIntel64      intel64(this);

    intel64.Append(m_instructs);
}

T100VOID T100CPUIntel64::uninit()
{

}

T100VOID T100CPUIntel64::SetBus(T100Bus* bus)
{
    m_bus   = dynamic_cast<T100BusIntel64*>(bus);
    T100CPU::SetBus(bus);
}

T100UINT16 T100CPUIntel64::GetAL()
{
    T100UINT64      value;

    value   = m_rax.GetValue();

    return value & 0xffff;
}

T100VOID T100CPUIntel64::SetRIP(T100UINT64 value)
{
    m_rip.SetValue(value);
}

T100UINT64 T100CPUIntel64::GetRIP()
{
    return m_rip.GetValue();
}

T100VOID T100CPUIntel64::SetEflags(T100UINT64 eflags)
{
    m_eflags.SetValue(eflags);
}

T100UINT64 T100CPUIntel64::GetEflags()
{
    return m_eflags.GetValue();
}

T100UINT64 T100CPUIntel64::GetAddress()
{
    T100UINT64      result;
    T100UINT64      cs;
    T100UINT64      ip;

    cs      = m_cs.GetValue();
    ip      = m_rip.GetValue();

    result  = (cs << 4) + ip;

    return result;
}

T100VOID T100CPUIntel64::Add()
{
    m_rip.SetValue(m_rip.GetValue() + 1);
}

T100BOOL T100CPUIntel64::Read(T100BYTE* data)
{
    Add();
    return m_bus->Read(GetAddress(), data);
}

T100BOOL T100CPUIntel64::Read(T100UINT16* data)
{
    Add();
    T100BOOL    result = m_bus->Read(GetAddress(), data);

    if(result){
        m_rip.SetValue(m_rip.GetValue() + 2);
    }
    return result;
}

T100BOOL T100CPUIntel64::Read(T100UINT32* data)
{
    Add();
    T100BOOL    result = m_bus->Read(GetAddress(), data);

    if(result){
        m_rip.SetValue(m_rip.GetValue() + 4);
    }
    return result;
}

T100BOOL T100CPUIntel64::Pulse()
{
    T100BYTE    data;

    if(m_bus->Read(GetAddress(), &data)){
        Execute(data);
        Add();
    }
    return T100TRUE;
}

T100VOID T100CPUIntel64::Execute(T100BYTE data)
{
    T100Instruct*       instruct        = T100NULL;

    instruct    = m_instructs[data];

    if(instruct){
        instruct->Execute(data);
        return;
    }

    switch(data){
    case 15:
        {
            Parse0F();
        }
        break;
    default:
        T100STRING  value   = "BYTE: " + T100TypeTools::to_string(data);
        T100PSVMInvoking::OnLog(value);
        break;
    }
}

T100VOID T100CPUIntel64::Parse0F()
{
    T100BYTE    data;
    if(!Read(&data)){
        return;
    }

    switch(data){
    case 32:
        {
            Parse20();
        }
        break;
    default:
        std::string     value   = std::to_string(data);
        //T100PSVMInvoking::OnLog(value);
    }
}

T100VOID T100CPUIntel64::Parse20()
{
    T100BYTE    data;
    if(!Read(&data)){
        return;
    }

    switch(data){
    case 192:
        {
            //mov     %cr0, %rax
            m_rax.SetValue(m_cr0.GetValue());
        }
        break;
    default:
        std::string     value   = std::to_string(data);
        //T100PSVMInvoking::OnLog(value);
    }
}

T100VOID T100CPUIntel64::Info(T100DebugFrame* frame)
{
    frame->ComboBoxRAX->SetValue(T100TypeTools::to_string(m_rax.GetValue()));
    frame->ComboBoxRBX->SetValue(T100TypeTools::to_string(m_rbx.GetValue()));
    frame->ComboBoxRCX->SetValue(T100TypeTools::to_string(m_rcx.GetValue()));
    frame->ComboBoxRDX->SetValue(T100TypeTools::to_string(m_rdx.GetValue()));

    frame->ComboBoxRSI->SetValue(T100TypeTools::to_string(m_rsi.GetValue()));
    frame->ComboBoxRDI->SetValue(T100TypeTools::to_string(m_rdi.GetValue()));
    frame->ComboBoxRBP->SetValue(T100TypeTools::to_string(m_rbp.GetValue()));
    frame->ComboBoxRSP->SetValue(T100TypeTools::to_string(m_rsp.GetValue()));

    frame->ComboBoxRIP->SetValue(T100TypeTools::to_string(m_rip.GetValue()));
    frame->ComboBoxCS->SetValue(T100TypeTools::to_string(m_cs.GetValue()));
    frame->ComboBoxSS->SetValue(T100TypeTools::to_string(m_ss.GetValue()));
    frame->ComboBoxDS->SetValue(T100TypeTools::to_string(m_ds.GetValue()));
    frame->ComboBoxES->SetValue(T100TypeTools::to_string(m_es.GetValue()));
    frame->ComboBoxFS->SetValue(T100TypeTools::to_string(m_fs.GetValue()));
    frame->ComboBoxGS->SetValue(T100TypeTools::to_string(m_gs.GetValue()));
    frame->ComboBoxFSBase->SetValue(T100TypeTools::to_string(m_fsBase.GetValue()));
    frame->ComboBoxGSBase->SetValue(T100TypeTools::to_string(m_gsBase.GetValue()));
    frame->ComboBoxKGSBase->SetValue(T100TypeTools::to_string(m_kGsBase.GetValue()));

    frame->ComboBoxR8->SetValue(T100TypeTools::to_string(m_r8.GetValue()));
    frame->ComboBoxR9->SetValue(T100TypeTools::to_string(m_r9.GetValue()));
    frame->ComboBoxR10->SetValue(T100TypeTools::to_string(m_r10.GetValue()));
    frame->ComboBoxR11->SetValue(T100TypeTools::to_string(m_r11.GetValue()));

    frame->ComboBoxR12->SetValue(T100TypeTools::to_string(m_r12.GetValue()));
    frame->ComboBoxR13->SetValue(T100TypeTools::to_string(m_r13.GetValue()));
    frame->ComboBoxR14->SetValue(T100TypeTools::to_string(m_r14.GetValue()));
    frame->ComboBoxR15->SetValue(T100TypeTools::to_string(m_r15.GetValue()));

    frame->ComboBoxEFLAGS->SetValue(T100TypeTools::to_string(m_eflags.GetValue()));
    frame->ComboBoxEFER->SetValue(T100TypeTools::to_string(m_efer.GetValue()));
    frame->ComboBoxMXCSR->SetValue(T100TypeTools::to_string(m_mxcsr.GetValue()));
}
