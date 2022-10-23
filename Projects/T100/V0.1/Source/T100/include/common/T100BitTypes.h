#ifndef T100BITTYPES_H
#define T100BITTYPES_H

#include "T100DataTypes.h"

//位操作结构体
typedef union{
    T100BYTE                BYTE;
    struct{
        T100BOOL            BIT0 : 1;
        T100BOOL            BIT1 : 1;
        T100BOOL            BIT2 : 1;
        T100BOOL            BIT3 : 1;
        T100BOOL            BIT4 : 1;
        T100BOOL            BIT5 : 1;
        T100BOOL            BIT6 : 1;
        T100BOOL            BIT7 : 1;
    };
}T100BYTE_BITS;

typedef union{
    T100HWORD               HWORD;
    struct{
        T100BYTE_BITS       BYTE_LOW;
        T100BYTE_BITS       BYTE_HIGH;
    };
}T100HWORD_BITS;

typedef union{
    T100WORD                WORD;
    struct{
        T100HWORD_BITS      HWORD_LOW;
        T100HWORD_BITS      HWORD_HIGH;
    };
    struct{
        T100BYTE_BITS       BYTE0;
        T100BYTE_BITS       BYTE1;
        T100BYTE_BITS       BYTE2;
        T100BYTE_BITS       BYTE3;
    };
}T100WORD_BITS;

typedef union{
    T100DWORD               DWORD;
    struct{
        T100WORD_BITS       WORD_LOW;
        T100WORD_BITS       WORD_HIGH;
    };
}T100DWORD_BITS;


#endif // T100BITTYPES_H
