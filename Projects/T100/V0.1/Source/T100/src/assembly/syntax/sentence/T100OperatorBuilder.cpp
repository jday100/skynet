#include "T100OperatorBuilder.h"

#include "T100ProduceInfo.h"
#include "T100VariableDrawer.h"


namespace T100SentenceBase{

T100OperatorBuilder::T100OperatorBuilder(T100SentenceBase* base)
    :T100BuilderBase(base)
{
    //ctor
}

T100OperatorBuilder::~T100OperatorBuilder()
{
    //dtor
}

T100BOOL T100OperatorBuilder::build(T100Assembly::T100BuildInfo* info, T100OPERATOR& target, T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100FALSE;

    switch(target.DATA_TYPE){
    case T100DATA_COR:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_COR;
                }
                break;
            case P_ADDRESS:
                {
                    return T100FALSE;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = I_COR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_CBR:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_CBR;
                }
                break;
            case P_ADDRESS:
                {
                    return T100FALSE;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = I_CBR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_CCR:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_CCR;
                }
                break;
            case P_ADDRESS:
                {
                    return T100FALSE;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = I_CCR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_AAR:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_AAR;
                }
                break;
            case P_ADDRESS:
                {
                    return T100FALSE;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = I_AAR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ABR:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_ABR;
                }
                break;
            case P_ADDRESS:
                {
                    return T100FALSE;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = I_ABR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ACR:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_ACR;
                }
                break;
            case P_ADDRESS:
                {
                    return T100FALSE;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = I_ACR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ADR:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_ADR;
                }
                break;
            case P_ADDRESS:
                {
                    return T100FALSE;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = I_ADR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ACF:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_ACF;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_AMF:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_AMF;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_AOF:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_AOF;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_INTEGER:
        {
            build.FLAG      = T100TRUE;
            build.VALUE     = target.VALUE;
            build.DEVIANT++;

            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_IMM;
                }
                break;
            case P_ADDRESS:
                {
                    build.TYPE      = T_COR;
                }
                break;
            case P_VALUE:
                {
                    build.TYPE      = T_IMM;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_FLOAT:
        {
            build.FLAG      = T100TRUE;
            build.VALUE     = target.VALUE;
            build.DEVIANT++;

            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_IMM;
                }
                break;
            default:
                //
                return T100FALSE;
            }
        }
        break;
    case T100DATA_STRING:
        {
            //
            return T100FALSE;
        }
        break;
    case T100DATA_LABEL:
        {
            build.FLAG      = T100TRUE;

            switch(target.PREFIX_TYPE){
            case P_NONE:
            case P_ADDRESS:
                {
                    T100WORD        offset;

                    build.TYPE      = T_IMM;

                    result = info->getLabel(target.NAME, offset);

                    T100LABEL_CALL* item    = T100NEW T100LABEL_CALL();
                    item->NAME              = target.NAME;

                    //test
                    build.DEVIANT++;

                    T100WORD        temp;

                    temp            = info->getOffset() + build.DEVIANT;
                    item->OFFSET    = info->getOffset() + build.DEVIANT;

                    info->addLabelCall(item);

                    build.VALUE     = offset;
                }
                break;
            default:
                //
                return T100FALSE;
            }
        }
        break;
    case T100DATA_VARIABLE:
        {
            T100WORD        offset;

            build.FLAG      = T100TRUE;

            T100Assembly::T100VARIABLE_DEFINE* vd = T100Assembly::T100ProduceInfo::getVariableDrawer().getVariableDefine(target.NAME);
            if(!vd){
                //
                return T100FALSE;
            }

            //test
            if(vd->ISARRAY){
                if(target.ISARRAY){
                    if(target.LENGTH >= vd->LENGTH){
                        //
                        return T100FALSE;
                    }else{
                        build.ARRAY = T100TRUE;
                        build.INDEX = target.LENGTH;
                    }
                }
            }else if(vd->ISARRAY != target.ISARRAY){
                //
                return T100FALSE;
            }

            result  = info->getVariable(target.NAME, offset);
            offset  = vd->OFFSET;

            T100VARIABLE_CALL* item     = T100NEW T100VARIABLE_CALL();

            item->NAME                  = target.NAME;
            build.DEVIANT++;
            item->OFFSET                = info->getOffset() + build.DEVIANT;

            info->addVariableCall(item);

            //test
            target.ISSHARE  = vd->ISSHARE;

            T100BOOL        value = target.ISSHARE;

            build.VALUE     = offset;

            switch(vd->BASE_TYPE){
            case T100DATA_INTEGER:
            case T100DATA_FLOAT:
                {
                    switch(target.PREFIX_TYPE){
                    case P_NONE:
                        {
                            if(build.ARRAY){
                                if(target.ISSHARE){
                                    build.TYPE      = ST_ARR;
                                }else{
                                    build.TYPE      = T_ARR;
                                }
                                build.DEVIANT++;
                            }else{
                                if(target.ISSHARE){
                                    build.TYPE      = ST_MEM;
                                }else{
                                    build.TYPE      = T_MEM;
                                }
                            }
                        }
                        break;
                    case P_ADDRESS:
                        {
                            if(target.ISSHARE){
                                build.TYPE      = ST_IMM;
                            }else{
                                build.TYPE      = T_IMM;
                            }

                            if(build.ARRAY){
                                return T100FALSE;
                            }
                        }
                        break;
                    case P_VALUE:
                        {
                            if(build.ARRAY){
                                if(target.ISSHARE){
                                    build.TYPE      = SI_ARR;
                                }else{
                                    build.TYPE      = I_ARR;
                                }
                                build.DEVIANT++;
                            }else{
                                if(target.ISSHARE){
                                    build.TYPE      = SI_MEM;
                                }else{
                                    build.TYPE      = I_MEM;
                                }
                            }
                        }
                        break;
                    }
                }
                break;
            case T100DATA_STRING:
                {
                    switch(target.PREFIX_TYPE){
                    case P_NONE:
                    case P_ADDRESS:
                        {
                            if(target.ISSHARE){
                                build.TYPE      = ST_IMM;
                            }else{
                                build.TYPE      = T_IMM;
                            }
                        }
                        break;
                    case P_VALUE:
                        {
                            if(target.ISSHARE){
                                build.TYPE      = ST_MEM;
                            }else{
                                build.TYPE      = T_MEM;
                            }
                        }
                        break;
                    default:
                        return T100FALSE;
                    }
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}


T100BOOL T100OperatorBuilder::buildAll(T100Assembly::T100BuildInfo* info, T100OPERATOR& target, T100OPERATOR_BUILD& build)
{
    T100BOOL        result          = T100FALSE;

    switch(target.DATA_TYPE){
    case T100DATA_ALL:
        {
            build.FLAG      = T100FALSE;
            switch(target.PREFIX_TYPE){
            case P_NONE:
                {
                    build.TYPE      = T_ALL;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    default:
        return this->build(info, target, build);
    }

    return T100TRUE;
}

}
