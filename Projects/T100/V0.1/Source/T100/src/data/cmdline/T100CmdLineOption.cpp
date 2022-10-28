#include "T100CmdLineOption.h"

namespace T100Library{

T100CmdLineOption::T100CmdLineOption()
{
    //ctor
    create();
}

T100CmdLineOption::~T100CmdLineOption()
{
    //dtor
    destroy();
}

T100VOID T100CmdLineOption::create()
{
    type = T100CMDLINE_OPTION;
}

T100VOID T100CmdLineOption::destroy()
{

}

}
