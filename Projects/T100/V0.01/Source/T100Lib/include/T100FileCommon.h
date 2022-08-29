#ifndef T100FILECOMMON_H
#define T100FILECOMMON_H


#include "T100Common.h"
class T100File;

#define     T100FILE_HANDLE             T100DWORD
#define     T100FILE_VECTOR             std::vector<T100File*>
#define     T100FILE_HANDLE_HASH        std::unordered_map<T100FILE_HANDLE, T100File*>


enum T100FILE_TYPE{
    T100FILE_NONE                   = 0,
    //
    T100FILE_TEXT,                  //TXT
    T100FILE_BINARY,                //BIN
    //
    T100FILE_DOCUMENT,              //DOC
    T100FILE_DATABASE,              //DAT
    T100FILE_LOG,                   //LOG
    T100FILE_TEMPORARY,             //TMP
    //
    T100FILE_FONT,                  //FNT
    T100FILE_VDISK,                 //VDK
    T100FILE_EXECUTABLE,            //EXE
    T100FILE_LIBRARY,               //LIB
    T100FILE_TINY,                  //TNY
    //
    T100FILE_ASSEMBLY,              //ASM
    T100FILE_OBJECT,                //OBJ
    T100FILE_SYMBOL,                //SYM
    //
    T100FILE_PAL,                   //PAL
    T100FILE_MAIN,                  //MN
    T100FILE_PROJECT,               //PRJ
    T100FILE_CODE,                  //COD
    T100FILE_PLAN,                  //PLN
    T100FILE_DICTIONARY,            //DCT

    T100FILE_WEB,                   //WEB

    T100FILE_MAX
};

typedef struct{
    T100WORD        SIGN;
}T100FILE_HEAD;

enum T100FILE_MODE{
    T100FILE_READ,
    T100FILE_WRITE,
    T100FILE_READWRITE
};

#endif // T100FILECOMMON_H
