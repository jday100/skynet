#ifndef T100UNICODECOMMON_H
#define T100UNICODECOMMON_H

#include "T100Common.h"


typedef union{
    T100WORD            WORD;
    struct{
        T100BYTE        GROUP;
        T100BYTE        PLANE;
        T100BYTE        ROW;
        T100BYTE        CELL;
    };
}T100UNICODE32;


static T100STDSTRING       T100FONT_COUNTRY[3][2] = {
    {
        "中国",     "china"
    },{
        "美国",     "america"
    },{
        "",     ""
    }
};

static T100STDSTRING       T100FONT_CHINA_CODE[3][2] = {
    {
        "00004E00",         "00009FFF"
    },{
        "0000F900",         "0000FAFF"
    },{
        "",     ""
    }
};

static T100STDSTRING       T100FONT_AMERICA_CODE[2][2] = {
    {
        "00000000",         "000000FF"
    },{
        "",                 ""
    }
};

#endif // T100UNICODECOMMON_H
