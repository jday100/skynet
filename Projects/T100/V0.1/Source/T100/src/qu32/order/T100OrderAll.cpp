#include "T100OrderAll.h"

namespace T100QU32{

T100OrderAll::T100OrderAll(T100QU32* host, T100Executor32* exec)
    :T100OrderOperator(host, exec)
{
    //ctor
}

T100OrderAll::~T100OrderAll()
{
    //dtor
}

T100BOOL T100OrderAll::parseOperatorAllBuild(T100SentenceBase::T100OPERATOR_BUILD& build)
{

}

T100BOOL T100OrderAll::loadOperatorAllBuild(T100SentenceBase::T100OPERATOR_BUILD& build)
{

}

}
