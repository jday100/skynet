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
        T100DELETE(item);
    }
}

T100STDSTRING T100SegmentToken::tostring()
{
    return name.to_std_string();
}

T100SegmentToken* T100SegmentToken::copy()
{
    T100SegmentToken* token = T100NEW T100SegmentToken();

    token->type         = type;
    token->eof          = eof;
    token->err          = err;
    token->row          = row;

    token->sentences    = sentences;

    return token;
}

T100VOID T100SegmentToken::clear()
{
    type        = T100TOKEN_NONE;

    master      = T100FALSE;
    name.clear();
    sentences.clear();
}
