#include "T100OrderStore.h"

namespace T100QU32{

T100OrderStore::T100OrderStore(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderStore::~T100OrderStore()
{
    //dtor
}

T100BOOL T100OrderStore::run()
{
    return T100TRUE;
}

T100VOID T100OrderStore::log()
{

}

}
