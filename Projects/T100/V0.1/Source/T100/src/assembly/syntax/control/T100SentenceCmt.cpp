#include "T100SentenceCmt.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceCmt::T100SentenceCmt(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceCmt::~T100SentenceCmt()
{
    //dtor
}

T100VOID T100SentenceCmt::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_CMT] = L"T100SentenceCmt";
}

T100BOOL T100SentenceCmt::parse()
{
    T100BOOL        result          = T100TRUE;

    result = parseValue();

    if(result){
        type            = T100SENTENCE_CMT;
        m_token->type   = T100SENTENCE_CMT;
    }

    return result;
}

T100BOOL T100SentenceCmt::parseValue()
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
            m_token->err    = T100ERROR_SENTENCE;
            return T100FALSE;
        }
        break;
    case T100Component::T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CONSTANT_INTEGER:
        {
            id = std::stoll(m_item->value.to_wstring().c_str(), T100NULL, 0);
            setLoaded(T100FALSE);
            return T100TRUE;
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            m_token->type   = T100Component::T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            return T100FALSE;
        }
        break;
    default:
        m_token->type   = T100Component::T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        return T100FALSE;
    }

    return T100FALSE;
}

T100BOOL T100SentenceCmt::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_CMT;

    info->setValue(order.WORD);
    info->next();

    info->setValue(id);
    info->next();

    return T100TRUE;
}

}
