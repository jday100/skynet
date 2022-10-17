#include "T100String32Tools.h"

T100String32Tools::T100String32Tools()
{
    //ctor
}

T100String32Tools::~T100String32Tools()
{
    //dtor
}

T100String32 T100String32Tools::to_string(T100WORD* data, T100WORD length)
{
    data++;

    T100String32    result((T100CHAR32*)data);

    return result;
}

T100BOOL T100String32Tools::format(T100String source, T100String& target)
{
    T100BOOL            result          = T100TRUE;
    T100WORD            size;
    T100STRING32        s;

    size = source.length();

    if(2 >= size){
        return T100TRUE;
    }

    s = source.to_string().getString32();

    T100STRING32 t(s.begin()+2, s.end()-2);

    target = T100String32(const_cast<char32_t*>(t.c_str()));

    return result;
}

T100BOOL T100String32Tools::copy(T100WORD* target, T100WORD* source, T100WORD length)
{
    if(T100NULL == target || T100NULL == source){
        return T100FALSE;
    }

    T100WORD        size;

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

T100BOOL T100String32Tools::split(T100String line, T100String mask, T100STRING_VECTOR& strs)
{
    T100BOOL            result          = T100TRUE;
    T100WCHAR*          source          = T100NULL;
    T100WCHAR*          item            = T100NULL;
    T100WSTRING         str;

    source = const_cast<T100WCHAR*>(line.m_wstring.c_str());

    item = ::wcstok(source, mask.m_wstring.c_str());

    while(T100NULL != item){
        str = item;
        strs.push_back(str);

        item = ::wcstok(T100NULL, mask.m_wstring.c_str());
    }

    return result;
}

T100BOOL T100String32Tools::compare(T100WORD* data, T100WORD length, T100String& source)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100WORD    slength;
    T100WORD    tlength;
    T100WORD*   sdata;

    T100WORD    s;
    T100WORD    t;

    T100WORD    temp;

    temp    = source.to_string().raw_data()[0];
    sdata   = source.to_string().raw_data();
    temp    = sdata[0];

    temp    = source.to_string().raw_data()[0];


    slength = source.length();
    if(slength > length){
        return T100FALSE;
    }

    if(!data){
        return T100FALSE;
    }

    tlength = data[0];

    if(slength == tlength){
        //sdata   = source.to_string().raw_data();
        for(int i=0;i<slength+2;i++){
            //test
            //s = sdata[i];
            s = source.to_string().raw_data()[i];
            t = data[i];

            if(s == t){

            }else{
                return T100FALSE;
            }
        }
    }else{
        result = T100FALSE;
    }

    return result;
}
