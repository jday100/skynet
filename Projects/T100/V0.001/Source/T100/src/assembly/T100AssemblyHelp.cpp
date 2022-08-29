#include "T100AssemblyHelp.h"

#include "T100AssemblyHint.h"


T100AssemblyHelp::T100AssemblyHelp()
{
    //ctor
}

T100AssemblyHelp::~T100AssemblyHelp()
{
    //dtor
}

T100BOOL T100AssemblyHelp::show()
{
    T100Log::out(T100AssemblyHint::help_hint(""));
    return T100TRUE;
}
