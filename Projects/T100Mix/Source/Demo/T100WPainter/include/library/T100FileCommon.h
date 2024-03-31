#ifndef T100FILECOMMON_H
#define T100FILECOMMON_H

#include "T100Common.h"

typedef enum{
    T100FILE_NONE           = 0,
    //
    T100FILE_TEXT,          //TXT
    T100FILE_BINARY,        //BIN
    //
    T100FILE_BITMAP,        //BMP   位图
    T100FILE_ICON,          //ICO   图标
    //
    T100FILE_PICTURE,       //PIC   图片
    T100FILE_GRAPH,         //GRP   图片
    //
    T100FILE_DIAGRAM,       //DGM   流程图
    T100FILE_DRAWING,       //DRW   图形
    T100FILE_CHART,         //CHT   图表
    T100FILE_MAP,           //MAP   地图
    T100FILE_PHOTO,         //PHT   照片
    //
    T100FILE_VIDEO,
    T100FILE_MOVIE,
    T100FILE_AUDIO,
    T100FILE_SOUND,
    T100FILE_MUSIC,
    //
    T100FILE_DOCUMENT,      //DOC
    T100FILE_DATABASE,      //DAT
    T100FILE_LOG,           //LOG
    T100FILE_TEMPORARY,     //TMP
    //
    T100FILE_FONT,          //FNT
    T100FILE_VDISK,         //VDK
    T100FILE_EXECUTABLE,    //EXE
    T100FILE_LIBRARY,       //LIB
    //
    T100FILE_ASSEMBLY,      //ASM
    T100FILE_OBJECT,        //OBJ
    T100FILE_SYMBOL,        //SYM
    //
    T100FILE_PAL,           //PAL
    T100FILE_MAIN,          //MN
    T100FILE_PROJECT,       //PRJ
    T100FILE_CODE,          //COD
    T100FILE_PLAN,          //PLN
    T100FILE_DICTIONARY,    //DCT
    //
    T100FILE_WEB,           //WEB
    //
    T100FILE_MAX
}T100FILE_TYPE;

typedef struct{
    T100WORD                SIGN;
}T100FILE_HEAD;

typedef enum{
    T100FILE_READ,
    T100FILE_WRITE,
    T100FILE_STREAM
}T100FILE_MODE;

#endif // T100FILECOMMON_H
