#ifndef T100VDISKCOMMON_H
#define T100VDISKCOMMON_H

#include "T100Common.h"
#include "T100FileCommon.h"


#define     T100VDISK_DATA_LENGTH                       16 * 1024

namespace T100Component{

typedef struct{
    T100DWORD               LENGTH;
    T100DWORD               BLOCK_LENGTH;
    T100DWORD               DATA_LENGTH;
    T100DWORD               FILE_LENGTH;
    T100DWORD               PHYSICAL_LENGTH;
}T100VDISK_INFO;

typedef union{
    struct{
        T100Library::T100FILE_HEAD      HEAD;
        T100VDISK_INFO                  INFO;
    };
    T100WORD                DATA[T100VDISK_DATA_LENGTH];
}T100VDISK_FILE_HEAD;

}

#endif // T100VDISKCOMMON_H
