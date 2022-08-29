#include "T100OrderDebug.h"

T100OrderDebug::T100OrderDebug(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderDebug::~T100OrderDebug()
{
    //dtor
}

T100BOOL T100OrderDebug::run()
{
    getExecutor()->debug();

    return T100TRUE;
}

T100VOID T100OrderDebug::log()
{

}
