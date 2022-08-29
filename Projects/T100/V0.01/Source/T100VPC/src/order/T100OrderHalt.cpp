#include "T100OrderHalt.h"

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
    getHost()->done();

    return T100TRUE;
}

T100VOID T100OrderHalt::log()
{

}
