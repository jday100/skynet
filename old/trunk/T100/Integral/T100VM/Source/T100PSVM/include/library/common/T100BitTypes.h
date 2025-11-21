#ifndef T100BITTYPES_H
#define T100BITTYPES_H

#include "T100DataTypes.h"

//位操作结构体
typedef union {
    T100BYTE                BYTE;
    struct {
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

typedef union {
    T100UINT16              DATA16;
    struct {
        T100BYTE_BITS       BYTE_LOW;
        T100BYTE_BITS       BYTE_HIGH;
    };
}T100DATA16_BITS;

typedef union {
    T100UINT32              DATA32;
    struct {
        T100DATA16_BITS     DATA16_LOW;
        T100DATA16_BITS     DATA16_HIGH;
    };
    struct {
        T100BYTE_BITS       BYTE0;
        T100BYTE_BITS       BYTE1;
        T100BYTE_BITS       BYTE2;
        T100BYTE_BITS       BYTE3;
    };
}T100DATA32_BITS;

typedef union {
    T100UINT64              DATA64;
    struct {
        T100DATA32_BITS     DATA32_LOW;
        T100DATA32_BITS     DATA32_HIGH;
    };
}T100DATA64_BITS;

#endif // T100BITTYPES_H

