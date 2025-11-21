#ifndef T100COMMON_H
#define T100COMMON_H

#include "common/T100DataTypes.h"
#include "common/T100StringTypes.h"

#define     T100NEW             new
#define     T100SAFE_DELETE     delete

struct T100BYTE_DATA{
    T100BYTE*       DATA_PTR        = T100NULL;
    T100UINT        LENGTH          = 0;
};

#endif // T100COMMON_H
