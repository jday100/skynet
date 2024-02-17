#include "T100ByteTools.h"

T100ByteTools::T100ByteTools()
{
    //ctor
}

T100ByteTools::~T100ByteTools()
{
    //dtor
}

T100INT64 T100ByteTools::swop(T100INT64 value)
{
    T100INT64_MIX       result;
    T100INT64_MIX       temp;

    temp.VALUE  = value;

    result.DATA[0]  = temp.DATA[7];
    result.DATA[1]  = temp.DATA[6];
    result.DATA[2]  = temp.DATA[5];
    result.DATA[3]  = temp.DATA[4];

    result.DATA[4]  = temp.DATA[3];
    result.DATA[5]  = temp.DATA[2];
    result.DATA[6]  = temp.DATA[1];
    result.DATA[7]  = temp.DATA[0];

    return result.VALUE;
}

T100VOID T100ByteTools::swop(T100BYTE* source, T100BYTE* target, T100INT32 length)
{
    T100INT32   value;

    value   = length - 1;
    for(int i=0;i<value;i++){
        target[i]   = source[value-i];
    }
}
