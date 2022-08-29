#include "T100Sentence.h"

#include "T100AssemblyHint.h"
#include "T100AssemblyError.h"
#include "T100ProduceInfo.h"
#include "T100SentenceScanner.h"

#include "T100BuildInfo.h"
#include "T100VariableDrawer.h"
#include "T100ProcedureDrawer.h"


T100Sentence::T100Sentence(T100SentenceScanner* scanner)
    :m_scanner(scanner)
{
    //ctor
    create();
}

T100Sentence::~T100Sentence()
{
    //dtor
    destroy();
}

T100VOID T100Sentence::create()
{
    m_token = m_scanner->m_token;
    m_item  = &(m_scanner->m_item);
}

T100VOID T100Sentence::destroy()
{

}

T100BOOL T100Sentence::parse()
{
    return T100FALSE;
}

T100BOOL T100Sentence::build(T100BuildInfo* info)
{
    return T100FALSE;
}

T100BOOL T100Sentence::read()
{
    T100BOOL    result;

    result = m_scanner->read();

    return result;
}

T100BOOL T100Sentence::clear()
{
    m_type          = S_NONE;
    m_scanner->clear();
    return T100TRUE;
}

T100BOOL T100Sentence::append()
{
    return m_scanner->append();
}

T100VOID T100Sentence::setLoaded(T100BOOL value)
{
    m_scanner->setLoaded(value);
}

T100BOOL T100Sentence::isLoaded()
{
    return m_scanner->isLoaded();
}

T100BOOL T100Sentence::parseNumber(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    m_type  = S_NONE;

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
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
                break;
            }
        case T100TOKEN_SPACE:
            {
                setLoaded(T100FALSE);
                goto READ_NEXT;
                break;
            }
        case T100CHAR_POUND:
            {
                m_type  = S_VAL;
                setLoaded(T100FALSE);
                goto READ_NEXT;
                break;
            }
        case T100CHAR_EMAIL:
            {
                m_type  = S_ADD;
                setLoaded(T100FALSE);
                goto READ_NEXT;
                break;
            }
        case T100KEYWORD_COR:
        case T100KEYWORD_CBR:
        case T100KEYWORD_CCR:
        case T100KEYWORD_AAR:
        case T100KEYWORD_ABR:
        case T100KEYWORD_ACR:
        case T100KEYWORD_ADR:
        case T100KEYWORD_ACF:
        case T100KEYWORD_AMF:
        case T100KEYWORD_AOF:
            {
                return parseRegister(op);
                break;
            }
        case T100CONSTANT_INTEGER:
        case T100CONSTANT_FLOAT:
            {
                op.USED     = T100TRUE;
                return parseExpression(op);
                break;
            }
        case T100KEYWORD_VARIABLE:
            {
                op.USED     = T100TRUE;
                return parseVariable(op);
                break;
            }
        case T100KEYWORD_LABEL:
            {
                op.USED     = T100TRUE;
                return parseVariable(op);
                break;
            }
        case T100TOKEN_EOF:
            {
                m_token->type   = T100TOKEN_ERROR;
                m_token->err    = T100ERROR_SENTENCE;
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
                break;
            }
        case T100CHAR_CLOSED_BRACE:
            {
                op.ADDR_TYPE    = m_type;
                return T100TRUE;
                break;
            }
        default:
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }

        return T100FALSE;
}

