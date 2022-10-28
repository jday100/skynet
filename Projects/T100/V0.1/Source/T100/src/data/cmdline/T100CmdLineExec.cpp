#include "T100CmdLineExec.h"

namespace T100Library{

T100CmdLineExec::T100CmdLineExec()
    :T100CmdLineInfo()
{
    //ctor
    create();
}

T100CmdLineExec::~T100CmdLineExec()
{
    //dtor
    destroy();
}

T100VOID T100CmdLineExec::create()
{
    type = T100CMDLINE_EXEC;
}

T100VOID T100CmdLineExec::destroy()
{

}

}
