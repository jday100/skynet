#ifndef T100VHD_H
#define T100VHD_H

#include <guiddef.h>
#include "T100Common.h"
#include "T100VHDBase.h"


typedef struct{
    T100BYTE        COOKIE[8];
    T100INT32       FEATURES;
    T100INT16       FILE_FORMAT_MAJOR;
    T100INT16       FILE_FORMAT_MINOR;
    T100BYTE        DATA_OFFSET[8];
    T100INT32       TIME_STAMP;
    T100BYTE        CREATE_APPLICATION[4];
    T100INT16       CREATE_VERSION_MAJOR;
    T100INT16       CREATE_VERSION_MINOR;
    T100BYTE        CREATE_HOST_OS[4];
    T100INT64       ORIGINAL_SIZE;
    T100INT64       CURRENT_SIZE;
    T100INT16       DISK_GEOMETRY_CYLINDER;
    T100INT8        DISK_GEOMETRY_HEADS;
    T100INT8        DISK_GEOMETRY_SECTORS;
    T100INT32       DISK_TYPE;
    T100INT32       CHECKSUM;
    GUID            UNIQUE_ID;
    T100BYTE        SAVED_STATE;
    T100BYTE        RESERVED[427];
}T100VHD_FOOTER;


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
    T100VHD_FOOTER  FOOTER;
}T100VHD_FILE;


class T100VHD : public T100VHDBase
{
    public:
        T100VHD(T100STRING, T100INT64);
        virtual ~T100VHD();

        T100BOOL                create(T100VHD_STORAGE_TYPE);
        T100VOID                cancel();

        T100VOID                setValue(T100VOID*);
        T100VOID                setCreateCallback(T100THREAD_CALLBACK);

    protected:
        T100VHD_FILE            m_file_head;
        T100VOID*               m_value             = T100NULL;
        T100THREAD_CALLBACK     m_callback          = T100NULL;

        T100BOOL                fixed();
        T100BOOL                dynamic();

        T100BOOL                fixed1();
        T100BOOL                create1(T100VHD_STORAGE_TYPE);

    protected:
        T100BOOL                setCookie();
        T100BOOL                setFeatures();
        T100BOOL                setFileFormatVersion();
        T100BOOL                setDataOffset();
        T100BOOL                setTimeStamp();
        T100BOOL                setCreateApplication();
        T100BOOL                setCreateVersion();
        T100BOOL                setCreateHostOS();
        T100BOOL                setOriginalSize();
        T100BOOL                setCurrentSize();
        T100BOOL                setDiskGeometry();
        T100BOOL                setDiskType();
        T100BOOL                setUniqueID();
        T100BOOL                setSavedState();
        T100BOOL                setCheckSum();

    private:
        T100INT64               m_length            = 0;
        T100STRING              m_filename;
};

#endif // T100VHD_H
