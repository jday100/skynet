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

T100BOOL T100StringTools::startsWith(T100WSTRING source, T100WSTRING target)
{
    T100BOOL        result;

    T100INT         slength;
    T100INT         tlength;

    slength = source.length();
    tlength = target.length();

    if(slength < tlength){
        return T100FALSE;
    }else{

    }
}

T100BOOL T100StringTools::endsWith(T100WSTRING source, T100WSTRING target)
{
    T100BOOL        result;

    T100INT         slength;
    T100INT         tlength;

    slength = source.length();
    tlength = target.length();

    if(slength < tlength){
        return T100FALSE;
    }else{

    }
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


T100STRING_CODED_TYPE T100StringTools::test(T100CHAR8* chars)
{
    unsigned char ch;

    ch = chars[0];
    ch = chars[1];

    //输入“一”
    switch(chars[0]){
    case 0xa4:
        {
            if(0x40 == chars[1]){
                return T100STRING_CODED_BIG5;
            }
        }
        break;
    case 0xd2:
        {
            if(0xbb == chars[1]){
                return T100STRING_CODED_GBK;
            }
        }
        break;
    case 0xe4:
        {
            if(0xb8 == chars[1] && 0x80 == chars[2]){
                return T100STRING_CODED_UTF8;
            }
        }
        break;
    case 0x4e:
        {
            if(0 == chars[1]){
                return T100STRING_CODED_UTF16BE;
            }
        }
        break;
    case 0:
        {
            switch(chars[1]){
            case 0:
                {
                    switch(chars[2]){
                    case 0xfe:
                        {
                            if(0xff == chars[3] && 0 == chars[4]
                               && 0x4e == chars[5] && 0 == chars[6]
                               && 0 == chars[7]){
                                return T100STRING_CODED_UCS4;
                            }
                        }
                        break;
                    case 0x4e:
                        {
                            if(0 == chars[3]){
                                return T100STRING_CODED_UCS4;
                            }
                        }
                        break;
                    }
                }
                break;
            case 0x4e:
                {
                    return T100STRING_CODED_UTF16LE;
                }
                break;
            }
        }
        break;
    }

    return T100STRING_CODED_NONE;
}

}
