#include "T100FileToken.h"

T100FileToken::T100FileToken()
{
    //ctor
    create();
}

T100FileToken::~T100FileToken()
{
    //dtor
    destroy();
}

T100VOID T100FileToken::create()
{

}

T100VOID T100FileToken::destroy()
{
    for(auto item : segments){
        T100DELETE(item);
    }

    segments.clear();
}

T100STDSTRING T100FileToken::tostring()
{
    T100STDSTRING result;

    result = "Master: ";
    if(master){
        result += "TRUE";
    }else{
        result += "FALSE";
    }
    result += " ";
    result += "Path: ";
    result += path.to_std_string();
    result += " ";
    result += "File: ";
    result += file.to_std_string();

    return result;
}

T100VOID T100FileToken::clear()
{
    master      = T100FALSE;
    path.clear();
    file.clear();

    segments.clear();

    T100Token::clear();
}

T100FileToken* T100FileToken::copy()
{
    T100FileToken* token = T100NEW T100FileToken();

    token->type     = type;
    token->eof      = eof;
    token->err      = err;
    token->row      = row;

    token->master   = master;
    token->segments = segments;

    return token;
}
