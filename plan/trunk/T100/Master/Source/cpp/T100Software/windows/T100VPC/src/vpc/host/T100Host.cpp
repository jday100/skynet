#include "T100Host.h"

#include "T100VPCCommon.h"
#include "T100Keyboard.h"
#include "T100Mouse.h"
#include "T100VPCInvoking.h"

T100Host::T100Host() :
    m_port(),
    m_memory(),
    m_device(),
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
    Install();
}

T100VOID T100Host::uninit()
{

}

T100VOID T100Host::Start()
{
    T100UINT64      memorySize      = 0x01000000;
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
                m_port.Run(m_emulator, context);

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

T100VOID T100Host::Install()
{
    T100Mouse*          mouse       = T100NEW T100Mouse();
    T100Keyboard*       keyboard    = T100NEW T100Keyboard();

    m_device.Install(mouse);
    m_device.Install(keyboard);

    /*
    WHV_EMULATOR_CALLBACKS*         callback    = T100NEW WHV_EMULATOR_CALLBACKS;

    callback->Size       = sizeof(WHV_EMULATOR_CALLBACKS);
    callback->WHvEmulatorMemoryCallback      = T100VPCInvoking::OnMemoryCallback;
    callback->WHvEmulatorIoPortCallback      = T100VPCInvoking::OnIoPortCallback;
    callback->WHvEmulatorGetVirtualProcessorRegisters    = T100VPCInvoking::OnGetRegistersCallback;
    callback->WHvEmulatorSetVirtualProcessorRegisters    = T100VPCInvoking::OnSetRegistersCallback;
    callback->WHvEmulatorTranslateGvaPage    = T100VPCInvoking::OnTranslateGvaPageCallback;

    HRESULT result = WHvEmulatorCreateEmulator(callback, &m_emulator);
    */
    WHV_EMULATOR_CALLBACKS          callback;

    callback.Size       = sizeof(WHV_EMULATOR_CALLBACKS);
    callback.WHvEmulatorMemoryCallback      = T100VPCInvoking::OnMemoryCallback;
    callback.WHvEmulatorIoPortCallback      = T100VPCInvoking::OnIoPortCallback;
    callback.WHvEmulatorGetVirtualProcessorRegisters    = T100VPCInvoking::OnGetRegistersCallback;
    callback.WHvEmulatorSetVirtualProcessorRegisters    = T100VPCInvoking::OnSetRegistersCallback;
    callback.WHvEmulatorTranslateGvaPage    = T100VPCInvoking::OnTranslateGvaPageCallback;

    HRESULT result = WHvEmulatorCreateEmulator(&callback, &m_emulator);

    if(result == 0){
        return;
    }
}
