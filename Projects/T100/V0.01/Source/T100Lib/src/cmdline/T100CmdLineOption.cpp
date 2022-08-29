#include "T100CmdLineOption.h"

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
