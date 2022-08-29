#include "T100OrderXor.h"

T100OrderXor::T100OrderXor(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderXor::~T100OrderXor()
{
    //dtor
}

T100BOOL T100OrderXor::run()
{
    getHost()->getAU32()->Xor();

    return T100TRUE;
}

T100VOID T100OrderXor::log()
{

}
