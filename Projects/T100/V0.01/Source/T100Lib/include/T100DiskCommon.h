#ifndef T100DISKCOMMON_H
#define T100DISKCOMMON_H

#include "T100Common.h"
#include "T100GraphicCommon.h"
#include "T100String.h"


typedef enum{
    T100DISK_NONE               = 0,
    T100DISK_MAX
}T100DISK_TYPE;

typedef enum{
    T100DISK_PART_NONE          = 0,
    T100DISK_PART_MAX
}T100DISK_PART_TYPE;


typedef struct{
    T100DWORD       LENGTH;
    T100WORD        BLOCK_SIZE;
    T100WORD        BLOCK_LENGTH;
}T100DISK;

typedef struct{
    T100STRING      NAME;
    T100DWORD       LOCATION;
    T100DWORD       LENGTH;
    T100BOOL        BOOT;
}T100DISK_PART;

typedef struct{
    T100DISK_PART*          PART;
    T100WORD                X;
    T100WORD                Y;
    T100WORD                WIDTH;
    T100WORD                HEIGHT;
    T100FLOAT               RATIO;
}T100DISK_PART_CTRL;


#define     T100DISK_VECTOR                 std::vector<T100DISK*>
#define     T100DISK_PART_VECTOR            std::vector<T100DISK_PART*>
#define     T100DISK_PART_CTRL_VECTOR       std::vector<T100DISK_PART_CTRL*>

#define     T100DISK_COLOUR_DEFAULT                 T100COLOUR_GREEN
#define     T100DISK_PART_COLOUR_DEFAULT            T100COLOUR_YELLOW



#endif // T100DISKCOMMON_H
