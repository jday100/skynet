#include "T100OrderNop.h"

T100OrderNop::T100OrderNop(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderNop::~T100OrderNop()
{
    //dtor
}

T100BOOL T100OrderNop::run()
{
    return T100TRUE;
}

T100VOID T100OrderNop::log()
{

}
