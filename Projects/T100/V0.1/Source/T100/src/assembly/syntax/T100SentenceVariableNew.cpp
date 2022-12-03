#include "T100SentenceVariableNew.h"

#include "T100BitTypes.h"
#include "T100StringTools.h"
#include "T100ProduceInfo.h"
#include "T100VariableDrawer.h"


namespace T100Assembly{


T100SentenceVariableNew::T100SentenceVariableNew(T100SentenceScanner* scanner)
    :T100SentenceBase(scanner)
{
    //ctor
}

T100SentenceVariableNew::~T100SentenceVariableNew()
{
    //dtor
}

T100VOID T100SentenceVariableNew::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_VARIABLE] = L"T100SentenceVariable";
}

T100BOOL T100SentenceVariableNew::parse()
{
    T100BOOL        result          = T100TRUE;

    target.NAME = m_item->value;
    setLoaded(T100FALSE);

    result = parseType();
    if(!result){
        return T100FALSE;
    }

    result = parseValue();

    if(result){
        type            = T100SENTENCE_VARIABLE;
        m_token->type   = T100SENTENCE_VARIABLE;

        result = setDefine();
    }

    return result;
}

T100BOOL T100SentenceVariableNew::parseType()
{
    T100BOOL        result          = T100FALSE;

READ_NEXT:
    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item->type){
    case T100Component::T100TOKEN_BR:
        {
            m_token->type   = T100Component::T100TOKEN_ERROR;
            m_token->err    = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    case T100Component::T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100KEYWORD_INTEGER:
        {
            target.DATA_TYPE    = ::T100SentenceBase::T100DATA_INTEGER;
            target.LENGTH       = 1;
            target.VALUE        = 0;

            return parseBrackets(target);
        }
        break;
    case T100Assembly::T100KEYWORD_FLOAT:
        {
            target.DATA_TYPE    = ::T100SentenceBase::T100DATA_FLOAT;
            target.LENGTH       = 1;
            target.VALUE        = 0.0;

            return parseBrackets(target);
        }
        break;
    case T100Assembly::T100KEYWORD_STRING:
        {
            target.DATA_TYPE    = ::T100SentenceBase::T100DATA_STRING;
            target.LENGTH       = 1;

            return parseBrackets(target);
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            m_token->type   = T100Component::T100TOKEN_ERROR;
            m_token->err    = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    default:
        m_token->type   = T100Component::T100TOKEN_ERROR;
        m_token->err    = T100Assembly::T100ERROR_SENTENCE;
        //
        return T100FALSE;
    }
    return T100FALSE;
}

T100BOOL T100SentenceVariableNew::parseValue()
{
    if(target.ISARRAY){
        return parseArray();
    }
    return parseDefault();
}

T100BOOL T100SentenceVariableNew::parseDefault()
{
    T100BOOL        result          = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type){
    case T100Component::T100TOKEN_BR:
        {
            return T100TRUE;
        }
        break;
    case T100Component::T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CONSTANT_INTEGER:
        {
            if(::T100SentenceBase::T100DATA_INTEGER == target.DATA_TYPE){
                target.VALUE = T100Library::T100StringTools::to_long(m_item->value.to_wstring());

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                //
                return T100FALSE;
            }
        }
        break;
    case T100Assembly::T100CONSTANT_FLOAT:
        {
            if(::T100SentenceBase::T100DATA_FLOAT == target.DATA_TYPE){
                FLOAT = T100Library::T100StringTools::to_float(m_item->value.to_wstring());

                setLoaded(T100FALSE);
                return T100FALSE;
            }else{
                //
                return T100FALSE;
            }
        }
        break;
    case T100Assembly::T100CONSTANT_STRING:
        {
            if(::T100SentenceBase::T100DATA_STRING == target.DATA_TYPE){
                STRING = m_item->value;

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                //
                return T100FALSE;
            }
        }
        break;
    case T100CHAR_EMAIL:
        {
            setLoaded(T100FALSE);
            if(!read()){
                return T100FALSE;
            }

            if(T100Assembly::T100KEYWORD_LABEL == m_item->type){
                STRING = m_item->value;
                target.PREFIX_TYPE  = ::T100SentenceBase::P_ADDRESS;

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                //
                return T100FALSE;
            }
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            m_token->type   = T100Component::T100TOKEN_ERROR;
            m_token->err    = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    case T100KEYWORD_COMMENT:
        {
            setLoaded(T100FALSE);
            return T100TRUE;
        }
        break;
    default:
        m_token->type   = T100Component::T100TOKEN_ERROR;
        m_token->err    = T100Assembly::T100ERROR_SENTENCE;
        //
        return T100FALSE;
    }
    //
    return T100FALSE;
}

T100BOOL T100SentenceVariableNew::parseArray()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    switch(target.DATA_TYPE){
    case ::T100SentenceBase::T100DATA_INTEGER:
        {
            result = parseInteger();
        }
        break;
    case ::T100SentenceBase::T100DATA_FLOAT:
        {
            result = parseFloat();
        }
        break;
    case ::T100SentenceBase::T100DATA_STRING:
        {
            result = parseString();
        }
        break;
    default:
        result = T100FALSE;
    }
    return result;
}

