#include "T100Host.h"

#include "T100VPCCommon.h"

T100Host::T100Host() :
    m_port(),
    m_memory(),
    m_processor()
{
    //ctor
    init();
}

T100Host::~T100Host()
{
    //dtor
    uninit();
}

T100VOID T100Host::init()
{

}

T100VOID T100Host::uninit()
{

}

T100VOID T100Host::SetFrame(T100VPCFrame* frame)
{
    m_frame     = frame;
}

T100VOID T100Host::Start()
{
    T100UINT64      memorySize      = 0x00010000;
    T100UINT64      memoryOffset    = 0x00000000;

    //T100UINT64      memorySize      = 0x00001000;
    //T100UINT64      memoryOffset    = 0x00001000;

    ENSURE(WHvGetCapability(WHvCapabilityCodeHypervisorPresent, &m_hypervisorPresent,
        sizeof(m_hypervisorPresent), T100NULL) == S_OK);

    if(!m_hypervisorPresent){
        return;
    }

    ENSURE(WHvCreatePartition(&m_partition) == S_OK);

    m_processor.Create(m_partition, 1);

    m_memory.Create(m_partition, memorySize, memoryOffset);
    m_memory.Load(m_partition);

    m_processor.Start();
    m_processor.SetRIP(m_memory.GetOffset());

    Run();
}

T100VOID T100Host::Stop()
{

}

T100VOID T100Host::Run()
{
    while(T100TRUE){
        WHV_RUN_VP_EXIT_CONTEXT     context = {};
        m_processor.Run(context);

        switch(context.ExitReason){
        case WHvRunVpExitReasonX64IoPortAccess:
            {
                m_port.Run(context, m_frame);

                m_processor.SetRIP(m_processor.GetRIP() + context.VpContext.InstructionLength);
                break;
            }
        case WHvRunVpExitReasonX64Halt:
            {
                std::cerr << "VM Halt" << std::endl;
                WHvDeletePartition(m_partition);
                return;
            }
        default:
            {
                std::cerr << context.MemoryAccess.AccessInfo.AccessType << std::endl;
                std::cerr << "Unexpected Exit Reason : " <<context.ExitReason << std::endl;
                return;
            }
        }

    }
}
