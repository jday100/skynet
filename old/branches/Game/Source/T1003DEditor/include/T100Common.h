#ifndef T100COMMON_H
#define T100COMMON_H

#include <string>
#include <stdint.h>

#include "common/T100DataTypes.h"

#define     T100NEW             new
#define     T100SAFE_DELETE     delete
#define     T100SAFE_DELETES    delete[]

#define     T100INT32           int

//#define     T100UINT8           uint8_t
//#define     T100UINT16          uint16_t
#define     T100UINT24          uint24_t
//#define     T100UINT32          uint32_t

#define     T100STRING          std::string
#define     T100WSTRING         std::wstring

#define     T100WCHAR           wchar_t
#define     T100CHAR            char
#define     T100UCHAR           unsigned char

#define     T100DX12SIZE        size_t

#endif // T100COMMON_H
