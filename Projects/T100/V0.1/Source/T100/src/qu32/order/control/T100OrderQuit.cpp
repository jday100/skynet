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
    T100BOOL        result          = T100TRUE;

    result = parseMonoBuild(target);
    if(!result){
        return T100FALSE;
    }

    result = getGdt()->quit(target.BASE.VALUE, target.OPERATOR.VALUE);

    return result;
}

T100VOID T100OrderQuit::log()
{

}

}
