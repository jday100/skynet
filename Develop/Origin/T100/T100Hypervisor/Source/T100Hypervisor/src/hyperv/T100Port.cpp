#include "T100Port.h"

#include <iostream>
#include <winhvplatform.h>
#include <winhvemulation.h>

T100Port::T100Port()
{
    //ctor
}

T100Port::~T100Port()
{
    //dtor
}

T100VOID T100Port::Run(WHV_EMULATOR_HANDLE emulator, WHV_RUN_VP_EXIT_CONTEXT& context)
{
    if(context.IoPortAccess.AccessInfo.IsWrite && context.IoPortAccess.AccessInfo.AccessSize == 1
       && !context.IoPortAccess.AccessInfo.StringOp && context.IoPortAccess.PortNumber == 0x3F8){
        std::cout << char(context.IoPortAccess.Rax);
    }

    if(context.IoPortAccess.AccessInfo.IsWrite){
        Write(emulator, context);
    }else{
        Read(emulator, context);
    }
}

T100VOID T100Port::Write(WHV_EMULATOR_HANDLE emulator, WHV_RUN_VP_EXIT_CONTEXT& context)
{
    std::cout << "Write: ";
    std::cout << context.IoPortAccess.PortNumber;
    std::cout << std::endl;
}

/*
5066
10250
85
30809
*/
T100VOID T100Port::Read(WHV_EMULATOR_HANDLE emulator, WHV_RUN_VP_EXIT_CONTEXT& context)
{
    std::cout << "Read: ";
    std::cout << context.IoPortAccess.PortNumber;
    std::cout << std::endl;

    //WHvEmulatorCreateEmulator();

    //WHV_EMULATOR_HANDLE     emulator;
    WHV_EMULATOR_STATUS     status;
    void*                   cpu     = T100NULL;

    HRESULT result = WHvEmulatorTryIoEmulation(emulator, cpu, &context.VpContext, &context.IoPortAccess, &status);

    if(result == 0){
        return;
    }
}
