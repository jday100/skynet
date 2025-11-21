#include "T100Processor.h"

#include "T100VPCCommon.h"

T100Processor::T100Processor()
{
    //ctor
}

T100Processor::~T100Processor()
{
    //dtor
}

T100VOID T100Processor::SetRIP(T100UINT64 rip)
{
    WHV_REGISTER_NAME       name        = WHvX64RegisterRip;
    WHV_REGISTER_VALUE      value       = {};

    value.Reg64     = rip;

    ENSURE(WHvSetVirtualProcessorRegisters(m_partition, 0, &name, 1, &value) == S_OK);
}

T100UINT64 T100Processor::GetRIP()
{
    WHV_REGISTER_NAME       name        = WHvX64RegisterRip;
    WHV_REGISTER_VALUE      value       = {};

    ENSURE(WHvGetVirtualProcessorRegisters(m_partition, 0, &name, 1, &value) == S_OK);

    return value.Reg64;
}

T100VOID T100Processor::Create(WHV_PARTITION_HANDLE handler, T100UINT value)
{
    m_partition     = handler;

    ENSURE(WHvSetPartitionProperty(handler, WHvPartitionPropertyCodeProcessorCount,
        &value, sizeof(value)) == S_OK);
    ENSURE(WHvSetupPartition(handler) == S_OK);
    ENSURE(WHvCreateVirtualProcessor(handler, 0, 0) == S_OK);
}

T100VOID T100Processor::Start()
{
    WHV_REGISTER_NAME       name        = WHvX64RegisterCs;
    WHV_REGISTER_VALUE      value       = {};

    value.Segment.Base          = 0x00000000;
    //value.Segment.Limit         = 0x0000ffff;
    value.Segment.Limit         = 0x000fffff;
    value.Segment.Selector      = 0x0000;
    value.Segment.Attributes    = 0x009b;

    ENSURE(WHvSetVirtualProcessorRegisters(m_partition, 0, &name, 1, &value) == S_OK);
}

T100VOID T100Processor::Run(WHV_RUN_VP_EXIT_CONTEXT& context)
{
    ENSURE(WHvRunVirtualProcessor(m_partition, 0, &context, sizeof(context)) == S_OK);
}
