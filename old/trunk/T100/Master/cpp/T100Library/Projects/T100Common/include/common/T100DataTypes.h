#ifndef T100DATATYPES_H
#define T100DATATYPES_H

#include <cstdint>

namespace T100LIBRARY{

//数据类型定义
typedef     void                    T100VOID;
typedef     bool                    T100BOOL;

//有符号
typedef     int8_t                  T100INT8;
typedef     int16_t                 T100INT16;
typedef     int32_t                 T100INT32;
typedef     int64_t                 T100INT64;

//无符号
typedef     uint8_t                 T100UINT8;
typedef     uint16_t                T100UINT16;
typedef     uint32_t                T100UINT32;
typedef     uint64_t                T100UINT64;

typedef     float                   T100FLOAT;
typedef     double                  T100DOUBLE;

typedef     T100UINT8               T100BYTE;

typedef     T100INT32               T100INT;
typedef     T100UINT32              T100UINT;

}

#endif // T100DATATYPES_H
