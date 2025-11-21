#ifndef T100DATATYPES_H
#define T100DATATYPES_H

#include <vector>
#include <stdint.h>

typedef     int8_t              T100INT8;
typedef     int16_t             T100INT16;
typedef     int32_t             T100INT32;
typedef     int64_t             T100INT64;

typedef     uint8_t             T100UINT8;
typedef     uint16_t            T100UINT16;
typedef     uint32_t            T100UINT32;
typedef     uint64_t            T100UINT64;

typedef     T100UINT32          T100UINT;
typedef     T100INT32           T100INT;

typedef     T100UINT8           T100BYTE;

#define     T100BYTE_VECTOR                 std::vector<T100BYTE>

#endif // T100DATATYPES_H

