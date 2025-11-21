#ifndef T100BITCOMMON_H
#define T100BITCOMMON_H

#include "T100Common.h"

namespace T100LIBRARY{

typedef union T100BYTE_BIT{
    T100BYTE        BYTE;
    struct{
        T100BYTE    BYTE_LOW4   : 4;
        T100BYTE    BYTE_HIGH4  : 4;
    };
    struct{
        T100BOOL    BIT0        : 1;
        T100BOOL    BIT1        : 1;
        T100BOOL    BIT2        : 1;
        T100BOOL    BIT3        : 1;

        T100BOOL    BIT4        : 1;
        T100BOOL    BIT5        : 1;
        T100BOOL    BIT6        : 1;
        T100BOOL    BIT7        : 1;
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
    T100UINT64      UINT64;
    struct{
        T100UINT64      UINT64_LOW;
        T100UINT64      UINT64_HIGH;
    };
}T100UINT64_BIT;


}

#endif // T100BITCOMMON_H
