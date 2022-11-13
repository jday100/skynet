#include "T100SegmentToken.h"

namespace T100Assembly{

T100SegmentToken::T100SegmentToken()
    :T100Component::T100Token()
{
    //ctor
    create();
}

T100SegmentToken::~T100SegmentToken()
{
    //dtor
    destroy();
}

T100VOID T100SegmentToken::create()
{

}

T100VOID T100SegmentToken::destroy()
{

}

T100SegmentToken* T100SegmentToken::copy()
{
    T100SegmentToken*   token = T100NEW T100SegmentToken();

    token->type         = type;
    token->eof          = eof;
    token->err          = err;
    token->row          = row;

    token->sentences    = sentences;

    return token;
}

T100VOID T100SegmentToken::clear()
{
    name.clear();
    sentences.clear();

    T100Token::clear();
}

}
