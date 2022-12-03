#include "T100ComplexusBuilder.h"

#include "T100BitTypes.h"
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
        build.BASE.USED = T100TRUE;
        result = getParent()->getOperatorBuilder().build(info, op.BASE, build.BASE);
    }else{
        result = T100TRUE;
    }

    if(result){
        build.OPERATOR.DEVIANT = build.BASE.DEVIANT;
        result = getParent()->getOperatorBuilder().build(info, op.OPERATOR, build.OPERATOR);
    }

    return result;
}

T100BOOL T100ComplexusBuilder::build(T100Assembly::T100BuildInfo* info, T100OPERATOR_COMPLEXUS& target, T100Component::T100ORDER_TYPE type)
{
    T100BOOL            result;
    T100WORD_BITS       order;
    ::T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD        build;

    order.BYTE0.BYTE    = type;

    result = this->build(info, target, build);
    if(!result){
        return T100FALSE;
    }

    order.BYTE2.BYTE    = build.BASE.TYPE;
    order.BYTE3.BYTE    = build.OPERATOR.TYPE;

    info->setValue(order.WORD);
    info->next();

    if(build.BASE.USED && build.BASE.FLAG){
        info->setValue(build.BASE.VALUE);
        info->next();
    }

    if(build.OPERATOR.FLAG){
        info->setValue(build.OPERATOR.VALUE);
        info->next();
    }

    return result;
}

}
