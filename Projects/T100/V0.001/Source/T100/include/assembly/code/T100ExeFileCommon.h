#ifndef T100EXEFILECOMMON_H
#define T100EXEFILECOMMON_H

#include "T100FileCommon.h"
#include "T100ExeCommon.h"


typedef struct{
    T100FILE_HEAD       COMMON;
    T100WORD            TYPE;
    T100WORD            CODE_COUNT;
    T100WORD            CODE_TABLE_OFFSET;
    T100WORD            CODE_TABLE_LENGTH;
    T100WORD            CODE_OFFSET;
    T100WORD            CODE_LENGTH;
    //
    T100WORD            DATA_COUNT;
    T100WORD            DATA_TABLE_OFFSET;
    T100WORD            DATA_TABLE_LENGTH;
    T100WORD            DATA_OFFSET;
    T100WORD            DATA_LENGTH;
    //
    T100WORD            SHARE_CODE_COUNT;
    T100WORD            SHARE_CODE_TABLE_OFFSET;
    T100WORD            SHARE_CODE_TABLE_LENGTH;
    T100WORD            SHARE_CODE_OFFSET;
    T100WORD            SHARE_CODE_LENGTH;
    //
    T100WORD            SHARE_DATA_COUNT;
    T100WORD            SHARE_DATA_TABLE_OFFSET;
    T100WORD            SHARE_DATA_TABLE_LENGTH;
    T100WORD            SHARE_DATA_OFFSET;
    T100WORD            SHARE_DATA_LENGTH;
    //
    T100WORD            EXPANDED_COUNT;
    T100WORD            EXPANDED_TABLE_OFFSET;
    T100WORD            EXPANDED_TABLE_LENGTH;
    T100WORD            EXPANDED_OFFSET;
    T100WORD            EXPANDED_LENGTH;
    //
}T100EXECUTABLE_FILE_HEAD;


typedef struct{
    T100WORD            INDEX;
    T100WORD            OFFSET;
    T100WORD            LENGTH;
}T100EXECUTABLE_FILE_CODE;

typedef struct{
    T100WORD            INDEX;
    T100WORD            OFFSET;
    T100WORD            LENGTH;
}T100EXECUTABLE_FILE_DATA;

typedef struct{
    T100WORD            INDEX;
    T100WORD            OFFSET;
    T100WORD            LENGTH;
    T100WORD            LOCATION;
    T100String          NAME;
}T100EXECUTABLE_FILE_SHARE;

#endif // T100EXEFILECOMMON_H
