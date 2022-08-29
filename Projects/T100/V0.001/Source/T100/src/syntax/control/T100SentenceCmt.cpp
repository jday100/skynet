#include "T100SentenceCmt.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceCmt::T100SentenceCmt(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceCmt::~T100SentenceCmt()
{
    //dtor
}

T100BOOL T100SentenceCmt::parse()
{
    T100BOOL    result      = T100FALSE;

    result = parseValue();

    if(result){
        type            = T100SENTENCE_CMT;
        m_token->type   = T100SENTENCE_CMT;
    }

    return result;
}

T100BOOL T100SentenceCmt::parseValue()
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
            T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
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
            //id = std::stoi(m_item->data.to_std_string());
            id = std::stoll(m_item->data.to_std_string().c_str(), T100NULL, 0);
            setLoaded(T100FALSE);
            return T100TRUE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }

    T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceCmt::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_CMT;

    code->setValue(order.WORD);
    code->next();

    code->setValue(id);
    code->next();

    return T100TRUE;
}
