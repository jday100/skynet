#include "T100StringTools.h"

#include <iconv.h>
#include <string.h>
#include <sstream>


T100StringTools::T100StringTools()
{
    //ctor
}

T100StringTools::~T100StringTools()
{
    //dtor
}

T100String T100StringTools::format(T100String source)
{
    T100STDSTRING32     target;
    T100STDSTRING32     result;
    T100WORD            size;

    target = source.to_std_string32();

    if(target.size() < 3){
        return T100String();
    }

    size = target.size() - 1;

    for(int i=1;i<size;i++){
        result += target[i];
    }

    T100String temp(result);

    return temp;
}

T100BOOL T100StringTools::copy(T100WORD* target, T100WORD* source, T100WORD length)
{
    if(T100NULL == target || T100NULL == source){
        return T100FALSE;
    }

    T100WORD    size;

    if(length > source[0]){
        length = source[0];
    }

    size = length + 1;

    target[0] = length;

    for(int i=1;i<size;i++){
        target[i] = source[i];
    }

    target[size + 1] = 0;

    return T100TRUE;
}

T100String T100StringTools::to_string(T100WORD* data, T100WORD length)
{
    data++;

    T100String result((T100CHAR32*)data);

    return result;
}

T100BOOL T100StringTools::compare(T100WORD* data, T100WORD length, T100String source)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100WORD    slength;
    T100WORD    tlength;
    T100WORD*   sdata;

    slength = source.getLength();
    if(slength > length){
        return T100FALSE;
    }

    if(!data){
        return T100FALSE;
    }

    tlength = data[0];

    if(slength == tlength){
        sdata   = source.getRawData();
        for(int i=0;i<slength+2;i++){
            if(data[i] == sdata[i]){

            }else{
                return T100FALSE;
            }
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100StringTools::split(T100STDSTRING& line, T100STDSTRING separator, T100STDSTRING_VECTOR& cmds)
{
    T100STDCHAR*        source      = T100NULL;
    T100STDCHAR*        item        = T100NULL;
    T100STDSTRING       str;

    source = (T100STDCHAR*)(line.c_str());

    item = ::strtok(source, separator.c_str());

    while(T100NULL != item){
        str = item;
        cmds.push_back(str);

        item = ::strtok(T100NULL, separator.c_str());
    }

    return T100TRUE;
}

T100BOOL T100StringTools::code_convert(T100STDSTRING source, T100STDSTRING target, T100STDCHAR* inbuf, size_t inlen, T100STDCHAR* outbuf, size_t outlen)
{
    T100BOOL    result      = T100TRUE;

    iconv_t         it;
    T100INTEGER     rc;
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

T100STDSTRING T100StringTools::to_string(T100DWORD value)
{
    T100STDSTRING result;

    std::stringstream ss;

    ss << value;
    ss >> result;

    return result;
}
