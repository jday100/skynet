#include "T100CmdLineParam.h"

namespace T100Library{

T100CmdLineParam::T100CmdLineParam()
{
    //ctor
    create();
}

T100CmdLineParam::~T100CmdLineParam()
{
    //dtor
    destroy();
}

T100VOID T100CmdLineParam::create()
{
    type = T100CMDLINE_PARAM;
}

T100VOID T100CmdLineParam::destroy()
{

}

}
