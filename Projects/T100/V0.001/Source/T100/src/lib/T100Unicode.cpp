#include "T100Unicode.h"

#include <locale>
#include <codecvt>
#include "T100StringTools.h"


T100Unicode::T100Unicode()
{
    //ctor
}

T100Unicode::~T100Unicode()
{
    //dtor
}

T100STDSTRING T100Unicode::to_utf8(T100STDSTRING32 str)
{
    return std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}.to_bytes(str);
}

T100STDSTRING32 T100Unicode::to_utf32(T100STDSTRING str)
{
    return std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}.from_bytes(str);
}

T100STDSTRING T100Unicode::gbk_to_utf8(T100STDSTRING str)
{
    T100STDSTRING result;

    T100STDCHAR*    inbuf;
    T100STDCHAR*    outbuf;
    size_t          inlen;
    size_t          outlen;

    inbuf   = (T100STDCHAR*)str.c_str();
    inlen   = str.size();

    outlen  = inlen * 3;
    outbuf  = T100NEW T100STDCHAR[outlen];

    if(T100StringTools::code_convert("GBK", "UTF-8", inbuf, inlen, outbuf, outlen)){
        result = outbuf;
    }else{

    }

    T100DELETE(outbuf);

    return result;
}
