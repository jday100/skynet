#ifndef T100FONTCOMMON_H
#define T100FONTCOMMON_H

#include "T100UnicodeCommon.h"
#include "T100File.h"


#define     T100FONTFILE_DEFAULT_SIZE           16


#define     T100FONT_DATA_VECTOR            std::vector<T100WORD>
#define     T100FONT_VECTOR                 std::vector<T100FONT_DATA_VECTOR*>


typedef struct{
    T100FILE_HEAD       FILE_SIGN;
    T100WORD            FONT_NAME[130];
    T100WORD            FONT_WIDTH;
    T100WORD            FONT_HEIGHT;
    T100WORD            ROW_SIZE;
}T100FONTFILE_HEAD;

typedef struct{
    T100UNICODE32       UNICODE32;
    T100WORD            BEGIN;
    T100WORD            END;
    T100WORD            SEEK;
    T100WORD            LENGTH;
}T100FONTFILE_ROW;


typedef struct{
    T100FONTFILE_ROW*   ROW;
    T100FONT_VECTOR*    FONTS;
}T100FONT_ROW;


#define     T100FONT_ROW_VECTOR         std::vector<T100FONT_ROW*>
#define     T100FONT_HASH               std::unordered_map<T100WORD, T100FONT_DATA_VECTOR*>


#define     T100FONTFILE_VECTOR             std::vector<T100FONTFILE*>
#define     T100FONTFILE_HASH               std::unordered_map<T100FILE_HANDLE, T100FontFile*>
#define     T100FONTFILE_ROW_VECTOR         std::vector<T100FONTFILE_ROW*>



#endif // T100FONTCOMMON_H
