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
    T100BOOL    result      = T100TRUE;

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

T100LONG T100StringTools::to_long(T100WSTRING str)
{
    return std::stoll(str.c_str(), T100NULL, 0);
}

T100FLOAT T100StringTools::to_float(T100WSTRING str)
{
    return std::stof(str);
}
