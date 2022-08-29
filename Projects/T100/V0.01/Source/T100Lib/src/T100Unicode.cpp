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

T100STRING8 T100Unicode::to_string8(T100STRING16& str)
{
    return (T100STRING8)std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes((std::u16string)str);
}

T100STRING16 T100Unicode::to_string16(T100STRING8& str)
{
    return (T100STRING16)std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes((std::string)str);
}

T100STRING8 T100Unicode::to_string8(T100STRING32& str)
{
    return (T100STRING8)std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}.to_bytes((std::u32string)str);
}

T100STRING32 T100Unicode::to_string32(T100STRING8& str)
{
    return (T100STRING32)std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}.from_bytes((std::string)str);
}

T100STRING16 T100Unicode::to_string16(T100STRING32& str)
{
    T100STRING16    value;

    for(int i=0;i<str.size();i++){
        value += str[i];
    }

    return value;
}

T100STRING32 T100Unicode::to_string32(T100STRING16& str)
{
    T100STRING32    value;

    for(int i=0;i<str.size();i++){
        value += str[i];
    }

    return value;
}

T100STRING8 T100Unicode::to_string8(T100WSTRING& str)
{
    return (T100STRING8)std::wstring_convert<std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>>{}.to_bytes((std::wstring)str);
}

T100WSTRING T100Unicode::to_wstring(T100STRING8& str)
{
    return (T100WSTRING)std::wstring_convert<std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>>{}.from_bytes((std::string)str);
}

T100STRING16 T100Unicode::to_string16(T100WSTRING& str)
{
    T100STRING16    value;

    for(int i=0;i<str.size();i++){
        value += str[i];
    }

    return value;
}

T100WSTRING T100Unicode::to_wstring(T100STRING16& str)
{
    T100WSTRING     value;

    for(int i=0;i<str.size();i++){
        value += str[i];
    }

    return value;
}

T100STRING32 T100Unicode::to_string32(T100WSTRING& str)
{
    T100STRING32    value;

    for(int i=0;i<str.size();i++){
        value += str[i];
    }

    return value;
}

T100WSTRING T100Unicode::to_wstring(T100STRING32& str)
{
    T100WSTRING     value;

    for(int i=0;i<str.size();i++){
        value += str[i];
    }

    return value;
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

    T100SAFE_DELETE(outbuf);

    return result;
}

