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

T100BOOL T100String32Tools::split(T100String line, T100String mask, T100STRING_VECTOR& result)
{

}

T100BOOL T100String32Tools::compare(T100WORD* data, T100WORD length, T100String& source)
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;
    T100WORD    slength;
    T100WORD    tlength;
    T100WORD*   sdata;

    slength = source.length();
    if(slength > length){
        return T100FALSE;
    }

    if(!data){
        return T100FALSE;
    }

    tlength = data[0];

    if(slength == tlength){
        sdata   = source.to_string().raw_data();
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
