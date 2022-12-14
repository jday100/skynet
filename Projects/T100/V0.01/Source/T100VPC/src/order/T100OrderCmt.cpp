#include "T100OrderCmt.h"

#include "T100TestTools.h"
#include "T100QU32Setup.h"


T100OrderCmt::T100OrderCmt(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderCmt::~T100OrderCmt()
{
    //dtor
}

T100BOOL T100OrderCmt::run()
{
    id = getHost()->getCU32()->step();

    if(T100QU32Setup::DEBUG){
        T100TestTools::Print(std::to_wstring(id));
    }

    getHost()->getExecutor32()->pauseComment();

    return T100TRUE;
}

T100VOID T100OrderCmt::log()
{

}
