#include "T100OrderQuit.h"

namespace T100QU32{

T100OrderQuit::T100OrderQuit(T100QU32* host, T100Executor32* exec)
    :T100OrderBase(host, exec)
{
    //ctor
}

T100OrderQuit::~T100OrderQuit()
{
    //dtor
}

T100BOOL T100OrderQuit::run()
{

}

T100VOID T100OrderQuit::log()
{

}

}
