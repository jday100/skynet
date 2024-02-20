#ifndef T100VHD_H
#define T100VHD_H

#include "T100Common.h"
#include "T100VHDCommon.h"


typedef struct{
    T100BYTE        COOKIE[8];
    T100BYTE        FEATURES[4];
    T100BYTE        FILE_FORMAT_VERSION[4];
    T100BYTE        DATA_OFFSET[8];
    T100BYTE        TIME_STAMP[4];
    T100BYTE        CREATOR_APPLICATION[4];
    T100BYTE        CREATOR_VERSION[4];
    T100BYTE        CREATOR_HOST_OS[4];
    T100BYTE        ORIGINAL_SIZE[8];
    T100BYTE        CURRENT_SIZE[8];
    T100BYTE        DISK_GEOMETRY[4];
    T100BYTE        DISK_TYPE[4];
    T100BYTE        CHECKSUM[4];
    T100BYTE        UNIQUE_ID[16];
    T100BYTE        SAVED_STATE;
    T100BYTE        RESERVED[427];
}T100VHD_HEAD;

typedef union{
    T100BYTE        DATA[512];
    T100VHD_HEAD    HEAD;
}T100VHD_FILE;


class T100VHD
{
    public:
        T100VHD(T100STRING, T100INT64);
        virtual ~T100VHD();

        T100BOOL            create(T100VHD_STORAGE_TYPE);

    protected:
        T100VHD_FILE        m_file_head;

        T100BOOL            fixed();


    private:
        T100INT64           m_length            = 0;
        T100STRING          m_filename;
};

#endif // T100VHD_H
