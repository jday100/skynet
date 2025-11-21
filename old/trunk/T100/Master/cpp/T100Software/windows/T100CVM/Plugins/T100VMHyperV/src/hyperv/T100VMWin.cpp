#include "T100VMWin.h"

#include <cstring>
#include <iostream>
#include <windows.h>
#include <winhvplatform.h>

#define     ENSURE(x)       do { if(!(x)) { std::cerr << L"Error: " #x " is false!" << std::endl; std::exit(1); } } while(0)

T100VMWin::T100VMWin() :
    T100VMBase()
{
    //ctor
}

T100VMWin::~T100VMWin()
{
    //dtor
}

T100VOID T100VMWin::Start()
{
    BOOL        hypervisorPresent       = false;
    ENSURE(WHvGetCapability(WHvCapabilityCodeHypervisorPresent, &hypervisorPresent,
        sizeof(hypervisorPresent), nullptr) == S_OK);

    if(!hypervisorPresent){
        return;
    }

    WHV_PARTITION_HANDLE    partition = nullptr;

    ENSURE(WHvCreatePartition(&partition) == S_OK);

    UINT32 processorCount = 1;

    ENSURE(WHvSetPartitionProperty(partition, WHvPartitionPropertyCodeProcessorCount,
        &processorCount, sizeof(processorCount)) == S_OK);
    ENSURE(WHvSetupPartition(partition) == S_OK);
    ENSURE(WHvCreateVirtualProcessor(partition, 0, 0) == S_OK);

    std::vector<T100UINT8>      code;

    code.insert(code.end(), {0xba, 0xf8, 0x03});
    for(T100UINT8 c : T100STDSTRING("Hello, Hyper-V!\n"))
    code.insert(code.end(), {0xb0, c, 0xee});

    code.insert(code.end(), {0xf4});

    T100UINT64  memorySize  = 0x00001000, memoryOffset = 0x00001000;

    void* memory = VirtualAlloc(nullptr, memorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    ENSURE(memory != nullptr);
    std::memcpy(memory, code.data(), code.size());

    ENSURE(WHvMapGpaRange(partition, memory, memoryOffset, memorySize,
        WHvMapGpaRangeFlagRead | WHvMapGpaRangeFlagWrite | WHvMapGpaRangeFlagExecute) == S_OK);

    WHV_REGISTER_NAME   name = WHvX64RegisterCs;
    WHV_REGISTER_VALUE  value = {};

    value.Segment.Base  = 0x00000000;
    value.Segment.Limit = 0x0000ffff;
    value.Segment.Selector = 0x0000;
    value.Segment.Attributes = 0x009b;

    ENSURE(WHvSetVirtualProcessorRegisters(partition, 0, &name, 1, &value) == S_OK);

    auto getRIP = [partition]() ->T100UINT64 {
        WHV_REGISTER_NAME       name = WHvX64RegisterRip;
        WHV_REGISTER_VALUE      value = {};
        ENSURE(WHvGetVirtualProcessorRegisters(partition, 0, &name, 1, &value) == S_OK);
        return value.Reg64;
    };

    auto setRIP = [partition](T100UINT64 rip) {
        WHV_REGISTER_NAME       name = WHvX64RegisterRip;
        WHV_REGISTER_VALUE      value = {};
        value.Reg64 = rip;
        ENSURE(WHvSetVirtualProcessorRegisters(partition, 0, &name, 1, &value) == S_OK);
    };

    setRIP(memoryOffset);

    while(true){
        WHV_RUN_VP_EXIT_CONTEXT     context = {};
        ENSURE(WHvRunVirtualProcessor(partition, 0, &context, sizeof(context)) == S_OK);

        switch(context.ExitReason){
        case WHvRunVpExitReasonX64IoPortAccess:
            {
                if(context.IoPortAccess.AccessInfo.IsWrite && context.IoPortAccess.AccessInfo.AccessSize == 1
                   && !context.IoPortAccess.AccessInfo.StringOp && context.IoPortAccess.PortNumber == 0x3F8)
                    std::cout << char(context.IoPortAccess.Rax);

                setRIP(getRIP() + context.VpContext.InstructionLength);
                break;
            }
        case WHvRunVpExitReasonX64Halt:
            {
                std::cerr << "VM Halt" << std::endl;
                WHvDeletePartition(partition);
                return;
            }
        default:
            {
                std::cerr << "Unexpected Exit Reason : " <<context.ExitReason << std::endl;
                return;
            }
        }

    }
}

T100VOID T100VMWin::Stop()
{

}
