#include "T100SentenceCall.h"

#include "T100ProduceInfo.h"


T100SentenceCall::T100SentenceCall(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceCall::~T100SentenceCall()
{
    //dtor
}

T100BOOL T100SentenceCall::parse()
{
    T100BOOL        result          = T100TRUE;

    result = parseProcedure();

    if(result){
        type            = T100SENTENCE_CALL;
        m_token->type   = T100SENTENCE_CALL;
    }

    return result;
}

T100BOOL T100SentenceCall::parseProcedure()
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
            //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_LABEL:
        {
            name    = m_item->value;

            setLoaded(T100FALSE);
            return T100TRUE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }

    //T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceCall::build(T100BuildInfo* info)
{
    T100BOOL        result          = T100FALSE;
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_CALL;
    order.BYTE1.BYTE = T_NONE;
    order.BYTE2.BYTE = T_IMM;

    T100WORD    offset;

    result = getProcedureOffset(info, name, offset);
    if(!result){
        return T100FALSE;
    }

    T100PROCEDURE_CALL* item = T100NEW T100PROCEDURE_CALL;

    item->name      = name;
    item->offset    = info->getOffset() + 1;

    info->addProcedureCall(item);

    info->setValue(order.WORD);
    info->next();

    info->setValue(offset);
    info->next();

    return T100TRUE;
}
