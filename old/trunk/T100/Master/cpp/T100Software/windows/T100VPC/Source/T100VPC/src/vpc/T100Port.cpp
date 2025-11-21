#include "T100Port.h"

#include <iostream>

T100Port::T100Port()
{
    //ctor
}

T100Port::~T100Port()
{
    //dtor
}

T100VOID T100Port::Run(WHV_RUN_VP_EXIT_CONTEXT& context, T100VPCFrame* frame)
{
    if(context.IoPortAccess.AccessInfo.IsWrite && context.IoPortAccess.AccessInfo.AccessSize == 1
       && !context.IoPortAccess.AccessInfo.StringOp && context.IoPortAccess.PortNumber == 0x3F8){
        std::cout << char(context.IoPortAccess.Rax);
        frame->Value    += wchar_t(context.IoPortAccess.Rax);
    }
}
