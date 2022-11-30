#include "T100ComplexusBuilder.h"

#include "T100ProduceInfo.h"
#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100ComplexusBuilder::T100ComplexusBuilder(T100SentenceBase* base)
    :T100BuilderBase(base)
{
    //ctor
}

T100ComplexusBuilder::~T100ComplexusBuilder()
{
    //dtor
}

T100BOOL T100ComplexusBuilder::build(T100Assembly::T100BuildInfo* info, T100OPERATOR_COMPLEXUS& op, T100OPERATOR_COMPLEXUS_BUILD& build)
{
    T100BOOL        result          = T100FALSE;

    if(op.BASE.USED){
        result = getParent()->getOperatorBuilder().build(info, op.BASE, build.BASE);
    }else{
        result = T100TRUE;
    }

    if(result){
        result = getParent()->getOperatorBuilder().build(info, op.OFFSET, build.OPERATOR);
    }

    return result;
}

}
