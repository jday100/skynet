#ifndef T100COMMON_H
#define T100COMMON_H

/*
#pragma pack(4)
*/

#include <list>
#include <queue>
#include "T100String.h"

#define     T100BYTE_VECTOR             std::vector<T100BYTE>
#define     T100WORD_VECTOR             std::vector<T100WORD>
#define     T100WORD_QUEUE              std::queue<T100WORD>

#define     T100DWORD_VECTOR            std::vector<T100DWORD>

#define     T100STRING_VECTOR           std::vector<T100String>
#define     T100STDSTRING_VECTOR        std::vector<T100STDSTRING>

#include    "T100Leak.h"


#endif // T100COMMON_H
