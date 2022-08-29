#include "T100CmdLineSwitch.h"

T100CmdLineSwitch::T100CmdLineSwitch()
{
    //ctor
    create();
}

T100CmdLineSwitch::~T100CmdLineSwitch()
{
    //dtor
    destroy();
}

T100VOID T100CmdLineSwitch::create()
{
    type = T100CMDLINE_SWITCH;
}

T100VOID T100CmdLineSwitch::destroy()
{

}
