#include "T100BinocularParser.h"

#include "T100AssemblyCommon.h"
#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100BinocularParser::T100BinocularParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100BinocularParser::~T100BinocularParser()
{
    //dtor
}

T100BOOL T100BinocularParser::parse(::T100SentenceBase::T100OPERATOR_BINOCULAR& op)
{
    T100BOOL        result          = T100FALSE;

    result = getParent()->getComplexusParser().parse(op.TARGET);
    if(!result){
        return T100FALSE;
    }

    result = getParent()->getComplexusParser().parse(op.SOURCE);
    if(!result){
        return T100FALSE;
    }

    if(T100OPERATOR_THREE_THREE == op.TARGET.TYPE){
        op.TYPE         = T100OPERATOR_THREE_THREE;
        op.SOURCE.TYPE  = T100OPERATOR_THREE_THREE;
    }else if(T100OPERATOR_THREE_THREE == op.SOURCE.TYPE){
        op.TYPE         = T100OPERATOR_THREE_THREE;
        op.TARGET.TYPE  = T100OPERATOR_THREE_THREE;
    }else{
        op.TYPE         = T100OPERATOR_ONE_ONE;
    }
    return T100TRUE;
}

}
