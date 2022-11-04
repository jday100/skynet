#include "T100OrderHalt.h"

namespace T100QU32{

T100OrderHalt::T100OrderHalt(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderHalt::~T100OrderHalt()
{
    //dtor
}

T100BOOL T100OrderHalt::run()
{
    getHost()->halt();
    return T100TRUE;
}

T100VOID T100OrderHalt::log()
{

}

}
