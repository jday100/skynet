#include "T100OrderMove.h"

T100OrderMove::T100OrderMove(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderMove::~T100OrderMove()
{
    //dtor
}

T100BOOL T100OrderMove::run()
{
    T100BOOL            result;

    result = parse(target, source);

    if(!result){
        return T100FALSE;
    }

    return result;
}

T100VOID T100OrderMove::log()
{

}
