#ifndef T100STRINGCOMMON_H
#define T100STRINGCOMMON_H

#include "T100Common.h"
#include "T100StringTypes.h"
#include "T100DataStructure.h"
#include "T100Class.h"
class T100String;

#define     T100STRING_EMPTY                    L""

#define     T100CHAR_VECTOR                     std::vector<T100CHAR>
#define     T100WCHAR_VECTOR                    std::vector<T100WCHAR>

#define     T100WSTRING_VECTOR                  std::vector<T100WSTRING>
#define     T100STRING_VECTOR                   std::vector<T100Library::T100String>


typedef enum{
    T100STRING_TYPE_NONE            = 0,
    T100STRING_TYPE_WSTRING,
    T100STRING_TYPE_STRING8,
    T100STRING_TYPE_STRING16,
    T100STRING_TYPE_STRING32,
    T100STRING_TYPE_CUSTOM,
    T100STRING_TYPE_MAX
}T100STRING_TYPE;

typedef enum{
    T100STRING_CODED_NONE           = 0,
    T100STRING_CODED_UTF8,
    T100STRING_CODED_UTF16BE,
    T100STRING_CODED_UTF16LE,
    T100STRING_CODED_UTF32,
    T100STRING_CODED_UCS2,
    T100STRING_CODED_UCS4,
    T100STRING_CODED_GBK,
    T100STRING_CODED_BIG5,
    T100STRING_CODED_MAX
}T100STRING_CODED_TYPE;



#endif // T100STRINGCOMMON_H
