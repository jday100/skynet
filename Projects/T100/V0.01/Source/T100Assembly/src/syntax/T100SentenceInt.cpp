#include "T100SentenceInt.h"

T100SentenceInt::T100SentenceInt(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceInt::~T100SentenceInt()
{
    //dtor
}

T100BOOL T100SentenceInt::parse()
{
    T100BOOL        result          = T100TRUE;

    result = parseValue();

    if(result){
        type            = T100SENTENCE_INT;
        m_token->type   = T100SENTENCE_INT;
    }

    return result;
}

T100BOOL T100SentenceInt::parseValue()
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
    case T100CONSTANT_INTEGER:
        {
            id = std::stoi(m_item->value.to_wstring());
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

T100BOOL T100SentenceInt::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_INT;
    order.BYTE3.BYTE = id;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
