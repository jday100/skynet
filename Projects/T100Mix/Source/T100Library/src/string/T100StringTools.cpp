#include "T100StringTools.h"

#include <iconv.h>
#include <string.h>

T100StringTools::T100StringTools()
{
    //ctor
}

T100StringTools::~T100StringTools()
{
    //dtor
}

T100BOOL T100StringTools::code_convert(T100STDSTRING source, T100STDSTRING target, T100STDCHAR* inbuf, size_t inlen, T100STDCHAR* outbuf, size_t outlen)
{
    T100BOOL        result          = T100TRUE;

    iconv_t         it;
    T100INT         rc;
    T100STDCHAR**   pin;
    T100STDCHAR**   pout;

    pin     = &inbuf;
    pout    = &outbuf;

    it = iconv_open(target.c_str(), source.c_str());
    if(0 == it){
        return T100FALSE;
    }

    memset(outbuf, 0, outlen);

    if(-1 == iconv(it, pin, &inlen, pout, &outlen)){
        iconv_close(it);
        return T100FALSE;
    }

    iconv_close(it);

    return result;
}

T100STDSTRING T100StringTools::utf8_to_gbk(T100STDSTRING& str)
{
    T100STDSTRING       value;
    T100BOOL            result;
    T100WORD            length;

    length  = str.size() * 2;

    T100STDCHAR         buffer[length];

    result = code_convert("UTF-8", "GBK", (T100STDCHAR*)str.c_str(), str.size(), buffer, length);
    if(result){
        value = buffer;
    }
    return value;
}

T100STDSTRING T100StringTools::gbk_to_utf8(T100STDSTRING& str)
{
    T100STDSTRING       value;
    T100BOOL            result;
    T100WORD            length;

    length  = str.size() * 2;

    T100STDCHAR         buffer[length];

    result = code_convert("GBK", "UTF-8", (T100STDCHAR*)str.c_str(), str.size(), buffer, length);
    if(result){
        value = buffer;
    }
    return value;
}

