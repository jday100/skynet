#ifndef T100CAPACITYCOMMON_H
#define T100CAPACITYCOMMON_H

#include "T100Common.h"

namespace T100Library{

typedef enum{
    T100CAPACITY_TOKEN_NONE         = 0,
    T100CAPACITY_TOKEN_EOF,
    T100CAPACITY_TOKEN_ERROR,
    //
    T100CAPACITY_CHAR_DIGIT,
    T100CAPACITY_CHAR_B,
    T100CAPACITY_CHAR_C,
    T100CAPACITY_CHAR_D,
    T100CAPACITY_CHAR_E,
    T100CAPACITY_CHAR_G,
    T100CAPACITY_CHAR_K,
    T100CAPACITY_CHAR_M,
    T100CAPACITY_CHAR_N,
    T100CAPACITY_CHAR_P,
    T100CAPACITY_CHAR_T,
    T100CAPACITY_CHAR_W,
    T100CAPACITY_CHAR_Y,
    T100CAPACITY_CHAR_Z,
    //
    T100CAPACITY_TOKEN_NUMBER,
    //
    T100CAPACITY_UNIT_B,
    T100CAPACITY_UNIT_W,
    T100CAPACITY_UNIT_D,
    //
    T100CAPACITY_TOKEN_K,
    T100CAPACITY_TOKEN_M,
    T100CAPACITY_TOKEN_G,
    T100CAPACITY_TOKEN_T,
    T100CAPACITY_TOKEN_P,
    T100CAPACITY_TOKEN_E,
    T100CAPACITY_TOKEN_Z,
    T100CAPACITY_TOKEN_Y,
    T100CAPACITY_TOKEN_B,
    T100CAPACITY_TOKEN_N,
    T100CAPACITY_TOKEN_D,
    T100CAPACITY_TOKEN_C,
    //
    T100CAPACITY_TOKEN_MAX
}T100CAPACITY_TOKEN_TYPE;

}

#endif // T100CAPACITYCOMMON_H