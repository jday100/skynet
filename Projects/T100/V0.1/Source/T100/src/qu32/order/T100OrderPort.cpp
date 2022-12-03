#include "T100OrderPort.h"

namespace T100QU32{

T100OrderPort::T100OrderPort(T100QU32* host, T100Executor32* exec)
    :T100OrderAll(host, exec)
{
    //ctor
}

T100OrderPort::~T100OrderPort()
{
    //dtor
}

}