T100BOOL T100SentenceVariableNew::parseInteger()
{
    T100BOOL        result          = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    T100WORD temp;

    temp = m_item->type;

    switch(m_item->type){
    case T100Component::T100TOKEN_BR:
        {
            return T100TRUE;
        }
        break;
    case T100Component::T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CHAR_OPEN_BRACE:
        {
INTEGER_READ_NEXT:
            result = read();
            if(!result){
                return T100FALSE;
            }

            switch(m_item->type){
            case T100Component::T100TOKEN_BR:
                {
                    setLoaded(T100FALSE);
                    goto INTEGER_READ_NEXT;
                }
                break;
            case T100Component::T100TOKEN_SPACE:
                {
                    setLoaded(T100FALSE);
                    goto INTEGER_READ_NEXT;
                }
                break;
            case T100Assembly::T100CONSTANT_INTEGER:
                {
                    T100WORD        value;

                    value = T100Library::T100StringTools::to_long(m_item->value.to_wstring());
                    m_integer.push_back(value);

INTEGER_ITEM_READ_NEXT:
                    setLoaded(T100FALSE);
                    result = read();
                    if(!result){
                        return T100FALSE;
                    }

                    switch(m_item->type){
                    case T100Assembly::T100CHAR_COMMA:
                        {
                            setLoaded(T100FALSE);
                            result = read();
                            if(!result){
                                return T100FALSE;
                            }

                            if(T100Assembly::T100CONSTANT_INTEGER == m_item->type){
                                T100WORD        value;

                                value = T100Library::T100StringTools::to_long(m_item->value.to_wstring());
                                m_integer.push_back(value);

                                setLoaded(T100FALSE);
                                goto INTEGER_ITEM_READ_NEXT;
                            }else{
                                m_token->type   = T100Component::T100TOKEN_ERROR;
                                m_token->err    = T100Assembly::T100ERROR_SENTENCE;
                                //
                                return T100FALSE;
                            }
                        }
                        break;
                    case T100Assembly::T100CHAR_CLOSED_BRACE:
                        {
                            setLoaded(T100FALSE);
                            return T100TRUE;
                        }
                        break;
                    default:
                        m_token->type   = T100Component::T100TOKEN_ERROR;
                        m_token->err    = T100Assembly::T100ERROR_SENTENCE;
                        //
                        return T100FALSE;
                    }
                }
                break;
            case T100Assembly::T100CHAR_CLOSED_BRACKETS:
                {
                    setLoaded(T100FALSE);
                    return T100TRUE;
                }
                break;
            default:
                m_token->type   = T100Component::T100TOKEN_ERROR;
                m_token->err    = T100Assembly::T100ERROR_SENTENCE;
                //
                return T100FALSE;
            }
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            m_token->type   = T100Component::T100TOKEN_ERROR;
            m_token->err    = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    case T100Assembly::T100KEYWORD_COMMENT:
        {
            setLoaded(T100FALSE);
            return T100TRUE;
        }
        break;
    default:
        m_token->type   = T100Component::T100TOKEN_ERROR;
        m_token->err    = T100Assembly::T100ERROR_SENTENCE;
        //
        return T100FALSE;
    }

    //
    return T100FALSE;
}

T100BOOL T100SentenceVariableNew::parseFloat()
{
    return T100FALSE;
}

T100BOOL T100SentenceVariableNew::parseString()
{
    return T100FALSE;
}

T100BOOL T100SentenceVariableNew::setDefine()
{
    T100BOOL        result          = T100TRUE;

    T100VARIABLE_DEFINE* vd = T100NEW T100VARIABLE_DEFINE();

    vd->NAME        = target.NAME;
    vd->LENGTH      = target.LENGTH;
    vd->VALUE       = target.VALUE;
    vd->BASE_TYPE   = target.DATA_TYPE;
    vd->ISARRAY     = target.ISARRAY;
    vd->ISSHARE     = target.ISSHARE;

    //test
    vd->OFFSET      = 0;
    vd->TYPE        = getType(target.DATA_TYPE);

    result = T100ProduceInfo::getVariableDrawer().setVariableDefine(target.NAME, vd);
    if(!result){
        T100SAFE_DELETE(vd);
    }
    return result;
}

////

T100BOOL T100SentenceVariableNew::build(T100BuildInfo* info)
{
    T100BOOL        result          = T100TRUE;

    switch(target.DATA_TYPE){
    case ::T100SentenceBase::T100DATA_INTEGER:
        {
            result = buildInteger(info);
        }
        break;
    case ::T100SentenceBase::T100DATA_FLOAT:
        {
            result = buildFloat(info);
        }
        break;
    case ::T100Component::T100DATA_STRING:
        {
            result = buildString(info);
        }
        break;
    default:
        return T100FALSE;
    }
    return result;
}

T100BOOL T100SentenceVariableNew::buildInteger(T100BuildInfo* info)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        offset;

    if(target.ISARRAY){
        switch(target.DATA_TYPE){
        case ::T100SentenceBase::T100DATA_INTEGER:
            {
                result = info->getData()->setArrayInteger(offset, target.LENGTH, m_integer);
            }
            break;
        case ::T100SentenceBase::T100DATA_FLOAT:
            {
                result = info->getData()->setArrayFloat(offset, target.LENGTH, m_float);
            }
            break;
        case ::T100SentenceBase::T100DATA_STRING:
            {
                result = info->getData()->setArrayString(offset, target.LENGTH, m_string);
            }
            break;
        default:
            result = T100FALSE;
        }

        if(result){
            result = info->setVariable(target.NAME, offset);
        }
    }else{
        if(::T100SentenceBase::P_ADDRESS == target.PREFIX_TYPE){
            result = info->getData()->setWord(offset, target.VALUE);

            if(result){
                info->setVariable(target.NAME, offset);

                T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(target.NAME);

                if(!vd){
                    //
                    return T100FALSE;
                }

                vd->NAME        = target.NAME;
                vd->LENGTH      = target.LENGTH;
                vd->BASE_TYPE   = target.DATA_TYPE;
                vd->OFFSET      = offset;
                vd->ISVIRTUAL   = info->getData()->isVirtual;
                vd->ISSHARE     = info->getData()->isShare;

                result = T100ProduceInfo::getVariableDrawer().setVariableDefine(target.NAME, vd);

                if(!result){
                    //
                    return T100FALSE;
                }

                result = info->getLabel(target.NAME, offset);

                T100LABEL_CALL* item    = T100NEW T100LABEL_CALL();
                item->NAME              = target.NAME;
                //test
                item->OFFSET            = info->getOffset() - 1;

                info->addLabelCall(item);

                return T100TRUE;
            }

            return T100FALSE;
        }

        result = info->getData()->setWord(offset, target.VALUE);

        if(result){
            info->setVariable(target.NAME, offset);

            T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(target.NAME);

            if(!vd){
                //
                return T100FALSE;
            }

            vd->NAME        = target.NAME;
            vd->LENGTH      = target.LENGTH;
            vd->BASE_TYPE   = target.DATA_TYPE;
            vd->OFFSET      = offset;
            vd->ISVIRTUAL   = info->getData()->isVirtual;
            vd->ISSHARE     = info->getData()->isShare;
        }

        if(result){
            result = info->setVariable(target.NAME, offset);
        }
    }

    return result;
}

T100BOOL T100SentenceVariableNew::buildFloat(T100BuildInfo* info)
{

}

T100BOOL T100SentenceVariableNew::buildString(T100BuildInfo* info)
{

}

}
