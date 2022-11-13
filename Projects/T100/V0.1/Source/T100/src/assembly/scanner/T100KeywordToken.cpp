#include "T100KeywordToken.h"

namespace T100Assembly{

T100KeywordToken::T100KeywordToken()
    :T100Component::T100Token()
{
    //ctor
}

T100KeywordToken::~T100KeywordToken()
{
    //dtor
}

T100VOID T100KeywordToken::clear()
{
    value.clear();

    T100Token::clear();
}

T100KeywordToken* T100KeywordToken::copy()
{
    T100KeywordToken*   token = T100NEW T100KeywordToken();

    token->type     = type;
    token->eof      = eof;
    token->err      = err;
    token->row      = row;

    token->value    = value;

    return token;
}

}
