#ifndef T100BITCOMMON_H
#define T100BITCOMMON_H

#include "T100Common.h"

typedef union T100BYTE_BIT{
    T100BYTE        BYTE;
    struct{
        T100BYTE    BYTE_LOW4   : 4;
        T100BYTE    BYTE_HIGH4  : 4;
    };

    T100BOOL operator==(T100BYTE_BIT& data){
        if(BYTE == data.BYTE){
            return T100TRUE;
        }else{
            return T100FALSE;
        }
    };
}T100BYTE_BIT;

typedef union{
    T100DWORD   DWORD;
    struct{
        T100WORD    WORD_LOW;
        T100WORD    WORD_HIGH;
    };
}T100DWORD_BIT;

#endif // T100BITCOMMON_H
