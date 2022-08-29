#include "T100PartToken.h"

T100PartToken::T100PartToken()
{
    //ctor
    create();
}

T100PartToken::~T100PartToken()
{
    //dtor
    destroy();
}

T100VOID T100PartToken::create()
{

}

T100VOID T100PartToken::destroy()
{
    for(auto item : segments){
        T100SAFE_DELETE(item);
    }

    segments.clear();
}

T100PartToken* T100PartToken::copy()
{
    T100PartToken*  token = T100NEW T100PartToken();

    token->type     = type;
    token->eof      = eof;
    token->err      = err;
    token->row      = row;

    token->master   = master;
    token->segments = segments;

    return token;
}

T100VOID T100PartToken::clear()
{
    segments.clear();

    T100Token::clear();
}
