#include "T100OrderCmt.h"

#include "T100TestTools.h"

namespace T100QU32{

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
        T100Library::T100TestTools::Print(std::to_wstring(id));

        getHost()->getNotifier().notify_cmt_update(id);
    }

    getHost()->getExecutor32()->pauseComment();
    return T100TRUE;
}

T100VOID T100OrderCmt::log()
{

}

}
