#include "T100SentenceVariable.h"

#include "T100AssemblyError.h"
#include "T100StringTools.h"
#include "T100CodeNew.h"
#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceVariable::T100SentenceVariable(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceVariable::~T100SentenceVariable()
{
    //dtor
}

T100BOOL T100SentenceVariable::parse()
{
    T100BOOL    result      = T100FALSE;

    name            = m_item->data;
    setLoaded(T100FALSE);

    result = parseType();
    if(!result){
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
        return T100FALSE;
    }

    result = parseValue();

    if(result){
        type            = T100SENTENCE_VARIABLE;
        m_token->type   = T100SENTENCE_VARIABLE;

        T100VARIABLE_DEFINE* vd = T100NEW T100VARIABLE_DEFINE;

        vd->name        = name;
        vd->length      = target.LENGTH;
        vd->value       = target.VALUE;
        vd->type        = target.DATA_TYPE;
        vd->isarray     = target.ISARRAY;
        vd->isshare     = target.ISSHARE;

        T100Code::setVariableDefine(name, vd);
    }

    return result;
}

T100BOOL T100SentenceVariable::parseType()
{
    T100BOOL    result      = T100FALSE;

READ_NEXT:
    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_INTEGER:
        {
            target.DATA_TYPE    = T100DATA_INTEGER;
            target.LENGTH       = 1;
            target.VALUE        = 0;

            return parseBrackets(target);
            break;
        }
    case T100KEYWORD_FLOAT:
        {
            target.DATA_TYPE    = T100DATA_FLOAT;
            target.LENGTH       = 1;
            target.VALUE        = 0.0;

            return parseBrackets(target);
            break;
        }
    case T100KEYWORD_STRING:
        {
            target.DATA_TYPE    = T100DATA_STRING;
            target.LENGTH       = 1;
            target.NAME.clear();

            setLoaded(T100FALSE);
            return T100TRUE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
        return T100FALSE;
    }

    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceVariable::parseValue()
{
    T100BOOL    result      = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            return T100TRUE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100CONSTANT_INTEGER:
        {
            if(T100DATA_INTEGER == target.DATA_TYPE){
                //target.VALUE = std::stoi(m_item->data.to_std_string());
                target.VALUE = std::stoll(m_item->data.to_std_string().c_str(), T100NULL, 0);

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
                return T100FALSE;
            }
            break;
        }
    case T100CONSTANT_FLOAT:
        {
            if(T100DATA_FLOAT == target.DATA_TYPE){
                target.VALUE = std::stof(m_item->data.to_std_string());
                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
                return T100FALSE;
            }
            break;
        }
    case T100CONSTANT_STRING:
        {
            if(T100DATA_STRING == target.DATA_TYPE){
                target.NAME = m_item->data;
                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
                return T100FALSE;
            }
            break;
        }
    case T100CHAR_EMAIL:
        {
            setLoaded(T100FALSE);
            if(!read()){
                return T100FALSE;
            }

            if(T100KEYWORD_LABEL == m_item->type){
                target.NAME         = m_item->data;
                target.ADDR_TYPE    = S_ADD;

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                return T100FALSE;
            }

            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100KEYWORD_COMMENT:
        {
            setLoaded(T100FALSE);
            return T100TRUE;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
        return T100FALSE;
    }

    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceVariable::build(T100FileData* code)
{
    T100BOOL    result      = T100TRUE;
    T100WORD    offset;

    switch(target.DATA_TYPE)
    {
    case T100DATA_FLOAT:
        {
            if(1 == target.LENGTH){
                result = code->getData()->setWord(offset, target.VALUE);
            }else{
                result = code->getData()->setArray(offset, target.LENGTH);
            }

            if(result){
                code->setVariable(name, offset);

                T100VARIABLE_DEFINE* vd = T100Code::getVariableDefine(name);
                if(T100NULL == vd){
                    T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                    return T100FALSE;
                }

                vd->name        = name;
                vd->length      = target.LENGTH;
                vd->type        = target.DATA_TYPE;
                vd->offset      = offset;
                vd->isvirtual   = code->getData()->isVirtual;
                vd->isshare     = code->getData()->isShare;

                T100BOOL value = vd->isshare;

                T100Code::setVariableDefine(name, vd);
            }
            break;
        }
    case T100DATA_INTEGER:
        {
            if(S_ADD == target.ADDR_TYPE){
                result = code->getData()->setWord(offset, target.VALUE);

                if(result){
                    code->setVariable(name, offset);

                    T100VARIABLE_DEFINE* vd = T100Code::getVariableDefine(name);
                    if(T100NULL == vd){
                        T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                        return T100FALSE;
                    }

                    vd->name        = name;
                    vd->length      = target.LENGTH;
                    vd->type        = target.DATA_TYPE;
                    vd->offset      = offset;
                    vd->isvirtual   = code->getData()->isVirtual;
                    vd->isshare     = code->getData()->isShare;

                    T100BOOL value = vd->isshare;

                    T100Code::setVariableDefine(name, vd);

                    //

                    T100Log::info("DATA add label call");

                    result = code->getLabel(target.NAME, offset);
                    T100LABEL_CALL* item    = T100NEW T100LABEL_CALL();
                    item->name              = target.NAME;
                    //test
                    item->offset            = code->getOffset() - 1;

                    code->addLabelCall(item);

                    return T100TRUE;
                }

                return T100FALSE;
            }

            if(1 == target.LENGTH){
                result = code->getData()->setWord(offset, target.VALUE);
            }else{
                result = code->getData()->setArray(offset, target.LENGTH);
            }

            if(result){
                code->setVariable(name, offset);

                T100VARIABLE_DEFINE* vd = T100Code::getVariableDefine(name);
                if(T100NULL == vd){
                    T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                    return T100FALSE;
                }

                vd->name        = name;
                vd->length      = target.LENGTH;
                vd->type        = target.DATA_TYPE;
                vd->offset      = offset;
                vd->isvirtual   = code->getData()->isVirtual;
                vd->isshare     = code->getData()->isShare;

                T100BOOL value = vd->isshare;

                T100Code::setVariableDefine(name, vd);
            }
            break;
        }
    case T100DATA_STRING:
        {
            //test
            T100String temp;

            temp = T100StringTools::format(target.NAME);

            result = code->getData()->setString(offset, temp);
            if(result){
                code->setVariable(name, offset);

                T100VARIABLE_DEFINE* vd = T100Code::getVariableDefine(name);
                if(T100NULL == vd){
                    T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                    return T100FALSE;
                }

                vd->name        = name;
                vd->type        = target.DATA_TYPE;
                vd->offset      = offset;
                vd->isvirtual   = code->getData()->isVirtual;
                vd->isshare     = code->getData()->isShare;

                T100Code::setVariableDefine(name, vd);
            }
            break;
        }
    };

    if(result){
        code->setVariable(name, offset);
    }

    return result;
}
