#include "T100SentenceToken.h"

#include "T100Sentence.h"

namespace T100Assembly{

T100SentenceToken::T100SentenceToken()
    :T100Component::T100Token()
{
    //ctor
}

T100SentenceToken::~T100SentenceToken()
{
    //dtor
}

T100SentenceToken* T100SentenceToken::copy()
{
    T100SentenceToken*  token = T100NEW T100SentenceToken();

    token->type     = type;
    token->eof      = eof;
    token->err      = err;
    token->row      = row;

    token->value    = value;

    return token;
}

T100VOID T100SentenceToken::clear()
{
    value       = T100NULL;

    T100Token::clear();
}

}
