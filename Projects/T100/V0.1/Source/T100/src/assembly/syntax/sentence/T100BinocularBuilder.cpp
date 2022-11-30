#include "T100BinocularBuilder.h"

#include "T100SentenceBase.h"
#include "T100ProduceInfo.h"

namespace T100SentenceBase{

T100BinocularBuilder::T100BinocularBuilder(T100SentenceBase* base)
    :T100BuilderBase(base)
{
    //ctor
}

T100BinocularBuilder::~T100BinocularBuilder()
{
    //dtor
}

T100BOOL T100BinocularBuilder::build(T100Assembly::T100BuildInfo* info, T100OPERATOR_BINOCULAR& op, T100OPERATOR_BINOCULAR_BUILD& build)
{
    T100BOOL        result          = T100FALSE;

    build.TYPE      = op.TYPE;

    switch(op.TYPE){
    case T100OPERATOR_ONE_ONE:
        {
            build.TARGET.OFFSET     = 0;
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            build.TARGET.OFFSET     = 1;
        }
        break;
    default:
        build.TARGET.OFFSET     = 0;
    }

    result = getParent()->getComplexusBuilder().build(info, op.TARGET, build.TARGET);
    if(!result){
        return T100FALSE;
    }

    build.SOURCE.OFFSET     = build.TARGET.OFFSET;

    result = getParent()->getComplexusBuilder().build(info, op.SOURCE, build.SOURCE);

    return result;
}

}
