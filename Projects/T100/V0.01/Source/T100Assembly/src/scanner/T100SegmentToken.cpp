#include "T100SegmentToken.h"

T100SegmentToken::T100SegmentToken()
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
    for(auto item : sentences){
        //T100SAFE_DELETE(item);
    }
}

T100SegmentToken* T100SegmentToken::copy()
{
    T100SegmentToken* token = T100NEW T100SegmentToken();

    token->type         = type;
    token->eof          = eof;
    token->err          = err;
    token->row          = row;

    token->sentences    = sentences;

    //test
    int i;

    i = token->sentences.size();

    return token;
}

T100VOID T100SegmentToken::clear()
{
    name.clear();
    sentences.clear();

    T100Token::clear();
}
