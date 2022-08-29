#include "T100CmdLineExec.h"

T100CmdLineExec::T100CmdLineExec()
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