T100BOOL T100Sentence::parseRegister(T100OPERATOR& op)
{
    switch(m_item->type)
    {
    case T100KEYWORD_COR:
        {
            op.DATA_TYPE    = T100DATA_COR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_CBR:
        {
            op.DATA_TYPE    = T100DATA_CBR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_CCR:
        {
            op.DATA_TYPE    = T100DATA_CCR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_AAR:
        {
            op.DATA_TYPE    = T100DATA_AAR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ABR:
        {
            op.DATA_TYPE    = T100DATA_ABR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ACR:
        {
            op.DATA_TYPE    = T100DATA_ACR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ADR:
        {
            op.DATA_TYPE    = T100DATA_ADR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ACF:
        {
            op.DATA_TYPE    = T100DATA_ACF;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_AMF:
        {
            op.DATA_TYPE    = T100DATA_AMF;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_AOF:
        {
            op.DATA_TYPE    = T100DATA_AOF;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    }

    return T100TRUE;
}

T100BOOL T100Sentence::parseExpression(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100TRUE);

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type)
    {
    case T100CONSTANT_INTEGER:
        {
            op.LENGTH       = 0;
            op.DATA_TYPE    = T100DATA_INTEGER;
            op.ADDR_TYPE    = m_type;

            op.VALUE        = std::stoll(m_item->value.to_wstring().c_str(), T100NULL, 0);

            setLoaded(T100FALSE);

            return T100TRUE;
            break;
        }
    case T100CONSTANT_FLOAT:
        {
            if(S_NONE != m_type){
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
            }

            op.LENGTH       = 0;
            op.DATA_TYPE    = T100DATA_FLOAT;
            op.ADDR_TYPE    = m_type;

            op.VALUE        = std::stof(m_item->value.to_wstring().c_str());
            setLoaded(T100FALSE);

            return T100TRUE;
            break;
        }
    case T100CONSTANT_STRING:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    default:
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
    }

    return T100FALSE;
}

T100BOOL T100Sentence::parseVariable(T100OPERATOR& op)
{
    op.NAME         = m_item->value;
    op.DATA_TYPE    = T100DATA_VARIABLE;
    op.ADDR_TYPE    = m_type;

    //setLoaded(T100FALSE);
    return parseBrackets(op);
}

T100BOOL T100Sentence::parseLabel(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    switch(m_type)
    {
    case S_NONE:
        {
            op.NAME         = m_item->value;
            op.DATA_TYPE    = T100DATA_LABEL;
            op.ADDR_TYPE    = S_NONE;

            setLoaded(T100FALSE);
            result = T100TRUE;
            break;
        }
    case S_ADD:
        {
            op.NAME         = m_item->value;
            op.DATA_TYPE    = T100DATA_LABEL;
            op.ADDR_TYPE    = S_ADD;

            setLoaded(T100FALSE);
            result = T100TRUE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Sentence::parseBrackets(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);

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
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100CHAR_OPEN_BRACKETS:
        {
            result = read();
            if(!result){
                return T100FALSE;
            }

            if(T100CONSTANT_INTEGER == m_item->type){
                T100WORD    value;

                value = std::stoll(m_item->value.to_wstring());

                result = read();
                if(!result){
                    return T100FALSE;
                }

                if(T100CHAR_CLOSED_BRACKETS == m_item->type){
                    op.ISARRAY  = T100TRUE;
                    op.LENGTH   = value;
                    setLoaded(T100FALSE);
                    return T100TRUE;
                }else{
                    m_token->type   = T100TOKEN_ERROR;
                    m_token->err    = T100ERROR_SENTENCE;
                    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                    return T100FALSE;
                }
            }else{
                m_token->type   = T100TOKEN_ERROR;
                m_token->err    = T100ERROR_SENTENCE;
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
            }
            break;
        }
    default:
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Sentence::parseBrace(T100OPERATOR& base, T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    m_type  = S_NONE;

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
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
        {
            result = parseRegister(base);
            if(!result){
                return T100FALSE;
            }
            goto READ_NEXT;
            break;
        }
    case T100CONSTANT_INTEGER:
        {
            base.USED   = T100TRUE;
            result = parseExpression(base);
            if(!result){
                return T100FALSE;
            }
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_VARIABLE:
        {
            base.USED     = T100TRUE;
            result = parseVariable(base);
            if(!result){
                return T100FALSE;
            }
            goto READ_NEXT;
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type       = T100TOKEN_ERROR;
            m_token->err        = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100CHAR_COLON:
        {
            setLoaded(T100FALSE);
            result = parseNumber(op);
            if(!result){
                return T100FALSE;
            }
            //setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100CHAR_CLOSED_BRACE:
        {
            setLoaded(T100FALSE);
            return T100TRUE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }

}

T100BOOL T100Sentence::parseOperator(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    m_type      = S_NONE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        };
    };

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_POUND:
        {
            m_type      = S_VAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_EMAIL:
        {
            m_type      = S_ADD;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
    case T100KEYWORD_ACF:
    case T100KEYWORD_AMF:
    case T100KEYWORD_AOF:
        {
            return parseRegister(op);
        }
        break;
    case T100CONSTANT_INTEGER:
    case T100CONSTANT_FLOAT:
        {
            op.USED     = T100TRUE;
            return parseExpression(op);
        }
        break;
    case T100KEYWORD_VARIABLE:
        {
            op.USED     = T100TRUE;
            return parseVariable(op);
        }
        break;
    case T100KEYWORD_LABEL:
        {
            op.USED     = T100TRUE;
            return parseLabel(op);
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        }
        break;
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    }

    return T100FALSE;
}

T100BOOL T100Sentence::parseOperator(T100OPERATOR_COMPLEXUS& op)
{
    T100BOOL    result          = T100FALSE;

    m_type              = S_NONE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        };
    };

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_POUND:
        {
            m_type      = S_VAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_EMAIL:
        {
            m_type      = S_ADD;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
    case T100KEYWORD_ACF:
    case T100KEYWORD_AMF:
    case T100KEYWORD_AOF:
        {
            return parseRegister(op.OFFSET);
        }
        break;
    case T100CONSTANT_INTEGER:
    case T100CONSTANT_FLOAT:
        {
            op.OFFSET.USED      = T100TRUE;
            return parseExpression(op.OFFSET);
        }
        break;
    case T100KEYWORD_VARIABLE:
        {
            op.OFFSET.USED      = T100TRUE;
            return parseVariable(op.OFFSET);
        }
        break;
    case T100KEYWORD_LABEL:
        {
            op.OFFSET.USED      = T100TRUE;
            return parseLabel(op.OFFSET);
        }
        break;
    case T100CHAR_OPEN_BRACE:
        {
            op.USED     = T100TRUE;
            return parseBrace(op.BASE, op.OFFSET);
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        }
        break;
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    }

    return T100FALSE;
}


T100BOOL T100Sentence::parseComplexus(T100OPERATOR_COMPLEXUS& op)
{
    T100BOOL    result          = T100FALSE;

    m_type  = S_NONE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        };
    };

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_POUND:
        {
            m_type      = S_VAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_EMAIL:
        {
            m_type      = S_ADD;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
    case T100KEYWORD_ACF:
    case T100KEYWORD_AMF:
    case T100KEYWORD_AOF:
        {
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseRegister(op.OFFSET);
        }
        break;
    case T100CONSTANT_INTEGER:
    case T100CONSTANT_FLOAT:
        {
            op.OFFSET.USED      = T100TRUE;
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseExpression(op.OFFSET);
        }
        break;
    case T100KEYWORD_VARIABLE:
        {
            op.OFFSET.USED      = T100TRUE;
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseVariable(op.OFFSET);
        }
        break;
    case T100KEYWORD_LABEL:
        {
            op.OFFSET.USED      = T100TRUE;
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseLabel(op.OFFSET);
        }
        break;
    case T100CHAR_OPEN_BRACE:
        {
            op.USED             = T100TRUE;
            op.SYMBOL_TYPE      = m_type;
            op.TYPE             = T100OPERATOR_THREE_THREE;
            return parseBrace(op.BASE, op.OFFSET);
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        }
        break;
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    }

    return T100FALSE;
}


T100BOOL T100Sentence::parseOperator(T100OPERATOR_BINOCULAR& op)
{
    T100BOOL    result          = T100FALSE;

    result = parseComplexus(op.TARGET);
    if(!result){
        return T100FALSE;
    }

    result = parseComplexus(op.SOURCE);
    if(!result){
        return T100FALSE;
    }

    /*
    if(op.TARGET.OFFSET.USED && op.SOURCE.OFFSET.USED){
        //T100Error::error(//T100HintFormat::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }
    */

    if(T100OPERATOR_THREE_THREE == op.TARGET.TYPE){
        op.TYPE         = T100OPERATOR_THREE_THREE;
        op.SOURCE.TYPE  = T100OPERATOR_THREE_THREE;
    }else if(T100OPERATOR_THREE_THREE == op.SOURCE.TYPE){
        op.TYPE         = T100OPERATOR_THREE_THREE;
        op.TARGET.TYPE  = T100OPERATOR_THREE_THREE;
    }else{
        op.TYPE = T100OPERATOR_ONE_ONE;
    }

    return T100TRUE;
}

T100BOOL T100Sentence::buildOperator(T100BuildInfo* code, T100OPERATOR& target, T100OPERATOR_BUILD& info)
{
    T100BOOL    result          = T100FALSE;

    //info.BASE_USED      = T100FALSE;
    //info.BASE_TYPE      = T_NONE;

    switch(target.DATA_TYPE)
    {
    case T100DATA_COR:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_COR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_COR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_CBR:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_CBR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_CBR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_CCR:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_CCR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_CCR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_AAR:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_AAR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_AAR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ABR:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_ABR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_ABR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ACR:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_ACR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_ACR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ADR:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_ADR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_ADR;
                }
                break;
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_ACF:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_ACF;
                }
                break;
            /*
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_ACF;
                }
                break;
            */
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_AMF:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_AMF;
                }
                break;
            /*
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_AMF;
                }
                break;
            */
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_AOF:
        {
            info.OPERATOR_FLAG      = T100FALSE;
            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_AOF;
                }
                break;
            /*
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = I_AOF;
                }
                break;
            */
            default:
                return T100FALSE;
            }
        }
        break;
    case T100DATA_INTEGER:
        {
            info.OPERATOR_FLAG      = T100TRUE;
            info.OPERATOR_VALUE     = target.VALUE;
            info.OFFSET++;
            info.OPERATOR_OFFSET    = info.OFFSET;

            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_IMM;
                }
                break;
            case S_ADD:
                {
                    info.OPERATOR_TYPE      = T_COR;
                }
                break;
            case S_VAL:
                {
                    info.OPERATOR_TYPE      = T_IMM;
                }
                break;
            default:
                return T100FALSE;
            };
        }
        break;
    case T100DATA_FLOAT:
        {
            info.OPERATOR_FLAG      = T100TRUE;
            info.OPERATOR_VALUE     = target.VALUE;
            info.OFFSET++;
            info.OPERATOR_OFFSET    = info.OFFSET;

            switch(target.ADDR_TYPE)
            {
            case S_NONE:
                {
                    info.OPERATOR_TYPE      = T_IMM;
                }
                break;
            default:
                {
                    //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                    return T100FALSE;
                }
                break;
            };
        }
        break;
    case T100DATA_STRING:
        {
            //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
            return T100FALSE;
        }
        break;
    case T100DATA_LABEL:
        {
            info.OPERATOR_FLAG      = T100TRUE;

            switch(target.ADDR_TYPE)
            {
            case S_NONE:
            case S_ADD:
                {
                    T100WORD        offset;
                    info.OPERATOR_TYPE      = T_IMM;

                    result = code->getLabel(target.NAME, offset);
                    T100LABEL_CALL* item    = T100NEW T100LABEL_CALL();
                    item->name              = target.NAME;
                    //test
                    info.OFFSET++;
                    info.OPERATOR_OFFSET    = info.OFFSET;

                    T100WORD    temp;

                    temp = code->getOffset() + info.OPERATOR_OFFSET;
                    item->offset            = code->getOffset() + info.OPERATOR_OFFSET;

                    code->addLabelCall(item);

                    info.OPERATOR_VALUE     = offset;
                }
                break;
            default:
                {
                    //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                    return T100FALSE;
                }
                break;
            };
        }
        break;
    case T100DATA_VARIABLE:
        {
            T100WORD        offset;
            info.OPERATOR_FLAG      = T100TRUE;

            T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(target.NAME);           //T100ProduceInfo::getVariableDefine(target.NAME);
            if(!vd){
                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                return T100FALSE;
            }

            //test
            if(vd->isarray){
                if(target.ISARRAY){
                    if(target.LENGTH >= vd->length){
                        //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                        return T100FALSE;
                    }else{
                        info.OPERATOR_ARRAY     = T100TRUE;
                        info.OPERATOR_INDEX     = target.LENGTH;
                    }
                }else{

                }
            }else if(vd->isarray != target.ISARRAY){
                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                return T100FALSE;
            }

            result = code->getVariable(target.NAME, offset);
            offset = vd->offset;

            T100VARIABLE_CALL* item = T100NEW T100VARIABLE_CALL();

            item->name              = target.NAME;
            info.OFFSET++;
            info.OPERATOR_OFFSET    = info.OFFSET;
            item->offset            = code->getOffset() + info.OPERATOR_OFFSET;

            code->addVariableCall(item);

            //test
            target.ISSHARE  = vd->isshare;

            T100BOOL value = target.ISSHARE;

            info.OPERATOR_VALUE     = offset;

            switch(vd->type)
            {
            case T100DATA_INTEGER:
            case T100DATA_FLOAT:
                {
                    switch(target.ADDR_TYPE)
                    {
                    case S_NONE:
                        {
                            if(info.OPERATOR_ARRAY){
                                if(target.ISSHARE){
                                    info.OPERATOR_TYPE      = ST_ARR;
                                }else{
                                    info.OPERATOR_TYPE      = T_ARR;
                                }
                                info.OFFSET++;
                            }else{
                                if(target.ISSHARE){
                                    info.OPERATOR_TYPE      = ST_MEM;
                                }else{
                                    info.OPERATOR_TYPE      = T_MEM;
                                }
                            }
                        }
                        break;
                    case S_ADD:
                        {
                            if(target.ISSHARE){
                                info.OPERATOR_TYPE      = ST_IMM;
                            }else{
                                info.OPERATOR_TYPE      = T_IMM;
                            }

                            if(info.OPERATOR_ARRAY){
                                return T100FALSE;
                            }
                        }
                        break;
                    case S_VAL:
                        {
                            if(info.OPERATOR_ARRAY){
                                if(target.ISSHARE){
                                    info.OPERATOR_TYPE      = SI_ARR;
                                }else{
                                    info.OPERATOR_TYPE      = I_ARR;
                                }
                                info.OFFSET++;
                            }else{
                                if(target.ISSHARE){
                                    info.OPERATOR_TYPE      = SI_MEM;
                                }else{
                                    info.OPERATOR_TYPE      = I_MEM;
                                }
                            }
                        }
                        break;
                    default:
                        return T100FALSE;
                    };
                }
                break;
            case T100DATA_STRING:
                {
                    switch(target.ADDR_TYPE)
                    {
                    case S_NONE:
                    case S_ADD:
                        {
                            if(target.ISSHARE){
                                info.OPERATOR_TYPE      = ST_IMM;
                            }else{
                                info.OPERATOR_TYPE      = T_IMM;
                            }
                        }
                        break;
                    case S_VAL:
                        {
                            if(target.ISSHARE){
                                info.OPERATOR_TYPE      = ST_MEM;
                            }else{
                                info.OPERATOR_TYPE      = T_MEM;
                            }
                        }
                        break;
                    default:
                        return T100FALSE;
                    };
                }
                break;
            };
        }
        break;
    };

    return T100TRUE;
}

T100BOOL T100Sentence::buildOperator(T100BuildInfo* code, T100OPERATOR_COMPLEXUS& op, T100OPERATOR_BUILD& info)
{
    T100BOOL    result          = T100FALSE;

    info.BASE_USED      = T100FALSE;
    info.BASE_TYPE      = T_NONE;

    if(op.USED){
        info.BASE_USED      = T100TRUE;

        switch(op.BASE.DATA_TYPE)
        {
        case T100DATA_COR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_COR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_COR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_CBR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_CBR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_CBR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_CCR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_CCR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_CCR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_AAR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_AAR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_AAR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_ABR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_ABR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_ABR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_ACR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_ACR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_ACR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_ADR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_ADR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_ADR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_INTEGER:
            {
                info.BASE_FLAG      = T100TRUE;
                info.BASE_VALUE     = op.BASE.VALUE;
                info.OFFSET++;
                info.BASE_OFFSET    = info.OFFSET;

                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_IMM;
                    }
                    break;
                case S_ADD:
                    {
                        info.BASE_TYPE      = T_COR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = T_IMM;
                    }
                    break;
                };
            }
            break;
        case T100DATA_FLOAT:
            {
                info.BASE_FLAG      = T100TRUE;
                info.BASE_VALUE     = op.BASE.VALUE;
                info.OFFSET++;
                info.BASE_OFFSET    = info.OFFSET;

                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_IMM;
                    }
                    break;
                default:
                    {
                        //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                        return T100FALSE;
                    }
                    break;
                };
            }
            break;
        case T100DATA_STRING:
            {
                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                return T100FALSE;
            }
            break;
        case T100DATA_LABEL:
            {
                info.BASE_FLAG      = T100TRUE;

                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                case S_ADD:
                    {
                        T100WORD        offset;
                        info.BASE_TYPE      = T_IMM;

                        result = code->getLabel(op.BASE.NAME, offset);
                        T100LABEL_CALL* item    = T100NEW T100LABEL_CALL();
                        item->name              = op.BASE.NAME;
                        //test
                        info.OFFSET++;
                        info.BASE_OFFSET        = info.OFFSET;
                        item->offset            = code->getOffset() + info.BASE_OFFSET;

                        code->addLabelCall(item);

                        info.BASE_VALUE         = offset;
                    }
                    break;
                default:
                    {
                        //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                        return T100FALSE;
                    }
                    break;
                };
            }
            break;
        case T100DATA_VARIABLE:
            {
                T100WORD        offset;
                info.BASE_FLAG      = T100TRUE;

                T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(op.BASE.NAME);
                if(!vd){
                    //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                    return T100FALSE;
                }

                result = code->getVariable(op.BASE.NAME, offset);
                offset = vd->offset;

                T100VARIABLE_CALL* item     = T100NEW T100VARIABLE_CALL();

                item->name                  = op.BASE.NAME;
                info.OFFSET++;
                info.BASE_OFFSET            = info.OFFSET;
                item->offset                = code->getOffset() + info.BASE_OFFSET;

                code->addVariableCall(item);

                info.BASE_VALUE             = offset;

                switch(vd->type)
                {
                case T100DATA_INTEGER:
                case T100DATA_FLOAT:
                    {
                        switch(op.BASE.ADDR_TYPE)
                        {
                        case S_NONE:
                            {
                                info.BASE_TYPE      = T_MEM;
                            }
                            break;
                        case S_ADD:
                            {
                                info.BASE_TYPE      = T_IMM;
                            }
                            break;
                        case S_VAL:
                            {
                                info.BASE_TYPE      = I_MEM;
                            }
                            break;
                        default:
                            return T100FALSE;
                        };
                    }
                    break;
                case T100DATA_STRING:
                    {
                        switch(op.BASE.ADDR_TYPE)
                        {
                        case S_NONE:
                        case S_ADD:
                            {
                                info.BASE_TYPE      = T_IMM;
                            }
                            break;
                        case S_VAL:
                            {
                                info.BASE_TYPE      = T_MEM;
                            }
                            break;
                        default:
                            {
                                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                                return T100FALSE;
                            }
                            break;
                        };
                    }
                    break;
                };
            }
            break;
        };
    };

    result = buildOperator(code, op.OFFSET, info);

    return result;

}

