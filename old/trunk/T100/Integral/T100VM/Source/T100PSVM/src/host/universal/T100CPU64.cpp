#include "T100CPU64.h"

#include "T100TypeTools.h"
#include "T100DebugFrame.h"
#include "T100Host64.h"
#include "T100InstructSet64.h"
#include "T100PSVMInvoking.h"

T100CPU64::T100CPU64(T100Host64* host) :
    T100CPU64Base(host)
{
    //ctor
    init();
}

T100CPU64::~T100CPU64()
{
    //dtor
    uninit();
}

T100VOID T100CPU64::init()
{
    m_flag  = T100FALSE;
    m_count = 0;
    m_delay = 2;

    m_rdx.SetValue(0x60fb1);
    m_rip.SetValue(0xfff0);
    m_eflags.SetValue(0x2);
    m_cs.SetValue(0xf000);

    m_cr0.SetValue(0x60000010);
    m_mxcsr.SetValue(0x1f80);

    T100InstructSet64       instruct64(this);

    instruct64.Append(m_instructs);
}

T100VOID T100CPU64::uninit()
{

}

/*
T100VOID T100CPU64::Execute()
{
    static T100BYTE     data;

    if(m_flag){
        m_count++;

        if(m_count >= m_delay){
            T100BOOL    busy        = m_host->m_bus.IsBusy();

            if(busy){
                if(m_host->m_bus.IsReady()){
                    //T100BYTE    data;
                    m_host->m_bus.Read(GetAddress(), &data);
                    m_flag      = T100FALSE;
                    m_count     = 0;

                    Parse(data);
                }else{
                    //Parse(data);
                }
            }else{
                m_host->m_bus.Acquire(/ *GetAddress()* /);

                if(m_host->m_bus.IsReady()){
                    T100BYTE    data;
                    m_host->m_bus.Read(GetAddress(), &data);
                    m_flag      = T100FALSE;
                    m_count     = 0;
                }
            }
        }
    }else{
        m_flag  = T100TRUE;
    }
}
*/

T100VOID T100CPU64::Parse(T100BYTE data)
{
    T100Instruct*       instruct        = T100NULL;

    instruct    = m_instructs[data];

    if(instruct){
        instruct->Execute(data);
        return;
    }

    switch(data){
    default:
        T100STRING      value   = "BYTE: " + T100TypeTools::to_string(data);
        T100PSVMInvoking::OnLog(value);
    }
}

T100VOID T100CPU64::Info(T100DebugFrame* frame)
{
    if(!frame)
    {
        return;
    }

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
