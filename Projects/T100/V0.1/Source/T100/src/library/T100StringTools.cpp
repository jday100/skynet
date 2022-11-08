#include "T100StringTools.h"

#include <iconv.h>
#include <string.h>


namespace T100Library{

T100StringTools::T100StringTools()
{
    //ctor
}

T100StringTools::~T100StringTools()
{
    //dtor
}

T100BOOL T100StringTools::split(T100WSTRING line, T100WSTRING mask, T100WSTRING_VECTOR& strs)
{
    T100BOOL        result          = T100TRUE;
    T100WCHAR*      source          = T100NULL;
    T100WCHAR*      item            = T100NULL;
    T100WSTRING     str;

    source  = const_cast<T100WCHAR*>(line.c_str());
    item    = ::wcstok(source, mask.c_str());

    while(T100NULL != item){
        str = item;
        strs.push_back(str);

        item = ::wcstok(T100NULL, mask.c_str());
    }

    return result;
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

T100LONG T100StringTools::to_long(T100WSTRING str)
{
    return std::stoll(str.c_str(), T100NULL, 0);
}

T100FLOAT T100StringTools::to_float(T100WSTRING str)
{
    return std::stof(str);
}

}