T100BOOL T100Sentence::buildOperator(T100BuildInfo* code, T100OPERATOR_BINOCULAR& op, T100OPERATOR_INFO& info)
{
    T100BOOL    result          = T100FALSE;

    info.TYPE   = op.TYPE;

    switch(op.TYPE){
    case T100OPERATOR_ONE_ONE:
        {
            info.TARGET.OFFSET  = 0;
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            info.TARGET.OFFSET  = 1;
        }
        break;
    default:
        info.TARGET.OFFSET = 0;
    }

    result = buildComplexus(code, op.TARGET, info.TARGET);
    if(!result){
        return T100FALSE;
    }

    info.SOURCE.OFFSET      = info.TARGET.OFFSET;

    result = buildComplexus(code, op.SOURCE, info.SOURCE);

    /*
    if(result){
        if(S_NONE == info.TARGET.TYPE
           && !info.TARGET.BASE_USED
           && S_NONE == info.SOURCE.TYPE
           && !info.SOURCE.BASE_USED){
                info.TYPE   = T100OPERATOR_TWO;
           }else{
                info.TYPE   = T100OPERATOR_SIX;
                if(info.TARGET.BASE_FLAG){
                    info.TARGET.BASE_OFFSET++;
                }
                if(info.TARGET.OPERATOR_FLAG){
                    info.TARGET.OPERATOR_OFFSET++;
                }
                if(info.SOURCE.BASE_FLAG){
                    info.SOURCE.BASE_OFFSET++;
                }
                if(info.SOURCE.OPERATOR_FLAG){
                    info.SOURCE.OPERATOR_OFFSET++;
                }
           }
    }
    */

    return result;
}


