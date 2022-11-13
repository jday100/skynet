#include "T100SentenceVariable.h"

#include "T100AssemblyHint.h"
#include "T100AssemblyError.h"
#include "T100StringTools.h"
#include "T100String32Tools.h"
#include "T100ProduceInfo.h"
#include "T100VariableDrawer.h"

namespace T100Assembly{

T100SentenceVariable::T100SentenceVariable(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceVariable::~T100SentenceVariable()
{
    //dtor
}

T100BOOL T100SentenceVariable::parse()
{
    T100BOOL        result          = T100TRUE;

    name = m_item->value;
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

T100BOOL T100SentenceVariable::parseType()
{
    T100BOOL        result          = T100FALSE;

READ_NEXT:
    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item->type){
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_INTEGER:
        {
            target.DATA_TYPE    = T100Component::T100DATA_INTEGER;
            target.LENGTH       = 1;
            target.VALUE        = 0;

            return parseBrackets(target);
        }
        break;
    case T100KEYWORD_FLOAT:
        {
            target.DATA_TYPE    = T100Component::T100DATA_FLOAT;
            target.LENGTH       = 1;
            target.VALUE        = 0.0;

            return parseBrackets(target);
        }
        break;
    case T100KEYWORD_STRING:
        {
            target.DATA_TYPE    = T100Component::T100DATA_STRING;
            target.LENGTH       = 1;
            target.NAME.clear();

            setLoaded(T100FALSE);
            return T100TRUE;
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
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
    T100BOOL        result          = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type){
    case T100TOKEN_BR:
        {
            return T100TRUE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CONSTANT_INTEGER:
        {
            if(T100Component::T100DATA_INTEGER == target.DATA_TYPE){
                target.VALUE = T100Library::T100StringTools::to_long(m_item->value.to_wstring());

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
                return T100FALSE;
            }
        }
        break;
    case T100CONSTANT_FLOAT:
        {
            if(T100Component::T100DATA_FLOAT == target.DATA_TYPE){
                target.VALUE = T100Library::T100StringTools::to_float(m_item->value.to_wstring());

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
                return T100FALSE;
            }
        }
        break;
    case T100CONSTANT_STRING:
        {
            if(T100Component::T100DATA_STRING == target.DATA_TYPE){
                target.NAME = m_item->value;

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
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

            if(T100KEYWORD_LABEL == m_item->type){
                target.NAME         = m_item->value;
                target.ADDR_TYPE    = T100Component::S_ADD;

                setLoaded(T100FALSE);
                return T100TRUE;
            }else{
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
                return T100FALSE;
            }
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
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
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
        return T100FALSE;
    }

    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_VARIABLE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceVariable::build(T100BuildInfo* info)
{
    T100BOOL        result          = T100TRUE;

    switch(target.DATA_TYPE){
    case T100Component::T100DATA_FLOAT:
        {
            result = buildFloat(info);
        }
        break;
    case T100Component::T100DATA_INTEGER:
        {
            result = buildInteger(info);
        }
        break;
    case T100Component::T100DATA_STRING:
        {
            result = buildString(info);
        }
        break;
    }

    return result;
}

T100BOOL T100SentenceVariable::setDefine()
{
    T100BOOL        result          = T100TRUE;

    T100VARIABLE_DEFINE* vd = T100NEW T100VARIABLE_DEFINE();

    vd->NAME        = name;
    vd->LENGTH      = target.LENGTH;
    vd->VALUE       = target.VALUE;
    vd->TYPE        = target.DATA_TYPE;
    vd->ISARRAY     = target.ISARRAY;
    vd->ISSHARE     = target.ISSHARE;

    //test
    vd->OFFSET      = 0;

    result = T100ProduceInfo::getVariableDrawer().setVariableDefine(name, vd);
    if(!result){
        T100SAFE_DELETE(vd);
    }

    return result;
}

T100BOOL T100SentenceVariable::buildFloat(T100BuildInfo* info)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        offset;

    if(1 == target.LENGTH){
        result = info->getData()->setWord(offset, target.VALUE);
    }else{
        result = info->getData()->setArray(offset, target.LENGTH);
    }

    if(result){
        info->setVariable(name, offset);

        T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(name);

        if(!vd){
            //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
            return T100FALSE;
        }

        vd->NAME        = name;
        vd->LENGTH      = target.LENGTH;
        vd->TYPE        = target.DATA_TYPE;
        vd->OFFSET      = offset;
        vd->ISVIRTUAL   = info->getData()->isVirtual;
        vd->ISSHARE     = info->getData()->isShare;
    }

    return result;
}

T100BOOL T100SentenceVariable::buildInteger(T100BuildInfo* info)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        offset;

    if(T100Component::S_ADD == target.ADDR_TYPE){
        result = info->getData()->setWord(offset, target.VALUE);

        if(result){
            info->setVariable(name, offset);

            T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(name);

            if(!vd){
                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                return T100FALSE;
            }

            vd->NAME        = name;
            vd->LENGTH      = target.LENGTH;
            vd->TYPE        = target.DATA_TYPE;
            vd->OFFSET      = offset;
            vd->ISVIRTUAL   = info->getData()->isVirtual;
            vd->ISSHARE     = info->getData()->isShare;

            T100BOOL    value = vd->ISSHARE;

            result = T100ProduceInfo::getVariableDrawer().setVariableDefine(name, vd);
            if(!result){
                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
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

    if(1 == target.LENGTH){
        result = info->getData()->setWord(offset, target.VALUE);
    }else{
        result = info->getData()->setArray(offset, target.LENGTH);
    }

    if(result){
        info->setVariable(name, offset);

        T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(name);

        if(!vd){
            //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
            return T100FALSE;
        }

        vd->NAME        = name;
        vd->LENGTH      = target.LENGTH;
        vd->TYPE        = target.DATA_TYPE;
        vd->OFFSET      = offset;
        vd->ISVIRTUAL   = info->getData()->isVirtual;
        vd->ISSHARE     = info->getData()->isShare;
    }

    if(result){
        result = info->setVariable(name, offset);
    }

    return result;
}

T100BOOL T100SentenceVariable::buildString(T100BuildInfo* info)
{
    T100BOOL        result          = T100TRUE;
    T100WORD        offset;

    //test
    T100STRING      temp;

    if(!T100Library::T100String32Tools::format(target.NAME, temp)){
        return T100FALSE;
    }

    result = info->getData()->setString(offset, temp);
    if(result){
        info->setVariable(name, offset);

        T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(name);
        if(!vd){
            //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
            return T100FALSE;
        }

        vd->NAME        = name;
        vd->TYPE        = target.DATA_TYPE;
        vd->OFFSET      = offset;
        vd->ISVIRTUAL   = info->getData()->isVirtual;
        vd->ISSHARE     = info->getData()->isShare;
    }

    return result;
}

}
