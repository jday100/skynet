#ifndef T100DISKCOMMON_H
#define T100DISKCOMMON_H

typedef enum{
    T100DISK_TYPE_NONE,
    T100DISK_TYPE_IDE,
    T100DISK_TYPE_SATA,
    T100DISK_TYPE_SCSI,
    T100DISK_TYPE_NVME,
    T100DISK_TYPE_USB,
    T100DISK_TYPE_VDISK
}T100DISK_TYPE;

#endif // T100DISKCOMMON_H