T100BOOL T100Sentence::buildComplexus(T100BuildInfo* code, T100OPERATOR_COMPLEXUS& op, T100OPERATOR_BUILD& info)
{
    T100BOOL    result          = T100FALSE;

    info.BASE_USED      = T100FALSE;
    info.BASE_TYPE      = T_NONE;

    switch(op.SYMBOL_TYPE){
    case S_NONE:
        {
            info.TYPE   = T_NONE;
        }
        break;
    case S_ADD:
        {
            info.TYPE   = T_IMM;
        }
        break;
    case S_VAL:
        {
            info.TYPE   = I_MEM;
        }
        break;
    default:
        return result;
    }

    if(op.USED){
        info.BASE_USED      = T100TRUE;

        switch(op.BASE.DATA_TYPE)
        {
        case T100DATA_COR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_COR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_COR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_CBR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_CBR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_CBR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_CCR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_CCR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_CCR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_AAR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_AAR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_AAR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_ABR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_ABR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_ABR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_ACR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_ACR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_ACR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_ADR:
            {
                info.BASE_FLAG      = T100FALSE;
                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_ADR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = I_ADR;
                    }
                    break;
                default:
                    return T100FALSE;
                }
            }
            break;
        case T100DATA_INTEGER:
            {
                info.BASE_FLAG      = T100TRUE;
                info.BASE_VALUE     = op.BASE.VALUE;
                info.OFFSET++;
                info.BASE_OFFSET    = info.OFFSET;

                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_IMM;
                    }
                    break;
                case S_ADD:
                    {
                        info.BASE_TYPE      = T_COR;
                    }
                    break;
                case S_VAL:
                    {
                        info.BASE_TYPE      = T_IMM;
                    }
                    break;
                };
            }
            break;
        case T100DATA_FLOAT:
            {
                info.BASE_FLAG      = T100TRUE;
                info.BASE_VALUE     = op.BASE.VALUE;
                info.OFFSET++;
                info.BASE_OFFSET    = info.OFFSET;

                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                    {
                        info.BASE_TYPE      = T_IMM;
                    }
                    break;
                default:
                    {
                        //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                        return T100FALSE;
                    }
                    break;
                };
            }
            break;
        case T100DATA_STRING:
            {
                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                return T100FALSE;
            }
            break;
        case T100DATA_LABEL:
            {
                info.BASE_FLAG      = T100TRUE;

                switch(op.BASE.ADDR_TYPE)
                {
                case S_NONE:
                case S_ADD:
                    {
                        T100WORD        offset;
                        info.BASE_TYPE      = T_IMM;

                        result = code->getLabel(op.BASE.NAME, offset);
                        T100LABEL_CALL* item    = T100NEW T100LABEL_CALL();
                        item->name              = op.BASE.NAME;
                        //test
                        info.OFFSET++;
                        info.BASE_OFFSET        = info.OFFSET;
                        item->offset            = code->getOffset() + info.BASE_OFFSET;

                        code->addLabelCall(item);

                        info.BASE_VALUE         = offset;
                    }
                    break;
                default:
                    {
                        //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                        return T100FALSE;
                    }
                    break;
                };
            }
            break;
        case T100DATA_VARIABLE:
            {
                T100WORD        offset;
                info.BASE_FLAG      = T100TRUE;

                T100VARIABLE_DEFINE* vd = T100ProduceInfo::getVariableDrawer().getVariableDefine(op.BASE.NAME);
                if(!vd){
                    //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                    return T100FALSE;
                }

                result = code->getVariable(op.BASE.NAME, offset);
                offset = vd->offset;

                T100VARIABLE_CALL* item     = T100NEW T100VARIABLE_CALL();

                item->name                  = op.BASE.NAME;
                info.OFFSET++;
                info.BASE_OFFSET            = info.OFFSET;
                item->offset                = code->getOffset() + info.BASE_OFFSET;

                code->addVariableCall(item);

                info.BASE_VALUE             = offset;

                switch(vd->type)
                {
                case T100DATA_INTEGER:
                case T100DATA_FLOAT:
                    {
                        switch(op.BASE.ADDR_TYPE)
                        {
                        case S_NONE:
                            {
                                info.BASE_TYPE      = T_MEM;
                            }
                            break;
                        case S_ADD:
                            {
                                info.BASE_TYPE      = T_IMM;
                            }
                            break;
                        case S_VAL:
                            {
                                info.BASE_TYPE      = I_MEM;
                            }
                            break;
                        default:
                            return T100FALSE;
                        };
                    }
                    break;
                case T100DATA_STRING:
                    {
                        switch(op.BASE.ADDR_TYPE)
                        {
                        case S_NONE:
                        case S_ADD:
                            {
                                info.BASE_TYPE      = T_IMM;
                            }
                            break;
                        case S_VAL:
                            {
                                info.BASE_TYPE      = T_MEM;
                            }
                            break;
                        default:
                            {
                                //T100AssemblyError::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
                                return T100FALSE;
                            }
                            break;
                        };
                    }
                    break;
                };
            }
            break;
        };
    };

    result = buildOperator(code, op.OFFSET, info);

    return result;

}

T100BOOL T100Sentence::buildInfo(T100ORDER_TYPE type, T100BuildInfo* code, T100OPERATOR_INFO& info)
{
    T100BOOL            result      = T100TRUE;
    T100WORD_BITS       order;

    order.BYTE0.BYTE    = type;

    switch(info.TYPE){
    case T100OPERATOR_ONE_ONE:
        {
            order.BYTE1.BYTE    = T100OPERATOR_ONE_ONE;

            order.BYTE2.BYTE    = info.TARGET.OPERATOR_TYPE;
            order.BYTE3.BYTE    = info.SOURCE.OPERATOR_TYPE;

            code->setValue(order.WORD);
            code->next();

            if(info.TARGET.OPERATOR_FLAG){
                code->setValue(info.TARGET.OPERATOR_VALUE);
                code->next();
            }

            if(info.SOURCE.OPERATOR_FLAG){
                code->setValue(info.SOURCE.OPERATOR_VALUE);
                code->next();
            }
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            order.BYTE1.BYTE    = T100OPERATOR_THREE_THREE;

            order.BYTE2.BYTE    = info.TARGET.TYPE;
            order.BYTE3.BYTE    = info.SOURCE.TYPE;

            code->setValue(order.WORD);
            code->next();

            order.BYTE0.BYTE    = info.TARGET.BASE_TYPE;
            order.BYTE1.BYTE    = info.TARGET.OPERATOR_TYPE;
            order.BYTE2.BYTE    = info.SOURCE.BASE_TYPE;
            order.BYTE3.BYTE    = info.SOURCE.OPERATOR_TYPE;

            code->setValue(order.WORD);
            code->next();

            if(info.TARGET.BASE_USED && info.TARGET.BASE_FLAG){
                code->setValue(info.TARGET.BASE_VALUE);
                code->next();
            }

            if(info.TARGET.OPERATOR_FLAG){
                code->setValue(info.TARGET.OPERATOR_VALUE);
                code->next();

                if(info.TARGET.OPERATOR_ARRAY){
                    code->setValue(info.TARGET.OPERATOR_INDEX);
                    code->next();
                }
            }

            if(info.SOURCE.BASE_USED && info.SOURCE.BASE_FLAG){
                code->setValue(info.SOURCE.BASE_VALUE);
                code->next();
            }

            if(info.SOURCE.OPERATOR_FLAG){
                code->setValue(info.SOURCE.OPERATOR_VALUE);
                code->next();

                if(info.SOURCE.OPERATOR_ARRAY){
                    code->setValue(info.SOURCE.OPERATOR_INDEX);
                    code->next();
                }
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}

T100BOOL T100Sentence::getProcedureOffset(T100BuildInfo* info, T100String name, T100WORD& offset)
{
        T100BOOL            result          = T100TRUE;

        result = info->getProcedure(name, offset);

        if(!result){
            T100PROCEDURE_DEFINE*   pd = T100ProduceInfo::getProcedureDrawer().getProcedureDefine(name);

            if(pd){
                offset = pd->offset;
            }else{
                return T100FALSE;
            }
        }

        return result;
}

